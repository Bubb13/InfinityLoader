
#pragma once

#include "dll_api.h"
#include "opaque_object_api.h"

#include <Windows.h>

class SharedStateMappedMemory {
private:
	void* imp;
public:
	OpaqueObjectBoilerplateAPIDef(SharedStateMappedMemory)
	// Non-Static Functions
	IMPORT DWORD& ParentProcessId();
	IMPORT HANDLE& StdIn();
	IMPORT HANDLE& StdOut();
	IMPORT HANDLE& StdErr();
	IMPORT bool& Debug();
	IMPORT bool& Pause();
	IMPORT bool& ProtonCompatibility();
};
