// lua.hpp
// Lua header files for C++
// <<extern "C">> not supplied automatically because Lua also compiles as C++

extern "C" {
#include "tolua_reference/lua.h"
#include "tolua_reference/lualib.h"
#include "tolua_reference/lauxlib.h"
}
