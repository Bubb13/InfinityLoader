#include "InfinityLoaderCommon.cpp"
#include "InfinityLoaderCommonSharedMemory.cpp"
template DWORD GetINIIntegerDef(String, const TCHAR*, const TCHAR*, bool, bool&);
template DWORD GetINIIntegerDef(String, const TCHAR*, const TCHAR*, intptr_t, intptr_t&);