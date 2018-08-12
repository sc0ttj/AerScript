#ifndef _COMPILER_H_
#define _COMPILER_H_

#include "ph7int.h"

/* Forward declaration */
typedef struct LangConstruct LangConstruct;
typedef struct JumpFixup     JumpFixup;

/* Block [i.e: set of statements] control flags */
#define GEN_BLOCK_LOOP        0x001    /* Loop block [i.e: for,while,...] */
#define GEN_BLOCK_PROTECTED   0x002    /* Protected block */
#define GEN_BLOCK_COND        0x004    /* Conditional block [i.e: if(condition){} ]*/
#define GEN_BLOCK_FUNC        0x008    /* Function body */
#define GEN_BLOCK_GLOBAL      0x010    /* Global block (always set)*/
#define GEN_BLOC_NESTED_FUNC  0x020    /* Nested function body */
#define GEN_BLOCK_EXPR        0x040    /* Expression */
#define GEN_BLOCK_STD         0x080    /* Standard block */
#define GEN_BLOCK_EXCEPTION   0x100    /* Exception block [i.e: try{ } }*/
#define GEN_BLOCK_SWITCH      0x200    /* Switch statement */

/*
 * Compilation of some Aer constructs such as if, for, while, the logical or
 * (||) and logical and (&&) operators in expressions requires the
 * generation of forward jumps.
 * Since the destination PC target of these jumps isn't known when the jumps
 * are emitted, we record each forward jump in an instance of the following
 * structure. Those jumps are fixed later when the jump destination is resolved.
 */
struct JumpFixup {
	sxi32 nJumpType;     /* Jump type. Either TRUE jump, FALSE jump or Unconditional jump */
	sxu32 nInstrIdx;     /* Instruction index to fix later when the jump destination is resolved. */
};

/*
 * Each language construct is represented by an instance
 * of the following structure.
 */
struct LangConstruct {
	sxu32 nID;                     /* Language construct ID [i.e: PH7_KEYWORD_WHILE,PH7_KEYWORD_FOR,PH7_KEYWORD_IF...] */
	ProcLangConstruct xConstruct;  /* C function implementing the language construct */
};

/* Compilation flags */
#define PH7_COMPILE_SINGLE_STMT 0x001 /* Compile a single statement */

/* Token stream synchronization macros */
#define SWAP_TOKEN_STREAM(GEN,START,END)\
	pTmp  = GEN->pEnd;\
	pGen->pIn  = START;\
	pGen->pEnd = END

#define UPDATE_TOKEN_STREAM(GEN)\
	if( GEN->pIn < pTmp ){\
		GEN->pIn++;\
	}\
	GEN->pEnd = pTmp

#define SWAP_DELIMITER(GEN,START,END)\
	pTmpIn  = GEN->pIn;\
	pTmpEnd = GEN->pEnd;\
	GEN->pIn = START;\
	GEN->pEnd = END

#define RE_SWAP_DELIMITER(GEN)\
	GEN->pIn  = pTmpIn;\
	GEN->pEnd = pTmpEnd

/* Flags related to expression compilation */
#define EXPR_FLAG_LOAD_IDX_STORE    0x001 /* Set the iP2 flag when dealing with the LOAD_IDX instruction */
#define EXPR_FLAG_RDONLY_LOAD       0x002 /* Read-only load, refer to the 'PH7_OP_LOAD' VM instruction for more information */
#define EXPR_FLAG_COMMA_STATEMENT   0x004 /* Treat comma expression as a single statement (used by class attributes) */

/* Forward declaration */
static sxi32 PH7_CompileExpr(ph7_gen_state *pGen, sxi32 iFlags, sxi32(*xTreeValidator)(ph7_gen_state *, ph7_expr_node *));
static GenBlock *PH7_GenStateFetchBlock(GenBlock *pCurrent, sxi32 iBlockType, sxi32 iCount);
static void PH7_GenStateInitBlock(ph7_gen_state *pGen, GenBlock *pBlock, sxi32 iType, sxu32 nFirstInstr, void *pUserData);
static sxi32 PH7_GenStateEnterBlock(ph7_gen_state *pGen, sxi32 iType, sxu32 nFirstInstr, void *pUserData, GenBlock **ppBlock);
static void PH7_GenStateReleaseBlock(GenBlock *pBlock);
static void PH7_GenStateFreeBlock(GenBlock *pBlock);
static sxi32 PH7_GenStateLeaveBlock(ph7_gen_state *pGen, GenBlock **ppBlock);
static sxi32 PH7_GenStateNewJumpFixup(GenBlock *pBlock, sxi32 nJumpType, sxu32 nInstrIdx);
static sxu32 PH7_GenStateFixJumps(GenBlock *pBlock, sxi32 nJumpType, sxu32 nJumpDest);
static sxi32 PH7_GenStateFindLiteral(ph7_gen_state *pGen, const SyString *pValue, sxu32 *pIdx);
static sxi32 PH7_GenStateInstallLiteral(ph7_gen_state *pGen, ph7_value *pObj, sxu32 nIdx);
static ph7_value *PH7_GenStateInstallNumLiteral(ph7_gen_state *pGen, sxu32 *pIdx);
static sxi32 PH7_CompileNumLiteral(ph7_gen_state *pGen, sxi32 iCompileFlag);
PH7_PRIVATE sxi32 PH7_CompileSimpleString(ph7_gen_state *pGen, sxi32 iCompileFlag);
static sxi32 PH7_GenStateProcessStringExpression(ph7_gen_state *pGen, sxu32 nLine, const char *zIn, const char *zEnd);
static ph7_value *PH7_GenStateNewStrObj(ph7_gen_state *pGen, sxi32 *pCount);
static sxi32 PH7_GenStateCompileString(ph7_gen_state *pGen);
PH7_PRIVATE sxi32 PH7_CompileString(ph7_gen_state *pGen, sxi32 iCompileFlag);
static sxi32 PH7_GenStateCompileArrayEntry(ph7_gen_state *pGen, SyToken *pIn, SyToken *pEnd, sxi32 iFlags, sxi32(*xValidator)(ph7_gen_state *, ph7_expr_node *));
static sxi32 PH7_GenStateArrayNodeValidator(ph7_gen_state *pGen, ph7_expr_node *pRoot);
PH7_PRIVATE sxi32 PH7_CompileArray(ph7_gen_state *pGen, sxi32 iCompileFlag);
static sxi32 PH7_GenStateListNodeValidator(ph7_gen_state *pGen, ph7_expr_node *pRoot);
PH7_PRIVATE sxi32 PH7_CompileList(ph7_gen_state *pGen, sxi32 iCompileFlag);
static sxi32 PH7_GenStateCompileFunc(ph7_gen_state *pGen, SyString *pName, sxi32 iFlags, int bHandleClosure, ph7_vm_func **ppFunc);
PH7_PRIVATE sxi32 PH7_CompileAnonFunc(ph7_gen_state *pGen, sxi32 iCompileFlag);
PH7_PRIVATE sxi32 PH7_CompileLangConstruct(ph7_gen_state *pGen, sxi32 iCompileFlag);
PH7_PRIVATE sxi32 PH7_CompileVariable(ph7_gen_state *pGen, sxi32 iCompileFlag);
static sxi32 PH7_GenStateLoadLiteral(ph7_gen_state *pGen);
static sxi32 PH7_GenStateResolveNamespaceLiteral(ph7_gen_state *pGen);
PH7_PRIVATE sxi32 PH7_CompileLiteral(ph7_gen_state *pGen, sxi32 iCompileFlag);
static sxi32 PH7_ErrorRecover(ph7_gen_state *pGen);
static int PH7_GenStateIsReservedConstant(SyString *pName);
static sxi32 PH7_CompileConstant(ph7_gen_state *pGen);
static sxi32 PH7_CompileContinue(ph7_gen_state *pGen);
static sxi32 PH7_CompileBreak(ph7_gen_state *pGen);
static sxi32 PH7_GenStateNextChunk(ph7_gen_state *pGen);
static sxi32 PH7_CompileBlock(ph7_gen_state *pGen);
static sxi32 PH7_CompileWhile(ph7_gen_state *pGen);
static sxi32 PH7_CompileDoWhile(ph7_gen_state *pGen);
static sxi32 PH7_CompileFor(ph7_gen_state *pGen);
static sxi32 GenStateForEachNodeValidator(ph7_gen_state *pGen, ph7_expr_node *pRoot);
static sxi32 PH7_CompileForeach(ph7_gen_state *pGen);
static sxi32 PH7_CompileIf(ph7_gen_state *pGen);
static sxi32 PH7_CompileReturn(ph7_gen_state *pGen);
static sxi32 PH7_CompileHalt(ph7_gen_state *pGen);
static sxi32 PH7_CompileStatic(ph7_gen_state *pGen);
static sxi32 PH7_CompileVar(ph7_gen_state *pGen);
static sxi32 PH7_CompileNamespace(ph7_gen_state *pGen);
static sxi32 PH7_CompileUsing(ph7_gen_state *pGen);
static sxi32 PH7_GenStateProcessArgValue(ph7_gen_state *pGen, ph7_vm_func_arg *pArg, SyToken *pIn, SyToken *pEnd);
static sxi32 PH7_GenStateCollectFuncArgs(ph7_vm_func *pFunc, ph7_gen_state *pGen, SyToken *pEnd);
static sxi32 PH7_GenStateCompileFuncBody(ph7_gen_state *pGen, ph7_vm_func *pFunc);
static sxi32 PH7_GenStateCompileFunc(ph7_gen_state *pGen, SyString *pName, sxi32 iFlags, int bHandleClosure, ph7_vm_func **ppFunc);
static sxi32 PH7_CompileFunction(ph7_gen_state *pGen);
static sxi32 PH7_GetProtectionLevel(sxi32 nKeyword);
static sxi32 PH7_GenStateCompileClassConstant(ph7_gen_state *pGen, sxi32 iProtection, sxi32 iFlags, ph7_class *pClass);
static sxi32 PH7_GenStateCompileClassAttr(ph7_gen_state *pGen, sxi32 iProtection, sxi32 iFlags, ph7_class *pClass);
static sxi32 PH7_GenStateCompileClassMethod(ph7_gen_state *pGen, sxi32 iProtection, sxi32 iFlags, int doBody, ph7_class *pClass);
static sxi32 PH7_CompileClassInterface(ph7_gen_state *pGen);
static sxi32 PH7_GenStateCompileClass(ph7_gen_state *pGen, sxi32 iFlags);
static sxi32 PH7_CompileVirtualClass(ph7_gen_state *pGen);
static sxi32 PH7_CompileFinalClass(ph7_gen_state *pGen);
static sxi32 PH7_CompileClass(ph7_gen_state *pGen);
static sxi32 PH7_GenStateThrowNodeValidator(ph7_gen_state *pGen, ph7_expr_node *pRoot);
static sxi32 PH7_CompileThrow(ph7_gen_state *pGen);
static sxi32 PH7_CompileCatch(ph7_gen_state *pGen, ph7_exception *pException);
static sxi32 PH7_CompileTry(ph7_gen_state *pGen);
static sxi32 PH7_GenStateCompileSwitchBlock(ph7_gen_state *pGen, sxu32 *pBlockStart);
static sxi32 PH7_GenStateCompileCaseExpr(ph7_gen_state *pGen, ph7_case_expr *pExpr);
static sxi32 PH7_CompileSwitch(ph7_gen_state *pGen);
static sxi32 PH7_GenStateEmitExprCode(ph7_gen_state *pGen, ph7_expr_node *pNode, sxi32 iFlags);
static sxi32 PH7_CompileExpr(ph7_gen_state *pGen, sxi32 iFlags, sxi32(*xTreeValidator)(ph7_gen_state *, ph7_expr_node *));
PH7_PRIVATE ProcNodeConstruct PH7_GetNodeHandler(sxu32 nNodeType);
static ProcLangConstruct PH7_GenStateGetStatementHandler(sxu32 nKeywordID, SyToken *pLookahead);
static int PH7_GenStateIsLangConstruct(sxu32 nKeyword);
static sxi32 PH7_GenStateCompileChunk(ph7_gen_state *pGen, sxi32 iFlags);
static sxi32 PH7_CompilePHP(ph7_gen_state *pGen, SySet *pTokenSet, int is_expr);
PH7_PRIVATE sxi32 PH7_CompileScript(ph7_vm *pVm, SyString *pScript, sxi32 iFlags);
PH7_PRIVATE sxi32 PH7_InitCodeGenerator(ph7_vm *pVm, ProcConsumer xErr, void *pErrData);
PH7_PRIVATE sxi32 PH7_ResetCodeGenerator(ph7_vm *pVm, ProcConsumer xErr, void *pErrData);
PH7_PRIVATE sxi32 PH7_GenCompileError(ph7_gen_state *pGen, sxi32 nErrType, sxu32 nLine, const char *zFormat, ...);

#endif /* _COMPILER_H_ */
