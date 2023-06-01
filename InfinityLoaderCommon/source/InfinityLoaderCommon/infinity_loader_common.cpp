
#include <codecvt>
#include <fcntl.h>
#include <filesystem>
#include <fstream>
#include <functional>
#include <io.h>
#include <iostream>
#include <ranges>

#include "infinity_loader_common.h"
#include "shared_state_mapped_memory.h"

#include <dbghelp.h>

//////////
// Init //
//////////

EXPORT DWORD CreateMappedMemory(HANDLE& mappedMemoryHandleOut, SharedStateMappedMemory& mappedMemoryOut) {
	TryRetErr( SharedStateMappedMemory::Create(mappedMemoryHandle(), mappedMemory()) )
	mappedMemoryHandleOut = mappedMemoryHandle();
	mappedMemoryOut = mappedMemory();
	return ERROR_SUCCESS;
}

EXPORT DWORD InitMappedMemory(HANDLE mappedMemoryHandle, SharedStateMappedMemory& mappedMemoryOut) {
	TryRetErr( SharedStateMappedMemory::CreateFromHandle(mappedMemoryHandle, mappedMemory()) )
	mappedMemoryHandle() = mappedMemoryHandle;
	mappedMemoryOut = mappedMemory();
	return ERROR_SUCCESS;
}

/////////////
// Logging //
/////////////

#undef fprintf
#undef fprintfT

#ifndef UNICODE
#define fprintfT fprintf
#else
#define fprintfT fwprintf
#endif

FILE* consoleOut;
EXPORT type_FPrint FPrint = reinterpret_cast<type_FPrint>(fprintf);
EXPORT type_FPrintT FPrintT = reinterpret_cast<type_FPrintT>(fprintfT);

void FPrintT_NoConsole(FILE* file, const TCHAR* formatText, ...) {

	va_list args;
	TCHAR buffer[printBufferCount];

	va_start(args, formatText);
	int bytesWritten = _vsnprintfT_s(buffer, _countof(buffer), _TRUNCATE, formatText, args);
	va_end(args);

	fprintfT(file, TEXT("%s"), buffer);
}

void FPrintT_Console(FILE* file, const TCHAR* formatText, ...) {

	va_list args;
	TCHAR buffer[printBufferCount];
	constexpr DWORD count = _countof(buffer);

	va_start(args, formatText);
	int bytesWritten = _vsnprintfT_s(buffer, count, _TRUNCATE, formatText, args);
	va_end(args);

	fprintfT(consoleOut, TEXT("%s"), buffer);
	fprintfT(file, TEXT("%s"), buffer);
}

void FPrint_NoConsole(FILE* file, const char* formatText, ...) {

	va_list args;
	char buffer[printBufferCount];

	va_start(args, formatText);
	int bytesWritten = _vsnprintf_s(buffer, _countof(buffer), _TRUNCATE, formatText, args);
	va_end(args);

	fprintf(file, "%s", buffer);
}

void FPrint_Console(FILE* file, const char* formatText, ...) {

	va_list args;
	char buffer[printBufferCount];
	constexpr DWORD count = _countof(buffer);

	va_start(args, formatText);
	int bytesWritten = _vsnprintf_s(buffer, count, _TRUNCATE, formatText, args);
	va_end(args);

	fprintf(consoleOut, "%s", buffer);
	fprintf(file, "%s", buffer);
}

#define fprintf error
#undef fprintfT
#define fprintfT error

EXPORT int InitFPrint() {

	if (GetFileType(GetStdHandle(STD_ERROR_HANDLE)) != FILE_TYPE_CHAR) {

		FPrint = FPrint_Console;
		FPrintT = FPrintT_Console;

		if (errno_t error = fopen_s(&consoleOut, "CONOUT$", "w")) {
			Print("[!] fopen_s failed (%d).\n", error);
			return error;
		}

		if (int error = setvbuf(consoleOut, NULL, _IONBF, 0)) {
			Print("[!] setvbuf failed (%d).\n", error);
			return error;
		}

		if (debug()) {
			Print("[?] InitFPrint() - Console\n");
		}
	}
	else {

		FPrint = FPrint_NoConsole;
		FPrintT = FPrintT_NoConsole;

		if (debug()) {
			Print("[?] InitFPrint() - NoConsole\n");
		}
	}

	return 0;
}

EXPORT void LogMessageBox(const TCHAR* toLog) {
	MessageBoxFormat(TEXT("InfinityLoader"), MB_ICONERROR, toLog);
}

EXPORT void LogPrint(const TCHAR* toLog) {
	PrintT(toLog);
	Print("\n");
}

/////////////
// Utility //
/////////////

EXPORT void ForEveryCharSplit(const String& buffer, const TCHAR splitChar, std::function<bool(String)> action) {

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

EXPORT void MessageBoxFormat(String caption, UINT uType, String formatText, ...) {

	va_list args;
	TCHAR buffer[1024];
	constexpr size_t count = _countof(buffer);

	va_start(args, formatText);
	int bytesWritten = _vsnprintfT_s(buffer, count, _TRUNCATE, formatText.c_str(), args);
	va_end(args);

	MessageBox(NULL, buffer, caption.c_str(), uType);
}

EXPORT void MessageBoxFormatA(StringA caption, UINT uType, StringA formatText, ...) {

	va_list args;
	char buffer[1024];
	constexpr size_t count = _countof(buffer);

	va_start(args, formatText);
	int bytesWritten = _vsnprintf_s(buffer, count, _TRUNCATE, formatText.c_str(), args);
	va_end(args);

	MessageBoxA(NULL, buffer, caption.c_str(), uType);
}

EXPORT int UnbufferCrtStreams() {

	if (int error = setvbuf(stdin, NULL, _IONBF, 0)) {
		Print("[!] setvbuf failed (%d).\n", error);
		return error;
	}

	if (int error = setvbuf(stdout, NULL, _IONBF, 0)) {
		Print("[!] setvbuf failed (%d).\n", error);
		return error;
	}

	if (int error = setvbuf(stderr, NULL, _IONBF, 0)) {
		Print("[!] setvbuf failed (%d).\n", error);
		return error;
	}

	return 0;
}

EXPORT void NulCrtStreams() {
	FILE* dummyFile;
	freopen_s(&dummyFile, "nul", "r", stdin);
	setvbuf(stdin, NULL, _IONBF, 0);
	std::wcin.clear();
	std::cin.clear();
	freopen_s(&dummyFile, "nul", "w", stdout);
	setvbuf(stdout, NULL, _IONBF, 0);
	std::wcout.clear();
	std::cout.clear();
	freopen_s(&dummyFile, "nul", "w", stderr);
	setvbuf(stderr, NULL, _IONBF, 0);
	std::wcerr.clear();
	std::cerr.clear();
}

EXPORT void BindCrtStreamsToOSHandles() {

	// The below info has been determined via reversing ucrtbase.dll and KernelBase.dll.
	//
	// AttachConsole(): Attaches a console and sets STD_INPUT_HANDLE, STD_OUTPUT_HANDLE, and STD_ERROR_HANDLE
	//                  (as if through SetStdHandle()). Note: KernelBase.dll caches STD_INPUT_HANDLE,
	//                  STD_OUTPUT_HANDLE, and STD_ERROR_HANDLE at the time of console initialization,
	//                  meaning those exact handles MUST stay valid for when the console is eventually cleaned
	//                  up, else INVALID_HANDLE_VALUE will be thrown on FreeConsole() or equivalent.
	//
	// _open_osfhandle(): Creates and assigns a new file descriptor that points to the OS handle.
	//
	// _dup2(): _close()'s the dst file descriptor, (which also CloseHandle()'s the dst fd's OS handle), and
	//          copies the src fd to the dst fd, (including DuplicateHandle()'ing the contained OS handle).
	//
	// The strategy:
	//
	//   1) _dup2() only works when the dst file descriptor exists. Specifically, invalid FILE* streams return
	//      -2 when _fileno() is called on them. Calling freopen_s() to ensure stdin/stdout/stderr are
	//      initialized to valid file descriptors.
	//
	//   2) Calling DuplicateHandle() for the current STD_INPUT_HANDLE/STD_OUTPUT_HANDLE/STD_ERROR_HANDLE.
	//      The OS handle used by _dup2() to initialize stdin/stdout/stderr, (which itself is duplicated
	//      internally by _dup2()), is closed later as a side effect of _close()'ing the temporarily-allocated
	//      src file descriptor for _dup2(). Since AttachConsole() caches STD_INPUT_HANDLE/STD_OUTPUT_HANDLE/
	//      STD_ERROR_HANDLE, the current OS file handle MUST stay open.
	//
	//   3) _open_osfhandle() allocates and creates a file descriptor that contains the OS handle we want to
	//      assign to stdin/stdout/stderr. Since there is no direct way to update a file descriptor to use a
	//      new OS handle, a new file descriptor has to be created for use with _dup2().
	//
	//   4) _dup2() is used to actually assign the OS handle to the dst file descriptor.
	//
	//   5) setvbuf() updates the stream's buffering mode to be unbuffered.
	//
	//   6) _close() the temporarily-allocated src file descriptor as to not leak objects. Note that this
	//      also closes the contained OS handle, which is why it had to be duplicated above.
	//
	//   7) Clear any error states from the C++ stream objects so they start working with the new file descriptor.

	NulCrtStreams();

#define DupHandle(srcProcess,srcHandle,targetProcess,targetHandle)\
	DuplicateHandle(\
		srcProcess,\
		srcHandle,\
		targetProcess,\
		&targetHandle,\
		NULL,\
		false,\
		DUPLICATE_SAME_ACCESS\
	);

	HANDLE handleDuplicate;

	HANDLE stdInHandle = GetStdHandle(STD_INPUT_HANDLE);
	if (stdInHandle != INVALID_HANDLE_VALUE) {
		DupHandle(GetCurrentProcess(), stdInHandle, GetCurrentProcess(), handleDuplicate);
		if (int fd = _open_osfhandle(reinterpret_cast<intptr_t>(handleDuplicate), _O_TEXT); fd != -1) {
			if (_dup2(fd, _fileno(stdin)) == 0) {
				setvbuf(stdin, NULL, _IONBF, 0);
			}
			_close(fd);
		}
	}

	HANDLE stdOutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (stdOutHandle != INVALID_HANDLE_VALUE) {
		DupHandle(GetCurrentProcess(), stdOutHandle, GetCurrentProcess(), handleDuplicate);
		if (int fd = _open_osfhandle(reinterpret_cast<intptr_t>(handleDuplicate), _O_TEXT); fd != -1) {
			if (_dup2(fd, _fileno(stdout)) == 0) {
				setvbuf(stdout, NULL, _IONBF, 0);
			}
			_close(fd);
		}
	}

	HANDLE stdErrHandle = GetStdHandle(STD_ERROR_HANDLE);
	if (stdErrHandle != INVALID_HANDLE_VALUE) {
		DupHandle(GetCurrentProcess(), stdErrHandle, GetCurrentProcess(), handleDuplicate);
		if (int fd = _open_osfhandle(reinterpret_cast<intptr_t>(handleDuplicate), _O_TEXT); fd != -1) {
			if (_dup2(fd, _fileno(stderr)) == 0) {
				setvbuf(stderr, NULL, _IONBF, 0);
			}
			_close(fd);
		}
	}
}

void TrimString(String& str) {

	const size_t strSize = str.size();

	if (strSize == 0) {
		return;
	}

	const TCHAR *const cStr = str.c_str();
	size_t startIndex;
	size_t curIndex = 0;
	TCHAR curChar;

	for (; curIndex < strSize; ++curIndex) {
		curChar = cStr[curIndex];
		if (curChar != TCHAR{' '} && curChar != TCHAR{'\t'}) {
			break;
		}
	}

	startIndex = curIndex;
	curIndex = strSize;

	for (curIndex = strSize; curIndex > 0; --curIndex) {
		curChar = cStr[curIndex - 1];
		if (curChar != TCHAR{' '} && curChar != TCHAR{'\t'}) {
			break;
		}
	}

	str.erase(0, startIndex);
	str.erase(curIndex - startIndex, strSize - startIndex);
}

bool CaseInsensitiveEquals(const StringView& lhs, const StringView& rhs) {
	auto toLowerTransform{ std::ranges::views::transform(toLowerT) };
	return std::ranges::equal(lhs | toLowerTransform, rhs | toLowerTransform);
}

EXPORT long long CurrentMicroseconds() {
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

//////////////////
// INI Handling //
//////////////////

EXPORT bool INISectionExists(const String& iniPath, const TCHAR* section) {

	const StringView sectionView{ section };

	IFStream inputStream{};
	inputStream.open(iniPath);

	if (inputStream.good()) {

		// 0 = Searching for '['
		// 1 = Found '[', searching for ']'
		// 2 = Ignoring line
		byte state = 0;

		String currentSectionName{};
		TCHAR newChar;

		while (!inputStream.eof()) {

			inputStream.read(&newChar, 1);

			if (inputStream.bad()) {
				break;
			}

			if (newChar == TCHAR{'\n'}) {
				if (state == 1) {
					currentSectionName.clear();
				}
				state = 0;
			}
			else {
				if (state == 0) {
					if (newChar == TCHAR{'['}) {
						state = 1;
					}
					else if (newChar != TCHAR{' '} && newChar != TCHAR{'\t'}) {
						state = 2;
					}
				}
				else if (state == 1) {
					if (newChar == TCHAR{']'}) {
						TrimString(currentSectionName);
						if (CaseInsensitiveEquals(currentSectionName, sectionView)) {
							return true;
						}
						currentSectionName.clear();
						state = 2;
					}
					else {
						currentSectionName.push_back(newChar);
					}
				}
			}
		}
	}

	return false;
}

EXPORT DWORD GetINIStr(const String& iniPath, const TCHAR* section, const TCHAR* key, String& outStr, bool& filled) {

	filled = false;

	TCHAR buffer[1024];
	const std::size_t bufferSize = sizeof(buffer) / sizeof(buffer[0]);

	DWORD numRead = GetPrivateProfileString(section, key, nullptr,
		buffer, bufferSize, iniPath.c_str());

	if (DWORD lastError = GetLastError(); lastError != ERROR_SUCCESS && lastError != ERROR_FILE_NOT_FOUND) {
		Print("[!] GetPrivateProfileString failed (%d).\n", lastError);
		return lastError;
	}

	if (numRead > 0) {
		outStr = buffer;
		filled = true;
	}

	return 0;
}

EXPORT DWORD GetINIStrDef(const String& iniPath, const TCHAR* section, const TCHAR* key, const TCHAR* def, String& outStr) {
	bool filled;
	DWORD error = GetINIStr(iniPath, section, key, outStr, filled);
	if (!filled) {
		outStr = def;
	}
	return error;
}

///////////
// Paths //
///////////

String getMyFolder() {
	String myPath = getMyPath();
	return myPath.substr(0, myPath.length() - (myPath.length() - myPath.find_last_of('\\')) + 1);
}

String getMyPath() {
	TCHAR fileName[MAX_PATH];
	GetModuleFileName(NULL, fileName, MAX_PATH);
	return String(fileName);
}

String getWorkingFolder() {
#ifndef UNICODE
	return std::filesystem::current_path().string().append(TEXT("\\"));
#else
	return std::filesystem::current_path().wstring().append(TEXT("\\"));
#endif
}

StringA getWorkingFolderA() {
	return std::filesystem::current_path().string().append("\\");
}

DWORD initExePath(const String& workingFolder, const String& iniPath, String& exePathOut, String& exeNameOut) {

	String exeNames;
	TryRetErr( GetINIStrDef(iniPath, TEXT("General"), TEXT("ExeNames"), TEXT(""), exeNames) )

	DWORD result = -1;
	ForEveryCharSplit(exeNames, TCHAR{ ',' }, [&](const String str) {

		const String checkingFor = String{ workingFolder }.append(str);
		if (std::filesystem::exists(checkingFor)) {
			exePathOut = checkingFor;
			exeNameOut = str;
			result = 0;
			return true;
		}
		return false;
	});

	if (result) {
		Print("[!] Failed to find any of the executables defined by [General].ExeNames.\n");
	}

	return result;
}

EXPORT DWORD InitPaths(String& dbPath, String& exePath, String& exeName,
	String& iniPath, String& workingFolder, StringA& workingFolderA)
{
	workingFolder = getWorkingFolder();
	workingFolderA = getWorkingFolderA();
	dbPath = String{ workingFolder }.append(TEXT("InfinityLoader.db"));
	iniPath = String{ workingFolder }.append(TEXT("InfinityLoader.ini"));
	return initExePath(workingFolder, iniPath, exePath, exeName);
}

EXPORT DWORD AllocateNear(uintptr_t address, size_t size, uintptr_t& allocatedOut) {

	SYSTEM_INFO info;
	GetSystemInfo(&info);

	while (true) {

		allocatedOut = reinterpret_cast<uintptr_t>(VirtualAlloc(reinterpret_cast<void*>(address),
			size, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));

		if (allocatedOut) {
			break;
		}

		if (DWORD lastError = GetLastError(); lastError != ERROR_INVALID_ADDRESS) {
			Print("[!] VirtualAlloc failed (%d).\n", lastError);
			return lastError;
		}

		address -= info.dwAllocationGranularity;
	}

	return 0;
}

////////////////////////
// String Conversions //
////////////////////////

EXPORT std::string WideStrToStr(const std::wstring& wstr) {
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
	return convert.to_bytes(wstr);
}

EXPORT std::wstring StrToWideStr(const std::string& str) {
	std::wstring newStr;
	return newStr.assign(str.begin(), str.end());
}

EXPORT String NulTermStrToStr(const char* str) {
#ifndef UNICODE
	return String{ str };
#else
	return String{ StrToWideStr(str) };
#endif
}

EXPORT StringA StrToStrA(const String& string) {
#ifndef UNICODE
	return string;
#else
	return WideStrToStr(string);
#endif
}

////////////////////////
// Exception Handling //
////////////////////////

EXPORT String WriteDump(const String& baseFolder, EXCEPTION_POINTERS* pointers)
{
	//const MINIDUMP_TYPE dumpType = static_cast<MINIDUMP_TYPE>(
	//      MiniDumpWithFullMemory
	//    | MiniDumpWithHandleData
	//    | MiniDumpWithUnloadedModules
	//    | MiniDumpWithProcessThreadData
	//    | MiniDumpWithFullMemoryInfo
	//    | MiniDumpWithThreadInfo
	//    | MiniDumpWithFullAuxiliaryState
	//    | MiniDumpIgnoreInaccessibleMemory
	//    | MiniDumpWithTokenInformation
	//);

	const MINIDUMP_TYPE dumpType = static_cast<MINIDUMP_TYPE>(MiniDumpWithDataSegs | MiniDumpWithIndirectlyReferencedMemory);

	MINIDUMP_EXCEPTION_INFORMATION exceptionInfo{};
	exceptionInfo.ThreadId = GetCurrentThreadId();
	exceptionInfo.ExceptionPointers = pointers;
	exceptionInfo.ClientPointers = FALSE;

	OStringStream dmpNameStream{ String{ baseFolder }.append(TEXT("InfinityLoader_Crash"))};
	String builtDmpName = dmpNameStream.str();

	if (!std::filesystem::exists(builtDmpName)) {
		std::filesystem::create_directory(builtDmpName);
	}

	size_t attemptI = 0;

	while (true) {

		dmpNameStream << baseFolder;
		dmpNameStream << "InfinityLoader_Crash\\InfinityLoader_Crash_";
		dmpNameStream << attemptI++;
		dmpNameStream << ".dmp";
		builtDmpName = dmpNameStream.str();

		if (!std::filesystem::exists(builtDmpName)) {
			break;
		}

		dmpNameStream.str(TEXT(""));
		dmpNameStream.clear();
	}

	HANDLE hFile = CreateFile(
		builtDmpName.c_str(),
		GENERIC_WRITE,
		NULL,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	MiniDumpWriteDump(
		GetCurrentProcess(),
		GetCurrentProcessId(),
		hFile,
		dumpType,
		&exceptionInfo,
		NULL,
		NULL
	);

	CloseHandle(hFile);
	return builtDmpName;
}
