
#include "InfinityLoaderCommon.h"

#include <fcntl.h>
#include <fstream>
#include <io.h>
#include <iostream>
#include <ranges>

/////////////
// Globals //
/////////////

String dbPath;
String iniPath;
String workingFolder;

const std::pair<const TCHAR, const unsigned char> aDecimalDigitToByte[] = {
	std::pair{TCHAR{'0'}, 0},
	std::pair{TCHAR{'1'}, 1},
	std::pair{TCHAR{'2'}, 2},
	std::pair{TCHAR{'3'}, 3},
	std::pair{TCHAR{'4'}, 4},
	std::pair{TCHAR{'5'}, 5},
	std::pair{TCHAR{'6'}, 6},
	std::pair{TCHAR{'7'}, 7},
	std::pair{TCHAR{'8'}, 8},
	std::pair{TCHAR{'9'}, 9},
};

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

constexpr size_t printBufferCount = 4096;

FILE* consoleOut;
type_FPrint FPrint = reinterpret_cast<type_FPrint>(fprintf);
type_FPrintT FPrintT = reinterpret_cast<type_FPrintT>(fprintfT);

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

int InitFPrint(bool debug, bool protonCompatibility) {

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

		if (debug) {
			Print("[?] InitFPrint() - Console\n");
		}
	}
	else {

		FPrint = FPrint_NoConsole;
		FPrintT = FPrintT_NoConsole;

		if (debug) {
			Print("[?] InitFPrint() - NoConsole\n");
		}
	}

	return 0;
}

void LogMessageBox(const TCHAR* toLog) {
	MessageBoxFormat(TEXT("InfinityLoader"), MB_ICONERROR, toLog);
}

void LogPrint(const TCHAR* toLog) {
	PrintT(toLog);
	Print("\n");
}

void LogUsingFuncT(LogFuncT logFunc, const TCHAR* formatText, ...) {

	va_list args;
	TCHAR buffer[printBufferCount];
	constexpr DWORD count = _countof(buffer);

	va_start(args, formatText);
	int bytesWritten = _vsnprintfT_s(buffer, count, _TRUNCATE, formatText, args);
	va_end(args);

	logFunc(buffer);
}

/////////////
// Utility //
/////////////

void MessageBoxFormat(String caption, UINT uType, String formatText, ...) {

	va_list args;
	TCHAR buffer[1024];
	constexpr size_t count = _countof(buffer);

	va_start(args, formatText);
	int bytesWritten = _vsnprintfT_s(buffer, count, _TRUNCATE, formatText.c_str(), args);
	va_end(args);

	MessageBox(NULL, buffer, caption.c_str(), uType);
}

void MessageBoxFormatA(StringA caption, UINT uType, StringA formatText, ...) {

	va_list args;
	char buffer[1024];
	constexpr size_t count = _countof(buffer);

	va_start(args, formatText);
	int bytesWritten = _vsnprintf_s(buffer, count, _TRUNCATE, formatText.c_str(), args);
	va_end(args);

	MessageBoxA(NULL, buffer, caption.c_str(), uType);
}

int UnbufferCrtStreams() {

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

void NulCrtStreams() {
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

void BindCrtStreamsToOSHandles() {

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

//////////////////
// INI Handling //
//////////////////

PatternEntry::PatternEntry(const String str, const intptr_t val) : name(str), value(val) {};

bool INISectionExists(const String iniPath, const TCHAR *const section) {

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

DWORD GetINIString(const String& iniPath, const TCHAR* section, const TCHAR* key, String& outStr, bool& filled) {

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

DWORD GetINIStringDef(const String& iniPath, const TCHAR* section, const TCHAR* key, const TCHAR* def, String& outStr) {
	bool filled;
	DWORD error = GetINIString(iniPath, section, key, outStr, filled);
	if (!filled) {
		outStr = def;
	}
	return error;
}

bool decimalStrToInteger(const String decimalStr, bool& accumulator) {

	size_t strLen = decimalStr.length();
	if (strLen == 0) {
		return false;
	}

	const TCHAR* characters = decimalStr.c_str();
	size_t minimumI = 0;

	if (characters[0] == TCHAR{ '-' }) {
		if (strLen == 1) {
			return false;
		}
		minimumI = 1;
	}

	const TCHAR firstChar = characters[minimumI];
	for (const auto& entry : aDecimalDigitToByte) {
		if (firstChar == entry.first) {
			accumulator = entry.second != 0;
			return true;
		}
	}

	return false;
}

// TODO: Suboptimal
template<typename IntegerType>
bool decimalStrToInteger(const String decimalStr, IntegerType& accumulator) {

	size_t strLen = decimalStr.length();
	if (strLen == 0) {
		return false;
	}

	const TCHAR* characters = decimalStr.c_str();
	size_t minimumI = 0;
	bool negative = false;

	if (characters[0] == TCHAR{ '-' }) {
		if (strLen == 1) {
			return false;
		}
		minimumI = 1;
		negative = true;
	}

	accumulator = 0;
	size_t curPow = 1;
	size_t i = strLen - 1;
	do {
		for (auto& entry : aDecimalDigitToByte) {
			if (characters[i] == entry.first) {
				accumulator += entry.second * curPow;
				curPow *= 10;
				goto loop_continue;
			}
		}

		return false;
	loop_continue:;

	} while (i-- != minimumI);

	if (negative) {
		accumulator = -accumulator;
	}

	return true;
}

template<typename IntegerType>
DWORD GetINIInteger(String iniPath, const TCHAR* section, const TCHAR* key,
	IntegerType& outInteger, bool& filled, LogFuncT logFunc)
{
	filled = false;

	TCHAR buffer[1024];
	const std::size_t bufferSize = sizeof(buffer) / sizeof(buffer[0]);

	DWORD numRead = GetPrivateProfileString(section, key, nullptr,
		buffer, bufferSize, iniPath.c_str());

	if (DWORD lastError = GetLastError(); lastError != ERROR_SUCCESS && lastError != ERROR_FILE_NOT_FOUND) {
		LogUsingFuncT(logFunc, TEXT("[!] GetPrivateProfileString failed (%d)."), lastError);
		return lastError;
	}

	if (numRead > 0) {
		if (!decimalStrToInteger(buffer, outInteger)) {
			LogUsingFuncT(logFunc, TEXT("[!] Invalid decimal for [%s].%s: \"%s\"."), section, key, buffer);
			return -1;
		}
		filled = true;
	}

	return 0;
}

template<typename IntegerType>
DWORD GetINIInteger(String iniPath, const TCHAR* section, const TCHAR* key, IntegerType& outInteger, bool& filled) {
	return GetINIInteger<IntegerType>(iniPath, section, key, outInteger, filled, LogPrint);
}

template<typename IntegerType>
DWORD GetINIIntegerDef(String iniPath, const TCHAR* section, const TCHAR* key, IntegerType def, IntegerType& outInteger,
	LogFuncT errorFunc)
{
	bool filled;
	DWORD error = GetINIInteger(iniPath, section, key, outInteger, filled, errorFunc);
	if (!filled) {
		outInteger = def;
	}
	return error;
}

template<typename IntegerType>
DWORD GetINIIntegerDef(String iniPath, const TCHAR* section, const TCHAR* key, IntegerType def, IntegerType& outInteger) {
	return GetINIIntegerDef(iniPath, section, key, def, outInteger, LogPrint);
}

template<typename IntegerType>
struct DivisorInformation {
	IntegerType divisor;
	IntegerType nNumberChars;
};

template<typename IntegerType>
constexpr DivisorInformation<IntegerType> calculateDivisorInformation() {

	constexpr auto maxPossible = maxIntegerTypeValue<IntegerType>() / 10;

	IntegerType multiple = 1;
	IntegerType numChars = 1;

	while (multiple <= maxPossible) {
		++numChars;
		multiple *= 10;
	}

	return { multiple, numChars };
}

const TCHAR decDigitToChar[10]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

template<typename IntegerType>
String integerToDecimalStr(IntegerType integer) {

	if (integer == 0) {
		return String { '0' };
	}

	DivisorInformation divisorInformation = calculateDivisorInformation<IntegerType>();
	auto divisor = divisorInformation.divisor;

	TCHAR* buffer = reinterpret_cast<TCHAR*>(alloca(sizeof(TCHAR) * (divisorInformation.nNumberChars + 1)));
	size_t writeI = 0;
	char sign;

	if (integer < 0) {
		buffer[writeI++] = '-';
		sign = -1;
	}
	else {
		sign = 1;
	}

	while (divisor > 1) {
		// Cannot lose data here because of the large divisor
		const char character = static_cast<char>(integer / divisor);
		if (character != 0) {
			buffer[writeI++] = decDigitToChar[sign * character];
			integer -= character * divisor;
			divisor /= 10;
			break;
		}
		divisor /= 10;
	}

	while (divisor > 1) {
		// Cannot lose data here because of the large divisor
		const char character = static_cast<char>(integer / divisor);
		buffer[writeI++] = decDigitToChar[sign * character];
		integer -= character * divisor;
		divisor /= 10;
	}

	buffer[writeI++] = decDigitToChar[sign * integer];
	return String { buffer, writeI };
}

template<typename IntegerType>
DWORD SetINIInteger(const String& iniPath, const TCHAR *const section, const TCHAR *const key, const IntegerType toSet) {
	const String toSetStr = integerToDecimalStr(toSet);
	if (!WritePrivateProfileString(section, key, toSetStr.c_str(), iniPath.c_str())) {
		PrintT(TEXT("[!] Failed to set [%s].%s = %s\n"), section, key, toSetStr.c_str());
		return GetLastError();
	}
	return ERROR_SUCCESS;
}

///////////
// Paths //
///////////

DWORD getExePath(String& exePathOut, String* exeNameOut) {

	String exeNames;
	if (DWORD lastError = GetINIStringDef(iniPath, TEXT("General"), TEXT("ExeNames"), TEXT(""), exeNames)) {
		return lastError;
	}

	DWORD result = -1;
	forEveryCharSplit(exeNames, TCHAR{','}, [&](const String str) {

		const String checkingFor = String{ workingFolder }.append(str);
		if (std::filesystem::exists(checkingFor)) {

			if (exeNameOut) {
				*exeNameOut = str;
			}

			exePathOut = checkingFor;
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

void initPaths() {
	workingFolder = getWorkingFolder();
	iniPath = String{ workingFolder }.append(TEXT("InfinityLoader.ini"));
	dbPath = String{ workingFolder }.append(TEXT("InfinityLoader.db"));
}

//////////////////////
// Assembly Writing //
//////////////////////

AssemblyWriter::AssemblyWriter(unsigned char* buff) {
	buffer = buff;
}

intptr_t AssemblyWriter::getLocation() {
	return curMemAddress;
}

void AssemblyWriter::setLocation(intptr_t newCurMemAddress) {
	startMemAddress = newCurMemAddress;
	curMemAddress = newCurMemAddress;
}

void AssemblyWriter::writeBytesToBuffer(int numBytes, ...) {
	va_list args;
	va_start(args, numBytes);
	for (int i = 0; i < numBytes; ++i) {
		unsigned char byte = va_arg(args, unsigned char);
		buffer[curI++] = byte;
		++curMemAddress;
	}
	va_end(args);
}

void AssemblyWriter::writeNumberToBuffer(intptr_t pointer, size_t writeSize) {
	for (size_t i = 0; i < writeSize; ++i) {
		buffer[curI++] = pointer & 0xFF;
		++curMemAddress;
		pointer = pointer >> 8;
	}
}

void AssemblyWriter::writeRelativeToBuffer32(intptr_t relAddress) {
	intptr_t destOffset = relAddress - (curMemAddress + 4);
	writeNumberToBuffer(destOffset, 4);
}

void AssemblyWriter::branchUsingIndirect64(intptr_t destAddress, unsigned char branchOpcode) {

	writeBytesToBuffer(2, 0xEB, 0x8); // JMP
	writeNumberToBuffer(destAddress, 8); // (QWORD)

	writeBytesToBuffer(2, 0xFF, branchOpcode); // CALL/JMP [&QWORD]
	writeRelativeToBuffer32(curMemAddress - 10);
}

void AssemblyWriter::writeArgImmediate32(__int32 num, int argI) {

#if defined(_WIN64)
	switch (argI) {
		case 0: writeBytesToBuffer(3, 0x48, 0xC7, 0xC1); break;
		case 1: writeBytesToBuffer(3, 0x48, 0xC7, 0xC2); break;
		case 2: writeBytesToBuffer(3, 0x49, 0xC7, 0xC0); break;
		case 3: writeBytesToBuffer(3, 0x49, 0xC7, 0xC1); break;
		default: MessageBoxFormat(TEXT("InfinityLoader"), MB_ICONERROR, TEXT("(internal error) unhandled argI: %d"), argI); return;
	}
#else
	writeBytesToBuffer(1, 0x68);
#endif

	writeNumberToBuffer(num, 4);
}

void AssemblyWriter::jmpToAddressFar(intptr_t address) {
#if defined(_WIN64)
	branchUsingIndirect64(address, 0x25);
#else
	writeBytesToBuffer(1, 0xE9);
	writeRelativeToBuffer32(address);
#endif
}

void AssemblyWriter::jmpToAddress(intptr_t address) {
	writeBytesToBuffer(1, 0xE9);
	writeRelativeToBuffer32(address);
}

void AssemblyWriter::callToAddressFar(intptr_t address) {
#if defined(_WIN64)
	branchUsingIndirect64(address, 0x15);
#else
	writeBytesToBuffer(1, 0xE8);
	writeRelativeToBuffer32(address);
#endif
}

void AssemblyWriter::callToAddress(intptr_t address) {
	writeBytesToBuffer(1, 0xE8);
	writeRelativeToBuffer32(address);
}

void AssemblyWriter::alignStackAndMakeShadowSpace() {
#if defined(_WIN64)
	// push rsp
	// and rsp, 0xFFFFFFFFFFFFFFF0
	// sub rsp, 0x20
	writeBytesToBuffer(9, 0x54, 0x48, 0x83, 0xE4, 0xF0, 0x48, 0x83, 0xEC, 0x20);
#endif
}

void AssemblyWriter::undoAlignAndShadowSpace() {
#if defined(_WIN64)
	writeBytesToBuffer(5, 0x48, 0x83, 0xC4, 0x20, 0x5C);
#endif
}

void AssemblyWriter::pushVolatileRegisters() {
#if defined(_WIN64)
	writeBytesToBuffer(11, 0x50, 0x51, 0x52, 0x41, 0x50, 0x41, 0x51, 0x41, 0x52, 0x41, 0x53);
#else
	writeBytesToBuffer(3, 0x50, 0x52, 0x51);
#endif
}

void AssemblyWriter::popVolatileRegisters() {
#if defined(_WIN64)
	writeBytesToBuffer(11, 0x41, 0x5B, 0x41, 0x5A, 0x41, 0x59, 0x41, 0x58, 0x5A, 0x59, 0x58);
#else
	writeBytesToBuffer(3, 0x59, 0x5A, 0x58);
#endif
}

void AssemblyWriter::printBuffer() {
	Print("[!] Debug dump of AssemblyWriter located at %p: ", reinterpret_cast<void*>(startMemAddress));
	for (size_t i = 0; i < curI; ++i) {
		Print("%02X ", buffer[i]);
	}
	Print("\n");
}

void AssemblyWriter::flush() {
	memcpy_s(reinterpret_cast<void*>(startMemAddress), curI, buffer, curI);
	curI = 0;
}

DWORD writeProcessString(HANDLE hProcess, const TCHAR* str, intptr_t& memoryPtr) {

	size_t strSizeBytes = (sizeof(TCHAR) + 1) * strlenT(str);

	LPVOID allocPtr = VirtualAllocEx(hProcess, NULL, strSizeBytes, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (!allocPtr) {
		DWORD lastError = GetLastError();
		Print("[!] VirtualAllocEx failed (%d).\n", lastError);
		return lastError;
	}

	if (!WriteProcessMemory(hProcess, allocPtr, str, strSizeBytes, NULL)) {
		DWORD lastError = GetLastError();
		Print("[!] WriteProcessMemory failed (%d).\n", lastError);
		return lastError;
	}

	memoryPtr = reinterpret_cast<intptr_t>(allocPtr);
	return 0;
}

DWORD writeProcessStringA(HANDLE hProcess, const char* str, intptr_t& memoryPtr) {

	size_t strSizeBytes = (sizeof(char) + 1) * strlen(str);

	LPVOID allocPtr = VirtualAllocEx(hProcess, NULL, strSizeBytes, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (!allocPtr) {
		DWORD lastError = GetLastError();
		Print("[!] VirtualAllocEx failed (%d).\n", lastError);
		return lastError;
	}

	if (!WriteProcessMemory(hProcess, allocPtr, str, strSizeBytes, NULL)) {
		DWORD lastError = GetLastError();
		Print("[!] WriteProcessMemory failed (%d).\n", lastError);
		return lastError;
	}

	memoryPtr = reinterpret_cast<intptr_t>(allocPtr);
	return 0;
}

DWORD allocateNear(intptr_t address, size_t size, size_t dwAllocationGranularity, intptr_t& allocatedOut) {
	allocatedOut = reinterpret_cast<intptr_t>(VirtualAlloc(reinterpret_cast<void*>(address), size, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
	while (!allocatedOut) {
		DWORD lastError = GetLastError();
		if (lastError != ERROR_INVALID_ADDRESS) {
			Print("[!] VirtualAlloc failed (%d).\n", lastError);
			return lastError;
		}
		address -= dwAllocationGranularity;
		allocatedOut = reinterpret_cast<intptr_t>(VirtualAlloc(reinterpret_cast<void*>(address), size, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
	};
	return 0;
}

////////////////////////
// String Conversions //
////////////////////////

std::string ws2s(const std::wstring& wstr) {
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
	return convert.to_bytes(wstr);
}

std::wstring s2ws(const std::string& str) {
	std::wstring newStr;
	return newStr.assign(str.begin(), str.end());
}

String ToString(const char* str) {
#ifndef UNICODE
	return String{ str };
#else
	return String{ s2ws(str) };
#endif
}

StringA StringToStringA(const String& string) {
#ifndef UNICODE
	return string;
#else
	return ws2s(string);
#endif
}

////////////////////////
// Exception Handling //
////////////////////////

String writeDump(EXCEPTION_POINTERS* pointers)
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

	OStringStream dmpNameStream{ String{ workingFolder }.append(TEXT("InfinityLoader_Crash")) };
	String builtDmpName = dmpNameStream.str();

	if (!std::filesystem::exists(builtDmpName)) {
		std::filesystem::create_directory(builtDmpName);
	}

	size_t attemptI = 0;

	while (true) {

		dmpNameStream << workingFolder;
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
