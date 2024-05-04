
#include <chrono>
#include <optional>
#include <sstream>

#include "Baldur-v2.6.6.0_generated.h"
#include "EEex.h"
#include "util.hpp"

//---------------------------//
//          Defines          //
//---------------------------//

/////////////////////////////
// Hook Integrity Watchdog //
/////////////////////////////

constexpr uintptr_t HOOK_INTEGRITY_WATCHDOG_STACK_SNAPSHOT_SIZE = 256;

//////////////////
// Stutter Util //
//////////////////

//#define STUTTER_LOGGING

#ifdef STUTTER_LOGGING
	#define STUTTER_LOG_START(retType, stutterLogName) return logStutter<retType>(stutterLogName, [&]() -> retType {
	#define STUTTER_LOG_END });
#else
	#define STUTTER_LOG_START(retType, stutterLogName)
	#define STUTTER_LOG_END
#endif

///////////
// Stats //
///////////

// Needs to be updated if Beamdog ever adds a new stat
#define FIRST_EXTENDED_STAT_ID 203

////////////////
// Projectile //
////////////////

//#define PROJECTILE_MUTATORS_DISABLED

//---------------------------//
//          Globals          //
//---------------------------//

typedef int(*type_wrapper_fprintf)(FILE* stream, const char* format, ...);
type_wrapper_fprintf wrapper_fprintf;

typedef int(*type_wrapper_fclose)(FILE* stream);
type_wrapper_fclose wrapper_fclose;

/////////////////////////////
// Hook Integrity Watchdog //
/////////////////////////////

struct HookIntegrityWatchdogSnapshotData {
	RegisterValues registers;
	byte stack[HOOK_INTEGRITY_WATCHDOG_STACK_SNAPSHOT_SIZE];
};

struct HookIntegrityWatchdogIgnoreInstance {
	EEex_HookIntegrityWatchdogRegister registers;
	std::vector<std::pair<int, int>> stackRanges;
};

struct HookIntegrityWatchdogIgnoreData {
	std::unordered_map<size_t, HookIntegrityWatchdogIgnoreInstance> instances;
};

thread_local std::vector<HookIntegrityWatchdogSnapshotData> hookIntegrityWatchdogSnapshotVector;
std::unordered_map<uintptr_t, HookIntegrityWatchdogIgnoreData> hookIntegrityWatchdogIgnoreMap;

thread_local uintptr_t hookIntegrityWatchdogCachedStackBase = getStackBase();

//////////////////
// Stutter Util //
//////////////////

bool topLevel = true;

///////////
// Stats //
///////////

struct EnabledActionListenerData {
	char funcName[9];
	CGameEffect* pEffect;
};

struct ExStatData {
	std::unordered_map<int, int> exStatValues{};
	// op280
	int forcedWildSurgeNumber = 0;
	bool suppressWildSurgeVisuals = false;
	// op403
	std::vector<CGameEffect*> screenEffects;
	// op408
	std::vector<CGameEffect*> projectileMutatorEffects;
	// op409
	std::vector<EnabledActionListenerData> enableActionListenerEffects;
};

std::unordered_map<void*, ExStatData> exStatDataMap{};

struct ExStatInfo {
	int min;
	int max;
	int def;
};

std::unordered_map<int, ExStatInfo> exStatInfoMap{};

struct ExScriptData {
	bool bPlayerScript;
};

std::unordered_map<void*, ExScriptData> exScriptDataMap{};

////////////
// Opcode //
////////////

struct ExEffectInfo {
	bool bypassOp120;
};

std::unordered_map<void*, ExEffectInfo> exEffectInfoMap{};

////////////////
// Projectile //
////////////////

std::unordered_map<uintptr_t, std::pair<const char*, EEex::ProjectileType>> projVFTableToType{};

////////////
// Sprite //
////////////

struct ExSpriteData {

	Array<int, 3> oldDisabledSpellTypes;
	int oldDisableSpells = 0;
	uint64_t uuid = 0;

	ExSpriteData() {
		std::fill_n(oldDisabledSpellTypes.data, 3, 0);
	}
};

struct ExUUIDData {
	CGameSprite* pSprite;
};

std::unordered_map<void*, ExSpriteData> exSpriteDataMap{};
std::unordered_map<uint64_t, ExUUIDData> exUUIDDataMap{};

////////////////
// Game State //
////////////////

uint64_t nextUUID = 0;

/////////////
// Exports //
/////////////

std::vector<std::function<void(CGameAIBase*, unsigned char)>> scriptLevelHitCallbacks;
std::vector<std::function<void(int16_t)>> conditionResponseHitCallbacks{};
std::vector<std::function<void(int32_t)>> triggerHitCallbacks{};
std::vector<std::function<void(bool)>> triggerEvaluatedCallbacks{};

//-----------------------------//
//          Math Util          //
//-----------------------------//

template<typename NumType>
NumType clamp(NumType num, NumType minVal, NumType maxVal) {
	return max(minVal, min(num, maxVal));
}

template<typename ClampType, typename NumType>
ClampType clampToType(NumType num) {
	constexpr NumType minVal = (std::numeric_limits<ClampType>::min)();
	constexpr NumType maxVal = (std::numeric_limits<ClampType>::max)();
	return static_cast<ClampType>(clamp(num, minVal, maxVal));
}

template<typename HolderType, typename NumType>
constexpr bool canTypeHoldSum() {
	constexpr HolderType holderMin = (std::numeric_limits<HolderType>::min)();
	constexpr NumType numMin = (std::numeric_limits<NumType>::min)();
	return holderMin / 2 <= numMin;
}

template<typename HolderType, typename NumType>
constexpr bool canTypeHoldProduct() {
	constexpr HolderType holderMin = (std::numeric_limits<HolderType>::min)();
	constexpr NumType numMin = (std::numeric_limits<NumType>::min)();
	return -(holderMin / numMin) <= numMin;
}

template<typename NumType>
NumType clampedSum(NumType num1, NumType num2) {
	static_assert(canTypeHoldSum<__int64, NumType>());
	return clampToType<NumType>(static_cast<__int64>(num1) + num2);
}

template<typename NumType>
NumType clampedPercent(NumType num, NumType percent) {
	static_assert(canTypeHoldProduct<__int64, NumType>());
	return clampToType<NumType>(static_cast<__int64>(num) * percent / 100);
}

//-------------------------------------------//
//          Hook Integrity Watchdog          //
//-------------------------------------------//

__forceinline int operator&(const EEex_HookIntegrityWatchdogRegister a, const EEex_HookIntegrityWatchdogRegister b) {
	return static_cast<__int32>(a) & static_cast<__int32>(b);
}

void EEex::HookIntegrityWatchdogIgnoreStackRange(const uintptr_t address, const size_t instance, const int lowerBound, const int upperBound) {
	hookIntegrityWatchdogIgnoreMap[address].instances[instance].stackRanges.emplace_back(lowerBound, upperBound);
}

void EEex::HookIntegrityWatchdogIgnoreRegisters(const uintptr_t address, const size_t instance, const EEex_HookIntegrityWatchdogRegister registers) {
	hookIntegrityWatchdogIgnoreMap[address].instances[instance].registers = registers;
}

void EEex::HookIntegrityWatchdogEnter(const uintptr_t hookAddress, const RegisterValues *const registers) {

	HookIntegrityWatchdogSnapshotData& hookIntegrityWatchdogSnapshot = hookIntegrityWatchdogSnapshotVector.emplace_back();
	hookIntegrityWatchdogSnapshot.registers = *registers;

	byte *const hookIntegrityWatchdogStackSnapshot = hookIntegrityWatchdogSnapshot.stack;
	const byte *const stackPtr = reinterpret_cast<byte*>(registers->rsp);

	const uintptr_t limit = (std::min)(HOOK_INTEGRITY_WATCHDOG_STACK_SNAPSHOT_SIZE,
		hookIntegrityWatchdogCachedStackBase - reinterpret_cast<uintptr_t>(stackPtr));

	for (uintptr_t i = 0; i < limit; ++i) {
		hookIntegrityWatchdogStackSnapshot[i] = stackPtr[i];
	}
}

void EEex::HookIntegrityWatchdogExit(const uintptr_t hookAddress, const size_t instance, const RegisterValues *const registers) {

	const HookIntegrityWatchdogSnapshotData& hookIntegrityWatchdogSnapshot = hookIntegrityWatchdogSnapshotVector.back();

	const HookIntegrityWatchdogIgnoreInstance* hookIntegrityWatchdogIgnoreInstance = nullptr;
	if (auto itr = hookIntegrityWatchdogIgnoreMap.find(hookAddress); itr != hookIntegrityWatchdogIgnoreMap.end()) {
		auto& hookIntegrityWatchdogIgnoreInstances = itr->second.instances;
		if (auto itr2 = hookIntegrityWatchdogIgnoreInstances.find(instance); itr2 != hookIntegrityWatchdogIgnoreInstances.end()) {
			hookIntegrityWatchdogIgnoreInstance = &itr2->second;
		}
	}

	#define checkRegister(reg, regStr, ignoreFlag) \
		if (hookIntegrityWatchdogSnapshot.registers.reg != registers->reg \
			&& (hookIntegrityWatchdogIgnoreInstance == nullptr || (hookIntegrityWatchdogIgnoreInstance->registers & ignoreFlag) == 0)) \
		{ \
			Print("[!][EEex.dll] EEex::HookIntegrityWatchdogExit() - [%p] (instance %llu) %s changed from 0x%X to 0x%X\n", \
				hookAddress, instance, regStr, hookIntegrityWatchdogSnapshot.registers.reg, registers->reg); \
		}

	checkRegister(rax, "rax", EEex_HookIntegrityWatchdogRegister::RAX)
	checkRegister(rbx, "rbx", EEex_HookIntegrityWatchdogRegister::RBX)
	checkRegister(rcx, "rcx", EEex_HookIntegrityWatchdogRegister::RCX)
	checkRegister(rdx, "rdx", EEex_HookIntegrityWatchdogRegister::RDX)
	checkRegister(rbp, "rbp", EEex_HookIntegrityWatchdogRegister::RBP)
	checkRegister(rsp, "rsp", EEex_HookIntegrityWatchdogRegister::RSP)
	checkRegister(rsi, "rsi", EEex_HookIntegrityWatchdogRegister::RSI)
	checkRegister(rdi, "rdi", EEex_HookIntegrityWatchdogRegister::RDI)
	checkRegister(r8,  "r8",  EEex_HookIntegrityWatchdogRegister::R8)
	checkRegister(r9,  "r9",  EEex_HookIntegrityWatchdogRegister::R9)
	checkRegister(r10, "r10", EEex_HookIntegrityWatchdogRegister::R10)
	checkRegister(r11, "r11", EEex_HookIntegrityWatchdogRegister::R11)
	checkRegister(r12, "r12", EEex_HookIntegrityWatchdogRegister::R12)
	checkRegister(r13, "r13", EEex_HookIntegrityWatchdogRegister::R13)
	checkRegister(r14, "r14", EEex_HookIntegrityWatchdogRegister::R14)
	checkRegister(r15, "r15", EEex_HookIntegrityWatchdogRegister::R15)

	const byte *const hookIntegrityWatchdogStackSnapshot = hookIntegrityWatchdogSnapshot.stack;
	const byte *const stackPtr = reinterpret_cast<byte*>(registers->rsp);

	const uintptr_t limit = (std::min)(HOOK_INTEGRITY_WATCHDOG_STACK_SNAPSHOT_SIZE,
		hookIntegrityWatchdogCachedStackBase - reinterpret_cast<uintptr_t>(stackPtr));

	for (uintptr_t i = 0; i < limit; ++i) {

		const byte hookIntegrityWatchdogStackSnapshotByte = hookIntegrityWatchdogStackSnapshot[i];
		const byte stackByte = stackPtr[i];

		if (hookIntegrityWatchdogStackSnapshotByte == stackByte) {
			continue;
		}

		bool ignore = false;

		if (hookIntegrityWatchdogIgnoreInstance != nullptr) {
			for (auto& ignoredRange : hookIntegrityWatchdogIgnoreInstance->stackRanges) {
				if (i >= ignoredRange.first && i <= ignoredRange.second) {
					ignore = true;
					break;
				}
			}
		}

		if (!ignore) {
			Print("[!][EEex.dll] EEex::HookIntegrityWatchdogExit() - [%p] (instance %llu) Stack[+0x%X] Changed from 0x%X to 0x%X\n",
				hookAddress, instance, i, hookIntegrityWatchdogStackSnapshotByte, stackByte);
		}
	}

	hookIntegrityWatchdogSnapshotVector.pop_back();
}

uint64_t CGameSprite::GetUUID() {
	if (auto itr = exSpriteDataMap.find(this); itr != exSpriteDataMap.end()) {
		return itr->second.uuid;
	}
	return 0;
}

CGameSprite* EEex::GetSpriteFromUUID(uint64_t uuid) {
	if (auto itr = exUUIDDataMap.find(uuid); itr != exUUIDDataMap.end()) {
		return itr->second.pSprite;
	}
	return nullptr;
}

//--------------------------------//
//          Stutter Util          //
//--------------------------------//

long long currentMicroseconds() {
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void exitStutterLog(const char *const name, long long timeTaken) {

	lua_State *const L = *p_g_lua;
	lua_getglobal(L, "EEex_StutterDetector_Private_Times");            // 1 [ ..., EEex_StutterDetector_Private_Times ]

	lua_pushstring(L, name);                                           // 2 [ ..., EEex_StutterDetector_Private_Times, name ]
	lua_rawget(L, -2);                                                 // 2 [ ..., EEex_StutterDetector_Private_Times, EEex_StutterDetector_Private_Times[name] -> timeEntry ]

	if (!lua_isnil(L, -1)) {

		lua_rawgeti(L, -1, 1);                                         // 3 [ ..., EEex_StutterDetector_Private_Times, timeEntry, timeEntry[1] -> count ]
		const lua_Integer count = lua_tointeger(L, -1);
		lua_pop(L, 1);                                                 // 2 [ ..., EEex_StutterDetector_Private_Times, timeEntry ]
		lua_pushinteger(L, count + 1);                                 // 3 [ ..., EEex_StutterDetector_Private_Times, timeEntry, newCount ]
		lua_rawseti(L, -2, 1);                                         // 2 [ ..., EEex_StutterDetector_Private_Times, timeEntry ]

		lua_rawgeti(L, -1, 2);                                         // 3 [ ..., EEex_StutterDetector_Private_Times, timeEntry, timeEntry[1] -> totalTimeTaken ]
		const lua_Integer totalTimeTaken = lua_tointeger(L, -1);
		lua_pop(L, 1);                                                 // 2 [ ..., EEex_StutterDetector_Private_Times, timeEntry ]
		lua_pushinteger(L, totalTimeTaken + timeTaken);                // 3 [ ..., EEex_StutterDetector_Private_Times, timeEntry, newTotalTimeTaken ]
		lua_rawseti(L, -2, 2);                                         // 2 [ ..., EEex_StutterDetector_Private_Times, timeEntry ]

		lua_pop(L, 2);                                                 // 0 [ ... ]
	}
	else {

		lua_pop(L, 1);                                                 // 1 [ ..., EEex_StutterDetector_Private_Times ]
		lua_pushstring(L, name);                                       // 2 [ ..., EEex_StutterDetector_Private_Times, name ]
		lua_newtable(L);                                               // 3 [ ..., EEex_StutterDetector_Private_Times, name, {} -> timeEntry ]

		lua_pushinteger(L, 1);                                         // 4 [ ..., EEex_StutterDetector_Private_Times, name, timeEntry, 1 ]
		lua_rawseti(L, -2, 1);                                         // 3 [ ..., EEex_StutterDetector_Private_Times, name, timeEntry ]

		lua_pushinteger(L, timeTaken);                                 // 4 [ ..., EEex_StutterDetector_Private_Times, name, timeEntry, timeTaken ]
		lua_rawseti(L, -2, 2);                                         // 3 [ ..., EEex_StutterDetector_Private_Times, name, timeEntry ]

		lua_rawset(L, -3);                                             // 1 [ ..., EEex_StutterDetector_Private_Times ]

		lua_pop(L, 1);                                                 // 0 [ ... ]
	}

	if (topLevel) {

		lua_getglobal(L, "EEex_StutterDetector_Private_TopLevelTime"); // 1 [ ..., EEex_StutterDetector_Private_TopLevelTime ]
		const lua_Integer topLevelTime = lua_tointeger(L, -1);
		lua_pop(L, 1);                                                 // 0 [ ... ]
		lua_pushinteger(L, topLevelTime + timeTaken);                  // 1 [ ..., newTopLevelTime ]
		lua_setglobal(L, "EEex_StutterDetector_Private_TopLevelTime"); // 0 [ ... ]
	}
}

template<typename RetType>
RetType logStutter(const char* name, std::function<RetType()> func) {
	bool oldTopLevel = topLevel;
	topLevel = false;
	long long startTime = currentMicroseconds();
	RetType ret = func();
	long long timeTaken = currentMicroseconds() - startTime;
	topLevel = oldTopLevel;
	exitStutterLog(name, timeTaken);
	return ret;
}

template<>
void logStutter<void>(const char* name, std::function<void()> func) {
	bool oldTopLevel = topLevel;
	topLevel = false;
	long long startTime = currentMicroseconds();
	func();
	long long timeTaken = currentMicroseconds() - startTime;
	topLevel = oldTopLevel;
	exitStutterLog(name, timeTaken);
}

//----------------------------//
//          Lua Util          //
//----------------------------//

// Expects:       0 [ ... ]
// Returns: nReturn [ ..., return1, ..., returnN ]
bool luaCallProtected(lua_State* L, int nArg, int nReturn, std::function<void(int)> setup) {

	const int top = lua_gettop(L);

	lua_getglobal(L, "debug");                                                 //           1 [ debug ]
	lua_getfield(L, -1, "traceback");                                          //           2 [ debug, traceback ]

	setup(top);

	if (lua_pcallk(L, nArg, nReturn, top + 2, 0, nullptr) == LUA_OK) {
																			   // nReturn + 2 [ debug, traceback, return1, ..., returnN ]
		lua_remove(L, top + 2);                                                // nReturn + 1 [ debug, return1, ..., returnN ]
		lua_remove(L, top + 1);                                                //     nReturn [ return1, ..., returnN ]
		return true;
	}
	else {
																			   //           3 [ debug, traceback, errorMessage ]
		Print("[!][EEex.dll] luaCallProtected() - %s\n", lua_tostring(L, -1));
		lua_pop(L, 3);                                                         //           0 [ ]
		return false;
	}
}

// Expects: 0 [ ... ]
// Returns: 1 [ ..., result ]
void pushGlobalIndexedByInt(lua_State *const L, const char *const globalName, const lua_Integer key) {
	lua_getglobal(L, globalName); // 1 [ ..., global ]
	lua_pushinteger(L, key);      // 2 [ ..., global, key ]
	lua_rawget(L, -2);            // 2 [ ..., global, global[key] -> result ]
	lua_remove(L, -2);            // 1 [ ..., result ]
}

// Contract: Value index must be absolute
// Expects:  1 [ ..., t ]
// Returns:  1 [ ..., t ]
void setImmediateTableValue(lua_State *const L, const char *const fieldName, int absValueIndex) {
	lua_pushstring(L, fieldName);    // 2 [ ..., t, fieldName ]
	lua_pushvalue(L, absValueIndex); // 3 [ ..., t, fieldName, value ]
	lua_rawset(L, -3);               // 1 [ ..., t ]
}

union LuaTypeValue {
	const char* string;
	lua_Integer integer;
	bool boolean;
	LuaTypeValue(const char* string) : string(string) {}
	LuaTypeValue(lua_Integer integer) : integer(integer) {}
	LuaTypeValue(bool boolean) : boolean(boolean) {}
	LuaTypeValue() {}
};

struct LuaTypeContainer {
	bool valid;
	int type;
	LuaTypeValue value;
	LuaTypeContainer(int type, LuaTypeValue value) : type(type), value(value), valid(true) {}
	LuaTypeContainer(int type) : type(type), valid(true) {}
	LuaTypeContainer() : valid(false) {}
};

LuaTypeContainer getLuaTypeContainer(lua_State* L, int index) {
	const int type = lua_type(L, index);
	switch (type) {
		case LUA_TNUMBER: return LuaTypeContainer{ type, lua_tointeger(L, index) };
		case LUA_TSTRING: return LuaTypeContainer{ type, lua_tostring(L, index) };
		case LUA_TBOOLEAN: return LuaTypeContainer{ type, static_cast<bool>(lua_toboolean(L, index)) };
	}
	return LuaTypeContainer{ type };
}

//---------------------------------//
//          Userdata Util          //
//---------------------------------//

// Expects: n     [ ... ]
// Returns: n + 1 [ ..., t ]
void getUDAux(lua_State *const L, void *const ptr) {

	////////////////////////////////////////////////////////////
	// function EEex_GetUserDataAuxiliary(ptr)                //
	//     local auxiliary = EEex_UserDataAuxiliary[lud(lud)] //
	//     if not auxiliary then                              //
	//         auxiliary = {}                                 //
	//         EEex_UserDataAuxiliary[lud(ptr)] = auxiliary   //
	//     end                                                //
	//     return auxiliary                                   //
	// end                                                    //
	////////////////////////////////////////////////////////////

	lua_getglobal(L, "EEex_UserDataAuxiliary"); // 1 [ ..., EEex_UserDataAuxiliary ]
	lua_pushlightuserdata(L, ptr);              // 2 [ ..., EEex_UserDataAuxiliary, lud(ptr) -> lud ]
	lua_rawget(L, -2);                          // 2 [ ..., EEex_UserDataAuxiliary, EEex_UserDataAuxiliary[lud] -> t ]
	if (lua_isnil(L, -1)) {
		lua_pop(L, 1);                          // 1 [ ..., EEex_UserDataAuxiliary ]
		lua_newtable(L);                        // 2 [ ..., EEex_UserDataAuxiliary, {} -> t ]
		lua_pushlightuserdata(L, ptr);          // 3 [ ..., EEex_UserDataAuxiliary, t, lud(ptr) -> lud ]
		lua_pushvalue(L, -2);                   // 4 [ ..., EEex_UserDataAuxiliary, t, lud, t ]
		lua_rawset(L, -4);                      // 2 [ ..., EEex_UserDataAuxiliary, t ]
	}
	lua_remove(L, -2);                          // 1 [ ..., t ]
}

// Expects: n     [ ... ]
// Returns: n + 1 [ ..., castPtrUD ]
void getCastUD(lua_State* L, const char* castBaseName, const char* castFuncName, void* toCastPtr) {
	lua_getglobal(L, castFuncName);                        // 1 [ castFunc ]
	tolua_pushusertype_nocast(L, toCastPtr, castBaseName); // 2 [ castFunc, toCastPtr ]
	lua_call(L, 1, 1);                                     // 1 [ castPtrUD ]
}

void registerProjVFTableType(const TCHAR* patternName, std::pair<const char*, EEex::ProjectileType> info) {
	PatternValueHandle patternHandle;
	switch (sharedState().GetPatternValue(patternName, patternHandle)) {
		case PatternValueType::SINGLE: {
			projVFTableToType.emplace(sharedState().GetSinglePatternValue(patternHandle), info);
			break;
		}
		case PatternValueType::INVALID: {
			PrintT(TEXT("[!][EEex.dll] registerProjVFTableType() - Pattern [%s] missing, EEex will not work as expected\n"), patternName);
			break;
		}
		default: {
			PrintT(TEXT("[!][EEex.dll] registerProjVFTableType() - [%s].Type must be SINGLE\n"), patternName);
			break;
		}
	}
}

void pushGameObjectUD(lua_State* L, CGameObject* pGameObject) {
	if (pGameObject == nullptr) {
		lua_pushnil(L);
		return;
	}
	const char* userType;
	switch (pGameObject->m_objectType) {
		case CGameObjectType::AIBASE:        userType = "CGameAIBase";      break;
		case CGameObjectType::SOUND:         userType = "CGameSound";       break;
		case CGameObjectType::CONTAINER:     userType = "CGameContainer";   break;
		case CGameObjectType::SPAWNING:      userType = "CGameSpawning";    break;
		case CGameObjectType::DOOR:          userType = "CGameDoor";        break;
		case CGameObjectType::STATIC:        userType = "CGameStatic";      break;
		case CGameObjectType::SPRITE:        userType = "CGameSprite";      break;
		case CGameObjectType::OBJECT_MARKER: userType = "CObjectMarker";    break;
		case CGameObjectType::TRIGGER:       userType = "CGameTrigger";     break;
		case CGameObjectType::TILED_OBJECT:  userType = "CGameTiledObject"; break;
		case CGameObjectType::TEMPORAL:      userType = "CGameTemporal";    break;
		case CGameObjectType::AREA_AI:       userType = "CGameAIArea";      break;
		case CGameObjectType::FIREBALL:      userType = "CGameFireball3d";  break;
		case CGameObjectType::GAME_AI:       userType = "CGameAIGame";      break;
		default:                             userType = "CGameObject";      break;
	}
	tolua_pushusertype_nocast(L, pGameObject, userType);
}

void pushProjectileUD(lua_State* L, CProjectile* pProjectile) {
	if (pProjectile == nullptr) {
		lua_pushnil(L);
		return;
	}
	const uintptr_t vfptr = *reinterpret_cast<uintptr_t*>(pProjectile);
	if (auto found = projVFTableToType.find(vfptr); found != projVFTableToType.end()) {
		tolua_pushusertype_nocast(L, pProjectile, found->second.first);
	}
	else {
		tolua_pushusertype_nocast(L, pProjectile, "CProjectile");
	}
}

//-------------------------------//
//          Engine Util          //
//-------------------------------//

EngineVal<CString> fetchStrRef(uint strref) {
	EngineVal<STR_RES> res;
	(*p_g_pBaldurChitin)->m_cTlkTable.Fetch(strref, &*res, false);
	return EngineVal<CString>(&res->szText);
}

EngineVal<CString> getEffectSourceName(CGameEffect* pEffect) {
	if (pEffect->m_sourceType == 1) {
		// Spell
		EngineVal<CSpell> spell{ pEffect->m_sourceRes };
		CResSpell* res = spell->pRes;
		if (res->Demand()) {
			return fetchStrRef(res->pHeader->genericName);
		}
	}
	else if (pEffect->m_sourceType == 2) {
		// Item
		EngineVal<CItem> item{ pEffect->m_sourceRes, 0, 0, 0, 0, 0 };
		CResItem* res = item->pRes;
		if (res->Demand()) {
			if ((pEffect->m_flags & 0x80000000) != 0) {
				return fetchStrRef(res->pHeader->identifiedName);
			}
			else {
				return fetchStrRef(res->pHeader->genericName);
			}
		}
	}
	return "Unknown";
}

void displaySpriteMessage(CGameSprite* pTarget, EngineVal<CString> message) {

	CMessageDisplayText *const pMessageDisplayText = newEngineObj<CMessageDisplayText>(
		pTarget->GetName(false), &*message, 0xBED7D7, 0xBED7D7, -1, pTarget->m_id, pTarget->m_id);

	(*p_g_pBaldurChitin)->m_cMessageHandler.AddMessage(pMessageDisplayText, false);
}

bool isSprite(CGameObject* pObject, bool allowDead = false) {
	if (pObject != nullptr && pObject->m_objectType == CGameObjectType::SPRITE) {
		return allowDead || (reinterpret_cast<CGameSprite*>(pObject)->m_baseStats.m_generalState & 0xFC0) == 0;
	}
	return false;
}

CAIScript* getScriptLevel(CGameAIBase* pAIBase, int scriptLevel) {
	switch (scriptLevel) {
		case 0: return pAIBase->m_overrideScript;
		case 1: return pAIBase->m_areaScript;
		case 2: return pAIBase->m_specificsScript;
		case 4: return pAIBase->m_classScript;
		case 5: return pAIBase->m_raceScript;
		case 6: return pAIBase->m_generalScript;
		case 7: return pAIBase->m_defaultScript;
		default: return nullptr;
	}
}

//------------------------------//
//          Input Util          //
//------------------------------//

// Parses `str` and fills `result` with the resulting integer.
// Accepts leading whitespace, and supports hexadecimal (0x)
//   and octal (leading 0) notation.
// Returns 0 on failure, 1 on success.
bool parseInt(const char *const str, int& result) {

	if (*str == '\0') {
		return false;
	}

	char* endptr;
	const long val = strtol(str, &endptr, 0);

	if (*endptr != '\0') {
		return false;
	}

	if constexpr (sizeof(long) > sizeof(int)) {
		if (val < INT_MIN || val > INT_MAX) {
			return false;
		}
	}

	result = val;
	return true;
}

//------------------------//
//          EEex          //
//------------------------//

///////////////////
// START Drawing //
///////////////////

typedef void(__cdecl *uiDrawSliceFunc)(const SDL_Rect* dr, const SDL_Rect* r, const SDL_Rect* rClip, float scaleX, float scaleY, bool wide);

void __cdecl drawSlicedRect(const slicedRect& slicedRect, SDL_Rect* bounds, int alpha, SDL_Rect* rClip) {

	const CResRef pvrzResref { slicedRect.name };
	CResPVR *const pResPVR = reinterpret_cast<CResPVR*>(p_dimmGetResObject(&pvrzResref, 0x404, false));
	pResPVR->filtering = 0x2600;

	if (pResPVR->Demand() == nullptr) {
		return;
	}

	p_DrawPushState();
	p_DrawBindTexture(pResPVR->texture);
	p_DrawEnable(DrawFeature::DRAW_TEXTURE_2D);
	p_DrawEnable(DrawFeature::DRAW_BLEND);
	p_DrawBlendFunc(DrawBlend::DRAW_SRC_ALPHA, DrawBlend::DRAW_ONE_MINUS_SRC_ALPHA);
	p_DrawColor(0xFFFFFFFF);
	p_DrawAlpha(alpha << 0x18);

	const float scaleX = static_cast<float>(pResPVR->size.cx) / slicedRect.d.x;
	const float scaleY = static_cast<float>(pResPVR->size.cy) / slicedRect.d.y;

	// Draw Center

	SDL_Rect drawRect { bounds };

	if ((slicedRect.flags & 2) == 0) {
		// Normal
		drawRect.x += slicedRect.l.w;
		drawRect.y += slicedRect.t.h;
		drawRect.w -= slicedRect.l.w + slicedRect.r.w;
		drawRect.h -= slicedRect.t.h + slicedRect.b.h;
	}
	else {
		// Ugly hack for the tooltip box
		drawRect.x += (slicedRect.l.w + (slicedRect.l.w < 0 ? 3 : 0)) / 4;
		drawRect.y += (slicedRect.t.h + (slicedRect.t.h < 0 ? 3 : 0)) / 4;

		drawRect.w -=
			  (slicedRect.l.w + (slicedRect.l.w < 0 ? 3 : 0)) / 4
			+ (slicedRect.r.w + (slicedRect.r.w < 0 ? 3 : 0)) / 4;

		drawRect.h -=
			  (slicedRect.t.h + (slicedRect.t.h < 0 ? 3 : 0)) / 4
			+ (slicedRect.b.h + (slicedRect.b.h < 0 ? 3 : 0)) / 4;
	}

	p_drawSlice(&drawRect, &slicedRect.c, rClip, scaleX, scaleY, false);

	// Calculate side flags...

	int tileStartAdjust;
	uiDrawSliceFunc uiDrawSliceFunc;

	if ((slicedRect.flags & 1) == 0) {
		tileStartAdjust = 0;           // Normal positioning
		uiDrawSliceFunc = p_drawSlice; // Strech sides
	}
	else {
		tileStartAdjust = slicedRect.tl.w / 2; // Sink into corner pieces
		uiDrawSliceFunc = p_drawSliceSide;     // Tile sides
	}

	const int tileLengthAdjust = tileStartAdjust * 2;

	// Draw Top
	drawRect.x = bounds->x + slicedRect.tl.w - tileStartAdjust;
	drawRect.y = bounds->y + slicedRect.t.y;
	drawRect.w = bounds->w - slicedRect.tl.w - slicedRect.tr.w + tileLengthAdjust;
	drawRect.h = slicedRect.t.h;
	uiDrawSliceFunc(&drawRect, &slicedRect.t, rClip, scaleX, scaleY, true);

	// Draw Right
	drawRect.x = bounds->x + bounds->w - slicedRect.r.w;
	drawRect.y = bounds->y + slicedRect.tl.h - tileStartAdjust;
	drawRect.w = slicedRect.r.w;
	drawRect.h = bounds->h - slicedRect.tr.h - slicedRect.br.h + tileLengthAdjust;
	uiDrawSliceFunc(&drawRect, &slicedRect.r, rClip, scaleX, scaleY, false);

	// Draw Bottom
	drawRect.x = bounds->x + slicedRect.bl.w - tileStartAdjust;
	drawRect.y = bounds->y + bounds->h - slicedRect.b.h;
	drawRect.w = bounds->w - slicedRect.tl.w - slicedRect.tr.w + tileLengthAdjust;
	drawRect.h = slicedRect.b.h;
	uiDrawSliceFunc(&drawRect, &slicedRect.b, rClip, scaleX, scaleY, true);

	// Draw Left
	drawRect.x = bounds->x;
	drawRect.y = bounds->y + slicedRect.tl.h - tileStartAdjust;
	drawRect.w = slicedRect.l.w;
	drawRect.h = bounds->h - slicedRect.tr.h - slicedRect.br.h + tileLengthAdjust;
	uiDrawSliceFunc(&drawRect, &slicedRect.l, rClip, scaleX, scaleY, false);

	// Draw Top-Left
	drawRect.x = bounds->x + slicedRect.tl.x;
	drawRect.y = bounds->y + slicedRect.tl.y;
	drawRect.w = slicedRect.tl.w;
	drawRect.h = slicedRect.tl.h;
	p_drawSlice(&drawRect, &slicedRect.tl, rClip, scaleX, scaleY, false);

	// Draw Top-Right
	drawRect.x = bounds->x + bounds->w - slicedRect.tr.w;
	drawRect.y = bounds->y + slicedRect.tr.y;
	drawRect.w = slicedRect.tr.w;
	drawRect.h = slicedRect.tr.h;
	p_drawSlice(&drawRect, &slicedRect.tr, rClip, scaleX, scaleY, false);

	// Draw Bottom-Right
	drawRect.x = bounds->x + bounds->w - slicedRect.br.w;
	drawRect.y = bounds->y + bounds->h - slicedRect.br.h;
	drawRect.w = slicedRect.br.w;
	drawRect.h = slicedRect.br.h;
	p_drawSlice(&drawRect, &slicedRect.br, rClip, scaleX, scaleY, false);

	// Draw Bottom-Left
	drawRect.x = bounds->x + slicedRect.bl.x;
	drawRect.y = bounds->y + bounds->h - slicedRect.bl.h;
	drawRect.w = slicedRect.bl.w;
	drawRect.h = slicedRect.bl.h;
	p_drawSlice(&drawRect, &slicedRect.bl, rClip, scaleX, scaleY, false);

	p_DrawPopState();
}

void drawSlicedRectNum(int rectNum, SDL_Rect* bounds, int alpha, SDL_Rect* rClip) {

	if (rectNum < 0 || rectNum > 5) {
		rectNum = 0;
	}

	const slicedRect& slicedRect = (*p_slicedRects)[rectNum];
	drawSlicedRect(slicedRect, bounds, alpha, rClip);
}

// Expects: 4 [ rectNum, bounds, alpha, rClip ]
// Returns: 0 [ ]
void EEex::DrawSlicedRectNum(lua_State* L) {

	for (int i = lua_gettop(L); i < 4; ++i) {
		lua_pushnil(L);
	}

	/////////////
	// rectNum //
	/////////////

	if (lua_type(L, 1) != LUA_TNUMBER) {
		luaL_error(L, "[EEex.dll] EEex::DrawSlicedRectNum() - arg 1 (rectNum) must be a number");
		return;
	}
	const int rectNum = static_cast<int>(lua_tointeger(L, 1));

	////////////
	// bounds //
	////////////

	if (lua_type(L, 2) != LUA_TTABLE) {
		luaL_error(L, "[EEex.dll] EEex::DrawSlicedRectNum() - arg 2 (bounds) must be a table");
		return;
	}

	SDL_Rect bounds { 0, 0, 0, 0 };

	lua_rawgeti(L, 2, 1);
	if (lua_type(L, -1) != LUA_TNUMBER) {
		luaL_error(L, "[EEex.dll] EEex::DrawSlicedRectNum() - arg 2, index 1 (bounds.x) must be a number");
		return;
	}
	bounds.x = static_cast<int>(lua_tointeger(L, -1));

	lua_rawgeti(L, 2, 2);
	if (lua_type(L, -1) != LUA_TNUMBER) {
		luaL_error(L, "[EEex.dll] EEex::DrawSlicedRectNum() - arg 2, index 2 (bounds.y) must be a number");
		return;
	}
	bounds.y = static_cast<int>(lua_tointeger(L, -1));

	lua_rawgeti(L, 2, 3);
	if (lua_type(L, -1) != LUA_TNUMBER) {
		luaL_error(L, "[EEex.dll] EEex::DrawSlicedRectNum() - arg 2, index 3 (bounds.w) must be a number");
		return;
	}
	bounds.w = static_cast<int>(lua_tointeger(L, -1));

	lua_rawgeti(L, 2, 4);
	if (lua_type(L, -1) != LUA_TNUMBER) {
		luaL_error(L, "[EEex.dll] EEex::DrawSlicedRectNum() - arg 2, index 4 (bounds.h) must be a number");
		return;
	}
	bounds.h = static_cast<int>(lua_tointeger(L, -1));

	///////////
	// alpha //
	///////////

	int alpha = 255;
	if (const int type = lua_type(L, 3); type == LUA_TNUMBER) {
		alpha = static_cast<int>(lua_tointeger(L, 3));
	}
	else if (type != LUA_TNIL) {
		luaL_error(L, "[EEex.dll] EEex::DrawSlicedRectNum() - arg 3 (alpha) must be a number or nil");
		return;
	}

	///////////
	// rClip //
	///////////

	SDL_Rect rClip { bounds };

	if (const int type = lua_type(L, 4); type == LUA_TTABLE) {

		lua_rawgeti(L, 4, 1);
		if (lua_type(L, -1) != LUA_TNUMBER) {
			luaL_error(L, "[EEex.dll] EEex::DrawSlicedRectNum() - arg 4, index 1 (rClip.x) must be a number");
			return;
		}
		rClip.x = static_cast<int>(lua_tointeger(L, -1));

		lua_rawgeti(L, 4, 2);
		if (lua_type(L, -1) != LUA_TNUMBER) {
			luaL_error(L, "[EEex.dll] EEex::DrawSlicedRectNum() - arg 4, index 2 (rClip.y) must be a number");
			return;
		}
		rClip.y = static_cast<int>(lua_tointeger(L, -1));

		lua_rawgeti(L, 4, 3);
		if (lua_type(L, -1) != LUA_TNUMBER) {
			luaL_error(L, "[EEex.dll] EEex::DrawSlicedRectNum() - arg 4, index 3 (rClip.w) must be a number");
			return;
		}
		rClip.w = static_cast<int>(lua_tointeger(L, -1));

		lua_rawgeti(L, 4, 4);
		if (lua_type(L, -1) != LUA_TNUMBER) {
			luaL_error(L, "[EEex.dll] EEex::DrawSlicedRectNum() - arg 4, index 4 (rClip.h) must be a number");
			return;
		}
		rClip.h = static_cast<int>(lua_tointeger(L, -1));
	}
	else if (type != LUA_TNIL) {
		luaL_error(L, "[EEex.dll] EEex::DrawSlicedRectNum() - arg 4 (rClip) must be a table or nil");
		return;
	}

	/////////////
	// Do Call //
	/////////////

	drawSlicedRectNum(rectNum, &bounds, alpha, &rClip);
}

bool readRectTable(lua_State* L, const char* funcName, int argIndex, const char* fieldName, int tIndex, SDL_Rect& rectOut, bool allowNil = false) {

	tIndex = lua_absindex(L, tIndex);

	if (const int type = lua_type(L, tIndex); allowNil && type == LUA_TNIL) {
		return false;
	}
	else if (type != LUA_TTABLE) {
		luaL_error(L, "[EEex.dll] %s() - arg %d (%s) must be a table", funcName, argIndex, fieldName);
		return false;
	}

	lua_rawgeti(L, tIndex, 1);
	if (lua_type(L, -1) != LUA_TNUMBER) {
		luaL_error(L, "[EEex.dll] %s() - arg %d, index 1 (%s.x) must be a number", funcName, argIndex, fieldName);
		return false;
	}
	rectOut.x = static_cast<int>(lua_tointeger(L, -1));

	lua_rawgeti(L, tIndex, 2);
	if (lua_type(L, -1) != LUA_TNUMBER) {
		luaL_error(L, "[EEex.dll] %s() - arg %d, index 2 (%s.y) must be a number", funcName, argIndex, fieldName);
		return false;
	}
	rectOut.y = static_cast<int>(lua_tointeger(L, -1));

	lua_rawgeti(L, tIndex, 3);
	if (lua_type(L, -1) != LUA_TNUMBER) {
		luaL_error(L, "[EEex.dll] %s() - arg %d, index 3 (%s.w) must be a number", funcName, argIndex, fieldName);
		return false;
	}
	rectOut.w = static_cast<int>(lua_tointeger(L, -1));

	lua_rawgeti(L, tIndex, 4);
	if (lua_type(L, -1) != LUA_TNUMBER) {
		luaL_error(L, "[EEex.dll] %s() - arg %d, index 4 (%s.h) must be a number", funcName, argIndex, fieldName);
		return false;
	}
	rectOut.h = static_cast<int>(lua_tointeger(L, -1));
	return true;
}

bool readTableRectTable(lua_State* L, const char* funcName, const char* fieldName, int tIndex, SDL_Rect& rectOut, bool allowNil = false) {
	lua_pushstring(L, fieldName);
	lua_rawget(L, tIndex);
	return readRectTable(L, funcName, tIndex, fieldName, -1, rectOut, allowNil);
}

bool readPointTable(lua_State* L, const char* funcName, int argIndex, const char* fieldName, int tIndex, SDL_Point& pointOut, bool allowNil = false) {

	tIndex = lua_absindex(L, tIndex);

	if (const int type = lua_type(L, tIndex); allowNil && type == LUA_TNIL) {
		return false;
	}
	else if (type != LUA_TTABLE) {
		luaL_error(L, "[EEex.dll] %s() - arg %d (%s) must be a table", funcName, argIndex, fieldName);
		return false;
	}

	lua_rawgeti(L, tIndex, 1);
	if (lua_type(L, -1) != LUA_TNUMBER) {
		luaL_error(L, "[EEex.dll] %s() - arg %d, index 1 (%s.x) must be a number", funcName, argIndex, fieldName);
		return false;
	}
	pointOut.x = static_cast<int>(lua_tointeger(L, -1));

	lua_rawgeti(L, tIndex, 2);
	if (lua_type(L, -1) != LUA_TNUMBER) {
		luaL_error(L, "[EEex.dll] %s() - arg %d, index 2 (%s.y) must be a number", funcName, argIndex, fieldName);
		return false;
	}
	pointOut.y = static_cast<int>(lua_tointeger(L, -1));
	return true;
}

bool readTablePointTable(lua_State* L, const char* funcName, const char* fieldName, int tIndex, SDL_Point& pointOut, bool allowNil = false) {
	lua_pushstring(L, fieldName);
	lua_rawget(L, tIndex);
	return readPointTable(L, funcName, tIndex, fieldName, -1, pointOut, allowNil);
}

bool readTableStringCopy(lua_State* L, const char* funcName, const char* fieldName, int tIndex, const char*& stringOut, bool allowNil = false) {

	lua_pushstring(L, fieldName);
	lua_rawget(L, tIndex);

	if (const int type = lua_type(L, -1); allowNil && type == LUA_TNIL) {
		return false;
	}
	else if (type != LUA_TSTRING) {
		luaL_error(L, "[EEex.dll] %s() - arg %d (%s) must be a string", funcName, tIndex, fieldName);
		return false;
	}

	const char* str = lua_tostring(L, -1);
	const size_t strLen = strlen(str) + 1;
	char* strCopy = new char[strLen];
	memcpy(strCopy, str, strLen);

	stringOut = strCopy;
	return true;
}

bool readTableInt(lua_State* L, const char* funcName, const char* fieldName, int tIndex, int& intOut, bool allowNil = false) {

	lua_pushstring(L, fieldName);
	lua_rawget(L, tIndex);

	if (const int type = lua_type(L, -1); allowNil && type == LUA_TNIL) {
		return false;
	}
	else if (type != LUA_TNUMBER) {
		luaL_error(L, "[EEex.dll] %s() - arg %d (%s) must be a number", funcName, tIndex, fieldName);
		return false;
	}

	intOut = static_cast<int>(lua_tointeger(L, -1));
	return true;
}

std::unordered_map<std::string, slicedRect> rectInfos{};

void EEex::RegisterSlicedRect(lua_State* L) {

	//////////////
	// rectName //
	//////////////

	if (lua_type(L, 1) != LUA_TSTRING) {
		luaL_error(L, "[EEex.dll] EEex::RegisterSlicedRect() - arg 1 (rectName) must be a string");
		return;
	}

	const char* rectName = lua_tostring(L, 1);

	//////////////
	// rectInfo //
	//////////////

	slicedRect& slicedRect = rectInfos[rectName];
	readTableRectTable(  L, "EEex::RegisterSlicedRect", "topLeft",     2, slicedRect.tl    );
	readTableRectTable(  L, "EEex::RegisterSlicedRect", "top",         2, slicedRect.t     );
	readTableRectTable(  L, "EEex::RegisterSlicedRect", "topRight",    2, slicedRect.tr    );
	readTableRectTable(  L, "EEex::RegisterSlicedRect", "right",       2, slicedRect.r     );
	readTableRectTable(  L, "EEex::RegisterSlicedRect", "bottomRight", 2, slicedRect.br    );
	readTableRectTable(  L, "EEex::RegisterSlicedRect", "bottom",      2, slicedRect.b     );
	readTableRectTable(  L, "EEex::RegisterSlicedRect", "bottomLeft",  2, slicedRect.bl    );
	readTableRectTable(  L, "EEex::RegisterSlicedRect", "left",        2, slicedRect.l     );
	readTableRectTable(  L, "EEex::RegisterSlicedRect", "center",      2, slicedRect.c     );
	readTablePointTable( L, "EEex::RegisterSlicedRect", "dimensions",  2, slicedRect.d     );
	readTableStringCopy( L, "EEex::RegisterSlicedRect", "resref",      2, slicedRect.name  );
	readTableInt(        L, "EEex::RegisterSlicedRect", "flags",       2, slicedRect.flags );
}

// Expects: 4 [ rectName, bounds, alpha, rClip ]
void EEex::DrawSlicedRect(lua_State* L) {

	for (int i = lua_gettop(L); i < 4; ++i) {
		lua_pushnil(L);
	}

	//////////////
	// rectName //
	//////////////

	if (lua_type(L, 1) != LUA_TSTRING) {
		luaL_error(L, "[EEex.dll] EEex::DrawSlicedRect() - arg 1 (rectName) must be a string");
		return;
	}

	slicedRect* rectInfo;

	if (auto rectInfoPair = rectInfos.find(lua_tostring(L, 1)); rectInfoPair != rectInfos.end()) {
		rectInfo = &rectInfoPair->second;
	}
	else {
		luaL_error(L, "[EEex.dll] EEex::DrawSlicedRect() - arg 1 (rectName) not registered");
		return;
	}

	////////////
	// bounds //
	////////////

	SDL_Rect bounds;
	readRectTable(L, "EEex::DrawSlicedRect", 2, "bounds", 2, bounds);

	///////////
	// alpha //
	///////////

	int alpha = 255;
	if (const int type = lua_type(L, 3); type == LUA_TNUMBER) {
		alpha = static_cast<int>(lua_tointeger(L, 3));
	}
	else if (type != LUA_TNIL) {
		luaL_error(L, "[EEex.dll] EEex::DrawSlicedRect() - arg 3 (alpha) must be a number or nil");
		return;
	}

	///////////
	// rClip //
	///////////

	SDL_Rect rClip;
	if (!readRectTable(L, "EEex::DrawSlicedRect", 4, "rClip", 4, rClip, true)) {
		rClip = bounds;
	}

	drawSlicedRect(*rectInfo, &bounds, alpha, &rClip);
}

/////////////////
// END Drawing //
/////////////////


///////////////////////
// START MatchObject //
///////////////////////

__forceinline int operator&(EEex_MatchObjectFlags a, EEex_MatchObjectFlags b)
{
	return static_cast<__int32>(a) & static_cast<__int32>(b);
}

enum class EEex_CheckShortCircuitDirection
{
	BACKWARD = 0,
	FORWARD = 1,
	IMPOSSIBLE = 2,
};

// 3 [ ..., matchFunc, debug, traceback ]
bool EEex_RunMatchFunction(lua_State *const L, CGameObject *const pObject)
{
	lua_pushvalue(L, -3);                                                              // 4 [ ..., matchFunc, debug, traceback, matchFunc ]
	pushGameObjectUD(L, pObject);                                                      // 5 [ ..., matchFunc, debug, traceback, matchFunc, pObject ]
	lua_setglobal(L, "EEex_MatchObject");                                              // 4 [ ..., matchFunc, debug, traceback, matchFunc ]

	if (lua_pcallk(L, 0, 1, -2, 0, nullptr) != LUA_OK)
	{
																					   // 4 [ ..., matchFunc, debug, traceback, error ]
		Print("[!][EEex.dll] MatchObject - Runtime error: %s\n", lua_tostring(L, -1));
		lua_pop(L, 1);                                                                 // 3 [ ..., matchFunc, debug, traceback ]
		return false;
	}
																					   // 4 [ ..., matchFunc, debug, traceback, result ]
	const bool toReturn { static_cast<bool>(lua_toboolean(L, -1)) };
	lua_pop(L, 1);                                                                     // 3 [ ..., matchFunc, debug, traceback ]
	return toReturn;
}

bool EEex_CheckMatch(lua_State* L,
	// Loop data
	const EEex_CheckShortCircuitDirection shortCircuitDirection,
	long *const idArray, int *const distanceArray, const short nArray,
	// Area data
	CGameArea& area, const byte *const terrainTable,
	// Checking object
	const long objectID,
	// Caller data
	const CAIObjectType& callerType, const CPoint& callerPos, const CPoint& callerPosAdj,
	// Restrictions
	const bool bNearest, const short range, const int rangeSquared, const bool bCheckLOS,
	const bool bIgnoreNonSprites, const bool bIgnoreInvisible, const bool bIgnoreSleeping, const bool bIgnoreDead)
{
	CGameObject* object;
	if (CGameObjectArray::GetShare(objectID, &object) != 0) {
		return false;
	}

	const CGameObjectType objectType { object->virtual_GetObjectType() };

	if ((bIgnoreNonSprites && objectType != CGameObjectType::SPRITE) || !isAIBase(objectType)) {
		return false;
	}

	const CPoint& objectPos { object->m_pos };
	const CPoint objectPosAdj { objectPos.x, objectPos.y * 4/3 };

	const int yDiff { objectPosAdj.y - callerPosAdj.y };
	const int distanceSquared { square(objectPosAdj.x - callerPosAdj.x) + square(yDiff) };

	if (range != -1)
	{
		// Short-circuit loop based on the sorted nature of m_lVertSort*
		if (shortCircuitDirection == EEex_CheckShortCircuitDirection::BACKWARD)
		{
			if (yDiff < 0)
			{
				if (-yDiff > range) {
					return true;
				}
			}
			else if (yDiff > range) {
				return false;
			}
		}
		else if (shortCircuitDirection == EEex_CheckShortCircuitDirection::FORWARD)
		{
			if (yDiff >= 0)
			{
				if (yDiff > range) {
					return true;
				}
			}
			else if (-yDiff > range) {
				return false;
			}
		}

		if (distanceSquared > rangeSquared) {
			return false;
		}
	}

	if (objectType == CGameObjectType::SPRITE)
	{
		CGameSprite& sprite { *reinterpret_cast<CGameSprite*>(object) };
		CDerivedStats& stats { *sprite.GetActiveStats() };
		const uint generalState { stats.m_generalState };

		if (!sprite.m_active || !sprite.m_activeAI || !sprite.m_activeImprisonment
			|| (bIgnoreInvisible && ((generalState & 0x10) != 0 || stats.m_bSanctuary))
			|| (bIgnoreSleeping && (generalState & 1) != 0)
			|| (bIgnoreDead && (generalState & 0x800) != 0)
			|| !sprite.m_animation.m_animation->virtual_GetAboveGround()
			|| stats.m_cImmunitiesAIType.OnList(&callerType))
		{
			return false;
		}
	}

	if ((bCheckLOS && !area.CheckLOS(&callerPos, &objectPos, terrainTable, 0, range)) ||
		!EEex_RunMatchFunction(L, object))
	{
		return false;
	}

	for (short i { 0 }; i <= nArray; ++i)
	{
		if (bNearest)
		{
			if (distanceSquared >= distanceArray[i]) {
				continue;
			}
		}
		else if (distanceSquared <= distanceArray[i]) {
			continue;
		}

		const short slotsAfter { nArray - i };
		memmove(&idArray[i + 1], &idArray[i], sizeof(long) * slotsAfter);
		memmove(&distanceArray[i + 1], &distanceArray[i], sizeof(int) * slotsAfter);
		idArray[i] = object->m_id;
		distanceArray[i] = distanceSquared;
		return false;
	}

	return false;
}

long EEex::MatchObject(lua_State *const L, CGameObject *const pStartObject, const char *const matchChunk,
	const int nth, int range, const EEex_MatchObjectFlags flags)
{
	STUTTER_LOG_START(long, "EEex::MatchObject")

	if (pStartObject == nullptr || !isAIBase(pStartObject->virtual_GetObjectType())) {
		return -1;
	}

	CGameAIBase *const pStartAIBase { reinterpret_cast<CGameSprite*>(pStartObject) };
	CGameArea *const pArea { pStartAIBase->m_pArea };

	if (pArea == nullptr) {
		return -1;
	}

	const CTypedPtrList<CPtrList,long>::CNode *const pVertListPos { pStartAIBase->virtual_GetVertListPos() };

	if (pVertListPos == nullptr) {
		return -1;
	}

	if (nth < 0 || nth >= MAXBYTE)
	{
		Print("[!][EEex.dll] MatchObject - Nth %d invalid, must be [0-255]\n", nth);
		return -1;
	}

	int rangeSquared;
	bool bCheckLOS { (flags & EEex_MatchObjectFlags::IGNORE_LOS) == 0 };

	if (range == 0)
	{
		range = pStartAIBase->virtual_GetVisualRange();
		rangeSquared = square(range);
	}
	else if (range < 0)
	{
		if (range == -1) {
			bCheckLOS = false;
		}
		else
		{
			Print("[!][EEex.dll] MatchObject - Range %d invalid, use -1 to ignore\n", range);
			return -1;
		}
	}
	else if (range <= static_cast<int>(sqrt(INT_MAX)))
	{
		if (bCheckLOS)
		{
			if (const short callerVisualRange { pStartAIBase->virtual_GetVisualRange() };
				callerVisualRange < range)
			{
				range = callerVisualRange;
			}
		}
		rangeSquared = square(range);
	}
	else
	{
		Print("[!][EEex.dll] MatchObject - Range %d too large, use -1 to ignore\n", range);
		return -1;
	}

	if (luaL_loadstring(L, matchChunk) != LUA_OK)
	{                                                                              // 1 [ ..., error ]
		Print("[!][EEex.dll] MatchObject - Compile error: %s\n", lua_tostring(L, -1));
		lua_pop(L, 1);                                                             // 0 [ ... ]
		return -1;
	}
																					// 1 [ ..., matchFunc ]
	lua_getglobal(L, "debug");                                                     // 2 [ ..., matchFunc, debug ]
	lua_getfield(L, -1, "traceback");                                              // 3 [ ..., matchFunc, debug, traceback ]

	const short arraySize { static_cast<short>(nth) + 1 };
	long *const idArray { reinterpret_cast<long*>(alloca(sizeof(long) * arraySize + sizeof(int) * arraySize)) };
	int *const distanceArray { reinterpret_cast<int*>(idArray + arraySize) };

	const int distanceArrayDefault { (flags & EEex_MatchObjectFlags::FARTHEST) == 0
		? INT_MAX
		: INT_MIN };

	for (short i { 0 }; i <= nth; ++i)
	{
		idArray[i] = -1;
		distanceArray[i] = distanceArrayDefault;
	}

	const byte* pTerrainTable { pStartAIBase->virtual_GetTerrainTable() };

	const CAIObjectType& callerType { *pStartAIBase->virtual_GetAIType() };
	const CPoint& callerPos { pStartAIBase->m_pos };
	const CPoint callerPosAdj { callerPos.x, callerPos.y * 4/3 };

	const bool bNearest { (flags & EEex_MatchObjectFlags::FARTHEST) == 0 };
	const bool bIgnoreNonSprites { (flags & EEex_MatchObjectFlags::MATCH_NON_SPRITES) == 0 };
	const bool bIgnoreInvisible {
		(flags & EEex_MatchObjectFlags::IGNORE_INVISIBLE) != 0 ||
		((flags & EEex_MatchObjectFlags::MATCH_INVISIBLE) == 0 && !pStartAIBase->virtual_GetCanSeeInvisible())
	};
	const bool bIgnoreSleeping { (flags & EEex_MatchObjectFlags::MATCH_SLEEPING) == 0 };
	const bool bIgnoreDead { (flags & EEex_MatchObjectFlags::MATCH_DEAD) == 0 };

	#define check(nodeName, stepName, directionName) \
		while (nodeName != nullptr) \
		{ \
			if (EEex_CheckMatch(L, \
				/* Loop data */ \
				directionName, idArray, distanceArray, nth, \
				/* Area data */ \
				*pArea, pTerrainTable, \
				/* Checking object */ \
				nodeName->data, \
				/* Caller data */ \
				callerType, callerPos, callerPosAdj, \
				/* Restrictions */ \
				bNearest, range, rangeSquared, bCheckLOS, \
				bIgnoreNonSprites, bIgnoreInvisible, bIgnoreSleeping, bIgnoreDead)) \
			{ \
				break; \
			} \
			else { \
				nodeName = nodeName->stepName; \
			} \
		}

	if ((flags & EEex_MatchObjectFlags::MATCH_ONLY_BACKLIST) == 0)
	{
		const VertListType vertListType { pStartAIBase->virtual_GetVertListType() };
		if (vertListType == VertListType::LIST_FRONT)
		{
			CTypedPtrList<CPtrList,long>::CNode* pNode { pVertListPos->pPrev };
			check(pNode, pPrev, EEex_CheckShortCircuitDirection::BACKWARD);

			pNode = pVertListPos->pNext;
			check(pNode, pNext, EEex_CheckShortCircuitDirection::FORWARD);
		}
		else
		{
			CTypedPtrList<CPtrList,long>::CNode* pNextNode { pArea->m_lVertSort.m_pNodeHead };
			check(pNextNode, pNext, EEex_CheckShortCircuitDirection::FORWARD);
		}
	}

	long toReturn;

	if ((flags & EEex_MatchObjectFlags::MATCH_DEAD) != 0
		|| (flags & EEex_MatchObjectFlags::MATCH_BACKLIST) != 0
		|| (flags & EEex_MatchObjectFlags::PRIORITIZE_BACKLIST) != 0
		|| (flags & EEex_MatchObjectFlags::MATCH_ONLY_BACKLIST) != 0)
	{
		if ((flags & EEex_MatchObjectFlags::PRIORITIZE_BACKLIST) != 0
			|| (flags & EEex_MatchObjectFlags::MATCH_ONLY_BACKLIST) != 0)
		{
			CTypedPtrList<CPtrList,long>::CNode* pNextNode { pArea->m_lVertSortBack.m_pNodeHead };
			check(pNextNode, pNext, EEex_CheckShortCircuitDirection::IMPOSSIBLE);
			toReturn = idArray[nth];
		}
		else if (toReturn = idArray[nth]; toReturn == -1)
		{
			for (short i { 0 }; i <= nth; ++i)
			{
				idArray[i] = -1;
				distanceArray[i] = distanceArrayDefault;
			}

			CTypedPtrList<CPtrList,long>::CNode* pNextNode { pArea->m_lVertSortBack.m_pNodeHead };
			check(pNextNode, pNext, EEex_CheckShortCircuitDirection::IMPOSSIBLE);
			toReturn = idArray[nth];
		}
	}
	else {
		toReturn = idArray[nth];
	}

	#undef check

	lua_pop(L, 3);                                                                 // 0 [ ... ]
	return toReturn;

	STUTTER_LOG_END
}

/////////////////////
// END MatchObject //
/////////////////////

bool EEex::ShouldEffectBypassOp120(CGameEffect* pEffect) {
	return exEffectInfoMap[pEffect].bypassOp120;
}

int EEex::GetExtendedStatValue(CGameSprite* pSprite, int exStatId) {

	auto& exStatValues = exStatDataMap[pSprite->GetActiveStats()].exStatValues;
	if (auto exStatValuePair = exStatValues.find(exStatId); exStatValuePair != exStatValues.end()) {
		return exStatValuePair->second;
	}

	Print("[!][EEex.dll] EEex.GetExtendedStatValue() - Attempted to get invalid extended stat id: %d\n", exStatId);
	return 0;
}

bool EEex::IsPlayerScript(CAIScript* pScript) {
	return exScriptDataMap[pScript].bPlayerScript;
}

// Expects: n     [ ..., t, ... ]
// Returns: n + 1 [ ..., t, ..., tCopy ]
void EEex::DeepCopyIndex(lua_State* L, int tIndex) {

	STUTTER_LOG_START(void, "EEex::DeepCopyIndex")

	// Only deep-copying tables
	if (lua_type(L, tIndex) != LUA_TTABLE) {
		lua_pushvalue(L, tIndex);                 // 1 [ ..., t ]
		return;
	}

	tIndex = lua_absindex(L, tIndex);

	// Push return value (tCopy)
	// and processStack.
	lua_newtable(L);                              // 1 [ ..., tCopy ]
	lua_newtable(L);                              // 2 [ ..., tCopy, processStack ]
	int stackTop = 1;

	// Set initial toFillT (tCopy)
	lua_pushvalue(L, -2);                         // 3 [ ..., tCopy, processStack, tCopy -> toFillT ]
	lua_rawseti(L, -2, stackTop++);               // 2 [ ..., tCopy, processStack ]

	// Set initial toProcessT (t)
	lua_pushvalue(L, tIndex);                     // 3 [ ..., tCopy, processStack, t -> toProcessT ]
	lua_rawseti(L, -2, stackTop++);               // 2 [ ..., tCopy, processStack ]

	// Set initial iterK (nil)
	lua_pushnil(L);                               // 3 [ ..., tCopy, processStack, nil -> iterK ]
	lua_rawseti(L, -2, stackTop++);               // 2 [ ..., tCopy, processStack ]

	while (true) {
	continueOuterWhile:;

		// Read toFillT, toProcessT, and
		// iterK from processStack.
		lua_rawgeti(L, -1, stackTop - 3);         // 3 [ ..., tCopy, processStack, toFillT ]
		lua_rawgeti(L, -2, stackTop - 2);         // 4 [ ..., tCopy, processStack, toFillT, toProcessT ]
		lua_rawgeti(L, -3, stackTop - 1);         // 5 [ ..., tCopy, processStack, toFillT, toProcessT, iterK ]

		while (lua_next(L, -2)) {
													// 6 [ ..., tCopy, processStack, toFillT, toProcessT, k, v ]
			if (lua_type(L, -1) == LUA_TTABLE) {

				// Save iterK to resume later
				lua_pushvalue(L, -2);             // 7 [ ..., tCopy, processStack, toFillT, toProcessT, k, v, k ]
				lua_rawseti(L, -6, stackTop - 1); // 6 [ ..., tCopy, processStack, toFillT, toProcessT, k, v ]

				// Set next toFillT ({})
				lua_newtable(L);                  // 7 [ ..., tCopy, processStack, toFillT, toProcessT, k, v, nextToFillT ]
				lua_rawseti(L, -6, stackTop++);   // 6 [ ..., tCopy, processStack, toFillT, toProcessT, k, v ]

				// Set next toProcessT (v)
				lua_pushvalue(L, -1);             // 7 [ ..., tCopy, processStack, toFillT, toProcessT, k, v, nextToProcessT ]
				lua_rawseti(L, -6, stackTop++);   // 6 [ ..., tCopy, processStack, toFillT, toProcessT, k, v ]

				// Set next iterK (nil)
				lua_pushnil(L);                   // 7 [ ..., tCopy, processStack, toFillT, toProcessT, k, v, nil -> nextIterK ]
				lua_rawseti(L, -6, stackTop++);   // 6 [ ..., tCopy, processStack, toFillT, toProcessT, k, v ]

				// Jump to process subtable
				lua_pop(L, 4);                    // 2 [ ..., tCopy, processStack ]
				goto continueOuterWhile;
			}
			else {
				// toFillT[iterK] = v
				lua_pushvalue(L, -2);             // 7 [ ..., tCopy, processStack, toFillT, toProcessT, k, v, k ]
				lua_insert(L, -2);                // 7 [ ..., tCopy, processStack, toFillT, toProcessT, k, k, v ]
				lua_rawset(L, -5);                // 5 [ ..., tCopy, processStack, toFillT, toProcessT, k ]
			}
		}
													// 4 [ ..., tCopy, processStack, toFillT, toProcessT ]
		if (stackTop == 4) {
			// The top-level table doesn't have
			// a parent to store its value on,
			// deep copy done.
			lua_pop(L, 3);                        // 1 [ ..., tCopy ]
			return;
		}

		// Remove toFillT, toProcessT, and
		// iterK from processStack.
		lua_pushnil(L);                           // 5 [ ..., tCopy, processStack, toFillT, toProcessT, nil ]
		lua_rawseti(L, -4, --stackTop);           // 4 [ ..., tCopy, processStack, toFillT, toProcessT ]
		lua_pushnil(L);                           // 5 [ ..., tCopy, processStack, toFillT, toProcessT, nil ]
		lua_rawseti(L, -4, --stackTop);           // 4 [ ..., tCopy, processStack, toFillT, toProcessT ]
		lua_pushnil(L);                           // 5 [ ..., tCopy, processStack, toFillT, toProcessT, nil ]
		lua_rawseti(L, -4, --stackTop);           // 4 [ ..., tCopy, processStack, toFillT, toProcessT ]

		// parentToFillT[parentIterK] = toFillT
		lua_rawgeti(L, -3, stackTop - 3);         // 5 [ ..., tCopy, processStack, toFillT, toProcessT, parentToFillT ]
		lua_rawgeti(L, -4, stackTop - 1);         // 6 [ ..., tCopy, processStack, toFillT, toProcessT, parentToFillT, parentIterK ]
		lua_pushvalue(L, -4);                     // 7 [ ..., tCopy, processStack, toFillT, toProcessT, parentToFillT, parentIterK, toFillT ]
		lua_rawset(L, -3);                        // 5 [ ..., tCopy, processStack, toFillT, toProcessT, parentToFillT ]

		// Continue parent processing
		lua_pop(L, 3);                            // 2 [ ..., tCopy, processStack ]
	}

	STUTTER_LOG_END
}

void EEex::DeepCopy(lua_State* L) {
	EEex::DeepCopyIndex(L, 1);
	return;
}

bool EEex::IsDefaultAttackCursor() {

	CInfGame *const pGame = (*p_g_pBaldurChitin)->m_pObjectGame;
	CGameArea *const pArea = pGame->m_gameAreas[pGame->m_visibleArea];

	if (pArea == nullptr) {
		return false;
	}

	CGameObject* pObject;
	if (CGameObjectArray::GetShare(pArea->m_iPicked, &pObject) || pObject->m_objectType != CGameObjectType::SPRITE) {
		return false;
	}

	CGameSprite *const pSprite = reinterpret_cast<CGameSprite*>(pObject);

	return
	(
		pGame->m_nState == 0
		&&
		pGame->m_group.m_memberList.m_nCount != 0
		&&
		(
			(
				pGame->GetCharacterPortraitNum(pSprite->m_id) == -1
				&&
				!pGame->m_allies.Find(pSprite->m_id, nullptr)
				&&
				!pGame->m_familiars.Find(pSprite->m_id, nullptr)
				&&
				(
					pSprite->GetActiveStats()->m_nPuppetMasterId == -1
					||
					pSprite->m_typeAI.m_EnemyAlly > 15 // EA_CONTROLCUTOFF
				)
			)
			||
			(
				pGame->m_gameSave.m_bArenaMode
				&&
				!pSprite->InControl()
			)
		)
		&&
		(
			pSprite->m_typeAI.m_EnemyAlly >= 200 // EA_EVILCUTOFF
			||
			pSprite->m_typeAI.m_EnemyAlly == 28 // EA_GOODBUTRED
		)
	);
}

/////////////////////////////////
//          Overrides          //
/////////////////////////////////

void EEex::Override_bootstrapLua() {

	//*p_g_lua = luaL_newstate();
	lua_State *const L = luaState();
	*p_g_lua = L;

	//luaL_requiref(L, "_G", luaopen_base, 1);
	//lua_settop(L, -2);

	lua_pushcfunction(L, p_l_log_print);
	lua_setglobal(L, "print");

	//luaL_requiref(L, "table", luaopen_table, 1);
	//lua_settop(L, -2);

	//luaL_requiref(L, "string", luaopen_string, 1);
	//lua_settop(L, -2);

	//luaL_requiref(L, "bit32", luaopen_bit32, 1);
	//lua_settop(L, -2);

	//luaL_requiref(L, "math", luaopen_math, 1);
	//lua_settop(L, -2);

	//luaL_requiref(L, "debug", luaopen_debug, 1);
	//lua_settop(L, -2);

	lua_atpanic(L, p_panic);

	int result = luaL_loadstring(L,
R"(
options = {};
function SetPrivateProfileString( section, key, value )
	if options[ section ] == nil then options[ section ] = {} end
	options[ section ][ key ] = value;
end
)"
	);

	if (result == 0) {
		lua_pcallk(L, 0, -1, 0, 0, nullptr);
	}

	lua_pushcfunction(L, p_Chitin_GetSectionCallback);
	lua_setglobal(L, "Chitin_GetSectionCallback");

	result = luaL_loadstring(L,
R"(
function getOptionsSection(sectionName, functionPointer, batton)
	for index,value in pairs(options) do
		if(index == sectionName) then
			for index2,value2 in pairs(value) do
				Chitin_GetSectionCallback(functionPointer, index2, value2, batton)
			end
		end
	end
end
)"
	);

	if (result == 0) {
		lua_pcallk(L, 0, -1, 0, 0, nullptr);
	}

	result = luaL_loadstring(L,
R"(
languages = {}
function setLanguageVisible( locale )
	languages[locale] = {0, 0, locale}
end
)"
	);

	if (result == 0) {
		lua_pcallk(L, 0, -1, 0, 0, nullptr);
	}
}

int checkNoSavingThrowsAndEvasion(CGameEffect *const pEffect, CGameSprite *const pTarget) {

	if ((pEffect->m_savingThrow & 0x1F) == 0) {

		// .EFF [+0x5C] BIT2
		// Automatically set by:
		//   Targeting modes 3, 4, 5, 6, 7, and 8
		//   Secondary AoE projectiles

		if ((pEffect->m_flags & 4) != 0) {

			for (auto pNode = pTarget->m_equipedEffectList.m_pNodeHead; pNode != nullptr; pNode = pNode->pNext) {
				// CGameEffectEvadeAreaOfEffect
				if (pNode->data->m_effectId == 0x142) {
					pEffect->m_savingThrow >>= 5;
					goto checkStillNoSavingThrow;
				}
			}

			for (auto pNode = pTarget->m_timedEffectList.m_pNodeHead; pNode != nullptr; pNode = pNode->pNext) {
				// CGameEffectEvadeAreaOfEffect
				if (pNode->data->m_effectId == 0x142) {
					pEffect->m_savingThrow >>= 5;
				}
			}
		}

	checkStillNoSavingThrow:;
		if ((pEffect->m_savingThrow & 0x1F) == 0) {
			return true; // No saving throws defined or evaded
		}
	}

	return false; // Not evaded
}

int EEex::Override_CGameEffect_CheckSave(CGameEffect *const pEffect, CGameSprite *const pTarget,
	byte *const saveVSDeathRollRaw, byte *const saveVSWandsRollRaw, byte *const saveVSPolyRollRaw,
	byte *const saveVSBreathRollRaw, byte *const saveVSSpellRollRaw, byte *const resistMagicRollRaw)
{
	STUTTER_LOG_START(int, "EEex::Override_CGameEffect_CheckSave")

	bool extraFeedback = true;

	CBaldurChitin& chitin = **p_g_pBaldurChitin;
	CInfGame& game = *chitin.m_pObjectGame;
	CDerivedStats& targetStats = *pTarget->GetActiveStats();

	// State: Poison || Graphics: Display Special Effect Icon - Poisoned
	if (const uint nEffectId = pEffect->m_effectId;
		(nEffectId == 25 || (nEffectId == 142 && pEffect->m_dWFlags == 6))
		&& ((pTarget->m_nMirrorImages != 0 && (pEffect->m_savingThrow & 0x1000000) == 0) // Bypass mirror image
			|| targetStats.m_nStoneSkins > 0
			|| targetStats.m_nStoneSkinsGolem > 0
		))
	{
		if (extraFeedback) {
			displaySpriteMessage(pTarget, "Poison blocked.");
		}

		return false; // SAVE SUCCEEDED (EFFECT BLOCKED)
	}

	// v2.5
	//if (uint nResistFlags = pEffect->m_flags; (nResistFlags & 1) != 0 && (nResistFlags & 2) == 0) {
	//
	//	sbyte resistMagicRoll = *resistMagicRollRaw & 0x7F;
	//	short nMagicResistance = targetStats.m_nResistMagic;
	//
	//	if (resistMagicRoll < nMagicResistance) {
	//
	//		if ((*resistMagicRollRaw & 0x80) == 0) {
	//
	//			CMessageDisplayTextRef* pMessageDisplayTextRef = newEngineObj<CMessageDisplayTextRef>(
	//				pTarget->GetNameRef(), 0xF00519, 0xBED7D7, 0xBED7D7, -1, pTarget->m_id, pTarget->m_id);
	//
	//			chitin.m_cMessageHandler.AddMessage(pMessageDisplayTextRef, false);
	//			*resistMagicRollRaw = *resistMagicRollRaw | 0x80;
	//		}
	//
	//		return false;
	//	}
	//}

	const uint nResistFlags = pEffect->m_flags;
	const sbyte nResistMagicRoll = *resistMagicRollRaw & 0x7F;
	const short nResistMagic = targetStats.m_nResistMagic;
	const bool bMagicResisted = nResistMagicRoll < nResistMagic;

	// .EFF [+0x5C] BIT3
	// Automatically set by:
	//   Targeting modes 1, 2 (sometimes), and 9

	if ((nResistFlags & 8) != 0 && pEffect->m_sourceId == pTarget->m_id && bMagicResisted
		&& checkNoSavingThrowsAndEvasion(pEffect, pTarget))
	{
		return true; // SAVE FAILED (EFFECT ADDED)
	}

	if ((nResistFlags & 1) != 0 && (nResistFlags & 2) == 0 && bMagicResisted) {

		if ((*resistMagicRollRaw & 0x80) == 0) {

			if (extraFeedback) {
				EngineVal<CString> magicResStr = fetchStrRef(0xF00519);
				displaySpriteMessage(pTarget, std::format("{} ({:d} < {})",
					magicResStr->m_pchData, nResistMagicRoll, nResistMagic).c_str());
			}
			else {
				CMessageDisplayTextRef *const pMessageDisplayTextRef = newEngineObj<CMessageDisplayTextRef>(
					pTarget->GetNameRef(), 0xF00519, 0xBED7D7, 0xBED7D7, -1, pTarget->m_id, pTarget->m_id);

				chitin.m_cMessageHandler.AddMessage(pMessageDisplayTextRef, false);
			}

			*resistMagicRollRaw = *resistMagicRollRaw | 0x80;
		}

		return false; // SAVE SUCCEEDED (EFFECT BLOCKED)
	}

	// .EFF [0x50]
	// Automatically set by:
	//   CProjectileNewScorcher::ApplyEffectsToTarget()
	//     1 -> Target
	//     2 -> Bystander (standing in projectile path)

	if (const uint nJeremyIsAnIdiot = pEffect->m_JeremyIsAnIdiot;
			(nJeremyIsAnIdiot == 1 && (pEffect->m_savingThrow & 0x400) != 0)  // Ignore primary target
		|| (nJeremyIsAnIdiot == 2 && (pEffect->m_savingThrow & 0x800) != 0)) // Ignore secondary target
	{
		return false; // SAVE SUCCEEDED (EFFECT BLOCKED)
	}

	if (checkNoSavingThrowsAndEvasion(pEffect, pTarget)) {
		return true; // SAVE FAILED (EFFECT ADDED)
	}

	short nBestSaveStat = 20;
	int nBestSavesRoll = 0;
	uint saveFeedbackStrRef = 0;

	// Save vs. Death
	if ((pEffect->m_savingThrow & 4) != 0 && targetStats.m_nSaveVSDeath < nBestSaveStat) {

		nBestSaveStat = targetStats.m_nSaveVSDeath;
		nBestSavesRoll = *saveVSDeathRollRaw & 0x7F;

		// BUGFIX: The engine normally checks whether it should output "Save vs. Type" here
		//         via (nBestSaveStat <= nBestSavesRoll). This breaks when the modifiers
		//         later in the function change an initially failed save into a success.
		//
		if ((*saveVSDeathRollRaw & 0x80) == 0) {
			saveFeedbackStrRef = 0xF00517;
			*saveVSWandsRollRaw = *saveVSWandsRollRaw & 0x7F;
			*saveVSPolyRollRaw = *saveVSPolyRollRaw & 0x7F;
			*saveVSBreathRollRaw = *saveVSBreathRollRaw & 0x7F;
			*saveVSSpellRollRaw = *saveVSSpellRollRaw & 0x7F;
			*saveVSDeathRollRaw = *saveVSDeathRollRaw | 0x80;
		}
	}

	// Save vs. Wands
	if ((pEffect->m_savingThrow & 8) != 0 && targetStats.m_nSaveVSWands < nBestSaveStat) {

		nBestSaveStat = targetStats.m_nSaveVSWands;
		nBestSavesRoll = *saveVSWandsRollRaw & 0x7F;

		// BUGFIX: The engine normally checks whether it should output "Save vs. Type" here
		//         via (nBestSaveStat <= nBestSavesRoll). This breaks when the modifiers
		//         later in the function change an initially failed save into a success.
		//
		if ((*saveVSWandsRollRaw & 0x80) == 0) {
			saveFeedbackStrRef = 0xF0051B;
			*saveVSDeathRollRaw = *saveVSDeathRollRaw & 0x7F;
			*saveVSPolyRollRaw = *saveVSPolyRollRaw & 0x7F;
			*saveVSBreathRollRaw = *saveVSBreathRollRaw & 0x7F;
			*saveVSSpellRollRaw = *saveVSSpellRollRaw & 0x7F;
			*saveVSWandsRollRaw = *saveVSWandsRollRaw | 0x80;
		}
	}

	// Save vs. Poly
	if ((pEffect->m_savingThrow & 0x10) != 0 && targetStats.m_nSaveVSPoly < nBestSaveStat) {

		nBestSaveStat = targetStats.m_nSaveVSPoly;
		nBestSavesRoll = *saveVSPolyRollRaw & 0x7F;

		// BUGFIX: The engine normally checks whether it should output "Save vs. Type" here
		//         via (nBestSaveStat <= nBestSavesRoll). This breaks when the modifiers
		//         later in the function change an initially failed save into a success.
		//
		if ((*saveVSPolyRollRaw & 0x80) == 0) {
			saveFeedbackStrRef = 0xF00518;
			*saveVSDeathRollRaw = *saveVSDeathRollRaw & 0x7F;
			*saveVSWandsRollRaw = *saveVSWandsRollRaw & 0x7F;
			*saveVSBreathRollRaw = *saveVSBreathRollRaw & 0x7F;
			*saveVSSpellRollRaw = *saveVSSpellRollRaw & 0x7F;
			*saveVSPolyRollRaw = *saveVSPolyRollRaw | 0x80;
		}
	}

	// Save vs. Breath
	if ((pEffect->m_savingThrow & 2) != 0 && targetStats.m_nSaveVSBreath < nBestSaveStat) {

		nBestSaveStat = targetStats.m_nSaveVSBreath;
		nBestSavesRoll = *saveVSBreathRollRaw & 0x7F;

		// BUGFIX: The engine normally checks whether it should output "Save vs. Type" here
		//         via (nBestSaveStat <= nBestSavesRoll). This breaks when the modifiers
		//         later in the function change an initially failed save into a success.
		//
		if ((*saveVSBreathRollRaw & 0x80) == 0) {
			saveFeedbackStrRef = 0xF00516;
			*saveVSDeathRollRaw = *saveVSDeathRollRaw & 0x7F;
			*saveVSWandsRollRaw = *saveVSWandsRollRaw & 0x7F;
			*saveVSPolyRollRaw = *saveVSPolyRollRaw & 0x7F;
			*saveVSSpellRollRaw = *saveVSSpellRollRaw & 0x7F;
			*saveVSBreathRollRaw = *saveVSBreathRollRaw | 0x80;
		}
	}

	// Save vs. Spell
	if ((pEffect->m_savingThrow & 1) != 0 && targetStats.m_nSaveVSSpell < nBestSaveStat) {

		nBestSaveStat = targetStats.m_nSaveVSSpell;
		nBestSavesRoll = *saveVSSpellRollRaw & 0x7F;

		// BUGFIX: The engine normally checks whether it should output "Save vs. Type" here
		//         via (nBestSaveStat <= nBestSavesRoll). This breaks when the modifiers
		//         later in the function change an initially failed save into a success.
		//
		if ((*saveVSSpellRollRaw & 0x80) == 0) {
			saveFeedbackStrRef = 0xF0051A;
			*saveVSDeathRollRaw = *saveVSDeathRollRaw & 0x7F;
			*saveVSWandsRollRaw = *saveVSWandsRollRaw & 0x7F;
			*saveVSPolyRollRaw = *saveVSPolyRollRaw & 0x7F;
			*saveVSBreathRollRaw = *saveVSBreathRollRaw & 0x7F;
			*saveVSSpellRollRaw = *saveVSSpellRollRaw | 0x80;
		}
	}

	int nBestSavesRollTotal = nBestSavesRoll;
	OStringStreamA extraFeedbackStream{};
	bool alreadyOutputRoll = false;
	const char* feedbackSeparator = "";

	#define outputBonus(name, val)                                \
		if (!alreadyOutputRoll) {                                 \
			alreadyOutputRoll = true;                             \
			extraFeedbackStream << "Roll: " << nBestSavesRoll;    \
			feedbackSeparator = ", ";                             \
		}                                                         \
		extraFeedbackStream << feedbackSeparator << name << ": "; \
		if (val > 0) {                                            \
			extraFeedbackStream << "+";                           \
		}                                                         \
		extraFeedbackStream << val;                               \
		feedbackSeparator = ", ";

	// Improved Invisibility
	//
	// BUGFIX: The engine normally subtracts 4 from nBestSaveStat in the blocks above,
	//         however, this causes a bug when multiple saving throw types are
	//         selected, where a better saving throw stat must be better than or equal
	//         to the improved invisibility bonus (-4) to be used. This really doesn't
	//         matter since no vanilla spells use the mechanic, but fix it anyway in
	//         case some mod uses it.
	//
	if ((targetStats.m_generalState & 0x400000) != 0) {
		nBestSavesRollTotal += 4;
		outputBonus("Improved Invisibility", 4);
	}

	// .EFF [+0x44] - Effect save bonus
	const int nSaveMod = pEffect->m_saveMod;
	nBestSavesRollTotal += nSaveMod;
	if (nSaveMod != 0) {
		outputBonus("Spell Bonus", nSaveMod);
	}

	// Legacy of Bhaal - Removed in v2.6 as part of bugfix
	//if (game.m_options.m_bNightmareMode
	//	&& pTarget->virtual_GetAIType()->m_EnemyAlly >= 30) // GOODCUTOFF
	//{
	//	nBestSavesRoll += 5;
	//}

	// Mage specialist bonus vs. incoming spells
	const uint school = pEffect->m_school;
	if (school != 0 && school == game.m_ruleTables.MapCharacterSpecializationToSchool(
		pTarget->m_baseStats.m_mageSpecialization))
	{
		nBestSavesRollTotal += 2;
		outputBonus("Specialist vs. School", 2);
	}

	// op346
	if (school < 12) {
		const short nSchoolSaveBonus = targetStats.m_nSchoolSaveBonus[school];
		nBestSavesRollTotal += nSchoolSaveBonus;
		if (nSchoolSaveBonus != 0) {
			outputBonus("Creature vs. School", nSchoolSaveBonus);
		}
	}

	CGameSprite* pSourceSprite = nullptr;

	// op219
	if (CGameObject* pSourceObject;
		pEffect->m_sourceId != -1 && CGameObjectArray::GetShare(pEffect->m_sourceId, &pSourceObject) == 0
		&& pSourceObject->virtual_GetObjectType() == CGameObjectType::SPRITE)
	{
		pSourceSprite = reinterpret_cast<CGameSprite*>(pSourceObject);
		const CAIObjectType* pSourceAIType = pSourceObject->virtual_GetAIType();
		const CSelectiveBonus* pFoundBonus = nullptr;

		for (auto pNode = targetStats.m_cProtectionList.m_pNodeHead; pNode != nullptr; pNode = pNode->pNext) {

			const CSelectiveBonus* pBonus = pNode->data;

			// type, checkForNonSprites, noNonSprites, deathMatchAllowance
			if (pSourceAIType->OfType(&pBonus->m_type, false, false, false)) {
				pFoundBonus = pBonus;
				break;
			}
		}

		const short nAITypeBonus = pFoundBonus != nullptr ? static_cast<short>(pFoundBonus->m_bonus) : 0;
		nBestSavesRollTotal += nAITypeBonus;
		if (nAITypeBonus != 0) {
			const CAIObjectType& type = pFoundBonus->m_type;
			const char* bonusName;
			if (type.m_EnemyAlly != 0) {
				bonusName = "Creature vs. Allegiance";
			}
			else if (type.m_General != 0) {
				bonusName = "Creature vs. General";
			}
			else if (type.m_Race != 0) {
				bonusName = "Creature vs. Race";
			}
			else if (type.m_Class != 0) {
				bonusName = "Creature vs. Class";
			}
			else if (type.m_Specifics != 0) {
				bonusName = "Creature vs. Specifics";
			}
			else if (type.m_Gender != 0) {
				bonusName = "Creature vs. Gender";
			}
			else if (type.m_Alignment != 0) {
				bonusName = "Creature vs. Alignment";
			}
			else {
				bonusName = "Creature vs. Everyone";
			}
			outputBonus(bonusName, nAITypeBonus);
		}
	}

	if (nBestSaveStat <= nBestSavesRollTotal) {

		if (saveFeedbackStrRef != 0 && (targetStats.m_generalState & 0x800) == 0) {

			if (extraFeedback) {

				EngineVal<CString> saveStr = fetchStrRef(saveFeedbackStrRef);
				const std::string extraFeedbackStr = extraFeedbackStream.str();

				EngineVal<CString> sourceName = getEffectSourceName(pEffect);
				EngineVal<CString> name = "Unknown";

				if (pSourceSprite != nullptr) {
					*name = pSourceSprite->GetName(true);
				}

				if (extraFeedbackStr.empty()) {
					displaySpriteMessage(pTarget, std::format("{} ({}: {}) : {} <= {}", saveStr->m_pchData,
						sourceName->m_pchData, name->m_pchData, nBestSaveStat, nBestSavesRollTotal).c_str());
				}
				else {
					displaySpriteMessage(pTarget, std::format("{} ({}: {}) : {} <= {} ({})", saveStr->m_pchData,
						sourceName->m_pchData, name->m_pchData, nBestSaveStat, nBestSavesRollTotal, extraFeedbackStr).c_str());
				}
			}
			else {

				if (const uint nTextLevel = game.m_options.m_nEffectTextLevel; (nTextLevel & 1) == 0)
				{
					if ((nTextLevel & 8) != 0) {

						//     Options->Gameplay->Feedback->To-Hit Rolls  [Disabled]
						// and Options->Gameplay->Feedback->State Changes [Enabled]
						// (default config)

						CMessageDisplayTextRef *const pMessageDisplayTextRef = newEngineObj<CMessageDisplayTextRef>(
							pTarget->GetNameRef(), saveFeedbackStrRef, 0xBED7D7, 0xBED7D7, -1, pTarget->m_id, pTarget->m_id);

						chitin.m_cMessageHandler.AddMessage(pMessageDisplayTextRef, false);
					}
				}
				else {

					// Options->Gameplay->Feedback->To-Hit Rolls [Enabled]

					displaySpriteMessage(pTarget, std::format("{} : {}",
						fetchStrRef(saveFeedbackStrRef)->m_pchData, nBestSavesRollTotal).c_str());
				}
			}
		}

		return false; // SAVE SUCCEEDED (EFFECT BLOCKED)
	}

	return true; // SAVE FAILED (EFFECT ADDED)

	STUTTER_LOG_END
}

void __cdecl EEex::Override_chWriteInifile() {
	if (*p_optionsHaveChanged != 0) {
		_iobuf *const buf = p_OpenIniFile("Baldur.lua", "wb");
		if (buf != nullptr) {
			lua_State *const L = luaState();
			lua_getglobal(L, "printIni");
			lua_pushlightuserdata(L, buf);
			lua_callk(L, 1, 0, 0, nullptr);
			wrapper_fclose(buf);
		}
	}
	*p_optionsHaveChanged = 0;
}

int __cdecl EEex::Override_Infinity_WriteINILine(lua_State* L) {
	_iobuf *const buf = reinterpret_cast<_iobuf*>(lua_touserdata(L, 1));
	const char *const line = lua_tolstring(L, 2, nullptr);
	wrapper_fprintf(buf, "%s", line);
	return 0;
}

int CAICondition::Override_Hold(CTypedPtrList<CPtrList, CAITrigger*>* pTriggerList, CGameAIBase* pCaller)
{
	auto pNode = this->m_triggerList.m_pNodeHead;
	if (pNode == nullptr) {
		return 1;
	}

	bool bRet = false;
	int nORCounter = 0;

	bool bNextTriggerObject = false;
	CGameAIBase* pNextTriggerObject = nullptr;

	// EEex
	int nTrigger = 0;

	do
	{
		if (nORCounter <= 0) {
			bRet = false;
		}

		CAITrigger *const pTrigger = pNode->data;
		const short nTriggerID = pTrigger->m_triggerID;

		if (nTriggerID == 0x4089) // OR
		{
			nORCounter = pTrigger->m_specificID;
		}
		else if (nTriggerID == 0x40E0) // NextTriggerObject
		{
			EngineVal<CAIObjectType> nextTriggerObjectType{ &pTrigger->m_triggerCause };
			nextTriggerObjectType->Decode(pCaller);

			bNextTriggerObject = true;
			pNextTriggerObject = reinterpret_cast<CGameAIBase*>(nextTriggerObjectType->GetShareType(pCaller, CGameObjectType::AIBASE, 0));

			if (pNextTriggerObject != nullptr && nORCounter < 1) {
				bRet = true;
			}
		}
		else {
			--nORCounter;
		}

		if (nTriggerID != 0x40E0) // NOT NextTriggerObject
		{
			if (bNextTriggerObject)
			{
				if (pNextTriggerObject != nullptr)
				{
					// EEex
					if (EEex::bInTrackedResponse)
					{
						for (auto callback : triggerHitCallbacks) {
							callback(nTrigger);
						}
					}

					bNextTriggerObject = false;
					const bool bTriggerHolds = this->TriggerHolds(pTrigger, pTriggerList, pNextTriggerObject);
					bRet |= bTriggerHolds;

					// EEex
					if (EEex::bInTrackedResponse)
					{
						for (auto callback : triggerEvaluatedCallbacks) {
							callback(bTriggerHolds);
						}
					}
				}
			}
			else
			{
				// EEex
				if (EEex::bInTrackedResponse)
				{
					for (auto callback : triggerHitCallbacks) {
						callback(nTrigger);
					}
				}

				const bool bTriggerHolds = this->TriggerHolds(pTrigger, pTriggerList, pCaller);
				bRet |= bTriggerHolds;

				// EEex
				if (EEex::bInTrackedResponse)
				{
					for (auto callback : triggerEvaluatedCallbacks) {
						callback(bTriggerHolds);
					}
				}
			}
		}

		if (!bRet && nORCounter < 1) // Fail
		{
			break;
		}

		pNode = pNode->pNext;

		// EEex
		++nTrigger;
	}
	while (pNode != nullptr);

	return bRet;
}

int CAICondition::Override_TriggerHolds(CAITrigger* pTrigger, CTypedPtrList<CPtrList, CAITrigger*>* pTriggerList, CGameAIBase* pCaller)
{
	bool nRet = false;

	if ((pTrigger->m_triggerID & 0x4000) == 0) // Event-driven trigger
	{
		for (auto pNode = pTriggerList->m_pNodeHead; pNode != nullptr; pNode = pNode->pNext)
		{
			pTrigger->m_triggerCause.Decode(pCaller);
			nRet = pNode->data->OfType(pTrigger);

			if ((pTrigger->m_flags & 1) != 0) // Inverted
			{
				nRet = !nRet;
			}

			if (nRet) {
				break;
			}
		}
	}
	else // Status trigger
	{
		nRet = pCaller->virtual_EvaluateStatusTrigger(pTrigger);

		if ((pTrigger->m_flags & 1) != 0) // Inverted
		{
			nRet = !nRet;
		}
	}

	return nRet;
}

/////////////////////////////
//          Hooks          //
/////////////////////////////

////////////////
// Game State //
////////////////

void initStats();

void EEex::GameState_Hook_OnInitialized() {

	STUTTER_LOG_START(void, "EEex::GameState_Hook_OnInitialized")

	initStats();

	lua_State *const L = luaState();
	luaCallProtected(L, 0, 0, [&](int _) {
		lua_getglobal(L, "EEex_GameState_LuaHook_OnInitialized");
	});

	STUTTER_LOG_END
}

void addNextUUIDLocal(CVariableHash* pVariables) {
	EngineVal<CVariable> variable;
	variable->m_name.set("EEEX_NEXTUUID");
	variable->m_intValue = static_cast<int>(nextUUID);
	variable->m_dWValue = static_cast<unsigned int>(nextUUID >> 32);
	pVariables->AddKey(variable);
}

void updateNextUUIDLocal() {

	CVariableHash *const pGlobalVariables = &(*p_g_pBaldurChitin)->m_pObjectGame->m_variables;
	CVariable *const pVariable = pGlobalVariables->FindKey(EngineVal<CString, false>{"EEEX_NEXTUUID"});

	if (pVariable == nullptr) {
		addNextUUIDLocal(pGlobalVariables);
	}
	else {
		pVariable->m_intValue = static_cast<int>(nextUUID);
		pVariable->m_dWValue = static_cast<unsigned int>(nextUUID >> 32);
	}
}

void EEex::GameState_Hook_OnAfterGlobalVariablesUnmarshalled() {

	CVariableHash *const pGlobalVariables = &(*p_g_pBaldurChitin)->m_pObjectGame->m_variables;
	CVariable *const pVariable = pGlobalVariables->FindKey(EngineVal<CString, false>{"EEEX_NEXTUUID"});

	if (pVariable == nullptr) {
		nextUUID = 0;
		addNextUUIDLocal(pGlobalVariables);
	}
	else {
		nextUUID = (static_cast<uint64_t>(pVariable->m_dWValue) << 32) | pVariable->m_intValue;
	}
}

///////////
// Stats //
///////////

void EEex::Stats_Hook_OnConstruct(CDerivedStats* pStats) {
	STUTTER_LOG_START(void, "EEex::Stats_Hook_OnConstruct")
	STUTTER_LOG_END
}

void EEex::Stats_Hook_OnDestruct(CDerivedStats* pStats) {

	STUTTER_LOG_START(void, "EEex::Stats_Hook_OnDestruct")

	exStatDataMap.erase(pStats);

	STUTTER_LOG_END
}

// Assuming m_derivedStats is being reloaded (true as of v2.6)
void EEex::Stats_Hook_OnReload(CGameSprite* pSprite) {

	STUTTER_LOG_START(void, "EEex::Stats_Hook_OnReload")

	ExStatData& exStatData = exStatDataMap[&pSprite->m_derivedStats];

	// op280
	exStatData.forcedWildSurgeNumber = 0;
	exStatData.suppressWildSurgeVisuals = false;

	// op401
	auto& exStatValues = exStatData.exStatValues;
	for (auto& [id, info] : exStatInfoMap) {
		exStatValues[id] = info.def;
	}

	// op403
	exStatData.screenEffects.clear();

	// op408
	exStatData.projectileMutatorEffects.clear();

	// op409
	exStatData.enableActionListenerEffects.clear();

	STUTTER_LOG_END
}

void EEex::Stats_Hook_OnEqu(CDerivedStats* pStats, CDerivedStats* pOtherStats) {

	STUTTER_LOG_START(void, "EEex::Stats_Hook_OnEqu")

	ExStatData& exStatData = exStatDataMap[pStats];
	ExStatData& otherExStatData = exStatDataMap[pOtherStats];

	// op280
	exStatData.forcedWildSurgeNumber = otherExStatData.forcedWildSurgeNumber;
	exStatData.suppressWildSurgeVisuals = otherExStatData.suppressWildSurgeVisuals;

	// op401
	auto& exStatValues = exStatData.exStatValues;
	auto& otherExStatValues = otherExStatData.exStatValues;

	for (auto& [id, info] : exStatInfoMap) {
		exStatValues[id] = otherExStatValues[id];
	}

	// op403
	auto& screenEffects = exStatData.screenEffects;
	auto& otherScreenEffects = otherExStatData.screenEffects;
	screenEffects.clear();

	for (auto pOtherEffect : otherScreenEffects) {
		screenEffects.emplace_back(pOtherEffect);
	}

	// op408
	auto& projectileMutatorEffects = exStatData.projectileMutatorEffects;
	auto& otherProjectileMutatorEffects = otherExStatData.projectileMutatorEffects;
	projectileMutatorEffects.clear();

	for (auto pOtherProjectileMutatorEffects : otherProjectileMutatorEffects) {
		projectileMutatorEffects.emplace_back(pOtherProjectileMutatorEffects);
	}

	// op409
	auto& enableActionListenerEffects = exStatData.enableActionListenerEffects;
	auto& otherEnableActionListenerEffects = otherExStatData.enableActionListenerEffects;
	enableActionListenerEffects.clear();

	for (auto& otherEnableActionListener : otherEnableActionListenerEffects) {
		auto& data = enableActionListenerEffects.emplace_back();
		strcpy_s(data.funcName, sizeof(data.funcName), otherEnableActionListener.funcName);
		data.pEffect = otherEnableActionListener.pEffect;
	}

	STUTTER_LOG_END
}

void EEex::Stats_Hook_OnPlusEqu(CDerivedStats* pStats, CDerivedStats* pOtherStats) {

	STUTTER_LOG_START(void, "EEex::Stats_Hook_OnPlusEqu")

	ExStatData& exStatData = exStatDataMap[pStats];
	ExStatData& otherExStatData = exStatDataMap[pOtherStats];

	// op280
	if (otherExStatData.forcedWildSurgeNumber != 0) {
		exStatData.forcedWildSurgeNumber = otherExStatData.forcedWildSurgeNumber;
	}

	if (otherExStatData.suppressWildSurgeVisuals) {
		exStatData.suppressWildSurgeVisuals = true;
	}

	// op401
	auto& exStatValues = exStatData.exStatValues;
	auto& otherExStatValues = otherExStatData.exStatValues;
	for (auto& [id, info] : exStatInfoMap) {
		int& val = exStatValues[id];
		val = clamp(clampedSum(val, otherExStatValues[id]), info.min, info.max);
	}

	// op403
	auto& screenEffects = exStatData.screenEffects;
	auto& otherScreenEffects = otherExStatData.screenEffects;
	for (auto pOtherEffect : otherScreenEffects) {
		screenEffects.emplace_back(pOtherEffect);
	}

	// op408
	auto& projectileMutatorEffects = exStatData.projectileMutatorEffects;
	auto& otherProjectileMutatorEffects = otherExStatData.projectileMutatorEffects;
	for (auto pOtherProjectileMutatorEffects : otherProjectileMutatorEffects) {
		projectileMutatorEffects.emplace_back(pOtherProjectileMutatorEffects);
	}

	// op409
	auto& enableActionListenerEffects = exStatData.enableActionListenerEffects;
	auto& otherEnableActionListenerEffects = otherExStatData.enableActionListenerEffects;
	for (auto& otherEnableActionListener : otherEnableActionListenerEffects) {
		auto& data = enableActionListenerEffects.emplace_back();
		strcpy_s(data.funcName, sizeof(data.funcName), otherEnableActionListener.funcName);
		data.pEffect = otherEnableActionListener.pEffect;
	}

	STUTTER_LOG_END
}

int EEex::Stats_Hook_OnGettingUnknown(CDerivedStats* pStats, int nStatId) {

	STUTTER_LOG_START(int, "EEex::Stats_Hook_OnGettingUnknown")

	auto& exStatValues = exStatDataMap[pStats].exStatValues;
	if (auto exStatValuePair = exStatValues.find(nStatId); exStatValuePair != exStatValues.end()) {
		return exStatValuePair->second;
	}

	return 0;

	STUTTER_LOG_END
}

////////////
// Opcode //
////////////

// op101 - Allow saving throw BIT23 to bypass opcode #101
bool EEex::Opcode_Hook_Op101_ShouldEffectBypassImmunity(CGameEffect* pEffect) {

	STUTTER_LOG_START(bool, "EEex::Opcode_Hook_Op101_ShouldEffectBypassImmunity")

	return (pEffect->m_savingThrow & 0x800000) != 0;

	STUTTER_LOG_END
}

// op248
void EEex::Opcode_Hook_OnOp248AddTail(CGameEffect* pOp248, CGameEffect* pEffect) {

	STUTTER_LOG_START(void, "EEex::Opcode_Hook_OnOp248AddTail")

	if ((pOp248->m_special & 1) != 0) {
		exEffectInfoMap[pEffect].bypassOp120 = true;
	}

	STUTTER_LOG_END
}

// op249
void EEex::Opcode_Hook_OnOp249AddTail(CGameEffect* pOp249, CGameEffect* pEffect) {

	STUTTER_LOG_START(void, "EEex::Opcode_Hook_OnOp249AddTail")

	if ((pOp249->m_special & 1) != 0) {
		exEffectInfoMap[pEffect].bypassOp120 = true;
	}

	STUTTER_LOG_END
}

// op280
void EEex::Opcode_Hook_Op280_BeforeApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite) {

	STUTTER_LOG_START(void, "EEex::Opcode_Hook_Op280_BeforeApplyEffect")

	ExStatData& exStatData = exStatDataMap[&pSprite->m_derivedStats];
	exStatData.forcedWildSurgeNumber = pEffect->m_effectAmount;
	exStatData.suppressWildSurgeVisuals = pEffect->m_special != 0;

	STUTTER_LOG_END
}

// Return:
//      0 => Don't override wild surge number
//     !0 => Override wild surge number
int EEex::Opcode_Hook_Op280_GetForcedWildSurgeNumber(CGameSprite* pSprite) {

	STUTTER_LOG_START(int, "EEex::Opcode_Hook_Op280_GetForcedWildSurgeNumber")

	return exStatDataMap[&pSprite->m_derivedStats].forcedWildSurgeNumber;

	STUTTER_LOG_END
}

// Return:
//     false => Don't suppress wild surge feedback string and visuals
//     true  => Suppress wild surge feedback string and visuals
bool EEex::Opcode_Hook_Op280_ShouldSuppressWildSurgeVisuals(CGameSprite* pSprite) {

	STUTTER_LOG_START(bool, "EEex::Opcode_Hook_Op280_ShouldSuppressWildSurgeVisuals")

	return exStatDataMap[&pSprite->m_derivedStats].suppressWildSurgeVisuals;

	STUTTER_LOG_END
}

// New op400
int EEex::Opcode_Hook_SetTemporaryAIScript_ApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite) {

	STUTTER_LOG_START(int, "EEex::Opcode_Hook_SetTemporaryAIScript_ApplyEffect")

	if (pEffect->m_firstCall == 0) {
		return 1;
	}

	const int param2 = pEffect->m_dWFlags;
	if (param2 < 0 || param2 > 7 || param2 == 3) {
		// Engine fails to call OnRemove() if an effect was applied with immediateResolve = 1
		// and it immediately returns from ApplyEffect() with m_done = 1
		pEffect->m_done = 1;
		return 1;
	}

	pEffect->m_firstCall = 0;

	if (CAIScript *const pExistingScript = getScriptLevel(pSprite, param2);
		pExistingScript != nullptr)
	{
		pEffect->m_effectAmount2 = exScriptDataMap[pExistingScript].bPlayerScript;
		pEffect->m_res2 = pExistingScript->cResRef;
	}
	else {
		pEffect->m_res2 = "";
	}

	CAIScript *const pNewScript = pEffect->m_res.m_resRef[0] != '\0'
		? newEngineObj<CAIScript>(pEffect->m_res, 0)
		: nullptr;

	pSprite->virtual_SetScript(param2, pNewScript);
	return 1;

	STUTTER_LOG_END
}

void EEex::Opcode_Hook_SetTemporaryAIScript_OnRemove(CGameEffect* pEffect, CGameSprite* pSprite) {

	STUTTER_LOG_START(void, "EEex::Opcode_Hook_SetTemporaryAIScript_OnRemove")

	if (pEffect->m_firstCall == 0) {

		CAIScript *const pScript = pEffect->m_res2.m_resRef[0] != '\0'
			? newEngineObj<CAIScript>(pEffect->m_res2, pEffect->m_effectAmount2)
			: nullptr;

		pSprite->virtual_SetScript(pEffect->m_dWFlags, pScript);
	}

	STUTTER_LOG_END
}

// New op401
int EEex::Opcode_Hook_SetExtendedStat_ApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite) {

	STUTTER_LOG_START(int, "EEex::Opcode_Hook_SetExtendedStat_ApplyEffect")

	int param1 = pEffect->m_effectAmount;
	int modType = pEffect->m_dWFlags;
	int exStatId = pEffect->m_special;

	ExStatInfo* exStatInfo;
	if (auto exStatInfoPair = exStatInfoMap.find(exStatId); exStatInfoPair == exStatInfoMap.end()) {
		Print("[!][EEex.dll] op401 (SetExtendedStat) - Invalid special (extended stat id) value: %d\n", exStatId);
		return 1;
	}
	else {
		exStatInfo = &exStatInfoPair->second;
	}

	auto& exStatValues = exStatDataMap[&pSprite->m_derivedStats].exStatValues;
	int newVal;

	switch (modType) {
		case 0:
			newVal = clampedSum(exStatValues[exStatId], param1);
			break;
		case 1:
			newVal = param1;
			break;
		case 2:
			newVal = clampedPercent(exStatValues[exStatId], param1);
			break;
		default:
			Print("[!][EEex.dll] op401 (SetExtendedStat) - Invalid param2 (modification type) value: %d\n", modType);
			return 1;
	}

	exStatValues[exStatId] = clamp(newVal, exStatInfo->min, exStatInfo->max);
	return 1;

	STUTTER_LOG_END
}

// New op403
int EEex::Opcode_Hook_ScreenEffects_ApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite) {

	STUTTER_LOG_START(int, "EEex::Opcode_Hook_ScreenEffects_ApplyEffect")

	exStatDataMap[&pSprite->m_derivedStats].screenEffects.emplace_back(pEffect);
	return 1;

	STUTTER_LOG_END
}

// New op408
int EEex::Opcode_Hook_ProjectileMutator_ApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite) {

	STUTTER_LOG_START(int, "EEex::Opcode_Hook_ProjectileMutator_ApplyEffect")

	exStatDataMap[&pSprite->m_derivedStats].projectileMutatorEffects.emplace_back(pEffect);
	return 1;

	STUTTER_LOG_END
}

void removeProjectileMutatorCache(CDerivedStats& stats, const CGameEffect *const pEffect) {

	ExStatData& exStatData = exStatDataMap[&stats];
	std::vector<CGameEffect*>& projectileMutatorEffects = exStatData.projectileMutatorEffects;

	const auto end = projectileMutatorEffects.end();
	const auto pos = std::find(projectileMutatorEffects.begin(), end, pEffect);

	if (pos != end) {
		projectileMutatorEffects.erase(pos);
	}
}

void EEex::Opcode_Hook_ProjectileMutator_OnRemove(CGameEffect* pEffect, CGameSprite* pSprite) {
	// The op408 effect is about to be destroyed - remove its cached values
	removeProjectileMutatorCache(pSprite->m_derivedStats, pEffect);
	removeProjectileMutatorCache(pSprite->m_tempStats, pEffect);
	removeProjectileMutatorCache(pSprite->m_bonusStats, pEffect);
}

// New op409
int EEex::Opcode_Hook_EnableActionListener_ApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite) {

	STUTTER_LOG_START(int, "EEex::Opcode_Hook_EnableActionListener_ApplyEffect")

	EnabledActionListenerData& data = exStatDataMap[&pSprite->m_derivedStats].enableActionListenerEffects.emplace_back();
	pEffect->m_res.toNullTerminatedStr(data.funcName);
	data.pEffect = pEffect;
	return 1;

	STUTTER_LOG_END
}

int EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget(CGameEffect* pEffect) {

	STUTTER_LOG_START(int, "EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget")

	return (pEffect->m_special & 2) != 0;

	STUTTER_LOG_END
}

int EEex::Opcode_Hook_OnCheckAdd(CGameEffect* pEffect, CGameSprite* pSprite) {

	STUTTER_LOG_START(int, "EEex::Opcode_Hook_OnCheckAdd")

	auto& screenEffects = exStatDataMap[pSprite->GetActiveStats()].screenEffects;

	if (screenEffects.empty()) {
		return 0;
	}

	lua_State *const L = luaState();
	tolua_pushusertype_nocast(L, pEffect, "CGameEffect");                   // 1 [ ..., pEffectUD ]
	tolua_pushusertype_nocast(L, pSprite, "CGameSprite");                   // 2 [ ..., pEffectUD, pSpriteUD ]
	int foundImmunity = 0;

	for (CGameEffect* pScreenEffect : screenEffects) {

		char immunityFunc[9];
		pScreenEffect->m_res.toNullTerminatedStr(immunityFunc);
		lua_getglobal(L, immunityFunc);                                     // 3 [ ..., pEffectUD, pSpriteUD, _G[immunityFunc] ]

		if (lua_isfunction(L, -1)) {

			if (luaCallProtected(L, 3, 1, [&](int base) {
																			// 3 [ ..., pEffectUD, pSpriteUD, _G[immunityFunc], ... ]
				lua_pushvalue(L, base);                                     // 4 [ ..., pEffectUD, pSpriteUD, _G[immunityFunc], ..., _G[immunityFunc] ]
				tolua_pushusertype_nocast(L, pScreenEffect, "CGameEffect"); // 5 [ ..., pEffectUD, pSpriteUD, _G[immunityFunc], ..., _G[immunityFunc], pScreenEffectUD ]
				lua_pushvalue(L, base - 2);                                 // 6 [ ..., pEffectUD, pSpriteUD, _G[immunityFunc], ..., _G[immunityFunc], pScreenEffectUD, pEffectUD ]
				lua_pushvalue(L, base - 1);                                 // 7 [ ..., pEffectUD, pSpriteUD, _G[immunityFunc], ..., _G[immunityFunc], pScreenEffectUD, pEffectUD, pSpriteUD ]
			}))
			{
																			// 4 [ ..., pEffectUD, pSpriteUD, _G[immunityFunc], retVal ]
				int nRetType = lua_type(L, -1);
				if (nRetType == LUA_TNIL) {
					// Treat nil as false
				}
				else if (nRetType == LUA_TBOOLEAN) {
					if (lua_toboolean(L, -1)) {
						foundImmunity = 1;
						lua_pop(L, 2);                                      // 2 [ ..., pEffectUD, pSpriteUD ]
						break;
					}
				}
				else {
					Print("[!][EEex.dll] op403 (ScreenEffects) - immunityFunc \"%s\" returned invalid type\n", immunityFunc);
				}

				lua_pop(L, 2);                                              // 2 [ ..., pEffectUD, pSpriteUD ]
			}
		}
		else {
			Print("[!][EEex.dll] op403 (ScreenEffects) - immunityFunc \"%s\" has invalid type\n", immunityFunc);
			lua_pop(L, 1);                                                  // 2 [ ..., pEffectUD, pSpriteUD ]
		}
	}

	lua_pop(L, 2);                                                          // 0 [ ... ]
	return foundImmunity;

	STUTTER_LOG_END
}

void EEex::Opcode_Hook_OnCopy(CGameEffect* pSrcEffect, CGameEffect* pDstEffect) {

	STUTTER_LOG_START(void, "EEex::Opcode_Hook_OnCopy")

	exEffectInfoMap[pDstEffect] = exEffectInfoMap[pSrcEffect];

	STUTTER_LOG_END
}

void EEex::Opcode_Hook_OnDestruct(CGameEffect* pEffect) {

	STUTTER_LOG_START(void, "EEex::Opcode_Hook_OnDestruct")

	exEffectInfoMap.erase(pEffect);

	STUTTER_LOG_END
}

void EEex::Opcode_Hook_AfterListsResolved(CGameSprite* pSprite) {

	STUTTER_LOG_START(void, "EEex::Opcode_Hook_AfterListsResolved")

	ExSpriteData& exData = exSpriteDataMap[pSprite];
	CDerivedStats& stats = *pSprite->GetActiveStats();
	lua_State *const L = luaState();

	if
	(
		stats.m_disableSpells != exData.oldDisableSpells
		||
		!std::equal(
			std::begin(stats.m_disabledSpellTypes.data),
			std::end(stats.m_disabledSpellTypes.data),
			std::begin(exData.oldDisabledSpellTypes.data)
		)
	)
	{
		exData.oldDisableSpells = stats.m_disableSpells;
		std::copy_n(stats.m_disabledSpellTypes.data, 3, exData.oldDisabledSpellTypes.data);

		luaCallProtected(L, 1, 0, [&](int _) {
			lua_getglobal(L, "EEex_Sprite_LuaHook_OnSpellDisableStateChanged"); // 1 [ ..., EEex_Sprite_LuaHook_SpellDisableStateChanged ]
			tolua_pushusertype_nocast(L, pSprite, "CGameSprite");               // 2 [ ..., EEex_Sprite_LuaHook_SpellDisableStateChanged, pSpriteUD ]
		});
	}

	if (!EEex::Opcode_LuaHook_AfterListsResolved_Enabled) {
		return;
	}

	luaCallProtected(L, 1, 0, [&](int _) {
		lua_getglobal(L, "EEex_Opcode_LuaHook_AfterListsResolved"); // 1 [ ..., EEex_Opcode_LuaHook_AfterListsResolved ]
		tolua_pushusertype_nocast(L, pSprite, "CGameSprite");       // 2 [ ..., EEex_Opcode_LuaHook_AfterListsResolved, pSpriteUD ]
	});

	STUTTER_LOG_END
}

////////////
// Sprite //
////////////

void EEex::Sprite_Hook_OnConstruct(CGameSprite* pSprite) {
	exSpriteDataMap.try_emplace(pSprite);
}

void EEex::Sprite_Hook_OnDestruct(CGameSprite* pSprite) {
	if (auto itr = exSpriteDataMap.find(pSprite); itr != exSpriteDataMap.end()) {
		ExSpriteData& exData = itr->second;
		if (exData.uuid != 0) {
			//Print("Erased UUID %llu association\n", exData.uuid);
			exUUIDDataMap.erase(exData.uuid);
		}
		exSpriteDataMap.erase(itr);
	}
}

void updateUUIDLocal(CGameSprite* pSprite, ExSpriteData& exData) {

	CVariableHash *const pLocalVariables = pSprite->m_pLocalVariables;
	CVariable *const pVariable = pLocalVariables->FindKey(EngineVal<CString, false>{"EEEX_UUID"});

	if (pVariable == nullptr) {
		EngineVal<CVariable> variable;
		variable->m_name.set("EEEX_UUID");
		variable->m_intValue = static_cast<int>(exData.uuid);
		variable->m_dWValue = static_cast<unsigned int>(exData.uuid >> 32);
		pLocalVariables->AddKey(variable);
	}
	else {
		pVariable->m_intValue = static_cast<int>(exData.uuid);
		pVariable->m_dWValue = static_cast<unsigned int>(exData.uuid >> 32);
	}
}

EEex_OnBeforeEffectUnmarshalledRet EEex::Sprite_Hook_OnBeforeEffectUnmarshalled(CGameSprite* pSprite, CGameEffectBase* pEffectBase) {

	if (EEex::bNoUUID) {
		return EEex_OnBeforeEffectUnmarshalledRet::NORMAL;
	}

	ExSpriteData& exData = exSpriteDataMap[pSprite];

	if (pEffectBase->m_effectId == 187) {

		if (strncmp(pEffectBase->m_scriptName.data, "EEEX_UUID", 32) == 0) {
			exData.uuid = (static_cast<uint64_t>(pEffectBase->m_dWFlags) << 32) | pEffectBase->m_effectAmount;
		}
	}

	return EEex_OnBeforeEffectUnmarshalledRet::NORMAL;
}

void EEex::Sprite_Hook_OnAfterEffectListUnmarshalled(CGameSprite* pSprite) {

	if (EEex::bNoUUID) {
		return;
	}

	ExSpriteData& exData = exSpriteDataMap[pSprite];

	if (exData.uuid == 0) {
		exData.uuid = ++nextUUID;
		//Print("Generated UUID for %s: %llu\n", pSprite->GetName(true)->m_pchData, exData.uuid);
		updateNextUUIDLocal();
	}
	else {
		//Print("Using existing UUID for %s: %llu\n", pSprite->GetName(true)->m_pchData, exData.uuid);
	}

	ExUUIDData& exUUIDData = exUUIDDataMap[exData.uuid];

	exUUIDData.pSprite = pSprite;
	updateUUIDLocal(pSprite, exData);

	lua_State *const L = *p_g_lua;
	luaCallProtected(L, 1, 0, [&](int _) {
		lua_getglobal(L, "EEex_Sprite_LuaHook_OnAfterEffectListUnmarshalled"); // 1 [ ..., EEex_Sprite_LuaHook_OnAfterEffectListUnmarshalled ]
		tolua_pushusertype_nocast(L, pSprite, "CGameSprite");                  // 2 [ ..., EEex_Sprite_LuaHook_OnAfterEffectListUnmarshalled, pSpriteUD ]
	});
}

void EEex::Sprite_Hook_OnBeforeEffectListMarshalled(CGameSprite* pSprite) {

	if (!EEex::bNoUUID && !EEex::bStripUUID) {
		return;
	}

	CGameEffectList *const pEffectList = &pSprite->m_timedEffectList;

	for (auto* pNode = pEffectList->m_pNodeHead; pNode != nullptr;) {

		auto *const pNext = pNode->pNext;
		CGameEffect* pEffect = pNode->data;

		if (pEffect->m_effectId == 187 && strncmp(pEffect->m_scriptName.data, "EEEX_UUID", 32) == 0) {
			pEffectList->RemoveAt(reinterpret_cast<__POSITION*>(pNode));
			pEffect->virtual_OnRemove(pSprite);
			pEffect->virtual_Destruct(1);
		}

		pNode = pNext;
	}
}

////////////
// Action //
////////////

void EEex::Action_Hook_OnAfterSpriteStartedAction(CGameSprite* pSprite) {

	STUTTER_LOG_START(void, "EEex::Action_Hook_OnAfterSpriteStartedAction")

	lua_State *const L = luaState();

	auto& enableActionListenerEffects = exStatDataMap[pSprite->GetActiveStats()].enableActionListenerEffects;
	if (!enableActionListenerEffects.empty()) {

		tolua_pushusertype_nocast(L, pSprite, "CGameSprite");                        // 1 [ ..., pSpriteUD ]
		tolua_pushusertype_nocast(L, &pSprite->m_curAction, "CAIAction");            // 2 [ ..., pSpriteUD, pActionUD ]
		lua_getglobal(L, "EEex_Action_Private_EnabledSpriteStartedActionListeners"); // 3 [ ..., pSpriteUD, pActionUD, EEex_Action_Private_EnabledSpriteStartedActionListeners ]

		for (auto& data : enableActionListenerEffects) {

			if (CGameEffect *const pEffect = data.pEffect; pEffect->m_effectAmount != 0) {

				lua_pushstring(L, data.funcName);                                    // 4 [ ..., pSpriteUD, pActionUD, EEex_Action_Private_EnabledSpriteStartedActionListeners, funcName ]
				lua_rawget(L, -2);                                                   // 4 [ ..., pSpriteUD, pActionUD, EEex_Action_Private_EnabledSpriteStartedActionListeners, EEex_Action_Private_EnabledSpriteStartedActionListeners[funcName] ]

				if (lua_isfunction(L, -1)) {
					luaCallProtected(L, 1, 0, [&](int base) {
																					 // 4 [ ..., pSpriteUD, pActionUD, EEex_Action_Private_EnabledSpriteStartedActionListeners, EEex_Action_Private_EnabledSpriteStartedActionListeners[funcName], ... ]
						lua_pushvalue(L, base);                                      // 5 [ ..., pSpriteUD, pActionUD, EEex_Action_Private_EnabledSpriteStartedActionListeners, EEex_Action_Private_EnabledSpriteStartedActionListeners[funcName], ..., EEex_Action_Private_EnabledSpriteStartedActionListeners[funcName] ]
						lua_pushvalue(L, base - 3);                                  // 6 [ ..., pSpriteUD, pActionUD, EEex_Action_Private_EnabledSpriteStartedActionListeners, EEex_Action_Private_EnabledSpriteStartedActionListeners[funcName], ..., EEex_Action_Private_EnabledSpriteStartedActionListeners[funcName], pSpriteUD ]
						lua_pushvalue(L, base - 2);                                  // 7 [ ..., pSpriteUD, pActionUD, EEex_Action_Private_EnabledSpriteStartedActionListeners, EEex_Action_Private_EnabledSpriteStartedActionListeners[funcName], ..., EEex_Action_Private_EnabledSpriteStartedActionListeners[funcName], pSpriteUD, pActionUD ]
						tolua_pushusertype_nocast(L, pEffect, "CGameEffect");        // 8 [ ..., pSpriteUD, pActionUD, EEex_Action_Private_EnabledSpriteStartedActionListeners, EEex_Action_Private_EnabledSpriteStartedActionListeners[funcName], ..., EEex_Action_Private_EnabledSpriteStartedActionListeners[funcName], pSpriteUD, pActionUD, pEffect ]
					});
				}
				else {
					Print("[!][EEex.dll] op409 (EnableActionListener) - Attempted to call invalid function \"%s\"\n", data.funcName);
				}

				lua_pop(L, 1);                                                       // 3 [ ..., pSpriteUD, pActionUD, EEex_Action_Private_EnabledSpriteStartedActionListeners ]
			}
		}

		lua_pop(L, 3);                                                               // 0 [ ... ]
	}

	luaCallProtected(L, 1, 0, [&](int base) {
		lua_getglobal(L, "EEex_Action_LuaHook_OnAfterSpriteStartedAction");          // 1 [ ..., EEex_Action_Hook_OnAfterSpriteStartedAction ]
		tolua_pushusertype_nocast(L, pSprite, "CGameSprite");                        // 2 [ ..., EEex_Action_Hook_OnAfterSpriteStartedAction, pSpriteUD ]
	});
																					 // 0 [ ... ]
	STUTTER_LOG_END
}

////////////////
// Projectile //
////////////////

LuaTypeContainer callMutatorFunction(
	lua_State* L,
	const char* mutatorTableName,
	const char* mutatorFunctionName,
	int argumentsTableIndex)
{
	argumentsTableIndex = lua_absindex(L, argumentsTableIndex);
	lua_getglobal(L, mutatorTableName);                // 1 [ ..., mutatorTable ]

	if (lua_type(L, -1) == LUA_TTABLE) {

		lua_pushstring(L, mutatorFunctionName);        // 2 [ ..., mutatorTable, mutatorFunctionName ]
		lua_rawget(L, -2);                             // 2 [ ..., mutatorTable, mutatorFunction ]
		int mutatorFuncType = lua_type(L, -1);

		if (mutatorFuncType == LUA_TFUNCTION) {

			if (luaCallProtected(L, 1, 1, [&](int top) {
													   // 2 [ ..., mutatorTable, mutatorFunction, ... ]
				lua_pushvalue(L, top);                 // 3 [ ..., mutatorTable, mutatorFunction, ..., mutatorFunction ]
				lua_pushvalue(L, argumentsTableIndex); // 4 [ ..., mutatorTable, mutatorFunction, ..., mutatorFunction, argumentsTable ]
			})) {
													   // 3 [ ..., mutatorTable, mutatorFunction, retVal ]
				const LuaTypeContainer toRet = getLuaTypeContainer(L, -1);
				lua_pop(L, 3);                         // 0 [ ... ]
				return toRet;
			}
													   // 2 [ ..., mutatorTable, mutatorFunction ]
		}
		else if (mutatorFuncType != LUA_TNIL) {
			Print("[!][EEex.dll] op408 (ProjectileMutator) - Attempted to use an invalid \"%s\" value under: \"%s\"\n", mutatorFunctionName, mutatorTableName);
		}
		lua_pop(L, 2);                                 // 0 [ ... ]
	}
	else {
		Print("[!][EEex.dll] op408 (ProjectileMutator) - Attempted to use an invalid mutator table: \"%s\"\n", mutatorTableName);
		lua_pop(L, 1);                                 // 0 [ ... ]
	}

	return LuaTypeContainer{};
}

LuaTypeContainer processMutatorFunctions(
	lua_State* L,
	const std::optional<std::vector<CGameEffect*>*>& projectileMutatorEffects,
	std::function<LuaTypeContainer(const char*, std::optional<int>)> func)
{
	if (EEex::Projectile_LuaHook_GlobalMutators_Enabled) {

		lua_getglobal(L, "EEex_Projectile_Private_GlobalMutators");   // 1 [ ..., EEex_Projectile_Private_GlobalMutators ]
		lua_pushnil(L);                                               // 2 [ ..., EEex_Projectile_Private_GlobalMutators, nil ]
		while (lua_next(L, -2)) {
																	  // 3 [ ..., EEex_Projectile_Private_GlobalMutators, k, v -> mutatorTableName ]
			LuaTypeContainer retType = func(lua_tostring(L, -1), {});
			if (retType.valid && retType.type != LUA_TNIL) {
				lua_pop(L, 3);                                        // 0 [ ... ]
				return retType;
			}

			lua_pop(L, 1);                                            // 2 [ ..., EEex_Projectile_Private_GlobalMutators, k ]
		}
																	  // 1 [ ..., EEex_Projectile_Private_GlobalMutators ]
		lua_pop(L, 1);                                                // 0 [ ... ]
	}

	if (projectileMutatorEffects.has_value()) {

		for (CGameEffect *const pEffect : **projectileMutatorEffects) {

			tolua_pushusertype_nocast(L, pEffect, "CGameEffect"); // 1 [ ..., pEffectUD ]

			char mutatorTableName[9];
			pEffect->m_res.toNullTerminatedStr(mutatorTableName);

			LuaTypeContainer retType = func(mutatorTableName, -1);
			if (retType.valid && retType.type != LUA_TNIL) {
				lua_pop(L, 2);                                    // 0 [ ... ]
				return retType;
			}

			lua_pop(L, 1);                                        // 0 [ ... ]
		}
	}

	return LuaTypeContainer{};
}

std::optional<std::vector<CGameEffect*>*> getProjectileMutatorEffects(CGameAIBase *const pDecoder) {

	if (isSprite(pDecoder, true)) {
		CGameSprite *const pSprite = reinterpret_cast<CGameSprite*>(pDecoder);
		auto projectileMutatorEffects = &exStatDataMap[pSprite->GetActiveStats()].projectileMutatorEffects;
		return { projectileMutatorEffects };
	}

	return {};
}

#ifdef PROJECTILE_MUTATORS_DISABLED
	#define GUARD_GET_PROJECTILE_MUTATOR_EFFECTS(shortCircuitRetVal)        \
		return shortCircuitRetVal;                                          \
		std::optional<std::vector<CGameEffect*>*> projectileMutatorEffects;
#else
	#define GUARD_GET_PROJECTILE_MUTATOR_EFFECTS(shortCircuitRetVal)                                \
		auto projectileMutatorEffects = getProjectileMutatorEffects(pDecoder);                      \
		if (!EEex::Projectile_LuaHook_GlobalMutators_Enabled                                        \
			&& (!projectileMutatorEffects.has_value() || projectileMutatorEffects.value()->empty()) \
		)                                                                                           \
		{                                                                                           \
			return shortCircuitRetVal;                                                              \
		}
#endif

#define NORET

ushort EEex::Projectile_Hook_OnBeforeDecode(ushort nProjectileType, CGameAIBase* pDecoder, uintptr_t pRetPtr) {

	STUTTER_LOG_START(ushort, "EEex::Projectile_Hook_OnBeforeDecode")

	GUARD_GET_PROJECTILE_MUTATOR_EFFECTS(-1)

	lua_State *const L = luaState();
	const int myBase = lua_gettop(L);

	pushGlobalIndexedByInt(L, "EEex_Projectile_Private_DecodeSources", pRetPtr);                // 1 [ ..., decodeSource ]
	pushGameObjectUD(L, pDecoder);                                                              // 2 [ ..., decodeSource, pDecoderUD ]
	lua_pushinteger(L, nProjectileType);                                                        // 3 [ ..., decodeSource, pDecoderUD, nProjectileType ]

	LuaTypeContainer newType = processMutatorFunctions(L, projectileMutatorEffects,
		[&](const char* mutatorTableName, std::optional<int> originatingEffectIndex) -> LuaTypeContainer
	{
																								// 3 [ ..., decodeSource, pDecoderUD, nProjectileType, ... ]
		if (originatingEffectIndex.has_value()) {
			originatingEffectIndex = lua_absindex(L, *originatingEffectIndex);
		}

		lua_newtable(L);                                                                        // 4 [ ..., decodeSource, pDecoderUD, nProjectileType, ..., argsT ]

		setImmediateTableValue(L, "decodeSource",      myBase + 1);
		setImmediateTableValue(L, "originatingSprite", myBase + 2);
		setImmediateTableValue(L, "projectileType",    myBase + 3);

		if (originatingEffectIndex.has_value()) {
			setImmediateTableValue(L, "originatingEffect", *originatingEffectIndex);
		}

		LuaTypeContainer newType = callMutatorFunction(L, mutatorTableName, "typeMutator", -1); // 4 [ ..., decodeSource, pDecoderUD, nProjectileType, ..., argsT ]
		lua_pop(L, 1);                                                                          // 3 [ ..., decodeSource, pDecoderUD, nProjectileType, ... ]

		if (newType.valid && newType.type != LUA_TNIL) {
			if (newType.type == LUA_TNUMBER) {
				return newType;
			}
			else {
				Print("[!][EEex.dll] op408 (ProjectileMutator) - Attempted to use an invalid return value from typeMutator under: \"%s\"\n", mutatorTableName);
			}
		}

		return LuaTypeContainer{};
	});
																								// 3 [ ..., decodeSource, pDecoderUD, nProjectileType ]
	lua_pop(L, 3);                                                                              // 0 [ ... ]
	return newType.valid ? static_cast<ushort>(newType.value.integer) : -1;

	STUTTER_LOG_END
}

void EEex::Projectile_Hook_OnAfterDecode(CProjectile* pProjectile, CGameAIBase* pDecoder, uintptr_t pRetPtr) {

	STUTTER_LOG_START(void, "EEex::Projectile_Hook_OnAfterDecode")

	GUARD_GET_PROJECTILE_MUTATOR_EFFECTS(NORET)

	lua_State *const L = luaState();
	const int myBase = lua_gettop(L);

	pushGlobalIndexedByInt(L, "EEex_Projectile_Private_DecodeSources", pRetPtr);                                    // 1 [ ..., decodeSource ]
	pushProjectileUD(L, pProjectile);                                                                               // 2 [ ..., decodeSource, pProjectileUD ]
	pushGameObjectUD(L, pDecoder);                                                                                  // 3 [ ..., decodeSource, pProjectileUD, pDecoderUD ]

	processMutatorFunctions(L, projectileMutatorEffects,
		[&](const char* mutatorTableName, std::optional<int> originatingEffectIndex) -> LuaTypeContainer
	{
																													// 3 [ ..., decodeSource, pProjectileUD, pDecoderUD, ... ]
		if (originatingEffectIndex.has_value()) {
			originatingEffectIndex = lua_absindex(L, *originatingEffectIndex);
		}

		lua_newtable(L);                                                                                            // 4 [ ..., decodeSource, pProjectileUD, pDecoderUD, ..., argsT ]

		setImmediateTableValue(L, "decodeSource",      myBase + 1);
		setImmediateTableValue(L, "projectile",        myBase + 2);
		setImmediateTableValue(L, "originatingSprite", myBase + 3);

		if (originatingEffectIndex.has_value()) {
			setImmediateTableValue(L, "originatingEffect", *originatingEffectIndex);
		}

		LuaTypeContainer blockFurtherMutations = callMutatorFunction(L, mutatorTableName, "projectileMutator", -1); // 4 [ ..., decodeSource, pProjectileUD, pDecoderUD, ..., argsT ]
		lua_pop(L, 1);                                                                                              // 3 [ ..., decodeSource, pProjectileUD, pDecoderUD, ... ]

		if (blockFurtherMutations.valid && blockFurtherMutations.type != LUA_TNIL) {
			if (blockFurtherMutations.type == LUA_TBOOLEAN) {
				if (blockFurtherMutations.value.boolean) {
					return blockFurtherMutations;
				}
			}
			else {
				Print("[!][EEex.dll] op408 (ProjectileMutator) - Attempted to use an invalid return value from projectileMutator under: \"%s\"\n", mutatorTableName);
			}
		}

		return LuaTypeContainer{};
	});
																													// 3 [ ..., decodeSource, pProjectileUD, pDecoderUD ]
	lua_pop(L, 3);                                                                                                  // 0 [ ... ]

	STUTTER_LOG_END
}

void EEex::Projectile_Hook_OnBeforeAddEffect(CProjectile* pProjectile, CGameAIBase* pDecoder, CGameEffect* pEffect, uintptr_t pRetPtr) {

	STUTTER_LOG_START(void, "EEex::Projectile_Hook_OnBeforeAddEffect")

	GUARD_GET_PROJECTILE_MUTATOR_EFFECTS(NORET)

	lua_State *const L = luaState();
	const int myBase = lua_gettop(L);

	pushGlobalIndexedByInt(L, "EEex_Projectile_Private_AddEffectSources", pRetPtr);                             // 1 [ ..., addEffectSource ]
	pushProjectileUD(L, pProjectile);                                                                           // 2 [ ..., addEffectSource, pProjectileUD ]
	pushGameObjectUD(L, pDecoder);                                                                              // 3 [ ..., addEffectSource, pProjectileUD, pDecoderUD ]
	tolua_pushusertype_nocast(L, pEffect, "CGameEffect");                                                       // 4 [ ..., addEffectSource, pProjectileUD, pDecoderUD, pEffectUD ]

	processMutatorFunctions(L, projectileMutatorEffects,
		[&](const char* mutatorTableName, std::optional<int> originatingEffectIndex) -> LuaTypeContainer
	{
																												// 4 [ ..., addEffectSource, pProjectileUD, pDecoderUD, pEffectUD, ... ]
		if (originatingEffectIndex.has_value()) {
			originatingEffectIndex = lua_absindex(L, *originatingEffectIndex);
		}

		lua_newtable(L);                                                                                        // 5 [ ..., addEffectSource, pProjectileUD, pDecoderUD, pEffectUD, ..., argsT ]

		setImmediateTableValue(L, "addEffectSource",   myBase + 1);
		setImmediateTableValue(L, "projectile",        myBase + 2);
		setImmediateTableValue(L, "originatingSprite", myBase + 3);
		setImmediateTableValue(L, "effect",            myBase + 4);

		if (originatingEffectIndex.has_value()) {
			setImmediateTableValue(L, "originatingEffect", *originatingEffectIndex);
		}

		LuaTypeContainer blockFurtherMutations = callMutatorFunction(L, mutatorTableName, "effectMutator", -1); // 5 [ ..., addEffectSource, pProjectileUD, pDecoderUD, pEffectUD, ..., argsT ]
		lua_pop(L, 1);                                                                                          // 4 [ ..., addEffectSource, pProjectileUD, pDecoderUD, pEffectUD, ... ]

		if (blockFurtherMutations.valid && blockFurtherMutations.type != LUA_TNIL) {
			if (blockFurtherMutations.type == LUA_TBOOLEAN) {
				if (blockFurtherMutations.value.boolean) {
					return blockFurtherMutations;
				}
			}
			else {
				Print("[!][EEex.dll] op408 (ProjectileMutator) - Attempted to use an invalid return value from effectMutator under: \"%s\"\n", mutatorTableName);
			}
		}

		return LuaTypeContainer{};
	});
																												// 4 [ ..., addEffectSource, pProjectileUD, pDecoderUD, pEffectUD ]
	lua_pop(L, 4);                                                                                              // 0 [ ... ]

	STUTTER_LOG_END
}

#undef GUARD_GET_PROJECTILE_MUTATOR_EFFECTS
#undef NORET

////////////
// Script //
////////////

void EEex::Script_Hook_OnRead(CAIScript* pScript, bool bPlayerScript) {

	STUTTER_LOG_START(void, "EEex::Script_Hook_OnRead")

	exScriptDataMap[pScript].bPlayerScript = bPlayerScript;

	STUTTER_LOG_END
}

void EEex::Script_Hook_OnCopy(CAIScript* pSrcScript, CAIScript* pDstScript) {

	STUTTER_LOG_START(void, "EEex::Script_Hook_OnCopy")

	exScriptDataMap[pDstScript].bPlayerScript = exScriptDataMap[pSrcScript].bPlayerScript;

	STUTTER_LOG_END
}

void EEex::Script_Hook_OnDestruct(CAIScript* pScript) {

	STUTTER_LOG_START(void, "EEex::Script_Hook_OnDestruct")

	exScriptDataMap.erase(pScript);

	STUTTER_LOG_END
}

/////////
// Fix //
/////////

bool EEex::Fix_Hook_ShouldTransformSpellImmunityStrref(CGameEffect* pEffect, CImmunitySpell* pImmunitySpell) {

	STUTTER_LOG_START(bool, "EEex::Fix_Hook_ShouldTransformSpellImmunityStrref")

	const auto nErrorStrref = pImmunitySpell->m_error;
	return pEffect->m_sourceRes.m_resRef[0] == '\0' && (nErrorStrref == 0xF00074 || nErrorStrref == 0xF00080);

	STUTTER_LOG_END
}

bool EEex::Fix_Hook_SpellImmunityShouldSkipItemIndexing(CGameObject* pGameObject) {

	STUTTER_LOG_START(bool, "EEex::Fix_Hook_SpellImmunityShouldSkipItemIndexing")

	return pGameObject->m_objectType != CGameObjectType::SPRITE;

	STUTTER_LOG_END
}

/////////////
// Trigger //
/////////////

void EEex::Trigger_Hook_OnScriptLevelHit(CGameAIBase* pCaller, unsigned char nScriptLevel) {
	for (auto callback : scriptLevelHitCallbacks) {
		callback(pCaller, nScriptLevel);
	}
}

void EEex::Trigger_Hook_OnConditionResponseHit(int16_t nResponseSetNum) {
	for (auto callback : conditionResponseHitCallbacks) {
		callback(nResponseSetNum);
	}
}

//---------------------------//
//          Exports          //
//---------------------------//

void EEex::RegisterScriptLevelHitCallback(std::function<void(CGameAIBase*, unsigned char)> callback) {
	scriptLevelHitCallbacks.emplace_back(callback);
}

void EEex::RegisterConditionResponseHitCallback(std::function<void(int16_t)> callback) {
	conditionResponseHitCallbacks.emplace_back(callback);
}

void EEex::RegisterTriggerHitCallback(std::function<void(int32_t)> callback) {
	triggerHitCallbacks.emplace_back(callback);
}

void EEex::RegisterTriggerEvaluatedCallback(std::function<void(bool)> callback) {
	triggerEvaluatedCallbacks.emplace_back(callback);
}

//------------------------//
//          Init          //
//------------------------//

void initProjectileMutator() {
	registerProjVFTableType(TEXT("CProjectile::VFTable"),              { "CProjectile",                    EEex::ProjectileType::CProjectile                    });
	registerProjVFTableType(TEXT("CProjectileAmbiant::VFTable"),       { "CProjectileAmbiant",             EEex::ProjectileType::CProjectileAmbiant             });
	registerProjVFTableType(TEXT("CProjectileArea::VFTable"),          { "CProjectileArea",                EEex::ProjectileType::CProjectileArea                });
	registerProjVFTableType(TEXT("CProjectileBAM::VFTable"),           { "CProjectileBAM",                 EEex::ProjectileType::CProjectileBAM                 });
	//registerProjVFTableType(TEXT("CProjectileCallLightning::VFTable"), { "CProjectileCallLightning",       EEex::ProjectileType::CProjectileCallLightning       });
	//registerProjVFTableType(TEXT("CProjectileCastingGlow::VFTable"),   { "CProjectileCastingGlow",         EEex::ProjectileType::CProjectileCastingGlow         });
	registerProjVFTableType(TEXT("CProjectileChain::VFTable"),         { "CProjectileChain",               EEex::ProjectileType::CProjectileChain               });
	registerProjVFTableType(TEXT("CProjectileColorSpray::VFTable"),    { "CProjectileColorSpray",          EEex::ProjectileType::CProjectileColorSpray          });
	registerProjVFTableType(TEXT("CProjectileConeOfCold::VFTable"),    { "CProjectileConeOfCold",          EEex::ProjectileType::CProjectileConeOfCold          });
	registerProjVFTableType(TEXT("CProjectileFall::VFTable"),          { "CProjectileFall",                EEex::ProjectileType::CProjectileFall                });
	registerProjVFTableType(TEXT("CProjectileFireHands::VFTable"),     { "CProjectileFireHands",           EEex::ProjectileType::CProjectileFireHands           });
	registerProjVFTableType(TEXT("CProjectileInstant::VFTable"),       { "CProjectileInstant",             EEex::ProjectileType::CProjectileInstant             });
	//registerProjVFTableType(TEXT("CProjectileInvisibleTravelling"),    { "CProjectileInvisibleTravelling", EEex::ProjectileType::CProjectileInvisibleTravelling });
	//registerProjVFTableType(TEXT("CProjectileLightningBolt"),          { "CProjectileLightningBolt",       EEex::ProjectileType::CProjectileLightningBolt       });
	//registerProjVFTableType(TEXT("CProjectileLightningBoltGround"),    { "CProjectileLightningBoltGround", EEex::ProjectileType::CProjectileLightningBoltGround });
	//registerProjVFTableType(TEXT("CProjectileLightningBounce"),        { "CProjectileLightningBounce",     EEex::ProjectileType::CProjectileLightningBounce     });
	//registerProjVFTableType(TEXT("CProjectileLightningStorm"),         { "CProjectileLightningStorm",      EEex::ProjectileType::CProjectileLightningStorm      });
	//registerProjVFTableType(TEXT("CProjectileMagicMissileMulti"),      { "CProjectileMagicMissileMulti",   EEex::ProjectileType::CProjectileMagicMissileMulti   });
	registerProjVFTableType(TEXT("CProjectileMulti::VFTable"),         { "CProjectileMulti",               EEex::ProjectileType::CProjectileMulti               });
	registerProjVFTableType(TEXT("CProjectileMushroom::VFTable"),      { "CProjectileMushroom",            EEex::ProjectileType::CProjectileMushroom            });
	registerProjVFTableType(TEXT("CProjectileNewScorcher::VFTable"),   { "CProjectileNewScorcher",         EEex::ProjectileType::CProjectileNewScorcher         });
	registerProjVFTableType(TEXT("CProjectileScorcher::VFTable"),      { "CProjectileScorcher",            EEex::ProjectileType::CProjectileScorcher            });
	registerProjVFTableType(TEXT("CProjectileSegment::VFTable"),       { "CProjectileSegment",             EEex::ProjectileType::CProjectileSegment             });
	registerProjVFTableType(TEXT("CProjectileSkyStrike::VFTable"),     { "CProjectileSkyStrike",           EEex::ProjectileType::CProjectileSkyStrike           });
	registerProjVFTableType(TEXT("CProjectileSkyStrikeBAM::VFTable"),  { "CProjectileSkyStrikeBAM",        EEex::ProjectileType::CProjectileSkyStrikeBAM        });
	registerProjVFTableType(TEXT("CProjectileSpellHit::VFTable"),      { "CProjectileSpellHit",            EEex::ProjectileType::CProjectileSpellHit            });
	registerProjVFTableType(TEXT("CProjectileTravelDoor::VFTable"),    { "CProjectileTravelDoor",          EEex::ProjectileType::CProjectileTravelDoor          });
}

int getExtendedStatField(C2DArray* pXStats2DA, const char* name, int id, const char* field, int def, int& pVal) {

	const CString *const strVal = pXStats2DA->GetAtLabels(EngineVal<CString>{field}, EngineVal<CString>{name});

	if (strcmp(strVal->m_pchData, "*") == 0) {
		pVal = def;
		return true;
	}

	int val;
	if (!parseInt(strVal->m_pchData, val)) {
		Print("[!][EEex.dll] X-STATS.2DA - Invalid %s(#%d) %s value: \"%s\"\n", name, id, field, strVal->m_pchData);
		return false;
	}

	pVal = val;
	return true;
}

void initStats() {

	EngineVal<CAIIdList> pStatsIDS{};
	pStatsIDS->LoadList2("STATS", false);

	EngineVal<C2DArray> pXStats2DA{};
	{
		const CResRef resref{"X-STATS"};
		pXStats2DA->Load(&resref);
	}

	for (const auto* node = pStatsIDS->m_idList.m_pNodeHead; node != nullptr; node = node->pNext) {

		CAIId *const pId = node->data;
		const int id = pId->m_id;

		if (id < FIRST_EXTENDED_STAT_ID) {
			continue;
		}

		const char *const name = pId->m_line.m_pchData;

		int min;
		if (!getExtendedStatField(pXStats2DA, name, id, "MIN", INT_MIN, min)) {
			continue;
		}

		int max;
		if (!getExtendedStatField(pXStats2DA, name, id, "MAX", INT_MAX, max)) {
			continue;
		}

		int def;
		if (!getExtendedStatField(pXStats2DA, name, id, "DEFAULT", 0, def)) {
			continue;
		}

		exStatInfoMap.try_emplace(id, min, max, def);
	}
}

template<typename out_type>
DWORD getLuaProc(const char* name, out_type& out) {
	if (out = reinterpret_cast<out_type>(GetProcAddress(luaLibrary(), name)); out == 0) {
		DWORD lastError = GetLastError();
		Print("[!][EEex.dll] getLuaProc() - GetProcAddress() failed (%d) to find Lua function \"%s\", the game will probably crash\n", lastError, name);
		return lastError;
	}
	return 0;
}

void EEex::InitEEex() {

	EEex::Opcode_LuaHook_AfterListsResolved_Enabled = false;
	EEex::Projectile_LuaHook_GlobalMutators_Enabled = false;
	initProjectileMutator();

	if (luaMode() == LuaMode::REPLACE_INTERNAL_WITH_EXTERNAL) {
		getLuaProc("wrapper_fclose", wrapper_fclose);
		getLuaProc("wrapper_fprintf", wrapper_fprintf);
	}
}
