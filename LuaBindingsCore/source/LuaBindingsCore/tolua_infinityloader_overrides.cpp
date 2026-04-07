
#include <queue>

#include "infinity_loader_common_api.h"
#include "tolua.h"
#include "tolua_infinityloader_overrides.h"
#include "tolua_pointers.h"

/////////////
// Globals //
/////////////

// Using `StringA` (value comparison), not `const char*` (address comparison)
std::unordered_map<StringA, std::unordered_map<StringA, uintptr_t>> baseclassOffsets;

///////////////////////
// Special Functions //
///////////////////////

EXPORT void RegisterClassBaseclassOffsets(const char* name, const std::initializer_list<std::pair<const char*, uintptr_t>>& toRegister) {

	// Don't register baseclasses more than once for a type
	if (baseclassOffsets.contains(name)) {
		return;
	}

	std::unordered_map<StringA, uintptr_t>& offsets = baseclassOffsets[name];
	for (const auto& [baseclassName, baseclassOffset] : toRegister) {
		offsets.emplace(baseclassName, baseclassOffset);
	}
}

// Example input:
//
// {
//     {"CResInfTile", {
//         {"CResTile", offsetofbase<CResInfTile, CResTile>()},
//     }},
//     {"CSnowFlake", {
//         {"CParticle", offsetofbase<CSnowFlake, CParticle>()},
//     }},
//     {"CSound", {
//         {"CObject", offsetofbase<CSound, CObject>()},
//         {"CResHelper<CResWave,4>", offsetofbase<CSound, CResHelper<CResWave,4>>()},
//     }},
// }
//
EXPORT void RegisterBaseclassOffsets(const std::initializer_list<std::pair<const char*, std::initializer_list<std::pair<const char*, uintptr_t>>>>& toRegister) {
	for (auto& [className, baseclassInfo] : toRegister) {
		RegisterClassBaseclassOffsets(className, baseclassInfo);
	}
}

//////////
// Misc //
//////////

static void dumpStackIndex(lua_State* L, const char* label, int index) {

	const int absIndex = lua_absindex(L, index);

	lua_getglobal(L, "debug");                                                          // [ debug ]
	lua_getfield(L, -1, "traceback");                                                   // [ debug, traceback ]

	lua_getglobal(L, "EEex_Dump");                                                      // [ debug, traceback, EEex_Dump ]
	lua_pushstring(L, label);                                                           // [ debug, traceback, EEex_Dump, label ]
	lua_pushvalue(L, absIndex);                                                         // [ debug, traceback, EEex_Dump, label, stack[index] ]

	if (lua_pcallk(L, 2, 0, -4, 0, nullptr) != LUA_OK) {
																						// [ debug, traceback, errorMessage ]
		FPrint("[?][LuaBindingsCore.dll] dumpStackIndex() - %s\n", lua_tostring(L, -1));
		lua_pop(L, 3);                                                                  // [ ]
	}
	else {
																						// [ debug, traceback ]
		lua_pop(L, 2);                                                                  // [ ]
	}
}

static int dumpStack(lua_State* L) {
	int top = lua_gettop(L);
	for (int i = 1; i <= top; ++i) {
		StringA label = IntToDecStrA(i);
		dumpStackIndex(L, label.c_str(), i);
	}
	return 0;
}

// Expects   2+ [ ..., t, ..., key, ... ]
// End Stack 2+ [ ..., t, ..., key, ..., t[key] -> value? ]
// Returns   0-1
static bool rawGetOnTable(lua_State* L, int tIndex, int keyIndex) {

	if (!lua_istable(L, tIndex)) {
		return false;
	}

	tIndex = lua_absindex(L, tIndex);
	lua_pushvalue(L, keyIndex); // 3+ [ ..., t, ..., key, ..., key ]
	lua_rawget(L, tIndex);      // 3+ [ ..., t, ..., key, ..., t[key] -> value ]
	return true;
}

// Expects   2+ [ ..., t, ..., key1, key2, ... ]
// End Stack 2+ [ ..., t, ..., key1, key2, ..., value? ]
// Returns   0-1
static bool getPath(lua_State* L, int tIndex, int keysStartIndex, int numKeys) {

	keysStartIndex = lua_absindex(L, keysStartIndex);

	int i = keysStartIndex;
	const int keysEndIndex = keysStartIndex + numKeys;

	if (!rawGetOnTable(L, tIndex, i++)) {
		return false;
	}
										 // 3+ [ ..., t, ..., key1, key2, ..., t[key1] -> curValue ]
	for (; i < keysEndIndex; ++i) {

		if (!rawGetOnTable(L, -1, i)) {
										 // 3+ [ ..., t, ..., key1, key2, ..., curValue ]
			lua_pop(L, 1);               // 2+ [ ..., t, ..., key1, key2, ... ]
			return false;
		}
										 // 4+ [ ..., t, ..., key1, key2, ..., curValue -> lastValue, curValue[keyN] -> curValue ]
		lua_remove(L, -2);               // 3+ [ ..., t, ..., key1, key2, ..., curValue ]
	}
										 // 3+ [ ..., t, ..., key1, key2, ..., curValue -> value ]
	return true;
}

/////////////
// Helpers //
/////////////

enum class KeyKeyReturn : int {
	NONE = 0,
	KEY = 1,
	KEYKEY = 2,
};

// Expects           [ ..., mt, key ]
// End Stack:
//     NONE       => [ ... ]
//     KEY/KEYKEY => [ ..., mtVal ]
template<typename SingleAction>
static KeyKeyReturn findKeyKeyOnBase(lua_State* L, const char* keykey, SingleAction action) {

	lua_pushstring(L, "tolua_base");                                               // 3  [ ..., mt, key, "tolua_base" ]
	lua_rawget(L, LUA_REGISTRYINDEX);                                              // 3  [ ..., mt, key, registry["tolua_base"] ]

	lua_pushvalue(L, -3);                                                          // 4  [ ..., mt, key, registry["tolua_base"], mt ]
	lua_rawget(L, -2);                                                             // 4  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt] ]

	if (!lua_isnil(L, -1)) {
		lua_pushnil(L);                                                            // 5  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], nil ]
		while (lua_next(L, -2)) {
																				   // 6  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v ]
			lua_pushstring(L, "mt");                                               // 7  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, "mt" ]
			lua_rawget(L, -2);                                                     // 7  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT ]

			if (action(-6)) {
																				   // 8  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT, retVal ]
				lua_insert(L, -8);                                                 // 8  [ ..., retVal, mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT ]
				lua_pop(L, 7);                                                     // 1  [ ..., retVal ]
				return KeyKeyReturn::KEY;
			}

			lua_pushstring(L, keykey);                                             // 8  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT, keykey ]
			lua_rawget(L, -2);                                                     // 8  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT, baseMT[keykey] ]
			if (lua_istable(L, -1)) {

				lua_pushvalue(L, -7);                                              // 9  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT, baseMT[keykey], key ]
				lua_rawget(L, -2);                                                 // 9  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT, baseMT[keykey], baseMT[keykey][key] ]

				if (!lua_isnil(L, -1)) {
					lua_insert(L, -9);                                             // 9  [ ..., baseMT[keykey][key], mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT, baseMT[keykey] ]
					lua_pop(L, 8);                                                 // 1  [ ..., baseMT[keykey][key] ]
					return KeyKeyReturn::KEYKEY;
				}
				else {
					lua_pop(L, 2);                                                 // 7  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT ]
					lua_pushvalue(L, -6);                                          // 8  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT, key ]
					if (KeyKeyReturn retVal = findKeyKeyOnBase(L, keykey, action);
						retVal != KeyKeyReturn::NONE)
					{
																				   // 7  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, mtVal ]
						lua_insert(L, -7);                                         // 7  [ ..., mtVal, mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v ]
						lua_pop(L, 6);                                             // 1  [ ..., mtVal ]
						return retVal;
					}
					else {
																				   // 6  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v ]
						lua_pop(L, 1);                                             // 5  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i ]
					}
				}
			}
			else {
				lua_pop(L, 3);                                                     // 5  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i ]
			}
		}
	}

	lua_pop(L, 4);                                                                 // 0  [ ... ]
	return KeyKeyReturn::NONE;
}

// Expects           [ ..., table, key ]
// End Stack:
//     NONE       => [ ... ]
//     KEY/KEYKEY => [ ..., mtVal ]
template<typename SingleAction>
static KeyKeyReturn findKeyKey(lua_State* L, const char* keykey, SingleAction action) {

	lua_getmetatable(L, -2);                                       // 3 [ ..., table, key, mt(table) ]
	if (action(-2)) {
																   // 4 [ ..., table, key, mt(table), retVal ]
		lua_insert(L, -4);                                         // 4 [ ..., retVal, table, key, mt(table) ]
		lua_pop(L, 3);                                             // 1 [ ..., retVal ]
		return KeyKeyReturn::KEY;
	}

	lua_pushstring(L, keykey);                                     // 4 [ ..., table, key, mt(table), keykey ]
	lua_rawget(L, -2);                                             // 4 [ ..., table, key, mt(table), mt(table)[keykey] ]
	if (lua_istable(L, -1)) {
		lua_pushvalue(L, -3);                                      // 5 [ ..., table, key, mt(table), mt(table)[keykey], key ]
		lua_rawget(L, -2);                                         // 5 [ ..., table, key, mt(table), mt(table)[keykey], mt(table)[keykey][key] ]
		if (!lua_isnil(L, -1)) {
			lua_insert(L, -5);                                     // 5 [ ..., mt(table)[keykey][key], table, key, mt(table), mt(table)[keykey] ]
			lua_pop(L, 4);                                         // 1 [ ..., mt(table)[keykey][key] ]
			return KeyKeyReturn::KEYKEY;
		}
		else {
			lua_pop(L, 2);                                         // 3 [ ..., table, key, mt(table) ]
		}
	}
	else {
		lua_pop(L, 1);                                             // 3 [ ..., table, key, mt(table) ]
	}
	lua_pushvalue(L, -2);                                          // 4 [ ..., table, key, mt(table), key ]
	if (KeyKeyReturn retVal = findKeyKeyOnBase(L, keykey, action);
		retVal != KeyKeyReturn::NONE)
	{
																   // 3 [ ..., table, key, mtVal ]
		lua_insert(L, -3);                                         // 3 [ ..., mtVal, table, key ]
		lua_pop(L, 2);                                             // 1 [ ..., mtVal ]
		return retVal;
	}
	else {
																   // 2 [ ..., table, key ]
		lua_pop(L, 2);                                             // 0 [ ... ]
	}
	return KeyKeyReturn::NONE;
}

// Expects   [ ..., table, key ]
// End Stack:
//     0 => [ ..., table, key ]
//     1 => [ ..., table, key, retVal ]
static int callGetDynamic(lua_State* L) {

	lua_pushvalue(L, -2);                                           // 3 [ ..., table, key, table ]
	lua_pushvalue(L, -2);                                           // 4 [ ..., table, key, table, key ]

	KeyKeyReturn retVal = findKeyKey(L, ".get", [&](int keyIndex) {
																	// 1 [ ..., mt ]
		lua_pushvalue(L, keyIndex);                                 // 2 [ ..., mt, key ]
		lua_rawget(L, -2);                                          // 2 [ ..., mt, mt[key] ]

		if (lua_isnil(L, -1)) {
			lua_pop(L, 1);                                          // 1 [ ..., mt ]
			return 0;
		}

		return 1;
	});

	if (retVal == KeyKeyReturn::KEY) {
																	// 3 [ ..., table, key, mtVal ]
		return 1;
	}
	else if (retVal == KeyKeyReturn::KEYKEY) {
																	// 3 [ ..., table, key, mtVal ]
		if (lua_iscfunction(L, -1)) {
			lua_pushvalue(L, -3);                                   // 4 [ ..., table, key, mtVal, table ]
			lua_pushvalue(L, -3);                                   // 5 [ ..., table, key, mtVal, table, key ]
			lua_call(L, 2, 1);                                      // 3 [ ..., table, key, retVal ]
			return 1;
		}
		else {
			lua_pop(L, 1);                                          // 2 [ ..., table, key ]
		}
	}
	return 0;                                                       // 2 [ ..., table, key ]
}

// Expects   [ ..., table, key, value ]
// End Stack [ ..., table, key, value ]
static int callSetDynamic(lua_State* L) {

	lua_pushvalue(L, -3);                           // 4 [ ..., table, key, value, table ]
	lua_pushvalue(L, -3);                           // 5 [ ..., table, key, value, table, key ]

	if (findKeyKey(L, ".set", [&](size_t keyIndex){
		return 0;
	}) == KeyKeyReturn::KEYKEY) {
													// 4 [ ..., table, key, value, mtVal ]
		if (lua_iscfunction(L, -1)) {
			lua_pushvalue(L, -4);                   // 5 [ ..., table, key, value, mtVal, table ]
			lua_pushvalue(L, -3);                   // 6 [ ..., table, key, value, mtVal, table, value ]
			lua_call(L, 2, 0);                      // 3 [ ..., table, key, value ]
			return 1;
		}
		else {
			lua_pop(L, 1);                          // 3 [ ..., table, key, value ]
		}
	}
	return 0;
}

// Expects   [ ..., table, key, value ]
// End Stack [ ..., table, key, value ]
static void callSetI(lua_State* L) {
	lua_pushvalue(L, -3);             // 4 [ ..., table, key, value, table ]
	while (lua_getmetatable(L, -1)) {
									  // 5 [ ..., table, key, value, table, getmetatable(table) ]
		lua_remove(L, -2);            // 4 [ ..., table, key, value, getmetatable(table) ]
		lua_pushstring(L, ".seti");   // 5 [ ..., table, key, value, getmetatable(table), ".seti" ]
		lua_rawget(L, -2);            // 5 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".seti"] ]
		if (lua_isfunction(L, -1)) {
			lua_pushvalue(L, -5);     // 6 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".seti"], table ]
			lua_pushvalue(L, -5);     // 7 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".seti"], table, key ]
			lua_pushvalue(L, -5);     // 8 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".seti"], table, key, value ]
			lua_call(L, 3, 0);        // 4 [ ..., table, key, value, getmetatable(table) ]
			lua_pop(L, 1);            // 3 [ ..., table, key, value ]
			return;
		}
		lua_pop(L, 1);                // 4 [ ..., table, key, value, getmetatable(table) ]
	}
	lua_pop(L, 1);                    // 3 [ ..., table, key, value ]
	tolua_error(L, "Attempt to set indexed value on an invalid operand", NULL);
}

// Expects   [ ..., table, key, value ]
// End Stack [ ..., table, key, value ]
static int callSet(lua_State* L) {

	///////////////////////////////////////////
	// local setT = table[".set"]            //
	// if type(setT) == "table" then         //
	//     local setV = setT[key]            //
	//     if type(setV) == "cfunction" then //
	//         return setV(table, value)     //
	//     end                               //
	// end                                   //
	///////////////////////////////////////////

	lua_pushstring(L, ".set");            // 4 [ ..., table, key, value, ".set" ]
	lua_rawget(L, -4);                    // 4 [ ..., table, key, value, table[".set"] ]
	if (lua_istable(L, -1)) {
		lua_pushvalue(L, -3);             // 5 [ ..., table, key, value, table[".set"], key ]
		lua_rawget(L, -2);                // 5 [ ..., table, key, value, table[".set"], table[".set"][key] ]
		if (lua_iscfunction(L, -1)) {
			lua_pushvalue(L, -5);         // 6 [ ..., table, key, value, table[".set"], table[".set"][key], table ]
			lua_pushvalue(L, -4);         // 7 [ ..., table, key, value, table[".set"], table[".set"][key], table, value ]
			lua_call(L, 2, 0);            // 4 [ ..., table, key, value, table[".set"] ]
			lua_pop(L, 1);                // 3 [ ..., table, key, value ]
			return 1;
		}
		else {
			lua_pop(L, 2);                // 3 [ ..., table, key, value ]
		}
	}
	else {
		lua_pop(L, 1);                    // 3 [ ..., table, key, value ]
	}

	//////////////////////////////////////////////
	// local curTable = table                   //
	// while true do                            //
	//     local meta = getmetatable(curTable)  //
	//     if not meta then                     //
	//         break                            //
	//     end                                  //
	//     curTable = meta                      //
	//     local setT = meta[".set"]            //
	//     if type(setT) == "table" then        //
	//         local set = setT[key]            //
	//         if type(set) == "cfunction" then //
	//             set(table, value)            //
	//             return 1                     //
	//         end                              //
	//     end                                  //
	// end                                      //
	// return 0                                 //
	//////////////////////////////////////////////

	lua_pushvalue(L, -3);                 // 4 [ ..., table, key, value, table ]
	while (lua_getmetatable(L, -1)) {
										  // 5 [ ..., table, key, value, table, getmetatable(table) ]
		lua_remove(L, -2);                // 4 [ ..., table, key, value, getmetatable(table) ]
		lua_pushstring(L, ".set");        // 5 [ ..., table, key, value, getmetatable(table), ".set" ]
		lua_rawget(L, -2);                // 5 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".set"] ]
		if (lua_istable(L, -1)) {
			lua_pushvalue(L, -4);         // 6 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".set"], key ]
			lua_rawget(L, -2);            // 6 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".set"], getmetatable(table)[".set"][key] ]
			if (lua_iscfunction(L, -1)) {
				lua_pushvalue(L, -6);     // 7 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".set"], getmetatable(table)[".set"][key], table ]
				lua_pushvalue(L, -5);     // 8 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".set"], getmetatable(table)[".set"][key], table, value ]
				lua_call(L, 2, 0);        // 5 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".set"] ]
				lua_pop(L, 2);            // 3 [ ..., table, key, value ]
				return 1;
			}
			else {
				lua_pop(L, 2);            // 4 [ ..., table, key, value, getmetatable(table) ]
			}
		}
		else {
			lua_pop(L, 1);                // 4 [ ..., table, key, value, getmetatable(table) ]
		}
	}
	lua_pop(L, 1);                        // 3 [ ..., table, key, value ]
	return 0;
}

// Expects   [ ..., key ]
// End Stack [ ..., t ]
static void getOrCreateTable(lua_State* L, int tableI) {
	tableI = lua_absindex(L, tableI);
	lua_pushvalue(L, -1);             // 2 [ ..., key, key ]
	lua_rawget(L, tableI);            // 2 [ ..., key, table[key] ]
	if (!lua_istable(L, -1)) {
		lua_pop(L, 1);                // 1 [ ..., key ]
		lua_newtable(L);              // 2 [ ..., key, newT ]
		lua_insert(L, -2);            // 2 [ ..., newT, key ]
		lua_pushvalue(L, -2);         // 3 [ ..., newT, key, newT ]
		lua_rawset(L, tableI);        // 1 [ ..., newT -> t ]
	}
	else {
		lua_remove(L, -2);            // 1 [ ..., table[key] -> t ]
	}
}

// Expects   [ ... ]
// End Stack [ ..., t ]
static void getOrCreateTableI(lua_State* L, int tableI, int i) {
	tableI = lua_absindex(L, tableI);
	lua_rawgeti(L, tableI, i);        // 1 [ ..., table[i] ]
	if (!lua_istable(L, -1)) {
		lua_pop(L, 1);                // 0 [ ... ]
		lua_newtable(L);              // 1 [ ..., newT ]
		lua_pushvalue(L, -1);         // 2 [ ..., newT, newT ]
		lua_rawseti(L, tableI, i);    // 1 [ ..., newT -> t ]
	}
}

static void mapBases(lua_State* L, const char* name, std::initializer_list<const char*>& bases) {

	///////////////////////////////////////////////
	// local mtToBasesT = registry["tolua_base"] //
	//                                           //
	// local mt = mt(name)                       //
	// local basesT = mtToBasesT[mt]             //
	//                                           //
	// if type(basesT) ~= "table" then           //
	//     basesT = {}                           //
	//     mtToBasesT[mt] = basesT               //
	// end                                       //
	//                                           //
	// for i, baseName in ipairs(bases) do       //
	//                                           //
	//     local baseEntry = basesT[i]           //
	//                                           //
	//     if type(baseEntry) ~= "table" then    //
	//         baseEntry = {}                    //
	//         basesT[i] = baseEntry             //
	//     end                                   //
	//                                           //
	//     baseEntry["mt"] = mt(baseName)        //
	// end                                       //
	///////////////////////////////////////////////

	lua_pushstring(L, "tolua_base");     // 1 [ ..., "tolua_base" ]
	lua_rawget(L, LUA_REGISTRYINDEX);    // 1 [ ..., registry["tolua_base"] -> mtToBasesT ]

	tolua_getmetatable(L, name);         // 2 [ ..., mtToBasesT, mt(name) -> mt ]
	getOrCreateTable(L, -2);             // 2 [ ..., mtToBasesT, mtToBasesT[mt] -> basesT ]

	int i = 0;
	for (const char *const baseName : bases) {

		getOrCreateTableI(L, -1, ++i);   // 3 [ ..., mtToBasesT, basesT, basesT[i] -> baseEntry ]

		lua_pushstring(L, "mt");         // 4 [ ..., mtToBasesT, basesT, baseEntry, "mt" ]
		tolua_getmetatable(L, baseName); // 5 [ ..., mtToBasesT, basesT, baseEntry, "mt", mt(baseName) ]
		lua_rawset(L, -3);               // 3 [ ..., mtToBasesT, basesT, baseEntry ]

		lua_pop(L, 1);                   // 2 [ ..., mtToBasesT, basesT ]
	}

	////////////////////////////////////////////////////////////////////////////
	// local mtToBaseMapT = registry["tolua_base_map"]                        //
	//                                                                        //
	// local mt = mt(name)                                                    //
	// local baseMapT = mtToBaseMapT[mt]                                      //
	//                                                                        //
	// if type(baseMapT) ~= "table" then                                      //
	//     baseMapT = {}                                                      //
	//     mtToBaseMapT[mt] = baseMapT                                        //
	// end                                                                    //
	//                                                                        //
	// local toProcess = {}                                                   //
	// table.insert(toProcess, { name, 0 })                                   //
	//                                                                        //
	// local baseI = 0                                                        //
	//                                                                        //
	// while toProcess[1] ~= nil do                                           //
	//                                                                        //
	//     local back = toProcess[#toProcess]                                 //
	//     local baseName = back[1]                                           //
	//     local offset = back[2]                                             //
	//                                                                        //
	//     local baseMT = mt(baseName)                                        //
	//                                                                        //
	//     if type(baseMT) == "table" then                                    //
	// 	       baseI = baseI + 1                                              //
	//         baseMapT[baseI] = { ["mt"] = baseMT, ["offset"] = offset }     //
	//     end                                                                //
	//                                                                        //
	//     if (baseclassOffsets.contains(baseName)) then                      //
	//         for nestedBaseName, nestedOffset in pairs(baseclassOffsets) do //
	//             table.insert(toProcess, { nestedBaseName, nestedOffset })  //
	//         end                                                            //
	//     end                                                                //
	// end                                                                    //
	////////////////////////////////////////////////////////////////////////////

	lua_pushstring(L, "tolua_base_map");       // 3 [ ..., mtToBasesT, basesT, "tolua_base_map" ]
	lua_rawget(L, LUA_REGISTRYINDEX);          // 3 [ ..., mtToBasesT, basesT, registry["tolua_base_map"] -> mtToBaseMapT ]

	tolua_getmetatable(L, name);               // 4 [ ..., mtToBasesT, basesT, mtToBaseMapT, mt(name) -> mt ]
	getOrCreateTable(L, -2);                   // 4 [ ..., mtToBasesT, basesT, mtToBaseMapT, mtToBaseMapT[mt] -> baseMapT ]

	// baseName, offset
	std::queue<std::pair<const char*, uintptr_t>> toProcess{};
	toProcess.emplace(name, 0);

	int baseI = 0;

	while (!toProcess.empty()) {

		const std::pair<const char*, uintptr_t>& pair = toProcess.front();
		const char *const baseName = pair.first;
		const uintptr_t offset = pair.second;
		toProcess.pop();

		tolua_getmetatable(L, baseName);       // 5 [ ..., mtToBasesT, basesT, mtToBaseMapT, baseMapT, baseMT ]

		if (lua_istable(L, -1)) {

			getOrCreateTableI(L, -2, ++baseI); // 6 [ ..., mtToBasesT, basesT, mtToBaseMapT, baseMapT, baseMT, baseMapT[baseI] -> baseT ]

			lua_pushstring(L, "mt");           // 7 [ ..., mtToBasesT, basesT, mtToBaseMapT, baseMapT, baseMT, baseT, "mt" ]
			lua_pushvalue(L, -3);              // 8 [ ..., mtToBasesT, basesT, mtToBaseMapT, baseMapT, baseMT, baseT, "mt", baseMT ]
			lua_rawset(L, -3);                 // 6 [ ..., mtToBasesT, basesT, mtToBaseMapT, baseMapT, baseMT, baseT ]

			lua_pushstring(L, "offset");       // 7 [ ..., mtToBasesT, basesT, mtToBaseMapT, baseMapT, baseMT, baseT, "offset" ]
			lua_pushinteger(L, offset);        // 8 [ ..., mtToBasesT, basesT, mtToBaseMapT, baseMapT, baseMT, baseT, "offset", offset ]
			lua_rawset(L, -3);                 // 6 [ ..., mtToBasesT, basesT, mtToBaseMapT, baseMapT, baseMT, baseT ]

			lua_pop(L, 2);                     // 4 [ ..., mtToBasesT, basesT, mtToBaseMapT, baseMapT ]
		}
		else {
			lua_pop(L, 1);                     // 4 [ ..., mtToBasesT, basesT, mtToBaseMapT, baseMapT ]
		}

		if (baseclassOffsets.contains(baseName)) {
			for (const auto& basePair : baseclassOffsets[baseName]) {
				toProcess.emplace(basePair.first.c_str(), offset + basePair.second);
			}
		}
	}

	lua_pop(L, 4);                             // 0 [ ... ]
}

static void tolua_push_globals_table(lua_State* L) {
	if (LUA_VERSION_NUM >= 502) {
		lua_pushvalue(L, LUA_REGISTRYINDEX);
		lua_pushnumber(L, LUA_RIDX_GLOBALS);
		lua_rawget(L, -2);
		lua_remove(L, -2);
	}
	else {
		lua_pushvalue(L, LUA_GLOBALSINDEX);
	}
}

////////////////////////
// Internal Overrides //
////////////////////////

//**********************************************//
// Pattern export: "override_class_index_event" //
//**********************************************//
// Expects   [ table, key ]
// End Stack [ table, key, ..., retVal ]
// Returns   1
int class_index_event(lua_State* L) {
	int t = lua_type(L, 1);
	if (t == LUA_TUSERDATA) {

		/////////////////////////////////////////////////
		// local peerT = registry["tolua_peer"][table] //
		// if type(peerT) == "table" then              //
		//     local val = peerT[key]                  //
		//     if val ~= nil then                      //
		//         return val                          //
		//     end                                     //
		// end                                         //
		/////////////////////////////////////////////////

		lua_pushstring(L, "tolua_peer");                           // 3 [ table, key, "tolua_peer" ]
		lua_rawget(L, LUA_REGISTRYINDEX);                          // 3 [ table, key, registry["tolua_peer"] ]
		lua_pushvalue(L, 1);                                       // 4 [ table, key, registry["tolua_peer"], table ]
		lua_rawget(L, -2);                                         // 4 [ table, key, registry["tolua_peer"], registry["tolua_peer"][table] ]
		if (lua_istable(L, -1)) {
			lua_pushvalue(L, 2);                                   // 5 [ table, key, registry["tolua_peer"], registry["tolua_peer"][table], key ]
			lua_gettable(L, -2);                                   // 5 [ table, key, registry["tolua_peer"], registry["tolua_peer"][table], registry["tolua_peer"][table][key] ]
			if (!lua_isnil(L, -1)) {
				return 1;
			}
		}

		////////////////////////////////////////////////////////
		// local curT = table                                 //
		// while true do                                      //
		//     local mt = getmetatable(curT)                  //
		//     if not mt then                                 //
		//         break                                      //
		//     end                                            //
		//     if type(key) == "number" then                  //
		//         local geti = mt[".geti"]                   //
		//         if type(geti) == "function" then           //
		//             return geti(table, key)                //
		//         end                                        //
		//     else                                           //
		//         local mtVal = mt[key]                      //
		//         if mtVal ~= nil then                       //
		//             return mtVal                           //
		//         end                                        //
		//         local get = mt[".get"]                     //
		//         if type(get) == "table" then               //
		//             local getVal = get[key]                //
		//             local getType = type(getVal)           //
		//             if getType == "cfunction" then         //
		//                 return getVal(table, key)          //
		//             elseif getType == "table" then         //
		//                 local newT = {}                    //
		//                 newT[".self"] = lud(ud2ptr(table)) //
		//                 setmetatable(newT, getVal)         //
		//                 storeatpeer(table, key, newTable)  //
		//                 return newTable                    //
		//             end                                    //
		//         end                                        //
		//     end                                            //
		//     curT = mt                                      //
		// end                                                //
		// return nil                                         //
		////////////////////////////////////////////////////////

		lua_settop(L, 2);                                          // 2 [ table, key ]

		if (callGetDynamic(L)) {
			return 1;
		}

		/*lua_pushvalue(L, 1);                                     // 3 [ table, key, table -> curT ]
		while (lua_getmetatable(L, -1)) {                          // TODO: Metatable Base
																   // 4 [ table, key, curT, mt(curT) ]
			lua_remove(L, -2);                                     // 3 [ table, key, mt(curT) ]
			if (lua_isnumber(L, 2)) {
				lua_pushstring(L, ".geti");                        // 4 [ table, key, mt(curT), ".geti" ]
				lua_rawget(L, -2);                                 // 4 [ table, key, mt(curT), mt(curT)[".geti"] ]
				if (lua_isfunction(L, -1)) {
					lua_pushvalue(L, 1);                           // 5 [ table, key, mt(curT), mt(curT)[".geti"], table ]
					lua_pushvalue(L, 2);                           // 6 [ table, key, mt(curT), mt(curT)[".geti"], table, key ]
					lua_call(L, 2, 1);                             // 4 [ table, key, mt(curT), retVal ]
					return 1;
				}
			}
			else {
				lua_pushvalue(L, 2);                               // 4 [ table, key, mt(curT), key ]
				lua_rawget(L, -2);                                 // 4 [ table, key, mt(curT), mt(curT)[key] ]
				if (!lua_isnil(L, -1)) {
					return 1;
				}
				else {
					lua_pop(L, 1);                                 // 3 [ table, key, mt(curT) ]
				}
				lua_pushstring(L, ".get");                         // 4 [ table, key, mt(curT), ".get" ]
				lua_rawget(L, -2);                                 // 4 [ table, key, mt(curT), mt(curT)[".get"] ]
				if (lua_istable(L, -1)) {
					lua_pushvalue(L, 2);                           // 5 [ table, key, mt(curT), mt(curT)[".get"], key ]
					lua_rawget(L, -2);                             // 5 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key] ]
					if (lua_iscfunction(L, -1)) {
						lua_pushvalue(L, 1);                       // 6 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], table ]
						lua_pushvalue(L, 2);                       // 7 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], table, key ]
						lua_call(L, 2, 1);                         // 5 [ table, key, mt(curT), mt(curT)[".get"], retVal ]
						return 1;
					}
					else if (lua_istable(L, -1)) {
						void* u = *((void**)lua_touserdata(L, 1));
						lua_newtable(L);                           // 6 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], newTable ]
						lua_pushstring(L, ".self");                // 7 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], newTable, ".self" ]
						lua_pushlightuserdata(L, u);               // 8 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], newTable, ".self", lud(ud2ptr(table)) ]
						lua_rawset(L, -3);                         // 6 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], newTable ]
						lua_insert(L, -2);                         // 6 [ table, key, mt(curT), mt(curT)[".get"], newTable, mt(table)[".get"][key] ]
						lua_setmetatable(L, -2);                   // 5 [ table, key, mt(curT), mt(curT)[".get"], newTable ]
						lua_pushvalue(L, -1);                      // 6 [ table, key, mt(curT), mt(curT)[".get"], newTable, newTable ]
						lua_pushvalue(L, 2);                       // 7 [ table, key, mt(curT), mt(curT)[".get"], newTable, newTable, key]
						lua_insert(L, -2);                         // 7 [ table, key, mt(curT), mt(curT)[".get"], newTable, key, newTable]
						storeatpeer(L, 1);                         // 5 [ table, key, mt(curT), mt(curT)[".get"], newTable ]
						return 1;
					}
				}
			}
			lua_settop(L, 3);                                      // 3 [ table, key, mt(table) -> curT ]
		}*/

		lua_pushnil(L);                                            // 4 [ table, key, ..., nil ]
		return 1;
	}
	else if (t == LUA_TTABLE) {
		module_index_event(L);                                     // 4 [ table, key, table[".get"], ..., retVal ]
		return 1;
	}
	lua_pushnil(L);                                                // 3 [ table, key, nil ]
	return 1;
}

//*************************************************//
// Pattern export: "override_class_newindex_event" //
//*************************************************//
// Expects [ table, key, value ]
int class_newindex_event(lua_State* L) {
	int t = lua_type(L, 1);
	if (t == LUA_TUSERDATA) {
		if (lua_isnumber(L, 2)) {
			callSetI(L);
			return 0;
		}
		else if (callSetDynamic(L)) {
			return 0;
		}
		storeatpeer(L, 1);
	}
	else if (t == LUA_TTABLE) {
		module_newindex_event(L);
	}
	return 0;
}

// Expects   [ ..., mt, key ]
// End Stack [ ..., mt, key, value ]
static void moduleGetOnBase(lua_State* L) {

	lua_pushstring(L, "tolua_base_map");   // 3 [ ..., mt, key, "tolua_base_map" ]
	lua_rawget(L, LUA_REGISTRYINDEX);      // 3 [ ..., mt, key, registry["tolua_base_map"] -> mtToBaseMapT ]

	lua_pushvalue(L, -3);                  // 4 [ ..., mt, key, mtToBaseMapT, mt ]
	lua_rawget(L, -2);                     // 4 [ ..., mt, key, mtToBaseMapT, mtToBaseMapT[mt] -> baseMapT ]

	// Validate that there are baseclasses mapped for the given metatable
	if (!lua_istable(L, -1)) {
		lua_pop(L, 2);                     // 2 [ ..., mt, key ]
		lua_pushnil(L);                    // 3 [ ..., mt, key, nil ]
		return;
	}

	// Iterate baseclasses (baseI == 1 is the class itself)
	for (int baseI = 2; ; ++baseI) {

		lua_pushinteger(L, baseI);         // 5 [ ..., mt, key, mtToBaseMapT, baseMapT, baseI ]
		lua_rawget(L, -2);                 // 5 [ ..., mt, key, mtToBaseMapT, baseMapT, baseMapT[baseI] -> baseT ]

		if (!lua_istable(L, -1)) {
			lua_pop(L, 3);                 // 2 [ ..., mt, key ]
			lua_pushnil(L);                // 3 [ ..., mt, key, nil ]
			return;
		}

		lua_pushstring(L, "mt");           // 6 [ ..., mt, key, mtToBaseMapT, baseMapT, baseT, "mt" ]
		lua_rawget(L, -2);                 // 6 [ ..., mt, key, mtToBaseMapT, baseMapT, baseT, baseT["mt"] -> baseMT ]

		lua_pushvalue(L, -5);              // 7 [ ..., mt, key, mtToBaseMapT, baseMapT, baseT, baseMT, key ]
		lua_rawget(L, -2);                 // 7 [ ..., mt, key, mtToBaseMapT, baseMapT, baseT, baseMT, baseMT[key] -> value ]

		if (!lua_isnil(L, -1)) {
			lua_insert(L, -5);             // 7 [ ..., mt, key, value, mtToBaseMapT, baseMapT, baseT, baseMT ]
			lua_pop(L, 4);                 // 3 [ ..., mt, key, value ]
			return;
		}

		lua_pop(L, 3);                     // 4 [ ..., mt, key, mtToBaseMapT, baseMapT ]
	}
}

//***********************************************//
// Pattern export: "override_module_index_event" //
//***********************************************//
// Expects   [ table, key ]
// End Stack [ table, key, table[".get"], ..., retVal ]
// Returns   1
int module_index_event(lua_State* L) {

	///////////////////////////////////////////
	// local getT = table[".get"]            //
	// if type(getT) == "table" then         //
	//     local getV = getT[key]            //
	//     if type(getV) == "cfunction" then //
	//         return getV()                 //
	//     elseif type(getV) == "table" then //
	//         return getV                   //
	//     end                               //
	// end                                   //
	///////////////////////////////////////////

	lua_pushstring(L, ".get");         // 3 [ table, key, ".get" ]
	lua_rawget(L, -3);                 // 3 [ table, key, table[".get"] ]

	if (lua_istable(L, -1)) {

		lua_pushvalue(L, 2);           // 4 [ table, key, table[".get"], key ]
		lua_rawget(L, -2);             // 4 [ table, key, table[".get"], table[".get"][key] ]

		if (lua_iscfunction(L, -1)) {
			lua_call(L, 0, 1);         // 3 [ table, key, table[".get"], retVal ]
			return 1;
		}
		else if (lua_istable(L, -1)) {
			return 1;
		}

		lua_pop(L, 1);                 // 3 [ table, key, table[".get"] ]
	}

	lua_pop(L, 1);                     // 2 [ table, key ]

	/////////////////////////////////////
	// Attempt to fetch from baseclass //
	/////////////////////////////////////

	moduleGetOnBase(L);
	return 1;
}

//**************************************************//
// Pattern export: "override_module_newindex_event" //
//**************************************************//
// Expects [ table, key, value ]
int module_newindex_event(lua_State* L) {

	if (callSet(L)) {
		return 0;
	}

	//if (lua_getmetatable(L, 1) && lua_getmetatable(L, -1)) {
	//	                                                       // [ table, key, value, ?, getmetatable(table), getmetatable(getmetatable(table)) ]
	//	lua_pushstring(L, "__newindex");                       // [ table, key, value, getmetatable(table), getmetatable(getmetatable(table)), "__newindex" ]
	//	lua_rawget(L, -2);                                     // [ table, key, value, getmetatable(table), getmetatable(getmetatable(table)), getmetatable(getmetatable(table))["__newindex"] ]
	//	if (lua_isfunction(L, -1)) {
	//		lua_pushvalue(L, 1);                               // [ table, key, value, getmetatable(table), getmetatable(getmetatable(table)), getmetatable(getmetatable(table))["__newindex"], table ]
	//		lua_pushvalue(L, 2);                               // [ table, key, value, getmetatable(table), getmetatable(getmetatable(table)), getmetatable(getmetatable(table))["__newindex"], table, key ]
	//		lua_pushvalue(L, 3);                               // [ table, key, value, getmetatable(table), getmetatable(getmetatable(table)), getmetatable(getmetatable(table))["__newindex"], table, key, value ]
	//		lua_call(L, 3, 0);                                 // [ table, key, value, getmetatable(table), getmetatable(getmetatable(table)) ]
	//	}
	//}
	//lua_settop(L, 3);
	//lua_rawset(L, -3);

	lua_rawset(L, -3);                                         // [ table ]
	return 0;
}

///////////////
// Overrides //
///////////////

//**********************************************//
// Pattern export: "override_tolua_beginmodule" //
//**********************************************//
// Expects   [ ..., module ]
// End Stack [ ..., module, module[name] or _G ]
EXPORT void tolua_beginmodule(lua_State* L, const char* name) {
	if (name) {
		lua_pushstring(L, name);     // 2 [ ..., module, name ]
		lua_rawget(L, -2);           // 2 [ ..., module, module[name] ]
	}
	else {
		tolua_push_globals_table(L); // 2 [ ..., module, _G ]
	}
}

// Expects   [ ..., module ]
// End Stack [ ..., module ]
EXPORT void tolua_cclass(lua_State* L, const char* lname, const char* name, std::initializer_list<const char*>&& bases, lua_CFunction col) {

	// Don't register cclass more than once
	lua_pushstring(L, "tolua_cclass_registered"); // 2 [ ..., module, "tolua_cclass_registered" ]
	getOrCreateTable(L, LUA_REGISTRYINDEX);       // 2 [ ..., module, registry["tolua_cclass_registered"] ]
	lua_pushstring(L, name);                      // 3 [ ..., module, registry["tolua_cclass_registered"], name ]
	lua_rawget(L, -2);                            // 3 [ ..., module, registry["tolua_cclass_registered"], registry["tolua_cclass_registered"][name] ]

	if (!lua_isnil(L, -1)) {
		lua_pop(L, 2);                            // 1 [ ..., module ]
		return;
	}
	lua_pop(L, 1);                                // 2 [ ..., module, registry["tolua_cclass_registered"] ]
	lua_pushstring(L, name);                      // 3 [ ..., module, registry["tolua_cclass_registered"], name ]
	lua_pushboolean(L, true);                     // 4 [ ..., module, registry["tolua_cclass_registered"], name, true ]
	lua_rawset(L, -3);                            // 2 [ ..., module, registry["tolua_cclass_registered"] ]
	lua_pop(L, 1);                                // 1 [ ..., module ]

	const char* baseName = bases.size() > 0 ? *bases.begin() : "";
	char constName[128] = "const ";
	char constBaseName[128] = "const ";
	strncat(constName, name, 120);
	strncat(constBaseName, baseName, 120);

	mapinheritance(L, name, baseName);
	mapinheritance(L, constName, name);

	mapsuper(L, constName, constBaseName);
	mapsuper(L, name, baseName);

	mapBases(L, name, bases);

	////////////////////////////////////////////
	// getmetatable(name)[".collector"] = col //
	// module[lname] = getmetatable(name)     //
	////////////////////////////////////////////

	lua_pushstring(L, lname);                     // 2 [ ..., module, lname ]
	tolua_getmetatable(L, name);                  // 3 [ ..., module, lname, getmetatable(name) ]
	// Disabled due to changes to "tolua_gc" and "tolua_ubox" registry functionality
	//lua_pushstring(L, ".collector");            // 4 [ ..., module, lname, getmetatable(name), ".collector" ]
	//lua_pushcfunction(L, col);                  // 5 [ ..., module, lname, getmetatable(name), ".collector", col ]
	//lua_rawset(L, -3);                          // 3 [ ..., module, lname, getmetatable(name) ]
	lua_rawset(L, -3);                            // 1 [ ..., module ]
}

//*****************************************//
// Pattern export: "override_tolua_module" //
//*****************************************//
// Expects 1 [ ..., table ]
EXPORT void tolua_module(lua_State* L, const char* name, int hasvar) {

	/////////////////////////////////////////
	// local module                        //
	// if name then                        //
	//     module = table[name]            //
	//     if type(module) ~= "table" then //
	//         module = {}                 //
	//         table[name] = module        //
	//     end                             //
	// else                                //
	//     module = _G                     //
	// end                                 //
	/////////////////////////////////////////

	if (name) {
		lua_pushstring(L, name);           // 2 [ ..., table, name ]
		lua_rawget(L, -2);                 // 2 [ ..., table, table[name] -> module ]
		if (!lua_istable(L, -1)) {
			lua_pop(L, 1);                 // 1 [ ..., table ]
			lua_newtable(L);               // 2 [ ..., table, newT ]
			lua_pushstring(L, name);       // 3 [ ..., table, newT, name ]
			lua_pushvalue(L, -2);          // 4 [ ..., table, newT, name, newT ]
			lua_rawset(L, -4);             // 2 [ ..., table, newT -> module ]
		}
	}
	else {
		tolua_push_globals_table(L);       // 2 [ ..., table, _G -> module ]
	}

	if (hasvar) {
		if (!tolua_ismodulemetatable(L)) {
			lua_newtable(L);               // 3 [ table, module, newMT ]
			tolua_moduleevents(L);
			if (lua_getmetatable(L, -2)) {
										   // 4 [ table, module, newMT, mt(module) ]
				lua_setmetatable(L, -2);   // 3 [ table, module, newMT ]
			}
			lua_setmetatable(L, -2);       // 2 [ table, module ]
		}
	}
	lua_pop(L, 1);                         // 1 [ table ]
}

//***************************************//
// Pattern export: "override_tolua_open" //
//***************************************//
EXPORT void tolua_open(lua_State* L) {
	int top = lua_gettop(L);
	lua_pushstring(L, "tolua_opened");       // [ "tolua_opened" ]
	lua_rawget(L, LUA_REGISTRYINDEX);        // [ registry["tolua_opened"] ]
	if (!lua_isboolean(L, -1)) {

		lua_pushstring(L, "tolua_opened");   // [ registry["tolua_opened"], "tolua_opened" ]
		lua_pushboolean(L, 1);               // [ registry["tolua_opened"], "tolua_opened", true ]
		lua_rawset(L, LUA_REGISTRYINDEX);    // [ registry["tolua_opened"] ]

		lua_pushstring(L, "tolua_ubox");     // [ registry["tolua_opened"], "tolua_ubox" ]
		lua_newtable(L);                     // [ registry["tolua_opened"], "tolua_ubox", newT ]
		lua_pushvalue(L, -1);                // [ registry["tolua_opened"], "tolua_ubox", newT, newT ]
		lua_pushstring(L, "__mode");         // [ registry["tolua_opened"], "tolua_ubox", newT, newT, "__mode" ]
		lua_pushstring(L, "v");              // [ registry["tolua_opened"], "tolua_ubox", newT, newT, "__mode", "v" ]
		lua_rawset(L, -3);                   // [ registry["tolua_opened"], "tolua_ubox", newT, newT ]
		lua_setmetatable(L, -2);             // [ registry["tolua_opened"], "tolua_ubox", newT ]
		lua_rawset(L, LUA_REGISTRYINDEX);    // [ registry["tolua_opened"] ]

		lua_pushstring(L, "tolua_peer");     // [ registry["tolua_opened"], "tolua_peer" ]
		lua_newtable(L);                     // [ registry["tolua_opened"], "tolua_peer", newT ]
		lua_pushvalue(L, -1);                // [ registry["tolua_opened"], "tolua_peer", newT, newT ]
		lua_pushstring(L, "__mode");         // [ registry["tolua_opened"], "tolua_peer", newT, newT, "__mode" ]
		lua_pushstring(L, "k");              // [ registry["tolua_opened"], "tolua_peer", newT, newT, "__mode", "k" ]
		lua_rawset(L, -3);                   // [ registry["tolua_opened"], "tolua_peer", newT, newT ]
		lua_setmetatable(L, -2);             // [ registry["tolua_opened"], "tolua_peer", newT ]
		lua_rawset(L, LUA_REGISTRYINDEX);    // [ registry["tolua_opened"] ]

		lua_pushstring(L, "tolua_super");    // [ registry["tolua_opened"], "tolua_super" ]
		lua_newtable(L);                     // [ registry["tolua_opened"], "tolua_super", newT ]
		lua_rawset(L, LUA_REGISTRYINDEX);    // [ registry["tolua_opened"] ]

		lua_pushstring(L, "tolua_gc");       // [ registry["tolua_opened"], "tolua_gc" ]
		lua_newtable(L);                     // [ registry["tolua_opened"], "tolua_gc", newT ]
		lua_rawset(L, LUA_REGISTRYINDEX);    // [ registry["tolua_opened"] ]

		lua_pushstring(L, "tolua_base");     // [ registry["tolua_opened"], "tolua_base" ]
		lua_newtable(L);                     // [ registry["tolua_opened"], "tolua_base", newT ]
		lua_rawset(L, LUA_REGISTRYINDEX);    // [ registry["tolua_opened"] ]

		lua_pushstring(L, "tolua_base_map"); // [ registry["tolua_opened"], "tolua_base_map" ]
		lua_newtable(L);                     // [ registry["tolua_opened"], "tolua_base_map", newT ]
		lua_rawset(L, LUA_REGISTRYINDEX);    // [ registry["tolua_opened"] ]

		tolua_newmetatable(L, "tolua_commonclass");

		tolua_module(L, NULL, 0);
		tolua_beginmodule(L, NULL);
		tolua_module(L, "tolua", 0);
		tolua_beginmodule(L, "tolua");
		tolua_function(L, "type", tolua_bnd_type);
		//tolua_function(L, "takeownership", tolua_bnd_takeownership);
		//tolua_function(L, "releaseownership", tolua_bnd_releaseownership);
		//tolua_function(L, "cast", tolua_bnd_cast);
		//tolua_function(L, "release", tolua_bnd_release);
		//tolua_function(L, "getpeertable", tolua_bnd_getpeertable);
		tolua_endmodule(L);
		tolua_endmodule(L);
	}
	lua_settop(L, top);
}

//************************************************//
// Pattern export: "Hardcoded_tolua_pushusertype" //
//************************************************//
EXPORT void tolua_pushusertype(lua_State* L, void* value, const char* type) {

	///////////////////////////////////////////////////
	// if value == nullptr then                      //
	//     return nil                                //
	// else                                          //
	//     local ud = ptr2ud(value)                  //
	//     local gcReg = registry["tolua_gc"]        //
	//     local gcT = gcReg[ptr2lud(value)]         //
	//     if gcT == nil then                        //
	//         gcT = { ["refCount"] = 1 }            //
	//         gcReg[ptr2lud(value)] = gcT           //
	//     else                                      //
	//         gcT["refCount"] = gcT["refCount"] + 1 //
	//     end                                       //
	//     return ud                                 //
	// end                                           //
	///////////////////////////////////////////////////

	if (value == nullptr) {
		lua_pushnil(L);                                                       // 1 [ ..., nil ]
	}
	else {
		*reinterpret_cast<void**>(lua_newuserdata(L, sizeof(void*))) = value; // 1 [ ..., ud ]
		tolua_getmetatable(L, type);                                          // 2 [ ..., ud, mt ]
		lua_setmetatable(L, -2);                                              // 1 [ ..., ud ]

		lua_pushstring(L, "tolua_gc");                                        // 2 [ ..., ud, "tolua_gc" ]
		lua_rawget(L, LUA_REGISTRYINDEX);                                     // 2 [ ..., ud, registry["tolua_gc"] ]

		lua_pushlightuserdata(L, value);                                      // 3 [ ..., ud, registry["tolua_gc"], lud(value) ]
		lua_rawget(L, -2);                                                    // 3 [ ..., ud, registry["tolua_gc"], registry["tolua_gc"][lud(value)] -> gcT ]

		if (lua_isnil(L, -1)) {

			lua_pop(L, 1);                                                    // 2 [ ..., ud, registry["tolua_gc"] ]
			lua_newtable(L);                                                  // 3 [ ..., ud, registry["tolua_gc"], gcT ]

			lua_pushstring(L, "refCount");                                    // 4 [ ..., ud, registry["tolua_gc"], gcT, "refCount" ]
			lua_pushinteger(L, 1);                                            // 5 [ ..., ud, registry["tolua_gc"], gcT, "refCount", 1 ]
			lua_rawset(L, -3);                                                // 3 [ ..., ud, registry["tolua_gc"], gcT ]

			lua_pushlightuserdata(L, value);                                  // 4 [ ..., ud, registry["tolua_gc"], gcT, lud(value) ]
			lua_pushvalue(L, -2);                                             // 5 [ ..., ud, registry["tolua_gc"], gcT, lud(value), gcT ]
			lua_rawset(L, -4);                                                // 3 [ ..., ud, registry["tolua_gc"], gcT ]
		}
		else {
			lua_pushstring(L, "refCount");                                    // 4 [ ..., ud, registry["tolua_gc"], gcT, "refCount" ]
			lua_rawget(L, -2);                                                // 4 [ ..., ud, registry["tolua_gc"], gcT, refCount ]
			const lua_Integer newRefCount = lua_tointeger(L, -1) + 1;
			lua_pop(L, 1);                                                    // 3 [ ..., ud, registry["tolua_gc"], gcT ]

			lua_pushstring(L, "refCount");                                    // 4 [ ..., ud, registry["tolua_gc"], gcT, "refCount" ]
			lua_pushinteger(L, newRefCount);                                  // 5 [ ..., ud, registry["tolua_gc"], gcT, "refCount", newRefCount ]
			lua_rawset(L, -3);                                                // 3 [ ..., ud, registry["tolua_gc"], gcT ]
		}

		lua_pop(L, 2);                                                        // 1 [ ..., ud ]
	}
}

//*******************************************//
// Pattern export: "override_tolua_usertype" //
//*******************************************//
EXPORT void tolua_usertype(lua_State* L, const char* type) {

	// Don't register same usertype more than once
	tolua_getmetatable(L, type); // 1 [ ..., getmetatable(type) ]
	if (!lua_isnil(L, -1)) {
		lua_pop(L, 1);           // 0 [ ... ]
		return;
	}
	lua_pop(L, 1);               // 0 [ ... ]

	char constType[128] = "const ";
	strncat(constType, type, 120);

	tolua_newmetatable(L, constType);
	tolua_newmetatable(L, type);

	mapsuper(L, type, constType);
}

////////////
// Custom //
////////////

//*****************************************//
// Pattern export: "override_tolua_cclass" //
//*****************************************//
void tolua_cclass_translate(lua_State* L, const char* lname, const char* name, const char* base, lua_CFunction col) {
	if (base[0] == '\0') {
		tolua_cclass(L, lname, name, {}, col);
	}
	else {
		tolua_cclass(L, lname, name, { base }, col);
	}
}

void tolua_pushusertypestring(lua_State* L, int index) {
	int tag = lua_type(L, index);
	if (tag == LUA_TUSERDATA && lua_getmetatable(L, index)) {
											  // [ getmetatable(stack[index]) ]
		lua_rawget(L, LUA_REGISTRYINDEX);     // [ registry[getmetatable(stack[index])] ]
		if (lua_type(L, -1) == LUA_TSTRING) {
			return;
		}
		else {
			lua_pop(L, 1);                    // [ ]
		}
	}
	lua_pushnil(L);                           // [ nil ]
}

//----------------//
// Custom Exports //
//----------------//

EXPORT bool tolua_function_toboolean(lua_State *const L, const int narg, const char *const functionName) {
	if (lua_gettop(L) < narg) {
		return luaL_error(L, "boolean argument #%d missing in function '%s'; 'boolean' or 'number' expected.", narg, functionName);
	}
	switch (lua_type(L, narg)) {
		case LUA_TBOOLEAN: return lua_toboolean(L, narg);
		case LUA_TNUMBER: {
			const lua_Integer arg = lua_tointeger(L, narg);
			switch (arg) {
				case 0: return false;
				case 1: return true;
			}
			return luaL_error(L, "invalid integer '%d' for boolean argument #%d in function '%s'; '0' or '1' expected.", arg, narg, functionName);
		}
	}
	return luaL_error(L, "invalid type '%s' for boolean argument #%d in function '%s'; 'boolean' or 'number' expected.", tolua_typename(L, narg), narg, functionName);
}

EXPORT char tolua_function_tochar(lua_State *const L, const int narg, const char *const functionName) {
	if (lua_gettop(L) < narg) {
		return luaL_error(L, "character argument #%d missing in function '%s'; 'string' or 'number' expected.", narg, functionName);
	}
	switch (lua_type(L, narg)) {
		case LUA_TSTRING: {
			const char *const arg = lua_tostring(L, narg);
			if (arg[0] != '\0' && arg[1] == '\0') {
				return arg[0];
			}
			return luaL_error(L, "invalid string '%s' for character argument #%d in function '%s'; 'string' of length 1 expected.", arg, narg, functionName);
		}
		case LUA_TNUMBER: {
			const lua_Integer arg = lua_tointeger(L, narg);
			if (arg >= -128 && arg <= 127) {
				return static_cast<char>(arg);
			}
			return luaL_error(L, "invalid integer '%d' for character argument #%d in function '%s'; '[-128-127]' expected.", arg, narg, functionName);
		}
	}
	return luaL_error(L, "invalid type '%s' for character argument #%d in function '%s'; 'string' or 'number' expected.", tolua_typename(L, narg), narg, functionName);
}

EXPORT const char* tolua_function_tostring(lua_State *const L, const int narg, const char *const functionName) {
	if (lua_gettop(L) < narg) {
		luaL_error(L, "string argument #%d missing in function '%s'; 'string' expected.", narg, functionName);
	}
	switch (lua_type(L, narg)) {
		case LUA_TSTRING: return lua_tostring(L, narg);
		case LUA_TLIGHTUSERDATA:
			if (lua_touserdata(L, narg) == &NULL_POINTER) {
				return nullptr;
			}
	}
	luaL_error(L, "invalid type '%s' for string argument #%d in function '%s'; 'string' expected.", tolua_typename(L, narg), narg, functionName);
	return nullptr; // To silence warning, luaL_error() never returns
}

EXPORT bool tolua_setter_toboolean(lua_State *const L, const char *const variableName) {
	constexpr int narg = 2;
	if (lua_gettop(L) < narg) {
		return luaL_error(L, "argument missing in boolean variable setter '%s'; 'boolean' or 'number' expected.", variableName);
	}
	switch (lua_type(L, narg)) {
		case LUA_TBOOLEAN: return lua_toboolean(L, narg);
		case LUA_TNUMBER: {
			const lua_Integer arg = lua_tointeger(L, narg);
			switch (arg) {
				case 0: return false;
				case 1: return true;
			}
			return luaL_error(L, "invalid integer argument '%d' in boolean variable setter '%s'; '0' or '1' expected.", arg, variableName);
		}
	}
	return luaL_error(L, "invalid type '%s' in boolean variable setter '%s'; 'boolean' or 'number' expected.", tolua_typename(L, narg), variableName);
}

EXPORT char tolua_setter_tochar(lua_State *const L, const char *const variableName) {
	constexpr int narg = 2;
	if (lua_gettop(L) < narg) {
		return luaL_error(L, "argument missing in character variable setter '%s'; 'string' or 'number' expected.", variableName);
	}
	switch (lua_type(L, narg)) {
		case LUA_TSTRING: {
			const char *const arg = lua_tostring(L, narg);
			if (arg[0] != '\0' && arg[1] == '\0') {
				return arg[0];
			}
			return luaL_error(L, "invalid string argument '%s' in character variable setter '%s'; 'string' of length 1 expected.", arg, variableName);
		}
		case LUA_TNUMBER: {
			const lua_Integer arg = lua_tointeger(L, narg);
			if (arg >= -128 && arg <= 127) {
				return static_cast<char>(arg);
			}
			return luaL_error(L, "invalid integer argument '%d' in character variable setter '%s'; '[-128-127]' expected.", arg, variableName);
		}
	}
	return luaL_error(L, "invalid type '%s' in character variable setter '%s'; 'string' or 'number' expected.", tolua_typename(L, narg), variableName);
}

EXPORT void* tolua_tousertype_dynamic(lua_State* L, int index, void* def, const char* targetUsertype) {

	if (abs(index) > lua_gettop(L)) {
		return def;
	}

	index = lua_absindex(L, index);

	void** u = reinterpret_cast<void**>(lua_touserdata(L, index));
	if (u == nullptr) {
		return nullptr;
	}

	void* ptr = *u;

	lua_pushstring(L, "tolua_base_map");   // 1 [ ...,"tolua_base_map" ]
	lua_rawget(L, LUA_REGISTRYINDEX);      // 1 [ ..., registry["tolua_base_map"] -> mtToBaseMapT ]

	// Fetch and validate metatable of userdata in existing index
	if (!lua_getmetatable(L, index)) {
		lua_pop(L, 1);                     // 0 [ ... ]
		return ptr;
	}
										   // 2 [ ..., mtToBaseMapT, mt ]
	lua_rawget(L, -2);                     // 2 [ ..., mtToBaseMapT, mtToBaseMapT[mt] -> baseMapT ]

	// Validate that there are baseclasses mapped for the given metatable
	if (!lua_istable(L, -1)) {
		lua_pop(L, 2);                     // 0 [ ... ]
		return ptr;
	}

	// Fetch metatable of target usertype
	tolua_getmetatable(L, targetUsertype); // 3 [ ..., mtToBaseMapT, baseMapT, targetMT ]

	// Validate metatable of target usertype
	if (!lua_istable(L, -1)) {
		lua_pop(L, 3);                     // 0 [ ... ]
		return ptr;
	}

	lua_Integer offset = 0;

	// Iterate baseclasses, match on target metatable, get offset to transform original usertype to target usertype
	for (int baseI = 1; ; ++baseI) {

		lua_pushinteger(L, baseI);         // 4 [ ..., mtToBaseMapT, baseMapT, targetMT, baseI ]
		lua_rawget(L, -3);                 // 4 [ ..., mtToBaseMapT, baseMapT, targetMT, baseMapT[baseI] -> baseT ]

		// Detect end of baseclass entries
		if (!lua_istable(L, -1)) {
			lua_pop(L, 1);                 // 3 [ ..., mtToBaseMapT, baseMapT, targetMT ]
			break;
		}

		lua_pushstring(L, "mt");           // 5 [ ..., mtToBaseMapT, baseMapT, targetMT, baseT, "mt" ]
		lua_rawget(L, -2);                 // 5 [ ..., mtToBaseMapT, baseMapT, targetMT, baseT, baseT["mt"] -> mt ]

		if (lua_rawequal(L, -3, -1)) {

			lua_pushstring(L, "offset");   // 6 [ ..., mtToBaseMapT, baseMapT, targetMT, baseT, mt, "offset" ]
			lua_rawget(L, -3);             // 6 [ ..., mtToBaseMapT, baseMapT, targetMT, baseT, mt, baseT["offset"] -> offset ]

			if (lua_isnumber(L, -1)) {
				offset = lua_tointeger(L, -1);
			}

			lua_pop(L, 3);                 // 3 [ ..., mtToBaseMapT, baseMapT, targetMT ]
			break;
		}
		else {
			lua_pop(L, 2);                 // 3 [ ..., mtToBaseMapT, baseMapT, targetMT ]
		}
	}
										   // 3 [ ..., mtToBaseMapT, baseMapT, targetMT ]
	lua_pop(L, 3);                         // 0 [ ... ]
	return reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(ptr) + offset);
}
