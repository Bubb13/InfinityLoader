
#pragma once

#include <mutex>

#include "dll_api.h"
#include "opaque_object.h"

#include <Windows.h>

class SharedIO {
private:
	friend class SharedStateMappedMemory;
	DWORD parentProcessId;
	HANDLE hStdIn;
	HANDLE hStdOut;
	HANDLE hStdErr;
};

class SharedOptions {
private:
	friend class SharedStateMappedMemory;
	bool debug;
	bool pause;
	bool protonCompatibility;
};

class SharedStateMappedMemoryData {
private:
	friend class SharedStateMappedMemory;
	SharedIO io;
	SharedOptions options;
};

class SharedStateMappedMemory : OpaqueObject::Obj<SharedStateMappedMemoryData> {
public:
	OpaqueObjectBoilerplateDef(SharedStateMappedMemory)
	// Static Functions
	static DWORD Create(HANDLE& mappedMemoryHandleOut, SharedStateMappedMemory& mappedMemoryOut);
	static DWORD CreateFromHandle(HANDLE mappedMemoryHandle, SharedStateMappedMemory& mappedMemoryOut);
	// Non-Static Functions
	EXPORT DWORD& ParentProcessId();
	EXPORT HANDLE& StdIn();
	EXPORT HANDLE& StdOut();
	EXPORT HANDLE& StdErr();
	EXPORT bool& Debug();
	EXPORT bool& Pause();
	EXPORT bool& ProtonCompatibility();
};

/////////////////////////
// Globals and Defines //
/////////////////////////

extern HANDLE hSharedStateMappedMemory;
extern SharedStateMappedMemory sharedStateMappedMemory;

#define mappedMemoryHandle() hSharedStateMappedMemory
#define mappedMemory() sharedStateMappedMemory

#define parentProcessId() mappedMemory().ParentProcessId()
#define stdIn() mappedMemory().StdIn()
#define stdOut() mappedMemory().StdOut()
#define stdErr() mappedMemory().StdErr()
#define debug() mappedMemory().Debug()
#define pause() mappedMemory().Pause()
#define protonCompatibility() mappedMemory().ProtonCompatibility()
