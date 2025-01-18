
#pragma once

#include "dll_api.h"
#include "infinity_loader_common_types.h"

/////////////
// Logging //
/////////////

constexpr size_t printBufferCount = 4096;

EXPORT void FilePrint(FILE* file, const char* str);
EXPORT void FilePrintT(FILE* file, const TCHAR* str);

EXTERN_EXPORT type_FFilePrint FFilePrint;
EXTERN_EXPORT type_FFilePrintT FFilePrintT;

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
EXPORT DWORD SetINIStr(const String& iniPath, const TCHAR* section, const TCHAR* key, const String& toSet);

///////////
// Paths //
///////////

EXPORT DWORD InitPaths(String& dbPath, String& exePath, String& exeName, String& iniPath, String& workingFolder, StringA& workingFolderA);
String getMyPath();

////////////////////////
// String Conversions //
////////////////////////

EXPORT StringA StrToStrA(const String& string);
