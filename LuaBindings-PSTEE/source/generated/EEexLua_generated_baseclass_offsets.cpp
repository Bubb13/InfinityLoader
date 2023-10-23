
#include "engine_structs_generated.h"

template<typename Derived, typename Base>
constexpr uintptr_t offsetofbase() {
	return reinterpret_cast<uintptr_t>(static_cast<Base*>(reinterpret_cast<Derived*>(1))) - 1;
}

void registerBaseclasses() {
	RegisterBaseclassOffsets({
		{"CMessageVisualEffect", {
			{"CMessage", offsetofbase<CMessageVisualEffect, CMessage>()},
		}},
		{"CMessageAddEffect", {
			{"CMessage", offsetofbase<CMessageAddEffect, CMessage>()},
		}},
		{"CTypedPtrList<CPtrList,long>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,long>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,long>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,long>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CGameEffect*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameEffect*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CGameEffect*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CGameEffect*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,int*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,int*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,int*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,int*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,int>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,int>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,int>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,int>::vtbl, CObject::vtbl>()},
		}},
		{"CGameEffectList", {
			{"CTypedPtrList<CPtrList,CGameEffect*>", offsetofbase<CGameEffectList, CTypedPtrList<CPtrList,CGameEffect*>>()},
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
		{"CProjectile::vtbl", {
			{"CGameObject::vtbl", offsetofbase<CProjectile::vtbl, CGameObject::vtbl>()},
		}},
		{"CProjectileBAM", {
			{"CProjectile", offsetofbase<CProjectileBAM, CProjectile>()},
		}},
		{"CProjectileBAM::vtbl", {
			{"CProjectile::vtbl", offsetofbase<CProjectileBAM::vtbl, CProjectile::vtbl>()},
		}},
		{"CProjectileArea", {
			{"CProjectileBAM", offsetofbase<CProjectileArea, CProjectileBAM>()},
		}},
		{"CProjectileUnknownPST", {
			{"CProjectileBAM", offsetofbase<CProjectileUnknownPST, CProjectileBAM>()},
		}},
		{"CProjectileUnknownPST::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileUnknownPST::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileUnknownPST2", {
			{"CProjectileUnknownPST", offsetofbase<CProjectileUnknownPST2, CProjectileUnknownPST>()},
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
	});
}

