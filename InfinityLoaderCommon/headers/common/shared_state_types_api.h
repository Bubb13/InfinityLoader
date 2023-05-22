
#pragma once

#include <functional>
#include <map>

#include "dll_api.h"
#include "infinity_loader_common_types.h"
#include "lua_provider_api_core.h"
#include "opaque_object_api.h"
#include "shared_state_mapped_memory_types_api.h"

#include <Windows.h>

enum class LuaMode {
	INTERNAL,
	EXTERNAL,
	REPLACE_INTERNAL_WITH_EXTERNAL,
};

class SharedState {
private:
	void* imp;
public:
	OpaqueObjectBoilerplateAPIDef(SharedState)
	// Static Functions
	IMPORT static DWORD Create(SharedStateMappedMemory mappedMemory, SharedState& sharedStateOut);
	// Non-Static Functions
	IMPORT DWORD InitState();
	IMPORT SharedStateMappedMemory& MappedMemory();
	IMPORT const String& DbPath();
	IMPORT const String& ExePath();
	IMPORT const String& ExeName();
	IMPORT const String& IniPath();
	IMPORT const String& WorkingFolder();
	IMPORT const StringA& WorkingFolderA();
	IMPORT long long InitTime();
	IMPORT void InitLuaState(lua_State* L);
	IMPORT lua_State* LuaState();
	IMPORT HMODULE LuaLibrary();
	IMPORT LuaMode LuaMode();
	IMPORT void IteratePatternValues(std::function<bool(const String&, uintptr_t)> func);
	IMPORT bool GetPatternValue(const String& name, uintptr_t& out);
	IMPORT void SetPatternValue(const String& name, uintptr_t value);
	IMPORT void SetPatternValue(const String& name, void* value);
	IMPORT uintptr_t ImageBase();
	IMPORT DWORD LoadSegmentInfo(const StringA& sectionName);
	IMPORT bool GetSegmentPointer(const char* name, void*& out);
	IMPORT bool GetSegmentSize(const char* name, DWORD& out);
	IMPORT bool GetSegmentPointerAndSize(const char* name, void*& ptrOut, DWORD& sizeOut);
};
