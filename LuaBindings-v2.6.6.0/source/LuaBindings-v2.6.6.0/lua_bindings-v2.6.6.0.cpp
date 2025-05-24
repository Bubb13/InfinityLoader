
#include "Baldur-v2.6.6.0_generated.h"
#include "EEexLua_generated.h"

static void exportPattern(const String& name, void* value) {

	PatternValueHandle handle;
	if (sharedState().GetOrCreatePatternValue(name, PatternValueType::SINGLE, handle)) {
		FPrintT(TEXT("[!][LuaBindings-v2.6.6.0.dll] exportPattern() - [%s].Type must be SINGLE\n"), name.c_str());
		return;
	}

	sharedState().SetSinglePatternValue(handle, value);
}

// Ugly hack to get a member-function pointer
template<typename T>
static constexpr void* getMemberPtr(T func) {
	return reinterpret_cast<void*&>(func);
}

static void exportPatterns() {
	exportPattern(TEXT("CGameSprite::MakeLocal"), getMemberPtr(&CGameSprite::MakeLocal));
}

void __stdcall InitBindings(SharedState argSharedState) {
	sharedState() = argSharedState;
	InitBindingsInternal();
	exportPatterns();
}

void __stdcall OpenBindings() {

	InitLuaBindingsCommon(sharedState());

	// Export lua bindings
	OpenBindingsInternal(luaState());
}
