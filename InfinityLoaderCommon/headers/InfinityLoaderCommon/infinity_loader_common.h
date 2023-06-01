
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
EXPORT void MessageBoxFormatA(StringA caption, UINT uType, StringA formatText, ...);
EXPORT long long CurrentMicroseconds();

//////////////////
// INI Handling //
//////////////////

EXPORT DWORD GetINIStr(const String& iniPath, const TCHAR* section, const TCHAR* key, String& outStr, bool& filled);
EXPORT DWORD GetINIStrDef(const String& iniPath, const TCHAR* section, const TCHAR* key, const TCHAR* def, String& outStr);

///////////
// Paths //
///////////

EXPORT DWORD InitPaths(String& dbPath, String& exePath, String& exeName, String& iniPath, String& workingFolder, StringA& workingFolderA);
String getMyPath();
