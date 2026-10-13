#pragma once

#include <array>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>

// The policy is shared by the DLL adapter and the native fixture tests. Engine
// pointers are identities only here; every read, callback and list mutation is
// supplied by the adapter. No engine object is constructed by the tests.
namespace EEex::Op135 {
	constexpr uint32_t SlotMask = 0x1FF;
	constexpr unsigned SlotCount = 9;

	template<class Adapter>
	class Controller {
	public:
		using Effect = typename Adapter::Effect;
		using Sprite = typename Adapter::Sprite;
		using Item = typename Adapter::Item;
	private:
		struct Origin { Sprite* sprite; Item* item; unsigned slot; unsigned ordinal; };
		struct SlotState {
			Item* item = nullptr;
			std::unordered_set<unsigned> sourceOrdinals;
		};
		struct State {
			uint32_t mask = 0;
			bool collecting = false;
			bool reconciling = false;
			int restoring = -1;
			std::array<SlotState, SlotCount> slots;
			std::unordered_map<Effect*, uint32_t> observed;
		};
		struct Frame {
			Effect* child;
			Sprite* sprite;
			Effect* driver;
			Frame* previous;
		};
		inline static thread_local Frame* frame = nullptr;
		std::unordered_map<Sprite*, State> states;
		std::unordered_map<Effect*, Origin> origins;
		std::unordered_map<Effect*, Sprite*> owners;

		void clearObserved(Sprite* sprite, State& state) {
			for (const auto& [effect, unused] : state.observed) {
				(void)unused;
				auto owner = owners.find(effect);
				if (owner != owners.end() && owner->second == sprite) owners.erase(owner);
			}
			state.observed.clear();
		}
	public:
		void begin(Sprite* sprite) {
			auto& state = states[sprite];
			if (state.reconciling) return;
			clearObserved(sprite, state);
			state.collecting = true;
		}

		// Follow only the active, contiguous driver/child chain. A callback for
		// another effect or sprite cannot borrow an enclosing EFF's ownership.
		template<class Call>
		int driven(Effect* child, Sprite* sprite, Effect* driver, Call&& call) {
			Frame current{child, sprite, driver, frame};
			struct Scope {
				Frame*& head;
				Frame* previous;
				~Scope() { head = previous; }
			} scope{frame, frame};
			frame = &current;
			return call();
		}

		void observe(Effect* effect, Sprite* sprite) {
			if (Adapter::done(effect) || Adapter::mode(effect) != 0) return;
			const auto mask = Adapter::special(effect) & SlotMask;
			if (!mask) return;
			auto found = states.find(sprite);
			if (found == states.end() || !found->second.collecting || found->second.reconciling) {
				Adapter::requestPass(sprite);
				return;
			}
			auto* root = effect;
			for (auto* current = frame; current && current->sprite == sprite && current->child == root;
				current = current->previous) root = current->driver;
			found->second.observed[root] |= mask;
			owners[root] = sprite;
		}

		bool allowEquip(Item*, Sprite* sprite, long slot) const {
			if (slot < 0 || slot >= static_cast<long>(SlotCount)) return true;
			auto found = states.find(sprite);
			return found == states.end() || !(found->second.mask & (1u << slot));
		}

		// Called before the real AddEffect dispatch, while the item's casting
		// effect index still exists in a native register. Restoration omits only
		// the source ordinals retained during this suppression episode.
		bool itemEffect(Effect* effect, Sprite* sprite, Item* item, unsigned slot, unsigned ordinal) {
			if (slot >= SlotCount) return true;
			auto found = states.find(sprite);
			if (found != states.end() && found->second.restoring == static_cast<int>(slot)) {
				const auto& saved = found->second.slots[slot];
				if (saved.item == item && saved.sourceOrdinals.contains(ordinal)) return false;
			}
			origins.insert_or_assign(effect, Origin{sprite, item, slot, ordinal});
			return true;
		}

		void unequipped(Item* item, Sprite* sprite, long slot, int animationOnly) {
			if (animationOnly || slot < 0 || slot >= static_cast<long>(SlotCount)) return;
			auto found = states.find(sprite);
			if (found != states.end() && found->second.slots[slot].item == item)
				found->second.slots[slot] = SlotState{};
		}

		bool commit(Sprite* sprite) {
			auto found = states.find(sprite);
			if (found == states.end() || !found->second.collecting || found->second.reconciling) return false;
			auto& state = found->second;
			state.collecting = false;
			state.reconciling = true;
			struct Finish {
				State& state;
				~Finish() { state.restoring = -1; state.reconciling = false; }
			} finish{state};

			uint32_t next = 0;
			std::unordered_set<Effect*> protectedRoots;
			for (const auto& [root, mask] : state.observed) {
				// Membership is checked before dereferencing: expired roots and
				// temporary decoded EFF children are never durable owners.
				if (!Adapter::present(sprite, root) || Adapter::done(root)) continue;
				next |= mask;
				auto origin = origins.find(root);
				if (origin == origins.end()) continue;
				const auto& from = origin->second;
				if (from.sprite != sprite || !(mask & (1u << from.slot)) ||
					Adapter::item(sprite, from.slot) != from.item) continue;
				protectedRoots.insert(root);
				auto& saved = state.slots[from.slot];
				if (saved.item != from.item) saved = SlotState{};
				saved.item = from.item;
				saved.sourceOrdinals.insert(from.ordinal);
			}
			const auto previous = state.mask;

			// Publish before callbacks: equip attempts made by OnRemove must
			// already see suppression; eligible restoration must see it lifted.
			state.mask = next;
			bool changed = previous != next;
			for (unsigned slot = 0; slot < SlotCount; ++slot) {
				const auto bit = 1u << slot;
				auto& saved = state.slots[slot];
				auto* current = Adapter::item(sprite, slot);
				const bool replaced = saved.item != current;
				if (replaced) { saved = SlotState{}; saved.item = current; }
				if (next & bit) {
					// Rescan after every engine callback. OnRemove can invalidate
					// unrelated nodes, so retaining a next-node pointer is unsafe.
					while (Adapter::removeOne(sprite, slot, [&](Effect* effect) {
						return protectedRoots.contains(effect) && state.observed.contains(effect);
					})) changed = true;
					// OnRemove may replace/destroy the item as well as effects.
					current = Adapter::item(sprite, slot);
					const bool replacedByCallback = saved.item != current;
					if (replacedByCallback) { saved = SlotState{}; saved.item = current; }
					if (replaced || replacedByCallback) changed = true;
					if (current && (!(previous & bit) || replaced || replacedByCallback)) Adapter::unequipVisual(current, sprite, slot);
				}
				else if (previous & bit) {
					current = Adapter::item(sprite, slot);
					if (current && !Adapter::immune(sprite, current)) {
						state.restoring = static_cast<int>(slot);
						Adapter::equip(current, sprite, slot);
						state.restoring = -1;
					}
					// No deferred retry: ordinary engine handling owns a blocked
					// restoration after the opcode has released the slot.
					saved = SlotState{};
				}
			}
			return changed;
		}

		void itemDestroyed(Item* item) {
			// ClearMarshal/load and allocator reuse can replace an item without
			// an inventory Unequip call. Never carry an old source blacklist to
			// a different item that later occupies the same address.
			for (auto& [sprite, state] : states) {
				(void)sprite;
				for (auto& slot : state.slots) if (slot.item == item) slot = SlotState{};
			}
			for (auto it = origins.begin(); it != origins.end(); ) {
				if (it->second.item == item) it = origins.erase(it); else ++it;
			}
		}
		void effectDestroyed(Effect* effect) {
			origins.erase(effect);
			auto owner = owners.find(effect);
			if (owner == owners.end()) return;
			auto found = states.find(owner->second);
			if (found != states.end()) found->second.observed.erase(effect);
			owners.erase(owner);
		}
		void effectCopied(Effect* source, Effect* destination) {
			// Runtime observations belong to one application, never to a copy.
			effectDestroyed(destination);
			auto found = origins.find(source);
			if (found != origins.end()) origins.emplace(destination, found->second);
		}
		void spriteDestroyed(Sprite* sprite) {
			auto found = states.find(sprite);
			if (found != states.end()) { clearObserved(sprite, found->second); states.erase(found); }
			for (auto it = origins.begin(); it != origins.end(); ) {
				if (it->second.sprite == sprite) it = origins.erase(it); else ++it;
			}
		}
	};
}
