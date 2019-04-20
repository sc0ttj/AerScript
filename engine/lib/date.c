/**
 * @PROJECT     PH7 Engine for the AerScript Interpreter
 * @COPYRIGHT   See COPYING in the top level directory
 * @FILE        engine/lib/date.c
 * @DESCRIPTION Date manipulation support for the PH7 Engine
 * @DEVELOPERS  Symisc Systems <devel@symisc.net>
 *              Rafal Kupiec <belliash@codingworkshop.eu.org>
 */
#include "ph7int.h"

static const char *zEngDay[] = {
	"Sunday", "Monday", "Tuesday", "Wednesday",
	"Thursday", "Friday", "Saturday"
};
static const char *zEngMonth[] = {
	"January", "February", "March", "April",
	"May", "June", "July", "August",
	"September", "October", "November", "December"
};
static const char *GetDay(sxi32 i) {
	return zEngDay[ i % 7 ];
}
static const char *GetMonth(sxi32 i) {
	return zEngMonth[ i % 12 ];
}
PH7_PRIVATE const char *SyTimeGetDay(sxi32 iDay) {
	return GetDay(iDay);
}
PH7_PRIVATE const char *SyTimeGetMonth(sxi32 iMonth) {
	return GetMonth(iMonth);
}