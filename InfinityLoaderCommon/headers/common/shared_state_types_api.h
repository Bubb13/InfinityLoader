
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

enum class PatternValueType {
	INVALID = 0,
	SINGLE = 1,
	LIST = 2,
};
typedef const void* PatternValueHandle;

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
	IMPORT void AddLuaStateInitializedCallback(std::function<void()> callback);
	IMPORT lua_State* LuaState();
	IMPORT HMODULE LuaLibrary();
	IMPORT LuaMode LuaMode();

	IMPORT void AddAfterPatternModifiedListener(std::function<void(PatternValueHandle, uintptr_t)> listener);
	IMPORT void AddListPatternValue(PatternValueHandle valueHandle, uintptr_t value);
	IMPORT void AddListPatternValue(PatternValueHandle valueHandle, void* value);
	IMPORT bool GetOrCreatePatternValue(const String& name, PatternValueType valueType, PatternValueHandle& out);
	IMPORT PatternValueType GetPatternValue(const String& name, PatternValueHandle& out);
	IMPORT const String& GetPatternValueName(PatternValueHandle valueHandle);
	IMPORT PatternValueType GetPatternValueType(PatternValueHandle valueHandle);
	IMPORT uintptr_t GetSinglePatternValue(PatternValueHandle valueHandle);
	IMPORT void IteratePatternList(PatternValueHandle valueHandle, std::function<bool(uintptr_t)> func);
	IMPORT void IteratePatternValues(std::function<bool(PatternValueHandle)> func);
	IMPORT void SetSinglePatternValue(PatternValueHandle valueHandle, uintptr_t value);
	IMPORT void SetSinglePatternValue(PatternValueHandle valueHandle, void* value);

	IMPORT uintptr_t ImageBase();
	IMPORT DWORD LoadSegmentInfo(const StringA& sectionName);
	IMPORT bool GetSegmentPointer(const char* name, void*& out);
	IMPORT bool GetSegmentSize(const char* name, DWORD& out);
	IMPORT bool GetSegmentPointerAndSize(const char* name, void*& ptrOut, DWORD& sizeOut);
};
