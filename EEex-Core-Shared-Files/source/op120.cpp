#include <algorithm>
#include <unordered_set>

#include "EEex.h"
#include "op120.hpp"

// Mirrored by pattern/op120/audit.py --layouts against all three PDBs. These
// assertions check the C++ declarations used here, not just the disassembly.
static_assert(sizeof(CWeaponIdentification) == 16);
static_assert(sizeof(CSelectiveWeaponType) == 48);
static_assert(sizeof(CSelectiveWeaponTypeList) == 56);
static_assert(offsetof(CWeaponIdentification, m_attributes) == 12);
static_assert(offsetof(CSelectiveWeaponType, m_type) == 8);
static_assert(offsetof(CSelectiveWeaponType, m_weapon) == 32);
static_assert(offsetof(CProjectile, m_effectList) == 0x78);
static_assert(offsetof(CProjectile, m_extFlags) == 0x188);
static_assert(offsetof(CGameSprite, m_curProjectile) == 0x4AD8);
static_assert(offsetof(CGameSprite, m_liveTypeAI) == 0x4B50);
static_assert(offsetof(CDerivedStats, m_cImmunitiesWeapon) == 0x3C0);

namespace EEex {
	short (*Op120_Original_Swing)(CGameSprite*, CGameSprite*) = nullptr;
	void (*Op120_Original_AddEffect)(CGameSprite*, CGameEffect*, byte, int, int) = nullptr;
	int (*Op120_OnList)(CImmunitiesWeapon*, const CWeaponIdentification*) = nullptr;
	void (*Op120_OverrideWeaponType)(const CSelectiveWeaponTypeList*, const CAIObjectType*, int, int, CWeaponIdentification*) = nullptr;
	CSelectiveWeaponTypeList* (*Op120_CopySelective)(CSelectiveWeaponTypeList*, const CSelectiveWeaponTypeList*) = nullptr;
	void (*Op120_ApplyCriticals)(CGameSprite*, CGameSprite*, int, int, int, int) = nullptr;
	void* Op120_MultiTargetFire[6]{};
	void* Op120_FireMulti = nullptr;
	void* Op120_AIUpdateBAM = nullptr;
}

struct Op120Attack {

	CWeaponIdentification weapon;
	EngineVal<CSelectiveWeaponTypeList> overrides;
	const int slot;
	const int itemType;
	const uint64_t sourceUUID;
	const bool suppressFeedback;
	std::unordered_set<uint64_t> notifiedRecipients;

	Op120Attack(CGameSprite* source, const CSelectiveWeaponTypeList* original, int slotIn, int typeIn, const CWeaponIdentification& weaponIn)
		: weapon(weaponIn), overrides(original->m_nBlockSize), slot(slotIn), itemType(typeIn),
		  sourceUUID(source->GetUUID()), suppressFeedback(source->m_curAction.m_actionID == 98)
	{
		// Native assignment deep-copies the CAIObjectType CString and list entries.
		// A raw structure copy would retain pointers to the attacker's mutable stats.
		EEex::Op120_CopySelective(overrides, original);
	}

	~Op120Attack() {
		// Assignment from an empty list uses the engine's element destruction and
		// allocator. EngineVal then releases the list's node blocks. ClearAll has
		// identical bodies elsewhere in the EXE, so it is not signature-bound.
		EngineVal<CSelectiveWeaponTypeList> empty(overrides->m_nBlockSize);
		EEex::Op120_CopySelective(overrides, empty);
	}
};

namespace {

	struct SwingContext {
		CGameSprite* sprite;
		std::shared_ptr<Op120Attack> attack;
		CProjectile* deferredProjectile = nullptr;
		bool blockedAtLaunch = false;
		SwingContext* previous;
	};

	thread_local SwingContext* currentSwing = nullptr;

	struct SwingScope {
		SwingContext context;

		explicit SwingScope(CGameSprite* sprite) : context{sprite, {}, nullptr, false, currentSwing} {
			currentSwing = &context;
		}

		~SwingScope() {
			currentSwing = context.previous;
		}
	};

	bool isMultiTarget(CProjectile* projectile, std::unordered_set<CProjectile*>& visited) {
		if (projectile == nullptr) {
			return false;
		}

		const auto* vtable = *reinterpret_cast<const CProjectile::vtbl* const*>(projectile);
		void* fire = reinterpret_cast<void*>(vtable->Fire);
		if (std::find(std::begin(EEex::Op120_MultiTargetFire), std::end(EEex::Op120_MultiTargetFire), fire)
			!= std::end(EEex::Op120_MultiTargetFire))
		{
			return true;
		}

		// BAM AIUpdate tests extFlags BIT1 before entering BounceAI, whose hit
		// sweep enumerates recipients. Compare implementation pointers so derived
		// classes (including LightningBounce) need no guessed projectile IDs.
		if (reinterpret_cast<void*>(vtable->AIUpdate) == EEex::Op120_AIUpdateBAM && (projectile->m_extFlags & 2) != 0) {
			return true;
		}

		// Multi may contain only visual/single-target missiles, or a real area
		// projectile. Inspect its already-decoded children instead of changing
		// immunity timing for every multi-missile visual. Guard mutator cycles.
		if (fire == EEex::Op120_FireMulti) {
			// Allocate a visited set only for recursive composite projectiles.
			// Ordinary attacks and direct area projectiles need no allocation.
			if (!visited.insert(projectile).second) {
				return false;
			}
			for (auto* node = static_cast<CProjectileMulti*>(projectile)->m_projectiles.m_pNodeHead; node != nullptr; node = node->pNext) {
				if (isMultiTarget(node->data, visited)) {
					return true;
				}
			}
		}
		return false;
	}

	void tagEffect(CGameEffect* effect, const std::shared_ptr<Op120Attack>& attack) {
		// Target 9 is redirected to the caster by DeliverEffects/CreateSecondary.
		// It is not a hit against the selected recipient. Other caster/party
		// selectors are dispatched outside the projectile by LoadProjectile.
		if (effect != nullptr && effect->m_targetType != 9) {
			EEex::Op120_SetEffectAttack(effect, attack);
		}
	}
}

short EEex::Op120_Hook_Swing(CGameSprite* sprite, CGameSprite* target) {
	// Native Swing has many exits and can invoke mod callbacks. A native scope
	// restores the previous context on every return, including nested attacks.
	SwingScope scope(sprite);
	return Op120_Original_Swing(sprite, target);
}

void EEex::Op120_Hook_CaptureWeapon(const CSelectiveWeaponTypeList* overrides, const CAIObjectType* target, int slot, int itemType, CWeaponIdentification* weapon) {
	if (currentSwing != nullptr) {
		// Capture the raw identification before the engine specializes it for
		// the primary target. Delivery replays the native specialization for
		// the actual recipient, using this launch-time snapshot.
		currentSwing->attack = std::make_shared<Op120Attack>(currentSwing->sprite, overrides, slot, itemType, *weapon);
	}
	Op120_OverrideWeaponType(overrides, target, slot, itemType, weapon);
}

int EEex::Op120_Hook_RangedImmunity(CGameSprite* sprite, int blocked) {
	if (currentSwing == nullptr || currentSwing->sprite != sprite || !currentSwing->attack) {
		return blocked;
	}
	std::unordered_set<CProjectile*> visited;
	CProjectile* projectile = sprite->m_curProjectile;
	if (!isMultiTarget(projectile, visited)) {
		return blocked;
	}

	currentSwing->deferredProjectile = projectile;
	currentSwing->blockedAtLaunch = blocked != 0;
	for (auto* node = projectile->m_effectList.m_pNodeHead; node != nullptr; node = node->pNext) {
		tagEffect(node->data, currentSwing->attack);
	}
	// Only called after the explicit BlockWeaponHit listener has allowed the
	// hit. Returning zero also prevents the existing op249 helper from clearing
	// the payload; ordinary damage and on-hit effects are then built normally.
	return 0;
}

void EEex::Op120_Hook_ApplyCriticals(CGameSprite* sprite, CGameSprite* target, int attackType, int itemType, int flags, int mode) {
	// Swing's ranged success branch also sends immediate critical-hit spell
	// messages. These are launch-time attack callbacks, not projectile payload.
	// Retaining payload must not manufacture an extra critical callback that
	// the original primary-target immunity result would have prevented.
	if (currentSwing != nullptr && currentSwing->sprite == sprite
		&& currentSwing->deferredProjectile != nullptr && currentSwing->blockedAtLaunch)
	{
		return;
	}
	Op120_ApplyCriticals(sprite, target, attackType, itemType, flags, mode);
}

void EEex::Op120_OnProjectileAddEffect(CProjectile* projectile, CGameEffect* effect) {
	if (currentSwing != nullptr && projectile != nullptr && projectile == currentSwing->deferredProjectile) {
		tagEffect(effect, currentSwing->attack);
	}
}

void EEex::Op120_Hook_AddEffect(CGameSprite* sprite, CGameEffect* effect, byte list, int noSave, int immediate) {
	auto attack = Op120_GetEffectAttack(effect);
	if (attack) {
		// This instance is being delivered, not retained as a projectile template.
		// Consume its check before callbacks can copy an accepted/installed effect.
		// Other projectile copies retain their own shared context and are checked
		// independently, including later scorch/area pulses.
		Op120_SetEffectAttack(effect, nullptr);
		if (effect->m_targetType != 9 && !ShouldEffectBypassOp120(effect)) {
			CWeaponIdentification weapon = attack->weapon;
			Op120_OverrideWeaponType(attack->overrides, &sprite->m_liveTypeAI, attack->slot, attack->itemType, &weapon);
			if (Op120_OnList(&sprite->GetActiveStats()->m_cImmunitiesWeapon, &weapon)) {
				// Match AddEffect's rejection ownership: the incoming effect is
				// destroyed with the engine's virtual deleting destructor. In
				// particular, noSave must not turn weapon immunity into acceptance.
				effect->virtual_Destruct(1);
				if (!attack->suppressFeedback && attack->notifiedRecipients.insert(sprite->GetUUID()).second) {
					if (CGameSprite* source = GetSpriteFromUUID(attack->sourceUUID)) {
						// Same feedback ID/arguments as the native ranged rejection.
						EngineVal<CString> empty("");
						source->FeedBack(37, 0, 0, 0, -1, 0, empty);
					}
				}
				return;
			}
		}
	}
	Op120_Original_AddEffect(sprite, effect, list, noSave, immediate);
}
