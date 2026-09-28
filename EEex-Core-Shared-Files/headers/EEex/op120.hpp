#pragma once

#include <memory>

#include "Baldur_generated.h"

// Compiled only by EEex-v2.7.3.0. Effect metadata is deliberately private and
// transient: it is not a new EFF field or a serialized modding interface.
struct Op120Attack;

namespace EEex {

	extern short (*Op120_Original_Swing)(CGameSprite*, CGameSprite*);
	extern void (*Op120_Original_AddEffect)(CGameSprite*, CGameEffect*, byte, int, int);
	extern int (*Op120_OnList)(CImmunitiesWeapon*, const CWeaponIdentification*);
	extern void (*Op120_OverrideWeaponType)(const CSelectiveWeaponTypeList*, const CAIObjectType*, int, int, CWeaponIdentification*);
	extern CSelectiveWeaponTypeList* (*Op120_CopySelective)(CSelectiveWeaponTypeList*, const CSelectiveWeaponTypeList*);
	extern void (*Op120_ApplyCriticals)(CGameSprite*, CGameSprite*, int, int, int, int);
	extern void* Op120_MultiTargetFire[6];
	extern void* Op120_FireMulti;
	extern void* Op120_AIUpdateBAM;

	short Op120_Hook_Swing(CGameSprite* sprite, CGameSprite* target);
	void Op120_Hook_CaptureWeapon(const CSelectiveWeaponTypeList* overrides, const CAIObjectType* target, int slot, int itemType, CWeaponIdentification* weapon);
	int Op120_Hook_RangedImmunity(CGameSprite* sprite, int blocked);
	void Op120_Hook_ApplyCriticals(CGameSprite* sprite, CGameSprite* target, int attackType, int itemType, int flags, int mode);
	void Op120_Hook_AddEffect(CGameSprite* sprite, CGameEffect* effect, byte list, int noSave, int immediate);
	void Op120_OnProjectileAddEffect(CProjectile* projectile, CGameEffect* effect);

	// These access the existing ExEffectInfo map. Copy/destruction remain owned
	// by Opcode_Hook_OnCopy/OnDestruct, including the pre-existing bypass bit.
	std::shared_ptr<Op120Attack> Op120_GetEffectAttack(CGameEffect* effect);
	void Op120_SetEffectAttack(CGameEffect* effect, std::shared_ptr<Op120Attack> attack);
}
