
#pragma once

#include <windows.h>
#include <codecvt>
#include <filesystem>
#include <string>

///////////////////////////
// Type Defs and Defines //
///////////////////////////

#ifndef UNICODE  
typedef std::string String;
#define printfT printf
#define strcmpT strcmp
#define strlenT strlen
#define _vsnprintfT_s _vsnprintf_s
#else
typedef std::wstring String;
#define printfT wprintf
#define strcmpT wcscmp
#define strlenT wcslen
#define _vsnprintfT_s _vsnwprintf_s
#endif

typedef std::string StringA;
typedef std::wstring StringW;

/////////////
// Globals //
/////////////

extern String dbPath;
extern String iniPath;
extern String workingFolder;

/////////////
// Utility //
/////////////

extern void MessageBoxFormat(String caption, UINT uType, String formatText, ...);

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

template<typename IntegerType>
extern bool decimalStrToInteger(const String decimalStr, IntegerType& accumulator);

template<typename IntegerType>
extern String integerToDecimalStr(IntegerType integer);

extern DWORD GetINIString(String iniPath, const TCHAR* section, const TCHAR* key, const TCHAR* def, String& outStr);

template<typename IntegerType>
extern DWORD GetINIInteger(String iniPath, const TCHAR* section, const TCHAR* key, IntegerType& outInteger, bool& filled);

template<typename IntegerType>
extern DWORD GetINIIntegerDef(String iniPath, const TCHAR* section, const TCHAR* key, IntegerType def, IntegerType& outInteger);

template<typename IntegerType>
extern DWORD SetINIInteger(String iniPath, const TCHAR* section, const TCHAR* key, IntegerType toSet);

///////////
// Paths //
///////////

extern DWORD getExePath(String* exeNameOut, String& exePathOut);
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
	int curI;
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
