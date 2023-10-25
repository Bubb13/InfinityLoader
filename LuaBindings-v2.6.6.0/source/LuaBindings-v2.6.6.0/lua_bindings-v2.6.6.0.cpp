
#include "Baldur-v2.6.6.0_generated.h"
#include "EEexLua_generated.h"

void __stdcall InitBindings(SharedState argSharedState) {
	sharedState() = argSharedState;
	InitBindingsInternal();
}

void __stdcall OpenBindings() {

	InitLuaBindingsCommon(sharedState());

	// Export lua bindings
	OpenBindingsInternal(luaState());
}
