
#pragma once

// `shared_state_types.h` or `shared_state_types_api.h` should be included before this file.

/////////////////////////
// Globals and Defines //
/////////////////////////

extern SharedState sharedState;
#define sharedState() sharedState

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
