#include "xml.h"

/*
 * XML_ERROR_NONE
 *   Expand the value of SXML_ERROR_NO_MEMORY defined in ph7Int.h
 */
static void PH7_XML_ERROR_NONE_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_NO_MEMORY);
}
/*
 * XML_ERROR_NO_MEMORY
 *   Expand the value of SXML_ERROR_NONE defined in ph7Int.h
 */
static void PH7_XML_ERROR_NO_MEMORY_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_NO_MEMORY);
}
/*
 * XML_ERROR_SYNTAX
 *   Expand the value of SXML_ERROR_SYNTAX defined in ph7Int.h
 */
static void PH7_XML_ERROR_SYNTAX_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_SYNTAX);
}
/*
 * XML_ERROR_NO_ELEMENTS
 *   Expand the value of SXML_ERROR_NO_ELEMENTS defined in ph7Int.h
 */
static void PH7_XML_ERROR_NO_ELEMENTS_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_NO_ELEMENTS);
}
/*
 * XML_ERROR_INVALID_TOKEN
 *   Expand the value of SXML_ERROR_INVALID_TOKEN defined in ph7Int.h
 */
static void PH7_XML_ERROR_INVALID_TOKEN_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_INVALID_TOKEN);
}
/*
 * XML_ERROR_UNCLOSED_TOKEN
 *   Expand the value of SXML_ERROR_UNCLOSED_TOKEN defined in ph7Int.h
 */
static void PH7_XML_ERROR_UNCLOSED_TOKEN_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_UNCLOSED_TOKEN);
}
/*
 * XML_ERROR_PARTIAL_CHAR
 *   Expand the value of SXML_ERROR_PARTIAL_CHAR defined in ph7Int.h
 */
static void PH7_XML_ERROR_PARTIAL_CHAR_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_PARTIAL_CHAR);
}
/*
 * XML_ERROR_TAG_MISMATCH
 *   Expand the value of SXML_ERROR_TAG_MISMATCH defined in ph7Int.h
 */
static void PH7_XML_ERROR_TAG_MISMATCH_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_TAG_MISMATCH);
}
/*
 * XML_ERROR_DUPLICATE_ATTRIBUTE
 *   Expand the value of SXML_ERROR_DUPLICATE_ATTRIBUTE defined in ph7Int.h
 */
static void PH7_XML_ERROR_DUPLICATE_ATTRIBUTE_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_DUPLICATE_ATTRIBUTE);
}
/*
 * XML_ERROR_JUNK_AFTER_DOC_ELEMENT
 *   Expand the value of SXML_ERROR_JUNK_AFTER_DOC_ELEMENT defined in ph7Int.h
 */
static void PH7_XML_ERROR_JUNK_AFTER_DOC_ELEMENT_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_JUNK_AFTER_DOC_ELEMENT);
}
/*
 * XML_ERROR_PARAM_ENTITY_REF
 *   Expand the value of SXML_ERROR_PARAM_ENTITY_REF defined in ph7Int.h
 */
static void PH7_XML_ERROR_PARAM_ENTITY_REF_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_PARAM_ENTITY_REF);
}
/*
 * XML_ERROR_UNDEFINED_ENTITY
 *   Expand the value of SXML_ERROR_UNDEFINED_ENTITY defined in ph7Int.h
 */
static void PH7_XML_ERROR_UNDEFINED_ENTITY_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_UNDEFINED_ENTITY);
}
/*
 * XML_ERROR_RECURSIVE_ENTITY_REF
 *   Expand the value of SXML_ERROR_RECURSIVE_ENTITY_REF defined in ph7Int.h
 */
static void PH7_XML_ERROR_RECURSIVE_ENTITY_REF_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_RECURSIVE_ENTITY_REF);
}
/*
 * XML_ERROR_ASYNC_ENTITY
 *   Expand the value of SXML_ERROR_ASYNC_ENTITY defined in ph7Int.h
 */
static void PH7_XML_ERROR_ASYNC_ENTITY_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_ASYNC_ENTITY);
}
/*
 * XML_ERROR_BAD_CHAR_REF
 *   Expand the value of SXML_ERROR_BAD_CHAR_REF defined in ph7Int.h
 */
static void PH7_XML_ERROR_BAD_CHAR_REF_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_BAD_CHAR_REF);
}
/*
 * XML_ERROR_BINARY_ENTITY_REF
 *   Expand the value of SXML_ERROR_BINARY_ENTITY_REF defined in ph7Int.h
 */
static void PH7_XML_ERROR_BINARY_ENTITY_REF_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_BINARY_ENTITY_REF);
}
/*
 * XML_ERROR_ATTRIBUTE_EXTERNAL_ENTITY_REF
 *   Expand the value of SXML_ERROR_ATTRIBUTE_EXTERNAL_ENTITY_REF defined in ph7Int.h
 */
static void PH7_XML_ERROR_ATTRIBUTE_EXTERNAL_ENTITY_REF_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_ATTRIBUTE_EXTERNAL_ENTITY_REF);
}
/*
 * XML_ERROR_MISPLACED_XML_PI
 *   Expand the value of SXML_ERROR_MISPLACED_XML_PI defined in ph7Int.h
 */
static void PH7_XML_ERROR_MISPLACED_XML_PI_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_MISPLACED_XML_PI);
}
/*
 * XML_ERROR_UNKNOWN_ENCODING
 *   Expand the value of SXML_ERROR_UNKNOWN_ENCODING defined in ph7Int.h
 */
static void PH7_XML_ERROR_UNKNOWN_ENCODING_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_UNKNOWN_ENCODING);
}
/*
 * XML_ERROR_INCORRECT_ENCODING
 *   Expand the value of SXML_ERROR_INCORRECT_ENCODING defined in ph7Int.h
 */
static void PH7_XML_ERROR_INCORRECT_ENCODING_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_INCORRECT_ENCODING);
}
/*
 * XML_ERROR_UNCLOSED_CDATA_SECTION
 *   Expand the value of SXML_ERROR_UNCLOSED_CDATA_SECTION defined in ph7Int.h
 */
static void PH7_XML_ERROR_UNCLOSED_CDATA_SECTION_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_UNCLOSED_CDATA_SECTION);
}
/*
 * XML_ERROR_EXTERNAL_ENTITY_HANDLING
 *   Expand the value of SXML_ERROR_EXTERNAL_ENTITY_HANDLING defined in ph7Int.h
 */
static void PH7_XML_ERROR_EXTERNAL_ENTITY_HANDLING_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_ERROR_EXTERNAL_ENTITY_HANDLING);
}
/*
 * XML_OPTION_CASE_FOLDING
 *   Expand the value of SXML_OPTION_CASE_FOLDING defined in ph7Int.h.
 */
static void PH7_XML_OPTION_CASE_FOLDING_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_OPTION_CASE_FOLDING);
}
/*
 * XML_OPTION_TARGET_ENCODING
 *   Expand the value of SXML_OPTION_TARGET_ENCODING defined in ph7Int.h.
 */
static void PH7_XML_OPTION_TARGET_ENCODING_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_OPTION_TARGET_ENCODING);
}
/*
 * XML_OPTION_SKIP_TAGSTART
 *   Expand the value of SXML_OPTION_SKIP_TAGSTART defined in ph7Int.h.
 */
static void PH7_XML_OPTION_SKIP_TAGSTART_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_OPTION_SKIP_TAGSTART);
}
/*
 * XML_OPTION_SKIP_WHITE
 *   Expand the value of SXML_OPTION_SKIP_TAGSTART defined in ph7Int.h.
 */
static void PH7_XML_OPTION_SKIP_WHITE_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_int(pVal, SXML_OPTION_SKIP_WHITE);
}
/*
 * XML_SAX_IMPL.
 *   Expand the name of the underlying XML engine.
 */
static void PH7_XML_SAX_IMP_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_string(pVal, "Symisc XML engine", (int)sizeof("Symisc XML engine") - 1);
}

/*
 * Allocate and initialize an XML engine.
 */
static ph7_xml_engine *VmCreateXMLEngine(ph7_context *pCtx, int process_ns, int ns_sep) {
	ph7_xml_engine *pEngine;
	ph7_vm *pVm = pCtx->pVm;
	ph7_value *pValue;
	sxu32 n;
	/* Allocate a new instance */
	pEngine = (ph7_xml_engine *)SyMemBackendAlloc(&pVm->sAllocator, sizeof(ph7_xml_engine));
	if(pEngine == 0) {
		/* Out of memory */
		return 0;
	}
	/* Zero the structure */
	SyZero(pEngine, sizeof(ph7_xml_engine));
	/* Initialize fields */
	pEngine->pVm = pVm;
	pEngine->pCtx = 0;
	pEngine->ns_sep = ns_sep;
	SyXMLParserInit(&pEngine->sParser, &pVm->sAllocator, process_ns ? SXML_ENABLE_NAMESPACE : 0);
	SyBlobInit(&pEngine->sErr, &pVm->sAllocator);
	PH7_MemObjInit(pVm, &pEngine->sParserValue);
	for(n = 0 ; n < SX_ARRAYSIZE(pEngine->aCB) ; ++n) {
		pValue = &pEngine->aCB[n];
		/* NULLIFY the array entries,until someone register an event handler */
		PH7_MemObjInit(&(*pVm), pValue);
	}
	ph7_value_resource(&pEngine->sParserValue, pEngine);
	pEngine->iErrCode = SXML_ERROR_NONE;
	/* Finally set the magic number */
	pEngine->nMagic = XML_ENGINE_MAGIC;
	return pEngine;
}
/*
 * Release an XML engine.
 */
static void VmReleaseXMLEngine(ph7_xml_engine *pEngine) {
	ph7_vm *pVm = pEngine->pVm;
	ph7_value *pValue;
	sxu32 n;
	/* Release fields */
	SyBlobRelease(&pEngine->sErr);
	SyXMLParserRelease(&pEngine->sParser);
	PH7_MemObjRelease(&pEngine->sParserValue);
	for(n = 0 ; n < SX_ARRAYSIZE(pEngine->aCB) ; ++n) {
		pValue = &pEngine->aCB[n];
		PH7_MemObjRelease(pValue);
	}
	pEngine->nMagic = 0x2621;
	/* Finally,release the whole instance */
	SyMemBackendFree(&pVm->sAllocator, pEngine);
}
/*
 * resource xml_parser_create([ string $encoding ])
 *  Create an UTF-8 XML parser.
 * Parameter
 *  $encoding
 *   (Only UTF-8 encoding is used)
 * Return
 *  Returns a resource handle for the new XML parser.
 */
static int vm_builtin_xml_parser_create(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	/* Allocate a new instance */
	pEngine = VmCreateXMLEngine(&(*pCtx), 0, ':');
	if(pEngine == 0) {
		ph7_context_throw_error(pCtx, PH7_CTX_ERR, "PH7 is running out of memory");
		/* Return null */
		ph7_result_null(pCtx);
		SXUNUSED(nArg); /* cc warning */
		SXUNUSED(apArg);
		return PH7_OK;
	}
	/* Return the engine as a resource */
	ph7_result_resource(pCtx, pEngine);
	return PH7_OK;
}
/*
 * resource xml_parser_create_ns([ string $encoding[,string $separator = ':']])
 *  Create an UTF-8 XML parser with namespace support.
 * Parameter
 *  $encoding
 *   (Only UTF-8 encoding is supported)
 *  $separtor
 *   Namespace separator (a single character)
 * Return
 *  Returns a resource handle for the new XML parser.
 */
static int vm_builtin_xml_parser_create_ns(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	int ns_sep = ':';
	if(nArg > 1 && ph7_value_is_string(apArg[1])) {
		const char *zSep = ph7_value_to_string(apArg[1], 0);
		if(zSep[0] != 0) {
			ns_sep = zSep[0];
		}
	}
	/* Allocate a new instance */
	pEngine = VmCreateXMLEngine(&(*pCtx), TRUE, ns_sep);
	if(pEngine == 0) {
		ph7_context_throw_error(pCtx, PH7_CTX_ERR, "PH7 is running out of memory");
		/* Return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Return the engine as a resource */
	ph7_result_resource(pCtx, pEngine);
	return PH7_OK;
}
/*
 * bool xml_parser_free(resource $parser)
 *  Release an XML engine.
 * Parameter
 *  $parser
 *   A reference to the XML parser to free.
 * Return
 *  This function returns FALSE if parser does not refer
 *  to a valid parser, or else it frees the parser and returns TRUE.
 */
static int vm_builtin_xml_parser_free(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	if(nArg < 1 || !ph7_value_is_resource(apArg[0])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Safely release the engine */
	VmReleaseXMLEngine(pEngine);
	/* Return TRUE */
	ph7_result_bool(pCtx, 1);
	return PH7_OK;
}
/*
 * bool xml_set_element_handler(resource $parser,callback $start_element_handler,[callback $end_element_handler])
 * Sets the element handler functions for the XML parser. start_element_handler and end_element_handler
 * are strings containing the names of functions.
 * Parameters
 *  $parser
 *   A reference to the XML parser to set up start and end element handler functions.
 *  $start_element_handler
 *    The function named by start_element_handler must accept three parameters:
 *    start_element_handler(resource $parser,string $name,array $attribs)
 *    $parser
 *      The first parameter, parser, is a reference to the XML parser calling the handler.
 *   $name
 *      The second parameter, name, contains the name of the element for which this handler
 *		is called.If case-folding is in effect for this parser, the element name will be in uppercase letters.
 *  $attribs
 *      The third parameter, attribs, contains an associative array with the element's attributes (if any).
 *		The keys of this array are the attribute names, the values are the attribute values.
 *      Attribute names are case-folded on the same criteria as element names.Attribute values are not case-folded.
 *      The original order of the attributes can be retrieved by walking through attribs the normal way, using each().
 *      The first key in the array was the first attribute, and so on.
 *      Note: Instead of a function name, an array containing an object reference and a method name can also be supplied.
 * $end_element_handler
 *     The function named by end_element_handler must accept two parameters:
 *     end_element_handler(resource $parser,string $name)
 *    $parser
 *      The first parameter, parser, is a reference to the XML parser calling the handler.
 *   $name
 *      The second parameter, name, contains the name of the element for which this handler
 *      is called.If case-folding is in effect for this parser, the element name will be in uppercase
 *      letters.
 *      If a handler function is set to an empty string, or FALSE, the handler in question is disabled.
 * Return
 * TRUE on success or FALSE on failure.
 */
static int vm_builtin_xml_set_element_handler(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	if(nArg < 1 || !ph7_value_is_resource(apArg[0])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	if(nArg > 1) {
		/* Save the start_element_handler callback for later invocation */
		PH7_MemObjStore(apArg[1]/* User callback*/, &pEngine->aCB[PH7_XML_START_TAG]);
		if(nArg > 2) {
			/* Save the end_element_handler callback for later invocation */
			PH7_MemObjStore(apArg[2]/* User callback*/, &pEngine->aCB[PH7_XML_END_TAG]);
		}
	}
	/* All done,return TRUE */
	ph7_result_bool(pCtx, 1);
	return PH7_OK;
}
/*
 * bool xml_set_character_data_handler(resource $parser,callback $handler)
 *  Sets the character data handler function for the XML parser parser.
 * Parameters
 * $parser
 *   A reference to the XML parser to set up character data handler function.
 * $handler
 *  handler is a string containing the name of the callback.
 *  The function named by handler must accept two parameters:
 *   handler(resource $parser,string $data)
 *  $parser
 *    The first parameter, parser, is a reference to the XML parser calling the handler.
 *  $data
 *   The second parameter, data, contains the character data as a string.
 *   Character data handler is called for every piece of a text in the XML document.
 *   It can be called multiple times inside each fragment (e.g. for non-ASCII strings).
 *   If a handler function is set to an empty string, or FALSE, the handler in question is disabled.
 *   Note: Instead of a function name, an array containing an object reference and a method name
 *   can also be supplied.
 * Return
 *  TRUE on success or FALSE on failure.
 */
static int vm_builtin_xml_set_character_data_handler(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	if(nArg < 1 || !ph7_value_is_resource(apArg[0])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	if(nArg > 1) {
		/* Save the user callback for later invocation */
		PH7_MemObjStore(apArg[1]/* User callback*/, &pEngine->aCB[PH7_XML_CDATA]);
	}
	/* All done,return TRUE */
	ph7_result_bool(pCtx, 1);
	return PH7_OK;
}
/*
 * bool xml_set_default_handler(resource $parser,callback $handler)
 *  Set up default handler.
 * Parameters
 * $parser
 *   A reference to the XML parser to set up character data handler function.
 * $handler
 *  handler is a string containing the name of the callback.
 *  The function named by handler must accept two parameters:
 *   handler(resource $parser,string $data)
 *  $parser
 *    The first parameter, parser, is a reference to the XML parser calling the handler.
 *  $data
 *   The second parameter, data, contains the character data.This may be the XML declaration
 *   document type declaration, entities or other data for which no other handler exists.
 *   Note: Instead of a function name, an array containing an object reference and a method name
 *   can also be supplied.
 * Return
 *  TRUE on success or FALSE on failure.
 */
static int vm_builtin_xml_set_default_handler(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	if(nArg < 1 || !ph7_value_is_resource(apArg[0])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	if(nArg > 1) {
		/* Save the user callback for later invocation */
		PH7_MemObjStore(apArg[1]/* User callback*/, &pEngine->aCB[PH7_XML_DEF]);
	}
	/* All done,return TRUE */
	ph7_result_bool(pCtx, 1);
	return PH7_OK;
}
/*
 * bool xml_set_end_namespace_decl_handler(resource $parser,callback $handler)
 *  Set up end namespace declaration handler.
 * Parameters
 * $parser
 *   A reference to the XML parser to set up character data handler function.
 * $handler
 *  handler is a string containing the name of the callback.
 *  The function named by handler must accept two parameters:
 *   handler(resource $parser,string $prefix)
 *  $parser
 *    The first parameter, parser, is a reference to the XML parser calling the handler.
 *  $prefix
 *   The prefix is a string used to reference the namespace within an XML object.
 *   Note: Instead of a function name, an array containing an object reference and a method name
 *   can also be supplied.
 * Return
 *  TRUE on success or FALSE on failure.
 */
static int vm_builtin_xml_set_end_namespace_decl_handler(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	if(nArg < 1 || !ph7_value_is_resource(apArg[0])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	if(nArg > 1) {
		/* Save the user callback for later invocation */
		PH7_MemObjStore(apArg[1]/* User callback*/, &pEngine->aCB[PH7_XML_NS_END]);
	}
	/* All done,return TRUE */
	ph7_result_bool(pCtx, 1);
	return PH7_OK;
}
/*
 * bool xml_set_start_namespace_decl_handler(resource $parser,callback $handler)
 *  Set up start namespace declaration handler.
 * Parameters
 * $parser
 *   A reference to the XML parser to set up character data handler function.
 * $handler
 *  handler is a string containing the name of the callback.
 *  The function named by handler must accept two parameters:
 *   handler(resource $parser,string $prefix,string $uri)
 *  $parser
 *    The first parameter, parser, is a reference to the XML parser calling the handler.
 *  $prefix
 *   The prefix is a string used to reference the namespace within an XML object.
 *  $uri
 *    Uniform Resource Identifier (URI) of namespace.
 *   Note: Instead of a function name, an array containing an object reference and a method name
 *   can also be supplied.
 * Return
 *  TRUE on success or FALSE on failure.
 */
static int vm_builtin_xml_set_start_namespace_decl_handler(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	if(nArg < 1 || !ph7_value_is_resource(apArg[0])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	if(nArg > 1) {
		/* Save the user callback for later invocation */
		PH7_MemObjStore(apArg[1]/* User callback*/, &pEngine->aCB[PH7_XML_NS_START]);
	}
	/* All done,return TRUE */
	ph7_result_bool(pCtx, 1);
	return PH7_OK;
}
/*
 * bool xml_set_processing_instruction_handler(resource $parser,callback $handler)
 *  Set up processing instruction (PI) handler.
 * Parameters
 * $parser
 *   A reference to the XML parser to set up character data handler function.
 * $handler
 *  handler is a string containing the name of the callback.
 *  The function named by handler must accept three parameters:
 *   handler(resource $parser,string $target,string $data)
 *  $parser
 *    The first parameter, parser, is a reference to the XML parser calling the handler.
 *  $target
 *   The second parameter, target, contains the PI target.
 *  $data
     The third parameter, data, contains the PI data.
 *   Note: Instead of a function name, an array containing an object reference and a method name
 *   can also be supplied.
 * Return
 *  TRUE on success or FALSE on failure.
 */
static int vm_builtin_xml_set_processing_instruction_handler(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	if(nArg < 1 || !ph7_value_is_resource(apArg[0])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	if(nArg > 1) {
		/* Save the user callback for later invocation */
		PH7_MemObjStore(apArg[1]/* User callback*/, &pEngine->aCB[PH7_XML_PI]);
	}
	/* All done,return TRUE */
	ph7_result_bool(pCtx, 1);
	return PH7_OK;
}
/*
 * bool xml_set_unparsed_entity_decl_handler(resource $parser,callback $handler)
 *  Set up unparsed entity declaration handler.
 * Parameters
 * $parser
 *   A reference to the XML parser to set up character data handler function.
 * $handler
 *  handler is a string containing the name of the callback.
 *  The function named by handler must accept six parameters:
 *  handler(resource $parser,string $entity_name,string $base,string $system_id,string $public_id,string $notation_name)
 *  $parser
 *   The first parameter, parser, is a reference to the XML parser calling the handler.
 *  $entity_name
 *   The name of the entity that is about to be defined.
 *  $base
 *   This is the base for resolving the system identifier (systemId) of the external entity.
 *   Currently this parameter will always be set to an empty string.
 *  $system_id
 *   System identifier for the external entity.
 *  $public_id
 *    Public identifier for the external entity.
 *  $notation_name
 *    Name of the notation of this entity (see xml_set_notation_decl_handler()).
 *   Note: Instead of a function name, an array containing an object reference and a method name
 *   can also be supplied.
 * Return
 *  TRUE on success or FALSE on failure.
 */
static int vm_builtin_xml_set_unparsed_entity_decl_handler(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	if(nArg < 1 || !ph7_value_is_resource(apArg[0])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	if(nArg > 1) {
		/* Save the user callback for later invocation */
		PH7_MemObjStore(apArg[1]/* User callback*/, &pEngine->aCB[PH7_XML_UNPED]);
	}
	/* All done,return TRUE */
	ph7_result_bool(pCtx, 1);
	return PH7_OK;
}
/*
 * bool xml_set_notation_decl_handler(resource $parser,callback $handler)
 *  Set up notation declaration handler.
 * Parameters
 * $parser
 *   A reference to the XML parser to set up character data handler function.
 * $handler
 *  handler is a string containing the name of the callback.
 *  The function named by handler must accept five parameters:
 *  handler(resource $parser,string $entity_name,string $base,string $system_id,string $public_id)
 *  $parser
 *   The first parameter, parser, is a reference to the XML parser calling the handler.
 *  $entity_name
 *   The name of the entity that is about to be defined.
 *  $base
 *   This is the base for resolving the system identifier (systemId) of the external entity.
 *   Currently this parameter will always be set to an empty string.
 *  $system_id
 *   System identifier for the external entity.
 *  $public_id
 *    Public identifier for the external entity.
 *  Note: Instead of a function name, an array containing an object reference and a method name
 *  can also be supplied.
 * Return
 *  TRUE on success or FALSE on failure.
 */
static int vm_builtin_xml_set_notation_decl_handler(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	if(nArg < 1 || !ph7_value_is_resource(apArg[0])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	if(nArg > 1) {
		/* Save the user callback for later invocation */
		PH7_MemObjStore(apArg[1]/* User callback*/, &pEngine->aCB[PH7_XML_ND]);
	}
	/* All done,return TRUE */
	ph7_result_bool(pCtx, 1);
	return PH7_OK;
}
/*
 * bool xml_set_external_entity_ref_handler(resource $parser,callback $handler)
 *  Set up external entity reference handler.
 * Parameters
 * $parser
 *   A reference to the XML parser to set up character data handler function.
 * $handler
 *  handler is a string containing the name of the callback.
 *  The function named by handler must accept five parameters:
 *   handler(resource $parser,string $open_entity_names,string $base,string $system_id,string $public_id)
 *  $parser
 *   The first parameter, parser, is a reference to the XML parser calling the handler.
 *  $open_entity_names
 *   The second parameter, open_entity_names, is a space-separated list of the names
 *   of the entities that are open for the parse of this entity (including the name of the referenced entity).
 *  $base
 *   This is the base for resolving the system identifier (system_id) of the external entity.
 *   Currently this parameter will always be set to an empty string.
 *  $system_id
 *   The fourth parameter, system_id, is the system identifier as specified in the entity declaration.
 *  $public_id
 *   The fifth parameter, public_id, is the public identifier as specified in the entity declaration
 *   or an empty string if none was specified; the whitespace in the public identifier will have been
 *   normalized as required by the XML spec.
 * Note: Instead of a function name, an array containing an object reference and a method name
 * can also be supplied.
 * Return
 *  TRUE on success or FALSE on failure.
 */
static int vm_builtin_xml_set_external_entity_ref_handler(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	if(nArg < 1 || !ph7_value_is_resource(apArg[0])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	if(nArg > 1) {
		/* Save the user callback for later invocation */
		PH7_MemObjStore(apArg[1]/* User callback*/, &pEngine->aCB[PH7_XML_EER]);
	}
	/* All done,return TRUE */
	ph7_result_bool(pCtx, 1);
	return PH7_OK;
}
/*
 * int xml_get_current_line_number(resource $parser)
 *  Gets the current line number for the given XML parser.
 * Parameters
 * $parser
 *   A reference to the XML parser.
 * Return
 *  This function returns FALSE if parser does not refer
 *  to a valid parser, or else it returns which line the parser
 *  is currently at in its data buffer.
 */
static int vm_builtin_xml_get_current_line_number(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	if(nArg < 1 || !ph7_value_is_resource(apArg[0])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Return the line number */
	ph7_result_int(pCtx, (int)pEngine->nLine);
	return PH7_OK;
}
/*
 * int xml_get_current_byte_index(resource $parser)
 *  Gets the current byte index of the given XML parser.
 * Parameters
 * $parser
 *   A reference to the XML parser.
 * Return
 *  This function returns FALSE if parser does not refer to a valid
 *  parser, or else it returns which byte index the parser is currently
 *  at in its data buffer (starting at 0).
 */
static int vm_builtin_xml_get_current_byte_index(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	SyStream *pStream;
	SyToken *pToken;
	if(nArg < 1 || !ph7_value_is_resource(apArg[0])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the current processed token */
	pToken = (SyToken *)SySetPeekCurrentEntry(&pEngine->sParser.sToken);
	if(pToken == 0) {
		/* Stream not yet processed */
		ph7_result_int(pCtx, 0);
		return 0;
	}
	/* Point to the input stream */
	pStream = &pEngine->sParser.sLex.sStream;
	/* Return the byte index */
	ph7_result_int64(pCtx, (ph7_int64)(pToken->sData.zString - (const char *)pStream->zInput));
	return PH7_OK;
}
/*
 * bool xml_set_object(resource $parser,object &$object)
 *  Use XML Parser within an object.
 * NOTE
 *  This function is depreceated and is a no-op.
 * Parameters
 * $parser
 *   A reference to the XML parser.
 * $object
 *  The object where to use the XML parser.
 * Return
 * Always FALSE.
 */
static int vm_builtin_xml_set_object(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	if(nArg < 2 || !ph7_value_is_resource(apArg[0]) || !ph7_value_is_object(apArg[1])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/*  Throw a notice and return */
	ph7_context_throw_error(pCtx, PH7_CTX_NOTICE, "This function is depreceated and is a no-op."
							"In order to mimic this behaviour,you can supply instead of a function name an array "
							"containing an object reference and a method name."
						   );
	/* Return FALSE */
	ph7_result_bool(pCtx, 0);
	return PH7_OK;
}
/*
 * int xml_get_current_column_number(resource $parser)
 *  Gets the current column number of the given XML parser.
 * Parameters
 * $parser
 *   A reference to the XML parser.
 * Return
 *  This function returns FALSE if parser does not refer to a valid parser, or else it returns
 *  which column on the current line (as given by xml_get_current_line_number()) the parser
 *  is currently at.
 */
static int vm_builtin_xml_get_current_column_number(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	SyStream *pStream;
	SyToken *pToken;
	if(nArg < 1 || !ph7_value_is_resource(apArg[0])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the current processed token */
	pToken = (SyToken *)SySetPeekCurrentEntry(&pEngine->sParser.sToken);
	if(pToken == 0) {
		/* Stream not yet processed */
		ph7_result_int(pCtx, 0);
		return 0;
	}
	/* Point to the input stream */
	pStream = &pEngine->sParser.sLex.sStream;
	/* Return the byte index */
	ph7_result_int64(pCtx, (ph7_int64)(pToken->sData.zString - (const char *)pStream->zInput) / 80);
	return PH7_OK;
}
/*
 * int xml_get_error_code(resource $parser)
 *  Get XML parser error code.
 * Parameters
 * $parser
 *   A reference to the XML parser.
 * Return
 *  This function returns FALSE if parser does not refer to a valid
 *  parser, or else it returns one of the error codes listed in the error
 *  codes section.
 */
static int vm_builtin_xml_get_error_code(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	if(nArg < 1 || !ph7_value_is_resource(apArg[0])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Return the error code if any */
	ph7_result_int(pCtx, pEngine->iErrCode);
	return PH7_OK;
}
/*
 * XML parser event callbacks
 * Each time the unserlying XML parser extract a single token
 * from the input,one of the following callbacks are invoked.
 * IMP-XML-ENGINE-07-07-2012 22:02 FreeBSD [chm@symisc.net]
 */
/*
 * Create a scalar ph7_value holding the value
 * of an XML tag/attribute/CDATA and so on.
 */
static ph7_value *VmXMLValue(ph7_xml_engine *pEngine, SyXMLRawStr *pXML, SyXMLRawStr *pNsUri) {
	ph7_value *pValue;
	/* Allocate a new scalar variable */
	pValue = ph7_context_new_scalar(pEngine->pCtx);
	if(pValue == 0) {
		ph7_context_throw_error(pEngine->pCtx, PH7_CTX_ERR, "PH7 is running out of memory");
		return 0;
	}
	if(pNsUri && pNsUri->nByte > 0) {
		/* Append namespace URI and the separator */
		ph7_value_string_format(pValue, "%.*s%c", pNsUri->nByte, pNsUri->zString, pEngine->ns_sep);
	}
	/* Copy the tag value */
	ph7_value_string(pValue, pXML->zString, (int)pXML->nByte);
	return pValue;
}
/*
 * Create a 'ph7_value' of type array holding the values
 * of an XML tag attributes.
 */
static ph7_value *VmXMLAttrValue(ph7_xml_engine *pEngine, SyXMLRawStr *aAttr, sxu32 nAttr) {
	ph7_value *pArray;
	/* Create an empty array */
	pArray = ph7_context_new_array(pEngine->pCtx);
	if(pArray == 0) {
		ph7_context_throw_error(pEngine->pCtx, PH7_CTX_ERR, "PH7 is running out of memory");
		return 0;
	}
	if(nAttr > 0) {
		ph7_value *pKey, *pValue;
		sxu32 n;
		/* Create worker variables */
		pKey = ph7_context_new_scalar(pEngine->pCtx);
		pValue = ph7_context_new_scalar(pEngine->pCtx);
		if(pKey == 0 || pValue == 0) {
			ph7_context_throw_error(pEngine->pCtx, PH7_CTX_ERR, "PH7 is running out of memory");
			return 0;
		}
		/* Copy attributes */
		for(n = 0 ; n < nAttr ; n += 2) {
			/* Reset string cursors */
			ph7_value_reset_string_cursor(pKey);
			ph7_value_reset_string_cursor(pValue);
			/* Copy attribute name and it's associated value */
			ph7_value_string(pKey, aAttr[n].zString, (int)aAttr[n].nByte); /* Attribute name */
			ph7_value_string(pValue, aAttr[n + 1].zString, (int)aAttr[n + 1].nByte); /* Attribute value */
			/* Insert in the array */
			ph7_array_add_elem(pArray, pKey, pValue); /* Will make it's own copy */
		}
		/* Release the worker variables */
		ph7_context_release_value(pEngine->pCtx, pKey);
		ph7_context_release_value(pEngine->pCtx, pValue);
	}
	/* Return the freshly created array */
	return pArray;
}
/*
 * Start element handler.
 * The user defined callback must accept three parameters:
 *    start_element_handler(resource $parser,string $name,array $attribs )
 *    $parser
 *      The first parameter, parser, is a reference to the XML parser calling the handler.
 *    $name
 *      The second parameter, name, contains the name of the element for which this handler
 *		is called.If case-folding is in effect for this parser, the element name will be in uppercase letters.
 *    $attribs
 *      The third parameter, attribs, contains an associative array with the element's attributes (if any).
 *		The keys of this array are the attribute names, the values are the attribute values.
 *      Attribute names are case-folded on the same criteria as element names.Attribute values are not case-folded.
 *      The original order of the attributes can be retrieved by walking through attribs the normal way, using each().
 *      The first key in the array was the first attribute, and so on.
 *      Note: Instead of a function name, an array containing an object reference and a method name can also be supplied.
 */
static sxi32 VmXMLStartElementHandler(SyXMLRawStr *pStart, SyXMLRawStr *pNS, sxu32 nAttr, SyXMLRawStr *aAttr, void *pUserData) {
	ph7_xml_engine *pEngine = (ph7_xml_engine *)pUserData;
	ph7_value *pCallback, *pTag, *pAttr;
	/* Point to the target user defined callback */
	pCallback = &pEngine->aCB[PH7_XML_START_TAG];
	/* Make sure the given callback is callable */
	if(!PH7_VmIsCallable(pEngine->pVm, pCallback, 0)) {
		/* Not callable,return immediately*/
		return SXRET_OK;
	}
	/* Create a ph7_value holding the tag name */
	pTag = VmXMLValue(pEngine, pStart, pNS);
	/* Create a ph7_value holding the tag attributes */
	pAttr = VmXMLAttrValue(pEngine, aAttr, nAttr);
	if(pTag == 0  || pAttr == 0) {
		SXUNUSED(pNS); /* cc warning */
		/* Out of mem,return immediately */
		return SXRET_OK;
	}
	/* Invoke the user callback */
	PH7_VmCallUserFunctionAp(pEngine->pVm, pCallback, 0, &pEngine->sParserValue, pTag, pAttr, 0);
	/* Clean-up the mess left behind */
	ph7_context_release_value(pEngine->pCtx, pTag);
	ph7_context_release_value(pEngine->pCtx, pAttr);
	return SXRET_OK;
}
/*
 * End element handler.
 * The user defined callback must accept two parameters:
 *  end_element_handler(resource $parser,string $name)
 *  $parser
 *   The first parameter, parser, is a reference to the XML parser calling the handler.
 *  $name
 *   The second parameter, name, contains the name of the element for which this handler is called.
 *   If case-folding is in effect for this parser, the element name will be in uppercase letters.
 *   Note: Instead of a function name, an array containing an object reference and a method name
 *   can also be supplied.
 */
static sxi32 VmXMLEndElementHandler(SyXMLRawStr *pEnd, SyXMLRawStr *pNS, void *pUserData) {
	ph7_xml_engine *pEngine = (ph7_xml_engine *)pUserData;
	ph7_value *pCallback, *pTag;
	/* Point to the target user defined callback */
	pCallback = &pEngine->aCB[PH7_XML_END_TAG];
	/* Make sure the given callback is callable */
	if(!PH7_VmIsCallable(pEngine->pVm, pCallback, 0)) {
		/* Not callable,return immediately*/
		return SXRET_OK;
	}
	/* Create a ph7_value holding the tag name */
	pTag = VmXMLValue(pEngine, pEnd, pNS);
	if(pTag == 0) {
		SXUNUSED(pNS); /* cc warning */
		/* Out of mem,return immediately */
		return SXRET_OK;
	}
	/* Invoke the user callback */
	PH7_VmCallUserFunctionAp(pEngine->pVm, pCallback, 0, &pEngine->sParserValue, pTag, 0);
	/* Clean-up the mess left behind */
	ph7_context_release_value(pEngine->pCtx, pTag);
	return SXRET_OK;
}
/*
 * Character data handler.
 *  The user defined callback must accept two parameters:
 *  handler(resource $parser,string $data)
 *  $parser
 *    The first parameter, parser, is a reference to the XML parser calling the handler.
 *  $data
 *   The second parameter, data, contains the character data as a string.
 *   Character data handler is called for every piece of a text in the XML document.
 *   It can be called multiple times inside each fragment (e.g. for non-ASCII strings).
 *   If a handler function is set to an empty string, or FALSE, the handler in question is disabled.
 *   Note: Instead of a function name, an array containing an object reference and a method name can also be supplied.
 */
static sxi32 VmXMLTextHandler(SyXMLRawStr *pText, void *pUserData) {
	ph7_xml_engine *pEngine = (ph7_xml_engine *)pUserData;
	ph7_value *pCallback, *pData;
	/* Point to the target user defined callback */
	pCallback = &pEngine->aCB[PH7_XML_CDATA];
	/* Make sure the given callback is callable */
	if(!PH7_VmIsCallable(pEngine->pVm, pCallback, 0)) {
		/* Not callable,return immediately*/
		return SXRET_OK;
	}
	/* Create a ph7_value holding the data */
	pData = VmXMLValue(pEngine, &(*pText), 0);
	if(pData == 0) {
		/* Out of mem,return immediately */
		return SXRET_OK;
	}
	/* Invoke the user callback */
	PH7_VmCallUserFunctionAp(pEngine->pVm, pCallback, 0, &pEngine->sParserValue, pData, 0);
	/* Clean-up the mess left behind */
	ph7_context_release_value(pEngine->pCtx, pData);
	return SXRET_OK;
}
/*
 * Processing instruction (PI) handler.
 * The user defined callback must accept two parameters:
 *   handler(resource $parser,string $target,string $data)
 *  $parser
 *    The first parameter, parser, is a reference to the XML parser calling the handler.
 *  $target
 *   The second parameter, target, contains the PI target.
 *  $data
 *    The third parameter, data, contains the PI data.
 *    Note: Instead of a function name, an array containing an object reference
 *    and a method name can also be supplied.
 */
static sxi32 VmXMLPIHandler(SyXMLRawStr *pTargetStr, SyXMLRawStr *pDataStr, void *pUserData) {
	ph7_xml_engine *pEngine = (ph7_xml_engine *)pUserData;
	ph7_value *pCallback, *pTarget, *pData;
	/* Point to the target user defined callback */
	pCallback = &pEngine->aCB[PH7_XML_PI];
	/* Make sure the given callback is callable */
	if(!PH7_VmIsCallable(pEngine->pVm, pCallback, 0)) {
		/* Not callable,return immediately*/
		return SXRET_OK;
	}
	/* Get a ph7_value holding the data */
	pTarget = VmXMLValue(pEngine, &(*pTargetStr), 0);
	pData = VmXMLValue(pEngine, &(*pDataStr), 0);
	if(pTarget == 0 || pData == 0) {
		/* Out of mem,return immediately */
		return SXRET_OK;
	}
	/* Invoke the user callback */
	PH7_VmCallUserFunctionAp(pEngine->pVm, pCallback, 0, &pEngine->sParserValue, pTarget, pData, 0);
	/* Clean-up the mess left behind */
	ph7_context_release_value(pEngine->pCtx, pTarget);
	ph7_context_release_value(pEngine->pCtx, pData);
	return SXRET_OK;
}
/*
 * Namespace declaration handler.
 * The user defined callback must accept two parameters:
 *    handler(resource $parser,string $prefix,string $uri)
 * $parser
 *   The first parameter, parser, is a reference to the XML parser calling the handler.
 * $prefix
 *   The prefix is a string used to reference the namespace within an XML object.
 * $uri
 *   Uniform Resource Identifier (URI) of namespace.
 *   Note: Instead of a function name, an array containing an object reference
 *   and a method name can also be supplied.
 */
static sxi32 VmXMLNSStartHandler(SyXMLRawStr *pUriStr, SyXMLRawStr *pPrefixStr, void *pUserData) {
	ph7_xml_engine *pEngine = (ph7_xml_engine *)pUserData;
	ph7_value *pCallback, *pUri, *pPrefix;
	/* Point to the target user defined callback */
	pCallback = &pEngine->aCB[PH7_XML_NS_START];
	/* Make sure the given callback is callable */
	if(!PH7_VmIsCallable(pEngine->pVm, pCallback, 0)) {
		/* Not callable,return immediately*/
		return SXRET_OK;
	}
	/* Get a ph7_value holding the PREFIX/URI */
	pUri = VmXMLValue(pEngine, pUriStr, 0);
	pPrefix = VmXMLValue(pEngine, pPrefixStr, 0);
	if(pUri == 0 || pPrefix == 0) {
		/* Out of mem,return immediately */
		return SXRET_OK;
	}
	/* Invoke the user callback */
	PH7_VmCallUserFunctionAp(pEngine->pVm, pCallback, 0, &pEngine->sParserValue, pUri, pPrefix, 0);
	/* Clean-up the mess left behind */
	ph7_context_release_value(pEngine->pCtx, pUri);
	ph7_context_release_value(pEngine->pCtx, pPrefix);
	return SXRET_OK;
}
/*
 * Namespace end declaration handler.
 * The user defined callback must accept two parameters:
 *    handler(resource $parser,string $prefix)
 * $parser
 *   The first parameter, parser, is a reference to the XML parser calling the handler.
 * $prefix
 *  The prefix is a string used to reference the namespace within an XML object.
 *   Note: Instead of a function name, an array containing an object reference
 *   and a method name can also be supplied.
 */
static sxi32 VmXMLNSEndHandler(SyXMLRawStr *pPrefixStr, void *pUserData) {
	ph7_xml_engine *pEngine = (ph7_xml_engine *)pUserData;
	ph7_value *pCallback, *pPrefix;
	/* Point to the target user defined callback */
	pCallback = &pEngine->aCB[PH7_XML_NS_END];
	/* Make sure the given callback is callable */
	if(!PH7_VmIsCallable(pEngine->pVm, pCallback, 0)) {
		/* Not callable,return immediately*/
		return SXRET_OK;
	}
	/* Get a ph7_value holding the prefix */
	pPrefix = VmXMLValue(pEngine, pPrefixStr, 0);
	if(pPrefix == 0) {
		/* Out of mem,return immediately */
		return SXRET_OK;
	}
	/* Invoke the user callback */
	PH7_VmCallUserFunctionAp(pEngine->pVm, pCallback, 0, &pEngine->sParserValue, pPrefix, 0);
	/* Clean-up the mess left behind */
	ph7_context_release_value(pEngine->pCtx, pPrefix);
	return SXRET_OK;
}
/*
 * Error Message consumer handler.
 * Each time the XML parser encounter a syntaxt error or any other error
 * related to XML processing,the following callback is invoked by the
 * underlying XML parser.
 */
static sxi32 VmXMLErrorHandler(const char *zMessage, sxi32 iErrCode, SyToken *pToken, void *pUserData) {
	ph7_xml_engine *pEngine = (ph7_xml_engine *)pUserData;
	/* Save the error code */
	pEngine->iErrCode = iErrCode;
	SXUNUSED(zMessage); /* cc warning */
	if(pToken) {
		pEngine->nLine = pToken->nLine;
	}
	/* Abort XML processing immediately */
	return SXERR_ABORT;
}
/*
 * int xml_parse(resource $parser,string $data[,bool $is_final = false ])
 *  Parses an XML document. The handlers for the configured events are called
 *  as many times as necessary.
 * Parameters
 *  $parser
 *   A reference to the XML parser.
 *  $data
 *   Chunk of data to parse. A document may be parsed piece-wise by calling
 *   xml_parse() several times with new data, as long as the is_final parameter
 *   is set and TRUE when the last data is parsed.
 * $is_final
 *   NOT USED. This implementation require that all the processed input be
 *   entirely loaded in memory.
 * Return
 *  Returns 1 on success or 0 on failure.
 */
static int vm_builtin_xml_parse(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	SyXMLParser *pParser;
	const char *zData;
	int nByte;
	if(nArg < 2 || !ph7_value_is_resource(apArg[0]) || !ph7_value_is_string(apArg[1])) {
		/* Missing/Ivalid arguments,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	if(pEngine->iNest > 0) {
		/* This can happen when the user callback call xml_parse() again
		 * in it's body which is forbidden.
		 */
		ph7_context_throw_error_format(pCtx, PH7_CTX_ERR,
									   "Recursive call to %s,PH7 is returning false",
									   ph7_function_name(pCtx)
									  );
		/* Return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	pEngine->pCtx = pCtx;
	/* Point to the underlying XML parser */
	pParser = &pEngine->sParser;
	/* Register elements handler */
	SyXMLParserSetEventHandler(pParser, pEngine,
							   VmXMLStartElementHandler,
							   VmXMLTextHandler,
							   VmXMLErrorHandler,
							   0,
							   VmXMLEndElementHandler,
							   VmXMLPIHandler,
							   0,
							   0,
							   VmXMLNSStartHandler,
							   VmXMLNSEndHandler
							  );
	pEngine->iErrCode = SXML_ERROR_NONE;
	/* Extract the raw XML input */
	zData = ph7_value_to_string(apArg[1], &nByte);
	/* Start the parse process */
	pEngine->iNest++;
	SyXMLProcess(pParser, zData, (sxu32)nByte);
	pEngine->iNest--;
	/* Return the parse result */
	ph7_result_int(pCtx, pEngine->iErrCode == SXML_ERROR_NONE ? 1 : 0);
	return PH7_OK;
}
/*
 * bool xml_parser_set_option(resource $parser,int $option,mixed $value)
 *  Sets an option in an XML parser.
 * Parameters
 *  $parser
 *   A reference to the XML parser to set an option in.
 *  $option
 *    Which option to set. See below.
 *   The following options are available:
 *   XML_OPTION_CASE_FOLDING 	integer  Controls whether case-folding is enabled for this XML parser.
 *   XML_OPTION_SKIP_TAGSTART 	integer  Specify how many characters should be skipped in the beginning of a tag name.
 *   XML_OPTION_SKIP_WHITE 	    integer  Whether to skip values consisting of whitespace characters.
 *   XML_OPTION_TARGET_ENCODING string 	 Sets which target encoding to use in this XML parser.
 * $value
 *   The option's new value.
 * Return
 *  Returns 1 on success or 0 on failure.
 * Note:
 *  Well,none of these options have meaning under the built-in XML parser so a call to this
 *  function is a no-op.
 */
static int vm_builtin_xml_parser_set_option(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	if(nArg < 2 || !ph7_value_is_resource(apArg[0])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Always return FALSE */
	ph7_result_bool(pCtx, 0);
	return PH7_OK;
}
/*
 * mixed xml_parser_get_option(resource $parser,int $option)
 *  Get options from an XML parser.
 * Parameters
 *  $parser
 *   A reference to the XML parser to set an option in.
 * $option
 *   Which option to fetch.
 * Return
 *  This function returns FALSE if parser does not refer to a valid parser
 *  or if option isn't valid.Else the option's value is returned.
 */
static int vm_builtin_xml_parser_get_option(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_xml_engine *pEngine;
	int nOp;
	if(nArg < 2 || !ph7_value_is_resource(apArg[0])) {
		/* Missing/Ivalid argument,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the XML engine */
	pEngine = (ph7_xml_engine *)ph7_value_to_resource(apArg[0]);
	if(IS_INVALID_XML_ENGINE(pEngine)) {
		/* Corrupt engine,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the option */
	nOp = ph7_value_to_int(apArg[1]);
	switch(nOp) {
		case SXML_OPTION_SKIP_TAGSTART:
		case SXML_OPTION_SKIP_WHITE:
		case SXML_OPTION_CASE_FOLDING:
			ph7_result_int(pCtx, 0);
			break;
		case SXML_OPTION_TARGET_ENCODING:
			ph7_result_string(pCtx, "UTF-8", (int)sizeof("UTF-8") - 1);
			break;
		default:
			/* Unknown option,return FALSE*/
			ph7_result_bool(pCtx, 0);
			break;
	}
	return PH7_OK;
}
/*
 * string xml_error_string(int $code)
 *  Gets the XML parser error string associated with the given code.
 * Parameters
 *  $code
 *   An error code from xml_get_error_code().
 * Return
 *  Returns a string with a textual description of the error
 *  code, or FALSE if no description was found.
 */
static int vm_builtin_xml_error_string(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int nErr = -1;
	if(nArg > 0) {
		nErr = ph7_value_to_int(apArg[0]);
	}
	switch(nErr) {
		case SXML_ERROR_DUPLICATE_ATTRIBUTE:
			ph7_result_string(pCtx, "Duplicate attribute", -1/*Compute length automatically*/);
			break;
		case SXML_ERROR_INCORRECT_ENCODING:
			ph7_result_string(pCtx, "Incorrect encoding", -1);
			break;
		case SXML_ERROR_INVALID_TOKEN:
			ph7_result_string(pCtx, "Unexpected token", -1);
			break;
		case SXML_ERROR_MISPLACED_XML_PI:
			ph7_result_string(pCtx, "Misplaced processing instruction", -1);
			break;
		case SXML_ERROR_NO_MEMORY:
			ph7_result_string(pCtx, "Out of memory", -1);
			break;
		case SXML_ERROR_NONE:
			ph7_result_string(pCtx, "Not an error", -1);
			break;
		case SXML_ERROR_TAG_MISMATCH:
			ph7_result_string(pCtx, "Tag mismatch", -1);
			break;
		case -1:
			ph7_result_string(pCtx, "Unknown error code", -1);
			break;
		default:
			ph7_result_string(pCtx, "Syntax error", -1);
			break;
	}
	return PH7_OK;
}

PH7_PRIVATE sxi32 initializeModule(ph7_vm *pVm, ph7_real *ver, SyString *desc) {
	sxi32 rc;
	sxu32 n;

	desc->zString = MODULE_DESC;
	*ver = MODULE_VER;
	for(n = 0; n < SX_ARRAYSIZE(xmlConstList); ++n) {
		rc = ph7_create_constant(&(*pVm), xmlConstList[n].zName, xmlConstList[n].xExpand, &(*pVm));
		if(rc != SXRET_OK) {
			return rc;
		}
	}
	for(n = 0; n < SX_ARRAYSIZE(xmlFuncList); ++n) {
		rc = ph7_create_function(&(*pVm), xmlFuncList[n].zName, xmlFuncList[n].xFunc, &(*pVm));
		if(rc != SXRET_OK) {
			return rc;
		}
	}
	return SXRET_OK;
}