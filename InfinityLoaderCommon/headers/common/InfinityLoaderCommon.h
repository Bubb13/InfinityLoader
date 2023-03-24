
#pragma once

#include <codecvt>
#include <filesystem>
#include <string>
#include <sstream>

#include <windows.h>
#include <dbghelp.h>

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

#define printf error
#define printfT error
#define fprintf error
#define fprintfT error

typedef std::string StringA;
typedef std::wstring StringW;
typedef std::ostringstream OStringStreamA;

/////////////
// Globals //
/////////////

extern String dbPath;
extern String iniPath;
extern String workingFolder;

/////////////
// Logging //
/////////////

typedef void(*type_FPrint)(FILE* file, const char* formatText, ...);
extern type_FPrint FPrint;

typedef void(*type_FPrintT)(FILE* file, const TCHAR* formatText, ...);
extern type_FPrintT FPrintT;

extern int InitFPrint(bool debug, bool protonCompatibility);

typedef void (LogFuncT)(const TCHAR* toLog);

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

struct PatternEntry {
	String name;
	intptr_t value;
	PatternEntry(const String str, const intptr_t val);
};

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

extern DWORD getExePath(String& exePathOut, String* exeNameOut = nullptr);
extern String getMyFolder();
extern String getMyPath();
extern String getWorkingFolder();
extern StringA getWorkingFolderA();
extern void initPaths();

//////////////////////
// Assembly Writing //
//////////////////////

struct ImageSectionInfo
{
	intptr_t ImageBase;
	char SectionName[IMAGE_SIZEOF_SHORT_NAME];
	void* SectionAddress;
	DWORD SectionSize;
};

class AssemblyWriter {
private:
	unsigned char* buffer;
	size_t curI;
	intptr_t startMemAddress;
	intptr_t curMemAddress;
public:
	AssemblyWriter(unsigned char* buff);
	intptr_t getLocation();
	void setLocation(intptr_t newCurMemAddress);
	void writeBytesToBuffer(int numBytes, ...);
	void writeNumberToBuffer(intptr_t pointer, size_t writeSize);
	void writeRelativeToBuffer32(intptr_t relAddress);
	void branchUsingIndirect64(intptr_t destAddress, unsigned char branchOpcode);
	void writeArgImmediate32(__int32 num, int argI);
	void jmpToAddressFar(intptr_t address);
	void jmpToAddress(intptr_t address);
	void callToAddressFar(intptr_t address);
	void callToAddress(intptr_t address);
	void alignStackAndMakeShadowSpace();
	void undoAlignAndShadowSpace();
	void pushVolatileRegisters();
	void popVolatileRegisters();
	void printBuffer();
	void flush();
};

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
