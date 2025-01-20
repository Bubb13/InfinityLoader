
#include <array>
#include <iostream>

#include "infinity_loader_common_api.h"
#include "util.h"

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

static bool inheritedConsole() {
	HWND consoleWnd = GetConsoleWindow();
	DWORD dwProcessId;
	GetWindowThreadProcessId(consoleWnd, &dwProcessId);
	return GetCurrentProcessId() != dwProcessId;
}

static void hideConsole()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
}

static void showConsole()
{
	ShowWindow(GetConsoleWindow(), SW_SHOW);
}

/*static DWORD GetThreadStartAddress(HANDLE hThread)
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
static DWORD writeProcessString(HANDLE hProcess, const CharType* str, uintptr_t& memoryPtr) {

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
		FPrint("[!][InfinityLoader.exe] writeProcessString() - VirtualAllocEx() failed (%d)\n", lastError);
		return lastError;
	}

	if (!WriteProcessMemory(hProcess, allocPtr, str, strSizeBytes, NULL)) {
		DWORD lastError = GetLastError();
		FPrint("[!][InfinityLoader.exe] writeProcessString() - WriteProcessMemory() failed (%d)\n", lastError);
		return lastError;
	}

	memoryPtr = reinterpret_cast<uintptr_t>(allocPtr);
	return 0;
}

static DWORD patchMainThread(HANDLE hProcess, HANDLE hThread) {

	CONTEXT context;
	memset(&context, 0, sizeof(CONTEXT));
	context.ContextFlags = CONTEXT_INTEGER;
	if (!GetThreadContext(hThread, &context)) {
		DWORD lastError = GetLastError();
		FPrint("[!][InfinityLoader.exe] patchMainThread() - GetThreadContext() failed (%d)\n", lastError);
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
		FPrint("[!][InfinityLoader.exe] patchMainThread() - VirtualAllocEx() failed (%d)\n", lastError);
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
		FPrint("[!][InfinityLoader.exe] patchMainThread() - WriteProcessMemory() failed (%d)\n", lastError);
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
		FPrint("[!][InfinityLoader.exe] patchMainThread() - SetThreadContext() failed (%d)\n", lastError);
		return lastError;
	}

	if (debug()) {
		FPrint("[!][InfinityLoader.exe] patchMainThread() - threadStart: %p\n", threadStart);
	}

	return 0;
}

/*static DWORD remoteThread(HANDLE hProcess) {

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

static DWORD startGame() {

	STARTUPINFO startupInfo{};
	startupInfo.cb = sizeof(STARTUPINFO);

	PROCESS_INFORMATION processInfo{};
	DWORD lastError = ERROR_SUCCESS;

	HANDLE hStdInput = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdError = GetStdHandle(STD_ERROR_HANDLE);

	if (debug()) {
		FPrint("[?][InfinityLoader.exe] startGame() - Parent hStdInput: %d\n", hStdInput);
		FPrint("[?][InfinityLoader.exe] startGame() - Parent hStdOutput: %d\n", hStdOutput);
		FPrint("[?][InfinityLoader.exe] startGame() - Parent hStdError: %d\n", hStdError);
	}

	if (!CreateProcess(exePath.c_str(), NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &startupInfo, &processInfo)) {
		lastError = GetLastError();
		FPrintT(TEXT("[!][InfinityLoader.exe] startGame() - CreateProcess() failed (%d) attempting to start \"%s\"\n"), lastError, exePath.c_str());
		return lastError;
	}

	if (lastError = GetINIBoolDef(iniPath, TEXT("General"), TEXT("Pause"), false, pause())) {
		goto errorFinally;
	}

	if (pause()) {
		MessageBox(NULL, TEXT("[?] startGame() - Pause (Before Patch)"), TEXT("InfinityLoader.exe"), MB_ICONINFORMATION);
	}

	if (lastError = patchMainThread(processInfo.hProcess, processInfo.hThread)) {
		goto errorFinally;
	}

	//if (DWORD lastError = remoteThread(processInfo.hProcess)) {
	//	return lastError;
	//}

	if (pause()) {
		MessageBox(NULL, TEXT("[?] startGame() - Pause (Before Resume)"), TEXT("InfinityLoader.exe"), MB_ICONINFORMATION);
	}

	if (ResumeThread(processInfo.hThread) == -1) {
		lastError = GetLastError();
		FPrint("[!][InfinityLoader.exe] startGame() - ResumeThread() failed (%d)\n", lastError);
		goto errorFinally;
	}

	if (WaitForSingleObject(processInfo.hProcess, INFINITE) == WAIT_FAILED) {
		lastError = GetLastError();
		FPrint("[!][InfinityLoader.exe] startGame() - WaitForSingleObject() failed (%d)\n", lastError);
		goto errorFinally;
	}

	if (!CloseHandle(processInfo.hProcess)) {
		lastError = GetLastError();
		FPrint("[!][InfinityLoader.exe] startGame() - CloseHandle() failed (%d)\n", lastError);
	}

	if (!CloseHandle(processInfo.hThread)) {
		lastError = GetLastError();
		FPrint("[!][InfinityLoader.exe] startGame() - CloseHandle() failed (%d)\n", lastError);
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

////////////////////////////////////////
// Microsoft C++ STL Version Checking //
////////////////////////////////////////

static DWORD getDLLVersion(const wchar_t *const filePath, DWORD& majorOut, DWORD& minorOut, DWORD& buildOut, DWORD& revisionOut) {

	DWORD handle = NULL;
	const DWORD size = GetFileVersionInfoSizeW(filePath, &handle);

	if (size == 0) {
		const DWORD lastError = GetLastError();
		FPrint("[!][InfinityLoader.exe] getDLLVersion() - GetFileVersionInfoSizeW() failed (%d)\n", lastError);
		return lastError;
	}

	std::vector<unsigned char> versionData(size);

	if (!GetFileVersionInfoW(filePath, handle, size, versionData.data())) {
		const DWORD lastError = GetLastError();
		FPrint("[!][InfinityLoader.exe] getDLLVersion() - GetFileVersionInfoW() failed (%d)\n", lastError);
		return lastError;
	}

	VS_FIXEDFILEINFO* fileInfo = nullptr;
	UINT len;

	if (!VerQueryValueW(versionData.data(), L"\\", reinterpret_cast<LPVOID*>(&fileInfo), &len)) {
		const DWORD lastError = GetLastError();
		FPrint("[!][InfinityLoader.exe] getDLLVersion() - VerQueryValueW() failed (%d)\n", lastError);
		return lastError;
	}

	if (fileInfo == nullptr) {
		return -1;
	}

	majorOut = HIWORD(fileInfo->dwFileVersionMS);
	minorOut = LOWORD(fileInfo->dwFileVersionMS);
	buildOut = HIWORD(fileInfo->dwFileVersionLS);
	revisionOut = LOWORD(fileInfo->dwFileVersionLS);
	return ERROR_SUCCESS;
}

static void processLoadedModulePath(const HMODULE module, DWORD& lastError, std::function<void(wchar_t*, size_t)> callback) {

	RunWithGrowingBuffer<wchar_t>(

		[&](wchar_t *const buffer, const size_t bufferSize) {

			const DWORD pathSize = GetModuleFileNameW(module, buffer, static_cast<DWORD>(bufferSize));

			if (pathSize == 0) {
				lastError = GetLastError();
				FPrint("[!][InfinityLoader.exe] processLoadedModulePath() - GetModuleFileNameW() failed (%d)\n", lastError);
				return TryFillBufferResult::ABORT;
			}

			return pathSize == bufferSize ? TryFillBufferResult::GROW : TryFillBufferResult::DONE;
		},
		callback
	);
}

static DWORD getLoadedDLLVersion(const wchar_t *const dllName, DWORD& majorOut, DWORD& minorOut, DWORD& buildOut, DWORD& revisionOut) {

	const HMODULE hModule = GetModuleHandleW(dllName);

	if (hModule == NULL) {
		const DWORD lastError = GetLastError();
		FPrint("[!][InfinityLoader.exe] getLoadedDLLVersion() - GetModuleHandleW() failed (%d)\n", lastError);
		return lastError;
	}

	DWORD lastError = ERROR_SUCCESS;
	processLoadedModulePath(hModule, lastError, [&](const wchar_t *const modulePath, const size_t) {
		lastError = getDLLVersion(modulePath, majorOut, minorOut, buildOut, revisionOut);
	});

	return lastError;
}

template<std::size_t N>
static bool checkVersion(const std::array<DWORD, N>& targetVersion, const std::array<DWORD, N>& checkVersion) {
	for (std::size_t i = 0; i < N; ++i) {
		const DWORD checkPart = checkVersion[i];
		const DWORD targetPart = targetVersion[i];
		if (checkPart > targetPart) {
			break;
		}
		else if (checkPart < targetPart) {
			return false;
		}
	}
	return true;
}

////////////////////
// Initialization //
////////////////////

static DWORD checkAutoRedirectToFile() {

	String logName{};
	bool filled;
	TryRetErr( GetINIStr(iniPath, TEXT("General"), TEXT("LogFile"), logName, filled) )

	if (!filled) {
		return ERROR_SUCCESS;
	}

	const HANDLE hFile = CreateFile(
		String{ workingFolder }.append(logName).c_str(),
		GENERIC_WRITE,
		FILE_SHARE_READ,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	if (hFile == INVALID_HANDLE_VALUE) {
		MessageBoxFormat(TEXT("InfinityLoader.exe"), MB_ICONWARNING,
			TEXT("CreateFile() failed (%d); unable to open log file \"%s\""),
			GetLastError(), logName.c_str()
		);
		return ERROR_SUCCESS; // Don't prevent the game from launching just because the log couldn't be opened
	}

	if (!SetStdHandle(STD_OUTPUT_HANDLE, hFile)) {
		MessageBoxFormat(TEXT("InfinityLoader.exe"), MB_ICONWARNING,
			TEXT("SetStdHandle() failed (%d); unable to redirect STD_OUTPUT_HANDLE to log file \"%s\""),
			GetLastError(), logName.c_str()
		);
		return ERROR_SUCCESS; // Don't prevent the game from launching just because the log couldn't be opened
	}

	if (!SetStdHandle(STD_ERROR_HANDLE, hFile)) {
		MessageBoxFormat(TEXT("InfinityLoader.exe"), MB_ICONWARNING,
			TEXT("SetStdHandle() failed (%d); unable to redirect STD_ERROR_HANDLE to log file \"%s\""),
			GetLastError(), logName.c_str()
		);
		return ERROR_SUCCESS; // Don't prevent the game from launching just because the log couldn't be opened
	}

	BindCrtStreamsToOSHandles();
	return ERROR_SUCCESS;
}

static DWORD init() {

	std::array<DWORD, 4> version;
	TryRetErr( getLoadedDLLVersion(L"msvcp140.dll", version[0], version[1], version[2], version[3]) )

	if (!checkVersion({ 14, 42, 34433, 0 }, version)) {
		MessageBoxA(NULL, "Please update your Microsoft Visual C++ Redistributable", "InfinityLoader.exe", MB_ICONERROR);
		return -2;
	}

	TryRetErr( CreateMappedMemory(mappedMemoryHandle(), mappedMemory()) )
	TryRetErr( InitPaths(dbPath, exePath, exeName, iniPath, workingFolder, workingFolderA) )
	TryRetErr( checkAutoRedirectToFile() )
	TryRetErr( GetINIBoolDef(iniPath, TEXT("General"), TEXT("Debug"), false, debug()) )
	TryRetErr( GetINIBoolDef(iniPath, TEXT("General"), TEXT("ProtonCompatibility"), false, protonCompatibility()) )
	TryElseRetErr( UnbufferCrtStreams(), FPrint("[!][InfinityLoader.exe] init() - UnbufferCrtStreams() failed (%d)\n", error) )
	TryElseRetErr( InitFPrint(), FPrint("[!][InfinityLoader.exe] init() - InitFPrint() failed (%d)\n", error) )
	return ERROR_SUCCESS;
}

static int exceptionFilter(unsigned int code, _EXCEPTION_POINTERS* pointers) {
	String dmpLocation = WriteDump(workingFolder, pointers);
	MessageBoxFormat(TEXT("InfinityLoader.exe"), MB_ICONERROR, TEXT("[!] Unhandled exception 0x%X. Crash log saved to:\n\n%s\n\nThis should never happen. Please report to Bubb."), code, dmpLocation.c_str());
	exit(code);
}

int main(int argc, char* argv[]) {

	__try {

		if (!inheritedConsole()) {
			hideConsole();
		}

		if (const DWORD lastError = init()) {
			if (lastError != -2) {
				goto error;
			}
			return 0;
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
