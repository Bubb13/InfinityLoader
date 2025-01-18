
#include "engine_structs_generated.h"

CBaldurChitin** p_g_pBaldurChitin;
CGameObjectArray::type_GetShare CGameObjectArray::p_GetShare;
CGameEffect::type_DecodeEffect CGameEffect::p_DecodeEffect;
CProjectile::type_DecodeProjectile CProjectile::p_DecodeProjectile;

template<typename OutType>
static void attemptFillPointer(const String& patternName, OutType& pointerOut) {
	PatternValueHandle patternHandle;
	switch (sharedState().GetPatternValue(patternName, patternHandle)) {
		case PatternValueType::SINGLE: {
			pointerOut = reinterpret_cast<OutType>(sharedState().GetSinglePatternValue(patternHandle));
			break;
		}
		case PatternValueType::INVALID: {
			FPrintT(TEXT("[!][LuaBindings-PSTEE.dll] attemptFillPointer() - Binding pattern [%s] missing; using this binding will crash the game\n"), patternName.c_str());
			break;
		}
		default: {
			FPrintT(TEXT("[!][LuaBindings-PSTEE.dll] attemptFillPointer() - Binding pattern [%s].Type not SINGLE; using this binding will crash the game\n"), patternName.c_str());
			break;
		}
	}
}

void InitBindingsInternal() {
	attemptFillPointer(TEXT("g_pBaldurChitin"), p_g_pBaldurChitin);
	attemptFillPointer(TEXT("CGameObjectArray::GetShare"), CGameObjectArray::p_GetShare);
	attemptFillPointer(TEXT("CGameEffect::DecodeEffect"), CGameEffect::p_DecodeEffect);
	attemptFillPointer(TEXT("CProjectile::DecodeProjectile"), CProjectile::p_DecodeProjectile);
}
