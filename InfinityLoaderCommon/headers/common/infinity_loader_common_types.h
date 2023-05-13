
#pragma once

#include <string>

#include "dll_api.h"

#include <Windows.h>

#ifdef INFINITY_LOADER_COMMON_EXPORT
#define INFINITY_LOADER_COMMON_API EXPORT
#define INFINITY_LOADER_COMMON_API_VAR EXTERN_EXPORT
#else
#define INFINITY_LOADER_COMMON_API IMPORT
#define INFINITY_LOADER_COMMON_API_VAR EXTERN_IMPORT
#endif

///////////////////////////
// Type Defs and Defines //
///////////////////////////

#ifndef UNICODE
typedef std::string String;
typedef std::string_view StringView;
typedef std::ostringstream OStringStream;
typedef std::ifstream IFStream;
//#define printfT printf
//#define fprintfT fprintf
#define strcmpT strcmp
#define strlenT strlen
#define _vsnprintfT_s _vsnprintf_s
#define toLowerT tolower
#else
typedef std::wstring String;
typedef std::wstring_view StringView;
typedef std::wostringstream OStringStream;
typedef std::wifstream IFStream;
//#define printfT wprintf
//#define fprintfT fwprintf
#define strcmpT wcscmp
#define strlenT wcslen
#define _vsnprintfT_s _vsnwprintf_s
#define toLowerT towlower
#endif

#define Print(...) FPrint(stdout, ##__VA_ARGS__)
#define PrintErr(...) FPrint(stderr, ##__VA_ARGS__)
#define PrintT(...) FPrintT(stdout, ##__VA_ARGS__)
#define PrintTErr(...) FPrintT(stderr, ##__VA_ARGS__)
typedef void (LogFuncT)(const TCHAR* toLog);

#define printf error
#define printfT error
#define fprintf error
#define fprintfT error

typedef std::string StringA;
typedef std::wstring StringW;
typedef std::ostringstream OStringStreamA;

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

typedef void(*type_FPrint)(FILE* file, const char* formatText, ...);
typedef void(*type_FPrintT)(FILE* file, const TCHAR* formatText, ...);

//////////////////
// INI Handling //
//////////////////

struct PatternEntry {
	String name;
	intptr_t value;
	INFINITY_LOADER_COMMON_API PatternEntry(const String str, const intptr_t val);
};

//////////////////////
// Assembly Writing //
//////////////////////

struct ImageSectionInfo {
	intptr_t ImageBase;
	char SectionName[IMAGE_SIZEOF_SHORT_NAME];
	void* SectionAddress;
	DWORD SectionSize;
};
