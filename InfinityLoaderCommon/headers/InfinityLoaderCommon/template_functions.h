
#pragma once

#include "infinity_loader_common.h"

/////////////
// Globals //
/////////////

extern const std::initializer_list<const std::pair<TCHAR, unsigned char>> aDecimalDigitToByte;

///////////////
// Functions //
///////////////

void LogUsingFuncT(LogFuncT logFunc, const TCHAR* formatText, ...);

////////////////////////
// Template Functions //
////////////////////////

// TODO: Suboptimal
template<typename IntegerType>
bool decimalStrToIntegerTemplate(const String& decimalStr, IntegerType& accumulator) {

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
				accumulator += static_cast<IntegerType>(entry.second * curPow);
				curPow *= 10;
				goto loop_continue;
			}
		}

		return false;
	loop_continue:;

	} while (i-- != minimumI);

	if (negative) {
		using SignedIntegerType = std::make_signed<IntegerType>::type;
		accumulator = -static_cast<SignedIntegerType>(accumulator);
	}

	return true;
}

template<typename IntegerType>
struct DivisorInformation {
	IntegerType divisor;
	IntegerType nNumberChars;
};

template<typename IntegerType>
constexpr DivisorInformation<IntegerType> calculateDivisorInformation() {

	constexpr auto maxPossible = (std::numeric_limits<IntegerType>::max)() / 10;

	IntegerType multiple = 1;
	IntegerType numChars = 1;

	while (multiple <= maxPossible) {
		++numChars;
		multiple *= 10;
	}

	return { multiple, numChars };
}

template<typename StringType, typename IntegerType>
StringType integerToDecimalStrTemplate(IntegerType integer) {

	if (integer == 0) {
		return StringType{ '0' };
	}

	const StringType::value_type decDigitToChar[10]{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	constexpr const DivisorInformation divisorInformation = calculateDivisorInformation<IntegerType>();
	auto divisor = divisorInformation.divisor;

	using CharType = StringType::value_type;
	CharType *const buffer = reinterpret_cast<CharType*>(alloca(static_cast<size_t>(
		sizeof(CharType) * (divisorInformation.nNumberChars + 1)
	)));

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
	return StringType{ buffer, writeI };
}

template<typename IntegerType>
DWORD getINIIntegerTemplate(const String& iniPath, const TCHAR *const section, const TCHAR *const key,
	IntegerType& outInteger, bool& filled, LogFuncT logFunc)
{
	filled = false;

	TCHAR buffer[1024];
	const std::size_t bufferSize = sizeof(buffer) / sizeof(buffer[0]);

	DWORD numRead = GetPrivateProfileString(section, key, nullptr,
		buffer, bufferSize, iniPath.c_str());

	if (DWORD lastError = GetLastError(); lastError != ERROR_SUCCESS && lastError != ERROR_FILE_NOT_FOUND) {
		LogUsingFuncT(logFunc, TEXT("[!][InfinityLoaderCommon.dll] getINIIntegerTemplate() - GetPrivateProfileString() failed (%d)"), lastError);
		return lastError;
	}

	if (numRead > 0) {
		if (!decimalStrToIntegerTemplate(buffer, outInteger)) {
			LogUsingFuncT(logFunc, TEXT("[!][InfinityLoaderCommon.dll] getINIIntegerTemplate() - Invalid decimal for [%s].%s: \"%s\""), section, key, buffer);
			return -1;
		}
		filled = true;
	}

	return 0;
}

template<typename IntegerType>
DWORD getINIIntegerTemplate(const String& iniPath, const TCHAR *const section, const TCHAR *const key,
	IntegerType& outInteger, bool& filled)
{
	return getINIIntegerTemplate(iniPath, section, key, outInteger, filled, LogPrint);
}

template<typename IntegerType>
DWORD getINIIntegerDefTemplate(const String& iniPath, const TCHAR *const section, const TCHAR *const key,
	const IntegerType def, IntegerType& outInteger, LogFuncT errorFunc)
{
	bool filled;
	DWORD error = getINIIntegerTemplate(iniPath, section, key, outInteger, filled, errorFunc);
	if (!filled) {
		outInteger = def;
	}
	return error;
}

template<typename IntegerType>
DWORD getINIIntegerDefTemplate(const String& iniPath, const TCHAR *const section, const TCHAR *const key,
	const IntegerType def, IntegerType& outInteger)
{
	return getINIIntegerDefTemplate(iniPath, section, key, def, outInteger, LogPrint);
}

template<typename IntegerType>
DWORD setINIIntegerTemplate(const String& iniPath, const TCHAR *const section, const TCHAR *const key,
	const IntegerType toSet)
{
	const String toSetStr = integerToDecimalStrTemplate<String>(toSet);
	if (!WritePrivateProfileString(section, key, toSetStr.c_str(), iniPath.c_str())) {
		PrintT(TEXT("[!][InfinityLoaderCommon.dll] setINIIntegerTemplate() - Failed to set [%s].%s = %s\n"), section, key, toSetStr.c_str());
		return GetLastError();
	}
	return ERROR_SUCCESS;
}
