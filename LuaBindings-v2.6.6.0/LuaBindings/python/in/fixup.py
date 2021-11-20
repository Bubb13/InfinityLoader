
from generate_bindings import relocateGroup

def fixup(mainState):

	relocateGroup(mainState, "$C3D261E28D53B12983426B9B0D118A61", "frameTableEntry_st::$C3D261E28D53B12983426B9B0D118A61")

	mainState.getGroup("SDL_Event").retypeField(mainState, "type", "SDL_EventType")
	mainState.getGroup("SDL_Keysym").retypeField(mainState, "sym", "SDL_Keycode")
	mainState.getGroup("CGameObject").retypeField(mainState, "m_objectType", "CGameObjectType")
	mainState.getGroup("CAIGroup").retypeField(mainState, "m_memberList", "CTypedPtrList<CPtrList,long>")
	mainState.getGroup("CInfButtonArray").retypeField(mainState, "m_nSelectedButton", "CButtonType")
	mainState.getGroup("Spell_ability_st").retypeField(mainState, "quickSlotIcon", "CResRef")
	# TODO: There are several structs where __vftable is supposed to come before any baseclasses; this is broken. 
	#       Some structs also have multiple baseclasses - non-first baseclasses aren't mapped to Lua.
	mainState.getGroup("CGameEffect").removeField("__vftable")
	mainState.getGroup("CGameEffectBase").addVariableField(mainState, "__vftable", "CGameEffect_vtbl*", insertI=0)
