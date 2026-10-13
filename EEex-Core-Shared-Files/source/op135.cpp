#include <cstring>
#include "Baldur_generated.h"
#include "EEex.h"
#include "op135.hpp"

// These prototypes and slot values are verified against every supplied PDB.
// Addresses come exclusively from InfinityLoader patterns.
namespace {
	using Equip = void(__fastcall*)(CItem*, CGameSprite*, long, int);
	using Unequip = void(__fastcall*)(CItem*, CGameSprite*, long, int, int);
	Equip nativeEquip = nullptr;
	Unequip nativeUnequip = nullptr;

	struct Engine {
		using Effect = CGameEffect;
		using Sprite = CGameSprite;
		using Item = CItem;
		static bool done(Effect* effect) { return effect->m_done != 0; }
		static uint32_t mode(Effect* effect) { return effect->m_dWFlags; }
		static uint32_t special(Effect* effect) { return effect->m_special; }
		static void requestPass(Sprite* sprite) { sprite->m_newEffect = 1; }
		static Item* item(Sprite* sprite, unsigned slot) { return sprite->m_equipment.m_items[slot]; }
		static bool present(Sprite* sprite, Effect* effect) {
			for (auto* list : {&sprite->m_equipedEffectList, &sprite->m_timedEffectList})
				for (auto* node = list->m_pNodeHead; node; node = node->pNext)
					if (node->data == effect) return true;
			return false;
		}
		template<class Protected>
		static bool removeOne(Sprite* sprite, unsigned slot, Protected&& isProtected) {
			auto& list = sprite->m_equipedEffectList;
			for (auto* node = list.m_pNodeHead; node; node = node->pNext) {
				auto* effect = node->data;
				// Native Equip marks item origins as sourceType=2 and records the
				// exact slot. Native Unequip's resref comparison lacks this slot
				// check and can remove the other copy of an identical ring.
				if (effect->m_sourceType != 2 || effect->m_slotNum != static_cast<long>(slot) || isProtected(effect)) continue;
				list.RemoveAt(node);
				effect->virtual_OnRemove(sprite);
				effect->virtual_Destruct(1);
				return true;
			}
			return false;
		}
		static void unequipVisual(Item* item, Sprite* sprite, unsigned slot) {
			// animationOnly=1 leaves effect removal to the slot-aware path above;
			// recalculate=0 prevents recursive ProcessEffectList calls.
			nativeUnequip(item, sprite, static_cast<long>(slot), 0, 1);
		}
		static void equip(Item* item, Sprite* sprite, unsigned slot) {
			nativeEquip(item, sprite, static_cast<long>(slot), 0);
		}
		static bool immune(Sprite* sprite, Item* item) {
			auto& stats = *sprite->GetActiveStats();
			// OnList can clone an attached effect. We need only the native
			// comparisons, so walking these typed lists avoids that side effect.
			for (auto* node = stats.m_cImmunitiesItemEquip.m_pNodeHead; node; node = node->pNext)
				if (std::memcmp(&node->data->m_res, &item->cResRef, sizeof(CResRef)) == 0) return true;
			const auto category = item->GetItemType();
			for (auto* node = stats.m_cImmunitiesItemTypeEquip.m_pNodeHead; node; node = node->pNext)
				if (node->data->m_type == category) return true;
			return false;
		}
	};
	EEex::Op135::Controller<Engine> controller;

	template<class Pointer>
	bool resolve(const TCHAR* name, Pointer& out) {
		PatternValueHandle handle;
		if (sharedState().GetPatternValue(name, handle) != PatternValueType::SINGLE) return false;
		out = reinterpret_cast<Pointer>(sharedState().GetSinglePatternValue(handle));
		return out != nullptr;
	}
}

// Lua preflights this exported status along with every hook before installing
// anything. Older version databases leave the feature inactive.
uint8_t EEex::Opcode135_BindingsReady = 0;
void EEex::Opcode135_Init() {
	Opcode135_BindingsReady = resolve(TEXT("Hook-CItem::Equip()-Op135"), nativeEquip)
		&& resolve(TEXT("Hook-CItem::Unequip()-Op135"), nativeUnequip);
}
void EEex::Opcode135_BeginPass(CGameSprite* sprite) { controller.begin(sprite); }
void EEex::Opcode135_Observe(CGameEffect* effect, CGameSprite* sprite) { controller.observe(effect, sprite); }
int EEex::Opcode135_ApplyDriven(CGameEffect* child, CGameSprite* sprite, CGameEffect* driver) {
	return controller.driven(child, sprite, driver, [&] { return child->virtual_ApplyEffect(sprite); });
}
bool EEex::Opcode135_CommitPass(CGameSprite* sprite) { return controller.commit(sprite); }
bool EEex::Opcode135_ShouldSkipEquip(CItem* item, CGameSprite* sprite, long slot) {
	return !controller.allowEquip(item, sprite, slot);
}
bool EEex::Opcode135_ItemEffect(CGameEffect* effect, CGameSprite* sprite, CItem* item, unsigned slot, unsigned ordinal) {
	if (controller.itemEffect(effect, sprite, item, slot, ordinal)) return true;
	// The caller omits AddEffect on this path; release the freshly decoded
	// object through the same deleting destructor used by the native engine.
	effect->virtual_Destruct(1);
	return false;
}
void EEex::Opcode135_Unequipped(CItem* item, CGameSprite* sprite, long slot, int animationOnly) {
	controller.unequipped(item, sprite, slot, animationOnly);
}
void EEex::Opcode135_EffectDestroyed(CGameEffect* effect) { controller.effectDestroyed(effect); }
void EEex::Opcode135_EffectCopied(CGameEffect* source, CGameEffect* destination) { controller.effectCopied(source, destination); }
void EEex::Opcode135_SpriteDestroyed(CGameSprite* sprite) { controller.spriteDestroyed(sprite); }

void EEex::Opcode135_ItemDestroyed(CItem* item) { controller.itemDestroyed(item); }
