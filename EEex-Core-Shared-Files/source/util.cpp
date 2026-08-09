
#include "infinity_loader_common_api.h"

#include <Windows.h>
#include <winternl.h>

typedef struct _THREAD_BASIC_INFORMATION {
	NTSTATUS ExitStatus;
	PVOID TebBaseAddress;
	CLIENT_ID ClientId;
	KAFFINITY AffinityMask;
	KPRIORITY Priority;
	KPRIORITY BasePriority;
} THREAD_BASIC_INFORMATION, *PTHREAD_BASIC_INFORMATION;

uintptr_t getStackBase() {

	THREAD_BASIC_INFORMATION basicInfo;

	NtQueryInformationThread(GetCurrentThread(),
		static_cast<THREADINFOCLASS>(0), // Undocumented ThreadBasicInformation
		&basicInfo,
		sizeof(THREAD_BASIC_INFORMATION),
		NULL);

	const NT_TIB& tib = *reinterpret_cast<NT_TIB*>(basicInfo.TebBaseAddress);
	return reinterpret_cast<uintptr_t>(tib.StackBase);
}
