
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

/////////////
// Globals //
/////////////

FILE* consoleOut;

static void FilePrint_NoConsole(FILE* file, const char* str); // Forward declaration
typedef void(*type_FilePrint)(FILE* file, const char* str);
type_FilePrint p_FilePrint = reinterpret_cast<type_FilePrint>(FilePrint_NoConsole); // Not fputs because the argument order is reversed

static void FilePrintT_NoConsole(FILE* file, const TCHAR* str); // Forward declaration
typedef void(*type_FilePrintT)(FILE* file, const TCHAR* str);
type_FilePrintT p_FilePrintT = reinterpret_cast<type_FilePrintT>(FilePrintT_NoConsole); // Not fputsT because the argument order is reversed

#undef fprintf
#undef fprintfT

#ifndef UNICODE
#define fprintfT fprintf
#else
#define fprintfT fwprintf
#endif

EXPORT type_FFilePrint FFilePrint = reinterpret_cast<type_FFilePrint>(fprintf);
EXPORT type_FFilePrintT FFilePrintT = reinterpret_cast<type_FFilePrintT>(fprintfT);

#define fprintf error
#undef fprintfT
#define fprintfT error

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

//-----------//
// FilePrint //
//-----------//

static void FilePrint_NoConsole(FILE* file, const char* str) {
	fputs(str, file);
}

static void FilePrint_Console(FILE* file, const char* str) {
	fputs(str, consoleOut);
	fputs(str, file);
}

static void FilePrintT_NoConsole(FILE* file, const TCHAR* str) {
	fputsT(str, file);
}

static void FilePrintT_Console(FILE* file, const TCHAR* str) {
	fputsT(str, consoleOut);
	fputsT(str, file);
}

EXPORT void FilePrint(FILE* file, const char* str) {
	p_FilePrint(file, str);
}

EXPORT void FilePrintT(FILE* file, const TCHAR* str) {
	p_FilePrintT(file, str);
}

//------------//
// FFilePrint //
//------------//

static void FFilePrint_NoConsole(FILE* file, const char* formatText, ...) {

	va_list args;
	char buffer[printBufferCount];

	va_start(args, formatText);
	int bytesWritten = _vsnprintf_s(buffer, _countof(buffer), _TRUNCATE, formatText, args);
	va_end(args);

	fputs(buffer, file);
}

static void FFilePrint_Console(FILE* file, const char* formatText, ...) {

	va_list args;
	char buffer[printBufferCount];
	constexpr DWORD count = _countof(buffer);

	va_start(args, formatText);
	int bytesWritten = _vsnprintf_s(buffer, count, _TRUNCATE, formatText, args);
	va_end(args);

	fputs(buffer, consoleOut);
	fputs(buffer, file);
}

static void FFilePrintT_NoConsole(FILE* file, const TCHAR* formatText, ...) {

	va_list args;
	TCHAR buffer[printBufferCount];

	va_start(args, formatText);
	int bytesWritten = _vsnprintfT_s(buffer, _countof(buffer), _TRUNCATE, formatText, args);
	va_end(args);

	fputsT(buffer, file);
}

static void FFilePrintT_Console(FILE* file, const TCHAR* formatText, ...) {

	va_list args;
	TCHAR buffer[printBufferCount];
	constexpr DWORD count = _countof(buffer);

	va_start(args, formatText);
	int bytesWritten = _vsnprintfT_s(buffer, count, _TRUNCATE, formatText, args);
	va_end(args);

	fputsT(buffer, consoleOut);
	fputsT(buffer, file);
}

//----------------//
// END FFilePrint //
//----------------//

static void initFPrintNoConsole() {

	p_FilePrint = FilePrint_NoConsole;
	p_FilePrintT = FilePrintT_NoConsole;

	FFilePrint = FFilePrint_NoConsole;
	FFilePrintT = FFilePrintT_NoConsole;

	if (debug()) {
		Print("[?][InfinityLoaderCommon.dll] InitFPrint() - NoConsole\n");
	}
}

EXPORT int InitFPrint() {

	if (GetFileType(GetStdHandle(STD_ERROR_HANDLE)) != FILE_TYPE_CHAR) {

		// STD_ERROR_HANDLE was redirected, try to open the console directly

		if (errno_t error = fopen_s(&consoleOut, "CONOUT$", "w")) {

			if (protonCompatibility()) {
				// Fallback when some Wine variants refuse to give us the console handle
				initFPrintNoConsole();
				return 0;
			}
			else{
				FPrint("[!][InfinityLoaderCommon.dll] InitFPrint() - fopen_s() failed (%d)\n", error);
				return error;
			}
		}

		p_FilePrint = FilePrint_Console;
		p_FilePrintT = FilePrintT_Console;

		FFilePrint = FFilePrint_Console;
		FFilePrintT = FFilePrintT_Console;

		if (int error = setvbuf(consoleOut, NULL, _IONBF, 0)) {
			FPrint("[!][InfinityLoaderCommon.dll] InitFPrint() - setvbuf() failed (%d)\n", error);
			return error;
		}

		if (debug()) {
			Print("[?][InfinityLoaderCommon.dll] InitFPrint() - Console\n");
		}
	}
	else {
		initFPrintNoConsole();
	}

	return 0;
}

EXPORT void LogMessageBox(const TCHAR* toLog) {
	MessageBoxFormat(TEXT("InfinityLoaderCommon.dll"), MB_ICONERROR, toLog);
}

EXPORT void LogPrint(const TCHAR* toLog) {
	FPrintT(TEXT("%s\n"), toLog);
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
		FPrint("[!][InfinityLoaderCommon.dll] UnbufferCrtStreams() - setvbuf() failed (%d)\n", error);
		return error;
	}

	if (int error = setvbuf(stdout, NULL, _IONBF, 0)) {
		FPrint("[!][InfinityLoaderCommon.dll] UnbufferCrtStreams() - setvbuf() failed (%d)\n", error);
		return error;
	}

	if (int error = setvbuf(stderr, NULL, _IONBF, 0)) {
		FPrint("[!][InfinityLoaderCommon.dll] UnbufferCrtStreams() - setvbuf() failed (%d)\n", error);
		return error;
	}

	return 0;
}

// Note 1)
//   * If:
//     * Application is of type 'console'
//     * The fileno is 0 (stdin), 1 (stdout), or 2 (stderr) and the os handle is valid
//     -> SetStdHandle(STD_INPUT_HANDLE/STD_OUTPUT_HANDLE/STD_ERROR_HANDLE, NULL)
//
// Note 2)
//   * If:
//     * Application is of type 'console'
//     * The fileno is 0 (stdin), 1 (stdout), or 2 (stderr) and the os handle is valid
//     -> SetStdHandle(STD_INPUT_HANDLE/STD_OUTPUT_HANDLE/STD_ERROR_HANDLE, <HANDLE>)
//
// Note 3)
//   * If:
//     * The fileno is 1 (stdout) or 2 (stderr) and the os handle is valid
//     * STD_OUTPUT_HANDLE != STD_ERROR_HANDLE
//     -> CloseHandle()
//
// Note 4)
//   * Only as error

////////////////////////////
// SetStdHandle() callers //
////////////////////////////
//------//
// Base //
//------//
// _close          | [Note 1]
// _dup            | [Note 2]
// _dup2           | [Note 1, Note 2]
// _fclose_nolock  | [Note 1]
// _open           | [Note 2]
// _open_osfhandle | [Note 2]
// _pipe           | [Note 2]
// _sopen          | [Note 2]
// _sopen_s        | [Note 2]
// _wopen          | [Note 2]
// _wsopen         | [Note 2]
// _wsopen_s       | [Note 2]
// fclose          | [Note 1]
//---------//
// Derived //
//---------//
// _creat          | [Note 2]
// _fcloseall      | [Note 1]
// _rmtmp          | [Note 1]
// _wcreat         | [Note 2]
// _wfopen         | [Note 2]
// _wfopen_s       | [Note 2]
// _wfreopen       | [Note 1, Note 2]
// _wfreopen_s     | [Note 1, Note 2]
// fopen           | [Note 2]
// fopen_s         | [Note 2]
// freopen         | [Note 1, Note 2]
// freopen_s       | [Note 1, Note 2]
// tmpfile         | [Note 1]
// tmpfile_s       | [Note 1]

///////////////////////////
// CloseHandle() callers //
///////////////////////////
//------//
// Base //
//------//
// _close         | [Note 3]
// _dup2          | [Note 3]
// _fclose_nolock | [Note 3]
// _open          | [Note 3, Note 4]
// _pipe          | [Note 4]
// _sopen         | [Note 3, Note 4]
// _sopen_s       | [Note 3, Note 4]
// _wopen         | [Note 3, Note 4]
// _wsopen        | [Note 3, Note 4]
// _wsopen_s      | [Note 3, Note 4]
// fclose         | [Note 3]
//---------//
// Derived //
//---------//
// _creat         | [Note 3, Note 4]
// _fcloseall     | [Note 3]
// _rmtmp         | [Note 3]
// _wcreat        | [Note 3, Note 4]
// _wfopen        | [Note 3, Note 4]
// _wfopen_s      | [Note 3, Note 4]
// _wfreopen      | [Note 3]
// _wfreopen_s    | [Note 3]
// fopen          | [Note 3, Note 4]
// fopen_s        | [Note 3, Note 4]
// freopen        | [Note 3]
// freopen_s      | [Note 3]
// tmpfile        | [Note 3, Note 4]
// tmpfile_s      | [Note 3, Note 4]

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

	// NulCrtStreams() will wipe these if the application type is 'console' - save them to restore later.
	// The crt is trying to be smart and keep the handles synchronized, but it just causes problems.
	const HANDLE stdInHandle = GetStdHandle(STD_INPUT_HANDLE);
	const HANDLE stdOutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	const HANDLE stdErrHandle = GetStdHandle(STD_ERROR_HANDLE);

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

	if (stdInHandle != INVALID_HANDLE_VALUE) {
		DupHandle(GetCurrentProcess(), stdInHandle, GetCurrentProcess(), handleDuplicate);
		if (int fd = _open_osfhandle(reinterpret_cast<intptr_t>(handleDuplicate), _O_TEXT); fd != -1) {
			if (_dup2(fd, _fileno(stdin)) == 0) {
				setvbuf(stdin, NULL, _IONBF, 0);
			}
			_close(fd);
		}
	}

	if (stdOutHandle != INVALID_HANDLE_VALUE) {
		DupHandle(GetCurrentProcess(), stdOutHandle, GetCurrentProcess(), handleDuplicate);
		if (int fd = _open_osfhandle(reinterpret_cast<intptr_t>(handleDuplicate), _O_TEXT); fd != -1) {
			if (_dup2(fd, _fileno(stdout)) == 0) {
				setvbuf(stdout, NULL, _IONBF, 0);
			}
			_close(fd);
		}
	}

	if (stdErrHandle != INVALID_HANDLE_VALUE) {
		DupHandle(GetCurrentProcess(), stdErrHandle, GetCurrentProcess(), handleDuplicate);
		if (int fd = _open_osfhandle(reinterpret_cast<intptr_t>(handleDuplicate), _O_TEXT); fd != -1) {
			if (_dup2(fd, _fileno(stderr)) == 0) {
				setvbuf(stderr, NULL, _IONBF, 0);
			}
			_close(fd);
		}
	}

	// Restore these in case NulCrtStreams() wiped them
	SetStdHandle(STD_INPUT_HANDLE, stdInHandle);
	SetStdHandle(STD_OUTPUT_HANDLE, stdOutHandle);
	SetStdHandle(STD_ERROR_HANDLE, stdErrHandle);
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

EXPORT size_t GrowDouble(const size_t size) {
	return size * 2;
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

	const bool handleValid = mappedMemoryHandle() != INVALID_HANDLE_VALUE;

	filled = false;

	// Try to use a stack buffer at first
	const DWORD initialBufferSize = 1024;
	TCHAR stackBuffer[initialBufferSize];

	// If the stack buffer is too small allocate one on the heap
	TCHAR* curBuffer = stackBuffer;
	DWORD curBufferSize = initialBufferSize;

	DWORD numRead = GetPrivateProfileString(section, key, nullptr,
		curBuffer, curBufferSize, iniPath.c_str());

	DWORD lastError = GetLastError();

	if (handleValid && protonCompatibility() && lastError == ERROR_SUCCESS && numRead == initialBufferSize - 1) {
		// Wine fails to flag ERROR_MORE_DATA so we might have actually truncated
		lastError = ERROR_MORE_DATA;
	}

	if (lastError == ERROR_SUCCESS || lastError == ERROR_FILE_NOT_FOUND) {
		if (numRead > 0) {
			outStr = curBuffer;
			filled = true;
		}
	}
	else if (lastError == ERROR_MORE_DATA) {

		// Stack buffer too small
		curBufferSize *= 2;
		curBuffer = new TCHAR[curBufferSize];

		while (true) {

			// Try again with the larger buffer
			numRead = GetPrivateProfileString(section, key, nullptr,
				curBuffer, curBufferSize, iniPath.c_str());

			lastError = GetLastError();

			if (handleValid && protonCompatibility() && lastError == ERROR_SUCCESS && numRead == initialBufferSize - 1) {
				// Wine fails to flag ERROR_MORE_DATA so we might have actually truncated
				lastError = ERROR_MORE_DATA;
			}

			if (lastError = GetLastError(); lastError == ERROR_SUCCESS || lastError == ERROR_FILE_NOT_FOUND) {
				if (numRead > 0) {
					outStr = curBuffer;
					filled = true;
				}
				delete[] curBuffer;
				break;
			}
			else if (lastError == ERROR_MORE_DATA) {
				// Still too small
				delete[] curBuffer;
				curBufferSize *= 2;
				curBuffer = new TCHAR[curBufferSize];
			}
			else {
				delete[] curBuffer;
				FPrint("[!][InfinityLoaderCommon.dll] GetINIStr() - GetPrivateProfileString() failed (%d)\n", lastError);
				return lastError;
			}
		}
	}
	else {
		FPrint("[!][InfinityLoaderCommon.dll] GetINIStr() - GetPrivateProfileString() failed (%d)\n", lastError);
		return lastError;
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

EXPORT DWORD SetINIStr(const String& iniPath, const TCHAR *const section, const TCHAR *const key, const String& toSet) {
	if (!WritePrivateProfileString(section, key, toSet.c_str(), iniPath.c_str())) {
		FPrintT(TEXT("[!][InfinityLoaderCommon.dll] SetINIStr() - Failed to set [%s].%s = %s\n"), section, key, toSet.c_str());
		return GetLastError();
	}
	return ERROR_SUCCESS;
}

///////////
// Paths //
///////////

static String getMyFolder() {
	const String myPath = getMyPath();
	return myPath.substr(0, myPath.length() - (myPath.length() - myPath.find_last_of('\\')) + 1);
}

static String getMyPath() {
	TCHAR fileName[MAX_PATH];
	GetModuleFileName(NULL, fileName, MAX_PATH);
	return String{ fileName };
}

static String getWorkingFolder() {
#ifndef UNICODE
	return std::filesystem::current_path().string().append(TEXT("\\"));
#else
	return std::filesystem::current_path().wstring().append(TEXT("\\"));
#endif
}

static StringA getWorkingFolderA() {
	return std::filesystem::current_path().string().append("\\");
}

static String getINIPath() {
	return String{ getWorkingFolder() }.append(TEXT("InfinityLoader.ini"));
}

static DWORD initExePath(const String& workingFolder, const String& iniPath, String& exePathOut, String& exeNameOut) {

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
		Print("[!][InfinityLoaderCommon.dll] initExePath() - Failed to find any of the executables defined by [General].ExeNames\n");
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
			FPrint("[!][InfinityLoaderCommon.dll] AllocateNear() - VirtualAlloc() failed (%d)\n", lastError);
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

const TCHAR *const sCrashWithLogFormat = TEXT(R"(Crash detected with error code 0x%X.

.dmp (big) saved to:

%s

.dmp (small) saved to:

%s

.log saved to:

%s

The game will exit after you press OK.)");

const TCHAR *const sCrashWithoutLogFormat = TEXT(R"(Crash detected with error code 0x%X.

.dmp (big) saved to:

%s

.dmp (small) saved to:

%s

The game will exit after you press OK.)");

EXPORT void DumpCrashInfo(EXCEPTION_POINTERS* pointers)
{
	///////////////////////
	// Find output paths //
	///////////////////////

	OStringStream dmpNameStream{};
	dmpNameStream << getWorkingFolder();
	dmpNameStream << "InfinityLoader_Crash";

	const String dmpFolderPath = dmpNameStream.str();

	if (!std::filesystem::exists(dmpFolderPath)) {
		std::filesystem::create_directory(dmpFolderPath);
	}

	String logName{};
	bool hasLogFile;
	GetINIStr(getINIPath(), TEXT("General"), TEXT("LogFile"), logName, hasLogFile); // Error intentionally ignored

	String builtDmpNameBig{};
	String builtDmpName{};
	String builtLogName{};

	for (size_t attemptI = 0; ; ++attemptI) {

		dmpNameStream.str(TEXT(""));
		dmpNameStream.clear();
		dmpNameStream << dmpFolderPath << "\\InfinityLoader_Crash_" << attemptI << "_big" << ".dmp";

		builtDmpNameBig = dmpNameStream.str();

		if (std::filesystem::exists(builtDmpNameBig)) {
			continue;
		}

		dmpNameStream.str(TEXT(""));
		dmpNameStream.clear();
		dmpNameStream << dmpFolderPath << "\\InfinityLoader_Crash_" << attemptI << "_small" << ".dmp";

		builtDmpName = dmpNameStream.str();

		if (std::filesystem::exists(builtDmpName)) {
			continue;
		}

		if (!hasLogFile) {
			break;
		}

		dmpNameStream.str(TEXT(""));
		dmpNameStream.clear();
		dmpNameStream << dmpFolderPath << "\\InfinityLoader_Crash_" << attemptI << ".log";

		builtLogName = dmpNameStream.str();

		if (!std::filesystem::exists(builtLogName)) {
			break;
		}
	}

	////////////////////////////////////
	// MINIDUMP_EXCEPTION_INFORMATION //
	////////////////////////////////////

	MINIDUMP_EXCEPTION_INFORMATION exceptionInfo{};
	exceptionInfo.ThreadId = GetCurrentThreadId();
	exceptionInfo.ExceptionPointers = pointers;
	exceptionInfo.ClientPointers = FALSE;

	////////////////////
	// Write big dump //
	////////////////////

	const HANDLE hFileBig = CreateFile(
		builtDmpNameBig.c_str(),
		GENERIC_WRITE,
		NULL,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	const MINIDUMP_TYPE bigDumpType = static_cast<MINIDUMP_TYPE>(
		  MiniDumpWithFullMemory
		| MiniDumpWithHandleData
		| MiniDumpWithUnloadedModules
		| MiniDumpWithProcessThreadData
		| MiniDumpWithFullMemoryInfo
		| MiniDumpWithThreadInfo
		| MiniDumpWithFullAuxiliaryState
		| MiniDumpIgnoreInaccessibleMemory
		| MiniDumpWithTokenInformation
	);

	MiniDumpWriteDump(
		GetCurrentProcess(),
		GetCurrentProcessId(),
		hFileBig,
		bigDumpType,
		&exceptionInfo,
		NULL,
		NULL
	);

	CloseHandle(hFileBig);

	//////////////////////
	// Write small dump //
	//////////////////////

	const HANDLE hFile = CreateFile(
		builtDmpName.c_str(),
		GENERIC_WRITE,
		NULL,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	const MINIDUMP_TYPE dumpType = static_cast<MINIDUMP_TYPE>(
		  MiniDumpWithDataSegs
		| MiniDumpWithIndirectlyReferencedMemory
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

	//////////////
	// Copy log //
	//////////////

	if (hasLogFile) {
		CopyFile(logName.c_str(), builtLogName.c_str(), FALSE);
	}

	/////////////////////////
	// Display message box //
	/////////////////////////

	const DWORD exceptionCode = pointers->ExceptionRecord->ExceptionCode;

	if (hasLogFile)
	{
		MessageBoxFormat(TEXT("InfinityLoaderCommon.dll"), MB_ICONERROR, sCrashWithLogFormat,
			exceptionCode, builtDmpNameBig.c_str(), builtDmpName.c_str(), builtLogName.c_str());
	}
	else
	{
		MessageBoxFormat(TEXT("InfinityLoaderCommon.dll"), MB_ICONERROR, sCrashWithoutLogFormat,
			exceptionCode, builtDmpNameBig.c_str(), builtDmpName.c_str());
	}
}
