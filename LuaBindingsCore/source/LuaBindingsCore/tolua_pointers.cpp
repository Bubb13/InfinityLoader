
#include "tolua_pointers.h"

//////////////
// Pointers //
//////////////

EXPORT type_free p_free;
EXPORT type_malloc p_malloc;

/////////////
// Special //
/////////////

// The address of this variable is used as the pointer of a special
// light userdata object in the bindings that signifies "nullptr."
EXPORT bool NULL_POINTER;
