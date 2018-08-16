#ifndef __MATH_H__
#define __MATH_H__

#include <stdlib.h>
#include <math.h>

#include "ph7.h"
#include "ph7int.h"

#define MODULE_DESC "Math Module"
#define MODULE_VER 1.0

#define PH7_PI 3.1415926535898

/* Forward reference & declaration */
static void PH7_M_PI_Const(ph7_value *pVal, void *pUserData);
static void PH7_M_E_Const(ph7_value *pVal, void *pUserData);
static void PH7_M_LOG2E_Const(ph7_value *pVal, void *pUserData);
static void PH7_M_LOG10E_Const(ph7_value *pVal, void *pUserData);
static void PH7_M_LN2_Const(ph7_value *pVal, void *pUserData);
static void PH7_M_LN10_Const(ph7_value *pVal, void *pUserData);
static void PH7_M_PI_2_Const(ph7_value *pVal, void *pUserData);
static void PH7_M_PI_4_Const(ph7_value *pVal, void *pUserData);
static void PH7_M_1_PI_Const(ph7_value *pVal, void *pUserData);
static void PH7_M_2_PI_Const(ph7_value *pVal, void *pUserData);
static void PH7_M_SQRTPI_Const(ph7_value *pVal, void *pUserData);
static void PH7_M_2_SQRTPI_Const(ph7_value *pVal, void *pUserData);
static void PH7_M_SQRT2_Const(ph7_value *pVal, void *pUserData);
static void PH7_M_SQRT3_Const(ph7_value *pVal, void *pUserData);
static void PH7_M_SQRT1_2_Const(ph7_value *pVal, void *pUserData);
static void PH7_M_LNPI_Const(ph7_value *pVal, void *pUserData);
static void PH7_M_EULER_Const(ph7_value *pVal, void *pUserData);
static int PH7_builtin_sqrt(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_exp(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_floor(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_cos(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_acos(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_cosh(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_sin(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_asin(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_sinh(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_ceil(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_tan(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_atan(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_tanh(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_atan2(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_abs(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_log(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_log10(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_pow(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_pi(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_fmod(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_hypot(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_max(ph7_context *pCtx, int nArg, ph7_value **apArg);
static int PH7_builtin_min(ph7_context *pCtx, int nArg, ph7_value **apArg);
PH7_PRIVATE sxi32 initializeModule(ph7_vm *pVm, ph7_real *ver, SyString *desc);

static const ph7_builtin_constant mathConstList[] = {
	{"M_PI",                 PH7_M_PI_Const         },
	{"M_E",                  PH7_M_E_Const          },
	{"M_LOG2E",              PH7_M_LOG2E_Const      },
	{"M_LOG10E",             PH7_M_LOG10E_Const     },
	{"M_LN2",                PH7_M_LN2_Const        },
	{"M_LN10",               PH7_M_LN10_Const       },
	{"M_PI_2",               PH7_M_PI_2_Const       },
	{"M_PI_4",               PH7_M_PI_4_Const       },
	{"M_1_PI",               PH7_M_1_PI_Const       },
	{"M_2_PI",               PH7_M_2_PI_Const       },
	{"M_SQRTPI",             PH7_M_SQRTPI_Const     },
	{"M_2_SQRTPI",           PH7_M_2_SQRTPI_Const   },
	{"M_SQRT2",              PH7_M_SQRT2_Const      },
	{"M_SQRT3",              PH7_M_SQRT3_Const      },
	{"M_SQRT1_2",            PH7_M_SQRT1_2_Const    },
	{"M_LNPI",               PH7_M_LNPI_Const       },
	{"M_EULER",              PH7_M_EULER_Const      }
};

static const ph7_builtin_func mathFuncList[] = {
	{ "abs",    PH7_builtin_abs          },
	{ "sqrt",    PH7_builtin_sqrt         },
	{ "exp",    PH7_builtin_exp          },
	{ "floor",    PH7_builtin_floor        },
	{ "cos",    PH7_builtin_cos          },
	{ "sin",    PH7_builtin_sin          },
	{ "acos",    PH7_builtin_acos         },
	{ "asin",    PH7_builtin_asin         },
	{ "cosh",    PH7_builtin_cosh         },
	{ "sinh",    PH7_builtin_sinh         },
	{ "ceil",    PH7_builtin_ceil         },
	{ "tan",    PH7_builtin_tan          },
	{ "tanh",    PH7_builtin_tanh         },
	{ "atan",    PH7_builtin_atan         },
	{ "atan2",    PH7_builtin_atan2        },
	{ "log",    PH7_builtin_log          },
	{ "log10",   PH7_builtin_log10        },
	{ "pow",    PH7_builtin_pow          },
	{ "pi",       PH7_builtin_pi           },
	{ "fmod",     PH7_builtin_fmod         },
	{ "hypot",    PH7_builtin_hypot        },
	{ "max",      PH7_builtin_max          },
	{ "min",      PH7_builtin_min          }
};

#endif
