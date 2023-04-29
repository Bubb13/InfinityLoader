
#pragma once

#include <string>

#include <Windows.h>

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
// Logging //
/////////////

typedef void(*type_FPrint)(FILE* file, const char* formatText, ...);
typedef void(*type_FPrintT)(FILE* file, const TCHAR* formatText, ...);
typedef void (LogFuncT)(const TCHAR* toLog);

//////////////////
// INI Handling //
//////////////////

struct PatternEntry {
	String name;
	intptr_t value;
	PatternEntry(const String str, const intptr_t val);
};

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
