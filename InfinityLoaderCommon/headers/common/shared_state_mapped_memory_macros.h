
#pragma once

// `shared_state_mapped_memory_types.h` or `shared_state_mapped_memory_api.h` should be included before this file.

/////////////////////////
// Globals and Defines //
/////////////////////////

#if defined SHARED_MEMORY_DLL_HOST || defined SHARED_MEMORY_DLL
	extern SharedState sharedState;
	#define mappedMemory() sharedState.MappedMemory()
#else
	extern HANDLE hSharedStateMappedMemory;
	extern SharedStateMappedMemory sharedStateMappedMemory;
	#define mappedMemoryHandle() hSharedStateMappedMemory
	#define mappedMemory() sharedStateMappedMemory
#endif

#define parentProcessId() mappedMemory().ParentProcessId()
#define stdIn() mappedMemory().StdIn()
#define stdOut() mappedMemory().StdOut()
#define stdErr() mappedMemory().StdErr()
#define debug() mappedMemory().Debug()
#define pause() mappedMemory().Pause()
#define protonCompatibility() mappedMemory().ProtonCompatibility()
