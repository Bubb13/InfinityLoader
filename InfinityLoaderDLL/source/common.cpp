
#include "InfinityLoaderCommon.cpp"
#include "pointers.h"
#include "bounds_exceeded.cpp"

instantiateBoundsExceeded(__int16)
instantiateBoundsExceeded(__int32)
instantiateBoundsExceeded(__int64)
instantiateBoundsExceeded(__int8)
instantiateBoundsExceeded(int)
instantiateBoundsExceeded(size_t)
instantiateBoundsExceeded(UINT)

template DWORD GetINIIntegerDef<bool>(String, const TCHAR*, const TCHAR*, bool, bool&);

template DWORD GetINIIntegerDef<intptr_t>(String, const TCHAR*, const TCHAR*, intptr_t, intptr_t&);
template DWORD SetINIInteger<intptr_t>(const String&, const TCHAR*, const TCHAR*, intptr_t);

template DWORD GetINIInteger<long long>(String, const TCHAR*, const TCHAR*, long long&, bool& filled);
template DWORD SetINIInteger<long long>(const String&, const TCHAR*, const TCHAR*, long long);
