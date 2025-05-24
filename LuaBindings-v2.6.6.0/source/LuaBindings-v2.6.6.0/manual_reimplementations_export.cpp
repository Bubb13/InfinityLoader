
#include "Baldur-v2.6.6.0_generated.h"

void CGameSprite::MakeLocal() {

    if (!this->m_bGlobal || this->m_pArea == nullptr) {
        return;
    }

    this->m_bGlobal = false;

    CTypedPtrList<CPtrList, long>& globalCreatures = (*p_g_pBaldurChitin)->m_pObjectGame->m_lstGlobalCreatures;
    if (auto pNode = globalCreatures.Find(this->m_id, nullptr); pNode != nullptr) {
        globalCreatures.RemoveAt(pNode);
    }

    EngineVal<CVariable> scriptNameVariable{};
    strncpy(scriptNameVariable->m_name, this->m_scriptName, 32);
    scriptNameVariable->m_intValue = this->m_id;

    this->m_pArea->m_namedCreatures.AddKey(scriptNameVariable);
}
