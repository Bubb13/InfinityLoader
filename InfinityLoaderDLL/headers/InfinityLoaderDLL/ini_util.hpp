
#pragma once

#include "infinity_loader_common_api.h"

/////////////
// Globals //
/////////////

extern bool attemptUseCached;

///////////////
// Functions //
///////////////

DWORD loadExeNameForPatterns();

DWORD findINICategoryPattern(void* sectionPtr, DWORD sectionSize, const String& iniPath,
	const String& originalINICategoryName, PatternValueHandle& valueHandleOut);

////////////////////////
// Template Functions //
////////////////////////

template<typename AddressType>
bool setSinglePatternValue(const String& name, AddressType address, PatternValueHandle& patternHandleOut)
{
	if (sharedState().GetOrCreatePatternValue(name, PatternValueType::SINGLE, patternHandleOut))
	{
		FPrintT(TEXT("[!][InfinityLoaderDLL.dll] setSinglePatternValue() - [%s].Type must be SINGLE\n"), name.c_str());
		return false;
	}

	sharedState().SetSinglePatternValue(patternHandleOut, (uintptr_t)address);
	return true;
}

template<typename AddressType>
bool setSinglePatternValue(const String& name, AddressType address)
{
	PatternValueHandle patternHandle;
	return setSinglePatternValue(name, address, patternHandle);
}
