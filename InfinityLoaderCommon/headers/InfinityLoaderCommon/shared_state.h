
#pragma once

#include <map>
#include <queue>
#include <shared_mutex>

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

	struct SingleValue {
		uintptr_t address;
	};

	struct ListValue {
		std::shared_mutex mutex;
		std::list<uintptr_t> addresses;
	};

	union Value {
		SingleValue single;
		ListValue list;
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
	friend class SharedState;

private:

	long long initTime;

	struct ThreadQueue {

		struct Message {

			enum class Type {
				PATTERN_UPDATED = 0
			};

			struct PatternSet {
				PatternValueHandle patternValueHandle;
				uintptr_t value;
			};

			Type type;
			union {
				PatternSet patternSet;
			};
		};

		std::mutex messagesMutex{};
		std::queue<Message> messages{};
	};

	struct LuaStateEntry {
		DWORD threadId;
		lua_State* L;
		ThreadQueue threadQueue{};
		LuaStateEntry(DWORD threadId, lua_State* L) : threadId(threadId), L(L) {}
	};

	std::shared_mutex luaStateEntriesMutex;
	std::list<LuaStateEntry> luaStateEntries;

	std::vector<std::function<void(lua_State*)>> luaStateInitializedCallbacks;

	HMODULE luaLibrary = reinterpret_cast<HMODULE>(INVALID_HANDLE_VALUE);
	LuaMode luaMode;

	std::shared_mutex patternsModifyMutex;
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
private:
	using MessageType = SharedDLLState::ThreadQueue::Message::Type;
	void QueueAfterPatternSetMessage(PatternValueHandle valueHandle, uintptr_t value);
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
	EXPORT void AddLuaStateInitializedCallback(std::function<void(lua_State*)> callback);
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
	EXPORT void ProcessThreadQueue();
	EXPORT void SetSinglePatternValue(PatternValueHandle valueHandle, uintptr_t value);
	EXPORT void SetSinglePatternValue(PatternValueHandle valueHandle, void* value);

	EXPORT uintptr_t ImageBase();
	EXPORT DWORD LoadSegmentInfo(const StringA& sectionName);
	EXPORT bool GetSegmentPointer(const char* name, void*& out);
	EXPORT bool GetSegmentSize(const char* name, DWORD& out);
	EXPORT bool GetSegmentPointerAndSize(const char* name, void*& ptrOut, DWORD& sizeOut);
};
