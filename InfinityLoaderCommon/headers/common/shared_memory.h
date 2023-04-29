
#pragma once

#include "shared_memory_types.h"

extern HANDLE hSharedFile;
extern SharedMemory* shared;

extern String dbPath;
extern String exePath;
extern String exeName;
extern String iniPath;
extern String workingFolder;

#define dbPath() dbPath
#define exePath() exePath
#define exeName() exeName
#define iniPath() iniPath
#define workingFolder() workingFolder

#define shared() shared
#define parentProcessId() shared()->io.parentProcessId
#define hStdIn() shared()->io.hStdIn
#define hStdOut() shared()->io.hStdOut
#define hStdErr() shared()->io.hStdErr
#define debug() shared()->options.debug
#define bPause() shared()->options.pause
#define protonCompatibility() shared()->options.protonCompatibility
