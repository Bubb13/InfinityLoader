
#include <algorithm>
#include <cwctype>

#include "infinity_loader_common_api.h"

#include <Windows.h>
#include <DbgHelp.h>
#include <Psapi.h>

//////////////////////
// Static Functions //
//////////////////////

static StringA bufferToLowerCopy(const char *const str)
{
	StringA lower = str;

	std::transform(lower.begin(), lower.end(), lower.begin(), [](const unsigned char c)
	{
		return std::tolower(c);
	});

	return lower;
}

static StringW bufferToLowerCopy(const wchar_t *const str)\
{
	StringW lower = str;

	std::transform(lower.begin(), lower.end(), lower.begin(), [](const wchar_t c)
	{
		return std::towlower(c);
	});

	return lower;
}

static void processModuleName(const HMODULE module, const std::function<void(TCHAR*, size_t)> processFunc)
{
	DWORD pathSize;

	RunWithGrowingBuffer<TCHAR>
	(
		[&](TCHAR *const buffer, const size_t bufferSize)
		{
			pathSize = GetModuleFileName(module, buffer, static_cast<DWORD>(bufferSize));
			if (pathSize == bufferSize) return TryFillBufferResult::GROW;
			return TryFillBufferResult::DONE;
		},
		[&](TCHAR *const buffer, const size_t bufferSize)
		{
			size_t i = pathSize;

			while (i != 0)
			{
				if (buffer[--i] == '\\')
				{
					processFunc(&buffer[i + 1], pathSize - i - 1);
					return;
				}
			}
		}
	);
}

static bool sectionNameEquals(const BYTE *const sectionName, const char *const comparison)
{
	const char* s1 = reinterpret_cast<const char*>(sectionName);
	const char* s2 = comparison;

	for (int i = 0; i < IMAGE_SIZEOF_SHORT_NAME; ++i, ++s1, ++s2)
	{
		const char c1 = *s1;

		if (c1 != *s2)
		{
			return false;
		}
		else if (c1 == '\0')
		{
			return true;
		}
	}

	return *s2 == '\0';
}

static void sizedBufferToLower(char *const buffer, const size_t size)
{
	std::transform(buffer, buffer + size, buffer, [](const unsigned char c)
	{
		return static_cast<char>(std::tolower(c));
	});
}

static void sizedBufferToLower(wchar_t *const buffer, const size_t size)
{
	std::transform(buffer, buffer + size, buffer, [](const wchar_t c)
	{
		return std::towlower(c);
	});
}

///////////////
// Functions //
///////////////

HMODULE findLoadedModule(const TCHAR *const lookingForName)
{
	const String lookingForNameLower = bufferToLowerCopy(lookingForName);
	const HANDLE process = GetCurrentProcess();

	HMODULE toReturn = NULL;
	DWORD needed;

	RunWithGrowingBuffer<HMODULE>
	(
		[&](HMODULE *const buffer, const size_t bufferSize)
		{
			EnumProcessModules(process, buffer, static_cast<DWORD>(bufferSize), &needed);
			if (needed > bufferSize) return TryFillBufferResult::GROW;
			return TryFillBufferResult::DONE;
		},
		[&](const size_t bufferSize)
		{
			return needed;
		},
		[&](const HMODULE *const buffer, const size_t bufferSize)
		{
			const size_t filledModules = needed / sizeof(HMODULE);

			for (size_t i = 0; i < filledModules; ++i)
			{
				const HMODULE module = buffer[i];

				processModuleName(module, [&](TCHAR *const moduleName, const size_t nameSize)
				{
					sizedBufferToLower(moduleName, nameSize);

					if (strcmpT(lookingForNameLower.c_str(), moduleName) == 0)
					{
						toReturn = module;
					}
				});

				if (toReturn != NULL)
				{
					break;
				}
			}
		}
	);

	return toReturn;
}

bool findSectionInfo(HMODULE module, const char* sectionName, void*& sectionPointer, DWORD& sectionSize)
{
	byte *const dllImageBase = reinterpret_cast<byte*>(module);

	const IMAGE_NT_HEADERS *const pNtHdr = ImageNtHeader(dllImageBase);
	const WORD numSections = pNtHdr->FileHeader.NumberOfSections;

	const IMAGE_SECTION_HEADER* pCurSectionHdr = reinterpret_cast<const IMAGE_SECTION_HEADER*>(pNtHdr + 1);

	for (int i = 0; i < numSections; ++i, ++pCurSectionHdr)
	{
		if (sectionNameEquals(pCurSectionHdr->Name, sectionName))
		{
			sectionPointer = dllImageBase + pCurSectionHdr->VirtualAddress;
			sectionSize = pCurSectionHdr->Misc.VirtualSize;
			return true;
		}
	}

	return false;
}

void setSegmentProtection(const char *const segmentName, const DWORD protectionFlags)
{
	TryRetTruthy( sharedState().LoadSegmentInfo(segmentName) )

	void* sectionPtr;
	DWORD sectionSize;

	if (sharedState().GetSegmentPointerAndSize(segmentName, sectionPtr, sectionSize))
	{
		FPrint("[!][InfinityLoaderDLL.dll] setSegmentProtection() - Failed to fetch \"%s\" pointer and size\n", segmentName);
		return;
	}

	DWORD temp;
	VirtualProtect(sectionPtr, sectionSize, protectionFlags, &temp);
}

void disableCodeProtection()
{
	setSegmentProtection(".text", PAGE_EXECUTE_READWRITE);
}

void enableCodeProtection()
{
	setSegmentProtection(".text", PAGE_EXECUTE_READ);
}
