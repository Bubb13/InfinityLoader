
#include <filesystem>
#include <iostream>
#include <regex>

#include "asmjit/asmjit.h"
#include "asmtk/asmtk.h"
#include "infinity_loader_common_api.h"
#include "lua_provider_api.h"
#include "pointers.h"

#include <Windows.h>
#include <dbghelp.h>
#include <psapi.h>

/////////////
// Structs //
/////////////

struct PatternByteEntry {
	bool isWild;
	unsigned char byte;
	PatternByteEntry(const unsigned char pByte, const bool pIsWild) : byte(pByte), isWild(pIsWild) {};
};

struct LoadedBindings {

	enum class LoadState {
		Uninitialized,
		Initialized,
	};

	LoadState loadState = LoadState::Uninitialized;
	HMODULE hHandle;
};

/////////////
// Globals //
/////////////

String exeNameForPatterns;
bool attemptUseCached = false;
asmjit::JitRuntime rt;
std::unordered_map<StringA, LoadedBindings> loadedBindingsMap{};

StringA earlyPrintPrefix;
StringA extenderName;
StringA luaGlobalsPrefix;
#define prefixed(str) std::format("{}"##str, luaGlobalsPrefix).c_str()  

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

static void setSegmentProtection(const char *const segmentName, const DWORD protectionFlags) {

	TryRetTruthy( sharedState().LoadSegmentInfo(segmentName) )

	void* sectionPtr;
	DWORD sectionSize;
	if (sharedState().GetSegmentPointerAndSize(segmentName, sectionPtr, sectionSize)) {
		FPrint("[!][InfinityLoaderDLL.dll] setSegmentProtection() - Failed to fetch \"%s\" pointer and size\n", segmentName);
		return;
	}

	DWORD temp;
	VirtualProtect(sectionPtr, sectionSize, protectionFlags, &temp);
}

static void disableCodeProtection() {
	setSegmentProtection(".text", PAGE_EXECUTE_READWRITE);
}

static void enableCodeProtection() {
	setSegmentProtection(".text", PAGE_EXECUTE_READ);
}

void exposeToLua(lua_State* L, const char* exposedName, lua_CFunction func) {
	lua_pushcclosure(L, func, 0);
	lua_setglobal(L, exposedName);
}

void callOverrideFile(lua_State* L, const char* name) {

	lua_getglobal(L, "debug");                                                                                            // [ debug ]
	lua_getfield(L, -1, "traceback");                                                                                     // [ debug, traceback ]

	StringA luaFile = StringA{ workingFolderA() }.append("override\\").append(name).append(".lua");
	if (luaL_loadfilex(L, luaFile.c_str(), nullptr) != LUA_OK) {
																														  // [ debug, traceback, errorMessage ]
		lua_pushvalue(L, -2);                                                                                             // [ debug, traceback, errorMessage, traceback ]
		lua_pushvalue(L, -2);                                                                                             // [ debug, traceback, errorMessage, traceback, errorMessage ]
		if (lua_pcallk(L, 1, 1, 0, 0, nullptr) != LUA_OK) {
																														  // [ debug, traceback, errorMessage, errorErrorMessage  ]
			Print("[!][InfinityLoaderDLL.dll] callOverrideFile() - Error in error handling calling debug.traceback()\n");
			lua_pop(L, 4);                                                                                                // [ ]
			return;
		}
																														  // [ debug, traceback, errorMessage, errorMessageTraceback ]
		FPrint("[!][InfinityLoaderDLL.dll] callOverrideFile() - %s\n", lua_tostring(L, -1));
		lua_pop(L, 4);                                                                                                    // [ ]
		return;
	}
																														  // [ debug, traceback, chunk ]
	if (lua_pcallk(L, 0, 0, -2, 0, nullptr) != LUA_OK) {
																														  // [ debug, traceback, errorMessage ]
		FPrint("[!][InfinityLoaderDLL.dll] callOverrideFile() - %s\n", lua_tostring(L, -1));
		lua_pop(L, 3);                                                                                                    // [ ]
	}
	else {
																														  // [ debug, traceback ]
		lua_pop(L, 2);                                                                                                    // [ ]
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

template<typename out_type>
DWORD getLuaProc(const char* name, out_type& out) {
	if (out = reinterpret_cast<out_type>(GetProcAddress(luaLibrary(), name)); out == 0) {
		DWORD lastError = GetLastError();
		FPrint("[!][InfinityLoaderDLL.dll] getLuaProc() - GetProcAddress() failed (%d) to find Lua function \"%s\"\n", lastError, name);
		return lastError;
	}
	return 0;
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

bool findByteList(void* sectionPtr, DWORD sectionSize, std::list<PatternByteEntry>& byteList, uintptr_t& addressOut) {

	unsigned char* curAddress = reinterpret_cast<unsigned char*>(sectionPtr);
	unsigned char* endAddress = curAddress + sectionSize;

	for (; curAddress < endAddress; ++curAddress) {

		unsigned char* checkAddress = curAddress;

		for (PatternByteEntry& entry : byteList) {
			if (!entry.isWild && entry.byte != *checkAddress) {
				goto continue_outer;
			}
			++checkAddress;
		}

		addressOut = reinterpret_cast<uintptr_t>(curAddress);
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
		FPrintT(TEXT("[!][InfinityLoaderDLL.dll] checkOperationsArgCount() - Invalid number of arguments in %s operation for [%s].Operations: %d\n"), iniCategoryName.c_str(),
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
		FPrintT(TEXT("[!][InfinityLoaderDLL.dll] checkOperationsStackCount() - Not enough values pushed onto stack in %s operation for [%s].Operations: %d < %d\n"),
				operationStr.c_str(), iniCategoryName.c_str(), static_cast<int>(stackSize), static_cast<int>(neededStackSize));
		return false;
	}
	return true;
}

bool tryOperationsConvertToDecimal(const String& iniCategoryName, const String& operationStr,
	const std::vector<String>& parts, const int argI, intptr_t& out)
{
	String arg = parts[argI];
	if (!DecStrToIntPtr(arg, out)) {
		FPrintT(TEXT("[!][InfinityLoaderDLL.dll] tryOperationsConvertToDecimal() - Failed to convert %s argument to decimal for [%s].Operations: \"%s\"\n"),
				operationStr.c_str(), iniCategoryName.c_str(), arg.c_str());
		return false;
	}
	return true;
}

bool handlePatternOperations(String iniCategoryName, String operationsStr, uintptr_t& address) {

	std::vector<intptr_t> stack{ static_cast<intptr_t>(address) };
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

	ForEveryCharSplit(operationsStr, TCHAR{ ',' }, [&](const String str) {

		ForEveryCharSplit(str, TCHAR{ ' ' }, [&](const String str) {
			curParts.push_back(str);
			return false;
		});

		if (curParts.size() == 0) {
			FPrintT(TEXT("[!][InfinityLoaderDLL.dll] handlePatternOperations() - Operation missing for [%s].Operations\n"), iniCategoryName.c_str());
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
				FPrintT(TEXT("[!][InfinityLoaderDLL.dll] handlePatternOperations() - Invalid READ argument for [%s].Operations: \"%s\"\n"), iniCategoryName.c_str(), arg1.c_str());
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
					FPrintT(TEXT("[!][InfinityLoaderDLL.dll] handlePatternOperations() - Failed to decode BYTES value for [%s].Operations: \"%s\", %s\n"), iniCategoryName.c_str(), arg2.c_str(), errorStr.c_str());
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
					FPrintT(TEXT("[!][InfinityLoaderDLL.dll] handlePatternOperations() - Invalid WRITE argument for [%s].Operations: \"%s\"\n"), iniCategoryName.c_str(), arg1.c_str());
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
			FPrintT(TEXT("[!][InfinityLoaderDLL.dll] handlePatternOperations() - Invalid operation for [%s].Operations: \"%s\"\n"), iniCategoryName.c_str(), operationName.c_str());
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
	ForEveryCharSplit(aliasList, TCHAR{','}, [&](const String str) {

		const size_t colonI = str.find(TCHAR{':'});

		if (colonI == std::string::npos) {
			FPrintT(TEXT("[!][InfinityLoaderDLL.dll] resolveAliasTarget() - Invalid ExeSwitchAlias: \"%s\"\n"), str.c_str());
			result = -1;
			return true;
		}

		const String alias = str.substr(0, colonI);
		const String target = str.substr(colonI + 1);

		if (target.find(TCHAR{':'}) != std::string::npos) {
			FPrintT(TEXT("[!][InfinityLoaderDLL.dll] resolveAliasTarget() - Invalid ExeSwitchAlias: \"%s\"\n"), str.c_str());
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

template<typename AddressType>
bool setSinglePatternValue(const String& name, AddressType address, PatternValueHandle& patternHandleOut) {

	if (sharedState().GetOrCreatePatternValue(name, PatternValueType::SINGLE, patternHandleOut)) {
		FPrintT(TEXT("[!][InfinityLoaderDLL.dll] setSinglePatternValue() - [%s].Type must be SINGLE\n"), name.c_str());
		return false;
	}

	sharedState().SetSinglePatternValue(patternHandleOut, (uintptr_t)address);
	return true;
}

template<typename AddressType>
bool setSinglePatternValue(const String& name, AddressType address) {
	PatternValueHandle patternHandle;
	return setSinglePatternValue(name, address, patternHandle);
}

DWORD processINICategoryPatternValue(
	const String& iniPath,
	const String& originalINICategoryName,
	const String& iniCategoryName,
	const PatternValueType type,
	const TCHAR *const singleKey,
	const TCHAR *const listKey,
	PatternValueHandle& valueHandleOut,
	bool& filledOut)
{
	filledOut = false;

	if (type == PatternValueType::SINGLE) {

		uintptr_t address;
		TryRetErr( GetINIUIntPtrDef(iniPath, iniCategoryName.c_str(), singleKey, -1, address) )

		if (address != -1) {

			PatternValueHandle handle;
			TryRetDefErrCode( setSinglePatternValue(originalINICategoryName, address, handle) )

			valueHandleOut = handle;
			filledOut = true;
			return 0;
		}
	}
	else if (type == PatternValueType::LIST) {

		String addresses;
		bool filled;
		TryRetErr( GetINIStr(iniPath, iniCategoryName.c_str(), listKey, addresses, filled) )

		if (filled) {

			PatternValueHandle handle;
			if (sharedState().GetOrCreatePatternValue(originalINICategoryName, PatternValueType::LIST, handle)) {
				FPrintT(TEXT("[!][InfinityLoaderDLL.dll] processINICategoryPatternValue() - Conflicting pattern [%s].Type\n"), originalINICategoryName.c_str());
				return -1;
			}

			bool success = false;

			ForEveryCharSplit(addresses, TCHAR{ ',' }, [&](String addressStr) {

				uintptr_t address;
				if (!DecStrToUIntPtr(addressStr, address)) {
					success = false;
					FPrintT(TEXT("[!][InfinityLoaderDLL.dll] processINICategoryPatternValue() - Failed to parse [%s].%s\n"), iniCategoryName.c_str(), listKey);
					return true;
				}

				success = true;
				sharedState().AddListPatternValue(handle, address);
				return false;
			});

			if (success) {
				valueHandleOut = handle;
				filledOut = true;
				return 0;
			}
		}
	}
	else {
		FPrintT(TEXT("[!][InfinityLoaderDLL.dll] processINICategoryPatternValue() - Invalid [%s].Type\n"), iniCategoryName.c_str());
		return -1;
	}

	return 0;
}

DWORD findINICategoryPattern(void* sectionPtr, DWORD sectionSize, const String& iniPath,
	const String& originalINICategoryName, PatternValueHandle& valueHandleOut)
{
	String iniCategoryName = originalINICategoryName;

	uintptr_t bExeSwitch;
	if (DWORD lastError = GetINIUIntPtrDef(iniPath, iniCategoryName.c_str(), TEXT("ExeSwitch"), 0, bExeSwitch)) {
		return lastError;
	}

	if (bExeSwitch) {

		String exeAlias;
		if (DWORD lastError{ GetINIStrDef(iniPath, iniCategoryName.c_str(), TEXT("ExeSwitchAlias"), TEXT(""), exeAlias) }) {
			return lastError;
		}

		String exeSwitchName{ exeNameForPatterns };
		if (DWORD lastError = resolveAliasTarget(exeAlias, exeSwitchName)) {
			return lastError;
		}

		iniCategoryName.insert(0, String{ TEXT("!ExeSwitch-") }.append(exeSwitchName).append(TEXT("-")));
	}

	bool unsupported;
	TryRetErr( GetINIBoolDef(iniPath, iniCategoryName.c_str(), TEXT("Unsupported"), false, unsupported) )

	if (unsupported) {
		return 0;
	}

	String typeStr;
	TryRetErr( GetINIStrDef(iniPath, iniCategoryName.c_str(), TEXT("Type"), TEXT("SINGLE"), typeStr) )

	PatternValueType type;
	if (typeStr == TEXT("SINGLE")) {
		type = PatternValueType::SINGLE;
	}
	else if (typeStr == TEXT("LIST")) {
		type = PatternValueType::LIST;
	}
	else {
		FPrintT(TEXT("[!][InfinityLoaderDLL.dll] findINICategoryPattern() - Invalid [%s].Type\n"), iniCategoryName.c_str());
		return -1;
	}

	bool hadValue;
	TryRetErr(processINICategoryPatternValue(
		iniPath,
		originalINICategoryName,
		iniCategoryName,
		type,
		TEXT("Value"),
		TEXT("Values"),
		valueHandleOut,
		hadValue
	))

	if (hadValue) {
		return 0;
	}

	bool noCache;
	TryRetErr( GetINIBoolDef(iniPath, iniCategoryName.c_str(), TEXT("NoCache"), false, noCache) )

	if (!noCache && attemptUseCached) {

		bool filled;
		TryRetErr(processINICategoryPatternValue(
			iniPath,
			originalINICategoryName,
			iniCategoryName,
			type,
			TEXT("CachedAddress"),
			TEXT("CachedAddresses"),
			valueHandleOut,
			filled
		))

		if (filled) {
			return 0;
		}
	}

	String pattern;
	if (DWORD lastError = GetINIStrDef(iniPath, iniCategoryName.c_str(), TEXT("Pattern"), TEXT(""), pattern)) {
		return lastError;
	}

	std::list<PatternByteEntry> byteList;
	String errorStr;
	if (!decodeByteString(pattern, byteList, errorStr)) {
		FPrintT(TEXT("[!][InfinityLoaderDLL.dll] findINICategoryPattern() - Failed to decode [%s].Pattern: \"%s\"\n"), iniCategoryName.c_str(), errorStr.c_str());
		return -1;
	}

	if (type == PatternValueType::SINGLE) {

		uintptr_t foundAddress;
		if (!findByteList(sectionPtr, sectionSize, byteList, foundAddress)) {
			FPrintT(TEXT("[!][InfinityLoaderDLL.dll] findINICategoryPattern() - Could not find [%s].Pattern\n"), iniCategoryName.c_str());
			return -1;
		}

		String operations;
		if (DWORD lastError = GetINIStrDef(iniPath, iniCategoryName.c_str(), TEXT("Operations"), TEXT(""), operations)) {
			return lastError;
		}

		if (operations != TEXT("")) {
			handlePatternOperations(iniCategoryName, operations, foundAddress);
		}

		PatternValueHandle handle;
		TryRetDefErrCode( setSinglePatternValue(originalINICategoryName, foundAddress, handle) )

		valueHandleOut = handle;
	}
	else if (type == PatternValueType::LIST) {

		PatternValueHandle handle;
		if (sharedState().GetOrCreatePatternValue(originalINICategoryName, PatternValueType::LIST, handle)) {
			FPrintT(TEXT("[!][InfinityLoaderDLL.dll] findINICategoryPattern() - Conflicting pattern [%s].Type\n"), originalINICategoryName.c_str());
			return -1;
		}

		void* curAddress = sectionPtr;
		while (true) {

			uintptr_t foundAddress;
			if (!findByteList(curAddress, sectionSize, byteList, foundAddress)) {
				break;
			}

			String operations;
			TryRetErr( GetINIStrDef(iniPath, iniCategoryName.c_str(), TEXT("Operations"), TEXT(""), operations) )

			uintptr_t finalAddress = foundAddress;
			if (operations != TEXT("")) {
				handlePatternOperations(iniCategoryName, operations, finalAddress);
			}

			sharedState().AddListPatternValue(handle, finalAddress);
			curAddress = reinterpret_cast<void*>(foundAddress + byteList.size());
		}

		if (curAddress == sectionPtr) {
			FPrintT(TEXT("[!][InfinityLoaderDLL.dll] findINICategoryPattern() - Could not find [%s].Pattern\n"), iniCategoryName.c_str());
			return -1;
		}

		valueHandleOut = handle;
	}

	if (!noCache) {

		if (type == PatternValueType::SINGLE) {
			TryRetErr( SetINIUIntPtr(iniPath, iniCategoryName.c_str(), TEXT("CachedAddress"), sharedState().GetSinglePatternValue(valueHandleOut)) )
		}
		else if (type == PatternValueType::LIST) {

			OStringStream stream{};

			sharedState().IteratePatternList(valueHandleOut, [&](uintptr_t address) {
				stream << UIntPtrToDecStr(address) << ",";
				return false;
			});

			String listStr = stream.str();
			listStr.resize(listStr.length() - 1);
			TryRetErr( SetINIStr(iniPath, iniCategoryName.c_str(), TEXT("CachedAddresses"), listStr) )
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

DWORD findPatterns(void* sectionPtr, DWORD sectionSize) {

	bool alreadyCached;
	long long cachedExeTime;

	if (DWORD lastError = GetINILongLong(iniPath(), TEXT("Auto-Generated"), TEXT("CachedExeTime"), cachedExeTime, alreadyCached)) {
		return lastError;
	}

	const long long exeLastModifiedTime = getFileLastModifiedTime(exePath());

	if (alreadyCached) {
		if (debug()) {
			FPrint("[?][InfinityLoaderDLL.dll] findPatterns() - exeLastModifiedTime: %lld, CachedExeTime: %lld\n", exeLastModifiedTime, cachedExeTime);
		}
		if (exeLastModifiedTime == cachedExeTime) {
			attemptUseCached = true;
		}
	}

	if (!attemptUseCached) {
		if (DWORD lastError = SetINILongLong(iniPath(), TEXT("Auto-Generated"), TEXT("CachedExeTime"), exeLastModifiedTime)) {
			return lastError;
		}
	}

	if (debug()) {
		FPrint("[?][InfinityLoaderDLL.dll] findPatterns() - Using cached pattern addresses: %s\n", attemptUseCached ? "true" : "false");
	}

	DWORD returnVal = 0;
	forEveryINISectionName(dbPath(), [&](const String section) {

		if (section.rfind(TEXT("!"), 0) != std::string::npos) {
			return false;
		}

		PatternValueHandle patternValue;
		if (returnVal = findINICategoryPattern(sectionPtr, sectionSize, dbPath(), section.c_str(), patternValue)) {
			return true;
		}

		return false;
	});

	return returnVal;
}

///////////////////
// Lua Functions //
///////////////////

int addToLuaRegistryLua(lua_State* L) {
	lua_pushvalue(L, 1);
	lua_pushinteger(L, luaL_ref(L, LUA_REGISTRYINDEX));
	return 1;
}

int allocCodePageInternalLua(lua_State* L) {

	SYSTEM_INFO info;
	GetSystemInfo(&info);

	uintptr_t allocated;
	if (AllocateNear(sharedState().ImageBase(), info.dwAllocationGranularity, allocated)) {
		return 0;
	}

	lua_pushinteger(L, allocated);                    // [ address ]
	lua_pushinteger(L, info.dwAllocationGranularity); // [ address, size ]
	return 2;
}

typedef std::make_unsigned<lua_Integer>::type UnsignedLuaInt;

int bandLua(lua_State* L) {
	lua_pushinteger(L, static_cast<UnsignedLuaInt>(lua_tointeger(L, 1)) & static_cast<UnsignedLuaInt>(lua_tointeger(L, 2)));
	return 1;
}

int bnotLua(lua_State* L) {
	lua_pushinteger(L, ~static_cast<UnsignedLuaInt>(lua_tointeger(L, 1)));
	return 1;
}

int borLua(lua_State* L) {
	lua_pushinteger(L, static_cast<UnsignedLuaInt>(lua_tointeger(L, 1)) | static_cast<UnsignedLuaInt>(lua_tointeger(L, 2)));
	return 1;
}

int cFunctionToPointerLua(lua_State* L) {
	lua_pushinteger(L, reinterpret_cast<lua_Integer>(lua_tocfunction(L, 1)));
	return 1;
}

int disableCodeProtectionLua(lua_State* L) {
	disableCodeProtection();
	return 0;
}

int doFileLua(lua_State* L) {
	callOverrideFile(L, lua_tostring(L, 1));
	return 0;
}

int enableCodeProtectionLua(lua_State* L) {
	enableCodeProtection();
	return 0;
}

int exposeToLuaLua(lua_State* L) {
	exposeToLua(L, lua_tostring(L, 2), reinterpret_cast<lua_CFunction>(lua_tointeger(L, 1)));
	return 0;
}

int extractLua(lua_State* L) {
	UnsignedLuaInt num = lua_tointeger(L, 1);
	UnsignedLuaInt start = lua_tointeger(L, 2);
	UnsignedLuaInt len = lua_tointeger(L, 3);
	UnsignedLuaInt mask = 0x0;
	for (UnsignedLuaInt i = 0; i < len; ++i) {
		mask = (mask << 1) | 1;
	}
	lua_pushinteger(L, (num >> start) & mask);
	return 1;
}

int freeLua(lua_State* L) {
	void* ptr = reinterpret_cast<void*>(lua_tointeger(L, 1));
	p_free(ptr);
	return 0;
}

int getProcAddressLua(lua_State* L) {
	const HMODULE hModule = reinterpret_cast<HMODULE>(lua_tointeger(L, 1));
	const FARPROC proc = GetProcAddress(hModule, lua_tostring(L, 2));
	lua_pushinteger(L, reinterpret_cast<lua_Integer>(proc));
	return 1;
}

int getLuaRegistryIndexLua(lua_State* L) {
	castLuaIntArg(1, int, Int, n)
	lua_rawgeti(L, LUA_REGISTRYINDEX, n);
	return 1;
}

int getLuaLibraryProcLua(lua_State* L) {
	uintptr_t address;
	if (getLuaProc(lua_tostring(L, 1), address)) {
		return 0;
	}
	lua_pushinteger(L, address);
	return 1;
}

int getMicrosecondsLua(lua_State* L) {
	lua_pushinteger(L, static_cast<lua_Integer>(CurrentMicroseconds() - initTime()));
	return 1;
}

int getPatternMapLua(lua_State* L) {
	lua_pushstring(L, "InfinityLoader_Patterns"); // 1 [ "InfinityLoader_Patterns" ]
	lua_rawget(L, LUA_REGISTRYINDEX);             // 1 [ registry["InfinityLoader_Patterns"] ]
	return 1;
}

int iterateRegexLua(lua_State* L) {

	const char* str = lua_tostring(L, 1);
	const char* strEnd = str;
	while (*strEnd) ++strEnd;
	std::regex pattern{ lua_tostring(L, 2) };
	std::cregex_iterator foundBegin{ str, strEnd, pattern };
	std::cregex_iterator foundEnd;

	lua_getglobal(L, "debug");                                                                   // [ debug ]
	lua_getfield(L, -1, "traceback");                                                            // [ debug, traceback ]

	for (std::cregex_iterator& i = foundBegin; i != foundEnd; ++i) {

		const std::cmatch& match = *i;
		lua_pushvalue(L, 3);                                                                     // [ debug, traceback, func ]
		lua_pushinteger(L, match.position() + 1);                                                // [ debug, traceback, func, pos ]
		lua_pushinteger(L, match.position() + match.length());                                   // [ debug, traceback, func, pos, endPos ]
		lua_pushstring(L, match.str().c_str());                                                  // [ debug, traceback, func, pos, endPos, str ]

		lua_newtable(L);                                                                         // [ debug, traceback, func, pos, endPos, str, groups ]
		for (size_t i = 1; i < match.size(); ++i) {
			const std::csub_match& subMatch = match[i];
			lua_pushinteger(L, i);                                                               // [ debug, traceback, func, pos, endPos, str, groups, k ]
			if (!subMatch.length()) {
				lua_pushnil(L);                                                                  // [ debug, traceback, func, pos, endPos, str, groups, k, nil ]
			}
			else {
				lua_pushstring(L, subMatch.str().c_str());                                       // [ debug, traceback, func, pos, endPos, str, groups, k, v ]
			}
			lua_rawset(L, -3);                                                                   // [ debug, traceback, func, pos, endPos, str, groups ]
		}

		if (lua_pcallk(L, 4, 1, -6, 0, nullptr) != LUA_OK) {
																								 // [ debug, traceback, errorMessage ]
			FPrint("[!][InfinityLoaderDLL.dll] %sIterateRegex() - %s\n", luaGlobalsPrefix.c_str(), lua_tostring(L, -1));
			lua_pop(L, 1);                                                                       // [ debug, traceback ]
			break;
		}
		else {
																								 // [ debug, traceback, ret ]
			int retVal = lua_toboolean(L, -1);
			lua_pop(L, 1);                                                                       // [ debug, traceback ]
			if (retVal) {
				break;
			}
		}
	}

	lua_pop(L, 2);                                                                               // [ ]
	return 0;
}

int jitLua(lua_State* L) {

	asmjit::CodeHolder code;
	code.init(rt.environment());

	asmjit::x86::Assembler a(&code);
	asmtk::AsmParser p(&a);

	if (asmjit::Error err = p.parse(lua_tostring(L, 1))) {
		FPrint("[!][InfinityLoaderDLL.dll] %sJIT() - AsmJit failed: %s\n", luaGlobalsPrefix.c_str(), asmjit::DebugUtils::errorAsString(err));
		return 0;
	}

	void* ptr;
	if (asmjit::Error err = rt.add(&ptr, &code)) {
		FPrint("[!][InfinityLoaderDLL.dll] %sJIT() - AsmJit failed: %s\n", luaGlobalsPrefix.c_str(), asmjit::DebugUtils::errorAsString(err));
		return 0;
	}

	lua_pushinteger(L, reinterpret_cast<uintptr_t>(ptr));
	return 1;
}

int jitAtInternalLua(lua_State* L) {

	asmjit::CodeHolder code;
	code.init(rt.environment());

	asmjit::x86::Assembler a(&code);
	asmtk::AsmParser p(&a);

	if (asmjit::Error err = p.parse(lua_tostring(L, 3))) {
		FPrint("[!][InfinityLoaderDLL.dll] %sJITAtInternal() - AsmJit failed: %s\n", luaGlobalsPrefix.c_str(), asmjit::DebugUtils::errorAsString(err));
		return 0;
	}

	auto checkFunc = [&](size_t size) {

		lua_getglobal(L, "debug");                                                                                              // [ debug ]
		lua_getfield(L, -1, "traceback");                                                                                       // [ debug, traceback ]

		lua_pushvalue(L, 2);                                                                                                    // [ debug, traceback, func ]
		lua_pushinteger(L, size);                                                                                               // [ debug, traceback, func, size ]
		if (lua_pcallk(L, 1, 1, -3, 0, nullptr) != LUA_OK) {
																																// [ debug, traceback, errorMessage ]
			FPrint("[!][InfinityLoaderDLL.dll] %sJITAtInternal() - AsmJit failed: %s\n", luaGlobalsPrefix.c_str(), lua_tostring(L, -1));
			lua_pop(L, 3);                                                                                                      // [ ]
			return reinterpret_cast<uint8_t*>(-1);
		}
																																// [ debug, traceback, result ]
		uint8_t* newDst = reinterpret_cast<uint8_t*>(lua_tointeger(L, -1));
		lua_pop(L, 3);                                                                                                          // [ ]
		return newDst;
	};

	if (asmjit::Error err = jitAt(reinterpret_cast<uint8_t*>(lua_tointeger(L, 1)), &code, checkFunc)) {
		FPrint("[!][InfinityLoaderDLL.dll] %sJITAtInternal() - AsmJit failed: %s\n", luaGlobalsPrefix.c_str(), asmjit::DebugUtils::errorAsString(err));
		return 0;
	}

	return 0;
}

static bool initializeLuaBindings(const char *const bindingsFileName, LoadedBindings& loadedBindings) {

	const StringA bindingsPath = StringA{ workingFolderA() }.append(bindingsFileName).append(".dll");

	if (loadedBindings.hHandle = LoadLibraryA(bindingsPath.c_str()); !loadedBindings.hHandle) {
		FPrint("[!][InfinityLoaderDLL.dll] initializeLuaBindings() - LoadLibraryA(\"%s\") failed (%d)\n", bindingsPath.c_str(), GetLastError());
		return true;
	}

	FARPROC initProcFar;
	if (initProcFar = GetProcAddress(loadedBindings.hHandle, "InitBindings"); !initProcFar) {
		FPrint("[!][InfinityLoaderDLL.dll] initializeLuaBindings() - GetProcAddress() failed (%d)\n", GetLastError());
		return true;
	}

	typedef void(__stdcall* type_Init)(SharedState);
	const type_Init initProc = reinterpret_cast<type_Init>(initProcFar);
	initProc(sharedState());

	loadedBindings.loadState = LoadedBindings::LoadState::Initialized;
	return false;
}

static int loadLibraryLua(lua_State *const L) {
	const HMODULE hModule = LoadLibraryA(lua_tostring(L, 1));
	lua_pushinteger(L, reinterpret_cast<lua_Integer>(hModule));
	return 1;
}

static int openLuaBindingsLua(lua_State *const L) {

	const char *const bindingsFileName = lua_tolstring(L, 1, nullptr);
	LoadedBindings& loadedBindings = loadedBindingsMap[bindingsFileName];

	// Initialize the dll if it hasn't been initialized already

	if (loadedBindings.loadState == LoadedBindings::LoadState::Uninitialized
		&& initializeLuaBindings(bindingsFileName, loadedBindings))
	{
		return 0;
	}

	// Check if the dll's bindings have already been opened for the given Lua state

	const StringA openedKey = StringA{ "InfinityLoader_" }.append(bindingsFileName).append("_Opened");

	lua_pushstring(L, openedKey.c_str()); // 1 [ openedKey ]
	lua_rawget(L, LUA_REGISTRYINDEX);     // 1 [ registry[openedKey] ]

	if (lua_toboolean(L, -1)) {
		lua_pop(L, 1);                    // 0 [ ]
		return 0;
	}

	lua_pushstring(L, openedKey.c_str()); // 2 [ registry[openedKey], openedKey ]
	lua_pushboolean(L, true);             // 3 [ registry[openedKey], openedKey, true ]
	lua_rawset(L, LUA_REGISTRYINDEX);     // 1 [ registry[openedKey] ]
	lua_pop(L, 1);                        // 0 [ ]

	// Call dll's OpenBindings()

	FARPROC openBindingsProcFar;
	if (openBindingsProcFar = GetProcAddress(loadedBindings.hHandle, "OpenBindings"); !openBindingsProcFar) {
		FPrint("[!][InfinityLoaderDLL.dll] %sOpenLuaBindings() - GetProcAddress() failed (%d)\n", luaGlobalsPrefix.c_str(), GetLastError());
		return 0;
	}

	typedef void(__stdcall* type_OpenBindings)();
	const type_OpenBindings openBindingsProc = reinterpret_cast<type_OpenBindings>(openBindingsProcFar);
	openBindingsProc();

	return 0;
}

int initializeLuaBindingsLua(lua_State* L) {

	const char* bindingsFileName = lua_tolstring(L, 1, nullptr);
	LoadedBindings& loadedBindings = loadedBindingsMap[bindingsFileName];

	if (loadedBindings.loadState != LoadedBindings::LoadState::Uninitialized) {
		return 0;
	}

	initializeLuaBindings(bindingsFileName, loadedBindings);
	return 0;
}

int lshiftLua(lua_State* L) {
	lua_pushinteger(L, static_cast<UnsignedLuaInt>(lua_tointeger(L, 1)) << static_cast<UnsignedLuaInt>(lua_tointeger(L, 2)));
	return 1;
}

int mallocLua(lua_State* L) {
	castLuaIntArg(1, size_t, SizeT, size)
	lua_pushinteger(L, reinterpret_cast<lua_Integer>(p_malloc(size)));
	return 1;
}

int memcpyLua(lua_State* L) {
	castLuaIntArg(3, size_t, SizeT, size)
	memcpy(reinterpret_cast<void*>(lua_tointeger(L, 1)), reinterpret_cast<void*>(lua_tointeger(L, 2)), size);
	return 0;
}

int memsetLua(lua_State* L) {
	castLuaIntArg(2, int, Int, val)
	castLuaIntArg(3, size_t, SizeT, size)
	memset(reinterpret_cast<void*>(lua_tointeger(L, 1)), val, size);
	return 0;
}

int messageBoxInternalLua(lua_State* L) {
	castLuaIntArg(2, UINT, UInt, uType)
	MessageBoxA(NULL, lua_tostring(L, 1), extenderName.c_str(), uType);
	return 0;
}

int printLua(lua_State* L) {
	Print(lua_tostring(L, 1));
	return 0;
}

int printErrLua(lua_State* L) {
	PrintErr(lua_tostring(L, 1));
	return 0;
}

static int processThreadQueueLua(lua_State* L) {
	sharedState().ProcessThreadQueue();
	return 0;
}

int read16Lua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<__int16*>(lua_tointeger(L, 1)));
	return 1;
}

int read32Lua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<__int32*>(lua_tointeger(L, 1)));
	return 1;
}

#if defined(_WIN64)
int read64Lua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<__int64*>(lua_tointeger(L, 1)));
	return 1;
}
#endif

int read8Lua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<__int8*>(lua_tointeger(L, 1)));
	return 1;
}

int readPointerLua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<uintptr_t*>(lua_tointeger(L, 1)));
	return 1;
}

int readU16Lua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<unsigned __int16*>(lua_tointeger(L, 1)));
	return 1;
}

int readU32Lua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<unsigned __int32*>(lua_tointeger(L, 1)));
	return 1;
}

#if defined(_WIN64)
int readU64Lua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<unsigned __int64*>(lua_tointeger(L, 1)));
	return 1;
}
#endif

int readU8Lua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<unsigned __int8*>(lua_tointeger(L, 1)));
	return 1;
}

int readLString(lua_State* L) {
	const char *const data { reinterpret_cast<char*>(lua_tointeger(L, 1)) };
	castLuaIntArg(2, size_t, SizeT, length)
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
	lua_pushstring(L, localCopy);
	return 1;
}

int readString(lua_State* L) {
	lua_pushstring(L, reinterpret_cast<const char*>(lua_tointeger(L, 1)));
	return 1;
}

int rshiftLua(lua_State* L) {
	lua_pushinteger(L, static_cast<UnsignedLuaInt>(lua_tointeger(L, 1)) >> static_cast<UnsignedLuaInt>(lua_tointeger(L, 2)));
	return 1;
}

int runWithStackLua(lua_State* L) {

	castLuaIntArg(1, size_t, SizeT, size)

	lua_getglobal(L, "debug");                                                               // [ debug ]
	lua_getfield(L, -1, "traceback");                                                        // [ debug, traceback ]
	lua_pushvalue(L, 2);                                                                     // [ debug, traceback, func ]

	void* mem = alloca(size);
	lua_pushinteger(L, reinterpret_cast<lua_Integer>(mem));                                  // [ debug, traceback, func, stackPtr ]

	if (lua_pcallk(L, 1, 0, -3, 0, nullptr) != LUA_OK) {
																							 // [ debug, traceback, errorMessage ]
		FPrint("[!][InfinityLoaderDLL.dll] %sRunWithStack() - %s\n", luaGlobalsPrefix.c_str(), lua_tostring(L, -1));
		lua_pop(L, 3);                                                                       // [ ]
	}
	else {
																							 // [ debug, traceback ]
		lua_pop(L, 2);                                                                       // [ ]
	}

	return 0;
}

int selectFromTablesLua(lua_State* L) {

	const int nStackTop = lua_gettop(L);

	if (nStackTop % 3 != 0) {
		luaL_error(L, "Expected number of args to be a multiple of 3 (got %d)", nStackTop);
	}

	int nTotalLength = 0;

	for (int i = 1; i <= nStackTop; i += 3) {

		if (lua_type(L, i) != LUA_TNUMBER) {
			luaL_error(L, "Expected number (nStart) at arg %d", i);
		}

		const int nLengthI = i + 1;
		if (lua_type(L, i) != LUA_TNUMBER) {
			luaL_error(L, "Expected number (nLength) at arg %d", nLengthI);
		}

		const int nTableI = i + 2;
		if (lua_type(L, nTableI) != LUA_TTABLE) {
			luaL_error(L, "Expected table at arg %d", nTableI);
		}

		castLuaIntArg(i, int, Int, nStart)
		castLuaIntArg(nLengthI, int, Int, nLength)

		if (nLength == -1) {
			int j = nStart;
			while (true) {
				lua_rawgeti(L, nTableI, j++);
				if (lua_type(L, -1) == LUA_TNIL) {
					lua_pop(L, 1);
					break;
				}
				++nTotalLength;
			}
		}
		else {
			int end = nStart + nLength;
			for (int j = nStart; j < end; ++j) {
				lua_rawgeti(L, nTableI, j);
			}
			nTotalLength += nLength;
		}
	}

	return nTotalLength;
}

int setLuaRegistryIndexLua(lua_State* L) {
	castLuaIntArg(1, int, Int, n)
	lua_pushvalue(L, 2);
	lua_rawseti(L, LUA_REGISTRYINDEX, n);
	return 0;
}

static int setSegmentProtectionLua(lua_State* L) {
	const char *const segmentName = lua_tostring(L, 1);
	castLuaIntArg(2, unsigned __int32, UInt32, protectionFlags)
	setSegmentProtection(segmentName, protectionFlags);
	return 0;
}

static int temporaryPrintReplacementLua(lua_State* L) {
	const int top = lua_gettop(L);
	for (int index = 1; index <= top; ++index) {
		if (!lua_isstring(L, index)) {
			FPrint("Unable to convert arg %d a %s to string\n", index, lua_typename(L, index));
		}
		else {
			FPrint("%s%s\n", earlyPrintPrefix.c_str(), lua_tolstring(L, index, nullptr));
		}
	}
	return 0;
}

int toDecimalStringLua(lua_State* L) {
	static_assert(std::is_same<lua_Integer, ptrdiff_t>::value, "Expected lua_Integer type");
	lua_pushstring(L, PtrDiffToDecStrA(lua_tointeger(L, 1)).c_str());
	return 1;
}

int write16Lua(lua_State* L) {
	castLuaIntArg(2, __int16, Int16, val)
	*reinterpret_cast<__int16*>(lua_tointeger(L, 1)) = val;
	return 0;
}

int write32Lua(lua_State* L) {
	castLuaIntArg(2, __int32, Int32, val)
	*reinterpret_cast<__int32*>(lua_tointeger(L, 1)) = val;
	return 0;
}

#if defined(_WIN64)
int write64Lua(lua_State* L) {
	castLuaIntArg(2, __int64, Int64, val)
	*reinterpret_cast<__int64*>(lua_tointeger(L, 1)) = val;
	return 0;
}
#endif

int write8Lua(lua_State* L) {
	castLuaIntArg(2, __int8, Int8, val)
	*reinterpret_cast<__int8*>(lua_tointeger(L, 1)) = val;
	return 0;
}

int writePointerLua(lua_State* L) {
	*reinterpret_cast<uintptr_t*>(lua_tointeger(L, 1)) = lua_tointeger(L, 2);
	return 0;
}

int writeU16Lua(lua_State* L) {
	castLuaIntArg(2, unsigned __int16, UInt16, val)
	*reinterpret_cast<unsigned __int16*>(lua_tointeger(L, 1)) = val;
	return 0;
}

int writeU32Lua(lua_State* L) {
	castLuaIntArg(2, unsigned __int32, UInt32, val)
	*reinterpret_cast<unsigned __int32*>(lua_tointeger(L, 1)) = val;
	return 0;
}

int writeU64Lua(lua_State* L) {
	castLuaIntArg(2, unsigned __int64, UInt64, val)
	*reinterpret_cast<unsigned __int64*>(lua_tointeger(L, 1)) = val;
	return 0;
}

int writeU8Lua(lua_State* L) {
	castLuaIntArg(2, unsigned __int8, UInt8, val)
	*reinterpret_cast<unsigned __int8*>(lua_tointeger(L, 1)) = val;
	return 0;
}

int writeLStringLua(lua_State* L) {

	char* dst = reinterpret_cast<char*>(lua_tointeger(L, 1));
	const char* src = lua_tostring(L, 2);
	castLuaIntArg(3, size_t, SizeT, limit)

	const char *const dstLimit = dst + limit;

	for (; dst < dstLimit; ++src) {
		const char srcChar = *src;
		*dst++ = srcChar;
		if (srcChar == '\0') {
			break;
		}
	}

	for (; dst < dstLimit; ++dst) {
		*dst = '\0';
	}

	return 0;
}

int writeStringLua(lua_State* L) {
	char* writePtr = reinterpret_cast<char*>(lua_tointeger(L, 1));
	const char* str = lua_tostring(L, 2);
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
	const char* str = lua_tostring(L, 1);
	size_t len = strlen(str);
	char* newStr = reinterpret_cast<char*>(p_malloc(len + 1));
	char* newStrWPtr = newStr;
	for (size_t i = 0; i < len; ++i) {
		*newStrWPtr++ = *str++;
	}
	*newStrWPtr = '\0';
	lua_pushinteger(L, reinterpret_cast<uintptr_t>(newStr));
	return 1;
}

////////////////////////////
// START Pattern Tracking //
////////////////////////////

// Expects: 0 [ t, k, v ]
int onPatternMapChanged(lua_State* L) {

	const char *const patternName = lua_tostring(L, 2);
	const uintptr_t patternValue = lua_tointeger(L, 3);

	setSinglePatternValue(NulTermStrToStr(patternName), patternValue);
	lua_rawset(L, 1);
	return 0;
}

// Expects:   0 [ ... ]
// End Stack: 1 [ ..., registry["InfinityLoader_Patterns"] ]
void pushPatternsTable(lua_State* L) {

	lua_pushstring(L, "InfinityLoader_Patterns");     // 1 [ ..., "InfinityLoader_Patterns" ]
	lua_rawget(L, LUA_REGISTRYINDEX);                 // 1 [ ..., registry["InfinityLoader_Patterns"] ]

	if (lua_isnil(L, -1)) {

		lua_pop(L, 1);                                // 0 [ ... ]
		lua_newtable(L);                              // 1 [ ..., t ]

		lua_newtable(L);                              // 2 [ ..., t, mt ]
		lua_pushstring(L, "__newindex");              // 3 [ ..., t, mt, "__newindex" ]
		lua_pushcfunction(L, onPatternMapChanged);    // 4 [ ..., t, mt, "__newindex", onPatternMapChanged ]
		lua_rawset(L, -3);                            // 2 [ ..., t, mt ]

		lua_setmetatable(L, -2);                      // 1 [ ..., t ]

		lua_pushstring(L, "InfinityLoader_Patterns"); // 2 [ ..., t, "InfinityLoader_Patterns" ]
		lua_pushvalue(L, -2);                         // 3 [ ..., t, "InfinityLoader_Patterns", t ]
		lua_rawset(L, LUA_REGISTRYINDEX);             // 1 [ ..., t -> registry["InfinityLoader_Patterns"] ]
	}
}

// Expects:   1 [ ..., registry["InfinityLoader_Patterns"] -> patternsT ]
// End Stack: 1 [ ..., patternsT ]
void rawsetSinglePatternValue(lua_State *const L, const PatternValueHandle handle, const uintptr_t newAddress) {
	const String& name = sharedState().GetPatternValueName(handle);
	const StringA nameA = StrToStrA(name);
	lua_pushstring(L, nameA.c_str());                               // 2 [ ..., patternsT, name ]
	lua_pushinteger(L, newAddress);                                 // 3 [ ..., patternsT, name, value ]
	lua_rawset(L, -3);                                              // 1 [ ..., patternsT ]
}

// Expects:   1 [ ..., registry["InfinityLoader_Patterns"] -> patternsT ]
// End Stack: 2 [ ..., patternsT, patternsT[patternName(handle)] ]
void pushListPatternTable(lua_State *const L, const PatternValueHandle handle) {

	const String& name = sharedState().GetPatternValueName(handle);
	const StringA nameA = StrToStrA(name);

	lua_pushstring(L, nameA.c_str());                               // 2 [ ..., patternsT, name ]
	lua_rawget(L, -2);                                              // 2 [ ..., patternsT, patternsT[name] -> listT ]

	if (!lua_istable(L, -1)) {
		lua_pop(L, 1);                                              // 1 [ ..., patternsT ]
		lua_newtable(L);                                            // 2 [ ..., patternsT, newT ]
		lua_pushstring(L, nameA.c_str());                           // 3 [ ..., patternsT, newT, name ]
		lua_pushvalue(L, -2);                                       // 4 [ ..., patternsT, newT, name, newT ]
		lua_rawset(L, -4);                                          // 2 [ ..., patternsT, newT -> listT ]
		lua_pushinteger(L, 0);                                      // 3 [ ..., patternsT, listT, size ]
		lua_rawseti(L, -2, 0);                                      // 2 [ ..., patternsT, listT ]
	}
}

// Expects:   0 [ ... ]
// End Stack: 0 [ ... ]
void exportExistingPatterns(lua_State *const L) {

	pushPatternsTable(L);                                                             // 1 [ ..., patternsT ]

	sharedState().IteratePatternValues([&](const PatternValueHandle handle) -> bool {

		const PatternValueType type = sharedState().GetPatternValueType(handle);
		if (type == PatternValueType::SINGLE) {
			const uintptr_t value = sharedState().GetSinglePatternValue(handle);
			rawsetSinglePatternValue(L, handle, value);
		}
		else if (type == PatternValueType::LIST) {

			pushListPatternTable(L, handle);                                          // 2 [ ..., patternsT, listT ]
			lua_rawgeti(L, -1, 0);                                                    // 3 [ ..., patternsT, listT, size ]
			int size = static_cast<int>(lua_tointeger(L, -1));

			sharedState().IteratePatternList(handle, [&](uintptr_t newAddress) {
				lua_pushinteger(L, newAddress);                                       // 4 [ ..., patternsT, listT, size, newAddress ]
				lua_rawseti(L, -3, ++size);                                           // 3 [ ..., patternsT, listT, size ]
				return false;
			});
																					  // 3 [ ..., patternsT, listT, size ]
			lua_pushinteger(L, size);                                                 // 4 [ ..., patternsT, listT, size, newSize ]
			lua_rawseti(L, -3, 0);                                                    // 3 [ ..., patternsT, listT, size ]
			lua_pop(L, 2);                                                            // 1 [ ..., patternsT ]
		}

		return false;
	});

	lua_pop(L, 1);                                                                    // 0 [ ... ]
}

static void onLuaStateInitialized(lua_State *const L) {
	exportExistingPatterns(L);
}

static void onAfterPatternModified(const PatternValueHandle handle, const uintptr_t newAddress) {

	if (lua_State *const L = luaState(); L != nullptr) {

		pushPatternsTable(L);                                                    // 1 [ ..., patternsT ]

		const PatternValueType type = sharedState().GetPatternValueType(handle);
		if (type == PatternValueType::SINGLE) {
			uintptr_t value = sharedState().GetSinglePatternValue(handle);
			rawsetSinglePatternValue(L, handle, value);
		}
		else if (type == PatternValueType::LIST) {
			pushListPatternTable(L, handle);                                     // 2 [ ..., patternsT, listT ]
			lua_rawgeti(L, -1, 0);                                               // 3 [ ..., patternsT, listT, size ]
			const int newSize = static_cast<int>(lua_tointeger(L, -1)) + 1;
			lua_pushinteger(L, newSize);                                         // 4 [ ..., patternsT, listT, size, newSize ]
			lua_pushinteger(L, newAddress);                                      // 5 [ ..., patternsT, listT, size, newSize, newAddress ]
			lua_rawseti(L, -4, newSize);                                         // 4 [ ..., patternsT, listT, size, newSize ]
			lua_rawseti(L, -3, 0);                                               // 3 [ ..., patternsT, listT, size ]
			lua_pop(L, 3);                                                       // 0 [ ... ]
		}

		lua_pop(L, 1);                                                           // 0 [ ... ]
	}
}

void initPatternTracking() {
	// Callback that exports all existing patterns
	sharedState().AddLuaStateInitializedCallback(onLuaStateInitialized);
	// Listener that exports future patterns when they are set
	sharedState().AddAfterPatternModifiedListener(onAfterPatternModified);
}

//////////////////////////
// END Pattern Tracking //
//////////////////////////

////////////////////
// Initialization //
////////////////////

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

	HANDLE parentProcessHandle = OpenProcess(PROCESS_DUP_HANDLE, false, parentProcessId());
	HANDLE currentProcessHandle = GetCurrentProcess();
	HANDLE duplicatedHandle;

	DuplicateHandle(parentProcessHandle, stdIn(), currentProcessHandle, &duplicatedHandle, 0, false, DUPLICATE_SAME_ACCESS);
	SetStdHandle(STD_INPUT_HANDLE, duplicatedHandle);

	DuplicateHandle(parentProcessHandle, stdOut(), currentProcessHandle, &duplicatedHandle, 0, false, DUPLICATE_SAME_ACCESS);
	SetStdHandle(STD_OUTPUT_HANDLE, duplicatedHandle);

	DuplicateHandle(parentProcessHandle, stdErr(), currentProcessHandle, &duplicatedHandle, 0, false, DUPLICATE_SAME_ACCESS);
	SetStdHandle(STD_ERROR_HANDLE, duplicatedHandle);

	BindCrtStreamsToOSHandles();
	CloseHandle(parentProcessHandle);
}

bool attachedToConsole = false;

DWORD attachToConsole(bool force = false) {

	if (protonCompatibility()) {
		return ERROR_SUCCESS;
	}

	if (!force && attachedToConsole) {
		return ERROR_SUCCESS;
	}

	if (!AttachConsole(parentProcessId())) {
		const DWORD lastError = GetLastError();
		MessageBoxFormat(TEXT("InfinityLoaderDLL.dll"), MB_ICONERROR, TEXT("[!] attachToConsole() - AttachConsole() failed (%d)"), lastError);
		return lastError;
	}

	bindToParentOSHandles();
	attachedToConsole = true;

	if (debug()) {
		FPrint("[?][InfinityLoaderDLL.dll] attachToConsole() - force = %s\n", force ? "true" : "false");
	}

	return ERROR_SUCCESS;
}

DWORD detatchFromConsole(bool force = false) {

	if (protonCompatibility()) {
		return ERROR_SUCCESS;
	}

	if (!force) {

		if (!attachedToConsole) {
			return ERROR_SUCCESS;
		}

		bool keepConsoleAttached;
		if (GetINIBoolDef(iniPath(), TEXT("General"), TEXT("KeepConsoleAttached"), false, keepConsoleAttached) == ERROR_SUCCESS
			&& keepConsoleAttached)
		{
			return ERROR_SUCCESS;
		}
	}

	if (debug()) {
		FPrint("[?][InfinityLoaderDLL.dll] detatchFromConsole() - force = %s\n", force ? "true" : "false");
	}

	if (!FreeConsole()) {
		const DWORD lastError = GetLastError();
		MessageBoxFormat(TEXT("InfinityLoaderDLL.dll"), MB_ICONERROR, TEXT("[!] detatchFromConsole() - FreeConsole() failed (%d)"), lastError);
		return lastError;
	}

	// FreeConsole() NtClose()'s all of the cached OS handles, though the duplicated
	// OS handles in the file descriptors still need to be closed.

	bool keepCrtStreamsAttached;
	if (GetINIBoolDef(iniPath(), TEXT("General"), TEXT("KeepCrtStreamsAttached"), false, keepCrtStreamsAttached) == ERROR_SUCCESS
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

#undef fprintf

int logShim(FILE* stream, const char* format, const char* level, const char* message) {
	if (!attachedToConsole && !protonCompatibility()) {
		// Intentionally not FPrint() - Since the engine calls both WriteConsole() and fprintf(), this fprintf()
		// call only serves to send engine output to the redirected stderr of InfinityLoader. Note that FPrint()
		// is used when `attachedToConsole == true`, as if InfinityLoader is attached to the console, that means
		// the engine isn't, (which causes its WriteConsole() to fail).
		return fprintf(stderr, format, level, message);
	}
	else {
		FPrintErr(format, level, message);
		return 0;
	}
}

#define fprintf error

int logShimDisable(FILE* stream, const char* format, const char* level, const char* message) {
	return 0;
}

DWORD writeReplaceLogFunction(bool disable_fprintf = false) {

	void* sectionPtr;
	DWORD sectionSize;
	if (sharedState().GetSegmentPointerAndSize(".text", sectionPtr, sectionSize)) {
		Print("[!][InfinityLoaderDLL.dll] writeReplaceLogFunction() - Failed to fetch .text pointer and size\n");
		return -1;
	}

	PatternValueHandle patchAddressHandle;
	TryRetErr( findINICategoryPattern(sectionPtr, sectionSize, iniPath(), TEXT("Hardcoded_SDL_LogOutput()_fprintf"), patchAddressHandle) )
	if (sharedState().GetPatternValueType(patchAddressHandle) != PatternValueType::SINGLE) {
		Print("[!][InfinityLoaderDLL.dll] writeReplaceLogFunction() - [Hardcoded_SDL_LogOutput()_fprintf].Type must be SINGLE\n");
		return -1;
	}
	uintptr_t patchAddress = sharedState().GetSinglePatternValue(patchAddressHandle);

	uintptr_t curAllocatedPtr;
	SYSTEM_INFO info;
	GetSystemInfo(&info);

	if (DWORD lastError = AllocateNear(sharedState().ImageBase(), info.dwAllocationGranularity, curAllocatedPtr)) {
		return lastError;
	}

	AssemblyWriter writer = AssemblyWriter::Create();

	writer.SetLocation(patchAddress);
	writer.JmpToAddress(curAllocatedPtr);
	disableCodeProtection();
	writer.Flush();
	enableCodeProtection();
	writer.SetLocation(curAllocatedPtr);
	writer.CallToAddressFar(reinterpret_cast<uintptr_t>(!disable_fprintf ? logShim : logShimDisable));
	writer.JmpToAddress(patchAddress + 5);
	writer.Flush();

	if (debug()) {
		Print("[!][InfinityLoaderDLL.dll] writeReplaceLogFunction() - Done\n");
	}

	return 0;
}

void winMainHook() {

	if (debug()) {
		Print("[?][InfinityLoaderDLL.dll] winMainHook() - Debug output 2 (Windows: No, Proton: Yes)...\n");
	}

	// This function runs before the console has been attached, temporarily attach it for error output
	if (attachToConsole() != ERROR_SUCCESS) {
		return;
	}

	if (debug()) {

		Print("[?][InfinityLoaderDLL.dll] winMainHook() - Debug output 3 (Windows: Yes, Proton: Yes)...\n");

		FPrint("[?][InfinityLoaderDLL.dll] winMainHook() - Game hStdInput: %d\n", GetStdHandle(STD_INPUT_HANDLE));
		FPrint("[?][InfinityLoaderDLL.dll] winMainHook() - Game hStdOutput: %d\n", GetStdHandle(STD_OUTPUT_HANDLE));
		FPrint("[?][InfinityLoaderDLL.dll] winMainHook() - Game hStdError: %d\n", GetStdHandle(STD_ERROR_HANDLE));
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
	else if (protonCompatibility()) {
		installLogRedirect = true;
		disable_fprintf = true;
	}

	if (installLogRedirect) {

		if (debug()) {
			FPrint("[?][InfinityLoaderDLL.dll] winMainHook() - Redirecting output, disable_fprintf: %s\n", disable_fprintf ? "true" : "false");
		}

		if (DWORD redirectResult = writeReplaceLogFunction(disable_fprintf)) {
			FPrint("[!][InfinityLoaderDLL.dll] winMainHook() - Console redirection failed (%d)\n", redirectResult);
			goto cleanup;
		}
	}

cleanup:;
	detatchFromConsole();
}

template<typename pointer_type>
bool fillExportedPointer(const String& name, pointer_type& pointer, uintptr_t address) {
	if (!setSinglePatternValue(name, address)) return false;
	pointer = reinterpret_cast<pointer_type>(address);
	return true;
}

template<typename pointer_type>
bool fillExportedPointer(const String& name, pointer_type& pointer, void* address) {
	return fillExportedPointer(name, pointer, reinterpret_cast<uintptr_t>(address));
}

template<typename pointer_type, typename operations_type>
bool fillPatternPointer(void* segmentPtr, DWORD segmentSize, const String& name, pointer_type& pointer, const operations_type& operations) {

	PatternValueHandle patternHandle;
	TryRetErr( findINICategoryPattern(segmentPtr, segmentSize, iniPath(), name, patternHandle) )

	if (sharedState().GetPatternValueType(patternHandle) != PatternValueType::SINGLE) {
		FPrintT(TEXT("[!][InfinityLoaderDLL.dll] fillPatternPointer() - [%s].Type must be SINGLE\n"), name.c_str());
		return true;
	}

	uintptr_t address = sharedState().GetSinglePatternValue(patternHandle);
	operations(address);
	sharedState().SetSinglePatternValue(patternHandle, address);
	pointer = reinterpret_cast<pointer_type>(address);
	return false;
}

template<typename pointer_type>
bool fillPatternPointer(void* segmentPtr, DWORD segmentSize, const String& name, pointer_type& pointer) {
	return fillPatternPointer(segmentPtr, segmentSize, name, pointer, [](uintptr_t& address){});
}

/////////////////////////
// START Lua Functions //
/////////////////////////

static void initLuaState(lua_State *const L) {

	if (luaMode() != LuaMode::INTERNAL) {

		luaL_openlibs(L);

		// Since non-internal modes initialize the Lua state immediately, the engine's print() function isn't set when EEex's initial
		// Lua file is executed, which means print() must be redirected to InfinityLoader's FPrint() to get console output from the
		// initial file.
		lua_pushcfunction(L, temporaryPrintReplacementLua);
		lua_setglobal(L, "print");
	}

	////////////////////////
	// Export Lua Globals //
	////////////////////////

	lua_pushinteger(L, sizeof(void*));
	lua_setglobal(L, prefixed("PointerSize"));

	lua_pushinteger(L, sizeof(void*));
	lua_setglobal(L, prefixed("PtrSize"));

#if _WIN64
	lua_pushstring(L, "x86-64");
#elif _WIN32
	lua_pushstring(L, "x86");
#else
	#error "Unhandled Architecture"
#endif
	lua_setglobal(L, prefixed("Architecture"));

	//////////////////////////
	// Export Lua Functions //
	//////////////////////////

	exposeToLua(L, prefixed("AddToLuaRegistry"), addToLuaRegistryLua);
	exposeToLua(L, prefixed("AllocCodePageInternal"), allocCodePageInternalLua);
	exposeToLua(L, prefixed("BAnd"), bandLua);
	exposeToLua(L, prefixed("BNot"), bnotLua);
	exposeToLua(L, prefixed("BOr"), borLua);
	exposeToLua(L, prefixed("CFunctionToPointer"), cFunctionToPointerLua);
	exposeToLua(L, prefixed("CFuncToPtr"), cFunctionToPointerLua);
	exposeToLua(L, prefixed("DisableCodeProtection"), disableCodeProtectionLua);
	exposeToLua(L, prefixed("DoFile"), doFileLua);
	exposeToLua(L, prefixed("EnableCodeProtection"), enableCodeProtectionLua);
	exposeToLua(L, prefixed("ExposeToLua"), exposeToLuaLua);
	exposeToLua(L, prefixed("Extract"), extractLua);
	exposeToLua(L, prefixed("Free"), freeLua);
	exposeToLua(L, prefixed("GetLuaRegistryIndex"), getLuaRegistryIndexLua);
	exposeToLua(L, prefixed("GetLuaLibraryProc"), getLuaLibraryProcLua);
	exposeToLua(L, prefixed("GetMicroseconds"), getMicrosecondsLua);
	exposeToLua(L, prefixed("GetPatternMap"), getPatternMapLua);
	exposeToLua(L, prefixed("GetProcAddressInternal"), getProcAddressLua);
	exposeToLua(L, prefixed("InitializeLuaBindings"), initializeLuaBindingsLua);
	exposeToLua(L, prefixed("InitLuaBindings"), initializeLuaBindingsLua);
	exposeToLua(L, prefixed("IterateRegex"), iterateRegexLua);
	exposeToLua(L, prefixed("JIT"), jitLua);
	exposeToLua(L, prefixed("JITAtInternal"), jitAtInternalLua);
	exposeToLua(L, prefixed("LoadLibrary"), loadLibraryLua);
	exposeToLua(L, prefixed("LShift"), lshiftLua);
	exposeToLua(L, prefixed("Malloc"), mallocLua);
	exposeToLua(L, prefixed("Memcpy"), memcpyLua);
	exposeToLua(L, prefixed("Memset"), memsetLua);
	exposeToLua(L, prefixed("MessageBoxInternal"), messageBoxInternalLua);
	exposeToLua(L, prefixed("OpenLuaBindings"), openLuaBindingsLua);
	exposeToLua(L, prefixed("Print"), printLua);
	exposeToLua(L, prefixed("PrintErr"), printErrLua);
	exposeToLua(L, prefixed("ProcessThreadQueue"), processThreadQueueLua);
	exposeToLua(L, prefixed("Read16"), read16Lua);
	exposeToLua(L, prefixed("Read32"), read32Lua);
#if defined(_WIN64)
	exposeToLua(L, prefixed("Read64"), read64Lua);
#endif
	exposeToLua(L, prefixed("Read8"), read8Lua);
	exposeToLua(L, prefixed("ReadPointer"), readPointerLua);
	exposeToLua(L, prefixed("ReadPtr"), readPointerLua);
	exposeToLua(L, prefixed("ReadU16"), readU16Lua);
	exposeToLua(L, prefixed("ReadU32"), readU32Lua);
#if defined(_WIN64)
	exposeToLua(L, prefixed("ReadU64"), readU64Lua);
#endif
	exposeToLua(L, prefixed("ReadU8"), readU8Lua);
	exposeToLua(L, prefixed("ReadLString"), readLString);
	exposeToLua(L, prefixed("ReadString"), readString);
	exposeToLua(L, prefixed("RShift"), rshiftLua);
	exposeToLua(L, prefixed("RunWithStack"), runWithStackLua);
	exposeToLua(L, prefixed("SelectFromTables"), selectFromTablesLua);
	exposeToLua(L, prefixed("SetLuaRegistryIndex"), setLuaRegistryIndexLua);
	exposeToLua(L, prefixed("SetSegmentProtection"), setSegmentProtectionLua);
	exposeToLua(L, prefixed("ToDecimalString"), toDecimalStringLua);
	exposeToLua(L, prefixed("ToDecStr"), toDecimalStringLua);
	exposeToLua(L, prefixed("Write16"), write16Lua);
	exposeToLua(L, prefixed("Write32"), write32Lua);
#if defined(_WIN64)
	exposeToLua(L, prefixed("Write64"), write64Lua);
#endif
	exposeToLua(L, prefixed("Write8"), write8Lua);
	exposeToLua(L, prefixed("WritePointer"), writePointerLua);
	exposeToLua(L, prefixed("WritePtr"), writePointerLua);
	exposeToLua(L, prefixed("WriteU16"), writeU16Lua);
	exposeToLua(L, prefixed("WriteU32"), writeU32Lua);
	exposeToLua(L, prefixed("WriteU64"), writeU64Lua);
	exposeToLua(L, prefixed("WriteU8"), writeU8Lua);
	exposeToLua(L, prefixed("WriteLString"), writeLStringLua);
	exposeToLua(L, prefixed("WriteString"), writeStringLua);
	exposeToLua(L, prefixed("WriteStringAuto"), writeStringAutoLua);
}

/////////////////////////////////////
// START Hardcoded Pattern Exports //
/////////////////////////////////////

static void __stdcall doLuaFileExport(lua_State *const L, const char *const str) {
	callOverrideFile(L, str);
}

static lua_State* __stdcall getLuaStateExport() {
	return luaState();
}

static void __stdcall logExport(const char *const str) {
	Print(str);
}

static void logVExport(const char* formatText, ...) {

	va_list args;
	va_start(args, formatText);

	RunWithGrowingBuffer<char>(
		[&](char *const buffer, const size_t bufferSize) {
			const int result = _vsnprintf_s(buffer, bufferSize, _TRUNCATE, formatText, args);
			return result == -1 ? TryFillBufferResult::GROW : TryFillBufferResult::DONE;
		},
		[&](char *const buffer, const size_t) {
			Print(buffer);
		}
	);

	va_end(args);
}

static lua_State* __stdcall newLuaStateExport() {
	lua_State* const L = luaL_newstate();
	sharedState().InitLuaState(L);
	initLuaState(L);
	return L;
}

///////////////////////////////////
// END Hardcoded Pattern Exports //
///////////////////////////////////

static void initLua() {

	if (debug()) {
		Print("[?][InfinityLoaderDLL.dll] initLua() - Debug output 4 (Windows: No, Proton: Yes)...\n");
	}

	// This function runs before the console has been attached, temporarily attach it for error output
	if (attachToConsole() != ERROR_SUCCESS) {
		return;
	}

	if (debug()) {
		Print("[?][InfinityLoaderDLL.dll] initLua() - Debug output 5 (Windows: Yes, Proton: Yes)...\n");
	}

#define fillPatternPointerCleanup(name, outName) \
	if (fillPatternPointer(sectionPtr, sectionSize, TEXT(name), p_##outName)) { \
		goto cleanup; \
	}

#define fillExportedPointerCleanup(name, pointer, address) \
	if (!fillExportedPointer(name, pointer, address)) { \
		goto cleanup; \
	}

#define setSinglePatternValueCleanup(name, address) \
	if (!setSinglePatternValue(name, address)) { \
		goto cleanup; \
	}

	////////////////////
	// Init Lua state //
	////////////////////

	void* sectionPtr;
	DWORD sectionSize;

	String earlyPrintPrefixW;
	String extenderNameW;
	String luaGlobalsPrefixW;

	if (sharedState().GetSegmentPointerAndSize(".text", sectionPtr, sectionSize)) {
		Print("[!][InfinityLoaderDLL.dll] initLua() - Failed to fetch .text pointer and size\n");
		goto cleanup;
	}

	if (GetINIStrDef(iniPath(), TEXT("General"), TEXT("ExtenderName"), TEXT("EEex"), extenderNameW) != ERROR_SUCCESS) {
		Print("[!][InfinityLoaderDLL.dll] initLua() - Failed to read [General].ExtenderName\n");
		goto cleanup;
	}
	extenderName = StrToStrA(extenderNameW);

	if (GetINIStrDef(iniPath(), TEXT("General"), TEXT("LuaGlobalsPrefix"), TEXT("EEex_"), luaGlobalsPrefixW) != ERROR_SUCCESS) {
		Print("[!][InfinityLoaderDLL.dll] initLua() - Failed to read [General].LuaGlobalsPrefix\n");
		goto cleanup;
	}
	luaGlobalsPrefix = StrToStrA(luaGlobalsPrefixW);

	if (GetINIStrDef(iniPath(), TEXT("General"), TEXT("EarlyPrintPrefix"), TEXT(""), earlyPrintPrefixW) != ERROR_SUCCESS) {
		Print("[!][InfinityLoaderDLL.dll] initLua() - Failed to read [General].EarlyPrintPrefixW\n");
		goto cleanup;
	}
	earlyPrintPrefix = StrToStrA(earlyPrintPrefixW);

	lua_State* L;

	if (luaMode() == LuaMode::INTERNAL) {
		if (fillPatternPointer(sectionPtr, sectionSize, TEXT("Hardcoded_InternalLuaState"), L, [](uintptr_t& address) {
			address = *reinterpret_cast<uintptr_t*>(address);
		})) {
			goto cleanup;
		}
	}
	else {
		L = luaL_newstate();
		setSinglePatternValueCleanup(TEXT("Hardcoded_InternalLuaState"), L)
	}

	sharedState().InitLuaState(L);
	initLuaState(L);

	/////////////////////////////////////
	// Export Hardcoded Pattern Values //
	/////////////////////////////////////

	setSinglePatternValueCleanup(TEXT("Hardcoded_doLuaFile"), doLuaFileExport)
	setSinglePatternValueCleanup(TEXT("Hardcoded_getLuaState"), getLuaStateExport)
	setSinglePatternValueCleanup(TEXT("Hardcoded_log"), logExport)
	setSinglePatternValueCleanup(TEXT("Hardcoded_logV"), logVExport)
	setSinglePatternValueCleanup(TEXT("Hardcoded_newLuaState"), newLuaStateExport)

	///////////////////////
	// Run Main Lua File //
	///////////////////////

	if (luaMode() == LuaMode::INTERNAL) {
		fillPatternPointerCleanup("Hardcoded_free", free)
		fillPatternPointerCleanup("Hardcoded_malloc", malloc);
		callOverrideFile(L, prefixed("Main"));
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

		fillExportedPointerCleanup(TEXT("Hardcoded_free"), p_free, free);
		fillExportedPointerCleanup(TEXT("Hardcoded_malloc"), p_malloc, malloc);

		if (luaMode() == LuaMode::REPLACE_INTERNAL_WITH_EXTERNAL) {
			callOverrideFile(L, prefixed("EarlyMain"));
		}
		else {
			callOverrideFile(L, prefixed("Main"));
		}

		fillPatternPointerCleanup("Hardcoded_free", free);
		fillPatternPointerCleanup("Hardcoded_malloc", malloc);
	}

cleanup:;
	detatchFromConsole();
}

void delayedMainCall() {
	TryRetTruthy( attachToConsole() )
	callOverrideFile(luaState(), prefixed("Main"));
	TryRetTruthy( detatchFromConsole() )
}

void writeCallHookProcAfterCall(AssemblyWriter& writer, uintptr_t& curAllocatedPtr, uintptr_t patchAddress, void* targetProc) {

	// curAllocatedPtr keeps track of the current address in the VirtualAlloc()'d patch space

	__int32 relativeAmount = *reinterpret_cast<__int32*>(patchAddress + 1);
	uintptr_t target = patchAddress + 5 + relativeAmount;

	writer.SetLocation(patchAddress);
	writer.JmpToAddress(curAllocatedPtr);
	disableCodeProtection();
	writer.Flush();
	enableCodeProtection();

	writer.SetLocation(curAllocatedPtr);
	writer.CallToAddress(target);
	writer.PushVolatileRegisters();
	writer.AlignStackAndMakeShadowSpace();
	writer.CallToAddressFar(reinterpret_cast<uintptr_t>(targetProc));
	writer.UndoAlignAndShadowSpace();
	writer.PopVolatileRegisters();
	writer.JmpToAddress(patchAddress + 5);
	writer.Flush();

	curAllocatedPtr = writer.GetCurrentLocation();
}

DWORD writeInternalPatch(AssemblyWriter& writer, uintptr_t& curAllocatedPtr, void(*funcPtr)()) {

	// curAllocatedPtr keeps track of the current address in the VirtualAlloc()'d patch space

	void* sectionPtr;
	DWORD sectionSize;
	if (sharedState().GetSegmentPointerAndSize(".text", sectionPtr, sectionSize)) {
		Print("[!][InfinityLoaderDLL.dll] writeInternalPatch() - Failed to fetch .text pointer and size\n");
		return -1;
	}

	PatternValueHandle patchAddressHandle;
	TryRetErr( findINICategoryPattern(sectionPtr, sectionSize, iniPath(), TEXT("Hardcoded_InternalPatchLocation"), patchAddressHandle) )
	if (sharedState().GetPatternValueType(patchAddressHandle) != PatternValueType::SINGLE) {
		Print("[!][InfinityLoaderDLL.dll] writeInternalPatch() - [Hardcoded_InternalPatchLocation].Type must be SINGLE\n");
		return -1;
	}
	uintptr_t patchAddress = sharedState().GetSinglePatternValue(patchAddressHandle);

	writeCallHookProcAfterCall(writer, curAllocatedPtr, patchAddress, funcPtr);
	return ERROR_SUCCESS;
}

DWORD setUpLuaInitialization(void* sectionPtr, DWORD sectionSize) {

	uintptr_t curAllocatedPtr;
	SYSTEM_INFO info;
	GetSystemInfo(&info);

	TryRetErr( AllocateNear(sharedState().ImageBase(), info.dwAllocationGranularity, curAllocatedPtr) )

	AssemblyWriter writer = AssemblyWriter::Create();

	// Write hook early in WinMain to check for Console redirection
	if (INISectionExists(iniPath(), TEXT("Hardcoded_WinMainPatchLocation"))) {
		PatternValueHandle winMainPatchAddressHandle;
		TryRetErr( findINICategoryPattern(sectionPtr, sectionSize, iniPath(), TEXT("Hardcoded_WinMainPatchLocation"), winMainPatchAddressHandle) )
		if (sharedState().GetPatternValueType(winMainPatchAddressHandle) != PatternValueType::SINGLE) {
			Print("[!][InfinityLoaderDLL.dll] setUpLuaInitialization() - [Hardcoded_WinMainPatchLocation].Type must be SINGLE\n");
			return -1;
		}
		uintptr_t winMainPatchAddress = sharedState().GetSinglePatternValue(winMainPatchAddressHandle);
		writeCallHookProcAfterCall(writer, curAllocatedPtr, winMainPatchAddress, winMainHook);
	}

	// Initialize code that tracks patterns and exports them to Lua
	initPatternTracking();

	// Write Lua initialization hook
	if (LuaMode luaMode = luaMode(); luaMode == LuaMode::INTERNAL) {
		TryRetErr( writeInternalPatch(writer, curAllocatedPtr, initLua) )
	}
	else if (luaMode == LuaMode::REPLACE_INTERNAL_WITH_EXTERNAL) {
		TryRetErr( writeInternalPatch(writer, curAllocatedPtr, delayedMainCall) )
		initLua();
	}
	else {
		initLua();
	}

	return ERROR_SUCCESS;
}

DWORD loadExeNameForPatterns() {
	exeNameForPatterns = exeName();
	String globalExeAlias;
	TryRetErr( GetINIStrDef(iniPath(), TEXT("General"), TEXT("ExeSwitchAlias"), TEXT(""), globalExeAlias) )
	return resolveAliasTarget(globalExeAlias, exeNameForPatterns);
}

DWORD patchExe() {

	#pragma push_macro("printInitFailed")
	#pragma push_macro("attemptElseRetErr")
	#define printInitFailed() Print("[!][InfinityLoaderDLL.dll] patchExe() - Initialization failed; the main Lua file will not be executed\n");
	#define attemptElseRetErr(call) TryElseRetErr( call, printInitFailed() )

	attemptElseRetErr( loadExeNameForPatterns() )

	void* sectionPtr;
	DWORD sectionSize;
	if (sharedState().GetSegmentPointerAndSize(".text", sectionPtr, sectionSize)) {
		Print("[!][InfinityLoaderDLL.dll] patchExe() - Failed to fetch .text pointer and size\n");
		printInitFailed()
		return -1;
	}

	attemptElseRetErr( findPatterns(sectionPtr, sectionSize) )
	attemptElseRetErr( InitLuaProvider(sharedState()) )
	attemptElseRetErr( setUpLuaInitialization(sectionPtr, sectionSize) )
	return ERROR_SUCCESS;

	#pragma pop_macro("attemptElseRetErr")
	#pragma pop_macro("printInitFailed")
}

// Return:
//   0 -> No Error
//   1 -> Error (no console output)
//   2 -> Error (console output)

byte init(HANDLE mappedMemoryHandle) {

	SharedStateMappedMemory mappedMemory;
	if (InitMappedMemory(mappedMemoryHandle, mappedMemory) || SharedState::Create(mappedMemory, sharedState())) {
		return 1;
	}

	if (pause()) {
		MessageBox(NULL, TEXT("[?] init() - Pause"), TEXT("InfinityLoaderDLL.dll"), MB_ICONINFORMATION);
	}

	// This function runs before the console has been attached, temporarily attach it for error output
	if (attachToConsole() != ERROR_SUCCESS) {
		return 1;
	}

	if (protonCompatibility()) {
		if (int error = UnbufferCrtStreams()) {
			FPrint("[!][InfinityLoaderDLL.dll] init() - UnbufferCrtStreams() failed (%d)\n", error);
			return 2;
		}
	}

	if (int error = InitFPrint()) {
		FPrint("[!][InfinityLoaderDLL.dll] init() - InitFPrint() failed (%d)\n", error);
		return 2;
	}

	if (debug()) {

		Print("[?][InfinityLoaderDLL.dll] init() - Debug output 1 (Windows: Yes, Proton: Yes)...\n");

		FPrint("[?][InfinityLoaderDLL.dll] init() - DLL hStdInput: %d\n", GetStdHandle(STD_INPUT_HANDLE));
		FPrint("[?][InfinityLoaderDLL.dll] init() - DLL hStdOutput: %d\n", GetStdHandle(STD_OUTPUT_HANDLE));
		FPrint("[?][InfinityLoaderDLL.dll] init() - DLL hStdError: %d\n", GetStdHandle(STD_ERROR_HANDLE));
	}

	if (sharedState().InitState()) {
		return 2;
	}

	return 0;
}

int exceptionFilter(unsigned int code, _EXCEPTION_POINTERS* pointers, unsigned int& codeOut) {
	String dmpLocation = WriteDump(workingFolder(), pointers);
	MessageBoxFormat(TEXT("InfinityLoaderDLL.dll"), MB_ICONERROR, TEXT("[!] Unhandled exception 0x%X. Crash log saved to:\n\n%s\n\nThis should never happen. Please report to Bubb."), code, dmpLocation.c_str());
	codeOut = code;
	return EXCEPTION_EXECUTE_HANDLER;
}

int exceptionFilterIgnoreIfSubsequent(unsigned int code, _EXCEPTION_POINTERS* pointers, unsigned int& codeOut) {
	if (!codeOut) {
		String dmpLocation = WriteDump(workingFolder(), pointers);
		MessageBoxFormat(TEXT("InfinityLoaderDLL.dll"), MB_ICONERROR, TEXT("[!] Unhandled exception 0x%X. Crash log saved to:\n\n%s\n\nThis should never happen. Please report to Bubb."), code, dmpLocation.c_str());
		codeOut = code;
	}
	return EXCEPTION_EXECUTE_HANDLER;
}

// Don't remove __stdcall - the patch that calls this function assumes the stack gets cleaned up
void __stdcall Init(HANDLE mappedMemoryHandle) {

	unsigned int exitCode = 0;

	__try {

		if (byte result = init(mappedMemoryHandle)) {
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
