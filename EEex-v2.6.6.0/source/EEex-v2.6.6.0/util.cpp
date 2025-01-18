
#include "infinity_loader_common_api.h"

#include <Windows.h>
#include <winternl.h>

typedef struct _THREAD_BASIC_INFORMATION {
	NTSTATUS ExitStatus;
	PVOID TebBaseAddress;
	CLIENT_ID ClientId;
	KAFFINITY AffinityMask;
	KPRIORITY Priority;
	KPRIORITY BasePriority;
} THREAD_BASIC_INFORMATION, *PTHREAD_BASIC_INFORMATION;

uintptr_t getStackBase() {

	THREAD_BASIC_INFORMATION basicInfo;

	NtQueryInformationThread(GetCurrentThread(),
		static_cast<THREADINFOCLASS>(0), // Undocumented ThreadBasicInformation
		&basicInfo,
		sizeof(THREAD_BASIC_INFORMATION),
		NULL);

	const NT_TIB& tib = *reinterpret_cast<NT_TIB*>(basicInfo.TebBaseAddress);
	return reinterpret_cast<uintptr_t>(tib.StackBase);
}

///////////////
// Debugging //
///////////////

void dumpLuaStack(lua_State *const L)
{
	const int top { lua_gettop(L) };
	for (int i { 1 }; i <= top; ++i)
	{
		const int type { lua_type(L, i) };
		const char* typeStr { nullptr };

		switch (type)
		{
			case LUA_TNONE:          typeStr = "LUA_TNONE";          break;
			case LUA_TNIL:           typeStr = "LUA_TNIL";           break;
			case LUA_TBOOLEAN:       typeStr = "LUA_TBOOLEAN";       break;
			case LUA_TLIGHTUSERDATA: typeStr = "LUA_TLIGHTUSERDATA"; break;
			case LUA_TNUMBER:        typeStr = "LUA_TNUMBER";        break;
			case LUA_TSTRING:        typeStr = "LUA_TSTRING";        break;
			case LUA_TTABLE:         typeStr = "LUA_TTABLE";         break;
			case LUA_TFUNCTION:      typeStr = "LUA_TFUNCTION";      break;
			case LUA_TUSERDATA:      typeStr = "LUA_TUSERDATA";      break;
			case LUA_TTHREAD:        typeStr = "LUA_TTHREAD";        break;
			default:                 typeStr = "UNKNOWN";            break;
		}

		FPrint("%d    %s    ", i, typeStr);
		switch (type)
		{
			case LUA_TNUMBER:
				FPrint("%g\n", lua_tonumberx(L, i, nullptr));
				break;
			case LUA_TSTRING:
				Print(lua_tostring(L, i));
				Print("\n");
				break;
			case LUA_TBOOLEAN:
				Print(lua_toboolean(L, i) ? "true" : "false");
				Print("\n");
				break;
			case LUA_TNIL:
				Print("nil\n");
				break;
			default:
				Print("<no representation>\n");
				break;
		}
	}
}
