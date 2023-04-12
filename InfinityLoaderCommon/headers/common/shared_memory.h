
#pragma once

#include <Windows.h>

struct DllInitArguments {
	DWORD parentProcessId;
	HANDLE hStdIn;
	HANDLE hStdOut;
	HANDLE hStdErr;
};

struct SharedMemory {
	DllInitArguments dllInitArguments;
};
