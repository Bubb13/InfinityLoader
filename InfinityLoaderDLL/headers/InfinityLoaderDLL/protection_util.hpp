
#pragma once

#include <Windows.h>

///////////////
// Functions //
///////////////

HMODULE findLoadedModule(const TCHAR *const lookingForName);
bool findSectionInfo(HMODULE module, const char* sectionName, void*& sectionPointer, DWORD& sectionSize);
void setSegmentProtection(const char* const segmentName, const DWORD protectionFlags);

void disableCodeProtection();
void enableCodeProtection();
