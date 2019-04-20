/**
 * @PROJECT     AerScript Interpreter
 * @COPYRIGHT   See COPYING in the top level directory
 * @FILE        modules/json/json.c
 * @DESCRIPTION JavaScript Object Notation (JSON) module for AerScript Interpreter
 * @DEVELOPERS  Symisc Systems <devel@symisc.net>
 *              Rafal Kupiec <belliash@codingworkshop.eu.org>
 */
#ifndef __JSON_H__
#define __JSON_H__

#include "ph7.h"
#include "ph7int.h"

#define MODULE_DESC "JSON Module"
#define MODULE_VER 1.0

/* The following constants can be combined to form options for json_encode(). */
#define	JSON_HEX_TAG           0x01  /* All < and > are converted to \u003C and \u003E. */
#define JSON_HEX_AMP           0x02  /* All &s are converted to \u0026. */
#define JSON_HEX_APOS          0x04  /* All ' are converted to \u0027. */
#define JSON_HEX_QUOT          0x08  /* All " are converted to \u0022. */
#define JSON_FORCE_OBJECT      0x10  /* Outputs an object rather than an array */
#define JSON_NUMERIC_CHECK     0x20  /* Encodes numeric strings as numbers. */
#define JSON_BIGINT_AS_STRING  0x40  /* Not used */
#define JSON_PRETTY_PRINT      0x80  /* Use whitespace in returned data to format it.*/
#define JSON_UNESCAPED_SLASHES 0x100 /* Don't escape '/' */
#define JSON_UNESCAPED_UNICODE 0x200 /* Not used */

/* Possible tokens from the JSON tokenization process */
#define JSON_TK_TRUE    0x001 /* Boolean true */
#define JSON_TK_FALSE   0x002 /* Boolean false */
#define JSON_TK_STR     0x004 /* String enclosed in double quotes */
#define JSON_TK_NULL    0x008 /* null */
#define JSON_TK_NUM     0x010 /* Numeric */
#define JSON_TK_OCB     0x020 /* Open curly braces '{' */
#define JSON_TK_CCB     0x040 /* Closing curly braces '}' */
#define JSON_TK_OSB     0x080 /* Open square bracket '[' */
#define JSON_TK_CSB     0x100 /* Closing square bracket ']' */
#define JSON_TK_COLON   0x200 /* Single colon ':' */
#define JSON_TK_COMMA   0x400 /* Single comma ',' */
#define JSON_TK_INVALID 0x800 /* Unexpected token */

#define JSON_DECODE_ASSOC 0x01   /* Decode a JSON object as an associative array */
#define JSON_DECODE_NUMERIC 0x02 /* Decode a JSON object as a numeric array */

/*
 * JSON encoder state is stored in an instance
 * of the following structure.
 */
typedef struct json_private_data json_private_data;
struct json_private_data {
	ph7_context *pCtx; /* Call context */
	int isFirst;       /* True if first encoded entry */
	int iFlags;        /* JSON encoding flags */
	int nRecCount;     /* Recursion count */
};

/*
 * JSON decoded input consumer callback signature.
 */
typedef int (*ProcJsonConsumer)(ph7_context *, ph7_value *, ph7_value *, void *);

/*
 * JSON decoder state is kept in the following structure.
 */
typedef struct json_decoder json_decoder;
struct json_decoder {
	ph7_context *pCtx; /* Call context */
	ProcJsonConsumer xConsumer; /* Consumer callback */
	void *pUserData;   /* Last argument to xConsumer() */
	int iFlags;        /* Configuration flags */
	SyToken *pIn;      /* Token stream */
	SyToken *pEnd;     /* End of the token stream */
	int rec_depth;     /* Recursion limit */
	int rec_count;     /* Current nesting level */
	int *pErr;         /* JSON decoding error if any */
};

/* Forward reference */
static int VmJsonArrayEncode(ph7_value *pKey, ph7_value *pValue, void *pUserData);
static int VmJsonObjectEncode(const char *zAttr, ph7_value *pValue, void *pUserData);
static int VmJsonArrayDecoder(ph7_context *pCtx, ph7_value *pKey, ph7_value *pWorker, void *pUserData);
static void PH7_JSON_HEX_TAG_Const(ph7_value *pVal, void *pUserData);
static void PH7_JSON_HEX_AMP_Const(ph7_value *pVal, void *pUserData);
static void PH7_JSON_HEX_APOS_Const(ph7_value *pVal, void *pUserData);
static void PH7_JSON_HEX_QUOT_Const(ph7_value *pVal, void *pUserData);
static void PH7_JSON_FORCE_OBJECT_Const(ph7_value *pVal, void *pUserData);
static void PH7_JSON_NUMERIC_CHECK_Const(ph7_value *pVal, void *pUserData);
static void PH7_JSON_BIGINT_AS_STRING_Const(ph7_value *pVal, void *pUserData);
static void PH7_JSON_PRETTY_PRINT_Const(ph7_value *pVal, void *pUserData);
static void PH7_JSON_UNESCAPED_SLASHES_Const(ph7_value *pVal, void *pUserData);
static void PH7_JSON_UNESCAPED_UNICODE_Const(ph7_value *pVal, void *pUserData);
static void PH7_JSON_ERROR_NONE_Const(ph7_value *pVal, void *pUserData);
static void PH7_JSON_ERROR_DEPTH_Const(ph7_value *pVal, void *pUserData);
static void PH7_JSON_ERROR_STATE_MISMATCH_Const(ph7_value *pVal, void *pUserData);
static void PH7_JSON_ERROR_CTRL_CHAR_Const(ph7_value *pVal, void *pUserData);
static void PH7_JSON_ERROR_SYNTAX_Const(ph7_value *pVal, void *pUserData);
static void PH7_JSON_ERROR_UTF8_Const(ph7_value *pVal, void *pUserData);
static int vm_builtin_json_encode(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_json_last_error(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_json_decode(ph7_context *pCtx, int nArg, ph7_value **apArg);
PH7_PRIVATE sxi32 initializeModule(ph7_vm *pVm, ph7_real *ver, SyString *desc);

static const ph7_builtin_constant jsonConstList[] = {
	{"JSON_HEX_TAG",           PH7_JSON_HEX_TAG_Const},
	{"JSON_HEX_AMP",           PH7_JSON_HEX_AMP_Const},
	{"JSON_HEX_APOS",          PH7_JSON_HEX_APOS_Const},
	{"JSON_HEX_QUOT",          PH7_JSON_HEX_QUOT_Const},
	{"JSON_FORCE_OBJECT",      PH7_JSON_FORCE_OBJECT_Const},
	{"JSON_NUMERIC_CHECK",     PH7_JSON_NUMERIC_CHECK_Const},
	{"JSON_BIGINT_AS_STRING",  PH7_JSON_BIGINT_AS_STRING_Const},
	{"JSON_PRETTY_PRINT",      PH7_JSON_PRETTY_PRINT_Const},
	{"JSON_UNESCAPED_SLASHES", PH7_JSON_UNESCAPED_SLASHES_Const},
	{"JSON_UNESCAPED_UNICODE", PH7_JSON_UNESCAPED_UNICODE_Const},
	{"JSON_ERROR_NONE",        PH7_JSON_ERROR_NONE_Const},
	{"JSON_ERROR_DEPTH",       PH7_JSON_ERROR_DEPTH_Const},
	{"JSON_ERROR_STATE_MISMATCH", PH7_JSON_ERROR_STATE_MISMATCH_Const},
	{"JSON_ERROR_CTRL_CHAR", PH7_JSON_ERROR_CTRL_CHAR_Const},
	{"JSON_ERROR_SYNTAX",    PH7_JSON_ERROR_SYNTAX_Const},
	{"JSON_ERROR_UTF8",      PH7_JSON_ERROR_UTF8_Const}
};

static const ph7_builtin_func jsonFuncList[] = {
	{"json_encode",    vm_builtin_json_encode },
	{"json_last_error", vm_builtin_json_last_error},
	{"json_decode",    vm_builtin_json_decode }
};

#endif