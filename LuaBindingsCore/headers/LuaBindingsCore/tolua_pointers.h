
#pragma once

#include "dll_api.h"

//////////////
// Pointers //
//////////////

typedef void(__cdecl* type_free)(void* memblock);
EXTERN_EXPORT type_free p_free;

typedef void* (__cdecl* type_malloc)(size_t size);
EXTERN_EXPORT type_malloc p_malloc;

/////////////
// Special //
/////////////

// The address of this variable is used as the pointer of a special
// light userdata object in the bindings that signifies "nullptr."
EXTERN_EXPORT bool NULL_POINTER;
