
#include "InfinityLoaderCommon.h"

#include <dbghelp.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <map>
#include <psapi.h>
#include <regex>

#include "asmjit/asmjit.h"
#include "asmtk/asmtk.h"
#include "lua/lua.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}

//////////////
// Pointers //
//////////////

typedef void(__cdecl* type_free)(void* memblock);
type_free p_free;

typedef void(__cdecl* type_lua_createtable)(lua_State* L, int narr, int nrec);
type_lua_createtable p_lua_createtable;

typedef void(__cdecl* type_lua_getfield)(lua_State* L, int index, const char* k);
type_lua_getfield p_lua_getfield;

typedef void(__cdecl* type_lua_getglobal)(lua_State* L, const char* name);
type_lua_getglobal p_lua_getglobal;

typedef int(__cdecl* type_lua_gettop)(lua_State* L);
type_lua_gettop p_lua_gettop;

typedef int(__cdecl* type_lua_pcallk)(lua_State* L, int nargs, int nresults, int errfunc, int ctx, lua_CFunction k);
type_lua_pcallk p_lua_pcallk;

typedef void(__cdecl* type_lua_pushcclosure)(lua_State* L, lua_CFunction fn, int n);
type_lua_pushcclosure p_lua_pushcclosure;

typedef void(__cdecl* type_lua_pushinteger)(lua_State* L, lua_Integer n);
type_lua_pushinteger p_lua_pushinteger;

typedef void(__cdecl* type_lua_pushnil)(lua_State* L);
type_lua_pushnil p_lua_pushnil;

typedef const char*(__cdecl* type_lua_pushstring)(lua_State* L, const char* s);
type_lua_pushstring p_lua_pushstring;

typedef void(__cdecl* type_lua_pushvalue)(lua_State* L, int index);
type_lua_pushvalue p_lua_pushvalue;

typedef void(__cdecl* type_lua_rawgeti)(lua_State* L, int index, int n);
type_lua_rawgeti p_lua_rawgeti;

typedef void(__cdecl* type_lua_rawset)(lua_State* L, int index);
type_lua_rawset p_lua_rawset;

typedef void(__cdecl* type_lua_rawseti)(lua_State* L, int index, int n);
type_lua_rawseti p_lua_rawseti;

typedef void(__cdecl* type_lua_setglobal)(lua_State* L, const char* name);
type_lua_setglobal p_lua_setglobal;

typedef void(__cdecl* type_lua_settop)(lua_State* L, int index);
type_lua_settop p_lua_settop;

typedef int(__cdecl* type_lua_toboolean)(lua_State* L, int index);
type_lua_toboolean p_lua_toboolean;

typedef lua_Integer(__cdecl* type_lua_tointegerx)(lua_State* L, int index, int* isnum);
type_lua_tointegerx p_lua_tointegerx;

typedef const char*(__cdecl* type_lua_tolstring)(lua_State* L, int index, size_t* len);
type_lua_tolstring p_lua_tolstring;

typedef int(__cdecl* type_lua_type)(lua_State* L, int index);
type_lua_type p_lua_type;

typedef int(__cdecl* type_luaL_loadfilex)(lua_State* L, const char* fileName, const char* mode);
type_luaL_loadfilex p_luaL_loadfilex;

typedef int(__cdecl* type_luaL_ref)(lua_State* L, int t);
type_luaL_ref p_luaL_ref;

typedef void*(__cdecl* type_malloc)(size_t size);
type_malloc p_malloc;

#define p_lua_newtable(L) p_lua_createtable(L, 0, 0)
#define p_lua_pop(L, n) p_lua_settop(L, -(n) - 1)
#define p_lua_tointeger(L, i) p_lua_tointegerx(L, (i), NULL)
#define p_lua_tostring(L, i) p_lua_tolstring(L, (i), nullptr)

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

String exeName;
LuaMode luaMode;
ImageSectionInfo textInfo;
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

DWORD loadLuaMode() {

	String luaModeStr;
	if (DWORD lastError = GetINIString(iniPath, TEXT("General"), TEXT("LuaPatchMode"), TEXT(""), luaModeStr)) {
		return lastError;
	}

	if (luaModeStr == TEXT("INTERNAL")) {
		luaMode = LuaMode::INTERNAL;
	}
	else if (luaModeStr == TEXT("EXTERNAL")) {
		luaMode = LuaMode::EXTERNAL;
	}
	else {
		printf("[!] [General].LuaPatchMode must be either \"INTERNAL\" or \"EXTERNAL\".\n");
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
				printf("[!] GetModuleFileName failed (%d).\n", lastError);
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
		printf("[!] EnumProcessModules failed (%d).\n", lastError);
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
			printf("[!] Error in error handling calling debug.traceback()\n");
			p_lua_pop(L, 4);            // [ ]
			return;
		}
		                                // [ debug, traceback, errorMessage, errorMessageTraceback ]
		printf("[!] %s\n", p_lua_tostring(L, -1));
		p_lua_pop(L, 4);                // [ ]
		return;
	}
	                                    // [ debug, traceback, chunk ]
	if (p_lua_pcallk(L, 0, 0, -2, 0, nullptr) != LUA_OK) {
		                                // [ debug, traceback, errorMessage ]
		printf("[!] %s\n", p_lua_tostring(L, -1));
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
		printfT(TEXT("[!] Invalid number of arguments in %s operation for [%s].Operations: %d\n"), iniCategoryName.c_str(),
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
		printfT(TEXT("[!] Not enough values pushed onto stack in %s operation for [%s].Operations: %d < %d\n"),
				operationStr.c_str(), iniCategoryName.c_str(), static_cast<int>(stackSize), static_cast<int>(neededStackSize));
		return false;
	}
	return true;
}

bool tryOperationsConvertToDecimal(const String& iniCategoryName, const String& operationStr,
								   const std::vector<String>& parts, const int argI, intptr_t& out)
{
	String arg = parts[argI];
	if (!decimalStrToNumber(arg, out)) {
		printfT(TEXT("[!] Failed to convert %s argument to decimal for [%s].Operations: \"%s\"\n"),
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
			printfT(TEXT("[!] Operation missing for [%s].Operations\n"), iniCategoryName.c_str());
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
				printfT(TEXT("[!] Invalid READ argument for [%s].Operations: \"%s\"\n"), iniCategoryName.c_str(), arg1.c_str());
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
					printfT(TEXT("[!] Failed to decode BYTES value for [%s].Operations: \"%s\", %s\n"), iniCategoryName.c_str(), arg2.c_str(), errorStr.c_str());
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
					printfT(TEXT("[!] Invalid WRITE argument for [%s].Operations: \"%s\"\n"), iniCategoryName.c_str(), arg1.c_str());
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
			printfT(TEXT("[!] Invalid operation for [%s].Operations: \"%s\"\n"), iniCategoryName.c_str(), operationName.c_str());
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

DWORD findINICategoryPattern(ImageSectionInfo& sectionInfo, String iniPath, String iniCategoryName, intptr_t& addressOut) {

	intptr_t bExeSwitch;
	if (DWORD lastError = GetININumber(iniPath, iniCategoryName.c_str(), TEXT("ExeSwitch"), 0, bExeSwitch)) {
		return lastError;
	}

	if (bExeSwitch) {

		String exeAlias;
		if (DWORD lastError { GetINIString(iniPath, iniCategoryName.c_str(), TEXT("ExeSwitchAlias"), TEXT(""), exeAlias) }) {
			return lastError;
		}

		String exeSwitchName { exeName };
		if (exeAlias != TEXT("")) {

			bool error { false };
			forEveryCharSplit(exeAlias, TCHAR{ ',' }, [&](const String str) {

				size_t colonI { str.find(TCHAR{ ':' }) };

				if (colonI == std::string::npos) {
					printfT(TEXT("[!] Invalid ExeSwitchAlias: \"%s\".\n"), str.c_str());
					error = true;
					return true;
				}

				String alias { str.substr(0, colonI) };
				String target { str.substr(colonI + 1) };

				if (target.find(TCHAR{ ':' }) != std::string::npos) {
					printfT(TEXT("[!] Invalid ExeSwitchAlias: \"%s\".\n"), str.c_str());
					error = true;
					return true;
				}

				if (alias == exeName) {
					exeSwitchName = target;
					return true;
				}

				return false;
			});

			if (error) {
				return -1;
			}
		}

		iniCategoryName.insert(0, String{ TEXT("!ExeSwitch-") }.append(exeSwitchName).append(TEXT("-")));
	}

	String hardcodedPatchPattern;
	if (DWORD lastError = GetINIString(iniPath, iniCategoryName.c_str(), TEXT("Pattern"), TEXT(""), hardcodedPatchPattern)) {
		return lastError;
	}

	std::list<PatternByteEntry> byteList;
	String errorStr;
	if (!decodeByteString(hardcodedPatchPattern, byteList, errorStr)) {
		printfT(TEXT("[!] Failed to decode [%s].Pattern: \"%s\".\n"), iniCategoryName.c_str(), errorStr.c_str());
		return -1;
	}

	if (!findByteList(sectionInfo, byteList, addressOut)) {
		printfT(TEXT("[!] Could not find [%s].Pattern.\n"), iniCategoryName.c_str());
		return -1;
	}

	String operations;
	if (DWORD lastError = GetINIString(iniPath, iniCategoryName.c_str(), TEXT("Operations"), TEXT(""), operations)) {
		return lastError;
	}

	if (operations != TEXT("")) {
		handlePatternOperations(iniCategoryName, operations, addressOut);
	}

	return 0;
}

DWORD findPatterns(ImageSectionInfo& sectionInfo) {

	DWORD returnVal = 0;
	forEveryINISectionName(dbPath, [&](const String section) {

		if (section.rfind(TEXT("!"), 0) != std::string::npos)
			return false;

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

int bandLua(lua_State* L) {
	p_lua_pushinteger(L, static_cast<uintptr_t>(p_lua_tointeger(L, 1)) & static_cast<uintptr_t>(p_lua_tointeger(L, 2)));
	return 1;
}

int bnotLua(lua_State* L) {
	p_lua_pushinteger(L, ~static_cast<uintptr_t>(p_lua_tointeger(L, 1)));
	return 1;
}

int borLua(lua_State* L) {
	p_lua_pushinteger(L, static_cast<uintptr_t>(p_lua_tointeger(L, 1)) | static_cast<uintptr_t>(p_lua_tointeger(L, 2)));
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
	uintptr_t num = p_lua_tointeger(L, 1);
	uintptr_t start = p_lua_tointeger(L, 2);
	uintptr_t len = p_lua_tointeger(L, 3);
	uintptr_t mask = 0x0;
	for (uintptr_t i = 0; i < len; ++i) {
		mask = (mask << 1) | 1;
	}
	p_lua_pushinteger(L, (num >> start) & mask);
	return 1;
}

int freeLua(lua_State* L) {
	void* ptr = reinterpret_cast<void*>(p_lua_tointegerx(L, 1, nullptr));
	p_free(ptr);
	return 0;
}

int getLuaRegistryIndexLua(lua_State* L) {
	p_lua_rawgeti(L, LUA_REGISTRYINDEX, p_lua_tointeger(L, 1));
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
			printf("[!] %s\n", p_lua_tostring(L, -1));
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
		printf("[!] AsmJit failed: %s\n", asmjit::DebugUtils::errorAsString(err));
		return 0;
	}

	void* ptr;
	if (asmjit::Error err = rt.add(&ptr, &code)) {
		printf("[!] AsmJit failed: %s\n", asmjit::DebugUtils::errorAsString(err));
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
		printf("[!] AsmJit failed: %s\n", asmjit::DebugUtils::errorAsString(err));
		return 0;
	}

	auto checkFunc = [&](size_t size) {

		p_lua_getglobal(L, "debug");        // [ debug ]
		p_lua_getfield(L, -1, "traceback"); // [ debug, traceback ]

		p_lua_pushvalue(L, 2);              // [ debug, traceback, func ]
		p_lua_pushinteger(L, size);         // [ debug, traceback, func, size ]
		if (p_lua_pcallk(L, 1, 1, -3, 0, nullptr) != LUA_OK) {
			                                // [ debug, traceback, errorMessage ]
			printf("[!] AsmJit failed: %s\n", p_lua_tostring(L, -1));
			p_lua_pop(L, 3);                // [ ]
			return reinterpret_cast<uint8_t*>(-1);
		}
		                                    // [ debug, traceback, result ]
		uint8_t* newDst = reinterpret_cast<uint8_t*>(p_lua_tointeger(L, -1));
		p_lua_pop(L, 3);                    // [ ]
		return newDst;
	};

	if (asmjit::Error err = jitAt(reinterpret_cast<uint8_t*>(p_lua_tointeger(L, 1)), &code, checkFunc)) {
		printf("[!] AsmJit failed: %s\n", asmjit::DebugUtils::errorAsString(err));
		return 0;
	}

	return 0;
}

int loadLuaBindingsLua(lua_State* L) {

	const char* bindingsFileName = p_lua_tolstring(L, 1, nullptr);
	StringA bindingsPath = getWorkingFolderA().append(bindingsFileName).append(".dll");

	HMODULE bindingsHandle;
	if (bindingsHandle = LoadLibraryA(bindingsPath.c_str()); !bindingsHandle) {
		printf("[!] LoadLibraryA failed (%d).\n", GetLastError());
		return 0;
	}

	FARPROC proc;
	if (proc = GetProcAddress(bindingsHandle, "Init"); !proc) {
		printf("[!] GetProcAddress failed (%d).\n", GetLastError());
		return 0;
	}

	typedef void(__stdcall* type_Init)(void* L, std::map<String, PatternEntry>& patterns, ImageSectionInfo&);
	type_Init initProc = reinterpret_cast<type_Init>(proc);
	initProc(L, patternEntries, textInfo);

	return 0;
}

int lshiftLua(lua_State* L) {
	p_lua_pushinteger(L, static_cast<uintptr_t>(p_lua_tointeger(L, 1)) << static_cast<uintptr_t>(p_lua_tointeger(L, 2)));
	return 1;
}

int mallocLua(lua_State* L) {
	ptrdiff_t size = p_lua_tointegerx(L, 1, nullptr);
	p_lua_pushinteger(L, reinterpret_cast<ptrdiff_t>(p_malloc(size)));
	return 1;
}

int memcpyLua(lua_State* L) {
	memcpy(reinterpret_cast<void*>(p_lua_tointeger(L, 1)), reinterpret_cast<void*>(p_lua_tointeger(L, 2)), p_lua_tointeger(L, 3));
	return 0;
}

int memsetLua(lua_State* L) {
	memset(reinterpret_cast<void*>(p_lua_tointeger(L, 1)), p_lua_tointeger(L, 2), p_lua_tointeger(L, 3));
	return 0;
}

int messageBoxInternalLua(lua_State* L) {
	MessageBoxA(NULL, p_lua_tostring(L, 1), "EEex", p_lua_tointeger(L, 2));
	return 0;
}

int printLua(lua_State* L) {
	printf("%s\n", p_lua_tostring(L, 1));
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
	const lua_Integer length { p_lua_tointeger(L, 2) };
	char *const localCopy { reinterpret_cast<char*>(alloca(length + 1)) };
	lua_Integer i { 0 };
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
	p_lua_pushinteger(L, static_cast<uintptr_t>(p_lua_tointeger(L, 1)) >> static_cast<uintptr_t>(p_lua_tointeger(L, 2)));
	return 1;
}

int runWithStackLua(lua_State* L) {

	p_lua_getglobal(L, "debug");                              // [ debug ]
	p_lua_getfield(L, -1, "traceback");                       // [ debug, traceback ]
	p_lua_pushvalue(L, 2);                                    // [ debug, traceback, func ]

	void* mem = alloca(p_lua_tointeger(L, 1));
	p_lua_pushinteger(L, reinterpret_cast<lua_Integer>(mem)); // [ debug, traceback, func, stackPtr ]

	if (p_lua_pcallk(L, 1, 0, -3, 0, nullptr) != LUA_OK) {
		                                                      // [ debug, traceback, errorMessage ]
		printf("[!] %s\n", p_lua_tostring(L, -1));
		p_lua_pop(L, 3);                                      // [ ]
	}
	else {
		                                                      // [ debug, traceback ]
		p_lua_pop(L, 2);                                      // [ ]
	}

	return 0;
}

int setLuaRegistryIndexLua(lua_State* L) {
	p_lua_pushvalue(L, 2);
	p_lua_rawseti(L, LUA_REGISTRYINDEX, p_lua_tointeger(L, 1));
	return 0;
}

int write16Lua(lua_State* L) {
	*reinterpret_cast<__int16*>(p_lua_tointeger(L, 1)) = p_lua_tointeger(L, 2);
	return 0;
}

int write32Lua(lua_State* L) {
	*reinterpret_cast<__int32*>(p_lua_tointeger(L, 1)) = p_lua_tointeger(L, 2);
	return 0;
}

#if defined(_WIN64)
int write64Lua(lua_State* L) {
	*reinterpret_cast<__int64*>(p_lua_tointeger(L, 1)) = p_lua_tointeger(L, 2);
	return 0;
}
#endif

int write8Lua(lua_State* L) {
	*reinterpret_cast<__int8*>(p_lua_tointeger(L, 1)) = p_lua_tointeger(L, 2);
	return 0;
}

int writePointerLua(lua_State* L) {
	*reinterpret_cast<uintptr_t*>(p_lua_tointeger(L, 1)) = p_lua_tointeger(L, 2);
	return 0;
}

int writeLStringLua(lua_State* L) {
	char* dest = reinterpret_cast<char*>(p_lua_tointeger(L, 1));
	const char* src = p_lua_tostring(L, 2);
	size_t limit = p_lua_tointeger(L, 3);
	size_t i = 0;
	for (; i < limit; ++i) {
		*dest++ = *src++;
	}
	if (i < limit) {
		*dest = '\0';
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

void internalLuaHook() {

#define hardcodedLookup(name, type, outName) \
	if (findINICategoryPattern(textInfo, iniPath, TEXT(name), lookupTemp)) { \
		return; \
	} \
	patternEntries.emplace(TEXT(name), PatternEntry{ TEXT(name), lookupTemp }); \
	outName = reinterpret_cast<type>(lookupTemp);

#define hardcodedFuncLookup(name, outName) \
	if (findINICategoryPattern(textInfo, iniPath, TEXT(name), lookupTemp)) { \
		return; \
	} \
	patternEntries.emplace(TEXT(name), PatternEntry{ TEXT(name), lookupTemp }); \
	p_##outName = reinterpret_cast<type_##outName>(lookupTemp);

	lua_State* L;

	/////////////////////////////
	// Find Hardcoded Patterns //
	/////////////////////////////

	intptr_t lookupTemp;
	hardcodedLookup("Hardcoded_InternalLuaState", lua_State*, L);
	hardcodedFuncLookup("Hardcoded_free", free);
	hardcodedFuncLookup("Hardcoded_lua_createtable", lua_createtable);
	hardcodedFuncLookup("Hardcoded_lua_getfield", lua_getfield);
	hardcodedFuncLookup("Hardcoded_lua_getglobal", lua_getglobal);
	hardcodedFuncLookup("Hardcoded_lua_gettop", lua_gettop);
	hardcodedFuncLookup("Hardcoded_lua_pcallk", lua_pcallk);
	hardcodedFuncLookup("Hardcoded_lua_pushcclosure", lua_pushcclosure);
	hardcodedFuncLookup("Hardcoded_lua_pushinteger", lua_pushinteger);
	hardcodedFuncLookup("Hardcoded_lua_pushnil", lua_pushnil);
	hardcodedFuncLookup("Hardcoded_lua_pushstring", lua_pushstring);
	hardcodedFuncLookup("Hardcoded_lua_pushvalue", lua_pushvalue);
	hardcodedFuncLookup("Hardcoded_lua_rawgeti", lua_rawgeti);
	hardcodedFuncLookup("Hardcoded_lua_rawset", lua_rawset);
	hardcodedFuncLookup("Hardcoded_lua_rawseti", lua_rawseti);
	hardcodedFuncLookup("Hardcoded_lua_setglobal", lua_setglobal);
	hardcodedFuncLookup("Hardcoded_lua_settop", lua_settop);
	hardcodedFuncLookup("Hardcoded_lua_toboolean", lua_toboolean);
	hardcodedFuncLookup("Hardcoded_lua_tointegerx", lua_tointegerx);
	hardcodedFuncLookup("Hardcoded_lua_tolstring", lua_tolstring);
	hardcodedFuncLookup("Hardcoded_lua_type", lua_type);
	hardcodedFuncLookup("Hardcoded_luaL_loadfilex", luaL_loadfilex);
	hardcodedFuncLookup("Hardcoded_luaL_ref", luaL_ref);
	hardcodedFuncLookup("Hardcoded_malloc", malloc);

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
	exposeToLua(L, "EEex_WriteStringAuto", writeStringAutoLua);

	///////////////////////
	// Run Main Lua File //
	///////////////////////

	callOverrideFile(L, "EEex_Main");
}

DWORD writeInternalLuaHook(ImageSectionInfo& textInfo) {

	intptr_t allocated;
	SYSTEM_INFO info;
	GetSystemInfo(&info);

	if (DWORD lastError = allocateNear(textInfo.ImageBase, info.dwAllocationGranularity,
		info.dwAllocationGranularity, allocated))
	{
		return lastError;
	}

	if (DWORD lastError = loadLuaMode()) {
		return lastError;
	}

	if (luaMode == LuaMode::INTERNAL) {

		intptr_t patchAddress;
		if (DWORD lastError = findINICategoryPattern(textInfo, iniPath, TEXT("Hardcoded_InternalPatchLocation"), patchAddress)) {
			return lastError;
		}

		__int32 relativeAmount = *reinterpret_cast<__int32*>(patchAddress + 1);
		intptr_t target = patchAddress + 5 + relativeAmount;

		unsigned char codeBuff[1024];
		AssemblyWriter writer{ codeBuff };

		writer.setLocation(patchAddress);
		writer.jmpToAddress(allocated);
		disableCodeProtection();
		writer.flush();
		enableCodeProtection();

		writer.setLocation(allocated);
		writer.callToAddress(target);
		writer.pushVolatileRegisters();
		writer.alignStackAndMakeShadowSpace();
		writer.callToAddressFar(reinterpret_cast<intptr_t>(internalLuaHook));
		writer.undoAlignAndShadowSpace();
		writer.popVolatileRegisters();
		writer.jmpToAddress(patchAddress + 5);
		writer.flush();
	}
	else {
		printf("[!] LuaPatchMode::EXTERNAL unimplemented.\n");
		return -1;
	}

	return 0;
}

DWORD patchExe() {

	String exePath;
	if (getExePath(&exeName, exePath)) {
		return -1;
	}

	HMODULE foundModule;
	if (DWORD lastError = findModuleWithPath(GetCurrentProcess(), exePath, foundModule)) {
		return lastError;
	}

	if (!findSectionInfo(foundModule, ".text", textInfo)) {
		printf("[!] Failed to locate .text segment.\n");
	}

	if (DWORD lastError = findPatterns(textInfo)) {
		return lastError;
	}

	if (DWORD lastError = writeInternalLuaHook(textInfo)) {
		return lastError;
	}

	return 0;
}

void BindCrtHandlesToStdHandles(DWORD parentProcess, HANDLE parentStdIn, HANDLE parentStdOut, HANDLE parentStdErr) {

#define DupHandle(srcProcess,srcHandle,targetProcess,targetHandle)\
	HANDLE targetHandle;\
	DuplicateHandle(\
		srcProcess,\
		srcHandle,\
		targetProcess,\
		&targetHandle,\
		NULL,\
		false,\
		DUPLICATE_SAME_ACCESS\
	);

	HANDLE parentProcessHandle = OpenProcess(PROCESS_DUP_HANDLE, false, parentProcess);

	if (parentStdIn != INVALID_HANDLE_VALUE) {

		DupHandle(parentProcessHandle, parentStdIn, GetCurrentProcess(), myHandle);
		CloseHandle(GetStdHandle(STD_INPUT_HANDLE));
		SetStdHandle(STD_INPUT_HANDLE, myHandle);

		FILE* dummyFile;
		freopen_s(&dummyFile, "nul", "r", stdin);

		DupHandle(GetCurrentProcess(), myHandle, GetCurrentProcess(), myHandle2);
		if (int fd = _open_osfhandle(reinterpret_cast<intptr_t>(myHandle2), _O_TEXT); fd != -1) {
			if (_dup2(fd, _fileno(stdin)) == 0) {
				setvbuf(stdin, NULL, _IONBF, 0);
			}
			_close(fd);
		}

		std::wcin.clear();
		std::cin.clear();
	}

	if (parentStdOut != INVALID_HANDLE_VALUE) {

		DupHandle(parentProcessHandle, parentStdOut, GetCurrentProcess(), myHandle);
		CloseHandle(GetStdHandle(STD_OUTPUT_HANDLE));
		SetStdHandle(STD_OUTPUT_HANDLE, myHandle);

		FILE* dummyFile;
		freopen_s(&dummyFile, "nul", "w", stdout);

		DupHandle(GetCurrentProcess(), myHandle, GetCurrentProcess(), myHandle2);
		if (int fd = _open_osfhandle(reinterpret_cast<intptr_t>(myHandle), _O_TEXT); fd != -1) {
			if (_dup2(fd, _fileno(stdout)) == 0) {
				setvbuf(stdout, NULL, _IONBF, 0);
			}
			_close(fd);
		}

		std::wcout.clear();
		std::cout.clear();
	}

	if (parentStdErr != INVALID_HANDLE_VALUE) {

		DupHandle(parentProcessHandle, parentStdErr, GetCurrentProcess(), myHandle);
		CloseHandle(GetStdHandle(STD_ERROR_HANDLE));
		SetStdHandle(STD_ERROR_HANDLE, myHandle);

		FILE* dummyFile;
		freopen_s(&dummyFile, "nul", "w", stderr);

		DupHandle(GetCurrentProcess(), myHandle, GetCurrentProcess(), myHandle2);
		if (int fd = _open_osfhandle(reinterpret_cast<intptr_t>(myHandle2), _O_TEXT); fd != -1) {
			if (_dup2(fd, _fileno(stderr)) == 0) {
				setvbuf(stderr, NULL, _IONBF, 0);
			}
			_close(fd);
		}

		std::wcerr.clear();
		std::cerr.clear();
	}

	CloseHandle(parentProcessHandle);
}

void Init(DWORD parentProcess, HANDLE parentStdIn, HANDLE parentStdOut, HANDLE parentStdErr) {

	if (!AttachConsole(parentProcess)) {
		printf("AttachConsole failed (%d).\n", GetLastError());
		return;
	}
	BindCrtHandlesToStdHandles(parentProcess, parentStdIn, parentStdOut, parentStdErr);

	initPaths();

	if (patchExe()) {
		return;
	}
}
