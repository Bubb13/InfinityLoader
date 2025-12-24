
#include "infinity_loader_common_api.h"

EXPORT DWORD InitUtil(SharedState argSharedState)
{
	sharedState() = argSharedState;
	return ERROR_SUCCESS;
}
