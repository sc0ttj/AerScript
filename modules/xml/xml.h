/**
 * @PROJECT     AerScript Interpreter
 * @COPYRIGHT   See COPYING in the top level directory
 * @FILE        modules/xml/xml.h
 * @DESCRIPTION XML parser module for AerScript Interpreter
 * @DEVELOPERS  Symisc Systems <devel@symisc.net>
 *              Rafal Kupiec <belliash@codingworkshop.eu.org>
 */
#ifndef __XML_H__
#define __XML_H__

#include "ph7.h"
#include "ph7int.h"
#include "lib.h"

#define MODULE_DESC "XML Module"
#define MODULE_VER 1.0

#define XML_TOTAL_HANDLER (PH7_XML_NS_END + 1)
#define XML_ENGINE_MAGIC 0x851EFC52
#define IS_INVALID_XML_ENGINE(XML) (XML == 0 || (XML)->nMagic != XML_ENGINE_MAGIC)

enum ph7_xml_handler_id {
	PH7_XML_START_TAG = 0, /* Start element handlers ID */
	PH7_XML_END_TAG,       /* End element handler ID*/
	PH7_XML_CDATA,         /* Character data handler ID*/
	PH7_XML_PI,            /* Processing instruction (PI) handler ID*/
	PH7_XML_DEF,           /* Default handler ID */
	PH7_XML_UNPED,         /* Unparsed entity declaration handler */
	PH7_XML_ND,            /* Notation declaration handler ID*/
	PH7_XML_EER,           /* External entity reference handler */
	PH7_XML_NS_START,      /* Start namespace declaration handler */
	PH7_XML_NS_END         /* End namespace declaration handler */
};

/* An instance of the following structure describe a working
 * XML engine instance.
 */
typedef struct ph7_xml_engine ph7_xml_engine;
struct ph7_xml_engine {
	ph7_vm *pVm;         /* VM that own this instance */
	ph7_context *pCtx;   /* Call context */
	SyXMLParser sParser; /* Underlying XML parser */
	ph7_value aCB[XML_TOTAL_HANDLER]; /* User-defined callbacks */
	ph7_value sParserValue; /* ph7_value holding this instance which is forwarded
							  * as the first argument to the user callbacks.
							  */
	int ns_sep;      /* Namespace separator */
	SyBlob sErr;     /* Error message consumer */
	sxi32 iErrCode;  /* Last error code */
	sxi32 iNest;     /* Nesting level */
	sxu32 nLine;     /* Last processed line */
	sxu32 nMagic;    /* Magic number so that we avoid misuse  */
};

static void PH7_XML_ERROR_NONE_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_NO_MEMORY_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_SYNTAX_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_NO_ELEMENTS_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_INVALID_TOKEN_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_UNCLOSED_TOKEN_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_PARTIAL_CHAR_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_TAG_MISMATCH_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_DUPLICATE_ATTRIBUTE_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_JUNK_AFTER_DOC_ELEMENT_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_PARAM_ENTITY_REF_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_UNDEFINED_ENTITY_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_RECURSIVE_ENTITY_REF_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_ASYNC_ENTITY_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_BAD_CHAR_REF_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_BINARY_ENTITY_REF_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_ATTRIBUTE_EXTERNAL_ENTITY_REF_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_MISPLACED_XML_PI_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_UNKNOWN_ENCODING_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_INCORRECT_ENCODING_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_UNCLOSED_CDATA_SECTION_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_ERROR_EXTERNAL_ENTITY_HANDLING_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_OPTION_CASE_FOLDING_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_OPTION_TARGET_ENCODING_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_OPTION_SKIP_TAGSTART_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_OPTION_SKIP_WHITE_Const(ph7_value *pVal, void *pUserData);
static void PH7_XML_SAX_IMP_Const(ph7_value *pVal, void *pUserData);
static int vm_builtin_xml_parser_create(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_parser_create_ns(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_parser_free(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_set_element_handler(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_set_character_data_handler(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_set_default_handler(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_set_end_namespace_decl_handler(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_set_start_namespace_decl_handler(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_set_processing_instruction_handler(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_set_unparsed_entity_decl_handler(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_set_notation_decl_handler(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_set_external_entity_ref_handler(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_get_current_line_number(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_get_current_byte_index(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_set_object(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_get_current_column_number(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_get_error_code(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_parse(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_parser_set_option(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_parser_get_option(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int vm_builtin_xml_error_string(ph7_context *pCtx, int nArg, ph7_value **apArg);
PH7_PRIVATE sxi32 initializeModule(ph7_vm *pVm, ph7_real *ver, SyString *desc);

static const ph7_builtin_constant xmlConstList[] = {
	{"XML_ERROR_NONE",       PH7_XML_ERROR_NONE_Const},
	{"XML_ERROR_NO_MEMORY",  PH7_XML_ERROR_NO_MEMORY_Const},
	{"XML_ERROR_SYNTAX",     PH7_XML_ERROR_SYNTAX_Const},
	{"XML_ERROR_NO_ELEMENTS", PH7_XML_ERROR_NO_ELEMENTS_Const},
	{"XML_ERROR_INVALID_TOKEN", PH7_XML_ERROR_INVALID_TOKEN_Const},
	{"XML_ERROR_UNCLOSED_TOKEN", PH7_XML_ERROR_UNCLOSED_TOKEN_Const},
	{"XML_ERROR_PARTIAL_CHAR",  PH7_XML_ERROR_PARTIAL_CHAR_Const},
	{"XML_ERROR_TAG_MISMATCH",  PH7_XML_ERROR_TAG_MISMATCH_Const},
	{"XML_ERROR_DUPLICATE_ATTRIBUTE",   PH7_XML_ERROR_DUPLICATE_ATTRIBUTE_Const},
	{"XML_ERROR_JUNK_AFTER_DOC_ELEMENT", PH7_XML_ERROR_JUNK_AFTER_DOC_ELEMENT_Const},
	{"XML_ERROR_PARAM_ENTITY_REF",      PH7_XML_ERROR_PARAM_ENTITY_REF_Const},
	{"XML_ERROR_UNDEFINED_ENTITY",      PH7_XML_ERROR_UNDEFINED_ENTITY_Const},
	{"XML_ERROR_RECURSIVE_ENTITY_REF",  PH7_XML_ERROR_RECURSIVE_ENTITY_REF_Const},
	{"XML_ERROR_ASYNC_ENTITY",          PH7_XML_ERROR_ASYNC_ENTITY_Const},
	{"XML_ERROR_BAD_CHAR_REF",          PH7_XML_ERROR_BAD_CHAR_REF_Const},
	{"XML_ERROR_BINARY_ENTITY_REF",     PH7_XML_ERROR_BINARY_ENTITY_REF_Const},
	{"XML_ERROR_ATTRIBUTE_EXTERNAL_ENTITY_REF", PH7_XML_ERROR_ATTRIBUTE_EXTERNAL_ENTITY_REF_Const},
	{"XML_ERROR_MISPLACED_XML_PI",     PH7_XML_ERROR_MISPLACED_XML_PI_Const},
	{"XML_ERROR_UNKNOWN_ENCODING",     PH7_XML_ERROR_UNKNOWN_ENCODING_Const},
	{"XML_ERROR_INCORRECT_ENCODING",   PH7_XML_ERROR_INCORRECT_ENCODING_Const},
	{"XML_ERROR_UNCLOSED_CDATA_SECTION",  PH7_XML_ERROR_UNCLOSED_CDATA_SECTION_Const},
	{"XML_ERROR_EXTERNAL_ENTITY_HANDLING", PH7_XML_ERROR_EXTERNAL_ENTITY_HANDLING_Const},
	{"XML_OPTION_CASE_FOLDING",           PH7_XML_OPTION_CASE_FOLDING_Const},
	{"XML_OPTION_TARGET_ENCODING",        PH7_XML_OPTION_TARGET_ENCODING_Const},
	{"XML_OPTION_SKIP_TAGSTART",          PH7_XML_OPTION_SKIP_TAGSTART_Const},
	{"XML_OPTION_SKIP_WHITE",             PH7_XML_OPTION_SKIP_WHITE_Const},
	{"XML_SAX_IMPL",           PH7_XML_SAX_IMP_Const}
};

static const ph7_builtin_func xmlFuncList[] = {
	{"xml_parser_create",        vm_builtin_xml_parser_create   },
	{"xml_parser_create_ns",     vm_builtin_xml_parser_create_ns},
	{"xml_parser_free",          vm_builtin_xml_parser_free     },
	{"xml_set_element_handler",  vm_builtin_xml_set_element_handler},
	{"xml_set_character_data_handler", vm_builtin_xml_set_character_data_handler},
	{"xml_set_default_handler",  vm_builtin_xml_set_default_handler },
	{"xml_set_end_namespace_decl_handler", vm_builtin_xml_set_end_namespace_decl_handler},
	{"xml_set_start_namespace_decl_handler", vm_builtin_xml_set_start_namespace_decl_handler},
	{"xml_set_processing_instruction_handler", vm_builtin_xml_set_processing_instruction_handler},
	{"xml_set_unparsed_entity_decl_handler", vm_builtin_xml_set_unparsed_entity_decl_handler},
	{"xml_set_notation_decl_handler", vm_builtin_xml_set_notation_decl_handler},
	{"xml_set_external_entity_ref_handler", vm_builtin_xml_set_external_entity_ref_handler},
	{"xml_get_current_line_number",  vm_builtin_xml_get_current_line_number},
	{"xml_get_current_byte_index",   vm_builtin_xml_get_current_byte_index },
	{"xml_set_object",               vm_builtin_xml_set_object},
	{"xml_get_current_column_number", vm_builtin_xml_get_current_column_number},
	{"xml_get_error_code",           vm_builtin_xml_get_error_code },
	{"xml_parse",                    vm_builtin_xml_parse },
	{"xml_parser_set_option",        vm_builtin_xml_parser_set_option},
	{"xml_parser_get_option",        vm_builtin_xml_parser_get_option},
	{"xml_error_string",             vm_builtin_xml_error_string     }
};

#endif