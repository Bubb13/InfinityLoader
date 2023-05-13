
#pragma once

#include <Windows.h>

struct SharedIO {
	DWORD parentProcessId;
	HANDLE hStdIn;
	HANDLE hStdOut;
	HANDLE hStdErr;
};

struct SharedOptions {
	bool debug;
	bool pause;
	bool protonCompatibility;
};

struct SharedMemory {
	SharedIO io;
	SharedOptions options;
};
