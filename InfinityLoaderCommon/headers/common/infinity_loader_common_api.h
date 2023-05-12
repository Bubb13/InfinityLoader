
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
// Structs //
/////////////

class AssemblyWriter {
private:
	unsigned char* buffer;
	size_t curI;
	intptr_t startMemAddress;
	intptr_t curMemAddress;
public:
	IMPORT AssemblyWriter(unsigned char* buff);
	IMPORT intptr_t getLocation();
	IMPORT void setLocation(intptr_t newCurMemAddress);
	IMPORT void writeBytesToBuffer(int numBytes, ...);
	IMPORT void writeNumberToBuffer(intptr_t pointer, size_t writeSize);
	IMPORT void writeRelativeToBuffer32(intptr_t relAddress);
	IMPORT void branchUsingIndirect64(intptr_t destAddress, unsigned char branchOpcode);
	IMPORT void writeArgImmediate32(__int32 num, int argI);
	IMPORT void jmpToAddressFar(intptr_t address);
	IMPORT void jmpToAddress(intptr_t address);
	IMPORT void callToAddressFar(intptr_t address);
	IMPORT void callToAddress(intptr_t address);
	IMPORT void alignStackAndMakeShadowSpace();
	IMPORT void undoAlignAndShadowSpace();
	IMPORT void pushVolatileRegisters();
	IMPORT void popVolatileRegisters();
	IMPORT void printBuffer();
	IMPORT void flush();
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

IMPORT DWORD SetINIIntPtr(const String& iniPath, const TCHAR *const section, const TCHAR *const key, const intptr_t toSet);
IMPORT DWORD SetINILongLong(const String& iniPath, const TCHAR *const section, const TCHAR *const key, const long long toSet);

IMPORT StringA IntToDecStrA(const int integer);
IMPORT StringA PtrDiffToDecStrA(const ptrdiff_t integer);

///////////
// Paths //
///////////

//extern String getMyFolder();
//extern String getMyPath();
//extern String getWorkingFolder();
//extern StringA getWorkingFolderA();
IMPORT DWORD InitPaths(String& dbPath, String& exePath, String& exeName,
	String& iniPath, String& workingFolder, StringA& workingFolderA);

//////////////////////
// Assembly Writing //
//////////////////////

//extern DWORD writeProcessString(HANDLE hProcess, const TCHAR* str, intptr_t& memoryPtr);
//extern DWORD writeProcessStringA(HANDLE hProcess, const char* str, intptr_t& memoryPtr);
IMPORT DWORD AllocateNear(intptr_t address, size_t size, intptr_t& allocatedOut);

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
