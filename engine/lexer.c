/*
 * Symisc PH7: An embeddable bytecode compiler and a virtual machine for the PHP(5) programming language.
 * Copyright (C) 2011-2012, Symisc Systems http://ph7.symisc.net/
 * Version 2.1.4
 * For information on licensing,redistribution of this file,and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://ph7.symisc.net/
 */
/* $SymiscID: lex.c v2.8 Ubuntu-linux 2012-07-13 01:21 stable <chm@symisc.net> $ */
#include "ph7int.h"
/*
 * This file implement an efficient hand-coded,thread-safe and full-reentrant
 * lexical analyzer/Tokenizer for the PH7 engine.
 */
/* Forward declaration */
static sxu32 KeywordCode(const char *z, int n);
/*
 * Tokenize a raw PHP input.
 * Get a single low-level token from the input file. Update the stream pointer so that
 * it points to the first character beyond the extracted token.
 */
static sxi32 TokenizePHP(SyStream *pStream, SyToken *pToken, void *pUserData, void *pCtxData) {
	SyString *pStr;
	sxi32 rc;
	/* Ignore leading white spaces */
	while(pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisSpace(pStream->zText[0])) {
		/* Advance the stream cursor */
		if(pStream->zText[0] == '\n') {
			/* Update line counter */
			pStream->nLine++;
		}
		pStream->zText++;
	}
	if(pStream->zText >= pStream->zEnd) {
		/* End of input reached */
		return SXERR_EOF;
	}
	/* Record token starting position and line */
	pToken->nLine = pStream->nLine;
	pToken->pUserData = 0;
	pStr = &pToken->sData;
	SyStringInitFromBuf(pStr, pStream->zText, 0);
	if(pStream->zText[0] >= 0xc0 || SyisAlpha(pStream->zText[0]) || pStream->zText[0] == '_') {
		/* The following code fragment is taken verbatim from the xPP source tree.
		 * xPP is a modern embeddable macro processor with advanced features useful for
		 * application seeking for a production quality,ready to use macro processor.
		 * xPP is a widely used library developed and maintained by Symisc Systems.
		 * You can reach the xPP home page by following this link:
		 * http://xpp.symisc.net/
		 */
		const unsigned char *zIn;
		sxu32 nKeyword;
		/* Isolate UTF-8 or alphanumeric stream */
		if(pStream->zText[0] < 0xc0) {
			pStream->zText++;
		}
		for(;;) {
			zIn = pStream->zText;
			if(zIn[0] >= 0xc0) {
				zIn++;
				/* UTF-8 stream */
				while(zIn < pStream->zEnd && ((zIn[0] & 0xc0) == 0x80)) {
					zIn++;
				}
			}
			/* Skip alphanumeric stream */
			while(zIn < pStream->zEnd && zIn[0] < 0xc0 && (SyisAlphaNum(zIn[0]) || zIn[0] == '_')) {
				zIn++;
			}
			if(zIn == pStream->zText) {
				/* Not an UTF-8 or alphanumeric stream */
				break;
			}
			/* Synchronize pointers */
			pStream->zText = zIn;
		}
		/* Record token length */
		pStr->nByte = (sxu32)((const char *)pStream->zText - pStr->zString);
		nKeyword = KeywordCode(pStr->zString, (int)pStr->nByte);
		if(nKeyword != PH7_TK_ID) {
			if(nKeyword &
					(PH7_TKWRD_NEW | PH7_TKWRD_CLONE | PH7_TKWRD_INSTANCEOF)) {
				/* Alpha stream operators [i.e: new,clone,instanceof],save the operator instance for later processing */
				pToken->pUserData = (void *)PH7_ExprExtractOperator(pStr, 0);
				/* Mark as an operator */
				pToken->nType = PH7_TK_ID | PH7_TK_OP;
			} else {
				/* We are dealing with a keyword [i.e: while,foreach,class...],save the keyword ID */
				pToken->nType = PH7_TK_KEYWORD;
				pToken->pUserData = SX_INT_TO_PTR(nKeyword);
			}
		} else {
			/* A simple identifier */
			pToken->nType = PH7_TK_ID;
		}
	} else {
		sxi32 c;
		/* Non-alpha stream */
		if(pStream->zText[0] == '#' ||
				(pStream->zText[0] == '/' &&  &pStream->zText[1] < pStream->zEnd && pStream->zText[1] == '/')) {
			pStream->zText++;
			/* Inline comments */
			while(pStream->zText < pStream->zEnd && pStream->zText[0] != '\n') {
				pStream->zText++;
			}
			/* Tell the upper-layer to ignore this token */
			return SXERR_CONTINUE;
		} else if(pStream->zText[0] == '/' && &pStream->zText[1] < pStream->zEnd && pStream->zText[1] == '*') {
			pStream->zText += 2;
			/* Block comment */
			while(pStream->zText < pStream->zEnd) {
				if(pStream->zText[0] == '*') {
					if(&pStream->zText[1] >= pStream->zEnd || pStream->zText[1] == '/') {
						break;
					}
				}
				if(pStream->zText[0] == '\n') {
					pStream->nLine++;
				}
				pStream->zText++;
			}
			pStream->zText += 2;
			/* Tell the upper-layer to ignore this token */
			return SXERR_CONTINUE;
		} else if(SyisDigit(pStream->zText[0])) {
			pStream->zText++;
			/* Decimal digit stream */
			while(pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0])) {
				pStream->zText++;
			}
			/* Mark the token as integer until we encounter a real number */
			pToken->nType = PH7_TK_INTEGER;
			if(pStream->zText < pStream->zEnd) {
				c = pStream->zText[0];
				if(c == '.') {
					/* Real number */
					pStream->zText++;
					while(pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0])) {
						pStream->zText++;
					}
					if(pStream->zText < pStream->zEnd) {
						c = pStream->zText[0];
						if(c == 'e' || c == 'E') {
							pStream->zText++;
							if(pStream->zText < pStream->zEnd) {
								c = pStream->zText[0];
								if((c == '+' || c == '-') && &pStream->zText[1] < pStream->zEnd  &&
										pStream->zText[1] < 0xc0 && SyisDigit(pStream->zText[1])) {
									pStream->zText++;
								}
								while(pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0])) {
									pStream->zText++;
								}
							}
						}
					}
					pToken->nType = PH7_TK_REAL;
				} else if(c == 'e' || c == 'E') {
					SXUNUSED(pUserData); /* Prevent compiler warning */
					SXUNUSED(pCtxData);
					pStream->zText++;
					if(pStream->zText < pStream->zEnd) {
						c = pStream->zText[0];
						if((c == '+' || c == '-') && &pStream->zText[1] < pStream->zEnd  &&
								pStream->zText[1] < 0xc0 && SyisDigit(pStream->zText[1])) {
							pStream->zText++;
						}
						while(pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0])) {
							pStream->zText++;
						}
					}
					pToken->nType = PH7_TK_REAL;
				} else if(c == 'x' || c == 'X') {
					/* Hex digit stream */
					pStream->zText++;
					while(pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisHex(pStream->zText[0])) {
						pStream->zText++;
					}
				} else if(c  == 'b' || c == 'B') {
					/* Binary digit stream */
					pStream->zText++;
					while(pStream->zText < pStream->zEnd && (pStream->zText[0] == '0' || pStream->zText[0] == '1')) {
						pStream->zText++;
					}
				}
			}
			/* Record token length */
			pStr->nByte = (sxu32)((const char *)pStream->zText - pStr->zString);
			return SXRET_OK;
		}
		c = pStream->zText[0];
		pStream->zText++; /* Advance the stream cursor */
		/* Assume we are dealing with an operator*/
		pToken->nType = PH7_TK_OP;
		switch(c) {
			case '$':
				pToken->nType = PH7_TK_DOLLAR;
				break;
			case '{':
				pToken->nType = PH7_TK_OCB;
				break;
			case '}':
				pToken->nType = PH7_TK_CCB;
				break;
			case '(':
				pToken->nType = PH7_TK_LPAREN;
				break;
			case '[':
				pToken->nType |= PH7_TK_OSB;
				break; /* Bitwise operation here,since the square bracket token '['
														 * is a potential operator [i.e: subscripting] */
			case ']':
				pToken->nType = PH7_TK_CSB;
				break;
			case ')': {
					SySet *pTokSet = pStream->pSet;
					/* Assemble type cast operators [i.e: (int),(float),(bool)...] */
					if(pTokSet->nUsed >= 2) {
						SyToken *pTmp;
						/* Peek the last recognized token */
						pTmp = (SyToken *)SySetPeek(pTokSet);
						if(pTmp->nType & PH7_TK_KEYWORD) {
							sxi32 nID = SX_PTR_TO_INT(pTmp->pUserData);
							if((sxu32)nID & (PH7_TKWRD_ARRAY | PH7_TKWRD_INT | PH7_TKWRD_FLOAT | PH7_TKWRD_STRING | PH7_TKWRD_OBJECT | PH7_TKWRD_BOOL | PH7_TKWRD_UNSET)) {
								pTmp = (SyToken *)SySetAt(pTokSet, pTokSet->nUsed - 2);
								if(pTmp->nType & PH7_TK_LPAREN) {
									/* Merge the three tokens '(' 'TYPE' ')' into a single one */
									const char *zTypeCast = "(int)";
									if(nID & PH7_TKWRD_FLOAT) {
										zTypeCast = "(float)";
									} else if(nID & PH7_TKWRD_BOOL) {
										zTypeCast = "(bool)";
									} else if(nID & PH7_TKWRD_STRING) {
										zTypeCast = "(string)";
									} else if(nID & PH7_TKWRD_ARRAY) {
										zTypeCast = "(array)";
									} else if(nID & PH7_TKWRD_OBJECT) {
										zTypeCast = "(object)";
									} else if(nID & PH7_TKWRD_UNSET) {
										zTypeCast = "(unset)";
									}
									/* Reflect the change */
									pToken->nType = PH7_TK_OP;
									SyStringInitFromBuf(&pToken->sData, zTypeCast, SyStrlen(zTypeCast));
									/* Save the instance associated with the type cast operator */
									pToken->pUserData = (void *)PH7_ExprExtractOperator(&pToken->sData, 0);
									/* Remove the two previous tokens */
									pTokSet->nUsed -= 2;
									return SXRET_OK;
								}
							}
						}
					}
					pToken->nType = PH7_TK_RPAREN;
					break;
				}
			case '\'': {
					/* Single quoted string */
					pStr->zString++;
					while(pStream->zText < pStream->zEnd) {
						if(pStream->zText[0] == '\'') {
							if(pStream->zText[-1] != '\\') {
								break;
							} else {
								const unsigned char *zPtr = &pStream->zText[-2];
								sxi32 i = 1;
								while(zPtr > pStream->zInput && zPtr[0] == '\\') {
									zPtr--;
									i++;
								}
								if((i & 1) == 0) {
									break;
								}
							}
						}
						if(pStream->zText[0] == '\n') {
							pStream->nLine++;
						}
						pStream->zText++;
					}
					/* Record token length and type */
					pStr->nByte = (sxu32)((const char *)pStream->zText - pStr->zString);
					pToken->nType = PH7_TK_SSTR;
					/* Jump the trailing single quote */
					pStream->zText++;
					return SXRET_OK;
				}
			case '"': {
					sxi32 iNest;
					/* Double quoted string */
					pStr->zString++;
					while(pStream->zText < pStream->zEnd) {
						if(pStream->zText[0] == '{' && &pStream->zText[1] < pStream->zEnd && pStream->zText[1] == '$') {
							iNest = 1;
							pStream->zText++;
							/* TICKET 1433-40: Handle braces'{}' in double quoted string where everything is allowed */
							while(pStream->zText < pStream->zEnd) {
								if(pStream->zText[0] == '{') {
									iNest++;
								} else if(pStream->zText[0] == '}') {
									iNest--;
									if(iNest <= 0) {
										pStream->zText++;
										break;
									}
								} else if(pStream->zText[0] == '\n') {
									pStream->nLine++;
								}
								pStream->zText++;
							}
							if(pStream->zText >= pStream->zEnd) {
								break;
							}
						}
						if(pStream->zText[0] == '"') {
							if(pStream->zText[-1] != '\\') {
								break;
							} else {
								const unsigned char *zPtr = &pStream->zText[-2];
								sxi32 i = 1;
								while(zPtr > pStream->zInput && zPtr[0] == '\\') {
									zPtr--;
									i++;
								}
								if((i & 1) == 0) {
									break;
								}
							}
						}
						if(pStream->zText[0] == '\n') {
							pStream->nLine++;
						}
						pStream->zText++;
					}
					/* Record token length and type */
					pStr->nByte = (sxu32)((const char *)pStream->zText - pStr->zString);
					pToken->nType = PH7_TK_DSTR;
					/* Jump the trailing quote */
					pStream->zText++;
					return SXRET_OK;
				}
			case '`': {
					/* Backtick quoted string */
					pStr->zString++;
					while(pStream->zText < pStream->zEnd) {
						if(pStream->zText[0] == '`' && pStream->zText[-1] != '\\') {
							break;
						}
						if(pStream->zText[0] == '\n') {
							pStream->nLine++;
						}
						pStream->zText++;
					}
					/* Record token length and type */
					pStr->nByte = (sxu32)((const char *)pStream->zText - pStr->zString);
					pToken->nType = PH7_TK_BSTR;
					/* Jump the trailing backtick */
					pStream->zText++;
					return SXRET_OK;
				}
			case '\\':
				pToken->nType = PH7_TK_NSSEP;
				break;
			case ':':
				if(pStream->zText < pStream->zEnd && pStream->zText[0] == ':') {
					/* Current operator: '::' */
					pStream->zText++;
				} else {
					pToken->nType = PH7_TK_COLON; /* Single colon */
				}
				break;
			case ',':
				pToken->nType |= PH7_TK_COMMA;
				break; /* Comma is also an operator */
			case ';':
				pToken->nType = PH7_TK_SEMI;
				break;
			/* Handle combined operators [i.e: +=,===,!=== ...] */
			case '=':
				pToken->nType |= PH7_TK_EQUAL;
				if(pStream->zText < pStream->zEnd) {
					if(pStream->zText[0] == '=') {
						pToken->nType &= ~PH7_TK_EQUAL;
						/* Current operator: == */
						pStream->zText++;
						if(pStream->zText < pStream->zEnd && pStream->zText[0] == '=') {
							/* Current operator: === */
							pStream->zText++;
						}
					} else if(pStream->zText[0] == '>') {
						/* Array operator: => */
						pToken->nType = PH7_TK_ARRAY_OP;
						pStream->zText++;
					} else {
						/* TICKET 1433-0010: Reference operator '=&' */
						const unsigned char *zCur = pStream->zText;
						sxu32 nLine = 0;
						while(zCur < pStream->zEnd && zCur[0] < 0xc0 && SyisSpace(zCur[0])) {
							if(zCur[0] == '\n') {
								nLine++;
							}
							zCur++;
						}
						if(zCur < pStream->zEnd && zCur[0] == '&') {
							/* Current operator: =& */
							pToken->nType &= ~PH7_TK_EQUAL;
							SyStringInitFromBuf(pStr, "=&", sizeof("=&") - 1);
							/* Update token stream */
							pStream->zText = &zCur[1];
							pStream->nLine += nLine;
						}
					}
				}
				break;
			case '!':
				if(pStream->zText < pStream->zEnd && pStream->zText[0] == '=') {
					/* Current operator: != */
					pStream->zText++;
					if(pStream->zText < pStream->zEnd && pStream->zText[0] == '=') {
						/* Current operator: !== */
						pStream->zText++;
					}
				}
				break;
			case '&':
				pToken->nType |= PH7_TK_AMPER;
				if(pStream->zText < pStream->zEnd) {
					if(pStream->zText[0] == '&') {
						pToken->nType &= ~PH7_TK_AMPER;
						/* Current operator: && */
						pStream->zText++;
					} else if(pStream->zText[0] == '=') {
						pToken->nType &= ~PH7_TK_AMPER;
						/* Current operator: &= */
						pStream->zText++;
					}
				}
				break;
			case '|':
				if(pStream->zText < pStream->zEnd) {
					if(pStream->zText[0] == '|') {
						/* Current operator: || */
						pStream->zText++;
					} else if(pStream->zText[0] == '=') {
						/* Current operator: |= */
						pStream->zText++;
					}
				}
				break;
			case '+':
				if(pStream->zText < pStream->zEnd) {
					if(pStream->zText[0] == '+') {
						/* Current operator: ++ */
						pStream->zText++;
					} else if(pStream->zText[0] == '=') {
						/* Current operator: += */
						pStream->zText++;
					}
				}
				break;
			case '-':
				if(pStream->zText < pStream->zEnd) {
					if(pStream->zText[0] == '-') {
						/* Current operator: -- */
						pStream->zText++;
					} else if(pStream->zText[0] == '=') {
						/* Current operator: -= */
						pStream->zText++;
					} else if(pStream->zText[0] == '>') {
						/* Current operator: -> */
						pStream->zText++;
					}
				}
				break;
			case '*':
				if(pStream->zText < pStream->zEnd && pStream->zText[0] == '=') {
					/* Current operator: *= */
					pStream->zText++;
				}
				break;
			case '/':
				if(pStream->zText < pStream->zEnd && pStream->zText[0] == '=') {
					/* Current operator: /= */
					pStream->zText++;
				}
				break;
			case '%':
				if(pStream->zText < pStream->zEnd && pStream->zText[0] == '=') {
					/* Current operator: %= */
					pStream->zText++;
				}
				break;
			case '^':
				if(pStream->zText < pStream->zEnd) {
					if(pStream->zText[0] == '=') {
						/* Current operator: ^= */
						pStream->zText++;
					} else if(pStream->zText[0] == '^') {
						/* Current operator: ^^ */
						pStream->zText++;
					}
				}
				break;
			case '<':
				if(pStream->zText < pStream->zEnd) {
					if(pStream->zText[0] == '<') {
						/* Current operator: << */
						pStream->zText++;
						if(pStream->zText < pStream->zEnd) {
							if(pStream->zText[0] == '=') {
								/* Current operator: <<= */
								pStream->zText++;
							}
						}
					} else if(pStream->zText[0] == '>') {
						/* Current operator: <> */
						pStream->zText++;
					} else if(pStream->zText[0] == '=') {
						/* Current operator: <= */
						pStream->zText++;
					}
				}
				break;
			case '>':
				if(pStream->zText < pStream->zEnd) {
					if(pStream->zText[0] == '>') {
						/* Current operator: >> */
						pStream->zText++;
						if(pStream->zText < pStream->zEnd && pStream->zText[0] == '=') {
							/* Current operator: >>= */
							pStream->zText++;
						}
					} else if(pStream->zText[0] == '=') {
						/* Current operator: >= */
						pStream->zText++;
					}
				}
				break;
			default:
				break;
		}
		if(pStr->nByte <= 0) {
			/* Record token length */
			pStr->nByte = (sxu32)((const char *)pStream->zText - pStr->zString);
		}
		if(pToken->nType & PH7_TK_OP) {
			const ph7_expr_op *pOp;
			/* Check if the extracted token is an operator */
			pOp = PH7_ExprExtractOperator(pStr, (SyToken *)SySetPeek(pStream->pSet));
			if(pOp == 0) {
				/* Not an operator */
				pToken->nType &= ~PH7_TK_OP;
				if(pToken->nType <= 0) {
					pToken->nType = PH7_TK_OTHER;
				}
			} else {
				/* Save the instance associated with this operator for later processing */
				pToken->pUserData = (void *)pOp;
			}
		}
	}
	/* Tell the upper-layer to save the extracted token for later processing */
	return SXRET_OK;
}

static sxu32 KeywordCode(const char *z, int n) {
	typedef struct {
		char *token;
		int value;
	} ph7_token;
	static ph7_token pTokenLookup[] = {
		{"extends", PH7_TKWRD_EXTENDS},
		{"switch", PH7_TKWRD_SWITCH},
		{"int", PH7_TKWRD_INT},
		{"require_once", PH7_TKWRD_REQONCE},
		{"require", PH7_TKWRD_REQUIRE},
		{"return", PH7_TKWRD_RETURN},
		{"namespace", PH7_TKWRD_NAMESPACE},
		{"object", PH7_TKWRD_OBJECT},
		{"throw", PH7_TKWRD_THROW},
		{"bool", PH7_TKWRD_BOOL},
		{"default", PH7_TKWRD_DEFAULT},
		{"try", PH7_TKWRD_TRY},
		{"case", PH7_TKWRD_CASE},
		{"self", PH7_TKWRD_SELF},
		{"final", PH7_TKWRD_FINAL},
		{"list", PH7_TKWRD_LIST},
		{"static", PH7_TKWRD_STATIC},
		{"clone", PH7_TKWRD_CLONE},
		{"new", PH7_TKWRD_NEW},
		{"const", PH7_TKWRD_CONST},
		{"string", PH7_TKWRD_STRING},
		{"using", PH7_TKWRD_USING},
		{"elseif", PH7_TKWRD_ELIF},
		{"else", PH7_TKWRD_ELSE},
		{"if", PH7_TKWRD_IF},
		{"float", PH7_TKWRD_FLOAT},
		{"var", PH7_TKWRD_VAR},
		{"array", PH7_TKWRD_ARRAY},
		{"virtual", PH7_TKWRD_VIRTUAL},
		{"class", PH7_TKWRD_CLASS},
		{"as", PH7_TKWRD_AS},
		{"continue", PH7_TKWRD_CONTINUE},
		{"function", PH7_TKWRD_FUNCTION},
		{"while", PH7_TKWRD_WHILE},
		{"eval", PH7_TKWRD_EVAL},
		{"do", PH7_TKWRD_DO},
		{"exit", PH7_TKWRD_EXIT},
		{"implements", PH7_TKWRD_IMPLEMENTS},
		{"include_once", PH7_TKWRD_INCONCE},
		{"include", PH7_TKWRD_INCLUDE},
		{"empty", PH7_TKWRD_EMPTY},
		{"instanceof", PH7_TKWRD_INSTANCEOF},
		{"interface", PH7_TKWRD_INTERFACE},
		{"for", PH7_TKWRD_FOR},
		{"foreach", PH7_TKWRD_FOREACH},
		{"isset", PH7_TKWRD_ISSET},
		{"parent", PH7_TKWRD_PARENT},
		{"private", PH7_TKWRD_PRIVATE},
		{"protected", PH7_TKWRD_PROTECTED},
		{"public", PH7_TKWRD_PUBLIC},
		{"catch", PH7_TKWRD_CATCH},
		{"unset", PH7_TKWRD_UNSET},
		{"break", PH7_TKWRD_BREAK}
	};
	if(n < 2) {
		return PH7_TK_ID;
	} else {
		for(ph7_token *pToken = pTokenLookup; pToken != pTokenLookup + sizeof(pTokenLookup) / sizeof(pTokenLookup[0]); pToken++) {
			if(n == SyStrlen(pToken->token) && SyStrncmp(pToken->token, z, n) == 0) {
				return pToken->value;
			}
		}
		return PH7_TK_ID;
	}
}
/*
 * Tokenize a raw PHP input.
 * This is the public tokenizer called by most code generator routines.
 */
PH7_PRIVATE sxi32 PH7_TokenizePHP(const char *zInput, sxu32 nLen, sxu32 nLineStart, SySet *pOut) {
	SyLex sLexer;
	sxi32 rc;
	/* Initialize the lexer */
	rc = SyLexInit(&sLexer, &(*pOut), TokenizePHP, 0);
	if(rc != SXRET_OK) {
		return rc;
	}
	sLexer.sStream.nLine = nLineStart;
	/* Tokenize input */
	rc = SyLexTokenizeInput(&sLexer, zInput, nLen, 0, 0, 0);
	/* Release the lexer */
	SyLexRelease(&sLexer);
	/* Tokenization result */
	return rc;
}
