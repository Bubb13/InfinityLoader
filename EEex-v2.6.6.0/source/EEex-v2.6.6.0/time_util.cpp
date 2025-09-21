
#include "Windows.h"

//---------------------------//
//          Globals          //
//---------------------------//

long long numTicksInMicrosecond;
long long initTime;

//-----------------------------//
//          Functions          //
//-----------------------------//

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
