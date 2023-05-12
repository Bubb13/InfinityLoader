
#pragma once

#include <functional>

#include "InfinityLoaderCommonTypes.h"
#include "dll_api.h"

#if defined SHARED_MEMORY_DLL_HOST || defined SHARED_MEMORY_DLL
#include "shared_memory_dll.h"
#else
#include "shared_memory.h"
#endif

/////////////
// Logging //
/////////////

constexpr size_t printBufferCount = 4096;

EXTERN_EXPORT type_FPrint FPrint;
EXTERN_EXPORT type_FPrintT FPrintT;
EXTERN_EXPORT int InitFPrint();
EXTERN_EXPORT void LogMessageBox(const TCHAR* toLog);
EXTERN_EXPORT void LogPrint(const TCHAR* toLog);

/////////////
// Utility //
/////////////

EXPORT void ForEveryCharSplit(const String& buffer, const TCHAR splitChar, std::function<bool(String)> action);
EXTERN_EXPORT void MessageBoxFormat(String caption, UINT uType, String formatText, ...);
EXTERN_EXPORT void MessageBoxFormatA(StringA caption, UINT uType, StringA formatText, ...);
EXTERN_EXPORT int UnbufferCrtStreams();
EXTERN_EXPORT void NulCrtStreams();
EXTERN_EXPORT void BindCrtStreamsToOSHandles();

//////////////////
// INI Handling //
//////////////////

//EXTERN_EXPORT bool DecStrToBool(const String& decimalStr, bool& result);
//EXTERN_EXPORT bool DecStrToInt(const String& decimalStr, int& accumulator);
//EXTERN_EXPORT bool GetINIBoolDef(const String& iniPath, const TCHAR* section, const TCHAR* key, bool def, bool& outInteger);

//extern bool DecStrToBool(const String decimalStr, bool& result);

EXTERN_EXPORT bool INISectionExists(const String& iniPath, const TCHAR *const section);

//extern DWORD GetINIString(const String& iniPath, const TCHAR* section, const TCHAR* key, String& outStr, bool& filled);
//extern DWORD GetINIStringDef(const String& iniPath, const TCHAR* section, const TCHAR* key, const TCHAR* def, String& outStr);

///////////
// Paths //
///////////

extern String getMyFolder();
extern String getMyPath();
extern String getWorkingFolder();
extern StringA getWorkingFolderA();
EXTERN_EXPORT DWORD InitPaths(String& dbPath, String& exePath, String& exeName,
	String& iniPath, String& workingFolder, StringA& workingFolderA);

//////////////////////
// Assembly Writing //
//////////////////////

extern DWORD writeProcessString(HANDLE hProcess, const TCHAR* str, intptr_t& memoryPtr);
extern DWORD writeProcessStringA(HANDLE hProcess, const char* str, intptr_t& memoryPtr);
extern DWORD allocateNear(intptr_t address, size_t size, size_t dwAllocationGranularity, intptr_t& allocatedOut);

////////////////////////
// String Conversions //
////////////////////////

EXPORT std::string WideStrToStr(const std::wstring& wstr);
EXPORT std::wstring StrToWideStr(const std::string& str);
EXPORT String NulTermStrToStr(const char* str);
EXPORT StringA StrToStrA(const String& string);

////////////////////////
// Exception Handling //
////////////////////////

EXTERN_EXPORT String WriteDump(const String& baseFolder, EXCEPTION_POINTERS* pointers);
