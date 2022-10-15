
#include "InfinityLoaderCommon.h"

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

//////////////////
// INI Handling //
//////////////////

PatternEntry::PatternEntry(const String str, const intptr_t val) : name(str), value(val) {};

DWORD GetINIString(String iniPath, const TCHAR* section, const TCHAR* key, const TCHAR* def, String& outStr) {
	TCHAR buffer[1024];
	const std::size_t bufferSize = sizeof(buffer) / sizeof(buffer[0]);

	DWORD numRead = GetPrivateProfileString(section, key, def,
		(TCHAR*)&buffer, bufferSize, iniPath.c_str());

	if (DWORD lastError = GetLastError(); lastError != ERROR_SUCCESS && lastError != ERROR_FILE_NOT_FOUND) {
		printf("[!] GetPrivateProfileString failed (%d).\n", lastError);
		return lastError;
	}

	outStr = buffer;
	return 0;
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
DWORD GetINIInteger(String iniPath, const TCHAR* section, const TCHAR* key, IntegerType& outInteger, bool& filled) {

	filled = false;

	TCHAR buffer[1024];
	const std::size_t bufferSize = sizeof(buffer) / sizeof(buffer[0]);

	DWORD numRead = GetPrivateProfileString(section, key, nullptr,
		(TCHAR*)&buffer, bufferSize, iniPath.c_str());

	if (DWORD lastError = GetLastError(); lastError != ERROR_SUCCESS && lastError != ERROR_FILE_NOT_FOUND) {
		printf("[!] GetPrivateProfileString failed (%d).\n", lastError);
		return lastError;
	}

	if (numRead > 0) {
		if (!decimalStrToInteger(buffer, outInteger)) {
			printfT(TEXT("[!] Invalid decimal for [%s].%s: \"%s\".\n"), section, key, buffer);
			return -1;
		}
		filled = true;
	}

	return 0;
}

template<typename IntegerType>
DWORD GetINIIntegerDef(String iniPath, const TCHAR* section, const TCHAR* key, IntegerType def, IntegerType& outInteger) {
	bool filled;
	DWORD error = GetINIInteger(iniPath, section, key, outInteger, filled);
	if (!filled) {
		outInteger = def;
	}
	return error;
}

DWORD SetINIString(String iniPath, const TCHAR* section, const TCHAR* key, intptr_t def, String toSet) {
	WritePrivateProfileString(section, key, toSet.c_str(), iniPath.c_str());
}

template<typename IntegerType>
constexpr std::make_unsigned<IntegerType>::type maxIntegerTypeValue() {
	using UnsignedType = typename std::make_unsigned<IntegerType>::type;
	return std::is_unsigned<IntegerType>::value
		? ~static_cast<UnsignedType>(0)
		: static_cast<UnsignedType>(~static_cast<IntegerType>(0)) >> 1;
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
		const char character = integer / divisor;
		if (character != 0) {
			buffer[writeI++] = decDigitToChar[sign * character];
			integer -= character * divisor;
			divisor /= 10;
			break;
		}
		divisor /= 10;
	}

	while (divisor > 1) {
		const char character = integer / divisor;
		buffer[writeI++] = decDigitToChar[sign * character];
		integer -= character * divisor;
		divisor /= 10;
	}

	buffer[writeI++] = decDigitToChar[sign * integer];
	return String { buffer, writeI };
}

template<typename IntegerType>
DWORD SetINIInteger(String iniPath, const TCHAR* section, const TCHAR* key, IntegerType toSet) {
	WritePrivateProfileString(section, key, integerToDecimalStr(toSet).c_str(), iniPath.c_str());
}

///////////
// Paths //
///////////

DWORD getExePath(String* exeNameOut, String& exePathOut) {

	String exeNames;
	if (DWORD lastError = GetINIString(iniPath, TEXT("General"), TEXT("ExeNames"), TEXT(""), exeNames)) {
		return lastError;
	}

	forEveryCharSplit(exeNames, TCHAR{ ',' }, [&](const String str) {

		String checkingFor = String{ workingFolder }.append(str);
		if (std::filesystem::exists(checkingFor)) {

			if (exeNameOut) {
				*exeNameOut = str;
			}

			exePathOut = checkingFor;
			return true;
		}
		return false;
	});

	return 0;
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
	printf("[!] Debug dump of AssemblyWriter located at %p: ", reinterpret_cast<void*>(startMemAddress));
	for (size_t i = 0; i < curI; ++i) {
		printf("%02X ", buffer[i]);
	}
	printf("\n");
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
		printf("[!] VirtualAllocEx failed (%d).\n", lastError);
		return lastError;
	}

	if (!WriteProcessMemory(hProcess, allocPtr, str, strSizeBytes, NULL)) {
		DWORD lastError = GetLastError();
		printf("[!] WriteProcessMemory failed (%d).\n", lastError);
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
		printf("[!] VirtualAllocEx failed (%d).\n", lastError);
		return lastError;
	}

	if (!WriteProcessMemory(hProcess, allocPtr, str, strSizeBytes, NULL)) {
		DWORD lastError = GetLastError();
		printf("[!] WriteProcessMemory failed (%d).\n", lastError);
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
			printf("[!] VirtualAlloc failed (%d).\n", lastError);
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
