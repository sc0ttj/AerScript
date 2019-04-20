/**
 * @PROJECT     AerScript Interpreter
 * @COPYRIGHT   See COPYING in the top level directory
 * @FILE        modules/math/math.c
 * @DESCRIPTION Mathematical functions module for AerScript Interpreter
 * @DEVELOPERS  Symisc Systems <devel@symisc.net>
 *              Rafal Kupiec <belliash@codingworkshop.eu.org>
 */
#include "math.h"

/*
 * M_PI
 *  Expand the value of pi.
 */
static void PH7_M_PI_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, PH7_PI);
}
/*
 * M_E
 *  Expand 2.7182818284590452354
 */
static void PH7_M_E_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, 2.7182818284590452354);
}
/*
 * M_LOG2E
 *  Expand 2.7182818284590452354
 */
static void PH7_M_LOG2E_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, 1.4426950408889634074);
}
/*
 * M_LOG10E
 *  Expand 0.4342944819032518276
 */
static void PH7_M_LOG10E_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, 0.4342944819032518276);
}
/*
 * M_LN2
 *  Expand 	0.69314718055994530942
 */
static void PH7_M_LN2_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, 0.69314718055994530942);
}
/*
 * M_LN10
 *  Expand 	2.30258509299404568402
 */
static void PH7_M_LN10_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, 2.30258509299404568402);
}
/*
 * M_PI_2
 *  Expand 	1.57079632679489661923
 */
static void PH7_M_PI_2_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, 1.57079632679489661923);
}
/*
 * M_PI_4
 *  Expand 	0.78539816339744830962
 */
static void PH7_M_PI_4_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, 0.78539816339744830962);
}
/*
 * M_1_PI
 *  Expand 	0.31830988618379067154
 */
static void PH7_M_1_PI_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, 0.31830988618379067154);
}
/*
 * M_2_PI
 *  Expand 0.63661977236758134308
 */
static void PH7_M_2_PI_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, 0.63661977236758134308);
}
/*
 * M_SQRTPI
 *  Expand 1.77245385090551602729
 */
static void PH7_M_SQRTPI_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, 1.77245385090551602729);
}
/*
 * M_2_SQRTPI
 *  Expand 	1.12837916709551257390
 */
static void PH7_M_2_SQRTPI_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, 1.12837916709551257390);
}
/*
 * M_SQRT2
 *  Expand 	1.41421356237309504880
 */
static void PH7_M_SQRT2_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, 1.41421356237309504880);
}
/*
 * M_SQRT3
 *  Expand 	1.73205080756887729352
 */
static void PH7_M_SQRT3_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, 1.73205080756887729352);
}
/*
 * M_SQRT1_2
 *  Expand 	0.70710678118654752440
 */
static void PH7_M_SQRT1_2_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, 0.70710678118654752440);
}
/*
 * M_LNPI
 *  Expand 	1.14472988584940017414
 */
static void PH7_M_LNPI_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, 1.14472988584940017414);
}
/*
 * M_EULER
 *  Expand  0.57721566490153286061
 */
static void PH7_M_EULER_Const(ph7_value *pVal, void *pUserData) {
	SXUNUSED(pUserData); /* cc warning */
	ph7_value_double(pVal, 0.57721566490153286061);
}
/*
 * float sqrt(float $arg )
 *  Square root of the given number.
 * Parameter
 *  The number to process.
 * Return
 *  The square root of arg or the special value Nan of failure.
 */
static int PH7_builtin_sqrt(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	x = ph7_value_to_double(apArg[0]);
	/* Perform the requested operation */
	r = sqrt(x);
	/* store the result back */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float exp(float $arg )
 *  Calculates the exponent of e.
 * Parameter
 *  The number to process.
 * Return
 *  'e' raised to the power of arg.
 */
static int PH7_builtin_exp(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	x = ph7_value_to_double(apArg[0]);
	/* Perform the requested operation */
	r = exp(x);
	/* store the result back */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float floor(float $arg )
 *  Round fractions down.
 * Parameter
 *  The number to process.
 * Return
 *  Returns the next lowest integer value by rounding down value if necessary.
 */
static int PH7_builtin_floor(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	x = ph7_value_to_double(apArg[0]);
	/* Perform the requested operation */
	r = floor(x);
	/* store the result back */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float cos(float $arg )
 *  Cosine.
 * Parameter
 *  The number to process.
 * Return
 *  The cosine of arg.
 */
static int PH7_builtin_cos(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	x = ph7_value_to_double(apArg[0]);
	/* Perform the requested operation */
	r = cos(x);
	/* store the result back */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float acos(float $arg )
 *  Arc cosine.
 * Parameter
 *  The number to process.
 * Return
 *  The arc cosine of arg.
 */
static int PH7_builtin_acos(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	x = ph7_value_to_double(apArg[0]);
	/* Perform the requested operation */
	r = acos(x);
	/* store the result back */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float cosh(float $arg )
 *  Hyperbolic cosine.
 * Parameter
 *  The number to process.
 * Return
 *  The hyperbolic cosine of arg.
 */
static int PH7_builtin_cosh(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	x = ph7_value_to_double(apArg[0]);
	/* Perform the requested operation */
	r = cosh(x);
	/* store the result back */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float sin(float $arg )
 *  Sine.
 * Parameter
 *  The number to process.
 * Return
 *  The sine of arg.
 */
static int PH7_builtin_sin(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	x = ph7_value_to_double(apArg[0]);
	/* Perform the requested operation */
	r = sin(x);
	/* store the result back */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float asin(float $arg )
 *  Arc sine.
 * Parameter
 *  The number to process.
 * Return
 *  The arc sine of arg.
 */
static int PH7_builtin_asin(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	x = ph7_value_to_double(apArg[0]);
	/* Perform the requested operation */
	r = asin(x);
	/* store the result back */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float sinh(float $arg )
 *  Hyperbolic sine.
 * Parameter
 *  The number to process.
 * Return
 *  The hyperbolic sine of arg.
 */
static int PH7_builtin_sinh(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	x = ph7_value_to_double(apArg[0]);
	/* Perform the requested operation */
	r = sinh(x);
	/* store the result back */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float ceil(float $arg )
 *  Round fractions up.
 * Parameter
 *  The number to process.
 * Return
 *  The next highest integer value by rounding up value if necessary.
 */
static int PH7_builtin_ceil(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	x = ph7_value_to_double(apArg[0]);
	/* Perform the requested operation */
	r = ceil(x);
	/* store the result back */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float tan(float $arg )
 *  Tangent.
 * Parameter
 *  The number to process.
 * Return
 *  The tangent of arg.
 */
static int PH7_builtin_tan(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	x = ph7_value_to_double(apArg[0]);
	/* Perform the requested operation */
	r = tan(x);
	/* store the result back */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float atan(float $arg )
 *  Arc tangent.
 * Parameter
 *  The number to process.
 * Return
 *  The arc tangent of arg.
 */
static int PH7_builtin_atan(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	x = ph7_value_to_double(apArg[0]);
	/* Perform the requested operation */
	r = atan(x);
	/* store the result back */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float tanh(float $arg )
 *  Hyperbolic tangent.
 * Parameter
 *  The number to process.
 * Return
 *  The Hyperbolic tangent of arg.
 */
static int PH7_builtin_tanh(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	x = ph7_value_to_double(apArg[0]);
	/* Perform the requested operation */
	r = tanh(x);
	/* store the result back */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float atan2(float $y,float $x)
 *  Arc tangent of two variable.
 * Parameter
 *  $y = Dividend parameter.
 *  $x = Divisor parameter.
 * Return
 *  The arc tangent of y/x in radian.
 */
static int PH7_builtin_atan2(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x, y;
	if(nArg < 2) {
		/* Missing arguments,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	y = ph7_value_to_double(apArg[0]);
	x = ph7_value_to_double(apArg[1]);
	/* Perform the requested operation */
	r = atan2(y, x);
	/* store the result back */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float/int64 abs(float/int64 $arg )
 *  Absolute value.
 * Parameter
 *  The number to process.
 * Return
 *  The absolute value of number.
 */
static int PH7_builtin_abs(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	int is_float;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	is_float = ph7_value_is_float(apArg[0]);
	if(is_float) {
		double r, x;
		x = ph7_value_to_double(apArg[0]);
		/* Perform the requested operation */
		r = fabs(x);
		ph7_result_double(pCtx, r);
	} else {
		int r, x;
		x = ph7_value_to_int(apArg[0]);
		/* Perform the requested operation */
		r = abs(x);
		ph7_result_int(pCtx, r);
	}
	return PH7_OK;
}
/*
 * float log(float $arg,[int/float $base])
 *  Natural logarithm.
 * Parameter
 *  $arg: The number to process.
 *  $base: The optional logarithmic base to use. (only base-10 is supported)
 * Return
 *  The logarithm of arg to base, if given, or the natural logarithm.
 * Note:
 *  only Natural log and base-10 log are supported.
 */
static int PH7_builtin_log(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	x = ph7_value_to_double(apArg[0]);
	/* Perform the requested operation */
	if(nArg == 2 && ph7_value_is_numeric(apArg[1]) && ph7_value_to_int(apArg[1]) == 10) {
		/* Base-10 log */
		r = log10(x);
	} else {
		r = log(x);
	}
	/* store the result back */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float log10(float $arg )
 *  Base-10 logarithm.
 * Parameter
 *  The number to process.
 * Return
 *  The Base-10 logarithm of the given number.
 */
static int PH7_builtin_log10(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	x = ph7_value_to_double(apArg[0]);
	/* Perform the requested operation */
	r = log10(x);
	/* store the result back */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * number pow(number $base,number $exp)
 *  Exponential expression.
 * Parameter
 *  base
 *  The base to use.
 * exp
 *  The exponent.
 * Return
 *  base raised to the power of exp.
 *  If the result can be represented as integer it will be returned
 *  as type integer, else it will be returned as type float.
 */
static int PH7_builtin_pow(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double r, x, y;
	if(nArg < 1) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	x = ph7_value_to_double(apArg[0]);
	y = ph7_value_to_double(apArg[1]);
	/* Perform the requested operation */
	r = pow(x, y);
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float pi(void)
 *  Returns an approximation of pi.
 * Note
 *  you can use the M_PI constant which yields identical results to pi().
 * Return
 *  The value of pi as float.
 */
static int PH7_builtin_pi(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	SXUNUSED(nArg); /* cc warning */
	SXUNUSED(apArg);
	ph7_result_double(pCtx, PH7_PI);
	return PH7_OK;
}
/*
 * float fmod(float $x,float $y)
 *  Returns the floating point remainder (modulo) of the division of the arguments.
 * Parameters
 * $x
 *  The dividend
 * $y
 *  The divisor
 * Return
 *  The floating point remainder of x/y.
 */
static int PH7_builtin_fmod(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double x, y, r;
	if(nArg < 2) {
		/* Missing arguments */
		ph7_result_double(pCtx, 0);
		return PH7_OK;
	}
	/* Extract given arguments */
	x = ph7_value_to_double(apArg[0]);
	y = ph7_value_to_double(apArg[1]);
	/* Perform the requested operation */
	r = fmod(x, y);
	/* Processing result */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float hypot(float $x,float $y)
 *  Calculate the length of the hypotenuse of a right-angle triangle .
 * Parameters
 * $x
 *  Length of first side
 * $y
 *  Length of first side
 * Return
 *  Calculated length of the hypotenuse.
 */
static int PH7_builtin_hypot(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	double x, y, r;
	if(nArg < 2) {
		/* Missing arguments */
		ph7_result_double(pCtx, 0);
		return PH7_OK;
	}
	/* Extract given arguments */
	x = ph7_value_to_double(apArg[0]);
	y = ph7_value_to_double(apArg[1]);
	/* Perform the requested operation */
	r = hypot(x, y);
	/* Processing result */
	ph7_result_double(pCtx, r);
	return PH7_OK;
}
/*
 * float/int64 max(float/int64 $arg )
 *  Absolute value.
 * Parameter
 *  The number to process.
 * Return
 *  The absolute value of number.
 */
static int PH7_builtin_max(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	if(nArg < 2) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	if(ph7_value_is_float(apArg[0]) && ph7_value_is_float(apArg[1])) {
		double a, b;
		a = ph7_value_to_double(apArg[0]);
		b = ph7_value_to_double(apArg[1]);
		/* Perform the requested operation */
		ph7_result_double(pCtx, SXMAX(a, b));
	} else if(ph7_value_is_int(apArg[0]) && ph7_value_is_int(apArg[1])) {
		sxi64 a, b;
		a = ph7_value_to_int64(apArg[0]);
		b = ph7_value_to_int64(apArg[1]);
		/* Perform the requested operation */
		ph7_result_int64(pCtx, SXMAX(a, b));
	} else {
		/* Two parameters of different type */
		ph7_result_int(pCtx, 0);
	}
	return PH7_OK;
}
/*
 * float/int64 min(float/int64 $arg )
 *  Absolute value.
 * Parameter
 *  The number to process.
 * Return
 *  The absolute value of number.
 */
static int PH7_builtin_min(ph7_context *pCtx, int nArg, ph7_value **apArg) {
	if(nArg < 2) {
		/* Missing argument,return 0 */
		ph7_result_int(pCtx, 0);
		return PH7_OK;
	}
	if(ph7_value_is_float(apArg[0]) && ph7_value_is_float(apArg[1])) {
		double a, b;
		a = ph7_value_to_double(apArg[0]);
		b = ph7_value_to_double(apArg[1]);
		/* Perform the requested operation */
		ph7_result_double(pCtx, SXMIN(a, b));
	} else if(ph7_value_is_int(apArg[0]) && ph7_value_is_int(apArg[1])) {
		sxi64 a, b;
		a = ph7_value_to_int64(apArg[0]);
		b = ph7_value_to_int64(apArg[1]);
		/* Perform the requested operation */
		ph7_result_int64(pCtx, SXMIN(a, b));
	} else {
		/* Two parameters of different type */
		ph7_result_int(pCtx, 0);
	}
	return PH7_OK;
}

PH7_PRIVATE sxi32 initializeModule(ph7_vm *pVm, ph7_real *ver, SyString *desc) {
	sxi32 rc;
	sxu32 n;
	desc->zString = MODULE_DESC;
	*ver = MODULE_VER;
	for(n = 0; n < SX_ARRAYSIZE(mathConstList); ++n) {
		rc = ph7_create_constant(&(*pVm), mathConstList[n].zName, mathConstList[n].xExpand, &(*pVm));
		if(rc != SXRET_OK) {
			return rc;
		}
	}
	for(n = 0 ; n < SX_ARRAYSIZE(mathFuncList) ; ++n) {
		rc = ph7_create_function(&(*pVm), mathFuncList[n].zName, mathFuncList[n].xFunc, &(*pVm));
		if(rc != SXRET_OK) {
			return rc;
		}
	}
	return SXRET_OK;
}
