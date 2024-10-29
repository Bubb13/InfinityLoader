
#include "engine_structs_generated.h"
#include "EEexLua_generated.h"

void __stdcall InitBindings(SharedState argSharedState) {
	sharedState() = argSharedState;
	InitBindingsInternal();
}

void __stdcall OpenBindings() {

	InitBindingsInternal();

	// Export lua bindings
	OpenBindingsInternal(luaState());
}
