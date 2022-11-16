
#include "EEexLua_generated_baseclass_offsets.h"

template<typename Derived, typename Base>
constexpr uintptr_t offsetofbase() {
	return reinterpret_cast<uintptr_t>(static_cast<Base*>(reinterpret_cast<Derived*>(1))) - 1;
}

std::unordered_map<const char*, std::unordered_map<const char*, uintptr_t>> baseclassOffsets {
	{"CGameEffectList", {
		{"CPtrList", offsetofbase<CGameEffectList, CPtrList>()},
	}},
	{"CMessageVisualEffect", {
		{"CMessage", offsetofbase<CMessageVisualEffect, CMessage>()},
	}},
	{"CTypedPtrList<CPtrList,long>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,long>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,int*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,int*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,int>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,int>, CObject>()},
	}},
	{"CGameEffect", {
		{"CGameEffectBase", offsetofbase<CGameEffect, CGameEffectBase>()},
	}},
	{"CVariable", {
		{"CAreaVariable", offsetofbase<CVariable, CAreaVariable>()},
	}},
	{"CGameObject", {
		{"CObject", offsetofbase<CGameObject, CObject>()},
	}},
	{"CGameObject::vtbl", {
		{"CObject::vtbl", offsetofbase<CGameObject::vtbl, CObject::vtbl>()},
	}},
	{"CProjectile", {
		{"CGameObject", offsetofbase<CProjectile, CGameObject>()},
	}},
	{"CProjectileBAM", {
		{"CProjectile", offsetofbase<CProjectileBAM, CProjectile>()},
	}},
	{"CProjectileArea", {
		{"CProjectileBAM", offsetofbase<CProjectileArea, CProjectileBAM>()},
	}},
	{"CProjectileUnknownPST", {
		{"CProjectileBAM", offsetofbase<CProjectileUnknownPST, CProjectileBAM>()},
	}},
	{"CProjectileUnknownPST2", {
		{"CProjectileUnknownPST", offsetofbase<CProjectileUnknownPST2, CProjectileUnknownPST>()},
	}},
	{"CProjectileUnknownBase", {
		{"CProjectileBAM", offsetofbase<CProjectileUnknownBase, CProjectileBAM>()},
	}},
	{"CProjectile205", {
		{"CProjectileUnknownBase", offsetofbase<CProjectile205, CProjectileUnknownBase>()},
	}},
	{"CMessageSetTrigger", {
		{"CMessage", offsetofbase<CMessageSetTrigger, CMessage>()},
	}},
	{"CGameAIBase", {
		{"CGameObject", offsetofbase<CGameAIBase, CGameObject>()},
	}},
	{"CGameAIBase::vtbl", {
		{"CGameObject::vtbl", offsetofbase<CGameAIBase::vtbl, CGameObject::vtbl>()},
	}},
	{"CGameSprite", {
		{"CGameAIBase", offsetofbase<CGameSprite, CGameAIBase>()},
	}},
};
