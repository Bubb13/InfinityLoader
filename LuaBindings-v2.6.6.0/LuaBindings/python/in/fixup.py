
from generate_bindings import relocateGroup

def fixup(mainState):

	relocateGroup(mainState, "$C3D261E28D53B12983426B9B0D118A61", "frameTableEntry_st::$C3D261E28D53B12983426B9B0D118A61")

	mainState.getGroup("CAIGroup").retypeField(mainState, "m_memberList", "CTypedPtrList<CPtrList,long>")
	mainState.getGroup("CGameEffectBase").retypeField(mainState, "m_scriptName", "LCharString<32>")
	mainState.getGroup("CGameObject").retypeField(mainState, "m_objectType", "CGameObjectType")
	mainState.getGroup("CInfButtonArray").retypeField(mainState, "m_nSelectedButton", "CButtonType")
	mainState.getGroup("Item_effect_st").retypeField(mainState, "res", "CResRef")
	mainState.getGroup("SDL_Event").retypeField(mainState, "type", "SDL_EventType")
	mainState.getGroup("SDL_Keysym").retypeField(mainState, "sym", "SDL_Keycode")
	mainState.getGroup("Spell_ability_st").retypeField(mainState, "quickSlotIcon", "CResRef")
