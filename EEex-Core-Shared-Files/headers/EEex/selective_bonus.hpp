
#pragma once

#include <cstddef>
#include <optional>
#include <unordered_map>
#include <utility>

namespace EEex::detail {

	// Engine fact, not an inferred inventory convention: SLOT_SHIELD's public
	// PDB symbol and op344/345's explicit off-hand branch both yield 9 in all
	// three v2.7.3.0 executables.
	constexpr int SELECTIVE_BONUS_OFF_HAND_SLOT = 9;
	// CGameEffect's constructor initializes m_slotNum to -1; the native
	// selective weapon-list matcher treats exactly this value as unrestricted.
	constexpr int SELECTIVE_BONUS_UNRESTRICTED_SLOT = -1;

	constexpr bool IsHandSelectiveBonusOpcode(unsigned int opcode) {
		return opcode == 178 || opcode == 179;
	}

	constexpr bool IsHandSelectiveBonusContextOpcode(unsigned int opcode) {
		return IsHandSelectiveBonusOpcode(opcode) || opcode == 177 || opcode == 182 || opcode == 183 || opcode == 283;
	}

	struct SelectiveBonusMode {
		// op177/283 restore cached effect data into the child when the parent's
		// m_firstCall == 0, including Parameter 4. Capture the EFF-authored
		// value before that transfer, without interpreting the cache as a mode.
		// An engaged zero is intentional: a parent's cache must not enable a mode
		// that the EFF author did not request. The existing effect-copy hook copies
		// this value, and the effect-destruction hook owns its lifetime.
		std::optional<int> decodedMode;
		// Drivers do not forward m_slotNum. Carry the originating slot as a
		// value through driver children too, so nested EFFs retain their origin.
		// An engaged -1 prevents an EFF's file slot from restricting a spell or
		// other unbound parent. No pointer to a parent survives its destruction.
		std::optional<int> drivenSlot;

		void Capture(unsigned int opcode, int parameter4, int sourceSlot) {
			if (IsHandSelectiveBonusOpcode(opcode)) {
				decodedMode = parameter4;
			}
			if (IsHandSelectiveBonusContextOpcode(opcode)) {
				drivenSlot = sourceSlot;
			}
		}

		int Get(int parameter4) const {
			return decodedMode.value_or(parameter4);
		}

		int GetSourceSlot(int nativeSlot) const {
			return drivenSlot.value_or(nativeSlot);
		}
	};

	inline std::optional<int> ResolveSelectiveBonusSlot(int mode, int selectedWeaponSlot, int sourceSlot) {
		switch (mode) {
			case 1: return selectedWeaponSlot;
			case 2: return SELECTIVE_BONUS_OFF_HAND_SLOT;
			case 3: return sourceSlot == SELECTIVE_BONUS_UNRESTRICTED_SLOT ? std::nullopt : std::optional<int>{sourceSlot};
			default: return std::nullopt; // Preserve legacy behavior for unused values.
		}
	}

	inline int SelectiveBonusAttackSlot(int selectedWeaponSlot, int isLeftHand) {
		return isLeftHand != 0 ? SELECTIVE_BONUS_OFF_HAND_SLOT : selectedWeaponSlot;
	}

	class SelectiveBonusRestrictions {
	public:
		using Slots = std::unordered_map<std::size_t, int>;

		void Record(const void* list, std::size_t index, std::optional<int> slot) {
			if (slot) {
				m_slots[list][index] = *slot;
			}
			else if (auto entry = m_slots.find(list); entry != m_slots.end()) {
				entry->second.erase(index);
				if (entry->second.empty()) {
					m_slots.erase(entry);
				}
			}
		}

		void Copy(const void* destination, const void* source) {
			// The native operator= removes its destination before traversing its
			// source, so self-assignment empties the native list. Mirror that exact
			// behavior rather than retaining restrictions for entries now gone.
			if (destination == source) {
				Clear(destination);
			}
			else if (auto entry = m_slots.find(source); entry != m_slots.end()) {
				// Snapshot before inserting: inserting a destination may rehash the
				// outer map. The snapshot also makes each list's metadata independent.
				auto snapshot = entry->second;
				m_slots.insert_or_assign(destination, std::move(snapshot));
			}
			else {
				Clear(destination);
			}
		}

		void Clear(const void* list) {
			m_slots.erase(list);
		}

		const Slots* Find(const void* list) const {
			auto entry = m_slots.find(list);
			return entry != m_slots.end() ? &entry->second : nullptr;
		}

	private:
		// Indexes describe native list order, not effect identities or addresses.
		// Driven EFF children are immediately destroyed by the engine, and list
		// assignment clones bonus entries at new addresses. Neither invalidates
		// these values. Native ClearAll/operator= hooks maintain their lifetime.
		std::unordered_map<const void*, Slots> m_slots;
	};

	template<typename Node, typename Match>
	int FirstHandSelectiveBonus(const Node* node, const SelectiveBonusRestrictions::Slots& slots, int attackSlot, Match&& match) {
		std::size_t index = 0;
		for (; node != nullptr; node = node->pNext, ++index) {
			auto restriction = slots.find(index);
			if (restriction != slots.end() && restriction->second != attackSlot) {
				continue;
			}
			if (match(node->data->m_type)) {
				// GetBonus returns the FIRST match, including a zero or negative
				// bonus. Never sum entries or choose the greatest matching value.
				return node->data->m_bonus;
			}
		}
		return 0;
	}
}
