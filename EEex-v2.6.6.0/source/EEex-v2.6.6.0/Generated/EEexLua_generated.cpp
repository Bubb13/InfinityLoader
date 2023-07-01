
#include "Baldur-v2.6.6.0_generated.h"
#include "Baldur-v2.6.6.0_lua_generated.h"
#include "lua_bindings_core_api.h"

static int tolua_function_EEex_MatchObject(lua_State* L)
{
	long returnVal = EEex::MatchObject(L, (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject"), tolua_function_tostring(L, 2, "MatchObject"), tolua_function_tointeger<int>(L, 3, "MatchObject"), tolua_function_tointeger<int>(L, 4, "MatchObject"), (EEex_MatchObjectFlags)tolua_function_tointeger<__int32>(L, 5, "MatchObject"));
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_EEex_DeepCopy(lua_State* L)
{
	EEex::DeepCopy(L);
	return 1;
}

static int tolua_function_EEex_test(lua_State* L)
{
	int returnVal = EEex::test();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static void tolua_reg_types(lua_State* L)
{
	tolua_usertype(L, "EEex_MatchObjectFlags");
	tolua_usertype(L, "EEex");
	tolua_usertype(L, "EEex::ProjectileType");
}

int OpenBindings(lua_State* L)
{
	tolua_open(L);
	tolua_reg_types(L);
	tolua_module(L, NULL, 0);
	tolua_beginmodule(L, NULL);
	tolua_cclass(L, "EEex_MatchObjectFlags", "EEex_MatchObjectFlags", {"__int32"}, NULL);
	tolua_beginmodule(L, "EEex_MatchObjectFlags");
		tolua_constant(L, "IGNORE_LOS", 1);
		tolua_constant(L, "MATCH_NON_SPRITES", 2);
		tolua_constant(L, "IGNORE_INVISIBLE", 4);
		tolua_constant(L, "MATCH_INVISIBLE", 8);
		tolua_constant(L, "MATCH_SLEEPING", 16);
		tolua_constant(L, "MATCH_DEAD", 32);
		tolua_constant(L, "MATCH_BACKLIST", 64);
		tolua_constant(L, "PRIORITIZE_BACKLIST", 128);
		tolua_constant(L, "MATCH_ONLY_BACKLIST", 256);
		tolua_constant(L, "FARTHEST", 512);
	tolua_endmodule(L);
	tolua_cclass(L, "EEex", "EEex", {}, NULL);
	tolua_beginmodule(L, "EEex");
		tolua_function(L, "MatchObject", &tolua_function_EEex_MatchObject);
		tolua_function(L, "DeepCopy", &tolua_function_EEex_DeepCopy);
		tolua_function(L, "test", &tolua_function_EEex_test);
	tolua_endmodule(L);
	tolua_cclass(L, "EEex::ProjectileType", "EEex::ProjectileType", {"__int32"}, NULL);
	tolua_beginmodule(L, "EEex::ProjectileType");
		tolua_constant(L, "Unknown", 1);
		tolua_constant(L, "CProjectile", 2);
		tolua_constant(L, "CProjectileAmbiant", 4);
		tolua_constant(L, "CProjectileArea", 8);
		tolua_constant(L, "CProjectileBAM", 16);
		tolua_constant(L, "CProjectileChain", 32);
		tolua_constant(L, "CProjectileColorSpray", 64);
		tolua_constant(L, "CProjectileConeOfCold", 128);
		tolua_constant(L, "CProjectileFall", 256);
		tolua_constant(L, "CProjectileFireHands", 512);
		tolua_constant(L, "CProjectileInstant", 1024);
		tolua_constant(L, "CProjectileMulti", 2048);
		tolua_constant(L, "CProjectileMushroom", 4096);
		tolua_constant(L, "CProjectileNewScorcher", 8192);
		tolua_constant(L, "CProjectileScorcher", 16384);
		tolua_constant(L, "CProjectileSegment", 32768);
		tolua_constant(L, "CProjectileSkyStrike", 65536);
		tolua_constant(L, "CProjectileSkyStrikeBAM", 131072);
		tolua_constant(L, "CProjectileSpellHit", 262144);
		tolua_constant(L, "CProjectileTravelDoor", 524288);
	tolua_endmodule(L);
	tolua_endmodule(L);
	return 1;
}
