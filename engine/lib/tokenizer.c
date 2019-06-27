/**
 * @PROJECT     PH7 Engine for the AerScript Interpreter
 * @COPYRIGHT   See COPYING in the top level directory
 * @FILE        engine/lib/tokenizer.c
 * @DESCRIPTION PH7 Engine tokenizer
 * @DEVELOPERS  Symisc Systems <devel@symisc.net>
 *              Rafal Kupiec <belliash@codingworkshop.eu.org>
 */
#include "ph7int.h"

#define INVALID_LEXER(LEX)	(  LEX == 0  || LEX->xTokenizer == 0 )

PH7_PRIVATE sxi32 SyLexInit(SyLex *pLex, SySet *pSet, ProcTokenizer xTokenizer, void *pUserData) {
	SyStream *pStream;
	if(pLex == 0 || xTokenizer == 0) {
		return SXERR_CORRUPT;
	}
	pLex->pTokenSet = 0;
	/* Initialize lexer fields */
	if(pSet) {
		if(SySetElemSize(pSet) != sizeof(SyToken)) {
			return SXERR_INVALID;
		}
		pLex->pTokenSet = pSet;
	}
	pStream = &pLex->sStream;
	pLex->xTokenizer = xTokenizer;
	pLex->pUserData = pUserData;
	pStream->nLine = 1;
	pStream->nIgn  = 0;
	pStream->zText = pStream->zEnd = 0;
	pStream->pSet  = pSet;
	return SXRET_OK;
}
PH7_PRIVATE sxi32 SyLexTokenizeInput(SyLex *pLex, const char *zInput, sxu32 nLen, void *pCtxData, ProcSort xSort, ProcCmp xCmp) {
	const unsigned char *zCur;
	SyStream *pStream;
	SyToken sToken;
	sxi32 rc;
	if(INVALID_LEXER(pLex) || zInput == 0) {
		return SXERR_CORRUPT;
	}
	pStream = &pLex->sStream;
	/* Point to the head of the input */
	pStream->zText = pStream->zInput = (const unsigned char *)zInput;
	/* Point to the end of the input */
	pStream->zEnd = &pStream->zInput[nLen];
	for(;;) {
		if(pStream->zText >= pStream->zEnd) {
			/* End of the input reached */
			break;
		}
		zCur = pStream->zText;
		/* Call the tokenizer callback */
		rc = pLex->xTokenizer(pStream, &sToken, pLex->pUserData, pCtxData);
		if(rc != SXRET_OK && rc != SXERR_CONTINUE) {
			/* Tokenizer callback request an operation abort */
			if(rc == SXERR_ABORT) {
				return SXERR_ABORT;
			}
			break;
		}
		if(rc == SXERR_CONTINUE) {
			/* Request to ignore this token */
			pStream->nIgn++;
		} else if(pLex->pTokenSet) {
			/* Put the token in the set */
			rc = SySetPut(pLex->pTokenSet, (const void *)&sToken);
			if(rc != SXRET_OK) {
				break;
			}
		}
		if(zCur >= pStream->zText) {
			/* Automatic advance of the stream cursor */
			pStream->zText = &zCur[1];
		}
	}
	if(xSort &&  pLex->pTokenSet) {
		SyToken *aToken = (SyToken *)SySetBasePtr(pLex->pTokenSet);
		/* Sort the extrated tokens */
		if(xCmp == 0) {
			/* Use a default comparison function */
			xCmp = SyMemcmp;
		}
		xSort(aToken, SySetUsed(pLex->pTokenSet), sizeof(SyToken), xCmp);
	}
	return SXRET_OK;
}
PH7_PRIVATE sxi32 SyLexRelease(SyLex *pLex) {
	sxi32 rc = SXRET_OK;
	if(INVALID_LEXER(pLex)) {
		return SXERR_CORRUPT;
	}
	return rc;
}