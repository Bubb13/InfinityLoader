
#include <iostream>

#include "infinity_loader_common_api.h"

/////////////
// Globals //
/////////////

String dbPath;
String exePath;
String exeName;
String iniPath;
String workingFolder;
StringA workingFolderA;

//////////
// Code //
//////////

bool inheritedConsole() {
	HWND consoleWnd = GetConsoleWindow();
	DWORD dwProcessId;
	GetWindowThreadProcessId(consoleWnd, &dwProcessId);
	return GetCurrentProcessId() != dwProcessId;
}

void hideConsole()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
}

void showConsole()
{
	ShowWindow(GetConsoleWindow(), SW_SHOW);
}

/*DWORD GetThreadStartAddress(HANDLE hThread)
{
	NTSTATUS ntStatus;
	HANDLE hDupHandle;
	DWORD dwStartAddress;

	HANDLE hCurrentProcess = GetCurrentProcess();
	if (!DuplicateHandle(hCurrentProcess, hThread, hCurrentProcess, &hDupHandle, THREAD_QUERY_INFORMATION, FALSE, 0)) {
		return 0;
	}

	ntStatus = NtQueryInformationThread(hDupHandle, (THREADINFOCLASS)9, &dwStartAddress, sizeof(DWORD), NULL);
	CloseHandle(hDupHandle);
	if (ntStatus != 0)
		return 0;

	return dwStartAddress;
}*/

template<typename CharType>
DWORD writeProcessString(HANDLE hProcess, const CharType* str, uintptr_t& memoryPtr) {

	size_t strSizeBytes;
	if constexpr (std::is_same<CharType, char>::value) {
		strSizeBytes = (sizeof(char) + 1) * strlen(str);
	}
	else {
		static_assert(std::is_same<CharType, TCHAR>::value, "Bad character type");
		strSizeBytes = (sizeof(CharType) + 1) * strlenT(str);
	}

	LPVOID allocPtr = VirtualAllocEx(hProcess, NULL, strSizeBytes, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (!allocPtr) {
		DWORD lastError = GetLastError();
		Print("[!] VirtualAllocEx failed (%d).\n", lastError);
		return lastError;
	}

	if (!WriteProcessMemory(hProcess, allocPtr, str, strSizeBytes, NULL)) {
		DWORD lastError = GetLastError();
		Print("[!] WriteProcessMemory failed (%d).\n", lastError);
		return lastError;
	}

	memoryPtr = reinterpret_cast<uintptr_t>(allocPtr);
	return 0;
}

DWORD patchMainThread(HANDLE hProcess, HANDLE hThread) {

	CONTEXT context;
	memset(&context, 0, sizeof(CONTEXT));
	context.ContextFlags = CONTEXT_INTEGER;
	if (!GetThreadContext(hThread, &context)) {
		DWORD lastError = GetLastError();
		Print("[!] GetThreadContext failed (%d).\n", lastError);
		return lastError;
	}

#if defined(_WIN64)
	DWORD64& threadStart = context.Rcx;
#else
	DWORD& threadStart = context.Eax;
#endif

	//////////////////////
	// Write DLL string //
	//////////////////////

	uintptr_t dllStrMemory;
	if (DWORD lastError = writeProcessString<TCHAR>(hProcess, TEXT("InfinityLoaderDLL.dll"), dllStrMemory)) {
		return lastError;
	}

	////////////////
	// Write code //
	////////////////

	LPVOID codeMem = VirtualAllocEx(hProcess, NULL, 1024, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (!codeMem) {
		DWORD lastError = GetLastError();
		Print("[!] VirtualAllocEx failed (%d).\n", lastError);
		return lastError;
	}

	AssemblyWriter writer = AssemblyWriter::Create();
	writer.SetLocation(reinterpret_cast<uintptr_t>(codeMem));

	///////////////////////
	// Align Stack to 16 //
	///////////////////////

	writer.AlignStackAndMakeShadowSpace();

	///////////////////////////////////////////////
	// Call LoadLibrary("InfinityLoaderDLL.dll") //
	///////////////////////////////////////////////

	writer.WriteArgImmediate32(0, static_cast<__int32>(dllStrMemory));
	writer.CallToAddressFar(reinterpret_cast<uintptr_t>(LoadLibrary));

	///////////////////////////////
	// Write SharedMemory struct //
	///////////////////////////////

	HANDLE hChildMappedMemory;
	DuplicateHandle(GetCurrentProcess(), mappedMemoryHandle(), hProcess, &hChildMappedMemory, 0, false, DUPLICATE_SAME_ACCESS);

	parentProcessId() = GetCurrentProcessId();
	stdIn() = GetStdHandle(STD_INPUT_HANDLE);
	stdOut() = GetStdHandle(STD_OUTPUT_HANDLE);
	stdErr() = GetStdHandle(STD_ERROR_HANDLE);

	///////////////////////////////////////
	// Call InfinityLoaderDLL.dll Init() //
	///////////////////////////////////////

	uintptr_t dllInitStrMem;
	if (DWORD lastError = writeProcessString<char>(hProcess, "Init", dllInitStrMem)) {
		return lastError;
	}

	writer.WriteArgImmediate32(1, static_cast<__int32>(dllInitStrMem));

#if defined(_WIN64)
	writer.WriteBytesToBuffer(3, 0x48, 0x89, 0xC1); // mov rcx,rax
#else
	writer.WriteBytesToBuffer(1, 0x50); // push rax
#endif

	writer.CallToAddressFar(reinterpret_cast<uintptr_t>(GetProcAddress));
	// Only the lower 32 bits of a HANDLE are significant
	// https://learn.microsoft.com/en-us/windows/win32/winprog64/interprocess-communication
	writer.WriteArgImmediate32(0, static_cast<__int32>(reinterpret_cast<uintptr_t>(hChildMappedMemory)));
	writer.WriteBytesToBuffer(2, 0xFF, 0xD0); // call eax/rax

	///////////////////
	// Pop Alignment //
	///////////////////

	writer.UndoAlignAndShadowSpace();

	/////////////////////////////////////////////////////////
	// JMP (Return to main thread's normal starting point) //
	/////////////////////////////////////////////////////////

	writer.JmpToAddressFar(threadStart);

	//writer.printBuffer();
	if (!WriteProcessMemory(hProcess, codeMem, writer.GetBuffer(), writer.GetSize(), NULL)) {
		DWORD lastError = GetLastError();
		Print("[!] WriteProcessMemory failed (%d).\n", lastError);
		return lastError;
	}

	/////////////////////////
	// Change thread Start //
	/////////////////////////

#if defined(_WIN64)
	threadStart = reinterpret_cast<DWORD64>(codeMem);
#else
	threadStart = reinterpret_cast<DWORD>(codeMem);
#endif

	if (!SetThreadContext(hThread, &context)) {
		DWORD lastError = GetLastError();
		Print("[!] SetThreadContext failed (%d).\n", lastError);
		return lastError;
	}

	return 0;
}

/*DWORD remoteThread(HANDLE hProcess) {

	//////////////////////
	// Write DLL string //
	//////////////////////

	const TCHAR* dllStr = TEXT("InfinityLoaderDLL.dll");
	size_t dllStrSizeBytes = (sizeof(TCHAR) + 1) * strlenT(dllStr);

	LPVOID dllStrMemory = VirtualAllocEx(hProcess, NULL, dllStrSizeBytes, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (!dllStrMemory) {
		DWORD lastError = GetLastError();
		printf("[!] VirtualAllocEx failed (%d).\n", lastError);
		return lastError;
	}

	if (!WriteProcessMemory(hProcess, dllStrMemory, dllStr, dllStrSizeBytes, NULL)) {
		DWORD lastError = GetLastError();
		printf("[!] WriteProcessMemory failed (%d).\n", lastError);
		return lastError;
	}

	HANDLE hRemoteThread = CreateRemoteThread(hProcess, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibrary, dllStrMemory, NULL, NULL);
	if (!hRemoteThread) {
		DWORD lastError = GetLastError();
		printf("[!] CreateRemoteThread failed (%d).\n", lastError);
		return lastError;
	}

	if (WaitForSingleObject(hRemoteThread, INFINITE) == WAIT_FAILED) {
		DWORD lastError = GetLastError();
		printf("[!] WaitForSingleObject failed (%d).\n", lastError);
		return lastError;
	}

	return 0;
}*/

DWORD startGame() {

	STARTUPINFO startupInfo{};
	startupInfo.cb = sizeof(STARTUPINFO);

	PROCESS_INFORMATION processInfo{};
	DWORD lastError = ERROR_SUCCESS;

	HANDLE hStdInput = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdError = GetStdHandle(STD_ERROR_HANDLE);

	if (debug()) {
		Print("[?] Parent hStdInput: %d\n", hStdInput);
		Print("[?] Parent hStdOutput: %d\n", hStdOutput);
		Print("[?] Parent hStdError: %d\n", hStdError);
	}

	if (!CreateProcess(exePath.c_str(), NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &startupInfo, &processInfo)) {
		lastError = GetLastError();
		PrintT(TEXT("[!] CreateProcess failed attempting to start \"%s\" (%d).\n"), exePath.c_str(), lastError);
		return lastError;
	}

	if (lastError = GetINIBoolDef(iniPath, TEXT("General"), TEXT("Pause"), false, pause())) {
		goto errorFinally;
	}

	if (pause()) {
		MessageBox(NULL, TEXT("Pause"), TEXT("InfinityLoader"), MB_ICONINFORMATION);
	}

	if (lastError = patchMainThread(processInfo.hProcess, processInfo.hThread)) {
		goto errorFinally;
	}

	//if (DWORD lastError = remoteThread(processInfo.hProcess)) {
	//	return lastError;
	//}

	if (ResumeThread(processInfo.hThread) == -1) {
		lastError = GetLastError();
		Print("[!] ResumeThread failed (%d).\n", lastError);
		goto errorFinally;
	}

	if (WaitForSingleObject(processInfo.hProcess, INFINITE) == WAIT_FAILED) {
		lastError = GetLastError();
		Print("[!] WaitForSingleObject failed (%d).\n", lastError);
		goto errorFinally;
	}

	if (!CloseHandle(processInfo.hProcess)) {
		lastError = GetLastError();
		Print("[!] CloseHandle failed (%d).\n", lastError);
	}

	if (!CloseHandle(processInfo.hThread)) {
		lastError = GetLastError();
		Print("[!] CloseHandle failed (%d).\n", lastError);
	}

	return lastError;

errorFinally:;

	TerminateProcess(processInfo.hProcess, 0);

	if (processInfo.hProcess) {
		CloseHandle(processInfo.hProcess);
	}

	if (processInfo.hThread) {
		CloseHandle(processInfo.hThread);
	}

	return lastError;
}

DWORD init() {
	TryRetErr( CreateMappedMemory(mappedMemoryHandle(), mappedMemory()) )
	TryRetErr( InitPaths(dbPath, exePath, exeName, iniPath, workingFolder, workingFolderA) )
	TryRetErr( GetINIBoolDef(iniPath, TEXT("General"), TEXT("Debug"), false, debug()) )
	TryRetErr( GetINIBoolDef(iniPath, TEXT("General"), TEXT("ProtonCompatibility"), false, protonCompatibility()) )
	TryElseRetErr( UnbufferCrtStreams(), Print("[!] UnbufferCrtStreams failed (%d).\n", error) )
	TryElseRetErr( InitFPrint(), Print("[!] InitFPrint failed (%d).\n", error) )
	return ERROR_SUCCESS;
}

int exceptionFilter(unsigned int code, _EXCEPTION_POINTERS* pointers) {
	String dmpLocation = WriteDump(workingFolder, pointers);
	MessageBoxFormat(TEXT("InfinityLoader"), MB_ICONERROR, TEXT("Unhandled exception 0x%X. Crash log saved to:\n\n%s\n\nThis should never happen. Please report to Bubb."), code, dmpLocation.c_str());
	exit(code);
}

int main(int argc, char* argv[]) {

	__try {

		if (!inheritedConsole()) {
			hideConsole();
		}

		if (init()) {
			goto error;
		}

		if (startGame()) {
		error:;
			showConsole();
			Print("Press any key to continue . . .\n");
			std::cin.get();
		}
	}
	__except (exceptionFilter(GetExceptionCode(), GetExceptionInformation())) {}

	return 0;
}
