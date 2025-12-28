
#include <filesystem>
#include <fstream>
#include <sstream>

#include <Windows.h>
#include <dbghelp.h>

#include "infinity_loader_common_api.h"

//////////////////////
// Static Functions //
//////////////////////

static String getWorkingFolder() {
#ifndef UNICODE
	return std::filesystem::current_path().string().append(TEXT("\\"));
#else
	return std::filesystem::current_path().wstring().append(TEXT("\\"));
#endif
}

static String getINIPath() {
	return String{ getWorkingFolder() }.append(TEXT("InfinityLoader.ini"));
}

////////////////////////
// Exception Handling //
////////////////////////

const TCHAR *const sCrashWithLogFormat = TEXT(R"(Crash detected with error code 0x%X.

Dump file (big) saved to:

%s

Dump file (small) saved to:

%s

Log file saved to:

%s

The game will exit after you press OK.)");

const TCHAR *const sCrashWithoutLogFormat = TEXT(R"(Crash detected with error code 0x%X.

Dump file (big) saved to:

%s

Dump file (small) saved to:

%s

The game will exit after you press OK.)");

EXPORT void DumpCrashInfo(EXCEPTION_POINTERS* pointers)
{
	const DWORD exceptionCode = pointers->ExceptionRecord->ExceptionCode;
	FPrint("[!] Crash detected with error code 0x%X\n", exceptionCode);

	///////////////////////
	// Find output paths //
	///////////////////////

	OStringStream dmpNameStream{};
	dmpNameStream << getWorkingFolder();
	dmpNameStream << "InfinityLoader_Crash";

	const String dmpFolderPath = dmpNameStream.str();

	if (!std::filesystem::exists(dmpFolderPath)) {
		std::filesystem::create_directory(dmpFolderPath);
	}

	String logName{};
	bool hasLogFile;
	GetINIStr(getINIPath(), TEXT("General"), TEXT("LogFile"), logName, hasLogFile); // Error intentionally ignored

	String builtDmpNameBig{};
	String builtDmpName{};
	String builtLogName{};

	for (size_t attemptI = 0; ; ++attemptI) {

		///////////////////////////////
		// Derive big dump file path //
		///////////////////////////////

		dmpNameStream.str(TEXT(""));
		dmpNameStream.clear();
		dmpNameStream << dmpFolderPath << "\\InfinityLoader_Crash_" << attemptI << "_big" << ".dmp";

		builtDmpNameBig = dmpNameStream.str();

		if (std::filesystem::exists(builtDmpNameBig)) {
			continue;
		}

		/////////////////////////////////
		// Derive small dump file path //
		/////////////////////////////////

		dmpNameStream.str(TEXT(""));
		dmpNameStream.clear();
		dmpNameStream << dmpFolderPath << "\\InfinityLoader_Crash_" << attemptI << "_small" << ".dmp";

		builtDmpName = dmpNameStream.str();

		if (std::filesystem::exists(builtDmpName)) {
			continue;
		}

		///////////////////////////////
		// Derive game log file path //
		///////////////////////////////

		dmpNameStream.str(TEXT(""));
		dmpNameStream.clear();
		dmpNameStream << dmpFolderPath << "\\InfinityLoader_Crash_" << attemptI << ".log";

		builtLogName = dmpNameStream.str();

		if (std::filesystem::exists(builtLogName)) {
			continue;
		}

		break;
	}

	////////////////////////////////////
	// MINIDUMP_EXCEPTION_INFORMATION //
	////////////////////////////////////

	MINIDUMP_EXCEPTION_INFORMATION exceptionInfo{};
	exceptionInfo.ThreadId = GetCurrentThreadId();
	exceptionInfo.ExceptionPointers = pointers;
	exceptionInfo.ClientPointers = FALSE;

	////////////////////
	// Write big dump //
	////////////////////

	const HANDLE hFileBig = CreateFile(
		builtDmpNameBig.c_str(),
		GENERIC_WRITE,
		NULL,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	const MINIDUMP_TYPE bigDumpType = static_cast<MINIDUMP_TYPE>(
		  MiniDumpWithFullMemory
		| MiniDumpWithHandleData
		| MiniDumpWithUnloadedModules
		| MiniDumpWithProcessThreadData
		| MiniDumpWithFullMemoryInfo
		| MiniDumpWithThreadInfo
		| MiniDumpWithFullAuxiliaryState
		| MiniDumpIgnoreInaccessibleMemory
		| MiniDumpWithTokenInformation
	);

	MiniDumpWriteDump(
		GetCurrentProcess(),
		GetCurrentProcessId(),
		hFileBig,
		bigDumpType,
		&exceptionInfo,
		NULL,
		NULL
	);

	CloseHandle(hFileBig);

	//////////////////////
	// Write small dump //
	//////////////////////

	const HANDLE hFile = CreateFile(
		builtDmpName.c_str(),
		GENERIC_WRITE,
		NULL,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	const MINIDUMP_TYPE dumpType = static_cast<MINIDUMP_TYPE>(
		  MiniDumpWithDataSegs
		| MiniDumpWithIndirectlyReferencedMemory
	);

	MiniDumpWriteDump(
		GetCurrentProcess(),
		GetCurrentProcessId(),
		hFile,
		dumpType,
		&exceptionInfo,
		NULL,
		NULL
	);

	CloseHandle(hFile);

	///////////////////////////
	// Write Lua stack trace //
	///////////////////////////

	bool bWroteLuaOnlyLog = false;

	if (sharedState().IsValid()) {

		lua_State *const L = sharedState().LuaState();

		if (L != nullptr) {

			luaL_traceback(L, L, nullptr, 0);
			const char *const sLuaTraceback = lua_tostring(L, -1);

			if (!hasLogFile) {

				const std::filesystem::path luaLogPath { builtLogName.c_str() };
				std::ofstream luaLogOut { luaLogPath };

				luaLogOut << "[?] LogFile not defined in InfinityLoader.ini - writing crash info only\n";
				luaLogOut << "[!] Crashing thread had Lua state; " << sLuaTraceback;
				luaLogOut.flush();

				bWroteLuaOnlyLog = true;
			}

			Print("[!] Crashing thread had Lua state; ");
			Print(sLuaTraceback);

			lua_pop(L, 1);
		}
	}

	///////////////////
	// Copy game log //
	///////////////////

	if (hasLogFile) {
		CopyFile(logName.c_str(), builtLogName.c_str(), FALSE);
	}

	/////////////////////////
	// Display message box //
	/////////////////////////

	if (hasLogFile || bWroteLuaOnlyLog)
	{
		MessageBoxFormat(TEXT("InfinityLoaderUtil.dll"), MB_ICONERROR | MB_SYSTEMMODAL, sCrashWithLogFormat,
			exceptionCode, builtDmpNameBig.c_str(), builtDmpName.c_str(), builtLogName.c_str());
	}
	else
	{
		MessageBoxFormat(TEXT("InfinityLoaderUtil.dll"), MB_ICONERROR | MB_SYSTEMMODAL, sCrashWithoutLogFormat,
			exceptionCode, builtDmpNameBig.c_str(), builtDmpName.c_str());
	}
}
