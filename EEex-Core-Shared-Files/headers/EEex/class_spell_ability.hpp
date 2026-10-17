#pragma once

#include <algorithm>
#include <bit>
#include <cstdint>

namespace EEex::ClassSpellAbility {

	inline const char* column(unsigned int opcode) {
		switch (opcode) {
			case 6:  return "CHA";
			case 10: return "CON";
			case 19: return "INT";
			case 49: return "WIS";
			default: return nullptr;
		}
	}

	// Native op15/44 and the four extensions all replace Parameter 1 in mode 3.
	// Restrict the removal exception to item-sourced, while-equipped effects.
	template<typename Effect>
	bool isEquippedMode3(const Effect* effect) {
		if (effect->m_dWFlags != 3 || effect->m_durationType != 2 || effect->m_sourceType != 2) return false;
		switch (effect->m_effectId) {
			case 6: case 10: case 15: case 19: case 44: case 49: return true;
			default: return false;
		}
	}

	template<typename Effect>
	class RemovalFrame {
	public:
		inline static thread_local RemovalFrame* active = nullptr;
		const void* list;
		const Effect* query;
		const void* sprite;
		int slot;

		RemovalFrame(const void* pList, const Effect* pQuery, const void* pSprite, int nSlot)
			: list(pList), query(pQuery), sprite(pSprite), slot(nSlot), previous(active)
		{
			active = this;
		}

		~RemovalFrame() { active = previous; }
		RemovalFrame(const RemovalFrame&) = delete;
		RemovalFrame& operator=(const RemovalFrame&) = delete;

	private:
		RemovalFrame* previous;
	};

	template<typename Effect>
	bool amountMatches(const void* list, const Effect* query, const Effect* candidate, int compareSource = 1) {
		const auto* frame = RemovalFrame<Effect>::active;
		if (compareSource != 0 && frame != nullptr && frame->list == list && frame->query == query
			&& isEquippedMode3(query) && isEquippedMode3(candidate) && query->m_effectId == candidate->m_effectId)
		{
			// Even equal rolls must not select the other copy of an identical item.
			// Every other identity comparison remains in the native remover.
			return candidate->m_slotNum == frame->slot;
		}
		// In particular, nested calls that disable native source comparison must
		// not inherit the enclosing unequip's item-ownership exception.
		return query->m_effectAmount == candidate->m_effectAmount;
	}

	template<typename Effect, typename Remove>
	int removeEquipped(const void* list, const Effect* query, const void* sprite, int slot, Remove nativeRemove) {
		if (!isEquippedMode3(query)) return nativeRemove();
		RemovalFrame<Effect> frame { list, query, sprite, slot };
		int removed = 0;
		// Unequipping removes the entire item's contribution, including duplicate
		// entries and matching leftovers from earlier failed unequip cycles.
		while (nativeRemove() != 0) removed = 1;
		return removed;
	}

	// Frames borrow engine objects only for the duration of a driven ApplyEffect().
	// Matching the child and sprite also prevents unrelated reentrant applications
	// from inheriting another effect's saved roll. No pointer is saved in the CRE.
	template<typename Effect>
	class DrivenFrame {
	public:
		inline static thread_local DrivenFrame* active = nullptr;
		Effect* parent;
		Effect* child;
		const void* sprite;
		DrivenFrame* chain;

		DrivenFrame(Effect* pParent, Effect* pChild, const void* pSprite)
			: parent(pParent), child(pChild), sprite(pSprite),
			chain(active != nullptr && active->child == pParent && active->sprite == pSprite ? active : nullptr),
			previous(active)
		{
			active = this;
		}

		~DrivenFrame() { active = previous; }
		DrivenFrame(const DrivenFrame&) = delete;
		DrivenFrame& operator=(const DrivenFrame&) = delete;

		static DrivenFrame* forChild(Effect* pChild, const void* pSprite) {
			return active != nullptr && active->child == pChild && active->sprite == pSprite ? active : nullptr;
		}

		int savedRoll() const {
			const DrivenFrame* root = this;
			while (root->chain != nullptr) root = root->chain;
			return std::bit_cast<std::int32_t>(static_cast<std::uint32_t>(root->parent->m_special));
		}

		void saveRoll(int amount) {
			// op177/283 already copy special back from their child; op182/183 do
			// not. Set every carrier, including the leaf, so both paths agree.
			child->m_special = static_cast<std::uint32_t>(amount);
			for (DrivenFrame* frame = this; frame != nullptr; frame = frame->chain) {
				frame->parent->m_special = static_cast<std::uint32_t>(amount);
			}
		}

	private:
		DrivenFrame* previous;
	};

	// Shared by the engine hook and the standalone regression harness. Callbacks
	// keep the game RNG and table lookup explicit, and are invoked only on first use.
	template<typename Effect, typename Lookup, typename Random>
	bool prepare(Effect* effect, const void* sprite, int baseScore, Lookup lookup, Random random) {
		const char* name = column(effect->m_effectId);
		if (effect->m_dWFlags != 3 || name == nullptr) return false;

		auto* frame = DrivenFrame<Effect>::forChild(effect, sprite);
		if (effect->m_firstCall != 0) {
			effect->m_firstCall = 0;
			if (baseScore > 20) {
				// Native DEX consumes firstCall and retires the effect above its cap.
				effect->m_effectAmount = 0;
				effect->m_done = 1;
				if (frame != nullptr) frame->saveRoll(0);
				return false;
			}

			const auto die = static_cast<std::uint32_t>(lookup(name));
			const auto roll = static_cast<std::uint32_t>(random()) & 0x7FFFU;
			// Reproduce the native 32-bit IMUL/SAR sequence without signed overflow.
			const auto product = std::bit_cast<std::int32_t>(roll * die);
			const int bonus = (product >> 15) + 1;
			effect->m_effectAmount = (std::min)(bonus, 20 - baseScore);
		}
		else if (frame != nullptr) {
			// A freshly decoded EFF has the resource's Parameter 1, not the roll.
			// The outermost surviving wrapper owns the serialized result instead.
			effect->m_effectAmount = frame->savedRoll();
		}

		if (frame != nullptr) frame->saveRoll(effect->m_effectAmount);
		return true;
	}
}
