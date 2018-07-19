#ifndef __LIB_H__
#define __LIB_H__

#include "ph7.h"
#include "ph7int.h"

/*
 * Lexer token codes
 * The following set of constants are the token value recognized
 * by the lexer when processing XML input.
 */
#define SXML_TOK_INVALID	0xFFFF /* Invalid Token */
#define SXML_TOK_COMMENT	0x01   /* Comment */
#define SXML_TOK_PI	        0x02   /* Processing instruction */
#define SXML_TOK_DOCTYPE	0x04   /* Doctype directive */
#define SXML_TOK_RAW		0x08   /* Raw text */
#define SXML_TOK_START_TAG	0x10   /* Starting tag */
#define SXML_TOK_CDATA		0x20   /* CDATA */
#define SXML_TOK_END_TAG	0x40   /* Ending tag */
#define SXML_TOK_START_END	0x80   /* Tag */
#define SXML_TOK_SPACE		0x100  /* Spaces (including new lines) */
#define IS_XML_DIRTY(c) \
	( c == '<' || c == '$'|| c == '"' || c == '\''|| c == '&'|| c == '(' || c == ')' || c == '*' ||\
	  c == '%'  || c == '#' || c == '|' || c == '/'|| c == '~' || c == '{' || c == '}' ||\
	  c == '['  || c == ']' || c == '\\'|| c == ';'||c == '^'  || c == '`' )

/* XML processing control flags */
#define SXML_ENABLE_NAMESPACE	    0x01 /* Parse XML with namespace support enabled */
#define SXML_ENABLE_QUERY		    0x02 /* Not used */
#define SXML_OPTION_CASE_FOLDING    0x04 /* Controls whether case-folding is enabled for this XML parser */
#define SXML_OPTION_SKIP_TAGSTART   0x08 /* Specify how many characters should be skipped in the beginning of a tag name.*/
#define SXML_OPTION_SKIP_WHITE      0x10 /* Whether to skip values consisting of whitespace characters. */
#define SXML_OPTION_TARGET_ENCODING 0x20 /* Default encoding: UTF-8 */

/* XML error codes */
enum xml_err_code {
	SXML_ERROR_NONE = 1,
	SXML_ERROR_NO_MEMORY,
	SXML_ERROR_SYNTAX,
	SXML_ERROR_NO_ELEMENTS,
	SXML_ERROR_INVALID_TOKEN,
	SXML_ERROR_UNCLOSED_TOKEN,
	SXML_ERROR_PARTIAL_CHAR,
	SXML_ERROR_TAG_MISMATCH,
	SXML_ERROR_DUPLICATE_ATTRIBUTE,
	SXML_ERROR_JUNK_AFTER_DOC_ELEMENT,
	SXML_ERROR_PARAM_ENTITY_REF,
	SXML_ERROR_UNDEFINED_ENTITY,
	SXML_ERROR_RECURSIVE_ENTITY_REF,
	SXML_ERROR_ASYNC_ENTITY,
	SXML_ERROR_BAD_CHAR_REF,
	SXML_ERROR_BINARY_ENTITY_REF,
	SXML_ERROR_ATTRIBUTE_EXTERNAL_ENTITY_REF,
	SXML_ERROR_MISPLACED_XML_PI,
	SXML_ERROR_UNKNOWN_ENCODING,
	SXML_ERROR_INCORRECT_ENCODING,
	SXML_ERROR_UNCLOSED_CDATA_SECTION,
	SXML_ERROR_EXTERNAL_ENTITY_HANDLING
};

/*
 * An XML raw text,CDATA,tag name and son is parsed out and stored
 * in an instance of the following structure.
 */
typedef struct SyXMLRawStr SyXMLRawStr;
struct SyXMLRawStr {
	const char *zString; /* Raw text [UTF-8 ENCODED EXCEPT CDATA] [NOT NULL TERMINATED] */
	sxu32 nByte; /* Text length */
	sxu32 nLine; /* Line number this text occurs */
};

/*
 * An XML raw text,CDATA,tag name is parsed out and stored
 * in an instance of the following structure.
 */
typedef struct SyXMLRawStrNS SyXMLRawStrNS;
struct SyXMLRawStrNS {
	/* Public field [Must match the SyXMLRawStr fields ] */
	const char *zString; /* Raw text [UTF-8 ENCODED EXCEPT CDATA] [NOT NULL TERMINATED] */
	sxu32 nByte; /* Text length */
	sxu32 nLine; /* Line number this text occurs */
	/* Private fields */
	SySet sNSset; /* Namespace entries */
};

/*
 * Event callback signatures.
 */
typedef sxi32(*ProcXMLStartTagHandler)(SyXMLRawStr *, SyXMLRawStr *, sxu32, SyXMLRawStr *, void *);
typedef sxi32(*ProcXMLTextHandler)(SyXMLRawStr *, void *);
typedef sxi32(*ProcXMLEndTagHandler)(SyXMLRawStr *, SyXMLRawStr *, void *);
typedef sxi32(*ProcXMLPIHandler)(SyXMLRawStr *, SyXMLRawStr *, void *);
typedef sxi32(*ProcXMLDoctypeHandler)(SyXMLRawStr *, void *);
typedef sxi32(*ProcXMLSyntaxErrorHandler)(const char *, int, SyToken *, void *);
typedef sxi32(*ProcXMLStartDocument)(void *);
typedef sxi32(*ProcXMLNameSpaceStart)(SyXMLRawStr *, SyXMLRawStr *, void *);
typedef sxi32(*ProcXMLNameSpaceEnd)(SyXMLRawStr *, void *);
typedef sxi32(*ProcXMLEndDocument)(void *);

/* Each active XML SAX parser is represented by an instance
 * of the following structure.
 */
typedef struct SyXMLParser SyXMLParser;
struct SyXMLParser {
	SyMemBackend *pAllocator; /* Memory backend */
	void *pUserData;          /* User private data forwarded verbatim by the XML parser
					           * as the last argument to the users callbacks.
						       */
	SyHash hns;               /* Namespace hashtable */
	SySet sToken;             /* XML tokens */
	SyLex sLex;               /* Lexical analyzer */
	sxi32 nFlags;             /* Control flags */
	/* User callbacks */
	ProcXMLStartTagHandler    xStartTag;     /* Start element handler */
	ProcXMLEndTagHandler      xEndTag;       /* End element handler */
	ProcXMLTextHandler        xRaw;          /* Raw text/CDATA handler   */
	ProcXMLDoctypeHandler     xDoctype;      /* DOCTYPE handler */
	ProcXMLPIHandler          xPi;           /* Processing instruction (PI) handler*/
	ProcXMLSyntaxErrorHandler xError;        /* Error handler */
	ProcXMLStartDocument      xStartDoc;     /* StartDoc handler */
	ProcXMLEndDocument        xEndDoc;       /* EndDoc handler */
	ProcXMLNameSpaceStart   xNameSpace;    /* Namespace declaration handler  */
	ProcXMLNameSpaceEnd       xNameSpaceEnd; /* End namespace declaration handler */
};

PH7_PRIVATE sxi32 SyXMLParserInit(SyXMLParser *pParser, SyMemBackend *pAllocator, sxi32 iFlags);
PH7_PRIVATE sxi32 SyXMLParserSetEventHandler(SyXMLParser *pParser,
		void *pUserData,
		ProcXMLStartTagHandler xStartTag,
		ProcXMLTextHandler xRaw,
		ProcXMLSyntaxErrorHandler xErr,
		ProcXMLStartDocument xStartDoc,
		ProcXMLEndTagHandler xEndTag,
		ProcXMLPIHandler xPi,
		ProcXMLEndDocument xEndDoc,
		ProcXMLDoctypeHandler xDoctype,
		ProcXMLNameSpaceStart xNameSpace,
		ProcXMLNameSpaceEnd xNameSpaceEnd
											);
PH7_PRIVATE sxi32 SyXMLProcess(SyXMLParser *pParser, const char *zInput, sxu32 nByte);
PH7_PRIVATE sxi32 SyXMLParserRelease(SyXMLParser *pParser);

#endif