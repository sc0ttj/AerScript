#include "crypto.h"
#ifndef __WINNT__
#include <unistd.h>
#ifdef __linux__
#include <crypt.h>
#endif

int vm_builtin_crypt_function(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	SyString res;
	char *rawcrypt;
	const char *key;
	const char *salt;
	sxi32 keylen;
	sxi32 saltlen;

	if (nArg != 2) {
		return PH7_OK;
	}

	key = ph7_value_to_string(apArg[0], &keylen);
	salt = ph7_value_to_string(apArg[1], &saltlen);

	rawcrypt = crypt(key, salt);

	SyStringInitFromBuf(&res, rawcrypt, SyStrlen(rawcrypt));
	ph7_result_string(pCtx, res.zString, res.nByte);
	return PH7_OK;
}

PH7_PRIVATE sxi32 initializeModule(ph7_vm *pVm, ph7_real *ver, SyString *desc) {
	sxi32 rc;
	sxu32 n;
	
	desc->zString = MODULE_DESC;
	*ver = MODULE_VER;
	for(n = 0 ; n < SX_ARRAYSIZE(cryptoFuncList) ; ++n) {
		rc = ph7_create_function(&(*pVm), cryptoFuncList[n].zName, cryptoFuncList[n].xFunc, &(*pVm));
		if(rc != SXRET_OK) {
			return rc;
		}
	}
	return SXRET_OK;
}
#endif
