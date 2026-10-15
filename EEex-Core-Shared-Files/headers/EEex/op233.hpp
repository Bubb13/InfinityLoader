#pragma once

#include <array>
#include <bit>
#include <cstdint>
#include <type_traits>

// The executable switches select IDs 89..134. The audit independently compares
// this explicit member list with both switch tables and each game's PDB. A
// member-pointer table avoids treating engine objects as arrays of adjacent ints.
#define EEEX_OP233_PROFICIENCIES(X) \
	X(m_nProficiencyBastardSword) \
	X(m_nProficiencyLongSword) \
	X(m_nProficiencyShortSword) \
	X(m_nProficiencyAxe) \
	X(m_nProficiencyTwoHandedSword) \
	X(m_nProficiencyKatana) \
	X(m_nProficiencyScimitarWakisashiNinjaTo) \
	X(m_nProficiencyDagger) \
	X(m_nProficiencyWarhammer) \
	X(m_nProficiencySpear) \
	X(m_nProficiencyHalberd) \
	X(m_nProficiencyFlailMorningStar) \
	X(m_nProficiencyMace) \
	X(m_nProficiencyQuarterStaff) \
	X(m_nProficiencyCrossbow) \
	X(m_nProficiencyLongBow) \
	X(m_nProficiencyShortBow) \
	X(m_nProficiencyDart) \
	X(m_nProficiencySling) \
	X(m_nProficiencyBlackjack) \
	X(m_nProficiencyGun) \
	X(m_nProficiencyMartialArts) \
	X(m_nProficiency2Handed) \
	X(m_nProficiencySwordAndShield) \
	X(m_nProficiencySingleWeapon) \
	X(m_nProficiency2Weapon) \
	X(m_nProficiencyClub) \
	X(m_nExtraProficiency2) \
	X(m_nExtraProficiency3) \
	X(m_nExtraProficiency4) \
	X(m_nExtraProficiency5) \
	X(m_nExtraProficiency6) \
	X(m_nExtraProficiency7) \
	X(m_nExtraProficiency8) \
	X(m_nExtraProficiency9) \
	X(m_nExtraProficiency10) \
	X(m_nExtraProficiency11) \
	X(m_nExtraProficiency12) \
	X(m_nExtraProficiency13) \
	X(m_nExtraProficiency14) \
	X(m_nExtraProficiency15) \
	X(m_nExtraProficiency16) \
	X(m_nExtraProficiency17) \
	X(m_nExtraProficiency18) \
	X(m_nExtraProficiency19) \
	X(m_nExtraProficiency20)

namespace EEex::Op233 {

	constexpr std::uint32_t FIRST_PROFICIENCY = 89;

	template<typename Stats>
	constexpr auto proficiencyMembers = std::array {
		#define EEEX_OP233_MEMBER(name) &Stats::name,
		EEEX_OP233_PROFICIENCIES(EEEX_OP233_MEMBER)
		#undef EEEX_OP233_MEMBER
	};

	// Drivers reconstruct their EFF child on every pass. Op177/283 copy the
	// child's cached amount, but op182/183 only copy firstCall. Keep invocation
	// provenance on the native stack, then persist *only an actual op233 delta*
	// in existing effect fields. Nothing here outlives the call or allocates.
	template<typename Effect>
	struct DriverFrame {
		inline static thread_local DriverFrame* current = nullptr;
		Effect* driver;
		Effect* child;
		DriverFrame* previous;

		DriverFrame(Effect* pDriver, Effect* pChild)
			: driver(pDriver), child(pChild), previous(current) {
			current = this;
		}

		~DriverFrame() {
			current = previous;
		}

		DriverFrame(const DriverFrame&) = delete;
		DriverFrame& operator=(const DriverFrame&) = delete;
	};

	template<typename Effect, typename Sprite>
	int applyDrivenEffect(Effect* pChild, Sprite* pSprite, Effect* pDriver) {
		DriverFrame<Effect> frame(pDriver, pChild);
		// Use the child's original virtual slot. This preserves its implementation,
		// return value and all normal driver-side eligibility/lifetime handling.
		return pChild->virtual_ApplyEffect(pSprite);
	}

	template<typename Effect, typename Sprite>
	int applyIncrement(Effect* pEffect, Sprite* pSprite) {
		using Stats = std::remove_reference_t<decltype(pSprite->m_bonusStats)>;
		constexpr auto& members = proficiencyMembers<Stats>;
		static_assert(sizeof(pEffect->m_effectAmount2) == sizeof(std::uint32_t));
		static_assert(sizeof(pSprite->m_bonusStats.*members[0]) == sizeof(std::uint32_t));

		const std::uint32_t flags = pEffect->m_dWFlags;
		const std::uint32_t index = (flags & 0xFFFFU) - FIRST_PROFICIENCY;
		if ((flags >> 16) == 0 || index >= members.size()) {
			return 0;
		}

		// Only follow adjacent driver -> child links ending at this very effect.
		// An unrelated effect applied by a callback must never borrow the outer
		// driver's cache. The outermost contiguous driver survives reconstruction.
		auto* first = DriverFrame<Effect>::current;
		auto* root = pEffect;
		for (auto* frame = first; frame != nullptr && frame->child == root; frame = frame->previous) {
			root = frame->driver;
		}

		std::uint32_t delta;
		if (pEffect->m_firstCall != 0) {
			delta = static_cast<std::uint32_t>(pEffect->m_effectAmount);
			if (pEffect->m_special != 0) {
				// Native code always subtracts temp Long Sword here. Correct the
				// selector while retaining nonzero-special and first-call semantics.
				delta -= static_cast<std::uint32_t>(pSprite->m_tempStats.*members[index]);
			}
			pEffect->m_firstCall = 0;
		}
		else {
			delta = static_cast<std::uint32_t>(root->m_effectAmount2);
		}

		// x64 ADD/SUB wrap at 32 bits. Unsigned arithmetic plus bit_cast keeps
		// negative deltas and overflow defined in C++, without adding a clamp.
		const auto cached = std::bit_cast<std::int32_t>(delta);
		pEffect->m_effectAmount2 = cached;
		auto* child = pEffect;
		for (auto* frame = first; frame != nullptr && frame->child == child; frame = frame->previous) {
			frame->driver->m_effectAmount2 = cached;
			child = frame->driver;
		}
		auto& bonus = pSprite->m_bonusStats.*members[index];
		bonus = std::bit_cast<std::int32_t>(static_cast<std::uint32_t>(bonus) + delta);
		return 1;
	}
}
