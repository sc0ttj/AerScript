/**
 * @PROJECT     AerScript Interpreter
 * @COPYRIGHT   See COPYING in the top level directory
 * @FILE        modules/ctype/ctype.h
 * @DESCRIPTION Character type checking module for AerScript Interpreter
 * @DEVELOPERS  Symisc Systems <devel@symisc.net>
 *              Rafal Kupiec <belliash@codingworkshop.eu.org>
 */
#ifndef __CTYPE_H__
#define __CTYPE_H__

#include "ph7.h"
#include "ph7int.h"

#define MODULE_DESC "CType Module"
#define MODULE_VER 1.0

/* Forward reference */
static int PH7_builtin_ctype_alnum(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_ctype_alpha(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_ctype_cntrl(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_ctype_digit(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_ctype_xdigit(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_ctype_graph(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_ctype_print(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_ctype_punct(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_ctype_space(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_ctype_lower(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_ctype_upper(ph7_context *pCtx, int nArg, ph7_value **apArg);
PH7_PRIVATE sxi32 initializeModule(ph7_vm *pVm, ph7_real *ver, SyString *desc);

static const ph7_builtin_func ctypeFuncList[] = {
	{ "ctype_alnum", PH7_builtin_ctype_alnum },
	{ "ctype_alpha", PH7_builtin_ctype_alpha },
	{ "ctype_cntrl", PH7_builtin_ctype_cntrl },
	{ "ctype_digit", PH7_builtin_ctype_digit },
	{ "ctype_xdigit", PH7_builtin_ctype_xdigit},
	{ "ctype_graph", PH7_builtin_ctype_graph },
	{ "ctype_print", PH7_builtin_ctype_print },
	{ "ctype_punct", PH7_builtin_ctype_punct },
	{ "ctype_space", PH7_builtin_ctype_space },
	{ "ctype_lower", PH7_builtin_ctype_lower },
	{ "ctype_upper", PH7_builtin_ctype_upper }
};

#endif
