
#include "infinity_loader_common_api.h"

///////////////
// Functions //
///////////////

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
