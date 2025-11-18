
#pragma once

#include <Windows.h>

///////////////
// Functions //
///////////////

void setSegmentProtection(const char* const segmentName, const DWORD protectionFlags);

void disableCodeProtection();
void enableCodeProtection();
