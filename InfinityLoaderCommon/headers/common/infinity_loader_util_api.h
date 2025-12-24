
#pragma once

#include <Windows.h>

#include "dll_api.h"

//////////
// Main //
//////////

IMPORT DWORD InitUtil(SharedState argSharedState);

////////////////////////
// Exception Handling //
////////////////////////

IMPORT void DumpCrashInfo(EXCEPTION_POINTERS* pointers);
