
#include "engine_structs.h"
#include "to_lua_pointers.h"

static int tolua_function_CAIAction_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CAIAction>");
	return 1;
}

static int tolua_function_CGameAnimation_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameAnimation>");
	return 1;
}

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
	tolua_pushusertypepointer(L, (void*)&self->m_animation, "Pointer<CGameAnimationType*>");
	return 1;
}

static int tolua_function_CGameAnimationType_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameAnimationType>");
	return 1;
}

static int tolua_get_CGameAnimationType___vftable(lua_State* L)
{
	CGameAnimationType* self = (CGameAnimationType*)tolua_tousertype_dynamic(L, 1, 0, "CGameAnimationType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable '__vftable'", NULL);
	tolua_pushusertype(L, (void*)&self->__vftable, "dword");
	return 1;
}

static int tolua_function_CPersistantEffectColorEffect_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CPersistantEffectColorEffect>");
	return 1;
}

static int tolua_function_CPtrList_CNode_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CPtrList_CNode>");
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
	tolua_pushusertypepointer(L, (void*)&self->pNext, "Pointer<CPtrList_CNode*>");
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
	tolua_pushusertypepointer(L, (void*)&self->pPrev, "Pointer<CPtrList_CNode*>");
	return 1;
}

static int tolua_get_CPtrList_CNode_data(lua_State* L)
{
	CPtrList_CNode* self = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList_CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	tolua_pushusertype(L, (void*)self->data, "void");
	return 1;
}

static int tolua_set_CPtrList_CNode_data(lua_State* L)
{
	CPtrList_CNode* self = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList_CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	self->data = (void*)tolua_tousertype_dynamic(L, 2, 0, "void");
	return 0;
}

static int tolua_get_CPtrList_CNode_reference_data(lua_State* L)
{
	CPtrList_CNode* self = (CPtrList_CNode*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList_CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->data, "Pointer<void*>");
	return 1;
}

static int tolua_function_CResCell_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CResCell>");
	return 1;
}

static int tolua_function_CScreenWorld_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CScreenWorld>");
	return 1;
}

static int tolua_function_CSound_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CSound>");
	return 1;
}

static int tolua_function_CSoundImp_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CSoundImp>");
	return 1;
}

static int tolua_function_CVidImage_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CVidImage>");
	return 1;
}

static int tolua_function_CVideo_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CVideo>");
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
	tolua_pushusertypepointer(L, (void*)&self->pCurrentMode, "Pointer<CVidMode*>");
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

static int tolua_function_VoidPointer_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<void*>");
	return 1;
}

static int tolua_get_VoidPointer_reference(lua_State* L)
{
	VoidPointer* self = (VoidPointer*)tolua_tousertype_dynamic(L, 1, 0, "VoidPointer");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "void");
	return 1;
}

static int tolua_set_VoidPointer_reference(lua_State* L)
{
	VoidPointer* self = (VoidPointer*)tolua_tousertype_dynamic(L, 1, 0, "VoidPointer");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (void*)tolua_tousertype_dynamic(L, 2, 0, "void");
	return 0;
}

static int tolua_get_VoidPointer_reference_reference(lua_State* L)
{
	VoidPointer* self = (VoidPointer*)tolua_tousertype_dynamic(L, 1, 0, "VoidPointer");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->reference, "Pointer<void*>");
	return 1;
}

static int tolua_function___POSITION_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<__POSITION>");
	return 1;
}

static int tolua_function___int8_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<__int8>");
	return 1;
}

static int tolua_function_byte_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<byte>");
	return 1;
}

static int tolua_function_CTimerWorld_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CTimerWorld>");
	return 1;
}

static int tolua_get_CTimerWorld_m_gameTime(lua_State* L)
{
	CTimerWorld* self = (CTimerWorld*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CTimerWorld");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_gameTime'", NULL);
	tolua_pushusertype(L, (void*)&self->m_gameTime, "ulong");
	return 1;
}

static int tolua_get_CTimerWorld_m_active(lua_State* L)
{
	CTimerWorld* self = (CTimerWorld*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CTimerWorld");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_active'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_active);
	return 1;
}

static int tolua_set_CTimerWorld_m_active(lua_State* L)
{
	CTimerWorld* self = (CTimerWorld*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CTimerWorld");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_active'", NULL);
	self->m_active = tolua_setter_tointeger(L, "m_active");
	return 0;
}

static int tolua_get_CTimerWorld_reference_m_active(lua_State* L)
{
	CTimerWorld* self = (CTimerWorld*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CTimerWorld");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_active'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_active, "Pointer<byte>");
	return 1;
}

static int tolua_get_CTimerWorld_m_nLastPercentage(lua_State* L)
{
	CTimerWorld* self = (CTimerWorld*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CTimerWorld");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nLastPercentage'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nLastPercentage);
	return 1;
}

static int tolua_set_CTimerWorld_m_nLastPercentage(lua_State* L)
{
	CTimerWorld* self = (CTimerWorld*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CTimerWorld");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nLastPercentage'", NULL);
	self->m_nLastPercentage = tolua_setter_tointeger(L, "m_nLastPercentage");
	return 0;
}

static int tolua_get_CTimerWorld_reference_m_nLastPercentage(lua_State* L)
{
	CTimerWorld* self = (CTimerWorld*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CTimerWorld");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nLastPercentage'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nLastPercentage, "Pointer<byte>");
	return 1;
}

static int tolua_function_char_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<char>");
	return 1;
}

static int tolua_function_double_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<double>");
	return 1;
}

static int tolua_function_float_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<float>");
	return 1;
}

static int tolua_function_int_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<int>");
	return 1;
}

static int tolua_function_CRect_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CRect>");
	return 1;
}

static int tolua_get_CRect_left(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'left'", NULL);
	tolua_pushnumber(L, (lua_Number)self->left);
	return 1;
}

static int tolua_set_CRect_left(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'left'", NULL);
	self->left = tolua_setter_tointeger(L, "left");
	return 0;
}

static int tolua_get_CRect_reference_left(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'left'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->left, "Pointer<int>");
	return 1;
}

static int tolua_get_CRect_top(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'top'", NULL);
	tolua_pushnumber(L, (lua_Number)self->top);
	return 1;
}

static int tolua_set_CRect_top(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'top'", NULL);
	self->top = tolua_setter_tointeger(L, "top");
	return 0;
}

static int tolua_get_CRect_reference_top(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'top'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->top, "Pointer<int>");
	return 1;
}

static int tolua_get_CRect_right(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'right'", NULL);
	tolua_pushnumber(L, (lua_Number)self->right);
	return 1;
}

static int tolua_set_CRect_right(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'right'", NULL);
	self->right = tolua_setter_tointeger(L, "right");
	return 0;
}

static int tolua_get_CRect_reference_right(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'right'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->right, "Pointer<int>");
	return 1;
}

static int tolua_get_CRect_bottom(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bottom'", NULL);
	tolua_pushnumber(L, (lua_Number)self->bottom);
	return 1;
}

static int tolua_set_CRect_bottom(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bottom'", NULL);
	self->bottom = tolua_setter_tointeger(L, "bottom");
	return 0;
}

static int tolua_get_CRect_reference_bottom(lua_State* L)
{
	CRect* self = (CRect*)tolua_tousertype_dynamic(L, 1, 0, "CRect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bottom'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->bottom, "Pointer<int>");
	return 1;
}

static int tolua_function_CPtrList_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CPtrList>");
	return 1;
}

static int tolua_get_CPtrList___vftable(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable '__vftable'", NULL);
	tolua_pushusertype(L, (void*)&self->__vftable, "dword");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pNodeHead, "Pointer<CPtrList_CNode*>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pNodeTail, "Pointer<CPtrList_CNode*>");
	return 1;
}

static int tolua_get_CPtrList_m_nCount(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nCount);
	return 1;
}

static int tolua_set_CPtrList_m_nCount(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	self->m_nCount = tolua_setter_tointeger(L, "m_nCount");
	return 0;
}

static int tolua_get_CPtrList_reference_m_nCount(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nCount, "Pointer<int>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pNodeFree, "Pointer<CPtrList_CNode*>");
	return 1;
}

static int tolua_get_CPtrList_m_pBlocks(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertype(L, (void*)self->m_pBlocks, "void");
	return 1;
}

static int tolua_set_CPtrList_m_pBlocks(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	self->m_pBlocks = (void*)tolua_tousertype_dynamic(L, 2, 0, "void");
	return 0;
}

static int tolua_get_CPtrList_reference_m_pBlocks(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_pBlocks, "Pointer<void*>");
	return 1;
}

static int tolua_get_CPtrList_m_nBlockSize(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nBlockSize);
	return 1;
}

static int tolua_set_CPtrList_m_nBlockSize(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	self->m_nBlockSize = tolua_setter_tointeger(L, "m_nBlockSize");
	return 0;
}

static int tolua_get_CPtrList_reference_m_nBlockSize(lua_State* L)
{
	CPtrList* self = (CPtrList*)tolua_tousertype_dynamic(L, 1, 0, "CPtrList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nBlockSize, "Pointer<int>");
	return 1;
}

static int tolua_function_CPoint_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CPoint>");
	return 1;
}

static int tolua_get_CPoint_x(lua_State* L)
{
	CPoint* self = (CPoint*)tolua_tousertype_dynamic(L, 1, 0, "CPoint");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'x'", NULL);
	tolua_pushnumber(L, (lua_Number)self->x);
	return 1;
}

static int tolua_set_CPoint_x(lua_State* L)
{
	CPoint* self = (CPoint*)tolua_tousertype_dynamic(L, 1, 0, "CPoint");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'x'", NULL);
	self->x = tolua_setter_tointeger(L, "x");
	return 0;
}

static int tolua_get_CPoint_reference_x(lua_State* L)
{
	CPoint* self = (CPoint*)tolua_tousertype_dynamic(L, 1, 0, "CPoint");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'x'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->x, "Pointer<int>");
	return 1;
}

static int tolua_get_CPoint_y(lua_State* L)
{
	CPoint* self = (CPoint*)tolua_tousertype_dynamic(L, 1, 0, "CPoint");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'y'", NULL);
	tolua_pushnumber(L, (lua_Number)self->y);
	return 1;
}

static int tolua_set_CPoint_y(lua_State* L)
{
	CPoint* self = (CPoint*)tolua_tousertype_dynamic(L, 1, 0, "CPoint");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'y'", NULL);
	self->y = tolua_setter_tointeger(L, "y");
	return 0;
}

static int tolua_get_CPoint_reference_y(lua_State* L)
{
	CPoint* self = (CPoint*)tolua_tousertype_dynamic(L, 1, 0, "CPoint");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'y'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->y, "Pointer<int>");
	return 1;
}

static int tolua_function_CGameObjectArray_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameObjectArray>");
	return 1;
}

static int tolua_function_CGameObjectArray_GetShare(lua_State* L)
{
	byte returnVal = CGameObjectArray::GetShare(tolua_function_tointeger(L, 1, "GetShare"), (CGameObject**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameObject*>"));
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_get_reference_CGameObjectArray_GetShare(lua_State* L)
{
	tolua_pushusertype(L, CGameObjectArray::GetShare, "UnmappedUserType");
	return 1;
}

static int tolua_function_CGameEffectList_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameEffectList>");
	return 1;
}

static int tolua_get_CGameEffectList_m_posNext(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posNext'", NULL);
	tolua_pushusertype(L, (void*)self->m_posNext, "void");
	return 1;
}

static int tolua_set_CGameEffectList_m_posNext(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posNext'", NULL);
	self->m_posNext = (void*)tolua_tousertype_dynamic(L, 2, 0, "void");
	return 0;
}

static int tolua_get_CGameEffectList_reference_m_posNext(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posNext'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_posNext, "Pointer<void*>");
	return 1;
}

static int tolua_get_CGameEffectList_m_posCurrent(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posCurrent'", NULL);
	tolua_pushusertype(L, (void*)self->m_posCurrent, "void");
	return 1;
}

static int tolua_set_CGameEffectList_m_posCurrent(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posCurrent'", NULL);
	self->m_posCurrent = (void*)tolua_tousertype_dynamic(L, 2, 0, "void");
	return 0;
}

static int tolua_get_CGameEffectList_reference_m_posCurrent(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posCurrent'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_posCurrent, "Pointer<void*>");
	return 1;
}

static int tolua_get_CGameEffectList_m_newEffect(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_newEffect'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_newEffect);
	return 1;
}

static int tolua_set_CGameEffectList_m_newEffect(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_newEffect'", NULL);
	self->m_newEffect = tolua_setter_tointeger(L, "m_newEffect");
	return 0;
}

static int tolua_get_CGameEffectList_reference_m_newEffect(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_newEffect'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_newEffect, "Pointer<int>");
	return 1;
}

static int tolua_get_CGameEffectList_m_retry(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_retry'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_retry);
	return 1;
}

static int tolua_set_CGameEffectList_m_retry(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_retry'", NULL);
	self->m_retry = tolua_setter_tointeger(L, "m_retry");
	return 0;
}

static int tolua_get_CGameEffectList_reference_m_retry(lua_State* L)
{
	CGameEffectList* self = (CGameEffectList*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectList");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_retry'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_retry, "Pointer<int>");
	return 1;
}

static int tolua_function_CBaldurChitin_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CBaldurChitin>");
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
	tolua_pushnumber(L, (lua_Number)self->m_bConnectionEstablished);
	return 1;
}

static int tolua_set_CBaldurChitin_m_bConnectionEstablished(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bConnectionEstablished'", NULL);
	self->m_bConnectionEstablished = tolua_setter_tointeger(L, "m_bConnectionEstablished");
	return 0;
}

static int tolua_get_CBaldurChitin_reference_m_bConnectionEstablished(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bConnectionEstablished'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_bConnectionEstablished, "Pointer<byte>");
	return 1;
}

static int tolua_get_CBaldurChitin_m_idLocalPlayer(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_idLocalPlayer'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_idLocalPlayer);
	return 1;
}

static int tolua_set_CBaldurChitin_m_idLocalPlayer(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_idLocalPlayer'", NULL);
	self->m_idLocalPlayer = tolua_setter_tointeger(L, "m_idLocalPlayer");
	return 0;
}

static int tolua_get_CBaldurChitin_reference_m_idLocalPlayer(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_idLocalPlayer'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_idLocalPlayer, "Pointer<int>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pObjectGame, "Pointer<EEex_CInfGame*>");
	return 1;
}

static int tolua_get_CBaldurChitin_m_pEngineMap(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pEngineMap'", NULL);
	tolua_pushusertype(L, (void*)self->m_pEngineMap, "void");
	return 1;
}

static int tolua_set_CBaldurChitin_m_pEngineMap(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pEngineMap'", NULL);
	self->m_pEngineMap = (void*)tolua_tousertype_dynamic(L, 2, 0, "void");
	return 0;
}

static int tolua_get_CBaldurChitin_reference_m_pEngineMap(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pEngineMap'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_pEngineMap, "Pointer<void*>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pEngineWorld, "Pointer<EEex_CScreenWorld*>");
	return 1;
}

static int tolua_get_CBaldurChitin_m_cMessageHandler(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_cMessageHandler'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_cMessageHandler);
	return 1;
}

static int tolua_set_CBaldurChitin_m_cMessageHandler(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_cMessageHandler'", NULL);
	self->m_cMessageHandler = tolua_setter_tointeger(L, "m_cMessageHandler");
	return 0;
}

static int tolua_get_CBaldurChitin_reference_m_cMessageHandler(lua_State* L)
{
	CBaldurChitin* self = (CBaldurChitin*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CBaldurChitin");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_cMessageHandler'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_cMessageHandler, "Pointer<byte>");
	return 1;
}

static int tolua_function_intptr_t_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<intptr_t>");
	return 1;
}

static int tolua_function_UnmappedUserType_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<UnmappedUserType>");
	return 1;
}

static int tolua_function_UnmappedUserType_toPointer(lua_State* L)
{
	UnmappedUserType* self = (UnmappedUserType*)tolua_tousertype_dynamic(L, 1, 0, "UnmappedUserType");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'toPointer'", NULL);
	intptr_t returnVal = self->toPointer();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_long_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<long>");
	return 1;
}

static int tolua_function_CMessage_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CMessage>");
	return 1;
}

static int tolua_get_CMessage___vftable(lua_State* L)
{
	CMessage* self = (CMessage*)tolua_tousertype_dynamic(L, 1, 0, "CMessage");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable '__vftable'", NULL);
	tolua_pushusertype(L, (void*)&self->__vftable, "dword");
	return 1;
}

static int tolua_get_CMessage_m_targetId(lua_State* L)
{
	CMessage* self = (CMessage*)tolua_tousertype_dynamic(L, 1, 0, "CMessage");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_targetId);
	return 1;
}

static int tolua_set_CMessage_m_targetId(lua_State* L)
{
	CMessage* self = (CMessage*)tolua_tousertype_dynamic(L, 1, 0, "CMessage");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	self->m_targetId = tolua_setter_tointeger(L, "m_targetId");
	return 0;
}

static int tolua_get_CMessage_reference_m_targetId(lua_State* L)
{
	CMessage* self = (CMessage*)tolua_tousertype_dynamic(L, 1, 0, "CMessage");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_targetId, "Pointer<long>");
	return 1;
}

static int tolua_get_CMessage_m_sourceId(lua_State* L)
{
	CMessage* self = (CMessage*)tolua_tousertype_dynamic(L, 1, 0, "CMessage");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_sourceId);
	return 1;
}

static int tolua_set_CMessage_m_sourceId(lua_State* L)
{
	CMessage* self = (CMessage*)tolua_tousertype_dynamic(L, 1, 0, "CMessage");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	self->m_sourceId = tolua_setter_tointeger(L, "m_sourceId");
	return 0;
}

static int tolua_get_CMessage_reference_m_sourceId(lua_State* L)
{
	CMessage* self = (CMessage*)tolua_tousertype_dynamic(L, 1, 0, "CMessage");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_sourceId, "Pointer<long>");
	return 1;
}

static int tolua_function_CMessageVisualEffect_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CMessageVisualEffect>");
	return 1;
}

static int tolua_get_CMessageVisualEffect_m_nEffectType(lua_State* L)
{
	CMessageVisualEffect* self = (CMessageVisualEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageVisualEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nEffectType'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nEffectType);
	return 1;
}

static int tolua_set_CMessageVisualEffect_m_nEffectType(lua_State* L)
{
	CMessageVisualEffect* self = (CMessageVisualEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageVisualEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nEffectType'", NULL);
	self->m_nEffectType = tolua_setter_tointeger(L, "m_nEffectType");
	return 0;
}

static int tolua_get_CMessageVisualEffect_reference_m_nEffectType(lua_State* L)
{
	CMessageVisualEffect* self = (CMessageVisualEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageVisualEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nEffectType'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nEffectType, "Pointer<byte>");
	return 1;
}

static int tolua_get_CMessageVisualEffect_m_nEffectProperty(lua_State* L)
{
	CMessageVisualEffect* self = (CMessageVisualEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageVisualEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nEffectProperty'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nEffectProperty);
	return 1;
}

static int tolua_set_CMessageVisualEffect_m_nEffectProperty(lua_State* L)
{
	CMessageVisualEffect* self = (CMessageVisualEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageVisualEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nEffectProperty'", NULL);
	self->m_nEffectProperty = tolua_setter_tointeger(L, "m_nEffectProperty");
	return 0;
}

static int tolua_get_CMessageVisualEffect_reference_m_nEffectProperty(lua_State* L)
{
	CMessageVisualEffect* self = (CMessageVisualEffect*)tolua_tousertype_dynamic(L, 1, 0, "CMessageVisualEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nEffectProperty'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nEffectProperty, "Pointer<byte>");
	return 1;
}

static int tolua_function_short_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<short>");
	return 1;
}

static int tolua_function_size_t_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<size_t>");
	return 1;
}

static int tolua_function_uint_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<uint>");
	return 1;
}

static int tolua_function_CVidMode_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CVidMode>");
	return 1;
}

static int tolua_function_CInfinity_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CInfinity>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_areaTintOverride, "Pointer<CAreaTintOverride*>");
	return 1;
}

static int tolua_get_CInfinity_m_rgbAreaTintGlobalLightingOverride(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbAreaTintGlobalLightingOverride'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_rgbAreaTintGlobalLightingOverride);
	return 1;
}

static int tolua_set_CInfinity_m_rgbAreaTintGlobalLightingOverride(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbAreaTintGlobalLightingOverride'", NULL);
	self->m_rgbAreaTintGlobalLightingOverride = tolua_setter_tointeger(L, "m_rgbAreaTintGlobalLightingOverride");
	return 0;
}

static int tolua_get_CInfinity_reference_m_rgbAreaTintGlobalLightingOverride(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbAreaTintGlobalLightingOverride'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_rgbAreaTintGlobalLightingOverride, "Pointer<int>");
	return 1;
}

static int tolua_get_CInfinity_unknownPSTGlobalTint(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownPSTGlobalTint'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unknownPSTGlobalTint);
	return 1;
}

static int tolua_set_CInfinity_unknownPSTGlobalTint(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownPSTGlobalTint'", NULL);
	self->unknownPSTGlobalTint = tolua_setter_tointeger(L, "unknownPSTGlobalTint");
	return 0;
}

static int tolua_get_CInfinity_reference_unknownPSTGlobalTint(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownPSTGlobalTint'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknownPSTGlobalTint, "Pointer<uint>");
	return 1;
}

static int tolua_get_CInfinity_unknownSetByOp354(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownSetByOp354'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unknownSetByOp354);
	return 1;
}

static int tolua_set_CInfinity_unknownSetByOp354(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownSetByOp354'", NULL);
	self->unknownSetByOp354 = tolua_setter_tointeger(L, "unknownSetByOp354");
	return 0;
}

static int tolua_get_CInfinity_reference_unknownSetByOp354(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownSetByOp354'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknownSetByOp354, "Pointer<int>");
	return 1;
}

static int tolua_get_CInfinity_m_renderDayNightCode(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_renderDayNightCode'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_renderDayNightCode);
	return 1;
}

static int tolua_set_CInfinity_m_renderDayNightCode(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_renderDayNightCode'", NULL);
	self->m_renderDayNightCode = tolua_setter_tointeger(L, "m_renderDayNightCode");
	return 0;
}

static int tolua_get_CInfinity_reference_m_renderDayNightCode(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_renderDayNightCode'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_renderDayNightCode, "Pointer<byte>");
	return 1;
}

static int tolua_get_CInfinity_m_rgbLightningGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbLightningGlobalLighting'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_rgbLightningGlobalLighting);
	return 1;
}

static int tolua_set_CInfinity_m_rgbLightningGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbLightningGlobalLighting'", NULL);
	self->m_rgbLightningGlobalLighting = tolua_setter_tointeger(L, "m_rgbLightningGlobalLighting");
	return 0;
}

static int tolua_get_CInfinity_reference_m_rgbLightningGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbLightningGlobalLighting'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_rgbLightningGlobalLighting, "Pointer<uint>");
	return 1;
}

static int tolua_get_CInfinity_m_rgbOverCastGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbOverCastGlobalLighting'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_rgbOverCastGlobalLighting);
	return 1;
}

static int tolua_set_CInfinity_m_rgbOverCastGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbOverCastGlobalLighting'", NULL);
	self->m_rgbOverCastGlobalLighting = tolua_setter_tointeger(L, "m_rgbOverCastGlobalLighting");
	return 0;
}

static int tolua_get_CInfinity_reference_m_rgbOverCastGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbOverCastGlobalLighting'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_rgbOverCastGlobalLighting, "Pointer<uint>");
	return 1;
}

static int tolua_get_CInfinity_m_rgbTimeOfDayGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbTimeOfDayGlobalLighting'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_rgbTimeOfDayGlobalLighting);
	return 1;
}

static int tolua_set_CInfinity_m_rgbTimeOfDayGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbTimeOfDayGlobalLighting'", NULL);
	self->m_rgbTimeOfDayGlobalLighting = tolua_setter_tointeger(L, "m_rgbTimeOfDayGlobalLighting");
	return 0;
}

static int tolua_get_CInfinity_reference_m_rgbTimeOfDayGlobalLighting(lua_State* L)
{
	CInfinity* self = (CInfinity*)tolua_tousertype_dynamic(L, 1, 0, "CInfinity");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_rgbTimeOfDayGlobalLighting'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_rgbTimeOfDayGlobalLighting, "Pointer<uint>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pArea, "Pointer<CGameArea*>");
	return 1;
}

static int tolua_function_ushort_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<ushort>");
	return 1;
}

static int tolua_function_CGameTrigger_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameTrigger>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pArea, "Pointer<CGameArea*>");
	return 1;
}

static int tolua_get_CGameTrigger_m_posVertList(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posVertList'", NULL);
	tolua_pushusertype(L, (void*)self->m_posVertList, "void");
	return 1;
}

static int tolua_set_CGameTrigger_m_posVertList(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posVertList'", NULL);
	self->m_posVertList = (void*)tolua_tousertype_dynamic(L, 2, 0, "void");
	return 0;
}

static int tolua_get_CGameTrigger_reference_m_posVertList(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posVertList'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_posVertList, "Pointer<void*>");
	return 1;
}

static int tolua_get_CGameTrigger_m_id(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_id'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_id);
	return 1;
}

static int tolua_set_CGameTrigger_m_id(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_id'", NULL);
	self->m_id = tolua_setter_tointeger(L, "m_id");
	return 0;
}

static int tolua_get_CGameTrigger_reference_m_id(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_id'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_id, "Pointer<long>");
	return 1;
}

static int tolua_get_CGameTrigger_m_remotePlayerID(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remotePlayerID'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_remotePlayerID);
	return 1;
}

static int tolua_set_CGameTrigger_m_remotePlayerID(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remotePlayerID'", NULL);
	self->m_remotePlayerID = tolua_setter_tointeger(L, "m_remotePlayerID");
	return 0;
}

static int tolua_get_CGameTrigger_reference_m_remotePlayerID(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remotePlayerID'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_remotePlayerID, "Pointer<int>");
	return 1;
}

static int tolua_get_CGameTrigger_m_triggerType(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_triggerType'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_triggerType);
	return 1;
}

static int tolua_set_CGameTrigger_m_triggerType(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_triggerType'", NULL);
	self->m_triggerType = tolua_setter_tointeger(L, "m_triggerType");
	return 0;
}

static int tolua_get_CGameTrigger_reference_m_triggerType(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_triggerType'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_triggerType, "Pointer<ushort>");
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
	tolua_pushnumber(L, (lua_Number)self->m_boundingRange);
	return 1;
}

static int tolua_set_CGameTrigger_m_boundingRange(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_boundingRange'", NULL);
	self->m_boundingRange = tolua_setter_tointeger(L, "m_boundingRange");
	return 0;
}

static int tolua_get_CGameTrigger_reference_m_boundingRange(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_boundingRange'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_boundingRange, "Pointer<ushort>");
	return 1;
}

static int tolua_get_CGameTrigger_m_trapActivated(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_trapActivated);
	return 1;
}

static int tolua_set_CGameTrigger_m_trapActivated(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	self->m_trapActivated = tolua_setter_tointeger(L, "m_trapActivated");
	return 0;
}

static int tolua_get_CGameTrigger_reference_m_trapActivated(lua_State* L)
{
	CGameTrigger* self = (CGameTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CGameTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_trapActivated, "Pointer<ushort>");
	return 1;
}

static int tolua_function_CGameDoor_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameDoor>");
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
	tolua_pushnumber(L, (lua_Number)self->m_trapActivated);
	return 1;
}

static int tolua_set_CGameDoor_m_trapActivated(lua_State* L)
{
	CGameDoor* self = (CGameDoor*)tolua_tousertype_dynamic(L, 1, 0, "CGameDoor");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	self->m_trapActivated = tolua_setter_tointeger(L, "m_trapActivated");
	return 0;
}

static int tolua_get_CGameDoor_reference_m_trapActivated(lua_State* L)
{
	CGameDoor* self = (CGameDoor*)tolua_tousertype_dynamic(L, 1, 0, "CGameDoor");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_trapActivated, "Pointer<ushort>");
	return 1;
}

static int tolua_function_CGameContainer_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameContainer>");
	return 1;
}

static int tolua_get_CGameContainer_m_trapActivated(lua_State* L)
{
	CGameContainer* self = (CGameContainer*)tolua_tousertype_dynamic(L, 1, 0, "CGameContainer");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_trapActivated);
	return 1;
}

static int tolua_set_CGameContainer_m_trapActivated(lua_State* L)
{
	CGameContainer* self = (CGameContainer*)tolua_tousertype_dynamic(L, 1, 0, "CGameContainer");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	self->m_trapActivated = tolua_setter_tointeger(L, "m_trapActivated");
	return 0;
}

static int tolua_get_CGameContainer_reference_m_trapActivated(lua_State* L)
{
	CGameContainer* self = (CGameContainer*)tolua_tousertype_dynamic(L, 1, 0, "CGameContainer");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trapActivated'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_trapActivated, "Pointer<ushort>");
	return 1;
}

static int tolua_function_void_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "VoidPointer");
	return 1;
}

static int tolua_function_Pointer_CGameObject__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameObject*>");
	return 1;
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

static int tolua_function_Pointer_CBaldurChitin__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<EEex_CBaldurChitin*>");
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

static int tolua_function_Pointer_CObject__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CObject*>");
	return 1;
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

static int tolua_function_Pointer_CGameArea__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameArea*>");
	return 1;
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

static int tolua_function_Pointer_const_CPoint__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<const CPoint*>");
	return 1;
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

static int tolua_function_Pointer_const_CAIObjectType__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<const CAIObjectType*>");
	return 1;
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

static int tolua_function_Pointer_CPoint__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CPoint*>");
	return 1;
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

static int tolua_function_Pointer_CTypedPtrList_CPtrList_long___CNode__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CTypedPtrList<CPtrList,long>::CNode*>");
	return 1;
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

static int tolua_function_Pointer_unsigned_int__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<unsigned int*>");
	return 1;
}

static int tolua_get_Pointer_unsigned_int__reference(lua_State* L)
{
	Pointer<unsigned int>* self = (Pointer<unsigned int>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushnumber(L, (lua_Number)*self->reference);
	return 1;
}

static int tolua_set_Pointer_unsigned_int__reference(lua_State* L)
{
	Pointer<unsigned int>* self = (Pointer<unsigned int>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (unsigned int*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<unsigned int>");
	return 0;
}

static int tolua_function_Pointer_unsigned_int__getValue(lua_State* L)
{
	Pointer<unsigned int>* self = (Pointer<unsigned int>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned int>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	unsigned int returnVal = self->getValue();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Pointer_unsigned_int__setValue(lua_State* L)
{
	Pointer<unsigned int>* self = (Pointer<unsigned int>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned int>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger(L, 2, "setValue"));
	return 0;
}

static int tolua_function_Pointer_const_CString__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<const CString*>");
	return 1;
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

static int tolua_function_Pointer_CVidMode__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CVidMode*>");
	return 1;
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

static int tolua_function_Pointer___POSITION__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<__POSITION*>");
	return 1;
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

static int tolua_function_Pointer_const_CAITrigger__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<const CAITrigger*>");
	return 1;
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

static int tolua_function_Pointer_CGameAIBase__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameAIBase*>");
	return 1;
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

static int tolua_function_Pointer_const_CAIAction__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<const CAIAction*>");
	return 1;
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

static int tolua_function_Pointer_CGameEffect__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameEffect*>");
	return 1;
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

static int tolua_function_Pointer_CResRef__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CResRef*>");
	return 1;
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

static int tolua_function_Pointer_CGameObject___getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameObject**>");
	return 1;
}

static int tolua_get_Pointer_CGameObject___reference(lua_State* L)
{
	Pointer<CGameObject*>* self = (Pointer<CGameObject*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CGameObject*>");
	return 1;
}

static int tolua_set_Pointer_CGameObject___reference(lua_State* L)
{
	Pointer<CGameObject*>* self = (Pointer<CGameObject*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameObject**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameObject*>");
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

static int tolua_function_Pointer_Item_effect_st__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<Item_effect_st*>");
	return 1;
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

static int tolua_function_Pointer_CInfGame__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<EEex_CInfGame*>");
	return 1;
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

static int tolua_function_Pointer_CScreenWorld__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<EEex_CScreenWorld*>");
	return 1;
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

static int tolua_function_Pointer_CGameAnimationType__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameAnimationType*>");
	return 1;
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

static int tolua_function_Pointer_CProjectileUnknownPST2__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CProjectileUnknownPST2*>");
	return 1;
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

static int tolua_function_Pointer_CInfinity__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CInfinity*>");
	return 1;
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

static int tolua_function_Pointer_CVidCell__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CVidCell*>");
	return 1;
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

static int tolua_function_Pointer_CPtrList_CNode__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CPtrList_CNode*>");
	return 1;
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

static int tolua_function_Pointer_int__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<int*>");
	return 1;
}

static int tolua_get_Pointer_int__reference(lua_State* L)
{
	Pointer<int>* self = (Pointer<int>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushnumber(L, (lua_Number)*self->reference);
	return 1;
}

static int tolua_set_Pointer_int__reference(lua_State* L)
{
	Pointer<int>* self = (Pointer<int>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (int*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<int>");
	return 0;
}

static int tolua_function_Pointer_int__getValue(lua_State* L)
{
	Pointer<int>* self = (Pointer<int>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<int>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	int returnVal = self->getValue();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Pointer_int__setValue(lua_State* L)
{
	Pointer<int>* self = (Pointer<int>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<int>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger(L, 2, "setValue"));
	return 0;
}

static int tolua_function_Pointer_CSoundImp__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CSoundImp*>");
	return 1;
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

static int tolua_function_Pointer_CAreaTintOverride__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CAreaTintOverride*>");
	return 1;
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<EEex_CBaldurChitin*>");
	return 1;
}

static int tolua_set_Pointer_CBaldurChitin___reference(lua_State* L)
{
	Pointer<CBaldurChitin*>* self = (Pointer<CBaldurChitin*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CBaldurChitin*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CBaldurChitin**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<EEex_CBaldurChitin*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CObject*>");
	return 1;
}

static int tolua_set_Pointer_CObject___reference(lua_State* L)
{
	Pointer<CObject*>* self = (Pointer<CObject*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CObject*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CObject**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CObject*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CGameArea*>");
	return 1;
}

static int tolua_set_Pointer_CGameArea___reference(lua_State* L)
{
	Pointer<CGameArea*>* self = (Pointer<CGameArea*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameArea*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameArea**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameArea*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<const CPoint*>");
	return 1;
}

static int tolua_set_Pointer_const_CPoint___reference(lua_State* L)
{
	Pointer<const CPoint*>* self = (Pointer<const CPoint*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CPoint*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const CPoint**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<const CPoint*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<const CAIObjectType*>");
	return 1;
}

static int tolua_set_Pointer_const_CAIObjectType___reference(lua_State* L)
{
	Pointer<const CAIObjectType*>* self = (Pointer<const CAIObjectType*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAIObjectType*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const CAIObjectType**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<const CAIObjectType*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CPoint*>");
	return 1;
}

static int tolua_set_Pointer_CPoint___reference(lua_State* L)
{
	Pointer<CPoint*>* self = (Pointer<CPoint*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPoint*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CPoint**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CPoint*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CTypedPtrList<CPtrList,long>::CNode*>");
	return 1;
}

static int tolua_set_Pointer_CTypedPtrList_CPtrList_long___CNode___reference(lua_State* L)
{
	Pointer<CTypedPtrList<CPtrList,long>::CNode*>* self = (Pointer<CTypedPtrList<CPtrList,long>::CNode*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CTypedPtrList<CPtrList,long>::CNode*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CTypedPtrList<CPtrList,long>::CNode**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CTypedPtrList<CPtrList,long>::CNode*>");
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
	tolua_pushnumber(L, (lua_Number)**self->reference);
	return 1;
}

static int tolua_set_Pointer_unsigned_int___reference(lua_State* L)
{
	Pointer<unsigned int*>* self = (Pointer<unsigned int*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (unsigned int**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<unsigned int*>");
	return 0;
}

static int tolua_function_Pointer_unsigned_int___getValue(lua_State* L)
{
	Pointer<unsigned int*>* self = (Pointer<unsigned int*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned int*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	unsigned int* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "Pointer<unsigned int>");
	return 1;
}

static int tolua_function_Pointer_unsigned_int___setValue(lua_State* L)
{
	Pointer<unsigned int*>* self = (Pointer<unsigned int*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned int*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((unsigned int*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<unsigned int>"));
	return 0;
}

static int tolua_get_Pointer_const_CString___reference(lua_State* L)
{
	Pointer<const CString*>* self = (Pointer<const CString*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CString*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<const CString*>");
	return 1;
}

static int tolua_set_Pointer_const_CString___reference(lua_State* L)
{
	Pointer<const CString*>* self = (Pointer<const CString*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CString*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const CString**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<const CString*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CVidMode*>");
	return 1;
}

static int tolua_set_Pointer_CVidMode___reference(lua_State* L)
{
	Pointer<CVidMode*>* self = (Pointer<CVidMode*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidMode*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CVidMode**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CVidMode*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<__POSITION*>");
	return 1;
}

static int tolua_set_Pointer___POSITION___reference(lua_State* L)
{
	Pointer<__POSITION*>* self = (Pointer<__POSITION*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__POSITION*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (__POSITION**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<__POSITION*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<const CAITrigger*>");
	return 1;
}

static int tolua_set_Pointer_const_CAITrigger___reference(lua_State* L)
{
	Pointer<const CAITrigger*>* self = (Pointer<const CAITrigger*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAITrigger*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const CAITrigger**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<const CAITrigger*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CGameAIBase*>");
	return 1;
}

static int tolua_set_Pointer_CGameAIBase___reference(lua_State* L)
{
	Pointer<CGameAIBase*>* self = (Pointer<CGameAIBase*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAIBase*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameAIBase**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameAIBase*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<const CAIAction*>");
	return 1;
}

static int tolua_set_Pointer_const_CAIAction___reference(lua_State* L)
{
	Pointer<const CAIAction*>* self = (Pointer<const CAIAction*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const CAIAction*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const CAIAction**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<const CAIAction*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CGameEffect*>");
	return 1;
}

static int tolua_set_Pointer_CGameEffect___reference(lua_State* L)
{
	Pointer<CGameEffect*>* self = (Pointer<CGameEffect*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameEffect*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameEffect**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameEffect*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CResRef*>");
	return 1;
}

static int tolua_set_Pointer_CResRef___reference(lua_State* L)
{
	Pointer<CResRef*>* self = (Pointer<CResRef*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResRef*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CResRef**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CResRef*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CGameObject**>");
	return 1;
}

static int tolua_set_Pointer_CGameObject____reference(lua_State* L)
{
	Pointer<CGameObject**>* self = (Pointer<CGameObject**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject**>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameObject***)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameObject**>");
	return 0;
}

static int tolua_function_Pointer_CGameObject____getValue(lua_State* L)
{
	Pointer<CGameObject**>* self = (Pointer<CGameObject**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject**>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CGameObject** returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "Pointer<CGameObject*>");
	return 1;
}

static int tolua_function_Pointer_CGameObject____setValue(lua_State* L)
{
	Pointer<CGameObject**>* self = (Pointer<CGameObject**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObject**>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CGameObject**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameObject*>"));
	return 0;
}

static int tolua_get_Pointer_Item_effect_st___reference(lua_State* L)
{
	Pointer<Item_effect_st*>* self = (Pointer<Item_effect_st*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Item_effect_st*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<Item_effect_st*>");
	return 1;
}

static int tolua_set_Pointer_Item_effect_st___reference(lua_State* L)
{
	Pointer<Item_effect_st*>* self = (Pointer<Item_effect_st*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<Item_effect_st*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (Item_effect_st**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<Item_effect_st*>");
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

static int tolua_get_Pointer_CInfGame___reference(lua_State* L)
{
	Pointer<CInfGame*>* self = (Pointer<CInfGame*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CInfGame*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<EEex_CInfGame*>");
	return 1;
}

static int tolua_set_Pointer_CInfGame___reference(lua_State* L)
{
	Pointer<CInfGame*>* self = (Pointer<CInfGame*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CInfGame*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CInfGame**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<EEex_CInfGame*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<EEex_CScreenWorld*>");
	return 1;
}

static int tolua_set_Pointer_CScreenWorld___reference(lua_State* L)
{
	Pointer<CScreenWorld*>* self = (Pointer<CScreenWorld*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<EEex_CScreenWorld*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CScreenWorld**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<EEex_CScreenWorld*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CGameAnimationType*>");
	return 1;
}

static int tolua_set_Pointer_CGameAnimationType___reference(lua_State* L)
{
	Pointer<CGameAnimationType*>* self = (Pointer<CGameAnimationType*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameAnimationType*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameAnimationType**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameAnimationType*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CProjectileUnknownPST2*>");
	return 1;
}

static int tolua_set_Pointer_CProjectileUnknownPST2___reference(lua_State* L)
{
	Pointer<CProjectileUnknownPST2*>* self = (Pointer<CProjectileUnknownPST2*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST2*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CProjectileUnknownPST2**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CProjectileUnknownPST2*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CInfinity*>");
	return 1;
}

static int tolua_set_Pointer_CInfinity___reference(lua_State* L)
{
	Pointer<CInfinity*>* self = (Pointer<CInfinity*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CInfinity*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CInfinity**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CInfinity*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CVidCell*>");
	return 1;
}

static int tolua_set_Pointer_CVidCell___reference(lua_State* L)
{
	Pointer<CVidCell*>* self = (Pointer<CVidCell*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CVidCell*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CVidCell**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CVidCell*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CPtrList_CNode*>");
	return 1;
}

static int tolua_set_Pointer_CPtrList_CNode___reference(lua_State* L)
{
	Pointer<CPtrList_CNode*>* self = (Pointer<CPtrList_CNode*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CPtrList_CNode*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CPtrList_CNode**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CPtrList_CNode*>");
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
	tolua_pushnumber(L, (lua_Number)**self->reference);
	return 1;
}

static int tolua_set_Pointer_int___reference(lua_State* L)
{
	Pointer<int*>* self = (Pointer<int*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (int**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<int*>");
	return 0;
}

static int tolua_function_Pointer_int___getValue(lua_State* L)
{
	Pointer<int*>* self = (Pointer<int*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<int*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	int* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "Pointer<int>");
	return 1;
}

static int tolua_function_Pointer_int___setValue(lua_State* L)
{
	Pointer<int*>* self = (Pointer<int*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<int*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((int*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<int>"));
	return 0;
}

static int tolua_get_Pointer_CSoundImp___reference(lua_State* L)
{
	Pointer<CSoundImp*>* self = (Pointer<CSoundImp*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CSoundImp*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CSoundImp*>");
	return 1;
}

static int tolua_set_Pointer_CSoundImp___reference(lua_State* L)
{
	Pointer<CSoundImp*>* self = (Pointer<CSoundImp*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CSoundImp*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CSoundImp**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CSoundImp*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CAreaTintOverride*>");
	return 1;
}

static int tolua_set_Pointer_CAreaTintOverride___reference(lua_State* L)
{
	Pointer<CAreaTintOverride*>* self = (Pointer<CAreaTintOverride*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CAreaTintOverride*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CAreaTintOverride**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CAreaTintOverride*>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CResCell*>");
	return 1;
}

static int tolua_set_Pointer_CResCell___reference(lua_State* L)
{
	Pointer<CResCell*>* self = (Pointer<CResCell*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CResCell*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CResCell**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CResCell*>");
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

static int tolua_get_Pointer_void___reference(lua_State* L)
{
	Pointer<void*>* self = (Pointer<void*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<void*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<void*>");
	return 1;
}

static int tolua_set_Pointer_void___reference(lua_State* L)
{
	Pointer<void*>* self = (Pointer<void*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<void*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (void**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<void*>");
	return 0;
}

static int tolua_function_Pointer_void___getValue(lua_State* L)
{
	Pointer<void*>* self = (Pointer<void*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<void*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	void* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "void");
	return 1;
}

static int tolua_function_Pointer_void___setValue(lua_State* L)
{
	Pointer<void*>* self = (Pointer<void*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<void*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((void*)tolua_tousertype_dynamic(L, 2, 0, "void"));
	return 0;
}

static int tolua_get_Pointer_unsigned___int8__reference(lua_State* L)
{
	Pointer<unsigned __int8>* self = (Pointer<unsigned __int8>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned __int8>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushnumber(L, (lua_Number)*self->reference);
	return 1;
}

static int tolua_set_Pointer_unsigned___int8__reference(lua_State* L)
{
	Pointer<unsigned __int8>* self = (Pointer<unsigned __int8>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned __int8>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (unsigned __int8*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<unsigned __int8>");
	return 0;
}

static int tolua_function_Pointer_unsigned___int8__getValue(lua_State* L)
{
	Pointer<unsigned __int8>* self = (Pointer<unsigned __int8>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned __int8>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	unsigned __int8 returnVal = self->getValue();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Pointer_unsigned___int8__setValue(lua_State* L)
{
	Pointer<unsigned __int8>* self = (Pointer<unsigned __int8>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<unsigned __int8>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer___int8__reference(lua_State* L)
{
	Pointer<__int8>* self = (Pointer<__int8>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__int8>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushnumber(L, (lua_Number)*self->reference);
	return 1;
}

static int tolua_set_Pointer___int8__reference(lua_State* L)
{
	Pointer<__int8>* self = (Pointer<__int8>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__int8>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (__int8*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<__int8>");
	return 0;
}

static int tolua_function_Pointer___int8__getValue(lua_State* L)
{
	Pointer<__int8>* self = (Pointer<__int8>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__int8>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	__int8 returnVal = self->getValue();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Pointer___int8__setValue(lua_State* L)
{
	Pointer<__int8>* self = (Pointer<__int8>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<__int8>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_VertListType__reference(lua_State* L)
{
	Pointer<VertListType>* self = (Pointer<VertListType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<VertListType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "VertListType");
	return 1;
}

static int tolua_set_Pointer_VertListType__reference(lua_State* L)
{
	Pointer<VertListType>* self = (Pointer<VertListType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<VertListType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (VertListType*)tolua_tousertype_dynamic(L, 2, 0, "VertListType");
	return 0;
}

static int tolua_function_Pointer_VertListType__getValue(lua_State* L)
{
	Pointer<VertListType>* self = (Pointer<VertListType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<VertListType>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	VertListType returnVal = self->getValue();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Pointer_VertListType__setValue(lua_State* L)
{
	Pointer<VertListType>* self = (Pointer<VertListType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<VertListType>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((VertListType)tolua_function_tointeger(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_CGameObjectType__reference(lua_State* L)
{
	Pointer<CGameObjectType>* self = (Pointer<CGameObjectType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObjectType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "CGameObjectType");
	return 1;
}

static int tolua_set_Pointer_CGameObjectType__reference(lua_State* L)
{
	Pointer<CGameObjectType>* self = (Pointer<CGameObjectType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObjectType>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameObjectType*)tolua_tousertype_dynamic(L, 2, 0, "CGameObjectType");
	return 0;
}

static int tolua_function_Pointer_CGameObjectType__getValue(lua_State* L)
{
	Pointer<CGameObjectType>* self = (Pointer<CGameObjectType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObjectType>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CGameObjectType returnVal = self->getValue();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Pointer_CGameObjectType__setValue(lua_State* L)
{
	Pointer<CGameObjectType>* self = (Pointer<CGameObjectType>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameObjectType>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CGameObjectType)tolua_function_tointeger(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_byte__reference(lua_State* L)
{
	Pointer<byte>* self = (Pointer<byte>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<byte>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushnumber(L, (lua_Number)*self->reference);
	return 1;
}

static int tolua_set_Pointer_byte__reference(lua_State* L)
{
	Pointer<byte>* self = (Pointer<byte>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<byte>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (byte*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<byte>");
	return 0;
}

static int tolua_function_Pointer_byte__getValue(lua_State* L)
{
	Pointer<byte>* self = (Pointer<byte>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<byte>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	byte returnVal = self->getValue();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Pointer_byte__setValue(lua_State* L)
{
	Pointer<byte>* self = (Pointer<byte>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<byte>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_byte___reference(lua_State* L)
{
	Pointer<byte*>* self = (Pointer<byte*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<byte*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushnumber(L, (lua_Number)**self->reference);
	return 1;
}

static int tolua_set_Pointer_byte___reference(lua_State* L)
{
	Pointer<byte*>* self = (Pointer<byte*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<byte*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (byte**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<byte*>");
	return 0;
}

static int tolua_function_Pointer_byte___getValue(lua_State* L)
{
	Pointer<byte*>* self = (Pointer<byte*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<byte*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	byte* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "Pointer<byte>");
	return 1;
}

static int tolua_function_Pointer_byte___setValue(lua_State* L)
{
	Pointer<byte*>* self = (Pointer<byte*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<byte*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((byte*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<byte>"));
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

static int tolua_get_Pointer_char___reference(lua_State* L)
{
	Pointer<char*>* self = (Pointer<char*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<char*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<char*>");
	return 1;
}

static int tolua_set_Pointer_char___reference(lua_State* L)
{
	Pointer<char*>* self = (Pointer<char*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<char*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (char**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<char*>");
	return 0;
}

static int tolua_function_Pointer_char___setValue(lua_State* L)
{
	Pointer<char*>* self = (Pointer<char*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<char*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(*(char**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<char*>"));
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<char*>");
	return 1;
}

static int tolua_set_Pointer_const_char___reference(lua_State* L)
{
	Pointer<const char*>* self = (Pointer<const char*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<const char*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (const char**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<char*>");
	return 0;
}

static int tolua_get_Pointer_double__reference(lua_State* L)
{
	Pointer<double>* self = (Pointer<double>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<double>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushnumber(L, (lua_Number)*self->reference);
	return 1;
}

static int tolua_set_Pointer_double__reference(lua_State* L)
{
	Pointer<double>* self = (Pointer<double>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<double>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (double*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<double>");
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
	self->setValue(tolua_function_tonumber(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_float__reference(lua_State* L)
{
	Pointer<float>* self = (Pointer<float>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<float>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushnumber(L, (lua_Number)*self->reference);
	return 1;
}

static int tolua_set_Pointer_float__reference(lua_State* L)
{
	Pointer<float>* self = (Pointer<float>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<float>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (float*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<float>");
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
	self->setValue(tolua_function_tonumber(L, 2, "setValue"));
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

static int tolua_get_Pointer_intptr_t__reference(lua_State* L)
{
	Pointer<intptr_t>* self = (Pointer<intptr_t>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<intptr_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushnumber(L, (lua_Number)*self->reference);
	return 1;
}

static int tolua_set_Pointer_intptr_t__reference(lua_State* L)
{
	Pointer<intptr_t>* self = (Pointer<intptr_t>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<intptr_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (intptr_t*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<intptr_t>");
	return 0;
}

static int tolua_function_Pointer_intptr_t__getValue(lua_State* L)
{
	Pointer<intptr_t>* self = (Pointer<intptr_t>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<intptr_t>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	intptr_t returnVal = self->getValue();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Pointer_intptr_t__setValue(lua_State* L)
{
	Pointer<intptr_t>* self = (Pointer<intptr_t>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<intptr_t>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_long__reference(lua_State* L)
{
	Pointer<long>* self = (Pointer<long>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushnumber(L, (lua_Number)*self->reference);
	return 1;
}

static int tolua_set_Pointer_long__reference(lua_State* L)
{
	Pointer<long>* self = (Pointer<long>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (long*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<long>");
	return 0;
}

static int tolua_function_Pointer_long__getValue(lua_State* L)
{
	Pointer<long>* self = (Pointer<long>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	long returnVal = self->getValue();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Pointer_long__setValue(lua_State* L)
{
	Pointer<long>* self = (Pointer<long>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_long___reference(lua_State* L)
{
	Pointer<long*>* self = (Pointer<long*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushnumber(L, (lua_Number)**self->reference);
	return 1;
}

static int tolua_set_Pointer_long___reference(lua_State* L)
{
	Pointer<long*>* self = (Pointer<long*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (long**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<long*>");
	return 0;
}

static int tolua_function_Pointer_long___getValue(lua_State* L)
{
	Pointer<long*>* self = (Pointer<long*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	long* returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "Pointer<long>");
	return 1;
}

static int tolua_function_Pointer_long___setValue(lua_State* L)
{
	Pointer<long*>* self = (Pointer<long*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<long*>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((long*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<long>"));
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

static int tolua_get_Pointer_short__reference(lua_State* L)
{
	Pointer<short>* self = (Pointer<short>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<short>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushnumber(L, (lua_Number)*self->reference);
	return 1;
}

static int tolua_set_Pointer_short__reference(lua_State* L)
{
	Pointer<short>* self = (Pointer<short>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<short>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (short*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<short>");
	return 0;
}

static int tolua_function_Pointer_short__getValue(lua_State* L)
{
	Pointer<short>* self = (Pointer<short>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<short>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	short returnVal = self->getValue();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Pointer_short__setValue(lua_State* L)
{
	Pointer<short>* self = (Pointer<short>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<short>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_size_t__reference(lua_State* L)
{
	Pointer<size_t>* self = (Pointer<size_t>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<size_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushnumber(L, (lua_Number)*self->reference);
	return 1;
}

static int tolua_set_Pointer_size_t__reference(lua_State* L)
{
	Pointer<size_t>* self = (Pointer<size_t>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<size_t>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (size_t*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<size_t>");
	return 0;
}

static int tolua_function_Pointer_size_t__getValue(lua_State* L)
{
	Pointer<size_t>* self = (Pointer<size_t>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<size_t>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	size_t returnVal = self->getValue();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Pointer_size_t__setValue(lua_State* L)
{
	Pointer<size_t>* self = (Pointer<size_t>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<size_t>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_uint__reference(lua_State* L)
{
	Pointer<uint>* self = (Pointer<uint>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<uint>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushnumber(L, (lua_Number)*self->reference);
	return 1;
}

static int tolua_set_Pointer_uint__reference(lua_State* L)
{
	Pointer<uint>* self = (Pointer<uint>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<uint>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (uint*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<uint>");
	return 0;
}

static int tolua_function_Pointer_uint__getValue(lua_State* L)
{
	Pointer<uint>* self = (Pointer<uint>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<uint>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	uint returnVal = self->getValue();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Pointer_uint__setValue(lua_State* L)
{
	Pointer<uint>* self = (Pointer<uint>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<uint>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_ushort__reference(lua_State* L)
{
	Pointer<ushort>* self = (Pointer<ushort>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<ushort>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushnumber(L, (lua_Number)*self->reference);
	return 1;
}

static int tolua_set_Pointer_ushort__reference(lua_State* L)
{
	Pointer<ushort>* self = (Pointer<ushort>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<ushort>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (ushort*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<ushort>");
	return 0;
}

static int tolua_function_Pointer_ushort__getValue(lua_State* L)
{
	Pointer<ushort>* self = (Pointer<ushort>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<ushort>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	ushort returnVal = self->getValue();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Pointer_ushort__setValue(lua_State* L)
{
	Pointer<ushort>* self = (Pointer<ushort>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<ushort>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue(tolua_function_tointeger(L, 2, "setValue"));
	return 0;
}

static int tolua_get_Pointer_CharString___reference(lua_State* L)
{
	Pointer<CharString*>* self = (Pointer<CharString*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CharString*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	tolua_pushusertype(L, (void*)self->reference, "Pointer<char**>");
	return 1;
}

static int tolua_set_Pointer_CharString___reference(lua_State* L)
{
	Pointer<CharString*>* self = (Pointer<CharString*>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CharString*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CharString**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<char**>");
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CGameArea**>");
	return 1;
}

static int tolua_set_Pointer_CGameArea____reference(lua_State* L)
{
	Pointer<CGameArea**>* self = (Pointer<CGameArea**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameArea**>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CGameArea***)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameArea**>");
	return 0;
}

static int tolua_function_Pointer_CGameArea____getValue(lua_State* L)
{
	Pointer<CGameArea**>* self = (Pointer<CGameArea**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameArea**>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CGameArea** returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "Pointer<CGameArea*>");
	return 1;
}

static int tolua_function_Pointer_CGameArea____setValue(lua_State* L)
{
	Pointer<CGameArea**>* self = (Pointer<CGameArea**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CGameArea**>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CGameArea**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CGameArea*>"));
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
	tolua_pushusertype(L, (void*)self->reference, "Pointer<CProjectileUnknownPST2**>");
	return 1;
}

static int tolua_set_Pointer_CProjectileUnknownPST2____reference(lua_State* L)
{
	Pointer<CProjectileUnknownPST2**>* self = (Pointer<CProjectileUnknownPST2**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST2**>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'reference'", NULL);
	self->reference = (CProjectileUnknownPST2***)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CProjectileUnknownPST2**>");
	return 0;
}

static int tolua_function_Pointer_CProjectileUnknownPST2____getValue(lua_State* L)
{
	Pointer<CProjectileUnknownPST2**>* self = (Pointer<CProjectileUnknownPST2**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST2**>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getValue'", NULL);
	CProjectileUnknownPST2** returnVal = self->getValue();
	tolua_pushusertype(L, (void*)returnVal, "Pointer<CProjectileUnknownPST2*>");
	return 1;
}

static int tolua_function_Pointer_CProjectileUnknownPST2____setValue(lua_State* L)
{
	Pointer<CProjectileUnknownPST2**>* self = (Pointer<CProjectileUnknownPST2**>*)tolua_tousertype_dynamic(L, 1, 0, "Pointer<CProjectileUnknownPST2**>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setValue'", NULL);
	self->setValue((CProjectileUnknownPST2**)tolua_tousertype_dynamic(L, 2, 0, "Pointer<CProjectileUnknownPST2*>"));
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

static int tolua_function_CharString_getChar(lua_State* L)
{
	CharString* self = (CharString*)tolua_tousertype_dynamic(L, 1, 0, "CharString");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getChar'", NULL);
	char returnVal = self->getChar(tolua_function_tointeger(L, 2, "getChar"));
	lua_pushlstring(L, (const char*)&returnVal, 1);
	return 1;
}

static int tolua_function_CharString_setChar(lua_State* L)
{
	CharString* self = (CharString*)tolua_tousertype_dynamic(L, 1, 0, "CharString");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setChar'", NULL);
	self->setChar(tolua_function_tointeger(L, 2, "setChar"), tolua_function_tochar(L, 3, "setChar"));
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
	self->setL(tolua_function_tostring(L, 2, "setL"), tolua_function_tointeger(L, 3, "setL"));
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
	self->writeL(tolua_function_tostring(L, 2, "writeL"), tolua_function_tointeger(L, 3, "writeL"));
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
	self->pointTo(tolua_function_tointeger(L, 2, "pointTo"));
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
	self->getL(L, tolua_function_tointeger(L, 2, "getL"));
	return 1;
}

static int tolua_function_CharString_free(lua_State* L)
{
	CharString* self = (CharString*)tolua_tousertype_dynamic(L, 1, 0, "CharString");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'free'", NULL);
	self->free();
	return 0;
}

static int tolua_function_CString_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CString>");
	return 1;
}

static int tolua_get_CString_m_pchData(lua_State* L)
{
	CString* self = (CString*)tolua_tousertype_dynamic(L, 1, 0, "CString");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pchData'", NULL);
	tolua_pushusertype(L, (void*)&self->m_pchData, "CharString");
	return 1;
}

static int tolua_function_CObject_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CObject>");
	return 1;
}

static int tolua_function_CObject_virtual_Destruct(lua_State* L)
{
	CObject* self = (CObject*)tolua_tousertype_dynamic(L, 1, 0, "CObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_Destruct'", NULL);
	self->virtual_Destruct();
	return 0;
}

static int tolua_function_CObject__vtbl_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CObject::vtbl>");
	return 1;
}

static int tolua_get_CObject__vtbl_Destruct(lua_State* L)
{
	return 1;
}

static int tolua_set_CObject__vtbl_Destruct(lua_State* L)
{
	return 0;
}

static int tolua_function_CTypedPtrList_CPtrList_long__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CTypedPtrList<CPtrList,long>>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pNodeHead, "Pointer<CTypedPtrList<CPtrList,long>::CNode*>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pNodeTail, "Pointer<CTypedPtrList<CPtrList,long>::CNode*>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_long__m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nCount);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_long__m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	self->m_nCount = tolua_setter_tointeger(L, "m_nCount");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_long__reference_m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nCount, "Pointer<int>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pNodeFree, "Pointer<CTypedPtrList<CPtrList,long>::CNode*>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_long__m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertype(L, (void*)self->m_pBlocks, "void");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_long__m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	self->m_pBlocks = (void*)tolua_tousertype_dynamic(L, 2, 0, "void");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_long__reference_m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_pBlocks, "Pointer<void*>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_long__m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nBlockSize);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_long__m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	self->m_nBlockSize = tolua_setter_tointeger(L, "m_nBlockSize");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_long__reference_m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,long>* self = (CTypedPtrList<CPtrList,long>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nBlockSize, "Pointer<int>");
	return 1;
}

static int tolua_function_CTypedPtrList_CPtrList_long___CNode_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CTypedPtrList<CPtrList,long>::CNode>");
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
	tolua_pushusertypepointer(L, (void*)&self->pNext, "Pointer<CTypedPtrList<CPtrList,long>::CNode*>");
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
	tolua_pushusertypepointer(L, (void*)&self->pPrev, "Pointer<CTypedPtrList<CPtrList,long>::CNode*>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_long___CNode_data(lua_State* L)
{
	CTypedPtrList<CPtrList,long>::CNode* self = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	tolua_pushnumber(L, (lua_Number)self->data);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_long___CNode_data(lua_State* L)
{
	CTypedPtrList<CPtrList,long>::CNode* self = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	self->data = tolua_setter_tointeger(L, "data");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_long___CNode_reference_data(lua_State* L)
{
	CTypedPtrList<CPtrList,long>::CNode* self = (CTypedPtrList<CPtrList,long>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,long>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->data, "Pointer<long>");
	return 1;
}

static int tolua_function_CTypedPtrList_CPtrList_int___getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CTypedPtrList<CPtrList,int*>>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pNodeHead, "Pointer<CTypedPtrList<CPtrList,int*>::CNode*>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pNodeTail, "Pointer<CTypedPtrList<CPtrList,int*>::CNode*>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int___m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nCount);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int___m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	self->m_nCount = tolua_setter_tointeger(L, "m_nCount");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int___reference_m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nCount, "Pointer<int>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pNodeFree, "Pointer<CTypedPtrList<CPtrList,int*>::CNode*>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int___m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertype(L, (void*)self->m_pBlocks, "void");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int___m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	self->m_pBlocks = (void*)tolua_tousertype_dynamic(L, 2, 0, "void");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int___reference_m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_pBlocks, "Pointer<void*>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int___m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nBlockSize);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int___m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	self->m_nBlockSize = tolua_setter_tointeger(L, "m_nBlockSize");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int___reference_m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>* self = (CTypedPtrList<CPtrList,int*>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nBlockSize, "Pointer<int>");
	return 1;
}

static int tolua_function_CTypedPtrList_CPtrList_int____CNode_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CTypedPtrList<CPtrList,int*>::CNode>");
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
	tolua_pushusertypepointer(L, (void*)&self->pNext, "Pointer<CTypedPtrList<CPtrList,int*>::CNode*>");
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
	tolua_pushusertypepointer(L, (void*)&self->pPrev, "Pointer<CTypedPtrList<CPtrList,int*>::CNode*>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int____CNode_data(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>::CNode* self = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	tolua_pushnumber(L, (lua_Number)*self->data);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int____CNode_data(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>::CNode* self = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	self->data = (int*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<int>");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int____CNode_reference_data(lua_State* L)
{
	CTypedPtrList<CPtrList,int*>::CNode* self = (CTypedPtrList<CPtrList,int*>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int*>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->data, "Pointer<int*>");
	return 1;
}

static int tolua_function_CTypedPtrList_CPtrList_int__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CTypedPtrList<CPtrList,int>>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pNodeHead, "Pointer<CTypedPtrList<CPtrList,int>::CNode*>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pNodeTail, "Pointer<CTypedPtrList<CPtrList,int>::CNode*>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int__m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nCount);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int__m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	self->m_nCount = tolua_setter_tointeger(L, "m_nCount");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int__reference_m_nCount(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCount'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nCount, "Pointer<int>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pNodeFree, "Pointer<CTypedPtrList<CPtrList,int>::CNode*>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int__m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertype(L, (void*)self->m_pBlocks, "void");
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int__m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	self->m_pBlocks = (void*)tolua_tousertype_dynamic(L, 2, 0, "void");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int__reference_m_pBlocks(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pBlocks'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_pBlocks, "Pointer<void*>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int__m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nBlockSize);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int__m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	self->m_nBlockSize = tolua_setter_tointeger(L, "m_nBlockSize");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int__reference_m_nBlockSize(lua_State* L)
{
	CTypedPtrList<CPtrList,int>* self = (CTypedPtrList<CPtrList,int>*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nBlockSize'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nBlockSize, "Pointer<int>");
	return 1;
}

static int tolua_function_CTypedPtrList_CPtrList_int___CNode_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CTypedPtrList<CPtrList,int>::CNode>");
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
	tolua_pushusertypepointer(L, (void*)&self->pNext, "Pointer<CTypedPtrList<CPtrList,int>::CNode*>");
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
	tolua_pushusertypepointer(L, (void*)&self->pPrev, "Pointer<CTypedPtrList<CPtrList,int>::CNode*>");
	return 1;
}

static int tolua_get_CTypedPtrList_CPtrList_int___CNode_data(lua_State* L)
{
	CTypedPtrList<CPtrList,int>::CNode* self = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	tolua_pushnumber(L, (lua_Number)self->data);
	return 1;
}

static int tolua_set_CTypedPtrList_CPtrList_int___CNode_data(lua_State* L)
{
	CTypedPtrList<CPtrList,int>::CNode* self = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	self->data = tolua_setter_tointeger(L, "data");
	return 0;
}

static int tolua_get_CTypedPtrList_CPtrList_int___CNode_reference_data(lua_State* L)
{
	CTypedPtrList<CPtrList,int>::CNode* self = (CTypedPtrList<CPtrList,int>::CNode*)tolua_tousertype_dynamic(L, 1, 0, "CTypedPtrList<CPtrList,int>::CNode");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'data'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->data, "Pointer<int>");
	return 1;
}

static int tolua_function_CAreaTintOverride_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CAreaTintOverride>");
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
	tolua_pushusertypepointer(L, (void*)&self->pInfinity, "Pointer<CInfinity*>");
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
	tolua_pushusertypepointer(L, (void*)&self->pVidMode, "Pointer<CVidMode*>");
	return 1;
}

static int tolua_get_CAreaTintOverride_nMode1(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nMode1'", NULL);
	tolua_pushnumber(L, (lua_Number)self->nMode1);
	return 1;
}

static int tolua_set_CAreaTintOverride_nMode1(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nMode1'", NULL);
	self->nMode1 = tolua_setter_tointeger(L, "nMode1");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_nMode1(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nMode1'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->nMode1, "Pointer<byte>");
	return 1;
}

static int tolua_get_CAreaTintOverride_nMode2(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nMode2'", NULL);
	tolua_pushnumber(L, (lua_Number)self->nMode2);
	return 1;
}

static int tolua_set_CAreaTintOverride_nMode2(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nMode2'", NULL);
	self->nMode2 = tolua_setter_tointeger(L, "nMode2");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_nMode2(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nMode2'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->nMode2, "Pointer<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_nDuration(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDuration'", NULL);
	tolua_pushnumber(L, (lua_Number)self->nDuration);
	return 1;
}

static int tolua_set_CAreaTintOverride_nDuration(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDuration'", NULL);
	self->nDuration = tolua_setter_tointeger(L, "nDuration");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_nDuration(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDuration'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->nDuration, "Pointer<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_unknownTint1(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint1'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unknownTint1);
	return 1;
}

static int tolua_set_CAreaTintOverride_unknownTint1(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint1'", NULL);
	self->unknownTint1 = tolua_setter_tointeger(L, "unknownTint1");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_unknownTint1(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint1'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknownTint1, "Pointer<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_unknownTint1Red(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint1Red'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unknownTint1Red);
	return 1;
}

static int tolua_set_CAreaTintOverride_unknownTint1Red(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint1Red'", NULL);
	self->unknownTint1Red = tolua_setter_tointeger(L, "unknownTint1Red");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_unknownTint1Red(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint1Red'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknownTint1Red, "Pointer<byte>");
	return 1;
}

static int tolua_get_CAreaTintOverride_unknownTint1Green(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint1Green'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unknownTint1Green);
	return 1;
}

static int tolua_set_CAreaTintOverride_unknownTint1Green(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint1Green'", NULL);
	self->unknownTint1Green = tolua_setter_tointeger(L, "unknownTint1Green");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_unknownTint1Green(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint1Green'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknownTint1Green, "Pointer<byte>");
	return 1;
}

static int tolua_get_CAreaTintOverride_unknownTint1Blue(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint1Blue'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unknownTint1Blue);
	return 1;
}

static int tolua_set_CAreaTintOverride_unknownTint1Blue(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint1Blue'", NULL);
	self->unknownTint1Blue = tolua_setter_tointeger(L, "unknownTint1Blue");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_unknownTint1Blue(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint1Blue'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknownTint1Blue, "Pointer<byte>");
	return 1;
}

static int tolua_get_CAreaTintOverride_unknownTint2(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint2'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unknownTint2);
	return 1;
}

static int tolua_set_CAreaTintOverride_unknownTint2(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint2'", NULL);
	self->unknownTint2 = tolua_setter_tointeger(L, "unknownTint2");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_unknownTint2(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint2'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknownTint2, "Pointer<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_unknownTint2Red(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint2Red'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unknownTint2Red);
	return 1;
}

static int tolua_set_CAreaTintOverride_unknownTint2Red(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint2Red'", NULL);
	self->unknownTint2Red = tolua_setter_tointeger(L, "unknownTint2Red");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_unknownTint2Red(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint2Red'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknownTint2Red, "Pointer<byte>");
	return 1;
}

static int tolua_get_CAreaTintOverride_unknownTint2Green(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint2Green'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unknownTint2Green);
	return 1;
}

static int tolua_set_CAreaTintOverride_unknownTint2Green(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint2Green'", NULL);
	self->unknownTint2Green = tolua_setter_tointeger(L, "unknownTint2Green");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_unknownTint2Green(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint2Green'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknownTint2Green, "Pointer<byte>");
	return 1;
}

static int tolua_get_CAreaTintOverride_unknownTint2Blue(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint2Blue'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unknownTint2Blue);
	return 1;
}

static int tolua_set_CAreaTintOverride_unknownTint2Blue(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint2Blue'", NULL);
	self->unknownTint2Blue = tolua_setter_tointeger(L, "unknownTint2Blue");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_unknownTint2Blue(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint2Blue'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknownTint2Blue, "Pointer<byte>");
	return 1;
}

static int tolua_get_CAreaTintOverride_unknownTint3(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint3'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unknownTint3);
	return 1;
}

static int tolua_set_CAreaTintOverride_unknownTint3(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint3'", NULL);
	self->unknownTint3 = tolua_setter_tointeger(L, "unknownTint3");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_unknownTint3(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint3'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknownTint3, "Pointer<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_unknownTint4(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint4'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unknownTint4);
	return 1;
}

static int tolua_set_CAreaTintOverride_unknownTint4(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint4'", NULL);
	self->unknownTint4 = tolua_setter_tointeger(L, "unknownTint4");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_unknownTint4(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint4'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknownTint4, "Pointer<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_unknownTint5(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint5'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unknownTint5);
	return 1;
}

static int tolua_set_CAreaTintOverride_unknownTint5(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint5'", NULL);
	self->unknownTint5 = tolua_setter_tointeger(L, "unknownTint5");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_unknownTint5(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknownTint5'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknownTint5, "Pointer<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_nStartingGlobalLighting(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nStartingGlobalLighting'", NULL);
	tolua_pushnumber(L, (lua_Number)self->nStartingGlobalLighting);
	return 1;
}

static int tolua_set_CAreaTintOverride_nStartingGlobalLighting(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nStartingGlobalLighting'", NULL);
	self->nStartingGlobalLighting = tolua_setter_tointeger(L, "nStartingGlobalLighting");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_nStartingGlobalLighting(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nStartingGlobalLighting'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->nStartingGlobalLighting, "Pointer<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_globaTint(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'globaTint'", NULL);
	tolua_pushnumber(L, (lua_Number)self->globaTint);
	return 1;
}

static int tolua_set_CAreaTintOverride_globaTint(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'globaTint'", NULL);
	self->globaTint = tolua_setter_tointeger(L, "globaTint");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_globaTint(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'globaTint'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->globaTint, "Pointer<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_globalTintRed(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'globalTintRed'", NULL);
	tolua_pushnumber(L, (lua_Number)self->globalTintRed);
	return 1;
}

static int tolua_set_CAreaTintOverride_globalTintRed(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'globalTintRed'", NULL);
	self->globalTintRed = tolua_setter_tointeger(L, "globalTintRed");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_globalTintRed(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'globalTintRed'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->globalTintRed, "Pointer<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_globalTintGreen(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'globalTintGreen'", NULL);
	tolua_pushnumber(L, (lua_Number)self->globalTintGreen);
	return 1;
}

static int tolua_set_CAreaTintOverride_globalTintGreen(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'globalTintGreen'", NULL);
	self->globalTintGreen = tolua_setter_tointeger(L, "globalTintGreen");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_globalTintGreen(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'globalTintGreen'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->globalTintGreen, "Pointer<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_globalTintBlue(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'globalTintBlue'", NULL);
	tolua_pushnumber(L, (lua_Number)self->globalTintBlue);
	return 1;
}

static int tolua_set_CAreaTintOverride_globalTintBlue(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'globalTintBlue'", NULL);
	self->globalTintBlue = tolua_setter_tointeger(L, "globalTintBlue");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_globalTintBlue(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'globalTintBlue'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->globalTintBlue, "Pointer<uint>");
	return 1;
}

static int tolua_get_CAreaTintOverride_targetType(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'targetType'", NULL);
	tolua_pushnumber(L, (lua_Number)self->targetType);
	return 1;
}

static int tolua_set_CAreaTintOverride_targetType(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'targetType'", NULL);
	self->targetType = tolua_setter_tointeger(L, "targetType");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_targetType(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'targetType'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->targetType, "Pointer<byte>");
	return 1;
}

static int tolua_get_CAreaTintOverride_nSourceId(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nSourceId'", NULL);
	tolua_pushnumber(L, (lua_Number)self->nSourceId);
	return 1;
}

static int tolua_set_CAreaTintOverride_nSourceId(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nSourceId'", NULL);
	self->nSourceId = tolua_setter_tointeger(L, "nSourceId");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_nSourceId(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nSourceId'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->nSourceId, "Pointer<int>");
	return 1;
}

static int tolua_get_CAreaTintOverride_unknown(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unknown);
	return 1;
}

static int tolua_set_CAreaTintOverride_unknown(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown'", NULL);
	self->unknown = tolua_setter_tointeger(L, "unknown");
	return 0;
}

static int tolua_get_CAreaTintOverride_reference_unknown(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknown, "Pointer<int>");
	return 1;
}

static int tolua_get_CAreaTintOverride_spritesWithSuppressedTintsList(lua_State* L)
{
	CAreaTintOverride* self = (CAreaTintOverride*)tolua_tousertype_dynamic(L, 1, 0, "CAreaTintOverride");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'spritesWithSuppressedTintsList'", NULL);
	tolua_pushusertype(L, (void*)&self->spritesWithSuppressedTintsList, "CTypedPtrList<CPtrList,int*>");
	return 1;
}

static int tolua_function_CGameArea_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameArea>");
	return 1;
}

static int tolua_get_CGameArea_m_nCharacters(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCharacters'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nCharacters);
	return 1;
}

static int tolua_set_CGameArea_m_nCharacters(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCharacters'", NULL);
	self->m_nCharacters = tolua_setter_tointeger(L, "m_nCharacters");
	return 0;
}

static int tolua_get_CGameArea_reference_m_nCharacters(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCharacters'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nCharacters, "Pointer<byte>");
	return 1;
}

static int tolua_get_CGameArea_m_nInfravision(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nInfravision'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nInfravision);
	return 1;
}

static int tolua_set_CGameArea_m_nInfravision(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nInfravision'", NULL);
	self->m_nInfravision = tolua_setter_tointeger(L, "m_nInfravision");
	return 0;
}

static int tolua_get_CGameArea_reference_m_nInfravision(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nInfravision'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nInfravision, "Pointer<byte>");
	return 1;
}

static int tolua_get_CGameArea_m_bAreaLoaded(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bAreaLoaded'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_bAreaLoaded);
	return 1;
}

static int tolua_set_CGameArea_m_bAreaLoaded(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bAreaLoaded'", NULL);
	self->m_bAreaLoaded = tolua_setter_tointeger(L, "m_bAreaLoaded");
	return 0;
}

static int tolua_get_CGameArea_reference_m_bAreaLoaded(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bAreaLoaded'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_bAreaLoaded, "Pointer<byte>");
	return 1;
}

static int tolua_get_CGameArea_m_iPicked(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iPicked'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_iPicked);
	return 1;
}

static int tolua_set_CGameArea_m_iPicked(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iPicked'", NULL);
	self->m_iPicked = tolua_setter_tointeger(L, "m_iPicked");
	return 0;
}

static int tolua_get_CGameArea_reference_m_iPicked(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iPicked'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_iPicked, "Pointer<int>");
	return 1;
}

static int tolua_get_CGameArea_m_bPicked(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bPicked'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_bPicked);
	return 1;
}

static int tolua_set_CGameArea_m_bPicked(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bPicked'", NULL);
	self->m_bPicked = tolua_setter_tointeger(L, "m_bPicked");
	return 0;
}

static int tolua_get_CGameArea_reference_m_bPicked(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bPicked'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_bPicked, "Pointer<int>");
	return 1;
}

static int tolua_get_CGameArea_m_nToolTip(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nToolTip'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nToolTip);
	return 1;
}

static int tolua_set_CGameArea_m_nToolTip(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nToolTip'", NULL);
	self->m_nToolTip = tolua_setter_tointeger(L, "m_nToolTip");
	return 0;
}

static int tolua_get_CGameArea_reference_m_nToolTip(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nToolTip'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nToolTip, "Pointer<int>");
	return 1;
}

static int tolua_get_CGameArea_m_firstRender(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_firstRender'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_firstRender);
	return 1;
}

static int tolua_set_CGameArea_m_firstRender(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_firstRender'", NULL);
	self->m_firstRender = tolua_setter_tointeger(L, "m_firstRender");
	return 0;
}

static int tolua_get_CGameArea_reference_m_firstRender(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_firstRender'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_firstRender, "Pointer<byte>");
	return 1;
}

static int tolua_get_CGameArea_m_nAIIndex(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nAIIndex'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nAIIndex);
	return 1;
}

static int tolua_set_CGameArea_m_nAIIndex(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nAIIndex'", NULL);
	self->m_nAIIndex = tolua_setter_tointeger(L, "m_nAIIndex");
	return 0;
}

static int tolua_get_CGameArea_reference_m_nAIIndex(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nAIIndex'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nAIIndex, "Pointer<long>");
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

static int tolua_get_CGameArea_mpSpawner(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'mpSpawner'", NULL);
	tolua_pushusertype(L, (void*)self->mpSpawner, "void");
	return 1;
}

static int tolua_set_CGameArea_mpSpawner(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'mpSpawner'", NULL);
	self->mpSpawner = (void*)tolua_tousertype_dynamic(L, 2, 0, "void");
	return 0;
}

static int tolua_get_CGameArea_reference_mpSpawner(lua_State* L)
{
	CGameArea* self = (CGameArea*)tolua_tousertype_dynamic(L, 1, 0, "CGameArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'mpSpawner'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->mpSpawner, "Pointer<void*>");
	return 1;
}

static int tolua_function_Array_uchar_8__getReference(lua_State* L)
{
	Array<uchar,8>* self = (Array<uchar,8>*)tolua_tousertype_dynamic(L, 1, 0, "Array<uchar,8>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getReference'", NULL);
	uchar* returnVal = self->getReference(tolua_function_tointeger(L, 2, "getReference"));
	tolua_pushusertype(L, (void*)returnVal, "uchar");
	return 1;
}

static int tolua_function_Array_uchar_8__set(lua_State* L)
{
	Array<uchar,8>* self = (Array<uchar,8>*)tolua_tousertype_dynamic(L, 1, 0, "Array<uchar,8>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tointeger(L, 2, "set"), *(uchar*)tolua_tousertype_dynamic(L, 3, 0, "uchar"));
	return 0;
}

static int tolua_function_Array_CProjectileUnknownPST2__10__get(lua_State* L)
{
	Array<CProjectileUnknownPST2*,10>* self = (Array<CProjectileUnknownPST2*,10>*)tolua_tousertype_dynamic(L, 1, 0, "Array<CProjectileUnknownPST2*,10>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'get'", NULL);
	CProjectileUnknownPST2* returnVal = self->get(tolua_function_tointeger(L, 2, "get"));
	tolua_pushusertype(L, (void*)returnVal, "CProjectileUnknownPST2");
	return 1;
}

static int tolua_function_Array_CProjectileUnknownPST2__10__getReference(lua_State* L)
{
	Array<CProjectileUnknownPST2*,10>* self = (Array<CProjectileUnknownPST2*,10>*)tolua_tousertype_dynamic(L, 1, 0, "Array<CProjectileUnknownPST2*,10>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getReference'", NULL);
	CProjectileUnknownPST2** returnVal = self->getReference(tolua_function_tointeger(L, 2, "getReference"));
	tolua_pushusertype(L, (void*)returnVal, "Pointer<CProjectileUnknownPST2*>");
	return 1;
}

static int tolua_function_Array_CProjectileUnknownPST2__10__set(lua_State* L)
{
	Array<CProjectileUnknownPST2*,10>* self = (Array<CProjectileUnknownPST2*,10>*)tolua_tousertype_dynamic(L, 1, 0, "Array<CProjectileUnknownPST2*,10>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tointeger(L, 2, "set"), (CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 3, 0, "CProjectileUnknownPST2"));
	return 0;
}

static int tolua_function_Array_ulong_15__getReference(lua_State* L)
{
	Array<ulong,15>* self = (Array<ulong,15>*)tolua_tousertype_dynamic(L, 1, 0, "Array<ulong,15>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getReference'", NULL);
	ulong* returnVal = self->getReference(tolua_function_tointeger(L, 2, "getReference"));
	tolua_pushusertype(L, (void*)returnVal, "ulong");
	return 1;
}

static int tolua_function_Array_ulong_15__set(lua_State* L)
{
	Array<ulong,15>* self = (Array<ulong,15>*)tolua_tousertype_dynamic(L, 1, 0, "Array<ulong,15>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tointeger(L, 2, "set"), *(ulong*)tolua_tousertype_dynamic(L, 3, 0, "ulong"));
	return 0;
}

static int tolua_function_Array_char_32__get(lua_State* L)
{
	Array<char,32>* self = (Array<char,32>*)tolua_tousertype_dynamic(L, 1, 0, "Array<char,32>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'get'", NULL);
	char returnVal = self->get(tolua_function_tointeger(L, 2, "get"));
	lua_pushlstring(L, (const char*)&returnVal, 1);
	return 1;
}

static int tolua_function_Array_char_32__set(lua_State* L)
{
	Array<char,32>* self = (Array<char,32>*)tolua_tousertype_dynamic(L, 1, 0, "Array<char,32>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tointeger(L, 2, "set"), tolua_function_tochar(L, 3, "set"));
	return 0;
}

static int tolua_function_Array_CGameArea__12__get(lua_State* L)
{
	Array<CGameArea*,12>* self = (Array<CGameArea*,12>*)tolua_tousertype_dynamic(L, 1, 0, "Array<CGameArea*,12>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'get'", NULL);
	CGameArea* returnVal = self->get(tolua_function_tointeger(L, 2, "get"));
	tolua_pushusertype(L, (void*)returnVal, "CGameArea");
	return 1;
}

static int tolua_function_Array_CGameArea__12__getReference(lua_State* L)
{
	Array<CGameArea*,12>* self = (Array<CGameArea*,12>*)tolua_tousertype_dynamic(L, 1, 0, "Array<CGameArea*,12>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getReference'", NULL);
	CGameArea** returnVal = self->getReference(tolua_function_tointeger(L, 2, "getReference"));
	tolua_pushusertype(L, (void*)returnVal, "Pointer<CGameArea*>");
	return 1;
}

static int tolua_function_Array_CGameArea__12__set(lua_State* L)
{
	Array<CGameArea*,12>* self = (Array<CGameArea*,12>*)tolua_tousertype_dynamic(L, 1, 0, "Array<CGameArea*,12>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tointeger(L, 2, "set"), (CGameArea*)tolua_tousertype_dynamic(L, 3, 0, "CGameArea"));
	return 0;
}

static int tolua_function_Array_long_6__get(lua_State* L)
{
	Array<long,6>* self = (Array<long,6>*)tolua_tousertype_dynamic(L, 1, 0, "Array<long,6>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'get'", NULL);
	long returnVal = self->get(tolua_function_tointeger(L, 2, "get"));
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Array_long_6__getReference(lua_State* L)
{
	Array<long,6>* self = (Array<long,6>*)tolua_tousertype_dynamic(L, 1, 0, "Array<long,6>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getReference'", NULL);
	long* returnVal = self->getReference(tolua_function_tointeger(L, 2, "getReference"));
	tolua_pushusertype(L, (void*)returnVal, "Pointer<long>");
	return 1;
}

static int tolua_function_Array_long_6__set(lua_State* L)
{
	Array<long,6>* self = (Array<long,6>*)tolua_tousertype_dynamic(L, 1, 0, "Array<long,6>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tointeger(L, 2, "set"), tolua_function_tointeger(L, 3, "set"));
	return 0;
}

static int tolua_function_Array_ulong_8__getReference(lua_State* L)
{
	Array<ulong,8>* self = (Array<ulong,8>*)tolua_tousertype_dynamic(L, 1, 0, "Array<ulong,8>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getReference'", NULL);
	ulong* returnVal = self->getReference(tolua_function_tointeger(L, 2, "getReference"));
	tolua_pushusertype(L, (void*)returnVal, "ulong");
	return 1;
}

static int tolua_function_Array_ulong_8__set(lua_State* L)
{
	Array<ulong,8>* self = (Array<ulong,8>*)tolua_tousertype_dynamic(L, 1, 0, "Array<ulong,8>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tointeger(L, 2, "set"), *(ulong*)tolua_tousertype_dynamic(L, 3, 0, "ulong"));
	return 0;
}

static int tolua_function_Array_byte_5__get(lua_State* L)
{
	Array<byte,5>* self = (Array<byte,5>*)tolua_tousertype_dynamic(L, 1, 0, "Array<byte,5>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'get'", NULL);
	byte returnVal = self->get(tolua_function_tointeger(L, 2, "get"));
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_Array_byte_5__getReference(lua_State* L)
{
	Array<byte,5>* self = (Array<byte,5>*)tolua_tousertype_dynamic(L, 1, 0, "Array<byte,5>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getReference'", NULL);
	byte* returnVal = self->getReference(tolua_function_tointeger(L, 2, "getReference"));
	tolua_pushusertype(L, (void*)returnVal, "Pointer<byte>");
	return 1;
}

static int tolua_function_Array_byte_5__set(lua_State* L)
{
	Array<byte,5>* self = (Array<byte,5>*)tolua_tousertype_dynamic(L, 1, 0, "Array<byte,5>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'set'", NULL);
	self->set(tolua_function_tointeger(L, 2, "set"), tolua_function_tointeger(L, 3, "set"));
	return 0;
}

static int tolua_function_LCharString_32__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<LCharString<32>>");
	return 1;
}

static int tolua_function_LCharString_32__getChar(lua_State* L)
{
	LCharString<32>* self = (LCharString<32>*)tolua_tousertype_dynamic(L, 1, 0, "LCharString<32>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getChar'", NULL);
	char returnVal = self->getChar(tolua_function_tointeger(L, 2, "getChar"));
	lua_pushlstring(L, (const char*)&returnVal, 1);
	return 1;
}

static int tolua_function_LCharString_32__setChar(lua_State* L)
{
	LCharString<32>* self = (LCharString<32>*)tolua_tousertype_dynamic(L, 1, 0, "LCharString<32>");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'setChar'", NULL);
	self->setChar(tolua_function_tointeger(L, 2, "setChar"), tolua_function_tochar(L, 3, "setChar"));
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

static int tolua_function_CResRef_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CResRef>");
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

static int tolua_function_Item_effect_st_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<Item_effect_st>");
	return 1;
}

static int tolua_get_Item_effect_st_effectID(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'effectID'", NULL);
	tolua_pushnumber(L, (lua_Number)self->effectID);
	return 1;
}

static int tolua_set_Item_effect_st_effectID(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'effectID'", NULL);
	self->effectID = tolua_setter_tointeger(L, "effectID");
	return 0;
}

static int tolua_get_Item_effect_st_reference_effectID(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'effectID'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->effectID, "Pointer<ushort>");
	return 1;
}

static int tolua_get_Item_effect_st_targetType(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'targetType'", NULL);
	tolua_pushnumber(L, (lua_Number)self->targetType);
	return 1;
}

static int tolua_set_Item_effect_st_targetType(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'targetType'", NULL);
	self->targetType = tolua_setter_tointeger(L, "targetType");
	return 0;
}

static int tolua_get_Item_effect_st_reference_targetType(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'targetType'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->targetType, "Pointer<byte>");
	return 1;
}

static int tolua_get_Item_effect_st_spellLevel(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'spellLevel'", NULL);
	tolua_pushnumber(L, (lua_Number)self->spellLevel);
	return 1;
}

static int tolua_set_Item_effect_st_spellLevel(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'spellLevel'", NULL);
	self->spellLevel = tolua_setter_tointeger(L, "spellLevel");
	return 0;
}

static int tolua_get_Item_effect_st_reference_spellLevel(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'spellLevel'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->spellLevel, "Pointer<byte>");
	return 1;
}

static int tolua_get_Item_effect_st_effectAmount(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'effectAmount'", NULL);
	tolua_pushnumber(L, (lua_Number)self->effectAmount);
	return 1;
}

static int tolua_set_Item_effect_st_effectAmount(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'effectAmount'", NULL);
	self->effectAmount = tolua_setter_tointeger(L, "effectAmount");
	return 0;
}

static int tolua_get_Item_effect_st_reference_effectAmount(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'effectAmount'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->effectAmount, "Pointer<int>");
	return 1;
}

static int tolua_get_Item_effect_st_dwFlags(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'dwFlags'", NULL);
	tolua_pushnumber(L, (lua_Number)self->dwFlags);
	return 1;
}

static int tolua_set_Item_effect_st_dwFlags(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'dwFlags'", NULL);
	self->dwFlags = tolua_setter_tointeger(L, "dwFlags");
	return 0;
}

static int tolua_get_Item_effect_st_reference_dwFlags(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'dwFlags'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->dwFlags, "Pointer<uint>");
	return 1;
}

static int tolua_get_Item_effect_st_durationType(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'durationType'", NULL);
	tolua_pushnumber(L, (lua_Number)self->durationType);
	return 1;
}

static int tolua_set_Item_effect_st_durationType(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'durationType'", NULL);
	self->durationType = tolua_setter_tointeger(L, "durationType");
	return 0;
}

static int tolua_get_Item_effect_st_reference_durationType(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'durationType'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->durationType, "Pointer<ushort>");
	return 1;
}

static int tolua_get_Item_effect_st_duration(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'duration'", NULL);
	tolua_pushnumber(L, (lua_Number)self->duration);
	return 1;
}

static int tolua_set_Item_effect_st_duration(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'duration'", NULL);
	self->duration = tolua_setter_tointeger(L, "duration");
	return 0;
}

static int tolua_get_Item_effect_st_reference_duration(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'duration'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->duration, "Pointer<uint>");
	return 1;
}

static int tolua_get_Item_effect_st_probabilityUpper(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'probabilityUpper'", NULL);
	tolua_pushnumber(L, (lua_Number)self->probabilityUpper);
	return 1;
}

static int tolua_set_Item_effect_st_probabilityUpper(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'probabilityUpper'", NULL);
	self->probabilityUpper = tolua_setter_tointeger(L, "probabilityUpper");
	return 0;
}

static int tolua_get_Item_effect_st_reference_probabilityUpper(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'probabilityUpper'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->probabilityUpper, "Pointer<byte>");
	return 1;
}

static int tolua_get_Item_effect_st_probabilityLower(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'probabilityLower'", NULL);
	tolua_pushnumber(L, (lua_Number)self->probabilityLower);
	return 1;
}

static int tolua_set_Item_effect_st_probabilityLower(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'probabilityLower'", NULL);
	self->probabilityLower = tolua_setter_tointeger(L, "probabilityLower");
	return 0;
}

static int tolua_get_Item_effect_st_reference_probabilityLower(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'probabilityLower'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->probabilityLower, "Pointer<byte>");
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
	tolua_pushnumber(L, (lua_Number)self->numDice);
	return 1;
}

static int tolua_set_Item_effect_st_numDice(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'numDice'", NULL);
	self->numDice = tolua_setter_tointeger(L, "numDice");
	return 0;
}

static int tolua_get_Item_effect_st_reference_numDice(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'numDice'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->numDice, "Pointer<uint>");
	return 1;
}

static int tolua_get_Item_effect_st_diceSize(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'diceSize'", NULL);
	tolua_pushnumber(L, (lua_Number)self->diceSize);
	return 1;
}

static int tolua_set_Item_effect_st_diceSize(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'diceSize'", NULL);
	self->diceSize = tolua_setter_tointeger(L, "diceSize");
	return 0;
}

static int tolua_get_Item_effect_st_reference_diceSize(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'diceSize'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->diceSize, "Pointer<uint>");
	return 1;
}

static int tolua_get_Item_effect_st_savingThrow(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'savingThrow'", NULL);
	tolua_pushnumber(L, (lua_Number)self->savingThrow);
	return 1;
}

static int tolua_set_Item_effect_st_savingThrow(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'savingThrow'", NULL);
	self->savingThrow = tolua_setter_tointeger(L, "savingThrow");
	return 0;
}

static int tolua_get_Item_effect_st_reference_savingThrow(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'savingThrow'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->savingThrow, "Pointer<uint>");
	return 1;
}

static int tolua_get_Item_effect_st_saveMod(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'saveMod'", NULL);
	tolua_pushnumber(L, (lua_Number)self->saveMod);
	return 1;
}

static int tolua_set_Item_effect_st_saveMod(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'saveMod'", NULL);
	self->saveMod = tolua_setter_tointeger(L, "saveMod");
	return 0;
}

static int tolua_get_Item_effect_st_reference_saveMod(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'saveMod'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->saveMod, "Pointer<int>");
	return 1;
}

static int tolua_get_Item_effect_st_special(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'special'", NULL);
	tolua_pushnumber(L, (lua_Number)self->special);
	return 1;
}

static int tolua_set_Item_effect_st_special(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'special'", NULL);
	self->special = tolua_setter_tointeger(L, "special");
	return 0;
}

static int tolua_get_Item_effect_st_reference_special(lua_State* L)
{
	Item_effect_st* self = (Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'special'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->special, "Pointer<uint>");
	return 1;
}

static int tolua_function_CResHelper_CResCell_1000__getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CResHelper<CResCell,1000>>");
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
	tolua_pushusertypepointer(L, (void*)&self->pRes, "Pointer<CResCell*>");
	return 1;
}

static int tolua_get_CResHelper_CResCell_1000__cResRef(lua_State* L)
{
	CResHelper<CResCell,1000>* self = (CResHelper<CResCell,1000>*)tolua_tousertype_dynamic(L, 1, 0, "CResHelper<CResCell,1000>");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'cResRef'", NULL);
	tolua_pushusertype(L, (void*)&self->cResRef, "CResRef");
	return 1;
}

static int tolua_function_CVidCell_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CVidCell>");
	return 1;
}

static int tolua_get_CVidCell___vftable(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable '__vftable'", NULL);
	tolua_pushusertype(L, (void*)&self->__vftable, "dword");
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
	tolua_pushnumber(L, (lua_Number)self->m_nCurrentFrame);
	return 1;
}

static int tolua_set_CVidCell_m_nCurrentFrame(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCurrentFrame'", NULL);
	self->m_nCurrentFrame = tolua_setter_tointeger(L, "m_nCurrentFrame");
	return 0;
}

static int tolua_get_CVidCell_reference_m_nCurrentFrame(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCurrentFrame'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nCurrentFrame, "Pointer<short>");
	return 1;
}

static int tolua_get_CVidCell_m_nCurrentSequence(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCurrentSequence'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nCurrentSequence);
	return 1;
}

static int tolua_set_CVidCell_m_nCurrentSequence(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCurrentSequence'", NULL);
	self->m_nCurrentSequence = tolua_setter_tointeger(L, "m_nCurrentSequence");
	return 0;
}

static int tolua_get_CVidCell_reference_m_nCurrentSequence(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCurrentSequence'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nCurrentSequence, "Pointer<ushort>");
	return 1;
}

static int tolua_get_CVidCell_m_nAnimType(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nAnimType'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nAnimType);
	return 1;
}

static int tolua_set_CVidCell_m_nAnimType(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nAnimType'", NULL);
	self->m_nAnimType = tolua_setter_tointeger(L, "m_nAnimType");
	return 0;
}

static int tolua_get_CVidCell_reference_m_nAnimType(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nAnimType'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nAnimType, "Pointer<int>");
	return 1;
}

static int tolua_get_CVidCell_m_bPaletteChanged(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bPaletteChanged'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_bPaletteChanged);
	return 1;
}

static int tolua_set_CVidCell_m_bPaletteChanged(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bPaletteChanged'", NULL);
	self->m_bPaletteChanged = tolua_setter_tointeger(L, "m_bPaletteChanged");
	return 0;
}

static int tolua_get_CVidCell_reference_m_bPaletteChanged(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bPaletteChanged'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_bPaletteChanged, "Pointer<int>");
	return 1;
}

static int tolua_get_CVidCell_m_pFrame(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pFrame'", NULL);
	tolua_pushusertype(L, (void*)self->m_pFrame, "void");
	return 1;
}

static int tolua_set_CVidCell_m_pFrame(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pFrame'", NULL);
	self->m_pFrame = (void*)tolua_tousertype_dynamic(L, 2, 0, "void");
	return 0;
}

static int tolua_get_CVidCell_reference_m_pFrame(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_pFrame'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_pFrame, "Pointer<void*>");
	return 1;
}

static int tolua_get_CVidCell_m_bShadowOn(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bShadowOn'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_bShadowOn);
	return 1;
}

static int tolua_set_CVidCell_m_bShadowOn(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bShadowOn'", NULL);
	self->m_bShadowOn = tolua_setter_tointeger(L, "m_bShadowOn");
	return 0;
}

static int tolua_get_CVidCell_reference_m_bShadowOn(lua_State* L)
{
	CVidCell* self = (CVidCell*)tolua_tousertype_dynamic(L, 1, 0, "CVidCell");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bShadowOn'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_bShadowOn, "Pointer<byte>");
	return 1;
}

static int tolua_function_CInfGame_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CInfGame>");
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
	tolua_pushnumber(L, (lua_Number)self->m_bGameLoaded);
	return 1;
}

static int tolua_set_CInfGame_m_bGameLoaded(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bGameLoaded'", NULL);
	self->m_bGameLoaded = tolua_setter_tointeger(L, "m_bGameLoaded");
	return 0;
}

static int tolua_get_CInfGame_reference_m_bGameLoaded(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bGameLoaded'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_bGameLoaded, "Pointer<int>");
	return 1;
}

static int tolua_get_CInfGame_m_bInDestroyGame(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bInDestroyGame'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_bInDestroyGame);
	return 1;
}

static int tolua_set_CInfGame_m_bInDestroyGame(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bInDestroyGame'", NULL);
	self->m_bInDestroyGame = tolua_setter_tointeger(L, "m_bInDestroyGame");
	return 0;
}

static int tolua_get_CInfGame_reference_m_bInDestroyGame(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bInDestroyGame'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_bInDestroyGame, "Pointer<byte>");
	return 1;
}

static int tolua_get_CInfGame_m_nState(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nState'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nState);
	return 1;
}

static int tolua_set_CInfGame_m_nState(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nState'", NULL);
	self->m_nState = tolua_setter_tointeger(L, "m_nState");
	return 0;
}

static int tolua_get_CInfGame_reference_m_nState(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nState'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nState, "Pointer<short>");
	return 1;
}

static int tolua_get_CInfGame_m_iconCount(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iconCount'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_iconCount);
	return 1;
}

static int tolua_set_CInfGame_m_iconCount(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iconCount'", NULL);
	self->m_iconCount = tolua_setter_tointeger(L, "m_iconCount");
	return 0;
}

static int tolua_get_CInfGame_reference_m_iconCount(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iconCount'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_iconCount, "Pointer<int>");
	return 1;
}

static int tolua_get_CInfGame_m_iconIndex(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iconIndex'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_iconIndex);
	return 1;
}

static int tolua_set_CInfGame_m_iconIndex(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iconIndex'", NULL);
	self->m_iconIndex = tolua_setter_tointeger(L, "m_iconIndex");
	return 0;
}

static int tolua_get_CInfGame_reference_m_iconIndex(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_iconIndex'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_iconIndex, "Pointer<byte>");
	return 1;
}

static int tolua_get_CInfGame_m_tempCursor(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_tempCursor'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_tempCursor);
	return 1;
}

static int tolua_set_CInfGame_m_tempCursor(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_tempCursor'", NULL);
	self->m_tempCursor = tolua_setter_tointeger(L, "m_tempCursor");
	return 0;
}

static int tolua_get_CInfGame_reference_m_tempCursor(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_tempCursor'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_tempCursor, "Pointer<byte>");
	return 1;
}

static int tolua_get_CInfGame_m_visibleArea(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_visibleArea'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_visibleArea);
	return 1;
}

static int tolua_set_CInfGame_m_visibleArea(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_visibleArea'", NULL);
	self->m_visibleArea = tolua_setter_tointeger(L, "m_visibleArea");
	return 0;
}

static int tolua_get_CInfGame_reference_m_visibleArea(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_visibleArea'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_visibleArea, "Pointer<byte>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pGameAreaMaster, "Pointer<CGameArea*>");
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
	tolua_pushnumber(L, (lua_Number)self->m_nCharacters);
	return 1;
}

static int tolua_set_CInfGame_m_nCharacters(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCharacters'", NULL);
	self->m_nCharacters = tolua_setter_tointeger(L, "m_nCharacters");
	return 0;
}

static int tolua_get_CInfGame_reference_m_nCharacters(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nCharacters'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nCharacters, "Pointer<short>");
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
	tolua_pushnumber(L, (lua_Number)self->m_searchRequestListEmpty);
	return 1;
}

static int tolua_set_CInfGame_m_searchRequestListEmpty(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_searchRequestListEmpty'", NULL);
	self->m_searchRequestListEmpty = tolua_setter_tointeger(L, "m_searchRequestListEmpty");
	return 0;
}

static int tolua_get_CInfGame_reference_m_searchRequestListEmpty(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_searchRequestListEmpty'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_searchRequestListEmpty, "Pointer<int>");
	return 1;
}

static int tolua_get_CInfGame_m_currArmor(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currArmor'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_currArmor);
	return 1;
}

static int tolua_set_CInfGame_m_currArmor(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currArmor'", NULL);
	self->m_currArmor = tolua_setter_tointeger(L, "m_currArmor");
	return 0;
}

static int tolua_get_CInfGame_reference_m_currArmor(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currArmor'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_currArmor, "Pointer<short>");
	return 1;
}

static int tolua_get_CInfGame_m_currAnimation(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currAnimation'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_currAnimation);
	return 1;
}

static int tolua_set_CInfGame_m_currAnimation(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currAnimation'", NULL);
	self->m_currAnimation = tolua_setter_tointeger(L, "m_currAnimation");
	return 0;
}

static int tolua_get_CInfGame_reference_m_currAnimation(lua_State* L)
{
	CInfGame* self = (CInfGame*)tolua_tousertype_dynamic(L, 1, 0, "EEex_CInfGame");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currAnimation'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_currAnimation, "Pointer<short>");
	return 1;
}

static int tolua_function_CGameEffectBase_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameEffectBase>");
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
	tolua_pushnumber(L, (lua_Number)self->m_effectAmount);
	return 1;
}

static int tolua_set_CGameEffectBase_m_effectAmount(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount'", NULL);
	self->m_effectAmount = tolua_setter_tointeger(L, "m_effectAmount");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_effectAmount(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_effectAmount, "Pointer<long>");
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
	tolua_pushnumber(L, (lua_Number)self->m_probabilityUpper);
	return 1;
}

static int tolua_set_CGameEffectBase_m_probabilityUpper(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_probabilityUpper'", NULL);
	self->m_probabilityUpper = tolua_setter_tointeger(L, "m_probabilityUpper");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_probabilityUpper(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_probabilityUpper'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_probabilityUpper, "Pointer<ushort>");
	return 1;
}

static int tolua_get_CGameEffectBase_m_probabilityLower(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_probabilityLower'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_probabilityLower);
	return 1;
}

static int tolua_set_CGameEffectBase_m_probabilityLower(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_probabilityLower'", NULL);
	self->m_probabilityLower = tolua_setter_tointeger(L, "m_probabilityLower");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_probabilityLower(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_probabilityLower'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_probabilityLower, "Pointer<ushort>");
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
	tolua_pushnumber(L, (lua_Number)self->m_saveMod);
	return 1;
}

static int tolua_set_CGameEffectBase_m_saveMod(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_saveMod'", NULL);
	self->m_saveMod = tolua_setter_tointeger(L, "m_saveMod");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_saveMod(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_saveMod'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_saveMod, "Pointer<long>");
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
	tolua_pushnumber(L, (lua_Number)self->m_effectAmount2);
	return 1;
}

static int tolua_set_CGameEffectBase_m_effectAmount2(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount2'", NULL);
	self->m_effectAmount2 = tolua_setter_tointeger(L, "m_effectAmount2");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_effectAmount2(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount2'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_effectAmount2, "Pointer<long>");
	return 1;
}

static int tolua_get_CGameEffectBase_m_effectAmount3(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount3'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_effectAmount3);
	return 1;
}

static int tolua_set_CGameEffectBase_m_effectAmount3(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount3'", NULL);
	self->m_effectAmount3 = tolua_setter_tointeger(L, "m_effectAmount3");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_effectAmount3(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount3'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_effectAmount3, "Pointer<long>");
	return 1;
}

static int tolua_get_CGameEffectBase_m_effectAmount4(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount4'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_effectAmount4);
	return 1;
}

static int tolua_set_CGameEffectBase_m_effectAmount4(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount4'", NULL);
	self->m_effectAmount4 = tolua_setter_tointeger(L, "m_effectAmount4");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_effectAmount4(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount4'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_effectAmount4, "Pointer<long>");
	return 1;
}

static int tolua_get_CGameEffectBase_m_effectAmount5(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount5'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_effectAmount5);
	return 1;
}

static int tolua_set_CGameEffectBase_m_effectAmount5(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount5'", NULL);
	self->m_effectAmount5 = tolua_setter_tointeger(L, "m_effectAmount5");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_effectAmount5(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_effectAmount5'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_effectAmount5, "Pointer<long>");
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
	tolua_pushnumber(L, (lua_Number)self->m_slotNum);
	return 1;
}

static int tolua_set_CGameEffectBase_m_slotNum(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_slotNum'", NULL);
	self->m_slotNum = tolua_setter_tointeger(L, "m_slotNum");
	return 0;
}

static int tolua_get_CGameEffectBase_reference_m_slotNum(lua_State* L)
{
	CGameEffectBase* self = (CGameEffectBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffectBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_slotNum'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_slotNum, "Pointer<long>");
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

static int tolua_function_CGameEffect_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameEffect>");
	return 1;
}

static int tolua_get_CGameEffect___vftable(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable '__vftable'", NULL);
	tolua_pushusertype(L, (void*)&self->__vftable, "dword");
	return 1;
}

static int tolua_get_CGameEffect_m_sourceId(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_sourceId);
	return 1;
}

static int tolua_set_CGameEffect_m_sourceId(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	self->m_sourceId = tolua_setter_tointeger(L, "m_sourceId");
	return 0;
}

static int tolua_get_CGameEffect_reference_m_sourceId(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_sourceId, "Pointer<long>");
	return 1;
}

static int tolua_get_CGameEffect_m_done(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_done'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_done);
	return 1;
}

static int tolua_set_CGameEffect_m_done(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_done'", NULL);
	self->m_done = tolua_setter_tointeger(L, "m_done");
	return 0;
}

static int tolua_get_CGameEffect_reference_m_done(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_done'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_done, "Pointer<int>");
	return 1;
}

static int tolua_get_CGameEffect_m_forceRepass(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_forceRepass'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_forceRepass);
	return 1;
}

static int tolua_set_CGameEffect_m_forceRepass(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_forceRepass'", NULL);
	self->m_forceRepass = tolua_setter_tointeger(L, "m_forceRepass");
	return 0;
}

static int tolua_get_CGameEffect_reference_m_forceRepass(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_forceRepass'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_forceRepass, "Pointer<int>");
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
	tolua_pushnumber(L, (lua_Number)self->m_compareIdOnly);
	return 1;
}

static int tolua_set_CGameEffect_m_compareIdOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdOnly'", NULL);
	self->m_compareIdOnly = tolua_setter_tointeger(L, "m_compareIdOnly");
	return 0;
}

static int tolua_get_CGameEffect_reference_m_compareIdOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdOnly'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_compareIdOnly, "Pointer<int>");
	return 1;
}

static int tolua_get_CGameEffect_m_compareIdAndFlagsOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndFlagsOnly'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_compareIdAndFlagsOnly);
	return 1;
}

static int tolua_set_CGameEffect_m_compareIdAndFlagsOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndFlagsOnly'", NULL);
	self->m_compareIdAndFlagsOnly = tolua_setter_tointeger(L, "m_compareIdAndFlagsOnly");
	return 0;
}

static int tolua_get_CGameEffect_reference_m_compareIdAndFlagsOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndFlagsOnly'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_compareIdAndFlagsOnly, "Pointer<int>");
	return 1;
}

static int tolua_get_CGameEffect_m_compareIdAndEffectAmountOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndEffectAmountOnly'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_compareIdAndEffectAmountOnly);
	return 1;
}

static int tolua_set_CGameEffect_m_compareIdAndEffectAmountOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndEffectAmountOnly'", NULL);
	self->m_compareIdAndEffectAmountOnly = tolua_setter_tointeger(L, "m_compareIdAndEffectAmountOnly");
	return 0;
}

static int tolua_get_CGameEffect_reference_m_compareIdAndEffectAmountOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndEffectAmountOnly'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_compareIdAndEffectAmountOnly, "Pointer<int>");
	return 1;
}

static int tolua_get_CGameEffect_m_compareIdAndResrefOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndResrefOnly'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_compareIdAndResrefOnly);
	return 1;
}

static int tolua_set_CGameEffect_m_compareIdAndResrefOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndResrefOnly'", NULL);
	self->m_compareIdAndResrefOnly = tolua_setter_tointeger(L, "m_compareIdAndResrefOnly");
	return 0;
}

static int tolua_get_CGameEffect_reference_m_compareIdAndResrefOnly(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_compareIdAndResrefOnly'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_compareIdAndResrefOnly, "Pointer<int>");
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
	tolua_pushnumber(L, (lua_Number)self->m_sourceTarget);
	return 1;
}

static int tolua_set_CGameEffect_m_sourceTarget(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceTarget'", NULL);
	self->m_sourceTarget = tolua_setter_tointeger(L, "m_sourceTarget");
	return 0;
}

static int tolua_get_CGameEffect_reference_m_sourceTarget(lua_State* L)
{
	CGameEffect* self = (CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceTarget'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_sourceTarget, "Pointer<long>");
	return 1;
}

static int tolua_function_CGameEffect_DecodeEffect(lua_State* L)
{
	CGameEffect* returnVal = CGameEffect::DecodeEffect((Item_effect_st*)tolua_tousertype_dynamic(L, 1, 0, "Item_effect_st"), (const CPoint*)tolua_tousertype_dynamic(L, 2, 0, "CPoint"), tolua_function_tointeger(L, 3, "DecodeEffect"), (const CPoint*)tolua_tousertype_dynamic(L, 4, 0, "CPoint"), tolua_function_tointeger(L, 5, "DecodeEffect"));
	tolua_pushusertype(L, (void*)returnVal, "CGameEffect");
	return 1;
}

static int tolua_get_reference_CGameEffect_DecodeEffect(lua_State* L)
{
	tolua_pushusertype(L, CGameEffect::DecodeEffect, "UnmappedUserType");
	return 1;
}

static int tolua_function_CDerivedStats_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CDerivedStats>");
	return 1;
}

static int tolua_get_CDerivedStats_m_generalState(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_generalState'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_generalState);
	return 1;
}

static int tolua_set_CDerivedStats_m_generalState(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_generalState'", NULL);
	self->m_generalState = tolua_setter_tointeger(L, "m_generalState");
	return 0;
}

static int tolua_get_CDerivedStats_reference_m_generalState(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_generalState'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_generalState, "Pointer<uint>");
	return 1;
}

static int tolua_get_CDerivedStats_m_nLuck(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nLuck'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nLuck);
	return 1;
}

static int tolua_set_CDerivedStats_m_nLuck(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nLuck'", NULL);
	self->m_nLuck = tolua_setter_tointeger(L, "m_nLuck");
	return 0;
}

static int tolua_get_CDerivedStats_reference_m_nLuck(lua_State* L)
{
	CDerivedStats* self = (CDerivedStats*)tolua_tousertype_dynamic(L, 1, 0, "CDerivedStats");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nLuck'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nLuck, "Pointer<short>");
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

static int tolua_function_CAreaVariable_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CAreaVariable>");
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
	tolua_pushnumber(L, (lua_Number)self->m_type);
	return 1;
}

static int tolua_set_CAreaVariable_m_type(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_type'", NULL);
	self->m_type = tolua_setter_tointeger(L, "m_type");
	return 0;
}

static int tolua_get_CAreaVariable_reference_m_type(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_type'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_type, "Pointer<ushort>");
	return 1;
}

static int tolua_get_CAreaVariable_m_resRefType(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_resRefType'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_resRefType);
	return 1;
}

static int tolua_set_CAreaVariable_m_resRefType(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_resRefType'", NULL);
	self->m_resRefType = tolua_setter_tointeger(L, "m_resRefType");
	return 0;
}

static int tolua_get_CAreaVariable_reference_m_resRefType(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_resRefType'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_resRefType, "Pointer<ushort>");
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
	tolua_pushnumber(L, (lua_Number)self->m_intValue);
	return 1;
}

static int tolua_set_CAreaVariable_m_intValue(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_intValue'", NULL);
	self->m_intValue = tolua_setter_tointeger(L, "m_intValue");
	return 0;
}

static int tolua_get_CAreaVariable_reference_m_intValue(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_intValue'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_intValue, "Pointer<long>");
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
	self->m_floatValue = tolua_setter_tonumber(L, "m_floatValue");
	return 0;
}

static int tolua_get_CAreaVariable_reference_m_floatValue(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_floatValue'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_floatValue, "Pointer<double>");
	return 1;
}

static int tolua_get_CAreaVariable_m_stringValue(lua_State* L)
{
	CAreaVariable* self = (CAreaVariable*)tolua_tousertype_dynamic(L, 1, 0, "CAreaVariable");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_stringValue'", NULL);
	tolua_pushusertype(L, (void*)&self->m_stringValue, "Array<char,32>");
	return 1;
}

static int tolua_function_CVariable_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CVariable>");
	return 1;
}

static int tolua_function_CAIObjectType_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CAIObjectType>");
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
	tolua_pushnumber(L, (lua_Number)self->m_EnemyAlly);
	return 1;
}

static int tolua_set_CAIObjectType_m_EnemyAlly(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_EnemyAlly'", NULL);
	self->m_EnemyAlly = tolua_setter_tointeger(L, "m_EnemyAlly");
	return 0;
}

static int tolua_get_CAIObjectType_reference_m_EnemyAlly(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_EnemyAlly'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_EnemyAlly, "Pointer<byte>");
	return 1;
}

static int tolua_get_CAIObjectType_m_General(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_General'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_General);
	return 1;
}

static int tolua_set_CAIObjectType_m_General(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_General'", NULL);
	self->m_General = tolua_setter_tointeger(L, "m_General");
	return 0;
}

static int tolua_get_CAIObjectType_reference_m_General(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_General'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_General, "Pointer<byte>");
	return 1;
}

static int tolua_get_CAIObjectType_m_Race(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Race'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_Race);
	return 1;
}

static int tolua_set_CAIObjectType_m_Race(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Race'", NULL);
	self->m_Race = tolua_setter_tointeger(L, "m_Race");
	return 0;
}

static int tolua_get_CAIObjectType_reference_m_Race(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Race'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_Race, "Pointer<byte>");
	return 1;
}

static int tolua_get_CAIObjectType_m_Class(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Class'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_Class);
	return 1;
}

static int tolua_set_CAIObjectType_m_Class(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Class'", NULL);
	self->m_Class = tolua_setter_tointeger(L, "m_Class");
	return 0;
}

static int tolua_get_CAIObjectType_reference_m_Class(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Class'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_Class, "Pointer<byte>");
	return 1;
}

static int tolua_get_CAIObjectType_m_Instance(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Instance'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_Instance);
	return 1;
}

static int tolua_set_CAIObjectType_m_Instance(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Instance'", NULL);
	self->m_Instance = tolua_setter_tointeger(L, "m_Instance");
	return 0;
}

static int tolua_get_CAIObjectType_reference_m_Instance(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Instance'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_Instance, "Pointer<int>");
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
	tolua_pushnumber(L, (lua_Number)self->m_Specifics);
	return 1;
}

static int tolua_set_CAIObjectType_m_Specifics(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Specifics'", NULL);
	self->m_Specifics = tolua_setter_tointeger(L, "m_Specifics");
	return 0;
}

static int tolua_get_CAIObjectType_reference_m_Specifics(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Specifics'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_Specifics, "Pointer<byte>");
	return 1;
}

static int tolua_get_CAIObjectType_m_Gender(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Gender'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_Gender);
	return 1;
}

static int tolua_set_CAIObjectType_m_Gender(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Gender'", NULL);
	self->m_Gender = tolua_setter_tointeger(L, "m_Gender");
	return 0;
}

static int tolua_get_CAIObjectType_reference_m_Gender(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Gender'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_Gender, "Pointer<byte>");
	return 1;
}

static int tolua_get_CAIObjectType_m_Alignment(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Alignment'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_Alignment);
	return 1;
}

static int tolua_set_CAIObjectType_m_Alignment(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Alignment'", NULL);
	self->m_Alignment = tolua_setter_tointeger(L, "m_Alignment");
	return 0;
}

static int tolua_get_CAIObjectType_reference_m_Alignment(lua_State* L)
{
	CAIObjectType* self = (CAIObjectType*)tolua_tousertype_dynamic(L, 1, 0, "CAIObjectType");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_Alignment'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_Alignment, "Pointer<byte>");
	return 1;
}

static int tolua_function_CGameObject_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameObject>");
	return 1;
}

static int tolua_get_CGameObject_m_objectType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_objectType'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_objectType);
	return 1;
}

static int tolua_set_CGameObject_m_objectType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_objectType'", NULL);
	self->m_objectType = tolua_setter_tointeger(L, "m_objectType");
	return 0;
}

static int tolua_get_CGameObject_reference_m_objectType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_objectType'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_objectType, "Pointer<byte>");
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
	tolua_pushnumber(L, (lua_Number)self->m_posZ);
	return 1;
}

static int tolua_set_CGameObject_m_posZ(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posZ'", NULL);
	self->m_posZ = tolua_setter_tointeger(L, "m_posZ");
	return 0;
}

static int tolua_get_CGameObject_reference_m_posZ(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posZ'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_posZ, "Pointer<int>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_pArea, "Pointer<CGameArea*>");
	return 1;
}

static int tolua_get_CGameObject_m_posVertList(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posVertList'", NULL);
	tolua_pushusertype(L, (void*)self->m_posVertList, "void");
	return 1;
}

static int tolua_set_CGameObject_m_posVertList(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posVertList'", NULL);
	self->m_posVertList = (void*)tolua_tousertype_dynamic(L, 2, 0, "void");
	return 0;
}

static int tolua_get_CGameObject_reference_m_posVertList(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_posVertList'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_posVertList, "Pointer<void*>");
	return 1;
}

static int tolua_get_CGameObject_m_listType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_listType'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_listType);
	return 1;
}

static int tolua_set_CGameObject_m_listType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_listType'", NULL);
	self->m_listType = tolua_setter_tointeger(L, "m_listType");
	return 0;
}

static int tolua_get_CGameObject_reference_m_listType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_listType'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_listType, "Pointer<byte>");
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
	tolua_pushnumber(L, (lua_Number)self->m_id);
	return 1;
}

static int tolua_set_CGameObject_m_id(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_id'", NULL);
	self->m_id = tolua_setter_tointeger(L, "m_id");
	return 0;
}

static int tolua_get_CGameObject_reference_m_id(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_id'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_id, "Pointer<int>");
	return 1;
}

static int tolua_get_CGameObject_m_canBeSeen(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_canBeSeen'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_canBeSeen);
	return 1;
}

static int tolua_set_CGameObject_m_canBeSeen(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_canBeSeen'", NULL);
	self->m_canBeSeen = tolua_setter_tointeger(L, "m_canBeSeen");
	return 0;
}

static int tolua_get_CGameObject_reference_m_canBeSeen(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_canBeSeen'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_canBeSeen, "Pointer<short>");
	return 1;
}

static int tolua_get_CGameObject_m_remotePlayerID(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remotePlayerID'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_remotePlayerID);
	return 1;
}

static int tolua_set_CGameObject_m_remotePlayerID(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remotePlayerID'", NULL);
	self->m_remotePlayerID = tolua_setter_tointeger(L, "m_remotePlayerID");
	return 0;
}

static int tolua_get_CGameObject_reference_m_remotePlayerID(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remotePlayerID'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_remotePlayerID, "Pointer<int>");
	return 1;
}

static int tolua_get_CGameObject_m_remoteObjectID(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remoteObjectID'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_remoteObjectID);
	return 1;
}

static int tolua_set_CGameObject_m_remoteObjectID(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remoteObjectID'", NULL);
	self->m_remoteObjectID = tolua_setter_tointeger(L, "m_remoteObjectID");
	return 0;
}

static int tolua_get_CGameObject_reference_m_remoteObjectID(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_remoteObjectID'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_remoteObjectID, "Pointer<int>");
	return 1;
}

static int tolua_get_CGameObject_m_AISpeed(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_AISpeed'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_AISpeed);
	return 1;
}

static int tolua_set_CGameObject_m_AISpeed(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_AISpeed'", NULL);
	self->m_AISpeed = tolua_setter_tointeger(L, "m_AISpeed");
	return 0;
}

static int tolua_get_CGameObject_reference_m_AISpeed(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_AISpeed'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_AISpeed, "Pointer<byte>");
	return 1;
}

static int tolua_get_CGameObject_m_bLocalControl(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bLocalControl'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_bLocalControl);
	return 1;
}

static int tolua_set_CGameObject_m_bLocalControl(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bLocalControl'", NULL);
	self->m_bLocalControl = tolua_setter_tointeger(L, "m_bLocalControl");
	return 0;
}

static int tolua_get_CGameObject_reference_m_bLocalControl(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bLocalControl'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_bLocalControl, "Pointer<byte>");
	return 1;
}

static int tolua_get_CGameObject_m_AIInhibitor(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_AIInhibitor'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_AIInhibitor);
	return 1;
}

static int tolua_set_CGameObject_m_AIInhibitor(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_AIInhibitor'", NULL);
	self->m_AIInhibitor = tolua_setter_tointeger(L, "m_AIInhibitor");
	return 0;
}

static int tolua_get_CGameObject_reference_m_AIInhibitor(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_AIInhibitor'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_AIInhibitor, "Pointer<byte>");
	return 1;
}

static int tolua_function_CGameObject_virtual_GetObjectType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_GetObjectType'", NULL);
	CGameObjectType returnVal = self->virtual_GetObjectType();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_CGameObject_virtual_AddToArea(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_AddToArea'", NULL);
	self->virtual_AddToArea((CGameArea*)tolua_tousertype_dynamic(L, 2, 0, "CGameArea"), (const CPoint*)tolua_tousertype_dynamic(L, 3, 0, "CPoint"), tolua_function_tointeger(L, 4, "virtual_AddToArea"), tolua_function_tointeger(L, 5, "virtual_AddToArea"));
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
	tolua_pushnumber(L, (lua_Number)returnVal);
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
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_CGameObject_virtual_CanSaveGame(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_CanSaveGame'", NULL);
	unsigned __int8 returnVal = self->virtual_CanSaveGame((unsigned int*)tolua_tousertype_dynamic(L, 2, 0, "Pointer<unsigned int>"), tolua_function_tointeger(L, 3, "virtual_CanSaveGame"), tolua_function_tointeger(L, 4, "virtual_CanSaveGame"));
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_CGameObject_virtual_CompressTime(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_CompressTime'", NULL);
	unsigned __int8 returnVal = self->virtual_CompressTime(tolua_function_tointeger(L, 2, "virtual_CompressTime"));
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_CGameObject_virtual_DebugDump(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_DebugDump'", NULL);
	self->virtual_DebugDump((const CString*)tolua_tousertype_dynamic(L, 2, 0, "CString"), tolua_function_tointeger(L, 3, "virtual_DebugDump"));
	return 0;
}

static int tolua_function_CGameObject_virtual_IsOver(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_IsOver'", NULL);
	int returnVal = self->virtual_IsOver((const CPoint*)tolua_tousertype_dynamic(L, 2, 0, "CPoint"));
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_CGameObject_virtual_DoesIntersect(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_DoesIntersect'", NULL);
	int returnVal = self->virtual_DoesIntersect(*(CRect*)tolua_tousertype_dynamic(L, 2, 0, "CRect"));
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_CGameObject_virtual_OnSearchMap(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_OnSearchMap'", NULL);
	int returnVal = self->virtual_OnSearchMap();
	tolua_pushnumber(L, (lua_Number)returnVal);
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
	unsigned __int8 returnVal = self->virtual_DoAIUpdate(tolua_function_tointeger(L, 2, "virtual_DoAIUpdate"), tolua_function_tointeger(L, 3, "virtual_DoAIUpdate"));
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_CGameObject_virtual_SetAIType(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_SetAIType'", NULL);
	self->virtual_SetAIType((const CAIObjectType*)tolua_tousertype_dynamic(L, 2, 0, "CAIObjectType"), tolua_function_tointeger(L, 3, "virtual_SetAIType"));
	return 0;
}

static int tolua_function_CGameObject_virtual_SetCursor(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_SetCursor'", NULL);
	self->virtual_SetCursor(tolua_function_tointeger(L, 2, "virtual_SetCursor"));
	return 0;
}

static int tolua_function_CGameObject_virtual_SetTarget(lua_State* L)
{
	CGameObject* self = (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_SetTarget'", NULL);
	self->virtual_SetTarget(*(CPoint*)tolua_tousertype_dynamic(L, 2, 0, "CPoint"), tolua_function_tointeger(L, 3, "virtual_SetTarget"));
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
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_CGameObject__vtbl_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameObject::vtbl>");
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

static int tolua_get_CGameObject__vtbl_AddToArea(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_AddToArea(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_AIUpdate(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_AIUpdate(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_GetAIType(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_GetAIType(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_GetTargetId(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_GetTargetId(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_GetNextWaypoint(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_GetNextWaypoint(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_GetVertListPos(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_GetVertListPos(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_GetVertListType(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_GetVertListType(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_CanSaveGame(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_CanSaveGame(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_CompressTime(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_CompressTime(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_DebugDump(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_DebugDump(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_IsOver(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_IsOver(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_DoesIntersect(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_DoesIntersect(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_OnSearchMap(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_OnSearchMap(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_OnActionButton(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_OnActionButton(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_OnFormationButton(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_OnFormationButton(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_RemoveFromArea(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_RemoveFromArea(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_Render(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_Render(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_DoAIUpdate(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_DoAIUpdate(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_SetAIType(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_SetAIType(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_SetCursor(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_SetCursor(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_SetTarget(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_SetTarget(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_SetVertListPos(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_SetVertListPos(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameObject__vtbl_EvaluateStatusTrigger(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameObject__vtbl_EvaluateStatusTrigger(lua_State* L)
{
	return 0;
}

static int tolua_function_CProjectile_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CProjectile>");
	return 1;
}

static int tolua_get_CProjectile_m_projectileType(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_projectileType'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_projectileType);
	return 1;
}

static int tolua_set_CProjectile_m_projectileType(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_projectileType'", NULL);
	self->m_projectileType = tolua_setter_tointeger(L, "m_projectileType");
	return 0;
}

static int tolua_get_CProjectile_reference_m_projectileType(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_projectileType'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_projectileType, "Pointer<short>");
	return 1;
}

static int tolua_get_CProjectile_m_speed(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_speed'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_speed);
	return 1;
}

static int tolua_set_CProjectile_m_speed(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_speed'", NULL);
	self->m_speed = tolua_setter_tointeger(L, "m_speed");
	return 0;
}

static int tolua_get_CProjectile_reference_m_speed(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_speed'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_speed, "Pointer<short>");
	return 1;
}

static int tolua_get_CProjectile_m_sourceId(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_sourceId);
	return 1;
}

static int tolua_set_CProjectile_m_sourceId(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	self->m_sourceId = tolua_setter_tointeger(L, "m_sourceId");
	return 0;
}

static int tolua_get_CProjectile_reference_m_sourceId(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_sourceId'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_sourceId, "Pointer<int>");
	return 1;
}

static int tolua_get_CProjectile_m_targetId(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_targetId);
	return 1;
}

static int tolua_set_CProjectile_m_targetId(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	self->m_targetId = tolua_setter_tointeger(L, "m_targetId");
	return 0;
}

static int tolua_get_CProjectile_reference_m_targetId(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_targetId, "Pointer<int>");
	return 1;
}

static int tolua_get_CProjectile_m_callBackProjectile(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_callBackProjectile'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_callBackProjectile);
	return 1;
}

static int tolua_set_CProjectile_m_callBackProjectile(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_callBackProjectile'", NULL);
	self->m_callBackProjectile = tolua_setter_tointeger(L, "m_callBackProjectile");
	return 0;
}

static int tolua_get_CProjectile_reference_m_callBackProjectile(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_callBackProjectile'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_callBackProjectile, "Pointer<int>");
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
	tolua_pushnumber(L, (lua_Number)self->m_nType);
	return 1;
}

static int tolua_set_CProjectile_m_nType(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nType'", NULL);
	self->m_nType = tolua_setter_tointeger(L, "m_nType");
	return 0;
}

static int tolua_get_CProjectile_reference_m_nType(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nType'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nType, "Pointer<short>");
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
	tolua_pushnumber(L, (lua_Number)self->m_decAmmount);
	return 1;
}

static int tolua_set_CProjectile_m_decAmmount(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_decAmmount'", NULL);
	self->m_decAmmount = tolua_setter_tointeger(L, "m_decAmmount");
	return 0;
}

static int tolua_get_CProjectile_reference_m_decAmmount(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_decAmmount'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_decAmmount, "Pointer<ushort>");
	return 1;
}

static int tolua_get_CProjectile_m_bSparkleTrail(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bSparkleTrail'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_bSparkleTrail);
	return 1;
}

static int tolua_set_CProjectile_m_bSparkleTrail(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bSparkleTrail'", NULL);
	self->m_bSparkleTrail = tolua_setter_tointeger(L, "m_bSparkleTrail");
	return 0;
}

static int tolua_get_CProjectile_reference_m_bSparkleTrail(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bSparkleTrail'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_bSparkleTrail, "Pointer<int>");
	return 1;
}

static int tolua_get_CProjectile_m_defaultRenderFlags(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_defaultRenderFlags'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_defaultRenderFlags);
	return 1;
}

static int tolua_set_CProjectile_m_defaultRenderFlags(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_defaultRenderFlags'", NULL);
	self->m_defaultRenderFlags = tolua_setter_tointeger(L, "m_defaultRenderFlags");
	return 0;
}

static int tolua_get_CProjectile_reference_m_defaultRenderFlags(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_defaultRenderFlags'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_defaultRenderFlags, "Pointer<uint>");
	return 1;
}

static int tolua_get_CProjectile_m_bIgnoreTarget(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bIgnoreTarget'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_bIgnoreTarget);
	return 1;
}

static int tolua_set_CProjectile_m_bIgnoreTarget(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bIgnoreTarget'", NULL);
	self->m_bIgnoreTarget = tolua_setter_tointeger(L, "m_bIgnoreTarget");
	return 0;
}

static int tolua_get_CProjectile_reference_m_bIgnoreTarget(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bIgnoreTarget'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_bIgnoreTarget, "Pointer<int>");
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
	tolua_pushnumber(L, (lua_Number)self->m_loopFireSound);
	return 1;
}

static int tolua_set_CProjectile_m_loopFireSound(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_loopFireSound'", NULL);
	self->m_loopFireSound = tolua_setter_tointeger(L, "m_loopFireSound");
	return 0;
}

static int tolua_get_CProjectile_reference_m_loopFireSound(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_loopFireSound'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_loopFireSound, "Pointer<int>");
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
	tolua_pushnumber(L, (lua_Number)self->m_loopArrivalSound);
	return 1;
}

static int tolua_set_CProjectile_m_loopArrivalSound(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_loopArrivalSound'", NULL);
	self->m_loopArrivalSound = tolua_setter_tointeger(L, "m_loopArrivalSound");
	return 0;
}

static int tolua_get_CProjectile_reference_m_loopArrivalSound(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_loopArrivalSound'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_loopArrivalSound, "Pointer<int>");
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
	tolua_pushnumber(L, (lua_Number)self->m_visualEffect);
	return 1;
}

static int tolua_set_CProjectile_m_visualEffect(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_visualEffect'", NULL);
	self->m_visualEffect = tolua_setter_tointeger(L, "m_visualEffect");
	return 0;
}

static int tolua_get_CProjectile_reference_m_visualEffect(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_visualEffect'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_visualEffect, "Pointer<int>");
	return 1;
}

static int tolua_get_CProjectile_m_maxDuration(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_maxDuration'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_maxDuration);
	return 1;
}

static int tolua_set_CProjectile_m_maxDuration(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_maxDuration'", NULL);
	self->m_maxDuration = tolua_setter_tointeger(L, "m_maxDuration");
	return 0;
}

static int tolua_get_CProjectile_reference_m_maxDuration(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_maxDuration'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_maxDuration, "Pointer<short>");
	return 1;
}

static int tolua_get_CProjectile_m_strRef(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_strRef'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_strRef);
	return 1;
}

static int tolua_set_CProjectile_m_strRef(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_strRef'", NULL);
	self->m_strRef = tolua_setter_tointeger(L, "m_strRef");
	return 0;
}

static int tolua_get_CProjectile_reference_m_strRef(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_strRef'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_strRef, "Pointer<uint>");
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
	tolua_pushnumber(L, (lua_Number)self->unknown);
	return 1;
}

static int tolua_set_CProjectile_unknown(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown'", NULL);
	self->unknown = tolua_setter_tointeger(L, "unknown");
	return 0;
}

static int tolua_get_CProjectile_reference_unknown(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknown, "Pointer<int>");
	return 1;
}

static int tolua_get_CProjectile_unknown2(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown2'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unknown2);
	return 1;
}

static int tolua_set_CProjectile_unknown2(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown2'", NULL);
	self->unknown2 = tolua_setter_tointeger(L, "unknown2");
	return 0;
}

static int tolua_get_CProjectile_reference_unknown2(lua_State* L)
{
	CProjectile* self = (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown2'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknown2, "Pointer<int>");
	return 1;
}

static int tolua_function_CProjectileBAM_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CProjectileBAM>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_currentVidCell, "Pointer<CVidCell*>");
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
	tolua_pushusertypepointer(L, (void*)&self->m_shadowVidCell, "Pointer<CVidCell*>");
	return 1;
}

static int tolua_get_CProjectileBAM_bUseAreaTint(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bUseAreaTint'", NULL);
	tolua_pushnumber(L, (lua_Number)self->bUseAreaTint);
	return 1;
}

static int tolua_set_CProjectileBAM_bUseAreaTint(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bUseAreaTint'", NULL);
	self->bUseAreaTint = tolua_setter_tointeger(L, "bUseAreaTint");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_bUseAreaTint(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bUseAreaTint'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->bUseAreaTint, "Pointer<int>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_numDirections(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_numDirections'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_numDirections);
	return 1;
}

static int tolua_set_CProjectileBAM_m_numDirections(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_numDirections'", NULL);
	self->m_numDirections = tolua_setter_tointeger(L, "m_numDirections");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_numDirections(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_numDirections'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_numDirections, "Pointer<short>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_direction(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_direction'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_direction);
	return 1;
}

static int tolua_set_CProjectileBAM_m_direction(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_direction'", NULL);
	self->m_direction = tolua_setter_tointeger(L, "m_direction");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_direction(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_direction'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_direction, "Pointer<short>");
	return 1;
}

static int tolua_get_CProjectileBAM_unknown3(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown3'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unknown3);
	return 1;
}

static int tolua_set_CProjectileBAM_unknown3(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown3'", NULL);
	self->unknown3 = tolua_setter_tointeger(L, "unknown3");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_unknown3(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unknown3'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unknown3, "Pointer<ushort>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_render(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_render'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_render);
	return 1;
}

static int tolua_set_CProjectileBAM_m_render(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_render'", NULL);
	self->m_render = tolua_setter_tointeger(L, "m_render");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_render(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_render'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_render, "Pointer<int>");
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
	tolua_pushnumber(L, (lua_Number)self->m_nPuff1Spacing);
	return 1;
}

static int tolua_set_CProjectileBAM_m_nPuff1Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff1Spacing'", NULL);
	self->m_nPuff1Spacing = tolua_setter_tointeger(L, "m_nPuff1Spacing");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_nPuff1Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff1Spacing'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nPuff1Spacing, "Pointer<ushort>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_nPuff2Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff2Spacing'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nPuff2Spacing);
	return 1;
}

static int tolua_set_CProjectileBAM_m_nPuff2Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff2Spacing'", NULL);
	self->m_nPuff2Spacing = tolua_setter_tointeger(L, "m_nPuff2Spacing");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_nPuff2Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff2Spacing'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nPuff2Spacing, "Pointer<ushort>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_nPuff3Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff3Spacing'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nPuff3Spacing);
	return 1;
}

static int tolua_set_CProjectileBAM_m_nPuff3Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff3Spacing'", NULL);
	self->m_nPuff3Spacing = tolua_setter_tointeger(L, "m_nPuff3Spacing");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_nPuff3Spacing(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nPuff3Spacing'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nPuff3Spacing, "Pointer<ushort>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_dwPuffFlags(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_dwPuffFlags'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_dwPuffFlags);
	return 1;
}

static int tolua_set_CProjectileBAM_m_dwPuffFlags(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_dwPuffFlags'", NULL);
	self->m_dwPuffFlags = tolua_setter_tointeger(L, "m_dwPuffFlags");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_dwPuffFlags(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_dwPuffFlags'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_dwPuffFlags, "Pointer<uint>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_puffCounter(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_puffCounter'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_puffCounter);
	return 1;
}

static int tolua_set_CProjectileBAM_m_puffCounter(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_puffCounter'", NULL);
	self->m_puffCounter = tolua_setter_tointeger(L, "m_puffCounter");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_puffCounter(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_puffCounter'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_puffCounter, "Pointer<int>");
	return 1;
}

static int tolua_get_CProjectileBAM_m_unknownPSTFlags(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_unknownPSTFlags'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_unknownPSTFlags);
	return 1;
}

static int tolua_set_CProjectileBAM_m_unknownPSTFlags(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_unknownPSTFlags'", NULL);
	self->m_unknownPSTFlags = tolua_setter_tointeger(L, "m_unknownPSTFlags");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_m_unknownPSTFlags(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_unknownPSTFlags'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_unknownPSTFlags, "Pointer<uint>");
	return 1;
}

static int tolua_get_CProjectileBAM_nDelayedRemoveCounter(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDelayedRemoveCounter'", NULL);
	tolua_pushnumber(L, (lua_Number)self->nDelayedRemoveCounter);
	return 1;
}

static int tolua_set_CProjectileBAM_nDelayedRemoveCounter(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDelayedRemoveCounter'", NULL);
	self->nDelayedRemoveCounter = tolua_setter_tointeger(L, "nDelayedRemoveCounter");
	return 0;
}

static int tolua_get_CProjectileBAM_reference_nDelayedRemoveCounter(lua_State* L)
{
	CProjectileBAM* self = (CProjectileBAM*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileBAM");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDelayedRemoveCounter'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->nDelayedRemoveCounter, "Pointer<int>");
	return 1;
}

static int tolua_function_CProjectileArea_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CProjectileArea>");
	return 1;
}

static int tolua_get_CProjectileArea_m_coneSize(lua_State* L)
{
	CProjectileArea* self = (CProjectileArea*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_coneSize'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_coneSize);
	return 1;
}

static int tolua_set_CProjectileArea_m_coneSize(lua_State* L)
{
	CProjectileArea* self = (CProjectileArea*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_coneSize'", NULL);
	self->m_coneSize = tolua_setter_tointeger(L, "m_coneSize");
	return 0;
}

static int tolua_get_CProjectileArea_reference_m_coneSize(lua_State* L)
{
	CProjectileArea* self = (CProjectileArea*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileArea");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_coneSize'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_coneSize, "Pointer<ushort>");
	return 1;
}

static int tolua_function_CProjectileUnknownPST_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CProjectileUnknownPST>");
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
	tolua_pushusertypepointer(L, (void*)&self->pInfinity, "Pointer<CInfinity*>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST_nUnknownMode(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nUnknownMode'", NULL);
	tolua_pushnumber(L, (lua_Number)self->nUnknownMode);
	return 1;
}

static int tolua_set_CProjectileUnknownPST_nUnknownMode(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nUnknownMode'", NULL);
	self->nUnknownMode = tolua_setter_tointeger(L, "nUnknownMode");
	return 0;
}

static int tolua_get_CProjectileUnknownPST_reference_nUnknownMode(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nUnknownMode'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->nUnknownMode, "Pointer<uint>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST_nExpirationTime(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nExpirationTime'", NULL);
	tolua_pushnumber(L, (lua_Number)self->nExpirationTime);
	return 1;
}

static int tolua_set_CProjectileUnknownPST_nExpirationTime(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nExpirationTime'", NULL);
	self->nExpirationTime = tolua_setter_tointeger(L, "nExpirationTime");
	return 0;
}

static int tolua_get_CProjectileUnknownPST_reference_nExpirationTime(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nExpirationTime'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->nExpirationTime, "Pointer<uint>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST_bSuppressFireSound(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bSuppressFireSound'", NULL);
	tolua_pushnumber(L, (lua_Number)self->bSuppressFireSound);
	return 1;
}

static int tolua_set_CProjectileUnknownPST_bSuppressFireSound(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bSuppressFireSound'", NULL);
	self->bSuppressFireSound = tolua_setter_tointeger(L, "bSuppressFireSound");
	return 0;
}

static int tolua_get_CProjectileUnknownPST_reference_bSuppressFireSound(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bSuppressFireSound'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->bSuppressFireSound, "Pointer<int>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST_nDelayedRemoveSpeed(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDelayedRemoveSpeed'", NULL);
	tolua_pushnumber(L, (lua_Number)self->nDelayedRemoveSpeed);
	return 1;
}

static int tolua_set_CProjectileUnknownPST_nDelayedRemoveSpeed(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDelayedRemoveSpeed'", NULL);
	self->nDelayedRemoveSpeed = tolua_setter_tointeger(L, "nDelayedRemoveSpeed");
	return 0;
}

static int tolua_get_CProjectileUnknownPST_reference_nDelayedRemoveSpeed(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nDelayedRemoveSpeed'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->nDelayedRemoveSpeed, "Pointer<byte>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST_bDelayedRemoveScheduled(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bDelayedRemoveScheduled'", NULL);
	tolua_pushnumber(L, (lua_Number)self->bDelayedRemoveScheduled);
	return 1;
}

static int tolua_set_CProjectileUnknownPST_bDelayedRemoveScheduled(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bDelayedRemoveScheduled'", NULL);
	self->bDelayedRemoveScheduled = tolua_setter_tointeger(L, "bDelayedRemoveScheduled");
	return 0;
}

static int tolua_get_CProjectileUnknownPST_reference_bDelayedRemoveScheduled(lua_State* L)
{
	CProjectileUnknownPST* self = (CProjectileUnknownPST*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bDelayedRemoveScheduled'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->bDelayedRemoveScheduled, "Pointer<int>");
	return 1;
}

static int tolua_function_CProjectileUnknownPST2_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CProjectileUnknownPST2>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST2_bRemoveOnNextUpdate(lua_State* L)
{
	CProjectileUnknownPST2* self = (CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST2");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bRemoveOnNextUpdate'", NULL);
	tolua_pushnumber(L, (lua_Number)self->bRemoveOnNextUpdate);
	return 1;
}

static int tolua_set_CProjectileUnknownPST2_bRemoveOnNextUpdate(lua_State* L)
{
	CProjectileUnknownPST2* self = (CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST2");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bRemoveOnNextUpdate'", NULL);
	self->bRemoveOnNextUpdate = tolua_setter_tointeger(L, "bRemoveOnNextUpdate");
	return 0;
}

static int tolua_get_CProjectileUnknownPST2_reference_bRemoveOnNextUpdate(lua_State* L)
{
	CProjectileUnknownPST2* self = (CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST2");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bRemoveOnNextUpdate'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->bRemoveOnNextUpdate, "Pointer<int>");
	return 1;
}

static int tolua_get_CProjectileUnknownPST2_nTypePST(lua_State* L)
{
	CProjectileUnknownPST2* self = (CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST2");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nTypePST'", NULL);
	tolua_pushnumber(L, (lua_Number)self->nTypePST);
	return 1;
}

static int tolua_set_CProjectileUnknownPST2_nTypePST(lua_State* L)
{
	CProjectileUnknownPST2* self = (CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST2");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nTypePST'", NULL);
	self->nTypePST = tolua_setter_tointeger(L, "nTypePST");
	return 0;
}

static int tolua_get_CProjectileUnknownPST2_reference_nTypePST(lua_State* L)
{
	CProjectileUnknownPST2* self = (CProjectileUnknownPST2*)tolua_tousertype_dynamic(L, 1, 0, "CProjectileUnknownPST2");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nTypePST'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->nTypePST, "Pointer<byte>");
	return 1;
}

static int tolua_function_CProjectileUnknownBase_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CProjectileUnknownBase>");
	return 1;
}

static int tolua_function_CProjectile205_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CProjectile205>");
	return 1;
}

static int tolua_get_CProjectile205_bHitTarget(lua_State* L)
{
	CProjectile205* self = (CProjectile205*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile205");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bHitTarget'", NULL);
	tolua_pushnumber(L, (lua_Number)self->bHitTarget);
	return 1;
}

static int tolua_set_CProjectile205_bHitTarget(lua_State* L)
{
	CProjectile205* self = (CProjectile205*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile205");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bHitTarget'", NULL);
	self->bHitTarget = tolua_setter_tointeger(L, "bHitTarget");
	return 0;
}

static int tolua_get_CProjectile205_reference_bHitTarget(lua_State* L)
{
	CProjectile205* self = (CProjectile205*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile205");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bHitTarget'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->bHitTarget, "Pointer<int>");
	return 1;
}

static int tolua_function_CAITrigger_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CAITrigger>");
	return 1;
}

static int tolua_get_CAITrigger_m_triggerID(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_triggerID'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_triggerID);
	return 1;
}

static int tolua_set_CAITrigger_m_triggerID(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_triggerID'", NULL);
	self->m_triggerID = tolua_setter_tointeger(L, "m_triggerID");
	return 0;
}

static int tolua_get_CAITrigger_reference_m_triggerID(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_triggerID'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_triggerID, "Pointer<short>");
	return 1;
}

static int tolua_get_CAITrigger_m_specificID(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specificID'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_specificID);
	return 1;
}

static int tolua_set_CAITrigger_m_specificID(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specificID'", NULL);
	self->m_specificID = tolua_setter_tointeger(L, "m_specificID");
	return 0;
}

static int tolua_get_CAITrigger_reference_m_specificID(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specificID'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_specificID, "Pointer<int>");
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
	tolua_pushnumber(L, (lua_Number)self->m_flags);
	return 1;
}

static int tolua_set_CAITrigger_m_flags(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_flags'", NULL);
	self->m_flags = tolua_setter_tointeger(L, "m_flags");
	return 0;
}

static int tolua_get_CAITrigger_reference_m_flags(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_flags'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_flags, "Pointer<int>");
	return 1;
}

static int tolua_get_CAITrigger_m_specific2(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specific2'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_specific2);
	return 1;
}

static int tolua_set_CAITrigger_m_specific2(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specific2'", NULL);
	self->m_specific2 = tolua_setter_tointeger(L, "m_specific2");
	return 0;
}

static int tolua_get_CAITrigger_reference_m_specific2(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specific2'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_specific2, "Pointer<int>");
	return 1;
}

static int tolua_get_CAITrigger_m_specific3(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specific3'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_specific3);
	return 1;
}

static int tolua_set_CAITrigger_m_specific3(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specific3'", NULL);
	self->m_specific3 = tolua_setter_tointeger(L, "m_specific3");
	return 0;
}

static int tolua_get_CAITrigger_reference_m_specific3(lua_State* L)
{
	CAITrigger* self = (CAITrigger*)tolua_tousertype_dynamic(L, 1, 0, "CAITrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_specific3'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_specific3, "Pointer<int>");
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

static int tolua_function_CMessageSetTrigger_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CMessageSetTrigger>");
	return 1;
}

static int tolua_get_CMessageSetTrigger_m_trigger(lua_State* L)
{
	CMessageSetTrigger* self = (CMessageSetTrigger*)tolua_tousertype_dynamic(L, 1, 0, "CMessageSetTrigger");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_trigger'", NULL);
	tolua_pushusertype(L, (void*)&self->m_trigger, "CAITrigger");
	return 1;
}

static int tolua_function_CGameAIBase_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameAIBase>");
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
	tolua_pushnumber(L, (lua_Number)self->m_lAttackStyle);
	return 1;
}

static int tolua_set_CGameAIBase_m_lAttackStyle(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_lAttackStyle'", NULL);
	self->m_lAttackStyle = tolua_setter_tointeger(L, "m_lAttackStyle");
	return 0;
}

static int tolua_get_CGameAIBase_reference_m_lAttackStyle(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_lAttackStyle'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_lAttackStyle, "Pointer<int>");
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

static int tolua_get_CGameAIBase_m_actionCount(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_actionCount'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_actionCount);
	return 1;
}

static int tolua_set_CGameAIBase_m_actionCount(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_actionCount'", NULL);
	self->m_actionCount = tolua_setter_tointeger(L, "m_actionCount");
	return 0;
}

static int tolua_get_CGameAIBase_reference_m_actionCount(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_actionCount'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_actionCount, "Pointer<short>");
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
	self->virtual_ClearActions(tolua_function_tointeger(L, 2, "virtual_ClearActions"));
	return 0;
}

static int tolua_function_CGameAIBase_virtual_FloatMessage(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_FloatMessage'", NULL);
	short returnVal = self->virtual_FloatMessage();
	tolua_pushnumber(L, (lua_Number)returnVal);
	return 1;
}

static int tolua_function_CGameAIBase_virtual_KillFloatMessage(lua_State* L)
{
	CGameAIBase* self = (CGameAIBase*)tolua_tousertype_dynamic(L, 1, 0, "CGameAIBase");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'virtual_KillFloatMessage'", NULL);
	short returnVal = self->virtual_KillFloatMessage();
	tolua_pushnumber(L, (lua_Number)returnVal);
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
	self->virtual_AddEffect((CGameEffect*)tolua_tousertype_dynamic(L, 2, 0, "CGameEffect"), tolua_function_tointeger(L, 3, "virtual_AddEffect"), tolua_function_tointeger(L, 4, "virtual_AddEffect"), tolua_function_tointeger(L, 5, "virtual_AddEffect"));
	return 0;
}

static int tolua_function_CGameAIBase__vtbl_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameAIBase::vtbl>");
	return 1;
}

static int tolua_get_CGameAIBase__vtbl_ClearActions(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameAIBase__vtbl_ClearActions(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameAIBase__vtbl_FloatMessage(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameAIBase__vtbl_FloatMessage(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameAIBase__vtbl_KillFloatMessage(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameAIBase__vtbl_KillFloatMessage(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameAIBase__vtbl_UpdateTarget(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameAIBase__vtbl_UpdateTarget(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameAIBase__vtbl_AddAction(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameAIBase__vtbl_AddAction(lua_State* L)
{
	return 0;
}

static int tolua_get_CGameAIBase__vtbl_AddEffect(lua_State* L)
{
	return 1;
}

static int tolua_set_CGameAIBase__vtbl_AddEffect(lua_State* L)
{
	return 0;
}

static int tolua_function_CGameSprite_getInternalReference(lua_State* L)
{
	void** ptr = (void**)lua_touserdata(L, 1);
	tolua_pushusertype(L, ptr, "Pointer<CGameSprite>");
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
	tolua_pushnumber(L, (lua_Number)self->bAllowGlobalOrAreaTintsWhenRendering);
	return 1;
}

static int tolua_set_CGameSprite_bAllowGlobalOrAreaTintsWhenRendering(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bAllowGlobalOrAreaTintsWhenRendering'", NULL);
	self->bAllowGlobalOrAreaTintsWhenRendering = tolua_setter_tointeger(L, "bAllowGlobalOrAreaTintsWhenRendering");
	return 0;
}

static int tolua_get_CGameSprite_reference_bAllowGlobalOrAreaTintsWhenRendering(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'bAllowGlobalOrAreaTintsWhenRendering'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->bAllowGlobalOrAreaTintsWhenRendering, "Pointer<byte>");
	return 1;
}

static int tolua_get_CGameSprite_m_nMirrorImages(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nMirrorImages'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_nMirrorImages);
	return 1;
}

static int tolua_set_CGameSprite_m_nMirrorImages(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nMirrorImages'", NULL);
	self->m_nMirrorImages = tolua_setter_tointeger(L, "m_nMirrorImages");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_nMirrorImages(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_nMirrorImages'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_nMirrorImages, "Pointer<byte>");
	return 1;
}

static int tolua_get_CGameSprite_unkPSTVisualEffectVar1(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unkPSTVisualEffectVar1'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unkPSTVisualEffectVar1);
	return 1;
}

static int tolua_set_CGameSprite_unkPSTVisualEffectVar1(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unkPSTVisualEffectVar1'", NULL);
	self->unkPSTVisualEffectVar1 = tolua_setter_tointeger(L, "unkPSTVisualEffectVar1");
	return 0;
}

static int tolua_get_CGameSprite_reference_unkPSTVisualEffectVar1(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unkPSTVisualEffectVar1'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unkPSTVisualEffectVar1, "Pointer<byte>");
	return 1;
}

static int tolua_get_CGameSprite_unkPSTVisualEffectVar2(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unkPSTVisualEffectVar2'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unkPSTVisualEffectVar2);
	return 1;
}

static int tolua_set_CGameSprite_unkPSTVisualEffectVar2(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unkPSTVisualEffectVar2'", NULL);
	self->unkPSTVisualEffectVar2 = tolua_setter_tointeger(L, "unkPSTVisualEffectVar2");
	return 0;
}

static int tolua_get_CGameSprite_reference_unkPSTVisualEffectVar2(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unkPSTVisualEffectVar2'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unkPSTVisualEffectVar2, "Pointer<byte>");
	return 1;
}

static int tolua_get_CGameSprite_unkPSTVisualEffectVar3(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unkPSTVisualEffectVar3'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unkPSTVisualEffectVar3);
	return 1;
}

static int tolua_set_CGameSprite_unkPSTVisualEffectVar3(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unkPSTVisualEffectVar3'", NULL);
	self->unkPSTVisualEffectVar3 = tolua_setter_tointeger(L, "unkPSTVisualEffectVar3");
	return 0;
}

static int tolua_get_CGameSprite_reference_unkPSTVisualEffectVar3(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unkPSTVisualEffectVar3'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unkPSTVisualEffectVar3, "Pointer<ushort>");
	return 1;
}

static int tolua_get_CGameSprite_unkPSTVisualEffectVar4(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unkPSTVisualEffectVar4'", NULL);
	tolua_pushnumber(L, (lua_Number)self->unkPSTVisualEffectVar4);
	return 1;
}

static int tolua_set_CGameSprite_unkPSTVisualEffectVar4(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unkPSTVisualEffectVar4'", NULL);
	self->unkPSTVisualEffectVar4 = tolua_setter_tointeger(L, "unkPSTVisualEffectVar4");
	return 0;
}

static int tolua_get_CGameSprite_reference_unkPSTVisualEffectVar4(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'unkPSTVisualEffectVar4'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->unkPSTVisualEffectVar4, "Pointer<ushort>");
	return 1;
}

static int tolua_get_CGameSprite_m_bBlur(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bBlur'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_bBlur);
	return 1;
}

static int tolua_set_CGameSprite_m_bBlur(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bBlur'", NULL);
	self->m_bBlur = tolua_setter_tointeger(L, "m_bBlur");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_bBlur(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bBlur'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_bBlur, "Pointer<byte>");
	return 1;
}

static int tolua_get_CGameSprite_m_bMinorGlobe(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bMinorGlobe'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_bMinorGlobe);
	return 1;
}

static int tolua_set_CGameSprite_m_bMinorGlobe(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bMinorGlobe'", NULL);
	self->m_bMinorGlobe = tolua_setter_tointeger(L, "m_bMinorGlobe");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_bMinorGlobe(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bMinorGlobe'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_bMinorGlobe, "Pointer<byte>");
	return 1;
}

static int tolua_get_CGameSprite_m_bShieldGlobe(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bShieldGlobe'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_bShieldGlobe);
	return 1;
}

static int tolua_set_CGameSprite_m_bShieldGlobe(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bShieldGlobe'", NULL);
	self->m_bShieldGlobe = tolua_setter_tointeger(L, "m_bShieldGlobe");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_bShieldGlobe(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bShieldGlobe'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_bShieldGlobe, "Pointer<byte>");
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

static int tolua_get_CGameSprite_m_newEffect(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_newEffect'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_newEffect);
	return 1;
}

static int tolua_set_CGameSprite_m_newEffect(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_newEffect'", NULL);
	self->m_newEffect = tolua_setter_tointeger(L, "m_newEffect");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_newEffect(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_newEffect'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_newEffect, "Pointer<int>");
	return 1;
}

static int tolua_get_CGameSprite_m_hasColorEffects(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_hasColorEffects'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_hasColorEffects);
	return 1;
}

static int tolua_set_CGameSprite_m_hasColorEffects(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_hasColorEffects'", NULL);
	self->m_hasColorEffects = tolua_setter_tointeger(L, "m_hasColorEffects");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_hasColorEffects(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_hasColorEffects'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_hasColorEffects, "Pointer<int>");
	return 1;
}

static int tolua_get_CGameSprite_m_targetId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_targetId);
	return 1;
}

static int tolua_set_CGameSprite_m_targetId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	self->m_targetId = tolua_setter_tointeger(L, "m_targetId");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_targetId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_targetId'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_targetId, "Pointer<int>");
	return 1;
}

static int tolua_get_CGameSprite_m_dialog(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_dialog'", NULL);
	tolua_pushusertype(L, (void*)&self->m_dialog, "CResRef");
	return 1;
}

static int tolua_get_CGameSprite_m_bForceVisualEffects(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bForceVisualEffects'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_bForceVisualEffects);
	return 1;
}

static int tolua_set_CGameSprite_m_bForceVisualEffects(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bForceVisualEffects'", NULL);
	self->m_bForceVisualEffects = tolua_setter_tointeger(L, "m_bForceVisualEffects");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_bForceVisualEffects(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_bForceVisualEffects'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_bForceVisualEffects, "Pointer<int>");
	return 1;
}

static int tolua_get_CGameSprite_m_currentActionId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currentActionId'", NULL);
	tolua_pushnumber(L, (lua_Number)self->m_currentActionId);
	return 1;
}

static int tolua_set_CGameSprite_m_currentActionId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currentActionId'", NULL);
	self->m_currentActionId = tolua_setter_tointeger(L, "m_currentActionId");
	return 0;
}

static int tolua_get_CGameSprite_reference_m_currentActionId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'm_currentActionId'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->m_currentActionId, "Pointer<short>");
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
	tolua_pushnumber(L, (lua_Number)self->nAttachedPSTVisualEffectProjectiles);
	return 1;
}

static int tolua_set_CGameSprite_nAttachedPSTVisualEffectProjectiles(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nAttachedPSTVisualEffectProjectiles'", NULL);
	self->nAttachedPSTVisualEffectProjectiles = tolua_setter_tointeger(L, "nAttachedPSTVisualEffectProjectiles");
	return 0;
}

static int tolua_get_CGameSprite_reference_nAttachedPSTVisualEffectProjectiles(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nAttachedPSTVisualEffectProjectiles'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->nAttachedPSTVisualEffectProjectiles, "Pointer<byte>");
	return 1;
}

static int tolua_get_CGameSprite_nPSTVisualEffectsSetToRender(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nPSTVisualEffectsSetToRender'", NULL);
	tolua_pushnumber(L, (lua_Number)self->nPSTVisualEffectsSetToRender);
	return 1;
}

static int tolua_set_CGameSprite_nPSTVisualEffectsSetToRender(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nPSTVisualEffectsSetToRender'", NULL);
	self->nPSTVisualEffectsSetToRender = tolua_setter_tointeger(L, "nPSTVisualEffectsSetToRender");
	return 0;
}

static int tolua_get_CGameSprite_reference_nPSTVisualEffectsSetToRender(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nPSTVisualEffectsSetToRender'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->nPSTVisualEffectsSetToRender, "Pointer<byte>");
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
	tolua_pushnumber(L, (lua_Number)self->nOverTriggerId);
	return 1;
}

static int tolua_set_CGameSprite_nOverTriggerId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nOverTriggerId'", NULL);
	self->nOverTriggerId = tolua_setter_tointeger(L, "nOverTriggerId");
	return 0;
}

static int tolua_get_CGameSprite_reference_nOverTriggerId(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in accessing variable 'nOverTriggerId'", NULL);
	tolua_pushusertypepointer(L, (void*)&self->nOverTriggerId, "Pointer<long>");
	return 1;
}

static void tolua_reg_types(lua_State* L)
{
	tolua_usertype(L, "CAIAction");
	tolua_usertype(L, "CGameAnimation");
	tolua_usertype(L, "CGameAnimationType");
	tolua_usertype(L, "CPersistantEffectColorEffect");
	tolua_usertype(L, "CPtrList_CNode");
	tolua_usertype(L, "CResCell");
	tolua_usertype(L, "EEex_CScreenWorld");
	tolua_usertype(L, "CSound");
	tolua_usertype(L, "CSoundImp");
	tolua_usertype(L, "CVidImage");
	tolua_usertype(L, "CVideo");
	tolua_usertype(L, "EngineGlobals");
	tolua_usertype(L, "VoidPointer");
	tolua_usertype(L, "__POSITION");
	tolua_usertype(L, "__int8");
	tolua_usertype(L, "VertListType");
	tolua_usertype(L, "CGameObjectType");
	tolua_usertype(L, "byte");
	tolua_usertype(L, "EEex_CTimerWorld");
	tolua_usertype(L, "char");
	tolua_usertype(L, "double");
	tolua_usertype(L, "float");
	tolua_usertype(L, "int");
	tolua_usertype(L, "CRect");
	tolua_usertype(L, "CPtrList");
	tolua_usertype(L, "CPoint");
	tolua_usertype(L, "CGameObjectArray");
	tolua_usertype(L, "CGameEffectList");
	tolua_usertype(L, "EEex_CBaldurChitin");
	tolua_usertype(L, "intptr_t");
	tolua_usertype(L, "UnmappedUserType");
	tolua_usertype(L, "long");
	tolua_usertype(L, "CMessage");
	tolua_usertype(L, "CMessageVisualEffect");
	tolua_usertype(L, "short");
	tolua_usertype(L, "size_t");
	tolua_usertype(L, "uint");
	tolua_usertype(L, "CVidMode");
	tolua_usertype(L, "CInfinity");
	tolua_usertype(L, "ushort");
	tolua_usertype(L, "CGameTrigger");
	tolua_usertype(L, "CGameDoor");
	tolua_usertype(L, "CGameContainer");
	tolua_usertype(L, "void");
	tolua_usertype(L, "Pointer<CGameObject>");
	tolua_usertype(L, "Pointer<EEex_CBaldurChitin>");
	tolua_usertype(L, "Pointer<CObject>");
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
	tolua_usertype(L, "Pointer<CResCell>");
	tolua_usertype(L, "Pointer<CResCell*>");
	tolua_usertype(L, "Pointer<CSound>");
	tolua_usertype(L, "Pointer<CVidImage>");
	tolua_usertype(L, "Pointer<CVideo>");
	tolua_usertype(L, "Pointer<void*>");
	tolua_usertype(L, "Pointer<unsigned __int8>");
	tolua_usertype(L, "Pointer<__int8>");
	tolua_usertype(L, "Pointer<VertListType>");
	tolua_usertype(L, "Pointer<CGameObjectType>");
	tolua_usertype(L, "Pointer<byte>");
	tolua_usertype(L, "Pointer<byte*>");
	tolua_usertype(L, "Pointer<EEex_CTimerWorld>");
	tolua_usertype(L, "Pointer<char*>");
	tolua_usertype(L, "Pointer<char>");
	tolua_usertype(L, "Pointer<const char*>");
	tolua_usertype(L, "Pointer<double>");
	tolua_usertype(L, "Pointer<float>");
	tolua_usertype(L, "Pointer<CRect>");
	tolua_usertype(L, "Pointer<CPtrList>");
	tolua_usertype(L, "Pointer<CGameEffectList>");
	tolua_usertype(L, "Pointer<intptr_t>");
	tolua_usertype(L, "Pointer<long>");
	tolua_usertype(L, "Pointer<long*>");
	tolua_usertype(L, "Pointer<CMessage>");
	tolua_usertype(L, "Pointer<short>");
	tolua_usertype(L, "Pointer<size_t>");
	tolua_usertype(L, "Pointer<uint>");
	tolua_usertype(L, "Pointer<ushort>");
	tolua_usertype(L, "Pointer<CharString*>");
	tolua_usertype(L, "Pointer<CString>");
	tolua_usertype(L, "Pointer<CObject::vtbl>");
	tolua_usertype(L, "Pointer<CTypedPtrList<CPtrList,long>>");
	tolua_usertype(L, "Pointer<CTypedPtrList<CPtrList,int*>>");
	tolua_usertype(L, "Pointer<CTypedPtrList<CPtrList,int>>");
	tolua_usertype(L, "Pointer<CGameArea**>");
	tolua_usertype(L, "Pointer<CGameObject::vtbl>");
	tolua_usertype(L, "Pointer<LCharString<32>>");
	tolua_usertype(L, "Pointer<CResHelper<CResCell,1000>>");
	tolua_usertype(L, "Pointer<CGameEffectBase>");
	tolua_usertype(L, "Pointer<CDerivedStats>");
	tolua_usertype(L, "Pointer<CAreaVariable>");
	tolua_usertype(L, "Pointer<CAIObjectType>");
	tolua_usertype(L, "Pointer<CProjectile>");
	tolua_usertype(L, "Pointer<CProjectileBAM>");
	tolua_usertype(L, "Pointer<CProjectileUnknownPST>");
	tolua_usertype(L, "Pointer<CProjectileUnknownPST2**>");
	tolua_usertype(L, "Pointer<CProjectileUnknownBase>");
	tolua_usertype(L, "Pointer<CAITrigger>");
	tolua_usertype(L, "CharString");
	tolua_usertype(L, "CString");
	tolua_usertype(L, "CObject");
	tolua_usertype(L, "CObject::vtbl");
	tolua_usertype(L, "CTypedPtrList<CPtrList,long>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,long>::CNode");
	tolua_usertype(L, "CTypedPtrList<CPtrList,int*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,int*>::CNode");
	tolua_usertype(L, "CTypedPtrList<CPtrList,int>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,int>::CNode");
	tolua_usertype(L, "CAreaTintOverride");
	tolua_usertype(L, "CGameArea");
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
	tolua_usertype(L, "CGameObject");
	tolua_usertype(L, "CGameObject::vtbl");
	tolua_usertype(L, "CProjectile");
	tolua_usertype(L, "CProjectileBAM");
	tolua_usertype(L, "CProjectileArea");
	tolua_usertype(L, "CProjectileUnknownPST");
	tolua_usertype(L, "CProjectileUnknownPST2");
	tolua_usertype(L, "CProjectileUnknownBase");
	tolua_usertype(L, "CProjectile205");
	tolua_usertype(L, "CAITrigger");
	tolua_usertype(L, "CMessageSetTrigger");
	tolua_usertype(L, "CGameAIBase");
	tolua_usertype(L, "CGameAIBase::vtbl");
	tolua_usertype(L, "CGameSprite");
}

int tolua_EEexLua_open(lua_State* L)
{
	tolua_open(L);
	tolua_reg_types(L);
	tolua_module(L, NULL, 0);
	tolua_beginmodule(L, NULL);
	tolua_cclass(L, "CAIAction", "CAIAction", {}, NULL);
	tolua_beginmodule(L, "CAIAction");
		tolua_function(L, "getInternalReference", &tolua_function_CAIAction_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CAIAction));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameAnimation", "CGameAnimation", {}, NULL);
	tolua_beginmodule(L, "CGameAnimation");
		tolua_variable(L, "m_animation", tolua_get_CGameAnimation_m_animation, tolua_set_CGameAnimation_m_animation);
		tolua_variable(L, "reference_m_animation", tolua_get_CGameAnimation_reference_m_animation, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CGameAnimation_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CGameAnimation));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameAnimationType", "CGameAnimationType", {}, NULL);
	tolua_beginmodule(L, "CGameAnimationType");
		tolua_variable(L, "__vftable", tolua_get_CGameAnimationType___vftable, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CGameAnimationType_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CGameAnimationType));
	tolua_endmodule(L);
	tolua_cclass(L, "CPersistantEffectColorEffect", "CPersistantEffectColorEffect", {}, NULL);
	tolua_beginmodule(L, "CPersistantEffectColorEffect");
		tolua_function(L, "getInternalReference", &tolua_function_CPersistantEffectColorEffect_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CPersistantEffectColorEffect));
	tolua_endmodule(L);
	tolua_cclass(L, "CPtrList_CNode", "CPtrList_CNode", {}, NULL);
	tolua_beginmodule(L, "CPtrList_CNode");
		tolua_variable(L, "pNext", tolua_get_CPtrList_CNode_pNext, tolua_set_CPtrList_CNode_pNext);
		tolua_variable(L, "reference_pNext", tolua_get_CPtrList_CNode_reference_pNext, NULL);
		tolua_variable(L, "pPrev", tolua_get_CPtrList_CNode_pPrev, tolua_set_CPtrList_CNode_pPrev);
		tolua_variable(L, "reference_pPrev", tolua_get_CPtrList_CNode_reference_pPrev, NULL);
		tolua_variable(L, "data", tolua_get_CPtrList_CNode_data, tolua_set_CPtrList_CNode_data);
		tolua_variable(L, "reference_data", tolua_get_CPtrList_CNode_reference_data, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CPtrList_CNode_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CPtrList_CNode));
	tolua_endmodule(L);
	tolua_cclass(L, "CResCell", "CResCell", {}, NULL);
	tolua_beginmodule(L, "CResCell");
		tolua_function(L, "getInternalReference", &tolua_function_CResCell_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CResCell));
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenWorld", "EEex_CScreenWorld", {}, NULL);
	tolua_beginmodule(L, "EEex_CScreenWorld");
		tolua_function(L, "getInternalReference", &tolua_function_CScreenWorld_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CScreenWorld));
	tolua_endmodule(L);
	tolua_cclass(L, "CSound", "CSound", {}, NULL);
	tolua_beginmodule(L, "CSound");
		tolua_function(L, "getInternalReference", &tolua_function_CSound_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CSound));
	tolua_endmodule(L);
	tolua_cclass(L, "CSoundImp", "CSoundImp", {}, NULL);
	tolua_beginmodule(L, "CSoundImp");
		tolua_function(L, "getInternalReference", &tolua_function_CSoundImp_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CSoundImp));
	tolua_endmodule(L);
	tolua_cclass(L, "CVidImage", "CVidImage", {}, NULL);
	tolua_beginmodule(L, "CVidImage");
		tolua_function(L, "getInternalReference", &tolua_function_CVidImage_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CVidImage));
	tolua_endmodule(L);
	tolua_cclass(L, "CVideo", "CVideo", {}, NULL);
	tolua_beginmodule(L, "CVideo");
		tolua_variable(L, "pCurrentMode", tolua_get_CVideo_pCurrentMode, tolua_set_CVideo_pCurrentMode);
		tolua_variable(L, "reference_pCurrentMode", tolua_get_CVideo_reference_pCurrentMode, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CVideo_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CVideo));
	tolua_endmodule(L);
	tolua_cclass(L, "EngineGlobals", "EngineGlobals", {}, NULL);
	tolua_beginmodule(L, "EngineGlobals");
		tolua_variable(L, "g_pBaldurChitin", tolua_get_g_pBaldurChitin, tolua_set_g_pBaldurChitin);
	tolua_endmodule(L);
	tolua_cclass(L, "VoidPointer", "VoidPointer", {}, NULL);
	tolua_beginmodule(L, "VoidPointer");
		tolua_variable(L, "reference", tolua_get_VoidPointer_reference, tolua_set_VoidPointer_reference);
		tolua_variable(L, "reference_reference", tolua_get_VoidPointer_reference_reference, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_VoidPointer_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(VoidPointer));
	tolua_endmodule(L);
	tolua_cclass(L, "__POSITION", "__POSITION", {}, NULL);
	tolua_beginmodule(L, "__POSITION");
		tolua_function(L, "getInternalReference", &tolua_function___POSITION_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(__POSITION));
	tolua_endmodule(L);
	tolua_cclass(L, "__int8", "__int8", {}, NULL);
	tolua_beginmodule(L, "__int8");
		tolua_function(L, "getInternalReference", &tolua_function___int8_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(__int8));
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
	tolua_cclass(L, "byte", "byte", {}, NULL);
	tolua_beginmodule(L, "byte");
		tolua_function(L, "getInternalReference", &tolua_function_byte_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(byte));
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CTimerWorld", "EEex_CTimerWorld", {}, NULL);
	tolua_beginmodule(L, "EEex_CTimerWorld");
		tolua_variable(L, "m_gameTime", tolua_get_CTimerWorld_m_gameTime, NULL);
		tolua_variable(L, "m_active", tolua_get_CTimerWorld_m_active, tolua_set_CTimerWorld_m_active);
		tolua_variable(L, "reference_m_active", tolua_get_CTimerWorld_reference_m_active, NULL);
		tolua_variable(L, "m_nLastPercentage", tolua_get_CTimerWorld_m_nLastPercentage, tolua_set_CTimerWorld_m_nLastPercentage);
		tolua_variable(L, "reference_m_nLastPercentage", tolua_get_CTimerWorld_reference_m_nLastPercentage, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CTimerWorld_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CTimerWorld));
	tolua_endmodule(L);
	tolua_cclass(L, "char", "char", {}, NULL);
	tolua_beginmodule(L, "char");
		tolua_function(L, "getInternalReference", &tolua_function_char_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(char));
	tolua_endmodule(L);
	tolua_cclass(L, "double", "double", {}, NULL);
	tolua_beginmodule(L, "double");
		tolua_function(L, "getInternalReference", &tolua_function_double_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(double));
	tolua_endmodule(L);
	tolua_cclass(L, "float", "float", {}, NULL);
	tolua_beginmodule(L, "float");
		tolua_function(L, "getInternalReference", &tolua_function_float_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(float));
	tolua_endmodule(L);
	tolua_cclass(L, "int", "int", {}, NULL);
	tolua_beginmodule(L, "int");
		tolua_function(L, "getInternalReference", &tolua_function_int_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(int));
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
		tolua_function(L, "getInternalReference", &tolua_function_CRect_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CRect));
	tolua_endmodule(L);
	tolua_cclass(L, "CPtrList", "CPtrList", {}, NULL);
	tolua_beginmodule(L, "CPtrList");
		tolua_variable(L, "__vftable", tolua_get_CPtrList___vftable, NULL);
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
		tolua_function(L, "getInternalReference", &tolua_function_CPtrList_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CPtrList));
	tolua_endmodule(L);
	tolua_cclass(L, "CPoint", "CPoint", {}, NULL);
	tolua_beginmodule(L, "CPoint");
		tolua_variable(L, "x", tolua_get_CPoint_x, tolua_set_CPoint_x);
		tolua_variable(L, "reference_x", tolua_get_CPoint_reference_x, NULL);
		tolua_variable(L, "y", tolua_get_CPoint_y, tolua_set_CPoint_y);
		tolua_variable(L, "reference_y", tolua_get_CPoint_reference_y, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CPoint_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CPoint));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameObjectArray", "CGameObjectArray", {}, NULL);
	tolua_beginmodule(L, "CGameObjectArray");
		tolua_variable(L, "reference_GetShare", tolua_get_reference_CGameObjectArray_GetShare, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CGameObjectArray_getInternalReference);
		tolua_function(L, "GetShare", &tolua_function_CGameObjectArray_GetShare);
		tolua_constant(L, "sizeof", sizeof(CGameObjectArray));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameEffectList", "CGameEffectList", {"CPtrList"}, NULL);
	tolua_beginmodule(L, "CGameEffectList");
		tolua_variable(L, "m_posNext", tolua_get_CGameEffectList_m_posNext, tolua_set_CGameEffectList_m_posNext);
		tolua_variable(L, "reference_m_posNext", tolua_get_CGameEffectList_reference_m_posNext, NULL);
		tolua_variable(L, "m_posCurrent", tolua_get_CGameEffectList_m_posCurrent, tolua_set_CGameEffectList_m_posCurrent);
		tolua_variable(L, "reference_m_posCurrent", tolua_get_CGameEffectList_reference_m_posCurrent, NULL);
		tolua_variable(L, "m_newEffect", tolua_get_CGameEffectList_m_newEffect, tolua_set_CGameEffectList_m_newEffect);
		tolua_variable(L, "reference_m_newEffect", tolua_get_CGameEffectList_reference_m_newEffect, NULL);
		tolua_variable(L, "m_retry", tolua_get_CGameEffectList_m_retry, tolua_set_CGameEffectList_m_retry);
		tolua_variable(L, "reference_m_retry", tolua_get_CGameEffectList_reference_m_retry, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CGameEffectList_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CGameEffectList));
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CBaldurChitin", "EEex_CBaldurChitin", {}, NULL);
	tolua_beginmodule(L, "EEex_CBaldurChitin");
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
		tolua_function(L, "getInternalReference", &tolua_function_CBaldurChitin_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CBaldurChitin));
	tolua_endmodule(L);
	tolua_cclass(L, "intptr_t", "intptr_t", {}, NULL);
	tolua_beginmodule(L, "intptr_t");
		tolua_function(L, "getInternalReference", &tolua_function_intptr_t_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(intptr_t));
	tolua_endmodule(L);
	tolua_cclass(L, "UnmappedUserType", "UnmappedUserType", {}, NULL);
	tolua_beginmodule(L, "UnmappedUserType");
		tolua_function(L, "getInternalReference", &tolua_function_UnmappedUserType_getInternalReference);
		tolua_function(L, "toPointer", &tolua_function_UnmappedUserType_toPointer);
		tolua_constant(L, "sizeof", sizeof(UnmappedUserType));
	tolua_endmodule(L);
	tolua_cclass(L, "long", "long", {}, NULL);
	tolua_beginmodule(L, "long");
		tolua_function(L, "getInternalReference", &tolua_function_long_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(long));
	tolua_endmodule(L);
	tolua_cclass(L, "CMessage", "CMessage", {}, NULL);
	tolua_beginmodule(L, "CMessage");
		tolua_variable(L, "__vftable", tolua_get_CMessage___vftable, NULL);
		tolua_variable(L, "m_targetId", tolua_get_CMessage_m_targetId, tolua_set_CMessage_m_targetId);
		tolua_variable(L, "reference_m_targetId", tolua_get_CMessage_reference_m_targetId, NULL);
		tolua_variable(L, "m_sourceId", tolua_get_CMessage_m_sourceId, tolua_set_CMessage_m_sourceId);
		tolua_variable(L, "reference_m_sourceId", tolua_get_CMessage_reference_m_sourceId, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CMessage_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CMessage));
	tolua_endmodule(L);
	tolua_cclass(L, "CMessageVisualEffect", "CMessageVisualEffect", {"CMessage"}, NULL);
	tolua_beginmodule(L, "CMessageVisualEffect");
		tolua_variable(L, "m_nEffectType", tolua_get_CMessageVisualEffect_m_nEffectType, tolua_set_CMessageVisualEffect_m_nEffectType);
		tolua_variable(L, "reference_m_nEffectType", tolua_get_CMessageVisualEffect_reference_m_nEffectType, NULL);
		tolua_variable(L, "m_nEffectProperty", tolua_get_CMessageVisualEffect_m_nEffectProperty, tolua_set_CMessageVisualEffect_m_nEffectProperty);
		tolua_variable(L, "reference_m_nEffectProperty", tolua_get_CMessageVisualEffect_reference_m_nEffectProperty, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CMessageVisualEffect_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CMessageVisualEffect));
	tolua_endmodule(L);
	tolua_cclass(L, "short", "short", {}, NULL);
	tolua_beginmodule(L, "short");
		tolua_function(L, "getInternalReference", &tolua_function_short_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(short));
	tolua_endmodule(L);
	tolua_cclass(L, "size_t", "size_t", {}, NULL);
	tolua_beginmodule(L, "size_t");
		tolua_function(L, "getInternalReference", &tolua_function_size_t_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(size_t));
	tolua_endmodule(L);
	tolua_cclass(L, "uint", "uint", {}, NULL);
	tolua_beginmodule(L, "uint");
		tolua_function(L, "getInternalReference", &tolua_function_uint_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(uint));
	tolua_endmodule(L);
	tolua_cclass(L, "CVidMode", "CVidMode", {}, NULL);
	tolua_beginmodule(L, "CVidMode");
		tolua_function(L, "getInternalReference", &tolua_function_CVidMode_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CVidMode));
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
		tolua_variable(L, "unknownSetByOp354", tolua_get_CInfinity_unknownSetByOp354, tolua_set_CInfinity_unknownSetByOp354);
		tolua_variable(L, "reference_unknownSetByOp354", tolua_get_CInfinity_reference_unknownSetByOp354, NULL);
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
		tolua_function(L, "getInternalReference", &tolua_function_CInfinity_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CInfinity));
	tolua_endmodule(L);
	tolua_cclass(L, "ushort", "ushort", {}, NULL);
	tolua_beginmodule(L, "ushort");
		tolua_function(L, "getInternalReference", &tolua_function_ushort_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(ushort));
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
		tolua_function(L, "getInternalReference", &tolua_function_CGameTrigger_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CGameTrigger));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameDoor", "CGameDoor", {}, NULL);
	tolua_beginmodule(L, "CGameDoor");
		tolua_variable(L, "m_dwFlagsDoor", tolua_get_CGameDoor_m_dwFlagsDoor, NULL);
		tolua_variable(L, "m_trapActivated", tolua_get_CGameDoor_m_trapActivated, tolua_set_CGameDoor_m_trapActivated);
		tolua_variable(L, "reference_m_trapActivated", tolua_get_CGameDoor_reference_m_trapActivated, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CGameDoor_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CGameDoor));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameContainer", "CGameContainer", {}, NULL);
	tolua_beginmodule(L, "CGameContainer");
		tolua_variable(L, "m_trapActivated", tolua_get_CGameContainer_m_trapActivated, tolua_set_CGameContainer_m_trapActivated);
		tolua_variable(L, "reference_m_trapActivated", tolua_get_CGameContainer_reference_m_trapActivated, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CGameContainer_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CGameContainer));
	tolua_endmodule(L);
	tolua_cclass(L, "void", "void", {}, NULL);
	tolua_beginmodule(L, "void");
		tolua_function(L, "getInternalReference", &tolua_function_void_getInternalReference);
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameObject>", "Pointer<CGameObject>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameObject>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameObject__reference, tolua_set_Pointer_CGameObject__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CGameObject__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameObject__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameObject>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<EEex_CBaldurChitin>", "Pointer<EEex_CBaldurChitin>", {}, NULL);
	tolua_beginmodule(L, "Pointer<EEex_CBaldurChitin>");
		tolua_variable(L, "reference", tolua_get_Pointer_CBaldurChitin__reference, tolua_set_Pointer_CBaldurChitin__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CBaldurChitin__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CBaldurChitin__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CBaldurChitin>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CObject>", "Pointer<CObject>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CObject>");
		tolua_variable(L, "reference", tolua_get_Pointer_CObject__reference, tolua_set_Pointer_CObject__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CObject__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CObject__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CObject>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameArea>", "Pointer<CGameArea>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameArea>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameArea__reference, tolua_set_Pointer_CGameArea__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CGameArea__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameArea__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameArea>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<const CPoint>", "Pointer<const CPoint>", {}, NULL);
	tolua_beginmodule(L, "Pointer<const CPoint>");
		tolua_variable(L, "reference", tolua_get_Pointer_const_CPoint__reference, tolua_set_Pointer_const_CPoint__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_const_CPoint__getInternalReference);
		tolua_constant(L, "sizeof", sizeof(Pointer<const CPoint>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<const CAIObjectType>", "Pointer<const CAIObjectType>", {}, NULL);
	tolua_beginmodule(L, "Pointer<const CAIObjectType>");
		tolua_variable(L, "reference", tolua_get_Pointer_const_CAIObjectType__reference, tolua_set_Pointer_const_CAIObjectType__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_const_CAIObjectType__getInternalReference);
		tolua_constant(L, "sizeof", sizeof(Pointer<const CAIObjectType>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CPoint>", "Pointer<CPoint>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CPoint>");
		tolua_variable(L, "reference", tolua_get_Pointer_CPoint__reference, tolua_set_Pointer_CPoint__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CPoint__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CPoint__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CPoint>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CTypedPtrList<CPtrList,long>::CNode>", "Pointer<CTypedPtrList<CPtrList,long>::CNode>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CTypedPtrList<CPtrList,long>::CNode>");
		tolua_variable(L, "reference", tolua_get_Pointer_CTypedPtrList_CPtrList_long___CNode__reference, tolua_set_Pointer_CTypedPtrList_CPtrList_long___CNode__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CTypedPtrList_CPtrList_long___CNode__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CTypedPtrList_CPtrList_long___CNode__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CTypedPtrList<CPtrList,long>::CNode>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<unsigned int>", "Pointer<unsigned int>", {}, NULL);
	tolua_beginmodule(L, "Pointer<unsigned int>");
		tolua_variable(L, "reference", tolua_get_Pointer_unsigned_int__reference, tolua_set_Pointer_unsigned_int__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_unsigned_int__getInternalReference);
		tolua_function(L, "getValue", &tolua_function_Pointer_unsigned_int__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_unsigned_int__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<unsigned int>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<const CString>", "Pointer<const CString>", {}, NULL);
	tolua_beginmodule(L, "Pointer<const CString>");
		tolua_variable(L, "reference", tolua_get_Pointer_const_CString__reference, tolua_set_Pointer_const_CString__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_const_CString__getInternalReference);
		tolua_constant(L, "sizeof", sizeof(Pointer<const CString>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CVidMode>", "Pointer<CVidMode>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CVidMode>");
		tolua_variable(L, "reference", tolua_get_Pointer_CVidMode__reference, tolua_set_Pointer_CVidMode__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CVidMode__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CVidMode__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CVidMode>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<__POSITION>", "Pointer<__POSITION>", {}, NULL);
	tolua_beginmodule(L, "Pointer<__POSITION>");
		tolua_variable(L, "reference", tolua_get_Pointer___POSITION__reference, tolua_set_Pointer___POSITION__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer___POSITION__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer___POSITION__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<__POSITION>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<const CAITrigger>", "Pointer<const CAITrigger>", {}, NULL);
	tolua_beginmodule(L, "Pointer<const CAITrigger>");
		tolua_variable(L, "reference", tolua_get_Pointer_const_CAITrigger__reference, tolua_set_Pointer_const_CAITrigger__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_const_CAITrigger__getInternalReference);
		tolua_constant(L, "sizeof", sizeof(Pointer<const CAITrigger>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameAIBase>", "Pointer<CGameAIBase>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameAIBase>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameAIBase__reference, tolua_set_Pointer_CGameAIBase__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CGameAIBase__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameAIBase__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameAIBase>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<const CAIAction>", "Pointer<const CAIAction>", {}, NULL);
	tolua_beginmodule(L, "Pointer<const CAIAction>");
		tolua_variable(L, "reference", tolua_get_Pointer_const_CAIAction__reference, tolua_set_Pointer_const_CAIAction__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_const_CAIAction__getInternalReference);
		tolua_constant(L, "sizeof", sizeof(Pointer<const CAIAction>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameEffect>", "Pointer<CGameEffect>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameEffect>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameEffect__reference, tolua_set_Pointer_CGameEffect__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CGameEffect__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameEffect__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameEffect>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CResRef>", "Pointer<CResRef>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CResRef>");
		tolua_variable(L, "reference", tolua_get_Pointer_CResRef__reference, tolua_set_Pointer_CResRef__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CResRef__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CResRef__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CResRef>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameObject*>", "Pointer<CGameObject*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameObject*>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameObject___reference, tolua_set_Pointer_CGameObject___reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CGameObject___getInternalReference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CGameObject___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameObject___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameObject*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<Item_effect_st>", "Pointer<Item_effect_st>", {}, NULL);
	tolua_beginmodule(L, "Pointer<Item_effect_st>");
		tolua_variable(L, "reference", tolua_get_Pointer_Item_effect_st__reference, tolua_set_Pointer_Item_effect_st__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_Item_effect_st__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_Item_effect_st__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<Item_effect_st>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<EEex_CInfGame>", "Pointer<EEex_CInfGame>", {}, NULL);
	tolua_beginmodule(L, "Pointer<EEex_CInfGame>");
		tolua_variable(L, "reference", tolua_get_Pointer_CInfGame__reference, tolua_set_Pointer_CInfGame__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CInfGame__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CInfGame__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CInfGame>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<EEex_CScreenWorld>", "Pointer<EEex_CScreenWorld>", {}, NULL);
	tolua_beginmodule(L, "Pointer<EEex_CScreenWorld>");
		tolua_variable(L, "reference", tolua_get_Pointer_CScreenWorld__reference, tolua_set_Pointer_CScreenWorld__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CScreenWorld__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CScreenWorld__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CScreenWorld>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameAnimationType>", "Pointer<CGameAnimationType>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameAnimationType>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameAnimationType__reference, tolua_set_Pointer_CGameAnimationType__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CGameAnimationType__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameAnimationType__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameAnimationType>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CProjectileUnknownPST2>", "Pointer<CProjectileUnknownPST2>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CProjectileUnknownPST2>");
		tolua_variable(L, "reference", tolua_get_Pointer_CProjectileUnknownPST2__reference, tolua_set_Pointer_CProjectileUnknownPST2__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CProjectileUnknownPST2__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CProjectileUnknownPST2__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CProjectileUnknownPST2>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CInfinity>", "Pointer<CInfinity>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CInfinity>");
		tolua_variable(L, "reference", tolua_get_Pointer_CInfinity__reference, tolua_set_Pointer_CInfinity__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CInfinity__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CInfinity__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CInfinity>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CVidCell>", "Pointer<CVidCell>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CVidCell>");
		tolua_variable(L, "reference", tolua_get_Pointer_CVidCell__reference, tolua_set_Pointer_CVidCell__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CVidCell__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CVidCell__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CVidCell>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CPtrList_CNode>", "Pointer<CPtrList_CNode>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CPtrList_CNode>");
		tolua_variable(L, "reference", tolua_get_Pointer_CPtrList_CNode__reference, tolua_set_Pointer_CPtrList_CNode__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CPtrList_CNode__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CPtrList_CNode__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CPtrList_CNode>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<int>", "Pointer<int>", {}, NULL);
	tolua_beginmodule(L, "Pointer<int>");
		tolua_variable(L, "reference", tolua_get_Pointer_int__reference, tolua_set_Pointer_int__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_int__getInternalReference);
		tolua_function(L, "getValue", &tolua_function_Pointer_int__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_int__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<int>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CSoundImp>", "Pointer<CSoundImp>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CSoundImp>");
		tolua_variable(L, "reference", tolua_get_Pointer_CSoundImp__reference, tolua_set_Pointer_CSoundImp__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CSoundImp__getInternalReference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CSoundImp__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CSoundImp>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CAreaTintOverride>", "Pointer<CAreaTintOverride>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CAreaTintOverride>");
		tolua_variable(L, "reference", tolua_get_Pointer_CAreaTintOverride__reference, tolua_set_Pointer_CAreaTintOverride__reference);
		tolua_function(L, "getInternalReference", &tolua_function_Pointer_CAreaTintOverride__getInternalReference);
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
	tolua_cclass(L, "Pointer<void*>", "Pointer<void*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<void*>");
		tolua_variable(L, "reference", tolua_get_Pointer_void___reference, tolua_set_Pointer_void___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_void___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_void___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<void*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<unsigned __int8>", "Pointer<unsigned __int8>", {}, NULL);
	tolua_beginmodule(L, "Pointer<unsigned __int8>");
		tolua_variable(L, "reference", tolua_get_Pointer_unsigned___int8__reference, tolua_set_Pointer_unsigned___int8__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_unsigned___int8__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_unsigned___int8__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<unsigned __int8>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<__int8>", "Pointer<__int8>", {}, NULL);
	tolua_beginmodule(L, "Pointer<__int8>");
		tolua_variable(L, "reference", tolua_get_Pointer___int8__reference, tolua_set_Pointer___int8__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer___int8__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer___int8__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<__int8>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<VertListType>", "Pointer<VertListType>", {}, NULL);
	tolua_beginmodule(L, "Pointer<VertListType>");
		tolua_variable(L, "reference", tolua_get_Pointer_VertListType__reference, tolua_set_Pointer_VertListType__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_VertListType__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_VertListType__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<VertListType>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CGameObjectType>", "Pointer<CGameObjectType>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameObjectType>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameObjectType__reference, tolua_set_Pointer_CGameObjectType__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_CGameObjectType__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameObjectType__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameObjectType>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<byte>", "Pointer<byte>", {}, NULL);
	tolua_beginmodule(L, "Pointer<byte>");
		tolua_variable(L, "reference", tolua_get_Pointer_byte__reference, tolua_set_Pointer_byte__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_byte__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_byte__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<byte>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<byte*>", "Pointer<byte*>", {}, NULL);
	tolua_beginmodule(L, "Pointer<byte*>");
		tolua_variable(L, "reference", tolua_get_Pointer_byte___reference, tolua_set_Pointer_byte___reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_byte___getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_byte___setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<byte*>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<EEex_CTimerWorld>", "Pointer<EEex_CTimerWorld>", {}, NULL);
	tolua_beginmodule(L, "Pointer<EEex_CTimerWorld>");
		tolua_variable(L, "reference", tolua_get_Pointer_CTimerWorld__reference, tolua_set_Pointer_CTimerWorld__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CTimerWorld__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CTimerWorld>));
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
	tolua_cclass(L, "Pointer<CGameEffectList>", "Pointer<CGameEffectList>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CGameEffectList>");
		tolua_variable(L, "reference", tolua_get_Pointer_CGameEffectList__reference, tolua_set_Pointer_CGameEffectList__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CGameEffectList__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CGameEffectList>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<intptr_t>", "Pointer<intptr_t>", {}, NULL);
	tolua_beginmodule(L, "Pointer<intptr_t>");
		tolua_variable(L, "reference", tolua_get_Pointer_intptr_t__reference, tolua_set_Pointer_intptr_t__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_intptr_t__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_intptr_t__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<intptr_t>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<long>", "Pointer<long>", {}, NULL);
	tolua_beginmodule(L, "Pointer<long>");
		tolua_variable(L, "reference", tolua_get_Pointer_long__reference, tolua_set_Pointer_long__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_long__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_long__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<long>));
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
	tolua_cclass(L, "Pointer<short>", "Pointer<short>", {}, NULL);
	tolua_beginmodule(L, "Pointer<short>");
		tolua_variable(L, "reference", tolua_get_Pointer_short__reference, tolua_set_Pointer_short__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_short__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_short__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<short>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<size_t>", "Pointer<size_t>", {}, NULL);
	tolua_beginmodule(L, "Pointer<size_t>");
		tolua_variable(L, "reference", tolua_get_Pointer_size_t__reference, tolua_set_Pointer_size_t__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_size_t__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_size_t__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<size_t>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<uint>", "Pointer<uint>", {}, NULL);
	tolua_beginmodule(L, "Pointer<uint>");
		tolua_variable(L, "reference", tolua_get_Pointer_uint__reference, tolua_set_Pointer_uint__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_uint__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_uint__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<uint>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<ushort>", "Pointer<ushort>", {}, NULL);
	tolua_beginmodule(L, "Pointer<ushort>");
		tolua_variable(L, "reference", tolua_get_Pointer_ushort__reference, tolua_set_Pointer_ushort__reference);
		tolua_function(L, "getValue", &tolua_function_Pointer_ushort__getValue);
		tolua_function(L, "setValue", &tolua_function_Pointer_ushort__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<ushort>));
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
	tolua_cclass(L, "Pointer<CAIObjectType>", "Pointer<CAIObjectType>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CAIObjectType>");
		tolua_variable(L, "reference", tolua_get_Pointer_CAIObjectType__reference, tolua_set_Pointer_CAIObjectType__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CAIObjectType__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CAIObjectType>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CProjectile>", "Pointer<CProjectile>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CProjectile>");
		tolua_variable(L, "reference", tolua_get_Pointer_CProjectile__reference, tolua_set_Pointer_CProjectile__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CProjectile__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CProjectile>));
	tolua_endmodule(L);
	tolua_cclass(L, "Pointer<CProjectileBAM>", "Pointer<CProjectileBAM>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CProjectileBAM>");
		tolua_variable(L, "reference", tolua_get_Pointer_CProjectileBAM__reference, tolua_set_Pointer_CProjectileBAM__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CProjectileBAM__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CProjectileBAM>));
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
	tolua_cclass(L, "Pointer<CAITrigger>", "Pointer<CAITrigger>", {}, NULL);
	tolua_beginmodule(L, "Pointer<CAITrigger>");
		tolua_variable(L, "reference", tolua_get_Pointer_CAITrigger__reference, tolua_set_Pointer_CAITrigger__reference);
		tolua_function(L, "setValue", &tolua_function_Pointer_CAITrigger__setValue);
		tolua_constant(L, "sizeof", sizeof(Pointer<CAITrigger>));
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
		tolua_function(L, "getInternalReference", &tolua_function_CString_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CString));
	tolua_endmodule(L);
	tolua_cclass(L, "CObject", "CObject", {}, NULL);
	tolua_beginmodule(L, "CObject");
		tolua_function(L, "getInternalReference", &tolua_function_CObject_getInternalReference);
		tolua_function(L, "virtual_Destruct", &tolua_function_CObject_virtual_Destruct);
		tolua_constant(L, "sizeof", sizeof(CObject));
	tolua_endmodule(L);
	tolua_cclass(L, "CObject::vtbl", "CObject::vtbl", {}, NULL);
	tolua_beginmodule(L, "CObject::vtbl");
		tolua_variable(L, "Destruct", tolua_get_CObject__vtbl_Destruct, tolua_set_CObject__vtbl_Destruct);
		tolua_function(L, "getInternalReference", &tolua_function_CObject__vtbl_getInternalReference);
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
		tolua_function(L, "getInternalReference", &tolua_function_CTypedPtrList_CPtrList_long__getInternalReference);
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
		tolua_function(L, "getInternalReference", &tolua_function_CTypedPtrList_CPtrList_long___CNode_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CTypedPtrList<CPtrList,long>::CNode));
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
		tolua_function(L, "getInternalReference", &tolua_function_CTypedPtrList_CPtrList_int___getInternalReference);
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
		tolua_function(L, "getInternalReference", &tolua_function_CTypedPtrList_CPtrList_int____CNode_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CTypedPtrList<CPtrList,int*>::CNode));
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
		tolua_function(L, "getInternalReference", &tolua_function_CTypedPtrList_CPtrList_int__getInternalReference);
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
		tolua_function(L, "getInternalReference", &tolua_function_CTypedPtrList_CPtrList_int___CNode_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CTypedPtrList<CPtrList,int>::CNode));
	tolua_endmodule(L);
	tolua_cclass(L, "CAreaTintOverride", "CAreaTintOverride", {}, NULL);
	tolua_beginmodule(L, "CAreaTintOverride");
		tolua_variable(L, "vfptr", tolua_get_CAreaTintOverride_vfptr, NULL);
		tolua_variable(L, "pInfinity", tolua_get_CAreaTintOverride_pInfinity, tolua_set_CAreaTintOverride_pInfinity);
		tolua_variable(L, "reference_pInfinity", tolua_get_CAreaTintOverride_reference_pInfinity, NULL);
		tolua_variable(L, "pVidMode", tolua_get_CAreaTintOverride_pVidMode, tolua_set_CAreaTintOverride_pVidMode);
		tolua_variable(L, "reference_pVidMode", tolua_get_CAreaTintOverride_reference_pVidMode, NULL);
		tolua_variable(L, "nMode1", tolua_get_CAreaTintOverride_nMode1, tolua_set_CAreaTintOverride_nMode1);
		tolua_variable(L, "reference_nMode1", tolua_get_CAreaTintOverride_reference_nMode1, NULL);
		tolua_variable(L, "nMode2", tolua_get_CAreaTintOverride_nMode2, tolua_set_CAreaTintOverride_nMode2);
		tolua_variable(L, "reference_nMode2", tolua_get_CAreaTintOverride_reference_nMode2, NULL);
		tolua_variable(L, "nDuration", tolua_get_CAreaTintOverride_nDuration, tolua_set_CAreaTintOverride_nDuration);
		tolua_variable(L, "reference_nDuration", tolua_get_CAreaTintOverride_reference_nDuration, NULL);
		tolua_variable(L, "unknownTint1", tolua_get_CAreaTintOverride_unknownTint1, tolua_set_CAreaTintOverride_unknownTint1);
		tolua_variable(L, "reference_unknownTint1", tolua_get_CAreaTintOverride_reference_unknownTint1, NULL);
		tolua_variable(L, "unknownTint1Red", tolua_get_CAreaTintOverride_unknownTint1Red, tolua_set_CAreaTintOverride_unknownTint1Red);
		tolua_variable(L, "reference_unknownTint1Red", tolua_get_CAreaTintOverride_reference_unknownTint1Red, NULL);
		tolua_variable(L, "unknownTint1Green", tolua_get_CAreaTintOverride_unknownTint1Green, tolua_set_CAreaTintOverride_unknownTint1Green);
		tolua_variable(L, "reference_unknownTint1Green", tolua_get_CAreaTintOverride_reference_unknownTint1Green, NULL);
		tolua_variable(L, "unknownTint1Blue", tolua_get_CAreaTintOverride_unknownTint1Blue, tolua_set_CAreaTintOverride_unknownTint1Blue);
		tolua_variable(L, "reference_unknownTint1Blue", tolua_get_CAreaTintOverride_reference_unknownTint1Blue, NULL);
		tolua_variable(L, "unknownTint2", tolua_get_CAreaTintOverride_unknownTint2, tolua_set_CAreaTintOverride_unknownTint2);
		tolua_variable(L, "reference_unknownTint2", tolua_get_CAreaTintOverride_reference_unknownTint2, NULL);
		tolua_variable(L, "unknownTint2Red", tolua_get_CAreaTintOverride_unknownTint2Red, tolua_set_CAreaTintOverride_unknownTint2Red);
		tolua_variable(L, "reference_unknownTint2Red", tolua_get_CAreaTintOverride_reference_unknownTint2Red, NULL);
		tolua_variable(L, "unknownTint2Green", tolua_get_CAreaTintOverride_unknownTint2Green, tolua_set_CAreaTintOverride_unknownTint2Green);
		tolua_variable(L, "reference_unknownTint2Green", tolua_get_CAreaTintOverride_reference_unknownTint2Green, NULL);
		tolua_variable(L, "unknownTint2Blue", tolua_get_CAreaTintOverride_unknownTint2Blue, tolua_set_CAreaTintOverride_unknownTint2Blue);
		tolua_variable(L, "reference_unknownTint2Blue", tolua_get_CAreaTintOverride_reference_unknownTint2Blue, NULL);
		tolua_variable(L, "unknownTint3", tolua_get_CAreaTintOverride_unknownTint3, tolua_set_CAreaTintOverride_unknownTint3);
		tolua_variable(L, "reference_unknownTint3", tolua_get_CAreaTintOverride_reference_unknownTint3, NULL);
		tolua_variable(L, "unknownTint4", tolua_get_CAreaTintOverride_unknownTint4, tolua_set_CAreaTintOverride_unknownTint4);
		tolua_variable(L, "reference_unknownTint4", tolua_get_CAreaTintOverride_reference_unknownTint4, NULL);
		tolua_variable(L, "unknownTint5", tolua_get_CAreaTintOverride_unknownTint5, tolua_set_CAreaTintOverride_unknownTint5);
		tolua_variable(L, "reference_unknownTint5", tolua_get_CAreaTintOverride_reference_unknownTint5, NULL);
		tolua_variable(L, "nStartingGlobalLighting", tolua_get_CAreaTintOverride_nStartingGlobalLighting, tolua_set_CAreaTintOverride_nStartingGlobalLighting);
		tolua_variable(L, "reference_nStartingGlobalLighting", tolua_get_CAreaTintOverride_reference_nStartingGlobalLighting, NULL);
		tolua_variable(L, "globaTint", tolua_get_CAreaTintOverride_globaTint, tolua_set_CAreaTintOverride_globaTint);
		tolua_variable(L, "reference_globaTint", tolua_get_CAreaTintOverride_reference_globaTint, NULL);
		tolua_variable(L, "globalTintRed", tolua_get_CAreaTintOverride_globalTintRed, tolua_set_CAreaTintOverride_globalTintRed);
		tolua_variable(L, "reference_globalTintRed", tolua_get_CAreaTintOverride_reference_globalTintRed, NULL);
		tolua_variable(L, "globalTintGreen", tolua_get_CAreaTintOverride_globalTintGreen, tolua_set_CAreaTintOverride_globalTintGreen);
		tolua_variable(L, "reference_globalTintGreen", tolua_get_CAreaTintOverride_reference_globalTintGreen, NULL);
		tolua_variable(L, "globalTintBlue", tolua_get_CAreaTintOverride_globalTintBlue, tolua_set_CAreaTintOverride_globalTintBlue);
		tolua_variable(L, "reference_globalTintBlue", tolua_get_CAreaTintOverride_reference_globalTintBlue, NULL);
		tolua_variable(L, "targetType", tolua_get_CAreaTintOverride_targetType, tolua_set_CAreaTintOverride_targetType);
		tolua_variable(L, "reference_targetType", tolua_get_CAreaTintOverride_reference_targetType, NULL);
		tolua_variable(L, "nSourceId", tolua_get_CAreaTintOverride_nSourceId, tolua_set_CAreaTintOverride_nSourceId);
		tolua_variable(L, "reference_nSourceId", tolua_get_CAreaTintOverride_reference_nSourceId, NULL);
		tolua_variable(L, "unknown", tolua_get_CAreaTintOverride_unknown, tolua_set_CAreaTintOverride_unknown);
		tolua_variable(L, "reference_unknown", tolua_get_CAreaTintOverride_reference_unknown, NULL);
		tolua_variable(L, "spritesWithSuppressedTintsList", tolua_get_CAreaTintOverride_spritesWithSuppressedTintsList, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CAreaTintOverride_getInternalReference);
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
		tolua_variable(L, "mpSpawner", tolua_get_CGameArea_mpSpawner, tolua_set_CGameArea_mpSpawner);
		tolua_variable(L, "reference_mpSpawner", tolua_get_CGameArea_reference_mpSpawner, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CGameArea_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CGameArea));
	tolua_endmodule(L);
	tolua_cclass(L, "Array<uchar,8>", "Array<uchar,8>", {}, NULL);
	tolua_beginmodule(L, "Array<uchar,8>");
		tolua_function(L, "getReference", &tolua_function_Array_uchar_8__getReference);
		tolua_function(L, "set", &tolua_function_Array_uchar_8__set);
		tolua_constant(L, "sizeof", sizeof(Array<uchar,8>));
	tolua_endmodule(L);
	tolua_cclass(L, "Array<CProjectileUnknownPST2*,10>", "Array<CProjectileUnknownPST2*,10>", {}, NULL);
	tolua_beginmodule(L, "Array<CProjectileUnknownPST2*,10>");
		tolua_function(L, "get", &tolua_function_Array_CProjectileUnknownPST2__10__get);
		tolua_function(L, "getReference", &tolua_function_Array_CProjectileUnknownPST2__10__getReference);
		tolua_function(L, "set", &tolua_function_Array_CProjectileUnknownPST2__10__set);
		tolua_constant(L, "sizeof", sizeof(Array<CProjectileUnknownPST2*,10>));
	tolua_endmodule(L);
	tolua_cclass(L, "Array<ulong,15>", "Array<ulong,15>", {}, NULL);
	tolua_beginmodule(L, "Array<ulong,15>");
		tolua_function(L, "getReference", &tolua_function_Array_ulong_15__getReference);
		tolua_function(L, "set", &tolua_function_Array_ulong_15__set);
		tolua_constant(L, "sizeof", sizeof(Array<ulong,15>));
	tolua_endmodule(L);
	tolua_cclass(L, "Array<char,32>", "Array<char,32>", {}, NULL);
	tolua_beginmodule(L, "Array<char,32>");
		tolua_function(L, "get", &tolua_function_Array_char_32__get);
		tolua_function(L, "set", &tolua_function_Array_char_32__set);
		tolua_constant(L, "sizeof", sizeof(Array<char,32>));
	tolua_endmodule(L);
	tolua_cclass(L, "Array<CGameArea*,12>", "Array<CGameArea*,12>", {}, NULL);
	tolua_beginmodule(L, "Array<CGameArea*,12>");
		tolua_function(L, "get", &tolua_function_Array_CGameArea__12__get);
		tolua_function(L, "getReference", &tolua_function_Array_CGameArea__12__getReference);
		tolua_function(L, "set", &tolua_function_Array_CGameArea__12__set);
		tolua_constant(L, "sizeof", sizeof(Array<CGameArea*,12>));
	tolua_endmodule(L);
	tolua_cclass(L, "Array<long,6>", "Array<long,6>", {}, NULL);
	tolua_beginmodule(L, "Array<long,6>");
		tolua_function(L, "get", &tolua_function_Array_long_6__get);
		tolua_function(L, "getReference", &tolua_function_Array_long_6__getReference);
		tolua_function(L, "set", &tolua_function_Array_long_6__set);
		tolua_constant(L, "sizeof", sizeof(Array<long,6>));
	tolua_endmodule(L);
	tolua_cclass(L, "Array<ulong,8>", "Array<ulong,8>", {}, NULL);
	tolua_beginmodule(L, "Array<ulong,8>");
		tolua_function(L, "getReference", &tolua_function_Array_ulong_8__getReference);
		tolua_function(L, "set", &tolua_function_Array_ulong_8__set);
		tolua_constant(L, "sizeof", sizeof(Array<ulong,8>));
	tolua_endmodule(L);
	tolua_cclass(L, "Array<byte,5>", "Array<byte,5>", {}, NULL);
	tolua_beginmodule(L, "Array<byte,5>");
		tolua_function(L, "get", &tolua_function_Array_byte_5__get);
		tolua_function(L, "getReference", &tolua_function_Array_byte_5__getReference);
		tolua_function(L, "set", &tolua_function_Array_byte_5__set);
		tolua_constant(L, "sizeof", sizeof(Array<byte,5>));
	tolua_endmodule(L);
	tolua_cclass(L, "LCharString<32>", "LCharString<32>", {}, NULL);
	tolua_beginmodule(L, "LCharString<32>");
		tolua_function(L, "getInternalReference", &tolua_function_LCharString_32__getInternalReference);
		tolua_function(L, "getChar", &tolua_function_LCharString_32__getChar);
		tolua_function(L, "setChar", &tolua_function_LCharString_32__setChar);
		tolua_function(L, "set", &tolua_function_LCharString_32__set);
		tolua_function(L, "get", &tolua_function_LCharString_32__get);
		tolua_constant(L, "sizeof", sizeof(LCharString<32>));
	tolua_endmodule(L);
	tolua_cclass(L, "CResRef", "CResRef", {}, NULL);
	tolua_beginmodule(L, "CResRef");
		tolua_variable(L, "m_resRef", tolua_get_CResRef_m_resRef, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CResRef_getInternalReference);
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
		tolua_function(L, "getInternalReference", &tolua_function_Item_effect_st_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(Item_effect_st));
	tolua_endmodule(L);
	tolua_cclass(L, "CResHelper<CResCell,1000>", "CResHelper<CResCell,1000>", {}, NULL);
	tolua_beginmodule(L, "CResHelper<CResCell,1000>");
		tolua_variable(L, "pRes", tolua_get_CResHelper_CResCell_1000__pRes, tolua_set_CResHelper_CResCell_1000__pRes);
		tolua_variable(L, "reference_pRes", tolua_get_CResHelper_CResCell_1000__reference_pRes, NULL);
		tolua_variable(L, "cResRef", tolua_get_CResHelper_CResCell_1000__cResRef, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CResHelper_CResCell_1000__getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CResHelper<CResCell,1000>));
	tolua_endmodule(L);
	tolua_cclass(L, "CVidCell", "CVidCell", {}, NULL);
	tolua_beginmodule(L, "CVidCell");
		tolua_variable(L, "__vftable", tolua_get_CVidCell___vftable, NULL);
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
		tolua_function(L, "getInternalReference", &tolua_function_CVidCell_getInternalReference);
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
		tolua_function(L, "getInternalReference", &tolua_function_CInfGame_getInternalReference);
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
		tolua_function(L, "getInternalReference", &tolua_function_CGameEffectBase_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CGameEffectBase));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameEffect", "CGameEffect", {"CGameEffectBase"}, NULL);
	tolua_beginmodule(L, "CGameEffect");
		tolua_variable(L, "__vftable", tolua_get_CGameEffect___vftable, NULL);
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
		tolua_variable(L, "reference_DecodeEffect", tolua_get_reference_CGameEffect_DecodeEffect, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CGameEffect_getInternalReference);
		tolua_function(L, "DecodeEffect", &tolua_function_CGameEffect_DecodeEffect);
		tolua_constant(L, "sizeof", sizeof(CGameEffect));
	tolua_endmodule(L);
	tolua_cclass(L, "CDerivedStats", "CDerivedStats", {}, NULL);
	tolua_beginmodule(L, "CDerivedStats");
		tolua_variable(L, "m_generalState", tolua_get_CDerivedStats_m_generalState, tolua_set_CDerivedStats_m_generalState);
		tolua_variable(L, "reference_m_generalState", tolua_get_CDerivedStats_reference_m_generalState, NULL);
		tolua_variable(L, "m_nLuck", tolua_get_CDerivedStats_m_nLuck, tolua_set_CDerivedStats_m_nLuck);
		tolua_variable(L, "reference_m_nLuck", tolua_get_CDerivedStats_reference_m_nLuck, NULL);
		tolua_variable(L, "m_appliedColorEffects", tolua_get_CDerivedStats_m_appliedColorEffects, NULL);
		tolua_variable(L, "m_spellStates", tolua_get_CDerivedStats_m_spellStates, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CDerivedStats_getInternalReference);
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
		tolua_function(L, "getInternalReference", &tolua_function_CAreaVariable_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CAreaVariable));
	tolua_endmodule(L);
	tolua_cclass(L, "CVariable", "CVariable", {"CAreaVariable"}, NULL);
	tolua_beginmodule(L, "CVariable");
		tolua_function(L, "getInternalReference", &tolua_function_CVariable_getInternalReference);
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
		tolua_function(L, "getInternalReference", &tolua_function_CAIObjectType_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CAIObjectType));
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
		tolua_function(L, "getInternalReference", &tolua_function_CGameObject_getInternalReference);
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
		tolua_variable(L, "AddToArea", tolua_get_CGameObject__vtbl_AddToArea, tolua_set_CGameObject__vtbl_AddToArea);
		tolua_variable(L, "AIUpdate", tolua_get_CGameObject__vtbl_AIUpdate, tolua_set_CGameObject__vtbl_AIUpdate);
		tolua_variable(L, "GetAIType", tolua_get_CGameObject__vtbl_GetAIType, tolua_set_CGameObject__vtbl_GetAIType);
		tolua_variable(L, "GetTargetId", tolua_get_CGameObject__vtbl_GetTargetId, tolua_set_CGameObject__vtbl_GetTargetId);
		tolua_variable(L, "GetNextWaypoint", tolua_get_CGameObject__vtbl_GetNextWaypoint, tolua_set_CGameObject__vtbl_GetNextWaypoint);
		tolua_variable(L, "GetVertListPos", tolua_get_CGameObject__vtbl_GetVertListPos, tolua_set_CGameObject__vtbl_GetVertListPos);
		tolua_variable(L, "GetVertListType", tolua_get_CGameObject__vtbl_GetVertListType, tolua_set_CGameObject__vtbl_GetVertListType);
		tolua_variable(L, "CanSaveGame", tolua_get_CGameObject__vtbl_CanSaveGame, tolua_set_CGameObject__vtbl_CanSaveGame);
		tolua_variable(L, "CompressTime", tolua_get_CGameObject__vtbl_CompressTime, tolua_set_CGameObject__vtbl_CompressTime);
		tolua_variable(L, "DebugDump", tolua_get_CGameObject__vtbl_DebugDump, tolua_set_CGameObject__vtbl_DebugDump);
		tolua_variable(L, "IsOver", tolua_get_CGameObject__vtbl_IsOver, tolua_set_CGameObject__vtbl_IsOver);
		tolua_variable(L, "DoesIntersect", tolua_get_CGameObject__vtbl_DoesIntersect, tolua_set_CGameObject__vtbl_DoesIntersect);
		tolua_variable(L, "OnSearchMap", tolua_get_CGameObject__vtbl_OnSearchMap, tolua_set_CGameObject__vtbl_OnSearchMap);
		tolua_variable(L, "OnActionButton", tolua_get_CGameObject__vtbl_OnActionButton, tolua_set_CGameObject__vtbl_OnActionButton);
		tolua_variable(L, "OnFormationButton", tolua_get_CGameObject__vtbl_OnFormationButton, tolua_set_CGameObject__vtbl_OnFormationButton);
		tolua_variable(L, "RemoveFromArea", tolua_get_CGameObject__vtbl_RemoveFromArea, tolua_set_CGameObject__vtbl_RemoveFromArea);
		tolua_variable(L, "Render", tolua_get_CGameObject__vtbl_Render, tolua_set_CGameObject__vtbl_Render);
		tolua_variable(L, "DoAIUpdate", tolua_get_CGameObject__vtbl_DoAIUpdate, tolua_set_CGameObject__vtbl_DoAIUpdate);
		tolua_variable(L, "SetAIType", tolua_get_CGameObject__vtbl_SetAIType, tolua_set_CGameObject__vtbl_SetAIType);
		tolua_variable(L, "SetCursor", tolua_get_CGameObject__vtbl_SetCursor, tolua_set_CGameObject__vtbl_SetCursor);
		tolua_variable(L, "SetTarget", tolua_get_CGameObject__vtbl_SetTarget, tolua_set_CGameObject__vtbl_SetTarget);
		tolua_variable(L, "SetVertListPos", tolua_get_CGameObject__vtbl_SetVertListPos, tolua_set_CGameObject__vtbl_SetVertListPos);
		tolua_variable(L, "EvaluateStatusTrigger", tolua_get_CGameObject__vtbl_EvaluateStatusTrigger, tolua_set_CGameObject__vtbl_EvaluateStatusTrigger);
		tolua_function(L, "getInternalReference", &tolua_function_CGameObject__vtbl_getInternalReference);
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
		tolua_function(L, "getInternalReference", &tolua_function_CProjectile_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CProjectile));
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
		tolua_function(L, "getInternalReference", &tolua_function_CProjectileBAM_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CProjectileBAM));
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileArea", "CProjectileArea", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileArea");
		tolua_variable(L, "m_coneSize", tolua_get_CProjectileArea_m_coneSize, tolua_set_CProjectileArea_m_coneSize);
		tolua_variable(L, "reference_m_coneSize", tolua_get_CProjectileArea_reference_m_coneSize, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CProjectileArea_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CProjectileArea));
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileUnknownPST", "CProjectileUnknownPST", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileUnknownPST");
		tolua_variable(L, "pInfinity", tolua_get_CProjectileUnknownPST_pInfinity, tolua_set_CProjectileUnknownPST_pInfinity);
		tolua_variable(L, "reference_pInfinity", tolua_get_CProjectileUnknownPST_reference_pInfinity, NULL);
		tolua_variable(L, "nUnknownMode", tolua_get_CProjectileUnknownPST_nUnknownMode, tolua_set_CProjectileUnknownPST_nUnknownMode);
		tolua_variable(L, "reference_nUnknownMode", tolua_get_CProjectileUnknownPST_reference_nUnknownMode, NULL);
		tolua_variable(L, "nExpirationTime", tolua_get_CProjectileUnknownPST_nExpirationTime, tolua_set_CProjectileUnknownPST_nExpirationTime);
		tolua_variable(L, "reference_nExpirationTime", tolua_get_CProjectileUnknownPST_reference_nExpirationTime, NULL);
		tolua_variable(L, "bSuppressFireSound", tolua_get_CProjectileUnknownPST_bSuppressFireSound, tolua_set_CProjectileUnknownPST_bSuppressFireSound);
		tolua_variable(L, "reference_bSuppressFireSound", tolua_get_CProjectileUnknownPST_reference_bSuppressFireSound, NULL);
		tolua_variable(L, "nDelayedRemoveSpeed", tolua_get_CProjectileUnknownPST_nDelayedRemoveSpeed, tolua_set_CProjectileUnknownPST_nDelayedRemoveSpeed);
		tolua_variable(L, "reference_nDelayedRemoveSpeed", tolua_get_CProjectileUnknownPST_reference_nDelayedRemoveSpeed, NULL);
		tolua_variable(L, "bDelayedRemoveScheduled", tolua_get_CProjectileUnknownPST_bDelayedRemoveScheduled, tolua_set_CProjectileUnknownPST_bDelayedRemoveScheduled);
		tolua_variable(L, "reference_bDelayedRemoveScheduled", tolua_get_CProjectileUnknownPST_reference_bDelayedRemoveScheduled, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CProjectileUnknownPST_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CProjectileUnknownPST));
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileUnknownPST2", "CProjectileUnknownPST2", {"CProjectileUnknownPST"}, NULL);
	tolua_beginmodule(L, "CProjectileUnknownPST2");
		tolua_variable(L, "bRemoveOnNextUpdate", tolua_get_CProjectileUnknownPST2_bRemoveOnNextUpdate, tolua_set_CProjectileUnknownPST2_bRemoveOnNextUpdate);
		tolua_variable(L, "reference_bRemoveOnNextUpdate", tolua_get_CProjectileUnknownPST2_reference_bRemoveOnNextUpdate, NULL);
		tolua_variable(L, "nTypePST", tolua_get_CProjectileUnknownPST2_nTypePST, tolua_set_CProjectileUnknownPST2_nTypePST);
		tolua_variable(L, "reference_nTypePST", tolua_get_CProjectileUnknownPST2_reference_nTypePST, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CProjectileUnknownPST2_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CProjectileUnknownPST2));
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileUnknownBase", "CProjectileUnknownBase", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileUnknownBase");
		tolua_function(L, "getInternalReference", &tolua_function_CProjectileUnknownBase_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CProjectileUnknownBase));
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectile205", "CProjectile205", {"CProjectileUnknownBase"}, NULL);
	tolua_beginmodule(L, "CProjectile205");
		tolua_variable(L, "bHitTarget", tolua_get_CProjectile205_bHitTarget, tolua_set_CProjectile205_bHitTarget);
		tolua_variable(L, "reference_bHitTarget", tolua_get_CProjectile205_reference_bHitTarget, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CProjectile205_getInternalReference);
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
		tolua_function(L, "getInternalReference", &tolua_function_CAITrigger_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CAITrigger));
	tolua_endmodule(L);
	tolua_cclass(L, "CMessageSetTrigger", "CMessageSetTrigger", {"CMessage"}, NULL);
	tolua_beginmodule(L, "CMessageSetTrigger");
		tolua_variable(L, "m_trigger", tolua_get_CMessageSetTrigger_m_trigger, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CMessageSetTrigger_getInternalReference);
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
		tolua_variable(L, "m_actionCount", tolua_get_CGameAIBase_m_actionCount, tolua_set_CGameAIBase_m_actionCount);
		tolua_variable(L, "reference_m_actionCount", tolua_get_CGameAIBase_reference_m_actionCount, NULL);
		tolua_variable(L, "triggerOverride", tolua_get_CGameAIBase_triggerOverride, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CGameAIBase_getInternalReference);
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
		tolua_variable(L, "FloatMessage", tolua_get_CGameAIBase__vtbl_FloatMessage, tolua_set_CGameAIBase__vtbl_FloatMessage);
		tolua_variable(L, "KillFloatMessage", tolua_get_CGameAIBase__vtbl_KillFloatMessage, tolua_set_CGameAIBase__vtbl_KillFloatMessage);
		tolua_variable(L, "UpdateTarget", tolua_get_CGameAIBase__vtbl_UpdateTarget, tolua_set_CGameAIBase__vtbl_UpdateTarget);
		tolua_variable(L, "AddAction", tolua_get_CGameAIBase__vtbl_AddAction, tolua_set_CGameAIBase__vtbl_AddAction);
		tolua_variable(L, "AddEffect", tolua_get_CGameAIBase__vtbl_AddEffect, tolua_set_CGameAIBase__vtbl_AddEffect);
		tolua_function(L, "getInternalReference", &tolua_function_CGameAIBase__vtbl_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CGameAIBase::vtbl));
	tolua_endmodule(L);
	tolua_cclass(L, "CGameSprite", "CGameSprite", {"CGameAIBase"}, NULL);
	tolua_beginmodule(L, "CGameSprite");
		tolua_variable(L, "m_baseStats_m_generalState", tolua_get_CGameSprite_m_baseStats_m_generalState, NULL);
		tolua_variable(L, "m_derivedStats", tolua_get_CGameSprite_m_derivedStats, NULL);
		tolua_variable(L, "m_tempStats", tolua_get_CGameSprite_m_tempStats, NULL);
		tolua_variable(L, "m_animation", tolua_get_CGameSprite_m_animation, NULL);
		tolua_variable(L, "bAllowGlobalOrAreaTintsWhenRendering", tolua_get_CGameSprite_bAllowGlobalOrAreaTintsWhenRendering, tolua_set_CGameSprite_bAllowGlobalOrAreaTintsWhenRendering);
		tolua_variable(L, "reference_bAllowGlobalOrAreaTintsWhenRendering", tolua_get_CGameSprite_reference_bAllowGlobalOrAreaTintsWhenRendering, NULL);
		tolua_variable(L, "m_nMirrorImages", tolua_get_CGameSprite_m_nMirrorImages, tolua_set_CGameSprite_m_nMirrorImages);
		tolua_variable(L, "reference_m_nMirrorImages", tolua_get_CGameSprite_reference_m_nMirrorImages, NULL);
		tolua_variable(L, "unkPSTVisualEffectVar1", tolua_get_CGameSprite_unkPSTVisualEffectVar1, tolua_set_CGameSprite_unkPSTVisualEffectVar1);
		tolua_variable(L, "reference_unkPSTVisualEffectVar1", tolua_get_CGameSprite_reference_unkPSTVisualEffectVar1, NULL);
		tolua_variable(L, "unkPSTVisualEffectVar2", tolua_get_CGameSprite_unkPSTVisualEffectVar2, tolua_set_CGameSprite_unkPSTVisualEffectVar2);
		tolua_variable(L, "reference_unkPSTVisualEffectVar2", tolua_get_CGameSprite_reference_unkPSTVisualEffectVar2, NULL);
		tolua_variable(L, "unkPSTVisualEffectVar3", tolua_get_CGameSprite_unkPSTVisualEffectVar3, tolua_set_CGameSprite_unkPSTVisualEffectVar3);
		tolua_variable(L, "reference_unkPSTVisualEffectVar3", tolua_get_CGameSprite_reference_unkPSTVisualEffectVar3, NULL);
		tolua_variable(L, "unkPSTVisualEffectVar4", tolua_get_CGameSprite_unkPSTVisualEffectVar4, tolua_set_CGameSprite_unkPSTVisualEffectVar4);
		tolua_variable(L, "reference_unkPSTVisualEffectVar4", tolua_get_CGameSprite_reference_unkPSTVisualEffectVar4, NULL);
		tolua_variable(L, "m_bBlur", tolua_get_CGameSprite_m_bBlur, tolua_set_CGameSprite_m_bBlur);
		tolua_variable(L, "reference_m_bBlur", tolua_get_CGameSprite_reference_m_bBlur, NULL);
		tolua_variable(L, "m_bMinorGlobe", tolua_get_CGameSprite_m_bMinorGlobe, tolua_set_CGameSprite_m_bMinorGlobe);
		tolua_variable(L, "reference_m_bMinorGlobe", tolua_get_CGameSprite_reference_m_bMinorGlobe, NULL);
		tolua_variable(L, "m_bShieldGlobe", tolua_get_CGameSprite_m_bShieldGlobe, tolua_set_CGameSprite_m_bShieldGlobe);
		tolua_variable(L, "reference_m_bShieldGlobe", tolua_get_CGameSprite_reference_m_bShieldGlobe, NULL);
		tolua_variable(L, "m_shieldGlobeVidCell", tolua_get_CGameSprite_m_shieldGlobeVidCell, NULL);
		tolua_variable(L, "m_posOld", tolua_get_CGameSprite_m_posOld, NULL);
		tolua_variable(L, "m_posOldWalk", tolua_get_CGameSprite_m_posOldWalk, NULL);
		tolua_variable(L, "m_equipedEffectList", tolua_get_CGameSprite_m_equipedEffectList, NULL);
		tolua_variable(L, "m_timedEffectList", tolua_get_CGameSprite_m_timedEffectList, NULL);
		tolua_variable(L, "m_persistantEffects", tolua_get_CGameSprite_m_persistantEffects, NULL);
		tolua_variable(L, "m_newEffect", tolua_get_CGameSprite_m_newEffect, tolua_set_CGameSprite_m_newEffect);
		tolua_variable(L, "reference_m_newEffect", tolua_get_CGameSprite_reference_m_newEffect, NULL);
		tolua_variable(L, "m_hasColorEffects", tolua_get_CGameSprite_m_hasColorEffects, tolua_set_CGameSprite_m_hasColorEffects);
		tolua_variable(L, "reference_m_hasColorEffects", tolua_get_CGameSprite_reference_m_hasColorEffects, NULL);
		tolua_variable(L, "m_targetId", tolua_get_CGameSprite_m_targetId, tolua_set_CGameSprite_m_targetId);
		tolua_variable(L, "reference_m_targetId", tolua_get_CGameSprite_reference_m_targetId, NULL);
		tolua_variable(L, "m_dialog", tolua_get_CGameSprite_m_dialog, NULL);
		tolua_variable(L, "m_bForceVisualEffects", tolua_get_CGameSprite_m_bForceVisualEffects, tolua_set_CGameSprite_m_bForceVisualEffects);
		tolua_variable(L, "reference_m_bForceVisualEffects", tolua_get_CGameSprite_reference_m_bForceVisualEffects, NULL);
		tolua_variable(L, "m_currentActionId", tolua_get_CGameSprite_m_currentActionId, tolua_set_CGameSprite_m_currentActionId);
		tolua_variable(L, "reference_m_currentActionId", tolua_get_CGameSprite_reference_m_currentActionId, NULL);
		tolua_variable(L, "aPSTVisualEffectProjectiles", tolua_get_CGameSprite_aPSTVisualEffectProjectiles, NULL);
		tolua_variable(L, "nAttachedPSTVisualEffectProjectiles", tolua_get_CGameSprite_nAttachedPSTVisualEffectProjectiles, tolua_set_CGameSprite_nAttachedPSTVisualEffectProjectiles);
		tolua_variable(L, "reference_nAttachedPSTVisualEffectProjectiles", tolua_get_CGameSprite_reference_nAttachedPSTVisualEffectProjectiles, NULL);
		tolua_variable(L, "nPSTVisualEffectsSetToRender", tolua_get_CGameSprite_nPSTVisualEffectsSetToRender, tolua_set_CGameSprite_nPSTVisualEffectsSetToRender);
		tolua_variable(L, "reference_nPSTVisualEffectsSetToRender", tolua_get_CGameSprite_reference_nPSTVisualEffectsSetToRender, NULL);
		tolua_variable(L, "m_savedLocation", tolua_get_CGameSprite_m_savedLocation, NULL);
		tolua_variable(L, "nOverTriggerId", tolua_get_CGameSprite_nOverTriggerId, tolua_set_CGameSprite_nOverTriggerId);
		tolua_variable(L, "reference_nOverTriggerId", tolua_get_CGameSprite_reference_nOverTriggerId, NULL);
		tolua_function(L, "getInternalReference", &tolua_function_CGameSprite_getInternalReference);
		tolua_constant(L, "sizeof", sizeof(CGameSprite));
	tolua_endmodule(L);
	tolua_endmodule(L);
	return 1;
}