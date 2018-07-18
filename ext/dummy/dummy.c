#include "dummy.h"

#define MODULE_DESC "Dummy module"
#define MODULE_VER 1.0

int psharp_dummy_function(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	SyString dummy;
	const char *text = "Hello world from dummy module!";
	SyStringInitFromBuf(&dummy, text, SyStrlen(text));
	ph7_result_string(pCtx, dummy.zString, dummy.nByte);
	return PH7_OK;
}

PH7_PRIVATE sxi32 initializeModule(ph7_vm *pVm, ph7_real *ver, SyString *desc) {
	sxi32 rc;
	sxu32 n;
	
	desc->zString = MODULE_DESC;
	*ver = MODULE_VER;
	for(n = 0 ; n < SX_ARRAYSIZE(dummyFuncList) ; ++n) {
		rc = ph7_create_function(&(*pVm), dummyFuncList[n].zName, dummyFuncList[n].xFunc, &(*pVm));
		if(rc != SXRET_OK) {
			return rc;
		}
	}
	return SXRET_OK;
}
