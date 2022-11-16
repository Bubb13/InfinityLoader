
from generate_bindings import relocateGroup

def fixup(mainState):

	relocateGroup(mainState, "$C3D261E28D53B12983426B9B0D118A61", "frameTableEntry_st::$C3D261E28D53B12983426B9B0D118A61")

	mainState.getGroup("C2DArray").retypeField(mainState, "m_pArray", "ArrayPointer<CString>")
	mainState.getGroup("C2DArray").retypeField(mainState, "m_pNamesX", "ArrayPointer<CString>")
	mainState.getGroup("C2DArray").retypeField(mainState, "m_pNamesY", "ArrayPointer<CString>")
	mainState.getGroup("CAIGroup").retypeField(mainState, "m_memberList", "CTypedPtrList<CPtrList,long>")
	mainState.getGroup("CAIIdList").retypeField(mainState, "m_pIdArray", "ArrayPointer<CAIId*>")
	mainState.getGroup("CAreaVariable").retypeField(mainState, "m_name", "LCharString<32>")
	mainState.getGroup("CAreaVariable").retypeField(mainState, "m_stringValue", "LCharString<32>")
	mainState.getGroup("CGameAIBase_vtbl").retypeFunctionFieldRet(mainState, "GetVisibleTerrainTable", "byte*")
	mainState.getGroup("CGameArea").retypeField(mainState, "m_lVertSort", "CTypedPtrList<CPtrList,long>")
	mainState.getGroup("CGameArea").retypeField(mainState, "m_lVertSortBack", "CTypedPtrList<CPtrList,long>")
	mainState.getGroup("CGameArea").retypeField(mainState, "m_lVertSortFlight", "CTypedPtrList<CPtrList,long>")
	mainState.getGroup("CGameArea").retypeField(mainState, "m_lVertSortUnder", "CTypedPtrList<CPtrList,long>")
	mainState.getGroup("CGameEffect_vtbl").addFunctionFieldParameter(mainState, "Destruct", "unsigned int")
	mainState.getGroup("CGameEffectBase").retypeField(mainState, "m_scriptName", "LCharString<32>")
	mainState.getGroup("CGameObject").retypeField(mainState, "m_listType", "VertListType")
	mainState.getGroup("CGameObject").retypeField(mainState, "m_objectType", "CGameObjectType")
	mainState.getGroup("CGameObject_vtbl").retypeFunctionFieldRet(mainState, "GetObjectType", "CGameObjectType")
	mainState.getGroup("CGameObject_vtbl").retypeFunctionFieldRet(mainState, "GetVertListPos", "CTypedPtrList<CPtrList,long>::CNode*")
	mainState.getGroup("CGameObject_vtbl").retypeFunctionFieldRet(mainState, "GetVertListType", "VertListType")
	mainState.getGroup("CInfButtonArray").retypeField(mainState, "m_nSelectedButton", "CButtonType")
	mainState.getGroup("Item_effect_st").retypeField(mainState, "res", "CResRef")
	mainState.getGroup("SDL_Event").retypeField(mainState, "type", "SDL_EventType")
	mainState.getGroup("SDL_Keysym").retypeField(mainState, "sym", "SDL_Keycode")
	mainState.getGroup("Spell_ability_st").retypeField(mainState, "quickSlotIcon", "CResRef")
