#include "ph7int.h"
#if defined(__WINNT__)
	#include <Windows.h>
#else
	#include <stdlib.h>
#endif

void *SyOSHeapAlloc(sxu32 nByte) {
	void *pNew;
#if defined(__WINNT__)
	pNew = HeapAlloc(GetProcessHeap(), 0, nByte);
#else
	pNew = malloc((size_t)nByte);
#endif
	return pNew;
}
void *SyOSHeapRealloc(void *pOld, sxu32 nByte) {
	void *pNew;
#if defined(__WINNT__)
	pNew = HeapReAlloc(GetProcessHeap(), 0, pOld, nByte);
#else
	pNew = realloc(pOld, (size_t)nByte);
#endif
	return pNew;
}
void SyOSHeapFree(void *pPtr) {
#if defined(__WINNT__)
	HeapFree(GetProcessHeap(), 0, pPtr);
#else
	free(pPtr);
#endif
}