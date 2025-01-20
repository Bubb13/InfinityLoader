
#pragma once

#include <functional>

#include "infinity_loader_common_types.h"
#include "opaque_object_api.h"
#include "shared_state_api.h"

/////////////
// Structs //
/////////////

class AssemblyWriter {
private:
	void* imp;
public:
	OpaqueObjectBoilerplateAPIDef(AssemblyWriter)
	IMPORT static AssemblyWriter Create();
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

//////////
// Init //
//////////

IMPORT DWORD CreateMappedMemory(HANDLE& mappedMemoryHandleOut, SharedStateMappedMemory& mappedMemoryOut);
IMPORT DWORD InitMappedMemory(HANDLE mappedMemoryHandle, SharedStateMappedMemory& mappedMemoryOut);

/////////////
// Logging //
/////////////

IMPORT int InitFPrint();
IMPORT void FilePrint(FILE* file, const char* str);
IMPORT void FilePrintT(FILE* file, const TCHAR* str);
IMPORT void LogMessageBox(const TCHAR* toLog);
IMPORT void LogPrint(const TCHAR* toLog);

/////////////
// Utility //
/////////////

IMPORT void ForEveryCharSplit(const String& buffer, TCHAR splitChar, std::function<bool(String)> action);
IMPORT void MessageBoxFormat(String caption, UINT uType, String formatText, ...);
IMPORT void MessageBoxFormatA(StringA caption, UINT uType, StringA formatText, ...);
IMPORT int UnbufferCrtStreams();
IMPORT void NulCrtStreams();
IMPORT void BindCrtStreamsToOSHandles();
IMPORT long long CurrentMicroseconds();

//////////////////
// INI Handling //
//////////////////

IMPORT DWORD GetINIStr(const String& iniPath, const TCHAR* section, const TCHAR* key, String& outStr, bool& filled);
IMPORT bool GetINILongLong(const String& iniPath, const TCHAR* section, const TCHAR* key, long long& outInteger, bool& filled);

IMPORT DWORD GetINIStrDef(const String& iniPath, const TCHAR* section, const TCHAR* key, const TCHAR* def, String& outStr);
IMPORT bool GetINIBoolDef(const String& iniPath, const TCHAR* section, const TCHAR* key, bool def, bool& outInteger);
IMPORT bool GetINIIntDef(const String& iniPath, const TCHAR* section, const TCHAR* key, int def, int& outInteger);
IMPORT bool GetINIIntPtrDef(const String& iniPath, const TCHAR* section, const TCHAR* key, intptr_t def, intptr_t& outInteger);
IMPORT bool GetINIUIntPtrDef(const String& iniPath, const TCHAR* section, const TCHAR* key, uintptr_t def, uintptr_t& outInteger);

IMPORT bool INISectionExists(const String& iniPath, const TCHAR* section);

IMPORT DWORD SetINIStr(const String& iniPath, const TCHAR* section, const TCHAR* key, const String& toSet);
IMPORT DWORD SetINIIntPtr(const String& iniPath, const TCHAR* section, const TCHAR* key, intptr_t toSet);
IMPORT DWORD SetINILongLong(const String& iniPath, const TCHAR* section, const TCHAR* key, long long toSet);
IMPORT DWORD SetINIUIntPtr(const String& iniPath, const TCHAR* section, const TCHAR* key, uintptr_t toSet);

IMPORT bool DecStrToBool(const String& decimalStr, bool& result);
IMPORT bool DecStrToInt(const String& decimalStr, int& accumulator);
IMPORT bool DecStrToIntPtr(const String& decimalStr, intptr_t& accumulator);
IMPORT bool DecStrToUIntPtr(const String& decimalStr, uintptr_t& accumulator);

IMPORT StringA IntToDecStrA(int integer);
IMPORT StringA PtrDiffToDecStrA(ptrdiff_t integer);
IMPORT String UIntPtrToDecStr(uintptr_t integer);

///////////
// Paths //
///////////

IMPORT DWORD InitPaths(String& dbPath, String& exePath, String& exeName,
	String& iniPath, String& workingFolder, StringA& workingFolderA);

//////////////////////
// Assembly Writing //
//////////////////////

IMPORT DWORD AllocateNear(uintptr_t address, size_t size, uintptr_t& allocatedOut);

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
