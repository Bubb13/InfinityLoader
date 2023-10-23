
#pragma once

#include <map>

#include "dll_api.h"
#include "infinity_loader_common_types.h"
#include "lua_provider_api_core.h"
#include "opaque_object.h"
#include "shared_state_mapped_memory.h"

#include <Windows.h>

class SharedPaths {
private:
	friend class SharedState;
	String dbPath;
	String exePath;
	String exeName;
	String iniPath;
	String workingFolder;
	StringA workingFolderA;
};

enum class LuaMode {
	INTERNAL,
	EXTERNAL,
	REPLACE_INTERNAL_WITH_EXTERNAL,
};

struct SectionInfo {
	char SectionName[IMAGE_SIZEOF_SHORT_NAME];
	void* SectionPointer;
	DWORD SectionSize;
};

// API
enum class PatternValueType {
	INVALID = 0,
	SINGLE = 1,
	LIST = 2,
};
typedef const void* PatternValueHandle;

// Implementation
namespace Pattern {

	enum class ValueType {
		INVALID = 0,
		SINGLE = 1,
		LIST = 2,
	};

	union Value {
		uintptr_t address;
		std::vector<uintptr_t> addresses;
		Value() {};
		~Value() {};
	};

	struct Entry {
		String name;
		ValueType valueType;
		Value value;
		Entry(const String& str, uintptr_t val);
		Entry(const String& str, ValueType val);
		~Entry();
	};
}

class SharedDLLState {
private:
	friend class SharedState;
	long long initTime;
	lua_State* L;
	std::vector<std::function<void()>> luaStateInitializedCallbacks;
	HMODULE luaLibrary = reinterpret_cast<HMODULE>(-1);
	LuaMode luaMode;
	std::map<String, Pattern::Entry> patterns;
	std::vector<std::function<void(const PatternValueHandle valueHandle, uintptr_t)>> afterPatternSetListeners;
	uintptr_t imageBase;
	std::map<StringA, SectionInfo> sectionInfo;
};

class SharedStateData {
private:
	friend class SharedState;
	SharedStateMappedMemory mappedMemory;
	SharedPaths paths;
	SharedDLLState state;
};

class SharedState : OpaqueObject::Obj<SharedStateData> {
public:
	OpaqueObjectBoilerplateDef(SharedState)
	// Static Functions
	EXPORT static DWORD Create(SharedStateMappedMemory mappedMemory, SharedState& sharedStateOut);
	// Non-Static Functions
	EXPORT DWORD InitState();
	EXPORT SharedStateMappedMemory& MappedMemory();
	EXPORT const String& DbPath();
	EXPORT const String& ExePath();
	EXPORT const String& ExeName();
	EXPORT const String& IniPath();
	EXPORT const String& WorkingFolder();
	EXPORT const StringA& WorkingFolderA();
	EXPORT long long InitTime();
	EXPORT void InitLuaState(lua_State* L);
	EXPORT void AddLuaStateInitializedCallback(std::function<void()> callback);
	EXPORT lua_State* LuaState();
	EXPORT HMODULE LuaLibrary();
	EXPORT LuaMode LuaMode();

	EXPORT void AddAfterPatternModifiedListener(std::function<void(PatternValueHandle, uintptr_t)> listener);
	EXPORT void AddListPatternValue(PatternValueHandle valueHandle, uintptr_t value);
	EXPORT void AddListPatternValue(PatternValueHandle valueHandle, void* value);
	EXPORT bool GetOrCreatePatternValue(const String& name, PatternValueType valueType, PatternValueHandle& out);
	EXPORT PatternValueType GetPatternValue(const String& name, PatternValueHandle& out);
	EXPORT const String& GetPatternValueName(PatternValueHandle valueHandle);
	EXPORT PatternValueType GetPatternValueType(PatternValueHandle valueHandle);
	EXPORT uintptr_t GetSinglePatternValue(PatternValueHandle valueHandle);
	EXPORT void IteratePatternList(PatternValueHandle valueHandle, std::function<bool(uintptr_t)> func);
	EXPORT void IteratePatternValues(std::function<bool(PatternValueHandle)> func);
	EXPORT void SetSinglePatternValue(PatternValueHandle valueHandle, uintptr_t value);
	EXPORT void SetSinglePatternValue(PatternValueHandle valueHandle, void* value);

	EXPORT uintptr_t ImageBase();
	EXPORT DWORD LoadSegmentInfo(const StringA& sectionName);
	EXPORT bool GetSegmentPointer(const char* name, void*& out);
	EXPORT bool GetSegmentSize(const char* name, DWORD& out);
	EXPORT bool GetSegmentPointerAndSize(const char* name, void*& ptrOut, DWORD& sizeOut);
};
