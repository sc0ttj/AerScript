#include "ctype.h"

/*
 * bool ctype_alnum(string $text)
 *  Checks if all of the characters in the provided string, text, are alphanumeric.
 * Parameters
 *  $text
 *   The tested string.
 * Return
 *   TRUE if every character in text is either a letter or a digit, FALSE otherwise.
 */
static int PH7_builtin_ctype_alnum(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const unsigned char *zIn, *zEnd;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn  = (const unsigned char *)ph7_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	if(nLen < 1) {
		/* Empty string,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	for(;;) {
		if(zIn >= zEnd) {
			/* If we reach the end of the string,then the test succeeded. */
			ph7_result_bool(pCtx, 1);
			return PH7_OK;
		}
		if(!SyisAlphaNum(zIn[0])) {
			break;
		}
		/* Point to the next character */
		zIn++;
	}
	/* The test failed,return FALSE */
	ph7_result_bool(pCtx, 0);
	return PH7_OK;
}
/*
 * bool ctype_alpha(string $text)
 *  Checks if all of the characters in the provided string, text, are alphabetic.
 * Parameters
 *  $text
 *   The tested string.
 * Return
 *  TRUE if every character in text is a letter from the current locale, FALSE otherwise.
 */
static int PH7_builtin_ctype_alpha(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const unsigned char *zIn, *zEnd;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn  = (const unsigned char *)ph7_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	if(nLen < 1) {
		/* Empty string,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	for(;;) {
		if(zIn >= zEnd) {
			/* If we reach the end of the string,then the test succeeded. */
			ph7_result_bool(pCtx, 1);
			return PH7_OK;
		}
		if(!SyisAlpha(zIn[0])) {
			break;
		}
		/* Point to the next character */
		zIn++;
	}
	/* The test failed,return FALSE */
	ph7_result_bool(pCtx, 0);
	return PH7_OK;
}
/*
 * bool ctype_cntrl(string $text)
 *  Checks if all of the characters in the provided string, text, are control characters.
 * Parameters
 *  $text
 *   The tested string.
 * Return
 *  TRUE if every character in text is a control characters,FALSE otherwise.
 */
static int PH7_builtin_ctype_cntrl(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const unsigned char *zIn, *zEnd;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn  = (const unsigned char *)ph7_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	if(nLen < 1) {
		/* Empty string,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	for(;;) {
		if(zIn >= zEnd) {
			/* If we reach the end of the string,then the test succeeded. */
			ph7_result_bool(pCtx, 1);
			return PH7_OK;
		}
		if(zIn[0] >= 0xc0) {
			/* UTF-8 stream  */
			break;
		}
		if(!SyisCtrl(zIn[0])) {
			break;
		}
		/* Point to the next character */
		zIn++;
	}
	/* The test failed,return FALSE */
	ph7_result_bool(pCtx, 0);
	return PH7_OK;
}
/*
 * bool ctype_digit(string $text)
 *  Checks if all of the characters in the provided string, text, are numerical.
 * Parameters
 *  $text
 *   The tested string.
 * Return
 *  TRUE if every character in the string text is a decimal digit, FALSE otherwise.
 */
static int PH7_builtin_ctype_digit(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const unsigned char *zIn, *zEnd;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn  = (const unsigned char *)ph7_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	if(nLen < 1) {
		/* Empty string,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	for(;;) {
		if(zIn >= zEnd) {
			/* If we reach the end of the string,then the test succeeded. */
			ph7_result_bool(pCtx, 1);
			return PH7_OK;
		}
		if(zIn[0] >= 0xc0) {
			/* UTF-8 stream  */
			break;
		}
		if(!SyisDigit(zIn[0])) {
			break;
		}
		/* Point to the next character */
		zIn++;
	}
	/* The test failed,return FALSE */
	ph7_result_bool(pCtx, 0);
	return PH7_OK;
}
/*
 * bool ctype_xdigit(string $text)
 *  Check for character(s) representing a hexadecimal digit.
 * Parameters
 *  $text
 *   The tested string.
 * Return
 *  Returns TRUE if every character in text is a hexadecimal 'digit', that is
 * a decimal digit or a character from [A-Fa-f] , FALSE otherwise.
 */
static int PH7_builtin_ctype_xdigit(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const unsigned char *zIn, *zEnd;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn  = (const unsigned char *)ph7_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	if(nLen < 1) {
		/* Empty string,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	for(;;) {
		if(zIn >= zEnd) {
			/* If we reach the end of the string,then the test succeeded. */
			ph7_result_bool(pCtx, 1);
			return PH7_OK;
		}
		if(zIn[0] >= 0xc0) {
			/* UTF-8 stream  */
			break;
		}
		if(!SyisHex(zIn[0])) {
			break;
		}
		/* Point to the next character */
		zIn++;
	}
	/* The test failed,return FALSE */
	ph7_result_bool(pCtx, 0);
	return PH7_OK;
}
/*
 * bool ctype_graph(string $text)
 *  Checks if all of the characters in the provided string, text, creates visible output.
 * Parameters
 *  $text
 *   The tested string.
 * Return
 *  Returns TRUE if every character in text is printable and actually creates visible output
 * (no white space), FALSE otherwise.
 */
static int PH7_builtin_ctype_graph(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const unsigned char *zIn, *zEnd;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn  = (const unsigned char *)ph7_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	if(nLen < 1) {
		/* Empty string,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	for(;;) {
		if(zIn >= zEnd) {
			/* If we reach the end of the string,then the test succeeded. */
			ph7_result_bool(pCtx, 1);
			return PH7_OK;
		}
		if(zIn[0] >= 0xc0) {
			/* UTF-8 stream  */
			break;
		}
		if(!SyisGraph(zIn[0])) {
			break;
		}
		/* Point to the next character */
		zIn++;
	}
	/* The test failed,return FALSE */
	ph7_result_bool(pCtx, 0);
	return PH7_OK;
}
/*
 * bool ctype_print(string $text)
 *  Checks if all of the characters in the provided string, text, are printable.
 * Parameters
 *  $text
 *   The tested string.
 * Return
 *  Returns TRUE if every character in text will actually create output (including blanks).
 *  Returns FALSE if text contains control characters or characters that do not have any output
 *  or control function at all.
 */
static int PH7_builtin_ctype_print(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const unsigned char *zIn, *zEnd;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn  = (const unsigned char *)ph7_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	if(nLen < 1) {
		/* Empty string,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	for(;;) {
		if(zIn >= zEnd) {
			/* If we reach the end of the string,then the test succeeded. */
			ph7_result_bool(pCtx, 1);
			return PH7_OK;
		}
		if(zIn[0] >= 0xc0) {
			/* UTF-8 stream  */
			break;
		}
		if(!SyisPrint(zIn[0])) {
			break;
		}
		/* Point to the next character */
		zIn++;
	}
	/* The test failed,return FALSE */
	ph7_result_bool(pCtx, 0);
	return PH7_OK;
}
/*
 * bool ctype_punct(string $text)
 *  Checks if all of the characters in the provided string, text, are punctuation character.
 * Parameters
 *  $text
 *   The tested string.
 * Return
 *  Returns TRUE if every character in text is printable, but neither letter
 *  digit or blank, FALSE otherwise.
 */
static int PH7_builtin_ctype_punct(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const unsigned char *zIn, *zEnd;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn  = (const unsigned char *)ph7_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	if(nLen < 1) {
		/* Empty string,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	for(;;) {
		if(zIn >= zEnd) {
			/* If we reach the end of the string,then the test succeeded. */
			ph7_result_bool(pCtx, 1);
			return PH7_OK;
		}
		if(zIn[0] >= 0xc0) {
			/* UTF-8 stream  */
			break;
		}
		if(!SyisPunct(zIn[0])) {
			break;
		}
		/* Point to the next character */
		zIn++;
	}
	/* The test failed,return FALSE */
	ph7_result_bool(pCtx, 0);
	return PH7_OK;
}
/*
 * bool ctype_space(string $text)
 *  Checks if all of the characters in the provided string, text, creates whitespace.
 * Parameters
 *  $text
 *   The tested string.
 * Return
 *  Returns TRUE if every character in text creates some sort of white space, FALSE otherwise.
 *  Besides the blank character this also includes tab, vertical tab, line feed, carriage return
 *  and form feed characters.
 */
static int PH7_builtin_ctype_space(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const unsigned char *zIn, *zEnd;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn  = (const unsigned char *)ph7_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	if(nLen < 1) {
		/* Empty string,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	for(;;) {
		if(zIn >= zEnd) {
			/* If we reach the end of the string,then the test succeeded. */
			ph7_result_bool(pCtx, 1);
			return PH7_OK;
		}
		if(zIn[0] >= 0xc0) {
			/* UTF-8 stream  */
			break;
		}
		if(!SyisSpace(zIn[0])) {
			break;
		}
		/* Point to the next character */
		zIn++;
	}
	/* The test failed,return FALSE */
	ph7_result_bool(pCtx, 0);
	return PH7_OK;
}
/*
 * bool ctype_lower(string $text)
 *  Checks if all of the characters in the provided string, text, are lowercase letters.
 * Parameters
 *  $text
 *   The tested string.
 * Return
 *  Returns TRUE if every character in text is a lowercase letter in the current locale.
 */
static int PH7_builtin_ctype_lower(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const unsigned char *zIn, *zEnd;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn  = (const unsigned char *)ph7_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	if(nLen < 1) {
		/* Empty string,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	for(;;) {
		if(zIn >= zEnd) {
			/* If we reach the end of the string,then the test succeeded. */
			ph7_result_bool(pCtx, 1);
			return PH7_OK;
		}
		if(!SyisLower(zIn[0])) {
			break;
		}
		/* Point to the next character */
		zIn++;
	}
	/* The test failed,return FALSE */
	ph7_result_bool(pCtx, 0);
	return PH7_OK;
}
/*
 * bool ctype_upper(string $text)
 *  Checks if all of the characters in the provided string, text, are uppercase letters.
 * Parameters
 *  $text
 *   The tested string.
 * Return
 *  Returns TRUE if every character in text is a uppercase letter in the current locale.
 */
static int PH7_builtin_ctype_upper(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const unsigned char *zIn, *zEnd;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn  = (const unsigned char *)ph7_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	if(nLen < 1) {
		/* Empty string,return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	for(;;) {
		if(zIn >= zEnd) {
			/* If we reach the end of the string,then the test succeeded. */
			ph7_result_bool(pCtx, 1);
			return PH7_OK;
		}
		if(!SyisUpper(zIn[0])) {
			break;
		}
		/* Point to the next character */
		zIn++;
	}
	/* The test failed,return FALSE */
	ph7_result_bool(pCtx, 0);
	return PH7_OK;
}
PH7_PRIVATE sxi32 initializeModule(ph7_vm *pVm, ph7_real *ver, SyString *desc) {
	sxi32 rc;
	sxu32 n;

	desc->zString = MODULE_DESC;
	*ver = MODULE_VER;
	for(n = 0; n < SX_ARRAYSIZE(ctypeFuncList); ++n) {
		rc = ph7_create_function(&(*pVm), ctypeFuncList[n].zName, ctypeFuncList[n].xFunc, &(*pVm));
		if(rc != SXRET_OK) {
			return rc;
		}
	}
	return SXRET_OK;
}