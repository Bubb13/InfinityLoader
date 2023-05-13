
#include "template_functions.h"
#include "dll_api.h"

template<>
bool decimalStrToIntegerTemplate<bool>(const String& decimalStr, bool& result) {

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
			result = entry.second != 0;
			return true;
		}
	}

	return false;
}

EXPORT bool DecStrToBool(const String& decimalStr, bool& result) {
	return decimalStrToIntegerTemplate<bool>(decimalStr, result);
}

EXPORT bool DecStrToInt(const String& decimalStr, int& accumulator) {
	return decimalStrToIntegerTemplate<int>(decimalStr, accumulator);
}

EXPORT bool DecStrToIntPtr(const String& decimalStr, intptr_t& accumulator) {
	return decimalStrToIntegerTemplate<intptr_t>(decimalStr, accumulator);
}

EXPORT bool GetINILongLong(const String& iniPath, const TCHAR *const section,
	const TCHAR *const key, long long& outInteger, bool& filled)
{
	return getINIIntegerTemplate<long long>(iniPath, section, key, outInteger, filled);
}

EXPORT bool GetINIBoolDef(const String& iniPath, const TCHAR *const section,
	const TCHAR *const key, const bool def, bool& outInteger)
{
	return getINIIntegerDefTemplate<bool>(iniPath, section, key, def, outInteger);
}

EXPORT bool GetINIIntDef(const String& iniPath, const TCHAR *const section,
	const TCHAR *const key, const int def, int& outInteger)
{
	return getINIIntegerDefTemplate<int>(iniPath, section, key, def, outInteger);
}

EXPORT bool GetINIIntPtrDef(const String& iniPath, const TCHAR *const section,
	const TCHAR *const key, const intptr_t def, intptr_t& outInteger)
{
	return getINIIntegerDefTemplate<intptr_t>(iniPath, section, key, def, outInteger);
}

EXPORT bool GetINIUIntPtrDef(const String& iniPath, const TCHAR *const section,
	const TCHAR *const key, const uintptr_t def, uintptr_t& outInteger)
{
	return getINIIntegerDefTemplate<uintptr_t>(iniPath, section, key, def, outInteger);
}

EXPORT DWORD SetINIIntPtr(const String& iniPath, const TCHAR *const section,
	const TCHAR *const key, const intptr_t toSet)
{
	return setINIIntegerTemplate<intptr_t>(iniPath, section, key, toSet);
}

EXPORT DWORD SetINILongLong(const String& iniPath, const TCHAR *const section,
	const TCHAR *const key, const long long toSet)
{
	return setINIIntegerTemplate<long long>(iniPath, section, key, toSet);
}

EXPORT StringA IntToDecStrA(const int integer) {
	return integerToDecimalStrTemplate<StringA, int>(integer);
}

EXPORT StringA PtrDiffToDecStrA(const ptrdiff_t integer) {
	return integerToDecimalStrTemplate<StringA, ptrdiff_t>(integer);
}
