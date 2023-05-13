
#pragma once

#include <map>

#include "infinity_loader_common_types.h"
#include "lua_provider_api_core.h"
#include "shared_memory_types.h"

struct SharedDLLPaths {
	String dbPath;
	String exePath;
	String exeName;
	String iniPath;
	String workingFolder;
	StringA workingFolderA;
};

#define dbPath() sharedDLL->paths.dbPath
#define exePath() sharedDLL->paths.exePath
#define exeName() sharedDLL->paths.exeName
#define iniPath() sharedDLL->paths.iniPath
#define workingFolder() sharedDLL->paths.workingFolder
#define workingFolderA() sharedDLL->paths.workingFolderA

enum class LuaMode {
	INTERNAL,
	EXTERNAL,
	REPLACE_INTERNAL_WITH_EXTERNAL,
};

struct SharedDLLState {
	long long initTime;
	lua_State* L;
	HMODULE luaLibrary = reinterpret_cast<HMODULE>(-1);
	LuaMode luaMode;
	std::map<String, PatternEntry> patterns;
	ImageSectionInfo textInfo;
};

#define initTime() sharedDLL->state.initTime
#define L() sharedDLL->state.L
#define luaLibrary() sharedDLL->state.luaLibrary
#define luaMode() sharedDLL->state.luaMode
#define patterns() sharedDLL->state.patterns
#define textInfo() sharedDLL->state.textInfo

struct SharedDLLMemory {
	SharedDLLPaths paths;
	SharedMemory* shared;
	SharedDLLState state;
};

extern SharedDLLMemory* sharedDLL;

#define shared() sharedDLL->shared
#define parentProcessId() shared()->io.parentProcessId
#define hStdIn() shared()->io.hStdIn
#define hStdOut() shared()->io.hStdOut
#define hStdErr() shared()->io.hStdErr
#define debug() shared()->options.debug
#define bPause() shared()->options.pause
#define protonCompatibility() shared()->options.protonCompatibility
