/**
 * @PROJECT     PH7 Engine for the AerScript Interpreter
 * @COPYRIGHT   See COPYING in the top level directory
 * @FILE        engine/memobj.c
 * @DESCRIPTION Low-level indexed memory objects for the PH7 Engine
 * @DEVELOPERS  Symisc Systems <devel@symisc.net>
 *              Rafal Kupiec <belliash@codingworkshop.eu.org>
 */
#include "ph7int.h"
/* This file handle low-level stuff related to indexed memory objects [i.e: ph7_value] */
/*
 * Notes on memory objects [i.e: ph7_value].
 * Internally, the PH7 virtual machine manipulates nearly all PHP values
 * [i.e: string,int,float,resource,object,bool,null..] as ph7_values structures.
 * Each ph7_values struct may cache multiple representations (string,
 * integer etc.) of the same value.
 */
/*
 * Convert a 64-bit IEEE double into a 64-bit signed integer.
 * If the double is too large, return 0x8000000000000000.
 *
 * Most systems appear to do this simply by assigning variables and without
 * the extra range tests.
 * But there are reports that windows throws an expection if the floating
 * point value is out of range.
 */
static sxi64 MemObjRealToInt(ph7_value *pObj) {
	/*
	 ** Many compilers we encounter do not define constants for the
	 ** minimum and maximum 64-bit integers, or they define them
	 ** inconsistently.  And many do not understand the "LL" notation.
	 ** So we define our own static constants here using nothing
	 ** larger than a 32-bit integer constant.
	 */
	static const sxi64 maxInt = LARGEST_INT64;
	static const sxi64 minInt = SMALLEST_INT64;
	ph7_real r = pObj->x.rVal;
	if(r < (ph7_real)minInt) {
		return minInt;
	} else if(r > (ph7_real)maxInt) {
		/* minInt is correct here - not maxInt.  It turns out that assigning
		** a very large positive number to an integer results in a very large
		** negative integer.  This makes no sense, but it is what x86 hardware
		** does so for compatibility we will do the same in software. */
		return minInt;
	} else {
		return (sxi64)r;
	}
}
/*
 * Convert a raw token value typically a stream of digit [i.e: hex,octal,binary or decimal]
 * to a 64-bit integer.
 */
PH7_PRIVATE sxi64 PH7_TokenValueToInt64(SyString *pVal) {
	sxi64 iVal = 0;
	if(pVal->nByte <= 0) {
		return 0;
	}
	if(pVal->zString[0] == '0') {
		sxi32 c;
		if(pVal->nByte == sizeof(char)) {
			return 0;
		}
		c = pVal->zString[1];
		if(c  == 'x' || c == 'X') {
			/* Hex digit stream */
			SyHexStrToInt64(pVal->zString, pVal->nByte, (void *)&iVal, 0);
		} else if(c == 'b' || c == 'B') {
			/* Binary digit stream */
			SyBinaryStrToInt64(pVal->zString, pVal->nByte, (void *)&iVal, 0);
		} else {
			/* Octal digit stream */
			SyOctalStrToInt64(pVal->zString, pVal->nByte, (void *)&iVal, 0);
		}
	} else {
		/* Decimal digit stream */
		SyStrToInt64(pVal->zString, pVal->nByte, (void *)&iVal, 0);
	}
	return iVal;
}
/*
 * Return some kind of 64-bit integer value which is the best we can
 * do at representing the value that pObj describes as a string
 * representation.
 */
static sxi64 MemObjStringToInt(ph7_value *pObj) {
	SyString sVal;
	SyStringInitFromBuf(&sVal, SyBlobData(&pObj->sBlob), SyBlobLength(&pObj->sBlob));
	return PH7_TokenValueToInt64(&sVal);
}
/*
 * Call a magic class method [i.e: __toString(),__toInt(),...]
 * Return SXRET_OK if the magic method is available and have been
 * successfully called. Any other return value indicates failure.
 */
static sxi32 MemObjCallClassCastMethod(
	ph7_vm *pVm,               /* VM that trigger the invocation */
	ph7_class_instance *pThis, /* Target class instance [i.e: Object] */
	const char *zMethod,       /* Magic method name [i.e: __toString] */
	sxu32 nLen,                /* Method name length */
	ph7_value *pResult         /* OUT: Store the return value of the magic method here */
) {
	ph7_class_method *pMethod = 0;
	/* Check if the method is available */
	if(pThis) {
		pMethod = PH7_ClassExtractMethod(pThis->pClass, zMethod, nLen);
	}
	if(pMethod == 0) {
		/* No such method */
		return SXERR_NOTFOUND;
	}
	/* Invoke the desired method */
	PH7_VmCallClassMethod(&(*pVm), &(*pThis), pMethod, &(*pResult), 0, 0);
	/* Method successfully called,pResult should hold the return value */
	return SXRET_OK;
}
/*
 * Return some kind of integer value which is the best we can
 * do at representing the value that pObj describes as an integer.
 * If pObj is an integer, then the value is exact. If pObj is
 * a floating-point then  the value returned is the integer part.
 * If pObj is a string, then we make an attempt to convert it into
 * a integer and return that.
 * If pObj represents a NULL value, return 0.
 */
static sxi64 MemObjIntValue(ph7_value *pObj) {
	sxi32 nType;
	nType = pObj->nType;
	if(nType & MEMOBJ_REAL) {
		return MemObjRealToInt(&(*pObj));
	} else if(nType & (MEMOBJ_INT | MEMOBJ_BOOL | MEMOBJ_CHAR)) {
		return pObj->x.iVal;
	} else if(nType & MEMOBJ_STRING) {
		return MemObjStringToInt(&(*pObj));
	} else if(nType & (MEMOBJ_CALL | MEMOBJ_NULL | MEMOBJ_VOID)) {
		return 0;
	} else if(nType & MEMOBJ_HASHMAP) {
		ph7_hashmap *pMap = (ph7_hashmap *)pObj->x.pOther;
		sxu32 n = pMap->nEntry;
		PH7_HashmapUnref(pMap);
		/* Return total number of entries in the hashmap */
		return n;
	} else if(nType & MEMOBJ_OBJ) {
		ph7_value sResult;
		sxi64 iVal = 1;
		sxi32 rc;
		/* Invoke the [__toInt()] magic method if available [note that this is a symisc extension]  */
		PH7_MemObjInit(pObj->pVm, &sResult);
		rc = MemObjCallClassCastMethod(pObj->pVm, (ph7_class_instance *)pObj->x.pOther,
									   "__toInt", sizeof("__toInt") - 1, &sResult);
		if(rc == SXRET_OK && (sResult.nType & MEMOBJ_INT)) {
			/* Extract method return value */
			iVal = sResult.x.iVal;
		}
		PH7_ClassInstanceUnref((ph7_class_instance *)pObj->x.pOther);
		PH7_MemObjRelease(&sResult);
		return iVal;
	} else if(nType & MEMOBJ_RES) {
		return pObj->x.pOther != 0;
	}
	/* CANT HAPPEN */
	return 0;
}
/*
 * Return some kind of real value which is the best we can
 * do at representing the value that pObj describes as a real.
 * If pObj is a real, then the value is exact.If pObj is an
 * integer then the integer  is promoted to real and that value
 * is returned.
 * If pObj is a string, then we make an attempt to convert it
 * into a real and return that.
 * If pObj represents a NULL value, return 0.0
 */
static ph7_real MemObjRealValue(ph7_value *pObj) {
	sxi32 nType;
	nType = pObj->nType;
	if(nType & MEMOBJ_REAL) {
		return pObj->x.rVal;
	} else if(nType & (MEMOBJ_INT | MEMOBJ_BOOL | MEMOBJ_CHAR)) {
		return (ph7_real)pObj->x.iVal;
	} else if(nType & MEMOBJ_STRING) {
		SyString sString;
		ph7_real rVal = 0.0;
		SyStringInitFromBuf(&sString, SyBlobData(&pObj->sBlob), SyBlobLength(&pObj->sBlob));
		if(SyBlobLength(&pObj->sBlob) > 0) {
			/* Convert as much as we can */
			SyStrToReal(sString.zString, sString.nByte, (void *)&rVal, 0);
		}
		return rVal;
	} else if(nType & (MEMOBJ_CALL | MEMOBJ_NULL | MEMOBJ_VOID)) {
		return 0.0;
	} else if(nType & MEMOBJ_HASHMAP) {
		/* Return the total number of entries in the hashmap */
		ph7_hashmap *pMap = (ph7_hashmap *)pObj->x.pOther;
		ph7_real n = (ph7_real)pMap->nEntry;
		PH7_HashmapUnref(pMap);
		return n;
	} else if(nType & MEMOBJ_OBJ) {
		ph7_value sResult;
		ph7_real rVal = 1;
		sxi32 rc;
		/* Invoke the [__toFloat()] magic method if available [note that this is a symisc extension]  */
		PH7_MemObjInit(pObj->pVm, &sResult);
		rc = MemObjCallClassCastMethod(pObj->pVm, (ph7_class_instance *)pObj->x.pOther,
									   "__toFloat", sizeof("__toFloat") - 1, &sResult);
		if(rc == SXRET_OK && (sResult.nType & MEMOBJ_REAL)) {
			/* Extract method return value */
			rVal = sResult.x.rVal;
		}
		PH7_ClassInstanceUnref((ph7_class_instance *)pObj->x.pOther);
		PH7_MemObjRelease(&sResult);
		return rVal;
	} else if(nType & MEMOBJ_RES) {
		return (ph7_real)(pObj->x.pOther != 0);
	}
	/* NOT REACHED  */
	return 0;
}
/*
 * Return the string representation of a given ph7_value.
 * This function never fail and always return SXRET_OK.
 */
static sxi32 MemObjStringValue(SyBlob *pOut, ph7_value *pObj, sxu8 bStrictBool) {
	if(pObj->nType & MEMOBJ_REAL) {
		SyBlobFormat(&(*pOut), "%.15g", pObj->x.rVal);
	} else if(pObj->nType & MEMOBJ_INT) {
		SyBlobFormat(&(*pOut), "%qd", pObj->x.iVal);
		/* %qd (BSD quad) is equivalent to %lld in the libc printf */
	} else if(pObj->nType & MEMOBJ_BOOL) {
		if(pObj->x.iVal) {
			SyBlobAppend(&(*pOut), "TRUE", sizeof("TRUE") - 1);
		} else {
			if(!bStrictBool) {
				SyBlobAppend(&(*pOut), "FALSE", sizeof("FALSE") - 1);
			}
		}
	} else if(pObj->nType & MEMOBJ_CHAR) {
		if(pObj->x.iVal > 0) {
			SyBlobFormat(&(*pOut), "%c", pObj->x.iVal);
		}
	} else if(pObj->nType & MEMOBJ_HASHMAP) {
		SyBlobAppend(&(*pOut), "Array", sizeof("Array") - 1);
		PH7_HashmapUnref((ph7_hashmap *)pObj->x.pOther);
	} else if(pObj->nType & MEMOBJ_OBJ) {
		ph7_value sResult;
		sxi32 rc;
		/* Invoke the __toString() method if available */
		PH7_MemObjInit(pObj->pVm, &sResult);
		rc = MemObjCallClassCastMethod(pObj->pVm, (ph7_class_instance *)pObj->x.pOther,
									   "__toString", sizeof("__toString") - 1, &sResult);
		if(rc == SXRET_OK && (sResult.nType & MEMOBJ_STRING) && SyBlobLength(&sResult.sBlob) > 0) {
			/* Expand method return value */
			SyBlobDup(&sResult.sBlob, pOut);
		} else {
			/* Expand "Object" as requested by the PHP language reference manual */
			SyBlobAppend(&(*pOut), "Object", sizeof("Object") - 1);
		}
		PH7_ClassInstanceUnref((ph7_class_instance *)pObj->x.pOther);
		PH7_MemObjRelease(&sResult);
	} else if(pObj->nType & MEMOBJ_RES) {
		SyBlobFormat(&(*pOut), "ResourceID_%#x", pObj->x.pOther);
	}
	return SXRET_OK;
}
/*
 * Return some kind of boolean value which is the best we can do
 * at representing the value that pObj describes as a boolean.
 * When converting to boolean, the following values are considered FALSE:
 * NULL
 * the boolean FALSE itself.
 * the integer 0 (zero).
 * the real 0.0 (zero).
 * the empty string,a stream of zero [i.e: "0","00","000",...] and the string
 * "false".
 * an array with zero elements.
 */
static sxi32 MemObjBooleanValue(ph7_value *pObj) {
	sxi32 nType;
	nType = pObj->nType;
	if(nType & MEMOBJ_REAL) {
		return pObj->x.rVal != 0.0 ? 1 : 0;
	} else if(nType & (MEMOBJ_INT | MEMOBJ_CHAR)) {
		return pObj->x.iVal ? 1 : 0;
	} else if(nType & MEMOBJ_STRING) {
		SyString sString;
		SyStringInitFromBuf(&sString, SyBlobData(&pObj->sBlob), SyBlobLength(&pObj->sBlob));
		if(sString.nByte == 0) {
			/* Empty string */
			return 0;
		} else if((sString.nByte == sizeof("true") - 1 && SyStrnicmp(sString.zString, "true", sizeof("true") - 1) == 0) ||
				  (sString.nByte == sizeof("on") - 1 && SyStrnicmp(sString.zString, "on", sizeof("on") - 1) == 0) ||
				  (sString.nByte == sizeof("yes") - 1 && SyStrnicmp(sString.zString, "yes", sizeof("yes") - 1) == 0)) {
			return 1;
		} else if(sString.nByte == sizeof("false") - 1 && SyStrnicmp(sString.zString, "false", sizeof("false") - 1) == 0) {
			return 0;
		} else {
			const char *zIn, *zEnd;
			zIn = sString.zString;
			zEnd = &zIn[sString.nByte];
			while(zIn < zEnd && zIn[0] == '0') {
				zIn++;
			}
			return zIn >= zEnd ? 0 : 1;
		}
	} else if(nType & MEMOBJ_CALL) {
		SyString sString;
		SyStringInitFromBuf(&sString, SyBlobData(&pObj->sBlob), SyBlobLength(&pObj->sBlob));
		if(sString.nByte == 0) {
			/* Empty string */
			return 0;
		} else {
			/* Something set, return true */
			return 1;
		}
	} else if(nType & (MEMOBJ_NULL | MEMOBJ_VOID)) {
		return 0;
	} else if(nType & MEMOBJ_HASHMAP) {
		ph7_hashmap *pMap = (ph7_hashmap *)pObj->x.pOther;
		sxu32 n = pMap->nEntry;
		PH7_HashmapUnref(pMap);
		return n > 0 ? TRUE : FALSE;
	} else if(nType & MEMOBJ_OBJ) {
		ph7_value sResult;
		sxi32 iVal = 1;
		sxi32 rc;
		if(!pObj->x.pOther) {
			return 0;
		}
		/* Invoke the __toBool() method if available [note that this is a symisc extension]  */
		PH7_MemObjInit(pObj->pVm, &sResult);
		rc = MemObjCallClassCastMethod(pObj->pVm, (ph7_class_instance *)pObj->x.pOther,
									   "__toBool", sizeof("__toBool") - 1, &sResult);
		if(rc == SXRET_OK && (sResult.nType & (MEMOBJ_INT | MEMOBJ_BOOL))) {
			/* Extract method return value */
			iVal = (sxi32)(sResult.x.iVal != 0); /* Stupid cc warning -W -Wall -O6 */
		}
		PH7_ClassInstanceUnref((ph7_class_instance *)pObj->x.pOther);
		PH7_MemObjRelease(&sResult);
		return iVal;
	} else if(nType & MEMOBJ_RES) {
		return pObj->x.pOther != 0;
	}
	/* NOT REACHED */
	return 0;
}
/*
 * Return the char representation of a given ph7_value.
 * This function never fail and always return SXRET_OK.
 */
static ph7_real MemObjCharValue(ph7_value *pObj) {
	sxi32 nType;
	nType = pObj->nType;
	if(nType & (MEMOBJ_CALL | MEMOBJ_REAL | MEMOBJ_HASHMAP | MEMOBJ_RES | MEMOBJ_NULL | MEMOBJ_VOID)) {
		return 0;
	} else if(nType & MEMOBJ_INT) {
		return pObj->x.iVal;
	} else if(nType & MEMOBJ_STRING) {
		SyString sString;
		SyStringInitFromBuf(&sString, SyBlobData(&pObj->sBlob), SyBlobLength(&pObj->sBlob));
		if(sString.nByte == 0) {
			/* Empty string */
			return 0;
		}
		return (int) sString.zString[0];
	}
	/* NOT REACHED */
	return 0;
}
/*
 * Checks a ph7_value variable compatibility with nType data type.
 */
PH7_PRIVATE sxi32 PH7_CheckVarCompat(ph7_value *pObj, int nType) {
	if(((nType & MEMOBJ_HASHMAP) == 0) && ((pObj->nType & MEMOBJ_HASHMAP) == 0)) {
		if(pObj->nType & MEMOBJ_NULL) {
			/* Always allow to store a NULL */
			return SXRET_OK;
		} else if((nType & MEMOBJ_REAL) && (pObj->nType & MEMOBJ_INT)) {
			/* Allow to store INT to FLOAT variable */
			return SXRET_OK;
		} else if((nType & MEMOBJ_CHAR) && (pObj->nType & MEMOBJ_INT)) {
			/* Allow to store INT to CHAR variable */
			return SXRET_OK;
		} else if((nType & MEMOBJ_STRING) && (pObj->nType & MEMOBJ_CHAR)) {
			/* Allow to store CHAR to STRING variable */
			return SXRET_OK;
		} else if((nType & MEMOBJ_CHAR) && (pObj->nType & MEMOBJ_STRING)) {
			/* Allow to store STRING to CHAR variable (if not too long) */
			int len = SyBlobLength(&pObj->sBlob);
			if(len == 0 || len == 1) {
				return SXRET_OK;
			}
		} else if((nType & MEMOBJ_CALL) && (pObj->nType & MEMOBJ_STRING)) {
			/* Allow to store STRING to CALLBACK variable */
			return SXRET_OK;
		}
	}
	return SXERR_NOMATCH;
}
/*
 * Duplicate safely the contents of a ph7_value if source and
 * destination are of the compatible data types.
 */
PH7_PRIVATE sxi32 PH7_MemObjSafeStore(ph7_value *pSrc, ph7_value *pDest) {
	if(pDest->nType == 0 || pDest->nType == MEMOBJ_NULL || pDest->nType == pSrc->nType) {
		PH7_MemObjStore(pSrc, pDest);
		if(pDest->nType == 0 || pDest->nType == MEMOBJ_NULL) {
			if(pSrc->nType == MEMOBJ_NULL) {
				pDest->nType = MEMOBJ_VOID;
			} else {
				pDest->nType = pSrc->nType;
			}
		}
	} else if(pDest->nType & MEMOBJ_MIXED) {
		if(pDest->nType & MEMOBJ_HASHMAP) {
			/* mixed[] */
			if(pSrc->nType & MEMOBJ_HASHMAP) {
				PH7_MemObjStore(pSrc, pDest);
				pDest->nType |= MEMOBJ_MIXED;
			} else if(pSrc->nType & MEMOBJ_NULL) {
				PH7_MemObjToHashmap(pSrc);
				MemObjSetType(pSrc, pDest->nType);
				PH7_MemObjStore(pSrc, pDest);
			} else {
				return SXERR_NOMATCH;
			}
		} else {
			/* mixed */
			if(pSrc->nType == MEMOBJ_NULL) {
				MemObjSetType(pDest, MEMOBJ_MIXED | MEMOBJ_VOID);
			} else if((pSrc->nType & MEMOBJ_HASHMAP) == 0) {
				PH7_MemObjStore(pSrc, pDest);
				pDest->nType |= MEMOBJ_MIXED;
			} else {
				return SXERR_NOMATCH;
			}
		}
	} else if((pDest->nType & MEMOBJ_HASHMAP)) {
		/* [] */
		if(pSrc->nType & MEMOBJ_NULL) {
			PH7_MemObjToHashmap(pSrc);
			MemObjSetType(pSrc, pDest->nType);
			PH7_MemObjStore(pSrc, pDest);
		} else if(pSrc->nType & MEMOBJ_HASHMAP) {
			if(PH7_HashmapCast(pSrc, pDest->nType ^ MEMOBJ_HASHMAP) != SXRET_OK) {
				return SXERR_NOMATCH;
			}
			PH7_MemObjStore(pSrc, pDest);
		} else {
			return SXERR_NOMATCH;
		}
	} else if(PH7_CheckVarCompat(pSrc, pDest->nType) == SXRET_OK) {
		ProcMemObjCast xCast = PH7_MemObjCastMethod(pDest->nType);
		xCast(pSrc);
		PH7_MemObjStore(pSrc, pDest);
	} else {
		return SXERR_NOMATCH;
	}
	return SXRET_OK;
}
/*
 * Convert a ph7_value to type integer.Invalidate any prior representations.
 */
PH7_PRIVATE sxi32 PH7_MemObjToInteger(ph7_value *pObj) {
	if((pObj->nType & MEMOBJ_INT) == 0) {
		/* Preform the conversion */
		pObj->x.iVal = MemObjIntValue(&(*pObj));
		/* Invalidate any prior representations */
		SyBlobRelease(&pObj->sBlob);
		MemObjSetType(pObj, MEMOBJ_INT);
	}
	return SXRET_OK;
}
/*
 * Convert a ph7_value to type real (Try to get an integer representation also).
 * Invalidate any prior representations
 */
PH7_PRIVATE sxi32 PH7_MemObjToReal(ph7_value *pObj) {
	if((pObj->nType & MEMOBJ_REAL) == 0) {
		/* Preform the conversion */
		pObj->x.rVal = MemObjRealValue(&(*pObj));
		/* Invalidate any prior representations */
		SyBlobRelease(&pObj->sBlob);
		MemObjSetType(pObj, MEMOBJ_REAL);
	}
	return SXRET_OK;
}
/*
 * Convert a ph7_value to type boolean.Invalidate any prior representations.
 */
PH7_PRIVATE sxi32 PH7_MemObjToBool(ph7_value *pObj) {
	if((pObj->nType & MEMOBJ_BOOL) == 0) {
		/* Preform the conversion */
		pObj->x.iVal = MemObjBooleanValue(&(*pObj));
		/* Invalidate any prior representations */
		SyBlobRelease(&pObj->sBlob);
		MemObjSetType(pObj, MEMOBJ_BOOL);
	}
	return SXRET_OK;
}
PH7_PRIVATE sxi32 PH7_MemObjToChar(ph7_value *pObj) {
	if((pObj->nType & MEMOBJ_CHAR) == 0) {
		/* Preform the conversion */
		pObj->x.iVal = MemObjCharValue(&(*pObj));
		/* Invalidate any prior representations */
		SyBlobRelease(&pObj->sBlob);
		MemObjSetType(pObj, MEMOBJ_CHAR);
	}
	return SXRET_OK;
}
/*
 * Convert a ph7_value to type void.Invalidate any prior representations.
 */
PH7_PRIVATE sxi32 PH7_MemObjToVoid(ph7_value *pObj) {
	if((pObj->nType & MEMOBJ_VOID) == 0) {
		PH7_MemObjRelease(pObj);
		MemObjSetType(pObj, MEMOBJ_VOID);
	}
	return SXRET_OK;
}
PH7_PRIVATE sxi32 PH7_MemObjToCallback(ph7_value *pObj) {
	sxi32 rc = SXRET_OK;
	if((pObj->nType & (MEMOBJ_CALL | MEMOBJ_STRING)) == 0) {
		SyBlobReset(&pObj->sBlob); /* Reset the internal buffer */
		rc = MemObjStringValue(&pObj->sBlob, &(*pObj), TRUE);
	}
	MemObjSetType(pObj, MEMOBJ_CALL);
	return rc;
}
PH7_PRIVATE sxi32 PH7_MemObjToResource(ph7_value *pObj) {
	sxi32 rc = SXRET_OK;
	if((pObj->nType & MEMOBJ_NULL) == 0) {
		PH7_VmThrowError(&(*pObj->pVm), PH7_CTX_WARNING, "Unsafe type casting condition, assuming default value");
	}
	if((pObj->nType & MEMOBJ_RES) == 0) {
		pObj->x.iVal = 0;
	}
	MemObjSetType(pObj, MEMOBJ_RES);
	return rc;
}
/*
 * Convert a ph7_value to type string.Prior representations are NOT invalidated.
 */
PH7_PRIVATE sxi32 PH7_MemObjToString(ph7_value *pObj) {
	sxi32 rc = SXRET_OK;
	if((pObj->nType & MEMOBJ_STRING) == 0) {
		if((pObj->nType & MEMOBJ_CALL) == 0) {
			/* Perform the conversion */
			SyBlobReset(&pObj->sBlob); /* Reset the internal buffer */
			rc = MemObjStringValue(&pObj->sBlob, &(*pObj), TRUE);
		}
		MemObjSetType(pObj, MEMOBJ_STRING);
	}
	return rc;
}
/*
 * Convert a ph7_value to type array.Invalidate any prior representations.
  * According to the PHP language reference manual.
  *   For any of the types: integer, float, string, boolean converting a value
  *   to an array results in an array with a single element with index zero
  *   and the value of the scalar which was converted.
  */
PH7_PRIVATE sxi32 PH7_MemObjToHashmap(ph7_value *pObj) {
	if((pObj->nType & MEMOBJ_HASHMAP) == 0) {
		ph7_hashmap *pMap;
		/* Allocate a new hashmap instance */
		pMap = PH7_NewHashmap(pObj->pVm, 0, 0);
		if(pMap == 0) {
			return SXERR_MEM;
		}
		if((pObj->nType & (MEMOBJ_NULL | MEMOBJ_RES)) == 0) {
			/*
			 * According to the PHP language reference manual.
			 *   For any of the types: integer, float, string, boolean converting a value
			 *   to an array results in an array with a single element with index zero
			 *   and the value of the scalar which was converted.
			 */
			if(pObj->nType & MEMOBJ_OBJ) {
				/* Object cast */
				PH7_ClassInstanceToHashmap((ph7_class_instance *)pObj->x.pOther, pMap);
			} else {
				/* Insert a single element */
				PH7_HashmapInsert(pMap, 0/* Automatic index assign */, &(*pObj));
			}
			SyBlobRelease(&pObj->sBlob);
		}
		/* Invalidate any prior representation */
		MemObjSetType(pObj, MEMOBJ_HASHMAP);
		pObj->x.pOther = pMap;
	}
	return SXRET_OK;
}
/*
 * Convert a ph7_value to type object.Invalidate any prior representations.
 * The new object is instantiated from the builtin stdClass().
 * The stdClass() class have a single attribute which is '$value'. This attribute
 * hold a copy of the converted ph7_value.
 * The internal of the stdClass is as follows:
 * class stdClass{
 *	 public $value;
 *	 public function __toInt(){ return (int)$this->value; }
 *	 public function __toBool(){ return (bool)$this->value; }
 *	 public function __toFloat(){ return (float)$this->value; }
 *	 public function __toString(){ return (string)$this->value; }
 *	 function __construct($v){ $this->value = $v; }"
 *  }
 * Refer to the official documentation for more information.
 */
PH7_PRIVATE sxi32 PH7_MemObjToObject(ph7_value *pObj) {
	if(pObj->nType & MEMOBJ_NULL) {
		/* Invalidate any prior representation */
		PH7_MemObjRelease(pObj);
		/* Typecast the value */
		MemObjSetType(pObj, MEMOBJ_OBJ);
	} else if((pObj->nType & MEMOBJ_OBJ) == 0) {
		ph7_class_instance *pStd;
		ph7_class_method *pCons;
		ph7_class *pClass;
		ph7_vm *pVm;
		/* Point to the underlying VM */
		pVm = pObj->pVm;
		/* Point to the stdClass() */
		pClass = PH7_VmExtractClass(pVm, "stdClass", sizeof("stdClass") - 1, TRUE);
		if(pClass == 0) {
			/* Can't happen,load null instead */
			PH7_MemObjRelease(pObj);
			return SXRET_OK;
		}
		/* Instantiate a new stdClass() object */
		pStd = PH7_NewClassInstance(pVm, pClass);
		if(pStd == 0) {
			/* Out of memory */
			PH7_MemObjRelease(pObj);
			return SXRET_OK;
		}
		/* Check if a constructor is available */
		pCons = PH7_ClassExtractMethod(pClass, "__construct", sizeof("__construct") - 1);
		if(pCons) {
			ph7_value *apArg[2];
			/* Invoke the constructor with one argument */
			apArg[0] = pObj;
			PH7_VmCallClassMethod(pVm, pStd, pCons, 0, 1, apArg);
			if(pStd->iRef < 1) {
				pStd->iRef = 1;
			}
		}
		/* Invalidate any prior representation */
		PH7_MemObjRelease(pObj);
		/* Save the new instance */
		pObj->x.pOther = pStd;
		MemObjSetType(pObj, MEMOBJ_OBJ);
	}
	return SXRET_OK;
}
/*
 * Return a pointer to the appropriate convertion method associated
 * with the given type.
 * Note on type juggling.
 * According to the PHP language reference manual
 *  PHP does not require (or support) explicit type definition in variable
 *  declaration; a variable's type is determined by the context in which
 *  the variable is used. That is to say, if a string value is assigned
 *  to variable $var, $var becomes a string. If an integer value is then
 *  assigned to $var, it becomes an integer.
 */
PH7_PRIVATE ProcMemObjCast PH7_MemObjCastMethod(sxi32 nType) {
	if(nType & MEMOBJ_STRING) {
		return PH7_MemObjToString;
	} else if(nType & MEMOBJ_INT) {
		return PH7_MemObjToInteger;
	} else if(nType & MEMOBJ_REAL) {
		return PH7_MemObjToReal;
	} else if(nType & MEMOBJ_BOOL) {
		return PH7_MemObjToBool;
	} else if(nType & MEMOBJ_CHAR) {
		return PH7_MemObjToChar;
	} else if(nType & MEMOBJ_OBJ) {
		return PH7_MemObjToObject;
	} else if(nType & MEMOBJ_CALL) {
		return PH7_MemObjToCallback;
	} else if(nType & MEMOBJ_RES) {
		return PH7_MemObjToResource;
	} else if(nType & MEMOBJ_VOID) {
		return PH7_MemObjToVoid;
	}
	/* Release the variable */
	return PH7_MemObjRelease;
}
/*
 *
 */
PH7_PRIVATE sxi32 PH7_MemObjIsNull(ph7_value *pObj) {
	if(pObj->nType & MEMOBJ_HASHMAP) {
		ph7_hashmap *pMap = (ph7_hashmap *)pObj->x.pOther;
		return pMap->nEntry == 0 ? TRUE : FALSE;
	} else if(pObj->nType & (MEMOBJ_NULL | MEMOBJ_VOID)) {
		return TRUE;
	} else if(pObj->nType & (MEMOBJ_CHAR | MEMOBJ_INT)) {
		return pObj->x.iVal == 0 ? TRUE : FALSE;
	} else if(pObj->nType & MEMOBJ_REAL) {
		return pObj->x.rVal == (ph7_real) 0 ? TRUE : FALSE;
	} else if(pObj->nType & MEMOBJ_BOOL) {
		return !pObj->x.iVal;
	} else if(pObj->nType & (MEMOBJ_OBJ | MEMOBJ_RES)) {
		return pObj->x.pOther == 0 ? TRUE : FALSE;
	} else if(pObj->nType & MEMOBJ_STRING) {
		if(SyBlobLength(&pObj->sBlob) <= 0) {
			return TRUE;
		} else {
			const char *zIn, *zEnd;
			zIn = (const char *)SyBlobData(&pObj->sBlob);
			zEnd = &zIn[SyBlobLength(&pObj->sBlob)];
			while(zIn < zEnd) {
				if(zIn[0] != '0') {
					break;
				}
				zIn++;
			}
			return zIn >= zEnd ? TRUE : FALSE;
		}
	}
	/* Assume empty by default */
	return TRUE;
}
/*
 * Check whether the ph7_value is numeric [i.e: int/float/bool] or looks
 * like a numeric number [i.e: if the ph7_value is of type string.].
 * Return TRUE if numeric.FALSE otherwise.
 */
PH7_PRIVATE sxi32 PH7_MemObjIsNumeric(ph7_value *pObj) {
	if(pObj->nType & (MEMOBJ_INT | MEMOBJ_REAL)) {
		return TRUE;
	}
	return FALSE;
}
/*
 * Convert a ph7_value so that it has types MEMOBJ_REAL or MEMOBJ_INT
 * or both.
 * Invalidate any prior representations. Every effort is made to force
 * the conversion, even if the input is a string that does not look
 * completely like a number.Convert as much of the string as we can
 * and ignore the rest.
 */
PH7_PRIVATE sxi32 PH7_MemObjToNumeric(ph7_value *pObj) {
	if(pObj->nType & (MEMOBJ_INT | MEMOBJ_REAL | MEMOBJ_BOOL | MEMOBJ_NULL)) {
		if(pObj->nType & (MEMOBJ_BOOL | MEMOBJ_NULL | MEMOBJ_VOID)) {
			if(pObj->nType & (MEMOBJ_CALL | MEMOBJ_NULL | MEMOBJ_VOID)) {
				pObj->x.iVal = 0;
			}
			MemObjSetType(pObj, MEMOBJ_INT);
		}
		/* Already numeric */
		return  SXRET_OK;
	}
	if(pObj->nType & MEMOBJ_STRING) {
		sxi32 rc = SXERR_INVALID;
		sxu8 bReal = FALSE;
		SyString sString;
		SyStringInitFromBuf(&sString, SyBlobData(&pObj->sBlob), SyBlobLength(&pObj->sBlob));
		/* Check if the given string looks like a numeric number */
		if(sString.nByte > 0) {
			rc = SyStrIsNumeric(sString.zString, sString.nByte, &bReal, 0);
		}
		if(bReal) {
			PH7_MemObjToReal(&(*pObj));
		} else {
			if(rc != SXRET_OK) {
				/* The input does not look at all like a number,set the value to 0 */
				pObj->x.iVal = 0;
			} else {
				/* Convert as much as we can */
				pObj->x.iVal = MemObjStringToInt(&(*pObj));
			}
			MemObjSetType(pObj, MEMOBJ_INT);
			SyBlobRelease(&pObj->sBlob);
		}
	} else if(pObj->nType & (MEMOBJ_OBJ | MEMOBJ_HASHMAP | MEMOBJ_RES)) {
		PH7_MemObjToInteger(pObj);
	} else {
		/* Perform a blind cast */
		PH7_MemObjToReal(&(*pObj));
	}
	return SXRET_OK;
}
/*
 * Initialize a ph7_value to the null type.
 */
PH7_PRIVATE sxi32 PH7_MemObjInit(ph7_vm *pVm, ph7_value *pObj) {
	/* Zero the structure */
	SyZero(pObj, sizeof(ph7_value));
	/* Initialize fields */
	pObj->pVm = pVm;
	SyBlobInit(&pObj->sBlob, &pVm->sAllocator);
	/* Set the NULL type */
	pObj->nType = MEMOBJ_NULL;
	return SXRET_OK;
}
/*
 * Initialize a ph7_value to the integer type.
 */
PH7_PRIVATE sxi32 PH7_MemObjInitFromInt(ph7_vm *pVm, ph7_value *pObj, sxi64 iVal) {
	/* Zero the structure */
	SyZero(pObj, sizeof(ph7_value));
	/* Initialize fields */
	pObj->pVm = pVm;
	SyBlobInit(&pObj->sBlob, &pVm->sAllocator);
	/* Set the desired type */
	pObj->x.iVal = iVal;
	pObj->nType = MEMOBJ_INT;
	return SXRET_OK;
}
/*
 * Initialize a ph7_value to the boolean type.
 */
PH7_PRIVATE sxi32 PH7_MemObjInitFromBool(ph7_vm *pVm, ph7_value *pObj, sxi32 iVal) {
	/* Zero the structure */
	SyZero(pObj, sizeof(ph7_value));
	/* Initialize fields */
	pObj->pVm = pVm;
	SyBlobInit(&pObj->sBlob, &pVm->sAllocator);
	/* Set the desired type */
	pObj->x.iVal = iVal ? 1 : 0;
	pObj->nType = MEMOBJ_BOOL;
	return SXRET_OK;
}
/*
 * Initialize a ph7_value to the real type.
 */
PH7_PRIVATE sxi32 PH7_MemObjInitFromReal(ph7_vm *pVm, ph7_value *pObj, ph7_real rVal) {
	/* Zero the structure */
	SyZero(pObj, sizeof(ph7_value));
	/* Initialize fields */
	pObj->pVm = pVm;
	SyBlobInit(&pObj->sBlob, &pVm->sAllocator);
	/* Set the desired type */
	pObj->x.rVal = rVal;
	pObj->nType = MEMOBJ_REAL;
	return SXRET_OK;
}
/*
 * Initialize a ph7_value to the void type.
 */
PH7_PRIVATE sxi32 PH7_MemObjInitFromVoid(ph7_vm *pVm, ph7_value *pObj) {
	/* Zero the structure */
	SyZero(pObj, sizeof(ph7_value));
	/* Initialize fields */
	pObj->pVm = pVm;
	SyBlobInit(&pObj->sBlob, &pVm->sAllocator);
	/* Set the desired type */
	pObj->nType = MEMOBJ_VOID;
	return SXRET_OK;
}/*
 * Initialize a ph7_value to the array type.
 */
PH7_PRIVATE sxi32 PH7_MemObjInitFromArray(ph7_vm *pVm, ph7_value *pObj, ph7_hashmap *pArray) {
	/* Zero the structure */
	SyZero(pObj, sizeof(ph7_value));
	/* Initialize fields */
	pObj->pVm = pVm;
	SyBlobInit(&pObj->sBlob, &pVm->sAllocator);
	/* Set the desired type */
	pObj->nType = MEMOBJ_HASHMAP;
	pObj->x.pOther = pArray;
	return SXRET_OK;
}
/*
 * Initialize a ph7_value to the string type.
 */
PH7_PRIVATE sxi32 PH7_MemObjInitFromString(ph7_vm *pVm, ph7_value *pObj, const SyString *pVal) {
	/* Zero the structure */
	SyZero(pObj, sizeof(ph7_value));
	/* Initialize fields */
	pObj->pVm = pVm;
	SyBlobInit(&pObj->sBlob, &pVm->sAllocator);
	if(pVal) {
		/* Append contents */
		SyBlobAppend(&pObj->sBlob, (const void *)pVal->zString, pVal->nByte);
	}
	/* Set the desired type */
	pObj->nType = MEMOBJ_STRING;
	return SXRET_OK;
}
/*
 * Append some contents to the internal buffer of a given ph7_value.
 * If the given ph7_value is not of type string,this function
 * invalidate any prior representation and set the string type.
 * Then a simple append operation is performed.
 */
PH7_PRIVATE sxi32 PH7_MemObjStringAppend(ph7_value *pObj, const char *zData, sxu32 nLen) {
	sxi32 rc;
	if((pObj->nType & MEMOBJ_STRING) == 0) {
		/* Invalidate any prior representation */
		PH7_MemObjRelease(pObj);
		MemObjSetType(pObj, MEMOBJ_STRING);
	}
	/* Append contents */
	rc = SyBlobAppend(&pObj->sBlob, zData, nLen);
	return rc;
}
/*
 * Format and append some contents to the internal buffer of a given ph7_value.
 * If the given ph7_value is not of type string,this function invalidate
 * any prior representation and set the string type.
 * Then a simple format and append operation is performed.
 */
PH7_PRIVATE sxi32 PH7_MemObjStringFormat(ph7_value *pObj, const char *zFormat, va_list ap) {
	sxi32 rc;
	if((pObj->nType & MEMOBJ_STRING) == 0) {
		/* Invalidate any prior representation */
		PH7_MemObjRelease(pObj);
		MemObjSetType(pObj, MEMOBJ_STRING);
	}
	/* Format and append contents */
	rc = SyBlobFormatAp(&pObj->sBlob, zFormat, ap);
	return rc;
}
/*
 * Duplicate the contents of a ph7_value.
 */
PH7_PRIVATE sxi32 PH7_MemObjStore(ph7_value *pSrc, ph7_value *pDest) {
	ph7_class_instance *pObj = 0;
	ph7_hashmap *pSrcMap = 0;
	sxi32 rc;
	if(pSrc->x.pOther) {
		if(pSrc->nType & MEMOBJ_HASHMAP) {
			/* Dump source hashmap */
			pSrcMap = (ph7_hashmap *)pSrc->x.pOther;
		} else if(pSrc->nType & MEMOBJ_OBJ) {
			/* Increment reference count */
			((ph7_class_instance *)pSrc->x.pOther)->iRef++;
		}
	}
	if(pDest->nType & MEMOBJ_OBJ) {
		pObj = (ph7_class_instance *)pDest->x.pOther;
	}
	SyMemcpy((const void *) & (*pSrc), &(*pDest), sizeof(ph7_value) - (sizeof(ph7_vm *) + sizeof(SyBlob) + sizeof(sxu32)));
	if(pSrcMap) {
		ph7_hashmap *pMap;
		pMap = PH7_NewHashmap(&(*pDest->pVm), 0, 0);
		PH7_HashmapDup(pSrcMap, pMap);
		pDest->x.pOther = pMap;
	}
	rc = SXRET_OK;
	if(SyBlobLength(&pSrc->sBlob) > 0) {
		SyBlobReset(&pDest->sBlob);
		rc = SyBlobDup(&pSrc->sBlob, &pDest->sBlob);
	} else {
		if(SyBlobLength(&pDest->sBlob) > 0) {
			SyBlobRelease(&pDest->sBlob);
		}
	}
	if(pObj) {
		PH7_ClassInstanceUnref(pObj);
	}
	return rc;
}
/*
 * Duplicate the contents of a ph7_value but do not copy internal
 * buffer contents,simply point to it.
 */
PH7_PRIVATE sxi32 PH7_MemObjLoad(ph7_value *pSrc, ph7_value *pDest) {
	SyMemcpy((const void *) & (*pSrc), &(*pDest),
			 sizeof(ph7_value) - (sizeof(ph7_vm *) + sizeof(SyBlob) + sizeof(sxu32)));
	if(pSrc->x.pOther) {
		if(pSrc->nType & MEMOBJ_HASHMAP) {
			/* Increment reference count */
			((ph7_hashmap *)pSrc->x.pOther)->iRef++;
		} else if(pSrc->nType & MEMOBJ_OBJ) {
			/* Increment reference count */
			((ph7_class_instance *)pSrc->x.pOther)->iRef++;
		}
	}
	if(SyBlobLength(&pDest->sBlob) > 0) {
		SyBlobRelease(&pDest->sBlob);
	}
	if(SyBlobLength(&pSrc->sBlob) > 0) {
		SyBlobReadOnly(&pDest->sBlob, SyBlobData(&pSrc->sBlob), SyBlobLength(&pSrc->sBlob));
	}
	return SXRET_OK;
}
/*
 * Invalidate any prior representation of a given ph7_value.
 */
PH7_PRIVATE sxi32 PH7_MemObjRelease(ph7_value *pObj) {
	if((pObj->nType & MEMOBJ_NULL) == 0) {
		if(pObj->x.pOther) {
			if(pObj->nType & MEMOBJ_HASHMAP) {
				PH7_HashmapUnref((ph7_hashmap *)pObj->x.pOther);
			} else if(pObj->nType & MEMOBJ_OBJ) {
				PH7_ClassInstanceUnref((ph7_class_instance *)pObj->x.pOther);
			}
		}
		/* Release the internal buffer */
		SyBlobRelease(&pObj->sBlob);
		/* Invalidate any prior representation */
		pObj->nType = MEMOBJ_NULL;
	}
	return SXRET_OK;
}
/*
 * Compare two ph7_values.
 * Return 0 if the values are equals, > 0 if pObj1 is greater than pObj2
 * or < 0 if pObj2 is greater than pObj1.
 * Type comparison table taken from the PHP language reference manual.
 * Comparisons of $x with PHP functions Expression
 *              gettype() 	empty() 	is_null() 	isset() 	boolean : if($x)
 * $x = ""; 	string 	    TRUE 	FALSE 	TRUE 	FALSE
 * $x = null 	NULL 	    TRUE 	TRUE 	FALSE 	FALSE
 * var $x; 	    NULL 	TRUE 	TRUE 	FALSE 	FALSE
 * $x is undefined 	NULL 	TRUE 	TRUE 	FALSE 	FALSE
 *  $x = array(); 	array 	TRUE 	FALSE 	TRUE 	FALSE
 * $x = false; 	boolean 	TRUE 	FALSE 	TRUE 	FALSE
 * $x = true; 	boolean 	FALSE 	FALSE 	TRUE 	TRUE
 * $x = 1; 	    integer 	FALSE 	FALSE 	TRUE 	TRUE
 * $x = 42; 	integer 	FALSE 	FALSE 	TRUE 	TRUE
 * $x = 0; 	    integer 	TRUE 	FALSE 	TRUE 	FALSE
 * $x = -1; 	integer 	FALSE 	FALSE 	TRUE 	TRUE
 * $x = "1"; 	string 	FALSE 	FALSE 	TRUE 	TRUE
 * $x = "0"; 	string 	TRUE 	FALSE 	TRUE 	FALSE
 * $x = "-1"; 	string 	FALSE 	FALSE 	TRUE 	TRUE
 * $x = "php"; 	string 	FALSE 	FALSE 	TRUE 	TRUE
 * $x = "true"; string 	FALSE 	FALSE 	TRUE 	TRUE
 * $x = "false"; string 	FALSE 	FALSE 	TRUE 	TRUE
 *      Loose comparisons with ==
 * TRUE 	FALSE 	1 	0 	-1 	"1" 	"0" 	"-1" 	NULL 	array() 	"php" 	""
 * TRUE 	TRUE 	FALSE 	TRUE 	FALSE 	TRUE 	TRUE 	FALSE 	TRUE 	FALSE 	FALSE 	TRUE 	FALSE
 * FALSE 	FALSE 	TRUE 	FALSE 	TRUE 	FALSE 	FALSE 	TRUE 	FALSE 	TRUE 	TRUE 	FALSE 	TRUE
 * 1 	TRUE 	FALSE 	TRUE 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE
 * 0 	FALSE 	TRUE 	FALSE 	TRUE 	FALSE 	FALSE 	TRUE 	FALSE 	TRUE 	FALSE 	TRUE 	TRUE
 * -1 	TRUE 	FALSE 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE
 * "1" 	TRUE 	FALSE 	TRUE 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE
 * "0" 	FALSE 	TRUE 	FALSE 	TRUE 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE
 * "-1" 	TRUE 	FALSE 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE
 * NULL 	FALSE 	TRUE 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE 	TRUE 	TRUE 	FALSE 	TRUE
 * array() 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	TRUE 	TRUE 	FALSE 	FALSE
 * "php" 	TRUE 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	TRUE 	FALSE
 * "" 	FALSE 	TRUE 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	TRUE
 *    Strict comparisons with ===
 * TRUE 	FALSE 	1 	0 	-1 	"1" 	"0" 	"-1" 	NULL 	array() 	"php" 	""
 * TRUE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE
 * FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE
 * 1 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE
 * 0 	FALSE 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE
 * -1 	FALSE 	FALSE 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE
 * "1" 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE
 * "0" 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE
 * "-1" 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE 	FALSE
 * NULL 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE 	FALSE
 * array() 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	TRUE 	FALSE 	FALSE
 * "php" 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	TRUE 	FALSE
 * "" 	    FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	FALSE 	TRUE
 */
PH7_PRIVATE sxi32 PH7_MemObjCmp(ph7_value *pObj1, ph7_value *pObj2, int bStrict, int iNest) {
	sxi32 iComb;
	sxi32 rc;
	if(bStrict) {
		sxi32 iF1, iF2;
		/* Strict comparisons with === */
		iF1 = pObj1->nType;
		iF2 = pObj2->nType;
		if(iF1 != iF2) {
			/* Not of the same type */
			return 1;
		}
	}
	/* Combine flag together */
	iComb = pObj1->nType | pObj2->nType;
	if(iComb & (MEMOBJ_NULL | MEMOBJ_RES | MEMOBJ_BOOL)) {
		/* Convert to boolean: Keep in mind FALSE < TRUE */
		if((pObj1->nType & MEMOBJ_BOOL) == 0) {
			PH7_MemObjToBool(pObj1);
		}
		if((pObj2->nType & MEMOBJ_BOOL) == 0) {
			PH7_MemObjToBool(pObj2);
		}
		return (sxi32)((pObj1->x.iVal != 0) - (pObj2->x.iVal != 0));
	} else if(iComb & MEMOBJ_HASHMAP) {
		/* Hashmap aka 'array' comparison */
		if((pObj1->nType & MEMOBJ_HASHMAP) == 0) {
			/* Array is always greater */
			return -1;
		}
		if((pObj2->nType & MEMOBJ_HASHMAP) == 0) {
			/* Array is always greater */
			return 1;
		}
		/* Perform the comparison */
		rc = PH7_HashmapCmp((ph7_hashmap *)pObj1->x.pOther, (ph7_hashmap *)pObj2->x.pOther, bStrict);
		return rc;
	} else if(iComb & MEMOBJ_OBJ) {
		/* Object comparison */
		if((pObj1->nType & MEMOBJ_OBJ) == 0) {
			/* Object is always greater */
			return -1;
		}
		if((pObj2->nType & MEMOBJ_OBJ) == 0) {
			/* Object is always greater */
			return 1;
		}
		/* Perform the comparison */
		rc = PH7_ClassInstanceCmp((ph7_class_instance *)pObj1->x.pOther, (ph7_class_instance *)pObj2->x.pOther, bStrict, iNest);
		return rc;
	} else if(iComb & MEMOBJ_STRING) {
		SyString s1, s2;
		if(!bStrict) {
			/*
			 * According to the PHP language reference manual:
			 *
			 *  If you compare a number with a string or the comparison involves numerical
			 *  strings, then each string is converted to a number and the comparison
			 *  performed numerically.
			 */
			if(PH7_MemObjIsNumeric(pObj1)) {
				/* Perform a numeric comparison */
				goto Numeric;
			}
			if(PH7_MemObjIsNumeric(pObj2)) {
				/* Perform a numeric comparison */
				goto Numeric;
			}
		}
		/* Perform a strict string comparison.*/
		if((pObj1->nType & MEMOBJ_STRING) == 0) {
			PH7_MemObjToString(pObj1);
		}
		if((pObj2->nType & MEMOBJ_STRING) == 0) {
			PH7_MemObjToString(pObj2);
		}
		SyStringInitFromBuf(&s1, SyBlobData(&pObj1->sBlob), SyBlobLength(&pObj1->sBlob));
		SyStringInitFromBuf(&s2, SyBlobData(&pObj2->sBlob), SyBlobLength(&pObj2->sBlob));
		/*
		 * Strings are compared using memcmp(). If one value is an exact prefix of the
		 * other, then the shorter value is less than the longer value.
		 */
		rc = SyMemcmp((const void *)s1.zString, (const void *)s2.zString, SXMIN(s1.nByte, s2.nByte));
		if(rc == 0) {
			if(s1.nByte != s2.nByte) {
				rc = s1.nByte < s2.nByte ? -1 : 1;
			}
		}
		return rc;
	} else if(iComb & (MEMOBJ_INT | MEMOBJ_REAL)) {
Numeric:
		/* Perform a numeric comparison if one of the operand is numeric(integer or real) */
		if((pObj1->nType & (MEMOBJ_INT | MEMOBJ_REAL)) == 0) {
			PH7_MemObjToNumeric(pObj1);
		}
		if((pObj2->nType & (MEMOBJ_INT | MEMOBJ_REAL)) == 0) {
			PH7_MemObjToNumeric(pObj2);
		}
		if((pObj1->nType & pObj2->nType & MEMOBJ_INT) == 0) {
			ph7_real r1, r2;
			/* Compare as reals */
			if((pObj1->nType & MEMOBJ_REAL) == 0) {
				PH7_MemObjToReal(pObj1);
			}
			r1 = pObj1->x.rVal;
			if((pObj2->nType & MEMOBJ_REAL) == 0) {
				PH7_MemObjToReal(pObj2);
			}
			r2 = pObj2->x.rVal;
			if(r1 > r2) {
				return 1;
			} else if(r1 < r2) {
				return -1;
			}
			return 0;
		} else {
			/* Integer comparison */
			if(pObj1->x.iVal > pObj2->x.iVal) {
				return 1;
			} else if(pObj1->x.iVal < pObj2->x.iVal) {
				return -1;
			}
			return 0;
		}
	}
	/* NOT REACHED */
	return 0;
}
/*
 * Perform an addition operation of two ph7_values.
 * The reason this function is implemented here rather than 'vm.c'
 * is that the '+' operator is overloaded.
 * That is,the '+' operator is used for arithmetic operation and also
 * used for operation on arrays [i.e: union]. When used with an array
 * The + operator returns the right-hand array appended to the left-hand array.
 * For keys that exist in both arrays, the elements from the left-hand array
 * will be used, and the matching elements from the right-hand array will
 * be ignored.
 * This function take care of handling all the scenarios.
 */
PH7_PRIVATE sxi32 PH7_MemObjAdd(ph7_value *pObj1, ph7_value *pObj2, int bAddStore) {
	if(((pObj1->nType | pObj2->nType) & MEMOBJ_HASHMAP) == 0) {
		/* Arithemtic operation */
		PH7_MemObjToNumeric(pObj1);
		PH7_MemObjToNumeric(pObj2);
		if((pObj1->nType | pObj2->nType) & MEMOBJ_REAL) {
			/* Floating point arithmetic */
			ph7_real a, b;
			if((pObj1->nType & MEMOBJ_REAL) == 0) {
				PH7_MemObjToReal(pObj1);
			}
			if((pObj2->nType & MEMOBJ_REAL) == 0) {
				PH7_MemObjToReal(pObj2);
			}
			a = pObj1->x.rVal;
			b = pObj2->x.rVal;
			pObj1->x.rVal = a + b;
			MemObjSetType(pObj1, MEMOBJ_REAL);
		} else {
			/* Integer arithmetic */
			sxi64 a, b;
			a = pObj1->x.iVal;
			b = pObj2->x.iVal;
			pObj1->x.iVal = a + b;
			MemObjSetType(pObj1, MEMOBJ_INT);
		}
	} else {
		if((pObj1->nType | pObj2->nType) & MEMOBJ_HASHMAP) {
			ph7_hashmap *pMap;
			sxi32 rc;
			if(bAddStore) {
				/* Do not duplicate the hashmap,use the left one since its an add&store operation.
				 */
				if((pObj1->nType & MEMOBJ_HASHMAP) == 0) {
					/* Force a hashmap cast */
					rc = PH7_MemObjToHashmap(pObj1);
					if(rc != SXRET_OK) {
						PH7_VmMemoryError(pObj1->pVm);
					}
				}
				/* Point to the structure that describe the hashmap */
				pMap = (ph7_hashmap *)pObj1->x.pOther;
			} else {
				/* Create a new hashmap */
				pMap = PH7_NewHashmap(pObj1->pVm, 0, 0);
				if(pMap == 0) {
					PH7_VmMemoryError(pObj1->pVm);
				}
			}
			if(!bAddStore) {
				if(pObj1->nType & MEMOBJ_HASHMAP) {
					/* Perform a hashmap duplication */
					PH7_HashmapDup((ph7_hashmap *)pObj1->x.pOther, pMap);
				} else {
					if((pObj1->nType & MEMOBJ_NULL) == 0) {
						/* Simple insertion */
						PH7_HashmapInsert(pMap, 0, pObj1);
					}
				}
			}
			/* Perform the union */
			if(pObj2->nType & MEMOBJ_HASHMAP) {
				PH7_HashmapUnion(pMap, (ph7_hashmap *)pObj2->x.pOther);
			} else {
				if((pObj2->nType & MEMOBJ_NULL) == 0) {
					/* Simple insertion */
					PH7_HashmapInsert(pMap, 0, pObj2);
				}
			}
			/* Reflect the change */
			if(pObj1->nType & MEMOBJ_STRING) {
				SyBlobRelease(&pObj1->sBlob);
			}
			pObj1->x.pOther = pMap;
			MemObjSetType(pObj1, MEMOBJ_HASHMAP);
		}
	}
	return SXRET_OK;
}
/*
 * Return a printable representation of the type of a given
 * ph7_value.
 */
PH7_PRIVATE const char *PH7_MemObjTypeDump(ph7_value *pVal) {
	const char *zType = "";
	if(pVal->nType & MEMOBJ_NULL) {
		zType = "NULL";
	} else {
	if(pVal->nType & MEMOBJ_HASHMAP) {
		if(pVal->nType & MEMOBJ_MIXED) {
			zType = "array(mixed, ";
		} else if(pVal->nType & MEMOBJ_OBJ) {
			zType = "array(object, ";
		} else if(pVal->nType & MEMOBJ_INT) {
			zType = "array(int, ";
		} else if(pVal->nType & MEMOBJ_REAL) {
			zType = "array(float, ";
		} else if(pVal->nType & MEMOBJ_STRING) {
			zType = "array(string, ";
		} else if(pVal->nType & MEMOBJ_BOOL) {
			zType = "array(bool, ";
		} else if(pVal->nType & MEMOBJ_CHAR) {
			zType = "array(char, ";
		} else if(pVal->nType & MEMOBJ_RES) {
			zType = "array(resource, ";
		} else if(pVal->nType & MEMOBJ_CALL) {
			zType = "array(callback, ";
		} else if(pVal->nType & MEMOBJ_VOID) {
			zType = "array(void, ";
		}
	} else if(pVal->nType & MEMOBJ_OBJ) {
		zType = "object";
	} else if(pVal->nType & MEMOBJ_INT) {
		zType = "int";
	} else if(pVal->nType & MEMOBJ_REAL) {
		zType = "float";
	} else if(pVal->nType & MEMOBJ_STRING) {
		zType = "string";
	} else if(pVal->nType & MEMOBJ_BOOL) {
		zType = "bool";
	} else if(pVal->nType & MEMOBJ_CHAR) {
		zType = "char";
	} else if(pVal->nType & MEMOBJ_RES) {
		zType = "resource";
	} else if(pVal->nType & MEMOBJ_CALL) {
		zType = "callback";
	} else if(pVal->nType & MEMOBJ_VOID) {
		zType = "void";
	}
	}
	return zType;
}
/*
 * Dump a ph7_value [i.e: get a printable representation of it's type and contents.].
 * Store the dump in the given blob.
 */
PH7_PRIVATE sxi32 PH7_MemObjDump(
	SyBlob *pOut,      /* Store the dump here */
	ph7_value *pObj,   /* Dump this */
	int ShowType,      /* TRUE to output value type */
	int nTab,          /* # of Whitespace to insert */
	int nDepth         /* Nesting level */
) {
	sxi32 rc = SXRET_OK;
	const char *zType;
	int i;
	for(i = 0 ; i < nTab ; i++) {
		SyBlobAppend(&(*pOut), " ", sizeof(char));
	}
	if(ShowType) {
		/* Get value type first */
		zType = PH7_MemObjTypeDump(pObj);
		SyBlobAppend(&(*pOut), zType, SyStrlen(zType));
	}
	if((pObj->nType & MEMOBJ_NULL) == 0) {
		if(ShowType && (pObj->nType & MEMOBJ_HASHMAP) == 0) {
			SyBlobAppend(&(*pOut), "(", sizeof(char));
		}
		if(pObj->nType & MEMOBJ_HASHMAP) {
			/* Dump hashmap entries */
			rc = PH7_HashmapDump(&(*pOut), (ph7_hashmap *)pObj->x.pOther, ShowType, nTab + 1, nDepth + 1);
		} else if(pObj->nType & MEMOBJ_OBJ) {
			/* Dump class instance attributes */
			rc = PH7_ClassInstanceDump(&(*pOut), (ph7_class_instance *)pObj->x.pOther, ShowType, nTab + 1, nDepth + 1);
		} else if(pObj->nType & MEMOBJ_VOID) {
			SyBlobAppend(&(*pOut), "NULL", sizeof("NULL") - 1);
		} else {
			SyBlob *pContents = &pObj->sBlob;
			/* Get a printable representation of the contents */
			if((pObj->nType & (MEMOBJ_STRING | MEMOBJ_CALL)) == 0) {
				MemObjStringValue(&(*pOut), &(*pObj), FALSE);
			} else {
				/* Append length first */
				if(ShowType) {
					SyBlobFormat(&(*pOut), "%u '", SyBlobLength(&pObj->sBlob));
				}
				if(SyBlobLength(pContents) > 0) {
					SyBlobAppend(&(*pOut), SyBlobData(pContents), SyBlobLength(pContents));
				}
				if(ShowType) {
					SyBlobAppend(&(*pOut), "'", sizeof(char));
				}
			}
		}
		if(ShowType) {
			if((pObj->nType & (MEMOBJ_HASHMAP | MEMOBJ_OBJ)) == 0) {
				SyBlobAppend(&(*pOut), ")", sizeof(char));
			}
		}
	}
#ifdef __WINNT__
	SyBlobAppend(&(*pOut), "\r\n", sizeof("\r\n") - 1);
#else
	SyBlobAppend(&(*pOut), "\n", sizeof(char));
#endif
	return rc;
}
