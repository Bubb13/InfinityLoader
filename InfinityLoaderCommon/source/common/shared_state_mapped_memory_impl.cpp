
// `shared_state_mapped_memory_types.h` or `shared_state_mapped_memory_api.h` should be included before this file.

#if !(defined SHARED_MEMORY_DLL_HOST || defined SHARED_MEMORY_DLL)
	HANDLE hSharedStateMappedMemory;
	SharedStateMappedMemory sharedStateMappedMemory;
#endif
