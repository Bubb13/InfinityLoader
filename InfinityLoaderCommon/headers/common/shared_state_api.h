
#pragma once

#include "shared_state_mapped_memory_api.h"

/////////////////////////
// Globals and Defines //
/////////////////////////

#if defined SHARED_MEMORY_DLL_HOST 
extern SharedState sharedState;
#define sharedState() sharedState
#elif defined SHARED_MEMORY_DLL
extern SharedState sharedState;
#define sharedState() sharedState
#endif

#define dbPath() sharedState().DbPath()
#define exePath() sharedState().ExePath()
#define exeName() sharedState().ExeName()
#define iniPath() sharedState().IniPath()
#define workingFolder() sharedState().WorkingFolder()
#define workingFolderA() sharedState().WorkingFolderA()
#define initTime() sharedState().InitTime()
#define luaState() sharedState().LuaState()
#define luaLibrary() sharedState().LuaLibrary()
#define luaMode() sharedState().LuaMode()
#define textInfo() sharedState().TextInfo()
