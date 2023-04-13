
#include "InfinityLoaderCommon.h"
#include "shared_memory.h"

#include <dbghelp.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <map>
#include <psapi.h>
#include <regex>

#include "asmjit/asmjit.h"
#include "asmtk/asmtk.h"
#include "pointers.h"
#include "bounds_exceeded.h"

/////////////
// Structs //
/////////////

enum class LuaMode {
	INTERNAL,
	EXTERNAL,
};

struct PatternByteEntry {
	bool isWild;
	unsigned char byte;
	PatternByteEntry(const unsigned char pByte, const bool pIsWild) : byte(pByte), isWild(pIsWild) {};
};

/////////////
// Globals //
/////////////

bool debug;
long long initTime;
LuaMode luaMode;
HMODULE luaLibrary;
bool protonCompatibility;

String exePath;
String exeNameForPatterns;
ImageSectionInfo textInfo;
bool attemptUseCached = false;
std::map<String, PatternEntry> patternEntries;
asmjit::JitRuntime rt;

const std::tuple<const TCHAR*, const TCHAR*, const unsigned char> aHexLetterToByte[] = {
	std::tuple{TEXT("0"), TEXT("0"), 0},
	std::tuple{TEXT("1"), TEXT("1"), 1},
	std::tuple{TEXT("2"), TEXT("2"), 2},
	std::tuple{TEXT("3"), TEXT("3"), 3},
	std::tuple{TEXT("4"), TEXT("4"), 4},
	std::tuple{TEXT("5"), TEXT("5"), 5},
	std::tuple{TEXT("6"), TEXT("6"), 6},
	std::tuple{TEXT("7"), TEXT("7"), 7},
	std::tuple{TEXT("8"), TEXT("8"), 8},
	std::tuple{TEXT("9"), TEXT("9"), 9},
	std::tuple{TEXT("A"), TEXT("a"), 0xA},
	std::tuple{TEXT("B"), TEXT("b"), 0xB},
	std::tuple{TEXT("C"), TEXT("c"), 0xC},
	std::tuple{TEXT("D"), TEXT("d"), 0xD},
	std::tuple{TEXT("E"), TEXT("e"), 0xE},
	std::tuple{TEXT("F"), TEXT("f"), 0xF},
};

///////////////////////
// General Functions //
///////////////////////

long long currentMicroseconds() {
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

DWORD loadLuaMode() {

	String luaModeStr;
	if (DWORD lastError = GetINIStringDef(iniPath, TEXT("General"), TEXT("LuaPatchMode"), TEXT(""), luaModeStr)) {
		return lastError;
	}

	if (luaModeStr == TEXT("INTERNAL")) {
		luaMode = LuaMode::INTERNAL;
	}
	else if (luaModeStr == TEXT("EXTERNAL")) {

		luaMode = LuaMode::EXTERNAL;

		String luaLibraryName;

		bool filled;
		if (DWORD lastError = GetINIString(iniPath, TEXT("General"), TEXT("LuaLibrary"), luaLibraryName, filled)) {
			return lastError;
		}

		if (!filled) {
			Print("[!] [General].LuaLibrary must be defined when [General].LuaPatchMode == \"EXTERNAL\".\n");
			return -1;
		}

		if (luaLibrary = LoadLibrary(luaLibraryName.c_str()); luaLibrary == nullptr) {
			DWORD lastError = GetLastError();
			PrintT(TEXT("[!] LoadLibrary failed (%d) to load [General].LuaLibrary \"%s\".\n"), lastError, luaLibraryName.c_str());
			return lastError;
		}
	}
	else {
		Print("[!] [General].LuaPatchMode must be either \"INTERNAL\" or \"EXTERNAL\".\n");
		return -1;
	}

	return 0;
}

DWORD findModuleWithPath(HANDLE process, String& path, HMODULE& foundModule) {

	HMODULE modules[1024];
	DWORD needed;
	TCHAR nameBuffer[MAX_PATH];

	if (EnumProcessModules(process, modules, sizeof(modules), &needed)) {

		int filledModules = needed / sizeof(HMODULE);

		for (int i = 0; i < filledModules; i++) {

			HMODULE module = modules[i];
			if (!GetModuleFileName(module, nameBuffer, MAX_PATH)) {
				DWORD lastError = GetLastError();
				Print("[!] GetModuleFileName failed (%d).\n", lastError);
				return lastError;
			}

			if (strcmpT(path.c_str(), nameBuffer) == 0) {
				foundModule = module;
				return 0;
			}
		}
	}
	else {
		DWORD lastError = GetLastError();
		Print("[!] EnumProcessModules failed (%d).\n", lastError);
		return lastError;
	}
	return 0;
}

bool findSectionInfo(HMODULE module, const char* sectionName, ImageSectionInfo& sectionInfo) {

	char* dllImageBase = (char*)module;
	IMAGE_NT_HEADERS* pNtHdr = ImageNtHeader(dllImageBase);
	sectionInfo.ImageBase = pNtHdr->OptionalHeader.ImageBase;
	IMAGE_SECTION_HEADER* pSectionHdr = (IMAGE_SECTION_HEADER*)(pNtHdr + 1);

	for (int i = 0; i < pNtHdr->FileHeader.NumberOfSections; i++) {

		if (strcmp((char*)pSectionHdr->Name, sectionName) == 0) {
			strcpy_s(sectionInfo.SectionName, sectionName);
			sectionInfo.SectionAddress = dllImageBase + pSectionHdr->VirtualAddress;
			sectionInfo.SectionSize = pSectionHdr->Misc.VirtualSize;
			return true;
		}

		pSectionHdr++;
	}
	return false;
}

void disableCodeProtection() {
	DWORD temp;
	VirtualProtect(textInfo.SectionAddress, textInfo.SectionSize, PAGE_EXECUTE_READWRITE, &temp);
}

void enableCodeProtection() {
	DWORD temp;
	VirtualProtect(textInfo.SectionAddress, textInfo.SectionSize, PAGE_EXECUTE_READ, &temp);
}

void exposeToLua(lua_State* L, const char* exposedName, lua_CFunction func) {
	p_lua_pushcclosure(L, func, 0);
	p_lua_setglobal(L, exposedName);
}

void callOverrideFile(lua_State* L, const char* name) {

	p_lua_getglobal(L, "debug");        // [ debug ]
	p_lua_getfield(L, -1, "traceback"); // [ debug, traceback ]

	StringA luaFile = getWorkingFolderA().append("override\\").append(name).append(".lua");
	if (p_luaL_loadfilex(L, luaFile.c_str(), nullptr) != LUA_OK) {
		                                // [ debug, traceback, errorMessage ]
		p_lua_pushvalue(L, -2);         // [ debug, traceback, errorMessage, traceback ]
		p_lua_pushvalue(L, -2);         // [ debug, traceback, errorMessage, traceback, errorMessage ]
		if (p_lua_pcallk(L, 1, 1, 0, 0, nullptr) != LUA_OK) {
			                            // [ debug, traceback, errorMessage, errorErrorMessage  ]
			Print("[!] Error in error handling calling debug.traceback()\n");
			p_lua_pop(L, 4);            // [ ]
			return;
		}
		                                // [ debug, traceback, errorMessage, errorMessageTraceback ]
		Print("[!] %s\n", p_lua_tostring(L, -1));
		p_lua_pop(L, 4);                // [ ]
		return;
	}
	                                    // [ debug, traceback, chunk ]
	if (p_lua_pcallk(L, 0, 0, -2, 0, nullptr) != LUA_OK) {
		                                // [ debug, traceback, errorMessage ]
		Print("[!] %s\n", p_lua_tostring(L, -1));
		p_lua_pop(L, 3);                // [ ]
	}
	else {
		                                // [ debug, traceback ]
		p_lua_pop(L, 2);                // [ ]
	}
}

template<typename CheckFunc>
asmjit::Error jitAt(uint8_t* dst, asmjit::CodeHolder* code, const CheckFunc checkFunc) noexcept {

	ASMJIT_PROPAGATE(code->flatten());
	ASMJIT_PROPAGATE(code->resolveUnresolvedLinks());

	size_t estimatedCodeSize = code->codeSize();
	if (ASMJIT_UNLIKELY(estimatedCodeSize == 0))
		return asmjit::DebugUtils::errored(asmjit::kErrorNoCodeGenerated);

	// Recalculate the final code size and shrink the memory we allocated for it
	// in case that some relocations didn't require records in an address table.
	size_t codeSize;

	while (true) {
		// Relocate the code.
		asmjit::Error err = code->relocateToBase(reinterpret_cast<uint64_t>(dst));
		if (ASMJIT_UNLIKELY(err)) {
			return err;
		}

		codeSize = code->codeSize();
		uint8_t* newDst = checkFunc(codeSize);
		if (newDst == reinterpret_cast<uint8_t*>(-1))
			return asmjit::kErrorOk;
		else if (newDst)
			dst = newDst;
		else
			break;
	}

	for (asmjit::Section* section : code->_sections) {
		size_t offset = size_t(section->offset());
		size_t bufferSize = size_t(section->bufferSize());
		size_t virtualSize = size_t(section->virtualSize());

		ASMJIT_ASSERT(offset + bufferSize <= codeSize);
		memcpy(dst + offset, section->data(), bufferSize);

		if (virtualSize > bufferSize) {
			ASMJIT_ASSERT(offset + virtualSize <= codeSize);
			memset(dst + offset + bufferSize, 0, virtualSize - bufferSize);
		}
	}

	rt.flush(dst, codeSize);
	return asmjit::kErrorOk;
}

//////////////////////
// Pattern Matching //
//////////////////////

// TODO: Suboptimal
bool hexLetterToByte(String hexLetter, unsigned char& byteOut) {
	for (auto& tup : aHexLetterToByte) {
		if (hexLetter == std::get<0>(tup) || hexLetter == std::get<1>(tup)) {
			byteOut = std::get<2>(tup);
			return true;
		}
	}
	return false;
}

bool decodeByteString(String byteStr, std::list<PatternByteEntry>& listToFill, String& errorOut) {

	size_t byteStrLen = byteStr.length();
	if (byteStrLen == 0 || byteStrLen & 1) {
		errorOut = String{ TEXT("Length zero / not even") };
		return false;
	}

	for (size_t i = 0; i < byteStrLen; i += 2) {

		String curByteLetter1 = byteStr.substr(i, 1);
		String curByteLetter2 = byteStr.substr(i + 1, 1);

		if (curByteLetter1 == TEXT("?") && curByteLetter2 == TEXT("?")) {
			listToFill.emplace_back(0, true);
			continue;
		}

		unsigned char curByte = 0;

		unsigned char curByte1;
		if (!hexLetterToByte(curByteLetter1, curByte1)) {
			errorOut = String{ TEXT("Invalid hex character: '") }.append(curByteLetter1.c_str()).append(TEXT("'"));
			return false;
		}
		curByte |= (curByte1 << 4);


		unsigned char curByte2;
		if (!hexLetterToByte(curByteLetter2, curByte2)) {
			errorOut = String{ TEXT("Invalid hex character: '") }.append(curByteLetter2.c_str()).append(TEXT("'"));
			return false;
		}
		curByte |= curByte2;

		listToFill.emplace_back(curByte, false);
	}

	return true;
}

bool findByteList(ImageSectionInfo& section, std::list<PatternByteEntry> byteList, intptr_t& addressOut) {

	unsigned char* curAddress = reinterpret_cast<unsigned char*>(section.SectionAddress);
	unsigned char* endAddress = curAddress + section.SectionSize;

	for (; curAddress < endAddress; ++curAddress) {

		unsigned char* checkAddress = curAddress;

		for (PatternByteEntry& entry : byteList) {
			if (!entry.isWild && entry.byte != *checkAddress) {
				goto continue_outer;
			}
			++checkAddress;
		}

		addressOut = reinterpret_cast<intptr_t>(curAddress);
		return true;
		continue_outer:;
	}

	return false;
}

template<typename Func>
bool checkOperationsArgCount(const String& iniCategoryName, const String& operationStr,
							 const std::vector<String>& parts, const Func condition)
{
	size_t numArgs = parts.size() - 1;
	if (!condition(numArgs)) {
		PrintT(TEXT("[!] Invalid number of arguments in %s operation for [%s].Operations: %d\n"), iniCategoryName.c_str(),
				operationStr.c_str(), static_cast<int>(numArgs));
		return false;
	}
	return true;
}

bool checkOperationsStackCount(const String& iniCategoryName, const String& operationStr,
							   const std::vector<intptr_t>& stack, size_t neededStackSize)
{
	size_t stackSize = stack.size();
	if (stackSize < neededStackSize) {
		PrintT(TEXT("[!] Not enough values pushed onto stack in %s operation for [%s].Operations: %d < %d\n"),
				operationStr.c_str(), iniCategoryName.c_str(), static_cast<int>(stackSize), static_cast<int>(neededStackSize));
		return false;
	}
	return true;
}

bool tryOperationsConvertToDecimal(const String& iniCategoryName, const String& operationStr,
								   const std::vector<String>& parts, const int argI, intptr_t& out)
{
	String arg = parts[argI];
	if (!decimalStrToInteger(arg, out)) {
		PrintT(TEXT("[!] Failed to convert %s argument to decimal for [%s].Operations: \"%s\"\n"),
				operationStr.c_str(), iniCategoryName.c_str(), arg.c_str());
		return false;
	}
	return true;
}

bool handlePatternOperations(String iniCategoryName, String operationsStr, intptr_t& address) {

	std::vector<intptr_t> stack{ address };
	std::vector<String> curParts;
	bool result = true;

#define checkArgCount(condition) \
	if (!checkOperationsArgCount(iniCategoryName, operationName, curParts, condition)) { \
		result = false; \
		return true; \
	}

#define checkStackCount(count) \
	if (!checkOperationsStackCount(iniCategoryName, operationName, stack, count)) { \
		result = false; \
		return true; \
	}

#define tryConvertArgToDecimal(argI, out) \
	if (!tryOperationsConvertToDecimal(iniCategoryName, operationName, \
		curParts, argI, out)) \
	{ \
		result = false; \
		return true; \
	}

	forEveryCharSplit(operationsStr, TCHAR{ ',' }, [&](const String str) {

		forEveryCharSplit(str, TCHAR{ ' ' }, [&](const String str) {
			curParts.push_back(str);
			return false;
		});

		if (curParts.size() == 0) {
			PrintT(TEXT("[!] Operation missing for [%s].Operations\n"), iniCategoryName.c_str());
			result = false;
			return true;
		}

		size_t numArgs = curParts.size() - 1;
		String operationName = curParts[0];
		intptr_t* back = &stack.back();

		if (operationName == TEXT("ADD")) {

			checkArgCount([](const size_t count) {
				return count == 0 || count == 1;
			});

			if (numArgs == 0) {
				checkStackCount(2);
				intptr_t backVal = *back;
				stack.pop_back();
				back = &stack.back();
				*back += backVal;
			}
			else {
				intptr_t arg1;
				tryConvertArgToDecimal(1, arg1);
				*back += arg1;
			}
		}
		else if (operationName == TEXT("READ")) {

			checkArgCount([](const size_t count) {
				return count == 1;
			});

			String arg1 = curParts[1];
			if (arg1 == TEXT("BYTE")) {
				*back = *reinterpret_cast<__int8*>(*back);
			}
			else if (arg1 == TEXT("SHORT")) {
				*back = *reinterpret_cast<__int16*>(*back);
			}
			else if (arg1 == TEXT("DWORD")) {
				*back = *reinterpret_cast<__int32*>(*back);
			}
#if defined(_WIN64)
			else if (arg1 == TEXT("QWORD")) {
				*back = *reinterpret_cast<__int64*>(*back);
			}
#endif
			else {
				PrintT(TEXT("[!] Invalid READ argument for [%s].Operations: \"%s\"\n"), iniCategoryName.c_str(), arg1.c_str());
				result = false;
				return true;
			}
		}
		else if (operationName == TEXT("WRITE")) {

			checkArgCount([](const size_t count) {
				return count == 2;
			});

			String arg1 = curParts[1];
			String arg2 = curParts[2];

			if (arg1 == TEXT("BYTES")) {

				std::list<PatternByteEntry> byteList;
				String errorStr;
				if (!decodeByteString(arg2, byteList, errorStr)) {
					PrintT(TEXT("[!] Failed to decode BYTES value for [%s].Operations: \"%s\", %s\n"), iniCategoryName.c_str(), arg2.c_str(), errorStr.c_str());
					return true;
				}

				unsigned char* curWrite = reinterpret_cast<unsigned char*>(*back);
				for (auto& entry : byteList) {
					if (entry.isWild) {
						++curWrite;
						continue;
					}
					*curWrite++ = entry.byte;
				}
			}
			else {

				intptr_t arg2Dec;
				tryConvertArgToDecimal(2, arg2Dec);

				if (arg1 == TEXT("BYTE")) {
					*reinterpret_cast<__int8*>(*back) = static_cast<__int8>(arg2Dec);
				}
				else if (arg1 == TEXT("SHORT")) {
					*reinterpret_cast<__int16*>(*back) = static_cast<__int16>(arg2Dec);
				}
				else if (arg1 == TEXT("DWORD")) {
					*reinterpret_cast<__int32*>(*back) = static_cast<__int32>(arg2Dec);
				}
#if defined(_WIN64)
				else if (arg1 == TEXT("QWORD")) {
					*reinterpret_cast<__int64*>(*back) = static_cast<__int64>(arg2Dec);
				}
#endif
				else {
					PrintT(TEXT("[!] Invalid WRITE argument for [%s].Operations: \"%s\"\n"), iniCategoryName.c_str(), arg1.c_str());
					result = false;
					return true;
				}
			}
		}
		else if (operationName == TEXT("PUSH")) {
			stack.push_back(*back);
			back = &stack.back();
		}
		else if (operationName == TEXT("DISABLE_CODE_PROTECTION")) {
			disableCodeProtection();
		}
		else if (operationName == TEXT("ENABLE_CODE_PROTECTION")) {
			enableCodeProtection();
		}
		else {
			PrintT(TEXT("[!] Invalid operation for [%s].Operations: \"%s\"\n"), iniCategoryName.c_str(), operationName.c_str());
			result = false;
			return true;
		}

		curParts.clear();
		return false;
	});

	address = stack.back();
	return result;
}

template<typename Func>
void forEveryINISectionName(const String iniPath, const Func action) {

	DWORD numChars = 1024;
	TCHAR* buffer = new TCHAR[numChars];

	DWORD numRead = GetPrivateProfileSectionNames(buffer, numChars, iniPath.c_str());
	while (numRead == (numChars - 2)) {
		delete[] buffer;
		numChars *= 2;
		buffer = new TCHAR[numChars];
		numRead = GetPrivateProfileSectionNames(buffer, numChars, iniPath.c_str());
	}

	size_t lastI = 0;
	for (size_t i = 0; i < numRead; ++i) {
		if (buffer[i] == TCHAR{ '\0' }) {
			if (action(String{ &buffer[lastI], i - lastI })) {
				return;
			}
			lastI = i + 1;
		}
	}

	delete[] buffer;
}

DWORD resolveAliasTarget(const String aliasList, String& toTransform) {

	if (aliasList == TEXT("")) {
		return 0;
	}

	DWORD result = 0;
	forEveryCharSplit(aliasList, TCHAR{','}, [&](const String str) {

		const size_t colonI = str.find(TCHAR{':'});

		if (colonI == std::string::npos) {
			PrintT(TEXT("[!] Invalid ExeSwitchAlias: \"%s\".\n"), str.c_str());
			result = -1;
			return true;
		}

		const String alias = str.substr(0, colonI);
		const String target = str.substr(colonI + 1);

		if (target.find(TCHAR{':'}) != std::string::npos) {
			PrintT(TEXT("[!] Invalid ExeSwitchAlias: \"%s\".\n"), str.c_str());
			result = -1;
			return true;
		}

		if (alias == toTransform) {
			toTransform = target;
			return true;
		}

		return false;
	});

	return result;
}

DWORD findINICategoryPattern(ImageSectionInfo& sectionInfo, const String& iniPath,
	String iniCategoryName, intptr_t& addressOut)
{
	intptr_t bExeSwitch;
	if (DWORD lastError = GetINIIntegerDef<intptr_t>(iniPath, iniCategoryName.c_str(), TEXT("ExeSwitch"), 0, bExeSwitch)) {
		return lastError;
	}

	if (bExeSwitch) {

		String exeAlias;
		if (DWORD lastError{ GetINIStringDef(iniPath, iniCategoryName.c_str(), TEXT("ExeSwitchAlias"), TEXT(""), exeAlias) }) {
			return lastError;
		}

		String exeSwitchName{ exeNameForPatterns };
		if (DWORD lastError = resolveAliasTarget(exeAlias, exeSwitchName)) {
			return lastError;
		}

		iniCategoryName.insert(0, String{ TEXT("!ExeSwitch-") }.append(exeSwitchName).append(TEXT("-")));
	}

	bool noCache;
	if (DWORD lastError = GetINIIntegerDef<bool>(iniPath, iniCategoryName.c_str(), TEXT("NoCache"), false, noCache)) {
		return lastError;
	}

	if (!noCache && attemptUseCached) {

		intptr_t cachedAddress;
		if (DWORD lastError = GetINIIntegerDef<intptr_t>(iniPath, iniCategoryName.c_str(), TEXT("CachedAddress"), 0, cachedAddress)) {
			return lastError;
		}

		if (cachedAddress != 0) {
			addressOut = cachedAddress;
			return 0;
		}
	}

	String hardcodedPatchPattern;
	if (DWORD lastError = GetINIStringDef(iniPath, iniCategoryName.c_str(), TEXT("Pattern"), TEXT(""), hardcodedPatchPattern)) {
		return lastError;
	}

	std::list<PatternByteEntry> byteList;
	String errorStr;
	if (!decodeByteString(hardcodedPatchPattern, byteList, errorStr)) {
		PrintT(TEXT("[!] Failed to decode [%s].Pattern: \"%s\".\n"), iniCategoryName.c_str(), errorStr.c_str());
		return -1;
	}

	if (!findByteList(sectionInfo, byteList, addressOut)) {
		PrintT(TEXT("[!] Could not find [%s].Pattern.\n"), iniCategoryName.c_str());
		return -1;
	}

	String operations;
	if (DWORD lastError = GetINIStringDef(iniPath, iniCategoryName.c_str(), TEXT("Operations"), TEXT(""), operations)) {
		return lastError;
	}

	if (operations != TEXT("")) {
		handlePatternOperations(iniCategoryName, operations, addressOut);
	}

	if (!noCache) {
		if (DWORD lastError = SetINIInteger<intptr_t>(iniPath, iniCategoryName.c_str(), TEXT("CachedAddress"), addressOut)) {
			return lastError;
		}
	}
	return 0;
}

long long getFileLastModifiedTime(String filePath) {

	// IMPORTANT: std::chrono::clock_cast() loads icu.dll, which is only present
	// on Windows versions >= 1903 (May 2019 Update). Using it breaks compatibility
	// with older Windows versions and Wine / Proton!

	//const auto fileTime = std::filesystem::last_write_time(filePath);
	//if (!protonCompatibility) {
	//	const auto systemTime = std::chrono::clock_cast<std::chrono::system_clock>(fileTime);
	//	return std::chrono::duration_cast<std::chrono::milliseconds>(systemTime.time_since_epoch()).count();
	//}
	//else {
	//	const auto systemTime = fileTime;
	//	return std::chrono::duration_cast<std::chrono::milliseconds>(systemTime.time_since_epoch()).count();
	//}

	const auto fileTime = std::filesystem::last_write_time(filePath);
	return std::chrono::duration_cast<std::chrono::milliseconds>(fileTime.time_since_epoch()).count();
}

DWORD findPatterns(ImageSectionInfo& sectionInfo) {

	bool alreadyCached;
	long long cachedExeTime;

	if (DWORD lastError = GetINIInteger<long long>(iniPath, TEXT("Auto-Generated"), TEXT("CachedExeTime"), cachedExeTime, alreadyCached)) {
		return lastError;
	}

	const long long exeLastModifiedTime = getFileLastModifiedTime(exePath);

	if (alreadyCached && exeLastModifiedTime == cachedExeTime) {
		attemptUseCached = true;
	}

	if (!attemptUseCached) {
		if (DWORD lastError = SetINIInteger<long long>(iniPath, TEXT("Auto-Generated"), TEXT("CachedExeTime"), exeLastModifiedTime)) {
			return lastError;
		}
	}

	if (debug) {
		Print("[?] Using cached pattern addresses: %s\n", attemptUseCached ? "true" : "false");
	}

	DWORD returnVal = 0;
	forEveryINISectionName(dbPath, [&](const String section) {

		if (section.rfind(TEXT("!"), 0) != std::string::npos) {
			return false;
		}

		intptr_t address;
		if (returnVal = findINICategoryPattern(sectionInfo, dbPath, section.c_str(), address)) {
			return true;
		}

		patternEntries.emplace(section, PatternEntry{ section, address });
		return false;
	});

	return returnVal;
}

///////////////////
// Lua Functions //
///////////////////

int addToLuaRegistryLua(lua_State* L) {
	p_lua_pushvalue(L, 1);
	p_lua_pushinteger(L, p_luaL_ref(L, LUA_REGISTRYINDEX));
	return 1;
}

int allocCodePageInternalLua(lua_State* L) {

	SYSTEM_INFO info;
	GetSystemInfo(&info);

	intptr_t allocated;
	if (DWORD lastError = allocateNear(textInfo.ImageBase, info.dwAllocationGranularity,
		info.dwAllocationGranularity, allocated))
	{
		return 0;
	}

	p_lua_pushinteger(L, allocated);                    // [ address ]
	p_lua_pushinteger(L, info.dwAllocationGranularity); // [ address, size ]
	return 2;
}

typedef std::make_unsigned<lua_Integer>::type UnsignedLuaInt;

int bandLua(lua_State* L) {
	p_lua_pushinteger(L, static_cast<UnsignedLuaInt>(p_lua_tointeger(L, 1)) & static_cast<UnsignedLuaInt>(p_lua_tointeger(L, 2)));
	return 1;
}

int bnotLua(lua_State* L) {
	p_lua_pushinteger(L, ~static_cast<UnsignedLuaInt>(p_lua_tointeger(L, 1)));
	return 1;
}

int borLua(lua_State* L) {
	p_lua_pushinteger(L, static_cast<UnsignedLuaInt>(p_lua_tointeger(L, 1)) | static_cast<UnsignedLuaInt>(p_lua_tointeger(L, 2)));
	return 1;
}

int disableCodeProtectionLua(lua_State* L) {
	disableCodeProtection();
	return 0;
}

int doFileLua(lua_State* L) {
	callOverrideFile(L, p_lua_tostring(L, 1));
	return 0;
}

int enableCodeProtectionLua(lua_State* L) {
	enableCodeProtection();
	return 0;
}

int extractLua(lua_State* L) {
	UnsignedLuaInt num = p_lua_tointeger(L, 1);
	UnsignedLuaInt start = p_lua_tointeger(L, 2);
	UnsignedLuaInt len = p_lua_tointeger(L, 3);
	UnsignedLuaInt mask = 0x0;
	for (UnsignedLuaInt i = 0; i < len; ++i) {
		mask = (mask << 1) | 1;
	}
	p_lua_pushinteger(L, (num >> start) & mask);
	return 1;
}

int freeLua(lua_State* L) {
	void* ptr = reinterpret_cast<void*>(p_lua_tointeger(L, 1));
	p_free(ptr);
	return 0;
}

int getLuaRegistryIndexLua(lua_State* L) {
	castLuaIntArg(1, int, n)
	p_lua_rawgeti(L, LUA_REGISTRYINDEX, n);
	return 1;
}

int getMicrosecondsLua(lua_State* L) {
	p_lua_pushinteger(L, currentMicroseconds() - initTime);
	return 1;
}

int getPatternMapLua(lua_State* L) {
	p_lua_newtable(L);                                    // [ table ]
	for (auto& pattern : patternEntries) {
		p_lua_pushstring(L, ws2s(pattern.first).c_str()); // [ table, k ]
		p_lua_pushinteger(L, pattern.second.value);       // [ table, k, v ]
		p_lua_rawset(L, -3);                              // [ table ]
	}
	return 1;
}

int iterateRegexLua(lua_State* L) {

	const char* str = p_lua_tostring(L, 1);
	const char* strEnd = str;
	while (*strEnd) ++strEnd;
	std::regex pattern{ p_lua_tostring(L, 2) };
	std::cregex_iterator foundBegin{ str, strEnd, pattern };
	std::cregex_iterator foundEnd;

	p_lua_getglobal(L, "debug");                                 // [ debug ]
	p_lua_getfield(L, -1, "traceback");                          // [ debug, traceback ]

	for (std::cregex_iterator& i = foundBegin; i != foundEnd; ++i) {

		const std::cmatch& match = *i;
		p_lua_pushvalue(L, 3);                                   // [ debug, traceback, func ]
		p_lua_pushinteger(L, match.position() + 1);              // [ debug, traceback, func, pos ]
		p_lua_pushinteger(L, match.position() + match.length()); // [ debug, traceback, func, pos, endPos ]
		p_lua_pushstring(L, match.str().c_str());                // [ debug, traceback, func, pos, endPos, str ]

		p_lua_newtable(L);                                       // [ debug, traceback, func, pos, endPos, str, groups ]
		for (size_t i = 1; i < match.size(); ++i) {
			const std::csub_match& subMatch = match[i];
			p_lua_pushinteger(L, i);                             // [ debug, traceback, func, pos, endPos, str, groups, k ]
			if (!subMatch.length()) {
				p_lua_pushnil(L);                                // [ debug, traceback, func, pos, endPos, str, groups, k, nil ]
			}
			else {
				p_lua_pushstring(L, subMatch.str().c_str());     // [ debug, traceback, func, pos, endPos, str, groups, k, v ]
			}
			p_lua_rawset(L, -3);                                 // [ debug, traceback, func, pos, endPos, str, groups ]
		}

		if (p_lua_pcallk(L, 4, 1, -6, 0, nullptr) != LUA_OK) {
			                                                     // [ debug, traceback, errorMessage ]
			Print("[!] %s\n", p_lua_tostring(L, -1));
			p_lua_pop(L, 1);                                     // [ debug, traceback ]
			break;
		}
		else {
			                                                     // [ debug, traceback, ret ]
			int retVal = p_lua_toboolean(L, -1);
			p_lua_pop(L, 1);                                     // [ debug, traceback ]
			if (retVal) {
				break;
			}
		}
	}

	p_lua_pop(L, 2);                                             // [ ]
	return 0;
}

int jitLua(lua_State* L) {

	asmjit::CodeHolder code;
	code.init(rt.environment());

	asmjit::x86::Assembler a(&code);
	asmtk::AsmParser p(&a);

	if (asmjit::Error err = p.parse(p_lua_tostring(L, 1))) {
		Print("[!] AsmJit failed: %s\n", asmjit::DebugUtils::errorAsString(err));
		return 0;
	}

	void* ptr;
	if (asmjit::Error err = rt.add(&ptr, &code)) {
		Print("[!] AsmJit failed: %s\n", asmjit::DebugUtils::errorAsString(err));
		return 0;
	}

	p_lua_pushinteger(L, reinterpret_cast<intptr_t>(ptr));
	return 1;
}

int jitAtInternalLua(lua_State* L) {

	asmjit::CodeHolder code;
	code.init(rt.environment());

	asmjit::x86::Assembler a(&code);
	asmtk::AsmParser p(&a);

	if (asmjit::Error err = p.parse(p_lua_tostring(L, 3))) {
		Print("[!] AsmJit failed: %s\n", asmjit::DebugUtils::errorAsString(err));
		return 0;
	}

	auto checkFunc = [&](size_t size) {

		p_lua_getglobal(L, "debug");        // [ debug ]
		p_lua_getfield(L, -1, "traceback"); // [ debug, traceback ]

		p_lua_pushvalue(L, 2);              // [ debug, traceback, func ]
		p_lua_pushinteger(L, size);         // [ debug, traceback, func, size ]
		if (p_lua_pcallk(L, 1, 1, -3, 0, nullptr) != LUA_OK) {
			                                // [ debug, traceback, errorMessage ]
			Print("[!] AsmJit failed: %s\n", p_lua_tostring(L, -1));
			p_lua_pop(L, 3);                // [ ]
			return reinterpret_cast<uint8_t*>(-1);
		}
		                                    // [ debug, traceback, result ]
		uint8_t* newDst = reinterpret_cast<uint8_t*>(p_lua_tointeger(L, -1));
		p_lua_pop(L, 3);                    // [ ]
		return newDst;
	};

	if (asmjit::Error err = jitAt(reinterpret_cast<uint8_t*>(p_lua_tointeger(L, 1)), &code, checkFunc)) {
		Print("[!] AsmJit failed: %s\n", asmjit::DebugUtils::errorAsString(err));
		return 0;
	}

	return 0;
}

int loadLuaBindingsLua(lua_State* L) {

	const char* bindingsFileName = p_lua_tolstring(L, 1, nullptr);
	StringA bindingsPath = getWorkingFolderA().append(bindingsFileName).append(".dll");

	HMODULE bindingsHandle;
	if (bindingsHandle = LoadLibraryA(bindingsPath.c_str()); !bindingsHandle) {
		Print("[!] LoadLibraryA failed (%d).\n", GetLastError());
		return 0;
	}

	FARPROC proc;
	if (proc = GetProcAddress(bindingsHandle, "Init"); !proc) {
		Print("[!] GetProcAddress failed (%d).\n", GetLastError());
		return 0;
	}

	typedef void(__stdcall* type_Init)(void*, std::map<String, PatternEntry>&, ImageSectionInfo&, bool, bool);
	type_Init initProc = reinterpret_cast<type_Init>(proc);
	initProc(L, patternEntries, textInfo, debug, protonCompatibility);

	return 0;
}

int lshiftLua(lua_State* L) {
	p_lua_pushinteger(L, static_cast<UnsignedLuaInt>(p_lua_tointeger(L, 1)) << static_cast<UnsignedLuaInt>(p_lua_tointeger(L, 2)));
	return 1;
}

int mallocLua(lua_State* L) {
	castLuaIntArg(1, size_t, size)
	p_lua_pushinteger(L, reinterpret_cast<lua_Integer>(p_malloc(size)));
	return 1;
}

int memcpyLua(lua_State* L) {
	castLuaIntArg(3, size_t, size)
	memcpy(reinterpret_cast<void*>(p_lua_tointeger(L, 1)), reinterpret_cast<void*>(p_lua_tointeger(L, 2)), size);
	return 0;
}

int memsetLua(lua_State* L) {
	castLuaIntArg(2, int, val)
	castLuaIntArg(3, size_t, size)
	memset(reinterpret_cast<void*>(p_lua_tointeger(L, 1)), val, size);
	return 0;
}

int messageBoxInternalLua(lua_State* L) {
	castLuaIntArg(2, UINT, uType)
	MessageBoxA(NULL, p_lua_tostring(L, 1), "EEex", uType);
	return 0;
}

int printLua(lua_State* L) {
	Print("%s\n", p_lua_tostring(L, 1));
	return 0;
}

int printErrLua(lua_State* L) {
	PrintErr("%s\n", p_lua_tostring(L, 1));
	return 0;
}

int read16Lua(lua_State* L) {
	p_lua_pushinteger(L, *reinterpret_cast<__int16*>(p_lua_tointeger(L, 1)));
	return 1;
}

int read32Lua(lua_State* L) {
	p_lua_pushinteger(L, *reinterpret_cast<__int32*>(p_lua_tointeger(L, 1)));
	return 1;
}

#if defined(_WIN64)
int read64Lua(lua_State* L) {
	p_lua_pushinteger(L, *reinterpret_cast<__int64*>(p_lua_tointeger(L, 1)));
	return 1;
}
#endif

int read8Lua(lua_State* L) {
	p_lua_pushinteger(L, *reinterpret_cast<__int8*>(p_lua_tointeger(L, 1)));
	return 1;
}

int readPointerLua(lua_State* L) {
	p_lua_pushinteger(L, *reinterpret_cast<uintptr_t*>(p_lua_tointeger(L, 1)));
	return 1;
}

int readU16Lua(lua_State* L) {
	p_lua_pushinteger(L, *reinterpret_cast<unsigned __int16*>(p_lua_tointeger(L, 1)));
	return 1;
}

int readU32Lua(lua_State* L) {
	p_lua_pushinteger(L, *reinterpret_cast<unsigned __int32*>(p_lua_tointeger(L, 1)));
	return 1;
}

#if defined(_WIN64)
int readU64Lua(lua_State* L) {
	p_lua_pushinteger(L, *reinterpret_cast<unsigned __int64*>(p_lua_tointeger(L, 1)));
	return 1;
}
#endif

int readU8Lua(lua_State* L) {
	p_lua_pushinteger(L, *reinterpret_cast<unsigned __int8*>(p_lua_tointeger(L, 1)));
	return 1;
}

int readLString(lua_State* L) {
	const char *const data { reinterpret_cast<char*>(p_lua_tointeger(L, 1)) };
	castLuaIntArg(2, size_t, length)
	char *const localCopy { reinterpret_cast<char*>(alloca(length + 1)) };
	size_t i { 0 };
	for (; i < length; ++i) {
		const char readVal { data[i] };
		if (readVal == '\0') {
			break;
		}
		localCopy[i] = readVal;
	}
	localCopy[i] = '\0';
	p_lua_pushstring(L, localCopy);
	return 1;
}

int readString(lua_State* L) {
	p_lua_pushstring(L, reinterpret_cast<const char*>(p_lua_tointeger(L, 1)));
	return 1;
}

int rshiftLua(lua_State* L) {
	p_lua_pushinteger(L, static_cast<UnsignedLuaInt>(p_lua_tointeger(L, 1)) >> static_cast<UnsignedLuaInt>(p_lua_tointeger(L, 2)));
	return 1;
}

int runWithStackLua(lua_State* L) {

	castLuaIntArg(1, size_t, size)

	p_lua_getglobal(L, "debug");                              // [ debug ]
	p_lua_getfield(L, -1, "traceback");                       // [ debug, traceback ]
	p_lua_pushvalue(L, 2);                                    // [ debug, traceback, func ]

	void* mem = alloca(size);
	p_lua_pushinteger(L, reinterpret_cast<lua_Integer>(mem)); // [ debug, traceback, func, stackPtr ]

	if (p_lua_pcallk(L, 1, 0, -3, 0, nullptr) != LUA_OK) {
															  // [ debug, traceback, errorMessage ]
		Print("[!] %s\n", p_lua_tostring(L, -1));
		p_lua_pop(L, 3);                                      // [ ]
	}
	else {
															  // [ debug, traceback ]
		p_lua_pop(L, 2);                                      // [ ]
	}

	return 0;
}

int setLuaRegistryIndexLua(lua_State* L) {
	castLuaIntArg(1, int, n)
	p_lua_pushvalue(L, 2);
	p_lua_rawseti(L, LUA_REGISTRYINDEX, n);
	return 0;
}

int write16Lua(lua_State* L) {
	castLuaIntArg(2, __int16, val)
	*reinterpret_cast<__int16*>(p_lua_tointeger(L, 1)) = val;
	return 0;
}

int write32Lua(lua_State* L) {
	castLuaIntArg(2, __int32, val)
	*reinterpret_cast<__int32*>(p_lua_tointeger(L, 1)) = val;
	return 0;
}

#if defined(_WIN64)
int write64Lua(lua_State* L) {
	castLuaIntArg(2, __int64, val)
	*reinterpret_cast<__int64*>(p_lua_tointeger(L, 1)) = val;
	return 0;
}
#endif

int write8Lua(lua_State* L) {
	castLuaIntArg(2, __int8, val)
	*reinterpret_cast<__int8*>(p_lua_tointeger(L, 1)) = val;
	return 0;
}

int writePointerLua(lua_State* L) {
	*reinterpret_cast<uintptr_t*>(p_lua_tointeger(L, 1)) = p_lua_tointeger(L, 2);
	return 0;
}

int writeLStringLua(lua_State* L) {
	char* dest = reinterpret_cast<char*>(p_lua_tointeger(L, 1));
	const char* src = p_lua_tostring(L, 2);
	castLuaIntArg(3, size_t, limit)
	size_t i = 0;
	for (; i < limit; ++i) {
		*dest++ = *src++;
	}
	if (i < limit) {
		*dest = '\0';
	}
	return 0;
}

int writeStringLua(lua_State* L) {
	char* writePtr = reinterpret_cast<char*>(p_lua_tointeger(L, 1));
	const char* str = p_lua_tostring(L, 2);
	while (true) {
		const char existingChar = *str++;
		*writePtr++ = existingChar;
		if (existingChar == '\0') {
			break;
		}
	}
	return 0;
}

int writeStringAutoLua(lua_State* L) {
	const char* str = p_lua_tostring(L, 1);
	size_t len = strlen(str);
	char* newStr = reinterpret_cast<char*>(p_malloc(len + 1));
	char* newStrWPtr = newStr;
	for (size_t i = 0; i < len; ++i) {
		*newStrWPtr++ = *str++;
	}
	*newStrWPtr = '\0';
	p_lua_pushinteger(L, reinterpret_cast<intptr_t>(newStr));
	return 1;
}

////////////////////
// Initialization //
////////////////////

DWORD parentProcessId;
HANDLE parentStdIn;
HANDLE parentStdOut;
HANDLE parentStdErr;

#undef fprintf

int logShim(FILE* stream, const char* format, const char* level, const char* message) {
	if (!protonCompatibility) {
		return fprintf(stderr, format, level, message); // Intentionally not FPrint
	}
	else {
		FPrint(stderr, format, level, message);
		return 0;
	}
}

#define fprintf error

int logShimDisable(FILE* stream, const char* format, const char* level, const char* message) {
	return 0;
}

DWORD writeReplaceLogFunction(bool disable_fprintf = false) {

	intptr_t patchAddress;
	if (DWORD lastError = findINICategoryPattern(textInfo, iniPath, TEXT("Hardcoded_SDL_LogOutput()_fprintf"), patchAddress)) {
		return lastError;
	}

	intptr_t curAllocatedPtr;
	SYSTEM_INFO info;
	GetSystemInfo(&info);

	if (DWORD lastError = allocateNear(textInfo.ImageBase, info.dwAllocationGranularity,
		info.dwAllocationGranularity, curAllocatedPtr))
	{
		return lastError;
	}

	unsigned char codeBuff[1024];
	AssemblyWriter writer{ codeBuff };

	writer.setLocation(patchAddress);
	writer.jmpToAddress(curAllocatedPtr);
	disableCodeProtection();
	writer.flush();
	enableCodeProtection();
	writer.setLocation(curAllocatedPtr);
	writer.callToAddressFar(reinterpret_cast<intptr_t>(!disable_fprintf ? logShim : logShimDisable));
	writer.jmpToAddress(patchAddress + 5);
	writer.flush();
	curAllocatedPtr = writer.getLocation();

	return 0;
}

void bindToParentOSHandles() {

	// The strategy:
	//
	//   1) AttachConsole(), (which should have been called before this), attaches to the target console
	//      and sets STD_INPUT_HANDLE/STD_OUTPUT_HANDLE/STD_ERROR_HANDLE to new HANDLEs. However, since
	//      these handles are newly-created, they do not inherit any of the OS handle redirections of the
	//      parent process.
	//
	//   2) The console must be attached for IO to work, though (duplicates) of the parent handles
	//      must be used to maintain redirection.
	//
	//   3) Calling DuplicateHandle() and SetStdHandle() for every parent handle to make this process
	//      maintain parent redirection. Note: While this replaces the STD_INPUT_HANDLE/
	//      STD_OUTPUT_HANDLE/STD_ERROR_HANDLE values set by AttachConsole(), those handles are still
	//      cached by the crt, and are eventually closed by FreeConsole(). They MUST stay open to
	//      avoid INVALID_HANDLE_VALUE exceptions on console cleanup. This is why CloseHandle() is
	//      omitted before replacing STD_INPUT_HANDLE/STD_OUTPUT_HANDLE/STD_ERROR_HANDLE via SetStdHandle().

	HANDLE parentProcessHandle = OpenProcess(PROCESS_DUP_HANDLE, false, parentProcessId);
	HANDLE currentProcessHandle = GetCurrentProcess();
	HANDLE duplicatedHandle;

	DuplicateHandle(parentProcessHandle, parentStdIn, currentProcessHandle, &duplicatedHandle, 0, false, DUPLICATE_SAME_ACCESS);
	SetStdHandle(STD_INPUT_HANDLE, duplicatedHandle);

	DuplicateHandle(parentProcessHandle, parentStdOut, currentProcessHandle, &duplicatedHandle, 0, false, DUPLICATE_SAME_ACCESS);
	SetStdHandle(STD_OUTPUT_HANDLE, duplicatedHandle);

	DuplicateHandle(parentProcessHandle, parentStdErr, currentProcessHandle, &duplicatedHandle, 0, false, DUPLICATE_SAME_ACCESS);
	SetStdHandle(STD_ERROR_HANDLE, duplicatedHandle);

	BindCrtStreamsToOSHandles();
	CloseHandle(parentProcessHandle);
}

bool attachedToConsole = false;

DWORD attachToConsole(bool force = false) {

	if (protonCompatibility) {
		return ERROR_SUCCESS;
	}

	if (!force && attachedToConsole) {
		return ERROR_SUCCESS;
	}

	if (!AttachConsole(parentProcessId)) {
		const DWORD lastError = GetLastError();
		MessageBoxFormat(TEXT("InfinityLoaderDLL"), MB_ICONERROR, TEXT("AttachConsole failed (%d)."), lastError);
		return lastError;
	}

	bindToParentOSHandles();
	attachedToConsole = true;

	if (debug) {
		Print("[?] attachToConsole(force = %s)\n", force ? "true" : "false");
	}

	return ERROR_SUCCESS;
}

DWORD detatchFromConsole(bool force = false) {

	if (protonCompatibility) {
		return ERROR_SUCCESS;
	}

	if (!force) {

		if (!attachedToConsole) {
			return ERROR_SUCCESS;
		}

		bool keepConsoleAttached;
		if (GetINIIntegerDef<bool>(iniPath, TEXT("General"), TEXT("KeepConsoleAttached"), false, keepConsoleAttached) == ERROR_SUCCESS
			&& keepConsoleAttached)
		{
			return ERROR_SUCCESS;
		}
	}

	if (debug) {
		Print("[?] detatchFromConsole(force = %s)\n", force ? "true" : "false");
	}

	if (!FreeConsole()) {
		const DWORD lastError = GetLastError();
		MessageBoxFormat(TEXT("InfinityLoaderDLL"), MB_ICONERROR, TEXT("FreeConsole failed (%d)."), lastError);
		return lastError;
	}

	// FreeConsole() NtClose()'s all of the cached OS handles, though the duplicated
	// OS handles in the file descriptors still need to be closed.

	bool keepCrtStreamsAttached;
	if (GetINIIntegerDef<bool>(iniPath, TEXT("General"), TEXT("KeepCrtStreamsAttached"), false, keepCrtStreamsAttached) == ERROR_SUCCESS
		&& !keepCrtStreamsAttached)
	{
		NulCrtStreams();
	}

	// Close the duplicated parent handles so they don't leak, (crt may still hold
	// a duplicate of the duplicate if KeepCrtStreamsAttached=1, which is fine,
	// since they will be closed on the next attachToConsole()).
	//
	// Note: KeepCrtStreamsAttached=1 keeps the crt handles valid, while also closing
	// STD_INPUT_HANDLE/STD_OUTPUT_HANDLE/STD_ERROR_HANDLE. This may cause side effects
	// if the loader code / child processes expect GetStdHandle() to be valid.
	//
	// Note: SetStdHandle()'ing STD_INPUT_HANDLE/STD_OUTPUT_HANDLE/STD_ERROR_HANDLE
	// prevents the game from inheriting them, which is assumed by the rest of the
	// loader code. This prevents duplicate output for a non-patched SDL_LogOuput(),
	// because that function WriteConsole()'s and fprintf()'s, the latter is assumed
	// to be going to nul.

	CloseHandle(GetStdHandle(STD_INPUT_HANDLE));
	CloseHandle(GetStdHandle(STD_OUTPUT_HANDLE));
	CloseHandle(GetStdHandle(STD_ERROR_HANDLE));
	SetStdHandle(STD_INPUT_HANDLE, INVALID_HANDLE_VALUE);
	SetStdHandle(STD_OUTPUT_HANDLE, INVALID_HANDLE_VALUE);
	SetStdHandle(STD_ERROR_HANDLE, INVALID_HANDLE_VALUE);

	attachedToConsole = false;
	return ERROR_SUCCESS;
}

void winMainHook() {

	if (debug) {
		Print("[?] Debug output 2 (Windows: No, Proton: Yes)...\n");
	}

	// This function runs before the console has been attached, temporarily attach it for error output
	if (attachToConsole() != ERROR_SUCCESS) {
		return;
	}

	if (debug) {

		Print("[?] Debug output 3 (Windows: Yes, Proton: Yes)...\n");

		Print("[?] Game hStdInput: %d\n", GetStdHandle(STD_INPUT_HANDLE));
		Print("[?] Game hStdOutput: %d\n", GetStdHandle(STD_OUTPUT_HANDLE));
		Print("[?] Game hStdError: %d\n", GetStdHandle(STD_ERROR_HANDLE));
	}

	bool installLogRedirect = false;
	bool disable_fprintf = false;

	if (GetFileType(GetStdHandle(STD_ERROR_HANDLE)) != FILE_TYPE_CHAR) {

		// Redirecting output, use my fprintf so that it is actually redirected.
		// Ideally the exe's stdin, stdout, and stderr would be redirected, however,
		// this is extremely difficult to correct due to its statically linked c-runtime.
		// If AttachConsole() + BindCrtHandlesToStdHandles() are run in this DLL's Init()
		// the game will inherit redirected handles, though this makes logging too slow
		// in the case of stderr being spammed, (fprintf is SLOW, the engine normally
		// uses WriteConsole).
		//
		// Note: This only redirects SDL_LogOutput(), though most of the game's logging
		// goes through this function, and stdin, stdout, and stderr aren't normally
		// hooked up to the console anyway.

		installLogRedirect = true;
	}
	else if (protonCompatibility) {
		installLogRedirect = true;
		disable_fprintf = true;
	}

	if (installLogRedirect) {

		if (debug) {
			Print("[?] Redirecting output, disable_fprintf: %s\n", disable_fprintf ? "true" : "false");
		}

		if (DWORD redirectResult = writeReplaceLogFunction(disable_fprintf)) {
			Print("[!] Console redirection failed (%d).\n", redirectResult);
			goto cleanup;
		}
	}

cleanup:;
	detatchFromConsole();
}

template<typename pointer_type>
void fillExportedPointer(const String& name, pointer_type& pointer, intptr_t address) {
	patternEntries.emplace(name, PatternEntry{ name, address });
	pointer = reinterpret_cast<pointer_type>(address);
}

template<typename pointer_type>
void fillExportedPointer(const String& name, pointer_type& pointer, void* address) {
	fillExportedPointer(name, pointer, reinterpret_cast<intptr_t>(address));
}

template<typename pointer_type, typename operations_type>
bool fillPatternPointer(const String& name, pointer_type& pointer, const operations_type& operations) {

	intptr_t address;
	if (findINICategoryPattern(textInfo, iniPath, name, address)) {
		return true;
	}

	operations(address);
	fillExportedPointer(name, pointer, address);
	return false;
}

template<typename pointer_type>
bool fillPatternPointer(const String& name, pointer_type& pointer) {
	return fillPatternPointer(name, pointer, [](intptr_t& address){});
}

template<typename out_type>
DWORD getLuaProc(const StringA& name, out_type& out) {
	if (out = reinterpret_cast<out_type>(GetProcAddress(luaLibrary, name.c_str())); out == 0) {
		DWORD lastError = GetLastError();
		Print("[!] GetProcAddress failed (%d) to find Lua function \"%s\".\n", lastError, name.c_str());
		return lastError;
	}
	return 0;
}

template<typename pointer_type, typename operations_type>
DWORD fillLuaPointer(const String& name, pointer_type& pointer, const operations_type& operations) {

	const String hardcodedName = TEXT("Hardcoded_") + name;
	intptr_t address;

	if (luaMode == LuaMode::EXTERNAL) {
		if (DWORD lastError = getLuaProc(StringToStringA(name), address)) {
			return lastError;
		}
	}
	else {
		if (DWORD lastError = findINICategoryPattern(textInfo, iniPath, hardcodedName, address)) {
			return lastError;
		}
		operations(address);
	}

	fillExportedPointer(hardcodedName, pointer, address);
	return 0;
}

template<typename pointer_type>
bool fillLuaPointer(const String& name, pointer_type& pointer) {
	return fillLuaPointer(name, pointer, [](intptr_t& address) {});
}

void initLua() {

	if (debug) {
		Print("[?] Debug output 4 (Windows: No, Proton: Yes)...\n");
	}

	// This function runs before the console has been attached, temporarily attach it for error output
	if (attachToConsole() != ERROR_SUCCESS) {
		return;
	}

	if (debug) {
		Print("[?] Debug output 5 (Windows: Yes, Proton: Yes)...\n");
	}

#define fillPatternPointerLookup(name, outName) \
	if (fillPatternPointer(TEXT(name), p_##outName)) { \
		goto cleanup; \
	}

#define fillLuaPointerLookup(name, outName) \
	if (fillLuaPointer(TEXT(name), p_##outName)) { \
		goto cleanup; \
	}

	/////////////////////////////
	// Find Hardcoded Patterns //
	/////////////////////////////

	fillLuaPointerLookup("lua_createtable", lua_createtable);
	fillLuaPointerLookup("lua_getfield", lua_getfield);
	fillLuaPointerLookup("lua_getglobal", lua_getglobal);
	fillLuaPointerLookup("lua_gettop", lua_gettop);
	fillLuaPointerLookup("lua_pcallk", lua_pcallk);
	fillLuaPointerLookup("lua_pushcclosure", lua_pushcclosure);
	fillLuaPointerLookup("lua_pushinteger", lua_pushinteger);
	fillLuaPointerLookup("lua_pushnil", lua_pushnil);
	fillLuaPointerLookup("lua_pushstring", lua_pushstring);
	fillLuaPointerLookup("lua_pushvalue", lua_pushvalue);
	fillLuaPointerLookup("lua_rawgeti", lua_rawgeti);
	fillLuaPointerLookup("lua_rawset", lua_rawset);
	fillLuaPointerLookup("lua_rawseti", lua_rawseti);
	fillLuaPointerLookup("lua_setglobal", lua_setglobal);
	fillLuaPointerLookup("lua_settop", lua_settop);
	fillLuaPointerLookup("lua_toboolean", lua_toboolean);
	fillLuaPointerLookup("lua_tointegerx", lua_tointegerx);
	fillLuaPointerLookup("lua_tolstring", lua_tolstring);
	fillLuaPointerLookup("lua_type", lua_type);
	fillLuaPointerLookup("luaL_error", luaL_error);
	fillLuaPointerLookup("luaL_loadfilex", luaL_loadfilex);
	fillLuaPointerLookup("luaL_ref", luaL_ref);

	lua_State* L;

	if (luaMode == LuaMode::INTERNAL) {
		if (fillPatternPointer(TEXT("Hardcoded_InternalLuaState"), L, [](intptr_t& address) {
			address = *reinterpret_cast<intptr_t*>(address);
		})) {
			goto cleanup;
		}
	}
	else {

		typedef lua_State* (__cdecl* type_luaL_newstate)();
		type_luaL_newstate p_luaL_newstate;

		typedef void (__cdecl* type_luaL_openlibs)(lua_State*);
		type_luaL_openlibs p_luaL_openlibs;

		if (getLuaProc("luaL_newstate", p_luaL_newstate)) {
			goto cleanup;
		}

		if (getLuaProc("luaL_openlibs", p_luaL_openlibs)) {
			goto cleanup;
		}

		fillExportedPointer(TEXT("Hardcoded_InternalLuaState"), L, p_luaL_newstate());
		p_luaL_openlibs(L);
	}

	////////////////////////
	// Export Lua Globals //
	////////////////////////

	p_lua_pushinteger(L, sizeof(void*));
	p_lua_setglobal(L, "EEex_PointerSize");

	p_lua_pushinteger(L, sizeof(void*));
	p_lua_setglobal(L, "EEex_PtrSize");

	//////////////////////////
	// Export Lua Functions //
	//////////////////////////

	exposeToLua(L, "EEex_AddToLuaRegistry", addToLuaRegistryLua);
	exposeToLua(L, "EEex_AllocCodePageInternal", allocCodePageInternalLua);
	exposeToLua(L, "EEex_BAnd", bandLua);
	exposeToLua(L, "EEex_BNot", bnotLua);
	exposeToLua(L, "EEex_BOr", borLua);
	exposeToLua(L, "EEex_DisableCodeProtection", disableCodeProtectionLua);
	exposeToLua(L, "EEex_DoFile", doFileLua);
	exposeToLua(L, "EEex_EnableCodeProtection", enableCodeProtectionLua);
	exposeToLua(L, "EEex_Extract", extractLua);
	exposeToLua(L, "EEex_Free", freeLua);
	exposeToLua(L, "EEex_GetLuaRegistryIndex", getLuaRegistryIndexLua);
	exposeToLua(L, "EEex_GetMicroseconds", getMicrosecondsLua);
	exposeToLua(L, "EEex_GetPatternMap", getPatternMapLua);
	exposeToLua(L, "EEex_IterateRegex", iterateRegexLua);
	exposeToLua(L, "EEex_JIT", jitLua);
	exposeToLua(L, "EEex_JITAtInternal", jitAtInternalLua);
	exposeToLua(L, "EEex_LoadLuaBindings", loadLuaBindingsLua);
	exposeToLua(L, "EEex_LShift", lshiftLua);
	exposeToLua(L, "EEex_Malloc", mallocLua);
	exposeToLua(L, "EEex_Memcpy", memcpyLua);
	exposeToLua(L, "EEex_Memset", memsetLua);
	exposeToLua(L, "EEex_MessageBoxInternal", messageBoxInternalLua);
	exposeToLua(L, "EEex_Print", printLua);
	exposeToLua(L, "EEex_PrintErr", printErrLua);
	exposeToLua(L, "EEex_Read16", read16Lua);
	exposeToLua(L, "EEex_Read32", read32Lua);
#if defined(_WIN64)
	exposeToLua(L, "EEex_Read64", read64Lua);
#endif
	exposeToLua(L, "EEex_Read8", read8Lua);
	exposeToLua(L, "EEex_ReadPointer", readPointerLua);
	exposeToLua(L, "EEex_ReadPtr", readPointerLua);
	exposeToLua(L, "EEex_ReadU16", readU16Lua);
	exposeToLua(L, "EEex_ReadU32", readU32Lua);
#if defined(_WIN64)
	exposeToLua(L, "EEex_ReadU64", readU64Lua);
#endif
	exposeToLua(L, "EEex_ReadU8", readU8Lua);
	exposeToLua(L, "EEex_ReadLString", readLString);
	exposeToLua(L, "EEex_ReadString", readString);
	exposeToLua(L, "EEex_RShift", rshiftLua);
	exposeToLua(L, "EEex_RunWithStack", runWithStackLua);
	exposeToLua(L, "EEex_SetLuaRegistryIndex", setLuaRegistryIndexLua);
	exposeToLua(L, "EEex_Write16", write16Lua);
	exposeToLua(L, "EEex_Write32", write32Lua);
#if defined(_WIN64)
	exposeToLua(L, "EEex_Write64", write64Lua);
#endif
	exposeToLua(L, "EEex_Write8", write8Lua);
	exposeToLua(L, "EEex_WritePointer", writePointerLua);
	exposeToLua(L, "EEex_WritePtr", writePointerLua);
	exposeToLua(L, "EEex_WriteLString", writeLStringLua);
	exposeToLua(L, "EEex_WriteString", writeStringLua);
	exposeToLua(L, "EEex_WriteStringAuto", writeStringAutoLua);

	///////////////////////
	// Run Main Lua File //
	///////////////////////

	if (luaMode == LuaMode::INTERNAL) {
		fillPatternPointerLookup("Hardcoded_free", free);
		fillPatternPointerLookup("Hardcoded_malloc", malloc);
		callOverrideFile(L, "EEex_Main");
	}
	else {

		// LuaMode::EXTERNAL calls EEex_Main.lua before __tmainCRTStartup() has
		// been called to initialize the game's heap. Let EEex_Main.lua use the
		// DLL's heap for initialization.
		//
		// Note: Memory allocated during initialization should NEVER be freed.
		// Since free() is swapped out after EEex_Main.lua, attempting to free
		// memory allocated during initialization results in the wrong heap
		// being modified.

		fillExportedPointer(TEXT("Hardcoded_free"), p_free, free);
		fillExportedPointer(TEXT("Hardcoded_malloc"), p_malloc, malloc);
		callOverrideFile(L, "EEex_Main");
		fillPatternPointerLookup("Hardcoded_free", free);
		fillPatternPointerLookup("Hardcoded_malloc", malloc);
	}

cleanup:;
	detatchFromConsole();
}

void writeCallHookProcAfterCall(AssemblyWriter& writer, intptr_t& curAllocatedPtr, intptr_t patchAddress, void* targetProc) {

	__int32 relativeAmount = *reinterpret_cast<__int32*>(patchAddress + 1);
	intptr_t target = patchAddress + 5 + relativeAmount;

	writer.setLocation(patchAddress);
	writer.jmpToAddress(curAllocatedPtr);
	disableCodeProtection();
	writer.flush();
	enableCodeProtection();

	writer.setLocation(curAllocatedPtr);
	writer.callToAddress(target);
	writer.pushVolatileRegisters();
	writer.alignStackAndMakeShadowSpace();
	writer.callToAddressFar(reinterpret_cast<intptr_t>(targetProc));
	writer.undoAlignAndShadowSpace();
	writer.popVolatileRegisters();
	writer.jmpToAddress(patchAddress + 5);
	writer.flush();
	curAllocatedPtr = writer.getLocation();
}

DWORD setUpLuaInitialization(ImageSectionInfo& textInfo) {

	intptr_t curAllocatedPtr;
	SYSTEM_INFO info;
	GetSystemInfo(&info);

	if (DWORD lastError = allocateNear(textInfo.ImageBase, info.dwAllocationGranularity,
		info.dwAllocationGranularity, curAllocatedPtr))
	{
		return lastError;
	}

	unsigned char codeBuff[1024];
	AssemblyWriter writer{ codeBuff };

	// Write hook early in WinMain to check for Console redirection

	if (INISectionExists(iniPath, TEXT("Hardcoded_WinMainPatchLocation"))) {

		intptr_t winMainPatchAddress;
		if (DWORD lastError = findINICategoryPattern(textInfo, iniPath, TEXT("Hardcoded_WinMainPatchLocation"), winMainPatchAddress)) {
			return lastError;
		}
		writeCallHookProcAfterCall(writer, curAllocatedPtr, winMainPatchAddress, winMainHook);
	}

	// Write Lua initialization hook

	if (DWORD lastError = loadLuaMode()) {
		return lastError;
	}

	if (luaMode == LuaMode::INTERNAL) {

		intptr_t patchAddress;
		if (DWORD lastError = findINICategoryPattern(textInfo, iniPath, TEXT("Hardcoded_InternalPatchLocation"), patchAddress)) {
			return lastError;
		}
		writeCallHookProcAfterCall(writer, curAllocatedPtr, patchAddress, initLua);
	}
	else {
		initLua();
	}

	return 0;
}

DWORD loadExePathAndName() {

	if (getExePath(exePath, &exeNameForPatterns)) {
		return -1;
	}

	String globalExeAlias;
	if (DWORD lastError = GetINIStringDef(iniPath, TEXT("General"), TEXT("ExeSwitchAlias"), TEXT(""), globalExeAlias)) {
		return lastError;
	}

	return resolveAliasTarget(globalExeAlias, exeNameForPatterns);
}

DWORD patchExe() {

	if (DWORD lastError = loadExePathAndName()) {
		return lastError;
	}

	HMODULE foundModule;
	if (DWORD lastError = findModuleWithPath(GetCurrentProcess(), exePath, foundModule)) {
		return lastError;
	}

	if (!findSectionInfo(foundModule, ".text", textInfo)) {
		Print("[!] Failed to locate .text segment.\n");
		return -1;
	}

	if (DWORD lastError = findPatterns(textInfo)) {
		return lastError;
	}

	if (DWORD lastError = setUpLuaInitialization(textInfo)) {
		return lastError;
	}

	return 0;
}

// Return:
//   0 -> No Error
//   1 -> Error (no console output)
//   2 -> Error (console output)

byte initOutput(HANDLE hSharedFile) {

	intptr_t bPause;
	if (GetINIIntegerDef<intptr_t>(iniPath, TEXT("General"), TEXT("Pause"), 0, bPause, LogMessageBox)) {
		return 1;
	}

	if (bPause) {
		MessageBox(NULL, TEXT("Pause"), TEXT("InfinityLoaderDLL"), MB_ICONINFORMATION);
	}

	SharedMemory *const sharedFilePtr = reinterpret_cast<SharedMemory*>(MapViewOfFile(hSharedFile,
		FILE_MAP_ALL_ACCESS,
		0,                   // Offset to map (high)
		0,                   // Offset to map (low)
		0                    // Number of bytes to map (0 = to end of file)
	));

	if (sharedFilePtr == nullptr) {
		DWORD lastError = GetLastError();
		MessageBoxFormatA("InfinityLoaderDLL", MB_ICONERROR, "[!] MapViewOfFile failed (%d).\n", lastError);
		return 1;
	}

	DllInitArguments& dllInitArguments = sharedFilePtr->dllInitArguments;
	parentProcessId = dllInitArguments.parentProcessId;
	parentStdIn = dllInitArguments.hStdIn;
	parentStdOut = dllInitArguments.hStdOut;
	parentStdErr = dllInitArguments.hStdErr;

	if (GetINIIntegerDef<bool>(iniPath, TEXT("General"), TEXT("Debug"), false, debug, LogMessageBox)) {
		return 1;
	}

	if (GetINIIntegerDef<bool>(iniPath, TEXT("General"), TEXT("ProtonCompatibility"), false, protonCompatibility, LogMessageBox)) {
		return 1;
	}

	// This function runs before the console has been attached, temporarily attach it for error output
	if (attachToConsole() != ERROR_SUCCESS) {
		return 1;
	}

	if (protonCompatibility) {
		if (int error = UnbufferCrtStreams()) {
			Print("[!] UnbufferCrtStreams failed (%d).\n", error);
			return 2;
		}
	}

	if (int error = InitFPrint(debug, protonCompatibility)) {
		Print("InitFPrint failed (%d).\n", error);
		return 2;
	}

	if (debug) {

		Print("[?] Debug output 1 (Windows: Yes, Proton: Yes)...\n");

		Print("[?] DLL hStdInput: %d\n", GetStdHandle(STD_INPUT_HANDLE));
		Print("[?] DLL hStdOutput: %d\n", GetStdHandle(STD_OUTPUT_HANDLE));
		Print("[?] DLL hStdError: %d\n", GetStdHandle(STD_ERROR_HANDLE));
	}

	return 0;
}

int exceptionFilter(unsigned int code, _EXCEPTION_POINTERS* pointers, unsigned int& codeOut) {
	String dmpLocation = writeDump(pointers);
	MessageBoxFormat(TEXT("InfinityLoaderDLL"), MB_ICONERROR, TEXT("Unhandled exception 0x%X. Crash log saved to:\n\n%s\n\nThis should never happen. Please report to Bubb."), code, dmpLocation.c_str());
	codeOut = code;
	return EXCEPTION_EXECUTE_HANDLER;
}

int exceptionFilterIgnoreIfSubsequent(unsigned int code, _EXCEPTION_POINTERS* pointers, unsigned int& codeOut) {
	if (!codeOut) {
		String dmpLocation = writeDump(pointers);
		MessageBoxFormat(TEXT("InfinityLoaderDLL"), MB_ICONERROR, TEXT("Unhandled exception 0x%X. Crash log saved to:\n\n%s\n\nThis should never happen. Please report to Bubb."), code, dmpLocation.c_str());
		codeOut = code;
	}
	return EXCEPTION_EXECUTE_HANDLER;
}

void Init(HANDLE hSharedFile) {

	unsigned int exitCode = 0;

	__try {

		initTime = currentMicroseconds();
		initPaths();

		if (byte result = initOutput(hSharedFile)) {
			if (result == 2) {
				goto errorLogged;
			}
			return;
		}

		if (patchExe()) {
			goto errorLogged;
		}
	}
	__except (exceptionFilter(GetExceptionCode(), GetExceptionInformation(), exitCode)) {}

	goto cleanup;

errorLogged:;

	__try {
		ShowWindow(GetConsoleWindow(), SW_SHOW);
		Print("Press any key to continue . . .\n");
		std::cin.get();
	}
	__except (exceptionFilterIgnoreIfSubsequent(GetExceptionCode(), GetExceptionInformation(), exitCode)) {}

cleanup:;

	__try {
		detatchFromConsole();
	}
	__except (exceptionFilterIgnoreIfSubsequent(GetExceptionCode(), GetExceptionInformation(), exitCode)) {}

	if (exitCode) {
		exit(exitCode);
	}
}
