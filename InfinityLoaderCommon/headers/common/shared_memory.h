
#pragma once

#include "shared_memory_types.h"

/////////////
// Globals //
/////////////

extern HANDLE hSharedFile;
extern SharedMemory* shared;

/////////////
// Defines //
/////////////

#define shared() shared
#define parentProcessId() shared()->io.parentProcessId
#define hStdIn() shared()->io.hStdIn
#define hStdOut() shared()->io.hStdOut
#define hStdErr() shared()->io.hStdErr
#define debug() shared()->options.debug
#define bPause() shared()->options.pause
#define protonCompatibility() shared()->options.protonCompatibility
