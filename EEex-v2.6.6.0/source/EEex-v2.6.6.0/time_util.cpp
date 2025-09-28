
#include "Windows.h"

//---------------------------//
//          Globals          //
//---------------------------//

long long numTicksInMicrosecond;
long long initTime;

//-----------------------------//
//          Functions          //
//-----------------------------//

DWORD getHighestRefreshRate()
{
    DWORD highestRefreshRate = 0;

    DISPLAY_DEVICE displayDevice;
    displayDevice.cb = sizeof(DISPLAY_DEVICE);

    DEVMODE devMode;
    devMode.dmSize = sizeof(DEVMODE);
    devMode.dmDriverExtra = 0;

    for (DWORD deviceIndex = 0; EnumDisplayDevices(NULL, deviceIndex, &displayDevice, 0); ++deviceIndex)
    {
        if ((displayDevice.StateFlags & DISPLAY_DEVICE_ACTIVE) == 0)
        {
            continue;
        }

        if (!EnumDisplaySettings(displayDevice.DeviceName, ENUM_CURRENT_SETTINGS, &devMode))
        {
            continue;
        }

        if (devMode.dmDisplayFrequency > highestRefreshRate)
        {
            highestRefreshRate = devMode.dmDisplayFrequency;
        }
    }

    return highestRefreshRate;
}

long long getInitTime()
{
	return initTime;
}

long long getTime()
{
	LARGE_INTEGER result;
	QueryPerformanceCounter(&result);
	return result.QuadPart / numTicksInMicrosecond;
}

void initTimeUtil()
{
	LARGE_INTEGER result;
	QueryPerformanceFrequency(&result);
	numTicksInMicrosecond = result.QuadPart / 1000000;
	initTime = getTime();
}
