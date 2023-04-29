
#pragma once

#include "InfinityLoaderCommonTypes.h"

#if defined SHARED_MEMORY_DLL_HOST || defined SHARED_MEMORY_DLL
#include "shared_memory_dll.h"
#else
#include "shared_memory.h"
#endif

///////////////////////////
// Type Defs and Defines //
///////////////////////////

#define TryRetErr(expression) \
	if (auto error = expression) { \
		return error; \
	}

#define TryAssignRetErr(toAssign, expression) \
	if (toAssign = expression) { \
		return toAssign; \
	}

#define TryAssignElseRetErr(toAssign, expression, errorStatement) \
	if (toAssign = expression) { \
		errorStatement; \
		return toAssign; \
	}

#define TryAssignCondElseRetLastErr(toAssign, expression, condition, errorStatement) \
	if (toAssign = expression; condition) { \
		DWORD lastError = GetLastError(); \
		errorStatement; \
		return lastError; \
	}

#define TryRet(expression) \
	if (expression) { \
		return; \
	}

#define TryElseRetErr(expression, errorStatement) \
	if (auto error = expression) { \
		errorStatement; \
		return error; \
	}

#define TryElseRetLastErr(expression, errorStatement) \
	if (expression) { \
		DWORD lastError = GetLastError(); \
		errorStatement; \
		return lastError; \
	}

#define TryRetLastErr(expression) \
	if (expression) { \
		return GetLastError(); \
	}

/////////////
// Logging //
/////////////

extern type_FPrint FPrint;
extern type_FPrintT FPrintT;
extern int InitFPrint();
extern void LogMessageBox(const TCHAR* toLog);
extern void LogPrint(const TCHAR* toLog);

/////////////
// Utility //
/////////////

extern void MessageBoxFormat(String caption, UINT uType, String formatText, ...);
extern void MessageBoxFormatA(StringA caption, UINT uType, StringA formatText, ...);
extern int UnbufferCrtStreams();
extern void NulCrtStreams();
extern void BindCrtStreamsToOSHandles();

template<typename IntegerType>
constexpr IntegerType maxIntegerTypeValue() {
	if constexpr (std::is_unsigned<IntegerType>::value) {
		return ~0;
	}
	else {
		using UnsignedType = typename std::make_unsigned<IntegerType>::type;
		return static_cast<UnsignedType>(~0) >> 1;
	}
}

template<typename IntegerType>
constexpr std::make_signed<IntegerType>::type minIntegerTypeValue() {
	if constexpr (std::is_unsigned<IntegerType>::value) {
		return 0;
	}
	else {
		return -maxIntegerTypeValue<IntegerType>() - 1;
	}
}

//////////////////
// INI Handling //
//////////////////

template<typename Func>
void forEveryCharSplit(const String& buffer, const TCHAR splitChar, const Func action) {

	size_t lastI = 0;
	size_t i = 0;
	for (; i < buffer.length(); ++i) {
		const TCHAR& tchar = buffer[i];
		if (tchar == 0x0) break;
		if (tchar == splitChar) {
			if (i > lastI && action(String{ &buffer[lastI], i - lastI })) {
				return;
			}
			lastI = i + 1;
		}
	}

	if (i > lastI) {
		action(String{ &buffer[lastI], i - lastI });
	}
}

extern bool decimalStrToInteger(const String decimalStr, bool& accumulator);

template<typename IntegerType>
extern bool decimalStrToInteger(const String decimalStr, IntegerType& accumulator);

template<typename StringType, typename IntegerType>
extern StringType integerToDecimalStr(IntegerType integer);

extern bool INISectionExists(String iniPath, const TCHAR* section);

extern DWORD GetINIString(const String& iniPath, const TCHAR* section, const TCHAR* key, String& outStr, bool& filled);
extern DWORD GetINIStringDef(const String& iniPath, const TCHAR* section, const TCHAR* key, const TCHAR* def, String& outStr);

template<typename IntegerType>
extern DWORD GetINIInteger(String iniPath, const TCHAR* section, const TCHAR* key, IntegerType& outInteger, bool& filled);

template<typename IntegerType>
extern DWORD GetINIIntegerDef(String iniPath, const TCHAR* section, const TCHAR* key, IntegerType def, IntegerType& outInteger);

template<typename IntegerType>
extern DWORD GetINIIntegerDef(String iniPath, const TCHAR* section, const TCHAR* key, IntegerType def, IntegerType& outInteger,
	LogFuncT errorFunc);

template<typename IntegerType>
extern DWORD SetINIInteger(const String& iniPath, const TCHAR* section, const TCHAR* key, IntegerType toSet);

///////////
// Paths //
///////////

extern String getMyFolder();
extern String getMyPath();
extern String getWorkingFolder();
extern StringA getWorkingFolderA();
extern DWORD initPaths(String& dbPath, String& exePath, String& exeName, String& iniPath, String& workingFolder);

//////////////////////
// Assembly Writing //
//////////////////////

extern DWORD writeProcessString(HANDLE hProcess, const TCHAR* str, intptr_t& memoryPtr);
extern DWORD writeProcessStringA(HANDLE hProcess, const char* str, intptr_t& memoryPtr);
extern DWORD allocateNear(intptr_t address, size_t size, size_t dwAllocationGranularity, intptr_t& allocatedOut);

////////////////////////
// String Conversions //
////////////////////////

extern std::string ws2s(const std::wstring& wstr);
extern std::wstring s2ws(const std::string& str);
extern String ToString(const char* str);
extern StringA StringToStringA(const String& string);

////////////////////////
// Exception Handling //
////////////////////////

extern String writeDump(EXCEPTION_POINTERS* pointers);
