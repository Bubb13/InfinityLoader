
#pragma once

#include <functional>
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
#define fputsT fputs
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
#define fputsT fputws
#define toLowerT towlower
#endif

#define Print(str) FilePrint(stdout, str)
#define PrintErr(str) FilePrint(stderr, str)
#define PrintT(str) FilePrintT(stdout, str)
#define PrintTErr(str) FilePrintT(stderr, str)
#define FPrint(...) FFilePrint(stdout, ##__VA_ARGS__)
#define FPrintErr(...) FFilePrint(stderr, ##__VA_ARGS__)
#define FPrintT(...) FFilePrintT(stdout, ##__VA_ARGS__)
#define FPrintTErr(...) FFilePrintT(stderr, ##__VA_ARGS__)
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

#define TryRetDefErrCode(expression) \
	if (!expression) { \
		return -1; \
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

#define TryRetFalsey(expression) \
	if (!expression) { \
		return; \
	}

#define TryRetErrFalsey(expression) \
	if (const auto result = expression; !result) { \
		return result; \
	}

#define TryRetTruthy(expression) \
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

typedef void(*type_FFilePrint)(FILE* file, const char* formatText, ...);
typedef void(*type_FFilePrintT)(FILE* file, const TCHAR* formatText, ...);

INFINITY_LOADER_COMMON_API_VAR type_FFilePrint FFilePrint;
INFINITY_LOADER_COMMON_API_VAR type_FFilePrintT FFilePrintT;

/////////////
// Utility //
/////////////

enum class TryFillBufferResult {
	GROW,
	DONE,
	ABORT,
};

template<typename BufferType>
void RunWithGrowingBuffer(
	const std::function<TryFillBufferResult(BufferType*, size_t)> tryFillBuffer,
	const std::function<size_t(size_t)> growSizeCompute,
	const std::function<void(BufferType*, size_t)> useBuffer)
{
	// Try to use a stack buffer at first
	const size_t initialBufferSize = 1024;
	BufferType stackBuffer[initialBufferSize];

	// If the stack buffer is too small allocate one on the heap
	BufferType* curBuffer = stackBuffer;
	size_t curBufferSize = initialBufferSize;

	if (const TryFillBufferResult result = tryFillBuffer(curBuffer, curBufferSize); result == TryFillBufferResult::DONE) {
		useBuffer(curBuffer, curBufferSize);
		return;
	}
	else if (result == TryFillBufferResult::ABORT) {
		return;
	}
	else if (result != TryFillBufferResult::GROW) {
		FPrint("[!][InfinityLoaderCommon.dll] RunWithGrowingBuffer() - Bad TryFillBufferResult (%d)\n", result);
		return;
	}

	// Stack buffer too small
	curBufferSize = growSizeCompute(curBufferSize);
	curBuffer = new BufferType[curBufferSize];

	while (true) {

		// Try again with the larger buffer
		if (const TryFillBufferResult result = tryFillBuffer(curBuffer, curBufferSize); result == TryFillBufferResult::DONE) {
			useBuffer(curBuffer, curBufferSize);
			delete[] curBuffer;
			return;
		}
		else if (result == TryFillBufferResult::ABORT) {
			return;
		}
		else if (result != TryFillBufferResult::GROW) {
			FPrint("[!][InfinityLoaderCommon.dll] RunWithGrowingBuffer() - Bad TryFillBufferResult (%d)\n", result);
			return;
		}

		// Still too small
		delete[] curBuffer;
		curBufferSize = growSizeCompute(curBufferSize);
		curBuffer = new BufferType[curBufferSize];
	}
}

INFINITY_LOADER_COMMON_API size_t GrowDouble(size_t size);

template<typename BufferType>
void RunWithGrowingBuffer(
	const std::function<TryFillBufferResult(BufferType*, size_t)> tryFillBuffer,
	const std::function<void(BufferType*, size_t)> useBuffer)
{
	RunWithGrowingBuffer(tryFillBuffer, GrowDouble, useBuffer);
}
