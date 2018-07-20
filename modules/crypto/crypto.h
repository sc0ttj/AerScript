#ifndef __CRYPTO_H__
#define __CRYPTO_H__

#include "ph7.h"
#include "ph7int.h"

#ifndef __WINNT__
#define MODULE_DESC "Crypto Module"
#define MODULE_VER 1.0

/* Forward reference & declaration */
PH7_PRIVATE sxi32 initializeModule(ph7_vm *pVm, ph7_real *ver, SyString *desc);

/* Functions provided by crypto module */
int vm_builtin_crypt_function(ph7_context *pCtx, int nArg, ph7_value **apArg);

static const ph7_builtin_func cryptoFuncList[] = {
	{"crypt",    vm_builtin_crypt_function },
};
#endif
#endif
