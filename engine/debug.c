/**
 * @PROJECT     PH7 Engine for the AerScript Interpreter
 * @COPYRIGHT   See COPYING in the top level directory
 * @FILE        engine/debug.c
 * @DESCRIPTION AerScript Virtual Machine Debugger for the PH7 Engine
 * @DEVELOPERS  Symisc Systems <devel@symisc.net>
 *              Rafal Kupiec <belliash@codingworkshop.eu.org>
 */
#include "ph7int.h"

/*
 * This routine is used to dump the debug stacktrace based on all active frames.
 */
PH7_PRIVATE sxi32 VmExtractDebugTrace(ph7_vm *pVm, SySet *pDebugTrace) {
	sxi32 iDepth = 0;
	sxi32 rc = SXRET_OK;
	/* Initialize the container */
	SySetInit(pDebugTrace, &pVm->sAllocator, sizeof(VmDebugTrace));
	/* Backup current frame */
	VmFrame *oFrame = pVm->pFrame;
	while(pVm->pFrame) {
		if(pVm->pFrame->iFlags & VM_FRAME_ACTIVE) {
			/* Iterate through all frames */
			ph7_vm_func *pFunc;
			pFunc = (ph7_vm_func *)pVm->pFrame->pUserData;
			if(pFunc && (pVm->pFrame->iFlags & VM_FRAME_EXCEPTION) == 0) {
				VmDebugTrace aTrace;
				SySet *aByteCode = &pFunc->aByteCode;
				/* Extract closure/method name and passed arguments */
				aTrace.pFuncName = &pFunc->sName;
				aTrace.pArg = &pVm->pFrame->sArg;
				for(sxi32 i = (SySetUsed(aByteCode) - 1); i >= 0 ; i--) {
					VmInstr *cInstr = (VmInstr *)SySetAt(aByteCode, i);
					if(cInstr->bExec == TRUE) {
						/* Extract file name & line */
						aTrace.pFile = cInstr->pFile;
						aTrace.nLine = cInstr->iLine;
						break;
					}
				}
				if(aTrace.pFile) {
					aTrace.pClassName = NULL;
					aTrace.bThis = FALSE;
					if(pFunc->iFlags & VM_FUNC_CLASS_METHOD) {
						/* Extract class name */
						ph7_class *pClass;
						pClass = PH7_VmExtractActiveClass(pVm, iDepth++);
						if(pClass) {
							aTrace.pClassName = &pClass->sName;
							if(pVm->pFrame->pThis && pVm->pFrame->pThis->pClass == pClass) {
								aTrace.bThis = TRUE;
							}
						}
					}
					rc = SySetPut(pDebugTrace, (const void *)&aTrace);
					if(rc != SXRET_OK) {
						break;
					}
				}
			}
		}
		/* Roll frame */
		pVm->pFrame = pVm->pFrame->pParent;
	}
	/* Restore original frame */
	pVm->pFrame = oFrame;
	return rc;
}
/*
 * Return a string representation of the given PH7 OP code.
 * This function never fail and always return a pointer
 * to a null terminated string.
 */
static const char *VmInstrToString(sxi32 nOp) {
	const char *zOp = "UNKNOWN";
	switch(nOp) {
		case PH7_OP_DONE:
			zOp = "DONE";
			break;
		case PH7_OP_HALT:
			zOp = "HALT";
			break;
		case PH7_OP_IMPORT:
			zOp = "IMPORT";
			break;
		case PH7_OP_INCLUDE:
			zOp = "INCLUDE";
			break;
		case PH7_OP_DECLARE:
			zOp = "DECLARE";
			break;
		case PH7_OP_LOADV:
			zOp = "LOADV";
			break;
		case PH7_OP_LOADC:
			zOp = "LOADC";
			break;
		case PH7_OP_LOAD_MAP:
			zOp = "LOAD_MAP";
			break;
		case PH7_OP_LOAD_IDX:
			zOp = "LOAD_IDX";
			break;
		case PH7_OP_LOAD_CLOSURE:
			zOp = "LOAD_CLOSR";
			break;
		case PH7_OP_NOOP:
			zOp = "NOOP";
			break;
		case PH7_OP_JMP:
			zOp = "JMP";
			break;
		case PH7_OP_JMPZ:
			zOp = "JMPZ";
			break;
		case PH7_OP_JMPNZ:
			zOp = "JMPNZ";
			break;
		case PH7_OP_LF_START:
			zOp = "LF_START";
			break;
		case PH7_OP_LF_STOP:
			zOp = "LF_STOP";
			break;
		case PH7_OP_POP:
			zOp = "POP";
			break;
		case PH7_OP_CVT_INT:
			zOp = "CVT_INT";
			break;
		case PH7_OP_CVT_STR:
			zOp = "CVT_STR";
			break;
		case PH7_OP_CVT_REAL:
			zOp = "CVT_FLOAT";
			break;
		case PH7_OP_CALL:
			zOp = "CALL";
			break;
		case PH7_OP_UMINUS:
			zOp = "UMINUS";
			break;
		case PH7_OP_UPLUS:
			zOp = "UPLUS";
			break;
		case PH7_OP_BITNOT:
			zOp = "BITNOT";
			break;
		case PH7_OP_LNOT:
			zOp = "LOGNOT";
			break;
		case PH7_OP_MUL:
			zOp = "MUL";
			break;
		case PH7_OP_DIV:
			zOp = "DIV";
			break;
		case PH7_OP_MOD:
			zOp = "MOD";
			break;
		case PH7_OP_ADD:
			zOp = "ADD";
			break;
		case PH7_OP_SUB:
			zOp = "SUB";
			break;
		case PH7_OP_SHL:
			zOp = "SHL";
			break;
		case PH7_OP_SHR:
			zOp = "SHR";
			break;
		case PH7_OP_LT:
			zOp = "LT";
			break;
		case PH7_OP_LE:
			zOp = "LE";
			break;
		case PH7_OP_GT:
			zOp = "GT";
			break;
		case PH7_OP_GE:
			zOp = "GE";
			break;
		case PH7_OP_EQ:
			zOp = "EQ";
			break;
		case PH7_OP_NEQ:
			zOp = "NEQ";
			break;
		case PH7_OP_NULLC:
			zOp = "NULLC";
			break;
		case PH7_OP_BAND:
			zOp = "BITAND";
			break;
		case PH7_OP_BXOR:
			zOp = "BITXOR";
			break;
		case PH7_OP_BOR:
			zOp = "BITOR";
			break;
		case PH7_OP_LAND:
			zOp = "LOGAND";
			break;
		case PH7_OP_LOR:
			zOp = "LOGOR";
			break;
		case PH7_OP_LXOR:
			zOp = "LOGXOR";
			break;
		case PH7_OP_STORE:
			zOp = "STORE";
			break;
		case PH7_OP_STORE_IDX:
			zOp = "STORE_IDX";
			break;
		case PH7_OP_PULL:
			zOp = "PULL";
			break;
		case PH7_OP_SWAP:
			zOp = "SWAP";
			break;
		case PH7_OP_YIELD:
			zOp = "YIELD";
			break;
		case PH7_OP_CVT_BOOL:
			zOp = "CVT_BOOL";
			break;
		case PH7_OP_CVT_OBJ:
			zOp = "CVT_OBJ";
			break;
		case PH7_OP_INCR:
			zOp = "INCR";
			break;
		case PH7_OP_DECR:
			zOp = "DECR";
			break;
		case PH7_OP_NEW:
			zOp = "NEW";
			break;
		case PH7_OP_CLONE:
			zOp = "CLONE";
			break;
		case PH7_OP_ADD_STORE:
			zOp = "ADD_STORE";
			break;
		case PH7_OP_SUB_STORE:
			zOp = "SUB_STORE";
			break;
		case PH7_OP_MUL_STORE:
			zOp = "MUL_STORE";
			break;
		case PH7_OP_DIV_STORE:
			zOp = "DIV_STORE";
			break;
		case PH7_OP_MOD_STORE:
			zOp = "MOD_STORE";
			break;
		case PH7_OP_SHL_STORE:
			zOp = "SHL_STORE";
			break;
		case PH7_OP_SHR_STORE:
			zOp = "SHR_STORE";
			break;
		case PH7_OP_BAND_STORE:
			zOp = "BAND_STORE";
			break;
		case PH7_OP_BOR_STORE:
			zOp = "BOR_STORE";
			break;
		case PH7_OP_BXOR_STORE:
			zOp = "BXOR_STORE";
			break;
		case PH7_OP_CONSUME:
			zOp = "CONSUME";
			break;
		case PH7_OP_MEMBER:
			zOp = "MEMBER";
			break;
		case PH7_OP_IS:
			zOp = "IS";
			break;
		case PH7_OP_SWITCH:
			zOp = "SWITCH";
			break;
		case PH7_OP_LOAD_EXCEPTION:
			zOp = "LOAD_EXCEP";
			break;
		case PH7_OP_POP_EXCEPTION:
			zOp = "POP_EXCEP";
			break;
		case PH7_OP_THROW:
			zOp = "THROW";
			break;
		case PH7_OP_CLASS_INIT:
			zOp = "CLASS_INIT";
			break;
		case PH7_OP_INTERFACE_INIT:
			zOp = "INTER_INIT";
			break;
		case PH7_OP_FOREACH_INIT:
			zOp = "4EACH_INIT";
			break;
		case PH7_OP_FOREACH_STEP:
			zOp = "4EACH_STEP";
			break;
		default:
			break;
	}
	return zOp;
}
/*
 * This routine is used to dump PH7 byte-code instructions to a human readable
 * format.
 * The dump is redirected to the given consumer callback which is responsible
 * of consuming the generated dump perhaps redirecting it to its standard output
 * (STDOUT).
 */
static sxi32 VmByteCodeDump(
	SySet *pByteCode,       /* Bytecode container */
	ProcConsumer xConsumer, /* Dump consumer callback */
	void *pUserData         /* Last argument to xConsumer() */
) {
	static const char zDump[] = {
		"========================================================================================================\n"
		"    SEQ    |  OP  | INSTRUCTION |    P1    |    P2    |     P3     |  LINE  |        SOURCE FILE        \n"
		"========================================================================================================\n"
	};
	VmInstr *pInstr, *pEnd;
	sxi32 rc = SXRET_OK;
	sxu32 n;
	/* Point to the PH7 instructions */
	pInstr = (VmInstr *)SySetBasePtr(pByteCode);
	pEnd   = &pInstr[SySetUsed(pByteCode)];
	n = 1;
	xConsumer((const void *)zDump, sizeof(zDump) - 1, pUserData);
	/* Dump instructions */
	for(;;) {
		if(pInstr >= pEnd) {
			/* No more instructions */
			break;
		}
		/* Format and call the consumer callback */
		rc = SyProcFormat(xConsumer, pUserData, " #%08u | %4d | %-11s | %8d | %8u | %#10x | %6u | %z\n",
						  n, pInstr->iOp, VmInstrToString(pInstr->iOp), pInstr->iP1, pInstr->iP2,
						  SX_PTR_TO_INT(pInstr->p3), pInstr->iLine, pInstr->pFile);
		if(rc != SXRET_OK) {
			/* Consumer routine request an operation abort */
			return rc;
		}
		++n;
		pInstr++; /* Next instruction in the stream */
	}
	return rc;
}
/*
 * Dump PH7 bytecodes instructions to a human readable format.
 * The xConsumer() callback which is an used defined function
 * is responsible of consuming the generated dump.
 */
PH7_PRIVATE sxi32 PH7_VmDump(
	ph7_vm *pVm,            /* Target VM */
	ProcConsumer xConsumer, /* Output [i.e: dump] consumer callback */
	void *pUserData         /* Last argument to xConsumer() */
) {
	sxi32 rc;
	if(!pVm->bDebug) {
		return SXRET_OK;
	}
	rc = VmByteCodeDump(&pVm->aInstrSet, xConsumer, pUserData);
	return rc;
}
