
#include "infinity_loader_common.h"
#include "shared_state_mapped_memory_types.h"
#include "shared_state_mapped_memory_impl.cpp"

/////////////////////////////
// SharedStateMappedMemory //
/////////////////////////////

OpaqueObjectBoilerplateImp(SharedStateMappedMemory, SharedStateMappedMemoryData)

DWORD SharedStateMappedMemory::Create(HANDLE& mappedMemoryHandleOut, SharedStateMappedMemory& mappedMemoryOut) {

	DWORD lastError = ERROR_SUCCESS;

	SharedStateMappedMemory toReturn {

		[&]() -> SharedStateMappedMemoryData* {

			constexpr std::size_t sharedMemSize = sizeof(SharedStateMappedMemoryData);
			HANDLE mappedHandle = CreateFileMapping(
				INVALID_HANDLE_VALUE,
				0,                    // Default security
				PAGE_READWRITE,
#ifdef _WIN64
				sharedMemSize >> 32,
#else
				0,
#endif
				sharedMemSize & 0xFFFFFFFF,
				nullptr               // No name
			);

			if (mappedHandle == NULL) {
				lastError = GetLastError();
				FPrint("[!][InfinityLoaderCommon.dll] SharedStateMappedMemory::Create() - CreateFileMapping() failed (%d)\n", lastError);
				return nullptr;
			}

			mappedMemoryHandleOut = mappedHandle;

			SharedStateMappedMemoryData* mappedMemory = reinterpret_cast<SharedStateMappedMemoryData*>(MapViewOfFile(
				mappedHandle,
				FILE_MAP_ALL_ACCESS,
				0,                   // Offset to map (high)
				0,                   // Offset to map (low)
				0                    // Number of bytes to map (0 = to end of file)
			));

			if (mappedMemory == nullptr) {
				lastError = GetLastError();
				FPrint("[!][InfinityLoaderCommon.dll] SharedStateMappedMemory::Create() - MapViewOfFile() failed (%d)\n", lastError);
				return nullptr;
			}

			return mappedMemory;
		},
		[&](SharedStateMappedMemoryData* data) {
			UnmapViewOfFile(data);
		},
		OpaqueObject::AllocMode::NOW
	};

	if (lastError == ERROR_SUCCESS) {
		mappedMemoryOut = std::move(toReturn);
	}

	return lastError;
}

DWORD SharedStateMappedMemory::CreateFromHandle(HANDLE mappedMemoryHandle, SharedStateMappedMemory& mappedMemoryOut) {

	DWORD lastError = ERROR_SUCCESS;

	SharedStateMappedMemory toReturn {

		[&]() -> SharedStateMappedMemoryData* {

			SharedStateMappedMemoryData *const mappedMemory = reinterpret_cast<SharedStateMappedMemoryData*>(
				MapViewOfFile(mappedMemoryHandle,
					FILE_MAP_ALL_ACCESS,
					0,                   // Offset to map (high)
					0,                   // Offset to map (low)
					0                    // Number of bytes to map (0 = to end of file)
				)
			);

			if (mappedMemory == nullptr) {
				lastError = GetLastError();
				MessageBoxFormatA("InfinityLoaderCommon.dll", MB_ICONERROR, "[!] SharedStateMappedMemory::CreateFromHandle() - MapViewOfFile() failed (%d)", lastError);
				return nullptr;
			}

			return mappedMemory;
		},
		[&](SharedStateMappedMemoryData* data) {
			UnmapViewOfFile(data);
		},
		OpaqueObject::AllocMode::NOW
	};

	if (lastError == ERROR_SUCCESS) {
		mappedMemoryOut = std::move(toReturn);
	}

	return lastError;
}

EXPORT DWORD& SharedStateMappedMemory::ParentProcessId() {
	return data()->io.parentProcessId;
}

EXPORT HANDLE& SharedStateMappedMemory::StdIn() {
	return data()->io.hStdIn;
}

EXPORT HANDLE& SharedStateMappedMemory::StdOut() {
	return data()->io.hStdOut;
}

EXPORT HANDLE& SharedStateMappedMemory::StdErr() {
	return data()->io.hStdErr;
}

EXPORT bool& SharedStateMappedMemory::Debug() {
	return data()->options.debug;
}

EXPORT bool& SharedStateMappedMemory::Pause() {
	return data()->options.pause;
}

EXPORT bool& SharedStateMappedMemory::ProtonCompatibility() {
	return data()->options.protonCompatibility;
}
