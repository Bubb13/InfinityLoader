
#include "InfinityLoaderCommon.h"

#include <iostream>
#include <thread>

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

DWORD patchMainThread(HANDLE hProcess, HANDLE hThread) {

	CONTEXT context;
	memset(&context, 0, sizeof(CONTEXT));
	context.ContextFlags = CONTEXT_INTEGER;
	if (!GetThreadContext(hThread, &context)) {
		DWORD lastError = GetLastError();
		printf("[!] GetThreadContext failed (%d).\n", lastError);
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

	intptr_t dllStrMemory;
	if (DWORD lastError = writeProcessString(hProcess, TEXT("InfinityLoaderDLL.dll"), dllStrMemory)) {
		return lastError;
	}

	////////////////
	// Write code //
	////////////////

	LPVOID codeMem = VirtualAllocEx(hProcess, NULL, 1024, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (!codeMem) {
		DWORD lastError = GetLastError();
		printf("[!] VirtualAllocEx failed (%d).\n", lastError);
		return lastError;
	}

	unsigned char codeBuff[1024];
	AssemblyWriter writer{ codeBuff };
	writer.setLocation(reinterpret_cast<intptr_t>(codeMem));

	///////////////////////
	// Align Stack to 16 //
	///////////////////////

	writer.alignStackAndMakeShadowSpace();

	///////////////////////////////////////////////
	// Call LoadLibrary("InfinityLoaderDLL.dll") //
	///////////////////////////////////////////////

	writer.writeArgImmediate32(static_cast<__int32>(dllStrMemory), 0);
	writer.callToAddressFar(reinterpret_cast<intptr_t>(LoadLibrary));

	///////////////////////////////////////
	// Call InfinityLoaderDLL.dll Init() //
	///////////////////////////////////////

	intptr_t dllInitStrMem;
	if (DWORD lastError = writeProcessStringA(hProcess, "Init", dllInitStrMem)) {
		return lastError;
	}

	writer.writeArgImmediate32(static_cast<__int32>(dllInitStrMem), 1);

#if defined(_WIN64)
	writer.writeBytesToBuffer(3, 0x48, 0x89, 0xC1);
#else
	writer.writeBytesToBuffer(1, 0x50);
#endif

	writer.callToAddressFar(reinterpret_cast<intptr_t>(GetProcAddress));

	writer.writeArgImmediate32(reinterpret_cast<int>(GetStdHandle(STD_ERROR_HANDLE)), 3);
	writer.writeArgImmediate32(reinterpret_cast<int>(GetStdHandle(STD_OUTPUT_HANDLE)), 2);
	writer.writeArgImmediate32(reinterpret_cast<int>(GetStdHandle(STD_INPUT_HANDLE)), 1);
	writer.writeArgImmediate32(GetCurrentProcessId(), 0);
	writer.writeBytesToBuffer(2, 0xFF, 0xD0);

	///////////////////
	// Pop Alignment //
	///////////////////

	writer.undoAlignAndShadowSpace();

	/////////////////////////////////////////////////////////
	// JMP (Return to main thread's normal starting point) //
	/////////////////////////////////////////////////////////

	writer.jmpToAddressFar(threadStart);

	//writer.printBuffer();
	if (!WriteProcessMemory(hProcess, codeMem, codeBuff, sizeof(codeBuff), NULL)) {
		DWORD lastError = GetLastError();
		printf("[!] WriteProcessMemory failed (%d).\n", lastError);
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
		printf("[!] SetThreadContext failed (%d).\n", lastError);
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

	initPaths();

	String exePath;
	if (DWORD lastError = getExePath(nullptr, exePath)) {
		return lastError;
	}

	STARTUPINFO startupInfo{};
	startupInfo.cb = sizeof(STARTUPINFO);

	PROCESS_INFORMATION processInfo{};
	DWORD lastError = ERROR_SUCCESS;

	if (!CreateProcess(exePath.c_str(), NULL, NULL, NULL, false, CREATE_SUSPENDED, NULL, NULL, &startupInfo, &processInfo)) {
		lastError = GetLastError();
		printfT(TEXT("[!] CreateProcess failed attempting to start \"%s\" (%d).\n"), exePath.c_str(), lastError);
		return lastError;
	}

	intptr_t bPause;
	if (lastError = GetINIIntegerDef<intptr_t>(iniPath, TEXT("General"), TEXT("Pause"), 0, bPause)) {
		goto errorFinally;
	}

	if (bPause) {
		MessageBox(NULL, TEXT("Pause"), TEXT("Infinity Loader"), MB_ICONINFORMATION);
	}

	if (lastError = patchMainThread(processInfo.hProcess, processInfo.hThread)) {
		goto errorFinally;
	}

	//if (DWORD lastError = remoteThread(processInfo.hProcess)) {
	//	return lastError;
	//}

	if (ResumeThread(processInfo.hThread) == -1) {
		lastError = GetLastError();
		printf("[!] ResumeThread failed (%d).\n", lastError);
		goto errorFinally;
	}

	if (WaitForSingleObject(processInfo.hProcess, INFINITE) == WAIT_FAILED) {
		lastError = GetLastError();
		printf("[!] WaitForSingleObject failed (%d).\n", lastError);
		goto errorFinally;
	}

	if (!CloseHandle(processInfo.hProcess)) {
		lastError = GetLastError();
		printf("[!] CloseHandle failed (%d).\n", lastError);
	}

	if (!CloseHandle(processInfo.hThread)) {
		lastError = GetLastError();
		printf("[!] CloseHandle failed (%d).\n", lastError);
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

int main(int argc, char* argv[]) {
	
	if (!inheritedConsole()) {
		hideConsole();
	}

	if (startGame()) {
		showConsole();
		std::cout << "Press any key to continue . . .";
		std::cin.get();
	}

	return 0;
}
