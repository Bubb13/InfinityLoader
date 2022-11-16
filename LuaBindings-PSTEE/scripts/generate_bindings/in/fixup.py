
from generate_bindings import relocateGroup
from generate_bindings import TypeRefSourceType
from generate_bindings import defineTypeRef

def fixup(mainState):

	ref = defineTypeRef(mainState, None, "CGameObject", TypeRefSourceType.VARIABLE)
	mainState.getGroup("Pointer").addTemplateUse( (ref,), 0 )

	group = mainState.getGroup("CGameObjectType")
	group.isDirectlyWanted = True
	mainState.filteredGroups.addUnique(group)

	mainState.getGroup("CGameEffectBase").retypeField(mainState, "m_scriptName", "LCharString<32>")
	mainState.getGroup("Item_effect_st").retypeField(mainState, "res", "CResRef")
	
	pass
