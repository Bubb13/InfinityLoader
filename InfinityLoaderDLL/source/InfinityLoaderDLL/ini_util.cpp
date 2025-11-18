
#include <sstream>

#include "infinity_loader_common_api.h"
#include "protection_util.hpp"
#include "ini_util.hpp"

/////////////
// Structs //
/////////////

struct PatternByteEntry
{
	bool isWild;
	unsigned char byte;
	PatternByteEntry(const unsigned char pByte, const bool pIsWild) : byte(pByte), isWild(pIsWild) {};
};

/////////////
// Globals //
/////////////

bool attemptUseCached = false;
String exeNameForPatterns;

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

//////////////////////
// Static Functions //
//////////////////////

static DWORD resolveAliasTarget(const String aliasList, String& toTransform)
{
	if (aliasList == TEXT(""))
	{
		return 0;
	}

	DWORD result = 0;

	ForEveryCharSplit(aliasList, TCHAR{','}, [&](const String str)
	{
		const size_t colonI = str.find(TCHAR{':'});

		if (colonI == std::string::npos)
		{
			FPrintT(TEXT("[!][InfinityLoaderDLL.dll] resolveAliasTarget() - Invalid ExeSwitchAlias: \"%s\"\n"), str.c_str());
			result = -1;
			return true;
		}

		const String alias = str.substr(0, colonI);
		const String target = str.substr(colonI + 1);

		if (target.find(TCHAR{':'}) != std::string::npos)
		{
			FPrintT(TEXT("[!][InfinityLoaderDLL.dll] resolveAliasTarget() - Invalid ExeSwitchAlias: \"%s\"\n"), str.c_str());
			result = -1;
			return true;
		}

		if (alias == toTransform)
		{
			toTransform = target;
			return true;
		}

		return false;
	});

	return result;
}

static DWORD processINICategoryPatternValue(
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

	if (type == PatternValueType::SINGLE)
	{
		uintptr_t address;
		TryRetErr( GetINIUIntPtrDef(iniPath, iniCategoryName.c_str(), singleKey, -1, address) )

		if (address != -1)
		{
			PatternValueHandle handle;
			TryRetDefErrCode( setSinglePatternValue(originalINICategoryName, address, handle) )

			valueHandleOut = handle;
			filledOut = true;
			return 0;
		}
	}
	else if (type == PatternValueType::LIST)
	{
		String addresses;
		bool filled;
		TryRetErr( GetINIStr(iniPath, iniCategoryName.c_str(), listKey, addresses, filled) )

		if (filled)
		{
			PatternValueHandle handle;

			if (sharedState().GetOrCreatePatternValue(originalINICategoryName, PatternValueType::LIST, handle))
			{
				FPrintT(TEXT("[!][InfinityLoaderDLL.dll] processINICategoryPatternValue() - Conflicting pattern [%s].Type\n"), originalINICategoryName.c_str());
				return -1;
			}

			bool success = false;

			ForEveryCharSplit(addresses, TCHAR{ ',' }, [&](String addressStr)
			{
				uintptr_t address;

				if (!DecStrToUIntPtr(addressStr, address))
				{
					success = false;
					FPrintT(TEXT("[!][InfinityLoaderDLL.dll] processINICategoryPatternValue() - Failed to parse [%s].%s\n"), iniCategoryName.c_str(), listKey);
					return true;
				}

				success = true;
				sharedState().AddListPatternValue(handle, address);
				return false;
			});

			if (success)
			{
				valueHandleOut = handle;
				filledOut = true;
				return 0;
			}
		}
	}
	else
	{
		FPrintT(TEXT("[!][InfinityLoaderDLL.dll] processINICategoryPatternValue() - Invalid [%s].Type\n"), iniCategoryName.c_str());
		return -1;
	}

	return 0;
}

static bool findByteList(void* sectionPtr, DWORD sectionSize, std::list<PatternByteEntry>& byteList, uintptr_t& addressOut)
{
	unsigned char* curAddress = reinterpret_cast<unsigned char*>(sectionPtr);
	unsigned char* endAddress = curAddress + sectionSize;

	for (; curAddress < endAddress; ++curAddress)
	{
		unsigned char* checkAddress = curAddress;

		for (PatternByteEntry& entry : byteList)
		{
			if (!entry.isWild && entry.byte != *checkAddress)
			{
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
static bool checkOperationsArgCount(const String& iniCategoryName, const String& operationStr,
	const std::vector<String>& parts, const Func condition)
{
	size_t numArgs = parts.size() - 1;
	if (!condition(numArgs))
	{
		FPrintT(TEXT("[!][InfinityLoaderDLL.dll] checkOperationsArgCount() - Invalid number of arguments in %s operation for [%s].Operations: %d\n"),
			iniCategoryName.c_str(), operationStr.c_str(), static_cast<int>(numArgs)
		);
		return false;
	}
	return true;
}

static bool checkOperationsStackCount(const String& iniCategoryName, const String& operationStr,
	const std::vector<intptr_t>& stack, size_t neededStackSize)
{
	size_t stackSize = stack.size();
	if (stackSize < neededStackSize)
	{
		FPrintT(TEXT("[!][InfinityLoaderDLL.dll] checkOperationsStackCount() - Not enough values pushed onto stack in %s operation for [%s].Operations: %d < %d\n"),
			operationStr.c_str(), iniCategoryName.c_str(), static_cast<int>(stackSize), static_cast<int>(neededStackSize)
		);
		return false;
	}
	return true;
}

static bool tryOperationsConvertToDecimal(const String& iniCategoryName, const String& operationStr,
	const std::vector<String>& parts, const int argI, intptr_t& out)
{
	String arg = parts[argI];
	if (!DecStrToIntPtr(arg, out))
	{
		FPrintT(TEXT("[!][InfinityLoaderDLL.dll] tryOperationsConvertToDecimal() - Failed to convert %s argument to decimal for [%s].Operations: \"%s\"\n"),
			operationStr.c_str(), iniCategoryName.c_str(), arg.c_str()
		);
		return false;
	}
	return true;
}

// TODO: Suboptimal
static bool hexLetterToByte(String hexLetter, unsigned char& byteOut)
{
	for (auto& tup : aHexLetterToByte)
	{
		if (hexLetter == std::get<0>(tup) || hexLetter == std::get<1>(tup))
		{
			byteOut = std::get<2>(tup);
			return true;
		}
	}
	return false;
}

static bool decodeByteString(String byteStr, std::list<PatternByteEntry>& listToFill, String& errorOut)
{
	size_t byteStrLen = byteStr.length();

	if (byteStrLen == 0 || byteStrLen & 1)
	{
		errorOut = String{ TEXT("Length zero / not even") };
		return false;
	}

	for (size_t i = 0; i < byteStrLen; i += 2)
	{
		String curByteLetter1 = byteStr.substr(i, 1);
		String curByteLetter2 = byteStr.substr(i + 1, 1);

		if (curByteLetter1 == TEXT("?") && curByteLetter2 == TEXT("?"))
		{
			listToFill.emplace_back(0, true);
			continue;
		}

		unsigned char curByte = 0;

		unsigned char curByte1;
		if (!hexLetterToByte(curByteLetter1, curByte1))
		{
			errorOut = String{ TEXT("Invalid hex character: '") }.append(curByteLetter1.c_str()).append(TEXT("'"));
			return false;
		}
		curByte |= (curByte1 << 4);

		unsigned char curByte2;
		if (!hexLetterToByte(curByteLetter2, curByte2))
		{
			errorOut = String{ TEXT("Invalid hex character: '") }.append(curByteLetter2.c_str()).append(TEXT("'"));
			return false;
		}
		curByte |= curByte2;

		listToFill.emplace_back(curByte, false);
	}

	return true;
}

static bool handlePatternOperations(String iniCategoryName, String operationsStr, uintptr_t& address)
{
	std::vector<intptr_t> stack{ static_cast<intptr_t>(address) };
	std::vector<String> curParts;
	bool result = true;

#define checkArgCount(condition) \
	if (!checkOperationsArgCount(iniCategoryName, operationName, curParts, condition)) \
	{ \
		result = false; \
		return true; \
	}

#define checkStackCount(count) \
	if (!checkOperationsStackCount(iniCategoryName, operationName, stack, count)) \
	{ \
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

	ForEveryCharSplit(operationsStr, TCHAR{ ',' }, [&](const String str)
	{
		ForEveryCharSplit(str, TCHAR{ ' ' }, [&](const String str)
		{
			curParts.push_back(str);
			return false;
		});

		if (curParts.size() == 0)
		{
			FPrintT(TEXT("[!][InfinityLoaderDLL.dll] handlePatternOperations() - Operation missing for [%s].Operations\n"), iniCategoryName.c_str());
			result = false;
			return true;
		}

		size_t numArgs = curParts.size() - 1;
		String operationName = curParts[0];
		intptr_t* back = &stack.back();

		if (operationName == TEXT("ADD"))
		{
			checkArgCount([](const size_t count)
			{
				return count == 0 || count == 1;
			});

			if (numArgs == 0)
			{
				checkStackCount(2);
				intptr_t backVal = *back;
				stack.pop_back();
				back = &stack.back();
				*back += backVal;
			}
			else
			{
				intptr_t arg1;
				tryConvertArgToDecimal(1, arg1);
				*back += arg1;
			}
		}
		else if (operationName == TEXT("READ"))
		{
			checkArgCount([](const size_t count)
			{
				return count == 1;
			});

			String arg1 = curParts[1];

			if (arg1 == TEXT("BYTE"))
			{
				*back = *reinterpret_cast<__int8*>(*back);
			}
			else if (arg1 == TEXT("SHORT"))
			{
				*back = *reinterpret_cast<__int16*>(*back);
			}
			else if (arg1 == TEXT("DWORD"))
			{
				*back = *reinterpret_cast<__int32*>(*back);
			}
#if defined(_WIN64)
			else if (arg1 == TEXT("QWORD"))
			{
				*back = *reinterpret_cast<__int64*>(*back);
			}
#endif
			else
			{
				FPrintT(TEXT("[!][InfinityLoaderDLL.dll] handlePatternOperations() - Invalid READ argument for [%s].Operations: \"%s\"\n"), iniCategoryName.c_str(), arg1.c_str());
				result = false;
				return true;
			}
		}
		else if (operationName == TEXT("WRITE"))
		{
			checkArgCount([](const size_t count)
			{
				return count == 2;
			});

			String arg1 = curParts[1];
			String arg2 = curParts[2];

			if (arg1 == TEXT("BYTES"))
			{
				std::list<PatternByteEntry> byteList;
				String errorStr;

				if (!decodeByteString(arg2, byteList, errorStr))
				{
					FPrintT(TEXT("[!][InfinityLoaderDLL.dll] handlePatternOperations() - Failed to decode BYTES value for [%s].Operations: \"%s\", %s\n"), iniCategoryName.c_str(), arg2.c_str(), errorStr.c_str());
					return true;
				}

				unsigned char* curWrite = reinterpret_cast<unsigned char*>(*back);

				for (auto& entry : byteList)
				{
					if (entry.isWild)
					{
						++curWrite;
						continue;
					}
					*curWrite++ = entry.byte;
				}
			}
			else
			{
				intptr_t arg2Dec;
				tryConvertArgToDecimal(2, arg2Dec);

				if (arg1 == TEXT("BYTE"))
				{
					*reinterpret_cast<__int8*>(*back) = static_cast<__int8>(arg2Dec);
				}
				else if (arg1 == TEXT("SHORT"))
				{
					*reinterpret_cast<__int16*>(*back) = static_cast<__int16>(arg2Dec);
				}
				else if (arg1 == TEXT("DWORD"))
				{
					*reinterpret_cast<__int32*>(*back) = static_cast<__int32>(arg2Dec);
				}
#if defined(_WIN64)
				else if (arg1 == TEXT("QWORD"))
				{
					*reinterpret_cast<__int64*>(*back) = static_cast<__int64>(arg2Dec);
				}
#endif
				else
				{
					FPrintT(TEXT("[!][InfinityLoaderDLL.dll] handlePatternOperations() - Invalid WRITE argument for [%s].Operations: \"%s\"\n"), iniCategoryName.c_str(), arg1.c_str());
					result = false;
					return true;
				}
			}
		}
		else if (operationName == TEXT("PUSH"))
		{
			stack.push_back(*back);
			back = &stack.back();
		}
		else if (operationName == TEXT("DISABLE_CODE_PROTECTION"))
		{
			disableCodeProtection();
		}
		else if (operationName == TEXT("ENABLE_CODE_PROTECTION"))
		{
			enableCodeProtection();
		}
		else
		{
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

///////////////
// Functions //
///////////////

DWORD loadExeNameForPatterns()
{
	exeNameForPatterns = exeName();
	String globalExeAlias;
	TryRetErr( GetINIStrDef(iniPath(), TEXT("General"), TEXT("ExeSwitchAlias"), TEXT(""), globalExeAlias) )
	return resolveAliasTarget(globalExeAlias, exeNameForPatterns);
}

DWORD findINICategoryPattern(void* sectionPtr, DWORD sectionSize, const String& iniPath,
	const String& originalINICategoryName, PatternValueHandle& valueHandleOut)
{
	String iniCategoryName = originalINICategoryName;
	uintptr_t bExeSwitch;

	if (DWORD lastError = GetINIUIntPtrDef(iniPath, iniCategoryName.c_str(), TEXT("ExeSwitch"), 0, bExeSwitch))
	{
		return lastError;
	}

	if (bExeSwitch)
	{
		String exeAlias;

		if (DWORD lastError = GetINIStrDef(iniPath, iniCategoryName.c_str(), TEXT("ExeSwitchAlias"), TEXT(""), exeAlias))
		{
			return lastError;
		}

		String exeSwitchName { exeNameForPatterns };

		if (DWORD lastError = resolveAliasTarget(exeAlias, exeSwitchName))
		{
			return lastError;
		}

		iniCategoryName.insert(0, String{ TEXT("!ExeSwitch-") }.append(exeSwitchName).append(TEXT("-")));
	}

	bool unsupported;
	TryRetErr( GetINIBoolDef(iniPath, iniCategoryName.c_str(), TEXT("Unsupported"), false, unsupported) )

	if (unsupported)
	{
		return 0;
	}

	String typeStr;
	TryRetErr( GetINIStrDef(iniPath, iniCategoryName.c_str(), TEXT("Type"), TEXT("SINGLE"), typeStr) )

	PatternValueType type;

	if (typeStr == TEXT("SINGLE"))
	{
		type = PatternValueType::SINGLE;
	}
	else if (typeStr == TEXT("LIST"))
	{
		type = PatternValueType::LIST;
	}
	else
	{
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

	if (hadValue)
	{
		return 0;
	}

	bool noCache;
	TryRetErr( GetINIBoolDef(iniPath, iniCategoryName.c_str(), TEXT("NoCache"), false, noCache) )

	if (!noCache && attemptUseCached)
	{
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

		if (filled)
		{
			return 0;
		}
	}

	String pattern;

	if (DWORD lastError = GetINIStrDef(iniPath, iniCategoryName.c_str(), TEXT("Pattern"), TEXT(""), pattern))
	{
		return lastError;
	}

	std::list<PatternByteEntry> byteList;
	String errorStr;

	if (!decodeByteString(pattern, byteList, errorStr))
	{
		FPrintT(TEXT("[!][InfinityLoaderDLL.dll] findINICategoryPattern() - Failed to decode [%s].Pattern: \"%s\"\n"), iniCategoryName.c_str(), errorStr.c_str());
		return -1;
	}

	if (type == PatternValueType::SINGLE)
	{
		uintptr_t foundAddress;

		if (!findByteList(sectionPtr, sectionSize, byteList, foundAddress))
		{
			FPrintT(TEXT("[!][InfinityLoaderDLL.dll] findINICategoryPattern() - Could not find [%s].Pattern\n"), iniCategoryName.c_str());
			return -1;
		}

		String operations;

		if (DWORD lastError = GetINIStrDef(iniPath, iniCategoryName.c_str(), TEXT("Operations"), TEXT(""), operations))
		{
			return lastError;
		}

		if (operations != TEXT(""))
		{
			handlePatternOperations(iniCategoryName, operations, foundAddress);
		}

		PatternValueHandle handle;
		TryRetDefErrCode( setSinglePatternValue(originalINICategoryName, foundAddress, handle) )

		valueHandleOut = handle;
	}
	else if (type == PatternValueType::LIST)
	{
		PatternValueHandle handle;

		if (sharedState().GetOrCreatePatternValue(originalINICategoryName, PatternValueType::LIST, handle))
		{
			FPrintT(TEXT("[!][InfinityLoaderDLL.dll] findINICategoryPattern() - Conflicting pattern [%s].Type\n"), originalINICategoryName.c_str());
			return -1;
		}

		void* curAddress = sectionPtr;

		while (true)
		{
			uintptr_t foundAddress;

			if (!findByteList(curAddress, sectionSize, byteList, foundAddress))
			{
				break;
			}

			String operations;
			TryRetErr( GetINIStrDef(iniPath, iniCategoryName.c_str(), TEXT("Operations"), TEXT(""), operations) )

			uintptr_t finalAddress = foundAddress;

			if (operations != TEXT(""))
			{
				handlePatternOperations(iniCategoryName, operations, finalAddress);
			}

			sharedState().AddListPatternValue(handle, finalAddress);
			curAddress = reinterpret_cast<void*>(foundAddress + byteList.size());
		}

		if (curAddress == sectionPtr)
		{
			FPrintT(TEXT("[!][InfinityLoaderDLL.dll] findINICategoryPattern() - Could not find [%s].Pattern\n"), iniCategoryName.c_str());
			return -1;
		}

		valueHandleOut = handle;
	}

	if (!noCache)
	{
		if (type == PatternValueType::SINGLE)
		{
			TryRetErr( SetINIUIntPtr(iniPath, iniCategoryName.c_str(), TEXT("CachedAddress"), sharedState().GetSinglePatternValue(valueHandleOut)) )
		}
		else if (type == PatternValueType::LIST)
		{
			OStringStream stream{};

			sharedState().IteratePatternList(valueHandleOut, [&](uintptr_t address)
			{
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
