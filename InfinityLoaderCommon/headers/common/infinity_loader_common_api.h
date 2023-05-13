
#pragma once

#include <functional>

#include "infinity_loader_common_types.h"

#if defined SHARED_MEMORY_DLL_HOST || defined SHARED_MEMORY_DLL
#include "shared_memory_dll.h"
#else
#include "shared_memory.h"
#endif

/////////////
// Structs //
/////////////

class AssemblyWriterImp;

class AssemblyWriter {
private:
	AssemblyWriterImp* imp;
public:
	IMPORT AssemblyWriter();
	IMPORT ~AssemblyWriter();
	IMPORT const unsigned char* GetBuffer();
	IMPORT uintptr_t GetCurrentLocation();
	IMPORT uintptr_t GetStartingLocation();
	IMPORT size_t GetSize();
	IMPORT void AlignStackAndMakeShadowSpace();
	IMPORT void CallToAddress(uintptr_t address);
	IMPORT void CallToAddressFar(uintptr_t address);
	IMPORT void Flush();
	IMPORT void JmpToAddress(uintptr_t address);
	IMPORT void JmpToAddressFar(uintptr_t address);
	IMPORT void PopVolatileRegisters();
	IMPORT void PrintBuffer();
	IMPORT void PushVolatileRegisters();
	IMPORT void SetLocation(uintptr_t newCurMemAddress);
	IMPORT void UndoAlignAndShadowSpace();
	IMPORT void WriteArgImmediate32(size_t argI, __int32 num);
	IMPORT void WriteBytesToBuffer(size_t numBytes, ...);
	IMPORT void WriteNumberToBuffer(uintptr_t pointer, size_t writeSize);
	IMPORT void WriteRelativeToBuffer32(uintptr_t relAddress);
};

/////////////
// Globals //
/////////////

EXTERN_IMPORT type_FPrint FPrint;
EXTERN_IMPORT type_FPrintT FPrintT;

//////////
// Init //
//////////

IMPORT DWORD CreateSharedMemory(HANDLE& hSharedFileOut, SharedMemory*& sharedOut);
IMPORT void InitSharedMemory(const HANDLE hSharedFileArg, SharedMemory *const sharedArg);

/////////////
// Logging //
/////////////

IMPORT int InitFPrint();
IMPORT void LogMessageBox(const TCHAR* toLog);
IMPORT void LogPrint(const TCHAR* toLog);

/////////////
// Utility //
/////////////

IMPORT void ForEveryCharSplit(const String& buffer, const TCHAR splitChar, std::function<bool(String)> action);
IMPORT void MessageBoxFormat(String caption, UINT uType, String formatText, ...);
IMPORT void MessageBoxFormatA(StringA caption, UINT uType, StringA formatText, ...);
IMPORT int UnbufferCrtStreams();
IMPORT void NulCrtStreams();
IMPORT void BindCrtStreamsToOSHandles();

//////////////////
// INI Handling //
//////////////////

IMPORT bool INISectionExists(const String& iniPath, const TCHAR *const section);

IMPORT DWORD GetINIStr(const String& iniPath, const TCHAR *const section, const TCHAR *const key, String& outStr, bool& filled);
IMPORT DWORD GetINIStrDef(const String& iniPath, const TCHAR *const section, const TCHAR *const key, const TCHAR *const def, String& outStr);

IMPORT bool DecStrToBool(const String& decimalStr, bool& result);
IMPORT bool DecStrToInt(const String& decimalStr, int& accumulator);
IMPORT bool DecStrToIntPtr(const String& decimalStr, intptr_t& accumulator);

IMPORT bool GetINILongLong(const String& iniPath, const TCHAR *const section, const TCHAR *const key, long long& outInteger, bool& filled);

IMPORT bool GetINIBoolDef(const String& iniPath, const TCHAR *const section, const TCHAR *const key, const bool def, bool& outInteger);
IMPORT bool GetINIIntDef(const String& iniPath, const TCHAR *const section, const TCHAR *const key, const int def, int& outInteger);
IMPORT bool GetINIIntPtrDef(const String& iniPath, const TCHAR *const section, const TCHAR *const key, const intptr_t def, intptr_t& outInteger);
IMPORT bool GetINIUIntPtrDef(const String& iniPath, const TCHAR *const section, const TCHAR *const key, const uintptr_t def, uintptr_t& outInteger);

IMPORT DWORD SetINIIntPtr(const String& iniPath, const TCHAR *const section, const TCHAR *const key, const intptr_t toSet);
IMPORT DWORD SetINILongLong(const String& iniPath, const TCHAR *const section, const TCHAR *const key, const long long toSet);

IMPORT StringA IntToDecStrA(const int integer);
IMPORT StringA PtrDiffToDecStrA(const ptrdiff_t integer);

///////////
// Paths //
///////////

IMPORT DWORD InitPaths(String& dbPath, String& exePath, String& exeName,
	String& iniPath, String& workingFolder, StringA& workingFolderA);

//////////////////////
// Assembly Writing //
//////////////////////

IMPORT DWORD AllocateNear(uintptr_t address, const size_t size, uintptr_t& allocatedOut);

////////////////////////
// String Conversions //
////////////////////////

IMPORT std::string WideStrToStr(const std::wstring& wstr);
IMPORT std::wstring StrToWideStr(const std::string& str);
IMPORT String NulTermStrToStr(const char* str);
IMPORT StringA StrToStrA(const String& string);

////////////////////////
// Exception Handling //
////////////////////////

IMPORT String WriteDump(const String& baseFolder, EXCEPTION_POINTERS* pointers);
