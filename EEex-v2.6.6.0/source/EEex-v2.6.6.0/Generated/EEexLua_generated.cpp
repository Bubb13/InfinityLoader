
#include "Baldur-v2.6.6.0_generated.h"
#include "Baldur-v2.6.6.0_lua_generated.h"
#include "lua_bindings_core_api.h"

static int tolua_get_EEex_Opcode_LuaHook_AfterListsResolved_Enabled(lua_State* L)
{
	tolua_pushboolean(L, (bool)EEex::Opcode_LuaHook_AfterListsResolved_Enabled);
	return 1;
}

static int tolua_set_EEex_Opcode_LuaHook_AfterListsResolved_Enabled(lua_State* L)
{
	EEex::Opcode_LuaHook_AfterListsResolved_Enabled = tolua_setter_toboolean(L, "Opcode_LuaHook_AfterListsResolved_Enabled");
	return 0;
}

static int tolua_get_EEex_reference_Opcode_LuaHook_AfterListsResolved_Enabled(lua_State* L)
{
	tolua_pushusertype(L, (void*)&EEex::Opcode_LuaHook_AfterListsResolved_Enabled, "Primitive<bool>");
	return 1;
}

static int tolua_get_EEex_Projectile_LuaHook_GlobalMutators_Enabled(lua_State* L)
{
	tolua_pushboolean(L, (bool)EEex::Projectile_LuaHook_GlobalMutators_Enabled);
	return 1;
}

static int tolua_set_EEex_Projectile_LuaHook_GlobalMutators_Enabled(lua_State* L)
{
	EEex::Projectile_LuaHook_GlobalMutators_Enabled = tolua_setter_toboolean(L, "Projectile_LuaHook_GlobalMutators_Enabled");
	return 0;
}

static int tolua_get_EEex_reference_Projectile_LuaHook_GlobalMutators_Enabled(lua_State* L)
{
	tolua_pushusertype(L, (void*)&EEex::Projectile_LuaHook_GlobalMutators_Enabled, "Primitive<bool>");
	return 1;
}

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

static int tolua_function_EEex_ShouldEffectBypassOp120(lua_State* L)
{
	bool returnVal = EEex::ShouldEffectBypassOp120((CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect"));
	tolua_pushboolean(L, (bool)returnVal);
	return 1;
}

static int tolua_function_EEex_GetExtendedStatValue(lua_State* L)
{
	int returnVal = EEex::GetExtendedStatValue((CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite"), tolua_function_tointeger<int>(L, 2, "GetExtendedStatValue"));
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_EEex_IsPlayerScript(lua_State* L)
{
	bool returnVal = EEex::IsPlayerScript((CAIScript*)tolua_tousertype_dynamic(L, 1, 0, "CAIScript"));
	tolua_pushboolean(L, (bool)returnVal);
	return 1;
}

static int tolua_function_EEex_HookIntegrityWatchdogIgnoreStackRange(lua_State* L)
{
	EEex::HookIntegrityWatchdogIgnoreStackRange(tolua_function_tointeger<uintptr_t>(L, 1, "HookIntegrityWatchdogIgnoreStackRange"), tolua_function_tointeger<size_t>(L, 2, "HookIntegrityWatchdogIgnoreStackRange"), tolua_function_tointeger<int>(L, 3, "HookIntegrityWatchdogIgnoreStackRange"), tolua_function_tointeger<int>(L, 4, "HookIntegrityWatchdogIgnoreStackRange"));
	return 0;
}

static int tolua_function_EEex_HookIntegrityWatchdogIgnoreRegisters(lua_State* L)
{
	EEex::HookIntegrityWatchdogIgnoreRegisters(tolua_function_tointeger<uintptr_t>(L, 1, "HookIntegrityWatchdogIgnoreRegisters"), tolua_function_tointeger<size_t>(L, 2, "HookIntegrityWatchdogIgnoreRegisters"), (EEex_HookIntegrityWatchdogRegister)tolua_function_tointeger<__int32>(L, 3, "HookIntegrityWatchdogIgnoreRegisters"));
	return 0;
}

static int tolua_function_EEex_DrawSlicedRectNum(lua_State* L)
{
	EEex::DrawSlicedRectNum(L);
	return 0;
}

static int tolua_function_EEex_RegisterSlicedRect(lua_State* L)
{
	EEex::RegisterSlicedRect(L);
	return 0;
}

static int tolua_function_EEex_DrawSlicedRect(lua_State* L)
{
	EEex::DrawSlicedRect(L);
	return 0;
}

static int tolua_function_EEex_IsDefaultAttackCursor(lua_State* L)
{
	bool returnVal = EEex::IsDefaultAttackCursor();
	tolua_pushboolean(L, (bool)returnVal);
	return 1;
}

static void tolua_reg_types(lua_State* L)
{
	tolua_usertype(L, "EEex_MatchObjectFlags");
	tolua_usertype(L, "EEex_HookIntegrityWatchdogRegister");
	tolua_usertype(L, "EEex");
	tolua_usertype(L, "EEex::ProjectileType");
}

void registerBaseclasses();
int OpenBindingsInternal(lua_State* L)
{
	registerBaseclasses();
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
	tolua_cclass(L, "EEex_HookIntegrityWatchdogRegister", "EEex_HookIntegrityWatchdogRegister", {"__int32"}, NULL);
	tolua_beginmodule(L, "EEex_HookIntegrityWatchdogRegister");
		tolua_constant(L, "RAX", 1);
		tolua_constant(L, "RBX", 2);
		tolua_constant(L, "RCX", 4);
		tolua_constant(L, "RDX", 8);
		tolua_constant(L, "RBP", 16);
		tolua_constant(L, "RSP", 32);
		tolua_constant(L, "RSI", 64);
		tolua_constant(L, "RDI", 128);
		tolua_constant(L, "R8", 256);
		tolua_constant(L, "R9", 512);
		tolua_constant(L, "R10", 1024);
		tolua_constant(L, "R11", 2048);
		tolua_constant(L, "R12", 65536);
		tolua_constant(L, "R13", 131072);
		tolua_constant(L, "R14", 262144);
		tolua_constant(L, "R15", 524288);
	tolua_endmodule(L);
	tolua_cclass(L, "EEex", "EEex", {}, NULL);
	tolua_beginmodule(L, "EEex");
		tolua_variable(L, "Opcode_LuaHook_AfterListsResolved_Enabled", tolua_get_EEex_Opcode_LuaHook_AfterListsResolved_Enabled, tolua_set_EEex_Opcode_LuaHook_AfterListsResolved_Enabled);
		tolua_variable(L, "reference_Opcode_LuaHook_AfterListsResolved_Enabled", tolua_get_EEex_reference_Opcode_LuaHook_AfterListsResolved_Enabled, NULL);
		tolua_variable(L, "Projectile_LuaHook_GlobalMutators_Enabled", tolua_get_EEex_Projectile_LuaHook_GlobalMutators_Enabled, tolua_set_EEex_Projectile_LuaHook_GlobalMutators_Enabled);
		tolua_variable(L, "reference_Projectile_LuaHook_GlobalMutators_Enabled", tolua_get_EEex_reference_Projectile_LuaHook_GlobalMutators_Enabled, NULL);
		tolua_function(L, "MatchObject", &tolua_function_EEex_MatchObject);
		tolua_function(L, "DeepCopy", &tolua_function_EEex_DeepCopy);
		tolua_function(L, "ShouldEffectBypassOp120", &tolua_function_EEex_ShouldEffectBypassOp120);
		tolua_function(L, "GetExtendedStatValue", &tolua_function_EEex_GetExtendedStatValue);
		tolua_function(L, "IsPlayerScript", &tolua_function_EEex_IsPlayerScript);
		tolua_function(L, "HookIntegrityWatchdogIgnoreStackRange", &tolua_function_EEex_HookIntegrityWatchdogIgnoreStackRange);
		tolua_function(L, "HookIntegrityWatchdogIgnoreRegisters", &tolua_function_EEex_HookIntegrityWatchdogIgnoreRegisters);
		tolua_function(L, "DrawSlicedRectNum", &tolua_function_EEex_DrawSlicedRectNum);
		tolua_function(L, "RegisterSlicedRect", &tolua_function_EEex_RegisterSlicedRect);
		tolua_function(L, "DrawSlicedRect", &tolua_function_EEex_DrawSlicedRect);
		tolua_function(L, "IsDefaultAttackCursor", &tolua_function_EEex_IsDefaultAttackCursor);
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
