#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

// Presentation rules recovered from CItem::GetUsabilityText() in the matching
// BGEE, BG2EE and IWDEE v2.7.3.0 EXE/PDB pairs.
// Keep this helper independent of game structures so the native regression
// executable tests the exact selector and formatter used by EEex.dll.
namespace EEexItemUsability {

	inline constexpr std::uint32_t FighterClassMask = 0x00000800;
	// GetNotUsableBy2() packs bytes a,b,c,d from most to least significant.
	// Thus notUsableBy2c bit 6 becomes bit 14 of the assembled kit mask.
	inline constexpr std::uint32_t GeneralistMask = 0x00004000;

	struct MageSchool {
		std::uint32_t bit;
		std::uint32_t strref;
	};

	// Preserve the engine's first-school search order, extending it to ALL
	// allowed choices. Wild Mage is its final existing choice, not a new kit.
	inline constexpr std::array<MageSchool, 9> MageSchools = {{
		{6,  0xF00424},
		{7,  0xF00425},
		{8,  0xF00426},
		{9,  0xF00427},
		{10, 0xF00429},
		{11, 0xF0042A},
		{12, 0xF0042B},
		{13, 0xF0042C},
		{31, 0xF00433},
	}};

	struct MageCombination {
		std::uint32_t bit;
		std::uint32_t redundantBaseMask;
		std::uint32_t prefixStrref;
		std::uint32_t suffixStrref;
	};

	// Double-class entries have no additional suppression in the engine.
	// Triple-class entries are omitted when all three constituent classes are
	// unrestricted. Preserve that existing presentation policy and the exact
	// component order (for example, Fighter / school / Cleric).
	// A zero strref means that component is absent; it is never fetched.
	inline constexpr std::array<MageCombination, 5> MageCombinations = {{
		{8,  0x00000000, 0xF0038D, 0x00000000}, // Cleric / Mage
		{13, 0x00000000, 0xF00461, 0x00000000}, // Fighter / Mage
		{15, 0x00040880, 0xF00461, 0xF0038D},   // Fighter / Mage / Cleric
		{16, 0x00440800, 0xF00461, 0xF004BF},   // Fighter / Mage / Thief
		{19, 0x00000000, 0x00000000, 0xF004BF}, // Mage / Thief
	}};

	struct MageSelection {
		bool handled = false;
		const MageCombination* combination = nullptr;
		std::array<std::uint32_t, MageSchools.size()> schoolStrrefs{};
		std::size_t count = 0;
	};

	inline bool barbarianClassAllowed(std::uint32_t notUsableBy) {
		// The hook's original branch already checks the Barbarian kit bit for
		// its respective candidate list. Add only the missing parent-class gate,
		// matching the gates the engine applies to the other Fighter kits.
		return (notUsableBy & FighterClassMask) == 0;
	}

	inline MageSelection selectMageMulticlass(std::uint32_t notUsableBy,
		std::uint32_t notUsableBy2, std::uint32_t combinationBit) {

		MageSelection selection;
		if ((notUsableBy2 & GeneralistMask) == 0) {
			// Retain the entire native block when its generic Mage label is valid.
			return selection;
		}

		for (const auto& combination : MageCombinations) {
			if (combination.bit != combinationBit) {
				continue;
			}
			selection.handled = true;
			selection.combination = &combination;
			if ((notUsableBy & (std::uint32_t{1} << combination.bit)) != 0
				|| (combination.redundantBaseMask != 0
					&& (notUsableBy & combination.redundantBaseMask) == 0)) {
				// A handled empty result must skip the native block, otherwise its
				// unconditional generic Mage entry would reintroduce a false claim.
				return selection;
			}
			for (const auto& school : MageSchools) {
				if ((notUsableBy2 & (std::uint32_t{1} << school.bit)) == 0) {
					selection.schoolStrrefs[selection.count++] = school.strref;
				}
			}
			return selection;
		}
		// The installed hooks use only the five verified indices. An invalid
		// index takes the native fallback without shifting an unchecked value.
		return selection;
	}

	template<typename AppendText, typename AppendStrref>
	void appendMageMulticlass(const MageSelection& selection,
		AppendText appendText, AppendStrref appendStrref) {

		for (std::size_t i = 0; i < selection.count; ++i) {
			// Both literals are read from the native concatenation sites by the
			// audit. Labels stay localized through the caller's engine TLK fetch.
			appendText("\n");
			if (selection.combination->prefixStrref != 0) {
				appendStrref(selection.combination->prefixStrref);
				appendText(" / ");
			}
			appendStrref(selection.schoolStrrefs[i]);
			if (selection.combination->suffixStrref != 0) {
				appendText(" / ");
				appendStrref(selection.combination->suffixStrref);
			}
		}
	}
}
