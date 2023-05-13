
#pragma once

#include "dll_api.h"
#include "infinity_loader_common_types.h"

/////////////
// Logging //
/////////////

constexpr size_t printBufferCount = 4096;

EXTERN_EXPORT type_FPrint FPrint;
EXTERN_EXPORT type_FPrintT FPrintT;

EXPORT void LogPrint(const TCHAR* toLog);

/////////////
// Utility //
/////////////

EXPORT void MessageBoxFormat(String caption, UINT uType, String formatText, ...);

///////////
// Paths //
///////////

extern String getMyPath();
