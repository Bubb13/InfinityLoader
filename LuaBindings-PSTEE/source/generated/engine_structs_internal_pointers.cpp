
#include "engine_structs.h"

CBaldurChitin** p_g_pBaldurChitin;
CGameObjectArray::type_GetShare CGameObjectArray::p_GetShare;
CGameEffect::type_DecodeEffect CGameEffect::p_DecodeEffect;
CProjectile::type_DecodeProjectile CProjectile::p_DecodeProjectile;

std::vector<std::pair<const TCHAR*, void**>> internalPointersMap {
	std::pair{TEXT("g_pBaldurChitin"), reinterpret_cast<void**>(&p_g_pBaldurChitin)},
	std::pair{TEXT("CGameObjectArray::GetShare"), reinterpret_cast<void**>(&CGameObjectArray::p_GetShare)},
	std::pair{TEXT("CGameEffect::DecodeEffect"), reinterpret_cast<void**>(&CGameEffect::p_DecodeEffect)},
	std::pair{TEXT("CProjectile::DecodeProjectile"), reinterpret_cast<void**>(&CProjectile::p_DecodeProjectile)},
};
