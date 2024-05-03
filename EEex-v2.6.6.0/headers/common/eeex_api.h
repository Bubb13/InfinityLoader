
#pragma once

#include <functional>

#include "dll_api.h"

//---------------------------//
//          Exports          //
//---------------------------//

namespace EEex {
	IMPORT void RegisterScriptLevelHitCallback(std::function<void(CGameAIBase*, unsigned char)> callback);
	IMPORT void RegisterConditionResponseHitCallback(std::function<void(int16_t)> callback);
	IMPORT void RegisterTriggerHitCallback(std::function<void(int32_t)> callback);
	IMPORT void RegisterTriggerEvaluatedCallback(std::function<void(bool)> callback);
}
