
#include "engine_structs_generated.h"
#include "Baldur-v2.5.17.0_lua_generated.h"
#include "lua_bindings_core_api.h"

static int tolua_get_CGameAnimation_m_animation(lua_State* L)
{
	CGameAnimation* self = (CGameAnimation*)tolua_tousertype_dynamic(L, 1, 0, "CGameAnimation");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_animation'", NULL);
	tolua_pushusertype(L, (void*)self->m_animation, "CGameAnimationType");
	return 1;
}

static int tolua_set_CGameAnimation_m_animation(lua_State* L)
{
	CGameAnimation* self = (CGameAnimation*)tolua_tousertype_dynamic(L, 1, 0, "CGameAnimation");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_animation'", NULL);
	self->m_animation = (CGameAnimationType*)tolua_tousertype_dynamic(L, 2, 0, "CGameAnimationType");
	return 0;
}

static int tolua_get_CGameAnimation_reference_m_animation(lua_State* L)
{
	CGameAnimation* self = (CGameAnimation*)tolua_tousertype_dynamic(L, 1, 0, "CGameAnimation");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_animation'", NULL);
	tolua_pushusertype(L, (void*)&self->m_animation, "Pointer<CGameAnimationType>");
	return 1;
}

static int tolua_get_CPtrList_CNode_pNext(lua_State* L)
{
	CPtrList_CNode* self = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList_CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pNext'", NULL);
	tolua_pushusertype(L, (void*)self->pNext, "CPtrList_CNode");
	return 1;
}

static int tolua_set_CPtrList_CNode_pNext(lua_State* L)
{
	CPtrList_CNode* self = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList_CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pNext'", NULL);
	self->pNext = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 2, 0, "CPtrList_CNode");
	return 0;
}

static int tolua_get_CPtrList_CNode_reference_pNext(lua_State* L)
{
	CPtrList_CNode* self = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList_CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pNext'", NULL);
	tolua_pushusertype(L, (void*)&self->pNext, "Pointer<CPtrList_CNode>");
	return 1;
}

static int tolua_get_CPtrList_CNode_pPrev(lua_State* L)
{
	CPtrList_CNode* self = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList_CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pPrev'", NULL);
	tolua_pushusertype(L, (void*)self->pPrev, "CPtrList_CNode");
	return 1;
}

static int tolua_set_CPtrList_CNode_pPrev(lua_State* L)
{
	CPtrList_CNode* self = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList_CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pPrev'", NULL);
	self->pPrev = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 2, 0, "CPtrList_CNode");
	return 0;
}

static int tolua_get_CPtrList_CNode_reference_pPrev(lua_State* L)
{
	CPtrList_CNode* self = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList_CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pPrev'", NULL);
	tolua_pushusertype(L, (void*)&self->pPrev, "Pointer<CPtrList_CNode>");
	return 1;
}

static int tolua_get_CPtrList_CNode_data(lua_State* L)
{
	CPtrList_CNode* self = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList_CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	tolua_pushusertype(L, (void*)self->data, "UnmappedUserType");
	return 1;
}

static int tolua_set_CPtrList_CNode_data(lua_State* L)
{
	CPtrList_CNode* self = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList_CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	self->data = (void*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType");
	return 0;
}

static int tolua_get_CPtrList_CNode_reference_data(lua_State* L)
{
	CPtrList_CNode* self = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList_CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	tolua_pushusertype(L, (void*)&self->data, "VoidPointer");
	return 1;
}

static int tolua_get_CVideo_pCurrentMode(lua_State* L)
{
	CVideo* self = (CVideo*)tolua_tousertype_dynamic(L, 1, 0, "CVideo");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pCurrentMode'", NULL);
	tolua_pushusertype(L, (void*)self->pCurrentMode, "CVidMode");
	return 1;
}

static int tolua_set_CVideo_pCurrentMode(lua_State* L)
{
	CVideo* self = (CVideo*)tolua_tousertype_dynamic(L, 1, 0, "CVideo");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pCurrentMode'", NULL);
	self->pCurrentMode = (CVidMode*)tolua_tousertype_dynamic(L, 2, 0, "CVidMode");
	return 0;
}

static int tolua_get_CVideo_reference_pCurrentMode(lua_State* L)
{
	CVideo* self = (CVideo*)tolua_tousertype_dynamic(L, 1, 0, "CVideo");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pCurrentMode'", NULL);
	tolua_pushusertype(L, (void*)&self->pCurrentMode, "Pointer<CVidMode>");
	return 1;
}

static int tolua_get_g_pBaldurChitin(lua_State* L)
{
	tolua_pushusertype(L, (void*)*p_g_pBaldurChitin, "EEex_CBaldurChitin");
	return 1;
}

static int tolua_set_g_pBaldurChitin(lua_State* L)
{
	*p_g_pBaldurChitin = (CBaldurChitin*)tolua_tousertype_dynamic(L, 2, 0, "EEex_CBaldurChitin");
	return 0;
}

static int tolua_get_reference_g_pBaldurChitin(lua_State* L)
{
	tolua_pushusertype(L, (void*)p_g_pBaldurChitin, "Pointer<EEex_CBaldurChitin>");
	return 1;
}

static int tolua_get_Primitive_CGameObjectType__value(lua_State* L)
{
	Primitive<CGameObjectType>* self = (Primitive<CGameObjectType>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<CGameObjectType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_CGameObjectType__value(lua_State* L)
{
	Primitive<CGameObjectType>* self = (Primitive<CGameObjectType>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<CGameObjectType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = (CGameObjectType)tolua_setter_tointeger<__int8>(L, "value");
	return 0;
}

static int tolua_get_Primitive_CGameObjectType__reference_value(lua_State* L)
{
	Primitive<CGameObjectType>* self = (Primitive<CGameObjectType>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<CGameObjectType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<CGameObjectType>");
	return 1;
}

static int tolua_get_Primitive_DrawFeature__value(lua_State* L)
{
	Primitive<DrawFeature>* self = (Primitive<DrawFeature>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<DrawFeature>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_DrawFeature__value(lua_State* L)
{
	Primitive<DrawFeature>* self = (Primitive<DrawFeature>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<DrawFeature>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = (DrawFeature)tolua_setter_tointeger<__int32>(L, "value");
	return 0;
}

static int tolua_get_Primitive_DrawFeature__reference_value(lua_State* L)
{
	Primitive<DrawFeature>* self = (Primitive<DrawFeature>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<DrawFeature>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<DrawFeature>");
	return 1;
}

static int tolua_get_Primitive_PlayerScriptNameOrdinal__value(lua_State* L)
{
	Primitive<PlayerScriptNameOrdinal>* self = (Primitive<PlayerScriptNameOrdinal>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<PlayerScriptNameOrdinal>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_PlayerScriptNameOrdinal__value(lua_State* L)
{
	Primitive<PlayerScriptNameOrdinal>* self = (Primitive<PlayerScriptNameOrdinal>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<PlayerScriptNameOrdinal>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = (PlayerScriptNameOrdinal)tolua_setter_tointeger<__int32>(L, "value");
	return 0;
}

static int tolua_get_Primitive_PlayerScriptNameOrdinal__reference_value(lua_State* L)
{
	Primitive<PlayerScriptNameOrdinal>* self = (Primitive<PlayerScriptNameOrdinal>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<PlayerScriptNameOrdinal>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<PlayerScriptNameOrdinal>");
	return 1;
}

static int tolua_get_Primitive_VertListType__value(lua_State* L)
{
	Primitive<VertListType>* self = (Primitive<VertListType>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<VertListType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_VertListType__value(lua_State* L)
{
	Primitive<VertListType>* self = (Primitive<VertListType>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<VertListType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = (VertListType)tolua_setter_tointeger<__int8>(L, "value");
	return 0;
}

static int tolua_get_Primitive_VertListType__reference_value(lua_State* L)
{
	Primitive<VertListType>* self = (Primitive<VertListType>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<VertListType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<VertListType>");
	return 1;
}

static int tolua_get_Primitive_long_double__value(lua_State* L)
{
	Primitive<long double>* self = (Primitive<long double>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<long double>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushnumber(L, (lua_Number)self->value);
	return 1;
}

static int tolua_set_Primitive_long_double__value(lua_State* L)
{
	Primitive<long double>* self = (Primitive<long double>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<long double>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tonumber<long double>(L, "value");
	return 0;
}

static int tolua_get_Primitive_long_double__reference_value(lua_State* L)
{
	Primitive<long double>* self = (Primitive<long double>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<long double>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<double>");
	return 1;
}

static int tolua_get_Primitive_uint16_t__value(lua_State* L)
{
	Primitive<uint16_t>* self = (Primitive<uint16_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uint16_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_uint16_t__value(lua_State* L)
{
	Primitive<uint16_t>* self = (Primitive<uint16_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uint16_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<uint16_t>(L, "value");
	return 0;
}

static int tolua_get_Primitive_uint16_t__reference_value(lua_State* L)
{
	Primitive<uint16_t>* self = (Primitive<uint16_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uint16_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<uint16_t>");
	return 1;
}

static int tolua_get_Primitive_int__value(lua_State* L)
{
	Primitive<int>* self = (Primitive<int>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_int__value(lua_State* L)
{
	Primitive<int>* self = (Primitive<int>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<int>(L, "value");
	return 0;
}

static int tolua_get_Primitive_int__reference_value(lua_State* L)
{
	Primitive<int>* self = (Primitive<int>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<int>");
	return 1;
}

static int tolua_get_Primitive_int64_t__value(lua_State* L)
{
	Primitive<int64_t>* self = (Primitive<int64_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<int64_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_int64_t__value(lua_State* L)
{
	Primitive<int64_t>* self = (Primitive<int64_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<int64_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<int64_t>(L, "value");
	return 0;
}

static int tolua_get_Primitive_int64_t__reference_value(lua_State* L)
{
	Primitive<int64_t>* self = (Primitive<int64_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<int64_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<int64_t>");
	return 1;
}

static int tolua_get_Primitive_intptr_t__value(lua_State* L)
{
	Primitive<intptr_t>* self = (Primitive<intptr_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<intptr_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_intptr_t__value(lua_State* L)
{
	Primitive<intptr_t>* self = (Primitive<intptr_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<intptr_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<intptr_t>(L, "value");
	return 0;
}

static int tolua_get_Primitive_intptr_t__reference_value(lua_State* L)
{
	Primitive<intptr_t>* self = (Primitive<intptr_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<intptr_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<intptr_t>");
	return 1;
}

static int tolua_get_Primitive___int64__value(lua_State* L)
{
	Primitive<__int64>* self = (Primitive<__int64>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<__int64>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive___int64__value(lua_State* L)
{
	Primitive<__int64>* self = (Primitive<__int64>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<__int64>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<__int64>(L, "value");
	return 0;
}

static int tolua_get_Primitive___int64__reference_value(lua_State* L)
{
	Primitive<__int64>* self = (Primitive<__int64>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<__int64>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<__int64>");
	return 1;
}

static int tolua_get_Primitive_long__value(lua_State* L)
{
	Primitive<long>* self = (Primitive<long>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_long__value(lua_State* L)
{
	Primitive<long>* self = (Primitive<long>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<long>(L, "value");
	return 0;
}

static int tolua_get_Primitive_long__reference_value(lua_State* L)
{
	Primitive<long>* self = (Primitive<long>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<long>");
	return 1;
}

static int tolua_get_Primitive___int8__value(lua_State* L)
{
	Primitive<__int8>* self = (Primitive<__int8>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<__int8>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive___int8__value(lua_State* L)
{
	Primitive<__int8>* self = (Primitive<__int8>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<__int8>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<__int8>(L, "value");
	return 0;
}

static int tolua_get_Primitive___int8__reference_value(lua_State* L)
{
	Primitive<__int8>* self = (Primitive<__int8>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<__int8>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<__int8>");
	return 1;
}

static int tolua_get_Primitive_double__value(lua_State* L)
{
	Primitive<double>* self = (Primitive<double>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<double>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushnumber(L, (lua_Number)self->value);
	return 1;
}

static int tolua_set_Primitive_double__value(lua_State* L)
{
	Primitive<double>* self = (Primitive<double>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<double>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tonumber<double>(L, "value");
	return 0;
}

static int tolua_get_Primitive_double__reference_value(lua_State* L)
{
	Primitive<double>* self = (Primitive<double>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<double>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<double>");
	return 1;
}

static int tolua_get_Primitive_byte__value(lua_State* L)
{
	Primitive<byte>* self = (Primitive<byte>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<byte>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_byte__value(lua_State* L)
{
	Primitive<byte>* self = (Primitive<byte>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<byte>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<byte>(L, "value");
	return 0;
}

static int tolua_get_Primitive_byte__reference_value(lua_State* L)
{
	Primitive<byte>* self = (Primitive<byte>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<byte>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<byte>");
	return 1;
}

static int tolua_get_Primitive_float__value(lua_State* L)
{
	Primitive<float>* self = (Primitive<float>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<float>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushnumber(L, (lua_Number)self->value);
	return 1;
}

static int tolua_set_Primitive_float__value(lua_State* L)
{
	Primitive<float>* self = (Primitive<float>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<float>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tonumber<float>(L, "value");
	return 0;
}

static int tolua_get_Primitive_float__reference_value(lua_State* L)
{
	Primitive<float>* self = (Primitive<float>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<float>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<float>");
	return 1;
}

static int tolua_get_Primitive___int16__value(lua_State* L)
{
	Primitive<__int16>* self = (Primitive<__int16>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<__int16>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive___int16__value(lua_State* L)
{
	Primitive<__int16>* self = (Primitive<__int16>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<__int16>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<__int16>(L, "value");
	return 0;
}

static int tolua_get_Primitive___int16__reference_value(lua_State* L)
{
	Primitive<__int16>* self = (Primitive<__int16>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<__int16>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<__int16>");
	return 1;
}

static int tolua_get_Primitive_uint__value(lua_State* L)
{
	Primitive<uint>* self = (Primitive<uint>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uint>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_uint__value(lua_State* L)
{
	Primitive<uint>* self = (Primitive<uint>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uint>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<uint>(L, "value");
	return 0;
}

static int tolua_get_Primitive_uint__reference_value(lua_State* L)
{
	Primitive<uint>* self = (Primitive<uint>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uint>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<uint>");
	return 1;
}

static int tolua_get_Primitive_short__value(lua_State* L)
{
	Primitive<short>* self = (Primitive<short>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<short>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_short__value(lua_State* L)
{
	Primitive<short>* self = (Primitive<short>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<short>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<short>(L, "value");
	return 0;
}

static int tolua_get_Primitive_short__reference_value(lua_State* L)
{
	Primitive<short>* self = (Primitive<short>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<short>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<short>");
	return 1;
}

static int tolua_get_Primitive_int16_t__value(lua_State* L)
{
	Primitive<int16_t>* self = (Primitive<int16_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<int16_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_int16_t__value(lua_State* L)
{
	Primitive<int16_t>* self = (Primitive<int16_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<int16_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<int16_t>(L, "value");
	return 0;
}

static int tolua_get_Primitive_int16_t__reference_value(lua_State* L)
{
	Primitive<int16_t>* self = (Primitive<int16_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<int16_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<int16_t>");
	return 1;
}

static int tolua_get_Primitive_uintptr_t__value(lua_State* L)
{
	Primitive<uintptr_t>* self = (Primitive<uintptr_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uintptr_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_uintptr_t__value(lua_State* L)
{
	Primitive<uintptr_t>* self = (Primitive<uintptr_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uintptr_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<uintptr_t>(L, "value");
	return 0;
}

static int tolua_get_Primitive_uintptr_t__reference_value(lua_State* L)
{
	Primitive<uintptr_t>* self = (Primitive<uintptr_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uintptr_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<uintptr_t>");
	return 1;
}

static int tolua_get_Primitive_char__value(lua_State* L)
{
	Primitive<char>* self = (Primitive<char>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<char>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushlstring(L, (const char*)self->value, 1);
	return 1;
}

static int tolua_set_Primitive_char__value(lua_State* L)
{
	Primitive<char>* self = (Primitive<char>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<char>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tochar(L, "value");
	return 0;
}

static int tolua_get_Primitive_char__reference_value(lua_State* L)
{
	Primitive<char>* self = (Primitive<char>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<char>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "char");
	return 1;
}

static int tolua_get_Primitive_int8_t__value(lua_State* L)
{
	Primitive<int8_t>* self = (Primitive<int8_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<int8_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_int8_t__value(lua_State* L)
{
	Primitive<int8_t>* self = (Primitive<int8_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<int8_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<int8_t>(L, "value");
	return 0;
}

static int tolua_get_Primitive_int8_t__reference_value(lua_State* L)
{
	Primitive<int8_t>* self = (Primitive<int8_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<int8_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<int8_t>");
	return 1;
}

static int tolua_get_Primitive_ushort__value(lua_State* L)
{
	Primitive<ushort>* self = (Primitive<ushort>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<ushort>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_ushort__value(lua_State* L)
{
	Primitive<ushort>* self = (Primitive<ushort>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<ushort>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<ushort>(L, "value");
	return 0;
}

static int tolua_get_Primitive_ushort__reference_value(lua_State* L)
{
	Primitive<ushort>* self = (Primitive<ushort>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<ushort>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<ushort>");
	return 1;
}

static int tolua_get_Primitive_bool__value(lua_State* L)
{
	Primitive<bool>* self = (Primitive<bool>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<bool>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushboolean(L, (bool)self->value);
	return 1;
}

static int tolua_set_Primitive_bool__value(lua_State* L)
{
	Primitive<bool>* self = (Primitive<bool>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<bool>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_toboolean(L, "value");
	return 0;
}

static int tolua_get_Primitive_bool__reference_value(lua_State* L)
{
	Primitive<bool>* self = (Primitive<bool>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<bool>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<bool>");
	return 1;
}

static int tolua_get_Primitive_int32_t__value(lua_State* L)
{
	Primitive<int32_t>* self = (Primitive<int32_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<int32_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_int32_t__value(lua_State* L)
{
	Primitive<int32_t>* self = (Primitive<int32_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<int32_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<int32_t>(L, "value");
	return 0;
}

static int tolua_get_Primitive_int32_t__reference_value(lua_State* L)
{
	Primitive<int32_t>* self = (Primitive<int32_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<int32_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<int32_t>");
	return 1;
}

static int tolua_get_Primitive_uint64_t__value(lua_State* L)
{
	Primitive<uint64_t>* self = (Primitive<uint64_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uint64_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_uint64_t__value(lua_State* L)
{
	Primitive<uint64_t>* self = (Primitive<uint64_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uint64_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<uint64_t>(L, "value");
	return 0;
}

static int tolua_get_Primitive_uint64_t__reference_value(lua_State* L)
{
	Primitive<uint64_t>* self = (Primitive<uint64_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uint64_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<uint64_t>");
	return 1;
}

static int tolua_get_Primitive___int32__value(lua_State* L)
{
	Primitive<__int32>* self = (Primitive<__int32>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<__int32>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive___int32__value(lua_State* L)
{
	Primitive<__int32>* self = (Primitive<__int32>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<__int32>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<__int32>(L, "value");
	return 0;
}

static int tolua_get_Primitive___int32__reference_value(lua_State* L)
{
	Primitive<__int32>* self = (Primitive<__int32>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<__int32>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<__int32>");
	return 1;
}

static int tolua_get_Primitive_size_t__value(lua_State* L)
{
	Primitive<size_t>* self = (Primitive<size_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<size_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_size_t__value(lua_State* L)
{
	Primitive<size_t>* self = (Primitive<size_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<size_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<size_t>(L, "value");
	return 0;
}

static int tolua_get_Primitive_size_t__reference_value(lua_State* L)
{
	Primitive<size_t>* self = (Primitive<size_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<size_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<size_t>");
	return 1;
}

static int tolua_get_Primitive_uint8_t__value(lua_State* L)
{
	Primitive<uint8_t>* self = (Primitive<uint8_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uint8_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_uint8_t__value(lua_State* L)
{
	Primitive<uint8_t>* self = (Primitive<uint8_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uint8_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<uint8_t>(L, "value");
	return 0;
}

static int tolua_get_Primitive_uint8_t__reference_value(lua_State* L)
{
	Primitive<uint8_t>* self = (Primitive<uint8_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uint8_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<uint8_t>");
	return 1;
}

static int tolua_get_Primitive_uint32_t__value(lua_State* L)
{
	Primitive<uint32_t>* self = (Primitive<uint32_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uint32_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_uint32_t__value(lua_State* L)
{
	Primitive<uint32_t>* self = (Primitive<uint32_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uint32_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<uint32_t>(L, "value");
	return 0;
}

static int tolua_get_Primitive_uint32_t__reference_value(lua_State* L)
{
	Primitive<uint32_t>* self = (Primitive<uint32_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<uint32_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<uint32_t>");
	return 1;
}

static int tolua_get_Primitive_ptrdiff_t__value(lua_State* L)
{
	Primitive<ptrdiff_t>* self = (Primitive<ptrdiff_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<ptrdiff_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	lua_pushinteger(L, (lua_Integer)self->value);
	return 1;
}

static int tolua_set_Primitive_ptrdiff_t__value(lua_State* L)
{
	Primitive<ptrdiff_t>* self = (Primitive<ptrdiff_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<ptrdiff_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	self->value = tolua_setter_tointeger<ptrdiff_t>(L, "value");
	return 0;
}

static int tolua_get_Primitive_ptrdiff_t__reference_value(lua_State* L)
{
	Primitive<ptrdiff_t>* self = (Primitive<ptrdiff_t>*)tolua_tousertype_dynamic(L, 1, 0, "Primitive<ptrdiff_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'value'", NULL);
	tolua_pushusertype(L, (void*)&self->value, "Primitive<ptrdiff_t>");
	return 1;
}

static int tolua_get_VoidPointer_reference(lua_State* L)
{
	VoidPointer* self = (VoidPointer*)tolua_tousertype_dynamic(L, 1, 0, "VoidPointer");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "UnmappedUserType");
	return 1;
}

static int tolua_set_VoidPointer_reference(lua_State* L)
{
	VoidPointer* self = (VoidPointer*)tolua_tousertype_dynamic(L, 1, 0, "VoidPointer");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (void*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType");
	return 0;
}

static int tolua_get_CRect_left(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'left'", NULL);
	lua_pushinteger(L, (lua_Integer)self->left);
	return 1;
}

static int tolua_set_CRect_left(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'left'", NULL);
	self->left = tolua_setter_tointeger<int>(L, "left");
	return 0;
}

static int tolua_get_CRect_reference_left(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'left'", NULL);
	tolua_pushusertype(L, (void*)&self->left, "Primitive<int>");
	return 1;
}

static int tolua_get_CRect_top(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'top'", NULL);
	lua_pushinteger(L, (lua_Integer)self->top);
	return 1;
}

static int tolua_set_CRect_top(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'top'", NULL);
	self->top = tolua_setter_tointeger<int>(L, "top");
	return 0;
}

static int tolua_get_CRect_reference_top(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'top'", NULL);
	tolua_pushusertype(L, (void*)&self->top, "Primitive<int>");
	return 1;
}

static int tolua_get_CRect_right(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'right'", NULL);
	lua_pushinteger(L, (lua_Integer)self->right);
	return 1;
}

static int tolua_set_CRect_right(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'right'", NULL);
	self->right = tolua_setter_tointeger<int>(L, "right");
	return 0;
}

static int tolua_get_CRect_reference_right(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'right'", NULL);
	tolua_pushusertype(L, (void*)&self->right, "Primitive<int>");
	return 1;
}

static int tolua_get_CRect_bottom(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bottom'", NULL);
	lua_pushinteger(L, (lua_Integer)self->bottom);
	return 1;
}

static int tolua_set_CRect_bottom(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bottom'", NULL);
	self->bottom = tolua_setter_tointeger<int>(L, "bottom");
	return 0;
}

static int tolua_get_CRect_reference_bottom(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bottom'", NULL);
	tolua_pushusertype(L, (void*)&self->bottom, "Primitive<int>");
	return 1;
}

static int tolua_get_CPtrList_m_pNodeHead(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeHead'", NULL);
	tolua_pushusertype(L, (void*)self->m_pNodeHead, "CPtrList_CNode");
	return 1;
}

static int tolua_set_CPtrList_m_pNodeHead(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeHead'", NULL);
	self->m_pNodeHead = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 2, 0, "CPtrList_CNode");
	return 0;
}

static int tolua_get_CPtrList_reference_m_pNodeHead(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeHead'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pNodeHead, "Pointer<CPtrList_CNode>");
	return 1;
}

static int tolua_get_CPtrList_m_pNodeTail(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeTail'", NULL);
	tolua_pushusertype(L, (void*)self->m_pNodeTail, "CPtrList_CNode");
	return 1;
}

static int tolua_set_CPtrList_m_pNodeTail(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeTail'", NULL);
	self->m_pNodeTail = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 2, 0, "CPtrList_CNode");
	return 0;
}

static int tolua_get_CPtrList_reference_m_pNodeTail(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeTail'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pNodeTail, "Pointer<CPtrList_CNode>");
	return 1;
}

static int tolua_get_CPtrList_m_nCount(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nCount);
	return 1;
}

static int tolua_set_CPtrList_m_nCount(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	self->m_nCount = tolua_setter_tointeger<int>(L, "m_nCount");
	return 0;
}

static int tolua_get_CPtrList_reference_m_nCount(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nCount, "Primitive<int>");
	return 1;
}

static int tolua_get_CPtrList_m_pNodeFree(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeFree'", NULL);
	tolua_pushusertype(L, (void*)self->m_pNodeFree, "CPtrList_CNode");
	return 1;
}

static int tolua_set_CPtrList_m_pNodeFree(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeFree'", NULL);
	self->m_pNodeFree = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 2, 0, "CPtrList_CNode");
	return 0;
}

static int tolua_get_CPtrList_reference_m_pNodeFree(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeFree'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pNodeFree, "Pointer<CPtrList_CNode>");
	return 1;
}

static int tolua_get_CPtrList_m_pBlocks(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertype(L, (void*)self->m_pBlocks, "UnmappedUserType");
	return 1;
}

static int tolua_set_CPtrList_m_pBlocks(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	self->m_pBlocks = (void*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType");
	return 0;
}

static int tolua_get_CPtrList_reference_m_pBlocks(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pBlocks, "VoidPointer");
	return 1;
}

static int tolua_get_CPtrList_m_nBlockSize(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nBlockSize);
	return 1;
}

static int tolua_set_CPtrList_m_nBlockSize(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	self->m_nBlockSize = tolua_setter_tointeger<int>(L, "m_nBlockSize");
	return 0;
}

static int tolua_get_CPtrList_reference_m_nBlockSize(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nBlockSize, "Primitive<int>");
	return 1;
}

static int tolua_get_CPoint_x(lua_State* L)
{
	CPoint* self = (CPoint*)tolua_tousertype_dynamic(L, 1, 0, "CPoint");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'x'", NULL);
	lua_pushinteger(L, (lua_Integer)self->x);
	return 1;
}

static int tolua_set_CPoint_x(lua_State* L)
{
	CPoint* self = (CPoint*)tolua_tousertype_dynamic(L, 1, 0, "CPoint");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'x'", NULL);
	self->x = tolua_setter_tointeger<int>(L, "x");
	return 0;
}

static int tolua_get_CPoint_reference_x(lua_State* L)
{
	CPoint* self = (CPoint*)tolua_tousertype_dynamic(L, 1, 0, "CPoint");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'x'", NULL);
	tolua_pushusertype(L, (void*)&self->x, "Primitive<int>");
	return 1;
}

static int tolua_get_CPoint_y(lua_State* L)
{
	CPoint* self = (CPoint*)tolua_tousertype_dynamic(L, 1, 0, "CPoint");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'y'", NULL);
	lua_pushinteger(L, (lua_Integer)self->y);
	return 1;
}

static int tolua_set_CPoint_y(lua_State* L)
{
	CPoint* self = (CPoint*)tolua_tousertype_dynamic(L, 1, 0, "CPoint");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'y'", NULL);
	self->y = tolua_setter_tointeger<int>(L, "y");
	return 0;
}

static int tolua_get_CPoint_reference_y(lua_State* L)
{
	CPoint* self = (CPoint*)tolua_tousertype_dynamic(L, 1, 0, "CPoint");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'y'", NULL);
	tolua_pushusertype(L, (void*)&self->y, "Primitive<int>");
	return 1;
}

static int tolua_function_CGameObjectArray_GetShare(lua_State* L)
{
	byte returnVal = CGameObjectArray::GetShare(tolua_function_tointeger<int>(L, 1, "GetShare"), (CGameObject**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameObject>"));
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_get_reference_CGameObjectArray_GetShare(lua_State* L)
{
	tolua_pushusertype(L, CGameObjectArray::GetShare, "UnmappedUserType");
	return 1;
}

static int tolua_get_CBaldurChitin_pActiveEngine(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pActiveEngine'", NULL);
	tolua_pushusertype(L, (void*)self->pActiveEngine, "UnmappedUserType");
	return 1;
}

static int tolua_set_CBaldurChitin_pActiveEngine(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pActiveEngine'", NULL);
	self->pActiveEngine = (void*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType");
	return 0;
}

static int tolua_get_CBaldurChitin_reference_pActiveEngine(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pActiveEngine'", NULL);
	tolua_pushusertype(L, (void*)&self->pActiveEngine, "VoidPointer");
	return 1;
}

static int tolua_get_CBaldurChitin_cVideo(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'cVideo'", NULL);
	tolua_pushusertype(L, (void*)&self->cVideo, "CVideo");
	return 1;
}

static int tolua_get_CBaldurChitin_m_bConnectionEstablished(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bConnectionEstablished'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bConnectionEstablished);
	return 1;
}

static int tolua_set_CBaldurChitin_m_bConnectionEstablished(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bConnectionEstablished'", NULL);
	self->m_bConnectionEstablished = tolua_setter_tointeger<byte>(L, "m_bConnectionEstablished");
	return 0;
}

static int tolua_get_CBaldurChitin_reference_m_bConnectionEstablished(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bConnectionEstablished'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bConnectionEstablished, "Primitive<byte>");
	return 1;
}

static int tolua_get_CBaldurChitin_m_idLocalPlayer(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_idLocalPlayer'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_idLocalPlayer);
	return 1;
}

static int tolua_set_CBaldurChitin_m_idLocalPlayer(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_idLocalPlayer'", NULL);
	self->m_idLocalPlayer = tolua_setter_tointeger<int>(L, "m_idLocalPlayer");
	return 0;
}

static int tolua_get_CBaldurChitin_reference_m_idLocalPlayer(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_idLocalPlayer'", NULL);
	tolua_pushusertype(L, (void*)&self->m_idLocalPlayer, "Primitive<int>");
	return 1;
}

static int tolua_get_CBaldurChitin_m_pObjectGame(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pObjectGame'", NULL);
	tolua_pushusertype(L, (void*)self->m_pObjectGame, "EEex_CInfGame");
	return 1;
}

static int tolua_set_CBaldurChitin_m_pObjectGame(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pObjectGame'", NULL);
	self->m_pObjectGame = (CInfGame*)tolua_tousertype_dynamic(L, 2, 0, "EEex_CInfGame");
	return 0;
}

static int tolua_get_CBaldurChitin_reference_m_pObjectGame(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pObjectGame'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pObjectGame, "Pointer<EEex_CInfGame>");
	return 1;
}

static int tolua_get_CBaldurChitin_m_pEngineMap(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pEngineMap'", NULL);
	tolua_pushusertype(L, (void*)self->m_pEngineMap, "UnmappedUserType");
	return 1;
}

static int tolua_set_CBaldurChitin_m_pEngineMap(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pEngineMap'", NULL);
	self->m_pEngineMap = (void*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType");
	return 0;
}

static int tolua_get_CBaldurChitin_reference_m_pEngineMap(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pEngineMap'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pEngineMap, "VoidPointer");
	return 1;
}

static int tolua_get_CBaldurChitin_m_pEngineWorld(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pEngineWorld'", NULL);
	tolua_pushusertype(L, (void*)self->m_pEngineWorld, "EEex_CScreenWorld");
	return 1;
}

static int tolua_set_CBaldurChitin_m_pEngineWorld(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pEngineWorld'", NULL);
	self->m_pEngineWorld = (CScreenWorld*)tolua_tousertype_dynamic(L, 2, 0, "EEex_CScreenWorld");
	return 0;
}

static int tolua_get_CBaldurChitin_reference_m_pEngineWorld(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pEngineWorld'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pEngineWorld, "Pointer<EEex_CScreenWorld>");
	return 1;
}

static int tolua_get_CBaldurChitin_m_cMessageHandler(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_cMessageHandler'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_cMessageHandler);
	return 1;
}

static int tolua_set_CBaldurChitin_m_cMessageHandler(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_cMessageHandler'", NULL);
	self->m_cMessageHandler = tolua_setter_tointeger<byte>(L, "m_cMessageHandler");
	return 0;
}

static int tolua_get_CBaldurChitin_reference_m_cMessageHandler(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_cMessageHandler'", NULL);
	tolua_pushusertype(L, (void*)&self->m_cMessageHandler, "Primitive<byte>");
	return 1;
}

static int tolua_get_CMessage_m_targetId(lua_State* L)
{
	CMessage* self = (CMessage*)tolua_tousertype_dynamic(L, 1, 0, "CMessage");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_targetId);
	return 1;
}

static int tolua_set_CMessage_m_targetId(lua_State* L)
{
	CMessage* self = (CMessage*)tolua_tousertype_dynamic(L, 1, 0, "CMessage");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	self->m_targetId = tolua_setter_tointeger<long>(L, "m_targetId");
	return 0;
}

static int tolua_get_CMessage_reference_m_targetId(lua_State* L)
{
	CMessage* self = (CMessage*)tolua_tousertype_dynamic(L, 1, 0, "CMessage");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	tolua_pushusertype(L, (void*)&self->m_targetId, "Primitive<long>");
	return 1;
}

static int tolua_get_CMessage_m_sourceId(lua_State* L)
{
	CMessage* self = (CMessage*)tolua_tousertype_dynamic(L, 1, 0, "CMessage");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_sourceId);
	return 1;
}

static int tolua_set_CMessage_m_sourceId(lua_State* L)
{
	CMessage* self = (CMessage*)tolua_tousertype_dynamic(L, 1, 0, "CMessage");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	self->m_sourceId = tolua_setter_tointeger<long>(L, "m_sourceId");
	return 0;
}

static int tolua_get_CMessage_reference_m_sourceId(lua_State* L)
{
	CMessage* self = (CMessage*)tolua_tousertype_dynamic(L, 1, 0, "CMessage");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	tolua_pushusertype(L, (void*)&self->m_sourceId, "Primitive<long>");
	return 1;
}

static int tolua_get_CMessageVisualEffect_m_nEffectType(lua_State* L)
{
	CMessageVisualEffect* self = (CMessageVisualEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageVisualEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nEffectType'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nEffectType);
	return 1;
}

static int tolua_set_CMessageVisualEffect_m_nEffectType(lua_State* L)
{
	CMessageVisualEffect* self = (CMessageVisualEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageVisualEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nEffectType'", NULL);
	self->m_nEffectType = tolua_setter_tointeger<byte>(L, "m_nEffectType");
	return 0;
}

static int tolua_get_CMessageVisualEffect_reference_m_nEffectType(lua_State* L)
{
	CMessageVisualEffect* self = (CMessageVisualEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageVisualEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nEffectType'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nEffectType, "Primitive<byte>");
	return 1;
}

static int tolua_get_CMessageVisualEffect_m_nEffectProperty(lua_State* L)
{
	CMessageVisualEffect* self = (CMessageVisualEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageVisualEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nEffectProperty'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nEffectProperty);
	return 1;
}

static int tolua_set_CMessageVisualEffect_m_nEffectProperty(lua_State* L)
{
	CMessageVisualEffect* self = (CMessageVisualEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageVisualEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nEffectProperty'", NULL);
	self->m_nEffectProperty = tolua_setter_tointeger<byte>(L, "m_nEffectProperty");
	return 0;
}

static int tolua_get_CMessageVisualEffect_reference_m_nEffectProperty(lua_State* L)
{
	CMessageVisualEffect* self = (CMessageVisualEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageVisualEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nEffectProperty'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nEffectProperty, "Primitive<byte>");
	return 1;
}

static int tolua_get_CMessageAddEffect_m_effect(lua_State* L)
{
	CMessageAddEffect* self = (CMessageAddEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageAddEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effect'", NULL);
	tolua_pushusertype(L, (void*)self->m_effect, "CGameEffect");
	return 1;
}

static int tolua_set_CMessageAddEffect_m_effect(lua_State* L)
{
	CMessageAddEffect* self = (CMessageAddEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageAddEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effect'", NULL);
	self->m_effect = (CGameEffect*)tolua_tousertype_dynamic(L, 2, 0, "CGameEffect");
	return 0;
}

static int tolua_get_CMessageAddEffect_reference_m_effect(lua_State* L)
{
	CMessageAddEffect* self = (CMessageAddEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageAddEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effect'", NULL);
	tolua_pushusertype(L, (void*)&self->m_effect, "Pointer<CGameEffect>");
	return 1;
}

static int tolua_get_CMessageAddEffect_m_noSave(lua_State* L)
{
	CMessageAddEffect* self = (CMessageAddEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageAddEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_noSave'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_noSave);
	return 1;
}

static int tolua_set_CMessageAddEffect_m_noSave(lua_State* L)
{
	CMessageAddEffect* self = (CMessageAddEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageAddEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_noSave'", NULL);
	self->m_noSave = tolua_setter_tointeger<byte>(L, "m_noSave");
	return 0;
}

static int tolua_get_CMessageAddEffect_reference_m_noSave(lua_State* L)
{
	CMessageAddEffect* self = (CMessageAddEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageAddEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_noSave'", NULL);
	tolua_pushusertype(L, (void*)&self->m_noSave, "Primitive<byte>");
	return 1;
}

static int tolua_get_CTimerWorld_m_gameTime(lua_State* L)
{
	CTimerWorld* self = (CTimerWorld*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CTimerWorld");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_gameTime'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_gameTime);
	return 1;
}

static int tolua_set_CTimerWorld_m_gameTime(lua_State* L)
{
	CTimerWorld* self = (CTimerWorld*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CTimerWorld");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_gameTime'", NULL);
	self->m_gameTime = tolua_setter_tointeger<uint>(L, "m_gameTime");
	return 0;
}

static int tolua_get_CTimerWorld_reference_m_gameTime(lua_State* L)
{
	CTimerWorld* self = (CTimerWorld*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CTimerWorld");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_gameTime'", NULL);
	tolua_pushusertype(L, (void*)&self->m_gameTime, "Primitive<uint>");
	return 1;
}

static int tolua_get_CTimerWorld_m_active(lua_State* L)
{
	CTimerWorld* self = (CTimerWorld*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CTimerWorld");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_active'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_active);
	return 1;
}

static int tolua_set_CTimerWorld_m_active(lua_State* L)
{
	CTimerWorld* self = (CTimerWorld*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CTimerWorld");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_active'", NULL);
	self->m_active = tolua_setter_tointeger<byte>(L, "m_active");
	return 0;
}

static int tolua_get_CTimerWorld_reference_m_active(lua_State* L)
{
	CTimerWorld* self = (CTimerWorld*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CTimerWorld");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_active'", NULL);
	tolua_pushusertype(L, (void*)&self->m_active, "Primitive<byte>");
	return 1;
}

static int tolua_get_CTimerWorld_m_nLastPercentage(lua_State* L)
{
	CTimerWorld* self = (CTimerWorld*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CTimerWorld");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nLastPercentage'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nLastPercentage);
	return 1;
}

static int tolua_set_CTimerWorld_m_nLastPercentage(lua_State* L)
{
	CTimerWorld* self = (CTimerWorld*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CTimerWorld");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nLastPercentage'", NULL);
	self->m_nLastPercentage = tolua_setter_tointeger<byte>(L, "m_nLastPercentage");
	return 0;
}

static int tolua_get_CTimerWorld_reference_m_nLastPercentage(lua_State* L)
{
	CTimerWorld* self = (CTimerWorld*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CTimerWorld");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nLastPercentage'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nLastPercentage, "Primitive<byte>");
	return 1;
}

static int tolua_get_CInfinity_rViewPortNotZoomed(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'rViewPortNotZoomed'", NULL);
	tolua_pushusertype(L, (void*)&self->rViewPortNotZoomed, "CRect");
	return 1;
}

static int tolua_get_CInfinity_rViewPort(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'rViewPort'", NULL);
	tolua_pushusertype(L, (void*)&self->rViewPort, "CRect");
	return 1;
}

static int tolua_get_CInfinity_m_areaTintOverride(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_areaTintOverride'", NULL);
	tolua_pushusertype(L, (void*)self->m_areaTintOverride, "CAreaTintOverride");
	return 1;
}

static int tolua_set_CInfinity_m_areaTintOverride(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_areaTintOverride'", NULL);
	self->m_areaTintOverride = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 2, 0, "CAreaTintOverride");
	return 0;
}

static int tolua_get_CInfinity_reference_m_areaTintOverride(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_areaTintOverride'", NULL);
	tolua_pushusertype(L, (void*)&self->m_areaTintOverride, "Pointer<CAreaTintOverride>");
	return 1;
}

static int tolua_get_CInfinity_m_rgbAreaTintGlobalLightingOverride(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbAreaTintGlobalLightingOverride'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_rgbAreaTintGlobalLightingOverride);
	return 1;
}

static int tolua_set_CInfinity_m_rgbAreaTintGlobalLightingOverride(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbAreaTintGlobalLightingOverride'", NULL);
	self->m_rgbAreaTintGlobalLightingOverride = tolua_setter_tointeger<int>(L, "m_rgbAreaTintGlobalLightingOverride");
	return 0;
}

static int tolua_get_CInfinity_reference_m_rgbAreaTintGlobalLightingOverride(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbAreaTintGlobalLightingOverride'", NULL);
	tolua_pushusertype(L, (void*)&self->m_rgbAreaTintGlobalLightingOverride, "Primitive<int>");
	return 1;
}

static int tolua_get_CInfinity_unknownPSTGlobalTint(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownPSTGlobalTint'", NULL);
	lua_pushinteger(L, (lua_Integer)self->unknownPSTGlobalTint);
	return 1;
}

static int tolua_set_CInfinity_unknownPSTGlobalTint(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownPSTGlobalTint'", NULL);
	self->unknownPSTGlobalTint = tolua_setter_tointeger<uint>(L, "unknownPSTGlobalTint");
	return 0;
}

static int tolua_get_CInfinity_reference_unknownPSTGlobalTint(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownPSTGlobalTint'", NULL);
	tolua_pushusertype(L, (void*)&self->unknownPSTGlobalTint, "Primitive<uint>");
	return 1;
}

static int tolua_get_CInfinity_nFlashViewportWhiteCounter(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nFlashViewportWhiteCounter'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nFlashViewportWhiteCounter);
	return 1;
}

static int tolua_set_CInfinity_nFlashViewportWhiteCounter(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nFlashViewportWhiteCounter'", NULL);
	self->nFlashViewportWhiteCounter = tolua_setter_tointeger<int>(L, "nFlashViewportWhiteCounter");
	return 0;
}

static int tolua_get_CInfinity_reference_nFlashViewportWhiteCounter(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nFlashViewportWhiteCounter'", NULL);
	tolua_pushusertype(L, (void*)&self->nFlashViewportWhiteCounter, "Primitive<int>");
	return 1;
}

static int tolua_get_CInfinity_m_renderDayNightCode(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_renderDayNightCode'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_renderDayNightCode);
	return 1;
}

static int tolua_set_CInfinity_m_renderDayNightCode(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_renderDayNightCode'", NULL);
	self->m_renderDayNightCode = tolua_setter_tointeger<byte>(L, "m_renderDayNightCode");
	return 0;
}

static int tolua_get_CInfinity_reference_m_renderDayNightCode(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_renderDayNightCode'", NULL);
	tolua_pushusertype(L, (void*)&self->m_renderDayNightCode, "Primitive<byte>");
	return 1;
}

static int tolua_get_CInfinity_m_rgbLightningGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbLightningGlobalLighting'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_rgbLightningGlobalLighting);
	return 1;
}

static int tolua_set_CInfinity_m_rgbLightningGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbLightningGlobalLighting'", NULL);
	self->m_rgbLightningGlobalLighting = tolua_setter_tointeger<uint>(L, "m_rgbLightningGlobalLighting");
	return 0;
}

static int tolua_get_CInfinity_reference_m_rgbLightningGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbLightningGlobalLighting'", NULL);
	tolua_pushusertype(L, (void*)&self->m_rgbLightningGlobalLighting, "Primitive<uint>");
	return 1;
}

static int tolua_get_CInfinity_m_rgbOverCastGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbOverCastGlobalLighting'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_rgbOverCastGlobalLighting);
	return 1;
}

static int tolua_set_CInfinity_m_rgbOverCastGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbOverCastGlobalLighting'", NULL);
	self->m_rgbOverCastGlobalLighting = tolua_setter_tointeger<uint>(L, "m_rgbOverCastGlobalLighting");
	return 0;
}

static int tolua_get_CInfinity_reference_m_rgbOverCastGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbOverCastGlobalLighting'", NULL);
	tolua_pushusertype(L, (void*)&self->m_rgbOverCastGlobalLighting, "Primitive<uint>");
	return 1;
}

static int tolua_get_CInfinity_m_rgbTimeOfDayGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbTimeOfDayGlobalLighting'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_rgbTimeOfDayGlobalLighting);
	return 1;
}

static int tolua_set_CInfinity_m_rgbTimeOfDayGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbTimeOfDayGlobalLighting'", NULL);
	self->m_rgbTimeOfDayGlobalLighting = tolua_setter_tointeger<uint>(L, "m_rgbTimeOfDayGlobalLighting");
	return 0;
}

static int tolua_get_CInfinity_reference_m_rgbTimeOfDayGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbTimeOfDayGlobalLighting'", NULL);
	tolua_pushusertype(L, (void*)&self->m_rgbTimeOfDayGlobalLighting, "Primitive<uint>");
	return 1;
}

static int tolua_get_CInfinity_m_pArea(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pArea'", NULL);
	tolua_pushusertype(L, (void*)self->m_pArea, "CGameArea");
	return 1;
}

static int tolua_set_CInfinity_m_pArea(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pArea'", NULL);
	self->m_pArea = (CGameArea*)tolua_tousertype_dynamic(L, 2, 0, "CGameArea");
	return 0;
}

static int tolua_get_CInfinity_reference_m_pArea(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pArea'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pArea, "Pointer<CGameArea>");
	return 1;
}

static int tolua_get_CGameTrigger_m_pos(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pos'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pos, "CPoint");
	return 1;
}

static int tolua_get_CGameTrigger_m_pArea(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pArea'", NULL);
	tolua_pushusertype(L, (void*)self->m_pArea, "CGameArea");
	return 1;
}

static int tolua_set_CGameTrigger_m_pArea(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pArea'", NULL);
	self->m_pArea = (CGameArea*)tolua_tousertype_dynamic(L, 2, 0, "CGameArea");
	return 0;
}

static int tolua_get_CGameTrigger_reference_m_pArea(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pArea'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pArea, "Pointer<CGameArea>");
	return 1;
}

static int tolua_get_CGameTrigger_m_posVertList(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posVertList'", NULL);
	tolua_pushusertype(L, (void*)self->m_posVertList, "UnmappedUserType");
	return 1;
}

static int tolua_set_CGameTrigger_m_posVertList(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posVertList'", NULL);
	self->m_posVertList = (void*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType");
	return 0;
}

static int tolua_get_CGameTrigger_reference_m_posVertList(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posVertList'", NULL);
	tolua_pushusertype(L, (void*)&self->m_posVertList, "VoidPointer");
	return 1;
}

static int tolua_get_CGameTrigger_m_id(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_id'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_id);
	return 1;
}

static int tolua_set_CGameTrigger_m_id(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_id'", NULL);
	self->m_id = tolua_setter_tointeger<long>(L, "m_id");
	return 0;
}

static int tolua_get_CGameTrigger_reference_m_id(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_id'", NULL);
	tolua_pushusertype(L, (void*)&self->m_id, "Primitive<long>");
	return 1;
}

static int tolua_get_CGameTrigger_m_remotePlayerID(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remotePlayerID'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_remotePlayerID);
	return 1;
}

static int tolua_set_CGameTrigger_m_remotePlayerID(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remotePlayerID'", NULL);
	self->m_remotePlayerID = tolua_setter_tointeger<int>(L, "m_remotePlayerID");
	return 0;
}

static int tolua_get_CGameTrigger_reference_m_remotePlayerID(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remotePlayerID'", NULL);
	tolua_pushusertype(L, (void*)&self->m_remotePlayerID, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameTrigger_m_triggerType(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_triggerType'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_triggerType);
	return 1;
}

static int tolua_set_CGameTrigger_m_triggerType(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_triggerType'", NULL);
	self->m_triggerType = tolua_setter_tointeger<ushort>(L, "m_triggerType");
	return 0;
}

static int tolua_get_CGameTrigger_reference_m_triggerType(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_triggerType'", NULL);
	tolua_pushusertype(L, (void*)&self->m_triggerType, "Primitive<ushort>");
	return 1;
}

static int tolua_get_CGameTrigger_m_dwFlags(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_dwFlags'", NULL);
	tolua_pushusertype(L, (void*)&self->m_dwFlags, "ulong");
	return 1;
}

static int tolua_get_CGameTrigger_m_boundingRange(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_boundingRange'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_boundingRange);
	return 1;
}

static int tolua_set_CGameTrigger_m_boundingRange(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_boundingRange'", NULL);
	self->m_boundingRange = tolua_setter_tointeger<ushort>(L, "m_boundingRange");
	return 0;
}

static int tolua_get_CGameTrigger_reference_m_boundingRange(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_boundingRange'", NULL);
	tolua_pushusertype(L, (void*)&self->m_boundingRange, "Primitive<ushort>");
	return 1;
}

static int tolua_get_CGameTrigger_m_trapActivated(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_trapActivated);
	return 1;
}

static int tolua_set_CGameTrigger_m_trapActivated(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	self->m_trapActivated = tolua_setter_tointeger<ushort>(L, "m_trapActivated");
	return 0;
}

static int tolua_get_CGameTrigger_reference_m_trapActivated(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	tolua_pushusertype(L, (void*)&self->m_trapActivated, "Primitive<ushort>");
	return 1;
}

static int tolua_get_CGameDoor_m_dwFlagsDoor(lua_State* L)
{
	CGameDoor* self = (CGameDoor*)tolua_tousertype_dynamic(L, 1, 0, "CGameDoor");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_dwFlagsDoor'", NULL);
	tolua_pushusertype(L, (void*)&self->m_dwFlagsDoor, "ulong");
	return 1;
}

static int tolua_get_CGameDoor_m_trapActivated(lua_State* L)
{
	CGameDoor* self = (CGameDoor*)tolua_tousertype_dynamic(L, 1, 0, "CGameDoor");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_trapActivated);
	return 1;
}

static int tolua_set_CGameDoor_m_trapActivated(lua_State* L)
{
	CGameDoor* self = (CGameDoor*)tolua_tousertype_dynamic(L, 1, 0, "CGameDoor");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	self->m_trapActivated = tolua_setter_tointeger<ushort>(L, "m_trapActivated");
	return 0;
}

static int tolua_get_CGameDoor_reference_m_trapActivated(lua_State* L)
{
	CGameDoor* self = (CGameDoor*)tolua_tousertype_dynamic(L, 1, 0, "CGameDoor");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	tolua_pushusertype(L, (void*)&self->m_trapActivated, "Primitive<ushort>");
	return 1;
}

static int tolua_get_CGameContainer_m_trapActivated(lua_State* L)
{
	CGameContainer* self = (CGameContainer*)tolua_tousertype_dynamic(L, 1, 0, "CGameContainer");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_trapActivated);
	return 1;
}

static int tolua_set_CGameContainer_m_trapActivated(lua_State* L)
{
	CGameContainer* self = (CGameContainer*)tolua_tousertype_dynamic(L, 1, 0, "CGameContainer");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	self->m_trapActivated = tolua_setter_tointeger<ushort>(L, "m_trapActivated");
	return 0;
}

static int tolua_get_CGameContainer_reference_m_trapActivated(lua_State* L)
{
	CGameContainer* self = (CGameContainer*)tolua_tousertype_dynamic(L, 1, 0, "CGameContainer");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	tolua_pushusertype(L, (void*)&self->m_trapActivated, "Primitive<ushort>");
	return 1;
}

static int tolua_get_Pointer_CBaldurChitin__reference(lua_State* L)
{
	Pointer<CBaldurChitin>* self = (Pointer<CBaldurChitin>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CBaldurChitin>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "EEex_CBaldurChitin");
	return 1;
}

static int tolua_set_Pointer_CBaldurChitin__reference(lua_State* L)
{
	Pointer<CBaldurChitin>* self = (Pointer<CBaldurChitin>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CBaldurChitin>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CBaldurChitin*)tolua_tousertype_dynamic(L, 2, 0, "EEex_CBaldurChitin");
	return 0;
}

static int tolua_function_Pointer_CBaldurChitin__setValue(lua_State* L)
{
	Pointer<CBaldurChitin>* self = (Pointer<CBaldurChitin>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CBaldurChitin>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CBaldurChitin*)tolua_tousertype_dynamic(L, 2, 0, "EEex_CBaldurChitin"));
	return 0;
}

static int tolua_get_Pointer_CObject__reference(lua_State* L)
{
	Pointer<CObject>* self = (Pointer<CObject>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CObject>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CObject");
	return 1;
}

static int tolua_set_Pointer_CObject__reference(lua_State* L)
{
	Pointer<CObject>* self = (Pointer<CObject>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CObject>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CObject*)tolua_tousertype_dynamic(L, 2, 0, "CObject");
	return 0;
}

static int tolua_function_Pointer_CObject__setValue(lua_State* L)
{
	Pointer<CObject>* self = (Pointer<CObject>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CObject>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CObject*)tolua_tousertype_dynamic(L, 2, 0, "CObject"));
	return 0;
}

static int tolua_get_Pointer_CGameObject__reference(lua_State* L)
{
	Pointer<CGameObject>* self = (Pointer<CGameObject>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CGameObject");
	return 1;
}

static int tolua_set_Pointer_CGameObject__reference(lua_State* L)
{
	Pointer<CGameObject>* self = (Pointer<CGameObject>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameObject*)tolua_tousertype_dynamic(L, 2, 0, "CGameObject");
	return 0;
}

static int tolua_function_Pointer_CGameObject__setValue(lua_State* L)
{
	Pointer<CGameObject>* self = (Pointer<CGameObject>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CGameObject*)tolua_tousertype_dynamic(L, 2, 0, "CGameObject"));
	return 0;
}

static int tolua_get_Pointer_CGameArea__reference(lua_State* L)
{
	Pointer<CGameArea>* self = (Pointer<CGameArea>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameArea>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CGameArea");
	return 1;
}

static int tolua_set_Pointer_CGameArea__reference(lua_State* L)
{
	Pointer<CGameArea>* self = (Pointer<CGameArea>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameArea>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameArea*)tolua_tousertype_dynamic(L, 2, 0, "CGameArea");
	return 0;
}

static int tolua_function_Pointer_CGameArea__setValue(lua_State* L)
{
	Pointer<CGameArea>* self = (Pointer<CGameArea>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameArea>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CGameArea*)tolua_tousertype_dynamic(L, 2, 0, "CGameArea"));
	return 0;
}

static int tolua_get_Pointer_const_CPoint__reference(lua_State* L)
{
	Pointer<const CPoint>* self = (Pointer<const CPoint>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CPoint>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CPoint");
	return 1;
}

static int tolua_set_Pointer_const_CPoint__reference(lua_State* L)
{
	Pointer<const CPoint>* self = (Pointer<const CPoint>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CPoint>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const CPoint*)tolua_tousertype_dynamic(L, 2, 0, "CPoint");
	return 0;
}

static int tolua_get_Pointer_const_CAIObjectType__reference(lua_State* L)
{
	Pointer<const CAIObjectType>* self = (Pointer<const CAIObjectType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAIObjectType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CAIObjectType");
	return 1;
}

static int tolua_set_Pointer_const_CAIObjectType__reference(lua_State* L)
{
	Pointer<const CAIObjectType>* self = (Pointer<const CAIObjectType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAIObjectType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const CAIObjectType*)tolua_tousertype_dynamic(L, 2, 0, "CAIObjectType");
	return 0;
}

static int tolua_get_Pointer_CPoint__reference(lua_State* L)
{
	Pointer<CPoint>* self = (Pointer<CPoint>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPoint>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CPoint");
	return 1;
}

static int tolua_set_Pointer_CPoint__reference(lua_State* L)
{
	Pointer<CPoint>* self = (Pointer<CPoint>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPoint>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CPoint*)tolua_tousertype_dynamic(L, 2, 0, "CPoint");
	return 0;
}

static int tolua_function_Pointer_CPoint__setValue(lua_State* L)
{
	Pointer<CPoint>* self = (Pointer<CPoint>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPoint>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CPoint*)tolua_tousertype_dynamic(L, 2, 0, "CPoint"));
	return 0;
}

static int tolua_get_Pointer_CTypedPtrList_CPtrList_long___CNode__reference(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,long>::CNode>* self = (Pointer<CTypedPtrList<CPtrList,long>::CNode>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,long>::CNode>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CTypedPtrList<CPtrList,long>::CNode");
	return 1;
}

static int tolua_set_Pointer_CTypedPtrList_CPtrList_long___CNode__reference(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,long>::CNode>* self = (Pointer<CTypedPtrList<CPtrList,long>::CNode>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,long>::CNode>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,long>::CNode");
	return 0;
}

static int tolua_function_Pointer_CTypedPtrList_CPtrList_long___CNode__setValue(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,long>::CNode>* self = (Pointer<CTypedPtrList<CPtrList,long>::CNode>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,long>::CNode>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,long>::CNode"));
	return 0;
}

static int tolua_get_Pointer_unsigned_int__reference(lua_State* L)
{
	Pointer<unsigned int>* self = (Pointer<unsigned int>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<int>");
	return 1;
}

static int tolua_set_Pointer_unsigned_int__reference(lua_State* L)
{
	Pointer<unsigned int>* self = (Pointer<unsigned int>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (unsigned int*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<int>");
	return 0;
}

static int tolua_function_Pointer_unsigned_int__getValue(lua_State* L)
{
	Pointer<unsigned int>* self = (Pointer<unsigned int>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned int>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	unsigned int returnVal = self->getValue();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Pointer_unsigned_int__setValue(lua_State* L)
{
	Pointer<unsigned int>* self = (Pointer<unsigned int>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned int>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger<unsigned int>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_const_CString__reference(lua_State* L)
{
	Pointer<const CString>* self = (Pointer<const CString>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CString>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CString");
	return 1;
}

static int tolua_set_Pointer_const_CString__reference(lua_State* L)
{
	Pointer<const CString>* self = (Pointer<const CString>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CString>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const CString*)tolua_tousertype_dynamic(L, 2, 0, "CString");
	return 0;
}

static int tolua_get_Pointer_CVidMode__reference(lua_State* L)
{
	Pointer<CVidMode>* self = (Pointer<CVidMode>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidMode>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CVidMode");
	return 1;
}

static int tolua_set_Pointer_CVidMode__reference(lua_State* L)
{
	Pointer<CVidMode>* self = (Pointer<CVidMode>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidMode>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CVidMode*)tolua_tousertype_dynamic(L, 2, 0, "CVidMode");
	return 0;
}

static int tolua_function_Pointer_CVidMode__setValue(lua_State* L)
{
	Pointer<CVidMode>* self = (Pointer<CVidMode>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidMode>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CVidMode*)tolua_tousertype_dynamic(L, 2, 0, "CVidMode"));
	return 0;
}

static int tolua_get_Pointer___POSITION__reference(lua_State* L)
{
	Pointer<__POSITION>* self = (Pointer<__POSITION>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__POSITION>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "__POSITION");
	return 1;
}

static int tolua_set_Pointer___POSITION__reference(lua_State* L)
{
	Pointer<__POSITION>* self = (Pointer<__POSITION>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__POSITION>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (__POSITION*)tolua_tousertype_dynamic(L, 2, 0, "__POSITION");
	return 0;
}

static int tolua_function_Pointer___POSITION__setValue(lua_State* L)
{
	Pointer<__POSITION>* self = (Pointer<__POSITION>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__POSITION>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(__POSITION*)tolua_tousertype_dynamic(L, 2, 0, "__POSITION"));
	return 0;
}

static int tolua_get_Pointer_const_CAITrigger__reference(lua_State* L)
{
	Pointer<const CAITrigger>* self = (Pointer<const CAITrigger>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAITrigger>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CAITrigger");
	return 1;
}

static int tolua_set_Pointer_const_CAITrigger__reference(lua_State* L)
{
	Pointer<const CAITrigger>* self = (Pointer<const CAITrigger>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAITrigger>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const CAITrigger*)tolua_tousertype_dynamic(L, 2, 0, "CAITrigger");
	return 0;
}

static int tolua_get_Pointer_CGameAIBase__reference(lua_State* L)
{
	Pointer<CGameAIBase>* self = (Pointer<CGameAIBase>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAIBase>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CGameAIBase");
	return 1;
}

static int tolua_set_Pointer_CGameAIBase__reference(lua_State* L)
{
	Pointer<CGameAIBase>* self = (Pointer<CGameAIBase>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAIBase>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameAIBase*)tolua_tousertype_dynamic(L, 2, 0, "CGameAIBase");
	return 0;
}

static int tolua_function_Pointer_CGameAIBase__setValue(lua_State* L)
{
	Pointer<CGameAIBase>* self = (Pointer<CGameAIBase>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAIBase>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CGameAIBase*)tolua_tousertype_dynamic(L, 2, 0, "CGameAIBase"));
	return 0;
}

static int tolua_get_Pointer_const_CAIAction__reference(lua_State* L)
{
	Pointer<const CAIAction>* self = (Pointer<const CAIAction>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAIAction>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CAIAction");
	return 1;
}

static int tolua_set_Pointer_const_CAIAction__reference(lua_State* L)
{
	Pointer<const CAIAction>* self = (Pointer<const CAIAction>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAIAction>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const CAIAction*)tolua_tousertype_dynamic(L, 2, 0, "CAIAction");
	return 0;
}

static int tolua_get_Pointer_CGameEffect__reference(lua_State* L)
{
	Pointer<CGameEffect>* self = (Pointer<CGameEffect>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameEffect>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CGameEffect");
	return 1;
}

static int tolua_set_Pointer_CGameEffect__reference(lua_State* L)
{
	Pointer<CGameEffect>* self = (Pointer<CGameEffect>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameEffect>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameEffect*)tolua_tousertype_dynamic(L, 2, 0, "CGameEffect");
	return 0;
}

static int tolua_function_Pointer_CGameEffect__setValue(lua_State* L)
{
	Pointer<CGameEffect>* self = (Pointer<CGameEffect>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameEffect>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CGameEffect*)tolua_tousertype_dynamic(L, 2, 0, "CGameEffect"));
	return 0;
}

static int tolua_get_Pointer_CResRef__reference(lua_State* L)
{
	Pointer<CResRef>* self = (Pointer<CResRef>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResRef>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CResRef");
	return 1;
}

static int tolua_set_Pointer_CResRef__reference(lua_State* L)
{
	Pointer<CResRef>* self = (Pointer<CResRef>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResRef>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CResRef*)tolua_tousertype_dynamic(L, 2, 0, "CResRef");
	return 0;
}

static int tolua_function_Pointer_CResRef__setValue(lua_State* L)
{
	Pointer<CResRef>* self = (Pointer<CResRef>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResRef>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CResRef*)tolua_tousertype_dynamic(L, 2, 0, "CResRef"));
	return 0;
}

static int tolua_get_Pointer_CGameObject___reference(lua_State* L)
{
	Pointer<CGameObject*>* self = (Pointer<CGameObject*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CGameObject>");
	return 1;
}

static int tolua_set_Pointer_CGameObject___reference(lua_State* L)
{
	Pointer<CGameObject*>* self = (Pointer<CGameObject*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameObject**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameObject>");
	return 0;
}

static int tolua_function_Pointer_CGameObject___getValue(lua_State* L)
{
	Pointer<CGameObject*>* self = (Pointer<CGameObject*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CGameObject* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CGameObject");
	return 1;
}

static int tolua_function_Pointer_CGameObject___setValue(lua_State* L)
{
	Pointer<CGameObject*>* self = (Pointer<CGameObject*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CGameObject*)tolua_tousertype_dynamic(L, 2, 0, "CGameObject"));
	return 0;
}

static int tolua_get_Pointer_Item_effect_st__reference(lua_State* L)
{
	Pointer<Item_effect_st>* self = (Pointer<Item_effect_st>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Item_effect_st>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Item_effect_st");
	return 1;
}

static int tolua_set_Pointer_Item_effect_st__reference(lua_State* L)
{
	Pointer<Item_effect_st>* self = (Pointer<Item_effect_st>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Item_effect_st>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Item_effect_st*)tolua_tousertype_dynamic(L, 2, 0, "Item_effect_st");
	return 0;
}

static int tolua_function_Pointer_Item_effect_st__setValue(lua_State* L)
{
	Pointer<Item_effect_st>* self = (Pointer<Item_effect_st>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Item_effect_st>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Item_effect_st*)tolua_tousertype_dynamic(L, 2, 0, "Item_effect_st"));
	return 0;
}

static int tolua_get_Pointer_CProjectile__reference(lua_State* L)
{
	Pointer<CProjectile>* self = (Pointer<CProjectile>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectile>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CProjectile");
	return 1;
}

static int tolua_set_Pointer_CProjectile__reference(lua_State* L)
{
	Pointer<CProjectile>* self = (Pointer<CProjectile>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectile>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CProjectile*)tolua_tousertype_dynamic(L, 2, 0, "CProjectile");
	return 0;
}

static int tolua_function_Pointer_CProjectile__setValue(lua_State* L)
{
	Pointer<CProjectile>* self = (Pointer<CProjectile>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectile>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CProjectile*)tolua_tousertype_dynamic(L, 2, 0, "CProjectile"));
	return 0;
}

static int tolua_get_Pointer_CInfGame__reference(lua_State* L)
{
	Pointer<CInfGame>* self = (Pointer<CInfGame>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CInfGame>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "EEex_CInfGame");
	return 1;
}

static int tolua_set_Pointer_CInfGame__reference(lua_State* L)
{
	Pointer<CInfGame>* self = (Pointer<CInfGame>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CInfGame>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CInfGame*)tolua_tousertype_dynamic(L, 2, 0, "EEex_CInfGame");
	return 0;
}

static int tolua_function_Pointer_CInfGame__setValue(lua_State* L)
{
	Pointer<CInfGame>* self = (Pointer<CInfGame>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CInfGame>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CInfGame*)tolua_tousertype_dynamic(L, 2, 0, "EEex_CInfGame"));
	return 0;
}

static int tolua_get_Pointer_CScreenWorld__reference(lua_State* L)
{
	Pointer<CScreenWorld>* self = (Pointer<CScreenWorld>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CScreenWorld>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "EEex_CScreenWorld");
	return 1;
}

static int tolua_set_Pointer_CScreenWorld__reference(lua_State* L)
{
	Pointer<CScreenWorld>* self = (Pointer<CScreenWorld>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CScreenWorld>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CScreenWorld*)tolua_tousertype_dynamic(L, 2, 0, "EEex_CScreenWorld");
	return 0;
}

static int tolua_function_Pointer_CScreenWorld__setValue(lua_State* L)
{
	Pointer<CScreenWorld>* self = (Pointer<CScreenWorld>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CScreenWorld>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CScreenWorld*)tolua_tousertype_dynamic(L, 2, 0, "EEex_CScreenWorld"));
	return 0;
}

static int tolua_get_Pointer_CGameAnimationType__reference(lua_State* L)
{
	Pointer<CGameAnimationType>* self = (Pointer<CGameAnimationType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAnimationType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CGameAnimationType");
	return 1;
}

static int tolua_set_Pointer_CGameAnimationType__reference(lua_State* L)
{
	Pointer<CGameAnimationType>* self = (Pointer<CGameAnimationType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAnimationType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameAnimationType*)tolua_tousertype_dynamic(L, 2, 0, "CGameAnimationType");
	return 0;
}

static int tolua_function_Pointer_CGameAnimationType__setValue(lua_State* L)
{
	Pointer<CGameAnimationType>* self = (Pointer<CGameAnimationType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAnimationType>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CGameAnimationType*)tolua_tousertype_dynamic(L, 2, 0, "CGameAnimationType"));
	return 0;
}

static int tolua_get_Pointer_CProjectileUnknownPST2__reference(lua_State* L)
{
	Pointer<CProjectileUnknownPST2>* self = (Pointer<CProjectileUnknownPST2>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST2>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CProjectileUnknownPST2");
	return 1;
}

static int tolua_set_Pointer_CProjectileUnknownPST2__reference(lua_State* L)
{
	Pointer<CProjectileUnknownPST2>* self = (Pointer<CProjectileUnknownPST2>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST2>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 2, 0, "CProjectileUnknownPST2");
	return 0;
}

static int tolua_function_Pointer_CProjectileUnknownPST2__setValue(lua_State* L)
{
	Pointer<CProjectileUnknownPST2>* self = (Pointer<CProjectileUnknownPST2>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST2>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 2, 0, "CProjectileUnknownPST2"));
	return 0;
}

static int tolua_get_Pointer_CInfinity__reference(lua_State* L)
{
	Pointer<CInfinity>* self = (Pointer<CInfinity>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CInfinity>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CInfinity");
	return 1;
}

static int tolua_set_Pointer_CInfinity__reference(lua_State* L)
{
	Pointer<CInfinity>* self = (Pointer<CInfinity>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CInfinity>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CInfinity*)tolua_tousertype_dynamic(L, 2, 0, "CInfinity");
	return 0;
}

static int tolua_function_Pointer_CInfinity__setValue(lua_State* L)
{
	Pointer<CInfinity>* self = (Pointer<CInfinity>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CInfinity>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CInfinity*)tolua_tousertype_dynamic(L, 2, 0, "CInfinity"));
	return 0;
}

static int tolua_get_Pointer_CVidCell__reference(lua_State* L)
{
	Pointer<CVidCell>* self = (Pointer<CVidCell>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidCell>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CVidCell");
	return 1;
}

static int tolua_set_Pointer_CVidCell__reference(lua_State* L)
{
	Pointer<CVidCell>* self = (Pointer<CVidCell>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidCell>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CVidCell*)tolua_tousertype_dynamic(L, 2, 0, "CVidCell");
	return 0;
}

static int tolua_function_Pointer_CVidCell__setValue(lua_State* L)
{
	Pointer<CVidCell>* self = (Pointer<CVidCell>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidCell>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CVidCell*)tolua_tousertype_dynamic(L, 2, 0, "CVidCell"));
	return 0;
}

static int tolua_get_Pointer_CPtrList_CNode__reference(lua_State* L)
{
	Pointer<CPtrList_CNode>* self = (Pointer<CPtrList_CNode>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPtrList_CNode>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CPtrList_CNode");
	return 1;
}

static int tolua_set_Pointer_CPtrList_CNode__reference(lua_State* L)
{
	Pointer<CPtrList_CNode>* self = (Pointer<CPtrList_CNode>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPtrList_CNode>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 2, 0, "CPtrList_CNode");
	return 0;
}

static int tolua_function_Pointer_CPtrList_CNode__setValue(lua_State* L)
{
	Pointer<CPtrList_CNode>* self = (Pointer<CPtrList_CNode>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPtrList_CNode>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CPtrList_CNode*)tolua_tousertype_dynamic(L, 2, 0, "CPtrList_CNode"));
	return 0;
}

static int tolua_get_Pointer_int__reference(lua_State* L)
{
	Pointer<int>* self = (Pointer<int>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<int>");
	return 1;
}

static int tolua_set_Pointer_int__reference(lua_State* L)
{
	Pointer<int>* self = (Pointer<int>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (int*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<int>");
	return 0;
}

static int tolua_function_Pointer_int__getValue(lua_State* L)
{
	Pointer<int>* self = (Pointer<int>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<int>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	int returnVal = self->getValue();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Pointer_int__setValue(lua_State* L)
{
	Pointer<int>* self = (Pointer<int>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<int>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger<int>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_CSoundImp__reference(lua_State* L)
{
	Pointer<CSoundImp>* self = (Pointer<CSoundImp>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CSoundImp>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CSoundImp");
	return 1;
}

static int tolua_set_Pointer_CSoundImp__reference(lua_State* L)
{
	Pointer<CSoundImp>* self = (Pointer<CSoundImp>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CSoundImp>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CSoundImp*)tolua_tousertype_dynamic(L, 2, 0, "CSoundImp");
	return 0;
}

static int tolua_function_Pointer_CSoundImp__setValue(lua_State* L)
{
	Pointer<CSoundImp>* self = (Pointer<CSoundImp>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CSoundImp>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CSoundImp*)tolua_tousertype_dynamic(L, 2, 0, "CSoundImp"));
	return 0;
}

static int tolua_get_Pointer_CAreaTintOverride__reference(lua_State* L)
{
	Pointer<CAreaTintOverride>* self = (Pointer<CAreaTintOverride>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAreaTintOverride>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CAreaTintOverride");
	return 1;
}

static int tolua_set_Pointer_CAreaTintOverride__reference(lua_State* L)
{
	Pointer<CAreaTintOverride>* self = (Pointer<CAreaTintOverride>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAreaTintOverride>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 2, 0, "CAreaTintOverride");
	return 0;
}

static int tolua_function_Pointer_CAreaTintOverride__setValue(lua_State* L)
{
	Pointer<CAreaTintOverride>* self = (Pointer<CAreaTintOverride>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAreaTintOverride>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CAreaTintOverride*)tolua_tousertype_dynamic(L, 2, 0, "CAreaTintOverride"));
	return 0;
}

static int tolua_get_Pointer_CBaldurChitin___reference(lua_State* L)
{
	Pointer<CBaldurChitin*>* self = (Pointer<CBaldurChitin*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CBaldurChitin*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<EEex_CBaldurChitin>");
	return 1;
}

static int tolua_set_Pointer_CBaldurChitin___reference(lua_State* L)
{
	Pointer<CBaldurChitin*>* self = (Pointer<CBaldurChitin*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CBaldurChitin*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CBaldurChitin**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<EEex_CBaldurChitin>");
	return 0;
}

static int tolua_function_Pointer_CBaldurChitin___getValue(lua_State* L)
{
	Pointer<CBaldurChitin*>* self = (Pointer<CBaldurChitin*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CBaldurChitin*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CBaldurChitin* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "EEex_CBaldurChitin");
	return 1;
}

static int tolua_function_Pointer_CBaldurChitin___setValue(lua_State* L)
{
	Pointer<CBaldurChitin*>* self = (Pointer<CBaldurChitin*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CBaldurChitin*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CBaldurChitin*)tolua_tousertype_dynamic(L, 2, 0, "EEex_CBaldurChitin"));
	return 0;
}

static int tolua_get_Pointer_CObject___reference(lua_State* L)
{
	Pointer<CObject*>* self = (Pointer<CObject*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CObject*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CObject>");
	return 1;
}

static int tolua_set_Pointer_CObject___reference(lua_State* L)
{
	Pointer<CObject*>* self = (Pointer<CObject*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CObject*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CObject**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CObject>");
	return 0;
}

static int tolua_function_Pointer_CObject___getValue(lua_State* L)
{
	Pointer<CObject*>* self = (Pointer<CObject*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CObject*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CObject* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CObject");
	return 1;
}

static int tolua_function_Pointer_CObject___setValue(lua_State* L)
{
	Pointer<CObject*>* self = (Pointer<CObject*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CObject*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CObject*)tolua_tousertype_dynamic(L, 2, 0, "CObject"));
	return 0;
}

static int tolua_get_Pointer_CGameArea___reference(lua_State* L)
{
	Pointer<CGameArea*>* self = (Pointer<CGameArea*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameArea*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CGameArea>");
	return 1;
}

static int tolua_set_Pointer_CGameArea___reference(lua_State* L)
{
	Pointer<CGameArea*>* self = (Pointer<CGameArea*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameArea*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameArea**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameArea>");
	return 0;
}

static int tolua_function_Pointer_CGameArea___getValue(lua_State* L)
{
	Pointer<CGameArea*>* self = (Pointer<CGameArea*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameArea*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CGameArea* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CGameArea");
	return 1;
}

static int tolua_function_Pointer_CGameArea___setValue(lua_State* L)
{
	Pointer<CGameArea*>* self = (Pointer<CGameArea*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameArea*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CGameArea*)tolua_tousertype_dynamic(L, 2, 0, "CGameArea"));
	return 0;
}

static int tolua_get_Pointer_const_CPoint___reference(lua_State* L)
{
	Pointer<const CPoint*>* self = (Pointer<const CPoint*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CPoint*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<const CPoint>");
	return 1;
}

static int tolua_set_Pointer_const_CPoint___reference(lua_State* L)
{
	Pointer<const CPoint*>* self = (Pointer<const CPoint*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CPoint*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const CPoint**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<const CPoint>");
	return 0;
}

static int tolua_function_Pointer_const_CPoint___getValue(lua_State* L)
{
	Pointer<const CPoint*>* self = (Pointer<const CPoint*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CPoint*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	const CPoint* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CPoint");
	return 1;
}

static int tolua_get_Pointer_const_CAIObjectType___reference(lua_State* L)
{
	Pointer<const CAIObjectType*>* self = (Pointer<const CAIObjectType*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAIObjectType*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<const CAIObjectType>");
	return 1;
}

static int tolua_set_Pointer_const_CAIObjectType___reference(lua_State* L)
{
	Pointer<const CAIObjectType*>* self = (Pointer<const CAIObjectType*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAIObjectType*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const CAIObjectType**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<const CAIObjectType>");
	return 0;
}

static int tolua_function_Pointer_const_CAIObjectType___getValue(lua_State* L)
{
	Pointer<const CAIObjectType*>* self = (Pointer<const CAIObjectType*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAIObjectType*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	const CAIObjectType* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CAIObjectType");
	return 1;
}

static int tolua_get_Pointer_CPoint___reference(lua_State* L)
{
	Pointer<CPoint*>* self = (Pointer<CPoint*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPoint*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CPoint>");
	return 1;
}

static int tolua_set_Pointer_CPoint___reference(lua_State* L)
{
	Pointer<CPoint*>* self = (Pointer<CPoint*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPoint*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CPoint**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CPoint>");
	return 0;
}

static int tolua_function_Pointer_CPoint___getValue(lua_State* L)
{
	Pointer<CPoint*>* self = (Pointer<CPoint*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPoint*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CPoint* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CPoint");
	return 1;
}

static int tolua_function_Pointer_CPoint___setValue(lua_State* L)
{
	Pointer<CPoint*>* self = (Pointer<CPoint*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPoint*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CPoint*)tolua_tousertype_dynamic(L, 2, 0, "CPoint"));
	return 0;
}

static int tolua_get_Pointer_CTypedPtrList_CPtrList_long___CNode___reference(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,long>::CNode*>* self = (Pointer<CTypedPtrList<CPtrList,long>::CNode*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,long>::CNode*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CTypedPtrList<CPtrList,long>::CNode>");
	return 1;
}

static int tolua_set_Pointer_CTypedPtrList_CPtrList_long___CNode___reference(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,long>::CNode*>* self = (Pointer<CTypedPtrList<CPtrList,long>::CNode*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,long>::CNode*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CTypedPtrList<CPtrList,long>::CNode**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CTypedPtrList<CPtrList,long>::CNode>");
	return 0;
}

static int tolua_function_Pointer_CTypedPtrList_CPtrList_long___CNode___getValue(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,long>::CNode*>* self = (Pointer<CTypedPtrList<CPtrList,long>::CNode*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,long>::CNode*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CTypedPtrList<CPtrList,long>::CNode* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CTypedPtrList<CPtrList,long>::CNode");
	return 1;
}

static int tolua_function_Pointer_CTypedPtrList_CPtrList_long___CNode___setValue(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,long>::CNode*>* self = (Pointer<CTypedPtrList<CPtrList,long>::CNode*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,long>::CNode*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,long>::CNode"));
	return 0;
}

static int tolua_get_Pointer_unsigned_int___reference(lua_State* L)
{
	Pointer<unsigned int*>* self = (Pointer<unsigned int*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<unsigned int>");
	return 1;
}

static int tolua_set_Pointer_unsigned_int___reference(lua_State* L)
{
	Pointer<unsigned int*>* self = (Pointer<unsigned int*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (unsigned int**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<unsigned int>");
	return 0;
}

static int tolua_function_Pointer_unsigned_int___getValue(lua_State* L)
{
	Pointer<unsigned int*>* self = (Pointer<unsigned int*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned int*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	unsigned int* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "Primitive<int>");
	return 1;
}

static int tolua_function_Pointer_unsigned_int___setValue(lua_State* L)
{
	Pointer<unsigned int*>* self = (Pointer<unsigned int*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned int*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((unsigned int*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<int>"));
	return 0;
}

static int tolua_get_Pointer_const_CString___reference(lua_State* L)
{
	Pointer<const CString*>* self = (Pointer<const CString*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CString*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<const CString>");
	return 1;
}

static int tolua_set_Pointer_const_CString___reference(lua_State* L)
{
	Pointer<const CString*>* self = (Pointer<const CString*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CString*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const CString**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<const CString>");
	return 0;
}

static int tolua_function_Pointer_const_CString___getValue(lua_State* L)
{
	Pointer<const CString*>* self = (Pointer<const CString*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CString*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	const CString* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CString");
	return 1;
}

static int tolua_get_Pointer_CVidMode___reference(lua_State* L)
{
	Pointer<CVidMode*>* self = (Pointer<CVidMode*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidMode*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CVidMode>");
	return 1;
}

static int tolua_set_Pointer_CVidMode___reference(lua_State* L)
{
	Pointer<CVidMode*>* self = (Pointer<CVidMode*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidMode*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CVidMode**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CVidMode>");
	return 0;
}

static int tolua_function_Pointer_CVidMode___getValue(lua_State* L)
{
	Pointer<CVidMode*>* self = (Pointer<CVidMode*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidMode*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CVidMode* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CVidMode");
	return 1;
}

static int tolua_function_Pointer_CVidMode___setValue(lua_State* L)
{
	Pointer<CVidMode*>* self = (Pointer<CVidMode*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidMode*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CVidMode*)tolua_tousertype_dynamic(L, 2, 0, "CVidMode"));
	return 0;
}

static int tolua_get_Pointer___POSITION___reference(lua_State* L)
{
	Pointer<__POSITION*>* self = (Pointer<__POSITION*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__POSITION*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<__POSITION>");
	return 1;
}

static int tolua_set_Pointer___POSITION___reference(lua_State* L)
{
	Pointer<__POSITION*>* self = (Pointer<__POSITION*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__POSITION*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (__POSITION**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<__POSITION>");
	return 0;
}

static int tolua_function_Pointer___POSITION___getValue(lua_State* L)
{
	Pointer<__POSITION*>* self = (Pointer<__POSITION*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__POSITION*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	__POSITION* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "__POSITION");
	return 1;
}

static int tolua_function_Pointer___POSITION___setValue(lua_State* L)
{
	Pointer<__POSITION*>* self = (Pointer<__POSITION*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__POSITION*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((__POSITION*)tolua_tousertype_dynamic(L, 2, 0, "__POSITION"));
	return 0;
}

static int tolua_get_Pointer_const_CAITrigger___reference(lua_State* L)
{
	Pointer<const CAITrigger*>* self = (Pointer<const CAITrigger*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAITrigger*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<const CAITrigger>");
	return 1;
}

static int tolua_set_Pointer_const_CAITrigger___reference(lua_State* L)
{
	Pointer<const CAITrigger*>* self = (Pointer<const CAITrigger*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAITrigger*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const CAITrigger**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<const CAITrigger>");
	return 0;
}

static int tolua_function_Pointer_const_CAITrigger___getValue(lua_State* L)
{
	Pointer<const CAITrigger*>* self = (Pointer<const CAITrigger*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAITrigger*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	const CAITrigger* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CAITrigger");
	return 1;
}

static int tolua_get_Pointer_CGameAIBase___reference(lua_State* L)
{
	Pointer<CGameAIBase*>* self = (Pointer<CGameAIBase*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAIBase*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CGameAIBase>");
	return 1;
}

static int tolua_set_Pointer_CGameAIBase___reference(lua_State* L)
{
	Pointer<CGameAIBase*>* self = (Pointer<CGameAIBase*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAIBase*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameAIBase**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameAIBase>");
	return 0;
}

static int tolua_function_Pointer_CGameAIBase___getValue(lua_State* L)
{
	Pointer<CGameAIBase*>* self = (Pointer<CGameAIBase*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAIBase*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CGameAIBase* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CGameAIBase");
	return 1;
}

static int tolua_function_Pointer_CGameAIBase___setValue(lua_State* L)
{
	Pointer<CGameAIBase*>* self = (Pointer<CGameAIBase*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAIBase*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CGameAIBase*)tolua_tousertype_dynamic(L, 2, 0, "CGameAIBase"));
	return 0;
}

static int tolua_get_Pointer_const_CAIAction___reference(lua_State* L)
{
	Pointer<const CAIAction*>* self = (Pointer<const CAIAction*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAIAction*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<const CAIAction>");
	return 1;
}

static int tolua_set_Pointer_const_CAIAction___reference(lua_State* L)
{
	Pointer<const CAIAction*>* self = (Pointer<const CAIAction*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAIAction*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const CAIAction**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<const CAIAction>");
	return 0;
}

static int tolua_function_Pointer_const_CAIAction___getValue(lua_State* L)
{
	Pointer<const CAIAction*>* self = (Pointer<const CAIAction*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAIAction*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	const CAIAction* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CAIAction");
	return 1;
}

static int tolua_get_Pointer_CGameEffect___reference(lua_State* L)
{
	Pointer<CGameEffect*>* self = (Pointer<CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CGameEffect>");
	return 1;
}

static int tolua_set_Pointer_CGameEffect___reference(lua_State* L)
{
	Pointer<CGameEffect*>* self = (Pointer<CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameEffect**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameEffect>");
	return 0;
}

static int tolua_function_Pointer_CGameEffect___getValue(lua_State* L)
{
	Pointer<CGameEffect*>* self = (Pointer<CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CGameEffect* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CGameEffect");
	return 1;
}

static int tolua_function_Pointer_CGameEffect___setValue(lua_State* L)
{
	Pointer<CGameEffect*>* self = (Pointer<CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CGameEffect*)tolua_tousertype_dynamic(L, 2, 0, "CGameEffect"));
	return 0;
}

static int tolua_get_Pointer_CResRef___reference(lua_State* L)
{
	Pointer<CResRef*>* self = (Pointer<CResRef*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResRef*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CResRef>");
	return 1;
}

static int tolua_set_Pointer_CResRef___reference(lua_State* L)
{
	Pointer<CResRef*>* self = (Pointer<CResRef*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResRef*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CResRef**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CResRef>");
	return 0;
}

static int tolua_function_Pointer_CResRef___getValue(lua_State* L)
{
	Pointer<CResRef*>* self = (Pointer<CResRef*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResRef*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CResRef* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CResRef");
	return 1;
}

static int tolua_function_Pointer_CResRef___setValue(lua_State* L)
{
	Pointer<CResRef*>* self = (Pointer<CResRef*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResRef*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CResRef*)tolua_tousertype_dynamic(L, 2, 0, "CResRef"));
	return 0;
}

static int tolua_get_Pointer_CGameObject____reference(lua_State* L)
{
	Pointer<CGameObject**>* self = (Pointer<CGameObject**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject**>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CGameObject*>");
	return 1;
}

static int tolua_set_Pointer_CGameObject____reference(lua_State* L)
{
	Pointer<CGameObject**>* self = (Pointer<CGameObject**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject**>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameObject***)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameObject*>");
	return 0;
}

static int tolua_function_Pointer_CGameObject____getValue(lua_State* L)
{
	Pointer<CGameObject**>* self = (Pointer<CGameObject**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject**>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CGameObject** returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "Pointer<CGameObject>");
	return 1;
}

static int tolua_function_Pointer_CGameObject____setValue(lua_State* L)
{
	Pointer<CGameObject**>* self = (Pointer<CGameObject**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject**>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CGameObject**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameObject>"));
	return 0;
}

static int tolua_get_Pointer_Item_effect_st___reference(lua_State* L)
{
	Pointer<Item_effect_st*>* self = (Pointer<Item_effect_st*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Item_effect_st*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<Item_effect_st>");
	return 1;
}

static int tolua_set_Pointer_Item_effect_st___reference(lua_State* L)
{
	Pointer<Item_effect_st*>* self = (Pointer<Item_effect_st*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Item_effect_st*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Item_effect_st**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<Item_effect_st>");
	return 0;
}

static int tolua_function_Pointer_Item_effect_st___getValue(lua_State* L)
{
	Pointer<Item_effect_st*>* self = (Pointer<Item_effect_st*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Item_effect_st*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	Item_effect_st* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "Item_effect_st");
	return 1;
}

static int tolua_function_Pointer_Item_effect_st___setValue(lua_State* L)
{
	Pointer<Item_effect_st*>* self = (Pointer<Item_effect_st*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Item_effect_st*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((Item_effect_st*)tolua_tousertype_dynamic(L, 2, 0, "Item_effect_st"));
	return 0;
}

static int tolua_get_Pointer_CProjectile___reference(lua_State* L)
{
	Pointer<CProjectile*>* self = (Pointer<CProjectile*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectile*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CProjectile>");
	return 1;
}

static int tolua_set_Pointer_CProjectile___reference(lua_State* L)
{
	Pointer<CProjectile*>* self = (Pointer<CProjectile*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectile*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CProjectile**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CProjectile>");
	return 0;
}

static int tolua_function_Pointer_CProjectile___getValue(lua_State* L)
{
	Pointer<CProjectile*>* self = (Pointer<CProjectile*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectile*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CProjectile* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CProjectile");
	return 1;
}

static int tolua_function_Pointer_CProjectile___setValue(lua_State* L)
{
	Pointer<CProjectile*>* self = (Pointer<CProjectile*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectile*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CProjectile*)tolua_tousertype_dynamic(L, 2, 0, "CProjectile"));
	return 0;
}

static int tolua_get_Pointer_CInfGame___reference(lua_State* L)
{
	Pointer<CInfGame*>* self = (Pointer<CInfGame*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CInfGame*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<EEex_CInfGame>");
	return 1;
}

static int tolua_set_Pointer_CInfGame___reference(lua_State* L)
{
	Pointer<CInfGame*>* self = (Pointer<CInfGame*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CInfGame*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CInfGame**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<EEex_CInfGame>");
	return 0;
}

static int tolua_function_Pointer_CInfGame___getValue(lua_State* L)
{
	Pointer<CInfGame*>* self = (Pointer<CInfGame*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CInfGame*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CInfGame* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "EEex_CInfGame");
	return 1;
}

static int tolua_function_Pointer_CInfGame___setValue(lua_State* L)
{
	Pointer<CInfGame*>* self = (Pointer<CInfGame*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CInfGame*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CInfGame*)tolua_tousertype_dynamic(L, 2, 0, "EEex_CInfGame"));
	return 0;
}

static int tolua_get_Pointer_CScreenWorld___reference(lua_State* L)
{
	Pointer<CScreenWorld*>* self = (Pointer<CScreenWorld*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CScreenWorld*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<EEex_CScreenWorld>");
	return 1;
}

static int tolua_set_Pointer_CScreenWorld___reference(lua_State* L)
{
	Pointer<CScreenWorld*>* self = (Pointer<CScreenWorld*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CScreenWorld*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CScreenWorld**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<EEex_CScreenWorld>");
	return 0;
}

static int tolua_function_Pointer_CScreenWorld___getValue(lua_State* L)
{
	Pointer<CScreenWorld*>* self = (Pointer<CScreenWorld*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CScreenWorld*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CScreenWorld* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "EEex_CScreenWorld");
	return 1;
}

static int tolua_function_Pointer_CScreenWorld___setValue(lua_State* L)
{
	Pointer<CScreenWorld*>* self = (Pointer<CScreenWorld*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CScreenWorld*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CScreenWorld*)tolua_tousertype_dynamic(L, 2, 0, "EEex_CScreenWorld"));
	return 0;
}

static int tolua_get_Pointer_CGameAnimationType___reference(lua_State* L)
{
	Pointer<CGameAnimationType*>* self = (Pointer<CGameAnimationType*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAnimationType*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CGameAnimationType>");
	return 1;
}

static int tolua_set_Pointer_CGameAnimationType___reference(lua_State* L)
{
	Pointer<CGameAnimationType*>* self = (Pointer<CGameAnimationType*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAnimationType*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameAnimationType**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameAnimationType>");
	return 0;
}

static int tolua_function_Pointer_CGameAnimationType___getValue(lua_State* L)
{
	Pointer<CGameAnimationType*>* self = (Pointer<CGameAnimationType*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAnimationType*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CGameAnimationType* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CGameAnimationType");
	return 1;
}

static int tolua_function_Pointer_CGameAnimationType___setValue(lua_State* L)
{
	Pointer<CGameAnimationType*>* self = (Pointer<CGameAnimationType*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAnimationType*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CGameAnimationType*)tolua_tousertype_dynamic(L, 2, 0, "CGameAnimationType"));
	return 0;
}

static int tolua_get_Pointer_CProjectileUnknownPST2___reference(lua_State* L)
{
	Pointer<CProjectileUnknownPST2*>* self = (Pointer<CProjectileUnknownPST2*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST2*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CProjectileUnknownPST2>");
	return 1;
}

static int tolua_set_Pointer_CProjectileUnknownPST2___reference(lua_State* L)
{
	Pointer<CProjectileUnknownPST2*>* self = (Pointer<CProjectileUnknownPST2*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST2*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CProjectileUnknownPST2**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CProjectileUnknownPST2>");
	return 0;
}

static int tolua_function_Pointer_CProjectileUnknownPST2___getValue(lua_State* L)
{
	Pointer<CProjectileUnknownPST2*>* self = (Pointer<CProjectileUnknownPST2*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST2*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CProjectileUnknownPST2* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CProjectileUnknownPST2");
	return 1;
}

static int tolua_function_Pointer_CProjectileUnknownPST2___setValue(lua_State* L)
{
	Pointer<CProjectileUnknownPST2*>* self = (Pointer<CProjectileUnknownPST2*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST2*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 2, 0, "CProjectileUnknownPST2"));
	return 0;
}

static int tolua_get_Pointer_CInfinity___reference(lua_State* L)
{
	Pointer<CInfinity*>* self = (Pointer<CInfinity*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CInfinity*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CInfinity>");
	return 1;
}

static int tolua_set_Pointer_CInfinity___reference(lua_State* L)
{
	Pointer<CInfinity*>* self = (Pointer<CInfinity*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CInfinity*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CInfinity**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CInfinity>");
	return 0;
}

static int tolua_function_Pointer_CInfinity___getValue(lua_State* L)
{
	Pointer<CInfinity*>* self = (Pointer<CInfinity*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CInfinity*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CInfinity* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CInfinity");
	return 1;
}

static int tolua_function_Pointer_CInfinity___setValue(lua_State* L)
{
	Pointer<CInfinity*>* self = (Pointer<CInfinity*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CInfinity*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CInfinity*)tolua_tousertype_dynamic(L, 2, 0, "CInfinity"));
	return 0;
}

static int tolua_get_Pointer_CVidCell___reference(lua_State* L)
{
	Pointer<CVidCell*>* self = (Pointer<CVidCell*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidCell*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CVidCell>");
	return 1;
}

static int tolua_set_Pointer_CVidCell___reference(lua_State* L)
{
	Pointer<CVidCell*>* self = (Pointer<CVidCell*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidCell*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CVidCell**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CVidCell>");
	return 0;
}

static int tolua_function_Pointer_CVidCell___getValue(lua_State* L)
{
	Pointer<CVidCell*>* self = (Pointer<CVidCell*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidCell*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CVidCell* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CVidCell");
	return 1;
}

static int tolua_function_Pointer_CVidCell___setValue(lua_State* L)
{
	Pointer<CVidCell*>* self = (Pointer<CVidCell*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidCell*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CVidCell*)tolua_tousertype_dynamic(L, 2, 0, "CVidCell"));
	return 0;
}

static int tolua_get_Pointer_CPtrList_CNode___reference(lua_State* L)
{
	Pointer<CPtrList_CNode*>* self = (Pointer<CPtrList_CNode*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPtrList_CNode*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CPtrList_CNode>");
	return 1;
}

static int tolua_set_Pointer_CPtrList_CNode___reference(lua_State* L)
{
	Pointer<CPtrList_CNode*>* self = (Pointer<CPtrList_CNode*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPtrList_CNode*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CPtrList_CNode**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CPtrList_CNode>");
	return 0;
}

static int tolua_function_Pointer_CPtrList_CNode___getValue(lua_State* L)
{
	Pointer<CPtrList_CNode*>* self = (Pointer<CPtrList_CNode*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPtrList_CNode*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CPtrList_CNode* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CPtrList_CNode");
	return 1;
}

static int tolua_function_Pointer_CPtrList_CNode___setValue(lua_State* L)
{
	Pointer<CPtrList_CNode*>* self = (Pointer<CPtrList_CNode*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPtrList_CNode*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CPtrList_CNode*)tolua_tousertype_dynamic(L, 2, 0, "CPtrList_CNode"));
	return 0;
}

static int tolua_get_Pointer_int___reference(lua_State* L)
{
	Pointer<int*>* self = (Pointer<int*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<int>");
	return 1;
}

static int tolua_set_Pointer_int___reference(lua_State* L)
{
	Pointer<int*>* self = (Pointer<int*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (int**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<int>");
	return 0;
}

static int tolua_function_Pointer_int___getValue(lua_State* L)
{
	Pointer<int*>* self = (Pointer<int*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<int*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	int* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "Primitive<int>");
	return 1;
}

static int tolua_function_Pointer_int___setValue(lua_State* L)
{
	Pointer<int*>* self = (Pointer<int*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<int*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((int*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<int>"));
	return 0;
}

static int tolua_get_Pointer_CSoundImp___reference(lua_State* L)
{
	Pointer<CSoundImp*>* self = (Pointer<CSoundImp*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CSoundImp*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CSoundImp>");
	return 1;
}

static int tolua_set_Pointer_CSoundImp___reference(lua_State* L)
{
	Pointer<CSoundImp*>* self = (Pointer<CSoundImp*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CSoundImp*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CSoundImp**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CSoundImp>");
	return 0;
}

static int tolua_function_Pointer_CSoundImp___getValue(lua_State* L)
{
	Pointer<CSoundImp*>* self = (Pointer<CSoundImp*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CSoundImp*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CSoundImp* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CSoundImp");
	return 1;
}

static int tolua_function_Pointer_CSoundImp___setValue(lua_State* L)
{
	Pointer<CSoundImp*>* self = (Pointer<CSoundImp*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CSoundImp*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CSoundImp*)tolua_tousertype_dynamic(L, 2, 0, "CSoundImp"));
	return 0;
}

static int tolua_get_Pointer_CAreaTintOverride___reference(lua_State* L)
{
	Pointer<CAreaTintOverride*>* self = (Pointer<CAreaTintOverride*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAreaTintOverride*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CAreaTintOverride>");
	return 1;
}

static int tolua_set_Pointer_CAreaTintOverride___reference(lua_State* L)
{
	Pointer<CAreaTintOverride*>* self = (Pointer<CAreaTintOverride*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAreaTintOverride*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CAreaTintOverride**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CAreaTintOverride>");
	return 0;
}

static int tolua_function_Pointer_CAreaTintOverride___getValue(lua_State* L)
{
	Pointer<CAreaTintOverride*>* self = (Pointer<CAreaTintOverride*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAreaTintOverride*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CAreaTintOverride* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CAreaTintOverride");
	return 1;
}

static int tolua_function_Pointer_CAreaTintOverride___setValue(lua_State* L)
{
	Pointer<CAreaTintOverride*>* self = (Pointer<CAreaTintOverride*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAreaTintOverride*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CAreaTintOverride*)tolua_tousertype_dynamic(L, 2, 0, "CAreaTintOverride"));
	return 0;
}

static int tolua_get_Pointer_CGameAnimation__reference(lua_State* L)
{
	Pointer<CGameAnimation>* self = (Pointer<CGameAnimation>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAnimation>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CGameAnimation");
	return 1;
}

static int tolua_set_Pointer_CGameAnimation__reference(lua_State* L)
{
	Pointer<CGameAnimation>* self = (Pointer<CGameAnimation>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAnimation>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameAnimation*)tolua_tousertype_dynamic(L, 2, 0, "CGameAnimation");
	return 0;
}

static int tolua_function_Pointer_CGameAnimation__setValue(lua_State* L)
{
	Pointer<CGameAnimation>* self = (Pointer<CGameAnimation>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAnimation>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CGameAnimation*)tolua_tousertype_dynamic(L, 2, 0, "CGameAnimation"));
	return 0;
}

static int tolua_get_Pointer_CInfButtonArray__reference(lua_State* L)
{
	Pointer<CInfButtonArray>* self = (Pointer<CInfButtonArray>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CInfButtonArray>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "EEex_CInfButtonArray");
	return 1;
}

static int tolua_set_Pointer_CInfButtonArray__reference(lua_State* L)
{
	Pointer<CInfButtonArray>* self = (Pointer<CInfButtonArray>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CInfButtonArray>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CInfButtonArray*)tolua_tousertype_dynamic(L, 2, 0, "EEex_CInfButtonArray");
	return 0;
}

static int tolua_function_Pointer_CInfButtonArray__setValue(lua_State* L)
{
	Pointer<CInfButtonArray>* self = (Pointer<CInfButtonArray>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CInfButtonArray>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CInfButtonArray*)tolua_tousertype_dynamic(L, 2, 0, "EEex_CInfButtonArray"));
	return 0;
}

static int tolua_get_Pointer_CPersistantEffectColorEffect__reference(lua_State* L)
{
	Pointer<CPersistantEffectColorEffect>* self = (Pointer<CPersistantEffectColorEffect>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPersistantEffectColorEffect>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CPersistantEffectColorEffect");
	return 1;
}

static int tolua_set_Pointer_CPersistantEffectColorEffect__reference(lua_State* L)
{
	Pointer<CPersistantEffectColorEffect>* self = (Pointer<CPersistantEffectColorEffect>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPersistantEffectColorEffect>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CPersistantEffectColorEffect*)tolua_tousertype_dynamic(L, 2, 0, "CPersistantEffectColorEffect");
	return 0;
}

static int tolua_function_Pointer_CPersistantEffectColorEffect__setValue(lua_State* L)
{
	Pointer<CPersistantEffectColorEffect>* self = (Pointer<CPersistantEffectColorEffect>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPersistantEffectColorEffect>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CPersistantEffectColorEffect*)tolua_tousertype_dynamic(L, 2, 0, "CPersistantEffectColorEffect"));
	return 0;
}

static int tolua_get_Pointer_CPlanescape__reference(lua_State* L)
{
	Pointer<CPlanescape>* self = (Pointer<CPlanescape>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPlanescape>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CPlanescape");
	return 1;
}

static int tolua_set_Pointer_CPlanescape__reference(lua_State* L)
{
	Pointer<CPlanescape>* self = (Pointer<CPlanescape>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPlanescape>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CPlanescape*)tolua_tousertype_dynamic(L, 2, 0, "CPlanescape");
	return 0;
}

static int tolua_function_Pointer_CPlanescape__setValue(lua_State* L)
{
	Pointer<CPlanescape>* self = (Pointer<CPlanescape>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPlanescape>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CPlanescape*)tolua_tousertype_dynamic(L, 2, 0, "CPlanescape"));
	return 0;
}

static int tolua_get_Pointer_CResCell__reference(lua_State* L)
{
	Pointer<CResCell>* self = (Pointer<CResCell>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResCell>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CResCell");
	return 1;
}

static int tolua_set_Pointer_CResCell__reference(lua_State* L)
{
	Pointer<CResCell>* self = (Pointer<CResCell>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResCell>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CResCell*)tolua_tousertype_dynamic(L, 2, 0, "CResCell");
	return 0;
}

static int tolua_function_Pointer_CResCell__setValue(lua_State* L)
{
	Pointer<CResCell>* self = (Pointer<CResCell>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResCell>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CResCell*)tolua_tousertype_dynamic(L, 2, 0, "CResCell"));
	return 0;
}

static int tolua_get_Pointer_CResCell___reference(lua_State* L)
{
	Pointer<CResCell*>* self = (Pointer<CResCell*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResCell*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CResCell>");
	return 1;
}

static int tolua_set_Pointer_CResCell___reference(lua_State* L)
{
	Pointer<CResCell*>* self = (Pointer<CResCell*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResCell*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CResCell**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CResCell>");
	return 0;
}

static int tolua_function_Pointer_CResCell___getValue(lua_State* L)
{
	Pointer<CResCell*>* self = (Pointer<CResCell*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResCell*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CResCell* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CResCell");
	return 1;
}

static int tolua_function_Pointer_CResCell___setValue(lua_State* L)
{
	Pointer<CResCell*>* self = (Pointer<CResCell*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResCell*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CResCell*)tolua_tousertype_dynamic(L, 2, 0, "CResCell"));
	return 0;
}

static int tolua_get_Pointer_CSound__reference(lua_State* L)
{
	Pointer<CSound>* self = (Pointer<CSound>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CSound>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CSound");
	return 1;
}

static int tolua_set_Pointer_CSound__reference(lua_State* L)
{
	Pointer<CSound>* self = (Pointer<CSound>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CSound>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CSound*)tolua_tousertype_dynamic(L, 2, 0, "CSound");
	return 0;
}

static int tolua_function_Pointer_CSound__setValue(lua_State* L)
{
	Pointer<CSound>* self = (Pointer<CSound>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CSound>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CSound*)tolua_tousertype_dynamic(L, 2, 0, "CSound"));
	return 0;
}

static int tolua_get_Pointer_CVidImage__reference(lua_State* L)
{
	Pointer<CVidImage>* self = (Pointer<CVidImage>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidImage>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CVidImage");
	return 1;
}

static int tolua_set_Pointer_CVidImage__reference(lua_State* L)
{
	Pointer<CVidImage>* self = (Pointer<CVidImage>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidImage>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CVidImage*)tolua_tousertype_dynamic(L, 2, 0, "CVidImage");
	return 0;
}

static int tolua_function_Pointer_CVidImage__setValue(lua_State* L)
{
	Pointer<CVidImage>* self = (Pointer<CVidImage>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidImage>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CVidImage*)tolua_tousertype_dynamic(L, 2, 0, "CVidImage"));
	return 0;
}

static int tolua_get_Pointer_CVideo__reference(lua_State* L)
{
	Pointer<CVideo>* self = (Pointer<CVideo>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVideo>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CVideo");
	return 1;
}

static int tolua_set_Pointer_CVideo__reference(lua_State* L)
{
	Pointer<CVideo>* self = (Pointer<CVideo>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVideo>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CVideo*)tolua_tousertype_dynamic(L, 2, 0, "CVideo");
	return 0;
}

static int tolua_function_Pointer_CVideo__setValue(lua_State* L)
{
	Pointer<CVideo>* self = (Pointer<CVideo>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVideo>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CVideo*)tolua_tousertype_dynamic(L, 2, 0, "CVideo"));
	return 0;
}

static int tolua_get_Pointer_size_t__reference(lua_State* L)
{
	Pointer<size_t>* self = (Pointer<size_t>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<size_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<size_t>");
	return 1;
}

static int tolua_set_Pointer_size_t__reference(lua_State* L)
{
	Pointer<size_t>* self = (Pointer<size_t>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<size_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (size_t*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<size_t>");
	return 0;
}

static int tolua_function_Pointer_size_t__getValue(lua_State* L)
{
	Pointer<size_t>* self = (Pointer<size_t>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<size_t>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	size_t returnVal = self->getValue();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Pointer_size_t__setValue(lua_State* L)
{
	Pointer<size_t>* self = (Pointer<size_t>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<size_t>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger<size_t>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_uintptr_t__reference(lua_State* L)
{
	Pointer<uintptr_t>* self = (Pointer<uintptr_t>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<uintptr_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<uintptr_t>");
	return 1;
}

static int tolua_set_Pointer_uintptr_t__reference(lua_State* L)
{
	Pointer<uintptr_t>* self = (Pointer<uintptr_t>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<uintptr_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (uintptr_t*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<uintptr_t>");
	return 0;
}

static int tolua_function_Pointer_uintptr_t__getValue(lua_State* L)
{
	Pointer<uintptr_t>* self = (Pointer<uintptr_t>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<uintptr_t>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	uintptr_t returnVal = self->getValue();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Pointer_uintptr_t__setValue(lua_State* L)
{
	Pointer<uintptr_t>* self = (Pointer<uintptr_t>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<uintptr_t>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger<uintptr_t>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_CGameObjectType__reference(lua_State* L)
{
	Pointer<CGameObjectType>* self = (Pointer<CGameObjectType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObjectType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<CGameObjectType>");
	return 1;
}

static int tolua_set_Pointer_CGameObjectType__reference(lua_State* L)
{
	Pointer<CGameObjectType>* self = (Pointer<CGameObjectType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObjectType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameObjectType*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<CGameObjectType>");
	return 0;
}

static int tolua_function_Pointer_CGameObjectType__getValue(lua_State* L)
{
	Pointer<CGameObjectType>* self = (Pointer<CGameObjectType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObjectType>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CGameObjectType returnVal = self->getValue();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Pointer_CGameObjectType__setValue(lua_State* L)
{
	Pointer<CGameObjectType>* self = (Pointer<CGameObjectType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObjectType>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CGameObjectType)tolua_function_tointeger<__int8>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_unsigned___int8__reference(lua_State* L)
{
	Pointer<unsigned __int8>* self = (Pointer<unsigned __int8>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned __int8>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<__int8>");
	return 1;
}

static int tolua_set_Pointer_unsigned___int8__reference(lua_State* L)
{
	Pointer<unsigned __int8>* self = (Pointer<unsigned __int8>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned __int8>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (unsigned __int8*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<__int8>");
	return 0;
}

static int tolua_function_Pointer_unsigned___int8__getValue(lua_State* L)
{
	Pointer<unsigned __int8>* self = (Pointer<unsigned __int8>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned __int8>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	unsigned __int8 returnVal = self->getValue();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Pointer_unsigned___int8__setValue(lua_State* L)
{
	Pointer<unsigned __int8>* self = (Pointer<unsigned __int8>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned __int8>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger<unsigned __int8>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_long__reference(lua_State* L)
{
	Pointer<long>* self = (Pointer<long>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<long>");
	return 1;
}

static int tolua_set_Pointer_long__reference(lua_State* L)
{
	Pointer<long>* self = (Pointer<long>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (long*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<long>");
	return 0;
}

static int tolua_function_Pointer_long__getValue(lua_State* L)
{
	Pointer<long>* self = (Pointer<long>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	long returnVal = self->getValue();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Pointer_long__setValue(lua_State* L)
{
	Pointer<long>* self = (Pointer<long>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger<long>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_VertListType__reference(lua_State* L)
{
	Pointer<VertListType>* self = (Pointer<VertListType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<VertListType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<VertListType>");
	return 1;
}

static int tolua_set_Pointer_VertListType__reference(lua_State* L)
{
	Pointer<VertListType>* self = (Pointer<VertListType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<VertListType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (VertListType*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<VertListType>");
	return 0;
}

static int tolua_function_Pointer_VertListType__getValue(lua_State* L)
{
	Pointer<VertListType>* self = (Pointer<VertListType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<VertListType>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	VertListType returnVal = self->getValue();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Pointer_VertListType__setValue(lua_State* L)
{
	Pointer<VertListType>* self = (Pointer<VertListType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<VertListType>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((VertListType)tolua_function_tointeger<__int8>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_short__reference(lua_State* L)
{
	Pointer<short>* self = (Pointer<short>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<short>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<short>");
	return 1;
}

static int tolua_set_Pointer_short__reference(lua_State* L)
{
	Pointer<short>* self = (Pointer<short>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<short>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (short*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<short>");
	return 0;
}

static int tolua_function_Pointer_short__getValue(lua_State* L)
{
	Pointer<short>* self = (Pointer<short>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<short>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	short returnVal = self->getValue();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Pointer_short__setValue(lua_State* L)
{
	Pointer<short>* self = (Pointer<short>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<short>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger<short>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer___int8__reference(lua_State* L)
{
	Pointer<__int8>* self = (Pointer<__int8>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__int8>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<__int8>");
	return 1;
}

static int tolua_set_Pointer___int8__reference(lua_State* L)
{
	Pointer<__int8>* self = (Pointer<__int8>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__int8>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (__int8*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<__int8>");
	return 0;
}

static int tolua_function_Pointer___int8__getValue(lua_State* L)
{
	Pointer<__int8>* self = (Pointer<__int8>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__int8>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	__int8 returnVal = self->getValue();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Pointer___int8__setValue(lua_State* L)
{
	Pointer<__int8>* self = (Pointer<__int8>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__int8>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger<__int8>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_byte__reference(lua_State* L)
{
	Pointer<byte>* self = (Pointer<byte>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<byte>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<byte>");
	return 1;
}

static int tolua_set_Pointer_byte__reference(lua_State* L)
{
	Pointer<byte>* self = (Pointer<byte>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<byte>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (byte*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<byte>");
	return 0;
}

static int tolua_function_Pointer_byte__getValue(lua_State* L)
{
	Pointer<byte>* self = (Pointer<byte>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<byte>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	byte returnVal = self->getValue();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Pointer_byte__setValue(lua_State* L)
{
	Pointer<byte>* self = (Pointer<byte>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<byte>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger<byte>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_ushort__reference(lua_State* L)
{
	Pointer<ushort>* self = (Pointer<ushort>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<ushort>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<ushort>");
	return 1;
}

static int tolua_set_Pointer_ushort__reference(lua_State* L)
{
	Pointer<ushort>* self = (Pointer<ushort>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<ushort>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (ushort*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<ushort>");
	return 0;
}

static int tolua_function_Pointer_ushort__getValue(lua_State* L)
{
	Pointer<ushort>* self = (Pointer<ushort>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<ushort>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	ushort returnVal = self->getValue();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Pointer_ushort__setValue(lua_State* L)
{
	Pointer<ushort>* self = (Pointer<ushort>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<ushort>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger<ushort>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_uint__reference(lua_State* L)
{
	Pointer<uint>* self = (Pointer<uint>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<uint>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<uint>");
	return 1;
}

static int tolua_set_Pointer_uint__reference(lua_State* L)
{
	Pointer<uint>* self = (Pointer<uint>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<uint>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (uint*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<uint>");
	return 0;
}

static int tolua_function_Pointer_uint__getValue(lua_State* L)
{
	Pointer<uint>* self = (Pointer<uint>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<uint>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	uint returnVal = self->getValue();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Pointer_uint__setValue(lua_State* L)
{
	Pointer<uint>* self = (Pointer<uint>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<uint>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger<uint>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_double__reference(lua_State* L)
{
	Pointer<double>* self = (Pointer<double>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<double>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<double>");
	return 1;
}

static int tolua_set_Pointer_double__reference(lua_State* L)
{
	Pointer<double>* self = (Pointer<double>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<double>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (double*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<double>");
	return 0;
}

static int tolua_function_Pointer_double__getValue(lua_State* L)
{
	Pointer<double>* self = (Pointer<double>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<double>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	double returnVal = self->getValue();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Pointer_double__setValue(lua_State* L)
{
	Pointer<double>* self = (Pointer<double>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<double>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tonumber<double>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_float__reference(lua_State* L)
{
	Pointer<float>* self = (Pointer<float>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<float>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<float>");
	return 1;
}

static int tolua_set_Pointer_float__reference(lua_State* L)
{
	Pointer<float>* self = (Pointer<float>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<float>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (float*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<float>");
	return 0;
}

static int tolua_function_Pointer_float__getValue(lua_State* L)
{
	Pointer<float>* self = (Pointer<float>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<float>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	float returnVal = self->getValue();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Pointer_float__setValue(lua_State* L)
{
	Pointer<float>* self = (Pointer<float>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<float>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tonumber<float>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer___int32__reference(lua_State* L)
{
	Pointer<__int32>* self = (Pointer<__int32>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__int32>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<__int32>");
	return 1;
}

static int tolua_set_Pointer___int32__reference(lua_State* L)
{
	Pointer<__int32>* self = (Pointer<__int32>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__int32>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (__int32*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<__int32>");
	return 0;
}

static int tolua_function_Pointer___int32__getValue(lua_State* L)
{
	Pointer<__int32>* self = (Pointer<__int32>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__int32>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	__int32 returnVal = self->getValue();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Pointer___int32__setValue(lua_State* L)
{
	Pointer<__int32>* self = (Pointer<__int32>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__int32>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger<__int32>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_Primitive_long_double___reference(lua_State* L)
{
	Pointer<Primitive<long double>>* self = (Pointer<Primitive<long double>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<long double>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<long double>");
	return 1;
}

static int tolua_set_Pointer_Primitive_long_double___reference(lua_State* L)
{
	Pointer<Primitive<long double>>* self = (Pointer<Primitive<long double>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<long double>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<long double>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<long double>");
	return 0;
}

static int tolua_function_Pointer_Primitive_long_double___setValue(lua_State* L)
{
	Pointer<Primitive<long double>>* self = (Pointer<Primitive<long double>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<long double>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<long double>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<long double>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_uint16_t___reference(lua_State* L)
{
	Pointer<Primitive<uint16_t>>* self = (Pointer<Primitive<uint16_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uint16_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<uint16_t>");
	return 1;
}

static int tolua_set_Pointer_Primitive_uint16_t___reference(lua_State* L)
{
	Pointer<Primitive<uint16_t>>* self = (Pointer<Primitive<uint16_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uint16_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<uint16_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<uint16_t>");
	return 0;
}

static int tolua_function_Pointer_Primitive_uint16_t___setValue(lua_State* L)
{
	Pointer<Primitive<uint16_t>>* self = (Pointer<Primitive<uint16_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uint16_t>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<uint16_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<uint16_t>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_int___reference(lua_State* L)
{
	Pointer<Primitive<int>>* self = (Pointer<Primitive<int>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<int>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<int>");
	return 1;
}

static int tolua_set_Pointer_Primitive_int___reference(lua_State* L)
{
	Pointer<Primitive<int>>* self = (Pointer<Primitive<int>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<int>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<int>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<int>");
	return 0;
}

static int tolua_function_Pointer_Primitive_int___setValue(lua_State* L)
{
	Pointer<Primitive<int>>* self = (Pointer<Primitive<int>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<int>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<int>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<int>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_int64_t___reference(lua_State* L)
{
	Pointer<Primitive<int64_t>>* self = (Pointer<Primitive<int64_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<int64_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<int64_t>");
	return 1;
}

static int tolua_set_Pointer_Primitive_int64_t___reference(lua_State* L)
{
	Pointer<Primitive<int64_t>>* self = (Pointer<Primitive<int64_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<int64_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<int64_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<int64_t>");
	return 0;
}

static int tolua_function_Pointer_Primitive_int64_t___setValue(lua_State* L)
{
	Pointer<Primitive<int64_t>>* self = (Pointer<Primitive<int64_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<int64_t>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<int64_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<int64_t>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_intptr_t___reference(lua_State* L)
{
	Pointer<Primitive<intptr_t>>* self = (Pointer<Primitive<intptr_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<intptr_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<intptr_t>");
	return 1;
}

static int tolua_set_Pointer_Primitive_intptr_t___reference(lua_State* L)
{
	Pointer<Primitive<intptr_t>>* self = (Pointer<Primitive<intptr_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<intptr_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<intptr_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<intptr_t>");
	return 0;
}

static int tolua_function_Pointer_Primitive_intptr_t___setValue(lua_State* L)
{
	Pointer<Primitive<intptr_t>>* self = (Pointer<Primitive<intptr_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<intptr_t>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<intptr_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<intptr_t>"));
	return 0;
}

static int tolua_get_Pointer_Primitive___int64___reference(lua_State* L)
{
	Pointer<Primitive<__int64>>* self = (Pointer<Primitive<__int64>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<__int64>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<__int64>");
	return 1;
}

static int tolua_set_Pointer_Primitive___int64___reference(lua_State* L)
{
	Pointer<Primitive<__int64>>* self = (Pointer<Primitive<__int64>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<__int64>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<__int64>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<__int64>");
	return 0;
}

static int tolua_function_Pointer_Primitive___int64___setValue(lua_State* L)
{
	Pointer<Primitive<__int64>>* self = (Pointer<Primitive<__int64>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<__int64>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<__int64>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<__int64>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_long___reference(lua_State* L)
{
	Pointer<Primitive<long>>* self = (Pointer<Primitive<long>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<long>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<long>");
	return 1;
}

static int tolua_set_Pointer_Primitive_long___reference(lua_State* L)
{
	Pointer<Primitive<long>>* self = (Pointer<Primitive<long>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<long>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<long>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<long>");
	return 0;
}

static int tolua_function_Pointer_Primitive_long___setValue(lua_State* L)
{
	Pointer<Primitive<long>>* self = (Pointer<Primitive<long>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<long>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<long>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<long>"));
	return 0;
}

static int tolua_get_Pointer_Primitive___int8___reference(lua_State* L)
{
	Pointer<Primitive<__int8>>* self = (Pointer<Primitive<__int8>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<__int8>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<__int8>");
	return 1;
}

static int tolua_set_Pointer_Primitive___int8___reference(lua_State* L)
{
	Pointer<Primitive<__int8>>* self = (Pointer<Primitive<__int8>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<__int8>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<__int8>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<__int8>");
	return 0;
}

static int tolua_function_Pointer_Primitive___int8___setValue(lua_State* L)
{
	Pointer<Primitive<__int8>>* self = (Pointer<Primitive<__int8>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<__int8>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<__int8>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<__int8>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_double___reference(lua_State* L)
{
	Pointer<Primitive<double>>* self = (Pointer<Primitive<double>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<double>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<double>");
	return 1;
}

static int tolua_set_Pointer_Primitive_double___reference(lua_State* L)
{
	Pointer<Primitive<double>>* self = (Pointer<Primitive<double>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<double>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<double>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<double>");
	return 0;
}

static int tolua_function_Pointer_Primitive_double___setValue(lua_State* L)
{
	Pointer<Primitive<double>>* self = (Pointer<Primitive<double>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<double>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<double>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<double>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_byte___reference(lua_State* L)
{
	Pointer<Primitive<byte>>* self = (Pointer<Primitive<byte>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<byte>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<byte>");
	return 1;
}

static int tolua_set_Pointer_Primitive_byte___reference(lua_State* L)
{
	Pointer<Primitive<byte>>* self = (Pointer<Primitive<byte>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<byte>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<byte>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<byte>");
	return 0;
}

static int tolua_function_Pointer_Primitive_byte___setValue(lua_State* L)
{
	Pointer<Primitive<byte>>* self = (Pointer<Primitive<byte>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<byte>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<byte>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<byte>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_float___reference(lua_State* L)
{
	Pointer<Primitive<float>>* self = (Pointer<Primitive<float>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<float>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<float>");
	return 1;
}

static int tolua_set_Pointer_Primitive_float___reference(lua_State* L)
{
	Pointer<Primitive<float>>* self = (Pointer<Primitive<float>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<float>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<float>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<float>");
	return 0;
}

static int tolua_function_Pointer_Primitive_float___setValue(lua_State* L)
{
	Pointer<Primitive<float>>* self = (Pointer<Primitive<float>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<float>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<float>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<float>"));
	return 0;
}

static int tolua_get_Pointer_Primitive___int16___reference(lua_State* L)
{
	Pointer<Primitive<__int16>>* self = (Pointer<Primitive<__int16>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<__int16>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<__int16>");
	return 1;
}

static int tolua_set_Pointer_Primitive___int16___reference(lua_State* L)
{
	Pointer<Primitive<__int16>>* self = (Pointer<Primitive<__int16>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<__int16>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<__int16>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<__int16>");
	return 0;
}

static int tolua_function_Pointer_Primitive___int16___setValue(lua_State* L)
{
	Pointer<Primitive<__int16>>* self = (Pointer<Primitive<__int16>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<__int16>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<__int16>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<__int16>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_uint___reference(lua_State* L)
{
	Pointer<Primitive<uint>>* self = (Pointer<Primitive<uint>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uint>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<uint>");
	return 1;
}

static int tolua_set_Pointer_Primitive_uint___reference(lua_State* L)
{
	Pointer<Primitive<uint>>* self = (Pointer<Primitive<uint>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uint>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<uint>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<uint>");
	return 0;
}

static int tolua_function_Pointer_Primitive_uint___setValue(lua_State* L)
{
	Pointer<Primitive<uint>>* self = (Pointer<Primitive<uint>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uint>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<uint>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<uint>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_short___reference(lua_State* L)
{
	Pointer<Primitive<short>>* self = (Pointer<Primitive<short>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<short>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<short>");
	return 1;
}

static int tolua_set_Pointer_Primitive_short___reference(lua_State* L)
{
	Pointer<Primitive<short>>* self = (Pointer<Primitive<short>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<short>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<short>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<short>");
	return 0;
}

static int tolua_function_Pointer_Primitive_short___setValue(lua_State* L)
{
	Pointer<Primitive<short>>* self = (Pointer<Primitive<short>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<short>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<short>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<short>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_int16_t___reference(lua_State* L)
{
	Pointer<Primitive<int16_t>>* self = (Pointer<Primitive<int16_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<int16_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<int16_t>");
	return 1;
}

static int tolua_set_Pointer_Primitive_int16_t___reference(lua_State* L)
{
	Pointer<Primitive<int16_t>>* self = (Pointer<Primitive<int16_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<int16_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<int16_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<int16_t>");
	return 0;
}

static int tolua_function_Pointer_Primitive_int16_t___setValue(lua_State* L)
{
	Pointer<Primitive<int16_t>>* self = (Pointer<Primitive<int16_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<int16_t>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<int16_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<int16_t>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_uintptr_t___reference(lua_State* L)
{
	Pointer<Primitive<uintptr_t>>* self = (Pointer<Primitive<uintptr_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uintptr_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<uintptr_t>");
	return 1;
}

static int tolua_set_Pointer_Primitive_uintptr_t___reference(lua_State* L)
{
	Pointer<Primitive<uintptr_t>>* self = (Pointer<Primitive<uintptr_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uintptr_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<uintptr_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<uintptr_t>");
	return 0;
}

static int tolua_function_Pointer_Primitive_uintptr_t___setValue(lua_State* L)
{
	Pointer<Primitive<uintptr_t>>* self = (Pointer<Primitive<uintptr_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uintptr_t>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<uintptr_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<uintptr_t>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_char___reference(lua_State* L)
{
	Pointer<Primitive<char>>* self = (Pointer<Primitive<char>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<char>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<char>");
	return 1;
}

static int tolua_set_Pointer_Primitive_char___reference(lua_State* L)
{
	Pointer<Primitive<char>>* self = (Pointer<Primitive<char>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<char>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<char>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<char>");
	return 0;
}

static int tolua_function_Pointer_Primitive_char___setValue(lua_State* L)
{
	Pointer<Primitive<char>>* self = (Pointer<Primitive<char>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<char>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<char>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<char>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_int8_t___reference(lua_State* L)
{
	Pointer<Primitive<int8_t>>* self = (Pointer<Primitive<int8_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<int8_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<int8_t>");
	return 1;
}

static int tolua_set_Pointer_Primitive_int8_t___reference(lua_State* L)
{
	Pointer<Primitive<int8_t>>* self = (Pointer<Primitive<int8_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<int8_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<int8_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<int8_t>");
	return 0;
}

static int tolua_function_Pointer_Primitive_int8_t___setValue(lua_State* L)
{
	Pointer<Primitive<int8_t>>* self = (Pointer<Primitive<int8_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<int8_t>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<int8_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<int8_t>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_ushort___reference(lua_State* L)
{
	Pointer<Primitive<ushort>>* self = (Pointer<Primitive<ushort>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<ushort>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<ushort>");
	return 1;
}

static int tolua_set_Pointer_Primitive_ushort___reference(lua_State* L)
{
	Pointer<Primitive<ushort>>* self = (Pointer<Primitive<ushort>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<ushort>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<ushort>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<ushort>");
	return 0;
}

static int tolua_function_Pointer_Primitive_ushort___setValue(lua_State* L)
{
	Pointer<Primitive<ushort>>* self = (Pointer<Primitive<ushort>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<ushort>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<ushort>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<ushort>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_bool___reference(lua_State* L)
{
	Pointer<Primitive<bool>>* self = (Pointer<Primitive<bool>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<bool>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<bool>");
	return 1;
}

static int tolua_set_Pointer_Primitive_bool___reference(lua_State* L)
{
	Pointer<Primitive<bool>>* self = (Pointer<Primitive<bool>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<bool>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<bool>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<bool>");
	return 0;
}

static int tolua_function_Pointer_Primitive_bool___setValue(lua_State* L)
{
	Pointer<Primitive<bool>>* self = (Pointer<Primitive<bool>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<bool>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<bool>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<bool>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_int32_t___reference(lua_State* L)
{
	Pointer<Primitive<int32_t>>* self = (Pointer<Primitive<int32_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<int32_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<int32_t>");
	return 1;
}

static int tolua_set_Pointer_Primitive_int32_t___reference(lua_State* L)
{
	Pointer<Primitive<int32_t>>* self = (Pointer<Primitive<int32_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<int32_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<int32_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<int32_t>");
	return 0;
}

static int tolua_function_Pointer_Primitive_int32_t___setValue(lua_State* L)
{
	Pointer<Primitive<int32_t>>* self = (Pointer<Primitive<int32_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<int32_t>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<int32_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<int32_t>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_uint64_t___reference(lua_State* L)
{
	Pointer<Primitive<uint64_t>>* self = (Pointer<Primitive<uint64_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uint64_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<uint64_t>");
	return 1;
}

static int tolua_set_Pointer_Primitive_uint64_t___reference(lua_State* L)
{
	Pointer<Primitive<uint64_t>>* self = (Pointer<Primitive<uint64_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uint64_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<uint64_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<uint64_t>");
	return 0;
}

static int tolua_function_Pointer_Primitive_uint64_t___setValue(lua_State* L)
{
	Pointer<Primitive<uint64_t>>* self = (Pointer<Primitive<uint64_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uint64_t>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<uint64_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<uint64_t>"));
	return 0;
}

static int tolua_get_Pointer_Primitive___int32___reference(lua_State* L)
{
	Pointer<Primitive<__int32>>* self = (Pointer<Primitive<__int32>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<__int32>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<__int32>");
	return 1;
}

static int tolua_set_Pointer_Primitive___int32___reference(lua_State* L)
{
	Pointer<Primitive<__int32>>* self = (Pointer<Primitive<__int32>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<__int32>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<__int32>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<__int32>");
	return 0;
}

static int tolua_function_Pointer_Primitive___int32___setValue(lua_State* L)
{
	Pointer<Primitive<__int32>>* self = (Pointer<Primitive<__int32>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<__int32>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<__int32>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<__int32>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_size_t___reference(lua_State* L)
{
	Pointer<Primitive<size_t>>* self = (Pointer<Primitive<size_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<size_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<size_t>");
	return 1;
}

static int tolua_set_Pointer_Primitive_size_t___reference(lua_State* L)
{
	Pointer<Primitive<size_t>>* self = (Pointer<Primitive<size_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<size_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<size_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<size_t>");
	return 0;
}

static int tolua_function_Pointer_Primitive_size_t___setValue(lua_State* L)
{
	Pointer<Primitive<size_t>>* self = (Pointer<Primitive<size_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<size_t>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<size_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<size_t>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_uint8_t___reference(lua_State* L)
{
	Pointer<Primitive<uint8_t>>* self = (Pointer<Primitive<uint8_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uint8_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<uint8_t>");
	return 1;
}

static int tolua_set_Pointer_Primitive_uint8_t___reference(lua_State* L)
{
	Pointer<Primitive<uint8_t>>* self = (Pointer<Primitive<uint8_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uint8_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<uint8_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<uint8_t>");
	return 0;
}

static int tolua_function_Pointer_Primitive_uint8_t___setValue(lua_State* L)
{
	Pointer<Primitive<uint8_t>>* self = (Pointer<Primitive<uint8_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uint8_t>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<uint8_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<uint8_t>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_uint32_t___reference(lua_State* L)
{
	Pointer<Primitive<uint32_t>>* self = (Pointer<Primitive<uint32_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uint32_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<uint32_t>");
	return 1;
}

static int tolua_set_Pointer_Primitive_uint32_t___reference(lua_State* L)
{
	Pointer<Primitive<uint32_t>>* self = (Pointer<Primitive<uint32_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uint32_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<uint32_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<uint32_t>");
	return 0;
}

static int tolua_function_Pointer_Primitive_uint32_t___setValue(lua_State* L)
{
	Pointer<Primitive<uint32_t>>* self = (Pointer<Primitive<uint32_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<uint32_t>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<uint32_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<uint32_t>"));
	return 0;
}

static int tolua_get_Pointer_Primitive_ptrdiff_t___reference(lua_State* L)
{
	Pointer<Primitive<ptrdiff_t>>* self = (Pointer<Primitive<ptrdiff_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<ptrdiff_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<ptrdiff_t>");
	return 1;
}

static int tolua_set_Pointer_Primitive_ptrdiff_t___reference(lua_State* L)
{
	Pointer<Primitive<ptrdiff_t>>* self = (Pointer<Primitive<ptrdiff_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<ptrdiff_t>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Primitive<ptrdiff_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<ptrdiff_t>");
	return 0;
}

static int tolua_function_Pointer_Primitive_ptrdiff_t___setValue(lua_State* L)
{
	Pointer<Primitive<ptrdiff_t>>* self = (Pointer<Primitive<ptrdiff_t>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Primitive<ptrdiff_t>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(Primitive<ptrdiff_t>*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<ptrdiff_t>"));
	return 0;
}

static int tolua_get_Pointer_void___reference(lua_State* L)
{
	Pointer<void*>* self = (Pointer<void*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<void*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "VoidPointer");
	return 1;
}

static int tolua_set_Pointer_void___reference(lua_State* L)
{
	Pointer<void*>* self = (Pointer<void*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<void*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (void**)tolua_tousertype_dynamic(L, 2, 0, "VoidPointer");
	return 0;
}

static int tolua_function_Pointer_void___getValue(lua_State* L)
{
	Pointer<void*>* self = (Pointer<void*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<void*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	void* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "UnmappedUserType");
	return 1;
}

static int tolua_function_Pointer_void___setValue(lua_State* L)
{
	Pointer<void*>* self = (Pointer<void*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<void*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((void*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType"));
	return 0;
}

static int tolua_get_Pointer_UnmappedUserType__reference(lua_State* L)
{
	Pointer<UnmappedUserType>* self = (Pointer<UnmappedUserType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<UnmappedUserType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "UnmappedUserType");
	return 1;
}

static int tolua_set_Pointer_UnmappedUserType__reference(lua_State* L)
{
	Pointer<UnmappedUserType>* self = (Pointer<UnmappedUserType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<UnmappedUserType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (UnmappedUserType*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType");
	return 0;
}

static int tolua_function_Pointer_UnmappedUserType__setValue(lua_State* L)
{
	Pointer<UnmappedUserType>* self = (Pointer<UnmappedUserType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<UnmappedUserType>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(UnmappedUserType*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType"));
	return 0;
}

static int tolua_get_Pointer_PlayerScriptNameOrdinal__reference(lua_State* L)
{
	Pointer<PlayerScriptNameOrdinal>* self = (Pointer<PlayerScriptNameOrdinal>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<PlayerScriptNameOrdinal>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<PlayerScriptNameOrdinal>");
	return 1;
}

static int tolua_set_Pointer_PlayerScriptNameOrdinal__reference(lua_State* L)
{
	Pointer<PlayerScriptNameOrdinal>* self = (Pointer<PlayerScriptNameOrdinal>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<PlayerScriptNameOrdinal>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (PlayerScriptNameOrdinal*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<PlayerScriptNameOrdinal>");
	return 0;
}

static int tolua_function_Pointer_PlayerScriptNameOrdinal__getValue(lua_State* L)
{
	Pointer<PlayerScriptNameOrdinal>* self = (Pointer<PlayerScriptNameOrdinal>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<PlayerScriptNameOrdinal>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	PlayerScriptNameOrdinal returnVal = self->getValue();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Pointer_PlayerScriptNameOrdinal__setValue(lua_State* L)
{
	Pointer<PlayerScriptNameOrdinal>* self = (Pointer<PlayerScriptNameOrdinal>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<PlayerScriptNameOrdinal>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((PlayerScriptNameOrdinal)tolua_function_tointeger<__int32>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_DrawFeature__reference(lua_State* L)
{
	Pointer<DrawFeature>* self = (Pointer<DrawFeature>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<DrawFeature>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<DrawFeature>");
	return 1;
}

static int tolua_set_Pointer_DrawFeature__reference(lua_State* L)
{
	Pointer<DrawFeature>* self = (Pointer<DrawFeature>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<DrawFeature>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (DrawFeature*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<DrawFeature>");
	return 0;
}

static int tolua_function_Pointer_DrawFeature__getValue(lua_State* L)
{
	Pointer<DrawFeature>* self = (Pointer<DrawFeature>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<DrawFeature>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	DrawFeature returnVal = self->getValue();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Pointer_DrawFeature__setValue(lua_State* L)
{
	Pointer<DrawFeature>* self = (Pointer<DrawFeature>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<DrawFeature>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((DrawFeature)tolua_function_tointeger<__int32>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_byte___reference(lua_State* L)
{
	Pointer<byte*>* self = (Pointer<byte*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<byte*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<byte>");
	return 1;
}

static int tolua_set_Pointer_byte___reference(lua_State* L)
{
	Pointer<byte*>* self = (Pointer<byte*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<byte*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (byte**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<byte>");
	return 0;
}

static int tolua_function_Pointer_byte___getValue(lua_State* L)
{
	Pointer<byte*>* self = (Pointer<byte*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<byte*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	byte* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "Primitive<byte>");
	return 1;
}

static int tolua_function_Pointer_byte___setValue(lua_State* L)
{
	Pointer<byte*>* self = (Pointer<byte*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<byte*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((byte*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<byte>"));
	return 0;
}

static int tolua_get_Pointer_char___reference(lua_State* L)
{
	Pointer<char*>* self = (Pointer<char*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<char*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CharString");
	return 1;
}

static int tolua_set_Pointer_char___reference(lua_State* L)
{
	Pointer<char*>* self = (Pointer<char*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<char*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (char**)tolua_tousertype_dynamic(L, 2, 0, "CharString");
	return 0;
}

static int tolua_function_Pointer_char___setValue(lua_State* L)
{
	Pointer<char*>* self = (Pointer<char*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<char*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(char**)tolua_tousertype_dynamic(L, 2, 0, "CharString"));
	return 0;
}

static int tolua_get_Pointer_char__reference(lua_State* L)
{
	Pointer<char>* self = (Pointer<char>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<char>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)&self->reference, "CharString");
	return 1;
}

static int tolua_function_Pointer_char__getValue(lua_State* L)
{
	Pointer<char>* self = (Pointer<char>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<char>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	char returnVal = self->getValue();
	lua_pushlstring(L, (const char*)&returnVal, 1);
	return 1;
}

static int tolua_function_Pointer_char__setValue(lua_State* L)
{
	Pointer<char>* self = (Pointer<char>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<char>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tochar(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_const_char___reference(lua_State* L)
{
	Pointer<const char*>* self = (Pointer<const char*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const char*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "ConstCharString");
	return 1;
}

static int tolua_set_Pointer_const_char___reference(lua_State* L)
{
	Pointer<const char*>* self = (Pointer<const char*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const char*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const char**)tolua_tousertype_dynamic(L, 2, 0, "ConstCharString");
	return 0;
}

static int tolua_get_Pointer_long_double__reference(lua_State* L)
{
	Pointer<long double>* self = (Pointer<long double>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long double>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Primitive<double>");
	return 1;
}

static int tolua_set_Pointer_long_double__reference(lua_State* L)
{
	Pointer<long double>* self = (Pointer<long double>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long double>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (long double*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<double>");
	return 0;
}

static int tolua_function_Pointer_long_double__getValue(lua_State* L)
{
	Pointer<long double>* self = (Pointer<long double>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long double>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	long double returnVal = self->getValue();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Pointer_long_double__setValue(lua_State* L)
{
	Pointer<long double>* self = (Pointer<long double>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long double>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tonumber<long double>(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_CRect__reference(lua_State* L)
{
	Pointer<CRect>* self = (Pointer<CRect>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CRect>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CRect");
	return 1;
}

static int tolua_set_Pointer_CRect__reference(lua_State* L)
{
	Pointer<CRect>* self = (Pointer<CRect>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CRect>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CRect*)tolua_tousertype_dynamic(L, 2, 0, "CRect");
	return 0;
}

static int tolua_function_Pointer_CRect__setValue(lua_State* L)
{
	Pointer<CRect>* self = (Pointer<CRect>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CRect>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CRect*)tolua_tousertype_dynamic(L, 2, 0, "CRect"));
	return 0;
}

static int tolua_get_Pointer_CPtrList__reference(lua_State* L)
{
	Pointer<CPtrList>* self = (Pointer<CPtrList>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPtrList>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CPtrList");
	return 1;
}

static int tolua_set_Pointer_CPtrList__reference(lua_State* L)
{
	Pointer<CPtrList>* self = (Pointer<CPtrList>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPtrList>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CPtrList*)tolua_tousertype_dynamic(L, 2, 0, "CPtrList");
	return 0;
}

static int tolua_function_Pointer_CPtrList__setValue(lua_State* L)
{
	Pointer<CPtrList>* self = (Pointer<CPtrList>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPtrList>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CPtrList*)tolua_tousertype_dynamic(L, 2, 0, "CPtrList"));
	return 0;
}

static int tolua_get_Pointer_CGameObjectArray__reference(lua_State* L)
{
	Pointer<CGameObjectArray>* self = (Pointer<CGameObjectArray>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObjectArray>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CGameObjectArray");
	return 1;
}

static int tolua_set_Pointer_CGameObjectArray__reference(lua_State* L)
{
	Pointer<CGameObjectArray>* self = (Pointer<CGameObjectArray>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObjectArray>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameObjectArray*)tolua_tousertype_dynamic(L, 2, 0, "CGameObjectArray");
	return 0;
}

static int tolua_function_Pointer_CGameObjectArray__setValue(lua_State* L)
{
	Pointer<CGameObjectArray>* self = (Pointer<CGameObjectArray>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObjectArray>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CGameObjectArray*)tolua_tousertype_dynamic(L, 2, 0, "CGameObjectArray"));
	return 0;
}

static int tolua_get_Pointer_long___reference(lua_State* L)
{
	Pointer<long*>* self = (Pointer<long*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<long>");
	return 1;
}

static int tolua_set_Pointer_long___reference(lua_State* L)
{
	Pointer<long*>* self = (Pointer<long*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (long**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<long>");
	return 0;
}

static int tolua_function_Pointer_long___getValue(lua_State* L)
{
	Pointer<long*>* self = (Pointer<long*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	long* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "Primitive<long>");
	return 1;
}

static int tolua_function_Pointer_long___setValue(lua_State* L)
{
	Pointer<long*>* self = (Pointer<long*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((long*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<long>"));
	return 0;
}

static int tolua_get_Pointer_CMessage__reference(lua_State* L)
{
	Pointer<CMessage>* self = (Pointer<CMessage>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CMessage>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CMessage");
	return 1;
}

static int tolua_set_Pointer_CMessage__reference(lua_State* L)
{
	Pointer<CMessage>* self = (Pointer<CMessage>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CMessage>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CMessage*)tolua_tousertype_dynamic(L, 2, 0, "CMessage");
	return 0;
}

static int tolua_function_Pointer_CMessage__setValue(lua_State* L)
{
	Pointer<CMessage>* self = (Pointer<CMessage>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CMessage>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CMessage*)tolua_tousertype_dynamic(L, 2, 0, "CMessage"));
	return 0;
}

static int tolua_get_Pointer_CMessageVisualEffect__reference(lua_State* L)
{
	Pointer<CMessageVisualEffect>* self = (Pointer<CMessageVisualEffect>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CMessageVisualEffect>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CMessageVisualEffect");
	return 1;
}

static int tolua_set_Pointer_CMessageVisualEffect__reference(lua_State* L)
{
	Pointer<CMessageVisualEffect>* self = (Pointer<CMessageVisualEffect>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CMessageVisualEffect>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CMessageVisualEffect*)tolua_tousertype_dynamic(L, 2, 0, "CMessageVisualEffect");
	return 0;
}

static int tolua_function_Pointer_CMessageVisualEffect__setValue(lua_State* L)
{
	Pointer<CMessageVisualEffect>* self = (Pointer<CMessageVisualEffect>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CMessageVisualEffect>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CMessageVisualEffect*)tolua_tousertype_dynamic(L, 2, 0, "CMessageVisualEffect"));
	return 0;
}

static int tolua_get_Pointer_CMessageAddEffect__reference(lua_State* L)
{
	Pointer<CMessageAddEffect>* self = (Pointer<CMessageAddEffect>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CMessageAddEffect>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CMessageAddEffect");
	return 1;
}

static int tolua_set_Pointer_CMessageAddEffect__reference(lua_State* L)
{
	Pointer<CMessageAddEffect>* self = (Pointer<CMessageAddEffect>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CMessageAddEffect>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CMessageAddEffect*)tolua_tousertype_dynamic(L, 2, 0, "CMessageAddEffect");
	return 0;
}

static int tolua_function_Pointer_CMessageAddEffect__setValue(lua_State* L)
{
	Pointer<CMessageAddEffect>* self = (Pointer<CMessageAddEffect>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CMessageAddEffect>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CMessageAddEffect*)tolua_tousertype_dynamic(L, 2, 0, "CMessageAddEffect"));
	return 0;
}

static int tolua_get_Pointer_CTimerWorld__reference(lua_State* L)
{
	Pointer<CTimerWorld>* self = (Pointer<CTimerWorld>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CTimerWorld>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "EEex_CTimerWorld");
	return 1;
}

static int tolua_set_Pointer_CTimerWorld__reference(lua_State* L)
{
	Pointer<CTimerWorld>* self = (Pointer<CTimerWorld>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CTimerWorld>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CTimerWorld*)tolua_tousertype_dynamic(L, 2, 0, "EEex_CTimerWorld");
	return 0;
}

static int tolua_function_Pointer_CTimerWorld__setValue(lua_State* L)
{
	Pointer<CTimerWorld>* self = (Pointer<CTimerWorld>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CTimerWorld>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CTimerWorld*)tolua_tousertype_dynamic(L, 2, 0, "EEex_CTimerWorld"));
	return 0;
}

static int tolua_get_Pointer_CGameTrigger__reference(lua_State* L)
{
	Pointer<CGameTrigger>* self = (Pointer<CGameTrigger>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameTrigger>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CGameTrigger");
	return 1;
}

static int tolua_set_Pointer_CGameTrigger__reference(lua_State* L)
{
	Pointer<CGameTrigger>* self = (Pointer<CGameTrigger>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameTrigger>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameTrigger*)tolua_tousertype_dynamic(L, 2, 0, "CGameTrigger");
	return 0;
}

static int tolua_function_Pointer_CGameTrigger__setValue(lua_State* L)
{
	Pointer<CGameTrigger>* self = (Pointer<CGameTrigger>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameTrigger>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CGameTrigger*)tolua_tousertype_dynamic(L, 2, 0, "CGameTrigger"));
	return 0;
}

static int tolua_get_Pointer_CGameDoor__reference(lua_State* L)
{
	Pointer<CGameDoor>* self = (Pointer<CGameDoor>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameDoor>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CGameDoor");
	return 1;
}

static int tolua_set_Pointer_CGameDoor__reference(lua_State* L)
{
	Pointer<CGameDoor>* self = (Pointer<CGameDoor>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameDoor>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameDoor*)tolua_tousertype_dynamic(L, 2, 0, "CGameDoor");
	return 0;
}

static int tolua_function_Pointer_CGameDoor__setValue(lua_State* L)
{
	Pointer<CGameDoor>* self = (Pointer<CGameDoor>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameDoor>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CGameDoor*)tolua_tousertype_dynamic(L, 2, 0, "CGameDoor"));
	return 0;
}

static int tolua_get_Pointer_CGameContainer__reference(lua_State* L)
{
	Pointer<CGameContainer>* self = (Pointer<CGameContainer>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameContainer>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CGameContainer");
	return 1;
}

static int tolua_set_Pointer_CGameContainer__reference(lua_State* L)
{
	Pointer<CGameContainer>* self = (Pointer<CGameContainer>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameContainer>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameContainer*)tolua_tousertype_dynamic(L, 2, 0, "CGameContainer");
	return 0;
}

static int tolua_function_Pointer_CGameContainer__setValue(lua_State* L)
{
	Pointer<CGameContainer>* self = (Pointer<CGameContainer>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameContainer>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CGameContainer*)tolua_tousertype_dynamic(L, 2, 0, "CGameContainer"));
	return 0;
}

static int tolua_get_Pointer_CharString___reference(lua_State* L)
{
	Pointer<CharString*>* self = (Pointer<CharString*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CharString*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CharString");
	return 1;
}

static int tolua_set_Pointer_CharString___reference(lua_State* L)
{
	Pointer<CharString*>* self = (Pointer<CharString*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CharString*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CharString**)tolua_tousertype_dynamic(L, 2, 0, "CharString");
	return 0;
}

static int tolua_function_Pointer_CharString___getValue(lua_State* L)
{
	Pointer<CharString*>* self = (Pointer<CharString*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CharString*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CharString* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "CharString");
	return 1;
}

static int tolua_function_Pointer_CharString___setValue(lua_State* L)
{
	Pointer<CharString*>* self = (Pointer<CharString*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CharString*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CharString*)tolua_tousertype_dynamic(L, 2, 0, "CharString"));
	return 0;
}

static int tolua_get_Pointer_CString__reference(lua_State* L)
{
	Pointer<CString>* self = (Pointer<CString>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CString>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CString");
	return 1;
}

static int tolua_set_Pointer_CString__reference(lua_State* L)
{
	Pointer<CString>* self = (Pointer<CString>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CString>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CString*)tolua_tousertype_dynamic(L, 2, 0, "CString");
	return 0;
}

static int tolua_function_Pointer_CString__setValue(lua_State* L)
{
	Pointer<CString>* self = (Pointer<CString>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CString>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CString*)tolua_tousertype_dynamic(L, 2, 0, "CString"));
	return 0;
}

static int tolua_get_Pointer_CObject__vtbl__reference(lua_State* L)
{
	Pointer<CObject::vtbl>* self = (Pointer<CObject::vtbl>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CObject::vtbl>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CObject::vtbl");
	return 1;
}

static int tolua_set_Pointer_CObject__vtbl__reference(lua_State* L)
{
	Pointer<CObject::vtbl>* self = (Pointer<CObject::vtbl>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CObject::vtbl>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CObject::vtbl*)tolua_tousertype_dynamic(L, 2, 0, "CObject::vtbl");
	return 0;
}

static int tolua_function_Pointer_CObject__vtbl__setValue(lua_State* L)
{
	Pointer<CObject::vtbl>* self = (Pointer<CObject::vtbl>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CObject::vtbl>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CObject::vtbl*)tolua_tousertype_dynamic(L, 2, 0, "CObject::vtbl"));
	return 0;
}

static int tolua_get_Pointer_CTypedPtrList_CPtrList_long___reference(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,long>>* self = (Pointer<CTypedPtrList<CPtrList,long>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,long>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CTypedPtrList<CPtrList,long>");
	return 1;
}

static int tolua_set_Pointer_CTypedPtrList_CPtrList_long___reference(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,long>>* self = (Pointer<CTypedPtrList<CPtrList,long>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,long>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,long>");
	return 0;
}

static int tolua_function_Pointer_CTypedPtrList_CPtrList_long___setValue(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,long>>* self = (Pointer<CTypedPtrList<CPtrList,long>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,long>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,long>"));
	return 0;
}

static int tolua_get_Pointer_CTypedPtrList_CPtrList_CGameEffect____reference(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,CGameEffect*>>* self = (Pointer<CTypedPtrList<CPtrList,CGameEffect*>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,CGameEffect*>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CTypedPtrList<CPtrList,CGameEffect*>");
	return 1;
}

static int tolua_set_Pointer_CTypedPtrList_CPtrList_CGameEffect____reference(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,CGameEffect*>>* self = (Pointer<CTypedPtrList<CPtrList,CGameEffect*>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,CGameEffect*>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	return 0;
}

static int tolua_function_Pointer_CTypedPtrList_CPtrList_CGameEffect____setValue(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,CGameEffect*>>* self = (Pointer<CTypedPtrList<CPtrList,CGameEffect*>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,CGameEffect*>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,CGameEffect*>"));
	return 0;
}

static int tolua_get_Pointer_CTypedPtrList_CPtrList_int____reference(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,int*>>* self = (Pointer<CTypedPtrList<CPtrList,int*>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,int*>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CTypedPtrList<CPtrList,int*>");
	return 1;
}

static int tolua_set_Pointer_CTypedPtrList_CPtrList_int____reference(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,int*>>* self = (Pointer<CTypedPtrList<CPtrList,int*>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,int*>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,int*>");
	return 0;
}

static int tolua_function_Pointer_CTypedPtrList_CPtrList_int____setValue(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,int*>>* self = (Pointer<CTypedPtrList<CPtrList,int*>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,int*>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,int*>"));
	return 0;
}

static int tolua_get_Pointer_CTypedPtrList_CPtrList_int___reference(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,int>>* self = (Pointer<CTypedPtrList<CPtrList,int>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,int>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CTypedPtrList<CPtrList,int>");
	return 1;
}

static int tolua_set_Pointer_CTypedPtrList_CPtrList_int___reference(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,int>>* self = (Pointer<CTypedPtrList<CPtrList,int>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,int>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,int>");
	return 0;
}

static int tolua_function_Pointer_CTypedPtrList_CPtrList_int___setValue(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,int>>* self = (Pointer<CTypedPtrList<CPtrList,int>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,int>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,int>"));
	return 0;
}

static int tolua_get_Pointer_CGameArea____reference(lua_State* L)
{
	Pointer<CGameArea**>* self = (Pointer<CGameArea**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameArea**>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CGameArea*>");
	return 1;
}

static int tolua_set_Pointer_CGameArea____reference(lua_State* L)
{
	Pointer<CGameArea**>* self = (Pointer<CGameArea**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameArea**>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameArea***)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameArea*>");
	return 0;
}

static int tolua_function_Pointer_CGameArea____getValue(lua_State* L)
{
	Pointer<CGameArea**>* self = (Pointer<CGameArea**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameArea**>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CGameArea** returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "Pointer<CGameArea>");
	return 1;
}

static int tolua_function_Pointer_CGameArea____setValue(lua_State* L)
{
	Pointer<CGameArea**>* self = (Pointer<CGameArea**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameArea**>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CGameArea**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameArea>"));
	return 0;
}

static int tolua_get_Pointer_CGameEffectList__reference(lua_State* L)
{
	Pointer<CGameEffectList>* self = (Pointer<CGameEffectList>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameEffectList>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CGameEffectList");
	return 1;
}

static int tolua_set_Pointer_CGameEffectList__reference(lua_State* L)
{
	Pointer<CGameEffectList>* self = (Pointer<CGameEffectList>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameEffectList>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameEffectList*)tolua_tousertype_dynamic(L, 2, 0, "CGameEffectList");
	return 0;
}

static int tolua_function_Pointer_CGameEffectList__setValue(lua_State* L)
{
	Pointer<CGameEffectList>* self = (Pointer<CGameEffectList>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameEffectList>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CGameEffectList*)tolua_tousertype_dynamic(L, 2, 0, "CGameEffectList"));
	return 0;
}

static int tolua_get_Pointer_CGameObject__vtbl__reference(lua_State* L)
{
	Pointer<CGameObject::vtbl>* self = (Pointer<CGameObject::vtbl>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject::vtbl>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CGameObject::vtbl");
	return 1;
}

static int tolua_set_Pointer_CGameObject__vtbl__reference(lua_State* L)
{
	Pointer<CGameObject::vtbl>* self = (Pointer<CGameObject::vtbl>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject::vtbl>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameObject::vtbl*)tolua_tousertype_dynamic(L, 2, 0, "CGameObject::vtbl");
	return 0;
}

static int tolua_function_Pointer_CGameObject__vtbl__setValue(lua_State* L)
{
	Pointer<CGameObject::vtbl>* self = (Pointer<CGameObject::vtbl>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject::vtbl>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CGameObject::vtbl*)tolua_tousertype_dynamic(L, 2, 0, "CGameObject::vtbl"));
	return 0;
}

static int tolua_get_Pointer_LCharString_32___reference(lua_State* L)
{
	Pointer<LCharString<32>>* self = (Pointer<LCharString<32>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<LCharString<32>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "LCharString<32>");
	return 1;
}

static int tolua_set_Pointer_LCharString_32___reference(lua_State* L)
{
	Pointer<LCharString<32>>* self = (Pointer<LCharString<32>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<LCharString<32>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (LCharString<32>*)tolua_tousertype_dynamic(L, 2, 0, "LCharString<32>");
	return 0;
}

static int tolua_function_Pointer_LCharString_32___setValue(lua_State* L)
{
	Pointer<LCharString<32>>* self = (Pointer<LCharString<32>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<LCharString<32>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(LCharString<32>*)tolua_tousertype_dynamic(L, 2, 0, "LCharString<32>"));
	return 0;
}

static int tolua_get_Pointer_CResHelper_CResCell_1000___reference(lua_State* L)
{
	Pointer<CResHelper<CResCell,1000>>* self = (Pointer<CResHelper<CResCell,1000>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResHelper<CResCell,1000>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CResHelper<CResCell,1000>");
	return 1;
}

static int tolua_set_Pointer_CResHelper_CResCell_1000___reference(lua_State* L)
{
	Pointer<CResHelper<CResCell,1000>>* self = (Pointer<CResHelper<CResCell,1000>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResHelper<CResCell,1000>>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CResHelper<CResCell,1000>*)tolua_tousertype_dynamic(L, 2, 0, "CResHelper<CResCell,1000>");
	return 0;
}

static int tolua_function_Pointer_CResHelper_CResCell_1000___setValue(lua_State* L)
{
	Pointer<CResHelper<CResCell,1000>>* self = (Pointer<CResHelper<CResCell,1000>>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResHelper<CResCell,1000>>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CResHelper<CResCell,1000>*)tolua_tousertype_dynamic(L, 2, 0, "CResHelper<CResCell,1000>"));
	return 0;
}

static int tolua_get_Pointer_CGameEffectBase__reference(lua_State* L)
{
	Pointer<CGameEffectBase>* self = (Pointer<CGameEffectBase>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameEffectBase>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CGameEffectBase");
	return 1;
}

static int tolua_set_Pointer_CGameEffectBase__reference(lua_State* L)
{
	Pointer<CGameEffectBase>* self = (Pointer<CGameEffectBase>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameEffectBase>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameEffectBase*)tolua_tousertype_dynamic(L, 2, 0, "CGameEffectBase");
	return 0;
}

static int tolua_function_Pointer_CGameEffectBase__setValue(lua_State* L)
{
	Pointer<CGameEffectBase>* self = (Pointer<CGameEffectBase>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameEffectBase>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CGameEffectBase*)tolua_tousertype_dynamic(L, 2, 0, "CGameEffectBase"));
	return 0;
}

static int tolua_get_Pointer_CDerivedStats__reference(lua_State* L)
{
	Pointer<CDerivedStats>* self = (Pointer<CDerivedStats>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CDerivedStats>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CDerivedStats");
	return 1;
}

static int tolua_set_Pointer_CDerivedStats__reference(lua_State* L)
{
	Pointer<CDerivedStats>* self = (Pointer<CDerivedStats>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CDerivedStats>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CDerivedStats*)tolua_tousertype_dynamic(L, 2, 0, "CDerivedStats");
	return 0;
}

static int tolua_function_Pointer_CDerivedStats__setValue(lua_State* L)
{
	Pointer<CDerivedStats>* self = (Pointer<CDerivedStats>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CDerivedStats>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CDerivedStats*)tolua_tousertype_dynamic(L, 2, 0, "CDerivedStats"));
	return 0;
}

static int tolua_get_Pointer_CAreaVariable__reference(lua_State* L)
{
	Pointer<CAreaVariable>* self = (Pointer<CAreaVariable>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAreaVariable>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CAreaVariable");
	return 1;
}

static int tolua_set_Pointer_CAreaVariable__reference(lua_State* L)
{
	Pointer<CAreaVariable>* self = (Pointer<CAreaVariable>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAreaVariable>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CAreaVariable*)tolua_tousertype_dynamic(L, 2, 0, "CAreaVariable");
	return 0;
}

static int tolua_function_Pointer_CAreaVariable__setValue(lua_State* L)
{
	Pointer<CAreaVariable>* self = (Pointer<CAreaVariable>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAreaVariable>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CAreaVariable*)tolua_tousertype_dynamic(L, 2, 0, "CAreaVariable"));
	return 0;
}

static int tolua_get_Pointer_CVariable__reference(lua_State* L)
{
	Pointer<CVariable>* self = (Pointer<CVariable>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVariable>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CVariable");
	return 1;
}

static int tolua_set_Pointer_CVariable__reference(lua_State* L)
{
	Pointer<CVariable>* self = (Pointer<CVariable>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVariable>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CVariable*)tolua_tousertype_dynamic(L, 2, 0, "CVariable");
	return 0;
}

static int tolua_function_Pointer_CVariable__setValue(lua_State* L)
{
	Pointer<CVariable>* self = (Pointer<CVariable>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVariable>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CVariable*)tolua_tousertype_dynamic(L, 2, 0, "CVariable"));
	return 0;
}

static int tolua_get_Pointer_CAIObjectType__reference(lua_State* L)
{
	Pointer<CAIObjectType>* self = (Pointer<CAIObjectType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAIObjectType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CAIObjectType");
	return 1;
}

static int tolua_set_Pointer_CAIObjectType__reference(lua_State* L)
{
	Pointer<CAIObjectType>* self = (Pointer<CAIObjectType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAIObjectType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CAIObjectType*)tolua_tousertype_dynamic(L, 2, 0, "CAIObjectType");
	return 0;
}

static int tolua_function_Pointer_CAIObjectType__setValue(lua_State* L)
{
	Pointer<CAIObjectType>* self = (Pointer<CAIObjectType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAIObjectType>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CAIObjectType*)tolua_tousertype_dynamic(L, 2, 0, "CAIObjectType"));
	return 0;
}

static int tolua_get_Pointer_CAIAction__reference(lua_State* L)
{
	Pointer<CAIAction>* self = (Pointer<CAIAction>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAIAction>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CAIAction");
	return 1;
}

static int tolua_set_Pointer_CAIAction__reference(lua_State* L)
{
	Pointer<CAIAction>* self = (Pointer<CAIAction>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAIAction>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CAIAction*)tolua_tousertype_dynamic(L, 2, 0, "CAIAction");
	return 0;
}

static int tolua_function_Pointer_CAIAction__setValue(lua_State* L)
{
	Pointer<CAIAction>* self = (Pointer<CAIAction>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAIAction>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CAIAction*)tolua_tousertype_dynamic(L, 2, 0, "CAIAction"));
	return 0;
}

static int tolua_get_Pointer_CProjectile__vtbl__reference(lua_State* L)
{
	Pointer<CProjectile::vtbl>* self = (Pointer<CProjectile::vtbl>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectile::vtbl>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CProjectile::vtbl");
	return 1;
}

static int tolua_set_Pointer_CProjectile__vtbl__reference(lua_State* L)
{
	Pointer<CProjectile::vtbl>* self = (Pointer<CProjectile::vtbl>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectile::vtbl>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CProjectile::vtbl*)tolua_tousertype_dynamic(L, 2, 0, "CProjectile::vtbl");
	return 0;
}

static int tolua_function_Pointer_CProjectile__vtbl__setValue(lua_State* L)
{
	Pointer<CProjectile::vtbl>* self = (Pointer<CProjectile::vtbl>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectile::vtbl>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CProjectile::vtbl*)tolua_tousertype_dynamic(L, 2, 0, "CProjectile::vtbl"));
	return 0;
}

static int tolua_get_Pointer_CProjectileBAM__vtbl__reference(lua_State* L)
{
	Pointer<CProjectileBAM::vtbl>* self = (Pointer<CProjectileBAM::vtbl>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileBAM::vtbl>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CProjectileBAM::vtbl");
	return 1;
}

static int tolua_set_Pointer_CProjectileBAM__vtbl__reference(lua_State* L)
{
	Pointer<CProjectileBAM::vtbl>* self = (Pointer<CProjectileBAM::vtbl>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileBAM::vtbl>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CProjectileBAM::vtbl*)tolua_tousertype_dynamic(L, 2, 0, "CProjectileBAM::vtbl");
	return 0;
}

static int tolua_function_Pointer_CProjectileBAM__vtbl__setValue(lua_State* L)
{
	Pointer<CProjectileBAM::vtbl>* self = (Pointer<CProjectileBAM::vtbl>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileBAM::vtbl>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CProjectileBAM::vtbl*)tolua_tousertype_dynamic(L, 2, 0, "CProjectileBAM::vtbl"));
	return 0;
}

static int tolua_get_Pointer_CProjectileBAM__reference(lua_State* L)
{
	Pointer<CProjectileBAM>* self = (Pointer<CProjectileBAM>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileBAM>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CProjectileBAM");
	return 1;
}

static int tolua_set_Pointer_CProjectileBAM__reference(lua_State* L)
{
	Pointer<CProjectileBAM>* self = (Pointer<CProjectileBAM>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileBAM>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CProjectileBAM*)tolua_tousertype_dynamic(L, 2, 0, "CProjectileBAM");
	return 0;
}

static int tolua_function_Pointer_CProjectileBAM__setValue(lua_State* L)
{
	Pointer<CProjectileBAM>* self = (Pointer<CProjectileBAM>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileBAM>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CProjectileBAM*)tolua_tousertype_dynamic(L, 2, 0, "CProjectileBAM"));
	return 0;
}

static int tolua_get_Pointer_CProjectileArea__reference(lua_State* L)
{
	Pointer<CProjectileArea>* self = (Pointer<CProjectileArea>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileArea>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CProjectileArea");
	return 1;
}

static int tolua_set_Pointer_CProjectileArea__reference(lua_State* L)
{
	Pointer<CProjectileArea>* self = (Pointer<CProjectileArea>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileArea>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CProjectileArea*)tolua_tousertype_dynamic(L, 2, 0, "CProjectileArea");
	return 0;
}

static int tolua_function_Pointer_CProjectileArea__setValue(lua_State* L)
{
	Pointer<CProjectileArea>* self = (Pointer<CProjectileArea>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileArea>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CProjectileArea*)tolua_tousertype_dynamic(L, 2, 0, "CProjectileArea"));
	return 0;
}

static int tolua_get_Pointer_CProjectileUnknownPST__reference(lua_State* L)
{
	Pointer<CProjectileUnknownPST>* self = (Pointer<CProjectileUnknownPST>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CProjectileUnknownPST");
	return 1;
}

static int tolua_set_Pointer_CProjectileUnknownPST__reference(lua_State* L)
{
	Pointer<CProjectileUnknownPST>* self = (Pointer<CProjectileUnknownPST>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 2, 0, "CProjectileUnknownPST");
	return 0;
}

static int tolua_function_Pointer_CProjectileUnknownPST__setValue(lua_State* L)
{
	Pointer<CProjectileUnknownPST>* self = (Pointer<CProjectileUnknownPST>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 2, 0, "CProjectileUnknownPST"));
	return 0;
}

static int tolua_get_Pointer_CProjectileUnknownPST2____reference(lua_State* L)
{
	Pointer<CProjectileUnknownPST2**>* self = (Pointer<CProjectileUnknownPST2**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST2**>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CProjectileUnknownPST2*>");
	return 1;
}

static int tolua_set_Pointer_CProjectileUnknownPST2____reference(lua_State* L)
{
	Pointer<CProjectileUnknownPST2**>* self = (Pointer<CProjectileUnknownPST2**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST2**>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CProjectileUnknownPST2***)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CProjectileUnknownPST2*>");
	return 0;
}

static int tolua_function_Pointer_CProjectileUnknownPST2____getValue(lua_State* L)
{
	Pointer<CProjectileUnknownPST2**>* self = (Pointer<CProjectileUnknownPST2**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST2**>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CProjectileUnknownPST2** returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "Pointer<CProjectileUnknownPST2>");
	return 1;
}

static int tolua_function_Pointer_CProjectileUnknownPST2____setValue(lua_State* L)
{
	Pointer<CProjectileUnknownPST2**>* self = (Pointer<CProjectileUnknownPST2**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST2**>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CProjectileUnknownPST2**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CProjectileUnknownPST2>"));
	return 0;
}

static int tolua_get_Pointer_CProjectileUnknownBase__reference(lua_State* L)
{
	Pointer<CProjectileUnknownBase>* self = (Pointer<CProjectileUnknownBase>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownBase>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CProjectileUnknownBase");
	return 1;
}

static int tolua_set_Pointer_CProjectileUnknownBase__reference(lua_State* L)
{
	Pointer<CProjectileUnknownBase>* self = (Pointer<CProjectileUnknownBase>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownBase>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CProjectileUnknownBase*)tolua_tousertype_dynamic(L, 2, 0, "CProjectileUnknownBase");
	return 0;
}

static int tolua_function_Pointer_CProjectileUnknownBase__setValue(lua_State* L)
{
	Pointer<CProjectileUnknownBase>* self = (Pointer<CProjectileUnknownBase>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownBase>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CProjectileUnknownBase*)tolua_tousertype_dynamic(L, 2, 0, "CProjectileUnknownBase"));
	return 0;
}

static int tolua_get_Pointer_CProjectile205__reference(lua_State* L)
{
	Pointer<CProjectile205>* self = (Pointer<CProjectile205>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectile205>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CProjectile205");
	return 1;
}

static int tolua_set_Pointer_CProjectile205__reference(lua_State* L)
{
	Pointer<CProjectile205>* self = (Pointer<CProjectile205>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectile205>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CProjectile205*)tolua_tousertype_dynamic(L, 2, 0, "CProjectile205");
	return 0;
}

static int tolua_function_Pointer_CProjectile205__setValue(lua_State* L)
{
	Pointer<CProjectile205>* self = (Pointer<CProjectile205>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectile205>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CProjectile205*)tolua_tousertype_dynamic(L, 2, 0, "CProjectile205"));
	return 0;
}

static int tolua_get_Pointer_CAITrigger__reference(lua_State* L)
{
	Pointer<CAITrigger>* self = (Pointer<CAITrigger>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAITrigger>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CAITrigger");
	return 1;
}

static int tolua_set_Pointer_CAITrigger__reference(lua_State* L)
{
	Pointer<CAITrigger>* self = (Pointer<CAITrigger>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAITrigger>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CAITrigger*)tolua_tousertype_dynamic(L, 2, 0, "CAITrigger");
	return 0;
}

static int tolua_function_Pointer_CAITrigger__setValue(lua_State* L)
{
	Pointer<CAITrigger>* self = (Pointer<CAITrigger>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAITrigger>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CAITrigger*)tolua_tousertype_dynamic(L, 2, 0, "CAITrigger"));
	return 0;
}

static int tolua_get_Pointer_CMessageSetTrigger__reference(lua_State* L)
{
	Pointer<CMessageSetTrigger>* self = (Pointer<CMessageSetTrigger>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CMessageSetTrigger>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CMessageSetTrigger");
	return 1;
}

static int tolua_set_Pointer_CMessageSetTrigger__reference(lua_State* L)
{
	Pointer<CMessageSetTrigger>* self = (Pointer<CMessageSetTrigger>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CMessageSetTrigger>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CMessageSetTrigger*)tolua_tousertype_dynamic(L, 2, 0, "CMessageSetTrigger");
	return 0;
}

static int tolua_function_Pointer_CMessageSetTrigger__setValue(lua_State* L)
{
	Pointer<CMessageSetTrigger>* self = (Pointer<CMessageSetTrigger>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CMessageSetTrigger>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CMessageSetTrigger*)tolua_tousertype_dynamic(L, 2, 0, "CMessageSetTrigger"));
	return 0;
}

static int tolua_get_Pointer_CGameSprite__reference(lua_State* L)
{
	Pointer<CGameSprite>* self = (Pointer<CGameSprite>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameSprite>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CGameSprite");
	return 1;
}

static int tolua_set_Pointer_CGameSprite__reference(lua_State* L)
{
	Pointer<CGameSprite>* self = (Pointer<CGameSprite>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameSprite>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameSprite*)tolua_tousertype_dynamic(L, 2, 0, "CGameSprite");
	return 0;
}

static int tolua_function_Pointer_CGameSprite__setValue(lua_State* L)
{
	Pointer<CGameSprite>* self = (Pointer<CGameSprite>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameSprite>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(CGameSprite*)tolua_tousertype_dynamic(L, 2, 0, "CGameSprite"));
	return 0;
}

static int tolua_function_CharString_getChar(lua_State* L)
{
	CharString* self = (CharString*)tolua_tousertype_dynamic(L, 1, 0, "CharString");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getChar'", NULL);
	char returnVal = self->getChar(tolua_function_tointeger<size_t>(L, 2, "getChar"));
	lua_pushlstring(L, (const char*)&returnVal, 1);
	return 1;
}

static int tolua_function_CharString_setChar(lua_State* L)
{
	CharString* self = (CharString*)tolua_tousertype_dynamic(L, 1, 0, "CharString");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setChar'", NULL);
	self->setChar(tolua_function_tointeger<size_t>(L, 2, "setChar"), tolua_function_tochar(L, 3, "setChar"));
	return 0;
}

static int tolua_function_CharString_set(lua_State* L)
{
	CharString* self = (CharString*)tolua_tousertype_dynamic(L, 1, 0, "CharString");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tostring(L, 2, "set"));
	return 0;
}

static int tolua_function_CharString_setL(lua_State* L)
{
	CharString* self = (CharString*)tolua_tousertype_dynamic(L, 1, 0, "CharString");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setL'", NULL);
	self->setL(tolua_function_tostring(L, 2, "setL"), tolua_function_tointeger<size_t>(L, 3, "setL"));
	return 0;
}

static int tolua_function_CharString_write(lua_State* L)
{
	CharString* self = (CharString*)tolua_tousertype_dynamic(L, 1, 0, "CharString");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'write'", NULL);
	self->write(tolua_function_tostring(L, 2, "write"));
	return 0;
}

static int tolua_function_CharString_writeL(lua_State* L)
{
	CharString* self = (CharString*)tolua_tousertype_dynamic(L, 1, 0, "CharString");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'writeL'", NULL);
	self->writeL(tolua_function_tostring(L, 2, "writeL"), tolua_function_tointeger<size_t>(L, 3, "writeL"));
	return 0;
}

static int tolua_function_CharString_setReference(lua_State* L)
{
	CharString* self = (CharString*)tolua_tousertype_dynamic(L, 1, 0, "CharString");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setReference'", NULL);
	self->setReference((CharString*)tolua_tousertype_dynamic(L, 2, 0, "CharString"));
	return 0;
}

static int tolua_function_CharString_pointTo(lua_State* L)
{
	CharString* self = (CharString*)tolua_tousertype_dynamic(L, 1, 0, "CharString");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'pointTo'", NULL);
	self->pointTo(tolua_function_tointeger<uintptr_t>(L, 2, "pointTo"));
	return 0;
}

static int tolua_function_CharString_get(lua_State* L)
{
	CharString* self = (CharString*)tolua_tousertype_dynamic(L, 1, 0, "CharString");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'get'", NULL);
	char* returnVal = self->get();
	tolua_pushstring(L, (const char*)returnVal);
	return 1;
}

static int tolua_function_CharString_getL(lua_State* L)
{
	CharString* self = (CharString*)tolua_tousertype_dynamic(L, 1, 0, "CharString");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getL'", NULL);
	self->getL(L, tolua_function_tointeger<size_t>(L, 2, "getL"));
	return 1;
}

static int tolua_function_CharString_free(lua_State* L)
{
	CharString* self = (CharString*)tolua_tousertype_dynamic(L, 1, 0, "CharString");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'free'", NULL);
	self->free();
	return 0;
}

static int tolua_get_CString_m_pchData(lua_State* L)
{
	CString* self = (CString*)tolua_tousertype_dynamic(L, 1, 0, "CString");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pchData'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pchData, "CharString");
	return 1;
}

static int tolua_function_CObject_virtual_Destruct(lua_State* L)
{
	CObject* self = (CObject*)tolua_tousertype_dynamic(L, 1, 0, "CObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_Destruct'", NULL);
	self->virtual_Destruct();
	return 0;
}

static int tolua_get_CObject__vtbl_Destruct(lua_State* L)
{
	return 1;
}

static int tolua_set_CObject__vtbl_Destruct(lua_State* L)
{
	return 0;
}

static int tolua_get_CObject__vtbl_reference_Destruct(lua_State* L)
{
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_long__m_pNodeHead(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeHead'", NULL);
	tolua_pushusertype(L, (void*)self->m_pNodeHead, "CTypedPtrList<CPtrList,long>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_long__m_pNodeHead(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeHead'", NULL);
	self->m_pNodeHead = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,long>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_long__reference_m_pNodeHead(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeHead'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pNodeHead, "Pointer<CTypedPtrList<CPtrList,long>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_long__m_pNodeTail(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeTail'", NULL);
	tolua_pushusertype(L, (void*)self->m_pNodeTail, "CTypedPtrList<CPtrList,long>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_long__m_pNodeTail(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeTail'", NULL);
	self->m_pNodeTail = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,long>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_long__reference_m_pNodeTail(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeTail'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pNodeTail, "Pointer<CTypedPtrList<CPtrList,long>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_long__m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nCount);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_long__m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	self->m_nCount = tolua_setter_tointeger<int>(L, "m_nCount");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_long__reference_m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nCount, "Primitive<int>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_long__m_pNodeFree(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeFree'", NULL);
	tolua_pushusertype(L, (void*)self->m_pNodeFree, "CTypedPtrList<CPtrList,long>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_long__m_pNodeFree(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeFree'", NULL);
	self->m_pNodeFree = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,long>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_long__reference_m_pNodeFree(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeFree'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pNodeFree, "Pointer<CTypedPtrList<CPtrList,long>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_long__m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertype(L, (void*)self->m_pBlocks, "UnmappedUserType");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_long__m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	self->m_pBlocks = (void*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_long__reference_m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pBlocks, "VoidPointer");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_long__m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nBlockSize);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_long__m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	self->m_nBlockSize = tolua_setter_tointeger<int>(L, "m_nBlockSize");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_long__reference_m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nBlockSize, "Primitive<int>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_long___CNode_pNext(lua_State* L)
{
	CTypedPtrList<CPtrList,long>::CNode* self = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pNext'", NULL);
	tolua_pushusertype(L, (void*)self->pNext, "CTypedPtrList<CPtrList,long>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_long___CNode_pNext(lua_State* L)
{
	CTypedPtrList<CPtrList,long>::CNode* self = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pNext'", NULL);
	self->pNext = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,long>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_long___CNode_reference_pNext(lua_State* L)
{
	CTypedPtrList<CPtrList,long>::CNode* self = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pNext'", NULL);
	tolua_pushusertype(L, (void*)&self->pNext, "Pointer<CTypedPtrList<CPtrList,long>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_long___CNode_pPrev(lua_State* L)
{
	CTypedPtrList<CPtrList,long>::CNode* self = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pPrev'", NULL);
	tolua_pushusertype(L, (void*)self->pPrev, "CTypedPtrList<CPtrList,long>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_long___CNode_pPrev(lua_State* L)
{
	CTypedPtrList<CPtrList,long>::CNode* self = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pPrev'", NULL);
	self->pPrev = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,long>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_long___CNode_reference_pPrev(lua_State* L)
{
	CTypedPtrList<CPtrList,long>::CNode* self = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pPrev'", NULL);
	tolua_pushusertype(L, (void*)&self->pPrev, "Pointer<CTypedPtrList<CPtrList,long>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_long___CNode_data(lua_State* L)
{
	CTypedPtrList<CPtrList,long>::CNode* self = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	lua_pushinteger(L, (lua_Integer)self->data);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_long___CNode_data(lua_State* L)
{
	CTypedPtrList<CPtrList,long>::CNode* self = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	self->data = tolua_setter_tointeger<long>(L, "data");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_long___CNode_reference_data(lua_State* L)
{
	CTypedPtrList<CPtrList,long>::CNode* self = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	tolua_pushusertype(L, (void*)&self->data, "Primitive<long>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect___m_pNodeHead(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeHead'", NULL);
	tolua_pushusertype(L, (void*)self->m_pNodeHead, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_CGameEffect___m_pNodeHead(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeHead'", NULL);
	self->m_pNodeHead = (CTypedPtrList<CPtrList,CGameEffect*>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect___reference_m_pNodeHead(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeHead'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pNodeHead, "Pointer<CTypedPtrList<CPtrList,CGameEffect*>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect___m_pNodeTail(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeTail'", NULL);
	tolua_pushusertype(L, (void*)self->m_pNodeTail, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_CGameEffect___m_pNodeTail(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeTail'", NULL);
	self->m_pNodeTail = (CTypedPtrList<CPtrList,CGameEffect*>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect___reference_m_pNodeTail(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeTail'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pNodeTail, "Pointer<CTypedPtrList<CPtrList,CGameEffect*>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect___m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nCount);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_CGameEffect___m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	self->m_nCount = tolua_setter_tointeger<int>(L, "m_nCount");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect___reference_m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nCount, "Primitive<int>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect___m_pNodeFree(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeFree'", NULL);
	tolua_pushusertype(L, (void*)self->m_pNodeFree, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_CGameEffect___m_pNodeFree(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeFree'", NULL);
	self->m_pNodeFree = (CTypedPtrList<CPtrList,CGameEffect*>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect___reference_m_pNodeFree(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeFree'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pNodeFree, "Pointer<CTypedPtrList<CPtrList,CGameEffect*>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect___m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertype(L, (void*)self->m_pBlocks, "UnmappedUserType");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_CGameEffect___m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	self->m_pBlocks = (void*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect___reference_m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pBlocks, "VoidPointer");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect___m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nBlockSize);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_CGameEffect___m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	self->m_nBlockSize = tolua_setter_tointeger<int>(L, "m_nBlockSize");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect___reference_m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>* self = (CTypedPtrList<CPtrList,CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nBlockSize, "Primitive<int>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect____CNode_pNext(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>::CNode* self = (CTypedPtrList<CPtrList,CGameEffect*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pNext'", NULL);
	tolua_pushusertype(L, (void*)self->pNext, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_CGameEffect____CNode_pNext(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>::CNode* self = (CTypedPtrList<CPtrList,CGameEffect*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pNext'", NULL);
	self->pNext = (CTypedPtrList<CPtrList,CGameEffect*>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect____CNode_reference_pNext(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>::CNode* self = (CTypedPtrList<CPtrList,CGameEffect*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pNext'", NULL);
	tolua_pushusertype(L, (void*)&self->pNext, "Pointer<CTypedPtrList<CPtrList,CGameEffect*>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect____CNode_pPrev(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>::CNode* self = (CTypedPtrList<CPtrList,CGameEffect*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pPrev'", NULL);
	tolua_pushusertype(L, (void*)self->pPrev, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_CGameEffect____CNode_pPrev(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>::CNode* self = (CTypedPtrList<CPtrList,CGameEffect*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pPrev'", NULL);
	self->pPrev = (CTypedPtrList<CPtrList,CGameEffect*>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect____CNode_reference_pPrev(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>::CNode* self = (CTypedPtrList<CPtrList,CGameEffect*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pPrev'", NULL);
	tolua_pushusertype(L, (void*)&self->pPrev, "Pointer<CTypedPtrList<CPtrList,CGameEffect*>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect____CNode_data(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>::CNode* self = (CTypedPtrList<CPtrList,CGameEffect*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	tolua_pushusertype(L, (void*)self->data, "CGameEffect");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_CGameEffect____CNode_data(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>::CNode* self = (CTypedPtrList<CPtrList,CGameEffect*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	self->data = (CGameEffect*)tolua_tousertype_dynamic(L, 2, 0, "CGameEffect");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_CGameEffect____CNode_reference_data(lua_State* L)
{
	CTypedPtrList<CPtrList,CGameEffect*>::CNode* self = (CTypedPtrList<CPtrList,CGameEffect*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	tolua_pushusertype(L, (void*)&self->data, "Pointer<CGameEffect>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int___m_pNodeHead(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeHead'", NULL);
	tolua_pushusertype(L, (void*)self->m_pNodeHead, "CTypedPtrList<CPtrList,int*>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int___m_pNodeHead(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeHead'", NULL);
	self->m_pNodeHead = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int___reference_m_pNodeHead(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeHead'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pNodeHead, "Pointer<CTypedPtrList<CPtrList,int*>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int___m_pNodeTail(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeTail'", NULL);
	tolua_pushusertype(L, (void*)self->m_pNodeTail, "CTypedPtrList<CPtrList,int*>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int___m_pNodeTail(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeTail'", NULL);
	self->m_pNodeTail = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int___reference_m_pNodeTail(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeTail'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pNodeTail, "Pointer<CTypedPtrList<CPtrList,int*>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int___m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nCount);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int___m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	self->m_nCount = tolua_setter_tointeger<int>(L, "m_nCount");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int___reference_m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nCount, "Primitive<int>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int___m_pNodeFree(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeFree'", NULL);
	tolua_pushusertype(L, (void*)self->m_pNodeFree, "CTypedPtrList<CPtrList,int*>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int___m_pNodeFree(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeFree'", NULL);
	self->m_pNodeFree = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int___reference_m_pNodeFree(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeFree'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pNodeFree, "Pointer<CTypedPtrList<CPtrList,int*>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int___m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertype(L, (void*)self->m_pBlocks, "UnmappedUserType");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int___m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	self->m_pBlocks = (void*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int___reference_m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pBlocks, "VoidPointer");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int___m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nBlockSize);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int___m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	self->m_nBlockSize = tolua_setter_tointeger<int>(L, "m_nBlockSize");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int___reference_m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nBlockSize, "Primitive<int>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int____CNode_pNext(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>::CNode* self = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pNext'", NULL);
	tolua_pushusertype(L, (void*)self->pNext, "CTypedPtrList<CPtrList,int*>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int____CNode_pNext(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>::CNode* self = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pNext'", NULL);
	self->pNext = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int____CNode_reference_pNext(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>::CNode* self = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pNext'", NULL);
	tolua_pushusertype(L, (void*)&self->pNext, "Pointer<CTypedPtrList<CPtrList,int*>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int____CNode_pPrev(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>::CNode* self = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pPrev'", NULL);
	tolua_pushusertype(L, (void*)self->pPrev, "CTypedPtrList<CPtrList,int*>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int____CNode_pPrev(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>::CNode* self = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pPrev'", NULL);
	self->pPrev = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int____CNode_reference_pPrev(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>::CNode* self = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pPrev'", NULL);
	tolua_pushusertype(L, (void*)&self->pPrev, "Pointer<CTypedPtrList<CPtrList,int*>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int____CNode_data(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>::CNode* self = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	tolua_pushusertype(L, (void*)self->data, "Primitive<int>");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int____CNode_data(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>::CNode* self = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	self->data = (int*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<int>");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int____CNode_reference_data(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>::CNode* self = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	tolua_pushusertype(L, (void*)&self->data, "Pointer<int>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int__m_pNodeHead(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeHead'", NULL);
	tolua_pushusertype(L, (void*)self->m_pNodeHead, "CTypedPtrList<CPtrList,int>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int__m_pNodeHead(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeHead'", NULL);
	self->m_pNodeHead = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,int>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int__reference_m_pNodeHead(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeHead'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pNodeHead, "Pointer<CTypedPtrList<CPtrList,int>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int__m_pNodeTail(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeTail'", NULL);
	tolua_pushusertype(L, (void*)self->m_pNodeTail, "CTypedPtrList<CPtrList,int>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int__m_pNodeTail(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeTail'", NULL);
	self->m_pNodeTail = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,int>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int__reference_m_pNodeTail(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeTail'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pNodeTail, "Pointer<CTypedPtrList<CPtrList,int>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int__m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nCount);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int__m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	self->m_nCount = tolua_setter_tointeger<int>(L, "m_nCount");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int__reference_m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nCount, "Primitive<int>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int__m_pNodeFree(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeFree'", NULL);
	tolua_pushusertype(L, (void*)self->m_pNodeFree, "CTypedPtrList<CPtrList,int>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int__m_pNodeFree(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeFree'", NULL);
	self->m_pNodeFree = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,int>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int__reference_m_pNodeFree(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pNodeFree'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pNodeFree, "Pointer<CTypedPtrList<CPtrList,int>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int__m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertype(L, (void*)self->m_pBlocks, "UnmappedUserType");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int__m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	self->m_pBlocks = (void*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int__reference_m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pBlocks, "VoidPointer");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int__m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nBlockSize);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int__m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	self->m_nBlockSize = tolua_setter_tointeger<int>(L, "m_nBlockSize");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int__reference_m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nBlockSize, "Primitive<int>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int___CNode_pNext(lua_State* L)
{
	CTypedPtrList<CPtrList,int>::CNode* self = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pNext'", NULL);
	tolua_pushusertype(L, (void*)self->pNext, "CTypedPtrList<CPtrList,int>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int___CNode_pNext(lua_State* L)
{
	CTypedPtrList<CPtrList,int>::CNode* self = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pNext'", NULL);
	self->pNext = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,int>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int___CNode_reference_pNext(lua_State* L)
{
	CTypedPtrList<CPtrList,int>::CNode* self = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pNext'", NULL);
	tolua_pushusertype(L, (void*)&self->pNext, "Pointer<CTypedPtrList<CPtrList,int>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int___CNode_pPrev(lua_State* L)
{
	CTypedPtrList<CPtrList,int>::CNode* self = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pPrev'", NULL);
	tolua_pushusertype(L, (void*)self->pPrev, "CTypedPtrList<CPtrList,int>::CNode");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int___CNode_pPrev(lua_State* L)
{
	CTypedPtrList<CPtrList,int>::CNode* self = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pPrev'", NULL);
	self->pPrev = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 2, 0, "CTypedPtrList<CPtrList,int>::CNode");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int___CNode_reference_pPrev(lua_State* L)
{
	CTypedPtrList<CPtrList,int>::CNode* self = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pPrev'", NULL);
	tolua_pushusertype(L, (void*)&self->pPrev, "Pointer<CTypedPtrList<CPtrList,int>::CNode>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int___CNode_data(lua_State* L)
{
	CTypedPtrList<CPtrList,int>::CNode* self = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	lua_pushinteger(L, (lua_Integer)self->data);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int___CNode_data(lua_State* L)
{
	CTypedPtrList<CPtrList,int>::CNode* self = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	self->data = tolua_setter_tointeger<int>(L, "data");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int___CNode_reference_data(lua_State* L)
{
	CTypedPtrList<CPtrList,int>::CNode* self = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	tolua_pushusertype(L, (void*)&self->data, "Primitive<int>");
	return 1;
}

static int tolua_get_CAreaTintOverride_vfptr(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'vfptr'", NULL);
	tolua_pushusertype(L, (void*)&self->vfptr, "dword");
	return 1;
}

static int tolua_get_CAreaTintOverride_pInfinity(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pInfinity'", NULL);
	tolua_pushusertype(L, (void*)self->pInfinity, "CInfinity");
	return 1;
}

static int tolua_set_CAreaTintOverride_pInfinity(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pInfinity'", NULL);
	self->pInfinity = (CInfinity*)tolua_tousertype_dynamic(L, 2, 0, "CInfinity");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_pInfinity(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pInfinity'", NULL);
	tolua_pushusertype(L, (void*)&self->pInfinity, "Pointer<CInfinity>");
	return 1;
}

static int tolua_get_CAreaTintOverride_pVidMode(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pVidMode'", NULL);
	tolua_pushusertype(L, (void*)self->pVidMode, "CVidMode");
	return 1;
}

static int tolua_set_CAreaTintOverride_pVidMode(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pVidMode'", NULL);
	self->pVidMode = (CVidMode*)tolua_tousertype_dynamic(L, 2, 0, "CVidMode");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_pVidMode(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pVidMode'", NULL);
	tolua_pushusertype(L, (void*)&self->pVidMode, "Pointer<CVidMode>");
	return 1;
}

static int tolua_get_CAreaTintOverride_nMode(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nMode'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nMode);
	return 1;
}

static int tolua_set_CAreaTintOverride_nMode(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nMode'", NULL);
	self->nMode = tolua_setter_tointeger<byte>(L, "nMode");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_nMode(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nMode'", NULL);
	tolua_pushusertype(L, (void*)&self->nMode, "Primitive<byte>");
	return 1;
}

static int tolua_get_CAreaTintOverride_nBoundsInfringeCounter(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nBoundsInfringeCounter'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nBoundsInfringeCounter);
	return 1;
}

static int tolua_set_CAreaTintOverride_nBoundsInfringeCounter(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nBoundsInfringeCounter'", NULL);
	self->nBoundsInfringeCounter = tolua_setter_tointeger<uint>(L, "nBoundsInfringeCounter");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_nBoundsInfringeCounter(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nBoundsInfringeCounter'", NULL);
	tolua_pushusertype(L, (void*)&self->nBoundsInfringeCounter, "Primitive<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_nDuration(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDuration'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nDuration);
	return 1;
}

static int tolua_set_CAreaTintOverride_nDuration(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDuration'", NULL);
	self->nDuration = tolua_setter_tointeger<uint>(L, "nDuration");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_nDuration(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDuration'", NULL);
	tolua_pushusertype(L, (void*)&self->nDuration, "Primitive<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_tintMin(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'tintMin'", NULL);
	lua_pushinteger(L, (lua_Integer)self->tintMin);
	return 1;
}

static int tolua_set_CAreaTintOverride_tintMin(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'tintMin'", NULL);
	self->tintMin = tolua_setter_tointeger<uint>(L, "tintMin");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_tintMin(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'tintMin'", NULL);
	tolua_pushusertype(L, (void*)&self->tintMin, "Primitive<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_redMin(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'redMin'", NULL);
	lua_pushinteger(L, (lua_Integer)self->redMin);
	return 1;
}

static int tolua_set_CAreaTintOverride_redMin(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'redMin'", NULL);
	self->redMin = tolua_setter_tointeger<byte>(L, "redMin");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_redMin(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'redMin'", NULL);
	tolua_pushusertype(L, (void*)&self->redMin, "Primitive<byte>");
	return 1;
}

static int tolua_get_CAreaTintOverride_greenMin(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'greenMin'", NULL);
	lua_pushinteger(L, (lua_Integer)self->greenMin);
	return 1;
}

static int tolua_set_CAreaTintOverride_greenMin(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'greenMin'", NULL);
	self->greenMin = tolua_setter_tointeger<byte>(L, "greenMin");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_greenMin(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'greenMin'", NULL);
	tolua_pushusertype(L, (void*)&self->greenMin, "Primitive<byte>");
	return 1;
}

static int tolua_get_CAreaTintOverride_blueMin(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'blueMin'", NULL);
	lua_pushinteger(L, (lua_Integer)self->blueMin);
	return 1;
}

static int tolua_set_CAreaTintOverride_blueMin(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'blueMin'", NULL);
	self->blueMin = tolua_setter_tointeger<byte>(L, "blueMin");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_blueMin(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'blueMin'", NULL);
	tolua_pushusertype(L, (void*)&self->blueMin, "Primitive<byte>");
	return 1;
}

static int tolua_get_CAreaTintOverride_tintMax(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'tintMax'", NULL);
	lua_pushinteger(L, (lua_Integer)self->tintMax);
	return 1;
}

static int tolua_set_CAreaTintOverride_tintMax(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'tintMax'", NULL);
	self->tintMax = tolua_setter_tointeger<uint>(L, "tintMax");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_tintMax(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'tintMax'", NULL);
	tolua_pushusertype(L, (void*)&self->tintMax, "Primitive<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_redMax(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'redMax'", NULL);
	lua_pushinteger(L, (lua_Integer)self->redMax);
	return 1;
}

static int tolua_set_CAreaTintOverride_redMax(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'redMax'", NULL);
	self->redMax = tolua_setter_tointeger<byte>(L, "redMax");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_redMax(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'redMax'", NULL);
	tolua_pushusertype(L, (void*)&self->redMax, "Primitive<byte>");
	return 1;
}

static int tolua_get_CAreaTintOverride_greenMax(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'greenMax'", NULL);
	lua_pushinteger(L, (lua_Integer)self->greenMax);
	return 1;
}

static int tolua_set_CAreaTintOverride_greenMax(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'greenMax'", NULL);
	self->greenMax = tolua_setter_tointeger<byte>(L, "greenMax");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_greenMax(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'greenMax'", NULL);
	tolua_pushusertype(L, (void*)&self->greenMax, "Primitive<byte>");
	return 1;
}

static int tolua_get_CAreaTintOverride_blueMax(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'blueMax'", NULL);
	lua_pushinteger(L, (lua_Integer)self->blueMax);
	return 1;
}

static int tolua_set_CAreaTintOverride_blueMax(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'blueMax'", NULL);
	self->blueMax = tolua_setter_tointeger<byte>(L, "blueMax");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_blueMax(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'blueMax'", NULL);
	tolua_pushusertype(L, (void*)&self->blueMax, "Primitive<byte>");
	return 1;
}

static int tolua_get_CAreaTintOverride_redStep(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'redStep'", NULL);
	lua_pushinteger(L, (lua_Integer)self->redStep);
	return 1;
}

static int tolua_set_CAreaTintOverride_redStep(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'redStep'", NULL);
	self->redStep = tolua_setter_tointeger<int>(L, "redStep");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_redStep(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'redStep'", NULL);
	tolua_pushusertype(L, (void*)&self->redStep, "Primitive<int>");
	return 1;
}

static int tolua_get_CAreaTintOverride_greenStep(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'greenStep'", NULL);
	lua_pushinteger(L, (lua_Integer)self->greenStep);
	return 1;
}

static int tolua_set_CAreaTintOverride_greenStep(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'greenStep'", NULL);
	self->greenStep = tolua_setter_tointeger<int>(L, "greenStep");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_greenStep(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'greenStep'", NULL);
	tolua_pushusertype(L, (void*)&self->greenStep, "Primitive<int>");
	return 1;
}

static int tolua_get_CAreaTintOverride_blueStep(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'blueStep'", NULL);
	lua_pushinteger(L, (lua_Integer)self->blueStep);
	return 1;
}

static int tolua_set_CAreaTintOverride_blueStep(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'blueStep'", NULL);
	self->blueStep = tolua_setter_tointeger<int>(L, "blueStep");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_blueStep(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'blueStep'", NULL);
	tolua_pushusertype(L, (void*)&self->blueStep, "Primitive<int>");
	return 1;
}

static int tolua_get_CAreaTintOverride_nStartingGlobalLighting(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nStartingGlobalLighting'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nStartingGlobalLighting);
	return 1;
}

static int tolua_set_CAreaTintOverride_nStartingGlobalLighting(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nStartingGlobalLighting'", NULL);
	self->nStartingGlobalLighting = tolua_setter_tointeger<uint>(L, "nStartingGlobalLighting");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_nStartingGlobalLighting(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nStartingGlobalLighting'", NULL);
	tolua_pushusertype(L, (void*)&self->nStartingGlobalLighting, "Primitive<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_curGlobalTintOverrideStep(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'curGlobalTintOverrideStep'", NULL);
	lua_pushinteger(L, (lua_Integer)self->curGlobalTintOverrideStep);
	return 1;
}

static int tolua_set_CAreaTintOverride_curGlobalTintOverrideStep(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'curGlobalTintOverrideStep'", NULL);
	self->curGlobalTintOverrideStep = tolua_setter_tointeger<uint>(L, "curGlobalTintOverrideStep");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_curGlobalTintOverrideStep(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'curGlobalTintOverrideStep'", NULL);
	tolua_pushusertype(L, (void*)&self->curGlobalTintOverrideStep, "Primitive<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_curGlobalTintRed(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'curGlobalTintRed'", NULL);
	lua_pushinteger(L, (lua_Integer)self->curGlobalTintRed);
	return 1;
}

static int tolua_set_CAreaTintOverride_curGlobalTintRed(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'curGlobalTintRed'", NULL);
	self->curGlobalTintRed = tolua_setter_tointeger<uint>(L, "curGlobalTintRed");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_curGlobalTintRed(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'curGlobalTintRed'", NULL);
	tolua_pushusertype(L, (void*)&self->curGlobalTintRed, "Primitive<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_curGlobalTintGreen(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'curGlobalTintGreen'", NULL);
	lua_pushinteger(L, (lua_Integer)self->curGlobalTintGreen);
	return 1;
}

static int tolua_set_CAreaTintOverride_curGlobalTintGreen(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'curGlobalTintGreen'", NULL);
	self->curGlobalTintGreen = tolua_setter_tointeger<uint>(L, "curGlobalTintGreen");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_curGlobalTintGreen(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'curGlobalTintGreen'", NULL);
	tolua_pushusertype(L, (void*)&self->curGlobalTintGreen, "Primitive<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_curGlobalTintBlue(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'curGlobalTintBlue'", NULL);
	lua_pushinteger(L, (lua_Integer)self->curGlobalTintBlue);
	return 1;
}

static int tolua_set_CAreaTintOverride_curGlobalTintBlue(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'curGlobalTintBlue'", NULL);
	self->curGlobalTintBlue = tolua_setter_tointeger<uint>(L, "curGlobalTintBlue");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_curGlobalTintBlue(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'curGlobalTintBlue'", NULL);
	tolua_pushusertype(L, (void*)&self->curGlobalTintBlue, "Primitive<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_targetType(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'targetType'", NULL);
	lua_pushinteger(L, (lua_Integer)self->targetType);
	return 1;
}

static int tolua_set_CAreaTintOverride_targetType(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'targetType'", NULL);
	self->targetType = tolua_setter_tointeger<byte>(L, "targetType");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_targetType(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'targetType'", NULL);
	tolua_pushusertype(L, (void*)&self->targetType, "Primitive<byte>");
	return 1;
}

static int tolua_get_CAreaTintOverride_nSourceId(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nSourceId'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nSourceId);
	return 1;
}

static int tolua_set_CAreaTintOverride_nSourceId(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nSourceId'", NULL);
	self->nSourceId = tolua_setter_tointeger<int>(L, "nSourceId");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_nSourceId(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nSourceId'", NULL);
	tolua_pushusertype(L, (void*)&self->nSourceId, "Primitive<int>");
	return 1;
}

static int tolua_get_CAreaTintOverride_bIgnoreMode0ResetOnBoundsInfringement(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bIgnoreMode0ResetOnBoundsInfringement'", NULL);
	lua_pushinteger(L, (lua_Integer)self->bIgnoreMode0ResetOnBoundsInfringement);
	return 1;
}

static int tolua_set_CAreaTintOverride_bIgnoreMode0ResetOnBoundsInfringement(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bIgnoreMode0ResetOnBoundsInfringement'", NULL);
	self->bIgnoreMode0ResetOnBoundsInfringement = tolua_setter_tointeger<int>(L, "bIgnoreMode0ResetOnBoundsInfringement");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_bIgnoreMode0ResetOnBoundsInfringement(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bIgnoreMode0ResetOnBoundsInfringement'", NULL);
	tolua_pushusertype(L, (void*)&self->bIgnoreMode0ResetOnBoundsInfringement, "Primitive<int>");
	return 1;
}

static int tolua_get_CAreaTintOverride_spritesWithSuppressedTintsList(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'spritesWithSuppressedTintsList'", NULL);
	tolua_pushusertype(L, (void*)&self->spritesWithSuppressedTintsList, "CTypedPtrList<CPtrList,int*>");
	return 1;
}

static int tolua_get_CGameArea_m_nCharacters(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCharacters'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nCharacters);
	return 1;
}

static int tolua_set_CGameArea_m_nCharacters(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCharacters'", NULL);
	self->m_nCharacters = tolua_setter_tointeger<byte>(L, "m_nCharacters");
	return 0;
}

static int tolua_get_CGameArea_reference_m_nCharacters(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCharacters'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nCharacters, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameArea_m_nInfravision(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nInfravision'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nInfravision);
	return 1;
}

static int tolua_set_CGameArea_m_nInfravision(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nInfravision'", NULL);
	self->m_nInfravision = tolua_setter_tointeger<byte>(L, "m_nInfravision");
	return 0;
}

static int tolua_get_CGameArea_reference_m_nInfravision(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nInfravision'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nInfravision, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameArea_m_bAreaLoaded(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bAreaLoaded'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bAreaLoaded);
	return 1;
}

static int tolua_set_CGameArea_m_bAreaLoaded(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bAreaLoaded'", NULL);
	self->m_bAreaLoaded = tolua_setter_tointeger<byte>(L, "m_bAreaLoaded");
	return 0;
}

static int tolua_get_CGameArea_reference_m_bAreaLoaded(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bAreaLoaded'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bAreaLoaded, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameArea_m_iPicked(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iPicked'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_iPicked);
	return 1;
}

static int tolua_set_CGameArea_m_iPicked(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iPicked'", NULL);
	self->m_iPicked = tolua_setter_tointeger<int>(L, "m_iPicked");
	return 0;
}

static int tolua_get_CGameArea_reference_m_iPicked(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iPicked'", NULL);
	tolua_pushusertype(L, (void*)&self->m_iPicked, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameArea_m_bPicked(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bPicked'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bPicked);
	return 1;
}

static int tolua_set_CGameArea_m_bPicked(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bPicked'", NULL);
	self->m_bPicked = tolua_setter_tointeger<int>(L, "m_bPicked");
	return 0;
}

static int tolua_get_CGameArea_reference_m_bPicked(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bPicked'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bPicked, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameArea_m_nToolTip(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nToolTip'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nToolTip);
	return 1;
}

static int tolua_set_CGameArea_m_nToolTip(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nToolTip'", NULL);
	self->m_nToolTip = tolua_setter_tointeger<int>(L, "m_nToolTip");
	return 0;
}

static int tolua_get_CGameArea_reference_m_nToolTip(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nToolTip'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nToolTip, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameArea_m_firstRender(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_firstRender'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_firstRender);
	return 1;
}

static int tolua_set_CGameArea_m_firstRender(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_firstRender'", NULL);
	self->m_firstRender = tolua_setter_tointeger<byte>(L, "m_firstRender");
	return 0;
}

static int tolua_get_CGameArea_reference_m_firstRender(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_firstRender'", NULL);
	tolua_pushusertype(L, (void*)&self->m_firstRender, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameArea_m_nAIIndex(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nAIIndex'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nAIIndex);
	return 1;
}

static int tolua_set_CGameArea_m_nAIIndex(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nAIIndex'", NULL);
	self->m_nAIIndex = tolua_setter_tointeger<long>(L, "m_nAIIndex");
	return 0;
}

static int tolua_get_CGameArea_reference_m_nAIIndex(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nAIIndex'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nAIIndex, "Primitive<long>");
	return 1;
}

static int tolua_get_CGameArea_m_cInfinity(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_cInfinity'", NULL);
	tolua_pushusertype(L, (void*)&self->m_cInfinity, "CInfinity");
	return 1;
}

static int tolua_get_CGameArea_m_lVertSort(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_lVertSort'", NULL);
	tolua_pushusertype(L, (void*)&self->m_lVertSort, "CTypedPtrList<CPtrList,int>");
	return 1;
}

static int tolua_get_CGameArea_m_nScreenFlash(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nScreenFlash'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nScreenFlash);
	return 1;
}

static int tolua_set_CGameArea_m_nScreenFlash(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nScreenFlash'", NULL);
	self->m_nScreenFlash = tolua_setter_tointeger<short>(L, "m_nScreenFlash");
	return 0;
}

static int tolua_get_CGameArea_reference_m_nScreenFlash(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nScreenFlash'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nScreenFlash, "Primitive<short>");
	return 1;
}

static int tolua_get_CGameArea_mpSpawner(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'mpSpawner'", NULL);
	tolua_pushusertype(L, (void*)self->mpSpawner, "UnmappedUserType");
	return 1;
}

static int tolua_set_CGameArea_mpSpawner(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'mpSpawner'", NULL);
	self->mpSpawner = (void*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType");
	return 0;
}

static int tolua_get_CGameArea_reference_mpSpawner(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'mpSpawner'", NULL);
	tolua_pushusertype(L, (void*)&self->mpSpawner, "VoidPointer");
	return 1;
}

static int tolua_get_CGameEffectList_m_posNext(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posNext'", NULL);
	tolua_pushusertype(L, (void*)self->m_posNext, "UnmappedUserType");
	return 1;
}

static int tolua_set_CGameEffectList_m_posNext(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posNext'", NULL);
	self->m_posNext = (void*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType");
	return 0;
}

static int tolua_get_CGameEffectList_reference_m_posNext(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posNext'", NULL);
	tolua_pushusertype(L, (void*)&self->m_posNext, "VoidPointer");
	return 1;
}

static int tolua_get_CGameEffectList_m_posCurrent(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posCurrent'", NULL);
	tolua_pushusertype(L, (void*)self->m_posCurrent, "UnmappedUserType");
	return 1;
}

static int tolua_set_CGameEffectList_m_posCurrent(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posCurrent'", NULL);
	self->m_posCurrent = (void*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType");
	return 0;
}

static int tolua_get_CGameEffectList_reference_m_posCurrent(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posCurrent'", NULL);
	tolua_pushusertype(L, (void*)&self->m_posCurrent, "VoidPointer");
	return 1;
}

static int tolua_get_CGameEffectList_m_newEffect(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_newEffect'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_newEffect);
	return 1;
}

static int tolua_set_CGameEffectList_m_newEffect(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_newEffect'", NULL);
	self->m_newEffect = tolua_setter_tointeger<int>(L, "m_newEffect");
	return 0;
}

static int tolua_get_CGameEffectList_reference_m_newEffect(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_newEffect'", NULL);
	tolua_pushusertype(L, (void*)&self->m_newEffect, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameEffectList_m_retry(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_retry'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_retry);
	return 1;
}

static int tolua_set_CGameEffectList_m_retry(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_retry'", NULL);
	self->m_retry = tolua_setter_tointeger<int>(L, "m_retry");
	return 0;
}

static int tolua_get_CGameEffectList_reference_m_retry(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_retry'", NULL);
	tolua_pushusertype(L, (void*)&self->m_retry, "Primitive<int>");
	return 1;
}

static int tolua_function_Array_uchar_8__getReference(lua_State* L)
{
	Array<uchar,8>* self = (Array<uchar,8>*)tolua_tousertype_dynamic(L, 1, 0, "Array<uchar,8>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getReference'", NULL);
	uchar* returnVal = self->getReference(tolua_function_tointeger<size_t>(L, 2, "getReference"));
	tolua_pushusertype(L, (void*)returnVal, "uchar");
	return 1;
}

static int tolua_function_Array_uchar_8__set(lua_State* L)
{
	Array<uchar,8>* self = (Array<uchar,8>*)tolua_tousertype_dynamic(L, 1, 0, "Array<uchar,8>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tointeger<size_t>(L, 2, "set"), *(uchar*)tolua_tousertype_dynamic(L, 3, 0, "uchar"));
	return 0;
}

static int tolua_function_Array_CProjectileUnknownPST2__10__get(lua_State* L)
{
	Array<CProjectileUnknownPST2*,10>* self = (Array<CProjectileUnknownPST2*,10>*)tolua_tousertype_dynamic(L, 1, 0, "Array<CProjectileUnknownPST2*,10>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'get'", NULL);
	CProjectileUnknownPST2* returnVal = self->get(tolua_function_tointeger<size_t>(L, 2, "get"));
	tolua_pushusertype(L, (void*)returnVal, "CProjectileUnknownPST2");
	return 1;
}

static int tolua_function_Array_CProjectileUnknownPST2__10__getReference(lua_State* L)
{
	Array<CProjectileUnknownPST2*,10>* self = (Array<CProjectileUnknownPST2*,10>*)tolua_tousertype_dynamic(L, 1, 0, "Array<CProjectileUnknownPST2*,10>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getReference'", NULL);
	CProjectileUnknownPST2** returnVal = self->getReference(tolua_function_tointeger<size_t>(L, 2, "getReference"));
	tolua_pushusertype(L, (void*)returnVal, "Pointer<CProjectileUnknownPST2>");
	return 1;
}

static int tolua_function_Array_CProjectileUnknownPST2__10__set(lua_State* L)
{
	Array<CProjectileUnknownPST2*,10>* self = (Array<CProjectileUnknownPST2*,10>*)tolua_tousertype_dynamic(L, 1, 0, "Array<CProjectileUnknownPST2*,10>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tointeger<size_t>(L, 2, "set"), (CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 3, 0, "CProjectileUnknownPST2"));
	return 0;
}

static int tolua_function_Array_ulong_15__getReference(lua_State* L)
{
	Array<ulong,15>* self = (Array<ulong,15>*)tolua_tousertype_dynamic(L, 1, 0, "Array<ulong,15>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getReference'", NULL);
	ulong* returnVal = self->getReference(tolua_function_tointeger<size_t>(L, 2, "getReference"));
	tolua_pushusertype(L, (void*)returnVal, "ulong");
	return 1;
}

static int tolua_function_Array_ulong_15__set(lua_State* L)
{
	Array<ulong,15>* self = (Array<ulong,15>*)tolua_tousertype_dynamic(L, 1, 0, "Array<ulong,15>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tointeger<size_t>(L, 2, "set"), *(ulong*)tolua_tousertype_dynamic(L, 3, 0, "ulong"));
	return 0;
}

static int tolua_function_Array_char_32__get(lua_State* L)
{
	Array<char,32>* self = (Array<char,32>*)tolua_tousertype_dynamic(L, 1, 0, "Array<char,32>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'get'", NULL);
	char returnVal = self->get(tolua_function_tointeger<size_t>(L, 2, "get"));
	lua_pushlstring(L, (const char*)&returnVal, 1);
	return 1;
}

static int tolua_function_Array_char_32__set(lua_State* L)
{
	Array<char,32>* self = (Array<char,32>*)tolua_tousertype_dynamic(L, 1, 0, "Array<char,32>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tointeger<size_t>(L, 2, "set"), tolua_function_tochar(L, 3, "set"));
	return 0;
}

static int tolua_function_Array_CGameArea__12__get(lua_State* L)
{
	Array<CGameArea*,12>* self = (Array<CGameArea*,12>*)tolua_tousertype_dynamic(L, 1, 0, "Array<CGameArea*,12>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'get'", NULL);
	CGameArea* returnVal = self->get(tolua_function_tointeger<size_t>(L, 2, "get"));
	tolua_pushusertype(L, (void*)returnVal, "CGameArea");
	return 1;
}

static int tolua_function_Array_CGameArea__12__getReference(lua_State* L)
{
	Array<CGameArea*,12>* self = (Array<CGameArea*,12>*)tolua_tousertype_dynamic(L, 1, 0, "Array<CGameArea*,12>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getReference'", NULL);
	CGameArea** returnVal = self->getReference(tolua_function_tointeger<size_t>(L, 2, "getReference"));
	tolua_pushusertype(L, (void*)returnVal, "Pointer<CGameArea>");
	return 1;
}

static int tolua_function_Array_CGameArea__12__set(lua_State* L)
{
	Array<CGameArea*,12>* self = (Array<CGameArea*,12>*)tolua_tousertype_dynamic(L, 1, 0, "Array<CGameArea*,12>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tointeger<size_t>(L, 2, "set"), (CGameArea*)tolua_tousertype_dynamic(L, 3, 0, "CGameArea"));
	return 0;
}

static int tolua_function_Array_long_6__get(lua_State* L)
{
	Array<long,6>* self = (Array<long,6>*)tolua_tousertype_dynamic(L, 1, 0, "Array<long,6>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'get'", NULL);
	long returnVal = self->get(tolua_function_tointeger<size_t>(L, 2, "get"));
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Array_long_6__getReference(lua_State* L)
{
	Array<long,6>* self = (Array<long,6>*)tolua_tousertype_dynamic(L, 1, 0, "Array<long,6>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getReference'", NULL);
	long* returnVal = self->getReference(tolua_function_tointeger<size_t>(L, 2, "getReference"));
	tolua_pushusertype(L, (void*)returnVal, "Primitive<long>");
	return 1;
}

static int tolua_function_Array_long_6__set(lua_State* L)
{
	Array<long,6>* self = (Array<long,6>*)tolua_tousertype_dynamic(L, 1, 0, "Array<long,6>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tointeger<size_t>(L, 2, "set"), tolua_function_tointeger<long>(L, 3, "set"));
	return 0;
}

static int tolua_function_Array_ulong_8__getReference(lua_State* L)
{
	Array<ulong,8>* self = (Array<ulong,8>*)tolua_tousertype_dynamic(L, 1, 0, "Array<ulong,8>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getReference'", NULL);
	ulong* returnVal = self->getReference(tolua_function_tointeger<size_t>(L, 2, "getReference"));
	tolua_pushusertype(L, (void*)returnVal, "ulong");
	return 1;
}

static int tolua_function_Array_ulong_8__set(lua_State* L)
{
	Array<ulong,8>* self = (Array<ulong,8>*)tolua_tousertype_dynamic(L, 1, 0, "Array<ulong,8>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tointeger<size_t>(L, 2, "set"), *(ulong*)tolua_tousertype_dynamic(L, 3, 0, "ulong"));
	return 0;
}

static int tolua_function_Array_byte_5__get(lua_State* L)
{
	Array<byte,5>* self = (Array<byte,5>*)tolua_tousertype_dynamic(L, 1, 0, "Array<byte,5>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'get'", NULL);
	byte returnVal = self->get(tolua_function_tointeger<size_t>(L, 2, "get"));
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_Array_byte_5__getReference(lua_State* L)
{
	Array<byte,5>* self = (Array<byte,5>*)tolua_tousertype_dynamic(L, 1, 0, "Array<byte,5>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getReference'", NULL);
	byte* returnVal = self->getReference(tolua_function_tointeger<size_t>(L, 2, "getReference"));
	tolua_pushusertype(L, (void*)returnVal, "Primitive<byte>");
	return 1;
}

static int tolua_function_Array_byte_5__set(lua_State* L)
{
	Array<byte,5>* self = (Array<byte,5>*)tolua_tousertype_dynamic(L, 1, 0, "Array<byte,5>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tointeger<size_t>(L, 2, "set"), tolua_function_tointeger<byte>(L, 3, "set"));
	return 0;
}

static int tolua_function_LCharString_32__getChar(lua_State* L)
{
	LCharString<32>* self = (LCharString<32>*)tolua_tousertype_dynamic(L, 1, 0, "LCharString<32>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getChar'", NULL);
	char returnVal = self->getChar(tolua_function_tointeger<size_t>(L, 2, "getChar"));
	lua_pushlstring(L, (const char*)&returnVal, 1);
	return 1;
}

static int tolua_function_LCharString_32__setChar(lua_State* L)
{
	LCharString<32>* self = (LCharString<32>*)tolua_tousertype_dynamic(L, 1, 0, "LCharString<32>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setChar'", NULL);
	self->setChar(tolua_function_tointeger<size_t>(L, 2, "setChar"), tolua_function_tochar(L, 3, "setChar"));
	return 0;
}

static int tolua_function_LCharString_32__set(lua_State* L)
{
	LCharString<32>* self = (LCharString<32>*)tolua_tousertype_dynamic(L, 1, 0, "LCharString<32>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tostring(L, 2, "set"));
	return 0;
}

static int tolua_function_LCharString_32__get(lua_State* L)
{
	LCharString<32>* self = (LCharString<32>*)tolua_tousertype_dynamic(L, 1, 0, "LCharString<32>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'get'", NULL);
	self->get(L);
	return 1;
}

static int tolua_get_CResRef_m_resRef(lua_State* L)
{
	CResRef* self = (CResRef*)tolua_tousertype_dynamic(L, 1, 0, "CResRef");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_resRef'", NULL);
	tolua_pushusertype(L, (void*)&self->m_resRef, "Array<uchar,8>");
	return 1;
}

static int tolua_function_CResRef_get(lua_State* L)
{
	CResRef* self = (CResRef*)tolua_tousertype_dynamic(L, 1, 0, "CResRef");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'get'", NULL);
	self->get(L);
	return 1;
}

static int tolua_function_CResRef_set(lua_State* L)
{
	CResRef* self = (CResRef*)tolua_tousertype_dynamic(L, 1, 0, "CResRef");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tostring(L, 2, "set"));
	return 0;
}

static int tolua_function_CResRef_copy(lua_State* L)
{
	CResRef* self = (CResRef*)tolua_tousertype_dynamic(L, 1, 0, "CResRef");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'copy'", NULL);
	self->copy((CResRef*)tolua_tousertype_dynamic(L, 2, 0, "CResRef"));
	return 0;
}

static int tolua_get_Item_effect_st_effectID(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'effectID'", NULL);
	lua_pushinteger(L, (lua_Integer)self->effectID);
	return 1;
}

static int tolua_set_Item_effect_st_effectID(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'effectID'", NULL);
	self->effectID = tolua_setter_tointeger<ushort>(L, "effectID");
	return 0;
}

static int tolua_get_Item_effect_st_reference_effectID(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'effectID'", NULL);
	tolua_pushusertype(L, (void*)&self->effectID, "Primitive<ushort>");
	return 1;
}

static int tolua_get_Item_effect_st_targetType(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'targetType'", NULL);
	lua_pushinteger(L, (lua_Integer)self->targetType);
	return 1;
}

static int tolua_set_Item_effect_st_targetType(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'targetType'", NULL);
	self->targetType = tolua_setter_tointeger<byte>(L, "targetType");
	return 0;
}

static int tolua_get_Item_effect_st_reference_targetType(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'targetType'", NULL);
	tolua_pushusertype(L, (void*)&self->targetType, "Primitive<byte>");
	return 1;
}

static int tolua_get_Item_effect_st_spellLevel(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'spellLevel'", NULL);
	lua_pushinteger(L, (lua_Integer)self->spellLevel);
	return 1;
}

static int tolua_set_Item_effect_st_spellLevel(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'spellLevel'", NULL);
	self->spellLevel = tolua_setter_tointeger<byte>(L, "spellLevel");
	return 0;
}

static int tolua_get_Item_effect_st_reference_spellLevel(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'spellLevel'", NULL);
	tolua_pushusertype(L, (void*)&self->spellLevel, "Primitive<byte>");
	return 1;
}

static int tolua_get_Item_effect_st_effectAmount(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'effectAmount'", NULL);
	lua_pushinteger(L, (lua_Integer)self->effectAmount);
	return 1;
}

static int tolua_set_Item_effect_st_effectAmount(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'effectAmount'", NULL);
	self->effectAmount = tolua_setter_tointeger<int>(L, "effectAmount");
	return 0;
}

static int tolua_get_Item_effect_st_reference_effectAmount(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'effectAmount'", NULL);
	tolua_pushusertype(L, (void*)&self->effectAmount, "Primitive<int>");
	return 1;
}

static int tolua_get_Item_effect_st_dwFlags(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'dwFlags'", NULL);
	lua_pushinteger(L, (lua_Integer)self->dwFlags);
	return 1;
}

static int tolua_set_Item_effect_st_dwFlags(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'dwFlags'", NULL);
	self->dwFlags = tolua_setter_tointeger<uint>(L, "dwFlags");
	return 0;
}

static int tolua_get_Item_effect_st_reference_dwFlags(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'dwFlags'", NULL);
	tolua_pushusertype(L, (void*)&self->dwFlags, "Primitive<uint>");
	return 1;
}

static int tolua_get_Item_effect_st_durationType(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'durationType'", NULL);
	lua_pushinteger(L, (lua_Integer)self->durationType);
	return 1;
}

static int tolua_set_Item_effect_st_durationType(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'durationType'", NULL);
	self->durationType = tolua_setter_tointeger<ushort>(L, "durationType");
	return 0;
}

static int tolua_get_Item_effect_st_reference_durationType(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'durationType'", NULL);
	tolua_pushusertype(L, (void*)&self->durationType, "Primitive<ushort>");
	return 1;
}

static int tolua_get_Item_effect_st_duration(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'duration'", NULL);
	lua_pushinteger(L, (lua_Integer)self->duration);
	return 1;
}

static int tolua_set_Item_effect_st_duration(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'duration'", NULL);
	self->duration = tolua_setter_tointeger<uint>(L, "duration");
	return 0;
}

static int tolua_get_Item_effect_st_reference_duration(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'duration'", NULL);
	tolua_pushusertype(L, (void*)&self->duration, "Primitive<uint>");
	return 1;
}

static int tolua_get_Item_effect_st_probabilityUpper(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'probabilityUpper'", NULL);
	lua_pushinteger(L, (lua_Integer)self->probabilityUpper);
	return 1;
}

static int tolua_set_Item_effect_st_probabilityUpper(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'probabilityUpper'", NULL);
	self->probabilityUpper = tolua_setter_tointeger<byte>(L, "probabilityUpper");
	return 0;
}

static int tolua_get_Item_effect_st_reference_probabilityUpper(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'probabilityUpper'", NULL);
	tolua_pushusertype(L, (void*)&self->probabilityUpper, "Primitive<byte>");
	return 1;
}

static int tolua_get_Item_effect_st_probabilityLower(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'probabilityLower'", NULL);
	lua_pushinteger(L, (lua_Integer)self->probabilityLower);
	return 1;
}

static int tolua_set_Item_effect_st_probabilityLower(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'probabilityLower'", NULL);
	self->probabilityLower = tolua_setter_tointeger<byte>(L, "probabilityLower");
	return 0;
}

static int tolua_get_Item_effect_st_reference_probabilityLower(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'probabilityLower'", NULL);
	tolua_pushusertype(L, (void*)&self->probabilityLower, "Primitive<byte>");
	return 1;
}

static int tolua_get_Item_effect_st_res(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'res'", NULL);
	tolua_pushusertype(L, (void*)&self->res, "CResRef");
	return 1;
}

static int tolua_get_Item_effect_st_numDice(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'numDice'", NULL);
	lua_pushinteger(L, (lua_Integer)self->numDice);
	return 1;
}

static int tolua_set_Item_effect_st_numDice(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'numDice'", NULL);
	self->numDice = tolua_setter_tointeger<uint>(L, "numDice");
	return 0;
}

static int tolua_get_Item_effect_st_reference_numDice(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'numDice'", NULL);
	tolua_pushusertype(L, (void*)&self->numDice, "Primitive<uint>");
	return 1;
}

static int tolua_get_Item_effect_st_diceSize(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'diceSize'", NULL);
	lua_pushinteger(L, (lua_Integer)self->diceSize);
	return 1;
}

static int tolua_set_Item_effect_st_diceSize(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'diceSize'", NULL);
	self->diceSize = tolua_setter_tointeger<uint>(L, "diceSize");
	return 0;
}

static int tolua_get_Item_effect_st_reference_diceSize(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'diceSize'", NULL);
	tolua_pushusertype(L, (void*)&self->diceSize, "Primitive<uint>");
	return 1;
}

static int tolua_get_Item_effect_st_savingThrow(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'savingThrow'", NULL);
	lua_pushinteger(L, (lua_Integer)self->savingThrow);
	return 1;
}

static int tolua_set_Item_effect_st_savingThrow(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'savingThrow'", NULL);
	self->savingThrow = tolua_setter_tointeger<uint>(L, "savingThrow");
	return 0;
}

static int tolua_get_Item_effect_st_reference_savingThrow(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'savingThrow'", NULL);
	tolua_pushusertype(L, (void*)&self->savingThrow, "Primitive<uint>");
	return 1;
}

static int tolua_get_Item_effect_st_saveMod(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'saveMod'", NULL);
	lua_pushinteger(L, (lua_Integer)self->saveMod);
	return 1;
}

static int tolua_set_Item_effect_st_saveMod(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'saveMod'", NULL);
	self->saveMod = tolua_setter_tointeger<int>(L, "saveMod");
	return 0;
}

static int tolua_get_Item_effect_st_reference_saveMod(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'saveMod'", NULL);
	tolua_pushusertype(L, (void*)&self->saveMod, "Primitive<int>");
	return 1;
}

static int tolua_get_Item_effect_st_special(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'special'", NULL);
	lua_pushinteger(L, (lua_Integer)self->special);
	return 1;
}

static int tolua_set_Item_effect_st_special(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'special'", NULL);
	self->special = tolua_setter_tointeger<uint>(L, "special");
	return 0;
}

static int tolua_get_Item_effect_st_reference_special(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'special'", NULL);
	tolua_pushusertype(L, (void*)&self->special, "Primitive<uint>");
	return 1;
}

static int tolua_get_CResHelper_CResCell_1000__pRes(lua_State* L)
{
	CResHelper<CResCell,1000>* self = (CResHelper<CResCell,1000>*)tolua_tousertype_dynamic(L, 1, 0, "CResHelper<CResCell,1000>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pRes'", NULL);
	tolua_pushusertype(L, (void*)self->pRes, "CResCell");
	return 1;
}

static int tolua_set_CResHelper_CResCell_1000__pRes(lua_State* L)
{
	CResHelper<CResCell,1000>* self = (CResHelper<CResCell,1000>*)tolua_tousertype_dynamic(L, 1, 0, "CResHelper<CResCell,1000>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pRes'", NULL);
	self->pRes = (CResCell*)tolua_tousertype_dynamic(L, 2, 0, "CResCell");
	return 0;
}

static int tolua_get_CResHelper_CResCell_1000__reference_pRes(lua_State* L)
{
	CResHelper<CResCell,1000>* self = (CResHelper<CResCell,1000>*)tolua_tousertype_dynamic(L, 1, 0, "CResHelper<CResCell,1000>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pRes'", NULL);
	tolua_pushusertype(L, (void*)&self->pRes, "Pointer<CResCell>");
	return 1;
}

static int tolua_get_CResHelper_CResCell_1000__cResRef(lua_State* L)
{
	CResHelper<CResCell,1000>* self = (CResHelper<CResCell,1000>*)tolua_tousertype_dynamic(L, 1, 0, "CResHelper<CResCell,1000>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'cResRef'", NULL);
	tolua_pushusertype(L, (void*)&self->cResRef, "CResRef");
	return 1;
}

static int tolua_get_CVidCell_vidImage(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'vidImage'", NULL);
	tolua_pushusertype(L, (void*)&self->vidImage, "CVidImage");
	return 1;
}

static int tolua_get_CVidCell_resHelper(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'resHelper'", NULL);
	tolua_pushusertype(L, (void*)&self->resHelper, "CResHelper<CResCell,1000>");
	return 1;
}

static int tolua_get_CVidCell_m_nCurrentFrame(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCurrentFrame'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nCurrentFrame);
	return 1;
}

static int tolua_set_CVidCell_m_nCurrentFrame(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCurrentFrame'", NULL);
	self->m_nCurrentFrame = tolua_setter_tointeger<short>(L, "m_nCurrentFrame");
	return 0;
}

static int tolua_get_CVidCell_reference_m_nCurrentFrame(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCurrentFrame'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nCurrentFrame, "Primitive<short>");
	return 1;
}

static int tolua_get_CVidCell_m_nCurrentSequence(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCurrentSequence'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nCurrentSequence);
	return 1;
}

static int tolua_set_CVidCell_m_nCurrentSequence(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCurrentSequence'", NULL);
	self->m_nCurrentSequence = tolua_setter_tointeger<ushort>(L, "m_nCurrentSequence");
	return 0;
}

static int tolua_get_CVidCell_reference_m_nCurrentSequence(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCurrentSequence'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nCurrentSequence, "Primitive<ushort>");
	return 1;
}

static int tolua_get_CVidCell_m_nAnimType(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nAnimType'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nAnimType);
	return 1;
}

static int tolua_set_CVidCell_m_nAnimType(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nAnimType'", NULL);
	self->m_nAnimType = tolua_setter_tointeger<int>(L, "m_nAnimType");
	return 0;
}

static int tolua_get_CVidCell_reference_m_nAnimType(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nAnimType'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nAnimType, "Primitive<int>");
	return 1;
}

static int tolua_get_CVidCell_m_bPaletteChanged(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bPaletteChanged'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bPaletteChanged);
	return 1;
}

static int tolua_set_CVidCell_m_bPaletteChanged(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bPaletteChanged'", NULL);
	self->m_bPaletteChanged = tolua_setter_tointeger<int>(L, "m_bPaletteChanged");
	return 0;
}

static int tolua_get_CVidCell_reference_m_bPaletteChanged(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bPaletteChanged'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bPaletteChanged, "Primitive<int>");
	return 1;
}

static int tolua_get_CVidCell_m_pFrame(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pFrame'", NULL);
	tolua_pushusertype(L, (void*)self->m_pFrame, "UnmappedUserType");
	return 1;
}

static int tolua_set_CVidCell_m_pFrame(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pFrame'", NULL);
	self->m_pFrame = (void*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType");
	return 0;
}

static int tolua_get_CVidCell_reference_m_pFrame(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pFrame'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pFrame, "VoidPointer");
	return 1;
}

static int tolua_get_CVidCell_m_bShadowOn(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bShadowOn'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bShadowOn);
	return 1;
}

static int tolua_set_CVidCell_m_bShadowOn(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bShadowOn'", NULL);
	self->m_bShadowOn = tolua_setter_tointeger<byte>(L, "m_bShadowOn");
	return 0;
}

static int tolua_get_CVidCell_reference_m_bShadowOn(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bShadowOn'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bShadowOn, "Primitive<byte>");
	return 1;
}

static int tolua_get_CInfGame_m_worldTime(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_worldTime'", NULL);
	tolua_pushusertype(L, (void*)&self->m_worldTime, "EEex_CTimerWorld");
	return 1;
}

static int tolua_get_CInfGame_m_bGameLoaded(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bGameLoaded'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bGameLoaded);
	return 1;
}

static int tolua_set_CInfGame_m_bGameLoaded(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bGameLoaded'", NULL);
	self->m_bGameLoaded = tolua_setter_tointeger<int>(L, "m_bGameLoaded");
	return 0;
}

static int tolua_get_CInfGame_reference_m_bGameLoaded(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bGameLoaded'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bGameLoaded, "Primitive<int>");
	return 1;
}

static int tolua_get_CInfGame_m_bInDestroyGame(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bInDestroyGame'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bInDestroyGame);
	return 1;
}

static int tolua_set_CInfGame_m_bInDestroyGame(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bInDestroyGame'", NULL);
	self->m_bInDestroyGame = tolua_setter_tointeger<byte>(L, "m_bInDestroyGame");
	return 0;
}

static int tolua_get_CInfGame_reference_m_bInDestroyGame(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bInDestroyGame'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bInDestroyGame, "Primitive<byte>");
	return 1;
}

static int tolua_get_CInfGame_m_nState(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nState'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nState);
	return 1;
}

static int tolua_set_CInfGame_m_nState(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nState'", NULL);
	self->m_nState = tolua_setter_tointeger<short>(L, "m_nState");
	return 0;
}

static int tolua_get_CInfGame_reference_m_nState(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nState'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nState, "Primitive<short>");
	return 1;
}

static int tolua_get_CInfGame_m_iconCount(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iconCount'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_iconCount);
	return 1;
}

static int tolua_set_CInfGame_m_iconCount(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iconCount'", NULL);
	self->m_iconCount = tolua_setter_tointeger<int>(L, "m_iconCount");
	return 0;
}

static int tolua_get_CInfGame_reference_m_iconCount(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iconCount'", NULL);
	tolua_pushusertype(L, (void*)&self->m_iconCount, "Primitive<int>");
	return 1;
}

static int tolua_get_CInfGame_m_iconIndex(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iconIndex'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_iconIndex);
	return 1;
}

static int tolua_set_CInfGame_m_iconIndex(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iconIndex'", NULL);
	self->m_iconIndex = tolua_setter_tointeger<byte>(L, "m_iconIndex");
	return 0;
}

static int tolua_get_CInfGame_reference_m_iconIndex(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iconIndex'", NULL);
	tolua_pushusertype(L, (void*)&self->m_iconIndex, "Primitive<byte>");
	return 1;
}

static int tolua_get_CInfGame_m_tempCursor(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_tempCursor'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_tempCursor);
	return 1;
}

static int tolua_set_CInfGame_m_tempCursor(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_tempCursor'", NULL);
	self->m_tempCursor = tolua_setter_tointeger<byte>(L, "m_tempCursor");
	return 0;
}

static int tolua_get_CInfGame_reference_m_tempCursor(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_tempCursor'", NULL);
	tolua_pushusertype(L, (void*)&self->m_tempCursor, "Primitive<byte>");
	return 1;
}

static int tolua_get_CInfGame_m_visibleArea(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_visibleArea'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_visibleArea);
	return 1;
}

static int tolua_set_CInfGame_m_visibleArea(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_visibleArea'", NULL);
	self->m_visibleArea = tolua_setter_tointeger<byte>(L, "m_visibleArea");
	return 0;
}

static int tolua_get_CInfGame_reference_m_visibleArea(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_visibleArea'", NULL);
	tolua_pushusertype(L, (void*)&self->m_visibleArea, "Primitive<byte>");
	return 1;
}

static int tolua_get_CInfGame_m_gameAreas(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_gameAreas'", NULL);
	tolua_pushusertype(L, (void*)&self->m_gameAreas, "Array<CGameArea*,12>");
	return 1;
}

static int tolua_get_CInfGame_m_pGameAreaMaster(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pGameAreaMaster'", NULL);
	tolua_pushusertype(L, (void*)self->m_pGameAreaMaster, "CGameArea");
	return 1;
}

static int tolua_set_CInfGame_m_pGameAreaMaster(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pGameAreaMaster'", NULL);
	self->m_pGameAreaMaster = (CGameArea*)tolua_tousertype_dynamic(L, 2, 0, "CGameArea");
	return 0;
}

static int tolua_get_CInfGame_reference_m_pGameAreaMaster(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pGameAreaMaster'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pGameAreaMaster, "Pointer<CGameArea>");
	return 1;
}

static int tolua_get_CInfGame_m_characters(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_characters'", NULL);
	tolua_pushusertype(L, (void*)&self->m_characters, "Array<long,6>");
	return 1;
}

static int tolua_get_CInfGame_m_charactersPortrait(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_charactersPortrait'", NULL);
	tolua_pushusertype(L, (void*)&self->m_charactersPortrait, "Array<long,6>");
	return 1;
}

static int tolua_get_CInfGame_m_nCharacters(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCharacters'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nCharacters);
	return 1;
}

static int tolua_set_CInfGame_m_nCharacters(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCharacters'", NULL);
	self->m_nCharacters = tolua_setter_tointeger<short>(L, "m_nCharacters");
	return 0;
}

static int tolua_get_CInfGame_reference_m_nCharacters(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCharacters'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nCharacters, "Primitive<short>");
	return 1;
}

static int tolua_get_CInfGame_m_nTutorialState(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nTutorialState'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nTutorialState, "ulong");
	return 1;
}

static int tolua_get_CInfGame_m_searchRequestListEmpty(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_searchRequestListEmpty'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_searchRequestListEmpty);
	return 1;
}

static int tolua_set_CInfGame_m_searchRequestListEmpty(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_searchRequestListEmpty'", NULL);
	self->m_searchRequestListEmpty = tolua_setter_tointeger<int>(L, "m_searchRequestListEmpty");
	return 0;
}

static int tolua_get_CInfGame_reference_m_searchRequestListEmpty(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_searchRequestListEmpty'", NULL);
	tolua_pushusertype(L, (void*)&self->m_searchRequestListEmpty, "Primitive<int>");
	return 1;
}

static int tolua_get_CInfGame_m_currArmor(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currArmor'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_currArmor);
	return 1;
}

static int tolua_set_CInfGame_m_currArmor(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currArmor'", NULL);
	self->m_currArmor = tolua_setter_tointeger<short>(L, "m_currArmor");
	return 0;
}

static int tolua_get_CInfGame_reference_m_currArmor(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currArmor'", NULL);
	tolua_pushusertype(L, (void*)&self->m_currArmor, "Primitive<short>");
	return 1;
}

static int tolua_get_CInfGame_m_currAnimation(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currAnimation'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_currAnimation);
	return 1;
}

static int tolua_set_CInfGame_m_currAnimation(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currAnimation'", NULL);
	self->m_currAnimation = tolua_setter_tointeger<short>(L, "m_currAnimation");
	return 0;
}

static int tolua_get_CInfGame_reference_m_currAnimation(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currAnimation'", NULL);
	tolua_pushusertype(L, (void*)&self->m_currAnimation, "Primitive<short>");
	return 1;
}

static int tolua_get_CInfGame_m_gameTime(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_gameTime'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_gameTime);
	return 1;
}

static int tolua_set_CInfGame_m_gameTime(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_gameTime'", NULL);
	self->m_gameTime = tolua_setter_tointeger<uint>(L, "m_gameTime");
	return 0;
}

static int tolua_get_CInfGame_reference_m_gameTime(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_gameTime'", NULL);
	tolua_pushusertype(L, (void*)&self->m_gameTime, "Primitive<uint>");
	return 1;
}

static int tolua_get_CGameEffectBase_m_version(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_version'", NULL);
	tolua_pushusertype(L, (void*)&self->m_version, "CResRef");
	return 1;
}

static int tolua_get_CGameEffectBase_m_effectId(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectId'", NULL);
	tolua_pushusertype(L, (void*)&self->m_effectId, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_targetType(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetType'", NULL);
	tolua_pushusertype(L, (void*)&self->m_targetType, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_spellLevel(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_spellLevel'", NULL);
	tolua_pushusertype(L, (void*)&self->m_spellLevel, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_effectAmount(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_effectAmount);
	return 1;
}

static int tolua_set_CGameEffectBase_m_effectAmount(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount'", NULL);
	self->m_effectAmount = tolua_setter_tointeger<long>(L, "m_effectAmount");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_effectAmount(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount'", NULL);
	tolua_pushusertype(L, (void*)&self->m_effectAmount, "Primitive<long>");
	return 1;
}

static int tolua_get_CGameEffectBase_m_dWFlags(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_dWFlags'", NULL);
	tolua_pushusertype(L, (void*)&self->m_dWFlags, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_durationType(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_durationType'", NULL);
	tolua_pushusertype(L, (void*)&self->m_durationType, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_duration(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_duration'", NULL);
	tolua_pushusertype(L, (void*)&self->m_duration, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_probabilityUpper(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_probabilityUpper'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_probabilityUpper);
	return 1;
}

static int tolua_set_CGameEffectBase_m_probabilityUpper(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_probabilityUpper'", NULL);
	self->m_probabilityUpper = tolua_setter_tointeger<ushort>(L, "m_probabilityUpper");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_probabilityUpper(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_probabilityUpper'", NULL);
	tolua_pushusertype(L, (void*)&self->m_probabilityUpper, "Primitive<ushort>");
	return 1;
}

static int tolua_get_CGameEffectBase_m_probabilityLower(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_probabilityLower'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_probabilityLower);
	return 1;
}

static int tolua_set_CGameEffectBase_m_probabilityLower(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_probabilityLower'", NULL);
	self->m_probabilityLower = tolua_setter_tointeger<ushort>(L, "m_probabilityLower");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_probabilityLower(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_probabilityLower'", NULL);
	tolua_pushusertype(L, (void*)&self->m_probabilityLower, "Primitive<ushort>");
	return 1;
}

static int tolua_get_CGameEffectBase_m_res(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_res'", NULL);
	tolua_pushusertype(L, (void*)&self->m_res, "CResRef");
	return 1;
}

static int tolua_get_CGameEffectBase_m_numDice(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_numDice'", NULL);
	tolua_pushusertype(L, (void*)&self->m_numDice, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_diceSize(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_diceSize'", NULL);
	tolua_pushusertype(L, (void*)&self->m_diceSize, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_savingThrow(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_savingThrow'", NULL);
	tolua_pushusertype(L, (void*)&self->m_savingThrow, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_saveMod(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_saveMod'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_saveMod);
	return 1;
}

static int tolua_set_CGameEffectBase_m_saveMod(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_saveMod'", NULL);
	self->m_saveMod = tolua_setter_tointeger<long>(L, "m_saveMod");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_saveMod(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_saveMod'", NULL);
	tolua_pushusertype(L, (void*)&self->m_saveMod, "Primitive<long>");
	return 1;
}

static int tolua_get_CGameEffectBase_m_special(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_special'", NULL);
	tolua_pushusertype(L, (void*)&self->m_special, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_school(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_school'", NULL);
	tolua_pushusertype(L, (void*)&self->m_school, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_JeremyIsAnIdiot(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_JeremyIsAnIdiot'", NULL);
	tolua_pushusertype(L, (void*)&self->m_JeremyIsAnIdiot, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_minLevel(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_minLevel'", NULL);
	tolua_pushusertype(L, (void*)&self->m_minLevel, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_maxLevel(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_maxLevel'", NULL);
	tolua_pushusertype(L, (void*)&self->m_maxLevel, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_flags(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_flags'", NULL);
	tolua_pushusertype(L, (void*)&self->m_flags, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_effectAmount2(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount2'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_effectAmount2);
	return 1;
}

static int tolua_set_CGameEffectBase_m_effectAmount2(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount2'", NULL);
	self->m_effectAmount2 = tolua_setter_tointeger<long>(L, "m_effectAmount2");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_effectAmount2(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount2'", NULL);
	tolua_pushusertype(L, (void*)&self->m_effectAmount2, "Primitive<long>");
	return 1;
}

static int tolua_get_CGameEffectBase_m_effectAmount3(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount3'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_effectAmount3);
	return 1;
}

static int tolua_set_CGameEffectBase_m_effectAmount3(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount3'", NULL);
	self->m_effectAmount3 = tolua_setter_tointeger<long>(L, "m_effectAmount3");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_effectAmount3(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount3'", NULL);
	tolua_pushusertype(L, (void*)&self->m_effectAmount3, "Primitive<long>");
	return 1;
}

static int tolua_get_CGameEffectBase_m_effectAmount4(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount4'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_effectAmount4);
	return 1;
}

static int tolua_set_CGameEffectBase_m_effectAmount4(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount4'", NULL);
	self->m_effectAmount4 = tolua_setter_tointeger<long>(L, "m_effectAmount4");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_effectAmount4(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount4'", NULL);
	tolua_pushusertype(L, (void*)&self->m_effectAmount4, "Primitive<long>");
	return 1;
}

static int tolua_get_CGameEffectBase_m_effectAmount5(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount5'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_effectAmount5);
	return 1;
}

static int tolua_set_CGameEffectBase_m_effectAmount5(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount5'", NULL);
	self->m_effectAmount5 = tolua_setter_tointeger<long>(L, "m_effectAmount5");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_effectAmount5(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount5'", NULL);
	tolua_pushusertype(L, (void*)&self->m_effectAmount5, "Primitive<long>");
	return 1;
}

static int tolua_get_CGameEffectBase_m_res2(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_res2'", NULL);
	tolua_pushusertype(L, (void*)&self->m_res2, "CResRef");
	return 1;
}

static int tolua_get_CGameEffectBase_m_res3(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_res3'", NULL);
	tolua_pushusertype(L, (void*)&self->m_res3, "CResRef");
	return 1;
}

static int tolua_get_CGameEffectBase_m_source(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_source'", NULL);
	tolua_pushusertype(L, (void*)&self->m_source, "CPoint");
	return 1;
}

static int tolua_get_CGameEffectBase_m_target(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_target'", NULL);
	tolua_pushusertype(L, (void*)&self->m_target, "CPoint");
	return 1;
}

static int tolua_get_CGameEffectBase_m_sourceType(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceType'", NULL);
	tolua_pushusertype(L, (void*)&self->m_sourceType, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_sourceRes(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceRes'", NULL);
	tolua_pushusertype(L, (void*)&self->m_sourceRes, "CResRef");
	return 1;
}

static int tolua_get_CGameEffectBase_m_sourceFlags(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceFlags'", NULL);
	tolua_pushusertype(L, (void*)&self->m_sourceFlags, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_projectileType(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_projectileType'", NULL);
	tolua_pushusertype(L, (void*)&self->m_projectileType, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_slotNum(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_slotNum'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_slotNum);
	return 1;
}

static int tolua_set_CGameEffectBase_m_slotNum(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_slotNum'", NULL);
	self->m_slotNum = tolua_setter_tointeger<long>(L, "m_slotNum");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_slotNum(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_slotNum'", NULL);
	tolua_pushusertype(L, (void*)&self->m_slotNum, "Primitive<long>");
	return 1;
}

static int tolua_get_CGameEffectBase_m_scriptName(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_scriptName'", NULL);
	tolua_pushusertype(L, (void*)&self->m_scriptName, "LCharString<32>");
	return 1;
}

static int tolua_get_CGameEffectBase_m_casterLevel(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_casterLevel'", NULL);
	tolua_pushusertype(L, (void*)&self->m_casterLevel, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_firstCall(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_firstCall'", NULL);
	tolua_pushusertype(L, (void*)&self->m_firstCall, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_secondaryType(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_secondaryType'", NULL);
	tolua_pushusertype(L, (void*)&self->m_secondaryType, "ulong");
	return 1;
}

static int tolua_get_CGameEffectBase_m_pad(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pad'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pad, "Array<ulong,15>");
	return 1;
}

static int tolua_get_CGameEffect_m_sourceId(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_sourceId);
	return 1;
}

static int tolua_set_CGameEffect_m_sourceId(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	self->m_sourceId = tolua_setter_tointeger<long>(L, "m_sourceId");
	return 0;
}

static int tolua_get_CGameEffect_reference_m_sourceId(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	tolua_pushusertype(L, (void*)&self->m_sourceId, "Primitive<long>");
	return 1;
}

static int tolua_get_CGameEffect_m_done(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_done'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_done);
	return 1;
}

static int tolua_set_CGameEffect_m_done(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_done'", NULL);
	self->m_done = tolua_setter_tointeger<int>(L, "m_done");
	return 0;
}

static int tolua_get_CGameEffect_reference_m_done(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_done'", NULL);
	tolua_pushusertype(L, (void*)&self->m_done, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameEffect_m_forceRepass(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_forceRepass'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_forceRepass);
	return 1;
}

static int tolua_set_CGameEffect_m_forceRepass(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_forceRepass'", NULL);
	self->m_forceRepass = tolua_setter_tointeger<int>(L, "m_forceRepass");
	return 0;
}

static int tolua_get_CGameEffect_reference_m_forceRepass(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_forceRepass'", NULL);
	tolua_pushusertype(L, (void*)&self->m_forceRepass, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameEffect_m_durationTemp(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_durationTemp'", NULL);
	tolua_pushusertype(L, (void*)&self->m_durationTemp, "ulong");
	return 1;
}

static int tolua_get_CGameEffect_m_compareIdOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdOnly'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_compareIdOnly);
	return 1;
}

static int tolua_set_CGameEffect_m_compareIdOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdOnly'", NULL);
	self->m_compareIdOnly = tolua_setter_tointeger<int>(L, "m_compareIdOnly");
	return 0;
}

static int tolua_get_CGameEffect_reference_m_compareIdOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdOnly'", NULL);
	tolua_pushusertype(L, (void*)&self->m_compareIdOnly, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameEffect_m_compareIdAndFlagsOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndFlagsOnly'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_compareIdAndFlagsOnly);
	return 1;
}

static int tolua_set_CGameEffect_m_compareIdAndFlagsOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndFlagsOnly'", NULL);
	self->m_compareIdAndFlagsOnly = tolua_setter_tointeger<int>(L, "m_compareIdAndFlagsOnly");
	return 0;
}

static int tolua_get_CGameEffect_reference_m_compareIdAndFlagsOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndFlagsOnly'", NULL);
	tolua_pushusertype(L, (void*)&self->m_compareIdAndFlagsOnly, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameEffect_m_compareIdAndEffectAmountOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndEffectAmountOnly'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_compareIdAndEffectAmountOnly);
	return 1;
}

static int tolua_set_CGameEffect_m_compareIdAndEffectAmountOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndEffectAmountOnly'", NULL);
	self->m_compareIdAndEffectAmountOnly = tolua_setter_tointeger<int>(L, "m_compareIdAndEffectAmountOnly");
	return 0;
}

static int tolua_get_CGameEffect_reference_m_compareIdAndEffectAmountOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndEffectAmountOnly'", NULL);
	tolua_pushusertype(L, (void*)&self->m_compareIdAndEffectAmountOnly, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameEffect_m_compareIdAndResrefOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndResrefOnly'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_compareIdAndResrefOnly);
	return 1;
}

static int tolua_set_CGameEffect_m_compareIdAndResrefOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndResrefOnly'", NULL);
	self->m_compareIdAndResrefOnly = tolua_setter_tointeger<int>(L, "m_compareIdAndResrefOnly");
	return 0;
}

static int tolua_get_CGameEffect_reference_m_compareIdAndResrefOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndResrefOnly'", NULL);
	tolua_pushusertype(L, (void*)&self->m_compareIdAndResrefOnly, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameEffect_m_sound(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sound'", NULL);
	tolua_pushusertype(L, (void*)&self->m_sound, "CSound");
	return 1;
}

static int tolua_get_CGameEffect_m_sourceTarget(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceTarget'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_sourceTarget);
	return 1;
}

static int tolua_set_CGameEffect_m_sourceTarget(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceTarget'", NULL);
	self->m_sourceTarget = tolua_setter_tointeger<long>(L, "m_sourceTarget");
	return 0;
}

static int tolua_get_CGameEffect_reference_m_sourceTarget(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceTarget'", NULL);
	tolua_pushusertype(L, (void*)&self->m_sourceTarget, "Primitive<long>");
	return 1;
}

static int tolua_get_CGameEffect_unknownResRef(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownResRef'", NULL);
	tolua_pushusertype(L, (void*)&self->unknownResRef, "CResRef");
	return 1;
}

static int tolua_function_CGameEffect_DecodeEffect(lua_State* L)
{
	CGameEffect* returnVal = CGameEffect::DecodeEffect((Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st"), (const CPoint*)tolua_tousertype_dynamic(L, 2, 0, "CPoint"), tolua_function_tointeger<int>(L, 3, "DecodeEffect"), (const CPoint*)tolua_tousertype_dynamic(L, 4, 0, "CPoint"), tolua_function_tointeger<int>(L, 5, "DecodeEffect"));
	tolua_pushusertype(L, (void*)returnVal, "CGameEffect");
	return 1;
}

static int tolua_get_reference_CGameEffect_DecodeEffect(lua_State* L)
{
	tolua_pushusertype(L, CGameEffect::DecodeEffect, "UnmappedUserType");
	return 1;
}

static int tolua_get_CDerivedStats_m_generalState(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_generalState'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_generalState);
	return 1;
}

static int tolua_set_CDerivedStats_m_generalState(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_generalState'", NULL);
	self->m_generalState = tolua_setter_tointeger<uint>(L, "m_generalState");
	return 0;
}

static int tolua_get_CDerivedStats_reference_m_generalState(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_generalState'", NULL);
	tolua_pushusertype(L, (void*)&self->m_generalState, "Primitive<uint>");
	return 1;
}

static int tolua_get_CDerivedStats_m_nResistMagic(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nResistMagic'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nResistMagic);
	return 1;
}

static int tolua_set_CDerivedStats_m_nResistMagic(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nResistMagic'", NULL);
	self->m_nResistMagic = tolua_setter_tointeger<short>(L, "m_nResistMagic");
	return 0;
}

static int tolua_get_CDerivedStats_reference_m_nResistMagic(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nResistMagic'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nResistMagic, "Primitive<short>");
	return 1;
}

static int tolua_get_CDerivedStats_m_nLuck(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nLuck'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nLuck);
	return 1;
}

static int tolua_set_CDerivedStats_m_nLuck(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nLuck'", NULL);
	self->m_nLuck = tolua_setter_tointeger<short>(L, "m_nLuck");
	return 0;
}

static int tolua_get_CDerivedStats_reference_m_nLuck(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nLuck'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nLuck, "Primitive<short>");
	return 1;
}

static int tolua_get_CDerivedStats_m_nTurnUndeadLevel(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nTurnUndeadLevel'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nTurnUndeadLevel);
	return 1;
}

static int tolua_set_CDerivedStats_m_nTurnUndeadLevel(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nTurnUndeadLevel'", NULL);
	self->m_nTurnUndeadLevel = tolua_setter_tointeger<short>(L, "m_nTurnUndeadLevel");
	return 0;
}

static int tolua_get_CDerivedStats_reference_m_nTurnUndeadLevel(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nTurnUndeadLevel'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nTurnUndeadLevel, "Primitive<short>");
	return 1;
}

static int tolua_get_CDerivedStats_m_nBackstabDamageMultiplier(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBackstabDamageMultiplier'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nBackstabDamageMultiplier);
	return 1;
}

static int tolua_set_CDerivedStats_m_nBackstabDamageMultiplier(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBackstabDamageMultiplier'", NULL);
	self->m_nBackstabDamageMultiplier = tolua_setter_tointeger<short>(L, "m_nBackstabDamageMultiplier");
	return 0;
}

static int tolua_get_CDerivedStats_reference_m_nBackstabDamageMultiplier(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBackstabDamageMultiplier'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nBackstabDamageMultiplier, "Primitive<short>");
	return 1;
}

static int tolua_get_CDerivedStats_m_nLayOnHandsAmount(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nLayOnHandsAmount'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nLayOnHandsAmount);
	return 1;
}

static int tolua_set_CDerivedStats_m_nLayOnHandsAmount(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nLayOnHandsAmount'", NULL);
	self->m_nLayOnHandsAmount = tolua_setter_tointeger<short>(L, "m_nLayOnHandsAmount");
	return 0;
}

static int tolua_get_CDerivedStats_reference_m_nLayOnHandsAmount(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nLayOnHandsAmount'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nLayOnHandsAmount, "Primitive<short>");
	return 1;
}

static int tolua_get_CDerivedStats_m_appliedColorEffects(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_appliedColorEffects'", NULL);
	tolua_pushusertype(L, (void*)&self->m_appliedColorEffects, "CPtrList");
	return 1;
}

static int tolua_get_CDerivedStats_m_spellStates(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_spellStates'", NULL);
	tolua_pushusertype(L, (void*)&self->m_spellStates, "Array<ulong,8>");
	return 1;
}

static int tolua_get_CAreaVariable_m_name(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_name'", NULL);
	tolua_pushusertype(L, (void*)&self->m_name, "Array<char,32>");
	return 1;
}

static int tolua_get_CAreaVariable_m_type(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_type'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_type);
	return 1;
}

static int tolua_set_CAreaVariable_m_type(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_type'", NULL);
	self->m_type = tolua_setter_tointeger<ushort>(L, "m_type");
	return 0;
}

static int tolua_get_CAreaVariable_reference_m_type(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_type'", NULL);
	tolua_pushusertype(L, (void*)&self->m_type, "Primitive<ushort>");
	return 1;
}

static int tolua_get_CAreaVariable_m_resRefType(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_resRefType'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_resRefType);
	return 1;
}

static int tolua_set_CAreaVariable_m_resRefType(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_resRefType'", NULL);
	self->m_resRefType = tolua_setter_tointeger<ushort>(L, "m_resRefType");
	return 0;
}

static int tolua_get_CAreaVariable_reference_m_resRefType(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_resRefType'", NULL);
	tolua_pushusertype(L, (void*)&self->m_resRefType, "Primitive<ushort>");
	return 1;
}

static int tolua_get_CAreaVariable_m_dWValue(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_dWValue'", NULL);
	tolua_pushusertype(L, (void*)&self->m_dWValue, "ulong");
	return 1;
}

static int tolua_get_CAreaVariable_m_intValue(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_intValue'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_intValue);
	return 1;
}

static int tolua_set_CAreaVariable_m_intValue(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_intValue'", NULL);
	self->m_intValue = tolua_setter_tointeger<long>(L, "m_intValue");
	return 0;
}

static int tolua_get_CAreaVariable_reference_m_intValue(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_intValue'", NULL);
	tolua_pushusertype(L, (void*)&self->m_intValue, "Primitive<long>");
	return 1;
}

static int tolua_get_CAreaVariable_m_floatValue(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_floatValue'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_floatValue);
	return 1;
}

static int tolua_set_CAreaVariable_m_floatValue(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_floatValue'", NULL);
	self->m_floatValue = tolua_setter_tonumber<double>(L, "m_floatValue");
	return 0;
}

static int tolua_get_CAreaVariable_reference_m_floatValue(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_floatValue'", NULL);
	tolua_pushusertype(L, (void*)&self->m_floatValue, "Primitive<double>");
	return 1;
}

static int tolua_get_CAreaVariable_m_stringValue(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_stringValue'", NULL);
	tolua_pushusertype(L, (void*)&self->m_stringValue, "Array<char,32>");
	return 1;
}

static int tolua_get_CAIObjectType_m_name(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_name'", NULL);
	tolua_pushusertype(L, (void*)&self->m_name, "CString");
	return 1;
}

static int tolua_get_CAIObjectType_m_EnemyAlly(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_EnemyAlly'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_EnemyAlly);
	return 1;
}

static int tolua_set_CAIObjectType_m_EnemyAlly(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_EnemyAlly'", NULL);
	self->m_EnemyAlly = tolua_setter_tointeger<byte>(L, "m_EnemyAlly");
	return 0;
}

static int tolua_get_CAIObjectType_reference_m_EnemyAlly(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_EnemyAlly'", NULL);
	tolua_pushusertype(L, (void*)&self->m_EnemyAlly, "Primitive<byte>");
	return 1;
}

static int tolua_get_CAIObjectType_m_General(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_General'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_General);
	return 1;
}

static int tolua_set_CAIObjectType_m_General(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_General'", NULL);
	self->m_General = tolua_setter_tointeger<byte>(L, "m_General");
	return 0;
}

static int tolua_get_CAIObjectType_reference_m_General(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_General'", NULL);
	tolua_pushusertype(L, (void*)&self->m_General, "Primitive<byte>");
	return 1;
}

static int tolua_get_CAIObjectType_m_Race(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Race'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_Race);
	return 1;
}

static int tolua_set_CAIObjectType_m_Race(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Race'", NULL);
	self->m_Race = tolua_setter_tointeger<byte>(L, "m_Race");
	return 0;
}

static int tolua_get_CAIObjectType_reference_m_Race(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Race'", NULL);
	tolua_pushusertype(L, (void*)&self->m_Race, "Primitive<byte>");
	return 1;
}

static int tolua_get_CAIObjectType_m_Class(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Class'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_Class);
	return 1;
}

static int tolua_set_CAIObjectType_m_Class(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Class'", NULL);
	self->m_Class = tolua_setter_tointeger<byte>(L, "m_Class");
	return 0;
}

static int tolua_get_CAIObjectType_reference_m_Class(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Class'", NULL);
	tolua_pushusertype(L, (void*)&self->m_Class, "Primitive<byte>");
	return 1;
}

static int tolua_get_CAIObjectType_m_Instance(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Instance'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_Instance);
	return 1;
}

static int tolua_set_CAIObjectType_m_Instance(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Instance'", NULL);
	self->m_Instance = tolua_setter_tointeger<int>(L, "m_Instance");
	return 0;
}

static int tolua_get_CAIObjectType_reference_m_Instance(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Instance'", NULL);
	tolua_pushusertype(L, (void*)&self->m_Instance, "Primitive<int>");
	return 1;
}

static int tolua_get_CAIObjectType_m_SpecialCase(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_SpecialCase'", NULL);
	tolua_pushusertype(L, (void*)&self->m_SpecialCase, "Array<byte,5>");
	return 1;
}

static int tolua_get_CAIObjectType_m_Specifics(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Specifics'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_Specifics);
	return 1;
}

static int tolua_set_CAIObjectType_m_Specifics(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Specifics'", NULL);
	self->m_Specifics = tolua_setter_tointeger<byte>(L, "m_Specifics");
	return 0;
}

static int tolua_get_CAIObjectType_reference_m_Specifics(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Specifics'", NULL);
	tolua_pushusertype(L, (void*)&self->m_Specifics, "Primitive<byte>");
	return 1;
}

static int tolua_get_CAIObjectType_m_Gender(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Gender'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_Gender);
	return 1;
}

static int tolua_set_CAIObjectType_m_Gender(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Gender'", NULL);
	self->m_Gender = tolua_setter_tointeger<byte>(L, "m_Gender");
	return 0;
}

static int tolua_get_CAIObjectType_reference_m_Gender(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Gender'", NULL);
	tolua_pushusertype(L, (void*)&self->m_Gender, "Primitive<byte>");
	return 1;
}

static int tolua_get_CAIObjectType_m_Alignment(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Alignment'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_Alignment);
	return 1;
}

static int tolua_set_CAIObjectType_m_Alignment(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Alignment'", NULL);
	self->m_Alignment = tolua_setter_tointeger<byte>(L, "m_Alignment");
	return 0;
}

static int tolua_get_CAIObjectType_reference_m_Alignment(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Alignment'", NULL);
	tolua_pushusertype(L, (void*)&self->m_Alignment, "Primitive<byte>");
	return 1;
}

static int tolua_get_CAIAction_m_actionID(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_actionID'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_actionID);
	return 1;
}

static int tolua_set_CAIAction_m_actionID(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_actionID'", NULL);
	self->m_actionID = tolua_setter_tointeger<short>(L, "m_actionID");
	return 0;
}

static int tolua_get_CAIAction_reference_m_actionID(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_actionID'", NULL);
	tolua_pushusertype(L, (void*)&self->m_actionID, "Primitive<short>");
	return 1;
}

static int tolua_get_CAIAction_m_actorID(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_actorID'", NULL);
	tolua_pushusertype(L, (void*)&self->m_actorID, "CAIObjectType");
	return 1;
}

static int tolua_get_CAIAction_m_acteeID(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_acteeID'", NULL);
	tolua_pushusertype(L, (void*)&self->m_acteeID, "CAIObjectType");
	return 1;
}

static int tolua_get_CAIAction_m_acteeID2(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_acteeID2'", NULL);
	tolua_pushusertype(L, (void*)&self->m_acteeID2, "CAIObjectType");
	return 1;
}

static int tolua_get_CAIAction_m_specificID(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specificID'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_specificID);
	return 1;
}

static int tolua_set_CAIAction_m_specificID(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specificID'", NULL);
	self->m_specificID = tolua_setter_tointeger<int>(L, "m_specificID");
	return 0;
}

static int tolua_get_CAIAction_reference_m_specificID(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specificID'", NULL);
	tolua_pushusertype(L, (void*)&self->m_specificID, "Primitive<int>");
	return 1;
}

static int tolua_get_CAIAction_m_specificID2(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specificID2'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_specificID2);
	return 1;
}

static int tolua_set_CAIAction_m_specificID2(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specificID2'", NULL);
	self->m_specificID2 = tolua_setter_tointeger<int>(L, "m_specificID2");
	return 0;
}

static int tolua_get_CAIAction_reference_m_specificID2(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specificID2'", NULL);
	tolua_pushusertype(L, (void*)&self->m_specificID2, "Primitive<int>");
	return 1;
}

static int tolua_get_CAIAction_m_specificID3(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specificID3'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_specificID3);
	return 1;
}

static int tolua_set_CAIAction_m_specificID3(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specificID3'", NULL);
	self->m_specificID3 = tolua_setter_tointeger<int>(L, "m_specificID3");
	return 0;
}

static int tolua_get_CAIAction_reference_m_specificID3(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specificID3'", NULL);
	tolua_pushusertype(L, (void*)&self->m_specificID3, "Primitive<int>");
	return 1;
}

static int tolua_get_CAIAction_m_string1(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_string1'", NULL);
	tolua_pushusertype(L, (void*)&self->m_string1, "CString");
	return 1;
}

static int tolua_get_CAIAction_m_string2(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_string2'", NULL);
	tolua_pushusertype(L, (void*)&self->m_string2, "CString");
	return 1;
}

static int tolua_get_CAIAction_m_dest(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_dest'", NULL);
	tolua_pushusertype(L, (void*)&self->m_dest, "CPoint");
	return 1;
}

static int tolua_get_CAIAction_m_internalFlags(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_internalFlags'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_internalFlags);
	return 1;
}

static int tolua_set_CAIAction_m_internalFlags(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_internalFlags'", NULL);
	self->m_internalFlags = tolua_setter_tointeger<uint>(L, "m_internalFlags");
	return 0;
}

static int tolua_get_CAIAction_reference_m_internalFlags(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_internalFlags'", NULL);
	tolua_pushusertype(L, (void*)&self->m_internalFlags, "Primitive<uint>");
	return 1;
}

static int tolua_get_CAIAction_m_source(lua_State* L)
{
	CAIAction* self = (CAIAction*)tolua_tousertype_dynamic(L, 1, 0, "CAIAction");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_source'", NULL);
	tolua_pushusertype(L, (void*)&self->m_source, "CString");
	return 1;
}

static int tolua_get_CGameObject_m_objectType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_objectType'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_objectType);
	return 1;
}

static int tolua_set_CGameObject_m_objectType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_objectType'", NULL);
	self->m_objectType = tolua_setter_tointeger<byte>(L, "m_objectType");
	return 0;
}

static int tolua_get_CGameObject_reference_m_objectType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_objectType'", NULL);
	tolua_pushusertype(L, (void*)&self->m_objectType, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameObject_m_pos(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pos'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pos, "CPoint");
	return 1;
}

static int tolua_get_CGameObject_m_posZ(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posZ'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_posZ);
	return 1;
}

static int tolua_set_CGameObject_m_posZ(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posZ'", NULL);
	self->m_posZ = tolua_setter_tointeger<int>(L, "m_posZ");
	return 0;
}

static int tolua_get_CGameObject_reference_m_posZ(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posZ'", NULL);
	tolua_pushusertype(L, (void*)&self->m_posZ, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameObject_m_pArea(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pArea'", NULL);
	tolua_pushusertype(L, (void*)self->m_pArea, "CGameArea");
	return 1;
}

static int tolua_set_CGameObject_m_pArea(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pArea'", NULL);
	self->m_pArea = (CGameArea*)tolua_tousertype_dynamic(L, 2, 0, "CGameArea");
	return 0;
}

static int tolua_get_CGameObject_reference_m_pArea(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pArea'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pArea, "Pointer<CGameArea>");
	return 1;
}

static int tolua_get_CGameObject_m_posVertList(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posVertList'", NULL);
	tolua_pushusertype(L, (void*)self->m_posVertList, "UnmappedUserType");
	return 1;
}

static int tolua_set_CGameObject_m_posVertList(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posVertList'", NULL);
	self->m_posVertList = (void*)tolua_tousertype_dynamic(L, 2, 0, "UnmappedUserType");
	return 0;
}

static int tolua_get_CGameObject_reference_m_posVertList(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posVertList'", NULL);
	tolua_pushusertype(L, (void*)&self->m_posVertList, "VoidPointer");
	return 1;
}

static int tolua_get_CGameObject_m_listType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_listType'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_listType);
	return 1;
}

static int tolua_set_CGameObject_m_listType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_listType'", NULL);
	self->m_listType = tolua_setter_tointeger<byte>(L, "m_listType");
	return 0;
}

static int tolua_get_CGameObject_reference_m_listType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_listType'", NULL);
	tolua_pushusertype(L, (void*)&self->m_listType, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameObject_m_typeAI(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_typeAI'", NULL);
	tolua_pushusertype(L, (void*)&self->m_typeAI, "CAIObjectType");
	return 1;
}

static int tolua_get_CGameObject_m_id(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_id'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_id);
	return 1;
}

static int tolua_set_CGameObject_m_id(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_id'", NULL);
	self->m_id = tolua_setter_tointeger<int>(L, "m_id");
	return 0;
}

static int tolua_get_CGameObject_reference_m_id(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_id'", NULL);
	tolua_pushusertype(L, (void*)&self->m_id, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameObject_m_canBeSeen(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_canBeSeen'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_canBeSeen);
	return 1;
}

static int tolua_set_CGameObject_m_canBeSeen(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_canBeSeen'", NULL);
	self->m_canBeSeen = tolua_setter_tointeger<short>(L, "m_canBeSeen");
	return 0;
}

static int tolua_get_CGameObject_reference_m_canBeSeen(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_canBeSeen'", NULL);
	tolua_pushusertype(L, (void*)&self->m_canBeSeen, "Primitive<short>");
	return 1;
}

static int tolua_get_CGameObject_m_remotePlayerID(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remotePlayerID'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_remotePlayerID);
	return 1;
}

static int tolua_set_CGameObject_m_remotePlayerID(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remotePlayerID'", NULL);
	self->m_remotePlayerID = tolua_setter_tointeger<int>(L, "m_remotePlayerID");
	return 0;
}

static int tolua_get_CGameObject_reference_m_remotePlayerID(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remotePlayerID'", NULL);
	tolua_pushusertype(L, (void*)&self->m_remotePlayerID, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameObject_m_remoteObjectID(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remoteObjectID'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_remoteObjectID);
	return 1;
}

static int tolua_set_CGameObject_m_remoteObjectID(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remoteObjectID'", NULL);
	self->m_remoteObjectID = tolua_setter_tointeger<int>(L, "m_remoteObjectID");
	return 0;
}

static int tolua_get_CGameObject_reference_m_remoteObjectID(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remoteObjectID'", NULL);
	tolua_pushusertype(L, (void*)&self->m_remoteObjectID, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameObject_m_AISpeed(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_AISpeed'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_AISpeed);
	return 1;
}

static int tolua_set_CGameObject_m_AISpeed(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_AISpeed'", NULL);
	self->m_AISpeed = tolua_setter_tointeger<byte>(L, "m_AISpeed");
	return 0;
}

static int tolua_get_CGameObject_reference_m_AISpeed(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_AISpeed'", NULL);
	tolua_pushusertype(L, (void*)&self->m_AISpeed, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameObject_m_bLocalControl(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bLocalControl'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bLocalControl);
	return 1;
}

static int tolua_set_CGameObject_m_bLocalControl(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bLocalControl'", NULL);
	self->m_bLocalControl = tolua_setter_tointeger<byte>(L, "m_bLocalControl");
	return 0;
}

static int tolua_get_CGameObject_reference_m_bLocalControl(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bLocalControl'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bLocalControl, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameObject_m_AIInhibitor(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_AIInhibitor'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_AIInhibitor);
	return 1;
}

static int tolua_set_CGameObject_m_AIInhibitor(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_AIInhibitor'", NULL);
	self->m_AIInhibitor = tolua_setter_tointeger<byte>(L, "m_AIInhibitor");
	return 0;
}

static int tolua_get_CGameObject_reference_m_AIInhibitor(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_AIInhibitor'", NULL);
	tolua_pushusertype(L, (void*)&self->m_AIInhibitor, "Primitive<byte>");
	return 1;
}

static int tolua_function_CGameObject_virtual_GetObjectType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_GetObjectType'", NULL);
	CGameObjectType returnVal = self->virtual_GetObjectType();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_CGameObject_virtual_AddToArea(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_AddToArea'", NULL);
	self->virtual_AddToArea((CGameArea*)tolua_tousertype_dynamic(L, 2, 0, "CGameArea"), (const CPoint*)tolua_tousertype_dynamic(L, 3, 0, "CPoint"), tolua_function_tointeger<int>(L, 4, "virtual_AddToArea"), tolua_function_tointeger<unsigned __int8>(L, 5, "virtual_AddToArea"));
	return 0;
}

static int tolua_function_CGameObject_virtual_AIUpdate(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_AIUpdate'", NULL);
	self->virtual_AIUpdate();
	return 0;
}

static int tolua_function_CGameObject_virtual_GetAIType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_GetAIType'", NULL);
	const CAIObjectType* returnVal = self->virtual_GetAIType();
	tolua_pushusertype(L, (void*)returnVal, "CAIObjectType");
	return 1;
}

static int tolua_function_CGameObject_virtual_GetTargetId(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_GetTargetId'", NULL);
	int returnVal = self->virtual_GetTargetId();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_CGameObject_virtual_GetNextWaypoint(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_GetNextWaypoint'", NULL);
	self->virtual_GetNextWaypoint((CPoint*)tolua_tousertype_dynamic(L, 2, 0, "CPoint"));
	return 0;
}

static int tolua_function_CGameObject_virtual_GetVertListPos(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_GetVertListPos'", NULL);
	CTypedPtrList<CPtrList,long>::CNode* returnVal = self->virtual_GetVertListPos();
	tolua_pushusertype(L, (void*)returnVal, "CTypedPtrList<CPtrList,long>::CNode");
	return 1;
}

static int tolua_function_CGameObject_virtual_GetVertListType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_GetVertListType'", NULL);
	VertListType returnVal = self->virtual_GetVertListType();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_CGameObject_virtual_CanSaveGame(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_CanSaveGame'", NULL);
	unsigned __int8 returnVal = self->virtual_CanSaveGame((unsigned int*)tolua_tousertype_dynamic(L, 2, 0, "Primitive<int>"), tolua_function_tointeger<int>(L, 3, "virtual_CanSaveGame"), tolua_function_tointeger<int>(L, 4, "virtual_CanSaveGame"));
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_CGameObject_virtual_CompressTime(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_CompressTime'", NULL);
	unsigned __int8 returnVal = self->virtual_CompressTime(tolua_function_tointeger<unsigned int>(L, 2, "virtual_CompressTime"));
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_CGameObject_virtual_DebugDump(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_DebugDump'", NULL);
	self->virtual_DebugDump((const CString*)tolua_tousertype_dynamic(L, 2, 0, "CString"), tolua_function_tointeger<unsigned __int8>(L, 3, "virtual_DebugDump"));
	return 0;
}

static int tolua_function_CGameObject_virtual_IsOver(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_IsOver'", NULL);
	int returnVal = self->virtual_IsOver((const CPoint*)tolua_tousertype_dynamic(L, 2, 0, "CPoint"));
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_CGameObject_virtual_DoesIntersect(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_DoesIntersect'", NULL);
	int returnVal = self->virtual_DoesIntersect(*(CRect*)tolua_tousertype_dynamic(L, 2, 0, "CRect"));
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_CGameObject_virtual_OnSearchMap(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_OnSearchMap'", NULL);
	int returnVal = self->virtual_OnSearchMap();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_CGameObject_virtual_OnActionButton(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_OnActionButton'", NULL);
	self->virtual_OnActionButton((const CPoint*)tolua_tousertype_dynamic(L, 2, 0, "CPoint"));
	return 0;
}

static int tolua_function_CGameObject_virtual_OnFormationButton(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_OnFormationButton'", NULL);
	self->virtual_OnFormationButton((const CPoint*)tolua_tousertype_dynamic(L, 2, 0, "CPoint"));
	return 0;
}

static int tolua_function_CGameObject_virtual_RemoveFromArea(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_RemoveFromArea'", NULL);
	self->virtual_RemoveFromArea();
	return 0;
}

static int tolua_function_CGameObject_virtual_Render(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_Render'", NULL);
	self->virtual_Render((CGameArea*)tolua_tousertype_dynamic(L, 2, 0, "CGameArea"), (CVidMode*)tolua_tousertype_dynamic(L, 3, 0, "CVidMode"));
	return 0;
}

static int tolua_function_CGameObject_virtual_DoAIUpdate(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_DoAIUpdate'", NULL);
	unsigned __int8 returnVal = self->virtual_DoAIUpdate(tolua_function_tointeger<unsigned __int8>(L, 2, "virtual_DoAIUpdate"), tolua_function_tointeger<int>(L, 3, "virtual_DoAIUpdate"));
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_CGameObject_virtual_SetAIType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_SetAIType'", NULL);
	self->virtual_SetAIType((const CAIObjectType*)tolua_tousertype_dynamic(L, 2, 0, "CAIObjectType"), tolua_function_tointeger<int>(L, 3, "virtual_SetAIType"));
	return 0;
}

static int tolua_function_CGameObject_virtual_SetCursor(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_SetCursor'", NULL);
	self->virtual_SetCursor(tolua_function_tointeger<int>(L, 2, "virtual_SetCursor"));
	return 0;
}

static int tolua_function_CGameObject_virtual_SetTarget(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_SetTarget'", NULL);
	self->virtual_SetTarget(*(CPoint*)tolua_tousertype_dynamic(L, 2, 0, "CPoint"), tolua_function_tointeger<int>(L, 3, "virtual_SetTarget"));
	return 0;
}

static int tolua_function_CGameObject_virtual_SetVertListPos(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_SetVertListPos'", NULL);
	self->virtual_SetVertListPos((__POSITION*)tolua_tousertype_dynamic(L, 2, 0, "__POSITION"));
	return 0;
}

static int tolua_function_CGameObject_virtual_EvaluateStatusTrigger(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_EvaluateStatusTrigger'", NULL);
	int returnVal = self->virtual_EvaluateStatusTrigger((const CAITrigger*)tolua_tousertype_dynamic(L, 2, 0, "CAITrigger"));
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_get_CGameObject__vtbl_GetObjectType(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_GetObjectType(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_GetObjectType(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_AddToArea(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_AddToArea(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_AddToArea(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_AIUpdate(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_AIUpdate(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_AIUpdate(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_GetAIType(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_GetAIType(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_GetAIType(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_GetTargetId(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_GetTargetId(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_GetTargetId(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_GetNextWaypoint(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_GetNextWaypoint(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_GetNextWaypoint(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_GetVertListPos(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_GetVertListPos(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_GetVertListPos(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_GetVertListType(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_GetVertListType(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_GetVertListType(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_CanSaveGame(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_CanSaveGame(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_CanSaveGame(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_CompressTime(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_CompressTime(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_CompressTime(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_DebugDump(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_DebugDump(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_DebugDump(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_IsOver(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_IsOver(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_IsOver(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_DoesIntersect(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_DoesIntersect(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_DoesIntersect(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_OnSearchMap(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_OnSearchMap(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_OnSearchMap(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_OnActionButton(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_OnActionButton(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_OnActionButton(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_OnFormationButton(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_OnFormationButton(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_OnFormationButton(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_RemoveFromArea(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_RemoveFromArea(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_RemoveFromArea(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_Render(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_Render(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_Render(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_DoAIUpdate(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_DoAIUpdate(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_DoAIUpdate(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_SetAIType(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_SetAIType(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_SetAIType(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_SetCursor(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_SetCursor(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_SetCursor(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_SetTarget(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_SetTarget(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_SetTarget(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_SetVertListPos(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_SetVertListPos(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_SetVertListPos(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameObject__vtbl_EvaluateStatusTrigger(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_EvaluateStatusTrigger(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_reference_EvaluateStatusTrigger(lua_State* L)
{
	return 1;
}

static int tolua_get_CProjectile_m_projectileType(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_projectileType'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_projectileType);
	return 1;
}

static int tolua_set_CProjectile_m_projectileType(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_projectileType'", NULL);
	self->m_projectileType = tolua_setter_tointeger<short>(L, "m_projectileType");
	return 0;
}

static int tolua_get_CProjectile_reference_m_projectileType(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_projectileType'", NULL);
	tolua_pushusertype(L, (void*)&self->m_projectileType, "Primitive<short>");
	return 1;
}

static int tolua_get_CProjectile_m_speed(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_speed'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_speed);
	return 1;
}

static int tolua_set_CProjectile_m_speed(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_speed'", NULL);
	self->m_speed = tolua_setter_tointeger<short>(L, "m_speed");
	return 0;
}

static int tolua_get_CProjectile_reference_m_speed(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_speed'", NULL);
	tolua_pushusertype(L, (void*)&self->m_speed, "Primitive<short>");
	return 1;
}

static int tolua_get_CProjectile_m_sourceId(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_sourceId);
	return 1;
}

static int tolua_set_CProjectile_m_sourceId(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	self->m_sourceId = tolua_setter_tointeger<int>(L, "m_sourceId");
	return 0;
}

static int tolua_get_CProjectile_reference_m_sourceId(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	tolua_pushusertype(L, (void*)&self->m_sourceId, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectile_m_targetId(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_targetId);
	return 1;
}

static int tolua_set_CProjectile_m_targetId(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	self->m_targetId = tolua_setter_tointeger<int>(L, "m_targetId");
	return 0;
}

static int tolua_get_CProjectile_reference_m_targetId(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	tolua_pushusertype(L, (void*)&self->m_targetId, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectile_m_callBackProjectile(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_callBackProjectile'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_callBackProjectile);
	return 1;
}

static int tolua_set_CProjectile_m_callBackProjectile(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_callBackProjectile'", NULL);
	self->m_callBackProjectile = tolua_setter_tointeger<int>(L, "m_callBackProjectile");
	return 0;
}

static int tolua_get_CProjectile_reference_m_callBackProjectile(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_callBackProjectile'", NULL);
	tolua_pushusertype(L, (void*)&self->m_callBackProjectile, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectile_m_effectList(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectList'", NULL);
	tolua_pushusertype(L, (void*)&self->m_effectList, "CGameEffectList");
	return 1;
}

static int tolua_get_CProjectile_m_nType(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nType'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nType);
	return 1;
}

static int tolua_set_CProjectile_m_nType(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nType'", NULL);
	self->m_nType = tolua_setter_tointeger<short>(L, "m_nType");
	return 0;
}

static int tolua_get_CProjectile_reference_m_nType(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nType'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nType, "Primitive<short>");
	return 1;
}

static int tolua_get_CProjectile_m_posExact(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posExact'", NULL);
	tolua_pushusertype(L, (void*)&self->m_posExact, "CPoint");
	return 1;
}

static int tolua_get_CProjectile_m_posDest(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posDest'", NULL);
	tolua_pushusertype(L, (void*)&self->m_posDest, "CPoint");
	return 1;
}

static int tolua_get_CProjectile_m_decAmmount(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_decAmmount'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_decAmmount);
	return 1;
}

static int tolua_set_CProjectile_m_decAmmount(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_decAmmount'", NULL);
	self->m_decAmmount = tolua_setter_tointeger<ushort>(L, "m_decAmmount");
	return 0;
}

static int tolua_get_CProjectile_reference_m_decAmmount(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_decAmmount'", NULL);
	tolua_pushusertype(L, (void*)&self->m_decAmmount, "Primitive<ushort>");
	return 1;
}

static int tolua_get_CProjectile_m_bSparkleTrail(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bSparkleTrail'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bSparkleTrail);
	return 1;
}

static int tolua_set_CProjectile_m_bSparkleTrail(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bSparkleTrail'", NULL);
	self->m_bSparkleTrail = tolua_setter_tointeger<int>(L, "m_bSparkleTrail");
	return 0;
}

static int tolua_get_CProjectile_reference_m_bSparkleTrail(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bSparkleTrail'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bSparkleTrail, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectile_m_defaultRenderFlags(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_defaultRenderFlags'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_defaultRenderFlags);
	return 1;
}

static int tolua_set_CProjectile_m_defaultRenderFlags(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_defaultRenderFlags'", NULL);
	self->m_defaultRenderFlags = tolua_setter_tointeger<uint>(L, "m_defaultRenderFlags");
	return 0;
}

static int tolua_get_CProjectile_reference_m_defaultRenderFlags(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_defaultRenderFlags'", NULL);
	tolua_pushusertype(L, (void*)&self->m_defaultRenderFlags, "Primitive<uint>");
	return 1;
}

static int tolua_get_CProjectile_m_bIgnoreTarget(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bIgnoreTarget'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bIgnoreTarget);
	return 1;
}

static int tolua_set_CProjectile_m_bIgnoreTarget(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bIgnoreTarget'", NULL);
	self->m_bIgnoreTarget = tolua_setter_tointeger<int>(L, "m_bIgnoreTarget");
	return 0;
}

static int tolua_get_CProjectile_reference_m_bIgnoreTarget(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bIgnoreTarget'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bIgnoreTarget, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectile_m_fireSoundRef(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_fireSoundRef'", NULL);
	tolua_pushusertype(L, (void*)&self->m_fireSoundRef, "CResRef");
	return 1;
}

static int tolua_get_CProjectile_m_loopFireSound(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_loopFireSound'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_loopFireSound);
	return 1;
}

static int tolua_set_CProjectile_m_loopFireSound(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_loopFireSound'", NULL);
	self->m_loopFireSound = tolua_setter_tointeger<int>(L, "m_loopFireSound");
	return 0;
}

static int tolua_get_CProjectile_reference_m_loopFireSound(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_loopFireSound'", NULL);
	tolua_pushusertype(L, (void*)&self->m_loopFireSound, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectile_m_arrivalSoundRef(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_arrivalSoundRef'", NULL);
	tolua_pushusertype(L, (void*)&self->m_arrivalSoundRef, "CResRef");
	return 1;
}

static int tolua_get_CProjectile_m_loopArrivalSound(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_loopArrivalSound'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_loopArrivalSound);
	return 1;
}

static int tolua_set_CProjectile_m_loopArrivalSound(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_loopArrivalSound'", NULL);
	self->m_loopArrivalSound = tolua_setter_tointeger<int>(L, "m_loopArrivalSound");
	return 0;
}

static int tolua_get_CProjectile_reference_m_loopArrivalSound(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_loopArrivalSound'", NULL);
	tolua_pushusertype(L, (void*)&self->m_loopArrivalSound, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectile_m_visualEffectRef(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_visualEffectRef'", NULL);
	tolua_pushusertype(L, (void*)&self->m_visualEffectRef, "CString");
	return 1;
}

static int tolua_get_CProjectile_m_visualEffect(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_visualEffect'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_visualEffect);
	return 1;
}

static int tolua_set_CProjectile_m_visualEffect(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_visualEffect'", NULL);
	self->m_visualEffect = tolua_setter_tointeger<int>(L, "m_visualEffect");
	return 0;
}

static int tolua_get_CProjectile_reference_m_visualEffect(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_visualEffect'", NULL);
	tolua_pushusertype(L, (void*)&self->m_visualEffect, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectile_m_maxDuration(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_maxDuration'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_maxDuration);
	return 1;
}

static int tolua_set_CProjectile_m_maxDuration(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_maxDuration'", NULL);
	self->m_maxDuration = tolua_setter_tointeger<short>(L, "m_maxDuration");
	return 0;
}

static int tolua_get_CProjectile_reference_m_maxDuration(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_maxDuration'", NULL);
	tolua_pushusertype(L, (void*)&self->m_maxDuration, "Primitive<short>");
	return 1;
}

static int tolua_get_CProjectile_m_strRef(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_strRef'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_strRef);
	return 1;
}

static int tolua_set_CProjectile_m_strRef(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_strRef'", NULL);
	self->m_strRef = tolua_setter_tointeger<uint>(L, "m_strRef");
	return 0;
}

static int tolua_get_CProjectile_reference_m_strRef(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_strRef'", NULL);
	tolua_pushusertype(L, (void*)&self->m_strRef, "Primitive<uint>");
	return 1;
}

static int tolua_get_CProjectile_m_failureSpell(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_failureSpell'", NULL);
	tolua_pushusertype(L, (void*)&self->m_failureSpell, "CResRef");
	return 1;
}

static int tolua_get_CProjectile_m_successSpell(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_successSpell'", NULL);
	tolua_pushusertype(L, (void*)&self->m_successSpell, "CResRef");
	return 1;
}

static int tolua_get_CProjectile_unknown(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown'", NULL);
	lua_pushinteger(L, (lua_Integer)self->unknown);
	return 1;
}

static int tolua_set_CProjectile_unknown(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown'", NULL);
	self->unknown = tolua_setter_tointeger<int>(L, "unknown");
	return 0;
}

static int tolua_get_CProjectile_reference_unknown(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown'", NULL);
	tolua_pushusertype(L, (void*)&self->unknown, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectile_unknown2(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown2'", NULL);
	lua_pushinteger(L, (lua_Integer)self->unknown2);
	return 1;
}

static int tolua_set_CProjectile_unknown2(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown2'", NULL);
	self->unknown2 = tolua_setter_tointeger<int>(L, "unknown2");
	return 0;
}

static int tolua_get_CProjectile_reference_unknown2(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown2'", NULL);
	tolua_pushusertype(L, (void*)&self->unknown2, "Primitive<int>");
	return 1;
}

static int tolua_function_CProjectile_DecodeProjectile(lua_State* L)
{
	CProjectile* returnVal = CProjectile::DecodeProjectile(tolua_function_tointeger<ushort>(L, 1, "DecodeProjectile"), (CGameAIBase*)tolua_tousertype_dynamic(L, 2, 0, "CGameAIBase"), tolua_function_tointeger<uint>(L, 3, "DecodeProjectile"));
	tolua_pushusertype(L, (void*)returnVal, "CProjectile");
	return 1;
}

static int tolua_get_reference_CProjectile_DecodeProjectile(lua_State* L)
{
	tolua_pushusertype(L, CProjectile::DecodeProjectile, "UnmappedUserType");
	return 1;
}

static int tolua_get_CProjectileBAM_m_currentVidCell(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currentVidCell'", NULL);
	tolua_pushusertype(L, (void*)self->m_currentVidCell, "CVidCell");
	return 1;
}

static int tolua_set_CProjectileBAM_m_currentVidCell(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currentVidCell'", NULL);
	self->m_currentVidCell = (CVidCell*)tolua_tousertype_dynamic(L, 2, 0, "CVidCell");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_currentVidCell(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currentVidCell'", NULL);
	tolua_pushusertype(L, (void*)&self->m_currentVidCell, "Pointer<CVidCell>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_shadowVidCell(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_shadowVidCell'", NULL);
	tolua_pushusertype(L, (void*)self->m_shadowVidCell, "CVidCell");
	return 1;
}

static int tolua_set_CProjectileBAM_m_shadowVidCell(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_shadowVidCell'", NULL);
	self->m_shadowVidCell = (CVidCell*)tolua_tousertype_dynamic(L, 2, 0, "CVidCell");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_shadowVidCell(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_shadowVidCell'", NULL);
	tolua_pushusertype(L, (void*)&self->m_shadowVidCell, "Pointer<CVidCell>");
	return 1;
}

static int tolua_get_CProjectileBAM_bUseAreaTint(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bUseAreaTint'", NULL);
	lua_pushinteger(L, (lua_Integer)self->bUseAreaTint);
	return 1;
}

static int tolua_set_CProjectileBAM_bUseAreaTint(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bUseAreaTint'", NULL);
	self->bUseAreaTint = tolua_setter_tointeger<int>(L, "bUseAreaTint");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_bUseAreaTint(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bUseAreaTint'", NULL);
	tolua_pushusertype(L, (void*)&self->bUseAreaTint, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_numDirections(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_numDirections'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_numDirections);
	return 1;
}

static int tolua_set_CProjectileBAM_m_numDirections(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_numDirections'", NULL);
	self->m_numDirections = tolua_setter_tointeger<short>(L, "m_numDirections");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_numDirections(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_numDirections'", NULL);
	tolua_pushusertype(L, (void*)&self->m_numDirections, "Primitive<short>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_direction(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_direction'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_direction);
	return 1;
}

static int tolua_set_CProjectileBAM_m_direction(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_direction'", NULL);
	self->m_direction = tolua_setter_tointeger<short>(L, "m_direction");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_direction(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_direction'", NULL);
	tolua_pushusertype(L, (void*)&self->m_direction, "Primitive<short>");
	return 1;
}

static int tolua_get_CProjectileBAM_unknown3(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown3'", NULL);
	lua_pushinteger(L, (lua_Integer)self->unknown3);
	return 1;
}

static int tolua_set_CProjectileBAM_unknown3(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown3'", NULL);
	self->unknown3 = tolua_setter_tointeger<ushort>(L, "unknown3");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_unknown3(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown3'", NULL);
	tolua_pushusertype(L, (void*)&self->unknown3, "Primitive<ushort>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_render(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_render'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_render);
	return 1;
}

static int tolua_set_CProjectileBAM_m_render(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_render'", NULL);
	self->m_render = tolua_setter_tointeger<int>(L, "m_render");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_render(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_render'", NULL);
	tolua_pushusertype(L, (void*)&self->m_render, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectileBAM_unknown4(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown4'", NULL);
	lua_pushinteger(L, (lua_Integer)self->unknown4);
	return 1;
}

static int tolua_set_CProjectileBAM_unknown4(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown4'", NULL);
	self->unknown4 = tolua_setter_tointeger<int>(L, "unknown4");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_unknown4(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown4'", NULL);
	tolua_pushusertype(L, (void*)&self->unknown4, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_cPuffEffect1(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_cPuffEffect1'", NULL);
	tolua_pushusertype(L, (void*)&self->m_cPuffEffect1, "CResRef");
	return 1;
}

static int tolua_get_CProjectileBAM_m_cPuffEffect2(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_cPuffEffect2'", NULL);
	tolua_pushusertype(L, (void*)&self->m_cPuffEffect2, "CResRef");
	return 1;
}

static int tolua_get_CProjectileBAM_m_cPuffEffect3(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_cPuffEffect3'", NULL);
	tolua_pushusertype(L, (void*)&self->m_cPuffEffect3, "CResRef");
	return 1;
}

static int tolua_get_CProjectileBAM_m_nPuff1Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff1Spacing'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nPuff1Spacing);
	return 1;
}

static int tolua_set_CProjectileBAM_m_nPuff1Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff1Spacing'", NULL);
	self->m_nPuff1Spacing = tolua_setter_tointeger<ushort>(L, "m_nPuff1Spacing");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_nPuff1Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff1Spacing'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nPuff1Spacing, "Primitive<ushort>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_nPuff2Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff2Spacing'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nPuff2Spacing);
	return 1;
}

static int tolua_set_CProjectileBAM_m_nPuff2Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff2Spacing'", NULL);
	self->m_nPuff2Spacing = tolua_setter_tointeger<ushort>(L, "m_nPuff2Spacing");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_nPuff2Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff2Spacing'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nPuff2Spacing, "Primitive<ushort>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_nPuff3Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff3Spacing'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nPuff3Spacing);
	return 1;
}

static int tolua_set_CProjectileBAM_m_nPuff3Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff3Spacing'", NULL);
	self->m_nPuff3Spacing = tolua_setter_tointeger<ushort>(L, "m_nPuff3Spacing");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_nPuff3Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff3Spacing'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nPuff3Spacing, "Primitive<ushort>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_dwPuffFlags(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_dwPuffFlags'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_dwPuffFlags);
	return 1;
}

static int tolua_set_CProjectileBAM_m_dwPuffFlags(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_dwPuffFlags'", NULL);
	self->m_dwPuffFlags = tolua_setter_tointeger<uint>(L, "m_dwPuffFlags");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_dwPuffFlags(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_dwPuffFlags'", NULL);
	tolua_pushusertype(L, (void*)&self->m_dwPuffFlags, "Primitive<uint>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_puffCounter(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_puffCounter'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_puffCounter);
	return 1;
}

static int tolua_set_CProjectileBAM_m_puffCounter(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_puffCounter'", NULL);
	self->m_puffCounter = tolua_setter_tointeger<int>(L, "m_puffCounter");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_puffCounter(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_puffCounter'", NULL);
	tolua_pushusertype(L, (void*)&self->m_puffCounter, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_unknownPSTFlags(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_unknownPSTFlags'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_unknownPSTFlags);
	return 1;
}

static int tolua_set_CProjectileBAM_m_unknownPSTFlags(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_unknownPSTFlags'", NULL);
	self->m_unknownPSTFlags = tolua_setter_tointeger<uint>(L, "m_unknownPSTFlags");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_unknownPSTFlags(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_unknownPSTFlags'", NULL);
	tolua_pushusertype(L, (void*)&self->m_unknownPSTFlags, "Primitive<uint>");
	return 1;
}

static int tolua_get_CProjectileBAM_nDelayedRemoveCounter(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDelayedRemoveCounter'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nDelayedRemoveCounter);
	return 1;
}

static int tolua_set_CProjectileBAM_nDelayedRemoveCounter(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDelayedRemoveCounter'", NULL);
	self->nDelayedRemoveCounter = tolua_setter_tointeger<int>(L, "nDelayedRemoveCounter");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_nDelayedRemoveCounter(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDelayedRemoveCounter'", NULL);
	tolua_pushusertype(L, (void*)&self->nDelayedRemoveCounter, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectileArea_m_coneSize(lua_State* L)
{
	CProjectileArea* self = (CProjectileArea*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_coneSize'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_coneSize);
	return 1;
}

static int tolua_set_CProjectileArea_m_coneSize(lua_State* L)
{
	CProjectileArea* self = (CProjectileArea*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_coneSize'", NULL);
	self->m_coneSize = tolua_setter_tointeger<ushort>(L, "m_coneSize");
	return 0;
}

static int tolua_get_CProjectileArea_reference_m_coneSize(lua_State* L)
{
	CProjectileArea* self = (CProjectileArea*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_coneSize'", NULL);
	tolua_pushusertype(L, (void*)&self->m_coneSize, "Primitive<ushort>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST_pInfinity(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pInfinity'", NULL);
	tolua_pushusertype(L, (void*)self->pInfinity, "CInfinity");
	return 1;
}

static int tolua_set_CProjectileUnknownPST_pInfinity(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pInfinity'", NULL);
	self->pInfinity = (CInfinity*)tolua_tousertype_dynamic(L, 2, 0, "CInfinity");
	return 0;
}

static int tolua_get_CProjectileUnknownPST_reference_pInfinity(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'pInfinity'", NULL);
	tolua_pushusertype(L, (void*)&self->pInfinity, "Pointer<CInfinity>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST_nUnknownMode(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nUnknownMode'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nUnknownMode);
	return 1;
}

static int tolua_set_CProjectileUnknownPST_nUnknownMode(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nUnknownMode'", NULL);
	self->nUnknownMode = tolua_setter_tointeger<uint>(L, "nUnknownMode");
	return 0;
}

static int tolua_get_CProjectileUnknownPST_reference_nUnknownMode(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nUnknownMode'", NULL);
	tolua_pushusertype(L, (void*)&self->nUnknownMode, "Primitive<uint>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST_m_nUnknown1(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nUnknown1'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nUnknown1);
	return 1;
}

static int tolua_set_CProjectileUnknownPST_m_nUnknown1(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nUnknown1'", NULL);
	self->m_nUnknown1 = tolua_setter_tointeger<int>(L, "m_nUnknown1");
	return 0;
}

static int tolua_get_CProjectileUnknownPST_reference_m_nUnknown1(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nUnknown1'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nUnknown1, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST_nExpirationTime(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nExpirationTime'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nExpirationTime);
	return 1;
}

static int tolua_set_CProjectileUnknownPST_nExpirationTime(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nExpirationTime'", NULL);
	self->nExpirationTime = tolua_setter_tointeger<uint>(L, "nExpirationTime");
	return 0;
}

static int tolua_get_CProjectileUnknownPST_reference_nExpirationTime(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nExpirationTime'", NULL);
	tolua_pushusertype(L, (void*)&self->nExpirationTime, "Primitive<uint>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST_m_nUnknown2(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nUnknown2'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nUnknown2);
	return 1;
}

static int tolua_set_CProjectileUnknownPST_m_nUnknown2(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nUnknown2'", NULL);
	self->m_nUnknown2 = tolua_setter_tointeger<int>(L, "m_nUnknown2");
	return 0;
}

static int tolua_get_CProjectileUnknownPST_reference_m_nUnknown2(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nUnknown2'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nUnknown2, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST_bSuppressFireSound(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bSuppressFireSound'", NULL);
	lua_pushinteger(L, (lua_Integer)self->bSuppressFireSound);
	return 1;
}

static int tolua_set_CProjectileUnknownPST_bSuppressFireSound(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bSuppressFireSound'", NULL);
	self->bSuppressFireSound = tolua_setter_tointeger<int>(L, "bSuppressFireSound");
	return 0;
}

static int tolua_get_CProjectileUnknownPST_reference_bSuppressFireSound(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bSuppressFireSound'", NULL);
	tolua_pushusertype(L, (void*)&self->bSuppressFireSound, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST_nDelayedRemoveSpeed(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDelayedRemoveSpeed'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nDelayedRemoveSpeed);
	return 1;
}

static int tolua_set_CProjectileUnknownPST_nDelayedRemoveSpeed(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDelayedRemoveSpeed'", NULL);
	self->nDelayedRemoveSpeed = tolua_setter_tointeger<byte>(L, "nDelayedRemoveSpeed");
	return 0;
}

static int tolua_get_CProjectileUnknownPST_reference_nDelayedRemoveSpeed(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDelayedRemoveSpeed'", NULL);
	tolua_pushusertype(L, (void*)&self->nDelayedRemoveSpeed, "Primitive<byte>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST_bDelayedRemoveScheduled(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bDelayedRemoveScheduled'", NULL);
	lua_pushinteger(L, (lua_Integer)self->bDelayedRemoveScheduled);
	return 1;
}

static int tolua_set_CProjectileUnknownPST_bDelayedRemoveScheduled(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bDelayedRemoveScheduled'", NULL);
	self->bDelayedRemoveScheduled = tolua_setter_tointeger<int>(L, "bDelayedRemoveScheduled");
	return 0;
}

static int tolua_get_CProjectileUnknownPST_reference_bDelayedRemoveScheduled(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bDelayedRemoveScheduled'", NULL);
	tolua_pushusertype(L, (void*)&self->bDelayedRemoveScheduled, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST2_bRemoveOnNextUpdate(lua_State* L)
{
	CProjectileUnknownPST2* self = (CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST2");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bRemoveOnNextUpdate'", NULL);
	lua_pushinteger(L, (lua_Integer)self->bRemoveOnNextUpdate);
	return 1;
}

static int tolua_set_CProjectileUnknownPST2_bRemoveOnNextUpdate(lua_State* L)
{
	CProjectileUnknownPST2* self = (CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST2");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bRemoveOnNextUpdate'", NULL);
	self->bRemoveOnNextUpdate = tolua_setter_tointeger<int>(L, "bRemoveOnNextUpdate");
	return 0;
}

static int tolua_get_CProjectileUnknownPST2_reference_bRemoveOnNextUpdate(lua_State* L)
{
	CProjectileUnknownPST2* self = (CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST2");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bRemoveOnNextUpdate'", NULL);
	tolua_pushusertype(L, (void*)&self->bRemoveOnNextUpdate, "Primitive<int>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST2_nTypePST(lua_State* L)
{
	CProjectileUnknownPST2* self = (CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST2");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nTypePST'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nTypePST);
	return 1;
}

static int tolua_set_CProjectileUnknownPST2_nTypePST(lua_State* L)
{
	CProjectileUnknownPST2* self = (CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST2");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nTypePST'", NULL);
	self->nTypePST = tolua_setter_tointeger<byte>(L, "nTypePST");
	return 0;
}

static int tolua_get_CProjectileUnknownPST2_reference_nTypePST(lua_State* L)
{
	CProjectileUnknownPST2* self = (CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST2");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nTypePST'", NULL);
	tolua_pushusertype(L, (void*)&self->nTypePST, "Primitive<byte>");
	return 1;
}

static int tolua_get_CProjectile205_bHitTarget(lua_State* L)
{
	CProjectile205* self = (CProjectile205*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile205");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bHitTarget'", NULL);
	lua_pushinteger(L, (lua_Integer)self->bHitTarget);
	return 1;
}

static int tolua_set_CProjectile205_bHitTarget(lua_State* L)
{
	CProjectile205* self = (CProjectile205*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile205");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bHitTarget'", NULL);
	self->bHitTarget = tolua_setter_tointeger<int>(L, "bHitTarget");
	return 0;
}

static int tolua_get_CProjectile205_reference_bHitTarget(lua_State* L)
{
	CProjectile205* self = (CProjectile205*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile205");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bHitTarget'", NULL);
	tolua_pushusertype(L, (void*)&self->bHitTarget, "Primitive<int>");
	return 1;
}

static int tolua_get_CAITrigger_m_triggerID(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_triggerID'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_triggerID);
	return 1;
}

static int tolua_set_CAITrigger_m_triggerID(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_triggerID'", NULL);
	self->m_triggerID = tolua_setter_tointeger<short>(L, "m_triggerID");
	return 0;
}

static int tolua_get_CAITrigger_reference_m_triggerID(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_triggerID'", NULL);
	tolua_pushusertype(L, (void*)&self->m_triggerID, "Primitive<short>");
	return 1;
}

static int tolua_get_CAITrigger_m_specificID(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specificID'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_specificID);
	return 1;
}

static int tolua_set_CAITrigger_m_specificID(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specificID'", NULL);
	self->m_specificID = tolua_setter_tointeger<int>(L, "m_specificID");
	return 0;
}

static int tolua_get_CAITrigger_reference_m_specificID(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specificID'", NULL);
	tolua_pushusertype(L, (void*)&self->m_specificID, "Primitive<int>");
	return 1;
}

static int tolua_get_CAITrigger_m_triggerCause(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_triggerCause'", NULL);
	tolua_pushusertype(L, (void*)&self->m_triggerCause, "CAIObjectType");
	return 1;
}

static int tolua_get_CAITrigger_m_flags(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_flags'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_flags);
	return 1;
}

static int tolua_set_CAITrigger_m_flags(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_flags'", NULL);
	self->m_flags = tolua_setter_tointeger<int>(L, "m_flags");
	return 0;
}

static int tolua_get_CAITrigger_reference_m_flags(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_flags'", NULL);
	tolua_pushusertype(L, (void*)&self->m_flags, "Primitive<int>");
	return 1;
}

static int tolua_get_CAITrigger_m_specific2(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specific2'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_specific2);
	return 1;
}

static int tolua_set_CAITrigger_m_specific2(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specific2'", NULL);
	self->m_specific2 = tolua_setter_tointeger<int>(L, "m_specific2");
	return 0;
}

static int tolua_get_CAITrigger_reference_m_specific2(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specific2'", NULL);
	tolua_pushusertype(L, (void*)&self->m_specific2, "Primitive<int>");
	return 1;
}

static int tolua_get_CAITrigger_m_specific3(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specific3'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_specific3);
	return 1;
}

static int tolua_set_CAITrigger_m_specific3(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specific3'", NULL);
	self->m_specific3 = tolua_setter_tointeger<int>(L, "m_specific3");
	return 0;
}

static int tolua_get_CAITrigger_reference_m_specific3(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specific3'", NULL);
	tolua_pushusertype(L, (void*)&self->m_specific3, "Primitive<int>");
	return 1;
}

static int tolua_get_CAITrigger_m_string1(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_string1'", NULL);
	tolua_pushusertype(L, (void*)&self->m_string1, "CString");
	return 1;
}

static int tolua_get_CAITrigger_m_string2(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_string2'", NULL);
	tolua_pushusertype(L, (void*)&self->m_string2, "CString");
	return 1;
}

static int tolua_get_CMessageSetTrigger_m_trigger(lua_State* L)
{
	CMessageSetTrigger* self = (CMessageSetTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CMessageSetTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trigger'", NULL);
	tolua_pushusertype(L, (void*)&self->m_trigger, "CAITrigger");
	return 1;
}

static int tolua_get_CGameAIBase_m_lAttacker(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_lAttacker'", NULL);
	tolua_pushusertype(L, (void*)&self->m_lAttacker, "CAIObjectType");
	return 1;
}

static int tolua_get_CGameAIBase_m_lAttackStyle(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_lAttackStyle'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_lAttackStyle);
	return 1;
}

static int tolua_set_CGameAIBase_m_lAttackStyle(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_lAttackStyle'", NULL);
	self->m_lAttackStyle = tolua_setter_tointeger<int>(L, "m_lAttackStyle");
	return 0;
}

static int tolua_get_CGameAIBase_reference_m_lAttackStyle(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_lAttackStyle'", NULL);
	tolua_pushusertype(L, (void*)&self->m_lAttackStyle, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameAIBase_m_lOrderedBy(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_lOrderedBy'", NULL);
	tolua_pushusertype(L, (void*)&self->m_lOrderedBy, "CAIObjectType");
	return 1;
}

static int tolua_get_CGameAIBase_m_protecting(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_protecting'", NULL);
	tolua_pushusertype(L, (void*)&self->m_protecting, "CAIObjectType");
	return 1;
}

static int tolua_get_CGameAIBase_m_protector(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_protector'", NULL);
	tolua_pushusertype(L, (void*)&self->m_protector, "CAIObjectType");
	return 1;
}

static int tolua_get_CGameAIBase_m_lTargeted(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_lTargeted'", NULL);
	tolua_pushusertype(L, (void*)&self->m_lTargeted, "CAIObjectType");
	return 1;
}

static int tolua_get_CGameAIBase_m_activeAnimations(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_activeAnimations'", NULL);
	tolua_pushusertype(L, (void*)&self->m_activeAnimations, "CPtrList");
	return 1;
}

static int tolua_get_CGameAIBase_m_pendingTriggers(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pendingTriggers'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pendingTriggers, "CPtrList");
	return 1;
}

static int tolua_get_CGameAIBase_m_interrupt(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_interrupt'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_interrupt);
	return 1;
}

static int tolua_set_CGameAIBase_m_interrupt(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_interrupt'", NULL);
	self->m_interrupt = tolua_setter_tointeger<int>(L, "m_interrupt");
	return 0;
}

static int tolua_get_CGameAIBase_reference_m_interrupt(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_interrupt'", NULL);
	tolua_pushusertype(L, (void*)&self->m_interrupt, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameAIBase_m_actionCount(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_actionCount'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_actionCount);
	return 1;
}

static int tolua_set_CGameAIBase_m_actionCount(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_actionCount'", NULL);
	self->m_actionCount = tolua_setter_tointeger<short>(L, "m_actionCount");
	return 0;
}

static int tolua_get_CGameAIBase_reference_m_actionCount(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_actionCount'", NULL);
	tolua_pushusertype(L, (void*)&self->m_actionCount, "Primitive<short>");
	return 1;
}

static int tolua_get_CGameAIBase_m_curAction(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_curAction'", NULL);
	tolua_pushusertype(L, (void*)&self->m_curAction, "CAIAction");
	return 1;
}

static int tolua_get_CGameAIBase_m_scriptName(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_scriptName'", NULL);
	tolua_pushusertype(L, (void*)&self->m_scriptName, "Array<char,32>");
	return 1;
}

static int tolua_get_CGameAIBase_triggerOverride(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'triggerOverride'", NULL);
	tolua_pushusertype(L, (void*)&self->triggerOverride, "CAITrigger");
	return 1;
}

static int tolua_function_CGameAIBase_virtual_ClearActions(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_ClearActions'", NULL);
	self->virtual_ClearActions(tolua_function_tointeger<int>(L, 2, "virtual_ClearActions"));
	return 0;
}

static int tolua_function_CGameAIBase_virtual_FloatMessage(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_FloatMessage'", NULL);
	short returnVal = self->virtual_FloatMessage();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_CGameAIBase_virtual_KillFloatMessage(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_KillFloatMessage'", NULL);
	short returnVal = self->virtual_KillFloatMessage();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_CGameAIBase_virtual_UpdateTarget(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_UpdateTarget'", NULL);
	self->virtual_UpdateTarget((CGameObject*)tolua_tousertype_dynamic(L, 2, 0, "CGameObject"));
	return 0;
}

static int tolua_function_CGameAIBase_virtual_AddAction(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_AddAction'", NULL);
	self->virtual_AddAction((const CAIAction*)tolua_tousertype_dynamic(L, 2, 0, "CAIAction"));
	return 0;
}

static int tolua_function_CGameAIBase_virtual_AddEffect(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_AddEffect'", NULL);
	self->virtual_AddEffect((CGameEffect*)tolua_tousertype_dynamic(L, 2, 0, "CGameEffect"), tolua_function_tointeger<unsigned __int8>(L, 3, "virtual_AddEffect"), tolua_function_tointeger<int>(L, 4, "virtual_AddEffect"), tolua_function_tointeger<int>(L, 5, "virtual_AddEffect"));
	return 0;
}

static int tolua_get_CGameAIBase__vtbl_ClearActions(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameAIBase__vtbl_ClearActions(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameAIBase__vtbl_reference_ClearActions(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameAIBase__vtbl_FloatMessage(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameAIBase__vtbl_FloatMessage(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameAIBase__vtbl_reference_FloatMessage(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameAIBase__vtbl_KillFloatMessage(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameAIBase__vtbl_KillFloatMessage(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameAIBase__vtbl_reference_KillFloatMessage(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameAIBase__vtbl_UpdateTarget(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameAIBase__vtbl_UpdateTarget(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameAIBase__vtbl_reference_UpdateTarget(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameAIBase__vtbl_AddAction(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameAIBase__vtbl_AddAction(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameAIBase__vtbl_reference_AddAction(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameAIBase__vtbl_AddEffect(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameAIBase__vtbl_AddEffect(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameAIBase__vtbl_reference_AddEffect(lua_State* L)
{
	return 1;
}

static int tolua_get_CGameSprite_m_baseStats_m_generalState(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_baseStats_m_generalState'", NULL);
	tolua_pushusertype(L, (void*)&self->m_baseStats_m_generalState, "ulong");
	return 1;
}

static int tolua_get_CGameSprite_m_derivedStats(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_derivedStats'", NULL);
	tolua_pushusertype(L, (void*)&self->m_derivedStats, "CDerivedStats");
	return 1;
}

static int tolua_get_CGameSprite_m_tempStats(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_tempStats'", NULL);
	tolua_pushusertype(L, (void*)&self->m_tempStats, "CDerivedStats");
	return 1;
}

static int tolua_get_CGameSprite_m_bonusStats(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bonusStats'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bonusStats, "CDerivedStats");
	return 1;
}

static int tolua_get_CGameSprite_m_animation(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_animation'", NULL);
	tolua_pushusertype(L, (void*)&self->m_animation, "CGameAnimation");
	return 1;
}

static int tolua_get_CGameSprite_bAllowGlobalOrAreaTintsWhenRendering(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bAllowGlobalOrAreaTintsWhenRendering'", NULL);
	lua_pushinteger(L, (lua_Integer)self->bAllowGlobalOrAreaTintsWhenRendering);
	return 1;
}

static int tolua_set_CGameSprite_bAllowGlobalOrAreaTintsWhenRendering(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bAllowGlobalOrAreaTintsWhenRendering'", NULL);
	self->bAllowGlobalOrAreaTintsWhenRendering = tolua_setter_tointeger<byte>(L, "bAllowGlobalOrAreaTintsWhenRendering");
	return 0;
}

static int tolua_get_CGameSprite_reference_bAllowGlobalOrAreaTintsWhenRendering(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bAllowGlobalOrAreaTintsWhenRendering'", NULL);
	tolua_pushusertype(L, (void*)&self->bAllowGlobalOrAreaTintsWhenRendering, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameSprite_m_nMirrorImages(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nMirrorImages'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nMirrorImages);
	return 1;
}

static int tolua_set_CGameSprite_m_nMirrorImages(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nMirrorImages'", NULL);
	self->m_nMirrorImages = tolua_setter_tointeger<byte>(L, "m_nMirrorImages");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_nMirrorImages(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nMirrorImages'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nMirrorImages, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameSprite_nPainMirrorCounter(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nPainMirrorCounter'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nPainMirrorCounter);
	return 1;
}

static int tolua_set_CGameSprite_nPainMirrorCounter(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nPainMirrorCounter'", NULL);
	self->nPainMirrorCounter = tolua_setter_tointeger<byte>(L, "nPainMirrorCounter");
	return 0;
}

static int tolua_get_CGameSprite_reference_nPainMirrorCounter(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nPainMirrorCounter'", NULL);
	tolua_pushusertype(L, (void*)&self->nPainMirrorCounter, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameSprite_bGuardianMantle(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bGuardianMantle'", NULL);
	lua_pushinteger(L, (lua_Integer)self->bGuardianMantle);
	return 1;
}

static int tolua_set_CGameSprite_bGuardianMantle(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bGuardianMantle'", NULL);
	self->bGuardianMantle = tolua_setter_tointeger<byte>(L, "bGuardianMantle");
	return 0;
}

static int tolua_get_CGameSprite_reference_bGuardianMantle(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bGuardianMantle'", NULL);
	tolua_pushusertype(L, (void*)&self->bGuardianMantle, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameSprite_nCloakOfWardingDamageAbsorption(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nCloakOfWardingDamageAbsorption'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nCloakOfWardingDamageAbsorption);
	return 1;
}

static int tolua_set_CGameSprite_nCloakOfWardingDamageAbsorption(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nCloakOfWardingDamageAbsorption'", NULL);
	self->nCloakOfWardingDamageAbsorption = tolua_setter_tointeger<ushort>(L, "nCloakOfWardingDamageAbsorption");
	return 0;
}

static int tolua_get_CGameSprite_reference_nCloakOfWardingDamageAbsorption(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nCloakOfWardingDamageAbsorption'", NULL);
	tolua_pushusertype(L, (void*)&self->nCloakOfWardingDamageAbsorption, "Primitive<ushort>");
	return 1;
}

static int tolua_get_CGameSprite_nArmorDamageCounter(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nArmorDamageCounter'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nArmorDamageCounter);
	return 1;
}

static int tolua_set_CGameSprite_nArmorDamageCounter(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nArmorDamageCounter'", NULL);
	self->nArmorDamageCounter = tolua_setter_tointeger<short>(L, "nArmorDamageCounter");
	return 0;
}

static int tolua_get_CGameSprite_reference_nArmorDamageCounter(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nArmorDamageCounter'", NULL);
	tolua_pushusertype(L, (void*)&self->nArmorDamageCounter, "Primitive<short>");
	return 1;
}

static int tolua_get_CGameSprite_m_bBlur(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bBlur'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bBlur);
	return 1;
}

static int tolua_set_CGameSprite_m_bBlur(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bBlur'", NULL);
	self->m_bBlur = tolua_setter_tointeger<byte>(L, "m_bBlur");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_bBlur(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bBlur'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bBlur, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameSprite_m_bMinorGlobe(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bMinorGlobe'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bMinorGlobe);
	return 1;
}

static int tolua_set_CGameSprite_m_bMinorGlobe(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bMinorGlobe'", NULL);
	self->m_bMinorGlobe = tolua_setter_tointeger<byte>(L, "m_bMinorGlobe");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_bMinorGlobe(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bMinorGlobe'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bMinorGlobe, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameSprite_m_bShieldGlobe(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bShieldGlobe'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bShieldGlobe);
	return 1;
}

static int tolua_set_CGameSprite_m_bShieldGlobe(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bShieldGlobe'", NULL);
	self->m_bShieldGlobe = tolua_setter_tointeger<byte>(L, "m_bShieldGlobe");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_bShieldGlobe(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bShieldGlobe'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bShieldGlobe, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameSprite_m_shieldGlobeVidCell(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_shieldGlobeVidCell'", NULL);
	tolua_pushusertype(L, (void*)&self->m_shieldGlobeVidCell, "CVidCell");
	return 1;
}

static int tolua_get_CGameSprite_m_posOld(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posOld'", NULL);
	tolua_pushusertype(L, (void*)&self->m_posOld, "CPoint");
	return 1;
}

static int tolua_get_CGameSprite_m_posOldWalk(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posOldWalk'", NULL);
	tolua_pushusertype(L, (void*)&self->m_posOldWalk, "CPoint");
	return 1;
}

static int tolua_get_CGameSprite_m_bStartedCasting(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bStartedCasting'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bStartedCasting);
	return 1;
}

static int tolua_set_CGameSprite_m_bStartedCasting(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bStartedCasting'", NULL);
	self->m_bStartedCasting = tolua_setter_tointeger<int>(L, "m_bStartedCasting");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_bStartedCasting(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bStartedCasting'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bStartedCasting, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameSprite_m_bInCasting(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bInCasting'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bInCasting);
	return 1;
}

static int tolua_set_CGameSprite_m_bInCasting(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bInCasting'", NULL);
	self->m_bInCasting = tolua_setter_tointeger<int>(L, "m_bInCasting");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_bInCasting(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bInCasting'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bInCasting, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameSprite_m_moveCount(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_moveCount'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_moveCount);
	return 1;
}

static int tolua_set_CGameSprite_m_moveCount(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_moveCount'", NULL);
	self->m_moveCount = tolua_setter_tointeger<short>(L, "m_moveCount");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_moveCount(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_moveCount'", NULL);
	tolua_pushusertype(L, (void*)&self->m_moveCount, "Primitive<short>");
	return 1;
}

static int tolua_get_CGameSprite_m_equipedEffectList(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_equipedEffectList'", NULL);
	tolua_pushusertype(L, (void*)&self->m_equipedEffectList, "CGameEffectList");
	return 1;
}

static int tolua_get_CGameSprite_m_timedEffectList(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_timedEffectList'", NULL);
	tolua_pushusertype(L, (void*)&self->m_timedEffectList, "CGameEffectList");
	return 1;
}

static int tolua_get_CGameSprite_m_persistantEffects(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_persistantEffects'", NULL);
	tolua_pushusertype(L, (void*)&self->m_persistantEffects, "CPtrList");
	return 1;
}

static int tolua_get_CGameSprite_m_bWaitingForAreaLoadInLeaveAreaLUA(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bWaitingForAreaLoadInLeaveAreaLUA'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bWaitingForAreaLoadInLeaveAreaLUA);
	return 1;
}

static int tolua_set_CGameSprite_m_bWaitingForAreaLoadInLeaveAreaLUA(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bWaitingForAreaLoadInLeaveAreaLUA'", NULL);
	self->m_bWaitingForAreaLoadInLeaveAreaLUA = tolua_setter_tointeger<int>(L, "m_bWaitingForAreaLoadInLeaveAreaLUA");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_bWaitingForAreaLoadInLeaveAreaLUA(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bWaitingForAreaLoadInLeaveAreaLUA'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bWaitingForAreaLoadInLeaveAreaLUA, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameSprite_m_lastActionID(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_lastActionID'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_lastActionID);
	return 1;
}

static int tolua_set_CGameSprite_m_lastActionID(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_lastActionID'", NULL);
	self->m_lastActionID = tolua_setter_tointeger<short>(L, "m_lastActionID");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_lastActionID(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_lastActionID'", NULL);
	tolua_pushusertype(L, (void*)&self->m_lastActionID, "Primitive<short>");
	return 1;
}

static int tolua_get_CGameSprite_m_searchPauseCount(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_searchPauseCount'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_searchPauseCount);
	return 1;
}

static int tolua_set_CGameSprite_m_searchPauseCount(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_searchPauseCount'", NULL);
	self->m_searchPauseCount = tolua_setter_tointeger<short>(L, "m_searchPauseCount");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_searchPauseCount(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_searchPauseCount'", NULL);
	tolua_pushusertype(L, (void*)&self->m_searchPauseCount, "Primitive<short>");
	return 1;
}

static int tolua_get_CGameSprite_m_attackFrame(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_attackFrame'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_attackFrame);
	return 1;
}

static int tolua_set_CGameSprite_m_attackFrame(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_attackFrame'", NULL);
	self->m_attackFrame = tolua_setter_tointeger<short>(L, "m_attackFrame");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_attackFrame(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_attackFrame'", NULL);
	tolua_pushusertype(L, (void*)&self->m_attackFrame, "Primitive<short>");
	return 1;
}

static int tolua_get_CGameSprite_m_newEffect(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_newEffect'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_newEffect);
	return 1;
}

static int tolua_set_CGameSprite_m_newEffect(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_newEffect'", NULL);
	self->m_newEffect = tolua_setter_tointeger<int>(L, "m_newEffect");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_newEffect(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_newEffect'", NULL);
	tolua_pushusertype(L, (void*)&self->m_newEffect, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameSprite_m_canDamage(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_canDamage'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_canDamage);
	return 1;
}

static int tolua_set_CGameSprite_m_canDamage(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_canDamage'", NULL);
	self->m_canDamage = tolua_setter_tointeger<byte>(L, "m_canDamage");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_canDamage(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_canDamage'", NULL);
	tolua_pushusertype(L, (void*)&self->m_canDamage, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameSprite_m_leftAttack(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_leftAttack'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_leftAttack);
	return 1;
}

static int tolua_set_CGameSprite_m_leftAttack(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_leftAttack'", NULL);
	self->m_leftAttack = tolua_setter_tointeger<int>(L, "m_leftAttack");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_leftAttack(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_leftAttack'", NULL);
	tolua_pushusertype(L, (void*)&self->m_leftAttack, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameSprite_m_hasColorEffects(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_hasColorEffects'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_hasColorEffects);
	return 1;
}

static int tolua_set_CGameSprite_m_hasColorEffects(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_hasColorEffects'", NULL);
	self->m_hasColorEffects = tolua_setter_tointeger<int>(L, "m_hasColorEffects");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_hasColorEffects(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_hasColorEffects'", NULL);
	tolua_pushusertype(L, (void*)&self->m_hasColorEffects, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameSprite_m_hasAnimationEffects(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_hasAnimationEffects'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_hasAnimationEffects);
	return 1;
}

static int tolua_set_CGameSprite_m_hasAnimationEffects(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_hasAnimationEffects'", NULL);
	self->m_hasAnimationEffects = tolua_setter_tointeger<int>(L, "m_hasAnimationEffects");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_hasAnimationEffects(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_hasAnimationEffects'", NULL);
	tolua_pushusertype(L, (void*)&self->m_hasAnimationEffects, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameSprite_m_targetId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_targetId);
	return 1;
}

static int tolua_set_CGameSprite_m_targetId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	self->m_targetId = tolua_setter_tointeger<int>(L, "m_targetId");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_targetId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	tolua_pushusertype(L, (void*)&self->m_targetId, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameSprite_m_dialog(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_dialog'", NULL);
	tolua_pushusertype(L, (void*)&self->m_dialog, "CResRef");
	return 1;
}

static int tolua_get_CGameSprite_m_startedSwing(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_startedSwing'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_startedSwing);
	return 1;
}

static int tolua_set_CGameSprite_m_startedSwing(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_startedSwing'", NULL);
	self->m_startedSwing = tolua_setter_tointeger<int>(L, "m_startedSwing");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_startedSwing(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_startedSwing'", NULL);
	tolua_pushusertype(L, (void*)&self->m_startedSwing, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameSprite_m_followCount(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_followCount'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_followCount);
	return 1;
}

static int tolua_set_CGameSprite_m_followCount(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_followCount'", NULL);
	self->m_followCount = tolua_setter_tointeger<short>(L, "m_followCount");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_followCount(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_followCount'", NULL);
	tolua_pushusertype(L, (void*)&self->m_followCount, "Primitive<short>");
	return 1;
}

static int tolua_get_CGameSprite_m_bForceVisualEffects(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bForceVisualEffects'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_bForceVisualEffects);
	return 1;
}

static int tolua_set_CGameSprite_m_bForceVisualEffects(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bForceVisualEffects'", NULL);
	self->m_bForceVisualEffects = tolua_setter_tointeger<int>(L, "m_bForceVisualEffects");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_bForceVisualEffects(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bForceVisualEffects'", NULL);
	tolua_pushusertype(L, (void*)&self->m_bForceVisualEffects, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameSprite_m_currentActionId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currentActionId'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_currentActionId);
	return 1;
}

static int tolua_set_CGameSprite_m_currentActionId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currentActionId'", NULL);
	self->m_currentActionId = tolua_setter_tointeger<short>(L, "m_currentActionId");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_currentActionId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currentActionId'", NULL);
	tolua_pushusertype(L, (void*)&self->m_currentActionId, "Primitive<short>");
	return 1;
}

static int tolua_get_CGameSprite_m_nWaitingOnDialog(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nWaitingOnDialog'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nWaitingOnDialog);
	return 1;
}

static int tolua_set_CGameSprite_m_nWaitingOnDialog(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nWaitingOnDialog'", NULL);
	self->m_nWaitingOnDialog = tolua_setter_tointeger<int>(L, "m_nWaitingOnDialog");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_nWaitingOnDialog(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nWaitingOnDialog'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nWaitingOnDialog, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameSprite_m_nCrossAreaChaseCounter(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCrossAreaChaseCounter'", NULL);
	lua_pushinteger(L, (lua_Integer)self->m_nCrossAreaChaseCounter);
	return 1;
}

static int tolua_set_CGameSprite_m_nCrossAreaChaseCounter(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCrossAreaChaseCounter'", NULL);
	self->m_nCrossAreaChaseCounter = tolua_setter_tointeger<int>(L, "m_nCrossAreaChaseCounter");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_nCrossAreaChaseCounter(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCrossAreaChaseCounter'", NULL);
	tolua_pushusertype(L, (void*)&self->m_nCrossAreaChaseCounter, "Primitive<int>");
	return 1;
}

static int tolua_get_CGameSprite_aPSTVisualEffectProjectiles(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'aPSTVisualEffectProjectiles'", NULL);
	tolua_pushusertype(L, (void*)&self->aPSTVisualEffectProjectiles, "Array<CProjectileUnknownPST2*,10>");
	return 1;
}

static int tolua_get_CGameSprite_nAttachedPSTVisualEffectProjectiles(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nAttachedPSTVisualEffectProjectiles'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nAttachedPSTVisualEffectProjectiles);
	return 1;
}

static int tolua_set_CGameSprite_nAttachedPSTVisualEffectProjectiles(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nAttachedPSTVisualEffectProjectiles'", NULL);
	self->nAttachedPSTVisualEffectProjectiles = tolua_setter_tointeger<byte>(L, "nAttachedPSTVisualEffectProjectiles");
	return 0;
}

static int tolua_get_CGameSprite_reference_nAttachedPSTVisualEffectProjectiles(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nAttachedPSTVisualEffectProjectiles'", NULL);
	tolua_pushusertype(L, (void*)&self->nAttachedPSTVisualEffectProjectiles, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameSprite_nPSTVisualEffectsSetToRender(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nPSTVisualEffectsSetToRender'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nPSTVisualEffectsSetToRender);
	return 1;
}

static int tolua_set_CGameSprite_nPSTVisualEffectsSetToRender(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nPSTVisualEffectsSetToRender'", NULL);
	self->nPSTVisualEffectsSetToRender = tolua_setter_tointeger<byte>(L, "nPSTVisualEffectsSetToRender");
	return 0;
}

static int tolua_get_CGameSprite_reference_nPSTVisualEffectsSetToRender(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nPSTVisualEffectsSetToRender'", NULL);
	tolua_pushusertype(L, (void*)&self->nPSTVisualEffectsSetToRender, "Primitive<byte>");
	return 1;
}

static int tolua_get_CGameSprite_m_savedLocation(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_savedLocation'", NULL);
	tolua_pushusertype(L, (void*)&self->m_savedLocation, "CPoint");
	return 1;
}

static int tolua_get_CGameSprite_nOverTriggerId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nOverTriggerId'", NULL);
	lua_pushinteger(L, (lua_Integer)self->nOverTriggerId);
	return 1;
}

static int tolua_set_CGameSprite_nOverTriggerId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nOverTriggerId'", NULL);
	self->nOverTriggerId = tolua_setter_tointeger<long>(L, "nOverTriggerId");
	return 0;
}

static int tolua_get_CGameSprite_reference_nOverTriggerId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nOverTriggerId'", NULL);
	tolua_pushusertype(L, (void*)&self->nOverTriggerId, "Primitive<long>");
	return 1;
}

static void tolua_reg_types(lua_State* L)
{
	tolua_usertype(L, "CGameAnimation");
	tolua_usertype(L, "CPtrList_CNode");
	tolua_usertype(L, "CResCell");
	tolua_usertype(L, "CVideo");
	tolua_usertype(L, "EngineGlobals");
	tolua_usertype(L, "Primitive<CGameObjectType>");
	tolua_usertype(L, "Primitive<DrawFeature>");
	tolua_usertype(L, "Primitive<PlayerScriptNameOrdinal>");
	tolua_usertype(L, "Primitive<VertListType>");
	tolua_usertype(L, "Primitive<long double>");
	tolua_usertype(L, "Primitive<uint16_t>");
	tolua_usertype(L, "Primitive<int>");
	tolua_usertype(L, "Primitive<int64_t>");
	tolua_usertype(L, "Primitive<intptr_t>");
	tolua_usertype(L, "Primitive<__int64>");
	tolua_usertype(L, "Primitive<long>");
	tolua_usertype(L, "Primitive<__int8>");
	tolua_usertype(L, "Primitive<double>");
	tolua_usertype(L, "Primitive<byte>");
	tolua_usertype(L, "Primitive<float>");
	tolua_usertype(L, "Primitive<__int16>");
	tolua_usertype(L, "Primitive<uint>");
	tolua_usertype(L, "Primitive<short>");
	tolua_usertype(L, "Primitive<int16_t>");
	tolua_usertype(L, "Primitive<uintptr_t>");
	tolua_usertype(L, "Primitive<char>");
	tolua_usertype(L, "Primitive<int8_t>");
	tolua_usertype(L, "Primitive<ushort>");
	tolua_usertype(L, "Primitive<bool>");
	tolua_usertype(L, "Primitive<int32_t>");
	tolua_usertype(L, "Primitive<uint64_t>");
	tolua_usertype(L, "Primitive<__int32>");
	tolua_usertype(L, "Primitive<size_t>");
	tolua_usertype(L, "Primitive<uint8_t>");
	tolua_usertype(L, "Primitive<uint32_t>");
	tolua_usertype(L, "Primitive<ptrdiff_t>");
	tolua_usertype(L, "UnmappedUserType");
	tolua_usertype(L, "VoidPointer");
	tolua_usertype(L, "__POSITION");
	tolua_usertype(L, "PlayerScriptNameOrdinal");
	tolua_usertype(L, "DrawFeature");
	tolua_usertype(L, "VertListType");
	tolua_usertype(L, "CGameObjectType");
	tolua_usertype(L, "CRect");
	tolua_usertype(L, "CPtrList");
	tolua_usertype(L, "CPoint");
	tolua_usertype(L, "CGameObjectArray");
	tolua_usertype(L, "EEex_CBaldurChitin");
	tolua_usertype(L, "CMessage");
	tolua_usertype(L, "CMessageVisualEffect");
	tolua_usertype(L, "CMessageAddEffect");
	tolua_usertype(L, "EEex_CTimerWorld");
	tolua_usertype(L, "CInfinity");
	tolua_usertype(L, "CGameTrigger");
	tolua_usertype(L, "CGameDoor");
	tolua_usertype(L, "CGameContainer");
	tolua_usertype(L, "Pointer<EEex_CBaldurChitin>");
	tolua_usertype(L, "Pointer<CObject>");
	tolua_usertype(L, "Pointer<CGameObject>");
	tolua_usertype(L, "Pointer<CGameArea>");
	tolua_usertype(L, "Pointer<const CPoint>");
	tolua_usertype(L, "Pointer<const CAIObjectType>");
	tolua_usertype(L, "Pointer<CPoint>");
	tolua_usertype(L, "Pointer<CTypedPtrList<CPtrList,long>::CNode>");
	tolua_usertype(L, "Pointer<unsigned int>");
	tolua_usertype(L, "Pointer<const CString>");
	tolua_usertype(L, "Pointer<CVidMode>");
	tolua_usertype(L, "Pointer<__POSITION>");
	tolua_usertype(L, "Pointer<const CAITrigger>");
	tolua_usertype(L, "Pointer<CGameAIBase>");
	tolua_usertype(L, "Pointer<const CAIAction>");
	tolua_usertype(L, "Pointer<CGameEffect>");
	tolua_usertype(L, "Pointer<CResRef>");
	tolua_usertype(L, "Pointer<CGameObject*>");
	tolua_usertype(L, "Pointer<Item_effect_st>");
	tolua_usertype(L, "Pointer<CProjectile>");
	tolua_usertype(L, "Pointer<EEex_CInfGame>");
	tolua_usertype(L, "Pointer<EEex_CScreenWorld>");
	tolua_usertype(L, "Pointer<CGameAnimationType>");
	tolua_usertype(L, "Pointer<CProjectileUnknownPST2>");
	tolua_usertype(L, "Pointer<CInfinity>");
	tolua_usertype(L, "Pointer<CVidCell>");
	tolua_usertype(L, "Pointer<CPtrList_CNode>");
	tolua_usertype(L, "Pointer<int>");
	tolua_usertype(L, "Pointer<CSoundImp>");
	tolua_usertype(L, "Pointer<CAreaTintOverride>");
	tolua_usertype(L, "Pointer<EEex_CBaldurChitin*>");
	tolua_usertype(L, "Pointer<CObject*>");
	tolua_usertype(L, "Pointer<CGameArea*>");
	tolua_usertype(L, "Pointer<const CPoint*>");
	tolua_usertype(L, "Pointer<const CAIObjectType*>");
	tolua_usertype(L, "Pointer<CPoint*>");
	tolua_usertype(L, "Pointer<CTypedPtrList<CPtrList,long>::CNode*>");
	tolua_usertype(L, "Pointer<unsigned int*>");
	tolua_usertype(L, "Pointer<const CString*>");
	tolua_usertype(L, "Pointer<CVidMode*>");
	tolua_usertype(L, "Pointer<__POSITION*>");
	tolua_usertype(L, "Pointer<const CAITrigger*>");
	tolua_usertype(L, "Pointer<CGameAIBase*>");
	tolua_usertype(L, "Pointer<const CAIAction*>");
	tolua_usertype(L, "Pointer<CGameEffect*>");
	tolua_usertype(L, "Pointer<CResRef*>");
	tolua_usertype(L, "Pointer<CGameObject**>");
	tolua_usertype(L, "Pointer<Item_effect_st*>");
	tolua_usertype(L, "Pointer<CProjectile*>");
	tolua_usertype(L, "Pointer<EEex_CInfGame*>");
	tolua_usertype(L, "Pointer<EEex_CScreenWorld*>");
	tolua_usertype(L, "Pointer<CGameAnimationType*>");
	tolua_usertype(L, "Pointer<CProjectileUnknownPST2*>");
	tolua_usertype(L, "Pointer<CInfinity*>");
	tolua_usertype(L, "Pointer<CVidCell*>");
	tolua_usertype(L, "Pointer<CPtrList_CNode*>");
	tolua_usertype(L, "Pointer<int*>");
	tolua_usertype(L, "Pointer<CSoundImp*>");
	tolua_usertype(L, "Pointer<CAreaTintOverride*>");
	tolua_usertype(L, "Pointer<CGameAnimation>");
	tolua_usertype(L, "Pointer<EEex_CInfButtonArray>");
	tolua_usertype(L, "Pointer<CPersistantEffectColorEffect>");
	tolua_usertype(L, "Pointer<CPlanescape>");
	tolua_usertype(L, "Pointer<CResCell>");
	tolua_usertype(L, "Pointer<CResCell*>");
	tolua_usertype(L, "Pointer<CSound>");
	tolua_usertype(L, "Pointer<CVidImage>");
	tolua_usertype(L, "Pointer<CVideo>");
	tolua_usertype(L, "Pointer<size_t>");
	tolua_usertype(L, "Pointer<uintptr_t>");
	tolua_usertype(L, "Pointer<CGameObjectType>");
	tolua_usertype(L, "Pointer<unsigned __int8>");
	tolua_usertype(L, "Pointer<long>");
	tolua_usertype(L, "Pointer<VertListType>");
	tolua_usertype(L, "Pointer<short>");
	tolua_usertype(L, "Pointer<__int8>");
	tolua_usertype(L, "Pointer<byte>");
	tolua_usertype(L, "Pointer<ushort>");
	tolua_usertype(L, "Pointer<uint>");
	tolua_usertype(L, "Pointer<double>");
	tolua_usertype(L, "Pointer<float>");
	tolua_usertype(L, "Pointer<__int32>");
	tolua_usertype(L, "Pointer<Primitive<long double>>");
	tolua_usertype(L, "Pointer<Primitive<uint16_t>>");
	tolua_usertype(L, "Pointer<Primitive<int>>");
	tolua_usertype(L, "Pointer<Primitive<int64_t>>");
	tolua_usertype(L, "Pointer<Primitive<intptr_t>>");
	tolua_usertype(L, "Pointer<Primitive<__int64>>");
	tolua_usertype(L, "Pointer<Primitive<long>>");
	tolua_usertype(L, "Pointer<Primitive<__int8>>");
	tolua_usertype(L, "Pointer<Primitive<double>>");
	tolua_usertype(L, "Pointer<Primitive<byte>>");
	tolua_usertype(L, "Pointer<Primitive<float>>");
	tolua_usertype(L, "Pointer<Primitive<__int16>>");
	tolua_usertype(L, "Pointer<Primitive<uint>>");
	tolua_usertype(L, "Pointer<Primitive<short>>");
	tolua_usertype(L, "Pointer<Primitive<int16_t>>");
	tolua_usertype(L, "Pointer<Primitive<uintptr_t>>");
	tolua_usertype(L, "Pointer<Primitive<char>>");
	tolua_usertype(L, "Pointer<Primitive<int8_t>>");
	tolua_usertype(L, "Pointer<Primitive<ushort>>");
	tolua_usertype(L, "Pointer<Primitive<bool>>");
	tolua_usertype(L, "Pointer<Primitive<int32_t>>");
	tolua_usertype(L, "Pointer<Primitive<uint64_t>>");
	tolua_usertype(L, "Pointer<Primitive<__int32>>");
	tolua_usertype(L, "Pointer<Primitive<size_t>>");
	tolua_usertype(L, "Pointer<Primitive<uint8_t>>");
	tolua_usertype(L, "Pointer<Primitive<uint32_t>>");
	tolua_usertype(L, "Pointer<Primitive<ptrdiff_t>>");
	tolua_usertype(L, "Pointer<void*>");
	tolua_usertype(L, "Pointer<UnmappedUserType>");
	tolua_usertype(L, "Pointer<PlayerScriptNameOrdinal>");
	tolua_usertype(L, "Pointer<DrawFeature>");
	tolua_usertype(L, "Pointer<byte*>");
	tolua_usertype(L, "Pointer<char*>");
	tolua_usertype(L, "Pointer<char>");
	tolua_usertype(L, "Pointer<const char*>");
	tolua_usertype(L, "Pointer<long double>");
	tolua_usertype(L, "Pointer<CRect>");
	tolua_usertype(L, "Pointer<CPtrList>");
	tolua_usertype(L, "Pointer<CGameObjectArray>");
	tolua_usertype(L, "Pointer<long*>");
	tolua_usertype(L, "Pointer<CMessage>");
	tolua_usertype(L, "Pointer<CMessageVisualEffect>");
	tolua_usertype(L, "Pointer<CMessageAddEffect>");
	tolua_usertype(L, "Pointer<EEex_CTimerWorld>");
	tolua_usertype(L, "Pointer<CGameTrigger>");
	tolua_usertype(L, "Pointer<CGameDoor>");
	tolua_usertype(L, "Pointer<CGameContainer>");
	tolua_usertype(L, "Pointer<CharString*>");
	tolua_usertype(L, "Pointer<CString>");
	tolua_usertype(L, "Pointer<CObject::vtbl>");
	tolua_usertype(L, "Pointer<CTypedPtrList<CPtrList,long>>");
	tolua_usertype(L, "Pointer<CTypedPtrList<CPtrList,CGameEffect*>>");
	tolua_usertype(L, "Pointer<CTypedPtrList<CPtrList,int*>>");
	tolua_usertype(L, "Pointer<CTypedPtrList<CPtrList,int>>");
	tolua_usertype(L, "Pointer<CGameArea**>");
	tolua_usertype(L, "Pointer<CGameEffectList>");
	tolua_usertype(L, "Pointer<CGameObject::vtbl>");
	tolua_usertype(L, "Pointer<LCharString<32>>");
	tolua_usertype(L, "Pointer<CResHelper<CResCell,1000>>");
	tolua_usertype(L, "Pointer<CGameEffectBase>");
	tolua_usertype(L, "Pointer<CDerivedStats>");
	tolua_usertype(L, "Pointer<CAreaVariable>");
	tolua_usertype(L, "Pointer<CVariable>");
	tolua_usertype(L, "Pointer<CAIObjectType>");
	tolua_usertype(L, "Pointer<CAIAction>");
	tolua_usertype(L, "Pointer<CProjectile::vtbl>");
	tolua_usertype(L, "Pointer<CProjectileBAM::vtbl>");
	tolua_usertype(L, "Pointer<CProjectileBAM>");
	tolua_usertype(L, "Pointer<CProjectileArea>");
	tolua_usertype(L, "Pointer<CProjectileUnknownPST>");
	tolua_usertype(L, "Pointer<CProjectileUnknownPST2**>");
	tolua_usertype(L, "Pointer<CProjectileUnknownBase>");
	tolua_usertype(L, "Pointer<CProjectile205>");
	tolua_usertype(L, "Pointer<CAITrigger>");
	tolua_usertype(L, "Pointer<CMessageSetTrigger>");
	tolua_usertype(L, "Pointer<CGameSprite>");
	tolua_usertype(L, "CharString");
	tolua_usertype(L, "CString");
	tolua_usertype(L, "CObject");
	tolua_usertype(L, "CObject::vtbl");
	tolua_usertype(L, "CTypedPtrList<CPtrList,long>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,long>::CNode");
	tolua_usertype(L, "CTypedPtrList<CPtrList,long>::vtbl");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CGameEffect*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CGameEffect*>::vtbl");
	tolua_usertype(L, "CTypedPtrList<CPtrList,int*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,int*>::CNode");
	tolua_usertype(L, "CTypedPtrList<CPtrList,int*>::vtbl");
	tolua_usertype(L, "CTypedPtrList<CPtrList,int>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,int>::CNode");
	tolua_usertype(L, "CTypedPtrList<CPtrList,int>::vtbl");
	tolua_usertype(L, "CAreaTintOverride");
	tolua_usertype(L, "CGameArea");
	tolua_usertype(L, "CGameEffectList");
	tolua_usertype(L, "Array<uchar,8>");
	tolua_usertype(L, "Array<CProjectileUnknownPST2*,10>");
	tolua_usertype(L, "Array<ulong,15>");
	tolua_usertype(L, "Array<char,32>");
	tolua_usertype(L, "Array<CGameArea*,12>");
	tolua_usertype(L, "Array<long,6>");
	tolua_usertype(L, "Array<ulong,8>");
	tolua_usertype(L, "Array<byte,5>");
	tolua_usertype(L, "LCharString<32>");
	tolua_usertype(L, "CResRef");
	tolua_usertype(L, "Item_effect_st");
	tolua_usertype(L, "CResHelper<CResCell,1000>");
	tolua_usertype(L, "CVidCell");
	tolua_usertype(L, "EEex_CInfGame");
	tolua_usertype(L, "CGameEffectBase");
	tolua_usertype(L, "CGameEffect");
	tolua_usertype(L, "CDerivedStats");
	tolua_usertype(L, "CAreaVariable");
	tolua_usertype(L, "CVariable");
	tolua_usertype(L, "CAIObjectType");
	tolua_usertype(L, "CAIAction");
	tolua_usertype(L, "CGameObject");
	tolua_usertype(L, "CGameObject::vtbl");
	tolua_usertype(L, "CProjectile");
	tolua_usertype(L, "CProjectile::vtbl");
	tolua_usertype(L, "CProjectileBAM");
	tolua_usertype(L, "CProjectileBAM::vtbl");
	tolua_usertype(L, "CProjectileArea");
	tolua_usertype(L, "CProjectileUnknownPST");
	tolua_usertype(L, "CProjectileUnknownPST::vtbl");
	tolua_usertype(L, "CProjectileUnknownPST2");
	tolua_usertype(L, "CProjectile205");
	tolua_usertype(L, "CAITrigger");
	tolua_usertype(L, "CMessageSetTrigger");
	tolua_usertype(L, "CGameAIBase");
	tolua_usertype(L, "CGameAIBase::vtbl");
	tolua_usertype(L, "CGameSprite");
}

void registerBaseclasses();
int OpenBindingsInternal(lua_State* L)
{
	registerBaseclasses();
	tolua_open(L);
	tolua_reg_types(L);
	tolua_module(L, NULL, 0);
	tolua_beginmodule(L, NULL);
	tolua_cclass(L, "CGameAnimation", "CGameAnimation", {}, NULL);
	tolua_beginmodule(L, "CGameAnimation");
		tolua_variable(L, "m_animation", tolua_get_CGameAnimation_m_animation, tolua_set_CGameAnimation_m_animation);
		tolua_variable(L, "reference_m_animation", tolua_get_CGameAnimation_reference_m_animation, NULL);
		tolua_constant(L, "sizeof", sizeof(CGameAnimation));
	tolua_endmodule(L);
	tolua_cclass(L, "CPtrList_CNode", "CPtrList_CNode", {}, NULL);
	tolua_beginmodule(L, "CPtrList_CNode");
		tolua_variable(L, "pNext", tolua_get_CPtrList_CNode_pNext, tolua_set_CPtrList_CNode_pNext);
		tolua_variable(L, "reference_pNext", tolua_get_CPtrList_CNode_reference_pNext, NULL);
		tolua_variable(L, "pPrev", tolua_get_CPtrList_CNode_pPrev, tolua_set_CPtrList_CNode_pPrev);
		tolua_variable(L, "reference_pPrev", tolua_get_CPtrList_CNode_reference_pPrev, NULL);
		tolua_variable(L, "data", tolua_get_CPtrList_CNode_data, tolua_set_CPtrList_CNode_data);
		tolua_variable(L, "reference_data", tolua_get_CPtrList_CNode_reference_data, NULL);
		tolua_constant(L, "sizeof", sizeof(CPtrList_CNode));
	tolua_endmodule(L);
	tolua_cclass(L, "CResCell", "CResCell", {}, NULL);
	tolua_beginmodule(L, "CResCell");
		tolua_constant(L, "sizeof", sizeof(CResCell));
	tolua_endmodule(L);
	tolua_cclass(L, "CVideo", "CVideo", {}, NULL);
	tolua_beginmodule(L, "CVideo");
		tolua_variable(L, "pCurrentMode", tolua_get_CVideo_pCurrentMode, tolua_set_CVideo_pCurrentMode);
		tolua_variable(L, "reference_pCurrentMode", tolua_get_CVideo_reference_pCurrentMode, NULL);
		tolua_constant(L, "sizeof", sizeof(CVideo));
	tolua_endmodule(L);
	tolua_cclass(L, "EngineGlobals", "EngineGlobals", {}, NULL);
	tolua_beginmodule(L, "EngineGlobals");
		tolua_variable(L, "g_pBaldurChitin", tolua_get_g_pBaldurChitin, tolua_set_g_pBaldurChitin);
		tolua_variable(L, "reference_g_pBaldurChitin", tolua_get_reference_g_pBaldurChitin, NULL);
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<CGameObjectType>", "Primitive<CGameObjectType>", {}, NULL);
	tolua_beginmodule(L, "Primitive<CGameObjectType>");
		tolua_variable(L, "value", tolua_get_Primitive_CGameObjectType__value, tolua_set_Primitive_CGameObjectType__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_CGameObjectType__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<CGameObjectType>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<DrawFeature>", "Primitive<DrawFeature>", {}, NULL);
	tolua_beginmodule(L, "Primitive<DrawFeature>");
		tolua_variable(L, "value", tolua_get_Primitive_DrawFeature__value, tolua_set_Primitive_DrawFeature__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_DrawFeature__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<DrawFeature>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<PlayerScriptNameOrdinal>", "Primitive<PlayerScriptNameOrdinal>", {}, NULL);
	tolua_beginmodule(L, "Primitive<PlayerScriptNameOrdinal>");
		tolua_variable(L, "value", tolua_get_Primitive_PlayerScriptNameOrdinal__value, tolua_set_Primitive_PlayerScriptNameOrdinal__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_PlayerScriptNameOrdinal__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<PlayerScriptNameOrdinal>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<VertListType>", "Primitive<VertListType>", {}, NULL);
	tolua_beginmodule(L, "Primitive<VertListType>");
		tolua_variable(L, "value", tolua_get_Primitive_VertListType__value, tolua_set_Primitive_VertListType__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_VertListType__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<VertListType>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<long double>", "Primitive<long double>", {}, NULL);
	tolua_beginmodule(L, "Primitive<long double>");
		tolua_variable(L, "value", tolua_get_Primitive_long_double__value, tolua_set_Primitive_long_double__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_long_double__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<long double>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<uint16_t>", "Primitive<uint16_t>", {}, NULL);
	tolua_beginmodule(L, "Primitive<uint16_t>");
		tolua_variable(L, "value", tolua_get_Primitive_uint16_t__value, tolua_set_Primitive_uint16_t__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_uint16_t__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<uint16_t>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<int>", "Primitive<int>", {}, NULL);
	tolua_beginmodule(L, "Primitive<int>");
		tolua_variable(L, "value", tolua_get_Primitive_int__value, tolua_set_Primitive_int__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_int__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<int>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<int64_t>", "Primitive<int64_t>", {}, NULL);
	tolua_beginmodule(L, "Primitive<int64_t>");
		tolua_variable(L, "value", tolua_get_Primitive_int64_t__value, tolua_set_Primitive_int64_t__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_int64_t__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<int64_t>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<intptr_t>", "Primitive<intptr_t>", {}, NULL);
	tolua_beginmodule(L, "Primitive<intptr_t>");
		tolua_variable(L, "value", tolua_get_Primitive_intptr_t__value, tolua_set_Primitive_intptr_t__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_intptr_t__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<intptr_t>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<__int64>", "Primitive<__int64>", {}, NULL);
	tolua_beginmodule(L, "Primitive<__int64>");
		tolua_variable(L, "value", tolua_get_Primitive___int64__value, tolua_set_Primitive___int64__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive___int64__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<__int64>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<long>", "Primitive<long>", {}, NULL);
	tolua_beginmodule(L, "Primitive<long>");
		tolua_variable(L, "value", tolua_get_Primitive_long__value, tolua_set_Primitive_long__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_long__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<long>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<__int8>", "Primitive<__int8>", {}, NULL);
	tolua_beginmodule(L, "Primitive<__int8>");
		tolua_variable(L, "value", tolua_get_Primitive___int8__value, tolua_set_Primitive___int8__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive___int8__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<__int8>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<double>", "Primitive<double>", {}, NULL);
	tolua_beginmodule(L, "Primitive<double>");
		tolua_variable(L, "value", tolua_get_Primitive_double__value, tolua_set_Primitive_double__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_double__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<double>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<byte>", "Primitive<byte>", {}, NULL);
	tolua_beginmodule(L, "Primitive<byte>");
		tolua_variable(L, "value", tolua_get_Primitive_byte__value, tolua_set_Primitive_byte__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_byte__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<byte>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<float>", "Primitive<float>", {}, NULL);
	tolua_beginmodule(L, "Primitive<float>");
		tolua_variable(L, "value", tolua_get_Primitive_float__value, tolua_set_Primitive_float__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_float__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<float>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<__int16>", "Primitive<__int16>", {}, NULL);
	tolua_beginmodule(L, "Primitive<__int16>");
		tolua_variable(L, "value", tolua_get_Primitive___int16__value, tolua_set_Primitive___int16__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive___int16__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<__int16>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<uint>", "Primitive<uint>", {}, NULL);
	tolua_beginmodule(L, "Primitive<uint>");
		tolua_variable(L, "value", tolua_get_Primitive_uint__value, tolua_set_Primitive_uint__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_uint__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<uint>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<short>", "Primitive<short>", {}, NULL);
	tolua_beginmodule(L, "Primitive<short>");
		tolua_variable(L, "value", tolua_get_Primitive_short__value, tolua_set_Primitive_short__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_short__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<short>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<int16_t>", "Primitive<int16_t>", {}, NULL);
	tolua_beginmodule(L, "Primitive<int16_t>");
		tolua_variable(L, "value", tolua_get_Primitive_int16_t__value, tolua_set_Primitive_int16_t__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_int16_t__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<int16_t>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<uintptr_t>", "Primitive<uintptr_t>", {}, NULL);
	tolua_beginmodule(L, "Primitive<uintptr_t>");
		tolua_variable(L, "value", tolua_get_Primitive_uintptr_t__value, tolua_set_Primitive_uintptr_t__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_uintptr_t__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<uintptr_t>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<char>", "Primitive<char>", {}, NULL);
	tolua_beginmodule(L, "Primitive<char>");
		tolua_variable(L, "value", tolua_get_Primitive_char__value, tolua_set_Primitive_char__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_char__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<char>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<int8_t>", "Primitive<int8_t>", {}, NULL);
	tolua_beginmodule(L, "Primitive<int8_t>");
		tolua_variable(L, "value", tolua_get_Primitive_int8_t__value, tolua_set_Primitive_int8_t__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_int8_t__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<int8_t>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<ushort>", "Primitive<ushort>", {}, NULL);
	tolua_beginmodule(L, "Primitive<ushort>");
		tolua_variable(L, "value", tolua_get_Primitive_ushort__value, tolua_set_Primitive_ushort__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_ushort__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<ushort>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<bool>", "Primitive<bool>", {}, NULL);
	tolua_beginmodule(L, "Primitive<bool>");
		tolua_variable(L, "value", tolua_get_Primitive_bool__value, tolua_set_Primitive_bool__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_bool__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<bool>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<int32_t>", "Primitive<int32_t>", {}, NULL);
	tolua_beginmodule(L, "Primitive<int32_t>");
		tolua_variable(L, "value", tolua_get_Primitive_int32_t__value, tolua_set_Primitive_int32_t__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_int32_t__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<int32_t>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<uint64_t>", "Primitive<uint64_t>", {}, NULL);
	tolua_beginmodule(L, "Primitive<uint64_t>");
		tolua_variable(L, "value", tolua_get_Primitive_uint64_t__value, tolua_set_Primitive_uint64_t__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_uint64_t__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<uint64_t>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<__int32>", "Primitive<__int32>", {}, NULL);
	tolua_beginmodule(L, "Primitive<__int32>");
		tolua_variable(L, "value", tolua_get_Primitive___int32__value, tolua_set_Primitive___int32__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive___int32__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<__int32>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<size_t>", "Primitive<size_t>", {}, NULL);
	tolua_beginmodule(L, "Primitive<size_t>");
		tolua_variable(L, "value", tolua_get_Primitive_size_t__value, tolua_set_Primitive_size_t__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_size_t__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<size_t>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<uint8_t>", "Primitive<uint8_t>", {}, NULL);
	tolua_beginmodule(L, "Primitive<uint8_t>");
		tolua_variable(L, "value", tolua_get_Primitive_uint8_t__value, tolua_set_Primitive_uint8_t__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_uint8_t__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<uint8_t>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<uint32_t>", "Primitive<uint32_t>", {}, NULL);
	tolua_beginmodule(L, "Primitive<uint32_t>");
		tolua_variable(L, "value", tolua_get_Primitive_uint32_t__value, tolua_set_Primitive_uint32_t__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_uint32_t__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<uint32_t>));
	tolua_endmodule(L);
	tolua_cclass(L, "Primitive<ptrdiff_t>", "Primitive<ptrdiff_t>", {}, NULL);
	tolua_beginmodule(L, "Primitive<ptrdiff_t>");
		tolua_variable(L, "value", tolua_get_Primitive_ptrdiff_t__value, tolua_set_Primitive_ptrdiff_t__value);
		tolua_variable(L, "reference_value", tolua_get_Primitive_ptrdiff_t__reference_value, NULL);
		tolua_constant(L, "sizeof", sizeof(Primitive<ptrdiff_t>));
	tolua_endmodule(L);
	tolua_cclass(L, "UnmappedUserType", "UnmappedUserType", {}, NULL);
	tolua_beginmodule(L, "UnmappedUserType");
		tolua_constant(L, "sizeof", sizeof(UnmappedUserType));
	tolua_endmodule(L);
	tolua_cclass(L, "VoidPointer", "VoidPointer", {}, NULL);
	tolua_beginmodule(L, "VoidPointer");
		tolua_variable(L, "reference", tolua_get_VoidPointer_reference, tolua_set_VoidPointer_reference);
		tolua_constant(L, "sizeof", sizeof(VoidPointer));
	tolua_endmodule(L);
	tolua_cclass(L, "__POSITION", "__POSITION", {}, NULL);
	tolua_beginmodule(L, "__POSITION");
		tolua_constant(L, "sizeof", sizeof(__POSITION));
	tolua_endmodule(L);
	tolua_cclass(L, "PlayerScriptNameOrdinal", "PlayerScriptNameOrdinal", {"__int32"}, NULL);
	tolua_beginmodule(L, "PlayerScriptNameOrdinal");
		tolua_constant(L, "NAMELESS", 0);
		tolua_constant(L, "ANNAH", 1);
		tolua_constant(L, "IGNUS", 2);
		tolua_constant(L, "GRACE", 3);
		tolua_constant(L, "NORDOM", 4);
		tolua_constant(L, "VHAIL", 5);
		tolua_constant(L, "MORTE", 6);
		tolua_constant(L, "DAKKON", 7);
		tolua_constant(L, "INVALID", -1);
	tolua_endmodule(L);
	tolua_cclass(L, "DrawFeature", "DrawFeature", {"__int32"}, NULL);
	tolua_beginmodule(L, "DrawFeature");
		tolua_constant(L, "DRAW_BLEND", 3042);
		tolua_constant(L, "DRAW_SCISSOR_TEST", 3089);
		tolua_constant(L, "DRAW_RENDER_YUV", 3090);
		tolua_constant(L, "DRAW_TEXTURE_2D", 3553);
	tolua_endmodule(L);
	tolua_cclass(L, "VertListType", "VertListType", {"__int8"}, NULL);
	tolua_beginmodule(L, "VertListType");
		tolua_constant(L, "LIST_FRONT", 0);
		tolua_constant(L, "LIST_BACK", 1);
		tolua_constant(L, "LIST_FLIGHT", 2);
		tolua_constant(L, "LIST_UNDER", 3);
	tolua_endmodule(L);
	tolua_cclass(L, "CGameObjectType", "CGameObjectType", {"__int8"}, NULL);
	tolua_beginmodule(L, "CGameObjectType");
		tolua_constant(L, "NONE", 0);
		tolua_constant(L, "AIBASE", 1);
		tolua_constant(L, "SOUND", 16);
		tolua_constant(L, "CONTAINER", 17);
		tolua_constant(L, "SPAWNING", 32);
		tolua_constant(L, "DOOR", 33);
		tolua_constant(L, "STATIC", 48);
		tolua_constant(L, "SPRITE", 49);
		tolua_constant(L, "OBJECT_MARKER", 64);
		tolua_constant(L, "TRIGGER", 65);
		tolua_constant(L, "TILED_OBJECT", 81);
		tolua_constant(L, "TEMPORAL", 96);
		tolua_constant(L, "AREA_AI", 97);
		tolua_constant(L, "FIREBALL", 112);
		tolua_constant(L, "GAME_AI", 113);
	tolua_endmodule(L);
	tolua_cclass(L, "CRect", "CRect", {}, NULL);
	tolua_beginmodule(L, "CRect");
		tolua_variable(L, "left", tolua_get_CRect_left, tolua_set_CRect_left);
		tolua_variable(L, "reference_left", tolua_get_CRect_reference_left, NULL);
		tolua_variable(L, "top", tolua_get_CRect_top, tolua_set_CRect_top);
		tolua_variable(L, "reference_top", tolua_get_CRect_reference_top, NULL);
		tolua_variable(L, "right", tolua_get_CRect_right, tolua_set_CRect_right);
		tolua_variable(L, "reference_right", tolua_get_CRect_reference_right, NULL);
		tolua_variable(L, "bottom", tolua_get_CRect_bottom, tolua_set_CRect_bottom);
		tolua_variable(L, "reference_bottom", tolua_get_CRect_reference_bottom, NULL);
		tolua_constant(L, "sizeof", sizeof(CRect));
	tolua_endmodule(L);
	tolua_cclass(L, "CPtrList", "CPtrList", {}, NULL);
	tolua_beginmodule(L, "CPtrList");
		tolua_variable(L, "m_pNodeHead", tolua_get_CPtrList_m_pNodeHead, tolua_set_CPtrList_m_pNodeHead);
		tolua_variable(L, "reference_m_pNodeHead", tolua_get_CPtrList_reference_m_pNodeHead, NULL);
		tolua_variable(L, "m_pNodeTail", tolua_get_CPtrList_m_pNodeTail, tolua_set_CPtrList_m_pNodeTail);
		tolua_variable(L, "reference_m_pNodeTail", tolua_get_CPtrList_reference_m_pNodeTail, NULL);
		tolua_variable(L, "m_nCount", tolua_get_CPtrList_m_nCount, tolua_set_CPtrList_m_nCount);
		tolua_variable(L, "reference_m_nCount", tolua_get_CPtrList_reference_m_nCount, NULL);
		tolua_variable(L, "m_pNodeFree", tolua_get_CPtrList_m_pNodeFree, tolua_set_CPtrList_m_pNodeFree);
		tolua_variable(L, "reference_m_pNodeFree", tolua_get_CPtrList_reference_m_pNodeFree, NULL);
		tolua_variable(L, "m_pBlocks", tolua_get_CPtrList_m_pBlocks, tolua_set_CPtrList_m_pBlocks);
		tolua_variable(L, "reference_m_pBlocks", tolua_get_CPtrList_reference_m_pBlocks, NULL);
		tolua_variable(L, "m_nBlockSize", tolua_get_CPtrList_m_nBlockSize, tolua_set_CPtrList_m_nBlockSize);
		tolua_variable(L, "reference_m_nBlockSize", tolua_get_CPtrList_reference_m_nBlockSize, NULL);
		tolua_constant(L, "sizeof", sizeof(CPtrList));
	tolua_endmodule(L);
	tolua_cclass(L, "CPoint", "CPoint", {}, NULL);
	tolua_beginmodule(L, "CPoint");
		tolua_variable(L, "x", tolua_get_CPoint_x, tolua_set_CPoint_x);
		tolua_variable(L, "reference_x", tolua_get_CPoint_reference_x, NULL);
		tolua_variable(L, "y", tolua_get_CPoint_y, tolua_set_CPoint_y);
		tolua_variable(L, "reference_y", tolua_get_CPoint_reference_y, NULL);
		tolua_constant(L, "sizeof", sizeof(CPoint));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameObjectArray", "CGameObjectArray", {}, NULL);
	tolua_beginmodule(L, "CGameObjectArray");
		tolua_variable(L, "reference_GetShare", tolua_get_reference_CGameObjectArray_GetShare, NULL);
		tolua_function(L, "GetShare", &tolua_function_CGameObjectArray_GetShare);
		tolua_constant(L, "sizeof", sizeof(CGameObjectArray));
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CBaldurChitin", "EEex_CBaldurChitin", {}, NULL);
	tolua_beginmodule(L, "EEex_CBaldurChitin");
		tolua_variable(L, "pActiveEngine", tolua_get_CBaldurChitin_pActiveEngine, tolua_set_CBaldurChitin_pActiveEngine);
		tolua_variable(L, "reference_pActiveEngine", tolua_get_CBaldurChitin_reference_pActiveEngine, NULL);
		tolua_variable(L, "cVideo", tolua_get_CBaldurChitin_cVideo, NULL);
		tolua_variable(L, "m_bConnectionEstablished", tolua_get_CBaldurChitin_m_bConnectionEstablished, tolua_set_CBaldurChitin_m_bConnectionEstablished);
		tolua_variable(L, "reference_m_bConnectionEstablished", tolua_get_CBaldurChitin_reference_m_bConnectionEstablished, NULL);
		tolua_variable(L, "m_idLocalPlayer", tolua_get_CBaldurChitin_m_idLocalPlayer, tolua_set_CBaldurChitin_m_idLocalPlayer);
		tolua_variable(L, "reference_m_idLocalPlayer", tolua_get_CBaldurChitin_reference_m_idLocalPlayer, NULL);
		tolua_variable(L, "m_pObjectGame", tolua_get_CBaldurChitin_m_pObjectGame, tolua_set_CBaldurChitin_m_pObjectGame);
		tolua_variable(L, "reference_m_pObjectGame", tolua_get_CBaldurChitin_reference_m_pObjectGame, NULL);
		tolua_variable(L, "m_pEngineMap", tolua_get_CBaldurChitin_m_pEngineMap, tolua_set_CBaldurChitin_m_pEngineMap);
		tolua_variable(L, "reference_m_pEngineMap", tolua_get_CBaldurChitin_reference_m_pEngineMap, NULL);
		tolua_variable(L, "m_pEngineWorld", tolua_get_CBaldurChitin_m_pEngineWorld, tolua_set_CBaldurChitin_m_pEngineWorld);
		tolua_variable(L, "reference_m_pEngineWorld", tolua_get_CBaldurChitin_reference_m_pEngineWorld, NULL);
		tolua_variable(L, "m_cMessageHandler", tolua_get_CBaldurChitin_m_cMessageHandler, tolua_set_CBaldurChitin_m_cMessageHandler);
		tolua_variable(L, "reference_m_cMessageHandler", tolua_get_CBaldurChitin_reference_m_cMessageHandler, NULL);
		tolua_constant(L, "sizeof", sizeof(CBaldurChitin));
	tolua_endmodule(L);
	tolua_cclass(L, "CMessage", "CMessage", {}, NULL);
	tolua_beginmodule(L, "CMessage");
		tolua_variable(L, "m_targetId", tolua_get_CMessage_m_targetId, tolua_set_CMessage_m_targetId);
		tolua_variable(L, "reference_m_targetId", tolua_get_CMessage_reference_m_targetId, NULL);
		tolua_variable(L, "m_sourceId", tolua_get_CMessage_m_sourceId, tolua_set_CMessage_m_sourceId);
		tolua_variable(L, "reference_m_sourceId", tolua_get_CMessage_reference_m_sourceId, NULL);
		tolua_constant(L, "sizeof", sizeof(CMessage));
	tolua_endmodule(L);
	tolua_cclass(L, "CMessageVisualEffect", "CMessageVisualEffect", {"CMessage"}, NULL);
	tolua_beginmodule(L, "CMessageVisualEffect");
		tolua_variable(L, "m_nEffectType", tolua_get_CMessageVisualEffect_m_nEffectType, tolua_set_CMessageVisualEffect_m_nEffectType);
		tolua_variable(L, "reference_m_nEffectType", tolua_get_CMessageVisualEffect_reference_m_nEffectType, NULL);
		tolua_variable(L, "m_nEffectProperty", tolua_get_CMessageVisualEffect_m_nEffectProperty, tolua_set_CMessageVisualEffect_m_nEffectProperty);
		tolua_variable(L, "reference_m_nEffectProperty", tolua_get_CMessageVisualEffect_reference_m_nEffectProperty, NULL);
		tolua_constant(L, "sizeof", sizeof(CMessageVisualEffect));
	tolua_endmodule(L);
	tolua_cclass(L, "CMessageAddEffect", "CMessageAddEffect", {"CMessage"}, NULL);
	tolua_beginmodule(L, "CMessageAddEffect");
		tolua_variable(L, "m_effect", tolua_get_CMessageAddEffect_m_effect, tolua_set_CMessageAddEffect_m_effect);
		tolua_variable(L, "reference_m_effect", tolua_get_CMessageAddEffect_reference_m_effect, NULL);
		tolua_variable(L, "m_noSave", tolua_get_CMessageAddEffect_m_noSave, tolua_set_CMessageAddEffect_m_noSave);
		tolua_variable(L, "reference_m_noSave", tolua_get_CMessageAddEffect_reference_m_noSave, NULL);
		tolua_constant(L, "sizeof", sizeof(CMessageAddEffect));
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CTimerWorld", "EEex_CTimerWorld", {}, NULL);
	tolua_beginmodule(L, "EEex_CTimerWorld");
		tolua_variable(L, "m_gameTime", tolua_get_CTimerWorld_m_gameTime, tolua_set_CTimerWorld_m_gameTime);
		tolua_variable(L, "reference_m_gameTime", tolua_get_CTimerWorld_reference_m_gameTime, NULL);
		tolua_variable(L, "m_active", tolua_get_CTimerWorld_m_active, tolua_set_CTimerWorld_m_active);
		tolua_variable(L, "reference_m_active", tolua_get_CTimerWorld_reference_m_active, NULL);
		tolua_variable(L, "m_nLastPercentage", tolua_get_CTimerWorld_m_nLastPercentage, tolua_set_CTimerWorld_m_nLastPercentage);
		tolua_variable(L, "reference_m_nLastPercentage", tolua_get_CTimerWorld_reference_m_nLastPercentage, NULL);
		tolua_constant(L, "sizeof", sizeof(CTimerWorld));
	tolua_endmodule(L);
	tolua_cclass(L, "CInfinity", "CInfinity", {}, NULL);
	tolua_beginmodule(L, "CInfinity");
		tolua_variable(L, "rViewPortNotZoomed", tolua_get_CInfinity_rViewPortNotZoomed, NULL);
		tolua_variable(L, "rViewPort", tolua_get_CInfinity_rViewPort, NULL);
		tolua_variable(L, "m_areaTintOverride", tolua_get_CInfinity_m_areaTintOverride, tolua_set_CInfinity_m_areaTintOverride);
		tolua_variable(L, "reference_m_areaTintOverride", tolua_get_CInfinity_reference_m_areaTintOverride, NULL);
		tolua_variable(L, "m_rgbAreaTintGlobalLightingOverride", tolua_get_CInfinity_m_rgbAreaTintGlobalLightingOverride, tolua_set_CInfinity_m_rgbAreaTintGlobalLightingOverride);
		tolua_variable(L, "reference_m_rgbAreaTintGlobalLightingOverride", tolua_get_CInfinity_reference_m_rgbAreaTintGlobalLightingOverride, NULL);
		tolua_variable(L, "unknownPSTGlobalTint", tolua_get_CInfinity_unknownPSTGlobalTint, tolua_set_CInfinity_unknownPSTGlobalTint);
		tolua_variable(L, "reference_unknownPSTGlobalTint", tolua_get_CInfinity_reference_unknownPSTGlobalTint, NULL);
		tolua_variable(L, "nFlashViewportWhiteCounter", tolua_get_CInfinity_nFlashViewportWhiteCounter, tolua_set_CInfinity_nFlashViewportWhiteCounter);
		tolua_variable(L, "reference_nFlashViewportWhiteCounter", tolua_get_CInfinity_reference_nFlashViewportWhiteCounter, NULL);
		tolua_variable(L, "m_renderDayNightCode", tolua_get_CInfinity_m_renderDayNightCode, tolua_set_CInfinity_m_renderDayNightCode);
		tolua_variable(L, "reference_m_renderDayNightCode", tolua_get_CInfinity_reference_m_renderDayNightCode, NULL);
		tolua_variable(L, "m_rgbLightningGlobalLighting", tolua_get_CInfinity_m_rgbLightningGlobalLighting, tolua_set_CInfinity_m_rgbLightningGlobalLighting);
		tolua_variable(L, "reference_m_rgbLightningGlobalLighting", tolua_get_CInfinity_reference_m_rgbLightningGlobalLighting, NULL);
		tolua_variable(L, "m_rgbOverCastGlobalLighting", tolua_get_CInfinity_m_rgbOverCastGlobalLighting, tolua_set_CInfinity_m_rgbOverCastGlobalLighting);
		tolua_variable(L, "reference_m_rgbOverCastGlobalLighting", tolua_get_CInfinity_reference_m_rgbOverCastGlobalLighting, NULL);
		tolua_variable(L, "m_rgbTimeOfDayGlobalLighting", tolua_get_CInfinity_m_rgbTimeOfDayGlobalLighting, tolua_set_CInfinity_m_rgbTimeOfDayGlobalLighting);
		tolua_variable(L, "reference_m_rgbTimeOfDayGlobalLighting", tolua_get_CInfinity_reference_m_rgbTimeOfDayGlobalLighting, NULL);
		tolua_variable(L, "m_pArea", tolua_get_CInfinity_m_pArea, tolua_set_CInfinity_m_pArea);
		tolua_variable(L, "reference_m_pArea", tolua_get_CInfinity_reference_m_pArea, NULL);
		tolua_constant(L, "sizeof", sizeof(CInfinity));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameTrigger", "CGameTrigger", {}, NULL);
	tolua_beginmodule(L, "CGameTrigger");
		tolua_variable(L, "m_pos", tolua_get_CGameTrigger_m_pos, NULL);
		tolua_variable(L, "m_pArea", tolua_get_CGameTrigger_m_pArea, tolua_set_CGameTrigger_m_pArea);
		tolua_variable(L, "reference_m_pArea", tolua_get_CGameTrigger_reference_m_pArea, NULL);
		tolua_variable(L, "m_posVertList", tolua_get_CGameTrigger_m_posVertList, tolua_set_CGameTrigger_m_posVertList);
		tolua_variable(L, "reference_m_posVertList", tolua_get_CGameTrigger_reference_m_posVertList, NULL);
		tolua_variable(L, "m_id", tolua_get_CGameTrigger_m_id, tolua_set_CGameTrigger_m_id);
		tolua_variable(L, "reference_m_id", tolua_get_CGameTrigger_reference_m_id, NULL);
		tolua_variable(L, "m_remotePlayerID", tolua_get_CGameTrigger_m_remotePlayerID, tolua_set_CGameTrigger_m_remotePlayerID);
		tolua_variable(L, "reference_m_remotePlayerID", tolua_get_CGameTrigger_reference_m_remotePlayerID, NULL);
		tolua_variable(L, "m_triggerType", tolua_get_CGameTrigger_m_triggerType, tolua_set_CGameTrigger_m_triggerType);
		tolua_variable(L, "reference_m_triggerType", tolua_get_CGameTrigger_reference_m_triggerType, NULL);
		tolua_variable(L, "m_dwFlags", tolua_get_CGameTrigger_m_dwFlags, NULL);
		tolua_variable(L, "m_boundingRange", tolua_get_CGameTrigger_m_boundingRange, tolua_set_CGameTrigger_m_boundingRange);
		tolua_variable(L, "reference_m_boundingRange", tolua_get_CGameTrigger_reference_m_boundingRange, NULL);
		tolua_variable(L, "m_trapActivated", tolua_get_CGameTrigger_m_trapActivated, tolua_set_CGameTrigger_m_trapActivated);
		tolua_variable(L, "reference_m_trapActivated", tolua_get_CGameTrigger_reference_m_trapActivated, NULL);
		tolua_constant(L, "sizeof", sizeof(CGameTrigger));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameDoor", "CGameDoor", {}, NULL);
	tolua_beginmodule(L, "CGameDoor");
		tolua_variable(L, "m_dwFlagsDoor", tolua_get_CGameDoor_m_dwFlagsDoor, NULL);
		tolua_variable(L, "m_trapActivated", tolua_get_CGameDoor_m_trapActivated, tolua_set_CGameDoor_m_trapActivated);
		tolua_variable(L, "reference_m_trapActivated", tolua_get_CGameDoor_reference_m_trapActivated, NULL);
		tolua_constant(L, "sizeof", sizeof(CGameDoor));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameContainer", "CGameContainer", {}, NULL);
	tolua_beginmodule(L, "CGameContainer");
		tolua_variable(L, "m_trapActivated", tolua_get_CGameContainer_m_trapActivated, tolua_set_CGameContainer_m_trapActivated);
		tolua_variable(L, "reference_m_trapActivated", tolua_get_CGameContainer_reference_m_trapActivated, NULL);
		tolua_constant(L, "sizeof", sizeof(CGameContainer));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<EEex_CBaldurChitin>", "Pointer<EEex_CBaldurChitin>", {}, NULL);
	tolua_beginmodule(L, "Pointer<EEex_CBaldurChitin>");
		tolua_variable(L, "reference", tolua_get_Pointer_CBaldurChitin__reference, tolua_set_Pointer_CBaldurChitin__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CBaldurChitin__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CBaldurChitin>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CObject>", "Pointer<CObject>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CObject>");
		tolua_variable(L, "reference", tolua_get_Pointer_CObject__reference, tolua_set_Pointer_CObject__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CObject__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CObject>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameObject>", "Pointer<CGameObject>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameObject>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameObject__reference, tolua_set_Pointer_CGameObject__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameObject__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameObject>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameArea>", "Pointer<CGameArea>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameArea>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameArea__reference, tolua_set_Pointer_CGameArea__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameArea__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameArea>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<const CPoint>", "Pointer<const CPoint>", {}, NULL);
	tolua_beginmodule(L, "Pointer<const CPoint>");
		tolua_variable(L, "reference", tolua_get_Pointer_const_CPoint__reference, tolua_set_Pointer_const_CPoint__reference);
		tolua_constant(L, "sizeof", sizeof(Pointer<const CPoint>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<const CAIObjectType>", "Pointer<const CAIObjectType>", {}, NULL);
	tolua_beginmodule(L, "Pointer<const CAIObjectType>");
		tolua_variable(L, "reference", tolua_get_Pointer_const_CAIObjectType__reference, tolua_set_Pointer_const_CAIObjectType__reference);
		tolua_constant(L, "sizeof", sizeof(Pointer<const CAIObjectType>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CPoint>", "Pointer<CPoint>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CPoint>");
		tolua_variable(L, "reference", tolua_get_Pointer_CPoint__reference, tolua_set_Pointer_CPoint__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CPoint__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CPoint>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CTypedPtrList<CPtrList,long>::CNode>", "Pointer<CTypedPtrList<CPtrList,long>::CNode>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CTypedPtrList<CPtrList,long>::CNode>");
		tolua_variable(L, "reference", tolua_get_Pointer_CTypedPtrList_CPtrList_long___CNode__reference, tolua_set_Pointer_CTypedPtrList_CPtrList_long___CNode__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CTypedPtrList_CPtrList_long___CNode__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CTypedPtrList<CPtrList,long>::CNode>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<unsigned int>", "Pointer<unsigned int>", {}, NULL);
	tolua_beginmodule(L, "Pointer<unsigned int>");
		tolua_variable(L, "reference", tolua_get_Pointer_unsigned_int__reference, tolua_set_Pointer_unsigned_int__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_unsigned_int__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_unsigned_int__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<unsigned int>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<const CString>", "Pointer<const CString>", {}, NULL);
	tolua_beginmodule(L, "Pointer<const CString>");
		tolua_variable(L, "reference", tolua_get_Pointer_const_CString__reference, tolua_set_Pointer_const_CString__reference);
		tolua_constant(L, "sizeof", sizeof(Pointer<const CString>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CVidMode>", "Pointer<CVidMode>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CVidMode>");
		tolua_variable(L, "reference", tolua_get_Pointer_CVidMode__reference, tolua_set_Pointer_CVidMode__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CVidMode__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CVidMode>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<__POSITION>", "Pointer<__POSITION>", {}, NULL);
	tolua_beginmodule(L, "Pointer<__POSITION>");
		tolua_variable(L, "reference", tolua_get_Pointer___POSITION__reference, tolua_set_Pointer___POSITION__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer___POSITION__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<__POSITION>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<const CAITrigger>", "Pointer<const CAITrigger>", {}, NULL);
	tolua_beginmodule(L, "Pointer<const CAITrigger>");
		tolua_variable(L, "reference", tolua_get_Pointer_const_CAITrigger__reference, tolua_set_Pointer_const_CAITrigger__reference);
		tolua_constant(L, "sizeof", sizeof(Pointer<const CAITrigger>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameAIBase>", "Pointer<CGameAIBase>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameAIBase>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameAIBase__reference, tolua_set_Pointer_CGameAIBase__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameAIBase__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameAIBase>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<const CAIAction>", "Pointer<const CAIAction>", {}, NULL);
	tolua_beginmodule(L, "Pointer<const CAIAction>");
		tolua_variable(L, "reference", tolua_get_Pointer_const_CAIAction__reference, tolua_set_Pointer_const_CAIAction__reference);
		tolua_constant(L, "sizeof", sizeof(Pointer<const CAIAction>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameEffect>", "Pointer<CGameEffect>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameEffect>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameEffect__reference, tolua_set_Pointer_CGameEffect__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameEffect__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameEffect>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CResRef>", "Pointer<CResRef>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CResRef>");
		tolua_variable(L, "reference", tolua_get_Pointer_CResRef__reference, tolua_set_Pointer_CResRef__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CResRef__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CResRef>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameObject*>", "Pointer<CGameObject*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameObject*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameObject___reference, tolua_set_Pointer_CGameObject___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CGameObject___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameObject___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameObject*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Item_effect_st>", "Pointer<Item_effect_st>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Item_effect_st>");
		tolua_variable(L, "reference", tolua_get_Pointer_Item_effect_st__reference, tolua_set_Pointer_Item_effect_st__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Item_effect_st__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Item_effect_st>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CProjectile>", "Pointer<CProjectile>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CProjectile>");
		tolua_variable(L, "reference", tolua_get_Pointer_CProjectile__reference, tolua_set_Pointer_CProjectile__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CProjectile__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CProjectile>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<EEex_CInfGame>", "Pointer<EEex_CInfGame>", {}, NULL);
	tolua_beginmodule(L, "Pointer<EEex_CInfGame>");
		tolua_variable(L, "reference", tolua_get_Pointer_CInfGame__reference, tolua_set_Pointer_CInfGame__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CInfGame__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CInfGame>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<EEex_CScreenWorld>", "Pointer<EEex_CScreenWorld>", {}, NULL);
	tolua_beginmodule(L, "Pointer<EEex_CScreenWorld>");
		tolua_variable(L, "reference", tolua_get_Pointer_CScreenWorld__reference, tolua_set_Pointer_CScreenWorld__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CScreenWorld__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CScreenWorld>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameAnimationType>", "Pointer<CGameAnimationType>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameAnimationType>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameAnimationType__reference, tolua_set_Pointer_CGameAnimationType__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameAnimationType__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameAnimationType>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CProjectileUnknownPST2>", "Pointer<CProjectileUnknownPST2>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CProjectileUnknownPST2>");
		tolua_variable(L, "reference", tolua_get_Pointer_CProjectileUnknownPST2__reference, tolua_set_Pointer_CProjectileUnknownPST2__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CProjectileUnknownPST2__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CProjectileUnknownPST2>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CInfinity>", "Pointer<CInfinity>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CInfinity>");
		tolua_variable(L, "reference", tolua_get_Pointer_CInfinity__reference, tolua_set_Pointer_CInfinity__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CInfinity__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CInfinity>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CVidCell>", "Pointer<CVidCell>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CVidCell>");
		tolua_variable(L, "reference", tolua_get_Pointer_CVidCell__reference, tolua_set_Pointer_CVidCell__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CVidCell__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CVidCell>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CPtrList_CNode>", "Pointer<CPtrList_CNode>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CPtrList_CNode>");
		tolua_variable(L, "reference", tolua_get_Pointer_CPtrList_CNode__reference, tolua_set_Pointer_CPtrList_CNode__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CPtrList_CNode__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CPtrList_CNode>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<int>", "Pointer<int>", {}, NULL);
	tolua_beginmodule(L, "Pointer<int>");
		tolua_variable(L, "reference", tolua_get_Pointer_int__reference, tolua_set_Pointer_int__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_int__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_int__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<int>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CSoundImp>", "Pointer<CSoundImp>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CSoundImp>");
		tolua_variable(L, "reference", tolua_get_Pointer_CSoundImp__reference, tolua_set_Pointer_CSoundImp__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CSoundImp__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CSoundImp>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CAreaTintOverride>", "Pointer<CAreaTintOverride>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CAreaTintOverride>");
		tolua_variable(L, "reference", tolua_get_Pointer_CAreaTintOverride__reference, tolua_set_Pointer_CAreaTintOverride__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CAreaTintOverride__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CAreaTintOverride>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<EEex_CBaldurChitin*>", "Pointer<EEex_CBaldurChitin*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<EEex_CBaldurChitin*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CBaldurChitin___reference, tolua_set_Pointer_CBaldurChitin___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CBaldurChitin___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CBaldurChitin___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CBaldurChitin*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CObject*>", "Pointer<CObject*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CObject*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CObject___reference, tolua_set_Pointer_CObject___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CObject___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CObject___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CObject*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameArea*>", "Pointer<CGameArea*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameArea*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameArea___reference, tolua_set_Pointer_CGameArea___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CGameArea___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameArea___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameArea*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<const CPoint*>", "Pointer<const CPoint*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<const CPoint*>");
		tolua_variable(L, "reference", tolua_get_Pointer_const_CPoint___reference, tolua_set_Pointer_const_CPoint___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_const_CPoint___getValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<const CPoint*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<const CAIObjectType*>", "Pointer<const CAIObjectType*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<const CAIObjectType*>");
		tolua_variable(L, "reference", tolua_get_Pointer_const_CAIObjectType___reference, tolua_set_Pointer_const_CAIObjectType___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_const_CAIObjectType___getValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<const CAIObjectType*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CPoint*>", "Pointer<CPoint*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CPoint*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CPoint___reference, tolua_set_Pointer_CPoint___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CPoint___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CPoint___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CPoint*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CTypedPtrList<CPtrList,long>::CNode*>", "Pointer<CTypedPtrList<CPtrList,long>::CNode*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CTypedPtrList<CPtrList,long>::CNode*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CTypedPtrList_CPtrList_long___CNode___reference, tolua_set_Pointer_CTypedPtrList_CPtrList_long___CNode___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CTypedPtrList_CPtrList_long___CNode___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CTypedPtrList_CPtrList_long___CNode___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CTypedPtrList<CPtrList,long>::CNode*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<unsigned int*>", "Pointer<unsigned int*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<unsigned int*>");
		tolua_variable(L, "reference", tolua_get_Pointer_unsigned_int___reference, tolua_set_Pointer_unsigned_int___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_unsigned_int___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_unsigned_int___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<unsigned int*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<const CString*>", "Pointer<const CString*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<const CString*>");
		tolua_variable(L, "reference", tolua_get_Pointer_const_CString___reference, tolua_set_Pointer_const_CString___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_const_CString___getValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<const CString*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CVidMode*>", "Pointer<CVidMode*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CVidMode*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CVidMode___reference, tolua_set_Pointer_CVidMode___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CVidMode___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CVidMode___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CVidMode*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<__POSITION*>", "Pointer<__POSITION*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<__POSITION*>");
		tolua_variable(L, "reference", tolua_get_Pointer___POSITION___reference, tolua_set_Pointer___POSITION___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer___POSITION___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer___POSITION___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<__POSITION*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<const CAITrigger*>", "Pointer<const CAITrigger*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<const CAITrigger*>");
		tolua_variable(L, "reference", tolua_get_Pointer_const_CAITrigger___reference, tolua_set_Pointer_const_CAITrigger___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_const_CAITrigger___getValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<const CAITrigger*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameAIBase*>", "Pointer<CGameAIBase*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameAIBase*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameAIBase___reference, tolua_set_Pointer_CGameAIBase___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CGameAIBase___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameAIBase___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameAIBase*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<const CAIAction*>", "Pointer<const CAIAction*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<const CAIAction*>");
		tolua_variable(L, "reference", tolua_get_Pointer_const_CAIAction___reference, tolua_set_Pointer_const_CAIAction___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_const_CAIAction___getValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<const CAIAction*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameEffect*>", "Pointer<CGameEffect*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameEffect*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameEffect___reference, tolua_set_Pointer_CGameEffect___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CGameEffect___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameEffect___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameEffect*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CResRef*>", "Pointer<CResRef*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CResRef*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CResRef___reference, tolua_set_Pointer_CResRef___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CResRef___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CResRef___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CResRef*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameObject**>", "Pointer<CGameObject**>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameObject**>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameObject____reference, tolua_set_Pointer_CGameObject____reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CGameObject____getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameObject____setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameObject**>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Item_effect_st*>", "Pointer<Item_effect_st*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Item_effect_st*>");
		tolua_variable(L, "reference", tolua_get_Pointer_Item_effect_st___reference, tolua_set_Pointer_Item_effect_st___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_Item_effect_st___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_Item_effect_st___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Item_effect_st*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CProjectile*>", "Pointer<CProjectile*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CProjectile*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CProjectile___reference, tolua_set_Pointer_CProjectile___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CProjectile___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CProjectile___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CProjectile*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<EEex_CInfGame*>", "Pointer<EEex_CInfGame*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<EEex_CInfGame*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CInfGame___reference, tolua_set_Pointer_CInfGame___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CInfGame___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CInfGame___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CInfGame*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<EEex_CScreenWorld*>", "Pointer<EEex_CScreenWorld*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<EEex_CScreenWorld*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CScreenWorld___reference, tolua_set_Pointer_CScreenWorld___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CScreenWorld___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CScreenWorld___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CScreenWorld*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameAnimationType*>", "Pointer<CGameAnimationType*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameAnimationType*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameAnimationType___reference, tolua_set_Pointer_CGameAnimationType___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CGameAnimationType___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameAnimationType___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameAnimationType*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CProjectileUnknownPST2*>", "Pointer<CProjectileUnknownPST2*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CProjectileUnknownPST2*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CProjectileUnknownPST2___reference, tolua_set_Pointer_CProjectileUnknownPST2___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CProjectileUnknownPST2___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CProjectileUnknownPST2___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CProjectileUnknownPST2*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CInfinity*>", "Pointer<CInfinity*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CInfinity*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CInfinity___reference, tolua_set_Pointer_CInfinity___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CInfinity___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CInfinity___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CInfinity*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CVidCell*>", "Pointer<CVidCell*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CVidCell*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CVidCell___reference, tolua_set_Pointer_CVidCell___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CVidCell___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CVidCell___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CVidCell*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CPtrList_CNode*>", "Pointer<CPtrList_CNode*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CPtrList_CNode*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CPtrList_CNode___reference, tolua_set_Pointer_CPtrList_CNode___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CPtrList_CNode___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CPtrList_CNode___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CPtrList_CNode*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<int*>", "Pointer<int*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<int*>");
		tolua_variable(L, "reference", tolua_get_Pointer_int___reference, tolua_set_Pointer_int___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_int___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_int___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<int*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CSoundImp*>", "Pointer<CSoundImp*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CSoundImp*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CSoundImp___reference, tolua_set_Pointer_CSoundImp___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CSoundImp___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CSoundImp___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CSoundImp*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CAreaTintOverride*>", "Pointer<CAreaTintOverride*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CAreaTintOverride*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CAreaTintOverride___reference, tolua_set_Pointer_CAreaTintOverride___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CAreaTintOverride___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CAreaTintOverride___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CAreaTintOverride*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameAnimation>", "Pointer<CGameAnimation>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameAnimation>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameAnimation__reference, tolua_set_Pointer_CGameAnimation__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameAnimation__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameAnimation>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<EEex_CInfButtonArray>", "Pointer<EEex_CInfButtonArray>", {}, NULL);
	tolua_beginmodule(L, "Pointer<EEex_CInfButtonArray>");
		tolua_variable(L, "reference", tolua_get_Pointer_CInfButtonArray__reference, tolua_set_Pointer_CInfButtonArray__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CInfButtonArray__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CInfButtonArray>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CPersistantEffectColorEffect>", "Pointer<CPersistantEffectColorEffect>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CPersistantEffectColorEffect>");
		tolua_variable(L, "reference", tolua_get_Pointer_CPersistantEffectColorEffect__reference, tolua_set_Pointer_CPersistantEffectColorEffect__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CPersistantEffectColorEffect__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CPersistantEffectColorEffect>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CPlanescape>", "Pointer<CPlanescape>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CPlanescape>");
		tolua_variable(L, "reference", tolua_get_Pointer_CPlanescape__reference, tolua_set_Pointer_CPlanescape__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CPlanescape__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CPlanescape>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CResCell>", "Pointer<CResCell>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CResCell>");
		tolua_variable(L, "reference", tolua_get_Pointer_CResCell__reference, tolua_set_Pointer_CResCell__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CResCell__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CResCell>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CResCell*>", "Pointer<CResCell*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CResCell*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CResCell___reference, tolua_set_Pointer_CResCell___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CResCell___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CResCell___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CResCell*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CSound>", "Pointer<CSound>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CSound>");
		tolua_variable(L, "reference", tolua_get_Pointer_CSound__reference, tolua_set_Pointer_CSound__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CSound__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CSound>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CVidImage>", "Pointer<CVidImage>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CVidImage>");
		tolua_variable(L, "reference", tolua_get_Pointer_CVidImage__reference, tolua_set_Pointer_CVidImage__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CVidImage__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CVidImage>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CVideo>", "Pointer<CVideo>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CVideo>");
		tolua_variable(L, "reference", tolua_get_Pointer_CVideo__reference, tolua_set_Pointer_CVideo__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CVideo__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CVideo>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<size_t>", "Pointer<size_t>", {}, NULL);
	tolua_beginmodule(L, "Pointer<size_t>");
		tolua_variable(L, "reference", tolua_get_Pointer_size_t__reference, tolua_set_Pointer_size_t__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_size_t__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_size_t__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<size_t>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<uintptr_t>", "Pointer<uintptr_t>", {}, NULL);
	tolua_beginmodule(L, "Pointer<uintptr_t>");
		tolua_variable(L, "reference", tolua_get_Pointer_uintptr_t__reference, tolua_set_Pointer_uintptr_t__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_uintptr_t__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_uintptr_t__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<uintptr_t>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameObjectType>", "Pointer<CGameObjectType>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameObjectType>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameObjectType__reference, tolua_set_Pointer_CGameObjectType__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CGameObjectType__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameObjectType__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameObjectType>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<unsigned __int8>", "Pointer<unsigned __int8>", {}, NULL);
	tolua_beginmodule(L, "Pointer<unsigned __int8>");
		tolua_variable(L, "reference", tolua_get_Pointer_unsigned___int8__reference, tolua_set_Pointer_unsigned___int8__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_unsigned___int8__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_unsigned___int8__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<unsigned __int8>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<long>", "Pointer<long>", {}, NULL);
	tolua_beginmodule(L, "Pointer<long>");
		tolua_variable(L, "reference", tolua_get_Pointer_long__reference, tolua_set_Pointer_long__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_long__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_long__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<long>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<VertListType>", "Pointer<VertListType>", {}, NULL);
	tolua_beginmodule(L, "Pointer<VertListType>");
		tolua_variable(L, "reference", tolua_get_Pointer_VertListType__reference, tolua_set_Pointer_VertListType__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_VertListType__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_VertListType__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<VertListType>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<short>", "Pointer<short>", {}, NULL);
	tolua_beginmodule(L, "Pointer<short>");
		tolua_variable(L, "reference", tolua_get_Pointer_short__reference, tolua_set_Pointer_short__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_short__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_short__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<short>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<__int8>", "Pointer<__int8>", {}, NULL);
	tolua_beginmodule(L, "Pointer<__int8>");
		tolua_variable(L, "reference", tolua_get_Pointer___int8__reference, tolua_set_Pointer___int8__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer___int8__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer___int8__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<__int8>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<byte>", "Pointer<byte>", {}, NULL);
	tolua_beginmodule(L, "Pointer<byte>");
		tolua_variable(L, "reference", tolua_get_Pointer_byte__reference, tolua_set_Pointer_byte__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_byte__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_byte__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<byte>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<ushort>", "Pointer<ushort>", {}, NULL);
	tolua_beginmodule(L, "Pointer<ushort>");
		tolua_variable(L, "reference", tolua_get_Pointer_ushort__reference, tolua_set_Pointer_ushort__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_ushort__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_ushort__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<ushort>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<uint>", "Pointer<uint>", {}, NULL);
	tolua_beginmodule(L, "Pointer<uint>");
		tolua_variable(L, "reference", tolua_get_Pointer_uint__reference, tolua_set_Pointer_uint__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_uint__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_uint__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<uint>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<double>", "Pointer<double>", {}, NULL);
	tolua_beginmodule(L, "Pointer<double>");
		tolua_variable(L, "reference", tolua_get_Pointer_double__reference, tolua_set_Pointer_double__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_double__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_double__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<double>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<float>", "Pointer<float>", {}, NULL);
	tolua_beginmodule(L, "Pointer<float>");
		tolua_variable(L, "reference", tolua_get_Pointer_float__reference, tolua_set_Pointer_float__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_float__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_float__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<float>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<__int32>", "Pointer<__int32>", {}, NULL);
	tolua_beginmodule(L, "Pointer<__int32>");
		tolua_variable(L, "reference", tolua_get_Pointer___int32__reference, tolua_set_Pointer___int32__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer___int32__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer___int32__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<__int32>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<long double>>", "Pointer<Primitive<long double>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<long double>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_long_double___reference, tolua_set_Pointer_Primitive_long_double___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_long_double___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<long double>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<uint16_t>>", "Pointer<Primitive<uint16_t>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<uint16_t>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_uint16_t___reference, tolua_set_Pointer_Primitive_uint16_t___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_uint16_t___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<uint16_t>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<int>>", "Pointer<Primitive<int>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<int>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_int___reference, tolua_set_Pointer_Primitive_int___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_int___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<int>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<int64_t>>", "Pointer<Primitive<int64_t>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<int64_t>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_int64_t___reference, tolua_set_Pointer_Primitive_int64_t___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_int64_t___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<int64_t>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<intptr_t>>", "Pointer<Primitive<intptr_t>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<intptr_t>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_intptr_t___reference, tolua_set_Pointer_Primitive_intptr_t___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_intptr_t___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<intptr_t>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<__int64>>", "Pointer<Primitive<__int64>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<__int64>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive___int64___reference, tolua_set_Pointer_Primitive___int64___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive___int64___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<__int64>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<long>>", "Pointer<Primitive<long>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<long>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_long___reference, tolua_set_Pointer_Primitive_long___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_long___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<long>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<__int8>>", "Pointer<Primitive<__int8>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<__int8>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive___int8___reference, tolua_set_Pointer_Primitive___int8___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive___int8___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<__int8>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<double>>", "Pointer<Primitive<double>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<double>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_double___reference, tolua_set_Pointer_Primitive_double___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_double___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<double>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<byte>>", "Pointer<Primitive<byte>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<byte>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_byte___reference, tolua_set_Pointer_Primitive_byte___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_byte___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<byte>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<float>>", "Pointer<Primitive<float>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<float>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_float___reference, tolua_set_Pointer_Primitive_float___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_float___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<float>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<__int16>>", "Pointer<Primitive<__int16>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<__int16>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive___int16___reference, tolua_set_Pointer_Primitive___int16___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive___int16___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<__int16>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<uint>>", "Pointer<Primitive<uint>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<uint>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_uint___reference, tolua_set_Pointer_Primitive_uint___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_uint___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<uint>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<short>>", "Pointer<Primitive<short>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<short>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_short___reference, tolua_set_Pointer_Primitive_short___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_short___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<short>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<int16_t>>", "Pointer<Primitive<int16_t>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<int16_t>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_int16_t___reference, tolua_set_Pointer_Primitive_int16_t___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_int16_t___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<int16_t>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<uintptr_t>>", "Pointer<Primitive<uintptr_t>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<uintptr_t>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_uintptr_t___reference, tolua_set_Pointer_Primitive_uintptr_t___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_uintptr_t___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<uintptr_t>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<char>>", "Pointer<Primitive<char>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<char>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_char___reference, tolua_set_Pointer_Primitive_char___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_char___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<char>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<int8_t>>", "Pointer<Primitive<int8_t>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<int8_t>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_int8_t___reference, tolua_set_Pointer_Primitive_int8_t___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_int8_t___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<int8_t>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<ushort>>", "Pointer<Primitive<ushort>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<ushort>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_ushort___reference, tolua_set_Pointer_Primitive_ushort___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_ushort___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<ushort>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<bool>>", "Pointer<Primitive<bool>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<bool>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_bool___reference, tolua_set_Pointer_Primitive_bool___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_bool___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<bool>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<int32_t>>", "Pointer<Primitive<int32_t>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<int32_t>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_int32_t___reference, tolua_set_Pointer_Primitive_int32_t___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_int32_t___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<int32_t>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<uint64_t>>", "Pointer<Primitive<uint64_t>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<uint64_t>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_uint64_t___reference, tolua_set_Pointer_Primitive_uint64_t___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_uint64_t___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<uint64_t>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<__int32>>", "Pointer<Primitive<__int32>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<__int32>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive___int32___reference, tolua_set_Pointer_Primitive___int32___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive___int32___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<__int32>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<size_t>>", "Pointer<Primitive<size_t>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<size_t>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_size_t___reference, tolua_set_Pointer_Primitive_size_t___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_size_t___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<size_t>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<uint8_t>>", "Pointer<Primitive<uint8_t>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<uint8_t>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_uint8_t___reference, tolua_set_Pointer_Primitive_uint8_t___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_uint8_t___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<uint8_t>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<uint32_t>>", "Pointer<Primitive<uint32_t>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<uint32_t>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_uint32_t___reference, tolua_set_Pointer_Primitive_uint32_t___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_uint32_t___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<uint32_t>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Primitive<ptrdiff_t>>", "Pointer<Primitive<ptrdiff_t>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Primitive<ptrdiff_t>>");
		tolua_variable(L, "reference", tolua_get_Pointer_Primitive_ptrdiff_t___reference, tolua_set_Pointer_Primitive_ptrdiff_t___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Primitive_ptrdiff_t___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Primitive<ptrdiff_t>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<void*>", "Pointer<void*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<void*>");
		tolua_variable(L, "reference", tolua_get_Pointer_void___reference, tolua_set_Pointer_void___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_void___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_void___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<void*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<UnmappedUserType>", "Pointer<UnmappedUserType>", {}, NULL);
	tolua_beginmodule(L, "Pointer<UnmappedUserType>");
		tolua_variable(L, "reference", tolua_get_Pointer_UnmappedUserType__reference, tolua_set_Pointer_UnmappedUserType__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_UnmappedUserType__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<UnmappedUserType>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<PlayerScriptNameOrdinal>", "Pointer<PlayerScriptNameOrdinal>", {}, NULL);
	tolua_beginmodule(L, "Pointer<PlayerScriptNameOrdinal>");
		tolua_variable(L, "reference", tolua_get_Pointer_PlayerScriptNameOrdinal__reference, tolua_set_Pointer_PlayerScriptNameOrdinal__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_PlayerScriptNameOrdinal__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_PlayerScriptNameOrdinal__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<PlayerScriptNameOrdinal>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<DrawFeature>", "Pointer<DrawFeature>", {}, NULL);
	tolua_beginmodule(L, "Pointer<DrawFeature>");
		tolua_variable(L, "reference", tolua_get_Pointer_DrawFeature__reference, tolua_set_Pointer_DrawFeature__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_DrawFeature__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_DrawFeature__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<DrawFeature>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<byte*>", "Pointer<byte*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<byte*>");
		tolua_variable(L, "reference", tolua_get_Pointer_byte___reference, tolua_set_Pointer_byte___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_byte___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_byte___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<byte*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<char*>", "Pointer<char*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<char*>");
		tolua_variable(L, "reference", tolua_get_Pointer_char___reference, tolua_set_Pointer_char___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_char___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<char*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<char>", "Pointer<char>", {}, NULL);
	tolua_beginmodule(L, "Pointer<char>");
		tolua_variable(L, "reference", tolua_get_Pointer_char__reference, NULL);
		tolua_function(L, "getValue", &tolua_function_Pointer_char__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_char__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<char>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<const char*>", "Pointer<const char*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<const char*>");
		tolua_variable(L, "reference", tolua_get_Pointer_const_char___reference, tolua_set_Pointer_const_char___reference);
		tolua_constant(L, "sizeof", sizeof(Pointer<const char*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<long double>", "Pointer<long double>", {}, NULL);
	tolua_beginmodule(L, "Pointer<long double>");
		tolua_variable(L, "reference", tolua_get_Pointer_long_double__reference, tolua_set_Pointer_long_double__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_long_double__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_long_double__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<long double>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CRect>", "Pointer<CRect>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CRect>");
		tolua_variable(L, "reference", tolua_get_Pointer_CRect__reference, tolua_set_Pointer_CRect__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CRect__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CRect>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CPtrList>", "Pointer<CPtrList>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CPtrList>");
		tolua_variable(L, "reference", tolua_get_Pointer_CPtrList__reference, tolua_set_Pointer_CPtrList__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CPtrList__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CPtrList>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameObjectArray>", "Pointer<CGameObjectArray>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameObjectArray>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameObjectArray__reference, tolua_set_Pointer_CGameObjectArray__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameObjectArray__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameObjectArray>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<long*>", "Pointer<long*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<long*>");
		tolua_variable(L, "reference", tolua_get_Pointer_long___reference, tolua_set_Pointer_long___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_long___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_long___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<long*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CMessage>", "Pointer<CMessage>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CMessage>");
		tolua_variable(L, "reference", tolua_get_Pointer_CMessage__reference, tolua_set_Pointer_CMessage__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CMessage__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CMessage>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CMessageVisualEffect>", "Pointer<CMessageVisualEffect>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CMessageVisualEffect>");
		tolua_variable(L, "reference", tolua_get_Pointer_CMessageVisualEffect__reference, tolua_set_Pointer_CMessageVisualEffect__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CMessageVisualEffect__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CMessageVisualEffect>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CMessageAddEffect>", "Pointer<CMessageAddEffect>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CMessageAddEffect>");
		tolua_variable(L, "reference", tolua_get_Pointer_CMessageAddEffect__reference, tolua_set_Pointer_CMessageAddEffect__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CMessageAddEffect__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CMessageAddEffect>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<EEex_CTimerWorld>", "Pointer<EEex_CTimerWorld>", {}, NULL);
	tolua_beginmodule(L, "Pointer<EEex_CTimerWorld>");
		tolua_variable(L, "reference", tolua_get_Pointer_CTimerWorld__reference, tolua_set_Pointer_CTimerWorld__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CTimerWorld__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CTimerWorld>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameTrigger>", "Pointer<CGameTrigger>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameTrigger>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameTrigger__reference, tolua_set_Pointer_CGameTrigger__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameTrigger__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameTrigger>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameDoor>", "Pointer<CGameDoor>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameDoor>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameDoor__reference, tolua_set_Pointer_CGameDoor__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameDoor__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameDoor>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameContainer>", "Pointer<CGameContainer>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameContainer>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameContainer__reference, tolua_set_Pointer_CGameContainer__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameContainer__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameContainer>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CharString*>", "Pointer<CharString*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CharString*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CharString___reference, tolua_set_Pointer_CharString___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CharString___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CharString___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CharString*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CString>", "Pointer<CString>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CString>");
		tolua_variable(L, "reference", tolua_get_Pointer_CString__reference, tolua_set_Pointer_CString__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CString__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CString>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CObject::vtbl>", "Pointer<CObject::vtbl>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CObject::vtbl>");
		tolua_variable(L, "reference", tolua_get_Pointer_CObject__vtbl__reference, tolua_set_Pointer_CObject__vtbl__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CObject__vtbl__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CObject::vtbl>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CTypedPtrList<CPtrList,long>>", "Pointer<CTypedPtrList<CPtrList,long>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CTypedPtrList<CPtrList,long>>");
		tolua_variable(L, "reference", tolua_get_Pointer_CTypedPtrList_CPtrList_long___reference, tolua_set_Pointer_CTypedPtrList_CPtrList_long___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CTypedPtrList_CPtrList_long___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CTypedPtrList<CPtrList,long>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CTypedPtrList<CPtrList,CGameEffect*>>", "Pointer<CTypedPtrList<CPtrList,CGameEffect*>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CTypedPtrList<CPtrList,CGameEffect*>>");
		tolua_variable(L, "reference", tolua_get_Pointer_CTypedPtrList_CPtrList_CGameEffect____reference, tolua_set_Pointer_CTypedPtrList_CPtrList_CGameEffect____reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CTypedPtrList_CPtrList_CGameEffect____setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CTypedPtrList<CPtrList,CGameEffect*>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CTypedPtrList<CPtrList,int*>>", "Pointer<CTypedPtrList<CPtrList,int*>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CTypedPtrList<CPtrList,int*>>");
		tolua_variable(L, "reference", tolua_get_Pointer_CTypedPtrList_CPtrList_int____reference, tolua_set_Pointer_CTypedPtrList_CPtrList_int____reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CTypedPtrList_CPtrList_int____setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CTypedPtrList<CPtrList,int*>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CTypedPtrList<CPtrList,int>>", "Pointer<CTypedPtrList<CPtrList,int>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CTypedPtrList<CPtrList,int>>");
		tolua_variable(L, "reference", tolua_get_Pointer_CTypedPtrList_CPtrList_int___reference, tolua_set_Pointer_CTypedPtrList_CPtrList_int___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CTypedPtrList_CPtrList_int___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CTypedPtrList<CPtrList,int>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameArea**>", "Pointer<CGameArea**>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameArea**>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameArea____reference, tolua_set_Pointer_CGameArea____reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CGameArea____getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameArea____setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameArea**>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameEffectList>", "Pointer<CGameEffectList>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameEffectList>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameEffectList__reference, tolua_set_Pointer_CGameEffectList__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameEffectList__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameEffectList>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameObject::vtbl>", "Pointer<CGameObject::vtbl>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameObject::vtbl>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameObject__vtbl__reference, tolua_set_Pointer_CGameObject__vtbl__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameObject__vtbl__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameObject::vtbl>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<LCharString<32>>", "Pointer<LCharString<32>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<LCharString<32>>");
		tolua_variable(L, "reference", tolua_get_Pointer_LCharString_32___reference, tolua_set_Pointer_LCharString_32___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_LCharString_32___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<LCharString<32>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CResHelper<CResCell,1000>>", "Pointer<CResHelper<CResCell,1000>>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CResHelper<CResCell,1000>>");
		tolua_variable(L, "reference", tolua_get_Pointer_CResHelper_CResCell_1000___reference, tolua_set_Pointer_CResHelper_CResCell_1000___reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CResHelper_CResCell_1000___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CResHelper<CResCell,1000>>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameEffectBase>", "Pointer<CGameEffectBase>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameEffectBase>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameEffectBase__reference, tolua_set_Pointer_CGameEffectBase__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameEffectBase__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameEffectBase>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CDerivedStats>", "Pointer<CDerivedStats>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CDerivedStats>");
		tolua_variable(L, "reference", tolua_get_Pointer_CDerivedStats__reference, tolua_set_Pointer_CDerivedStats__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CDerivedStats__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CDerivedStats>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CAreaVariable>", "Pointer<CAreaVariable>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CAreaVariable>");
		tolua_variable(L, "reference", tolua_get_Pointer_CAreaVariable__reference, tolua_set_Pointer_CAreaVariable__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CAreaVariable__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CAreaVariable>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CVariable>", "Pointer<CVariable>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CVariable>");
		tolua_variable(L, "reference", tolua_get_Pointer_CVariable__reference, tolua_set_Pointer_CVariable__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CVariable__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CVariable>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CAIObjectType>", "Pointer<CAIObjectType>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CAIObjectType>");
		tolua_variable(L, "reference", tolua_get_Pointer_CAIObjectType__reference, tolua_set_Pointer_CAIObjectType__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CAIObjectType__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CAIObjectType>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CAIAction>", "Pointer<CAIAction>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CAIAction>");
		tolua_variable(L, "reference", tolua_get_Pointer_CAIAction__reference, tolua_set_Pointer_CAIAction__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CAIAction__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CAIAction>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CProjectile::vtbl>", "Pointer<CProjectile::vtbl>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CProjectile::vtbl>");
		tolua_variable(L, "reference", tolua_get_Pointer_CProjectile__vtbl__reference, tolua_set_Pointer_CProjectile__vtbl__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CProjectile__vtbl__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CProjectile::vtbl>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CProjectileBAM::vtbl>", "Pointer<CProjectileBAM::vtbl>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CProjectileBAM::vtbl>");
		tolua_variable(L, "reference", tolua_get_Pointer_CProjectileBAM__vtbl__reference, tolua_set_Pointer_CProjectileBAM__vtbl__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CProjectileBAM__vtbl__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CProjectileBAM::vtbl>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CProjectileBAM>", "Pointer<CProjectileBAM>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CProjectileBAM>");
		tolua_variable(L, "reference", tolua_get_Pointer_CProjectileBAM__reference, tolua_set_Pointer_CProjectileBAM__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CProjectileBAM__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CProjectileBAM>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CProjectileArea>", "Pointer<CProjectileArea>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CProjectileArea>");
		tolua_variable(L, "reference", tolua_get_Pointer_CProjectileArea__reference, tolua_set_Pointer_CProjectileArea__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CProjectileArea__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CProjectileArea>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CProjectileUnknownPST>", "Pointer<CProjectileUnknownPST>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CProjectileUnknownPST>");
		tolua_variable(L, "reference", tolua_get_Pointer_CProjectileUnknownPST__reference, tolua_set_Pointer_CProjectileUnknownPST__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CProjectileUnknownPST__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CProjectileUnknownPST>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CProjectileUnknownPST2**>", "Pointer<CProjectileUnknownPST2**>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CProjectileUnknownPST2**>");
		tolua_variable(L, "reference", tolua_get_Pointer_CProjectileUnknownPST2____reference, tolua_set_Pointer_CProjectileUnknownPST2____reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CProjectileUnknownPST2____getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CProjectileUnknownPST2____setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CProjectileUnknownPST2**>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CProjectileUnknownBase>", "Pointer<CProjectileUnknownBase>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CProjectileUnknownBase>");
		tolua_variable(L, "reference", tolua_get_Pointer_CProjectileUnknownBase__reference, tolua_set_Pointer_CProjectileUnknownBase__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CProjectileUnknownBase__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CProjectileUnknownBase>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CProjectile205>", "Pointer<CProjectile205>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CProjectile205>");
		tolua_variable(L, "reference", tolua_get_Pointer_CProjectile205__reference, tolua_set_Pointer_CProjectile205__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CProjectile205__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CProjectile205>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CAITrigger>", "Pointer<CAITrigger>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CAITrigger>");
		tolua_variable(L, "reference", tolua_get_Pointer_CAITrigger__reference, tolua_set_Pointer_CAITrigger__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CAITrigger__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CAITrigger>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CMessageSetTrigger>", "Pointer<CMessageSetTrigger>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CMessageSetTrigger>");
		tolua_variable(L, "reference", tolua_get_Pointer_CMessageSetTrigger__reference, tolua_set_Pointer_CMessageSetTrigger__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CMessageSetTrigger__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CMessageSetTrigger>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameSprite>", "Pointer<CGameSprite>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameSprite>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameSprite__reference, tolua_set_Pointer_CGameSprite__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameSprite__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameSprite>));
	tolua_endmodule(L);
	tolua_cclass(L, "CharString", "CharString", {}, NULL);
	tolua_beginmodule(L, "CharString");
		tolua_function(L, "getChar", &tolua_function_CharString_getChar);
		tolua_function(L, "setChar", &tolua_function_CharString_setChar);
		tolua_function(L, "set", &tolua_function_CharString_set);
		tolua_function(L, "setL", &tolua_function_CharString_setL);
		tolua_function(L, "write", &tolua_function_CharString_write);
		tolua_function(L, "writeL", &tolua_function_CharString_writeL);
		tolua_function(L, "setReference", &tolua_function_CharString_setReference);
		tolua_function(L, "pointTo", &tolua_function_CharString_pointTo);
		tolua_function(L, "get", &tolua_function_CharString_get);
		tolua_function(L, "getL", &tolua_function_CharString_getL);
		tolua_function(L, "free", &tolua_function_CharString_free);
		tolua_constant(L, "sizeof", sizeof(CharString));
	tolua_endmodule(L);
	tolua_cclass(L, "CString", "CString", {}, NULL);
	tolua_beginmodule(L, "CString");
		tolua_variable(L, "m_pchData", tolua_get_CString_m_pchData, NULL);
		tolua_constant(L, "sizeof", sizeof(CString));
	tolua_endmodule(L);
	tolua_cclass(L, "CObject", "CObject", {}, NULL);
	tolua_beginmodule(L, "CObject");
		tolua_function(L, "virtual_Destruct", &tolua_function_CObject_virtual_Destruct);
		tolua_constant(L, "sizeof", sizeof(CObject));
	tolua_endmodule(L);
	tolua_cclass(L, "CObject::vtbl", "CObject::vtbl", {}, NULL);
	tolua_beginmodule(L, "CObject::vtbl");
		tolua_variable(L, "Destruct", tolua_get_CObject__vtbl_Destruct, tolua_set_CObject__vtbl_Destruct);
		tolua_variable(L, "reference_Destruct", tolua_get_CObject__vtbl_reference_Destruct, NULL);
		tolua_constant(L, "sizeof", sizeof(CObject::vtbl));
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,long>", "CTypedPtrList<CPtrList,long>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,long>");
		tolua_variable(L, "m_pNodeHead", tolua_get_CTypedPtrList_CPtrList_long__m_pNodeHead, tolua_set_CTypedPtrList_CPtrList_long__m_pNodeHead);
		tolua_variable(L, "reference_m_pNodeHead", tolua_get_CTypedPtrList_CPtrList_long__reference_m_pNodeHead, NULL);
		tolua_variable(L, "m_pNodeTail", tolua_get_CTypedPtrList_CPtrList_long__m_pNodeTail, tolua_set_CTypedPtrList_CPtrList_long__m_pNodeTail);
		tolua_variable(L, "reference_m_pNodeTail", tolua_get_CTypedPtrList_CPtrList_long__reference_m_pNodeTail, NULL);
		tolua_variable(L, "m_nCount", tolua_get_CTypedPtrList_CPtrList_long__m_nCount, tolua_set_CTypedPtrList_CPtrList_long__m_nCount);
		tolua_variable(L, "reference_m_nCount", tolua_get_CTypedPtrList_CPtrList_long__reference_m_nCount, NULL);
		tolua_variable(L, "m_pNodeFree", tolua_get_CTypedPtrList_CPtrList_long__m_pNodeFree, tolua_set_CTypedPtrList_CPtrList_long__m_pNodeFree);
		tolua_variable(L, "reference_m_pNodeFree", tolua_get_CTypedPtrList_CPtrList_long__reference_m_pNodeFree, NULL);
		tolua_variable(L, "m_pBlocks", tolua_get_CTypedPtrList_CPtrList_long__m_pBlocks, tolua_set_CTypedPtrList_CPtrList_long__m_pBlocks);
		tolua_variable(L, "reference_m_pBlocks", tolua_get_CTypedPtrList_CPtrList_long__reference_m_pBlocks, NULL);
		tolua_variable(L, "m_nBlockSize", tolua_get_CTypedPtrList_CPtrList_long__m_nBlockSize, tolua_set_CTypedPtrList_CPtrList_long__m_nBlockSize);
		tolua_variable(L, "reference_m_nBlockSize", tolua_get_CTypedPtrList_CPtrList_long__reference_m_nBlockSize, NULL);
		tolua_constant(L, "sizeof", sizeof(CTypedPtrList<CPtrList,long>));
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,long>::CNode", "CTypedPtrList<CPtrList,long>::CNode", {}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,long>::CNode");
		tolua_variable(L, "pNext", tolua_get_CTypedPtrList_CPtrList_long___CNode_pNext, tolua_set_CTypedPtrList_CPtrList_long___CNode_pNext);
		tolua_variable(L, "reference_pNext", tolua_get_CTypedPtrList_CPtrList_long___CNode_reference_pNext, NULL);
		tolua_variable(L, "pPrev", tolua_get_CTypedPtrList_CPtrList_long___CNode_pPrev, tolua_set_CTypedPtrList_CPtrList_long___CNode_pPrev);
		tolua_variable(L, "reference_pPrev", tolua_get_CTypedPtrList_CPtrList_long___CNode_reference_pPrev, NULL);
		tolua_variable(L, "data", tolua_get_CTypedPtrList_CPtrList_long___CNode_data, tolua_set_CTypedPtrList_CPtrList_long___CNode_data);
		tolua_variable(L, "reference_data", tolua_get_CTypedPtrList_CPtrList_long___CNode_reference_data, NULL);
		tolua_constant(L, "sizeof", sizeof(CTypedPtrList<CPtrList,long>::CNode));
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,long>::vtbl", "CTypedPtrList<CPtrList,long>::vtbl", {"CObject::vtbl"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,long>::vtbl");
		tolua_constant(L, "sizeof", sizeof(CTypedPtrList<CPtrList,long>::vtbl));
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CGameEffect*>", "CTypedPtrList<CPtrList,CGameEffect*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CGameEffect*>");
		tolua_variable(L, "m_pNodeHead", tolua_get_CTypedPtrList_CPtrList_CGameEffect___m_pNodeHead, tolua_set_CTypedPtrList_CPtrList_CGameEffect___m_pNodeHead);
		tolua_variable(L, "reference_m_pNodeHead", tolua_get_CTypedPtrList_CPtrList_CGameEffect___reference_m_pNodeHead, NULL);
		tolua_variable(L, "m_pNodeTail", tolua_get_CTypedPtrList_CPtrList_CGameEffect___m_pNodeTail, tolua_set_CTypedPtrList_CPtrList_CGameEffect___m_pNodeTail);
		tolua_variable(L, "reference_m_pNodeTail", tolua_get_CTypedPtrList_CPtrList_CGameEffect___reference_m_pNodeTail, NULL);
		tolua_variable(L, "m_nCount", tolua_get_CTypedPtrList_CPtrList_CGameEffect___m_nCount, tolua_set_CTypedPtrList_CPtrList_CGameEffect___m_nCount);
		tolua_variable(L, "reference_m_nCount", tolua_get_CTypedPtrList_CPtrList_CGameEffect___reference_m_nCount, NULL);
		tolua_variable(L, "m_pNodeFree", tolua_get_CTypedPtrList_CPtrList_CGameEffect___m_pNodeFree, tolua_set_CTypedPtrList_CPtrList_CGameEffect___m_pNodeFree);
		tolua_variable(L, "reference_m_pNodeFree", tolua_get_CTypedPtrList_CPtrList_CGameEffect___reference_m_pNodeFree, NULL);
		tolua_variable(L, "m_pBlocks", tolua_get_CTypedPtrList_CPtrList_CGameEffect___m_pBlocks, tolua_set_CTypedPtrList_CPtrList_CGameEffect___m_pBlocks);
		tolua_variable(L, "reference_m_pBlocks", tolua_get_CTypedPtrList_CPtrList_CGameEffect___reference_m_pBlocks, NULL);
		tolua_variable(L, "m_nBlockSize", tolua_get_CTypedPtrList_CPtrList_CGameEffect___m_nBlockSize, tolua_set_CTypedPtrList_CPtrList_CGameEffect___m_nBlockSize);
		tolua_variable(L, "reference_m_nBlockSize", tolua_get_CTypedPtrList_CPtrList_CGameEffect___reference_m_nBlockSize, NULL);
		tolua_constant(L, "sizeof", sizeof(CTypedPtrList<CPtrList,CGameEffect*>));
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CGameEffect*>::CNode", "CTypedPtrList<CPtrList,CGameEffect*>::CNode", {}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CGameEffect*>::CNode");
		tolua_variable(L, "pNext", tolua_get_CTypedPtrList_CPtrList_CGameEffect____CNode_pNext, tolua_set_CTypedPtrList_CPtrList_CGameEffect____CNode_pNext);
		tolua_variable(L, "reference_pNext", tolua_get_CTypedPtrList_CPtrList_CGameEffect____CNode_reference_pNext, NULL);
		tolua_variable(L, "pPrev", tolua_get_CTypedPtrList_CPtrList_CGameEffect____CNode_pPrev, tolua_set_CTypedPtrList_CPtrList_CGameEffect____CNode_pPrev);
		tolua_variable(L, "reference_pPrev", tolua_get_CTypedPtrList_CPtrList_CGameEffect____CNode_reference_pPrev, NULL);
		tolua_variable(L, "data", tolua_get_CTypedPtrList_CPtrList_CGameEffect____CNode_data, tolua_set_CTypedPtrList_CPtrList_CGameEffect____CNode_data);
		tolua_variable(L, "reference_data", tolua_get_CTypedPtrList_CPtrList_CGameEffect____CNode_reference_data, NULL);
		tolua_constant(L, "sizeof", sizeof(CTypedPtrList<CPtrList,CGameEffect*>::CNode));
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CGameEffect*>::vtbl", "CTypedPtrList<CPtrList,CGameEffect*>::vtbl", {"CObject::vtbl"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CGameEffect*>::vtbl");
		tolua_constant(L, "sizeof", sizeof(CTypedPtrList<CPtrList,CGameEffect*>::vtbl));
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,int*>", "CTypedPtrList<CPtrList,int*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,int*>");
		tolua_variable(L, "m_pNodeHead", tolua_get_CTypedPtrList_CPtrList_int___m_pNodeHead, tolua_set_CTypedPtrList_CPtrList_int___m_pNodeHead);
		tolua_variable(L, "reference_m_pNodeHead", tolua_get_CTypedPtrList_CPtrList_int___reference_m_pNodeHead, NULL);
		tolua_variable(L, "m_pNodeTail", tolua_get_CTypedPtrList_CPtrList_int___m_pNodeTail, tolua_set_CTypedPtrList_CPtrList_int___m_pNodeTail);
		tolua_variable(L, "reference_m_pNodeTail", tolua_get_CTypedPtrList_CPtrList_int___reference_m_pNodeTail, NULL);
		tolua_variable(L, "m_nCount", tolua_get_CTypedPtrList_CPtrList_int___m_nCount, tolua_set_CTypedPtrList_CPtrList_int___m_nCount);
		tolua_variable(L, "reference_m_nCount", tolua_get_CTypedPtrList_CPtrList_int___reference_m_nCount, NULL);
		tolua_variable(L, "m_pNodeFree", tolua_get_CTypedPtrList_CPtrList_int___m_pNodeFree, tolua_set_CTypedPtrList_CPtrList_int___m_pNodeFree);
		tolua_variable(L, "reference_m_pNodeFree", tolua_get_CTypedPtrList_CPtrList_int___reference_m_pNodeFree, NULL);
		tolua_variable(L, "m_pBlocks", tolua_get_CTypedPtrList_CPtrList_int___m_pBlocks, tolua_set_CTypedPtrList_CPtrList_int___m_pBlocks);
		tolua_variable(L, "reference_m_pBlocks", tolua_get_CTypedPtrList_CPtrList_int___reference_m_pBlocks, NULL);
		tolua_variable(L, "m_nBlockSize", tolua_get_CTypedPtrList_CPtrList_int___m_nBlockSize, tolua_set_CTypedPtrList_CPtrList_int___m_nBlockSize);
		tolua_variable(L, "reference_m_nBlockSize", tolua_get_CTypedPtrList_CPtrList_int___reference_m_nBlockSize, NULL);
		tolua_constant(L, "sizeof", sizeof(CTypedPtrList<CPtrList,int*>));
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,int*>::CNode", "CTypedPtrList<CPtrList,int*>::CNode", {}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,int*>::CNode");
		tolua_variable(L, "pNext", tolua_get_CTypedPtrList_CPtrList_int____CNode_pNext, tolua_set_CTypedPtrList_CPtrList_int____CNode_pNext);
		tolua_variable(L, "reference_pNext", tolua_get_CTypedPtrList_CPtrList_int____CNode_reference_pNext, NULL);
		tolua_variable(L, "pPrev", tolua_get_CTypedPtrList_CPtrList_int____CNode_pPrev, tolua_set_CTypedPtrList_CPtrList_int____CNode_pPrev);
		tolua_variable(L, "reference_pPrev", tolua_get_CTypedPtrList_CPtrList_int____CNode_reference_pPrev, NULL);
		tolua_variable(L, "data", tolua_get_CTypedPtrList_CPtrList_int____CNode_data, tolua_set_CTypedPtrList_CPtrList_int____CNode_data);
		tolua_variable(L, "reference_data", tolua_get_CTypedPtrList_CPtrList_int____CNode_reference_data, NULL);
		tolua_constant(L, "sizeof", sizeof(CTypedPtrList<CPtrList,int*>::CNode));
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,int*>::vtbl", "CTypedPtrList<CPtrList,int*>::vtbl", {"CObject::vtbl"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,int*>::vtbl");
		tolua_constant(L, "sizeof", sizeof(CTypedPtrList<CPtrList,int*>::vtbl));
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,int>", "CTypedPtrList<CPtrList,int>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,int>");
		tolua_variable(L, "m_pNodeHead", tolua_get_CTypedPtrList_CPtrList_int__m_pNodeHead, tolua_set_CTypedPtrList_CPtrList_int__m_pNodeHead);
		tolua_variable(L, "reference_m_pNodeHead", tolua_get_CTypedPtrList_CPtrList_int__reference_m_pNodeHead, NULL);
		tolua_variable(L, "m_pNodeTail", tolua_get_CTypedPtrList_CPtrList_int__m_pNodeTail, tolua_set_CTypedPtrList_CPtrList_int__m_pNodeTail);
		tolua_variable(L, "reference_m_pNodeTail", tolua_get_CTypedPtrList_CPtrList_int__reference_m_pNodeTail, NULL);
		tolua_variable(L, "m_nCount", tolua_get_CTypedPtrList_CPtrList_int__m_nCount, tolua_set_CTypedPtrList_CPtrList_int__m_nCount);
		tolua_variable(L, "reference_m_nCount", tolua_get_CTypedPtrList_CPtrList_int__reference_m_nCount, NULL);
		tolua_variable(L, "m_pNodeFree", tolua_get_CTypedPtrList_CPtrList_int__m_pNodeFree, tolua_set_CTypedPtrList_CPtrList_int__m_pNodeFree);
		tolua_variable(L, "reference_m_pNodeFree", tolua_get_CTypedPtrList_CPtrList_int__reference_m_pNodeFree, NULL);
		tolua_variable(L, "m_pBlocks", tolua_get_CTypedPtrList_CPtrList_int__m_pBlocks, tolua_set_CTypedPtrList_CPtrList_int__m_pBlocks);
		tolua_variable(L, "reference_m_pBlocks", tolua_get_CTypedPtrList_CPtrList_int__reference_m_pBlocks, NULL);
		tolua_variable(L, "m_nBlockSize", tolua_get_CTypedPtrList_CPtrList_int__m_nBlockSize, tolua_set_CTypedPtrList_CPtrList_int__m_nBlockSize);
		tolua_variable(L, "reference_m_nBlockSize", tolua_get_CTypedPtrList_CPtrList_int__reference_m_nBlockSize, NULL);
		tolua_constant(L, "sizeof", sizeof(CTypedPtrList<CPtrList,int>));
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,int>::CNode", "CTypedPtrList<CPtrList,int>::CNode", {}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,int>::CNode");
		tolua_variable(L, "pNext", tolua_get_CTypedPtrList_CPtrList_int___CNode_pNext, tolua_set_CTypedPtrList_CPtrList_int___CNode_pNext);
		tolua_variable(L, "reference_pNext", tolua_get_CTypedPtrList_CPtrList_int___CNode_reference_pNext, NULL);
		tolua_variable(L, "pPrev", tolua_get_CTypedPtrList_CPtrList_int___CNode_pPrev, tolua_set_CTypedPtrList_CPtrList_int___CNode_pPrev);
		tolua_variable(L, "reference_pPrev", tolua_get_CTypedPtrList_CPtrList_int___CNode_reference_pPrev, NULL);
		tolua_variable(L, "data", tolua_get_CTypedPtrList_CPtrList_int___CNode_data, tolua_set_CTypedPtrList_CPtrList_int___CNode_data);
		tolua_variable(L, "reference_data", tolua_get_CTypedPtrList_CPtrList_int___CNode_reference_data, NULL);
		tolua_constant(L, "sizeof", sizeof(CTypedPtrList<CPtrList,int>::CNode));
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,int>::vtbl", "CTypedPtrList<CPtrList,int>::vtbl", {"CObject::vtbl"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,int>::vtbl");
		tolua_constant(L, "sizeof", sizeof(CTypedPtrList<CPtrList,int>::vtbl));
	tolua_endmodule(L);
	tolua_cclass(L, "CAreaTintOverride", "CAreaTintOverride", {}, NULL);
	tolua_beginmodule(L, "CAreaTintOverride");
		tolua_variable(L, "vfptr", tolua_get_CAreaTintOverride_vfptr, NULL);
		tolua_variable(L, "pInfinity", tolua_get_CAreaTintOverride_pInfinity, tolua_set_CAreaTintOverride_pInfinity);
		tolua_variable(L, "reference_pInfinity", tolua_get_CAreaTintOverride_reference_pInfinity, NULL);
		tolua_variable(L, "pVidMode", tolua_get_CAreaTintOverride_pVidMode, tolua_set_CAreaTintOverride_pVidMode);
		tolua_variable(L, "reference_pVidMode", tolua_get_CAreaTintOverride_reference_pVidMode, NULL);
		tolua_variable(L, "nMode", tolua_get_CAreaTintOverride_nMode, tolua_set_CAreaTintOverride_nMode);
		tolua_variable(L, "reference_nMode", tolua_get_CAreaTintOverride_reference_nMode, NULL);
		tolua_variable(L, "nBoundsInfringeCounter", tolua_get_CAreaTintOverride_nBoundsInfringeCounter, tolua_set_CAreaTintOverride_nBoundsInfringeCounter);
		tolua_variable(L, "reference_nBoundsInfringeCounter", tolua_get_CAreaTintOverride_reference_nBoundsInfringeCounter, NULL);
		tolua_variable(L, "nDuration", tolua_get_CAreaTintOverride_nDuration, tolua_set_CAreaTintOverride_nDuration);
		tolua_variable(L, "reference_nDuration", tolua_get_CAreaTintOverride_reference_nDuration, NULL);
		tolua_variable(L, "tintMin", tolua_get_CAreaTintOverride_tintMin, tolua_set_CAreaTintOverride_tintMin);
		tolua_variable(L, "reference_tintMin", tolua_get_CAreaTintOverride_reference_tintMin, NULL);
		tolua_variable(L, "redMin", tolua_get_CAreaTintOverride_redMin, tolua_set_CAreaTintOverride_redMin);
		tolua_variable(L, "reference_redMin", tolua_get_CAreaTintOverride_reference_redMin, NULL);
		tolua_variable(L, "greenMin", tolua_get_CAreaTintOverride_greenMin, tolua_set_CAreaTintOverride_greenMin);
		tolua_variable(L, "reference_greenMin", tolua_get_CAreaTintOverride_reference_greenMin, NULL);
		tolua_variable(L, "blueMin", tolua_get_CAreaTintOverride_blueMin, tolua_set_CAreaTintOverride_blueMin);
		tolua_variable(L, "reference_blueMin", tolua_get_CAreaTintOverride_reference_blueMin, NULL);
		tolua_variable(L, "tintMax", tolua_get_CAreaTintOverride_tintMax, tolua_set_CAreaTintOverride_tintMax);
		tolua_variable(L, "reference_tintMax", tolua_get_CAreaTintOverride_reference_tintMax, NULL);
		tolua_variable(L, "redMax", tolua_get_CAreaTintOverride_redMax, tolua_set_CAreaTintOverride_redMax);
		tolua_variable(L, "reference_redMax", tolua_get_CAreaTintOverride_reference_redMax, NULL);
		tolua_variable(L, "greenMax", tolua_get_CAreaTintOverride_greenMax, tolua_set_CAreaTintOverride_greenMax);
		tolua_variable(L, "reference_greenMax", tolua_get_CAreaTintOverride_reference_greenMax, NULL);
		tolua_variable(L, "blueMax", tolua_get_CAreaTintOverride_blueMax, tolua_set_CAreaTintOverride_blueMax);
		tolua_variable(L, "reference_blueMax", tolua_get_CAreaTintOverride_reference_blueMax, NULL);
		tolua_variable(L, "redStep", tolua_get_CAreaTintOverride_redStep, tolua_set_CAreaTintOverride_redStep);
		tolua_variable(L, "reference_redStep", tolua_get_CAreaTintOverride_reference_redStep, NULL);
		tolua_variable(L, "greenStep", tolua_get_CAreaTintOverride_greenStep, tolua_set_CAreaTintOverride_greenStep);
		tolua_variable(L, "reference_greenStep", tolua_get_CAreaTintOverride_reference_greenStep, NULL);
		tolua_variable(L, "blueStep", tolua_get_CAreaTintOverride_blueStep, tolua_set_CAreaTintOverride_blueStep);
		tolua_variable(L, "reference_blueStep", tolua_get_CAreaTintOverride_reference_blueStep, NULL);
		tolua_variable(L, "nStartingGlobalLighting", tolua_get_CAreaTintOverride_nStartingGlobalLighting, tolua_set_CAreaTintOverride_nStartingGlobalLighting);
		tolua_variable(L, "reference_nStartingGlobalLighting", tolua_get_CAreaTintOverride_reference_nStartingGlobalLighting, NULL);
		tolua_variable(L, "curGlobalTintOverrideStep", tolua_get_CAreaTintOverride_curGlobalTintOverrideStep, tolua_set_CAreaTintOverride_curGlobalTintOverrideStep);
		tolua_variable(L, "reference_curGlobalTintOverrideStep", tolua_get_CAreaTintOverride_reference_curGlobalTintOverrideStep, NULL);
		tolua_variable(L, "curGlobalTintRed", tolua_get_CAreaTintOverride_curGlobalTintRed, tolua_set_CAreaTintOverride_curGlobalTintRed);
		tolua_variable(L, "reference_curGlobalTintRed", tolua_get_CAreaTintOverride_reference_curGlobalTintRed, NULL);
		tolua_variable(L, "curGlobalTintGreen", tolua_get_CAreaTintOverride_curGlobalTintGreen, tolua_set_CAreaTintOverride_curGlobalTintGreen);
		tolua_variable(L, "reference_curGlobalTintGreen", tolua_get_CAreaTintOverride_reference_curGlobalTintGreen, NULL);
		tolua_variable(L, "curGlobalTintBlue", tolua_get_CAreaTintOverride_curGlobalTintBlue, tolua_set_CAreaTintOverride_curGlobalTintBlue);
		tolua_variable(L, "reference_curGlobalTintBlue", tolua_get_CAreaTintOverride_reference_curGlobalTintBlue, NULL);
		tolua_variable(L, "targetType", tolua_get_CAreaTintOverride_targetType, tolua_set_CAreaTintOverride_targetType);
		tolua_variable(L, "reference_targetType", tolua_get_CAreaTintOverride_reference_targetType, NULL);
		tolua_variable(L, "nSourceId", tolua_get_CAreaTintOverride_nSourceId, tolua_set_CAreaTintOverride_nSourceId);
		tolua_variable(L, "reference_nSourceId", tolua_get_CAreaTintOverride_reference_nSourceId, NULL);
		tolua_variable(L, "bIgnoreMode0ResetOnBoundsInfringement", tolua_get_CAreaTintOverride_bIgnoreMode0ResetOnBoundsInfringement, tolua_set_CAreaTintOverride_bIgnoreMode0ResetOnBoundsInfringement);
		tolua_variable(L, "reference_bIgnoreMode0ResetOnBoundsInfringement", tolua_get_CAreaTintOverride_reference_bIgnoreMode0ResetOnBoundsInfringement, NULL);
		tolua_variable(L, "spritesWithSuppressedTintsList", tolua_get_CAreaTintOverride_spritesWithSuppressedTintsList, NULL);
		tolua_constant(L, "sizeof", sizeof(CAreaTintOverride));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameArea", "CGameArea", {}, NULL);
	tolua_beginmodule(L, "CGameArea");
		tolua_variable(L, "m_nCharacters", tolua_get_CGameArea_m_nCharacters, tolua_set_CGameArea_m_nCharacters);
		tolua_variable(L, "reference_m_nCharacters", tolua_get_CGameArea_reference_m_nCharacters, NULL);
		tolua_variable(L, "m_nInfravision", tolua_get_CGameArea_m_nInfravision, tolua_set_CGameArea_m_nInfravision);
		tolua_variable(L, "reference_m_nInfravision", tolua_get_CGameArea_reference_m_nInfravision, NULL);
		tolua_variable(L, "m_bAreaLoaded", tolua_get_CGameArea_m_bAreaLoaded, tolua_set_CGameArea_m_bAreaLoaded);
		tolua_variable(L, "reference_m_bAreaLoaded", tolua_get_CGameArea_reference_m_bAreaLoaded, NULL);
		tolua_variable(L, "m_iPicked", tolua_get_CGameArea_m_iPicked, tolua_set_CGameArea_m_iPicked);
		tolua_variable(L, "reference_m_iPicked", tolua_get_CGameArea_reference_m_iPicked, NULL);
		tolua_variable(L, "m_bPicked", tolua_get_CGameArea_m_bPicked, tolua_set_CGameArea_m_bPicked);
		tolua_variable(L, "reference_m_bPicked", tolua_get_CGameArea_reference_m_bPicked, NULL);
		tolua_variable(L, "m_nToolTip", tolua_get_CGameArea_m_nToolTip, tolua_set_CGameArea_m_nToolTip);
		tolua_variable(L, "reference_m_nToolTip", tolua_get_CGameArea_reference_m_nToolTip, NULL);
		tolua_variable(L, "m_firstRender", tolua_get_CGameArea_m_firstRender, tolua_set_CGameArea_m_firstRender);
		tolua_variable(L, "reference_m_firstRender", tolua_get_CGameArea_reference_m_firstRender, NULL);
		tolua_variable(L, "m_nAIIndex", tolua_get_CGameArea_m_nAIIndex, tolua_set_CGameArea_m_nAIIndex);
		tolua_variable(L, "reference_m_nAIIndex", tolua_get_CGameArea_reference_m_nAIIndex, NULL);
		tolua_variable(L, "m_cInfinity", tolua_get_CGameArea_m_cInfinity, NULL);
		tolua_variable(L, "m_lVertSort", tolua_get_CGameArea_m_lVertSort, NULL);
		tolua_variable(L, "m_nScreenFlash", tolua_get_CGameArea_m_nScreenFlash, tolua_set_CGameArea_m_nScreenFlash);
		tolua_variable(L, "reference_m_nScreenFlash", tolua_get_CGameArea_reference_m_nScreenFlash, NULL);
		tolua_variable(L, "mpSpawner", tolua_get_CGameArea_mpSpawner, tolua_set_CGameArea_mpSpawner);
		tolua_variable(L, "reference_mpSpawner", tolua_get_CGameArea_reference_mpSpawner, NULL);
		tolua_constant(L, "sizeof", sizeof(CGameArea));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameEffectList", "CGameEffectList", {"CTypedPtrList<CPtrList,CGameEffect*>"}, NULL);
	tolua_beginmodule(L, "CGameEffectList");
		tolua_variable(L, "m_posNext", tolua_get_CGameEffectList_m_posNext, tolua_set_CGameEffectList_m_posNext);
		tolua_variable(L, "reference_m_posNext", tolua_get_CGameEffectList_reference_m_posNext, NULL);
		tolua_variable(L, "m_posCurrent", tolua_get_CGameEffectList_m_posCurrent, tolua_set_CGameEffectList_m_posCurrent);
		tolua_variable(L, "reference_m_posCurrent", tolua_get_CGameEffectList_reference_m_posCurrent, NULL);
		tolua_variable(L, "m_newEffect", tolua_get_CGameEffectList_m_newEffect, tolua_set_CGameEffectList_m_newEffect);
		tolua_variable(L, "reference_m_newEffect", tolua_get_CGameEffectList_reference_m_newEffect, NULL);
		tolua_variable(L, "m_retry", tolua_get_CGameEffectList_m_retry, tolua_set_CGameEffectList_m_retry);
		tolua_variable(L, "reference_m_retry", tolua_get_CGameEffectList_reference_m_retry, NULL);
		tolua_constant(L, "sizeof", sizeof(CGameEffectList));
	tolua_endmodule(L);
	tolua_cclass(L, "Array<uchar,8>", "Array<uchar,8>", {}, NULL);
	tolua_beginmodule(L, "Array<uchar,8>");
		tolua_function(L, "getReference", &tolua_function_Array_uchar_8__getReference);
		tolua_function(L, "set", &tolua_function_Array_uchar_8__set);
		tolua_constant(L, "sizeof", sizeof(Array<uchar,8>));
		tolua_constant(L, "size", 8);
		tolua_constant(L, "lastIndex", 7);
	tolua_endmodule(L);
	tolua_cclass(L, "Array<CProjectileUnknownPST2*,10>", "Array<CProjectileUnknownPST2*,10>", {}, NULL);
	tolua_beginmodule(L, "Array<CProjectileUnknownPST2*,10>");
		tolua_function(L, "get", &tolua_function_Array_CProjectileUnknownPST2__10__get);
		tolua_function(L, "getReference", &tolua_function_Array_CProjectileUnknownPST2__10__getReference);
		tolua_function(L, "set", &tolua_function_Array_CProjectileUnknownPST2__10__set);
		tolua_constant(L, "sizeof", sizeof(Array<CProjectileUnknownPST2*,10>));
		tolua_constant(L, "size", 10);
		tolua_constant(L, "lastIndex", 9);
	tolua_endmodule(L);
	tolua_cclass(L, "Array<ulong,15>", "Array<ulong,15>", {}, NULL);
	tolua_beginmodule(L, "Array<ulong,15>");
		tolua_function(L, "getReference", &tolua_function_Array_ulong_15__getReference);
		tolua_function(L, "set", &tolua_function_Array_ulong_15__set);
		tolua_constant(L, "sizeof", sizeof(Array<ulong,15>));
		tolua_constant(L, "size", 15);
		tolua_constant(L, "lastIndex", 14);
	tolua_endmodule(L);
	tolua_cclass(L, "Array<char,32>", "Array<char,32>", {}, NULL);
	tolua_beginmodule(L, "Array<char,32>");
		tolua_function(L, "get", &tolua_function_Array_char_32__get);
		tolua_function(L, "set", &tolua_function_Array_char_32__set);
		tolua_constant(L, "sizeof", sizeof(Array<char,32>));
		tolua_constant(L, "size", 32);
		tolua_constant(L, "lastIndex", 31);
	tolua_endmodule(L);
	tolua_cclass(L, "Array<CGameArea*,12>", "Array<CGameArea*,12>", {}, NULL);
	tolua_beginmodule(L, "Array<CGameArea*,12>");
		tolua_function(L, "get", &tolua_function_Array_CGameArea__12__get);
		tolua_function(L, "getReference", &tolua_function_Array_CGameArea__12__getReference);
		tolua_function(L, "set", &tolua_function_Array_CGameArea__12__set);
		tolua_constant(L, "sizeof", sizeof(Array<CGameArea*,12>));
		tolua_constant(L, "size", 12);
		tolua_constant(L, "lastIndex", 11);
	tolua_endmodule(L);
	tolua_cclass(L, "Array<long,6>", "Array<long,6>", {}, NULL);
	tolua_beginmodule(L, "Array<long,6>");
		tolua_function(L, "get", &tolua_function_Array_long_6__get);
		tolua_function(L, "getReference", &tolua_function_Array_long_6__getReference);
		tolua_function(L, "set", &tolua_function_Array_long_6__set);
		tolua_constant(L, "sizeof", sizeof(Array<long,6>));
		tolua_constant(L, "size", 6);
		tolua_constant(L, "lastIndex", 5);
	tolua_endmodule(L);
	tolua_cclass(L, "Array<ulong,8>", "Array<ulong,8>", {}, NULL);
	tolua_beginmodule(L, "Array<ulong,8>");
		tolua_function(L, "getReference", &tolua_function_Array_ulong_8__getReference);
		tolua_function(L, "set", &tolua_function_Array_ulong_8__set);
		tolua_constant(L, "sizeof", sizeof(Array<ulong,8>));
		tolua_constant(L, "size", 8);
		tolua_constant(L, "lastIndex", 7);
	tolua_endmodule(L);
	tolua_cclass(L, "Array<byte,5>", "Array<byte,5>", {}, NULL);
	tolua_beginmodule(L, "Array<byte,5>");
		tolua_function(L, "get", &tolua_function_Array_byte_5__get);
		tolua_function(L, "getReference", &tolua_function_Array_byte_5__getReference);
		tolua_function(L, "set", &tolua_function_Array_byte_5__set);
		tolua_constant(L, "sizeof", sizeof(Array<byte,5>));
		tolua_constant(L, "size", 5);
		tolua_constant(L, "lastIndex", 4);
	tolua_endmodule(L);
	tolua_cclass(L, "LCharString<32>", "LCharString<32>", {}, NULL);
	tolua_beginmodule(L, "LCharString<32>");
		tolua_function(L, "getChar", &tolua_function_LCharString_32__getChar);
		tolua_function(L, "setChar", &tolua_function_LCharString_32__setChar);
		tolua_function(L, "set", &tolua_function_LCharString_32__set);
		tolua_function(L, "get", &tolua_function_LCharString_32__get);
		tolua_constant(L, "sizeof", sizeof(LCharString<32>));
	tolua_endmodule(L);
	tolua_cclass(L, "CResRef", "CResRef", {}, NULL);
	tolua_beginmodule(L, "CResRef");
		tolua_variable(L, "m_resRef", tolua_get_CResRef_m_resRef, NULL);
		tolua_function(L, "get", &tolua_function_CResRef_get);
		tolua_function(L, "set", &tolua_function_CResRef_set);
		tolua_function(L, "copy", &tolua_function_CResRef_copy);
		tolua_constant(L, "sizeof", sizeof(CResRef));
	tolua_endmodule(L);
	tolua_cclass(L, "Item_effect_st", "Item_effect_st", {}, NULL);
	tolua_beginmodule(L, "Item_effect_st");
		tolua_variable(L, "effectID", tolua_get_Item_effect_st_effectID, tolua_set_Item_effect_st_effectID);
		tolua_variable(L, "reference_effectID", tolua_get_Item_effect_st_reference_effectID, NULL);
		tolua_variable(L, "targetType", tolua_get_Item_effect_st_targetType, tolua_set_Item_effect_st_targetType);
		tolua_variable(L, "reference_targetType", tolua_get_Item_effect_st_reference_targetType, NULL);
		tolua_variable(L, "spellLevel", tolua_get_Item_effect_st_spellLevel, tolua_set_Item_effect_st_spellLevel);
		tolua_variable(L, "reference_spellLevel", tolua_get_Item_effect_st_reference_spellLevel, NULL);
		tolua_variable(L, "effectAmount", tolua_get_Item_effect_st_effectAmount, tolua_set_Item_effect_st_effectAmount);
		tolua_variable(L, "reference_effectAmount", tolua_get_Item_effect_st_reference_effectAmount, NULL);
		tolua_variable(L, "dwFlags", tolua_get_Item_effect_st_dwFlags, tolua_set_Item_effect_st_dwFlags);
		tolua_variable(L, "reference_dwFlags", tolua_get_Item_effect_st_reference_dwFlags, NULL);
		tolua_variable(L, "durationType", tolua_get_Item_effect_st_durationType, tolua_set_Item_effect_st_durationType);
		tolua_variable(L, "reference_durationType", tolua_get_Item_effect_st_reference_durationType, NULL);
		tolua_variable(L, "duration", tolua_get_Item_effect_st_duration, tolua_set_Item_effect_st_duration);
		tolua_variable(L, "reference_duration", tolua_get_Item_effect_st_reference_duration, NULL);
		tolua_variable(L, "probabilityUpper", tolua_get_Item_effect_st_probabilityUpper, tolua_set_Item_effect_st_probabilityUpper);
		tolua_variable(L, "reference_probabilityUpper", tolua_get_Item_effect_st_reference_probabilityUpper, NULL);
		tolua_variable(L, "probabilityLower", tolua_get_Item_effect_st_probabilityLower, tolua_set_Item_effect_st_probabilityLower);
		tolua_variable(L, "reference_probabilityLower", tolua_get_Item_effect_st_reference_probabilityLower, NULL);
		tolua_variable(L, "res", tolua_get_Item_effect_st_res, NULL);
		tolua_variable(L, "numDice", tolua_get_Item_effect_st_numDice, tolua_set_Item_effect_st_numDice);
		tolua_variable(L, "reference_numDice", tolua_get_Item_effect_st_reference_numDice, NULL);
		tolua_variable(L, "diceSize", tolua_get_Item_effect_st_diceSize, tolua_set_Item_effect_st_diceSize);
		tolua_variable(L, "reference_diceSize", tolua_get_Item_effect_st_reference_diceSize, NULL);
		tolua_variable(L, "savingThrow", tolua_get_Item_effect_st_savingThrow, tolua_set_Item_effect_st_savingThrow);
		tolua_variable(L, "reference_savingThrow", tolua_get_Item_effect_st_reference_savingThrow, NULL);
		tolua_variable(L, "saveMod", tolua_get_Item_effect_st_saveMod, tolua_set_Item_effect_st_saveMod);
		tolua_variable(L, "reference_saveMod", tolua_get_Item_effect_st_reference_saveMod, NULL);
		tolua_variable(L, "special", tolua_get_Item_effect_st_special, tolua_set_Item_effect_st_special);
		tolua_variable(L, "reference_special", tolua_get_Item_effect_st_reference_special, NULL);
		tolua_constant(L, "sizeof", sizeof(Item_effect_st));
	tolua_endmodule(L);
	tolua_cclass(L, "CResHelper<CResCell,1000>", "CResHelper<CResCell,1000>", {}, NULL);
	tolua_beginmodule(L, "CResHelper<CResCell,1000>");
		tolua_variable(L, "pRes", tolua_get_CResHelper_CResCell_1000__pRes, tolua_set_CResHelper_CResCell_1000__pRes);
		tolua_variable(L, "reference_pRes", tolua_get_CResHelper_CResCell_1000__reference_pRes, NULL);
		tolua_variable(L, "cResRef", tolua_get_CResHelper_CResCell_1000__cResRef, NULL);
		tolua_constant(L, "sizeof", sizeof(CResHelper<CResCell,1000>));
	tolua_endmodule(L);
	tolua_cclass(L, "CVidCell", "CVidCell", {}, NULL);
	tolua_beginmodule(L, "CVidCell");
		tolua_variable(L, "vidImage", tolua_get_CVidCell_vidImage, NULL);
		tolua_variable(L, "resHelper", tolua_get_CVidCell_resHelper, NULL);
		tolua_variable(L, "m_nCurrentFrame", tolua_get_CVidCell_m_nCurrentFrame, tolua_set_CVidCell_m_nCurrentFrame);
		tolua_variable(L, "reference_m_nCurrentFrame", tolua_get_CVidCell_reference_m_nCurrentFrame, NULL);
		tolua_variable(L, "m_nCurrentSequence", tolua_get_CVidCell_m_nCurrentSequence, tolua_set_CVidCell_m_nCurrentSequence);
		tolua_variable(L, "reference_m_nCurrentSequence", tolua_get_CVidCell_reference_m_nCurrentSequence, NULL);
		tolua_variable(L, "m_nAnimType", tolua_get_CVidCell_m_nAnimType, tolua_set_CVidCell_m_nAnimType);
		tolua_variable(L, "reference_m_nAnimType", tolua_get_CVidCell_reference_m_nAnimType, NULL);
		tolua_variable(L, "m_bPaletteChanged", tolua_get_CVidCell_m_bPaletteChanged, tolua_set_CVidCell_m_bPaletteChanged);
		tolua_variable(L, "reference_m_bPaletteChanged", tolua_get_CVidCell_reference_m_bPaletteChanged, NULL);
		tolua_variable(L, "m_pFrame", tolua_get_CVidCell_m_pFrame, tolua_set_CVidCell_m_pFrame);
		tolua_variable(L, "reference_m_pFrame", tolua_get_CVidCell_reference_m_pFrame, NULL);
		tolua_variable(L, "m_bShadowOn", tolua_get_CVidCell_m_bShadowOn, tolua_set_CVidCell_m_bShadowOn);
		tolua_variable(L, "reference_m_bShadowOn", tolua_get_CVidCell_reference_m_bShadowOn, NULL);
		tolua_constant(L, "sizeof", sizeof(CVidCell));
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CInfGame", "EEex_CInfGame", {}, NULL);
	tolua_beginmodule(L, "EEex_CInfGame");
		tolua_variable(L, "m_worldTime", tolua_get_CInfGame_m_worldTime, NULL);
		tolua_variable(L, "m_bGameLoaded", tolua_get_CInfGame_m_bGameLoaded, tolua_set_CInfGame_m_bGameLoaded);
		tolua_variable(L, "reference_m_bGameLoaded", tolua_get_CInfGame_reference_m_bGameLoaded, NULL);
		tolua_variable(L, "m_bInDestroyGame", tolua_get_CInfGame_m_bInDestroyGame, tolua_set_CInfGame_m_bInDestroyGame);
		tolua_variable(L, "reference_m_bInDestroyGame", tolua_get_CInfGame_reference_m_bInDestroyGame, NULL);
		tolua_variable(L, "m_nState", tolua_get_CInfGame_m_nState, tolua_set_CInfGame_m_nState);
		tolua_variable(L, "reference_m_nState", tolua_get_CInfGame_reference_m_nState, NULL);
		tolua_variable(L, "m_iconCount", tolua_get_CInfGame_m_iconCount, tolua_set_CInfGame_m_iconCount);
		tolua_variable(L, "reference_m_iconCount", tolua_get_CInfGame_reference_m_iconCount, NULL);
		tolua_variable(L, "m_iconIndex", tolua_get_CInfGame_m_iconIndex, tolua_set_CInfGame_m_iconIndex);
		tolua_variable(L, "reference_m_iconIndex", tolua_get_CInfGame_reference_m_iconIndex, NULL);
		tolua_variable(L, "m_tempCursor", tolua_get_CInfGame_m_tempCursor, tolua_set_CInfGame_m_tempCursor);
		tolua_variable(L, "reference_m_tempCursor", tolua_get_CInfGame_reference_m_tempCursor, NULL);
		tolua_variable(L, "m_visibleArea", tolua_get_CInfGame_m_visibleArea, tolua_set_CInfGame_m_visibleArea);
		tolua_variable(L, "reference_m_visibleArea", tolua_get_CInfGame_reference_m_visibleArea, NULL);
		tolua_variable(L, "m_gameAreas", tolua_get_CInfGame_m_gameAreas, NULL);
		tolua_variable(L, "m_pGameAreaMaster", tolua_get_CInfGame_m_pGameAreaMaster, tolua_set_CInfGame_m_pGameAreaMaster);
		tolua_variable(L, "reference_m_pGameAreaMaster", tolua_get_CInfGame_reference_m_pGameAreaMaster, NULL);
		tolua_variable(L, "m_characters", tolua_get_CInfGame_m_characters, NULL);
		tolua_variable(L, "m_charactersPortrait", tolua_get_CInfGame_m_charactersPortrait, NULL);
		tolua_variable(L, "m_nCharacters", tolua_get_CInfGame_m_nCharacters, tolua_set_CInfGame_m_nCharacters);
		tolua_variable(L, "reference_m_nCharacters", tolua_get_CInfGame_reference_m_nCharacters, NULL);
		tolua_variable(L, "m_nTutorialState", tolua_get_CInfGame_m_nTutorialState, NULL);
		tolua_variable(L, "m_searchRequestListEmpty", tolua_get_CInfGame_m_searchRequestListEmpty, tolua_set_CInfGame_m_searchRequestListEmpty);
		tolua_variable(L, "reference_m_searchRequestListEmpty", tolua_get_CInfGame_reference_m_searchRequestListEmpty, NULL);
		tolua_variable(L, "m_currArmor", tolua_get_CInfGame_m_currArmor, tolua_set_CInfGame_m_currArmor);
		tolua_variable(L, "reference_m_currArmor", tolua_get_CInfGame_reference_m_currArmor, NULL);
		tolua_variable(L, "m_currAnimation", tolua_get_CInfGame_m_currAnimation, tolua_set_CInfGame_m_currAnimation);
		tolua_variable(L, "reference_m_currAnimation", tolua_get_CInfGame_reference_m_currAnimation, NULL);
		tolua_variable(L, "m_gameTime", tolua_get_CInfGame_m_gameTime, tolua_set_CInfGame_m_gameTime);
		tolua_variable(L, "reference_m_gameTime", tolua_get_CInfGame_reference_m_gameTime, NULL);
		tolua_constant(L, "sizeof", sizeof(CInfGame));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameEffectBase", "CGameEffectBase", {}, NULL);
	tolua_beginmodule(L, "CGameEffectBase");
		tolua_variable(L, "m_version", tolua_get_CGameEffectBase_m_version, NULL);
		tolua_variable(L, "m_effectId", tolua_get_CGameEffectBase_m_effectId, NULL);
		tolua_variable(L, "m_targetType", tolua_get_CGameEffectBase_m_targetType, NULL);
		tolua_variable(L, "m_spellLevel", tolua_get_CGameEffectBase_m_spellLevel, NULL);
		tolua_variable(L, "m_effectAmount", tolua_get_CGameEffectBase_m_effectAmount, tolua_set_CGameEffectBase_m_effectAmount);
		tolua_variable(L, "reference_m_effectAmount", tolua_get_CGameEffectBase_reference_m_effectAmount, NULL);
		tolua_variable(L, "m_dWFlags", tolua_get_CGameEffectBase_m_dWFlags, NULL);
		tolua_variable(L, "m_durationType", tolua_get_CGameEffectBase_m_durationType, NULL);
		tolua_variable(L, "m_duration", tolua_get_CGameEffectBase_m_duration, NULL);
		tolua_variable(L, "m_probabilityUpper", tolua_get_CGameEffectBase_m_probabilityUpper, tolua_set_CGameEffectBase_m_probabilityUpper);
		tolua_variable(L, "reference_m_probabilityUpper", tolua_get_CGameEffectBase_reference_m_probabilityUpper, NULL);
		tolua_variable(L, "m_probabilityLower", tolua_get_CGameEffectBase_m_probabilityLower, tolua_set_CGameEffectBase_m_probabilityLower);
		tolua_variable(L, "reference_m_probabilityLower", tolua_get_CGameEffectBase_reference_m_probabilityLower, NULL);
		tolua_variable(L, "m_res", tolua_get_CGameEffectBase_m_res, NULL);
		tolua_variable(L, "m_numDice", tolua_get_CGameEffectBase_m_numDice, NULL);
		tolua_variable(L, "m_diceSize", tolua_get_CGameEffectBase_m_diceSize, NULL);
		tolua_variable(L, "m_savingThrow", tolua_get_CGameEffectBase_m_savingThrow, NULL);
		tolua_variable(L, "m_saveMod", tolua_get_CGameEffectBase_m_saveMod, tolua_set_CGameEffectBase_m_saveMod);
		tolua_variable(L, "reference_m_saveMod", tolua_get_CGameEffectBase_reference_m_saveMod, NULL);
		tolua_variable(L, "m_special", tolua_get_CGameEffectBase_m_special, NULL);
		tolua_variable(L, "m_school", tolua_get_CGameEffectBase_m_school, NULL);
		tolua_variable(L, "m_JeremyIsAnIdiot", tolua_get_CGameEffectBase_m_JeremyIsAnIdiot, NULL);
		tolua_variable(L, "m_minLevel", tolua_get_CGameEffectBase_m_minLevel, NULL);
		tolua_variable(L, "m_maxLevel", tolua_get_CGameEffectBase_m_maxLevel, NULL);
		tolua_variable(L, "m_flags", tolua_get_CGameEffectBase_m_flags, NULL);
		tolua_variable(L, "m_effectAmount2", tolua_get_CGameEffectBase_m_effectAmount2, tolua_set_CGameEffectBase_m_effectAmount2);
		tolua_variable(L, "reference_m_effectAmount2", tolua_get_CGameEffectBase_reference_m_effectAmount2, NULL);
		tolua_variable(L, "m_effectAmount3", tolua_get_CGameEffectBase_m_effectAmount3, tolua_set_CGameEffectBase_m_effectAmount3);
		tolua_variable(L, "reference_m_effectAmount3", tolua_get_CGameEffectBase_reference_m_effectAmount3, NULL);
		tolua_variable(L, "m_effectAmount4", tolua_get_CGameEffectBase_m_effectAmount4, tolua_set_CGameEffectBase_m_effectAmount4);
		tolua_variable(L, "reference_m_effectAmount4", tolua_get_CGameEffectBase_reference_m_effectAmount4, NULL);
		tolua_variable(L, "m_effectAmount5", tolua_get_CGameEffectBase_m_effectAmount5, tolua_set_CGameEffectBase_m_effectAmount5);
		tolua_variable(L, "reference_m_effectAmount5", tolua_get_CGameEffectBase_reference_m_effectAmount5, NULL);
		tolua_variable(L, "m_res2", tolua_get_CGameEffectBase_m_res2, NULL);
		tolua_variable(L, "m_res3", tolua_get_CGameEffectBase_m_res3, NULL);
		tolua_variable(L, "m_source", tolua_get_CGameEffectBase_m_source, NULL);
		tolua_variable(L, "m_target", tolua_get_CGameEffectBase_m_target, NULL);
		tolua_variable(L, "m_sourceType", tolua_get_CGameEffectBase_m_sourceType, NULL);
		tolua_variable(L, "m_sourceRes", tolua_get_CGameEffectBase_m_sourceRes, NULL);
		tolua_variable(L, "m_sourceFlags", tolua_get_CGameEffectBase_m_sourceFlags, NULL);
		tolua_variable(L, "m_projectileType", tolua_get_CGameEffectBase_m_projectileType, NULL);
		tolua_variable(L, "m_slotNum", tolua_get_CGameEffectBase_m_slotNum, tolua_set_CGameEffectBase_m_slotNum);
		tolua_variable(L, "reference_m_slotNum", tolua_get_CGameEffectBase_reference_m_slotNum, NULL);
		tolua_variable(L, "m_scriptName", tolua_get_CGameEffectBase_m_scriptName, NULL);
		tolua_variable(L, "m_casterLevel", tolua_get_CGameEffectBase_m_casterLevel, NULL);
		tolua_variable(L, "m_firstCall", tolua_get_CGameEffectBase_m_firstCall, NULL);
		tolua_variable(L, "m_secondaryType", tolua_get_CGameEffectBase_m_secondaryType, NULL);
		tolua_variable(L, "m_pad", tolua_get_CGameEffectBase_m_pad, NULL);
		tolua_constant(L, "sizeof", sizeof(CGameEffectBase));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameEffect", "CGameEffect", {"CGameEffectBase"}, NULL);
	tolua_beginmodule(L, "CGameEffect");
		tolua_variable(L, "m_sourceId", tolua_get_CGameEffect_m_sourceId, tolua_set_CGameEffect_m_sourceId);
		tolua_variable(L, "reference_m_sourceId", tolua_get_CGameEffect_reference_m_sourceId, NULL);
		tolua_variable(L, "m_done", tolua_get_CGameEffect_m_done, tolua_set_CGameEffect_m_done);
		tolua_variable(L, "reference_m_done", tolua_get_CGameEffect_reference_m_done, NULL);
		tolua_variable(L, "m_forceRepass", tolua_get_CGameEffect_m_forceRepass, tolua_set_CGameEffect_m_forceRepass);
		tolua_variable(L, "reference_m_forceRepass", tolua_get_CGameEffect_reference_m_forceRepass, NULL);
		tolua_variable(L, "m_durationTemp", tolua_get_CGameEffect_m_durationTemp, NULL);
		tolua_variable(L, "m_compareIdOnly", tolua_get_CGameEffect_m_compareIdOnly, tolua_set_CGameEffect_m_compareIdOnly);
		tolua_variable(L, "reference_m_compareIdOnly", tolua_get_CGameEffect_reference_m_compareIdOnly, NULL);
		tolua_variable(L, "m_compareIdAndFlagsOnly", tolua_get_CGameEffect_m_compareIdAndFlagsOnly, tolua_set_CGameEffect_m_compareIdAndFlagsOnly);
		tolua_variable(L, "reference_m_compareIdAndFlagsOnly", tolua_get_CGameEffect_reference_m_compareIdAndFlagsOnly, NULL);
		tolua_variable(L, "m_compareIdAndEffectAmountOnly", tolua_get_CGameEffect_m_compareIdAndEffectAmountOnly, tolua_set_CGameEffect_m_compareIdAndEffectAmountOnly);
		tolua_variable(L, "reference_m_compareIdAndEffectAmountOnly", tolua_get_CGameEffect_reference_m_compareIdAndEffectAmountOnly, NULL);
		tolua_variable(L, "m_compareIdAndResrefOnly", tolua_get_CGameEffect_m_compareIdAndResrefOnly, tolua_set_CGameEffect_m_compareIdAndResrefOnly);
		tolua_variable(L, "reference_m_compareIdAndResrefOnly", tolua_get_CGameEffect_reference_m_compareIdAndResrefOnly, NULL);
		tolua_variable(L, "m_sound", tolua_get_CGameEffect_m_sound, NULL);
		tolua_variable(L, "m_sourceTarget", tolua_get_CGameEffect_m_sourceTarget, tolua_set_CGameEffect_m_sourceTarget);
		tolua_variable(L, "reference_m_sourceTarget", tolua_get_CGameEffect_reference_m_sourceTarget, NULL);
		tolua_variable(L, "unknownResRef", tolua_get_CGameEffect_unknownResRef, NULL);
		tolua_variable(L, "reference_DecodeEffect", tolua_get_reference_CGameEffect_DecodeEffect, NULL);
		tolua_function(L, "DecodeEffect", &tolua_function_CGameEffect_DecodeEffect);
		tolua_constant(L, "sizeof", sizeof(CGameEffect));
	tolua_endmodule(L);
	tolua_cclass(L, "CDerivedStats", "CDerivedStats", {}, NULL);
	tolua_beginmodule(L, "CDerivedStats");
		tolua_variable(L, "m_generalState", tolua_get_CDerivedStats_m_generalState, tolua_set_CDerivedStats_m_generalState);
		tolua_variable(L, "reference_m_generalState", tolua_get_CDerivedStats_reference_m_generalState, NULL);
		tolua_variable(L, "m_nResistMagic", tolua_get_CDerivedStats_m_nResistMagic, tolua_set_CDerivedStats_m_nResistMagic);
		tolua_variable(L, "reference_m_nResistMagic", tolua_get_CDerivedStats_reference_m_nResistMagic, NULL);
		tolua_variable(L, "m_nLuck", tolua_get_CDerivedStats_m_nLuck, tolua_set_CDerivedStats_m_nLuck);
		tolua_variable(L, "reference_m_nLuck", tolua_get_CDerivedStats_reference_m_nLuck, NULL);
		tolua_variable(L, "m_nTurnUndeadLevel", tolua_get_CDerivedStats_m_nTurnUndeadLevel, tolua_set_CDerivedStats_m_nTurnUndeadLevel);
		tolua_variable(L, "reference_m_nTurnUndeadLevel", tolua_get_CDerivedStats_reference_m_nTurnUndeadLevel, NULL);
		tolua_variable(L, "m_nBackstabDamageMultiplier", tolua_get_CDerivedStats_m_nBackstabDamageMultiplier, tolua_set_CDerivedStats_m_nBackstabDamageMultiplier);
		tolua_variable(L, "reference_m_nBackstabDamageMultiplier", tolua_get_CDerivedStats_reference_m_nBackstabDamageMultiplier, NULL);
		tolua_variable(L, "m_nLayOnHandsAmount", tolua_get_CDerivedStats_m_nLayOnHandsAmount, tolua_set_CDerivedStats_m_nLayOnHandsAmount);
		tolua_variable(L, "reference_m_nLayOnHandsAmount", tolua_get_CDerivedStats_reference_m_nLayOnHandsAmount, NULL);
		tolua_variable(L, "m_appliedColorEffects", tolua_get_CDerivedStats_m_appliedColorEffects, NULL);
		tolua_variable(L, "m_spellStates", tolua_get_CDerivedStats_m_spellStates, NULL);
		tolua_constant(L, "sizeof", sizeof(CDerivedStats));
	tolua_endmodule(L);
	tolua_cclass(L, "CAreaVariable", "CAreaVariable", {}, NULL);
	tolua_beginmodule(L, "CAreaVariable");
		tolua_variable(L, "m_name", tolua_get_CAreaVariable_m_name, NULL);
		tolua_variable(L, "m_type", tolua_get_CAreaVariable_m_type, tolua_set_CAreaVariable_m_type);
		tolua_variable(L, "reference_m_type", tolua_get_CAreaVariable_reference_m_type, NULL);
		tolua_variable(L, "m_resRefType", tolua_get_CAreaVariable_m_resRefType, tolua_set_CAreaVariable_m_resRefType);
		tolua_variable(L, "reference_m_resRefType", tolua_get_CAreaVariable_reference_m_resRefType, NULL);
		tolua_variable(L, "m_dWValue", tolua_get_CAreaVariable_m_dWValue, NULL);
		tolua_variable(L, "m_intValue", tolua_get_CAreaVariable_m_intValue, tolua_set_CAreaVariable_m_intValue);
		tolua_variable(L, "reference_m_intValue", tolua_get_CAreaVariable_reference_m_intValue, NULL);
		tolua_variable(L, "m_floatValue", tolua_get_CAreaVariable_m_floatValue, tolua_set_CAreaVariable_m_floatValue);
		tolua_variable(L, "reference_m_floatValue", tolua_get_CAreaVariable_reference_m_floatValue, NULL);
		tolua_variable(L, "m_stringValue", tolua_get_CAreaVariable_m_stringValue, NULL);
		tolua_constant(L, "sizeof", sizeof(CAreaVariable));
	tolua_endmodule(L);
	tolua_cclass(L, "CVariable", "CVariable", {"CAreaVariable"}, NULL);
	tolua_beginmodule(L, "CVariable");
		tolua_constant(L, "sizeof", sizeof(CVariable));
	tolua_endmodule(L);
	tolua_cclass(L, "CAIObjectType", "CAIObjectType", {}, NULL);
	tolua_beginmodule(L, "CAIObjectType");
		tolua_variable(L, "m_name", tolua_get_CAIObjectType_m_name, NULL);
		tolua_variable(L, "m_EnemyAlly", tolua_get_CAIObjectType_m_EnemyAlly, tolua_set_CAIObjectType_m_EnemyAlly);
		tolua_variable(L, "reference_m_EnemyAlly", tolua_get_CAIObjectType_reference_m_EnemyAlly, NULL);
		tolua_variable(L, "m_General", tolua_get_CAIObjectType_m_General, tolua_set_CAIObjectType_m_General);
		tolua_variable(L, "reference_m_General", tolua_get_CAIObjectType_reference_m_General, NULL);
		tolua_variable(L, "m_Race", tolua_get_CAIObjectType_m_Race, tolua_set_CAIObjectType_m_Race);
		tolua_variable(L, "reference_m_Race", tolua_get_CAIObjectType_reference_m_Race, NULL);
		tolua_variable(L, "m_Class", tolua_get_CAIObjectType_m_Class, tolua_set_CAIObjectType_m_Class);
		tolua_variable(L, "reference_m_Class", tolua_get_CAIObjectType_reference_m_Class, NULL);
		tolua_variable(L, "m_Instance", tolua_get_CAIObjectType_m_Instance, tolua_set_CAIObjectType_m_Instance);
		tolua_variable(L, "reference_m_Instance", tolua_get_CAIObjectType_reference_m_Instance, NULL);
		tolua_variable(L, "m_SpecialCase", tolua_get_CAIObjectType_m_SpecialCase, NULL);
		tolua_variable(L, "m_Specifics", tolua_get_CAIObjectType_m_Specifics, tolua_set_CAIObjectType_m_Specifics);
		tolua_variable(L, "reference_m_Specifics", tolua_get_CAIObjectType_reference_m_Specifics, NULL);
		tolua_variable(L, "m_Gender", tolua_get_CAIObjectType_m_Gender, tolua_set_CAIObjectType_m_Gender);
		tolua_variable(L, "reference_m_Gender", tolua_get_CAIObjectType_reference_m_Gender, NULL);
		tolua_variable(L, "m_Alignment", tolua_get_CAIObjectType_m_Alignment, tolua_set_CAIObjectType_m_Alignment);
		tolua_variable(L, "reference_m_Alignment", tolua_get_CAIObjectType_reference_m_Alignment, NULL);
		tolua_constant(L, "sizeof", sizeof(CAIObjectType));
	tolua_endmodule(L);
	tolua_cclass(L, "CAIAction", "CAIAction", {}, NULL);
	tolua_beginmodule(L, "CAIAction");
		tolua_variable(L, "m_actionID", tolua_get_CAIAction_m_actionID, tolua_set_CAIAction_m_actionID);
		tolua_variable(L, "reference_m_actionID", tolua_get_CAIAction_reference_m_actionID, NULL);
		tolua_variable(L, "m_actorID", tolua_get_CAIAction_m_actorID, NULL);
		tolua_variable(L, "m_acteeID", tolua_get_CAIAction_m_acteeID, NULL);
		tolua_variable(L, "m_acteeID2", tolua_get_CAIAction_m_acteeID2, NULL);
		tolua_variable(L, "m_specificID", tolua_get_CAIAction_m_specificID, tolua_set_CAIAction_m_specificID);
		tolua_variable(L, "reference_m_specificID", tolua_get_CAIAction_reference_m_specificID, NULL);
		tolua_variable(L, "m_specificID2", tolua_get_CAIAction_m_specificID2, tolua_set_CAIAction_m_specificID2);
		tolua_variable(L, "reference_m_specificID2", tolua_get_CAIAction_reference_m_specificID2, NULL);
		tolua_variable(L, "m_specificID3", tolua_get_CAIAction_m_specificID3, tolua_set_CAIAction_m_specificID3);
		tolua_variable(L, "reference_m_specificID3", tolua_get_CAIAction_reference_m_specificID3, NULL);
		tolua_variable(L, "m_string1", tolua_get_CAIAction_m_string1, NULL);
		tolua_variable(L, "m_string2", tolua_get_CAIAction_m_string2, NULL);
		tolua_variable(L, "m_dest", tolua_get_CAIAction_m_dest, NULL);
		tolua_variable(L, "m_internalFlags", tolua_get_CAIAction_m_internalFlags, tolua_set_CAIAction_m_internalFlags);
		tolua_variable(L, "reference_m_internalFlags", tolua_get_CAIAction_reference_m_internalFlags, NULL);
		tolua_variable(L, "m_source", tolua_get_CAIAction_m_source, NULL);
		tolua_constant(L, "sizeof", sizeof(CAIAction));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameObject", "CGameObject", {"CObject"}, NULL);
	tolua_beginmodule(L, "CGameObject");
		tolua_variable(L, "m_objectType", tolua_get_CGameObject_m_objectType, tolua_set_CGameObject_m_objectType);
		tolua_variable(L, "reference_m_objectType", tolua_get_CGameObject_reference_m_objectType, NULL);
		tolua_variable(L, "m_pos", tolua_get_CGameObject_m_pos, NULL);
		tolua_variable(L, "m_posZ", tolua_get_CGameObject_m_posZ, tolua_set_CGameObject_m_posZ);
		tolua_variable(L, "reference_m_posZ", tolua_get_CGameObject_reference_m_posZ, NULL);
		tolua_variable(L, "m_pArea", tolua_get_CGameObject_m_pArea, tolua_set_CGameObject_m_pArea);
		tolua_variable(L, "reference_m_pArea", tolua_get_CGameObject_reference_m_pArea, NULL);
		tolua_variable(L, "m_posVertList", tolua_get_CGameObject_m_posVertList, tolua_set_CGameObject_m_posVertList);
		tolua_variable(L, "reference_m_posVertList", tolua_get_CGameObject_reference_m_posVertList, NULL);
		tolua_variable(L, "m_listType", tolua_get_CGameObject_m_listType, tolua_set_CGameObject_m_listType);
		tolua_variable(L, "reference_m_listType", tolua_get_CGameObject_reference_m_listType, NULL);
		tolua_variable(L, "m_typeAI", tolua_get_CGameObject_m_typeAI, NULL);
		tolua_variable(L, "m_id", tolua_get_CGameObject_m_id, tolua_set_CGameObject_m_id);
		tolua_variable(L, "reference_m_id", tolua_get_CGameObject_reference_m_id, NULL);
		tolua_variable(L, "m_canBeSeen", tolua_get_CGameObject_m_canBeSeen, tolua_set_CGameObject_m_canBeSeen);
		tolua_variable(L, "reference_m_canBeSeen", tolua_get_CGameObject_reference_m_canBeSeen, NULL);
		tolua_variable(L, "m_remotePlayerID", tolua_get_CGameObject_m_remotePlayerID, tolua_set_CGameObject_m_remotePlayerID);
		tolua_variable(L, "reference_m_remotePlayerID", tolua_get_CGameObject_reference_m_remotePlayerID, NULL);
		tolua_variable(L, "m_remoteObjectID", tolua_get_CGameObject_m_remoteObjectID, tolua_set_CGameObject_m_remoteObjectID);
		tolua_variable(L, "reference_m_remoteObjectID", tolua_get_CGameObject_reference_m_remoteObjectID, NULL);
		tolua_variable(L, "m_AISpeed", tolua_get_CGameObject_m_AISpeed, tolua_set_CGameObject_m_AISpeed);
		tolua_variable(L, "reference_m_AISpeed", tolua_get_CGameObject_reference_m_AISpeed, NULL);
		tolua_variable(L, "m_bLocalControl", tolua_get_CGameObject_m_bLocalControl, tolua_set_CGameObject_m_bLocalControl);
		tolua_variable(L, "reference_m_bLocalControl", tolua_get_CGameObject_reference_m_bLocalControl, NULL);
		tolua_variable(L, "m_AIInhibitor", tolua_get_CGameObject_m_AIInhibitor, tolua_set_CGameObject_m_AIInhibitor);
		tolua_variable(L, "reference_m_AIInhibitor", tolua_get_CGameObject_reference_m_AIInhibitor, NULL);
		tolua_function(L, "virtual_GetObjectType", &tolua_function_CGameObject_virtual_GetObjectType);
		tolua_function(L, "virtual_AddToArea", &tolua_function_CGameObject_virtual_AddToArea);
		tolua_function(L, "virtual_AIUpdate", &tolua_function_CGameObject_virtual_AIUpdate);
		tolua_function(L, "virtual_GetAIType", &tolua_function_CGameObject_virtual_GetAIType);
		tolua_function(L, "virtual_GetTargetId", &tolua_function_CGameObject_virtual_GetTargetId);
		tolua_function(L, "virtual_GetNextWaypoint", &tolua_function_CGameObject_virtual_GetNextWaypoint);
		tolua_function(L, "virtual_GetVertListPos", &tolua_function_CGameObject_virtual_GetVertListPos);
		tolua_function(L, "virtual_GetVertListType", &tolua_function_CGameObject_virtual_GetVertListType);
		tolua_function(L, "virtual_CanSaveGame", &tolua_function_CGameObject_virtual_CanSaveGame);
		tolua_function(L, "virtual_CompressTime", &tolua_function_CGameObject_virtual_CompressTime);
		tolua_function(L, "virtual_DebugDump", &tolua_function_CGameObject_virtual_DebugDump);
		tolua_function(L, "virtual_IsOver", &tolua_function_CGameObject_virtual_IsOver);
		tolua_function(L, "virtual_DoesIntersect", &tolua_function_CGameObject_virtual_DoesIntersect);
		tolua_function(L, "virtual_OnSearchMap", &tolua_function_CGameObject_virtual_OnSearchMap);
		tolua_function(L, "virtual_OnActionButton", &tolua_function_CGameObject_virtual_OnActionButton);
		tolua_function(L, "virtual_OnFormationButton", &tolua_function_CGameObject_virtual_OnFormationButton);
		tolua_function(L, "virtual_RemoveFromArea", &tolua_function_CGameObject_virtual_RemoveFromArea);
		tolua_function(L, "virtual_Render", &tolua_function_CGameObject_virtual_Render);
		tolua_function(L, "virtual_DoAIUpdate", &tolua_function_CGameObject_virtual_DoAIUpdate);
		tolua_function(L, "virtual_SetAIType", &tolua_function_CGameObject_virtual_SetAIType);
		tolua_function(L, "virtual_SetCursor", &tolua_function_CGameObject_virtual_SetCursor);
		tolua_function(L, "virtual_SetTarget", &tolua_function_CGameObject_virtual_SetTarget);
		tolua_function(L, "virtual_SetVertListPos", &tolua_function_CGameObject_virtual_SetVertListPos);
		tolua_function(L, "virtual_EvaluateStatusTrigger", &tolua_function_CGameObject_virtual_EvaluateStatusTrigger);
		tolua_constant(L, "sizeof", sizeof(CGameObject));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameObject::vtbl", "CGameObject::vtbl", {"CObject::vtbl"}, NULL);
	tolua_beginmodule(L, "CGameObject::vtbl");
		tolua_variable(L, "GetObjectType", tolua_get_CGameObject__vtbl_GetObjectType, tolua_set_CGameObject__vtbl_GetObjectType);
		tolua_variable(L, "reference_GetObjectType", tolua_get_CGameObject__vtbl_reference_GetObjectType, NULL);
		tolua_variable(L, "AddToArea", tolua_get_CGameObject__vtbl_AddToArea, tolua_set_CGameObject__vtbl_AddToArea);
		tolua_variable(L, "reference_AddToArea", tolua_get_CGameObject__vtbl_reference_AddToArea, NULL);
		tolua_variable(L, "AIUpdate", tolua_get_CGameObject__vtbl_AIUpdate, tolua_set_CGameObject__vtbl_AIUpdate);
		tolua_variable(L, "reference_AIUpdate", tolua_get_CGameObject__vtbl_reference_AIUpdate, NULL);
		tolua_variable(L, "GetAIType", tolua_get_CGameObject__vtbl_GetAIType, tolua_set_CGameObject__vtbl_GetAIType);
		tolua_variable(L, "reference_GetAIType", tolua_get_CGameObject__vtbl_reference_GetAIType, NULL);
		tolua_variable(L, "GetTargetId", tolua_get_CGameObject__vtbl_GetTargetId, tolua_set_CGameObject__vtbl_GetTargetId);
		tolua_variable(L, "reference_GetTargetId", tolua_get_CGameObject__vtbl_reference_GetTargetId, NULL);
		tolua_variable(L, "GetNextWaypoint", tolua_get_CGameObject__vtbl_GetNextWaypoint, tolua_set_CGameObject__vtbl_GetNextWaypoint);
		tolua_variable(L, "reference_GetNextWaypoint", tolua_get_CGameObject__vtbl_reference_GetNextWaypoint, NULL);
		tolua_variable(L, "GetVertListPos", tolua_get_CGameObject__vtbl_GetVertListPos, tolua_set_CGameObject__vtbl_GetVertListPos);
		tolua_variable(L, "reference_GetVertListPos", tolua_get_CGameObject__vtbl_reference_GetVertListPos, NULL);
		tolua_variable(L, "GetVertListType", tolua_get_CGameObject__vtbl_GetVertListType, tolua_set_CGameObject__vtbl_GetVertListType);
		tolua_variable(L, "reference_GetVertListType", tolua_get_CGameObject__vtbl_reference_GetVertListType, NULL);
		tolua_variable(L, "CanSaveGame", tolua_get_CGameObject__vtbl_CanSaveGame, tolua_set_CGameObject__vtbl_CanSaveGame);
		tolua_variable(L, "reference_CanSaveGame", tolua_get_CGameObject__vtbl_reference_CanSaveGame, NULL);
		tolua_variable(L, "CompressTime", tolua_get_CGameObject__vtbl_CompressTime, tolua_set_CGameObject__vtbl_CompressTime);
		tolua_variable(L, "reference_CompressTime", tolua_get_CGameObject__vtbl_reference_CompressTime, NULL);
		tolua_variable(L, "DebugDump", tolua_get_CGameObject__vtbl_DebugDump, tolua_set_CGameObject__vtbl_DebugDump);
		tolua_variable(L, "reference_DebugDump", tolua_get_CGameObject__vtbl_reference_DebugDump, NULL);
		tolua_variable(L, "IsOver", tolua_get_CGameObject__vtbl_IsOver, tolua_set_CGameObject__vtbl_IsOver);
		tolua_variable(L, "reference_IsOver", tolua_get_CGameObject__vtbl_reference_IsOver, NULL);
		tolua_variable(L, "DoesIntersect", tolua_get_CGameObject__vtbl_DoesIntersect, tolua_set_CGameObject__vtbl_DoesIntersect);
		tolua_variable(L, "reference_DoesIntersect", tolua_get_CGameObject__vtbl_reference_DoesIntersect, NULL);
		tolua_variable(L, "OnSearchMap", tolua_get_CGameObject__vtbl_OnSearchMap, tolua_set_CGameObject__vtbl_OnSearchMap);
		tolua_variable(L, "reference_OnSearchMap", tolua_get_CGameObject__vtbl_reference_OnSearchMap, NULL);
		tolua_variable(L, "OnActionButton", tolua_get_CGameObject__vtbl_OnActionButton, tolua_set_CGameObject__vtbl_OnActionButton);
		tolua_variable(L, "reference_OnActionButton", tolua_get_CGameObject__vtbl_reference_OnActionButton, NULL);
		tolua_variable(L, "OnFormationButton", tolua_get_CGameObject__vtbl_OnFormationButton, tolua_set_CGameObject__vtbl_OnFormationButton);
		tolua_variable(L, "reference_OnFormationButton", tolua_get_CGameObject__vtbl_reference_OnFormationButton, NULL);
		tolua_variable(L, "RemoveFromArea", tolua_get_CGameObject__vtbl_RemoveFromArea, tolua_set_CGameObject__vtbl_RemoveFromArea);
		tolua_variable(L, "reference_RemoveFromArea", tolua_get_CGameObject__vtbl_reference_RemoveFromArea, NULL);
		tolua_variable(L, "Render", tolua_get_CGameObject__vtbl_Render, tolua_set_CGameObject__vtbl_Render);
		tolua_variable(L, "reference_Render", tolua_get_CGameObject__vtbl_reference_Render, NULL);
		tolua_variable(L, "DoAIUpdate", tolua_get_CGameObject__vtbl_DoAIUpdate, tolua_set_CGameObject__vtbl_DoAIUpdate);
		tolua_variable(L, "reference_DoAIUpdate", tolua_get_CGameObject__vtbl_reference_DoAIUpdate, NULL);
		tolua_variable(L, "SetAIType", tolua_get_CGameObject__vtbl_SetAIType, tolua_set_CGameObject__vtbl_SetAIType);
		tolua_variable(L, "reference_SetAIType", tolua_get_CGameObject__vtbl_reference_SetAIType, NULL);
		tolua_variable(L, "SetCursor", tolua_get_CGameObject__vtbl_SetCursor, tolua_set_CGameObject__vtbl_SetCursor);
		tolua_variable(L, "reference_SetCursor", tolua_get_CGameObject__vtbl_reference_SetCursor, NULL);
		tolua_variable(L, "SetTarget", tolua_get_CGameObject__vtbl_SetTarget, tolua_set_CGameObject__vtbl_SetTarget);
		tolua_variable(L, "reference_SetTarget", tolua_get_CGameObject__vtbl_reference_SetTarget, NULL);
		tolua_variable(L, "SetVertListPos", tolua_get_CGameObject__vtbl_SetVertListPos, tolua_set_CGameObject__vtbl_SetVertListPos);
		tolua_variable(L, "reference_SetVertListPos", tolua_get_CGameObject__vtbl_reference_SetVertListPos, NULL);
		tolua_variable(L, "EvaluateStatusTrigger", tolua_get_CGameObject__vtbl_EvaluateStatusTrigger, tolua_set_CGameObject__vtbl_EvaluateStatusTrigger);
		tolua_variable(L, "reference_EvaluateStatusTrigger", tolua_get_CGameObject__vtbl_reference_EvaluateStatusTrigger, NULL);
		tolua_constant(L, "sizeof", sizeof(CGameObject::vtbl));
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectile", "CProjectile", {"CGameObject"}, NULL);
	tolua_beginmodule(L, "CProjectile");
		tolua_variable(L, "m_projectileType", tolua_get_CProjectile_m_projectileType, tolua_set_CProjectile_m_projectileType);
		tolua_variable(L, "reference_m_projectileType", tolua_get_CProjectile_reference_m_projectileType, NULL);
		tolua_variable(L, "m_speed", tolua_get_CProjectile_m_speed, tolua_set_CProjectile_m_speed);
		tolua_variable(L, "reference_m_speed", tolua_get_CProjectile_reference_m_speed, NULL);
		tolua_variable(L, "m_sourceId", tolua_get_CProjectile_m_sourceId, tolua_set_CProjectile_m_sourceId);
		tolua_variable(L, "reference_m_sourceId", tolua_get_CProjectile_reference_m_sourceId, NULL);
		tolua_variable(L, "m_targetId", tolua_get_CProjectile_m_targetId, tolua_set_CProjectile_m_targetId);
		tolua_variable(L, "reference_m_targetId", tolua_get_CProjectile_reference_m_targetId, NULL);
		tolua_variable(L, "m_callBackProjectile", tolua_get_CProjectile_m_callBackProjectile, tolua_set_CProjectile_m_callBackProjectile);
		tolua_variable(L, "reference_m_callBackProjectile", tolua_get_CProjectile_reference_m_callBackProjectile, NULL);
		tolua_variable(L, "m_effectList", tolua_get_CProjectile_m_effectList, NULL);
		tolua_variable(L, "m_nType", tolua_get_CProjectile_m_nType, tolua_set_CProjectile_m_nType);
		tolua_variable(L, "reference_m_nType", tolua_get_CProjectile_reference_m_nType, NULL);
		tolua_variable(L, "m_posExact", tolua_get_CProjectile_m_posExact, NULL);
		tolua_variable(L, "m_posDest", tolua_get_CProjectile_m_posDest, NULL);
		tolua_variable(L, "m_decAmmount", tolua_get_CProjectile_m_decAmmount, tolua_set_CProjectile_m_decAmmount);
		tolua_variable(L, "reference_m_decAmmount", tolua_get_CProjectile_reference_m_decAmmount, NULL);
		tolua_variable(L, "m_bSparkleTrail", tolua_get_CProjectile_m_bSparkleTrail, tolua_set_CProjectile_m_bSparkleTrail);
		tolua_variable(L, "reference_m_bSparkleTrail", tolua_get_CProjectile_reference_m_bSparkleTrail, NULL);
		tolua_variable(L, "m_defaultRenderFlags", tolua_get_CProjectile_m_defaultRenderFlags, tolua_set_CProjectile_m_defaultRenderFlags);
		tolua_variable(L, "reference_m_defaultRenderFlags", tolua_get_CProjectile_reference_m_defaultRenderFlags, NULL);
		tolua_variable(L, "m_bIgnoreTarget", tolua_get_CProjectile_m_bIgnoreTarget, tolua_set_CProjectile_m_bIgnoreTarget);
		tolua_variable(L, "reference_m_bIgnoreTarget", tolua_get_CProjectile_reference_m_bIgnoreTarget, NULL);
		tolua_variable(L, "m_fireSoundRef", tolua_get_CProjectile_m_fireSoundRef, NULL);
		tolua_variable(L, "m_loopFireSound", tolua_get_CProjectile_m_loopFireSound, tolua_set_CProjectile_m_loopFireSound);
		tolua_variable(L, "reference_m_loopFireSound", tolua_get_CProjectile_reference_m_loopFireSound, NULL);
		tolua_variable(L, "m_arrivalSoundRef", tolua_get_CProjectile_m_arrivalSoundRef, NULL);
		tolua_variable(L, "m_loopArrivalSound", tolua_get_CProjectile_m_loopArrivalSound, tolua_set_CProjectile_m_loopArrivalSound);
		tolua_variable(L, "reference_m_loopArrivalSound", tolua_get_CProjectile_reference_m_loopArrivalSound, NULL);
		tolua_variable(L, "m_visualEffectRef", tolua_get_CProjectile_m_visualEffectRef, NULL);
		tolua_variable(L, "m_visualEffect", tolua_get_CProjectile_m_visualEffect, tolua_set_CProjectile_m_visualEffect);
		tolua_variable(L, "reference_m_visualEffect", tolua_get_CProjectile_reference_m_visualEffect, NULL);
		tolua_variable(L, "m_maxDuration", tolua_get_CProjectile_m_maxDuration, tolua_set_CProjectile_m_maxDuration);
		tolua_variable(L, "reference_m_maxDuration", tolua_get_CProjectile_reference_m_maxDuration, NULL);
		tolua_variable(L, "m_strRef", tolua_get_CProjectile_m_strRef, tolua_set_CProjectile_m_strRef);
		tolua_variable(L, "reference_m_strRef", tolua_get_CProjectile_reference_m_strRef, NULL);
		tolua_variable(L, "m_failureSpell", tolua_get_CProjectile_m_failureSpell, NULL);
		tolua_variable(L, "m_successSpell", tolua_get_CProjectile_m_successSpell, NULL);
		tolua_variable(L, "unknown", tolua_get_CProjectile_unknown, tolua_set_CProjectile_unknown);
		tolua_variable(L, "reference_unknown", tolua_get_CProjectile_reference_unknown, NULL);
		tolua_variable(L, "unknown2", tolua_get_CProjectile_unknown2, tolua_set_CProjectile_unknown2);
		tolua_variable(L, "reference_unknown2", tolua_get_CProjectile_reference_unknown2, NULL);
		tolua_variable(L, "reference_DecodeProjectile", tolua_get_reference_CProjectile_DecodeProjectile, NULL);
		tolua_function(L, "DecodeProjectile", &tolua_function_CProjectile_DecodeProjectile);
		tolua_constant(L, "sizeof", sizeof(CProjectile));
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectile::vtbl", "CProjectile::vtbl", {"CGameObject::vtbl"}, NULL);
	tolua_beginmodule(L, "CProjectile::vtbl");
		tolua_constant(L, "sizeof", sizeof(CProjectile::vtbl));
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileBAM", "CProjectileBAM", {"CProjectile"}, NULL);
	tolua_beginmodule(L, "CProjectileBAM");
		tolua_variable(L, "m_currentVidCell", tolua_get_CProjectileBAM_m_currentVidCell, tolua_set_CProjectileBAM_m_currentVidCell);
		tolua_variable(L, "reference_m_currentVidCell", tolua_get_CProjectileBAM_reference_m_currentVidCell, NULL);
		tolua_variable(L, "m_shadowVidCell", tolua_get_CProjectileBAM_m_shadowVidCell, tolua_set_CProjectileBAM_m_shadowVidCell);
		tolua_variable(L, "reference_m_shadowVidCell", tolua_get_CProjectileBAM_reference_m_shadowVidCell, NULL);
		tolua_variable(L, "bUseAreaTint", tolua_get_CProjectileBAM_bUseAreaTint, tolua_set_CProjectileBAM_bUseAreaTint);
		tolua_variable(L, "reference_bUseAreaTint", tolua_get_CProjectileBAM_reference_bUseAreaTint, NULL);
		tolua_variable(L, "m_numDirections", tolua_get_CProjectileBAM_m_numDirections, tolua_set_CProjectileBAM_m_numDirections);
		tolua_variable(L, "reference_m_numDirections", tolua_get_CProjectileBAM_reference_m_numDirections, NULL);
		tolua_variable(L, "m_direction", tolua_get_CProjectileBAM_m_direction, tolua_set_CProjectileBAM_m_direction);
		tolua_variable(L, "reference_m_direction", tolua_get_CProjectileBAM_reference_m_direction, NULL);
		tolua_variable(L, "unknown3", tolua_get_CProjectileBAM_unknown3, tolua_set_CProjectileBAM_unknown3);
		tolua_variable(L, "reference_unknown3", tolua_get_CProjectileBAM_reference_unknown3, NULL);
		tolua_variable(L, "m_render", tolua_get_CProjectileBAM_m_render, tolua_set_CProjectileBAM_m_render);
		tolua_variable(L, "reference_m_render", tolua_get_CProjectileBAM_reference_m_render, NULL);
		tolua_variable(L, "unknown4", tolua_get_CProjectileBAM_unknown4, tolua_set_CProjectileBAM_unknown4);
		tolua_variable(L, "reference_unknown4", tolua_get_CProjectileBAM_reference_unknown4, NULL);
		tolua_variable(L, "m_cPuffEffect1", tolua_get_CProjectileBAM_m_cPuffEffect1, NULL);
		tolua_variable(L, "m_cPuffEffect2", tolua_get_CProjectileBAM_m_cPuffEffect2, NULL);
		tolua_variable(L, "m_cPuffEffect3", tolua_get_CProjectileBAM_m_cPuffEffect3, NULL);
		tolua_variable(L, "m_nPuff1Spacing", tolua_get_CProjectileBAM_m_nPuff1Spacing, tolua_set_CProjectileBAM_m_nPuff1Spacing);
		tolua_variable(L, "reference_m_nPuff1Spacing", tolua_get_CProjectileBAM_reference_m_nPuff1Spacing, NULL);
		tolua_variable(L, "m_nPuff2Spacing", tolua_get_CProjectileBAM_m_nPuff2Spacing, tolua_set_CProjectileBAM_m_nPuff2Spacing);
		tolua_variable(L, "reference_m_nPuff2Spacing", tolua_get_CProjectileBAM_reference_m_nPuff2Spacing, NULL);
		tolua_variable(L, "m_nPuff3Spacing", tolua_get_CProjectileBAM_m_nPuff3Spacing, tolua_set_CProjectileBAM_m_nPuff3Spacing);
		tolua_variable(L, "reference_m_nPuff3Spacing", tolua_get_CProjectileBAM_reference_m_nPuff3Spacing, NULL);
		tolua_variable(L, "m_dwPuffFlags", tolua_get_CProjectileBAM_m_dwPuffFlags, tolua_set_CProjectileBAM_m_dwPuffFlags);
		tolua_variable(L, "reference_m_dwPuffFlags", tolua_get_CProjectileBAM_reference_m_dwPuffFlags, NULL);
		tolua_variable(L, "m_puffCounter", tolua_get_CProjectileBAM_m_puffCounter, tolua_set_CProjectileBAM_m_puffCounter);
		tolua_variable(L, "reference_m_puffCounter", tolua_get_CProjectileBAM_reference_m_puffCounter, NULL);
		tolua_variable(L, "m_unknownPSTFlags", tolua_get_CProjectileBAM_m_unknownPSTFlags, tolua_set_CProjectileBAM_m_unknownPSTFlags);
		tolua_variable(L, "reference_m_unknownPSTFlags", tolua_get_CProjectileBAM_reference_m_unknownPSTFlags, NULL);
		tolua_variable(L, "nDelayedRemoveCounter", tolua_get_CProjectileBAM_nDelayedRemoveCounter, tolua_set_CProjectileBAM_nDelayedRemoveCounter);
		tolua_variable(L, "reference_nDelayedRemoveCounter", tolua_get_CProjectileBAM_reference_nDelayedRemoveCounter, NULL);
		tolua_constant(L, "sizeof", sizeof(CProjectileBAM));
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileBAM::vtbl", "CProjectileBAM::vtbl", {"CProjectile::vtbl"}, NULL);
	tolua_beginmodule(L, "CProjectileBAM::vtbl");
		tolua_constant(L, "sizeof", sizeof(CProjectileBAM::vtbl));
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileArea", "CProjectileArea", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileArea");
		tolua_variable(L, "m_coneSize", tolua_get_CProjectileArea_m_coneSize, tolua_set_CProjectileArea_m_coneSize);
		tolua_variable(L, "reference_m_coneSize", tolua_get_CProjectileArea_reference_m_coneSize, NULL);
		tolua_constant(L, "sizeof", sizeof(CProjectileArea));
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileUnknownPST", "CProjectileUnknownPST", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileUnknownPST");
		tolua_variable(L, "pInfinity", tolua_get_CProjectileUnknownPST_pInfinity, tolua_set_CProjectileUnknownPST_pInfinity);
		tolua_variable(L, "reference_pInfinity", tolua_get_CProjectileUnknownPST_reference_pInfinity, NULL);
		tolua_variable(L, "nUnknownMode", tolua_get_CProjectileUnknownPST_nUnknownMode, tolua_set_CProjectileUnknownPST_nUnknownMode);
		tolua_variable(L, "reference_nUnknownMode", tolua_get_CProjectileUnknownPST_reference_nUnknownMode, NULL);
		tolua_variable(L, "m_nUnknown1", tolua_get_CProjectileUnknownPST_m_nUnknown1, tolua_set_CProjectileUnknownPST_m_nUnknown1);
		tolua_variable(L, "reference_m_nUnknown1", tolua_get_CProjectileUnknownPST_reference_m_nUnknown1, NULL);
		tolua_variable(L, "nExpirationTime", tolua_get_CProjectileUnknownPST_nExpirationTime, tolua_set_CProjectileUnknownPST_nExpirationTime);
		tolua_variable(L, "reference_nExpirationTime", tolua_get_CProjectileUnknownPST_reference_nExpirationTime, NULL);
		tolua_variable(L, "m_nUnknown2", tolua_get_CProjectileUnknownPST_m_nUnknown2, tolua_set_CProjectileUnknownPST_m_nUnknown2);
		tolua_variable(L, "reference_m_nUnknown2", tolua_get_CProjectileUnknownPST_reference_m_nUnknown2, NULL);
		tolua_variable(L, "bSuppressFireSound", tolua_get_CProjectileUnknownPST_bSuppressFireSound, tolua_set_CProjectileUnknownPST_bSuppressFireSound);
		tolua_variable(L, "reference_bSuppressFireSound", tolua_get_CProjectileUnknownPST_reference_bSuppressFireSound, NULL);
		tolua_variable(L, "nDelayedRemoveSpeed", tolua_get_CProjectileUnknownPST_nDelayedRemoveSpeed, tolua_set_CProjectileUnknownPST_nDelayedRemoveSpeed);
		tolua_variable(L, "reference_nDelayedRemoveSpeed", tolua_get_CProjectileUnknownPST_reference_nDelayedRemoveSpeed, NULL);
		tolua_variable(L, "bDelayedRemoveScheduled", tolua_get_CProjectileUnknownPST_bDelayedRemoveScheduled, tolua_set_CProjectileUnknownPST_bDelayedRemoveScheduled);
		tolua_variable(L, "reference_bDelayedRemoveScheduled", tolua_get_CProjectileUnknownPST_reference_bDelayedRemoveScheduled, NULL);
		tolua_constant(L, "sizeof", sizeof(CProjectileUnknownPST));
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileUnknownPST::vtbl", "CProjectileUnknownPST::vtbl", {"CProjectileBAM::vtbl"}, NULL);
	tolua_beginmodule(L, "CProjectileUnknownPST::vtbl");
		tolua_constant(L, "sizeof", sizeof(CProjectileUnknownPST::vtbl));
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileUnknownPST2", "CProjectileUnknownPST2", {"CProjectileUnknownPST"}, NULL);
	tolua_beginmodule(L, "CProjectileUnknownPST2");
		tolua_variable(L, "bRemoveOnNextUpdate", tolua_get_CProjectileUnknownPST2_bRemoveOnNextUpdate, tolua_set_CProjectileUnknownPST2_bRemoveOnNextUpdate);
		tolua_variable(L, "reference_bRemoveOnNextUpdate", tolua_get_CProjectileUnknownPST2_reference_bRemoveOnNextUpdate, NULL);
		tolua_variable(L, "nTypePST", tolua_get_CProjectileUnknownPST2_nTypePST, tolua_set_CProjectileUnknownPST2_nTypePST);
		tolua_variable(L, "reference_nTypePST", tolua_get_CProjectileUnknownPST2_reference_nTypePST, NULL);
		tolua_constant(L, "sizeof", sizeof(CProjectileUnknownPST2));
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectile205", "CProjectile205", {"CProjectileUnknownBase"}, NULL);
	tolua_beginmodule(L, "CProjectile205");
		tolua_variable(L, "bHitTarget", tolua_get_CProjectile205_bHitTarget, tolua_set_CProjectile205_bHitTarget);
		tolua_variable(L, "reference_bHitTarget", tolua_get_CProjectile205_reference_bHitTarget, NULL);
		tolua_constant(L, "sizeof", sizeof(CProjectile205));
	tolua_endmodule(L);
	tolua_cclass(L, "CAITrigger", "CAITrigger", {}, NULL);
	tolua_beginmodule(L, "CAITrigger");
		tolua_variable(L, "m_triggerID", tolua_get_CAITrigger_m_triggerID, tolua_set_CAITrigger_m_triggerID);
		tolua_variable(L, "reference_m_triggerID", tolua_get_CAITrigger_reference_m_triggerID, NULL);
		tolua_variable(L, "m_specificID", tolua_get_CAITrigger_m_specificID, tolua_set_CAITrigger_m_specificID);
		tolua_variable(L, "reference_m_specificID", tolua_get_CAITrigger_reference_m_specificID, NULL);
		tolua_variable(L, "m_triggerCause", tolua_get_CAITrigger_m_triggerCause, NULL);
		tolua_variable(L, "m_flags", tolua_get_CAITrigger_m_flags, tolua_set_CAITrigger_m_flags);
		tolua_variable(L, "reference_m_flags", tolua_get_CAITrigger_reference_m_flags, NULL);
		tolua_variable(L, "m_specific2", tolua_get_CAITrigger_m_specific2, tolua_set_CAITrigger_m_specific2);
		tolua_variable(L, "reference_m_specific2", tolua_get_CAITrigger_reference_m_specific2, NULL);
		tolua_variable(L, "m_specific3", tolua_get_CAITrigger_m_specific3, tolua_set_CAITrigger_m_specific3);
		tolua_variable(L, "reference_m_specific3", tolua_get_CAITrigger_reference_m_specific3, NULL);
		tolua_variable(L, "m_string1", tolua_get_CAITrigger_m_string1, NULL);
		tolua_variable(L, "m_string2", tolua_get_CAITrigger_m_string2, NULL);
		tolua_constant(L, "sizeof", sizeof(CAITrigger));
	tolua_endmodule(L);
	tolua_cclass(L, "CMessageSetTrigger", "CMessageSetTrigger", {"CMessage"}, NULL);
	tolua_beginmodule(L, "CMessageSetTrigger");
		tolua_variable(L, "m_trigger", tolua_get_CMessageSetTrigger_m_trigger, NULL);
		tolua_constant(L, "sizeof", sizeof(CMessageSetTrigger));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameAIBase", "CGameAIBase", {"CGameObject"}, NULL);
	tolua_beginmodule(L, "CGameAIBase");
		tolua_variable(L, "m_lAttacker", tolua_get_CGameAIBase_m_lAttacker, NULL);
		tolua_variable(L, "m_lAttackStyle", tolua_get_CGameAIBase_m_lAttackStyle, tolua_set_CGameAIBase_m_lAttackStyle);
		tolua_variable(L, "reference_m_lAttackStyle", tolua_get_CGameAIBase_reference_m_lAttackStyle, NULL);
		tolua_variable(L, "m_lOrderedBy", tolua_get_CGameAIBase_m_lOrderedBy, NULL);
		tolua_variable(L, "m_protecting", tolua_get_CGameAIBase_m_protecting, NULL);
		tolua_variable(L, "m_protector", tolua_get_CGameAIBase_m_protector, NULL);
		tolua_variable(L, "m_lTargeted", tolua_get_CGameAIBase_m_lTargeted, NULL);
		tolua_variable(L, "m_activeAnimations", tolua_get_CGameAIBase_m_activeAnimations, NULL);
		tolua_variable(L, "m_pendingTriggers", tolua_get_CGameAIBase_m_pendingTriggers, NULL);
		tolua_variable(L, "m_interrupt", tolua_get_CGameAIBase_m_interrupt, tolua_set_CGameAIBase_m_interrupt);
		tolua_variable(L, "reference_m_interrupt", tolua_get_CGameAIBase_reference_m_interrupt, NULL);
		tolua_variable(L, "m_actionCount", tolua_get_CGameAIBase_m_actionCount, tolua_set_CGameAIBase_m_actionCount);
		tolua_variable(L, "reference_m_actionCount", tolua_get_CGameAIBase_reference_m_actionCount, NULL);
		tolua_variable(L, "m_curAction", tolua_get_CGameAIBase_m_curAction, NULL);
		tolua_variable(L, "m_scriptName", tolua_get_CGameAIBase_m_scriptName, NULL);
		tolua_variable(L, "triggerOverride", tolua_get_CGameAIBase_triggerOverride, NULL);
		tolua_function(L, "virtual_ClearActions", &tolua_function_CGameAIBase_virtual_ClearActions);
		tolua_function(L, "virtual_FloatMessage", &tolua_function_CGameAIBase_virtual_FloatMessage);
		tolua_function(L, "virtual_KillFloatMessage", &tolua_function_CGameAIBase_virtual_KillFloatMessage);
		tolua_function(L, "virtual_UpdateTarget", &tolua_function_CGameAIBase_virtual_UpdateTarget);
		tolua_function(L, "virtual_AddAction", &tolua_function_CGameAIBase_virtual_AddAction);
		tolua_function(L, "virtual_AddEffect", &tolua_function_CGameAIBase_virtual_AddEffect);
		tolua_constant(L, "sizeof", sizeof(CGameAIBase));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameAIBase::vtbl", "CGameAIBase::vtbl", {"CGameObject::vtbl"}, NULL);
	tolua_beginmodule(L, "CGameAIBase::vtbl");
		tolua_variable(L, "ClearActions", tolua_get_CGameAIBase__vtbl_ClearActions, tolua_set_CGameAIBase__vtbl_ClearActions);
		tolua_variable(L, "reference_ClearActions", tolua_get_CGameAIBase__vtbl_reference_ClearActions, NULL);
		tolua_variable(L, "FloatMessage", tolua_get_CGameAIBase__vtbl_FloatMessage, tolua_set_CGameAIBase__vtbl_FloatMessage);
		tolua_variable(L, "reference_FloatMessage", tolua_get_CGameAIBase__vtbl_reference_FloatMessage, NULL);
		tolua_variable(L, "KillFloatMessage", tolua_get_CGameAIBase__vtbl_KillFloatMessage, tolua_set_CGameAIBase__vtbl_KillFloatMessage);
		tolua_variable(L, "reference_KillFloatMessage", tolua_get_CGameAIBase__vtbl_reference_KillFloatMessage, NULL);
		tolua_variable(L, "UpdateTarget", tolua_get_CGameAIBase__vtbl_UpdateTarget, tolua_set_CGameAIBase__vtbl_UpdateTarget);
		tolua_variable(L, "reference_UpdateTarget", tolua_get_CGameAIBase__vtbl_reference_UpdateTarget, NULL);
		tolua_variable(L, "AddAction", tolua_get_CGameAIBase__vtbl_AddAction, tolua_set_CGameAIBase__vtbl_AddAction);
		tolua_variable(L, "reference_AddAction", tolua_get_CGameAIBase__vtbl_reference_AddAction, NULL);
		tolua_variable(L, "AddEffect", tolua_get_CGameAIBase__vtbl_AddEffect, tolua_set_CGameAIBase__vtbl_AddEffect);
		tolua_variable(L, "reference_AddEffect", tolua_get_CGameAIBase__vtbl_reference_AddEffect, NULL);
		tolua_constant(L, "sizeof", sizeof(CGameAIBase::vtbl));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameSprite", "CGameSprite", {"CGameAIBase"}, NULL);
	tolua_beginmodule(L, "CGameSprite");
		tolua_variable(L, "m_baseStats_m_generalState", tolua_get_CGameSprite_m_baseStats_m_generalState, NULL);
		tolua_variable(L, "m_derivedStats", tolua_get_CGameSprite_m_derivedStats, NULL);
		tolua_variable(L, "m_tempStats", tolua_get_CGameSprite_m_tempStats, NULL);
		tolua_variable(L, "m_bonusStats", tolua_get_CGameSprite_m_bonusStats, NULL);
		tolua_variable(L, "m_animation", tolua_get_CGameSprite_m_animation, NULL);
		tolua_variable(L, "bAllowGlobalOrAreaTintsWhenRendering", tolua_get_CGameSprite_bAllowGlobalOrAreaTintsWhenRendering, tolua_set_CGameSprite_bAllowGlobalOrAreaTintsWhenRendering);
		tolua_variable(L, "reference_bAllowGlobalOrAreaTintsWhenRendering", tolua_get_CGameSprite_reference_bAllowGlobalOrAreaTintsWhenRendering, NULL);
		tolua_variable(L, "m_nMirrorImages", tolua_get_CGameSprite_m_nMirrorImages, tolua_set_CGameSprite_m_nMirrorImages);
		tolua_variable(L, "reference_m_nMirrorImages", tolua_get_CGameSprite_reference_m_nMirrorImages, NULL);
		tolua_variable(L, "nPainMirrorCounter", tolua_get_CGameSprite_nPainMirrorCounter, tolua_set_CGameSprite_nPainMirrorCounter);
		tolua_variable(L, "reference_nPainMirrorCounter", tolua_get_CGameSprite_reference_nPainMirrorCounter, NULL);
		tolua_variable(L, "bGuardianMantle", tolua_get_CGameSprite_bGuardianMantle, tolua_set_CGameSprite_bGuardianMantle);
		tolua_variable(L, "reference_bGuardianMantle", tolua_get_CGameSprite_reference_bGuardianMantle, NULL);
		tolua_variable(L, "nCloakOfWardingDamageAbsorption", tolua_get_CGameSprite_nCloakOfWardingDamageAbsorption, tolua_set_CGameSprite_nCloakOfWardingDamageAbsorption);
		tolua_variable(L, "reference_nCloakOfWardingDamageAbsorption", tolua_get_CGameSprite_reference_nCloakOfWardingDamageAbsorption, NULL);
		tolua_variable(L, "nArmorDamageCounter", tolua_get_CGameSprite_nArmorDamageCounter, tolua_set_CGameSprite_nArmorDamageCounter);
		tolua_variable(L, "reference_nArmorDamageCounter", tolua_get_CGameSprite_reference_nArmorDamageCounter, NULL);
		tolua_variable(L, "m_bBlur", tolua_get_CGameSprite_m_bBlur, tolua_set_CGameSprite_m_bBlur);
		tolua_variable(L, "reference_m_bBlur", tolua_get_CGameSprite_reference_m_bBlur, NULL);
		tolua_variable(L, "m_bMinorGlobe", tolua_get_CGameSprite_m_bMinorGlobe, tolua_set_CGameSprite_m_bMinorGlobe);
		tolua_variable(L, "reference_m_bMinorGlobe", tolua_get_CGameSprite_reference_m_bMinorGlobe, NULL);
		tolua_variable(L, "m_bShieldGlobe", tolua_get_CGameSprite_m_bShieldGlobe, tolua_set_CGameSprite_m_bShieldGlobe);
		tolua_variable(L, "reference_m_bShieldGlobe", tolua_get_CGameSprite_reference_m_bShieldGlobe, NULL);
		tolua_variable(L, "m_shieldGlobeVidCell", tolua_get_CGameSprite_m_shieldGlobeVidCell, NULL);
		tolua_variable(L, "m_posOld", tolua_get_CGameSprite_m_posOld, NULL);
		tolua_variable(L, "m_posOldWalk", tolua_get_CGameSprite_m_posOldWalk, NULL);
		tolua_variable(L, "m_bStartedCasting", tolua_get_CGameSprite_m_bStartedCasting, tolua_set_CGameSprite_m_bStartedCasting);
		tolua_variable(L, "reference_m_bStartedCasting", tolua_get_CGameSprite_reference_m_bStartedCasting, NULL);
		tolua_variable(L, "m_bInCasting", tolua_get_CGameSprite_m_bInCasting, tolua_set_CGameSprite_m_bInCasting);
		tolua_variable(L, "reference_m_bInCasting", tolua_get_CGameSprite_reference_m_bInCasting, NULL);
		tolua_variable(L, "m_moveCount", tolua_get_CGameSprite_m_moveCount, tolua_set_CGameSprite_m_moveCount);
		tolua_variable(L, "reference_m_moveCount", tolua_get_CGameSprite_reference_m_moveCount, NULL);
		tolua_variable(L, "m_equipedEffectList", tolua_get_CGameSprite_m_equipedEffectList, NULL);
		tolua_variable(L, "m_timedEffectList", tolua_get_CGameSprite_m_timedEffectList, NULL);
		tolua_variable(L, "m_persistantEffects", tolua_get_CGameSprite_m_persistantEffects, NULL);
		tolua_variable(L, "m_bWaitingForAreaLoadInLeaveAreaLUA", tolua_get_CGameSprite_m_bWaitingForAreaLoadInLeaveAreaLUA, tolua_set_CGameSprite_m_bWaitingForAreaLoadInLeaveAreaLUA);
		tolua_variable(L, "reference_m_bWaitingForAreaLoadInLeaveAreaLUA", tolua_get_CGameSprite_reference_m_bWaitingForAreaLoadInLeaveAreaLUA, NULL);
		tolua_variable(L, "m_lastActionID", tolua_get_CGameSprite_m_lastActionID, tolua_set_CGameSprite_m_lastActionID);
		tolua_variable(L, "reference_m_lastActionID", tolua_get_CGameSprite_reference_m_lastActionID, NULL);
		tolua_variable(L, "m_searchPauseCount", tolua_get_CGameSprite_m_searchPauseCount, tolua_set_CGameSprite_m_searchPauseCount);
		tolua_variable(L, "reference_m_searchPauseCount", tolua_get_CGameSprite_reference_m_searchPauseCount, NULL);
		tolua_variable(L, "m_attackFrame", tolua_get_CGameSprite_m_attackFrame, tolua_set_CGameSprite_m_attackFrame);
		tolua_variable(L, "reference_m_attackFrame", tolua_get_CGameSprite_reference_m_attackFrame, NULL);
		tolua_variable(L, "m_newEffect", tolua_get_CGameSprite_m_newEffect, tolua_set_CGameSprite_m_newEffect);
		tolua_variable(L, "reference_m_newEffect", tolua_get_CGameSprite_reference_m_newEffect, NULL);
		tolua_variable(L, "m_canDamage", tolua_get_CGameSprite_m_canDamage, tolua_set_CGameSprite_m_canDamage);
		tolua_variable(L, "reference_m_canDamage", tolua_get_CGameSprite_reference_m_canDamage, NULL);
		tolua_variable(L, "m_leftAttack", tolua_get_CGameSprite_m_leftAttack, tolua_set_CGameSprite_m_leftAttack);
		tolua_variable(L, "reference_m_leftAttack", tolua_get_CGameSprite_reference_m_leftAttack, NULL);
		tolua_variable(L, "m_hasColorEffects", tolua_get_CGameSprite_m_hasColorEffects, tolua_set_CGameSprite_m_hasColorEffects);
		tolua_variable(L, "reference_m_hasColorEffects", tolua_get_CGameSprite_reference_m_hasColorEffects, NULL);
		tolua_variable(L, "m_hasAnimationEffects", tolua_get_CGameSprite_m_hasAnimationEffects, tolua_set_CGameSprite_m_hasAnimationEffects);
		tolua_variable(L, "reference_m_hasAnimationEffects", tolua_get_CGameSprite_reference_m_hasAnimationEffects, NULL);
		tolua_variable(L, "m_targetId", tolua_get_CGameSprite_m_targetId, tolua_set_CGameSprite_m_targetId);
		tolua_variable(L, "reference_m_targetId", tolua_get_CGameSprite_reference_m_targetId, NULL);
		tolua_variable(L, "m_dialog", tolua_get_CGameSprite_m_dialog, NULL);
		tolua_variable(L, "m_startedSwing", tolua_get_CGameSprite_m_startedSwing, tolua_set_CGameSprite_m_startedSwing);
		tolua_variable(L, "reference_m_startedSwing", tolua_get_CGameSprite_reference_m_startedSwing, NULL);
		tolua_variable(L, "m_followCount", tolua_get_CGameSprite_m_followCount, tolua_set_CGameSprite_m_followCount);
		tolua_variable(L, "reference_m_followCount", tolua_get_CGameSprite_reference_m_followCount, NULL);
		tolua_variable(L, "m_bForceVisualEffects", tolua_get_CGameSprite_m_bForceVisualEffects, tolua_set_CGameSprite_m_bForceVisualEffects);
		tolua_variable(L, "reference_m_bForceVisualEffects", tolua_get_CGameSprite_reference_m_bForceVisualEffects, NULL);
		tolua_variable(L, "m_currentActionId", tolua_get_CGameSprite_m_currentActionId, tolua_set_CGameSprite_m_currentActionId);
		tolua_variable(L, "reference_m_currentActionId", tolua_get_CGameSprite_reference_m_currentActionId, NULL);
		tolua_variable(L, "m_nWaitingOnDialog", tolua_get_CGameSprite_m_nWaitingOnDialog, tolua_set_CGameSprite_m_nWaitingOnDialog);
		tolua_variable(L, "reference_m_nWaitingOnDialog", tolua_get_CGameSprite_reference_m_nWaitingOnDialog, NULL);
		tolua_variable(L, "m_nCrossAreaChaseCounter", tolua_get_CGameSprite_m_nCrossAreaChaseCounter, tolua_set_CGameSprite_m_nCrossAreaChaseCounter);
		tolua_variable(L, "reference_m_nCrossAreaChaseCounter", tolua_get_CGameSprite_reference_m_nCrossAreaChaseCounter, NULL);
		tolua_variable(L, "aPSTVisualEffectProjectiles", tolua_get_CGameSprite_aPSTVisualEffectProjectiles, NULL);
		tolua_variable(L, "nAttachedPSTVisualEffectProjectiles", tolua_get_CGameSprite_nAttachedPSTVisualEffectProjectiles, tolua_set_CGameSprite_nAttachedPSTVisualEffectProjectiles);
		tolua_variable(L, "reference_nAttachedPSTVisualEffectProjectiles", tolua_get_CGameSprite_reference_nAttachedPSTVisualEffectProjectiles, NULL);
		tolua_variable(L, "nPSTVisualEffectsSetToRender", tolua_get_CGameSprite_nPSTVisualEffectsSetToRender, tolua_set_CGameSprite_nPSTVisualEffectsSetToRender);
		tolua_variable(L, "reference_nPSTVisualEffectsSetToRender", tolua_get_CGameSprite_reference_nPSTVisualEffectsSetToRender, NULL);
		tolua_variable(L, "m_savedLocation", tolua_get_CGameSprite_m_savedLocation, NULL);
		tolua_variable(L, "nOverTriggerId", tolua_get_CGameSprite_nOverTriggerId, tolua_set_CGameSprite_nOverTriggerId);
		tolua_variable(L, "reference_nOverTriggerId", tolua_get_CGameSprite_reference_nOverTriggerId, NULL);
		tolua_constant(L, "sizeof", sizeof(CGameSprite));
	tolua_endmodule(L);
	tolua_endmodule(L);
	return 1;
}
