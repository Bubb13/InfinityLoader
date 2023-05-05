
#include "shared_memory_dll.h"

#ifdef SHARED_MEMORY_DLL_HOST
SharedDLLMemory sharedDLLHost;
SharedDLLMemory* sharedDLL = &sharedDLLHost;
#else
SharedDLLMemory* sharedDLL;
#endif
