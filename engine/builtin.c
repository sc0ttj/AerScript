/**
 * @PROJECT     PH7 Engine for the AerScript Interpreter
 * @COPYRIGHT   See COPYING in the top level directory
 * @FILE        engine/builtin.c
 * @DESCRIPTION Built-in foreign functions for the PH7 Engine
 * @DEVELOPERS  Symisc Systems <devel@symisc.net>
 *              Rafal Kupiec <belliash@codingworkshop.eu.org>
 */
#include "ph7int.h"
/*
 * Section:
 *    Variable handling Functions.
 * Authors:
 *    Symisc Systems,devel@symisc.net.
 *    Copyright (C) Symisc Systems,https://ph7.symisc.net
 * Status:
 *    Stable.
 */
/*
 * bool is_bool($var)
 *  Finds out whether a variable is a boolean.
 * Parameters
 *   $var: The variable being evaluated.
 * Return
 *  TRUE if var is a boolean. False otherwise.
 */
static int PH7_builtin_is_bool(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int res = 0; /* Assume false by default */
	if(nArg > 0) {
		res = ph7_value_is_bool(apArg[0]);
	}
	/* Query result */
	ph7_result_bool(pCtx, res);
	return PH7_OK;
}
/*
 * bool is_callback($var)
 *  Finds out whether a variable is a callback.
 * Parameters
 *   $var: The variable being evaluated.
 * Return
 *  TRUE if var is a callback. False otherwise.
 */
static int PH7_builtin_is_callback(ph7_context *pCtx, int nArg, ph7_value **apArg) {
        int res = 0; /* Assume false by default */
        if(nArg > 0) {
                res = ph7_value_is_callback(apArg[0]);
        }
        /* Query result */
        ph7_result_bool(pCtx, res);
        return PH7_OK;
}
/*
 * bool is_char($var)
 *  Finds out whether a variable is a character.
 * Parameters
 *   $var: The variable being evaluated.
 * Return
 *  TRUE if var is a character. False otherwise.
 */
static int PH7_builtin_is_char(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int res = 0; /* Assume false by default */
	if(nArg > 0) {
		res = ph7_value_is_char(apArg[0]);
	}
	/* Query result */
	ph7_result_bool(pCtx, res);
	return PH7_OK;
}
/*
 * bool is_float($var)
 *  Finds out whether a variable is a float.
 * Parameters
 *   $var: The variable being evaluated.
 * Return
 *  TRUE if var is a float. False otherwise.
 */
static int PH7_builtin_is_float(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int res = 0; /* Assume false by default */
	if(nArg > 0) {
		res = ph7_value_is_float(apArg[0]);
	}
	/* Query result */
	ph7_result_bool(pCtx, res);
	return PH7_OK;
}
/*
 * bool is_int($var)
 *  Finds out whether a variable is an integer.
 * Parameters
 *   $var: The variable being evaluated.
 * Return
 *  TRUE if var is an integer. False otherwise.
 */
static int PH7_builtin_is_int(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int res = 0; /* Assume false by default */
	if(nArg > 0) {
		res = ph7_value_is_int(apArg[0]);
	}
	/* Query result */
	ph7_result_bool(pCtx, res);
	return PH7_OK;
}
/*
 * bool is_string($var)
 *  Finds out whether a variable is a string.
 * Parameters
 *   $var: The variable being evaluated.
 * Return
 *  TRUE if var is string. False otherwise.
 */
static int PH7_builtin_is_string(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int res = 0; /* Assume false by default */
	if(nArg > 0) {
		res = ph7_value_is_string(apArg[0]);
	}
	/* Query result */
	ph7_result_bool(pCtx, res);
	return PH7_OK;
}
/*
 * bool is_void($var)
 *  Finds out whether a variable is a void.
 * Parameters
 *   $var: The variable being evaluated.
 * Return
 *  TRUE if var is void. False otherwise.
 */
static int PH7_builtin_is_void(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int res = 0; /* Assume false by default */
	if(nArg > 0) {
		res = ph7_value_is_void(apArg[0]);
	}
	/* Query result */
	ph7_result_bool(pCtx, res);
	return PH7_OK;
}
/*
 * bool is_numeric($var)
 *  Find out whether a variable is NULL.
 * Parameters
 *  $var: The variable being evaluated.
 * Return
 *  True if var is numeric. False otherwise.
 */
static int PH7_builtin_is_numeric(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int res = 0; /* Assume false by default */
	if(nArg > 0) {
		res = ph7_value_is_numeric(apArg[0]);
	}
	/* Query result */
	ph7_result_bool(pCtx, res);
	return PH7_OK;
}
/*
 * bool is_array($var)
 *  Find out whether a variable is an array.
 * Parameters
 *  $var: The variable being evaluated.
 * Return
 *  True if var is an array. False otherwise.
 */
static int PH7_builtin_is_array(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int res = 0; /* Assume false by default */
	if(nArg > 0) {
		res = ph7_value_is_array(apArg[0]);
	}
	/* Query result */
	ph7_result_bool(pCtx, res);
	return PH7_OK;
}
/*
 * bool is_object($var)
 *  Find out whether a variable is an object.
 * Parameters
 *  $var: The variable being evaluated.
 * Return
 *  True if var is an object. False otherwise.
 */
static int PH7_builtin_is_object(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int res = 0; /* Assume false by default */
	if(nArg > 0) {
		res = ph7_value_is_object(apArg[0]);
	}
	/* Query result */
	ph7_result_bool(pCtx, res);
	return PH7_OK;
}
/*
 * bool is_resource($var)
 *  Find out whether a variable is a resource.
 * Parameters
 *  $var: The variable being evaluated.
 * Return
 *  True if a resource. False otherwise.
 */
static int PH7_builtin_is_resource(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int res = 0; /* Assume false by default */
	if(nArg > 0) {
		res = ph7_value_is_resource(apArg[0]);
	}
	ph7_result_bool(pCtx, res);
	return PH7_OK;
}
/*
 * float round ( float $val [, int $precision = 0 [, int $mode = PHP_ROUND_HALF_UP ]] )
 *  Exponential expression.
 * Parameter
 *  $val
 *   The value to round.
 * $precision
 *   The optional number of decimal digits to round to.
 * $mode
 *   One of PHP_ROUND_HALF_UP, PHP_ROUND_HALF_DOWN, PHP_ROUND_HALF_EVEN, or PHP_ROUND_HALF_ODD.
 *   (not supported).
 * Return
 *  The rounded value.
 */
static int PH7_builtin_round(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int n = 0;
	double r;
	if(nArg < 1) {
		/* Missing argument, return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the precision if available */
	if(nArg > 1) {
		n = ph7_value_to_int(apArg[1]);
		if(n > 30) {
			n = 30;
		}
		if(n < 0) {
			n = 0;
		}
	}
	r = ph7_value_to_double(apArg[0]);
	/* If Y==0 and X will fit in a 64-bit int,
	 * handle the rounding directly.Otherwise
	 * use our own custom printf [i.e:SyBufferFormat()].
	 */
	if(n == 0 && r >= 0 && r < LARGEST_INT64 - 1) {
		r = (double)((ph7_int64)(r + 0.5));
	} else if(n == 0 && r < 0 && (-r) < LARGEST_INT64 - 1) {
		r = -(double)((ph7_int64)((-r) + 0.5));
	} else {
		char zBuf[256];
		sxu32 nLen;
		nLen = SyBufferFormat(zBuf, sizeof(zBuf), "%.*f", n, r);
		/* Convert the string to real number */
		SyStrToReal(zBuf, nLen, (void *)&r, 0);
	}
	/* Return thr rounded value */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * string dechex(int $number)
 *  Decimal to hexadecimal.
 * Parameters
 *  $number
 *   Decimal value to convert
 * Return
 *  Hexadecimal string representation of number
 */
static int PH7_builtin_dechex(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int iVal;
	if(nArg < 1) {
		/* Missing arguments, return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the given number */
	iVal = ph7_value_to_int(apArg[0]);
	/* Format */
	ph7_result_string_format(pCtx, "%x", iVal);
	return PH7_OK;
}
/*
 * string decoct(int $number)
 *  Decimal to Octal.
 * Parameters
 *  $number
 *   Decimal value to convert
 * Return
 *  Octal string representation of number
 */
static int PH7_builtin_decoct(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int iVal;
	if(nArg < 1) {
		/* Missing arguments, return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the given number */
	iVal = ph7_value_to_int(apArg[0]);
	/* Format */
	ph7_result_string_format(pCtx, "%o", iVal);
	return PH7_OK;
}
/*
 * string decbin(int $number)
 *  Decimal to binary.
 * Parameters
 *  $number
 *   Decimal value to convert
 * Return
 *  Binary string representation of number
 */
static int PH7_builtin_decbin(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int iVal;
	if(nArg < 1) {
		/* Missing arguments, return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the given number */
	iVal = ph7_value_to_int(apArg[0]);
	/* Format */
	ph7_result_string_format(pCtx, "%B", iVal);
	return PH7_OK;
}
/*
 * int64 hexdec(string $hex_string)
 *  Hexadecimal to decimal.
 * Parameters
 *  $hex_string
 *   The hexadecimal string to convert
 * Return
 *  The decimal representation of hex_string
 */
static int PH7_builtin_hexdec(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zString, *zEnd;
	ph7_int64 iVal;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return -1 */
		ph7_result_int(pCtx, -1);
		return PH7_OK;
	}
	iVal = 0;
	if(ph7_value_is_string(apArg[0])) {
		/* Extract the given string */
		zString = ph7_value_to_string(apArg[0], &nLen);
		/* Delimit the string */
		zEnd = &zString[nLen];
		/* Ignore non hex-stream */
		while(zString < zEnd) {
			if((unsigned char)zString[0] >= 0xc0) {
				/* UTF-8 stream */
				zString++;
				while(zString < zEnd && (((unsigned char)zString[0] & 0xc0) == 0x80)) {
					zString++;
				}
			} else {
				if(SyisHex(zString[0])) {
					break;
				}
				/* Ignore */
				zString++;
			}
		}
		if(zString < zEnd) {
			/* Cast */
			SyHexStrToInt64(zString, (sxu32)(zEnd - zString), (void *)&iVal, 0);
		}
	} else {
		/* Extract as a 64-bit integer */
		iVal = ph7_value_to_int64(apArg[0]);
	}
	/* Return the number */
	ph7_result_int64(pCtx, iVal);
	return PH7_OK;
}
/*
 * int64 bindec(string $bin_string)
 *  Binary to decimal.
 * Parameters
 *  $bin_string
 *   The binary string to convert
 * Return
 *  Returns the decimal equivalent of the binary number represented by the binary_string argument.
 */
static int PH7_builtin_bindec(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zString;
	ph7_int64 iVal;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return -1 */
		ph7_result_int(pCtx, -1);
		return PH7_OK;
	}
	iVal = 0;
	if(ph7_value_is_string(apArg[0])) {
		/* Extract the given string */
		zString = ph7_value_to_string(apArg[0], &nLen);
		if(nLen > 0) {
			/* Perform a binary cast */
			SyBinaryStrToInt64(zString, (sxu32)nLen, (void *)&iVal, 0);
		}
	} else {
		/* Extract as a 64-bit integer */
		iVal = ph7_value_to_int64(apArg[0]);
	}
	/* Return the number */
	ph7_result_int64(pCtx, iVal);
	return PH7_OK;
}
/*
 * int64 octdec(string $oct_string)
 *  Octal to decimal.
 * Parameters
 *  $oct_string
 *   The octal string to convert
 * Return
 *  Returns the decimal equivalent of the octal number represented by the octal_string argument.
 */
static int PH7_builtin_octdec(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zString;
	ph7_int64 iVal;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return -1 */
		ph7_result_int(pCtx, -1);
		return PH7_OK;
	}
	iVal = 0;
	if(ph7_value_is_string(apArg[0])) {
		/* Extract the given string */
		zString = ph7_value_to_string(apArg[0], &nLen);
		if(nLen > 0) {
			/* Perform the cast */
			SyOctalStrToInt64(zString, (sxu32)nLen, (void *)&iVal, 0);
		}
	} else {
		/* Extract as a 64-bit integer */
		iVal = ph7_value_to_int64(apArg[0]);
	}
	/* Return the number */
	ph7_result_int64(pCtx, iVal);
	return PH7_OK;
}
/*
 * srand([int $seed])
 * mt_srand([int $seed])
 *  Seed the random number generator.
 * Parameters
 * $seed
 *  Optional seed value
 * Return
 *  null.
 * Note:
 *  THIS FUNCTION IS A NO-OP.
 *  THE PH7 PRNG IS AUTOMATICALLY SEEDED WHEN THE VM IS CREATED.
 */
static int PH7_builtin_srand(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	SXUNUSED(nArg);
	SXUNUSED(apArg);
	ph7_result_null(pCtx);
	return PH7_OK;
}
/*
 * string base_convert(string $number,int $frombase,int $tobase)
 *  Convert a number between arbitrary bases.
 * Parameters
 * $number
 *  The number to convert
 * $frombase
 *  The base number is in
 * $tobase
 *  The base to convert number to
 * Return
 *  Number converted to base tobase
 */
static int PH7_builtin_base_convert(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int nLen, iFbase, iTobase;
	const char *zNum;
	ph7_int64 iNum;
	if(nArg < 3) {
		/* Return the empty string*/
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Base numbers */
	iFbase  = ph7_value_to_int(apArg[1]);
	iTobase = ph7_value_to_int(apArg[2]);
	if(ph7_value_is_string(apArg[0])) {
		/* Extract the target number */
		zNum = ph7_value_to_string(apArg[0], &nLen);
		if(nLen < 1) {
			/* Return the empty string*/
			ph7_result_string(pCtx, "", 0);
			return PH7_OK;
		}
		/* Base conversion */
		switch(iFbase) {
			case 16:
				/* Hex */
				SyHexStrToInt64(zNum, (sxu32)nLen, (void *)&iNum, 0);
				break;
			case 8:
				/* Octal */
				SyOctalStrToInt64(zNum, (sxu32)nLen, (void *)&iNum, 0);
				break;
			case 2:
				/* Binary */
				SyBinaryStrToInt64(zNum, (sxu32)nLen, (void *)&iNum, 0);
				break;
			default:
				/* Decimal */
				SyStrToInt64(zNum, (sxu32)nLen, (void *)&iNum, 0);
				break;
		}
	} else {
		iNum = ph7_value_to_int64(apArg[0]);
	}
	switch(iTobase) {
		case 16:
			/* Hex */
			ph7_result_string_format(pCtx, "%qx", iNum); /* Quad hex */
			break;
		case 8:
			/* Octal */
			ph7_result_string_format(pCtx, "%qo", iNum); /* Quad octal */
			break;
		case 2:
			/* Binary */
			ph7_result_string_format(pCtx, "%qB", iNum); /* Quad binary */
			break;
		default:
			/* Decimal */
			ph7_result_string_format(pCtx, "%qd", iNum); /* Quad decimal */
			break;
	}
	return PH7_OK;
}
/*
 * Section:
 *    String handling Functions.
 * Authors:
 *    Symisc Systems,devel@symisc.net.
 *    Copyright (C) Symisc Systems,https://ph7.symisc.net
 * Status:
 *    Stable.
 */
/*
 * string substr(string $string,int $start[, int $length ])
 *  Return part of a string.
 * Parameters
 *  $string
 *   The input string. Must be one character or longer.
 * $start
 *   If start is non-negative, the returned string will start at the start'th position
 *   in string, counting from zero. For instance, in the string 'abcdef', the character
 *   at position 0 is 'a', the character at position 2 is 'c', and so forth.
 *   If start is negative, the returned string will start at the start'th character
 *   from the end of string.
 *   If string is less than or equal to start characters long, FALSE will be returned.
 * $length
 *   If length is given and is positive, the string returned will contain at most length
 *   characters beginning from start (depending on the length of string).
 *   If length is given and is negative, then that many characters will be omitted from
 *   the end of string (after the start position has been calculated when a start is negative).
 *   If start denotes the position of this truncation or beyond, false will be returned.
 *   If length is given and is 0, FALSE or NULL an empty string will be returned.
 *   If length is omitted, the substring starting from start until the end of the string
 *   will be returned.
 * Return
 *  Returns the extracted part of string, or FALSE on failure or an empty string.
 */
static int PH7_builtin_substr(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zSource, *zOfft;
	int nOfft, nLen, nSrcLen;
	if(nArg < 2) {
		/* return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zSource = ph7_value_to_string(apArg[0], &nSrcLen);
	if(nSrcLen < 1) {
		/* Empty string, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	nLen = nSrcLen; /* cc warning */
	/* Extract the offset */
	nOfft = ph7_value_to_int(apArg[1]);
	if(nOfft < 0) {
		zOfft = &zSource[nSrcLen + nOfft];
		if(zOfft < zSource) {
			/* Invalid offset */
			ph7_result_bool(pCtx, 0);
			return PH7_OK;
		}
		nLen = (int)(&zSource[nSrcLen] - zOfft);
		nOfft = (int)(zOfft - zSource);
	} else if(nOfft >= nSrcLen) {
		/* Invalid offset */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	} else {
		zOfft = &zSource[nOfft];
		nLen = nSrcLen - nOfft;
	}
	if(nArg > 2) {
		/* Extract the length */
		nLen = ph7_value_to_int(apArg[2]);
		if(nLen == 0) {
			/* Invalid length, return an empty string */
			ph7_result_string(pCtx, "", 0);
			return PH7_OK;
		} else if(nLen < 0) {
			nLen = nSrcLen + nLen - nOfft;
			if(nLen < 1) {
				/* Invalid  length */
				nLen = nSrcLen - nOfft;
			}
		}
		if(nLen + nOfft > nSrcLen) {
			/* Invalid length */
			nLen = nSrcLen - nOfft;
		}
	}
	/* Return the substring */
	ph7_result_string(pCtx, zOfft, nLen);
	return PH7_OK;
}
/*
 * int substr_compare(string $main_str,string $str ,int $offset[,int $length[,bool $case_insensitivity = false ]])
 *  Binary safe comparison of two strings from an offset, up to length characters.
 * Parameters
 *  $main_str
 *  The main string being compared.
 *  $str
 *   The secondary string being compared.
 * $offset
 *  The start position for the comparison. If negative, it starts counting from
 *  the end of the string.
 * $length
 *  The length of the comparison. The default value is the largest of the length
 *  of the str compared to the length of main_str less the offset.
 * $case_insensitivity
 *  If case_insensitivity is TRUE, comparison is case insensitive.
 * Return
 *  Returns < 0 if main_str from position offset is less than str, > 0 if it is greater than
 *  str, and 0 if they are equal. If offset is equal to or greater than the length of main_str
 *  or length is set and is less than 1, substr_compare() prints a warning and returns FALSE.
 */
static int PH7_builtin_substr_compare(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zSource, *zOfft, *zSub;
	int nOfft, nLen, nSrcLen, nSublen;
	int iCase = 0;
	int rc;
	if(nArg < 3) {
		/* Missing arguments, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zSource = ph7_value_to_string(apArg[0], &nSrcLen);
	if(nSrcLen < 1) {
		/* Empty string, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	nLen = nSrcLen; /* cc warning */
	/* Extract the substring */
	zSub = ph7_value_to_string(apArg[1], &nSublen);
	if(nSublen < 1 || nSublen > nSrcLen) {
		/* Empty string, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the offset */
	nOfft = ph7_value_to_int(apArg[2]);
	if(nOfft < 0) {
		zOfft = &zSource[nSrcLen + nOfft];
		if(zOfft < zSource) {
			/* Invalid offset */
			ph7_result_bool(pCtx, 0);
			return PH7_OK;
		}
		nLen = (int)(&zSource[nSrcLen] - zOfft);
		nOfft = (int)(zOfft - zSource);
	} else if(nOfft >= nSrcLen) {
		/* Invalid offset */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	} else {
		zOfft = &zSource[nOfft];
		nLen = nSrcLen - nOfft;
	}
	if(nArg > 3) {
		/* Extract the length */
		nLen = ph7_value_to_int(apArg[3]);
		if(nLen < 1) {
			/* Invalid  length */
			ph7_result_int(pCtx, 1);
			return PH7_OK;
		} else if(nLen + nOfft > nSrcLen) {
			/* Invalid length */
			nLen = nSrcLen - nOfft;
		}
		if(nArg > 4) {
			/* Case-sensitive or not */
			iCase = ph7_value_to_bool(apArg[4]);
		}
	}
	/* Perform the comparison */
	if(iCase) {
		rc = SyStrnicmp(zOfft, zSub, (sxu32)nLen);
	} else {
		rc = SyStrncmp(zOfft, zSub, (sxu32)nLen);
	}
	/* Comparison result */
	ph7_result_int(pCtx, rc);
	return PH7_OK;
}
/*
 * int substr_count(string $haystack,string $needle[,int $offset = 0 [,int $length ]])
 *  Count the number of substring occurrences.
 * Parameters
 * $haystack
 *   The string to search in
 * $needle
 *   The substring to search for
 * $offset
 *  The offset where to start counting
 * $length (NOT USED)
 *  The maximum length after the specified offset to search for the substring.
 *  It outputs a warning if the offset plus the length is greater than the haystack length.
 * Return
 *  Toral number of substring occurrences.
 */
static int PH7_builtin_substr_count(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zText, *zPattern, *zEnd;
	int nTextlen, nPatlen;
	int iCount = 0;
	sxu32 nOfft;
	sxi32 rc;
	if(nArg < 2) {
		/* Missing arguments */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the haystack */
	zText = ph7_value_to_string(apArg[0], &nTextlen);
	/* Point to the neddle */
	zPattern = ph7_value_to_string(apArg[1], &nPatlen);
	if(nTextlen < 1 || nPatlen < 1 || nPatlen > nTextlen) {
		/* NOOP, return zero */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	if(nArg > 2) {
		int nOfft;
		/* Extract the offset */
		nOfft = ph7_value_to_int(apArg[2]);
		if(nOfft < 0 || nOfft > nTextlen) {
			/* Invalid offset, return zero */
			ph7_result_int(pCtx, 0);
			return PH7_OK;
		}
		/* Point to the desired offset */
		zText = &zText[nOfft];
		/* Adjust length */
		nTextlen -= nOfft;
	}
	/* Point to the end of the string */
	zEnd = &zText[nTextlen];
	if(nArg > 3) {
		int nLen;
		/* Extract the length */
		nLen = ph7_value_to_int(apArg[3]);
		if(nLen < 0 || nLen > nTextlen) {
			/* Invalid length, return 0 */
			ph7_result_int(pCtx, 0);
			return PH7_OK;
		}
		/* Adjust pointer */
		nTextlen = nLen;
		zEnd = &zText[nTextlen];
	}
	/* Perform the search */
	for(;;) {
		rc = SyBlobSearch((const void *)zText, (sxu32)(zEnd - zText), (const void *)zPattern, nPatlen, &nOfft);
		if(rc != SXRET_OK) {
			/* Pattern not found,break immediately */
			break;
		}
		/* Increment counter and update the offset */
		iCount++;
		zText += nOfft + nPatlen;
		if(zText >= zEnd) {
			break;
		}
	}
	/* Pattern count */
	ph7_result_int(pCtx, iCount);
	return PH7_OK;
}
/*
 * string chunk_split(string $body[,int $chunklen = 76 [, string $end = "\r\n" ]])
 *   Split a string into smaller chunks.
 * Parameters
 *  $body
 *   The string to be chunked.
 * $chunklen
 *   The chunk length.
 * $end
 *   The line ending sequence.
 * Return
 *  The chunked string or NULL on failure.
 */
static int PH7_builtin_chunk_split(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zIn, *zEnd, *zSep = "\r\n";
	int nSepLen, nChunkLen, nLen;
	if(nArg < 1 || !ph7_value_is_string(apArg[0])) {
		/* Nothing to split, return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* initialize/Extract arguments */
	nSepLen = (int)sizeof("\r\n") - 1;
	nChunkLen = 76;
	zIn = ph7_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	if(nArg > 1) {
		/* Chunk length */
		nChunkLen = ph7_value_to_int(apArg[1]);
		if(nChunkLen < 1) {
			/* Switch back to the default length */
			nChunkLen = 76;
		}
		if(nArg > 2) {
			/* Separator */
			zSep = ph7_value_to_string(apArg[2], &nSepLen);
			if(nSepLen < 1) {
				/* Switch back to the default separator */
				zSep = "\r\n";
				nSepLen = (int)sizeof("\r\n") - 1;
			}
		}
	}
	/* Perform the requested operation */
	if(nChunkLen > nLen) {
		/* Nothing to split, return the string and the separator */
		ph7_result_string_format(pCtx, "%.*s%.*s", nLen, zIn, nSepLen, zSep);
		return PH7_OK;
	}
	while(zIn < zEnd) {
		if(nChunkLen > (int)(zEnd - zIn)) {
			nChunkLen = (int)(zEnd - zIn);
		}
		/* Append the chunk and the separator */
		ph7_result_string_format(pCtx, "%.*s%.*s", nChunkLen, zIn, nSepLen, zSep);
		/* Point beyond the chunk */
		zIn += nChunkLen;
	}
	return PH7_OK;
}
/*
 * string addslashes(string $str)
 *  Quote string with slashes.
 *  Returns a string with backslashes before characters that need
 *  to be quoted in database queries etc. These characters are single
 *  quote ('), double quote ("), backslash (\) and NUL (the NULL byte).
 * Parameter
 *  str: The string to be escaped.
 * Return
 *  Returns the escaped string
 */
static int PH7_builtin_addslashes(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zCur, *zIn, *zEnd;
	int nLen;
	if(nArg < 1) {
		/* Nothing to process,retun NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the string to process */
	zIn  = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Return the empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	zEnd = &zIn[nLen];
	zCur = 0; /* cc warning */
	for(;;) {
		if(zIn >= zEnd) {
			/* No more input */
			break;
		}
		zCur = zIn;
		while(zIn < zEnd && zIn[0] != '\'' && zIn[0] != '"' && zIn[0] != '\\') {
			zIn++;
		}
		if(zIn > zCur) {
			/* Append raw contents */
			ph7_result_string(pCtx, zCur, (int)(zIn - zCur));
		}
		if(zIn < zEnd) {
			int c = zIn[0];
			ph7_result_string_format(pCtx, "\\%c", c);
		}
		zIn++;
	}
	return PH7_OK;
}
/*
 * Check if the given character is present in the given mask.
 * Return TRUE if present. FALSE otherwise.
 */
static int cSlashCheckMask(int c, const char *zMask, int nLen) {
	const char *zEnd = &zMask[nLen];
	while(zMask < zEnd) {
		if(zMask[0] == c) {
			/* Character present, return TRUE */
			return 1;
		}
		/* Advance the pointer */
		zMask++;
	}
	/* Not present */
	return 0;
}
/*
 * string addcslashes(string $str,string $charlist)
 *  Quote string with slashes in a C style.
 * Parameter
 *  $str:
 *    The string to be escaped.
 *  $charlist:
 *    A list of characters to be escaped. If charlist contains characters \n, \r etc.
 *    they are converted in C-like style, while other non-alphanumeric characters
 *    with ASCII codes lower than 32 and higher than 126 converted to octal representation.
 * Return
 *  Returns the escaped string.
 * Note:
 *  Range characters [i.e: 'A..Z'] is not implemented in the current release.
 */
static int PH7_builtin_addcslashes(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zCur, *zIn, *zEnd, *zMask;
	int nLen, nMask;
	if(nArg < 1) {
		/* Nothing to process,retun NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the string to process */
	zIn  = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1 || nArg < 2) {
		/* Return the string untouched */
		ph7_result_string(pCtx, zIn, nLen);
		return PH7_OK;
	}
	/* Extract the desired mask */
	zMask = ph7_value_to_string(apArg[1], &nMask);
	zEnd = &zIn[nLen];
	zCur = 0; /* cc warning */
	for(;;) {
		if(zIn >= zEnd) {
			/* No more input */
			break;
		}
		zCur = zIn;
		while(zIn < zEnd && !cSlashCheckMask(zIn[0], zMask, nMask)) {
			zIn++;
		}
		if(zIn > zCur) {
			/* Append raw contents */
			ph7_result_string(pCtx, zCur, (int)(zIn - zCur));
		}
		if(zIn < zEnd) {
			int c = zIn[0];
			if(c > 126 || (c < 32 && (!SyisAlphaNum(c)/*EBCDIC*/ && !SyisSpace(c)))) {
				/* Convert to octal */
				ph7_result_string_format(pCtx, "\\%o", c);
			} else {
				ph7_result_string_format(pCtx, "\\%c", c);
			}
		}
		zIn++;
	}
	return PH7_OK;
}
/*
 * string quotemeta(string $str)
 *  Quote meta characters.
 * Parameter
 *  $str:
 *    The string to be escaped.
 * Return
 *  Returns the escaped string.
*/
static int PH7_builtin_quotemeta(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zCur, *zIn, *zEnd;
	int nLen;
	if(nArg < 1) {
		/* Nothing to process,retun NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the string to process */
	zIn  = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Return the empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	zEnd = &zIn[nLen];
	zCur = 0; /* cc warning */
	for(;;) {
		if(zIn >= zEnd) {
			/* No more input */
			break;
		}
		zCur = zIn;
		while(zIn < zEnd && !cSlashCheckMask(zIn[0], ".\\+*?[^]($)", (int)sizeof(".\\+*?[^]($)") - 1)) {
			zIn++;
		}
		if(zIn > zCur) {
			/* Append raw contents */
			ph7_result_string(pCtx, zCur, (int)(zIn - zCur));
		}
		if(zIn < zEnd) {
			int c = zIn[0];
			ph7_result_string_format(pCtx, "\\%c", c);
		}
		zIn++;
	}
	return PH7_OK;
}
/*
 * string stripslashes(string $str)
 *  Un-quotes a quoted string.
 *  Returns a string with backslashes before characters that need
 *  to be quoted in database queries etc. These characters are single
 *  quote ('), double quote ("), backslash (\) and NUL (the NULL byte).
 * Parameter
 *  $str
 *   The input string.
 * Return
 *  Returns a string with backslashes stripped off.
 */
static int PH7_builtin_stripslashes(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zCur, *zIn, *zEnd;
	int nLen;
	if(nArg < 1) {
		/* Nothing to process,retun NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the string to process */
	zIn  = ph7_value_to_string(apArg[0], &nLen);
	if(zIn == 0) {
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	zEnd = &zIn[nLen];
	zCur = 0; /* cc warning */
	/* Encode the string */
	for(;;) {
		if(zIn >= zEnd) {
			/* No more input */
			break;
		}
		zCur = zIn;
		while(zIn < zEnd && zIn[0] != '\\') {
			zIn++;
		}
		if(zIn > zCur) {
			/* Append raw contents */
			ph7_result_string(pCtx, zCur, (int)(zIn - zCur));
		}
		if(&zIn[1] < zEnd) {
			int c = zIn[1];
			if(c == '\'' || c == '"' || c == '\\') {
				/* Ignore the backslash */
				zIn++;
			}
		} else {
			break;
		}
	}
	return PH7_OK;
}
/*
 * string htmlspecialchars(string $string [, int $flags = ENT_COMPAT | ENT_HTML401 [, string $charset]])
 *  HTML escaping of special characters.
 *  The translations performed are:
 *   '&' (ampersand) ==> '&amp;'
 *   '"' (double quote) ==> '&quot;' when ENT_NOQUOTES is not set.
 *   "'" (single quote) ==> '&#039;' only when ENT_QUOTES is set.
 *   '<' (less than) ==> '&lt;'
 *   '>' (greater than) ==> '&gt;'
 * Parameters
 *  $string
 *   The string being converted.
 * $flags
 *   A bitmask of one or more of the following flags, which specify how to handle quotes.
 *   The default is ENT_COMPAT | ENT_HTML401.
 *   ENT_COMPAT 	Will convert double-quotes and leave single-quotes alone.
 *   ENT_QUOTES 	Will convert both double and single quotes.
 *   ENT_NOQUOTES 	Will leave both double and single quotes unconverted.
 *   ENT_IGNORE 	Silently discard invalid code unit sequences instead of returning an empty string.
 * $charset
 *  Defines character set used in conversion. The default character set is ISO-8859-1. (Not used)
 * Return
 *  The escaped string or NULL on failure.
 */
static int PH7_builtin_htmlspecialchars(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zCur, *zIn, *zEnd;
	int iFlags = 0x01 | 0x40; /* ENT_COMPAT | ENT_HTML401 */
	int nLen, c;
	if(nArg < 1 || !ph7_value_is_string(apArg[0])) {
		/* Missing/Invalid arguments, return NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn = ph7_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	/* Extract the flags if available */
	if(nArg > 1) {
		iFlags = ph7_value_to_int(apArg[1]);
		if(iFlags < 0) {
			iFlags = 0x01 | 0x40;
		}
	}
	/* Perform the requested operation */
	for(;;) {
		if(zIn >= zEnd) {
			break;
		}
		zCur = zIn;
		while(zIn < zEnd && zIn[0] != '&' && zIn[0] != '\'' && zIn[0] != '"' && zIn[0] != '<' && zIn[0] != '>') {
			zIn++;
		}
		if(zCur < zIn) {
			/* Append the raw string verbatim */
			ph7_result_string(pCtx, zCur, (int)(zIn - zCur));
		}
		if(zIn >= zEnd) {
			break;
		}
		c = zIn[0];
		if(c == '&') {
			/* Expand '&amp;' */
			ph7_result_string(pCtx, "&amp;", (int)sizeof("&amp;") - 1);
		} else if(c == '<') {
			/* Expand '&lt;' */
			ph7_result_string(pCtx, "&lt;", (int)sizeof("&lt;") - 1);
		} else if(c == '>') {
			/* Expand '&gt;' */
			ph7_result_string(pCtx, "&gt;", (int)sizeof("&gt;") - 1);
		} else if(c == '\'') {
			if(iFlags & 0x02 /*ENT_QUOTES*/) {
				/* Expand '&#039;' */
				ph7_result_string(pCtx, "&#039;", (int)sizeof("&#039;") - 1);
			} else {
				/* Leave the single quote untouched */
				ph7_result_string(pCtx, "'", (int)sizeof(char));
			}
		} else if(c == '"') {
			if((iFlags & 0x04) == 0 /*ENT_NOQUOTES*/) {
				/* Expand '&quot;' */
				ph7_result_string(pCtx, "&quot;", (int)sizeof("&quot;") - 1);
			} else {
				/* Leave the double quote untouched */
				ph7_result_string(pCtx, "\"", (int)sizeof(char));
			}
		}
		/* Ignore the unsafe HTML character */
		zIn++;
	}
	return PH7_OK;
}
/*
 * string htmlspecialchars_decode(string $string[,int $quote_style = ENT_COMPAT ])
 *  Unescape HTML entities.
 * Parameters
 *  $string
 *   The string to decode
 *  $quote_style
 *    The quote style. One of the following constants:
 *   ENT_COMPAT 	Will convert double-quotes and leave single-quotes alone (default)
 *   ENT_QUOTES 	Will convert both double and single quotes
 *   ENT_NOQUOTES 	Will leave both double and single quotes unconverted
 * Return
 *  The unescaped string or NULL on failure.
 */
static int PH7_builtin_htmlspecialchars_decode(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zCur, *zIn, *zEnd;
	int iFlags = 0x01; /* ENT_COMPAT */
	int nLen, nJump;
	if(nArg < 1 || !ph7_value_is_string(apArg[0])) {
		/* Missing/Invalid arguments, return NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn = ph7_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	/* Extract the flags if available */
	if(nArg > 1) {
		iFlags = ph7_value_to_int(apArg[1]);
		if(iFlags < 0) {
			iFlags = 0x01;
		}
	}
	/* Perform the requested operation */
	for(;;) {
		if(zIn >= zEnd) {
			break;
		}
		zCur = zIn;
		while(zIn < zEnd && zIn[0] != '&') {
			zIn++;
		}
		if(zCur < zIn) {
			/* Append the raw string verbatim */
			ph7_result_string(pCtx, zCur, (int)(zIn - zCur));
		}
		nLen = (int)(zEnd - zIn);
		nJump = (int)sizeof(char);
		if(nLen >= (int)sizeof("&amp;") - 1 && SyStrnicmp(zIn, "&amp;", sizeof("&amp;") - 1) == 0) {
			/* &amp; ==> '&' */
			ph7_result_string(pCtx, "&", (int)sizeof(char));
			nJump = (int)sizeof("&amp;") - 1;
		} else if(nLen >= (int)sizeof("&lt;") - 1 && SyStrnicmp(zIn, "&lt;", sizeof("&lt;") - 1) == 0) {
			/* &lt; ==> < */
			ph7_result_string(pCtx, "<", (int)sizeof(char));
			nJump = (int)sizeof("&lt;") - 1;
		} else if(nLen >= (int)sizeof("&gt;") - 1 && SyStrnicmp(zIn, "&gt;", sizeof("&gt;") - 1) == 0) {
			/* &gt; ==> '>' */
			ph7_result_string(pCtx, ">", (int)sizeof(char));
			nJump = (int)sizeof("&gt;") - 1;
		} else if(nLen >= (int)sizeof("&quot;") - 1 && SyStrnicmp(zIn, "&quot;", sizeof("&quot;") - 1) == 0) {
			/* &quot; ==> '"' */
			if((iFlags & 0x04) == 0 /*ENT_NOQUOTES*/) {
				ph7_result_string(pCtx, "\"", (int)sizeof(char));
			} else {
				/* Leave untouched */
				ph7_result_string(pCtx, "&quot;", (int)sizeof("&quot;") - 1);
			}
			nJump = (int)sizeof("&quot;") - 1;
		} else if(nLen >= (int)sizeof("&#039;") - 1 && SyStrnicmp(zIn, "&#039;", sizeof("&#039;") - 1) == 0) {
			/* &#039; ==> ''' */
			if(iFlags & 0x02 /*ENT_QUOTES*/) {
				/* Expand ''' */
				ph7_result_string(pCtx, "'", (int)sizeof(char));
			} else {
				/* Leave untouched */
				ph7_result_string(pCtx, "&#039;", (int)sizeof("&#039;") - 1);
			}
			nJump = (int)sizeof("&#039;") - 1;
		} else if(nLen >= (int)sizeof(char)) {
			/* expand '&' */
			ph7_result_string(pCtx, "&", (int)sizeof(char));
		} else {
			/* No more input to process */
			break;
		}
		zIn += nJump;
	}
	return PH7_OK;
}
/* HTML encoding/Decoding table
 * Source: Symisc RunTime API.[chm@symisc.net]
 */
static const char *azHtmlEscape[] = {
	"&lt;", "<", "&gt;", ">", "&amp;", "&", "&quot;", "\"", "&#39;", "'",
	"&#33;", "!", "&#36;", "$", "&#35;", "#", "&#37;", "%", "&#40;", "(",
	"&#41;", ")", "&#123;", "{", "&#125;", "}", "&#61;", "=", "&#43;", "+",
	"&#63;", "?", "&#91;", "[", "&#93;", "]", "&#64;", "@", "&#44;", ","
};
/*
 * array get_html_translation_table(void)
 *  Returns the translation table used by htmlspecialchars() and htmlentities().
 * Parameters
 *  None
 * Return
 *  The translation table as an array or NULL on failure.
 */
static int PH7_builtin_get_html_translation_table(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_value *pArray, *pValue;
	sxu32 n;
	/* Element value */
	pValue = ph7_context_new_scalar(pCtx);
	if(pValue == 0) {
		SXUNUSED(nArg); /* cc warning */
		SXUNUSED(apArg);
		/* Return NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Create a new array */
	pArray = ph7_context_new_array(pCtx);
	if(pArray == 0) {
		/* Return NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Make the table */
	for(n = 0 ; n < SX_ARRAYSIZE(azHtmlEscape) ; n += 2) {
		/* Prepare the value */
		ph7_value_string(pValue, azHtmlEscape[n], -1 /* Compute length automatically */);
		/* Insert the value */
		ph7_array_add_strkey_elem(pArray, azHtmlEscape[n + 1], pValue);
		/* Reset the string cursor */
		ph7_value_reset_string_cursor(pValue);
	}
	/*
	 * Return the array.
	 * Don't worry about freeing memory, everything will be automatically
	 * released upon we return from this function.
	 */
	ph7_result_value(pCtx, pArray);
	return PH7_OK;
}
/*
 * string htmlentities( string $string [, int $flags = ENT_COMPAT | ENT_HTML401]);
 *   Convert all applicable characters to HTML entities
 * Parameters
 * $string
 *   The input string.
 * $flags
 *  A bitmask of one or more of the flags (see block-comment on PH7_builtin_htmlspecialchars())
 * Return
 * The encoded string.
 */
static int PH7_builtin_htmlentities(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int iFlags = 0x01; /* ENT_COMPAT */
	const char *zIn, *zEnd;
	int nLen, c;
	sxu32 n;
	if(nArg < 1 || !ph7_value_is_string(apArg[0])) {
		/* Missing/Invalid arguments, return NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn = ph7_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	/* Extract the flags if available */
	if(nArg > 1) {
		iFlags = ph7_value_to_int(apArg[1]);
		if(iFlags < 0) {
			iFlags = 0x01;
		}
	}
	/* Perform the requested operation */
	for(;;) {
		if(zIn >= zEnd) {
			/* No more input to process */
			break;
		}
		c = zIn[0];
		/* Perform a linear lookup on the decoding table */
		for(n = 0 ; n < SX_ARRAYSIZE(azHtmlEscape) ; n += 2) {
			if(azHtmlEscape[n + 1][0] == c) {
				/* Got one */
				break;
			}
		}
		if(n < SX_ARRAYSIZE(azHtmlEscape)) {
			/* Output the safe sequence [i.e: '<' ==> '&lt;"] */
			if(c == '"' && (iFlags & 0x04) /*ENT_NOQUOTES*/) {
				/* Expand the double quote verbatim */
				ph7_result_string(pCtx, (const char *)&c, (int)sizeof(char));
			} else if(c == '\'' && ((iFlags & 0x02 /*ENT_QUOTES*/) == 0 || (iFlags & 0x04) /*ENT_NOQUOTES*/)) {
				/* expand single quote verbatim */
				ph7_result_string(pCtx, (const char *)&c, (int)sizeof(char));
			} else {
				ph7_result_string(pCtx, azHtmlEscape[n], -1/*Compute length automatically */);
			}
		} else {
			/* Output character verbatim */
			ph7_result_string(pCtx, (const char *)&c, (int)sizeof(char));
		}
		zIn++;
	}
	return PH7_OK;
}
/*
 * string html_entity_decode(string $string [, int $quote_style = ENT_COMPAT [, string $charset = 'UTF-8' ]])
 *   Perform the reverse operation of html_entity_decode().
 * Parameters
 * $string
 *   The input string.
 * $flags
 *  A bitmask of one or more of the flags (see comment on PH7_builtin_htmlspecialchars())
 * Return
 * The decoded string.
 */
static int PH7_builtin_html_entity_decode(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zCur, *zIn, *zEnd;
	int iFlags = 0x01; /* ENT_COMPAT  */
	int nLen;
	sxu32 n;
	if(nArg < 1 || !ph7_value_is_string(apArg[0])) {
		/* Missing/Invalid arguments, return NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn = ph7_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	/* Extract the flags if available */
	if(nArg > 1) {
		iFlags = ph7_value_to_int(apArg[1]);
		if(iFlags < 0) {
			iFlags = 0x01;
		}
	}
	/* Perform the requested operation */
	for(;;) {
		if(zIn >= zEnd) {
			/* No more input to process */
			break;
		}
		zCur = zIn;
		while(zIn < zEnd && zIn[0] != '&') {
			zIn++;
		}
		if(zCur < zIn) {
			/* Append raw string verbatim */
			ph7_result_string(pCtx, zCur, (int)(zIn - zCur));
		}
		if(zIn >= zEnd) {
			break;
		}
		nLen = (int)(zEnd - zIn);
		/* Find an encoded sequence */
		for(n = 0 ; n < SX_ARRAYSIZE(azHtmlEscape) ; n += 2) {
			int iLen = (int)SyStrlen(azHtmlEscape[n]);
			if(nLen >= iLen && SyStrnicmp(zIn, azHtmlEscape[n], (sxu32)iLen) == 0) {
				/* Got one */
				zIn += iLen;
				break;
			}
		}
		if(n < SX_ARRAYSIZE(azHtmlEscape)) {
			int c = azHtmlEscape[n + 1][0];
			/* Output the decoded character */
			if(c == '\'' && ((iFlags & 0x02) == 0 /*ENT_QUOTES*/ || (iFlags & 0x04) /*ENT_NOQUOTES*/)) {
				/* Do not process single quotes */
				ph7_result_string(pCtx, azHtmlEscape[n], -1);
			} else if(c == '"' && (iFlags & 0x04) /*ENT_NOQUOTES*/) {
				/* Do not process double quotes */
				ph7_result_string(pCtx, azHtmlEscape[n], -1);
			} else {
				ph7_result_string(pCtx, azHtmlEscape[n + 1], -1); /* Compute length automatically */
			}
		} else {
			/* Append '&' */
			ph7_result_string(pCtx, "&", (int)sizeof(char));
			zIn++;
		}
	}
	return PH7_OK;
}
/*
 * int strlen($string)
 *  return the length of the given string.
 * Parameter
 *  string: The string being measured for length.
 * Return
 *  length of the given string.
 */
static int PH7_builtin_strlen(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int iLen = 0;
	if(nArg > 0) {
		ph7_value_to_string(apArg[0], &iLen);
	}
	/* String length */
	ph7_result_int(pCtx, iLen);
	return PH7_OK;
}
/*
 * int strcmp(string $str1,string $str2)
 *  Perform a binary safe string comparison.
 * Parameter
 *  str1: The first string
 *  str2: The second string
 * Return
 *  Returns < 0 if str1 is less than str2; > 0 if str1 is greater
 *  than str2, and 0 if they are equal.
 */
static int PH7_builtin_strcmp(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *z1, *z2;
	int n1, n2;
	int res;
	if(nArg < 2) {
		res = nArg == 0 ? 0 : 1;
		ph7_result_int(pCtx, res);
		return PH7_OK;
	}
	/* Perform the comparison */
	z1 = ph7_value_to_string(apArg[0], &n1);
	z2 = ph7_value_to_string(apArg[1], &n2);
	res = SyStrncmp(z1, z2, (sxu32)(SXMAX(n1, n2)));
	/* Comparison result */
	ph7_result_int(pCtx, res);
	return PH7_OK;
}
/*
 * int strncmp(string $str1,string $str2,int n)
 *  Perform a binary safe string comparison of the first n characters.
 * Parameter
 *  str1: The first string
 *  str2: The second string
 * Return
 *  Returns < 0 if str1 is less than str2; > 0 if str1 is greater
 *  than str2, and 0 if they are equal.
 */
static int PH7_builtin_strncmp(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *z1, *z2;
	int res;
	int n;
	if(nArg < 3) {
		/* Perform a standard comparison */
		return PH7_builtin_strcmp(pCtx, nArg, apArg);
	}
	/* Desired comparison length */
	n  = ph7_value_to_int(apArg[2]);
	if(n < 0) {
		/* Invalid length */
		ph7_result_int(pCtx, -1);
		return PH7_OK;
	}
	/* Perform the comparison */
	z1 = ph7_value_to_string(apArg[0], 0);
	z2 = ph7_value_to_string(apArg[1], 0);
	res = SyStrncmp(z1, z2, (sxu32)n);
	/* Comparison result */
	ph7_result_int(pCtx, res);
	return PH7_OK;
}
/*
 * int strcasecmp(string $str1,string $str2,int n)
 *  Perform a binary safe case-insensitive string comparison.
 * Parameter
 *  str1: The first string
 *  str2: The second string
 * Return
 *  Returns < 0 if str1 is less than str2; > 0 if str1 is greater
 *  than str2, and 0 if they are equal.
 */
static int PH7_builtin_strcasecmp(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *z1, *z2;
	int n1, n2;
	int res;
	if(nArg < 2) {
		res = nArg == 0 ? 0 : 1;
		ph7_result_int(pCtx, res);
		return PH7_OK;
	}
	/* Perform the comparison */
	z1 = ph7_value_to_string(apArg[0], &n1);
	z2 = ph7_value_to_string(apArg[1], &n2);
	res = SyStrnicmp(z1, z2, (sxu32)(SXMAX(n1, n2)));
	/* Comparison result */
	ph7_result_int(pCtx, res);
	return PH7_OK;
}
/*
 * int strncasecmp(string $str1,string $str2,int n)
 *  Perform a binary safe case-insensitive string comparison of the first n characters.
 * Parameter
 *  $str1: The first string
 *  $str2: The second string
 *  $len:  The length of strings to be used in the comparison.
 * Return
 *  Returns < 0 if str1 is less than str2; > 0 if str1 is greater
 *  than str2, and 0 if they are equal.
 */
static int PH7_builtin_strncasecmp(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *z1, *z2;
	int res;
	int n;
	if(nArg < 3) {
		/* Perform a standard comparison */
		return PH7_builtin_strcasecmp(pCtx, nArg, apArg);
	}
	/* Desired comparison length */
	n  = ph7_value_to_int(apArg[2]);
	if(n < 0) {
		/* Invalid length */
		ph7_result_int(pCtx, -1);
		return PH7_OK;
	}
	/* Perform the comparison */
	z1 = ph7_value_to_string(apArg[0], 0);
	z2 = ph7_value_to_string(apArg[1], 0);
	res = SyStrnicmp(z1, z2, (sxu32)n);
	/* Comparison result */
	ph7_result_int(pCtx, res);
	return PH7_OK;
}
/*
 * Implode context [i.e: it's private data].
 * A pointer to the following structure is forwarded
 * verbatim to the array walker callback defined below.
 */
struct implode_data {
	ph7_context *pCtx;    /* Call context */
	int bRecursive;       /* TRUE if recursive implode [this is a symisc eXtension] */
	const char *zSep;     /* Arguments separator if any */
	int nSeplen;          /* Separator length */
	int bFirst;           /* TRUE if first call */
	int nRecCount;        /* Recursion count to avoid infinite loop */
};
/*
 * Implode walker callback for the [ph7_array_walk()] interface.
 * The following routine is invoked for each array entry passed
 * to the implode() function.
 */
static int implode_callback(ph7_value *pKey, ph7_value *pValue, void *pUserData) {
	struct implode_data *pData = (struct implode_data *)pUserData;
	const char *zData;
	int nLen;
	if(pData->bRecursive && ph7_value_is_array(pValue) && pData->nRecCount < 32) {
		if(pData->nSeplen > 0) {
			if(!pData->bFirst) {
				/* append the separator first */
				ph7_result_string(pData->pCtx, pData->zSep, pData->nSeplen);
			} else {
				pData->bFirst = 0;
			}
		}
		/* Recurse */
		pData->bFirst = 1;
		pData->nRecCount++;
		PH7_HashmapWalk((ph7_hashmap *)pValue->x.pOther, implode_callback, pData);
		pData->nRecCount--;
		return PH7_OK;
	}
	/* Extract the string representation of the entry value */
	zData = ph7_value_to_string(pValue, &nLen);
	if(nLen > 0) {
		if(pData->nSeplen > 0) {
			if(!pData->bFirst) {
				/* append the separator first */
				ph7_result_string(pData->pCtx, pData->zSep, pData->nSeplen);
			} else {
				pData->bFirst = 0;
			}
		}
		ph7_result_string(pData->pCtx, zData, nLen);
	} else {
		SXUNUSED(pKey); /* cc warning */
	}
	return PH7_OK;
}
/*
 * string implode(string $glue,array $pieces,...)
 * string implode(array $pieces,...)
 *  Join array elements with a string.
 * $glue
 *   Defaults to an empty string. This is not the preferred usage of implode() as glue
 *   would be the second parameter and thus, the bad prototype would be used.
 * $pieces
 *   The array of strings to implode.
 * Return
 *  Returns a string containing a string representation of all the array elements in the same
 *  order, with the glue string between each element.
 */
static int PH7_builtin_implode(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	struct implode_data imp_data;
	int i = 1;
	if(nArg < 1) {
		/* Missing argument, return NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Prepare the implode context */
	imp_data.pCtx = pCtx;
	imp_data.bRecursive = 0;
	imp_data.bFirst = 1;
	imp_data.nRecCount = 0;
	if(!ph7_value_is_array(apArg[0])) {
		imp_data.zSep = ph7_value_to_string(apArg[0], &imp_data.nSeplen);
	} else {
		imp_data.zSep = 0;
		imp_data.nSeplen = 0;
		i = 0;
	}
	ph7_result_string(pCtx, "", 0); /* Set an empty stirng */
	/* Start the 'join' process */
	while(i < nArg) {
		if(ph7_value_is_array(apArg[i])) {
			/* Iterate throw array entries */
			ph7_array_walk(apArg[i], implode_callback, &imp_data);
		} else {
			const char *zData;
			int nLen;
			/* Extract the string representation of the ph7 value */
			zData = ph7_value_to_string(apArg[i], &nLen);
			if(nLen > 0) {
				if(imp_data.nSeplen > 0) {
					if(!imp_data.bFirst) {
						/* append the separator first */
						ph7_result_string(pCtx, imp_data.zSep, imp_data.nSeplen);
					} else {
						imp_data.bFirst = 0;
					}
				}
				ph7_result_string(pCtx, zData, nLen);
			}
		}
		i++;
	}
	return PH7_OK;
}
/*
 * Symisc eXtension:
 * string implode_recursive(string $glue,array $pieces,...)
 * Purpose
 *  Same as implode() but recurse on arrays.
 * Example:
 *   $a = array('usr',array('home','dean'));
 *   echo implode_recursive("/",$a);
 *   Will output
 *     usr/home/dean.
 *   While the standard implode would produce.
 *    usr/Array.
 * Parameter
 *  Refer to implode().
 * Return
 *  Refer to implode().
 */
static int PH7_builtin_implode_recursive(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	struct implode_data imp_data;
	int i = 1;
	if(nArg < 1) {
		/* Missing argument, return NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Prepare the implode context */
	imp_data.pCtx = pCtx;
	imp_data.bRecursive = 1;
	imp_data.bFirst = 1;
	imp_data.nRecCount = 0;
	if(!ph7_value_is_array(apArg[0])) {
		imp_data.zSep = ph7_value_to_string(apArg[0], &imp_data.nSeplen);
	} else {
		imp_data.zSep = 0;
		imp_data.nSeplen = 0;
		i = 0;
	}
	ph7_result_string(pCtx, "", 0); /* Set an empty stirng */
	/* Start the 'join' process */
	while(i < nArg) {
		if(ph7_value_is_array(apArg[i])) {
			/* Iterate throw array entries */
			ph7_array_walk(apArg[i], implode_callback, &imp_data);
		} else {
			const char *zData;
			int nLen;
			/* Extract the string representation of the ph7 value */
			zData = ph7_value_to_string(apArg[i], &nLen);
			if(nLen > 0) {
				if(imp_data.nSeplen > 0) {
					if(!imp_data.bFirst) {
						/* append the separator first */
						ph7_result_string(pCtx, imp_data.zSep, imp_data.nSeplen);
					} else {
						imp_data.bFirst = 0;
					}
				}
				ph7_result_string(pCtx, zData, nLen);
			}
		}
		i++;
	}
	return PH7_OK;
}
/*
 * array explode(string $delimiter,string $string[,int $limit ])
 *  Returns an array of strings, each of which is a substring of string
 *  formed by splitting it on boundaries formed by the string delimiter.
 * Parameters
 *  $delimiter
 *   The boundary string.
 * $string
 *   The input string.
 * $limit
 *   If limit is set and positive, the returned array will contain a maximum
 *   of limit elements with the last element containing the rest of string.
 *   If the limit parameter is negative, all fields except the last -limit are returned.
 *   If the limit parameter is zero, then this is treated as 1.
 * Returns
 *  Returns an array of strings created by splitting the string parameter
 *  on boundaries formed by the delimiter.
 *  If delimiter is an empty string (""), explode() will return FALSE.
 *  If delimiter contains a value that is not contained in string and a negative
 *  limit is used, then an empty array will be returned, otherwise an array containing string
 *  will be returned.
 * NOTE:
 *  Negative limit is not supported.
 */
static int PH7_builtin_explode(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zDelim, *zString, *zCur, *zEnd;
	int nDelim, nStrlen, iLimit;
	ph7_value *pArray;
	ph7_value *pValue;
	sxu32 nOfft;
	sxi32 rc;
	if(nArg < 2) {
		/* Missing arguments, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the delimiter */
	zDelim = ph7_value_to_string(apArg[0], &nDelim);
	if(nDelim < 1) {
		/* Empty delimiter, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the string */
	zString = ph7_value_to_string(apArg[1], &nStrlen);
	if(nStrlen < 1) {
		/* Empty delimiter, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the end of the string */
	zEnd = &zString[nStrlen];
	/* Create the array */
	pArray =  ph7_context_new_array(pCtx);
	pValue = ph7_context_new_scalar(pCtx);
	if(pArray == 0 || pValue == 0) {
		/* Out of memory, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Set a defualt limit */
	iLimit = SXI32_HIGH;
	if(nArg > 2) {
		iLimit = ph7_value_to_int(apArg[2]);
		if(iLimit < 0) {
			iLimit = -iLimit;
		}
		if(iLimit == 0) {
			iLimit = 1;
		}
		iLimit--;
	}
	/* Start exploding */
	for(;;) {
		if(zString >= zEnd) {
			/* No more entry to process */
			break;
		}
		rc = SyBlobSearch(zString, (sxu32)(zEnd - zString), zDelim, nDelim, &nOfft);
		if(rc != SXRET_OK || iLimit <= (int)ph7_array_count(pArray)) {
			/* Limit reached,insert the rest of the string and break */
			if(zEnd > zString) {
				ph7_value_string(pValue, zString, (int)(zEnd - zString));
				ph7_array_add_elem(pArray, 0/* Automatic index assign*/, pValue);
			}
			break;
		}
		/* Point to the desired offset */
		zCur = &zString[nOfft];
		if(zCur > zString) {
			/* Perform the store operation */
			ph7_value_string(pValue, zString, (int)(zCur - zString));
			ph7_array_add_elem(pArray, 0/* Automatic index assign*/, pValue);
		}
		/* Point beyond the delimiter */
		zString = &zCur[nDelim];
		/* Reset the cursor */
		ph7_value_reset_string_cursor(pValue);
	}
	/* Return the freshly created array */
	ph7_result_value(pCtx, pArray);
	/* NOTE that every allocated ph7_value will be automatically
	 * released as soon we return from this foregin function.
	 */
	return PH7_OK;
}
/*
 * string trim(string $str[,string $charlist ])
 *  Strip whitespace (or other characters) from the beginning and end of a string.
 * Parameters
 *  $str
 *   The string that will be trimmed.
 * $charlist
 *   Optionally, the stripped characters can also be specified using the charlist parameter.
 *   Simply list all characters that you want to be stripped.
 *   With .. you can specify a range of characters.
 * Returns.
 *  Thr processed string.
 * NOTE:
 *   RANGE CHARACTERS [I.E: 'a'..'z'] are not supported.
 */
static int PH7_builtin_trim(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zString;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the target string */
	zString = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string, return */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Start the trim process */
	if(nArg < 2) {
		SyString sStr;
		/* Remove white spaces and NUL bytes */
		SyStringInitFromBuf(&sStr, zString, nLen);
		SyStringFullTrimSafe(&sStr);
		ph7_result_string(pCtx, sStr.zString, (int)sStr.nByte);
	} else {
		/* Char list */
		const char *zList;
		int nListlen;
		zList = ph7_value_to_string(apArg[1], &nListlen);
		if(nListlen < 1) {
			/* Return the string unchanged */
			ph7_result_string(pCtx, zString, nLen);
		} else {
			const char *zEnd = &zString[nLen];
			const char *zCur = zString;
			const char *zPtr;
			int i;
			/* Left trim */
			for(;;) {
				if(zCur >= zEnd) {
					break;
				}
				zPtr = zCur;
				for(i = 0 ; i < nListlen ; i++) {
					if(zCur < zEnd && zCur[0] == zList[i]) {
						zCur++;
					}
				}
				if(zCur == zPtr) {
					/* No match,break immediately */
					break;
				}
			}
			/* Right trim */
			zEnd--;
			for(;;) {
				if(zEnd <= zCur) {
					break;
				}
				zPtr = zEnd;
				for(i = 0 ; i < nListlen ; i++) {
					if(zEnd > zCur && zEnd[0] == zList[i]) {
						zEnd--;
					}
				}
				if(zEnd == zPtr) {
					break;
				}
			}
			if(zCur >= zEnd) {
				/* Return the empty string */
				ph7_result_string(pCtx, "", 0);
			} else {
				zEnd++;
				ph7_result_string(pCtx, zCur, (int)(zEnd - zCur));
			}
		}
	}
	return PH7_OK;
}
/*
 * string rtrim(string $str[,string $charlist ])
 *  Strip whitespace (or other characters) from the end of a string.
 * Parameters
 *  $str
 *   The string that will be trimmed.
 * $charlist
 *   Optionally, the stripped characters can also be specified using the charlist parameter.
 *   Simply list all characters that you want to be stripped.
 *   With .. you can specify a range of characters.
 * Returns.
 *  Thr processed string.
 * NOTE:
 *   RANGE CHARACTERS [I.E: 'a'..'z'] are not supported.
 */
static int PH7_builtin_rtrim(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zString;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the target string */
	zString = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string, return */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Start the trim process */
	if(nArg < 2) {
		SyString sStr;
		/* Remove white spaces and NUL bytes*/
		SyStringInitFromBuf(&sStr, zString, nLen);
		SyStringRightTrimSafe(&sStr);
		ph7_result_string(pCtx, sStr.zString, (int)sStr.nByte);
	} else {
		/* Char list */
		const char *zList;
		int nListlen;
		zList = ph7_value_to_string(apArg[1], &nListlen);
		if(nListlen < 1) {
			/* Return the string unchanged */
			ph7_result_string(pCtx, zString, nLen);
		} else {
			const char *zEnd = &zString[nLen - 1];
			const char *zCur = zString;
			const char *zPtr;
			int i;
			/* Right trim */
			for(;;) {
				if(zEnd <= zCur) {
					break;
				}
				zPtr = zEnd;
				for(i = 0 ; i < nListlen ; i++) {
					if(zEnd > zCur && zEnd[0] == zList[i]) {
						zEnd--;
					}
				}
				if(zEnd == zPtr) {
					break;
				}
			}
			if(zEnd <= zCur) {
				/* Return the empty string */
				ph7_result_string(pCtx, "", 0);
			} else {
				zEnd++;
				ph7_result_string(pCtx, zCur, (int)(zEnd - zCur));
			}
		}
	}
	return PH7_OK;
}
/*
 * string ltrim(string $str[,string $charlist ])
 *  Strip whitespace (or other characters) from the beginning and end of a string.
 * Parameters
 *  $str
 *   The string that will be trimmed.
 * $charlist
 *   Optionally, the stripped characters can also be specified using the charlist parameter.
 *   Simply list all characters that you want to be stripped.
 *   With .. you can specify a range of characters.
 * Returns.
 *  Thr processed string.
 * NOTE:
 *   RANGE CHARACTERS [I.E: 'a'..'z'] are not supported.
 */
static int PH7_builtin_ltrim(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zString;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the target string */
	zString = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string, return */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Start the trim process */
	if(nArg < 2) {
		SyString sStr;
		/* Remove white spaces and NUL byte */
		SyStringInitFromBuf(&sStr, zString, nLen);
		SyStringLeftTrimSafe(&sStr);
		ph7_result_string(pCtx, sStr.zString, (int)sStr.nByte);
	} else {
		/* Char list */
		const char *zList;
		int nListlen;
		zList = ph7_value_to_string(apArg[1], &nListlen);
		if(nListlen < 1) {
			/* Return the string unchanged */
			ph7_result_string(pCtx, zString, nLen);
		} else {
			const char *zEnd = &zString[nLen];
			const char *zCur = zString;
			const char *zPtr;
			int i;
			/* Left trim */
			for(;;) {
				if(zCur >= zEnd) {
					break;
				}
				zPtr = zCur;
				for(i = 0 ; i < nListlen ; i++) {
					if(zCur < zEnd && zCur[0] == zList[i]) {
						zCur++;
					}
				}
				if(zCur == zPtr) {
					/* No match,break immediately */
					break;
				}
			}
			if(zCur >= zEnd) {
				/* Return the empty string */
				ph7_result_string(pCtx, "", 0);
			} else {
				ph7_result_string(pCtx, zCur, (int)(zEnd - zCur));
			}
		}
	}
	return PH7_OK;
}
/*
 * string strtolower(string $str)
 *  Make a string lowercase.
 * Parameters
 *  $str
 *   The input string.
 * Returns.
 *  The lowercased string.
 */
static int PH7_builtin_strtolower(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zString, *zCur, *zEnd;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the target string */
	zString = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string, return */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	zEnd = &zString[nLen];
	for(;;) {
		if(zString >= zEnd) {
			/* No more input,break immediately */
			break;
		}
		if((unsigned char)zString[0] >= 0xc0) {
			/* UTF-8 stream,output verbatim */
			zCur = zString;
			zString++;
			while(zString < zEnd && ((unsigned char)zString[0] & 0xc0) == 0x80) {
				zString++;
			}
			/* Append UTF-8 stream */
			ph7_result_string(pCtx, zCur, (int)(zString - zCur));
		} else {
			int c = zString[0];
			if(SyisUpper(c)) {
				c = SyToLower(zString[0]);
			}
			/* Append character */
			ph7_result_string(pCtx, (const char *)&c, (int)sizeof(char));
			/* Advance the cursor */
			zString++;
		}
	}
	return PH7_OK;
}
/*
 * string strtolower(string $str)
 *  Make a string uppercase.
 * Parameters
 *  $str
 *   The input string.
 * Returns.
 *  The uppercased string.
 */
static int PH7_builtin_strtoupper(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zString, *zCur, *zEnd;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the target string */
	zString = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string, return */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	zEnd = &zString[nLen];
	for(;;) {
		if(zString >= zEnd) {
			/* No more input,break immediately */
			break;
		}
		if((unsigned char)zString[0] >= 0xc0) {
			/* UTF-8 stream,output verbatim */
			zCur = zString;
			zString++;
			while(zString < zEnd && ((unsigned char)zString[0] & 0xc0) == 0x80) {
				zString++;
			}
			/* Append UTF-8 stream */
			ph7_result_string(pCtx, zCur, (int)(zString - zCur));
		} else {
			int c = zString[0];
			if(SyisLower(c)) {
				c = SyToUpper(zString[0]);
			}
			/* Append character */
			ph7_result_string(pCtx, (const char *)&c, (int)sizeof(char));
			/* Advance the cursor */
			zString++;
		}
	}
	return PH7_OK;
}
/*
 * string ucfirst(string $str)
 *  Returns a string with the first character of str capitalized, if that
 *  character is alphabetic.
 * Parameters
 *  $str
 *   The input string.
 * Returns.
 *  The processed string.
 */
static int PH7_builtin_ucfirst(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zString, *zEnd;
	int nLen, c;
	if(nArg < 1) {
		/* Missing arguments, return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the target string */
	zString = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string, return */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	zEnd = &zString[nLen];
	c = zString[0];
	if(SyisLower(c)) {
		c = SyToUpper(c);
	}
	/* Append the first character */
	ph7_result_string(pCtx, (const char *)&c, (int)sizeof(char));
	zString++;
	if(zString < zEnd) {
		/* Append the rest of the input verbatim */
		ph7_result_string(pCtx, zString, (int)(zEnd - zString));
	}
	return PH7_OK;
}
/*
 * string lcfirst(string $str)
 *  Make a string's first character lowercase.
 * Parameters
 *  $str
 *   The input string.
 * Returns.
 *  The processed string.
 */
static int PH7_builtin_lcfirst(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zString, *zEnd;
	int nLen, c;
	if(nArg < 1) {
		/* Missing arguments, return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the target string */
	zString = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string, return */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	zEnd = &zString[nLen];
	c = zString[0];
	if(SyisUpper(c)) {
		c = SyToLower(c);
	}
	/* Append the first character */
	ph7_result_string(pCtx, (const char *)&c, (int)sizeof(char));
	zString++;
	if(zString < zEnd) {
		/* Append the rest of the input verbatim */
		ph7_result_string(pCtx, zString, (int)(zEnd - zString));
	}
	return PH7_OK;
}
/*
 * int ord(string $string)
 *  Returns the ASCII value of the first character of string.
 * Parameters
 *  $str
 *   The input string.
 * Returns.
 *  The ASCII value as an integer.
 */
static int PH7_builtin_ord(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const unsigned char *zString;
	int nLen, c;
	if(nArg < 1) {
		/* Missing arguments, return -1 */
		ph7_result_int(pCtx, -1);
		return PH7_OK;
	}
	/* Extract the target string */
	zString = (const unsigned char *)ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string, return -1 */
		ph7_result_int(pCtx, -1);
		return PH7_OK;
	}
	/* Extract the ASCII value of the first character */
	c = zString[0];
	/* Return that value */
	ph7_result_int(pCtx, c);
	return PH7_OK;
}
/*
 * string chr(int $ascii)
 *  Returns a one-character string containing the character specified by ascii.
 * Parameters
 *  $ascii
 *   The ascii code.
 * Returns.
 *  The specified character.
 */
static int PH7_builtin_chr(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int c;
	if(nArg < 1) {
		/* Missing arguments, return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the ASCII value */
	c = ph7_value_to_int(apArg[0]);
	/* Return the specified character */
	ph7_result_string(pCtx, (const char *)&c, (int)sizeof(char));
	return PH7_OK;
}
/*
 * Binary to hex consumer callback.
 * This callback is the default consumer used by the hash functions
 * [i.e: bin2hex(),md5(),sha1(),md5_file() ... ] defined below.
 */
static int HashConsumer(const void *pData, unsigned int nLen, void *pUserData) {
	/* Append hex chunk verbatim */
	ph7_result_string((ph7_context *)pUserData, (const char *)pData, (int)nLen);
	return SXRET_OK;
}
/*
 * string bin2hex(string $str)
 *  Convert binary data into hexadecimal representation.
 * Parameters
 *  $str
 *   The input string.
 * Returns.
 *  Returns the hexadecimal representation of the given string.
 */
static int PH7_builtin_bin2hex(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zString;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the target string */
	zString = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string, return */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	SyBinToHexConsumer((const void *)zString, (sxu32)nLen, HashConsumer, pCtx);
	return PH7_OK;
}
/* Search callback signature */
typedef sxi32(*ProcStringMatch)(const void *, sxu32, const void *, sxu32, sxu32 *);
/*
 * Case-insensitive pattern match.
 * Brute force is the default search method used here.
 * This is due to the fact that brute-forcing works quite
 * well for short/medium texts on modern hardware.
 */
static sxi32 iPatternMatch(const void *pText, sxu32 nLen, const void *pPattern, sxu32 iPatLen, sxu32 *pOfft) {
	const char *zpIn = (const char *)pPattern;
	const char *zIn = (const char *)pText;
	const char *zpEnd = &zpIn[iPatLen];
	const char *zEnd = &zIn[nLen];
	const char *zPtr, *zPtr2;
	int c, d;
	if(iPatLen > nLen) {
		/* Don't bother processing */
		return SXERR_NOTFOUND;
	}
	for(;;) {
		if(zIn >= zEnd) {
			break;
		}
		c = SyToLower(zIn[0]);
		d = SyToLower(zpIn[0]);
		if(c == d) {
			zPtr   = &zIn[1];
			zPtr2  = &zpIn[1];
			for(;;) {
				if(zPtr2 >= zpEnd) {
					/* Pattern found */
					if(pOfft) {
						*pOfft = (sxu32)(zIn - (const char *)pText);
					}
					return SXRET_OK;
				}
				if(zPtr >= zEnd) {
					break;
				}
				c = SyToLower(zPtr[0]);
				d = SyToLower(zPtr2[0]);
				if(c != d) {
					break;
				}
				zPtr++;
				zPtr2++;
			}
		}
		zIn++;
	}
	/* Pattern not found */
	return SXERR_NOTFOUND;
}
/*
 * string strstr(string $haystack,string $needle[,bool $before_needle = false ])
 *  Find the first occurrence of a string.
 * Parameters
 *  $haystack
 *   The input string.
 * $needle
 *   Search pattern (must be a string).
 * $before_needle
 *   If TRUE, strstr() returns the part of the haystack before the first occurrence
 *   of the needle (excluding the needle).
 * Return
 *  Returns the portion of string, or FALSE if needle is not found.
 */
static int PH7_builtin_strstr(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ProcStringMatch xPatternMatch = SyBlobSearch; /* Case-sensitive pattern match */
	const char *zBlob, *zPattern;
	int nLen, nPatLen;
	sxu32 nOfft;
	sxi32 rc;
	if(nArg < 2) {
		/* Missing arguments, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the needle and the haystack */
	zBlob = ph7_value_to_string(apArg[0], &nLen);
	zPattern = ph7_value_to_string(apArg[1], &nPatLen);
	nOfft = 0; /* cc warning */
	if(nLen > 0 && nPatLen > 0) {
		int before = 0;
		/* Perform the lookup */
		rc = xPatternMatch(zBlob, (sxu32)nLen, zPattern, (sxu32)nPatLen, &nOfft);
		if(rc != SXRET_OK) {
			/* Pattern not found, return FALSE */
			ph7_result_bool(pCtx, 0);
			return PH7_OK;
		}
		/* Return the portion of the string */
		if(nArg > 2) {
			before = ph7_value_to_int(apArg[2]);
		}
		if(before) {
			ph7_result_string(pCtx, zBlob, (int)(&zBlob[nOfft] - zBlob));
		} else {
			ph7_result_string(pCtx, &zBlob[nOfft], (int)(&zBlob[nLen] - &zBlob[nOfft]));
		}
	} else {
		ph7_result_bool(pCtx, 0);
	}
	return PH7_OK;
}
/*
 * string stristr(string $haystack,string $needle[,bool $before_needle = false ])
 *  Case-insensitive strstr().
 * Parameters
 *  $haystack
 *   The input string.
 * $needle
 *   Search pattern (must be a string).
 * $before_needle
 *   If TRUE, strstr() returns the part of the haystack before the first occurrence
 *   of the needle (excluding the needle).
 * Return
 *  Returns the portion of string, or FALSE if needle is not found.
 */
static int PH7_builtin_stristr(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ProcStringMatch xPatternMatch = iPatternMatch; /* Case-insensitive pattern match */
	const char *zBlob, *zPattern;
	int nLen, nPatLen;
	sxu32 nOfft;
	sxi32 rc;
	if(nArg < 2) {
		/* Missing arguments, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the needle and the haystack */
	zBlob = ph7_value_to_string(apArg[0], &nLen);
	zPattern = ph7_value_to_string(apArg[1], &nPatLen);
	nOfft = 0; /* cc warning */
	if(nLen > 0 && nPatLen > 0) {
		int before = 0;
		/* Perform the lookup */
		rc = xPatternMatch(zBlob, (sxu32)nLen, zPattern, (sxu32)nPatLen, &nOfft);
		if(rc != SXRET_OK) {
			/* Pattern not found, return FALSE */
			ph7_result_bool(pCtx, 0);
			return PH7_OK;
		}
		/* Return the portion of the string */
		if(nArg > 2) {
			before = ph7_value_to_int(apArg[2]);
		}
		if(before) {
			ph7_result_string(pCtx, zBlob, (int)(&zBlob[nOfft] - zBlob));
		} else {
			ph7_result_string(pCtx, &zBlob[nOfft], (int)(&zBlob[nLen] - &zBlob[nOfft]));
		}
	} else {
		ph7_result_bool(pCtx, 0);
	}
	return PH7_OK;
}
/*
 * int strpos(string $haystack,string $needle [,int $offset = 0 ] )
 *  Returns the numeric position of the first occurrence of needle in the haystack string.
 * Parameters
 *  $haystack
 *   The input string.
 * $needle
 *   Search pattern (must be a string).
 * $offset
 *   This optional offset parameter allows you to specify which character in haystack
 *   to start searching. The position returned is still relative to the beginning
 *   of haystack.
 * Return
 *  Returns the position as an integer.If needle is not found, strpos() will return FALSE.
 */
static int PH7_builtin_strpos(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ProcStringMatch xPatternMatch = SyBlobSearch; /* Case-sensitive pattern match */
	const char *zBlob, *zPattern;
	int nLen, nPatLen, nStart;
	sxu32 nOfft;
	sxi32 rc;
	if(nArg < 2) {
		/* Missing arguments, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the needle and the haystack */
	zBlob = ph7_value_to_string(apArg[0], &nLen);
	zPattern = ph7_value_to_string(apArg[1], &nPatLen);
	nOfft = 0; /* cc warning */
	nStart = 0;
	/* Peek the starting offset if available */
	if(nArg > 2) {
		nStart = ph7_value_to_int(apArg[2]);
		if(nStart < 0) {
			nStart = -nStart;
		}
		if(nStart >= nLen) {
			/* Invalid offset */
			nStart = 0;
		} else {
			zBlob += nStart;
			nLen -= nStart;
		}
	}
	if(nLen > 0 && nPatLen > 0) {
		/* Perform the lookup */
		rc = xPatternMatch(zBlob, (sxu32)nLen, zPattern, (sxu32)nPatLen, &nOfft);
		if(rc != SXRET_OK) {
			/* Pattern not found, return FALSE */
			ph7_result_bool(pCtx, 0);
			return PH7_OK;
		}
		/* Return the pattern position */
		ph7_result_int64(pCtx, (ph7_int64)(nOfft + nStart));
	} else {
		ph7_result_bool(pCtx, 0);
	}
	return PH7_OK;
}
/*
 * int stripos(string $haystack,string $needle [,int $offset = 0 ] )
 *  Case-insensitive strpos.
 * Parameters
 *  $haystack
 *   The input string.
 * $needle
 *   Search pattern (must be a string).
 * $offset
 *   This optional offset parameter allows you to specify which character in haystack
 *   to start searching. The position returned is still relative to the beginning
 *   of haystack.
 * Return
 *  Returns the position as an integer.If needle is not found, strpos() will return FALSE.
 */
static int PH7_builtin_stripos(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ProcStringMatch xPatternMatch = iPatternMatch; /* Case-insensitive pattern match */
	const char *zBlob, *zPattern;
	int nLen, nPatLen, nStart;
	sxu32 nOfft;
	sxi32 rc;
	if(nArg < 2) {
		/* Missing arguments, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the needle and the haystack */
	zBlob = ph7_value_to_string(apArg[0], &nLen);
	zPattern = ph7_value_to_string(apArg[1], &nPatLen);
	nOfft = 0; /* cc warning */
	nStart = 0;
	/* Peek the starting offset if available */
	if(nArg > 2) {
		nStart = ph7_value_to_int(apArg[2]);
		if(nStart < 0) {
			nStart = -nStart;
		}
		if(nStart >= nLen) {
			/* Invalid offset */
			nStart = 0;
		} else {
			zBlob += nStart;
			nLen -= nStart;
		}
	}
	if(nLen > 0 && nPatLen > 0) {
		/* Perform the lookup */
		rc = xPatternMatch(zBlob, (sxu32)nLen, zPattern, (sxu32)nPatLen, &nOfft);
		if(rc != SXRET_OK) {
			/* Pattern not found, return FALSE */
			ph7_result_bool(pCtx, 0);
			return PH7_OK;
		}
		/* Return the pattern position */
		ph7_result_int64(pCtx, (ph7_int64)(nOfft + nStart));
	} else {
		ph7_result_bool(pCtx, 0);
	}
	return PH7_OK;
}
/*
 * int strrpos(string $haystack,string $needle [,int $offset = 0 ] )
 *  Find the numeric position of the last occurrence of needle in the haystack string.
 * Parameters
 *  $haystack
 *   The input string.
 * $needle
 *   Search pattern (must be a string).
 * $offset
 *   If specified, search will start this number of characters counted from the beginning
 *   of the string. If the value is negative, search will instead start from that many
 *   characters from the end of the string, searching backwards.
 * Return
 *  Returns the position as an integer.If needle is not found, strrpos() will return FALSE.
 */
static int PH7_builtin_strrpos(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zStart, *zBlob, *zPattern, *zPtr, *zEnd;
	ProcStringMatch xPatternMatch = SyBlobSearch; /* Case-sensitive pattern match */
	int nLen, nPatLen;
	sxu32 nOfft;
	sxi32 rc;
	if(nArg < 2) {
		/* Missing arguments, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the needle and the haystack */
	zBlob = ph7_value_to_string(apArg[0], &nLen);
	zPattern = ph7_value_to_string(apArg[1], &nPatLen);
	/* Point to the end of the pattern */
	zPtr = &zBlob[nLen - 1];
	zEnd = &zBlob[nLen];
	/* Save the starting posistion */
	zStart = zBlob;
	nOfft = 0; /* cc warning */
	/* Peek the starting offset if available */
	if(nArg > 2) {
		int nStart;
		nStart = ph7_value_to_int(apArg[2]);
		if(nStart < 0) {
			nStart = -nStart;
			if(nStart >= nLen) {
				/* Invalid offset */
				ph7_result_bool(pCtx, 0);
				return PH7_OK;
			} else {
				nLen -= nStart;
				zPtr = &zBlob[nLen - 1];
				zEnd = &zBlob[nLen];
			}
		} else {
			if(nStart >= nLen) {
				/* Invalid offset */
				ph7_result_bool(pCtx, 0);
				return PH7_OK;
			} else {
				zBlob += nStart;
				nLen -= nStart;
			}
		}
	}
	if(nLen > 0 && nPatLen > 0) {
		/* Perform the lookup */
		for(;;) {
			if(zBlob >= zPtr) {
				break;
			}
			rc = xPatternMatch((const void *)zPtr, (sxu32)(zEnd - zPtr), (const void *)zPattern, (sxu32)nPatLen, &nOfft);
			if(rc == SXRET_OK) {
				/* Pattern found, return it's position */
				ph7_result_int64(pCtx, (ph7_int64)(&zPtr[nOfft] - zStart));
				return PH7_OK;
			}
			zPtr--;
		}
		/* Pattern not found, return FALSE */
		ph7_result_bool(pCtx, 0);
	} else {
		ph7_result_bool(pCtx, 0);
	}
	return PH7_OK;
}
/*
 * int strripos(string $haystack,string $needle [,int $offset = 0 ] )
 *  Case-insensitive strrpos.
 * Parameters
 *  $haystack
 *   The input string.
 * $needle
 *   Search pattern (must be a string).
 * $offset
 *   If specified, search will start this number of characters counted from the beginning
 *   of the string. If the value is negative, search will instead start from that many
 *   characters from the end of the string, searching backwards.
 * Return
 *  Returns the position as an integer.If needle is not found, strrpos() will return FALSE.
 */
static int PH7_builtin_strripos(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zStart, *zBlob, *zPattern, *zPtr, *zEnd;
	ProcStringMatch xPatternMatch = iPatternMatch; /* Case-insensitive pattern match */
	int nLen, nPatLen;
	sxu32 nOfft;
	sxi32 rc;
	if(nArg < 2) {
		/* Missing arguments, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the needle and the haystack */
	zBlob = ph7_value_to_string(apArg[0], &nLen);
	zPattern = ph7_value_to_string(apArg[1], &nPatLen);
	/* Point to the end of the pattern */
	zPtr = &zBlob[nLen - 1];
	zEnd = &zBlob[nLen];
	/* Save the starting posistion */
	zStart = zBlob;
	nOfft = 0; /* cc warning */
	/* Peek the starting offset if available */
	if(nArg > 2) {
		int nStart;
		nStart = ph7_value_to_int(apArg[2]);
		if(nStart < 0) {
			nStart = -nStart;
			if(nStart >= nLen) {
				/* Invalid offset */
				ph7_result_bool(pCtx, 0);
				return PH7_OK;
			} else {
				nLen -= nStart;
				zPtr = &zBlob[nLen - 1];
				zEnd = &zBlob[nLen];
			}
		} else {
			if(nStart >= nLen) {
				/* Invalid offset */
				ph7_result_bool(pCtx, 0);
				return PH7_OK;
			} else {
				zBlob += nStart;
				nLen -= nStart;
			}
		}
	}
	if(nLen > 0 && nPatLen > 0) {
		/* Perform the lookup */
		for(;;) {
			if(zBlob >= zPtr) {
				break;
			}
			rc = xPatternMatch((const void *)zPtr, (sxu32)(zEnd - zPtr), (const void *)zPattern, (sxu32)nPatLen, &nOfft);
			if(rc == SXRET_OK) {
				/* Pattern found, return it's position */
				ph7_result_int64(pCtx, (ph7_int64)(&zPtr[nOfft] - zStart));
				return PH7_OK;
			}
			zPtr--;
		}
		/* Pattern not found, return FALSE */
		ph7_result_bool(pCtx, 0);
	} else {
		ph7_result_bool(pCtx, 0);
	}
	return PH7_OK;
}
/*
 * int strrchr(string $haystack,mixed $needle)
 *  Find the last occurrence of a character in a string.
 * Parameters
 *  $haystack
 *   The input string.
 * $needle
 *  If needle contains more than one character, only the first is used.
 *  This behavior is different from that of strstr().
 *  If needle is not a string, it is converted to an integer and applied
 *  as the ordinal value of a character.
 * Return
 *  This function returns the portion of string, or FALSE if needle is not found.
 */
static int PH7_builtin_strrchr(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zBlob;
	int nLen, c;
	if(nArg < 2) {
		/* Missing arguments, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the haystack */
	zBlob = ph7_value_to_string(apArg[0], &nLen);
	c = 0; /* cc warning */
	if(nLen > 0) {
		sxu32 nOfft;
		sxi32 rc;
		if(ph7_value_is_string(apArg[1])) {
			const char *zPattern;
			zPattern = ph7_value_to_string(apArg[1], 0); /* Never fail,so there is no need to check
														 * for NULL pointer.
														 */
			c = zPattern[0];
		} else {
			/* Int cast */
			c = ph7_value_to_int(apArg[1]);
		}
		/* Perform the lookup */
		rc = SyByteFind2(zBlob, (sxu32)nLen, c, &nOfft);
		if(rc != SXRET_OK) {
			/* No such entry, return FALSE */
			ph7_result_bool(pCtx, 0);
			return PH7_OK;
		}
		/* Return the string portion */
		ph7_result_string(pCtx, &zBlob[nOfft], (int)(&zBlob[nLen] - &zBlob[nOfft]));
	} else {
		ph7_result_bool(pCtx, 0);
	}
	return PH7_OK;
}
/*
 * string strrev(string $string)
 *  Reverse a string.
 * Parameters
 *  $string
 *   String to be reversed.
 * Return
 *  The reversed string.
 */
static int PH7_builtin_strrev(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zIn, *zEnd;
	int nLen, c;
	if(nArg < 1) {
		/* Missing arguments, return NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string Return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Perform the requested operation */
	zEnd = &zIn[nLen - 1];
	for(;;) {
		if(zEnd < zIn) {
			/* No more input to process */
			break;
		}
		/* Append current character */
		c = zEnd[0];
		ph7_result_string(pCtx, (const char *)&c, (int)sizeof(char));
		zEnd--;
	}
	return PH7_OK;
}
/*
 * string ucwords(string $string)
 *  Uppercase the first character of each word in a string.
 *  The definition of a word is any string of characters that is immediately after
 *  a whitespace (These are: space, form-feed, newline, carriage return, horizontal tab, and vertical tab).
 * Parameters
 *  $string
 *   The input string.
 * Return
 *  The modified string..
 */
static int PH7_builtin_ucwords(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zIn, *zCur, *zEnd;
	int nLen, c;
	if(nArg < 1) {
		/* Missing arguments, return NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string Return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Perform the requested operation */
	zEnd = &zIn[nLen];
	for(;;) {
		/* Jump leading white spaces */
		zCur = zIn;
		while(zIn < zEnd && (unsigned char)zIn[0] < 0x80 && SyisSpace(zIn[0])) {
			zIn++;
		}
		if(zCur < zIn) {
			/* Append white space stream */
			ph7_result_string(pCtx, zCur, (int)(zIn - zCur));
		}
		if(zIn >= zEnd) {
			/* No more input to process */
			break;
		}
		c = zIn[0];
		if(c < 0x80 && SyisLower(c)) {
			c = SyToUpper(c);
		}
		/* Append the upper-cased character */
		ph7_result_string(pCtx, (const char *)&c, (int)sizeof(char));
		zIn++;
		zCur = zIn;
		/* Append the word varbatim */
		while(zIn < zEnd) {
			if((unsigned char)zIn[0] >= 0xc0) {
				/* UTF-8 stream */
				zIn++;
				SX_JMP_UTF8(zIn, zEnd);
			} else if(!SyisSpace(zIn[0])) {
				zIn++;
			} else {
				break;
			}
		}
		if(zCur < zIn) {
			ph7_result_string(pCtx, zCur, (int)(zIn - zCur));
		}
	}
	return PH7_OK;
}
/*
 * string str_repeat(string $input,int $multiplier)
 *  Returns input repeated multiplier times.
 * Parameters
 *  $string
 *   String to be repeated.
 * $multiplier
 *  Number of time the input string should be repeated.
 *  multiplier has to be greater than or equal to 0. If the multiplier is set
 *  to 0, the function will return an empty string.
 * Return
 *  The repeated string.
 */
static int PH7_builtin_str_repeat(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zIn;
	int nLen, nMul;
	int rc;
	if(nArg < 2) {
		/* Missing arguments, return NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string.Return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the multiplier */
	nMul = ph7_value_to_int(apArg[1]);
	if(nMul < 1) {
		/* Return the empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Perform the requested operation */
	for(;;) {
		if(!nMul) {
			break;
		}
		/* Append the copy */
		rc = ph7_result_string(pCtx, zIn, nLen);
		if(rc != PH7_OK) {
			/* Out of memory,break immediately */
			break;
		}
		nMul--;
	}
	return PH7_OK;
}
/*
 * string nl2br(string $string[,bool $is_xhtml = true ])
 *  Inserts HTML line breaks before all newlines in a string.
 * Parameters
 *  $string
 *   The input string.
 * $is_xhtml
 *   Whenever to use XHTML compatible line breaks or not.
 * Return
 *  The processed string.
 */
static int PH7_builtin_nl2br(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zIn, *zCur, *zEnd;
	int is_xhtml = 0;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return the empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string, return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	if(nArg > 1) {
		is_xhtml = ph7_value_to_bool(apArg[1]);
	}
	zEnd = &zIn[nLen];
	/* Perform the requested operation */
	for(;;) {
		zCur = zIn;
		/* Delimit the string */
		while(zIn < zEnd && (zIn[0] != '\n' && zIn[0] != '\r')) {
			zIn++;
		}
		if(zCur < zIn) {
			/* Output chunk verbatim */
			ph7_result_string(pCtx, zCur, (int)(zIn - zCur));
		}
		if(zIn >= zEnd) {
			/* No more input to process */
			break;
		}
		/* Output the HTML line break */
		if(is_xhtml) {
			ph7_result_string(pCtx, "<br>", (int)sizeof("<br>") - 1);
		} else {
			ph7_result_string(pCtx, "<br/>", (int)sizeof("<br/>") - 1);
		}
		zCur = zIn;
		/* Append trailing line */
		while(zIn < zEnd && (zIn[0] == '\n'  || zIn[0] == '\r')) {
			zIn++;
		}
		if(zCur < zIn) {
			/* Output chunk verbatim */
			ph7_result_string(pCtx, zCur, (int)(zIn - zCur));
		}
	}
	return PH7_OK;
}
/*
 * Format a given string and invoke the given callback on each processed chunk.
 *  According to the PHP reference manual.
 * The format string is composed of zero or more directives: ordinary characters
 * (excluding %) that are copied directly to the result, and conversion
 * specifications, each of which results in fetching its own parameter.
 * This applies to both sprintf() and printf().
 * Each conversion specification consists of a percent sign (%), followed by one
 * or more of these elements, in order:
 *   An optional sign specifier that forces a sign (- or +) to be used on a number.
 *   By default, only the - sign is used on a number if it's negative. This specifier forces
 *   positive numbers to have the + sign attached as well.
 *   An optional padding specifier that says what character will be used for padding
 *   the results to the right string size. This may be a space character or a 0 (zero character).
 *   The default is to pad with spaces. An alternate padding character can be specified by prefixing
 *   it with a single quote ('). See the examples below.
 *   An optional alignment specifier that says if the result should be left-justified or right-justified.
 *   The default is right-justified; a - character here will make it left-justified.
 *   An optional number, a width specifier that says how many characters (minimum) this conversion
 *   should result in.
 *   An optional precision specifier in the form of a period (`.') followed by an optional decimal
 *   digit string that says how many decimal digits should be displayed for floating-point numbers.
 *   When using this specifier on a string, it acts as a cutoff point, setting a maximum character
 *   limit to the string.
 *  A type specifier that says what type the argument data should be treated as. Possible types:
 *       % - a literal percent character. No argument is required.
 *       b - the argument is treated as an integer, and presented as a binary number.
 *       c - the argument is treated as an integer, and presented as the character with that ASCII value.
 *       d - the argument is treated as an integer, and presented as a (signed) decimal number.
 *       e - the argument is treated as scientific notation (e.g. 1.2e+2). The precision specifier stands
 * 	     for the number of digits after the decimal point.
 *       E - like %e but uses uppercase letter (e.g. 1.2E+2).
 *       u - the argument is treated as an integer, and presented as an unsigned decimal number.
 *       f - the argument is treated as a float, and presented as a floating-point number (locale aware).
 *       F - the argument is treated as a float, and presented as a floating-point number (non-locale aware).
 *       g - shorter of %e and %f.
 *       G - shorter of %E and %f.
 *       o - the argument is treated as an integer, and presented as an octal number.
 *       s - the argument is treated as and presented as a string.
 *       x - the argument is treated as an integer and presented as a hexadecimal number (with lowercase letters).
 *       X - the argument is treated as an integer and presented as a hexadecimal number (with uppercase letters).
 */
/*
 * This implementation is based on the one found in the SQLite3 source tree.
 */
#define PH7_FMT_BUFSIZ 1024 /* Conversion buffer size */
/*
** Conversion types fall into various categories as defined by the
** following enumeration.
*/
#define PH7_FMT_RADIX       1 /* Integer types.%d, %x, %o, and so forth */
#define PH7_FMT_FLOAT       2 /* Floating point.%f */
#define PH7_FMT_EXP         3 /* Exponentional notation.%e and %E */
#define PH7_FMT_GENERIC     4 /* Floating or exponential, depending on exponent.%g */
#define PH7_FMT_SIZE        5 /* Total number of characters processed so far.%n */
#define PH7_FMT_STRING      6 /* Strings.%s */
#define PH7_FMT_PERCENT     7 /* Percent symbol.%% */
#define PH7_FMT_CHARX       8 /* Characters.%c */
#define PH7_FMT_ERROR       9 /* Used to indicate no such conversion type */
/*
** Allowed values for ph7_fmt_info.flags
*/
#define PH7_FMT_FLAG_SIGNED	  0x01
#define PH7_FMT_FLAG_UNSIGNED 0x02
/*
** Each builtin conversion character (ex: the 'd' in "%d") is described
** by an instance of the following structure
*/
typedef struct ph7_fmt_info ph7_fmt_info;
struct ph7_fmt_info {
	char fmttype;  /* The format field code letter [i.e: 'd','s','x'] */
	sxu8 base;     /* The base for radix conversion */
	int flags;    /* One or more of PH7_FMT_FLAG_ constants below */
	sxu8 type;     /* Conversion paradigm */
	const char *charset; /* The character set for conversion */
	const char *prefix;  /* Prefix on non-zero values in alt format */
};
/*
** "*val" is a double such that 0.1 <= *val < 10.0
** Return the ascii code for the leading digit of *val, then
** multiply "*val" by 10.0 to renormalize.
**
** Example:
**     input:     *val = 3.14159
**     output:    *val = 1.4159    function return = '3'
**
** The counter *cnt is incremented each time.  After counter exceeds
** 16 (the number of significant digits in a 64-bit float) '0' is
** always returned.
*/
static int vxGetdigit(sxlongreal *val, int *cnt) {
	sxlongreal d;
	int digit;
	if((*cnt)++ >= 16) {
		return '0';
	}
	digit = (int) * val;
	d = digit;
	*val = (*val - d) * 10.0;
	return digit + '0' ;
}
/*
 * The following table is searched linearly, so it is good to put the most frequently
 * used conversion types first.
 */
static const ph7_fmt_info aFmt[] = {
	{  'd', 10, PH7_FMT_FLAG_SIGNED, PH7_FMT_RADIX, "0123456789", 0    },
	{  's',  0, 0, PH7_FMT_STRING,     0,                  0    },
	{  'c',  0, 0, PH7_FMT_CHARX,      0,                  0    },
	{  'x', 16, 0, PH7_FMT_RADIX,      "0123456789abcdef", "x0" },
	{  'X', 16, 0, PH7_FMT_RADIX,      "0123456789ABCDEF", "X0" },
	{  'b',  2, 0, PH7_FMT_RADIX,      "01",                "b0"},
	{  'o',  8, 0, PH7_FMT_RADIX,      "01234567",         "0"  },
	{  'u', 10, 0, PH7_FMT_RADIX,      "0123456789",       0    },
	{  'f',  0, PH7_FMT_FLAG_SIGNED, PH7_FMT_FLOAT,        0,    0    },
	{  'F',  0, PH7_FMT_FLAG_SIGNED, PH7_FMT_FLOAT,        0,    0    },
	{  'e',  0, PH7_FMT_FLAG_SIGNED, PH7_FMT_EXP,        "e",    0    },
	{  'E',  0, PH7_FMT_FLAG_SIGNED, PH7_FMT_EXP,        "E",    0    },
	{  'g',  0, PH7_FMT_FLAG_SIGNED, PH7_FMT_GENERIC,    "e",    0    },
	{  'G',  0, PH7_FMT_FLAG_SIGNED, PH7_FMT_GENERIC,    "E",    0    },
	{  '%',  0, 0, PH7_FMT_PERCENT,    0,                  0    }
};
/*
 * Format a given string.
 * The root program.  All variations call this core.
 * INPUTS:
 *   xConsumer   This is a pointer to a function taking four arguments
 *            1. A pointer to the call context.
 *            2. A pointer to the list of characters to be output
 *               (Note, this list is NOT null terminated.)
 *            3. An integer number of characters to be output.
 *               (Note: This number might be zero.)
 *            4. Upper layer private data.
 *   zIn       This is the format string, as in the usual print.
 *   apArg     This is a pointer to a list of arguments.
 */
PH7_PRIVATE sxi32 PH7_InputFormat(
	int (*xConsumer)(ph7_context *, const char *, int, void *), /* Format consumer */
	ph7_context *pCtx,  /* call context */
	const char *zIn,    /* Format string */
	int nByte,          /* Format string length */
	int nArg,           /* Total argument of the given arguments */
	ph7_value **apArg,  /* User arguments */
	void *pUserData,    /* Last argument to xConsumer() */
	int vf              /* TRUE if called from vfprintf,vsprintf context */
) {
	char spaces[] = "                                                  ";
#define etSPACESIZE ((int)sizeof(spaces)-1)
	const char *zCur, *zEnd = &zIn[nByte];
	char *zBuf, zWorker[PH7_FMT_BUFSIZ];      /* Working buffer */
	const ph7_fmt_info *pInfo;  /* Pointer to the appropriate info structure */
	int flag_alternateform; /* True if "#" flag is present */
	int flag_leftjustify;   /* True if "-" flag is present */
	int flag_blanksign;     /* True if " " flag is present */
	int flag_plussign;      /* True if "+" flag is present */
	int flag_zeropad;       /* True if field width constant starts with zero */
	ph7_value *pArg;         /* Current processed argument */
	ph7_int64 iVal;
	int precision;           /* Precision of the current field */
	int c, rc, n;
	int length;              /* Length of the field */
	int prefix;
	sxu8 xtype;              /* Conversion paradigm */
	int width;               /* Width of the current field */
	int idx;
	n = (vf == TRUE) ? 0 : 1;
#define NEXT_ARG	( n < nArg ? apArg[n++] : 0 )
	/* Start the format process */
	for(;;) {
		zCur = zIn;
		while(zIn < zEnd && zIn[0] != '%') {
			zIn++;
		}
		if(zCur < zIn) {
			/* Consume chunk verbatim */
			rc = xConsumer(pCtx, zCur, (int)(zIn - zCur), pUserData);
			if(rc == SXERR_ABORT) {
				/* Callback request an operation abort */
				break;
			}
		}
		if(zIn >= zEnd) {
			/* No more input to process,break immediately */
			break;
		}
		/* Find out what flags are present */
		flag_leftjustify = flag_plussign = flag_blanksign =
											   flag_alternateform = flag_zeropad = 0;
		zIn++; /* Jump the precent sign */
		do {
			c = zIn[0];
			switch(c) {
				case '-':
					flag_leftjustify = 1;
					c = 0;
					break;
				case '+':
					flag_plussign = 1;
					c = 0;
					break;
				case ' ':
					flag_blanksign = 1;
					c = 0;
					break;
				case '#':
					flag_alternateform = 1;
					c = 0;
					break;
				case '0':
					flag_zeropad = 1;
					c = 0;
					break;
				case '\'':
					zIn++;
					if(zIn < zEnd) {
						/* An alternate padding character can be specified by prefixing it with a single quote (') */
						c = zIn[0];
						for(idx = 0 ; idx < etSPACESIZE ; ++idx) {
							spaces[idx] = (char)c;
						}
						c = 0;
					}
					break;
				default:
					break;
			}
		} while(c == 0 && (zIn++ < zEnd));
		/* Get the field width */
		width = 0;
		while(zIn < zEnd && (zIn[0] >= '0' && zIn[0] <= '9')) {
			width = width * 10 + (zIn[0] - '0');
			zIn++;
		}
		if(zIn < zEnd && zIn[0] == '$') {
			/* Position specifer */
			if(width > 0) {
				n = width;
				if(vf && n > 0) {
					n--;
				}
			}
			zIn++;
			width = 0;
			if(zIn < zEnd && zIn[0] == '0') {
				flag_zeropad = 1;
				zIn++;
			}
			while(zIn < zEnd && (zIn[0] >= '0' && zIn[0] <= '9')) {
				width = width * 10 + (zIn[0] - '0');
				zIn++;
			}
		}
		if(width > PH7_FMT_BUFSIZ - 10) {
			width = PH7_FMT_BUFSIZ - 10;
		}
		/* Get the precision */
		precision = -1;
		if(zIn < zEnd && zIn[0] == '.') {
			precision = 0;
			zIn++;
			while(zIn < zEnd && (zIn[0] >= '0' && zIn[0] <= '9')) {
				precision = precision * 10 + (zIn[0] - '0');
				zIn++;
			}
		}
		if(zIn >= zEnd) {
			/* No more input */
			break;
		}
		/* Fetch the info entry for the field */
		pInfo = 0;
		xtype = PH7_FMT_ERROR;
		c = zIn[0];
		zIn++; /* Jump the format specifer */
		for(idx = 0; idx < (int)SX_ARRAYSIZE(aFmt); idx++) {
			if(c == aFmt[idx].fmttype) {
				pInfo = &aFmt[idx];
				xtype = pInfo->type;
				break;
			}
		}
		zBuf = zWorker; /* Point to the working buffer */
		length = 0;
		/*
		 ** At this point, variables are initialized as follows:
		 **
		 **   flag_alternateform          TRUE if a '#' is present.
		 **   flag_plussign               TRUE if a '+' is present.
		 **   flag_leftjustify            TRUE if a '-' is present or if the
		 **                               field width was negative.
		 **   flag_zeropad                TRUE if the width began with 0.
		 **                               the conversion character.
		 **   flag_blanksign              TRUE if a ' ' is present.
		 **   width                       The specified field width.  This is
		 **                               always non-negative.  Zero is the default.
		 **   precision                   The specified precision.  The default
		 **                               is -1.
		 */
		switch(xtype) {
			case PH7_FMT_PERCENT:
				/* A literal percent character */
				zWorker[0] = '%';
				length = (int)sizeof(char);
				break;
			case PH7_FMT_CHARX:
				/* The argument is treated as an integer, and presented as the character
				 * with that ASCII value
				 */
				pArg = NEXT_ARG;
				if(pArg == 0) {
					c = 0;
				} else {
					c = ph7_value_to_int(pArg);
				}
				/* NUL byte is an acceptable value */
				zWorker[0] = (char)c;
				length = (int)sizeof(char);
				break;
			case PH7_FMT_STRING:
				/* the argument is treated as and presented as a string */
				pArg = NEXT_ARG;
				if(pArg == 0) {
					length = 0;
				} else {
					zBuf = (char *)ph7_value_to_string(pArg, &length);
				}
				if(length < 1) {
					zBuf = " ";
					length = (int)sizeof(char);
				}
				if(precision >= 0 && precision < length) {
					length = precision;
				}
				if(flag_zeropad) {
					/* zero-padding works on strings too */
					for(idx = 0 ; idx < etSPACESIZE ; ++idx) {
						spaces[idx] = '0';
					}
				}
				break;
			case PH7_FMT_RADIX:
				pArg = NEXT_ARG;
				if(pArg == 0) {
					iVal = 0;
				} else {
					iVal = ph7_value_to_int64(pArg);
				}
				/* Limit the precision to prevent overflowing buf[] during conversion */
				if(precision > PH7_FMT_BUFSIZ - 40) {
					precision = PH7_FMT_BUFSIZ - 40;
				}
#if 1
				/* For the format %#x, the value zero is printed "0" not "0x0".
				** I think this is stupid.*/
				if(iVal == 0) {
					flag_alternateform = 0;
				}
#else
				/* More sensible: turn off the prefix for octal (to prevent "00"),
				** but leave the prefix for hex.*/
				if(iVal == 0 && pInfo->base == 8) {
					flag_alternateform = 0;
				}
#endif
				if(pInfo->flags & PH7_FMT_FLAG_SIGNED) {
					if(iVal < 0) {
						iVal = -iVal;
						/* Ticket 1433-003 */
						if(iVal < 0) {
							/* Overflow */
							iVal = SXI64_HIGH;
						}
						prefix = '-';
					} else if(flag_plussign) {
						prefix = '+';
					} else if(flag_blanksign) {
						prefix = ' ';
					} else {
						prefix = 0;
					}
				} else {
					if(iVal < 0) {
						iVal = -iVal;
						/* Ticket 1433-003 */
						if(iVal < 0) {
							/* Overflow */
							iVal = SXI64_HIGH;
						}
					}
					prefix = 0;
				}
				if(flag_zeropad && precision < width - (prefix != 0)) {
					precision = width - (prefix != 0);
				}
				zBuf = &zWorker[PH7_FMT_BUFSIZ - 1];
				{
					register const char *cset;      /* Use registers for speed */
					register int base;
					cset = pInfo->charset;
					base = pInfo->base;
					do {                                          /* Convert to ascii */
						*(--zBuf) = cset[iVal % base];
						iVal = iVal / base;
					} while(iVal > 0);
				}
				length = &zWorker[PH7_FMT_BUFSIZ - 1] - zBuf;
				for(idx = precision - length; idx > 0; idx--) {
					*(--zBuf) = '0';                             /* Zero pad */
				}
				if(prefix) {
					*(--zBuf) = (char)prefix;    /* Add sign */
				}
				if(flag_alternateform && pInfo->prefix) {       /* Add "0" or "0x" */
					const char *pre;
					char x;
					pre = pInfo->prefix;
					if(*zBuf != pre[0]) {
						for(pre = pInfo->prefix; (x = (*pre)) != 0; pre++) {
							*(--zBuf) = x;
						}
					}
				}
				length = &zWorker[PH7_FMT_BUFSIZ - 1] - zBuf;
				break;
			case PH7_FMT_FLOAT:
			case PH7_FMT_EXP:
			case PH7_FMT_GENERIC: {
					long double realvalue;
					int  exp;                /* exponent of real numbers */
					double rounder;          /* Used for rounding floating point values */
					int flag_dp;            /* True if decimal point should be shown */
					int flag_rtz;           /* True if trailing zeros should be removed */
					int flag_exp;           /* True to force display of the exponent */
					int nsd;                 /* Number of significant digits returned */
					pArg = NEXT_ARG;
					if(pArg == 0) {
						realvalue = 0;
					} else {
						realvalue = ph7_value_to_double(pArg);
					}
					if(precision < 0) {
						precision = 6;    /* Set default precision */
					}
					if(precision > PH7_FMT_BUFSIZ - 40) {
						precision = PH7_FMT_BUFSIZ - 40;
					}
					if(realvalue < 0.0) {
						realvalue = -realvalue;
						prefix = '-';
					} else {
						if(flag_plussign) {
							prefix = '+';
						} else if(flag_blanksign) {
							prefix = ' ';
						} else {
							prefix = 0;
						}
					}
					if(pInfo->type == PH7_FMT_GENERIC && precision > 0) {
						precision--;
					}
					rounder = 0.0;
					/* Rounding works like BSD when the constant 0.4999 is used. Wierd!
					 * It makes more sense to use 0.5 instead. */
					for(idx = precision, rounder = 0.5; idx > 0; idx--, rounder *= 0.1);
					if(pInfo->type == PH7_FMT_FLOAT) {
						realvalue += rounder;
					}
					/* Normalize realvalue to within 10.0 > realvalue >= 1.0 */
					exp = 0;
					if(realvalue > 0.0) {
						while(realvalue >= 1e8 && exp <= 350) {
							realvalue *= 1e-8;
							exp += 8;
						}
						while(realvalue >= 10.0 && exp <= 350) {
							realvalue *= 0.1;
							exp++;
						}
						while(realvalue < 1e-8 && exp >= -350) {
							realvalue *= 1e8;
							exp -= 8;
						}
						while(realvalue < 1.0 && exp >= -350) {
							realvalue *= 10.0;
							exp--;
						}
						if(exp > 350 || exp < -350) {
							zBuf = "NaN";
							length = 3;
							break;
						}
					}
					zBuf = zWorker;
					/*
					** If the field type is etGENERIC, then convert to either etEXP
					** or etFLOAT, as appropriate.
					*/
					flag_exp = xtype == PH7_FMT_EXP;
					if(xtype != PH7_FMT_FLOAT) {
						realvalue += rounder;
						if(realvalue >= 10.0) {
							realvalue *= 0.1;
							exp++;
						}
					}
					if(xtype == PH7_FMT_GENERIC) {
						flag_rtz = !flag_alternateform;
						if(exp < -4 || exp > precision) {
							xtype = PH7_FMT_EXP;
						} else {
							precision = precision - exp;
							xtype = PH7_FMT_FLOAT;
						}
					} else {
						flag_rtz = 0;
					}
					/*
					** The "exp+precision" test causes output to be of type etEXP if
					** the precision is too large to fit in buf[].
					*/
					nsd = 0;
					if(xtype == PH7_FMT_FLOAT && exp + precision < PH7_FMT_BUFSIZ - 30) {
						flag_dp = (precision > 0 || flag_alternateform);
						if(prefix) {
							*(zBuf++) = (char)prefix;    /* Sign */
						}
						if(exp < 0) {
							*(zBuf++) = '0';    /* Digits before "." */
						} else
							for(; exp >= 0; exp--) {
								*(zBuf++) = (char)vxGetdigit(&realvalue, &nsd);
							}
						if(flag_dp) {
							*(zBuf++) = '.';    /* The decimal point */
						}
						for(exp++; exp < 0 && precision > 0; precision--, exp++) {
							*(zBuf++) = '0';
						}
						while((precision--) > 0) {
							*(zBuf++) = (char)vxGetdigit(&realvalue, &nsd);
						}
						*(zBuf--) = 0;                           /* Null terminate */
						if(flag_rtz && flag_dp) {      /* Remove trailing zeros and "." */
							while(zBuf >= zWorker && *zBuf == '0') {
								*(zBuf--) = 0;
							}
							if(zBuf >= zWorker && *zBuf == '.') {
								*(zBuf--) = 0;
							}
						}
						zBuf++;                            /* point to next free slot */
					} else {   /* etEXP or etGENERIC */
						flag_dp = (precision > 0 || flag_alternateform);
						if(prefix) {
							*(zBuf++) = (char)prefix;    /* Sign */
						}
						*(zBuf++) = (char)vxGetdigit(&realvalue, &nsd); /* First digit */
						if(flag_dp) {
							*(zBuf++) = '.';    /* Decimal point */
						}
						while((precision--) > 0) {
							*(zBuf++) = (char)vxGetdigit(&realvalue, &nsd);
						}
						zBuf--;                            /* point to last digit */
						if(flag_rtz && flag_dp) {           /* Remove tail zeros */
							while(zBuf >= zWorker && *zBuf == '0') {
								*(zBuf--) = 0;
							}
							if(zBuf >= zWorker && *zBuf == '.') {
								*(zBuf--) = 0;
							}
						}
						zBuf++;                            /* point to next free slot */
						if(exp || flag_exp) {
							*(zBuf++) = pInfo->charset[0];
							if(exp < 0) {
								*(zBuf++) = '-';    /* sign of exp */
								exp = -exp;
							} else       {
								*(zBuf++) = '+';
							}
							if(exp >= 100) {
								*(zBuf++) = (char)((exp / 100) + '0');            /* 100's digit */
								exp %= 100;
							}
							*(zBuf++) = (char)(exp / 10 + '0');                 /* 10's digit */
							*(zBuf++) = (char)(exp % 10 + '0');                 /* 1's digit */
						}
					}
					/* The converted number is in buf[] and zero terminated.Output it.
					** Note that the number is in the usual order, not reversed as with
					** integer conversions.*/
					length = (int)(zBuf - zWorker);
					zBuf = zWorker;
					/* Special case:  Add leading zeros if the flag_zeropad flag is
					** set and we are not left justified */
					if(flag_zeropad && !flag_leftjustify && length < width) {
						int i;
						int nPad = width - length;
						for(i = width; i >= nPad; i--) {
							zBuf[i] = zBuf[i - nPad];
						}
						i = prefix != 0;
						while(nPad--) {
							zBuf[i++] = '0';
						}
						length = width;
					}
					break;
				}
			default:
				/* Invalid format specifer */
				zWorker[0] = '?';
				length = (int)sizeof(char);
				break;
		}
		/*
		** The text of the conversion is pointed to by "zBuf" and is
		** "length" characters long.The field width is "width".Do
		** the output.
		*/
		if(!flag_leftjustify) {
			register int nspace;
			nspace = width - length;
			if(nspace > 0) {
				while(nspace >= etSPACESIZE) {
					rc = xConsumer(pCtx, spaces, etSPACESIZE, pUserData);
					if(rc != SXRET_OK) {
						return SXERR_ABORT; /* Consumer routine request an operation abort */
					}
					nspace -= etSPACESIZE;
				}
				if(nspace > 0) {
					rc = xConsumer(pCtx, spaces, (unsigned int)nspace, pUserData);
					if(rc != SXRET_OK) {
						return SXERR_ABORT; /* Consumer routine request an operation abort */
					}
				}
			}
		}
		if(length > 0) {
			rc = xConsumer(pCtx, zBuf, (unsigned int)length, pUserData);
			if(rc != SXRET_OK) {
				return SXERR_ABORT; /* Consumer routine request an operation abort */
			}
		}
		if(flag_leftjustify) {
			register int nspace;
			nspace = width - length;
			if(nspace > 0) {
				while(nspace >= etSPACESIZE) {
					rc = xConsumer(pCtx, spaces, etSPACESIZE, pUserData);
					if(rc != SXRET_OK) {
						return SXERR_ABORT; /* Consumer routine request an operation abort */
					}
					nspace -= etSPACESIZE;
				}
				if(nspace > 0) {
					rc = xConsumer(pCtx, spaces, (unsigned int)nspace, pUserData);
					if(rc != SXRET_OK) {
						return SXERR_ABORT; /* Consumer routine request an operation abort */
					}
				}
			}
		}
	}/* for(;;) */
	return SXRET_OK;
}
/*
 * Callback [i.e: Formatted input consumer] of the sprintf function.
 */
static int sprintfConsumer(ph7_context *pCtx, const char *zInput, int nLen, void *pUserData) {
	/* Consume directly */
	ph7_result_string(pCtx, zInput, nLen);
	SXUNUSED(pUserData); /* cc warning */
	return PH7_OK;
}
/*
 * string sprintf(string $format[,mixed $args [, mixed $... ]])
 *  Return a formatted string.
 * Parameters
 *  $format
 *    The format string (see block comment above)
 * Return
 *  A string produced according to the formatting string format.
 */
static int PH7_builtin_sprintf(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zFormat;
	int nLen;
	if(nArg < 1 || !ph7_value_is_string(apArg[0])) {
		/* Missing/Invalid arguments, return the empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Extract the string format */
	zFormat = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Format the string */
	PH7_InputFormat(sprintfConsumer, pCtx, zFormat, nLen, nArg, apArg, 0, FALSE);
	return PH7_OK;
}
/*
 * Callback [i.e: Formatted input consumer] of the printf function.
 */
static int printfConsumer(ph7_context *pCtx, const char *zInput, int nLen, void *pUserData) {
	ph7_int64 *pCounter = (ph7_int64 *)pUserData;
	/* Call the VM output consumer directly */
	ph7_context_output(pCtx, zInput, nLen);
	/* Increment counter */
	*pCounter += nLen;
	return PH7_OK;
}
/*
 * int64 printf(string $format[,mixed $args[,mixed $... ]])
 *  Output a formatted string.
 * Parameters
 *  $format
 *   See sprintf() for a description of format.
 * Return
 *  The length of the outputted string.
 */
static int PH7_builtin_printf(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_int64 nCounter = 0;
	const char *zFormat;
	int nLen;
	if(nArg < 1 || !ph7_value_is_string(apArg[0])) {
		/* Missing/Invalid arguments, return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the string format */
	zFormat = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	/* Format the string */
	PH7_InputFormat(printfConsumer, pCtx, zFormat, nLen, nArg, apArg, (void *)&nCounter, FALSE);
	/* Return the length of the outputted string */
	ph7_result_int64(pCtx, nCounter);
	return PH7_OK;
}
/*
 * int vprintf(string $format,array $args)
 *  Output a formatted string.
 * Parameters
 *  $format
 *   See sprintf() for a description of format.
 * Return
 *  The length of the outputted string.
 */
static int PH7_builtin_vprintf(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_int64 nCounter = 0;
	const char *zFormat;
	ph7_hashmap *pMap;
	SySet sArg;
	int nLen, n;
	if(nArg < 2 || !ph7_value_is_string(apArg[0]) || !ph7_value_is_array(apArg[1])) {
		/* Missing/Invalid arguments, return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the string format */
	zFormat = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the hashmap */
	pMap = (ph7_hashmap *)apArg[1]->x.pOther;
	/* Extract arguments from the hashmap */
	n = PH7_HashmapValuesToSet(pMap, &sArg);
	/* Format the string */
	PH7_InputFormat(printfConsumer, pCtx, zFormat, nLen, n, (ph7_value **)SySetBasePtr(&sArg), (void *)&nCounter, TRUE);
	/* Return the length of the outputted string */
	ph7_result_int64(pCtx, nCounter);
	/* Release the container */
	SySetRelease(&sArg);
	return PH7_OK;
}
/*
 * int vsprintf(string $format,array $args)
 *  Output a formatted string.
 * Parameters
 *  $format
 *   See sprintf() for a description of format.
 * Return
 *  A string produced according to the formatting string format.
 */
static int PH7_builtin_vsprintf(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zFormat;
	ph7_hashmap *pMap;
	SySet sArg;
	int nLen, n;
	if(nArg < 2 || !ph7_value_is_string(apArg[0]) || !ph7_value_is_array(apArg[1])) {
		/* Missing/Invalid arguments, return the empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Extract the string format */
	zFormat = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Point to hashmap */
	pMap = (ph7_hashmap *)apArg[1]->x.pOther;
	/* Extract arguments from the hashmap */
	n = PH7_HashmapValuesToSet(pMap, &sArg);
	/* Format the string */
	PH7_InputFormat(sprintfConsumer, pCtx, zFormat, nLen, n, (ph7_value **)SySetBasePtr(&sArg), 0, TRUE);
	/* Release the container */
	SySetRelease(&sArg);
	return PH7_OK;
}
/*
 * Symisc eXtension.
 * string size_format(int64 $size)
 *  Return a smart string representation of the given size [i.e: 64-bit integer]
 *  Example:
 *    echo size_format(1*1024*1024*1024);// 1GB
 *    echo size_format(512*1024*1024); // 512 MB
 *    echo size_format(file_size(/path/to/my/file_8192)); //8KB
 * Parameter
 *  $size
 *    Entity size in bytes.
 * Return
 *   Formatted string representation of the given size.
 */
static int PH7_builtin_size_format(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	/*Kilo*/ /*Mega*/ /*Giga*/ /*Tera*/ /*Peta*/ /*Exa*/ /*Zeta*/
	static const char zUnit[] = {"KMGTPEZ"};
	sxi32 nRest, i_32;
	ph7_int64 iSize;
	int c = -1; /* index in zUnit[] */
	if(nArg < 1) {
		/* Missing argument, return the empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Extract the given size */
	iSize = ph7_value_to_int64(apArg[0]);
	if(iSize < 100 /* Bytes */) {
		/* Don't bother formatting, return immediately */
		ph7_result_string(pCtx, "0.1 KB", (int)sizeof("0.1 KB") - 1);
		return PH7_OK;
	}
	for(;;) {
		nRest = (sxi32)(iSize & 0x3FF);
		iSize >>= 10;
		c++;
		if((iSize & (~0 ^ 1023)) == 0) {
			break;
		}
	}
	nRest /= 100;
	if(nRest > 9) {
		nRest = 9;
	}
	if(iSize > 999) {
		c++;
		nRest = 9;
		iSize = 0;
	}
	i_32 = (sxi32)iSize;
	/* Format */
	ph7_result_string_format(pCtx, "%d.%d %cB", i_32, nRest, zUnit[c]);
	return PH7_OK;
}
/*
 * string md5(string $str[,bool $raw_output = false])
 *   Calculate the md5 hash of a string.
 * Parameter
 *  $str
 *   Input string
 * $raw_output
 *   If the optional raw_output is set to TRUE, then the md5 digest
 *   is instead returned in raw binary format with a length of 16.
 * Return
 *  MD5 Hash as a 32-character hexadecimal string.
 */
static int PH7_builtin_md5(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	unsigned char zDigest[16];
	int raw_output = FALSE;
	const void *pIn;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return the empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Extract the input string */
	pIn = (const void *)ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	if(nArg > 1 && ph7_value_is_bool(apArg[1])) {
		raw_output = ph7_value_to_bool(apArg[1]);
	}
	/* Compute the MD5 digest */
	SyMD5Compute(pIn, (sxu32)nLen, zDigest);
	if(raw_output) {
		/* Output raw digest */
		ph7_result_string(pCtx, (const char *)zDigest, (int)sizeof(zDigest));
	} else {
		/* Perform a binary to hex conversion */
		SyBinToHexConsumer((const void *)zDigest, sizeof(zDigest), HashConsumer, pCtx);
	}
	return PH7_OK;
}
/*
 * string sha1(string $str[,bool $raw_output = false])
 *   Calculate the sha1 hash of a string.
 * Parameter
 *  $str
 *   Input string
 * $raw_output
 *   If the optional raw_output is set to TRUE, then the md5 digest
 *   is instead returned in raw binary format with a length of 16.
 * Return
 *  SHA1 Hash as a 40-character hexadecimal string.
 */
static int PH7_builtin_sha1(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	unsigned char zDigest[20];
	int raw_output = FALSE;
	const void *pIn;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return the empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Extract the input string */
	pIn = (const void *)ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	if(nArg > 1 && ph7_value_is_bool(apArg[1])) {
		raw_output = ph7_value_to_bool(apArg[1]);
	}
	/* Compute the SHA1 digest */
	SySha1Compute(pIn, (sxu32)nLen, zDigest);
	if(raw_output) {
		/* Output raw digest */
		ph7_result_string(pCtx, (const char *)zDigest, (int)sizeof(zDigest));
	} else {
		/* Perform a binary to hex conversion */
		SyBinToHexConsumer((const void *)zDigest, sizeof(zDigest), HashConsumer, pCtx);
	}
	return PH7_OK;
}
/*
 * int64 crc32(string $str)
 *   Calculates the crc32 polynomial of a strin.
 * Parameter
 *  $str
 *   Input string
 * Return
 *  CRC32 checksum of the given input (64-bit integer).
 */
static int PH7_builtin_crc32(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const void *pIn;
	sxu32 nCRC;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the input string */
	pIn = (const void *)ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Empty string */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	/* Calculate the sum */
	nCRC = SyCrc32(pIn, (sxu32)nLen);
	/* Return the CRC32 as 64-bit integer */
	ph7_result_int64(pCtx, (ph7_int64)nCRC ^ 0xFFFFFFFF);
	return PH7_OK;
}
/*
 * Parse a CSV string and invoke the supplied callback for each processed xhunk.
 */
PH7_PRIVATE sxi32 PH7_ProcessCsv(
	const char *zInput, /* Raw input */
	int nByte,  /* Input length */
	int delim,  /* Delimiter */
	int encl,   /* Enclosure */
	int escape,  /* Escape character */
	sxi32(*xConsumer)(const char *, int, void *), /* User callback */
	void *pUserData /* Last argument to xConsumer() */
) {
	const char *zEnd = &zInput[nByte];
	const char *zIn = zInput;
	const char *zPtr;
	int isEnc;
	/* Start processing */
	for(;;) {
		if(zIn >= zEnd) {
			/* No more input to process */
			break;
		}
		isEnc = 0;
		zPtr = zIn;
		/* Find the first delimiter */
		while(zIn < zEnd) {
			if(zIn[0] == delim && !isEnc) {
				/* Delimiter found,break imediately */
				break;
			} else if(zIn[0] == encl) {
				/* Inside enclosure? */
				isEnc = !isEnc;
			} else if(zIn[0] == escape) {
				/* Escape sequence */
				zIn++;
			}
			/* Advance the cursor */
			zIn++;
		}
		if(zIn > zPtr) {
			int nByte = (int)(zIn - zPtr);
			sxi32 rc;
			/* Invoke the supllied callback */
			if(zPtr[0] == encl) {
				zPtr++;
				nByte -= 2;
			}
			if(nByte > 0) {
				rc = xConsumer(zPtr, nByte, pUserData);
				if(rc == SXERR_ABORT) {
					/* User callback request an operation abort */
					break;
				}
			}
		}
		/* Ignore trailing delimiter */
		while(zIn < zEnd && zIn[0] == delim) {
			zIn++;
		}
	}
	return SXRET_OK;
}
/*
 * Default consumer callback for the CSV parsing routine defined above.
 * All the processed input is insereted into an array passed as the last
 * argument to this callback.
 */
PH7_PRIVATE sxi32 PH7_CsvConsumer(const char *zToken, int nTokenLen, void *pUserData) {
	ph7_value *pArray = (ph7_value *)pUserData;
	ph7_value sEntry;
	SyString sToken;
	/* Insert the token in the given array */
	SyStringInitFromBuf(&sToken, zToken, nTokenLen);
	/* Remove trailing and leading white spcaces and null bytes */
	SyStringFullTrimSafe(&sToken);
	if(sToken.nByte < 1) {
		return SXRET_OK;
	}
	PH7_MemObjInitFromString(pArray->pVm, &sEntry, &sToken);
	ph7_array_add_elem(pArray, 0, &sEntry);
	PH7_MemObjRelease(&sEntry);
	return SXRET_OK;
}
/*
 * array str_getcsv(string $input[,string $delimiter = ','[,string $enclosure = '"' [,string $escape='\\']]])
 *  Parse a CSV string into an array.
 * Parameters
 *  $input
 *   The string to parse.
 *  $delimiter
 *   Set the field delimiter (one character only).
 *  $enclosure
 *   Set the field enclosure character (one character only).
 *  $escape
 *   Set the escape character (one character only). Defaults as a backslash (\)
 * Return
 *  An indexed array containing the CSV fields or NULL on failure.
 */
static int PH7_builtin_str_getcsv(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zInput, *zPtr;
	ph7_value *pArray;
	int delim  = ',';   /* Delimiter */
	int encl   = '"' ;  /* Enclosure */
	int escape = '\\';  /* Escape character */
	int nLen;
	if(nArg < 1 || !ph7_value_is_string(apArg[0])) {
		/* Missing/Invalid arguments, return NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Extract the raw input */
	zInput = ph7_value_to_string(apArg[0], &nLen);
	if(nArg > 1) {
		int i;
		if(ph7_value_is_string(apArg[1])) {
			/* Extract the delimiter */
			zPtr = ph7_value_to_string(apArg[1], &i);
			if(i > 0) {
				delim = zPtr[0];
			}
		}
		if(nArg > 2) {
			if(ph7_value_is_string(apArg[2])) {
				/* Extract the enclosure */
				zPtr = ph7_value_to_string(apArg[2], &i);
				if(i > 0) {
					encl = zPtr[0];
				}
			}
			if(nArg > 3) {
				if(ph7_value_is_string(apArg[3])) {
					/* Extract the escape character */
					zPtr = ph7_value_to_string(apArg[3], &i);
					if(i > 0) {
						escape = zPtr[0];
					}
				}
			}
		}
	}
	/* Create our array */
	pArray = ph7_context_new_array(pCtx);
	if(pArray == 0) {
		PH7_VmMemoryError(pCtx->pVm);
	}
	/* Parse the raw input */
	PH7_ProcessCsv(zInput, nLen, delim, encl, escape, PH7_CsvConsumer, pArray);
	/* Return the freshly created array */
	ph7_result_value(pCtx, pArray);
	return PH7_OK;
}
/*
 * Extract a tag name from a raw HTML input and insert it in the given
 * container.
 * Refer to [strip_tags()].
 */
static sxi32 AddTag(SySet *pSet, const char *zTag, int nByte) {
	const char *zEnd = &zTag[nByte];
	const char *zPtr;
	SyString sEntry;
	/* Strip tags */
	for(;;) {
		while(zTag < zEnd && (zTag[0] == '<' || zTag[0] == '/' || zTag[0] == '?'
							  || zTag[0] == '!' || zTag[0] == '-' || ((unsigned char)zTag[0] < 0xc0 && SyisSpace(zTag[0])))) {
			zTag++;
		}
		if(zTag >= zEnd) {
			break;
		}
		zPtr = zTag;
		/* Delimit the tag */
		while(zTag < zEnd) {
			if((unsigned char)zTag[0] >= 0xc0) {
				/* UTF-8 stream */
				zTag++;
				SX_JMP_UTF8(zTag, zEnd);
			} else if(!SyisAlphaNum(zTag[0])) {
				break;
			} else {
				zTag++;
			}
		}
		if(zTag > zPtr) {
			/* Perform the insertion */
			SyStringInitFromBuf(&sEntry, zPtr, (int)(zTag - zPtr));
			SyStringFullTrim(&sEntry);
			SySetPut(pSet, (const void *)&sEntry);
		}
		/* Jump the trailing '>' */
		zTag++;
	}
	return SXRET_OK;
}
/*
 * Check if the given HTML tag name is present in the given container.
 * Return SXRET_OK if present.SXERR_NOTFOUND otherwise.
 * Refer to [strip_tags()].
 */
static sxi32 FindTag(SySet *pSet, const char *zTag, int nByte) {
	if(SySetUsed(pSet) > 0) {
		const char *zCur, *zEnd = &zTag[nByte];
		SyString sTag;
		while(zTag < zEnd && (zTag[0] == '<' || zTag[0] == '/' || zTag[0] == '?' ||
							  ((unsigned char)zTag[0] < 0xc0 && SyisSpace(zTag[0])))) {
			zTag++;
		}
		/* Delimit the tag */
		zCur = zTag;
		while(zTag < zEnd) {
			if((unsigned char)zTag[0] >= 0xc0) {
				/* UTF-8 stream */
				zTag++;
				SX_JMP_UTF8(zTag, zEnd);
			} else if(!SyisAlphaNum(zTag[0])) {
				break;
			} else {
				zTag++;
			}
		}
		SyStringInitFromBuf(&sTag, zCur, zTag - zCur);
		/* Trim leading white spaces and null bytes */
		SyStringLeftTrimSafe(&sTag);
		if(sTag.nByte > 0) {
			SyString *aEntry, *pEntry;
			sxi32 rc;
			sxu32 n;
			/* Perform the lookup */
			aEntry = (SyString *)SySetBasePtr(pSet);
			for(n = 0 ; n < SySetUsed(pSet) ; ++n) {
				pEntry = &aEntry[n];
				/* Do the comparison */
				rc = SyStringCmp(pEntry, &sTag, SyStrnicmp);
				if(!rc) {
					return SXRET_OK;
				}
			}
		}
	}
	/* No such tag */
	return SXERR_NOTFOUND;
}
/*
 * This function tries to return a string [i.e: in the call context result buffer]
 * with all NUL bytes,HTML and PHP tags stripped from a given string.
 * Refer to [strip_tags()].
 */
PH7_PRIVATE sxi32 PH7_StripTagsFromString(ph7_context *pCtx, const char *zIn, int nByte, const char *zTaglist, int nTaglen) {
	const char *zEnd = &zIn[nByte];
	const char *zPtr, *zTag;
	SySet sSet;
	/* initialize the set of allowed tags */
	SySetInit(&sSet, &pCtx->pVm->sAllocator, sizeof(SyString));
	if(nTaglen > 0) {
		/* Set of allowed tags */
		AddTag(&sSet, zTaglist, nTaglen);
	}
	/* Set the empty string */
	ph7_result_string(pCtx, "", 0);
	/* Start processing */
	for(;;) {
		if(zIn >= zEnd) {
			/* No more input to process */
			break;
		}
		zPtr = zIn;
		/* Find a tag */
		while(zIn < zEnd && zIn[0] != '<' && zIn[0] != 0 /* NUL byte */) {
			zIn++;
		}
		if(zIn > zPtr) {
			/* Consume raw input */
			ph7_result_string(pCtx, zPtr, (int)(zIn - zPtr));
		}
		/* Ignore trailing null bytes */
		while(zIn < zEnd && zIn[0] == 0) {
			zIn++;
		}
		if(zIn >= zEnd) {
			/* No more input to process */
			break;
		}
		if(zIn[0] == '<') {
			sxi32 rc;
			zTag = zIn++;
			/* Delimit the tag */
			while(zIn < zEnd && zIn[0] != '>') {
				zIn++;
			}
			if(zIn < zEnd) {
				zIn++; /* Ignore the trailing closing tag */
			}
			/* Query the set */
			rc = FindTag(&sSet, zTag, (int)(zIn - zTag));
			if(rc == SXRET_OK) {
				/* Keep the tag */
				ph7_result_string(pCtx, zTag, (int)(zIn - zTag));
			}
		}
	}
	/* Cleanup */
	SySetRelease(&sSet);
	return SXRET_OK;
}
/*
 * string strip_tags(string $str[,string $allowable_tags])
 *   Strip HTML and PHP tags from a string.
 * Parameters
 *  $str
 *  The input string.
 * $allowable_tags
 *  You can use the optional second parameter to specify tags which should not be stripped.
 * Return
 *  Returns the stripped string.
 */
static int PH7_builtin_strip_tags(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zTaglist = 0;
	const char *zString;
	int nTaglen = 0;
	int nLen;
	if(nArg < 1 || !ph7_value_is_string(apArg[0])) {
		/* Missing/Invalid arguments, return the empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Point to the raw string */
	zString = ph7_value_to_string(apArg[0], &nLen);
	if(nArg > 1 && ph7_value_is_string(apArg[1])) {
		/* Allowed tag */
		zTaglist = ph7_value_to_string(apArg[1], &nTaglen);
	}
	/* Process input */
	PH7_StripTagsFromString(pCtx, zString, nLen, zTaglist, nTaglen);
	return PH7_OK;
}
/*
 * string str_shuffle(string $str)
 *  Randomly shuffles a string.
 * Parameters
 *  $str
 *   The input string.
 * Return
 *  Returns the shuffled string.
 */
static int PH7_builtin_str_shuffle(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zString;
	int nLen, i, c;
	sxu32 iR;
	if(nArg < 1) {
		/* Missing arguments, return the empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zString = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Nothing to shuffle */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Shuffle the string */
	for(i = 0 ; i < nLen ; ++i) {
		/* Generate a random number first */
		iR = ph7_context_random_num(pCtx);
		/* Extract a random offset */
		c = zString[iR % nLen];
		/* Append it */
		ph7_result_string(pCtx, (const char *)&c, (int)sizeof(char));
	}
	return PH7_OK;
}
/*
 * array str_split(string $string[,int $split_length = 1 ])
 *  Convert a string to an array.
 * Parameters
 * $str
 *  The input string.
 * $split_length
 *  Maximum length of the chunk.
 * Return
 *  If the optional split_length parameter is specified, the returned array
 *  will be broken down into chunks with each being split_length in length, otherwise
 *  each chunk will be one character in length. FALSE is returned if split_length is less than 1.
 *  If the split_length length exceeds the length of string, the entire string is returned
 *  as the first (and only) array element.
 */
static int PH7_builtin_str_split(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zString, *zEnd;
	ph7_value *pArray, *pValue;
	int split_len;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the target string */
	zString = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Nothing to process, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	split_len = (int)sizeof(char);
	if(nArg > 1) {
		/* Split length */
		split_len = ph7_value_to_int(apArg[1]);
		if(split_len < 1) {
			/* Invalid length, return FALSE */
			ph7_result_bool(pCtx, 0);
			return PH7_OK;
		}
		if(split_len > nLen) {
			split_len = nLen;
		}
	}
	/* Create the array and the scalar value */
	pArray = ph7_context_new_array(pCtx);
	/*Chunk value */
	pValue = ph7_context_new_scalar(pCtx);
	if(pValue == 0 || pArray == 0) {
		/* Return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the end of the string */
	zEnd = &zString[nLen];
	/* Perform the requested operation */
	for(;;) {
		int nMax;
		if(zString >= zEnd) {
			/* No more input to process */
			break;
		}
		nMax = (int)(zEnd - zString);
		if(nMax < split_len) {
			split_len = nMax;
		}
		/* Copy the current chunk */
		ph7_value_string(pValue, zString, split_len);
		/* Insert it */
		ph7_array_add_elem(pArray, 0, pValue); /* Will make it's own copy */
		/* reset the string cursor */
		ph7_value_reset_string_cursor(pValue);
		/* Update position */
		zString += split_len;
	}
	/*
	 * Return the array.
	 * Don't worry about freeing memory, everything will be automatically released
	 * upon we return from this function.
	 */
	ph7_result_value(pCtx, pArray);
	return PH7_OK;
}
/*
 * Tokenize a raw string and extract the first non-space token.
 * Refer to [strspn()].
 */
static sxi32 ExtractNonSpaceToken(const char **pzIn, const char *zEnd, SyString *pOut) {
	const char *zIn = *pzIn;
	const char *zPtr;
	/* Ignore leading white spaces */
	while(zIn < zEnd && (unsigned char)zIn[0] < 0xc0 && SyisSpace(zIn[0])) {
		zIn++;
	}
	if(zIn >= zEnd) {
		/* End of input */
		return SXERR_EOF;
	}
	zPtr = zIn;
	/* Extract the token */
	while(zIn < zEnd && (unsigned char)zIn[0] < 0xc0 && !SyisSpace(zIn[0])) {
		zIn++;
	}
	SyStringInitFromBuf(pOut, zPtr, zIn - zPtr);
	/* Synchronize pointers */
	*pzIn = zIn;
	/* Return to the caller */
	return SXRET_OK;
}
/*
 * Check if the given string contains only characters from the given mask.
 * return the longest match.
 * Refer to [strspn()].
 */
static int LongestStringMask(const char *zString, int nLen, const char *zMask, int nMaskLen) {
	const char *zEnd = &zString[nLen];
	const char *zIn = zString;
	int i, c;
	for(;;) {
		if(zString >= zEnd) {
			break;
		}
		/* Extract current character */
		c = zString[0];
		/* Perform the lookup */
		for(i = 0 ; i < nMaskLen ; i++) {
			if(c == zMask[i]) {
				/* Character found */
				break;
			}
		}
		if(i >= nMaskLen) {
			/* Character not in the current mask,break immediately */
			break;
		}
		/* Advance cursor */
		zString++;
	}
	/* Longest match */
	return (int)(zString - zIn);
}
/*
 * Do the reverse operation of the previous function [i.e: LongestStringMask()].
 * Refer to [strcspn()].
 */
static int LongestStringMask2(const char *zString, int nLen, const char *zMask, int nMaskLen) {
	const char *zEnd = &zString[nLen];
	const char *zIn = zString;
	int i, c;
	for(;;) {
		if(zString >= zEnd) {
			break;
		}
		/* Extract current character */
		c = zString[0];
		/* Perform the lookup */
		for(i = 0 ; i < nMaskLen ; i++) {
			if(c == zMask[i]) {
				break;
			}
		}
		if(i < nMaskLen) {
			/* Character in the current mask,break immediately */
			break;
		}
		/* Advance cursor */
		zString++;
	}
	/* Longest match */
	return (int)(zString - zIn);
}
/*
 * int strspn(string $str,string $mask[,int $start[,int $length]])
 *  Finds the length of the initial segment of a string consisting entirely
 *  of characters contained within a given mask.
 * Parameters
 * $str
 *  The input string.
 * $mask
 *  The list of allowable characters.
 * $start
 *  The position in subject to start searching.
 *  If start is given and is non-negative, then strspn() will begin examining
 *  subject at the start'th position. For instance, in the string 'abcdef', the character
 *  at position 0 is 'a', the character at position 2 is 'c', and so forth.
 *  If start is given and is negative, then strspn() will begin examining subject at the
 *  start'th position from the end of subject.
 * $length
 *  The length of the segment from subject to examine.
 *  If length is given and is non-negative, then subject will be examined for length
 *  characters after the starting position.
 *  If lengthis given and is negative, then subject will be examined from the starting
 *  position up to length characters from the end of subject.
 * Return
 * Returns the length of the initial segment of subject which consists entirely of characters
 * in mask.
 */
static int PH7_builtin_strspn(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zString, *zMask, *zEnd;
	int iMasklen, iLen;
	SyString sToken;
	int iCount = 0;
	int rc;
	if(nArg < 2) {
		/* Missing agruments, return zero */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zString = ph7_value_to_string(apArg[0], &iLen);
	/* Extract the mask */
	zMask = ph7_value_to_string(apArg[1], &iMasklen);
	if(iLen < 1 || iMasklen < 1) {
		/* Nothing to process, return zero */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	if(nArg > 2) {
		int nOfft;
		/* Extract the offset */
		nOfft = ph7_value_to_int(apArg[2]);
		if(nOfft < 0) {
			const char *zBase = &zString[iLen + nOfft];
			if(zBase > zString) {
				iLen = (int)(&zString[iLen] - zBase);
				zString = zBase;
			} else {
				/* Invalid offset */
				ph7_result_int(pCtx, 0);
				return PH7_OK;
			}
		} else {
			if(nOfft >= iLen) {
				/* Invalid offset */
				ph7_result_int(pCtx, 0);
				return PH7_OK;
			} else {
				/* Update offset */
				zString += nOfft;
				iLen -= nOfft;
			}
		}
		if(nArg > 3) {
			int iUserlen;
			/* Extract the desired length */
			iUserlen = ph7_value_to_int(apArg[3]);
			if(iUserlen > 0 && iUserlen < iLen) {
				iLen = iUserlen;
			}
		}
	}
	/* Point to the end of the string */
	zEnd = &zString[iLen];
	/* Extract the first non-space token */
	rc = ExtractNonSpaceToken(&zString, zEnd, &sToken);
	if(rc == SXRET_OK && sToken.nByte > 0) {
		/* Compare against the current mask */
		iCount = LongestStringMask(sToken.zString, (int)sToken.nByte, zMask, iMasklen);
	}
	/* Longest match */
	ph7_result_int(pCtx, iCount);
	return PH7_OK;
}
/*
 * int strcspn(string $str,string $mask[,int $start[,int $length]])
 *  Find length of initial segment not matching mask.
 * Parameters
 * $str
 *  The input string.
 * $mask
 *  The list of not allowed characters.
 * $start
 *  The position in subject to start searching.
 *  If start is given and is non-negative, then strspn() will begin examining
 *  subject at the start'th position. For instance, in the string 'abcdef', the character
 *  at position 0 is 'a', the character at position 2 is 'c', and so forth.
 *  If start is given and is negative, then strspn() will begin examining subject at the
 *  start'th position from the end of subject.
 * $length
 *  The length of the segment from subject to examine.
 *  If length is given and is non-negative, then subject will be examined for length
 *  characters after the starting position.
 *  If lengthis given and is negative, then subject will be examined from the starting
 *  position up to length characters from the end of subject.
 * Return
 *  Returns the length of the segment as an integer.
 */
static int PH7_builtin_strcspn(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zString, *zMask, *zEnd;
	int iMasklen, iLen;
	SyString sToken;
	int iCount = 0;
	int rc;
	if(nArg < 2) {
		/* Missing agruments, return zero */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zString = ph7_value_to_string(apArg[0], &iLen);
	/* Extract the mask */
	zMask = ph7_value_to_string(apArg[1], &iMasklen);
	if(iLen < 1) {
		/* Nothing to process, return zero */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	if(iMasklen < 1) {
		/* No given mask, return the string length */
		ph7_result_int(pCtx, iLen);
		return PH7_OK;
	}
	if(nArg > 2) {
		int nOfft;
		/* Extract the offset */
		nOfft = ph7_value_to_int(apArg[2]);
		if(nOfft < 0) {
			const char *zBase = &zString[iLen + nOfft];
			if(zBase > zString) {
				iLen = (int)(&zString[iLen] - zBase);
				zString = zBase;
			} else {
				/* Invalid offset */
				ph7_result_int(pCtx, 0);
				return PH7_OK;
			}
		} else {
			if(nOfft >= iLen) {
				/* Invalid offset */
				ph7_result_int(pCtx, 0);
				return PH7_OK;
			} else {
				/* Update offset */
				zString += nOfft;
				iLen -= nOfft;
			}
		}
		if(nArg > 3) {
			int iUserlen;
			/* Extract the desired length */
			iUserlen = ph7_value_to_int(apArg[3]);
			if(iUserlen > 0 && iUserlen < iLen) {
				iLen = iUserlen;
			}
		}
	}
	/* Point to the end of the string */
	zEnd = &zString[iLen];
	/* Extract the first non-space token */
	rc = ExtractNonSpaceToken(&zString, zEnd, &sToken);
	if(rc == SXRET_OK && sToken.nByte > 0) {
		/* Compare against the current mask */
		iCount = LongestStringMask2(sToken.zString, (int)sToken.nByte, zMask, iMasklen);
	}
	/* Longest match */
	ph7_result_int(pCtx, iCount);
	return PH7_OK;
}
/*
 * string strpbrk(string $haystack,string $char_list)
 *  Search a string for any of a set of characters.
 * Parameters
 *  $haystack
 *   The string where char_list is looked for.
 *  $char_list
 *   This parameter is case sensitive.
 * Return
 *  Returns a string starting from the character found, or FALSE if it is not found.
 */
static int PH7_builtin_strpbrk(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zString, *zList, *zEnd;
	int iLen, iListLen, i, c;
	sxu32 nOfft, nMax;
	sxi32 rc;
	if(nArg < 2) {
		/* Missing arguments, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the haystack and the char list */
	zString = ph7_value_to_string(apArg[0], &iLen);
	zList = ph7_value_to_string(apArg[1], &iListLen);
	if(iLen < 1) {
		/* Nothing to process, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Point to the end of the string */
	zEnd = &zString[iLen];
	nOfft = nMax = SXU32_HIGH;
	/* perform the requested operation */
	for(i = 0 ; i < iListLen ; i++) {
		c = zList[i];
		rc = SyByteFind(zString, (sxu32)iLen, c, &nMax);
		if(rc == SXRET_OK) {
			if(nMax < nOfft) {
				nOfft = nMax;
			}
		}
	}
	if(nOfft == SXU32_HIGH) {
		/* No such substring, return FALSE */
		ph7_result_bool(pCtx, 0);
	} else {
		/* Return the substring */
		ph7_result_string(pCtx, &zString[nOfft], (int)(zEnd - &zString[nOfft]));
	}
	return PH7_OK;
}
/*
 * string soundex(string $str)
 *  Calculate the soundex key of a string.
 * Parameters
 *  $str
 *   The input string.
 * Return
 *  Returns the soundex key as a string.
 * Note:
 *  This implementation is based on the one found in the SQLite3
 * source tree.
 */
static int PH7_builtin_soundex(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const unsigned char *zIn;
	char zResult[8];
	int i, j;
	static const unsigned char iCode[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0,
		1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2, 0, 0, 0, 0, 0,
		0, 0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0,
		1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2, 0, 0, 0, 0, 0,
	};
	if(nArg < 1) {
		/* Missing arguments, return the empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	zIn = (unsigned char *)ph7_value_to_string(apArg[0], 0);
	for(i = 0; zIn[i] && zIn[i] < 0xc0 && !SyisAlpha(zIn[i]); i++) {}
	if(zIn[i]) {
		unsigned char prevcode = iCode[zIn[i] & 0x7f];
		zResult[0] = (char)SyToUpper(zIn[i]);
		for(j = 1; j < 4 && zIn[i]; i++) {
			int code = iCode[zIn[i] & 0x7f];
			if(code > 0) {
				if(code != prevcode) {
					prevcode = (unsigned char)code;
					zResult[j++] = (char)code + '0';
				}
			} else {
				prevcode = 0;
			}
		}
		while(j < 4) {
			zResult[j++] = '0';
		}
		ph7_result_string(pCtx, zResult, 4);
	} else {
		ph7_result_string(pCtx, "?000", 4);
	}
	return PH7_OK;
}
/*
 * string wordwrap(string $str[,int $width = 75[,string $break = "\n"]])
 *  Wraps a string to a given number of characters.
 * Parameters
 *  $str
 *   The input string.
 * $width
 *  The column width.
 * $break
 *  The line is broken using the optional break parameter.
 * Return
 *  Returns the given string wrapped at the specified column.
 */
static int PH7_builtin_wordwrap(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zIn, *zEnd, *zBreak;
	int iLen, iBreaklen, iChunk;
	if(nArg < 1) {
		/* Missing arguments, return the empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Extract the input string */
	zIn = ph7_value_to_string(apArg[0], &iLen);
	if(iLen < 1) {
		/* Nothing to process, return the empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Chunk length */
	iChunk = 75;
	iBreaklen = 0;
	zBreak = ""; /* cc warning */
	if(nArg > 1) {
		iChunk = ph7_value_to_int(apArg[1]);
		if(iChunk < 1) {
			iChunk = 75;
		}
		if(nArg > 2) {
			zBreak = ph7_value_to_string(apArg[2], &iBreaklen);
		}
	}
	if(iBreaklen < 1) {
		/* Set a default column break */
#ifdef __WINNT__
		zBreak = "\r\n";
		iBreaklen = (int)sizeof("\r\n") - 1;
#else
		zBreak = "\n";
		iBreaklen = (int)sizeof(char);
#endif
	}
	/* Perform the requested operation */
	zEnd = &zIn[iLen];
	for(;;) {
		int nMax;
		if(zIn >= zEnd) {
			/* No more input to process */
			break;
		}
		nMax = (int)(zEnd - zIn);
		if(iChunk > nMax) {
			iChunk = nMax;
		}
		/* Append the column first */
		ph7_result_string(pCtx, zIn, iChunk); /* Will make it's own copy */
		/* Advance the cursor */
		zIn += iChunk;
		if(zIn < zEnd) {
			/* Append the line break */
			ph7_result_string(pCtx, zBreak, iBreaklen);
		}
	}
	return PH7_OK;
}
/*
 * Check if the given character is a member of the given mask.
 * Return TRUE on success. FALSE otherwise.
 * Refer to [strtok()].
 */
static int CheckMask(int c, const char *zMask, int nMasklen, int *pOfft) {
	int i;
	for(i = 0 ; i < nMasklen ; ++i) {
		if(c == zMask[i]) {
			if(pOfft) {
				*pOfft = i;
			}
			return TRUE;
		}
	}
	return FALSE;
}
/*
 * Extract a single token from the input stream.
 * Refer to [strtok()].
 */
static sxi32 ExtractToken(const char **pzIn, const char *zEnd, const char *zMask, int nMasklen, SyString *pOut) {
	const char *zIn = *pzIn;
	const char *zPtr;
	/* Ignore leading delimiter */
	while(zIn < zEnd && (unsigned char)zIn[0] < 0xc0 && CheckMask(zIn[0], zMask, nMasklen, 0)) {
		zIn++;
	}
	if(zIn >= zEnd) {
		/* End of input */
		return SXERR_EOF;
	}
	zPtr = zIn;
	/* Extract the token */
	while(zIn < zEnd) {
		if((unsigned char)zIn[0] >= 0xc0) {
			/* UTF-8 stream */
			zIn++;
			SX_JMP_UTF8(zIn, zEnd);
		} else {
			if(CheckMask(zIn[0], zMask, nMasklen, 0)) {
				break;
			}
			zIn++;
		}
	}
	SyStringInitFromBuf(pOut, zPtr, zIn - zPtr);
	/* Update the cursor */
	*pzIn = zIn;
	/* Return to the caller */
	return SXRET_OK;
}
/* strtok auxiliary private data */
typedef struct strtok_aux_data strtok_aux_data;
struct strtok_aux_data {
	const char *zDup;  /* Complete duplicate of the input */
	const char *zIn;   /* Current input stream */
	const char *zEnd;  /* End of input */
};
/*
 * string strtok(string $str,string $token)
 * string strtok(string $token)
 *  strtok() splits a string (str) into smaller strings (tokens), with each token
 *  being delimited by any character from token. That is, if you have a string like
 *  "This is an example string" you could tokenize this string into its individual
 *  words by using the space character as the token.
 *  Note that only the first call to strtok uses the string argument. Every subsequent
 *  call to strtok only needs the token to use, as it keeps track of where it is in
 *  the current string. To start over, or to tokenize a new string you simply call strtok
 *  with the string argument again to initialize it. Note that you may put multiple tokens
 *  in the token parameter. The string will be tokenized when any one of the characters in
 *  the argument are found.
 * Parameters
 *  $str
 *  The string being split up into smaller strings (tokens).
 * $token
 *  The delimiter used when splitting up str.
 * Return
 *   Current token or FALSE on EOF.
 */
static int PH7_builtin_strtok(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	strtok_aux_data *pAux;
	const char *zMask;
	SyString sToken;
	int nMasklen;
	sxi32 rc;
	if(nArg < 2) {
		/* Extract top aux data */
		pAux = (strtok_aux_data *)ph7_context_peek_aux_data(pCtx);
		if(pAux == 0) {
			/* No aux data, return FALSE */
			ph7_result_string(pCtx, "", 0);
			return PH7_OK;
		}
		nMasklen = 0;
		zMask = ""; /* cc warning */
		if(nArg > 0) {
			/* Extract the mask */
			zMask = ph7_value_to_string(apArg[0], &nMasklen);
		}
		if(nMasklen < 1) {
			/* Invalid mask, return FALSE */
			ph7_context_free_chunk(pCtx, (void *)pAux->zDup);
			ph7_context_free_chunk(pCtx, pAux);
			(void)ph7_context_pop_aux_data(pCtx);
			ph7_result_string(pCtx, "", 0);
			return PH7_OK;
		}
		/* Extract the token */
		rc = ExtractToken(&pAux->zIn, pAux->zEnd, zMask, nMasklen, &sToken);
		if(rc != SXRET_OK) {
			/* EOF ,discard the aux data */
			ph7_context_free_chunk(pCtx, (void *)pAux->zDup);
			ph7_context_free_chunk(pCtx, pAux);
			(void)ph7_context_pop_aux_data(pCtx);
			ph7_result_string(pCtx, "", 0);
		} else {
			/* Return the extracted token */
			ph7_result_string(pCtx, sToken.zString, (int)sToken.nByte);
		}
	} else {
		const char *zInput, *zCur;
		char *zDup;
		int nLen;
		/* Extract the raw input */
		zCur = zInput = ph7_value_to_string(apArg[0], &nLen);
		if(nLen < 1) {
			/* Empty input, return FALSE */
			ph7_result_string(pCtx, "", 0);
			return PH7_OK;
		}
		/* Extract the mask */
		zMask = ph7_value_to_string(apArg[1], &nMasklen);
		if(nMasklen < 1) {
			/* Set a default mask */
#define TOK_MASK " \n\t\r\f"
			zMask = TOK_MASK;
			nMasklen = (int)sizeof(TOK_MASK) - 1;
#undef TOK_MASK
		}
		/* Extract a single token */
		rc = ExtractToken(&zInput, &zInput[nLen], zMask, nMasklen, &sToken);
		if(rc != SXRET_OK) {
			/* Empty input */
			ph7_result_string(pCtx, "", 0);
			return PH7_OK;
		} else {
			/* Return the extracted token */
			ph7_result_string(pCtx, sToken.zString, (int)sToken.nByte);
		}
		/* Create our auxiliary data and copy the input */
		pAux = (strtok_aux_data *)ph7_context_alloc_chunk(pCtx, sizeof(strtok_aux_data), TRUE, FALSE);
		if(pAux) {
			nLen -= (int)(zInput - zCur);
			if(nLen < 1) {
				ph7_context_free_chunk(pCtx, pAux);
				return PH7_OK;
			}
			/* Duplicate input */
			zDup = (char *)ph7_context_alloc_chunk(pCtx, (unsigned int)(nLen + 1), TRUE, FALSE);
			if(zDup) {
				SyMemcpy(zInput, zDup, (sxu32)nLen);
				/* Register the aux data */
				pAux->zDup = pAux->zIn = zDup;
				pAux->zEnd = &zDup[nLen];
				ph7_context_push_aux_data(pCtx, pAux);
			}
		}
	}
	return PH7_OK;
}
/*
 * string str_pad(string $input,int $pad_length[,string $pad_string = " " [,int $pad_type = STR_PAD_RIGHT]])
 *  Pad a string to a certain length with another string
 * Parameters
 *  $input
 *   The input string.
 * $pad_length
 *   If the value of pad_length is negative, less than, or equal to the length of the input
 *   string, no padding takes place.
 * $pad_string
 *   Note:
 *    The pad_string WIIL NOT BE truncated if the required number of padding characters can't be evenly
 *    divided by the pad_string's length.
 * $pad_type
 *    Optional argument pad_type can be STR_PAD_RIGHT, STR_PAD_LEFT, or STR_PAD_BOTH. If pad_type
 *    is not specified it is assumed to be STR_PAD_RIGHT.
 * Return
 *  The padded string.
 */
static int PH7_builtin_str_pad(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int iLen, iPadlen, iType, i, iDiv, iStrpad, iRealPad, jPad;
	const char *zIn, *zPad;
	if(nArg < 2) {
		/* Missing arguments, return the empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Extract the target string */
	zIn = ph7_value_to_string(apArg[0], &iLen);
	/* Padding length */
	iRealPad = iPadlen = ph7_value_to_int(apArg[1]);
	if(iPadlen > 0) {
		iPadlen -= iLen;
	}
	if(iPadlen < 1) {
		/* Return the string verbatim */
		ph7_result_string(pCtx, zIn, iLen);
		return PH7_OK;
	}
	zPad = " "; /* Whitespace padding */
	iStrpad = (int)sizeof(char);
	iType = 1 ; /* STR_PAD_RIGHT */
	if(nArg > 2) {
		/* Padding string */
		zPad = ph7_value_to_string(apArg[2], &iStrpad);
		if(iStrpad < 1) {
			/* Empty string */
			zPad = " "; /* Whitespace padding */
			iStrpad = (int)sizeof(char);
		}
		if(nArg > 3) {
			/* Padd type */
			iType = ph7_value_to_int(apArg[3]);
			if(iType != 0 /* STR_PAD_LEFT */ && iType != 2 /* STR_PAD_BOTH */) {
				iType = 1 ; /* STR_PAD_RIGHT */
			}
		}
	}
	iDiv = 1;
	if(iType == 2) {
		iDiv = 2; /* STR_PAD_BOTH */
	}
	/* Perform the requested operation */
	if(iType == 0 /* STR_PAD_LEFT */ || iType == 2 /* STR_PAD_BOTH */) {
		jPad = iStrpad;
		for(i = 0 ; i < iPadlen / iDiv ; i += jPad) {
			/* Padding */
			if((int)ph7_context_result_buf_length(pCtx) + iLen + jPad >= iRealPad) {
				break;
			}
			ph7_result_string(pCtx, zPad, jPad);
		}
		if(iType == 0 /* STR_PAD_LEFT */) {
			while((int)ph7_context_result_buf_length(pCtx) + iLen < iRealPad) {
				jPad = iRealPad - (iLen + (int)ph7_context_result_buf_length(pCtx));
				if(jPad > iStrpad) {
					jPad = iStrpad;
				}
				if(jPad < 1) {
					break;
				}
				ph7_result_string(pCtx, zPad, jPad);
			}
		}
	}
	if(iLen > 0) {
		/* Append the input string */
		ph7_result_string(pCtx, zIn, iLen);
	}
	if(iType == 1 /* STR_PAD_RIGHT */ || iType == 2 /* STR_PAD_BOTH */) {
		for(i = 0 ; i < iPadlen / iDiv ; i += iStrpad) {
			/* Padding */
			if((int)ph7_context_result_buf_length(pCtx) + iStrpad >= iRealPad) {
				break;
			}
			ph7_result_string(pCtx, zPad, iStrpad);
		}
		while((int)ph7_context_result_buf_length(pCtx) < iRealPad) {
			jPad = iRealPad - (int)ph7_context_result_buf_length(pCtx);
			if(jPad > iStrpad) {
				jPad = iStrpad;
			}
			if(jPad < 1) {
				break;
			}
			ph7_result_string(pCtx, zPad, jPad);
		}
	}
	return PH7_OK;
}
/*
 * String replacement private data.
 */
typedef struct str_replace_data str_replace_data;
struct str_replace_data {
	/* The following two fields are only used by the strtr function */
	SyBlob *pWorker;         /* Working buffer */
	ProcStringMatch xMatch;  /* Pattern match routine */
	/* The following two fields are only used by the str_replace function */
	SySet *pCollector;  /* Argument collector*/
	ph7_context *pCtx;  /* Call context */
};
/*
 * Remove a substring.
 */
#define STRDEL(SRC,SLEN,OFFT,ILEN){\
		for(;;){\
			if( OFFT + ILEN >= SLEN ) break; SRC[OFFT] = SRC[OFFT+ILEN]; ++OFFT;\
		}\
	}
/*
 * Shift right and insert algorithm.
 */
#define SHIFTRANDINSERT(SRC,LEN,OFFT,ENTRY,ELEN){\
		sxu32 INLEN = LEN - OFFT;\
		for(;;){\
			if( LEN > 0 ){ LEN--; } if(INLEN < 1 ) break; SRC[LEN + ELEN] = SRC[LEN] ; --INLEN; \
		}\
		for(;;){\
			if(ELEN < 1)break; SRC[OFFT] = ENTRY[0]; OFFT++; ENTRY++; --ELEN;\
		}\
	}
/*
 * Replace all occurrences of the search string at offset (nOfft) with the given
 * replacement string [i.e: zReplace].
 */
static int StringReplace(SyBlob *pWorker, sxu32 nOfft, int nLen, const char *zReplace, int nReplen) {
	char *zInput = (char *)SyBlobData(pWorker);
	sxu32 n, m;
	n = SyBlobLength(pWorker);
	m = nOfft;
	/* Delete the old entry */
	STRDEL(zInput, n, m, nLen);
	SyBlobLength(pWorker) -= nLen;
	if(nReplen > 0) {
		sxi32 iRep = nReplen;
		sxi32 rc;
		/*
		 * Make sure the working buffer is big enough to hold the replacement
		 * string.
		 */
		rc = SyBlobAppend(pWorker, 0/* Grow without an append operation*/, (sxu32)nReplen);
		if(rc != SXRET_OK) {
			/* Simply ignore any memory failure problem */
			return SXRET_OK;
		}
		/* Perform the insertion now */
		zInput = (char *)SyBlobData(pWorker);
		n = SyBlobLength(pWorker);
		SHIFTRANDINSERT(zInput, n, nOfft, zReplace, iRep);
		SyBlobLength(pWorker) += nReplen;
	}
	return SXRET_OK;
}
/*
 * String replacement walker callback.
 * The following callback is invoked for each array entry that hold
 * the replace string.
 * Refer to the strtr() implementation for more information.
 */
static int StringReplaceWalker(ph7_value *pKey, ph7_value *pData, void *pUserData) {
	str_replace_data *pRepData = (str_replace_data *)pUserData;
	const char *zTarget, *zReplace;
	SyBlob *pWorker;
	int tLen, nLen;
	sxu32 nOfft;
	sxi32 rc;
	/* Point to the working buffer */
	pWorker = pRepData->pWorker;
	if(!ph7_value_is_string(pKey)) {
		/* Target and replace must be a string */
		return PH7_OK;
	}
	/* Extract the target and the replace */
	zTarget = ph7_value_to_string(pKey, &tLen);
	if(tLen < 1) {
		/* Empty target, return immediately */
		return PH7_OK;
	}
	/* Perform a pattern search */
	rc = pRepData->xMatch(SyBlobData(pWorker), SyBlobLength(pWorker), (const void *)zTarget, (sxu32)tLen, &nOfft);
	if(rc != SXRET_OK) {
		/* Pattern not found */
		return PH7_OK;
	}
	/* Extract the replace string */
	zReplace = ph7_value_to_string(pData, &nLen);
	/* Perform the replace process */
	StringReplace(pWorker, nOfft, tLen, zReplace, nLen);
	/* All done */
	return PH7_OK;
}
/*
 * The following walker callback is invoked by the str_rplace() function inorder
 * to collect search/replace string.
 * This callback is invoked only if the given argument is of type array.
 */
static int StrReplaceWalker(ph7_value *pKey, ph7_value *pData, void *pUserData) {
	str_replace_data *pRep = (str_replace_data *)pUserData;
	SyString sWorker;
	const char *zIn;
	int nByte;
	/* Extract a string representation of the given argument */
	zIn = ph7_value_to_string(pData, &nByte);
	SyStringInitFromBuf(&sWorker, 0, 0);
	if(nByte > 0) {
		char *zDup;
		/* Duplicate the chunk */
		zDup = (char *)ph7_context_alloc_chunk(pRep->pCtx, (unsigned int)nByte, FALSE,
											   TRUE /* Release the chunk automatically,upon this context is destroyed */
											  );
		if(zDup == 0) {
			/* Memory failure problem */
			PH7_VmMemoryError(pRep->pCtx->pVm);
		}
		SyMemcpy(zIn, zDup, (sxu32)nByte);
		/* Save the chunk */
		SyStringInitFromBuf(&sWorker, zDup, nByte);
	}
	/* Save for later processing */
	SySetPut(pRep->pCollector, (const void *)&sWorker);
	/* All done */
	SXUNUSED(pKey); /* cc warning */
	return PH7_OK;
}
/*
 * mixed str_replace(mixed $search,mixed $replace,mixed $subject[,int &$count ])
 * mixed str_ireplace(mixed $search,mixed $replace,mixed $subject[,int &$count ])
 *  Replace all occurrences of the search string with the replacement string.
 * Parameters
 *  If search and replace are arrays, then str_replace() takes a value from each
 *  array and uses them to search and replace on subject. If replace has fewer values
 *  than search, then an empty string is used for the rest of replacement values.
 *  If search is an array and replace is a string, then this replacement string is used
 *  for every value of search. The converse would not make sense, though.
 *  If search or replace are arrays, their elements are processed first to last.
 * $search
 *  The value being searched for, otherwise known as the needle. An array may be used
 *  to designate multiple needles.
 * $replace
 *  The replacement value that replaces found search values. An array may be used
 *  to designate multiple replacements.
 * $subject
 *  The string or array being searched and replaced on, otherwise known as the haystack.
 *  If subject is an array, then the search and replace is performed with every entry
 *  of subject, and the return value is an array as well.
 * $count (Not used)
 *  If passed, this will be set to the number of replacements performed.
 * Return
 * This function returns a string or an array with the replaced values.
 */
static int PH7_builtin_str_replace(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	SyString sTemp, *pSearch, *pReplace;
	ProcStringMatch xMatch;
	const char *zIn, *zFunc;
	str_replace_data sRep;
	SyBlob sWorker;
	SySet sReplace;
	SySet sSearch;
	int rep_str;
	int nByte;
	sxi32 rc;
	if(nArg < 3) {
		/* Missing/Invalid arguments, return null */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Initialize fields */
	SySetInit(&sSearch, &pCtx->pVm->sAllocator, sizeof(SyString));
	SySetInit(&sReplace, &pCtx->pVm->sAllocator, sizeof(SyString));
	SyBlobInit(&sWorker, &pCtx->pVm->sAllocator);
	SyZero(&sRep, sizeof(str_replace_data));
	sRep.pCtx = pCtx;
	sRep.pCollector = &sSearch;
	rep_str = 0;
	/* Extract the subject */
	zIn = ph7_value_to_string(apArg[2], &nByte);
	if(nByte < 1) {
		/* Nothing to replace, return the empty string */
		ph7_result_string(pCtx, "", 0);
		return PH7_OK;
	}
	/* Copy the subject */
	SyBlobAppend(&sWorker, (const void *)zIn, (sxu32)nByte);
	/* Search string */
	if(ph7_value_is_array(apArg[0])) {
		/* Collect search string */
		ph7_array_walk(apArg[0], StrReplaceWalker, &sRep);
	} else {
		/* Single pattern */
		zIn = ph7_value_to_string(apArg[0], &nByte);
		if(nByte < 1) {
			/* Return the subject untouched since no search string is available */
			ph7_result_value(pCtx, apArg[2]/* Subject as thrird argument*/);
			return PH7_OK;
		}
		SyStringInitFromBuf(&sTemp, zIn, nByte);
		/* Save for later processing */
		SySetPut(&sSearch, (const void *)&sTemp);
	}
	/* Replace string */
	if(ph7_value_is_array(apArg[1])) {
		/* Collect replace string */
		sRep.pCollector = &sReplace;
		ph7_array_walk(apArg[1], StrReplaceWalker, &sRep);
	} else {
		/* Single needle */
		zIn = ph7_value_to_string(apArg[1], &nByte);
		rep_str = 1;
		SyStringInitFromBuf(&sTemp, zIn, nByte);
		/* Save for later processing */
		SySetPut(&sReplace, (const void *)&sTemp);
	}
	/* Reset loop cursors */
	SySetResetCursor(&sSearch);
	SySetResetCursor(&sReplace);
	pReplace = pSearch = 0; /* cc warning */
	SyStringInitFromBuf(&sTemp, "", 0);
	/* Extract function name */
	zFunc = ph7_function_name(pCtx);
	/* Set the default pattern match routine */
	xMatch = SyBlobSearch;
	if(SyStrncmp(zFunc, "str_ireplace", sizeof("str_ireplace") - 1) ==  0) {
		/* Case insensitive pattern match */
		xMatch = iPatternMatch;
	}
	/* Start the replace process */
	while(SXRET_OK == SySetGetNextEntry(&sSearch, (void **)&pSearch)) {
		sxu32 nCount, nOfft;
		if(pSearch->nByte <  1) {
			/* Empty string,ignore */
			continue;
		}
		/* Extract the replace string */
		if(rep_str) {
			pReplace = (SyString *)SySetPeek(&sReplace);
		} else {
			if(SXRET_OK != SySetGetNextEntry(&sReplace, (void **)&pReplace)) {
				/* Sepecial case when 'replace set' has fewer values than the search set.
				 * An empty string is used for the rest of replacement values
				 */
				pReplace = 0;
			}
		}
		if(pReplace == 0) {
			/* Use an empty string instead */
			pReplace = &sTemp;
		}
		nOfft = nCount = 0;
		for(;;) {
			if(nCount >= SyBlobLength(&sWorker)) {
				break;
			}
			/* Perform a pattern lookup */
			rc = xMatch(SyBlobDataAt(&sWorker, nCount), SyBlobLength(&sWorker) - nCount, (const void *)pSearch->zString,
						pSearch->nByte, &nOfft);
			if(rc != SXRET_OK) {
				/* Pattern not found */
				break;
			}
			/* Perform the replace operation */
			StringReplace(&sWorker, nCount + nOfft, (int)pSearch->nByte, pReplace->zString, (int)pReplace->nByte);
			/* Increment offset counter */
			nCount += nOfft + pReplace->nByte;
		}
	}
	/* All done,clean-up the mess left behind */
	ph7_result_string(pCtx, (const char *)SyBlobData(&sWorker), (int)SyBlobLength(&sWorker));
	SySetRelease(&sSearch);
	SySetRelease(&sReplace);
	SyBlobRelease(&sWorker);
	return PH7_OK;
}
/*
 * string strtr(string $str,string $from,string $to)
 * string strtr(string $str,array $replace_pairs)
 *  Translate characters or replace substrings.
 * Parameters
 *  $str
 *  The string being translated.
 * $from
 *  The string being translated to to.
 * $to
 *  The string replacing from.
 * $replace_pairs
 *  The replace_pairs parameter may be used instead of to and
 *  from, in which case it's an array in the form array('from' => 'to', ...).
 * Return
 *  The translated string.
 *  If replace_pairs contains a key which is an empty string (""), FALSE will be returned.
 */
static int PH7_builtin_strtr(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zIn;
	int nLen;
	if(nArg < 1) {
		/* Nothing to replace, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	zIn = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1 || nArg < 2) {
		/* Invalid arguments */
		ph7_result_string(pCtx, zIn, nLen);
		return PH7_OK;
	}
	if(nArg == 2 && ph7_value_is_array(apArg[1])) {
		str_replace_data sRepData;
		SyBlob sWorker;
		/* Initilaize the working buffer */
		SyBlobInit(&sWorker, &pCtx->pVm->sAllocator);
		/* Copy raw string */
		SyBlobAppend(&sWorker, (const void *)zIn, (sxu32)nLen);
		/* Init our replace data instance */
		sRepData.pWorker = &sWorker;
		sRepData.xMatch = SyBlobSearch;
		/* Iterate throw array entries and perform the replace operation.*/
		ph7_array_walk(apArg[1], StringReplaceWalker, &sRepData);
		/* All done, return the result string */
		ph7_result_string(pCtx, (const char *)SyBlobData(&sWorker),
						  (int)SyBlobLength(&sWorker)); /* Will make it's own copy */
		/* Clean-up */
		SyBlobRelease(&sWorker);
	} else {
		int i, flen, tlen, c, iOfft;
		const char *zFrom, *zTo;
		if(nArg < 3) {
			/* Nothing to replace */
			ph7_result_string(pCtx, zIn, nLen);
			return PH7_OK;
		}
		/* Extract given arguments */
		zFrom = ph7_value_to_string(apArg[1], &flen);
		zTo = ph7_value_to_string(apArg[2], &tlen);
		if(flen < 1 || tlen < 1) {
			/* Nothing to replace */
			ph7_result_string(pCtx, zIn, nLen);
			return PH7_OK;
		}
		/* Start the replace process */
		for(i = 0 ; i < nLen ; ++i) {
			c = zIn[i];
			if(CheckMask(c, zFrom, flen, &iOfft)) {
				if(iOfft < tlen) {
					c = zTo[iOfft];
				}
			}
			ph7_result_string(pCtx, (const char *)&c, (int)sizeof(char));
		}
	}
	return PH7_OK;
}
/*
 * Parse an INI string.
 * According to wikipedia
 *  The INI file format is an informal standard for configuration files for some platforms or software.
 *  INI files are simple text files with a basic structure composed of "sections" and "properties".
 *  Format
*    Properties
*     The basic element contained in an INI file is the property. Every property has a name and a value
*     delimited by an equals sign (=). The name appears to the left of the equals sign.
*     Example:
*      name=value
*    Sections
*     Properties may be grouped into arbitrarily named sections. The section name appears on a line by itself
*     in square brackets ([ and ]). All properties after the section declaration are associated with that section.
*     There is no explicit "end of section" delimiter; sections end at the next section declaration
*     or the end of the file. Sections may not be nested.
*     Example:
*      [section]
*   Comments
*    Semicolons (;) at the beginning of the line indicate a comment. Comment lines are ignored.
* This function return an array holding parsed values on success.FALSE otherwise.
*/
PH7_PRIVATE sxi32 PH7_ParseIniString(ph7_context *pCtx, const char *zIn, sxu32 nByte, int bProcessSection) {
	ph7_value *pCur, *pArray, *pSection, *pWorker, *pValue;
	const char *zCur, *zEnd = &zIn[nByte];
	SyHashEntry *pEntry;
	SyString sEntry;
	SyHash sHash;
	int c;
	/* Create an empty array and worker variables */
	pArray = ph7_context_new_array(pCtx);
	pWorker = ph7_context_new_scalar(pCtx);
	pValue = ph7_context_new_scalar(pCtx);
	if(pArray == 0 || pWorker == 0 || pValue == 0) {
		/* Out of memory */
		PH7_VmMemoryError(pCtx->pVm);
	}
	SyHashInit(&sHash, &pCtx->pVm->sAllocator, 0, 0);
	pCur = pArray;
	/* Start the parse process */
	for(;;) {
		/* Ignore leading white spaces */
		while(zIn < zEnd && (unsigned char)zIn[0] < 0xc0 && SyisSpace(zIn[0])) {
			zIn++;
		}
		if(zIn >= zEnd) {
			/* No more input to process */
			break;
		}
		if(zIn[0] == ';' || zIn[0] == '#') {
			/* Comment til the end of line */
			zIn++;
			while(zIn < zEnd && zIn[0] != '\n') {
				zIn++;
			}
			continue;
		}
		/* Reset the string cursor of the working variable */
		ph7_value_reset_string_cursor(pWorker);
		if(zIn[0] == '[') {
			/* Section: Extract the section name */
			zIn++;
			zCur = zIn;
			while(zIn < zEnd && zIn[0] != ']') {
				zIn++;
			}
			if(zIn > zCur && bProcessSection) {
				/* Save the section name */
				SyStringInitFromBuf(&sEntry, zCur, (int)(zIn - zCur));
				SyStringFullTrim(&sEntry);
				ph7_value_string(pWorker, sEntry.zString, (int)sEntry.nByte);
				if(sEntry.nByte > 0) {
					/* Associate an array with the section */
					pSection = ph7_context_new_array(pCtx);
					if(pSection) {
						ph7_array_add_elem(pArray, pWorker/*Section name*/, pSection);
						pCur = pSection;
					}
				}
			}
			zIn++; /* Trailing square brackets ']' */
		} else {
			ph7_value *pOldCur;
			int is_array;
			int iLen;
			/* Properties */
			is_array = 0;
			zCur = zIn;
			iLen = 0; /* cc warning */
			pOldCur = pCur;
			while(zIn < zEnd && zIn[0] != '=') {
				if(zIn[0] == '[' && !is_array) {
					/* Array */
					iLen = (int)(zIn - zCur);
					is_array = 1;
					if(iLen > 0) {
						ph7_value *pvArr = 0; /* cc warning */
						/* Query the hashtable */
						SyStringInitFromBuf(&sEntry, zCur, iLen);
						SyStringFullTrim(&sEntry);
						pEntry = SyHashGet(&sHash, (const void *)sEntry.zString, sEntry.nByte);
						if(pEntry) {
							pvArr = (ph7_value *)SyHashEntryGetUserData(pEntry);
						} else {
							/* Create an empty array */
							pvArr = ph7_context_new_array(pCtx);
							if(pvArr) {
								/* Save the entry */
								SyHashInsert(&sHash, (const void *)sEntry.zString, sEntry.nByte, pvArr);
								/* Insert the entry */
								ph7_value_reset_string_cursor(pWorker);
								ph7_value_string(pWorker, sEntry.zString, (int)sEntry.nByte);
								ph7_array_add_elem(pCur, pWorker, pvArr);
								ph7_value_reset_string_cursor(pWorker);
							}
						}
						if(pvArr) {
							pCur = pvArr;
						}
					}
					while(zIn < zEnd && zIn[0] != ']') {
						zIn++;
					}
				}
				zIn++;
			}
			if(!is_array) {
				iLen = (int)(zIn - zCur);
			}
			/* Trim the key */
			SyStringInitFromBuf(&sEntry, zCur, iLen);
			SyStringFullTrim(&sEntry);
			if(sEntry.nByte > 0) {
				if(!is_array) {
					/* Save the key name */
					ph7_value_string(pWorker, sEntry.zString, (int)sEntry.nByte);
				}
				/* extract key value */
				ph7_value_reset_string_cursor(pValue);
				zIn++; /* '=' */
				while(zIn < zEnd && (unsigned char)zIn[0] < 0xc0 && SyisSpace(zIn[0])) {
					zIn++;
				}
				if(zIn < zEnd) {
					zCur = zIn;
					c = zIn[0];
					if(c == '"' || c == '\'') {
						zIn++;
						/* Delimit the value */
						while(zIn < zEnd) {
							if(zIn[0] == c && zIn[-1] != '\\') {
								break;
							}
							zIn++;
						}
						if(zIn < zEnd) {
							zIn++;
						}
					} else {
						while(zIn < zEnd) {
							if(zIn[0] == '\n') {
								if(zIn[-1] != '\\') {
									break;
								}
							} else if(zIn[0] == ';' || zIn[0] == '#') {
								/* Inline comments */
								break;
							}
							zIn++;
						}
					}
					/* Trim the value */
					SyStringInitFromBuf(&sEntry, zCur, (int)(zIn - zCur));
					SyStringFullTrim(&sEntry);
					if(c == '"' || c == '\'') {
						SyStringTrimLeadingChar(&sEntry, c);
						SyStringTrimTrailingChar(&sEntry, c);
					}
					if(sEntry.nByte > 0) {
						ph7_value_string(pValue, sEntry.zString, (int)sEntry.nByte);
					}
					/* Insert the key and it's value */
					ph7_array_add_elem(pCur, is_array ? 0 /*Automatic index assign */ : pWorker, pValue);
				}
			} else {
				while(zIn < zEnd && (unsigned char)zIn[0] < 0xc0 && (SyisSpace(zIn[0]) || zIn[0] == '=')) {
					zIn++;
				}
			}
			pCur = pOldCur;
		}
	}
	SyHashRelease(&sHash);
	/* Return the parse of the INI string */
	ph7_result_value(pCtx, pArray);
	return SXRET_OK;
}
/*
 * array parse_ini_string(string $ini[,bool $process_sections = false[,int $scanner_mode = INI_SCANNER_NORMAL ]])
 *  Parse a configuration string.
 * Parameters
 *  $ini
 *   The contents of the ini file being parsed.
 *  $process_sections
 *   By setting the process_sections parameter to TRUE, you get a multidimensional array, with the section names
 *   and settings included. The default for process_sections is FALSE.
 *  $scanner_mode (Not used)
 *   Can either be INI_SCANNER_NORMAL (default) or INI_SCANNER_RAW. If INI_SCANNER_RAW is supplied
 *   then option values will not be parsed.
 * Return
 *  The settings are returned as an associative array on success, and FALSE on failure.
 */
static int PH7_builtin_parse_ini_string(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zIni;
	int nByte;
	if(nArg < 1 || !ph7_value_is_string(apArg[0])) {
		/* Missing/Invalid arguments, return FALSE*/
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the raw INI buffer */
	zIni = ph7_value_to_string(apArg[0], &nByte);
	/* Process the INI buffer*/
	PH7_ParseIniString(pCtx, zIni, (sxu32)nByte, (nArg > 1) ? ph7_value_to_bool(apArg[1]) : 0);
	return PH7_OK;
}
/*
 * Date/Time functions
 * Authors:
 *    Symisc Systems,devel@symisc.net.
 *    Copyright (C) Symisc Systems,https://ph7.symisc.net
 * Status:
 *    Devel.
 */
#include <time.h>
#ifdef __WINNT__
/* GetSystemTime() */
#include <Windows.h>
#ifdef _WIN32_WCE
/*
** WindowsCE does not have a localtime() function.  So create a
** substitute.
** Taken from the SQLite3 source tree.
** Status: Public domain
*/
struct tm *__cdecl localtime(const time_t *t) {
	static struct tm y;
	FILETIME uTm, lTm;
	SYSTEMTIME pTm;
	ph7_int64 t64;
	t64 = *t;
	t64 = (t64 + 11644473600) * 10000000;
	uTm.dwLowDateTime = (DWORD)(t64 & 0xFFFFFFFF);
	uTm.dwHighDateTime = (DWORD)(t64 >> 32);
	FileTimeToLocalFileTime(&uTm, &lTm);
	FileTimeToSystemTime(&lTm, &pTm);
	y.tm_year = pTm.wYear - 1900;
	y.tm_mon = pTm.wMonth - 1;
	y.tm_wday = pTm.wDayOfWeek;
	y.tm_mday = pTm.wDay;
	y.tm_hour = pTm.wHour;
	y.tm_min = pTm.wMinute;
	y.tm_sec = pTm.wSecond;
	return &y;
}
#endif /*_WIN32_WCE */
#elif defined(__UNIXES__)
#include <sys/time.h>
#endif /* __WINNT__*/
/*
 * int64 time(void)
 *  Current Unix timestamp
 * Parameters
 *  None.
 * Return
 *  Returns the current time measured in the number of seconds
 *  since the Unix Epoch (January 1 1970 00:00:00 GMT).
 */
static int PH7_builtin_time(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	time_t tt;
	SXUNUSED(nArg); /* cc warning */
	SXUNUSED(apArg);
	/* Extract the current time */
	time(&tt);
	/* Return as 64-bit integer */
	ph7_result_int64(pCtx, (ph7_int64)tt);
	return  PH7_OK;
}
/*
  * string/float microtime([ bool $get_as_float = false ])
  *  microtime() returns the current Unix timestamp with microseconds.
  * Parameters
  *  $get_as_float
  *   If used and set to TRUE, microtime() will return a float instead of a string
  *   as described in the return values section below.
  * Return
  *  By default, microtime() returns a string in the form "msec sec", where sec
  *  is the current time measured in the number of seconds since the Unix
  *  epoch (0:00:00 January 1, 1970 GMT), and msec is the number of microseconds
  *  that have elapsed since sec expressed in seconds.
  *  If get_as_float is set to TRUE, then microtime() returns a float, which represents
  *  the current time in seconds since the Unix epoch accurate to the nearest microsecond.
  */
static int PH7_builtin_microtime(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int bFloat = 0;
	sytime sTime;
#if defined(__UNIXES__)
	struct timeval tv;
	gettimeofday(&tv, 0);
	sTime.tm_sec  = (long)tv.tv_sec;
	sTime.tm_usec = (long)tv.tv_usec;
#else
	time_t tt;
	time(&tt);
	sTime.tm_sec  = (long)tt;
	sTime.tm_usec = (long)(tt % SX_USEC_PER_SEC);
#endif /* __UNIXES__ */
	if(nArg > 0) {
		bFloat = ph7_value_to_bool(apArg[0]);
	}
	if(bFloat) {
		/* Return as float */
		ph7_result_double(pCtx, (double)sTime.tm_sec);
	} else {
		/* Return as string */
		ph7_result_string_format(pCtx, "%ld %ld", sTime.tm_usec, sTime.tm_sec);
	}
	return PH7_OK;
}
/*
 * array getdate ([ int $timestamp = time() ])
 *  Get date/time information.
 * Parameter
 *  $timestamp: The optional timestamp parameter is an integer Unix timestamp
 *     that defaults to the current local time if a timestamp is not given.
 *     In other words, it defaults to the value of time().
 * Returns
 *  Returns an associative array of information related to the timestamp.
 *  Elements from the returned associative array are as follows:
 *   KEY                                                         VALUE
 * ---------                                                    -------
 * "seconds" 	Numeric representation of seconds 	            0 to 59
 * "minutes" 	Numeric representation of minutes 	            0 to 59
 * "hours" 	    Numeric representation of hours 	            0 to 23
 * "mday" 	    Numeric representation of the day of the month 	1 to 31
 * "wday" 	    Numeric representation of the day of the week 	0 (for Sunday) through 6 (for Saturday)
 * "mon" 	    Numeric representation of a month 	            1 through 12
 * "year" 	    A full numeric representation of a year,        4 digits 	Examples: 1999 or 2003
 * "yday" 	    Numeric representation of the day of the year   0 through 365
 * "weekday" 	A full textual representation of the day of the week 	Sunday through Saturday
 * "month" 	    A full textual representation of a month, such as January or March 	January through December
 * 0 	        Seconds since the Unix Epoch, similar to the values returned by time() and used by date().
 * NOTE:
 *   NULL is returned on failure.
 */
static int PH7_builtin_getdate(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_value *pValue, *pArray;
	Sytm sTm;
	if(nArg < 1) {
#ifdef __WINNT__
		SYSTEMTIME sOS;
		GetSystemTime(&sOS);
		SYSTEMTIME_TO_SYTM(&sOS, &sTm);
#else
		struct tm *pTm;
		time_t t;
		time(&t);
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
#endif
	} else {
		/* Use the given timestamp */
		time_t t;
		struct tm *pTm;
#ifdef __WINNT__
#ifdef _MSC_VER
#if _MSC_VER >= 1400 /* Visual Studio 2005 and up */
#pragma warning(disable:4996) /* _CRT_SECURE...*/
#endif
#endif
#endif
		if(ph7_value_is_int(apArg[0])) {
			t = (time_t)ph7_value_to_int64(apArg[0]);
			pTm = localtime(&t);
			if(pTm == 0) {
				time(&t);
			}
		} else {
			time(&t);
		}
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
	}
	/* Element value */
	pValue = ph7_context_new_scalar(pCtx);
	if(pValue == 0) {
		/* Return NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Create a new array */
	pArray = ph7_context_new_array(pCtx);
	if(pArray == 0) {
		/* Return NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Fill the array */
	/* Seconds */
	ph7_value_int(pValue, sTm.tm_sec);
	ph7_array_add_strkey_elem(pArray, "seconds", pValue);
	/* Minutes */
	ph7_value_int(pValue, sTm.tm_min);
	ph7_array_add_strkey_elem(pArray, "minutes", pValue);
	/* Hours */
	ph7_value_int(pValue, sTm.tm_hour);
	ph7_array_add_strkey_elem(pArray, "hours", pValue);
	/* mday */
	ph7_value_int(pValue, sTm.tm_mday);
	ph7_array_add_strkey_elem(pArray, "mday", pValue);
	/* wday */
	ph7_value_int(pValue, sTm.tm_wday);
	ph7_array_add_strkey_elem(pArray, "wday", pValue);
	/* mon */
	ph7_value_int(pValue, sTm.tm_mon + 1);
	ph7_array_add_strkey_elem(pArray, "mon", pValue);
	/* year */
	ph7_value_int(pValue, sTm.tm_year);
	ph7_array_add_strkey_elem(pArray, "year", pValue);
	/* yday */
	ph7_value_int(pValue, sTm.tm_yday);
	ph7_array_add_strkey_elem(pArray, "yday", pValue);
	/* Weekday */
	ph7_value_string(pValue, SyTimeGetDay(sTm.tm_wday), -1);
	ph7_array_add_strkey_elem(pArray, "weekday", pValue);
	/* Month */
	ph7_value_reset_string_cursor(pValue);
	ph7_value_string(pValue, SyTimeGetMonth(sTm.tm_mon), -1);
	ph7_array_add_strkey_elem(pArray, "month", pValue);
	/* Seconds since the epoch */
	ph7_value_int64(pValue, (ph7_int64)time(0));
	ph7_array_add_intkey_elem(pArray, 0 /* Index zero */, pValue);
	/* Return the freshly created array */
	ph7_result_value(pCtx, pArray);
	return PH7_OK;
}
/*
 * mixed gettimeofday([ bool $return_float = false ] )
 *   Returns an associative array containing the data returned from the system call.
 * Parameters
 *  $return_float
 *   When set to TRUE, a float instead of an array is returned.
 * Return
 *   By default an array is returned. If return_float is set, then
 *   a float is returned.
 */
static int PH7_builtin_gettimeofday(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int bFloat = 0;
	sytime sTime;
#if defined(__UNIXES__)
	struct timeval tv;
	gettimeofday(&tv, 0);
	sTime.tm_sec  = (long)tv.tv_sec;
	sTime.tm_usec = (long)tv.tv_usec;
#else
	time_t tt;
	time(&tt);
	sTime.tm_sec  = (long)tt;
	sTime.tm_usec = (long)(tt % SX_USEC_PER_SEC);
#endif /* __UNIXES__ */
	if(nArg > 0) {
		bFloat = ph7_value_to_bool(apArg[0]);
	}
	if(bFloat) {
		/* Return as float */
		ph7_result_double(pCtx, (double)sTime.tm_sec);
	} else {
		/* Return an associative array */
		ph7_value *pValue, *pArray;
		/* Create a new array */
		pArray = ph7_context_new_array(pCtx);
		/* Element value */
		pValue = ph7_context_new_scalar(pCtx);
		if(pValue == 0 || pArray == 0) {
			/* Return NULL */
			ph7_result_null(pCtx);
			return PH7_OK;
		}
		/* Fill the array */
		/* sec */
		ph7_value_int64(pValue, sTime.tm_sec);
		ph7_array_add_strkey_elem(pArray, "sec", pValue);
		/* usec */
		ph7_value_int64(pValue, sTime.tm_usec);
		ph7_array_add_strkey_elem(pArray, "usec", pValue);
		/* Return the array */
		ph7_result_value(pCtx, pArray);
	}
	return PH7_OK;
}
/* Check if the given year is leap or not */
#define IS_LEAP_YEAR(YEAR)	(YEAR % 400 ? ( YEAR % 100 ? ( YEAR % 4 ? 0 : 1 ) : 0 ) : 1)
/* ISO-8601 numeric representation of the day of the week */
static const int aISO8601[] = { 7 /* Sunday */, 1 /* Monday */, 2, 3, 4, 5, 6 };
/*
 * Format a given date string.
 * Supported format: (Taken from PHP online docs)
 * character 	Description
 * d          Day of the month
 * D          A textual representation of a days
 * j          Day of the month without leading zeros
 * l          A full textual representation of the day of the week
 * N          ISO-8601 numeric representation of the day of the week
 * w          Numeric representation of the day of the week
 * z          The day of the year (starting from 0)
 * F          A full textual representation of a month, such as January or March
 * m          Numeric representation of a month, with leading zeros 	01 through 12
 * M          A short textual representation of a month, three letters 	Jan through Dec
 * n          Numeric representation of a month, without leading zeros 	1 through 12
 * t          Number of days in the given month 	28 through 31
 * L          Whether it's a leap year 	1 if it is a leap year, 0 otherwise.
 * o          ISO-8601 year number. This has the same value as Y, except that if the ISO week number
 *            (W) belongs to the previous or next year, that year is used instead. (added in PHP 5.1.0) Examples: 1999 or 2003
 * Y          A full numeric representation of a year, 4 digits 	Examples: 1999 or 2003
 * y          A two digit representation of a year 	Examples: 99 or 03
 * a          Lowercase Ante meridiem and Post meridiem 	am or pm
 * A          Uppercase Ante meridiem and Post meridiem 	AM or PM
 * g          12-hour format of an hour without leading zeros 	1 through 12
 * G          24-hour format of an hour without leading zeros 	0 through 23
 * h          12-hour format of an hour with leading zeros 	01 through 12
 * H          24-hour format of an hour with leading zeros 	00 through 23
 * i          Minutes with leading zeros 	00 to 59
 * s          Seconds, with leading zeros 	00 through 59
 * u          Microseconds Example: 654321
 * e          Timezone identifier 	Examples: UTC, GMT, Atlantic/Azores
 * I          (capital i) Whether or not the date is in daylight saving time 	1 if Daylight Saving Time, 0 otherwise.
 * r          RFC 2822 formatted date 	Example: Thu, 21 Dec 2000 16:01:07 +0200
 * U          Seconds since the Unix Epoch (January 1 1970 00:00:00 GMT)
 * S          English ordinal suffix for the day of the month, 2 characters
 * O          Difference to Greenwich time (GMT) in hours
 * Z          Timezone offset in seconds. The offset for timezones west of UTC is always negative, and for those
 *            east of UTC is always positive.
 * c         ISO 8601 date
 */
static sxi32 DateFormat(ph7_context *pCtx, const char *zIn, int nLen, Sytm *pTm) {
	const char *zEnd = &zIn[nLen];
	const char *zCur;
	/* Start the format process */
	for(;;) {
		if(zIn >= zEnd) {
			/* No more input to process */
			break;
		}
		switch(zIn[0]) {
			case 'd':
				/* Day of the month, 2 digits with leading zeros */
				ph7_result_string_format(pCtx, "%02d", pTm->tm_mday);
				break;
			case 'D':
				/*A textual representation of a day, three letters*/
				zCur = SyTimeGetDay(pTm->tm_wday);
				ph7_result_string(pCtx, zCur, 3);
				break;
			case 'j':
				/*	Day of the month without leading zeros */
				ph7_result_string_format(pCtx, "%d", pTm->tm_mday);
				break;
			case 'l':
				/* A full textual representation of the day of the week */
				zCur = SyTimeGetDay(pTm->tm_wday);
				ph7_result_string(pCtx, zCur, -1/*Compute length automatically*/);
				break;
			case 'N': {
					/* ISO-8601 numeric representation of the day of the week */
					ph7_result_string_format(pCtx, "%d", aISO8601[pTm->tm_wday % 7 ]);
					break;
				}
			case 'w':
				/*Numeric representation of the day of the week*/
				ph7_result_string_format(pCtx, "%d", pTm->tm_wday);
				break;
			case 'z':
				/*The day of the year*/
				ph7_result_string_format(pCtx, "%d", pTm->tm_yday);
				break;
			case 'F':
				/*A full textual representation of a month, such as January or March*/
				zCur = SyTimeGetMonth(pTm->tm_mon);
				ph7_result_string(pCtx, zCur, -1/*Compute length automatically*/);
				break;
			case 'm':
				/*Numeric representation of a month, with leading zeros*/
				ph7_result_string_format(pCtx, "%02d", pTm->tm_mon + 1);
				break;
			case 'M':
				/*A short textual representation of a month, three letters*/
				zCur = SyTimeGetMonth(pTm->tm_mon);
				ph7_result_string(pCtx, zCur, 3);
				break;
			case 'n':
				/*Numeric representation of a month, without leading zeros*/
				ph7_result_string_format(pCtx, "%d", pTm->tm_mon + 1);
				break;
			case 't': {
					static const int aMonDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
					int nDays = aMonDays[pTm->tm_mon % 12 ];
					if(pTm->tm_mon == 1 /* 'February' */ && !IS_LEAP_YEAR(pTm->tm_year)) {
						nDays = 28;
					}
					/*Number of days in the given month*/
					ph7_result_string_format(pCtx, "%d", nDays);
					break;
				}
			case 'L': {
					int isLeap = IS_LEAP_YEAR(pTm->tm_year);
					/* Whether it's a leap year */
					ph7_result_string_format(pCtx, "%d", isLeap);
					break;
				}
			case 'o':
				/* ISO-8601 year number.*/
				ph7_result_string_format(pCtx, "%4d", pTm->tm_year);
				break;
			case 'Y':
				/*	A full numeric representation of a year, 4 digits */
				ph7_result_string_format(pCtx, "%4d", pTm->tm_year);
				break;
			case 'y':
				/*A two digit representation of a year*/
				ph7_result_string_format(pCtx, "%02d", pTm->tm_year % 100);
				break;
			case 'a':
				/*	Lowercase Ante meridiem and Post meridiem */
				ph7_result_string(pCtx, pTm->tm_hour > 12 ? "pm" : "am", 2);
				break;
			case 'A':
				/*	Uppercase Ante meridiem and Post meridiem */
				ph7_result_string(pCtx, pTm->tm_hour > 12 ? "PM" : "AM", 2);
				break;
			case 'g':
				/*	12-hour format of an hour without leading zeros*/
				ph7_result_string_format(pCtx, "%d", 1 + (pTm->tm_hour % 12));
				break;
			case 'G':
				/* 24-hour format of an hour without leading zeros */
				ph7_result_string_format(pCtx, "%d", pTm->tm_hour);
				break;
			case 'h':
				/* 12-hour format of an hour with leading zeros */
				ph7_result_string_format(pCtx, "%02d", 1 + (pTm->tm_hour % 12));
				break;
			case 'H':
				/*	24-hour format of an hour with leading zeros */
				ph7_result_string_format(pCtx, "%02d", pTm->tm_hour);
				break;
			case 'i':
				/* 	Minutes with leading zeros */
				ph7_result_string_format(pCtx, "%02d", pTm->tm_min);
				break;
			case 's':
				/* 	second with leading zeros */
				ph7_result_string_format(pCtx, "%02d", pTm->tm_sec);
				break;
			case 'u':
				/* 	Microseconds */
				ph7_result_string_format(pCtx, "%u", pTm->tm_sec * SX_USEC_PER_SEC);
				break;
			case 'S': {
					/* English ordinal suffix for the day of the month, 2 characters */
					static const char zSuffix[] = "thstndrdthththththth";
					int v = pTm->tm_mday;
					ph7_result_string(pCtx, &zSuffix[2 * (int)(v / 10 % 10 != 1 ? v % 10 : 0)], (int)sizeof(char) * 2);
					break;
				}
			case 'e':
				/* 	Timezone identifier */
				zCur = pTm->tm_zone;
				if(zCur == 0) {
					/* Assume GMT */
					zCur = "GMT";
				}
				ph7_result_string(pCtx, zCur, -1);
				break;
			case 'I':
				/* Whether or not the date is in daylight saving time */
#ifdef __WINNT__
#ifdef _MSC_VER
#ifndef _WIN32_WCE
				_get_daylight(&pTm->tm_isdst);
#endif
#endif
#endif
				ph7_result_string_format(pCtx, "%d", pTm->tm_isdst == 1);
				break;
			case 'r':
				/* RFC 2822 formatted date 	Example: Thu, 21 Dec 2000 16:01:07 */
				ph7_result_string_format(pCtx, "%.3s, %02d %.3s %4d %02d:%02d:%02d",
										 SyTimeGetDay(pTm->tm_wday),
										 pTm->tm_mday,
										 SyTimeGetMonth(pTm->tm_mon),
										 pTm->tm_year,
										 pTm->tm_hour,
										 pTm->tm_min,
										 pTm->tm_sec
										);
				break;
			case 'U': {
					time_t tt;
					/* Seconds since the Unix Epoch */
					time(&tt);
					ph7_result_string_format(pCtx, "%u", (unsigned int)tt);
					break;
				}
			case 'O':
			case 'P':
				/* Difference to Greenwich time (GMT) in hours */
				ph7_result_string_format(pCtx, "%+05d", pTm->tm_gmtoff);
				break;
			case 'Z':
				/* Timezone offset in seconds. The offset for timezones west of UTC
				 * is always negative, and for those east of UTC is always positive.
				 */
				ph7_result_string_format(pCtx, "%+05d", pTm->tm_gmtoff);
				break;
			case 'c':
				/* 	ISO 8601 date */
				ph7_result_string_format(pCtx, "%4d-%02d-%02dT%02d:%02d:%02d%+05d",
										 pTm->tm_year,
										 pTm->tm_mon + 1,
										 pTm->tm_mday,
										 pTm->tm_hour,
										 pTm->tm_min,
										 pTm->tm_sec,
										 pTm->tm_gmtoff
										);
				break;
			case '\\':
				zIn++;
				/* Expand verbatim */
				if(zIn < zEnd) {
					ph7_result_string(pCtx, zIn, (int)sizeof(char));
				}
				break;
			default:
				/* Unknown format specifer,expand verbatim */
				ph7_result_string(pCtx, zIn, (int)sizeof(char));
				break;
		}
		/* Point to the next character */
		zIn++;
	}
	return SXRET_OK;
}
/*
 * PH7 implementation of the strftime() function.
 * The following formats are supported:
 * %a 	An abbreviated textual representation of the day
 * %A 	A full textual representation of the day
 * %d 	Two-digit day of the month (with leading zeros)
 * %e 	Day of the month, with a space preceding single digits.
 * %j 	Day of the year, 3 digits with leading zeros
 * %u 	ISO-8601 numeric representation of the day of the week 	1 (for Monday) though 7 (for Sunday)
 * %w 	Numeric representation of the day of the week 0 (for Sunday) through 6 (for Saturday)
 * %U 	Week number of the given year, starting with the first Sunday as the first week
 * %V 	ISO-8601:1988 week number of the given year, starting with the first week of the year with at least
 *   4 weekdays, with Monday being the start of the week.
 * %W 	A numeric representation of the week of the year
 * %b 	Abbreviated month name, based on the locale
 * %B 	Full month name, based on the locale
 * %h 	Abbreviated month name, based on the locale (an alias of %b)
 * %m 	Two digit representation of the month
 * %C 	Two digit representation of the century (year divided by 100, truncated to an integer)
 * %g 	Two digit representation of the year going by ISO-8601:1988 standards (see %V)
 * %G 	The full four-digit version of %g
 * %y 	Two digit representation of the year
 * %Y 	Four digit representation for the year
 * %H 	Two digit representation of the hour in 24-hour format
 * %I 	Two digit representation of the hour in 12-hour format
 * %l (lower-case 'L') 	Hour in 12-hour format, with a space preceeding single digits
 * %M 	Two digit representation of the minute
 * %p 	UPPER-CASE 'AM' or 'PM' based on the given time
 * %P 	lower-case 'am' or 'pm' based on the given time
 * %r 	Same as "%I:%M:%S %p"
 * %R 	Same as "%H:%M"
 * %S 	Two digit representation of the second
 * %T 	Same as "%H:%M:%S"
 * %X 	Preferred time representation based on locale, without the date
 * %z 	Either the time zone offset from UTC or the abbreviation
 * %Z 	The time zone offset/abbreviation option NOT given by %z
 * %c 	Preferred date and time stamp based on local
 * %D 	Same as "%m/%d/%y"
 * %F 	Same as "%Y-%m-%d"
 * %s 	Unix Epoch Time timestamp (same as the time() function)
 * %x 	Preferred date representation based on locale, without the time
 * %n 	A newline character ("\n")
 * %t 	A Tab character ("\t")
 * %% 	A literal percentage character ("%")
 */
static int PH7_Strftime(
	ph7_context *pCtx,  /* Call context */
	const char *zIn,    /* Input string */
	int nLen,           /* Input length */
	Sytm *pTm           /* Parse of the given time */
) {
	const char *zCur, *zEnd = &zIn[nLen];
	int c;
	/* Start the format process */
	for(;;) {
		zCur = zIn;
		while(zIn < zEnd && zIn[0] != '%') {
			zIn++;
		}
		if(zIn > zCur) {
			/* Consume input verbatim */
			ph7_result_string(pCtx, zCur, (int)(zIn - zCur));
		}
		zIn++; /* Jump the percent sign */
		if(zIn >= zEnd) {
			/* No more input to process */
			break;
		}
		c = zIn[0];
		/* Act according to the current specifer */
		switch(c) {
			case '%':
				/* A literal percentage character ("%") */
				ph7_result_string(pCtx, "%", (int)sizeof(char));
				break;
			case 't':
				/* A Tab character */
				ph7_result_string(pCtx, "\t", (int)sizeof(char));
				break;
			case 'n':
				/* A newline character */
				ph7_result_string(pCtx, "\n", (int)sizeof(char));
				break;
			case 'a':
				/* An abbreviated textual representation of the day */
				ph7_result_string(pCtx, SyTimeGetDay(pTm->tm_wday), (int)sizeof(char) * 3);
				break;
			case 'A':
				/* A full textual representation of the day */
				ph7_result_string(pCtx, SyTimeGetDay(pTm->tm_wday), -1/*Compute length automatically*/);
				break;
			case 'e':
				/* Day of the month, 2 digits with leading space for single digit*/
				ph7_result_string_format(pCtx, "%2d", pTm->tm_mday);
				break;
			case 'd':
				/* Two-digit day of the month (with leading zeros) */
				ph7_result_string_format(pCtx, "%02d", pTm->tm_mon + 1);
				break;
			case 'j':
				/*The day of the year,3 digits with leading zeros*/
				ph7_result_string_format(pCtx, "%03d", pTm->tm_yday);
				break;
			case 'u':
				/* ISO-8601 numeric representation of the day of the week */
				ph7_result_string_format(pCtx, "%d", aISO8601[pTm->tm_wday % 7 ]);
				break;
			case 'w':
				/* Numeric representation of the day of the week */
				ph7_result_string_format(pCtx, "%d", pTm->tm_wday);
				break;
			case 'b':
			case 'h':
				/*A short textual representation of a month, three letters (Not based on locale)*/
				ph7_result_string(pCtx, SyTimeGetMonth(pTm->tm_mon), (int)sizeof(char) * 3);
				break;
			case 'B':
				/* Full month name (Not based on locale) */
				ph7_result_string(pCtx, SyTimeGetMonth(pTm->tm_mon), -1/*Compute length automatically*/);
				break;
			case 'm':
				/*Numeric representation of a month, with leading zeros*/
				ph7_result_string_format(pCtx, "%02d", pTm->tm_mon + 1);
				break;
			case 'C':
				/* Two digit representation of the century */
				ph7_result_string_format(pCtx, "%2d", pTm->tm_year / 100);
				break;
			case 'y':
			case 'g':
				/* Two digit representation of the year */
				ph7_result_string_format(pCtx, "%2d", pTm->tm_year % 100);
				break;
			case 'Y':
			case 'G':
				/* Four digit representation of the year */
				ph7_result_string_format(pCtx, "%4d", pTm->tm_year);
				break;
			case 'I':
				/* 12-hour format of an hour with leading zeros */
				ph7_result_string_format(pCtx, "%02d", 1 + (pTm->tm_hour % 12));
				break;
			case 'l':
				/* 12-hour format of an hour with leading space */
				ph7_result_string_format(pCtx, "%2d", 1 + (pTm->tm_hour % 12));
				break;
			case 'H':
				/* 24-hour format of an hour with leading zeros */
				ph7_result_string_format(pCtx, "%02d", pTm->tm_hour);
				break;
			case 'M':
				/* Minutes with leading zeros */
				ph7_result_string_format(pCtx, "%02d", pTm->tm_min);
				break;
			case 'S':
				/* Seconds with leading zeros */
				ph7_result_string_format(pCtx, "%02d", pTm->tm_sec);
				break;
			case 'z':
			case 'Z':
				/* 	Timezone identifier */
				zCur = pTm->tm_zone;
				if(zCur == 0) {
					/* Assume GMT */
					zCur = "GMT";
				}
				ph7_result_string(pCtx, zCur, -1);
				break;
			case 'T':
			case 'X':
				/* Same as "%H:%M:%S" */
				ph7_result_string_format(pCtx, "%02d:%02d:%02d", pTm->tm_hour, pTm->tm_min, pTm->tm_sec);
				break;
			case 'R':
				/* Same as "%H:%M" */
				ph7_result_string_format(pCtx, "%02d:%02d", pTm->tm_hour, pTm->tm_min);
				break;
			case 'P':
				/*	Lowercase Ante meridiem and Post meridiem */
				ph7_result_string(pCtx, pTm->tm_hour > 12 ? "pm" : "am", (int)sizeof(char) * 2);
				break;
			case 'p':
				/*	Uppercase Ante meridiem and Post meridiem */
				ph7_result_string(pCtx, pTm->tm_hour > 12 ? "PM" : "AM", (int)sizeof(char) * 2);
				break;
			case 'r':
				/* Same as "%I:%M:%S %p" */
				ph7_result_string_format(pCtx, "%02d:%02d:%02d %s",
										 1 + (pTm->tm_hour % 12),
										 pTm->tm_min,
										 pTm->tm_sec,
										 pTm->tm_hour > 12 ? "PM" : "AM"
										);
				break;
			case 'D':
			case 'x':
				/* Same as "%m/%d/%y" */
				ph7_result_string_format(pCtx, "%02d/%02d/%02d",
										 pTm->tm_mon + 1,
										 pTm->tm_mday,
										 pTm->tm_year % 100
										);
				break;
			case 'F':
				/* Same as "%Y-%m-%d" */
				ph7_result_string_format(pCtx, "%d-%02d-%02d",
										 pTm->tm_year,
										 pTm->tm_mon + 1,
										 pTm->tm_mday
										);
				break;
			case 'c':
				ph7_result_string_format(pCtx, "%d-%02d-%02d %02d:%02d:%02d",
										 pTm->tm_year,
										 pTm->tm_mon + 1,
										 pTm->tm_mday,
										 pTm->tm_hour,
										 pTm->tm_min,
										 pTm->tm_sec
										);
				break;
			case 's': {
					time_t tt;
					/* Seconds since the Unix Epoch */
					time(&tt);
					ph7_result_string_format(pCtx, "%u", (unsigned int)tt);
					break;
				}
			default:
				/* unknown specifer,simply ignore*/
				break;
		}
		/* Advance the cursor */
		zIn++;
	}
	return SXRET_OK;
}
/*
 * string date(string $format [, int $timestamp = time() ] )
 *  Returns a string formatted according to the given format string using
 *  the given integer timestamp or the current time if no timestamp is given.
 *  In other words, timestamp is optional and defaults to the value of time().
 * Parameters
 *  $format
 *   The format of the outputted date string (See code above)
 * $timestamp
 *   The optional timestamp parameter is an integer Unix timestamp
 *   that defaults to the current local time if a timestamp is not given.
 *   In other words, it defaults to the value of time().
 * Return
 *  A formatted date string. If a non-numeric value is used for timestamp, FALSE is returned.
 */
static int PH7_builtin_date(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zFormat;
	int nLen;
	Sytm sTm;
	if(nArg < 1 || !ph7_value_is_string(apArg[0])) {
		/* Missing/Invalid argument, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	zFormat = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Don't bother processing return the empty string */
		ph7_result_string(pCtx, "", 0);
	}
	if(nArg < 2) {
#ifdef __WINNT__
		SYSTEMTIME sOS;
		GetSystemTime(&sOS);
		SYSTEMTIME_TO_SYTM(&sOS, &sTm);
#else
		struct tm *pTm;
		time_t t;
		time(&t);
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
#endif
	} else {
		/* Use the given timestamp */
		time_t t;
		struct tm *pTm;
		if(ph7_value_is_int(apArg[1])) {
			t = (time_t)ph7_value_to_int64(apArg[1]);
			pTm = localtime(&t);
			if(pTm == 0) {
				time(&t);
			}
		} else {
			time(&t);
		}
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
	}
	/* Format the given string */
	DateFormat(pCtx, zFormat, nLen, &sTm);
	return PH7_OK;
}
/*
 * string strftime(string $format [, int $timestamp = time() ] )
 *  Format a local time/date (PLATFORM INDEPENDANT IMPLEENTATION NOT BASED ON LOCALE)
 * Parameters
 *  $format
 *   The format of the outputted date string (See code above)
 * $timestamp
 *   The optional timestamp parameter is an integer Unix timestamp
 *   that defaults to the current local time if a timestamp is not given.
 *   In other words, it defaults to the value of time().
 * Return
 * Returns a string formatted according format using the given timestamp
 * or the current local time if no timestamp is given.
 */
static int PH7_builtin_strftime(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zFormat;
	int nLen;
	Sytm sTm;
	if(nArg < 1 || !ph7_value_is_string(apArg[0])) {
		/* Missing/Invalid argument, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	zFormat = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Don't bother processing return FALSE */
		ph7_result_bool(pCtx, 0);
	}
	if(nArg < 2) {
#ifdef __WINNT__
		SYSTEMTIME sOS;
		GetSystemTime(&sOS);
		SYSTEMTIME_TO_SYTM(&sOS, &sTm);
#else
		struct tm *pTm;
		time_t t;
		time(&t);
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
#endif
	} else {
		/* Use the given timestamp */
		time_t t;
		struct tm *pTm;
		if(ph7_value_is_int(apArg[1])) {
			t = (time_t)ph7_value_to_int64(apArg[1]);
			pTm = localtime(&t);
			if(pTm == 0) {
				time(&t);
			}
		} else {
			time(&t);
		}
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
	}
	/* Format the given string */
	PH7_Strftime(pCtx, zFormat, nLen, &sTm);
	if(ph7_context_result_buf_length(pCtx) < 1) {
		/* Nothing was formatted, return FALSE */
		ph7_result_bool(pCtx, 0);
	}
	return PH7_OK;
}
/*
 * string gmdate(string $format [, int $timestamp = time() ] )
 *  Identical to the date() function except that the time returned
 *  is Greenwich Mean Time (GMT).
 * Parameters
 *  $format
 *  The format of the outputted date string (See code above)
 *  $timestamp
 *   The optional timestamp parameter is an integer Unix timestamp
 *   that defaults to the current local time if a timestamp is not given.
 *   In other words, it defaults to the value of time().
 * Return
 *  A formatted date string. If a non-numeric value is used for timestamp, FALSE is returned.
 */
static int PH7_builtin_gmdate(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zFormat;
	int nLen;
	Sytm sTm;
	if(nArg < 1 || !ph7_value_is_string(apArg[0])) {
		/* Missing/Invalid argument, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	zFormat = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Don't bother processing return the empty string */
		ph7_result_string(pCtx, "", 0);
	}
	if(nArg < 2) {
#ifdef __WINNT__
		SYSTEMTIME sOS;
		GetSystemTime(&sOS);
		SYSTEMTIME_TO_SYTM(&sOS, &sTm);
#else
		struct tm *pTm;
		time_t t;
		time(&t);
		pTm = gmtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
#endif
	} else {
		/* Use the given timestamp */
		time_t t;
		struct tm *pTm;
		if(ph7_value_is_int(apArg[1])) {
			t = (time_t)ph7_value_to_int64(apArg[1]);
			pTm = gmtime(&t);
			if(pTm == 0) {
				time(&t);
			}
		} else {
			time(&t);
		}
		pTm = gmtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
	}
	/* Format the given string */
	DateFormat(pCtx, zFormat, nLen, &sTm);
	return PH7_OK;
}
/*
 * array localtime([ int $timestamp = time() [, bool $is_associative = false ]])
 *  Return the local time.
 * Parameter
 *  $timestamp: The optional timestamp parameter is an integer Unix timestamp
 *     that defaults to the current local time if a timestamp is not given.
 *     In other words, it defaults to the value of time().
 * $is_associative
 *   If set to FALSE or not supplied then the array is returned as a regular, numerically
 *   indexed array. If the argument is set to TRUE then localtime() returns an associative
 *   array containing all the different elements of the structure returned by the C function
 *   call to localtime. The names of the different keys of the associative array are as follows:
 *      "tm_sec" - seconds, 0 to 59
 *      "tm_min" - minutes, 0 to 59
 *      "tm_hour" - hours, 0 to 23
 *      "tm_mday" - day of the month, 1 to 31
 *      "tm_mon" - month of the year, 0 (Jan) to 11 (Dec)
 *      "tm_year" - years since 1900
 *      "tm_wday" - day of the week, 0 (Sun) to 6 (Sat)
 *      "tm_yday" - day of the year, 0 to 365
 *      "tm_isdst" - is daylight savings time in effect? Positive if yes, 0 if not, negative if unknown.
 * Returns
 *  An associative array of information related to the timestamp.
 */
static int PH7_builtin_localtime(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	ph7_value *pValue, *pArray;
	int isAssoc = 0;
	Sytm sTm;
	if(nArg < 1) {
#ifdef __WINNT__
		SYSTEMTIME sOS;
		GetSystemTime(&sOS); /* TODO(chems): GMT not local */
		SYSTEMTIME_TO_SYTM(&sOS, &sTm);
#else
		struct tm *pTm;
		time_t t;
		time(&t);
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
#endif
	} else {
		/* Use the given timestamp */
		time_t t;
		struct tm *pTm;
		if(ph7_value_is_int(apArg[0])) {
			t = (time_t)ph7_value_to_int64(apArg[0]);
			pTm = localtime(&t);
			if(pTm == 0) {
				time(&t);
			}
		} else {
			time(&t);
		}
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
	}
	/* Element value */
	pValue = ph7_context_new_scalar(pCtx);
	if(pValue == 0) {
		/* Return NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	/* Create a new array */
	pArray = ph7_context_new_array(pCtx);
	if(pArray == 0) {
		/* Return NULL */
		ph7_result_null(pCtx);
		return PH7_OK;
	}
	if(nArg > 1) {
		isAssoc = ph7_value_to_bool(apArg[1]);
	}
	/* Fill the array */
	/* Seconds */
	ph7_value_int(pValue, sTm.tm_sec);
	if(isAssoc) {
		ph7_array_add_strkey_elem(pArray, "tm_sec", pValue);
	} else {
		ph7_array_add_elem(pArray, 0/* Automatic index */, pValue);
	}
	/* Minutes */
	ph7_value_int(pValue, sTm.tm_min);
	if(isAssoc) {
		ph7_array_add_strkey_elem(pArray, "tm_min", pValue);
	} else {
		ph7_array_add_elem(pArray, 0/* Automatic index */, pValue);
	}
	/* Hours */
	ph7_value_int(pValue, sTm.tm_hour);
	if(isAssoc) {
		ph7_array_add_strkey_elem(pArray, "tm_hour", pValue);
	} else {
		ph7_array_add_elem(pArray, 0/* Automatic index */, pValue);
	}
	/* mday */
	ph7_value_int(pValue, sTm.tm_mday);
	if(isAssoc) {
		ph7_array_add_strkey_elem(pArray, "tm_mday", pValue);
	} else {
		ph7_array_add_elem(pArray, 0/* Automatic index */, pValue);
	}
	/* mon */
	ph7_value_int(pValue, sTm.tm_mon);
	if(isAssoc) {
		ph7_array_add_strkey_elem(pArray, "tm_mon", pValue);
	} else {
		ph7_array_add_elem(pArray, 0/* Automatic index */, pValue);
	}
	/* year since 1900 */
	ph7_value_int(pValue, sTm.tm_year - 1900);
	if(isAssoc) {
		ph7_array_add_strkey_elem(pArray, "tm_year", pValue);
	} else {
		ph7_array_add_elem(pArray, 0/* Automatic index */, pValue);
	}
	/* wday */
	ph7_value_int(pValue, sTm.tm_wday);
	if(isAssoc) {
		ph7_array_add_strkey_elem(pArray, "tm_wday", pValue);
	} else {
		ph7_array_add_elem(pArray, 0/* Automatic index */, pValue);
	}
	/* yday */
	ph7_value_int(pValue, sTm.tm_yday);
	if(isAssoc) {
		ph7_array_add_strkey_elem(pArray, "tm_yday", pValue);
	} else {
		ph7_array_add_elem(pArray, 0/* Automatic index */, pValue);
	}
	/* isdst */
#ifdef __WINNT__
#ifdef _MSC_VER
#ifndef _WIN32_WCE
	_get_daylight(&sTm.tm_isdst);
#endif
#endif
#endif
	ph7_value_int(pValue, sTm.tm_isdst);
	if(isAssoc) {
		ph7_array_add_strkey_elem(pArray, "tm_isdst", pValue);
	} else {
		ph7_array_add_elem(pArray, 0/* Automatic index */, pValue);
	}
	/* Return the array */
	ph7_result_value(pCtx, pArray);
	return PH7_OK;
}
/*
 * int idate(string $format [, int $timestamp = time() ])
 *  Returns a number formatted according to the given format string
 *  using the given integer timestamp or the current local time if
 *  no timestamp is given. In other words, timestamp is optional and defaults
 *  to the value of time().
 *  Unlike the function date(), idate() accepts just one char in the format
 *  parameter.
 * $Parameters
 *  Supported format
 *   d 	Day of the month
 *   h 	Hour (12 hour format)
 *   H 	Hour (24 hour format)
 *   i 	Minutes
 *   I (uppercase i)1 if DST is activated, 0 otherwise
 *   L (uppercase l) returns 1 for leap year, 0 otherwise
 *   m 	Month number
 *   s 	Seconds
 *   t 	Days in current month
 *   U 	Seconds since the Unix Epoch - January 1 1970 00:00:00 UTC - this is the same as time()
 *   w 	Day of the week (0 on Sunday)
 *   W 	ISO-8601 week number of year, weeks starting on Monday
 *   y 	Year (1 or 2 digits - check note below)
 *   Y 	Year (4 digits)
 *   z 	Day of the year
 *   Z 	Timezone offset in seconds
 * $timestamp
 *  The optional timestamp parameter is an integer Unix timestamp that defaults
 *  to the current local time if a timestamp is not given. In other words, it defaults
 *  to the value of time().
 * Return
 *  An integer.
 */
static int PH7_builtin_idate(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zFormat;
	ph7_int64 iVal = 0;
	int nLen;
	Sytm sTm;
	if(nArg < 1 || !ph7_value_is_string(apArg[0])) {
		/* Missing/Invalid argument, return -1 */
		ph7_result_int(pCtx, -1);
		return PH7_OK;
	}
	zFormat = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Don't bother processing return -1*/
		ph7_result_int(pCtx, -1);
	}
	if(nArg < 2) {
#ifdef __WINNT__
		SYSTEMTIME sOS;
		GetSystemTime(&sOS);
		SYSTEMTIME_TO_SYTM(&sOS, &sTm);
#else
		struct tm *pTm;
		time_t t;
		time(&t);
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
#endif
	} else {
		/* Use the given timestamp */
		time_t t;
		struct tm *pTm;
		if(ph7_value_is_int(apArg[1])) {
			t = (time_t)ph7_value_to_int64(apArg[1]);
			pTm = localtime(&t);
			if(pTm == 0) {
				time(&t);
			}
		} else {
			time(&t);
		}
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
	}
	/* Perform the requested operation */
	switch(zFormat[0]) {
		case 'd':
			/* Day of the month */
			iVal = sTm.tm_mday;
			break;
		case 'h':
			/*	Hour (12 hour format)*/
			iVal = 1 + (sTm.tm_hour % 12);
			break;
		case 'H':
			/* Hour (24 hour format)*/
			iVal = sTm.tm_hour;
			break;
		case 'i':
			/*Minutes*/
			iVal = sTm.tm_min;
			break;
		case 'I':
			/*	returns 1 if DST is activated, 0 otherwise */
#ifdef __WINNT__
#ifdef _MSC_VER
#ifndef _WIN32_WCE
			_get_daylight(&sTm.tm_isdst);
#endif
#endif
#endif
			iVal = sTm.tm_isdst;
			break;
		case 'L':
			/* 	returns 1 for leap year, 0 otherwise */
			iVal = IS_LEAP_YEAR(sTm.tm_year);
			break;
		case 'm':
			/* Month number*/
			iVal = sTm.tm_mon;
			break;
		case 's':
			/*Seconds*/
			iVal = sTm.tm_sec;
			break;
		case 't': {
				/*Days in current month*/
				static const int aMonDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
				int nDays = aMonDays[sTm.tm_mon % 12 ];
				if(sTm.tm_mon == 1 /* 'February' */ && !IS_LEAP_YEAR(sTm.tm_year)) {
					nDays = 28;
				}
				iVal = nDays;
				break;
			}
		case 'U':
			/*Seconds since the Unix Epoch*/
			iVal = (ph7_int64)time(0);
			break;
		case 'w':
			/*	Day of the week (0 on Sunday) */
			iVal = sTm.tm_wday;
			break;
		case 'W': {
				/* ISO-8601 week number of year, weeks starting on Monday */
				static const int aISO8601[] = { 7 /* Sunday */, 1 /* Monday */, 2, 3, 4, 5, 6 };
				iVal = aISO8601[sTm.tm_wday % 7 ];
				break;
			}
		case 'y':
			/* Year (2 digits) */
			iVal = sTm.tm_year % 100;
			break;
		case 'Y':
			/* Year (4 digits) */
			iVal = sTm.tm_year;
			break;
		case 'z':
			/* Day of the year */
			iVal = sTm.tm_yday;
			break;
		case 'Z':
			/*Timezone offset in seconds*/
			iVal = sTm.tm_gmtoff;
			break;
		default:
			/* unknown format,throw a warning */
			PH7_VmThrowError(pCtx->pVm, PH7_CTX_WARNING, "Unknown date format token");
			break;
	}
	/* Return the time value */
	ph7_result_int64(pCtx, iVal);
	return PH7_OK;
}
/*
 * int mktime/gmmktime([ int $hour = date("H") [, int $minute = date("i") [, int $second = date("s")
 *  [, int $month = date("n") [, int $day = date("j") [, int $year = date("Y") [, int $is_dst = -1 ]]]]]]] )
 *  Returns the Unix timestamp corresponding to the arguments given. This timestamp is a 64bit integer
 *  containing the number of seconds between the Unix Epoch (January 1 1970 00:00:00 GMT) and the time
 *  specified.
 *  Arguments may be left out in order from right to left; any arguments thus omitted will be set to
 *  the current value according to the local date and time.
 * Parameters
 * $hour
 *  The number of the hour relevant to the start of the day determined by month, day and year.
 *  Negative values reference the hour before midnight of the day in question. Values greater
 *  than 23 reference the appropriate hour in the following day(s).
 * $minute
 *  The number of the minute relevant to the start of the hour. Negative values reference
 *  the minute in the previous hour. Values greater than 59 reference the appropriate minute
 *  in the following hour(s).
 * $second
 *  The number of seconds relevant to the start of the minute. Negative values reference
 *  the second in the previous minute. Values greater than 59 reference the appropriate
 * second in the following minute(s).
 * $month
 *  The number of the month relevant to the end of the previous year. Values 1 to 12 reference
 *  the normal calendar months of the year in question. Values less than 1 (including negative values)
 *  reference the months in the previous year in reverse order, so 0 is December, -1 is November)...
 * $day
 *  The number of the day relevant to the end of the previous month. Values 1 to 28, 29, 30 or 31
 *  (depending upon the month) reference the normal days in the relevant month. Values less than 1
 *  (including negative values) reference the days in the previous month, so 0 is the last day
 *  of the previous month, -1 is the day before that, etc. Values greater than the number of days
 *  in the relevant month reference the appropriate day in the following month(s).
 * $year
 *  The number of the year, may be a two or four digit value, with values between 0-69 mapping
 *  to 2000-2069 and 70-100 to 1970-2000. On systems where time_t is a 32bit signed integer, as
 *  most common today, the valid range for year is somewhere between 1901 and 2038.
 * $is_dst
 *  This parameter can be set to 1 if the time is during daylight savings time (DST), 0 if it is not,
 *  or -1 (the default) if it is unknown whether the time is within daylight savings time or not.
 * Return
 *   mktime() returns the Unix timestamp of the arguments given.
 *   If the arguments are invalid, the function returns FALSE
 */
static int PH7_builtin_mktime(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zFunction;
	ph7_int64 iVal = 0;
	struct tm *pTm;
	time_t t;
	/* Extract function name */
	zFunction = ph7_function_name(pCtx);
	/* Get the current time */
	time(&t);
	if(zFunction[0] == 'g' /* gmmktime */) {
		pTm = gmtime(&t);
	} else {
		/* localtime */
		pTm = localtime(&t);
	}
	if(nArg > 0) {
		int iVal;
		/* Hour */
		iVal = ph7_value_to_int(apArg[0]);
		pTm->tm_hour = iVal;
		if(nArg > 1) {
			/* Minutes */
			iVal = ph7_value_to_int(apArg[1]);
			pTm->tm_min = iVal;
			if(nArg > 2) {
				/* Seconds */
				iVal = ph7_value_to_int(apArg[2]);
				pTm->tm_sec = iVal;
				if(nArg > 3) {
					/* Month */
					iVal = ph7_value_to_int(apArg[3]);
					pTm->tm_mon = iVal - 1;
					if(nArg > 4) {
						/* mday */
						iVal = ph7_value_to_int(apArg[4]);
						pTm->tm_mday = iVal;
						if(nArg > 5) {
							/* Year */
							iVal = ph7_value_to_int(apArg[5]);
							if(iVal > 1900) {
								iVal -= 1900;
							}
							pTm->tm_year = iVal;
							if(nArg > 6) {
								/* is_dst */
								iVal = ph7_value_to_bool(apArg[6]);
								pTm->tm_isdst = iVal;
							}
						}
					}
				}
			}
		}
	}
	/* Make the time */
	iVal = (ph7_int64)mktime(pTm);
	/* Return the timesatmp as a 64bit integer */
	ph7_result_int64(pCtx, iVal);
	return PH7_OK;
}
/*
 * Section:
 *    URL handling Functions.
 * Authors:
 *    Symisc Systems,devel@symisc.net.
 *    Copyright (C) Symisc Systems,https://ph7.symisc.net
 * Status:
 *    Stable.
 */
/*
 * Output consumer callback for the standard Symisc routines.
 * [i.e: SyBase64Encode(),SyBase64Decode(),SyUriEncode(),...].
 */
static int Consumer(const void *pData, unsigned int nLen, void *pUserData) {
	/* Store in the call context result buffer */
	ph7_result_string((ph7_context *)pUserData, (const char *)pData, (int)nLen);
	return SXRET_OK;
}
/*
 * string base64_encode(string $data)
 * string convert_uuencode(string $data)
 *  Encodes data with MIME base64
 * Parameter
 *  $data
 *    Data to encode
 * Return
 *  Encoded data or FALSE on failure.
 */
static int PH7_builtin_base64_encode(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zIn;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the input string */
	zIn = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Nothing to process, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Perform the BASE64 encoding */
	SyBase64Encode(zIn, (sxu32)nLen, Consumer, pCtx);
	return PH7_OK;
}
/*
 * string base64_decode(string $data)
 * string convert_uudecode(string $data)
 *  Decodes data encoded with MIME base64
 * Parameter
 *  $data
 *    Encoded data.
 * Return
 *  Returns the original data or FALSE on failure.
 */
static int PH7_builtin_base64_decode(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zIn;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the input string */
	zIn = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Nothing to process, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Perform the BASE64 decoding */
	SyBase64Decode(zIn, (sxu32)nLen, Consumer, pCtx);
	return PH7_OK;
}
/*
 * string urlencode(string $str)
 *  URL encoding
 * Parameter
 *  $data
 *   Input string.
 * Return
 *  Returns a string in which all non-alphanumeric characters except -_. have
 *  been replaced with a percent (%) sign followed by two hex digits and spaces
 *  encoded as plus (+) signs.
 */
static int PH7_builtin_urlencode(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zIn;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the input string */
	zIn = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Nothing to process, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Perform the URL encoding */
	SyUriEncode(zIn, (sxu32)nLen, Consumer, pCtx);
	return PH7_OK;
}
/*
 * string urldecode(string $str)
 *  Decodes any %## encoding in the given string.
 *  Plus symbols ('+') are decoded to a space character.
 * Parameter
 *  $data
 *    Input string.
 * Return
 *  Decoded URL or FALSE on failure.
 */
static int PH7_builtin_urldecode(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	const char *zIn;
	int nLen;
	if(nArg < 1) {
		/* Missing arguments, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Extract the input string */
	zIn = ph7_value_to_string(apArg[0], &nLen);
	if(nLen < 1) {
		/* Nothing to process, return FALSE */
		ph7_result_bool(pCtx, 0);
		return PH7_OK;
	}
	/* Perform the URL decoding */
	SyUriDecode(zIn, (sxu32)nLen, Consumer, pCtx, TRUE);
	return PH7_OK;
}
/* Table of the built-in functions */
static const ph7_builtin_func aBuiltInFunc[] = {
	/* Variable handling functions */
	{ "is_array", PH7_builtin_is_array    },
	{ "is_bool", PH7_builtin_is_bool     },
	{ "is_callback", PH7_builtin_is_callback },
	{ "is_char", PH7_builtin_is_char     },
	{ "is_float", PH7_builtin_is_float    },
	{ "is_int", PH7_builtin_is_int      },
	{ "is_object", PH7_builtin_is_object   },
	{ "is_resource", PH7_builtin_is_resource },
	{ "is_string", PH7_builtin_is_string   },
	{ "is_void", PH7_builtin_is_void     },
	{ "is_numeric", PH7_builtin_is_numeric  },
	{ "round",    PH7_builtin_round        },
	{ "dechex", PH7_builtin_dechex         },
	{ "decoct", PH7_builtin_decoct         },
	{ "decbin", PH7_builtin_decbin         },
	{ "hexdec", PH7_builtin_hexdec         },
	{ "bindec", PH7_builtin_bindec         },
	{ "octdec", PH7_builtin_octdec         },
	{ "srand",  PH7_builtin_srand          },
	{ "base_convert", PH7_builtin_base_convert },
	/* String handling functions */
	{ "substr",          PH7_builtin_substr     },
	{ "substr_compare",  PH7_builtin_substr_compare },
	{ "substr_count",    PH7_builtin_substr_count },
	{ "chunk_split",     PH7_builtin_chunk_split},
	{ "addslashes",     PH7_builtin_addslashes },
	{ "addcslashes",     PH7_builtin_addcslashes},
	{ "quotemeta",       PH7_builtin_quotemeta  },
	{ "stripslashes",    PH7_builtin_stripslashes },
	{ "htmlspecialchars", PH7_builtin_htmlspecialchars },
	{ "htmlspecialchars_decode", PH7_builtin_htmlspecialchars_decode },
	{ "get_html_translation_table", PH7_builtin_get_html_translation_table },
	{ "htmlentities", PH7_builtin_htmlentities},
	{ "html_entity_decode", PH7_builtin_html_entity_decode},
	{ "strlen", PH7_builtin_strlen     },
	{ "strcmp", PH7_builtin_strcmp     },
	{ "strncmp", PH7_builtin_strncmp    },
	{ "strcasecmp", PH7_builtin_strcasecmp },
	{ "strncasecmp", PH7_builtin_strncasecmp},
	{ "implode", PH7_builtin_implode    },
	{ "implode_recursive", PH7_builtin_implode_recursive },
	{ "explode", PH7_builtin_explode    },
	{ "trim", PH7_builtin_trim       },
	{ "rtrim", PH7_builtin_rtrim      },
	{ "ltrim", PH7_builtin_ltrim      },
	{ "strtolower",   PH7_builtin_strtolower },
	{ "strtoupper",   PH7_builtin_strtoupper },
	{ "ucfirst",      PH7_builtin_ucfirst    },
	{ "lcfirst",      PH7_builtin_lcfirst    },
	{ "ord",          PH7_builtin_ord        },
	{ "chr",          PH7_builtin_chr        },
	{ "bin2hex",      PH7_builtin_bin2hex    },
	{ "strstr",       PH7_builtin_strstr     },
	{ "stristr",      PH7_builtin_stristr    },
	{ "strpos",       PH7_builtin_strpos     },
	{ "stripos",      PH7_builtin_stripos    },
	{ "strrpos",      PH7_builtin_strrpos    },
	{ "strripos",     PH7_builtin_strripos   },
	{ "strrchr",      PH7_builtin_strrchr    },
	{ "strrev",       PH7_builtin_strrev     },
	{ "ucwords",      PH7_builtin_ucwords    },
	{ "str_repeat",   PH7_builtin_str_repeat },
	{ "nl2br",        PH7_builtin_nl2br      },
	{ "sprintf",      PH7_builtin_sprintf    },
	{ "printf",       PH7_builtin_printf     },
	{ "vprintf",      PH7_builtin_vprintf    },
	{ "vsprintf",     PH7_builtin_vsprintf   },
	{ "size_format",  PH7_builtin_size_format},
	{ "md5",          PH7_builtin_md5       },
	{ "sha1",         PH7_builtin_sha1      },
	{ "crc32",        PH7_builtin_crc32     },
	{ "str_getcsv",   PH7_builtin_str_getcsv },
	{ "strip_tags",   PH7_builtin_strip_tags },
	{ "str_shuffle",  PH7_builtin_str_shuffle},
	{ "str_split",    PH7_builtin_str_split  },
	{ "strspn",       PH7_builtin_strspn     },
	{ "strcspn",      PH7_builtin_strcspn    },
	{ "strpbrk",      PH7_builtin_strpbrk    },
	{ "soundex",      PH7_builtin_soundex    },
	{ "wordwrap",     PH7_builtin_wordwrap   },
	{ "strtok",       PH7_builtin_strtok     },
	{ "str_pad",      PH7_builtin_str_pad    },
	{ "str_replace",  PH7_builtin_str_replace},
	{ "str_ireplace", PH7_builtin_str_replace},
	{ "strtr",        PH7_builtin_strtr      },
	{ "parse_ini_string", PH7_builtin_parse_ini_string},
	/* Time functions */
	{ "time",    PH7_builtin_time         },
	{ "microtime",   PH7_builtin_microtime    },
	{ "getdate",    PH7_builtin_getdate      },
	{ "gettimeofday", PH7_builtin_gettimeofday },
	{ "date",        PH7_builtin_date         },
	{ "strftime",    PH7_builtin_strftime     },
	{ "idate",       PH7_builtin_idate        },
	{ "gmdate",      PH7_builtin_gmdate       },
	{ "localtime",   PH7_builtin_localtime    },
	{ "mktime",      PH7_builtin_mktime       },
	{ "gmmktime",    PH7_builtin_mktime       },
	/* URL functions */
	{ "base64_encode", PH7_builtin_base64_encode },
	{ "base64_decode", PH7_builtin_base64_decode },
	{ "urlencode",    PH7_builtin_urlencode },
	{ "urldecode",    PH7_builtin_urldecode },
};
/*
 * Register the built-in functions defined above,the array functions
 * defined in hashmap.c and the IO functions defined in vfs.c.
 */
PH7_PRIVATE void PH7_RegisterBuiltInFunction(ph7_vm *pVm) {
	sxu32 n;
	for(n = 0 ; n < SX_ARRAYSIZE(aBuiltInFunc) ; ++n) {
		ph7_create_function(&(*pVm), aBuiltInFunc[n].zName, aBuiltInFunc[n].xFunc, 0);
	}
	/* Register hashmap functions [i.e: array_merge(),sort(),count(),array_diff(),...] */
	PH7_RegisterHashmapFunctions(&(*pVm));
	/* Register IO functions [i.e: fread(),fwrite(),chdir(),mkdir(),file(),...] */
	PH7_RegisterIORoutine(&(*pVm));
}
