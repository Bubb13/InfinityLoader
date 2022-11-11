
#include <InfinityLoaderCommon.cpp>

template DWORD GetINIIntegerDef<bool>(String, const TCHAR*, const TCHAR*, bool, bool&);

template DWORD GetINIIntegerDef<intptr_t>(String, const TCHAR*, const TCHAR*, intptr_t, intptr_t&);
template DWORD SetINIInteger<intptr_t>(String, const TCHAR*, const TCHAR*, intptr_t);

template DWORD GetINIInteger<long long>(String, const TCHAR*, const TCHAR*, long long&, bool& filled);
template DWORD SetINIInteger<long long>(String, const TCHAR*, const TCHAR*, long long);
