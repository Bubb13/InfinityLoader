
#pragma once

#include <queue>
#include <vector>

#include "InfinityLoaderCommon.h"
#include "to_lua_pointers.h"

struct ALCcontext_struct;
struct ALCdevice_struct;
struct CAIAction;
struct CAIObjectType;
struct CAIScript;
struct CAITrigger;
struct CAbilityData;
struct CAreaFileContainer;
struct CAreaFileProjectileObject;
struct CAreaPoint;
struct CBounceEntry;
struct CButtonData;
struct CColorEffect;
struct CContingency;
struct CCreatureFileItem;
struct CCriticalEntry;
struct CFileView;
struct CGameAnimationType;
struct CGameArea;
struct CGameDialogReply;
struct CGameEffect;
struct CGameEffectUsability;
struct CGameFile;
struct CGameObject;
struct CGameSprite;
struct CImmunitiesItemEquip;
struct CImmunitiesItemTypeEquip;
struct CImmunitySpell;
struct CInfButtonArray;
struct CInfCursor;
struct CInfGame;
struct CItem;
struct CMemINIValue;
struct CMessage;
struct CMoveListEntry;
struct CObList;
struct CObject;
struct CPathNode;
struct CPersistantEffect;
struct CPlex;
struct CPoint;
struct CProjectile;
struct CRect;
struct CRes;
struct CResPVR;
struct CResText;
struct CResTileSet;
struct CResWED;
struct CSaveGameSlot;
struct CSavedGamePartyCreature;
struct CScreenAI;
struct CSearchBitmap;
struct CSelectiveBonus;
struct CSelectiveWeaponType;
struct CSequenceSound;
struct CSound;
struct CSoundMixerImp;
struct CSpawn;
struct CSpawnList;
struct CSpawnPoint;
struct CSpawnVar;
struct CString;
struct CUIControlTextDisplay;
struct CVVCHashEntry;
struct CVariable;
struct CVidCellFont;
struct CVidMode;
struct CVisibilityMapTreeNode;
struct IDPPeer;
struct SDL_BlitMap;
union SDL_Event;
struct SDL_PixelFormat;
struct SDL_Window;
struct st_tiledef;
struct uiItem;
struct uiMenu;
struct uiVariant;

struct ALCcontext_struct
{
};

struct ALCdevice_struct
{
};

struct CObject
{
	virtual void CObject_Destructor()
	{
	}
};

struct CUIControlTextDisplay
{
};

struct CVideo
{
	CVidMode* pCurrentMode;
};

template<class POINTED_TO_TYPE>
struct Pointer
{
	POINTED_TO_TYPE* reference;

	POINTED_TO_TYPE getValue()
	{
		return *reference;
	}

	void setValue(POINTED_TO_TYPE val)
	{
		*reference = val;
	}
};

struct SAreaFileWrapper
{
	CAreaFileContainer* pContainer;
	CCreatureFileItem* pStartingItem;
	CAreaPoint* pPickPointStart;
};

struct SDL_Cursor
{
	SDL_Cursor* next;
	void* driverdata;
};

struct SProjectileWrapper
{
	CAreaFileProjectileObject* pProjectileObject;
	unsigned __int8* pEffectList;
};

struct __POSITION
{
};

struct WED_ScreenSectionList
{
	unsigned __int16 nStartingPoly;
	unsigned __int16 nNumPolys;
};

struct WED_PolyPoint_st
{
	unsigned __int16 x;
	unsigned __int16 y;
};

struct NECK_POINTS
{
	__int16 x;
	__int16 y;
};

struct CVIDPOLY_VERTEX
{
	unsigned __int16 x;
	unsigned __int16 y;
};

struct CAreaPoint
{
	unsigned __int16 m_xPos;
	unsigned __int16 m_yPos;
};

enum class WindowShapeMode : __int32
{
	ShapeModeDefault = 0,
	ShapeModeBinarizeAlpha = 1,
	ShapeModeReverseBinarizeAlpha = 2,
	ShapeModeColorKey = 3,
};

enum class SDL_bool : __int32
{
	SDL_FALSE = 0,
	SDL_TRUE = 1,
};

enum class SDL_Scancode : __int32
{
	SDL_SCANCODE_UNKNOWN = 0,
	SDL_SCANCODE_A = 4,
	SDL_SCANCODE_B = 5,
	SDL_SCANCODE_C = 6,
	SDL_SCANCODE_D = 7,
	SDL_SCANCODE_E = 8,
	SDL_SCANCODE_F = 9,
	SDL_SCANCODE_G = 10,
	SDL_SCANCODE_H = 11,
	SDL_SCANCODE_I = 12,
	SDL_SCANCODE_J = 13,
	SDL_SCANCODE_K = 14,
	SDL_SCANCODE_L = 15,
	SDL_SCANCODE_M = 16,
	SDL_SCANCODE_N = 17,
	SDL_SCANCODE_O = 18,
	SDL_SCANCODE_P = 19,
	SDL_SCANCODE_Q = 20,
	SDL_SCANCODE_R = 21,
	SDL_SCANCODE_S = 22,
	SDL_SCANCODE_T = 23,
	SDL_SCANCODE_U = 24,
	SDL_SCANCODE_V = 25,
	SDL_SCANCODE_W = 26,
	SDL_SCANCODE_X = 27,
	SDL_SCANCODE_Y = 28,
	SDL_SCANCODE_Z = 29,
	SDL_SCANCODE_1 = 30,
	SDL_SCANCODE_2 = 31,
	SDL_SCANCODE_3 = 32,
	SDL_SCANCODE_4 = 33,
	SDL_SCANCODE_5 = 34,
	SDL_SCANCODE_6 = 35,
	SDL_SCANCODE_7 = 36,
	SDL_SCANCODE_8 = 37,
	SDL_SCANCODE_9 = 38,
	SDL_SCANCODE_0 = 39,
	SDL_SCANCODE_RETURN = 40,
	SDL_SCANCODE_ESCAPE = 41,
	SDL_SCANCODE_BACKSPACE = 42,
	SDL_SCANCODE_TAB = 43,
	SDL_SCANCODE_SPACE = 44,
	SDL_SCANCODE_MINUS = 45,
	SDL_SCANCODE_EQUALS = 46,
	SDL_SCANCODE_LEFTBRACKET = 47,
	SDL_SCANCODE_RIGHTBRACKET = 48,
	SDL_SCANCODE_BACKSLASH = 49,
	SDL_SCANCODE_NONUSHASH = 50,
	SDL_SCANCODE_SEMICOLON = 51,
	SDL_SCANCODE_APOSTROPHE = 52,
	SDL_SCANCODE_GRAVE = 53,
	SDL_SCANCODE_COMMA = 54,
	SDL_SCANCODE_PERIOD = 55,
	SDL_SCANCODE_SLASH = 56,
	SDL_SCANCODE_CAPSLOCK = 57,
	SDL_SCANCODE_F1 = 58,
	SDL_SCANCODE_F2 = 59,
	SDL_SCANCODE_F3 = 60,
	SDL_SCANCODE_F4 = 61,
	SDL_SCANCODE_F5 = 62,
	SDL_SCANCODE_F6 = 63,
	SDL_SCANCODE_F7 = 64,
	SDL_SCANCODE_F8 = 65,
	SDL_SCANCODE_F9 = 66,
	SDL_SCANCODE_F10 = 67,
	SDL_SCANCODE_F11 = 68,
	SDL_SCANCODE_F12 = 69,
	SDL_SCANCODE_PRINTSCREEN = 70,
	SDL_SCANCODE_SCROLLLOCK = 71,
	SDL_SCANCODE_PAUSE = 72,
	SDL_SCANCODE_INSERT = 73,
	SDL_SCANCODE_HOME = 74,
	SDL_SCANCODE_PAGEUP = 75,
	SDL_SCANCODE_DELETE = 76,
	SDL_SCANCODE_END = 77,
	SDL_SCANCODE_PAGEDOWN = 78,
	SDL_SCANCODE_RIGHT = 79,
	SDL_SCANCODE_LEFT = 80,
	SDL_SCANCODE_DOWN = 81,
	SDL_SCANCODE_UP = 82,
	SDL_SCANCODE_NUMLOCKCLEAR = 83,
	SDL_SCANCODE_KP_DIVIDE = 84,
	SDL_SCANCODE_KP_MULTIPLY = 85,
	SDL_SCANCODE_KP_MINUS = 86,
	SDL_SCANCODE_KP_PLUS = 87,
	SDL_SCANCODE_KP_ENTER = 88,
	SDL_SCANCODE_KP_1 = 89,
	SDL_SCANCODE_KP_2 = 90,
	SDL_SCANCODE_KP_3 = 91,
	SDL_SCANCODE_KP_4 = 92,
	SDL_SCANCODE_KP_5 = 93,
	SDL_SCANCODE_KP_6 = 94,
	SDL_SCANCODE_KP_7 = 95,
	SDL_SCANCODE_KP_8 = 96,
	SDL_SCANCODE_KP_9 = 97,
	SDL_SCANCODE_KP_0 = 98,
	SDL_SCANCODE_KP_PERIOD = 99,
	SDL_SCANCODE_NONUSBACKSLASH = 100,
	SDL_SCANCODE_APPLICATION = 101,
	SDL_SCANCODE_POWER = 102,
	SDL_SCANCODE_KP_EQUALS = 103,
	SDL_SCANCODE_F13 = 104,
	SDL_SCANCODE_F14 = 105,
	SDL_SCANCODE_F15 = 106,
	SDL_SCANCODE_F16 = 107,
	SDL_SCANCODE_F17 = 108,
	SDL_SCANCODE_F18 = 109,
	SDL_SCANCODE_F19 = 110,
	SDL_SCANCODE_F20 = 111,
	SDL_SCANCODE_F21 = 112,
	SDL_SCANCODE_F22 = 113,
	SDL_SCANCODE_F23 = 114,
	SDL_SCANCODE_F24 = 115,
	SDL_SCANCODE_EXECUTE = 116,
	SDL_SCANCODE_HELP = 117,
	SDL_SCANCODE_MENU = 118,
	SDL_SCANCODE_SELECT = 119,
	SDL_SCANCODE_STOP = 120,
	SDL_SCANCODE_AGAIN = 121,
	SDL_SCANCODE_UNDO = 122,
	SDL_SCANCODE_CUT = 123,
	SDL_SCANCODE_COPY = 124,
	SDL_SCANCODE_PASTE = 125,
	SDL_SCANCODE_FIND = 126,
	SDL_SCANCODE_MUTE = 127,
	SDL_SCANCODE_VOLUMEUP = 128,
	SDL_SCANCODE_VOLUMEDOWN = 129,
	SDL_SCANCODE_KP_COMMA = 133,
	SDL_SCANCODE_KP_EQUALSAS400 = 134,
	SDL_SCANCODE_INTERNATIONAL1 = 135,
	SDL_SCANCODE_INTERNATIONAL2 = 136,
	SDL_SCANCODE_INTERNATIONAL3 = 137,
	SDL_SCANCODE_INTERNATIONAL4 = 138,
	SDL_SCANCODE_INTERNATIONAL5 = 139,
	SDL_SCANCODE_INTERNATIONAL6 = 140,
	SDL_SCANCODE_INTERNATIONAL7 = 141,
	SDL_SCANCODE_INTERNATIONAL8 = 142,
	SDL_SCANCODE_INTERNATIONAL9 = 143,
	SDL_SCANCODE_LANG1 = 144,
	SDL_SCANCODE_LANG2 = 145,
	SDL_SCANCODE_LANG3 = 146,
	SDL_SCANCODE_LANG4 = 147,
	SDL_SCANCODE_LANG5 = 148,
	SDL_SCANCODE_LANG6 = 149,
	SDL_SCANCODE_LANG7 = 150,
	SDL_SCANCODE_LANG8 = 151,
	SDL_SCANCODE_LANG9 = 152,
	SDL_SCANCODE_ALTERASE = 153,
	SDL_SCANCODE_SYSREQ = 154,
	SDL_SCANCODE_CANCEL = 155,
	SDL_SCANCODE_CLEAR = 156,
	SDL_SCANCODE_PRIOR = 157,
	SDL_SCANCODE_RETURN2 = 158,
	SDL_SCANCODE_SEPARATOR = 159,
	SDL_SCANCODE_OUT = 160,
	SDL_SCANCODE_OPER = 161,
	SDL_SCANCODE_CLEARAGAIN = 162,
	SDL_SCANCODE_CRSEL = 163,
	SDL_SCANCODE_EXSEL = 164,
	SDL_SCANCODE_KP_00 = 176,
	SDL_SCANCODE_KP_000 = 177,
	SDL_SCANCODE_THOUSANDSSEPARATOR = 178,
	SDL_SCANCODE_DECIMALSEPARATOR = 179,
	SDL_SCANCODE_CURRENCYUNIT = 180,
	SDL_SCANCODE_CURRENCYSUBUNIT = 181,
	SDL_SCANCODE_KP_LEFTPAREN = 182,
	SDL_SCANCODE_KP_RIGHTPAREN = 183,
	SDL_SCANCODE_KP_LEFTBRACE = 184,
	SDL_SCANCODE_KP_RIGHTBRACE = 185,
	SDL_SCANCODE_KP_TAB = 186,
	SDL_SCANCODE_KP_BACKSPACE = 187,
	SDL_SCANCODE_KP_A = 188,
	SDL_SCANCODE_KP_B = 189,
	SDL_SCANCODE_KP_C = 190,
	SDL_SCANCODE_KP_D = 191,
	SDL_SCANCODE_KP_E = 192,
	SDL_SCANCODE_KP_F = 193,
	SDL_SCANCODE_KP_XOR = 194,
	SDL_SCANCODE_KP_POWER = 195,
	SDL_SCANCODE_KP_PERCENT = 196,
	SDL_SCANCODE_KP_LESS = 197,
	SDL_SCANCODE_KP_GREATER = 198,
	SDL_SCANCODE_KP_AMPERSAND = 199,
	SDL_SCANCODE_KP_DBLAMPERSAND = 200,
	SDL_SCANCODE_KP_VERTICALBAR = 201,
	SDL_SCANCODE_KP_DBLVERTICALBAR = 202,
	SDL_SCANCODE_KP_COLON = 203,
	SDL_SCANCODE_KP_HASH = 204,
	SDL_SCANCODE_KP_SPACE = 205,
	SDL_SCANCODE_KP_AT = 206,
	SDL_SCANCODE_KP_EXCLAM = 207,
	SDL_SCANCODE_KP_MEMSTORE = 208,
	SDL_SCANCODE_KP_MEMRECALL = 209,
	SDL_SCANCODE_KP_MEMCLEAR = 210,
	SDL_SCANCODE_KP_MEMADD = 211,
	SDL_SCANCODE_KP_MEMSUBTRACT = 212,
	SDL_SCANCODE_KP_MEMMULTIPLY = 213,
	SDL_SCANCODE_KP_MEMDIVIDE = 214,
	SDL_SCANCODE_KP_PLUSMINUS = 215,
	SDL_SCANCODE_KP_CLEAR = 216,
	SDL_SCANCODE_KP_CLEARENTRY = 217,
	SDL_SCANCODE_KP_BINARY = 218,
	SDL_SCANCODE_KP_OCTAL = 219,
	SDL_SCANCODE_KP_DECIMAL = 220,
	SDL_SCANCODE_KP_HEXADECIMAL = 221,
	SDL_SCANCODE_LCTRL = 224,
	SDL_SCANCODE_LSHIFT = 225,
	SDL_SCANCODE_LALT = 226,
	SDL_SCANCODE_LGUI = 227,
	SDL_SCANCODE_RCTRL = 228,
	SDL_SCANCODE_RSHIFT = 229,
	SDL_SCANCODE_RALT = 230,
	SDL_SCANCODE_RGUI = 231,
	SDL_SCANCODE_MODE = 257,
	SDL_SCANCODE_AUDIONEXT = 258,
	SDL_SCANCODE_AUDIOPREV = 259,
	SDL_SCANCODE_AUDIOSTOP = 260,
	SDL_SCANCODE_AUDIOPLAY = 261,
	SDL_SCANCODE_AUDIOMUTE = 262,
	SDL_SCANCODE_MEDIASELECT = 263,
	SDL_SCANCODE_WWW = 264,
	SDL_SCANCODE_MAIL = 265,
	SDL_SCANCODE_CALCULATOR = 266,
	SDL_SCANCODE_COMPUTER = 267,
	SDL_SCANCODE_AC_SEARCH = 268,
	SDL_SCANCODE_AC_HOME = 269,
	SDL_SCANCODE_AC_BACK = 270,
	SDL_SCANCODE_AC_FORWARD = 271,
	SDL_SCANCODE_AC_STOP = 272,
	SDL_SCANCODE_AC_REFRESH = 273,
	SDL_SCANCODE_AC_BOOKMARKS = 274,
	SDL_SCANCODE_BRIGHTNESSDOWN = 275,
	SDL_SCANCODE_BRIGHTNESSUP = 276,
	SDL_SCANCODE_DISPLAYSWITCH = 277,
	SDL_SCANCODE_KBDILLUMTOGGLE = 278,
	SDL_SCANCODE_KBDILLUMDOWN = 279,
	SDL_SCANCODE_KBDILLUMUP = 280,
	SDL_SCANCODE_EJECT = 281,
	SDL_SCANCODE_SLEEP = 282,
	SDL_SCANCODE_APP1 = 283,
	SDL_SCANCODE_APP2 = 284,
	SDL_NUM_SCANCODES = 512,
};

enum class SDL_SYSWM_TYPE : __int32
{
	SDL_SYSWM_UNKNOWN = 0,
	SDL_SYSWM_WINDOWS = 1,
	SDL_SYSWM_X11 = 2,
	SDL_SYSWM_DIRECTFB = 3,
	SDL_SYSWM_COCOA = 4,
	SDL_SYSWM_UIKIT = 5,
	SDL_SYSWM_WAYLAND = 6,
	SDL_SYSWM_MIR = 7,
	SDL_SYSWM_WINRT = 8,
	SDL_SYSWM_ANDROID = 9,
};

enum class SDL_Keycode : __int32
{
	SDLK_UNKNOWN = 0,
	SDLK_BACKSPACE = 8,
	SDLK_TAB = 9,
	SDLK_RETURN = 13,
	SDLK_ESCAPE = 27,
	SDLK_SPACE = 32,
	SDLK_EXCLAIM = 33,
	SDLK_QUOTEDBL = 34,
	SDLK_HASH = 35,
	SDLK_DOLLAR = 36,
	SDLK_PERCENT = 37,
	SDLK_AMPERSAND = 38,
	SDLK_QUOTE = 39,
	SDLK_LEFTPAREN = 40,
	SDLK_RIGHTPAREN = 41,
	SDLK_ASTERISK = 42,
	SDLK_PLUS = 43,
	SDLK_COMMA = 44,
	SDLK_MINUS = 45,
	SDLK_PERIOD = 46,
	SDLK_SLASH = 47,
	SDLK_0 = 48,
	SDLK_1 = 49,
	SDLK_2 = 50,
	SDLK_3 = 51,
	SDLK_4 = 52,
	SDLK_5 = 53,
	SDLK_6 = 54,
	SDLK_7 = 55,
	SDLK_8 = 56,
	SDLK_9 = 57,
	SDLK_COLON = 58,
	SDLK_SEMICOLON = 59,
	SDLK_LESS = 60,
	SDLK_EQUALS = 61,
	SDLK_GREATER = 62,
	SDLK_QUESTION = 63,
	SDLK_AT = 64,
	SDLK_LEFTBRACKET = 91,
	SDLK_BACKSLASH = 92,
	SDLK_RIGHTBRACKET = 93,
	SDLK_CARET = 94,
	SDLK_UNDERSCORE = 95,
	SDLK_BACKQUOTE = 96,
	SDLK_a = 97,
	SDLK_b = 98,
	SDLK_c = 99,
	SDLK_d = 100,
	SDLK_e = 101,
	SDLK_f = 102,
	SDLK_g = 103,
	SDLK_h = 104,
	SDLK_i = 105,
	SDLK_j = 106,
	SDLK_k = 107,
	SDLK_l = 108,
	SDLK_m = 109,
	SDLK_n = 110,
	SDLK_o = 111,
	SDLK_p = 112,
	SDLK_q = 113,
	SDLK_r = 114,
	SDLK_s = 115,
	SDLK_t = 116,
	SDLK_u = 117,
	SDLK_v = 118,
	SDLK_w = 119,
	SDLK_x = 120,
	SDLK_y = 121,
	SDLK_z = 122,
	SDLK_DELETE = 127,
	SDLK_CAPSLOCK = 1073741881,
	SDLK_F1 = 1073741882,
	SDLK_F2 = 1073741883,
	SDLK_F3 = 1073741884,
	SDLK_F4 = 1073741885,
	SDLK_F5 = 1073741886,
	SDLK_F6 = 1073741887,
	SDLK_F7 = 1073741888,
	SDLK_F8 = 1073741889,
	SDLK_F9 = 1073741890,
	SDLK_F10 = 1073741891,
	SDLK_F11 = 1073741892,
	SDLK_F12 = 1073741893,
	SDLK_PRINTSCREEN = 1073741894,
	SDLK_SCROLLLOCK = 1073741895,
	SDLK_PAUSE = 1073741896,
	SDLK_INSERT = 1073741897,
	SDLK_HOME = 1073741898,
	SDLK_PAGEUP = 1073741899,
	SDLK_END = 1073741901,
	SDLK_PAGEDOWN = 1073741902,
	SDLK_RIGHT = 1073741903,
	SDLK_LEFT = 1073741904,
	SDLK_DOWN = 1073741905,
	SDLK_UP = 1073741906,
	SDLK_NUMLOCKCLEAR = 1073741907,
	SDLK_KP_DIVIDE = 1073741908,
	SDLK_KP_MULTIPLY = 1073741909,
	SDLK_KP_MINUS = 1073741910,
	SDLK_KP_PLUS = 1073741911,
	SDLK_KP_ENTER = 1073741912,
	SDLK_KP_1 = 1073741913,
	SDLK_KP_2 = 1073741914,
	SDLK_KP_3 = 1073741915,
	SDLK_KP_4 = 1073741916,
	SDLK_KP_5 = 1073741917,
	SDLK_KP_6 = 1073741918,
	SDLK_KP_7 = 1073741919,
	SDLK_KP_8 = 1073741920,
	SDLK_KP_9 = 1073741921,
	SDLK_KP_0 = 1073741922,
	SDLK_KP_PERIOD = 1073741923,
	SDLK_APPLICATION = 1073741925,
	SDLK_POWER = 1073741926,
	SDLK_KP_EQUALS = 1073741927,
	SDLK_F13 = 1073741928,
	SDLK_F14 = 1073741929,
	SDLK_F15 = 1073741930,
	SDLK_F16 = 1073741931,
	SDLK_F17 = 1073741932,
	SDLK_F18 = 1073741933,
	SDLK_F19 = 1073741934,
	SDLK_F20 = 1073741935,
	SDLK_F21 = 1073741936,
	SDLK_F22 = 1073741937,
	SDLK_F23 = 1073741938,
	SDLK_F24 = 1073741939,
	SDLK_EXECUTE = 1073741940,
	SDLK_HELP = 1073741941,
	SDLK_MENU = 1073741942,
	SDLK_SELECT = 1073741943,
	SDLK_STOP = 1073741944,
	SDLK_AGAIN = 1073741945,
	SDLK_UNDO = 1073741946,
	SDLK_CUT = 1073741947,
	SDLK_COPY = 1073741948,
	SDLK_PASTE = 1073741949,
	SDLK_FIND = 1073741950,
	SDLK_MUTE = 1073741951,
	SDLK_VOLUMEUP = 1073741952,
	SDLK_VOLUMEDOWN = 1073741953,
	SDLK_KP_COMMA = 1073741957,
	SDLK_KP_EQUALSAS400 = 1073741958,
	SDLK_ALTERASE = 1073741977,
	SDLK_SYSREQ = 1073741978,
	SDLK_CANCEL = 1073741979,
	SDLK_CLEAR = 1073741980,
	SDLK_PRIOR = 1073741981,
	SDLK_RETURN2 = 1073741982,
	SDLK_SEPARATOR = 1073741983,
	SDLK_OUT = 1073741984,
	SDLK_OPER = 1073741985,
	SDLK_CLEARAGAIN = 1073741986,
	SDLK_CRSEL = 1073741987,
	SDLK_EXSEL = 1073741988,
	SDLK_KP_00 = 1073742000,
	SDLK_KP_000 = 1073742001,
	SDLK_THOUSANDSSEPARATOR = 1073742002,
	SDLK_DECIMALSEPARATOR = 1073742003,
	SDLK_CURRENCYUNIT = 1073742004,
	SDLK_CURRENCYSUBUNIT = 1073742005,
	SDLK_KP_LEFTPAREN = 1073742006,
	SDLK_KP_RIGHTPAREN = 1073742007,
	SDLK_KP_LEFTBRACE = 1073742008,
	SDLK_KP_RIGHTBRACE = 1073742009,
	SDLK_KP_TAB = 1073742010,
	SDLK_KP_BACKSPACE = 1073742011,
	SDLK_KP_A = 1073742012,
	SDLK_KP_B = 1073742013,
	SDLK_KP_C = 1073742014,
	SDLK_KP_D = 1073742015,
	SDLK_KP_E = 1073742016,
	SDLK_KP_F = 1073742017,
	SDLK_KP_XOR = 1073742018,
	SDLK_KP_POWER = 1073742019,
	SDLK_KP_PERCENT = 1073742020,
	SDLK_KP_LESS = 1073742021,
	SDLK_KP_GREATER = 1073742022,
	SDLK_KP_AMPERSAND = 1073742023,
	SDLK_KP_DBLAMPERSAND = 1073742024,
	SDLK_KP_VERTICALBAR = 1073742025,
	SDLK_KP_DBLVERTICALBAR = 1073742026,
	SDLK_KP_COLON = 1073742027,
	SDLK_KP_HASH = 1073742028,
	SDLK_KP_SPACE = 1073742029,
	SDLK_KP_AT = 1073742030,
	SDLK_KP_EXCLAM = 1073742031,
	SDLK_KP_MEMSTORE = 1073742032,
	SDLK_KP_MEMRECALL = 1073742033,
	SDLK_KP_MEMCLEAR = 1073742034,
	SDLK_KP_MEMADD = 1073742035,
	SDLK_KP_MEMSUBTRACT = 1073742036,
	SDLK_KP_MEMMULTIPLY = 1073742037,
	SDLK_KP_MEMDIVIDE = 1073742038,
	SDLK_KP_PLUSMINUS = 1073742039,
	SDLK_KP_CLEAR = 1073742040,
	SDLK_KP_CLEARENTRY = 1073742041,
	SDLK_KP_BINARY = 1073742042,
	SDLK_KP_OCTAL = 1073742043,
	SDLK_KP_DECIMAL = 1073742044,
	SDLK_KP_HEXADECIMAL = 1073742045,
	SDLK_LCTRL = 1073742048,
	SDLK_LSHIFT = 1073742049,
	SDLK_LALT = 1073742050,
	SDLK_LGUI = 1073742051,
	SDLK_RCTRL = 1073742052,
	SDLK_RSHIFT = 1073742053,
	SDLK_RALT = 1073742054,
	SDLK_RGUI = 1073742055,
	SDLK_MODE = 1073742081,
	SDLK_AUDIONEXT = 1073742082,
	SDLK_AUDIOPREV = 1073742083,
	SDLK_AUDIOSTOP = 1073742084,
	SDLK_AUDIOPLAY = 1073742085,
	SDLK_AUDIOMUTE = 1073742086,
	SDLK_MEDIASELECT = 1073742087,
	SDLK_WWW = 1073742088,
	SDLK_MAIL = 1073742089,
	SDLK_CALCULATOR = 1073742090,
	SDLK_COMPUTER = 1073742091,
	SDLK_AC_SEARCH = 1073742092,
	SDLK_AC_HOME = 1073742093,
	SDLK_AC_BACK = 1073742094,
	SDLK_AC_FORWARD = 1073742095,
	SDLK_AC_STOP = 1073742096,
	SDLK_AC_REFRESH = 1073742097,
	SDLK_AC_BOOKMARKS = 1073742098,
	SDLK_BRIGHTNESSDOWN = 1073742099,
	SDLK_BRIGHTNESSUP = 1073742100,
	SDLK_DISPLAYSWITCH = 1073742101,
	SDLK_KBDILLUMTOGGLE = 1073742102,
	SDLK_KBDILLUMDOWN = 1073742103,
	SDLK_KBDILLUMUP = 1073742104,
	SDLK_EJECT = 1073742105,
	SDLK_SLEEP = 1073742106,
};

enum class SDL_HitTestResult : __int32
{
	SDL_HITTEST_NORMAL = 0,
	SDL_HITTEST_DRAGGABLE = 1,
	SDL_HITTEST_RESIZE_TOPLEFT = 2,
	SDL_HITTEST_RESIZE_TOP = 3,
	SDL_HITTEST_RESIZE_TOPRIGHT = 4,
	SDL_HITTEST_RESIZE_RIGHT = 5,
	SDL_HITTEST_RESIZE_BOTTOMRIGHT = 6,
	SDL_HITTEST_RESIZE_BOTTOM = 7,
	SDL_HITTEST_RESIZE_BOTTOMLEFT = 8,
	SDL_HITTEST_RESIZE_LEFT = 9,
};

enum class SDL_EventType : __int32
{
	SDL_FIRSTEVENT = 0,
	SDL_QUIT = 256,
	SDL_APP_TERMINATING = 257,
	SDL_APP_LOWMEMORY = 258,
	SDL_APP_WILLENTERBACKGROUND = 259,
	SDL_APP_DIDENTERBACKGROUND = 260,
	SDL_APP_WILLENTERFOREGROUND = 261,
	SDL_APP_DIDENTERFOREGROUND = 262,
	SDL_APP_UI_COVERED = 263,
	SDL_APP_SHOW_GAME_MESSAGE = 264,
	SDL_WINDOWEVENT = 512,
	SDL_SYSWMEVENT = 513,
	SDL_KEYDOWN = 768,
	SDL_KEYUP = 769,
	SDL_TEXTEDITING = 770,
	SDL_TEXTINPUT = 771,
	SDL_KEYMAPCHANGED = 772,
	SDL_MOUSEMOTION = 1024,
	SDL_MOUSEBUTTONDOWN = 1025,
	SDL_MOUSEBUTTONUP = 1026,
	SDL_MOUSEWHEEL = 1027,
	SDL_JOYAXISMOTION = 1536,
	SDL_JOYBALLMOTION = 1537,
	SDL_JOYHATMOTION = 1538,
	SDL_JOYBUTTONDOWN = 1539,
	SDL_JOYBUTTONUP = 1540,
	SDL_JOYDEVICEADDED = 1541,
	SDL_JOYDEVICEREMOVED = 1542,
	SDL_CONTROLLERAXISMOTION = 1616,
	SDL_CONTROLLERBUTTONDOWN = 1617,
	SDL_CONTROLLERBUTTONUP = 1618,
	SDL_CONTROLLERDEVICEADDED = 1619,
	SDL_CONTROLLERDEVICEREMOVED = 1620,
	SDL_CONTROLLERDEVICEREMAPPED = 1621,
	SDL_FINGERDOWN = 1792,
	SDL_FINGERUP = 1793,
	SDL_FINGERMOTION = 1794,
	SDL_DOLLARGESTURE = 2048,
	SDL_DOLLARRECORD = 2049,
	SDL_MULTIGESTURE = 2050,
	SDL_MAGNIFY = 2051,
	SDL_PAN = 2052,
	SDL_TAP = 2053,
	SDL_DOUBLETAP = 2054,
	SDL_LONGTAP = 2055,
	SDL_FLICK = 2056,
	SDL_CLIPBOARDUPDATE = 2304,
	SDL_DROPFILE = 4096,
	SDL_AUDIODEVICEADDED = 4352,
	SDL_AUDIODEVICEREMOVED = 4353,
	SDL_RENDER_TARGETS_RESET = 8192,
	SDL_RENDER_DEVICE_RESET = 8193,
	SDL_USEREVENT = 32768,
	SDL_LASTEVENT = 65535,
};

enum class EWorkshopVideoProvider : __int32
{
	k_EWorkshopVideoProviderNone = 0,
	k_EWorkshopVideoProviderYoutube = 1,
};

enum class EWorkshopFileType : __int32
{
	k_EWorkshopFileTypeFirst = 0,
	k_EWorkshopFileTypeCommunity = 0,
	k_EWorkshopFileTypeMicrotransaction = 1,
	k_EWorkshopFileTypeCollection = 2,
	k_EWorkshopFileTypeArt = 3,
	k_EWorkshopFileTypeVideo = 4,
	k_EWorkshopFileTypeScreenshot = 5,
	k_EWorkshopFileTypeGame = 6,
	k_EWorkshopFileTypeSoftware = 7,
	k_EWorkshopFileTypeConcept = 8,
	k_EWorkshopFileTypeWebGuide = 9,
	k_EWorkshopFileTypeIntegratedGuide = 10,
	k_EWorkshopFileTypeMerch = 11,
	k_EWorkshopFileTypeControllerBinding = 12,
	k_EWorkshopFileTypeSteamworksAccessInvite = 13,
	k_EWorkshopFileTypeSteamVideo = 14,
	k_EWorkshopFileTypeGameManagedItem = 15,
	k_EWorkshopFileTypeMax = 16,
};

enum class EWorkshopFileAction : __int32
{
	k_EWorkshopFileActionPlayed = 0,
	k_EWorkshopFileActionCompleted = 1,
};

enum class EWorkshopEnumerationType : __int32
{
	k_EWorkshopEnumerationTypeRankedByVote = 0,
	k_EWorkshopEnumerationTypeRecent = 1,
	k_EWorkshopEnumerationTypeTrending = 2,
	k_EWorkshopEnumerationTypeFavoritesOfFriends = 3,
	k_EWorkshopEnumerationTypeVotedByFriends = 4,
	k_EWorkshopEnumerationTypeContentByFriends = 5,
	k_EWorkshopEnumerationTypeRecentFromFollowedUsers = 6,
};

enum class EUserUGCListSortOrder : __int32
{
	k_EUserUGCListSortOrder_CreationOrderDesc = 0,
	k_EUserUGCListSortOrder_CreationOrderAsc = 1,
	k_EUserUGCListSortOrder_TitleAsc = 2,
	k_EUserUGCListSortOrder_LastUpdatedDesc = 3,
	k_EUserUGCListSortOrder_SubscriptionDateDesc = 4,
	k_EUserUGCListSortOrder_VoteScoreDesc = 5,
	k_EUserUGCListSortOrder_ForModeration = 6,
};

enum class EUserUGCList : __int32
{
	k_EUserUGCList_Published = 0,
	k_EUserUGCList_VotedOn = 1,
	k_EUserUGCList_VotedUp = 2,
	k_EUserUGCList_VotedDown = 3,
	k_EUserUGCList_WillVoteLater = 4,
	k_EUserUGCList_Favorited = 5,
	k_EUserUGCList_Subscribed = 6,
	k_EUserUGCList_UsedOrPlayed = 7,
	k_EUserUGCList_Followed = 8,
};

enum class EUGCReadAction : __int32
{
	k_EUGCRead_ContinueReadingUntilFinished = 0,
	k_EUGCRead_ContinueReading = 1,
	k_EUGCRead_Close = 2,
};

enum class EUGCQuery : __int32
{
	k_EUGCQuery_RankedByVote = 0,
	k_EUGCQuery_RankedByPublicationDate = 1,
	k_EUGCQuery_AcceptedForGameRankedByAcceptanceDate = 2,
	k_EUGCQuery_RankedByTrend = 3,
	k_EUGCQuery_FavoritedByFriendsRankedByPublicationDate = 4,
	k_EUGCQuery_CreatedByFriendsRankedByPublicationDate = 5,
	k_EUGCQuery_RankedByNumTimesReported = 6,
	k_EUGCQuery_CreatedByFollowedUsersRankedByPublicationDate = 7,
	k_EUGCQuery_NotYetRated = 8,
	k_EUGCQuery_RankedByTotalVotesAsc = 9,
	k_EUGCQuery_RankedByVotesUp = 10,
	k_EUGCQuery_RankedByTextSearch = 11,
	k_EUGCQuery_RankedByTotalUniqueSubscriptions = 12,
	k_EUGCQuery_RankedByPlaytimeTrend = 13,
	k_EUGCQuery_RankedByTotalPlaytime = 14,
	k_EUGCQuery_RankedByAveragePlaytimeTrend = 15,
	k_EUGCQuery_RankedByLifetimeAveragePlaytime = 16,
	k_EUGCQuery_RankedByPlaytimeSessionsTrend = 17,
	k_EUGCQuery_RankedByLifetimePlaytimeSessions = 18,
};

enum class EUGCMatchingUGCType : __int32
{
	k_EUGCMatchingUGCType_Items = 0,
	k_EUGCMatchingUGCType_Items_Mtx = 1,
	k_EUGCMatchingUGCType_Items_ReadyToUse = 2,
	k_EUGCMatchingUGCType_Collections = 3,
	k_EUGCMatchingUGCType_Artwork = 4,
	k_EUGCMatchingUGCType_Videos = 5,
	k_EUGCMatchingUGCType_Screenshots = 6,
	k_EUGCMatchingUGCType_AllGuides = 7,
	k_EUGCMatchingUGCType_WebGuides = 8,
	k_EUGCMatchingUGCType_IntegratedGuides = 9,
	k_EUGCMatchingUGCType_UsableInGame = 10,
	k_EUGCMatchingUGCType_ControllerBindings = 11,
	k_EUGCMatchingUGCType_GameManagedItems = 12,
	k_EUGCMatchingUGCType_All = -1,
};

enum class EResult : __int32
{
	k_EResultNone = 0,
	k_EResultOK = 1,
	k_EResultFail = 2,
	k_EResultNoConnection = 3,
	k_EResultInvalidPassword = 5,
	k_EResultLoggedInElsewhere = 6,
	k_EResultInvalidProtocolVer = 7,
	k_EResultInvalidParam = 8,
	k_EResultFileNotFound = 9,
	k_EResultBusy = 10,
	k_EResultInvalidState = 11,
	k_EResultInvalidName = 12,
	k_EResultInvalidEmail = 13,
	k_EResultDuplicateName = 14,
	k_EResultAccessDenied = 15,
	k_EResultTimeout = 16,
	k_EResultBanned = 17,
	k_EResultAccountNotFound = 18,
	k_EResultInvalidSteamID = 19,
	k_EResultServiceUnavailable = 20,
	k_EResultNotLoggedOn = 21,
	k_EResultPending = 22,
	k_EResultEncryptionFailure = 23,
	k_EResultInsufficientPrivilege = 24,
	k_EResultLimitExceeded = 25,
	k_EResultRevoked = 26,
	k_EResultExpired = 27,
	k_EResultAlreadyRedeemed = 28,
	k_EResultDuplicateRequest = 29,
	k_EResultAlreadyOwned = 30,
	k_EResultIPNotFound = 31,
	k_EResultPersistFailed = 32,
	k_EResultLockingFailed = 33,
	k_EResultLogonSessionReplaced = 34,
	k_EResultConnectFailed = 35,
	k_EResultHandshakeFailed = 36,
	k_EResultIOFailure = 37,
	k_EResultRemoteDisconnect = 38,
	k_EResultShoppingCartNotFound = 39,
	k_EResultBlocked = 40,
	k_EResultIgnored = 41,
	k_EResultNoMatch = 42,
	k_EResultAccountDisabled = 43,
	k_EResultServiceReadOnly = 44,
	k_EResultAccountNotFeatured = 45,
	k_EResultAdministratorOK = 46,
	k_EResultContentVersion = 47,
	k_EResultTryAnotherCM = 48,
	k_EResultPasswordRequiredToKickSession = 49,
	k_EResultAlreadyLoggedInElsewhere = 50,
	k_EResultSuspended = 51,
	k_EResultCancelled = 52,
	k_EResultDataCorruption = 53,
	k_EResultDiskFull = 54,
	k_EResultRemoteCallFailed = 55,
	k_EResultPasswordUnset = 56,
	k_EResultExternalAccountUnlinked = 57,
	k_EResultPSNTicketInvalid = 58,
	k_EResultExternalAccountAlreadyLinked = 59,
	k_EResultRemoteFileConflict = 60,
	k_EResultIllegalPassword = 61,
	k_EResultSameAsPreviousValue = 62,
	k_EResultAccountLogonDenied = 63,
	k_EResultCannotUseOldPassword = 64,
	k_EResultInvalidLoginAuthCode = 65,
	k_EResultAccountLogonDeniedNoMail = 66,
	k_EResultHardwareNotCapableOfIPT = 67,
	k_EResultIPTInitError = 68,
	k_EResultParentalControlRestricted = 69,
	k_EResultFacebookQueryError = 70,
	k_EResultExpiredLoginAuthCode = 71,
	k_EResultIPLoginRestrictionFailed = 72,
	k_EResultAccountLockedDown = 73,
	k_EResultAccountLogonDeniedVerifiedEmailRequired = 74,
	k_EResultNoMatchingURL = 75,
	k_EResultBadResponse = 76,
	k_EResultRequirePasswordReEntry = 77,
	k_EResultValueOutOfRange = 78,
	k_EResultUnexpectedError = 79,
	k_EResultDisabled = 80,
	k_EResultInvalidCEGSubmission = 81,
	k_EResultRestrictedDevice = 82,
	k_EResultRegionLocked = 83,
	k_EResultRateLimitExceeded = 84,
	k_EResultAccountLoginDeniedNeedTwoFactor = 85,
	k_EResultItemDeleted = 86,
	k_EResultAccountLoginDeniedThrottle = 87,
	k_EResultTwoFactorCodeMismatch = 88,
	k_EResultTwoFactorActivationCodeMismatch = 89,
	k_EResultAccountAssociatedToMultiplePartners = 90,
	k_EResultNotModified = 91,
	k_EResultNoMobileDevice = 92,
	k_EResultTimeNotSynced = 93,
	k_EResultSmsCodeFailed = 94,
	k_EResultAccountLimitExceeded = 95,
	k_EResultAccountActivityLimitExceeded = 96,
	k_EResultPhoneActivityLimitExceeded = 97,
	k_EResultRefundToWallet = 98,
	k_EResultEmailSendFailure = 99,
	k_EResultNotSettled = 100,
	k_EResultNeedCaptcha = 101,
	k_EResultGSLTDenied = 102,
	k_EResultGSOwnerDenied = 103,
	k_EResultInvalidItemType = 104,
	k_EResultIPBanned = 105,
	k_EResultGSLTExpired = 106,
	k_EResultInsufficientFunds = 107,
	k_EResultTooManyPending = 108,
	k_EResultNoSiteLicensesFound = 109,
	k_EResultWGNetworkSendExceeded = 110,
	k_EResultAccountNotFriends = 111,
	k_EResultLimitedUserAccount = 112,
	k_EResultCantRemoveItem = 113,
	k_EResultAccountDeleted = 114,
	k_EResultExistingUserCancelledLicense = 115,
	k_EResultCommunityCooldown = 116,
};

enum class ERemoteStoragePublishedFileVisibility : __int32
{
	k_ERemoteStoragePublishedFileVisibilityPublic = 0,
	k_ERemoteStoragePublishedFileVisibilityFriendsOnly = 1,
	k_ERemoteStoragePublishedFileVisibilityPrivate = 2,
	k_ERemoteStoragePublishedFileVisibilityUnlisted = 3,
};

enum class ERemoteStoragePlatform : __int32
{
	k_ERemoteStoragePlatformNone = 0,
	k_ERemoteStoragePlatformWindows = 1,
	k_ERemoteStoragePlatformOSX = 2,
	k_ERemoteStoragePlatformPS3 = 4,
	k_ERemoteStoragePlatformLinux = 8,
	k_ERemoteStoragePlatformSwitch = 16,
	k_ERemoteStoragePlatformAndroid = 32,
	k_ERemoteStoragePlatformIOS = 64,
	k_ERemoteStoragePlatformAll = -1,
};

enum class ELeaderboardUploadScoreMethod : __int32
{
	k_ELeaderboardUploadScoreMethodNone = 0,
	k_ELeaderboardUploadScoreMethodKeepBest = 1,
	k_ELeaderboardUploadScoreMethodForceUpdate = 2,
};

enum class ELeaderboardSortMethod : __int32
{
	k_ELeaderboardSortMethodNone = 0,
	k_ELeaderboardSortMethodAscending = 1,
	k_ELeaderboardSortMethodDescending = 2,
};

enum class ELeaderboardDisplayType : __int32
{
	k_ELeaderboardDisplayTypeNone = 0,
	k_ELeaderboardDisplayTypeNumeric = 1,
	k_ELeaderboardDisplayTypeTimeSeconds = 2,
	k_ELeaderboardDisplayTypeTimeMilliSeconds = 3,
};

enum class ELeaderboardDataRequest : __int32
{
	k_ELeaderboardDataRequestGlobal = 0,
	k_ELeaderboardDataRequestGlobalAroundUser = 1,
	k_ELeaderboardDataRequestFriends = 2,
	k_ELeaderboardDataRequestUsers = 3,
};

enum class EItemUpdateStatus : __int32
{
	k_EItemUpdateStatusInvalid = 0,
	k_EItemUpdateStatusPreparingConfig = 1,
	k_EItemUpdateStatusPreparingContent = 2,
	k_EItemUpdateStatusUploadingContent = 3,
	k_EItemUpdateStatusUploadingPreviewFile = 4,
	k_EItemUpdateStatusCommittingChanges = 5,
};

enum class EItemStatistic : __int32
{
	k_EItemStatistic_NumSubscriptions = 0,
	k_EItemStatistic_NumFavorites = 1,
	k_EItemStatistic_NumFollowers = 2,
	k_EItemStatistic_NumUniqueSubscriptions = 3,
	k_EItemStatistic_NumUniqueFavorites = 4,
	k_EItemStatistic_NumUniqueFollowers = 5,
	k_EItemStatistic_NumUniqueWebsiteViews = 6,
	k_EItemStatistic_ReportScore = 7,
	k_EItemStatistic_NumSecondsPlayed = 8,
	k_EItemStatistic_NumPlaytimeSessions = 9,
	k_EItemStatistic_NumComments = 10,
	k_EItemStatistic_NumSecondsPlayedDuringTimePeriod = 11,
	k_EItemStatistic_NumPlaytimeSessionsDuringTimePeriod = 12,
};

enum class EItemPreviewType : __int32
{
	k_EItemPreviewType_Image = 0,
	k_EItemPreviewType_YouTubeVideo = 1,
	k_EItemPreviewType_Sketchfab = 2,
	k_EItemPreviewType_EnvironmentMap_HorizontalCross = 3,
	k_EItemPreviewType_EnvironmentMap_LatLong = 4,
	k_EItemPreviewType_ReservedMax = 255,
};

enum class DP_ProviderID : __int32
{
	DP_PROVIDER_NONE = 0,
	DP_PROVIDER_TCPIP = 1,
	DP_PROVIDER_JINGLE = 2,
	DP_PROVIDER_GAMEKIT = 3,
};

enum class DP_EventType : __int32
{
	DP_EVENT_TYPE_NONE = 0,
	DP_EVENT_TYPE_CONNECT = 1,
	DP_EVENT_TYPE_DISCONNECT = 2,
	DP_EVENT_TYPE_RECEIVE = 3,
};

struct CSoundMixer
{
	CSoundMixerImp* pimpl;
};

enum class CScreenCreateCharStep : __int32
{
	CSCREENCREATECHAR_STEP_GENDER = 0,
	CSCREENCREATECHAR_STEP_PORTRAIT = 1,
	CSCREENCREATECHAR_STEP_CUSTOMPORTRAITS = 2,
	CSCREENCREATECHAR_STEP_RACE = 3,
	CSCREENCREATECHAR_STEP_CLASS = 4,
	CSCREENCREATECHAR_STEP_MULTICLASS = 5,
	CSCREENCREATECHAR_STEP_KIT = 6,
	CSCREENCREATECHAR_STEP_ALIGNMENT = 7,
	CSCREENCREATECHAR_STEP_ABILITIES = 8,
	CSCREENCREATECHAR_STEP_SKILLS = 9,
	CSCREENCREATECHAR_STEP_HATEDRACE = 10,
	CSCREENCREATECHAR_STEP_CHOOSE_MAGE = 11,
	CSCREENCREATECHAR_STEP_MEMORIZE_MAGE = 12,
	CSCREENCREATECHAR_STEP_MEMORIZE_PRIEST = 13,
	CSCREENCREATECHAR_STEP_PROFICIENCIES = 14,
	CSCREENCREATECHAR_STEP_APPEARANCE = 15,
	CSCREENCREATECHAR_STEP_CUSTOMSOUNDS = 16,
	CSCREENCREATECHAR_STEP_NAME = 17,
	CSCREENCREATECHAR_STEP_DONE = 18,
	CSCREENCREATECHAR_STEP_IMPORT = 19,
	CSCREENCREATECHAR_STEP_EXPORT = 20,
	CSCREENCREATECHAR_STEP_BIOGRAPHY = 21,
	CSCREENCREATECHAR_STEP_PREROLL = 22,
	CSCREENCREATECHAR_STEP_ERROR_MESSAGE = 23,
	CSCREENCREATECHAR_STEP_DUALCLASS_CLASS = 24,
	CSCREENCREATECHAR_STEP_DUALCLASS_PROFICIENCIES = 25,
	CSCREENCREATECHAR_STEP_DUALCLASS_CHOOSE_MAGE = 26,
	CSCREENCREATECHAR_STEP_DUALCLASS_DONE = 27,
	CSCREENCREATECHAR_STEP_LEVELUP_PROFICIENCIES = 28,
	CSCREENCREATECHAR_STEP_LEVELUP_HIGH_LEVEL_ABILITIES = 29,
};

enum class CGameJournalEntryFlag : __int32
{
	CGJEOpen = 0,
	CGJEClosed = 1,
	CGJEInUse = 2,
};

enum class CButtonType : __int32
{
	BARD_SONG = 2,
	CAST_SPELL = 3,
	FIND_TRAPS = 4,
	TALK = 5,
	GUARD = 7,
	ATTACK = 8,
	SPECIAL_ABILITIES = 16,
	STEALTH = 17,
	THIEVING = 18,
	TURN_UNDEAD = 19,
	USE_ITEM = 20,
	STOP = 21,
	QUICK_ITEM_1 = 33,
	QUICK_ITEM_2 = 34,
	QUICK_ITEM_3 = 35,
	QUICK_SPELL_1 = 36,
	QUICK_SPELL_2 = 37,
	QUICK_SPELL_3 = 38,
	QUICK_WEAPON_1 = 39,
	QUICK_WEAPON_2 = 40,
	QUICK_WEAPON_3 = 41,
	QUICK_WEAPON_4 = 48,
	NONE = 256,
};

struct _6B279AA1C7A281E7C97E085DB9F2DFBB
{
	__int32 move : 1;
	__int32 left : 1;
	__int32 right : 1;
	__int32 top : 1;
	__int32 bottom : 1;
};

struct CSteamID
{
	union SteamID_t
	{
		struct SteamIDComponent_t
		{
			unsigned __int32 m_unAccountID : 32;
			unsigned __int32 m_unAccountInstance : 20;
			unsigned __int32 m_EAccountType : 4;
			__int32 m_EUniverse : 8;
		};

		CSteamID::SteamID_t::SteamIDComponent_t m_comp;
		unsigned __int64 m_unAll64Bits;
	};

	CSteamID::SteamID_t m_steamid;
};

struct VRAM_FLAGS
{
	unsigned __int8 bVRamUpdated : 1;
};

struct TILE_CODE
{
	unsigned __int8 tileNW;
	unsigned __int8 tileNE;
	unsigned __int8 tileSW;
	unsigned __int8 tileSE;
};

struct SDL_version
{
	unsigned __int8 major;
	unsigned __int8 minor;
	unsigned __int8 patch;
};

struct SDL_Color
{
	unsigned __int8 r;
	unsigned __int8 g;
	unsigned __int8 b;
	unsigned __int8 a;
};

union SDL_WindowShapeParams
{
	unsigned __int8 binarizationCutoff;
	SDL_Color colorKey;
};

struct SDL_WindowShapeMode
{
	WindowShapeMode mode;
	SDL_WindowShapeParams parameters;
};

struct CVisibilityMapEllipse
{
	__int16 m_nXExploreRange;
	__int16 m_nYExploreRange;
	unsigned __int8* m_pXEllipsePts;
	unsigned __int8* m_pYEllipsePts;
	unsigned __int8 m_nXPtsSize;
	unsigned __int8 m_nYPtsSize;
};

enum class CGameObjectType : __int8
{
	NONE = 0,
	AIBASE = 1,
	SOUND = 16,
	CONTAINER = 17,
	SPAWNING = 32,
	DOOR = 33,
	STATIC = 48,
	SPRITE = 49,
	OBJECT_MARKER = 64,
	TRIGGER = 65,
	TILED_OBJECT = 81,
	TEMPORAL = 96,
	AREA_AI = 97,
	FIREBALL = 112,
	GAME_AI = 113,
};

struct CColorRange
{
	unsigned __int8 m_range;
	unsigned __int8 m_color;
};

struct SubmitItemUpdateResult_t
{
	EResult m_eResult;
	bool m_bUserNeedsToAcceptWorkshopLegalAgreement;
	unsigned __int64 m_nPublishedFileId;
};

struct CreateItemResult_t
{
	EResult m_eResult;
	unsigned __int64 m_nPublishedFileId;
	bool m_bUserNeedsToAcceptWorkshopLegalAgreement;
};

enum class importStateType : __int32
{
	Character = 0,
	Game = 1,
	CharacterFromGame = 2,
	GameInvalid = 3,
	PartyFromGame = 4,
};

struct frameTableEntry_st
{
	struct _anonymous_tag_
	{
		struct v2_t
		{
			__int16 nQuadStart;
			__int16 nQuadCount;
		};

	};

	union _C3D261E28D53B12983426B9B0D118A61
	{
		unsigned int nOffset;
		frameTableEntry_st::_anonymous_tag_::v2_t v2;
	};

	unsigned __int16 nWidth;
	unsigned __int16 nHeight;
	__int16 nCenterX;
	__int16 nCenterY;
	frameTableEntry_st::_C3D261E28D53B12983426B9B0D118A61 ___u4;
};

struct file_t
{
	int fd;
	int fm;
	int fs;
	int zo;
	int zs;
};

struct cnetworkwindow_queueentry_st
{
	int dpIDFrom;
	int dpIDTo;
	unsigned __int8* pInfo;
	unsigned int dwSize;
	unsigned int dwFlags;
};

struct bamHeader_st
{
	unsigned int nFileType;
	unsigned int nFileVersion;
	unsigned __int16 nFrames;
	unsigned __int8 nSequences;
	unsigned __int8 nTransparentColor;
	unsigned int nTableOffset;
	unsigned int nPaletteOffset;
	unsigned int nFrameListOffset;
};

struct _EdgeDescription
{
	_EdgeDescription* pNextEdge;
	int x;
	int nStartY;
	int nXDirection;
	int nXIncrement;
	int nErrTerm;
	int nErrTermAdjUp;
	int nErrTermAdjDown;
	int nCount;
};

struct _EAXPRESET
{
	unsigned int dwEnvironment;
	float fVolume;
	float fDecay;
	float fDamping;
};

struct CSoundProperties
{
	_EAXPRESET m_iEAXpreset;
};

struct WED_WedHeader_st
{
	unsigned int nFileType;
	unsigned int nFileVersion;
	unsigned int nLayers;
	unsigned int nTiledObjects;
	unsigned int nOffsetToLayerHeaders;
	unsigned int nOffsetToPolyHeader;
	unsigned int nOffsetToTiledObjects;
	unsigned int nOffsetToObjectTileList;
	unsigned __int16 nVisiblityRange;
	unsigned __int16 nChanceOfRain;
	unsigned __int16 nChanceOfFog;
	unsigned __int16 nChanceOfSnow;
	unsigned int dwFlags;
};

struct WED_PolyList_st
{
	unsigned int nStartingPoint;
	unsigned int nNumPoints;
	unsigned __int8 nType;
	unsigned __int8 nHeight;
	unsigned __int16 nLeft;
	unsigned __int16 nRight;
	unsigned __int16 nTop;
	unsigned __int16 nBottom;
};

struct WED_PolyHeader_st
{
	unsigned int nPolys;
	unsigned int nOffsetToPolyList;
	unsigned int nOffsetToPointList;
	unsigned int nOffsetToScreenSectionList;
	unsigned int nOffsetToScreenPolyList;
};

struct WAV_Header
{
	unsigned __int16 wFormatTag;
	unsigned __int16 nChannels;
	unsigned int nSamplesPerSec;
	unsigned int nAvgBytesPerSec;
	unsigned __int16 nBlockAlign;
	unsigned __int16 wBitsPerSample;
	unsigned __int16 cbSize;
};

struct SteamParamStringArray_t
{
	const char** m_ppStrings;
	int m_nNumStrings;
};

struct SDL_WindowShaper
{
	SDL_Window* window;
	unsigned int userx;
	unsigned int usery;
	SDL_WindowShapeMode mode;
	SDL_bool hasshape;
	void* driverdata;
};

struct SDL_WindowEvent
{
	unsigned int type;
	unsigned int timestamp;
	unsigned int windowID;
	unsigned __int8 event;
	unsigned __int8 padding1;
	unsigned __int8 padding2;
	unsigned __int8 padding3;
	int data1;
	int data2;
};

struct SDL_UserEvent
{
	unsigned int type;
	unsigned int timestamp;
	unsigned int windowID;
	int code;
	void* data1;
	void* data2;
};

struct SDL_TouchFingerEvent
{
	unsigned int type;
	unsigned int timestamp;
	__int64 touchId;
	__int64 fingerId;
	float x;
	float y;
	float dx;
	float dy;
	float pressure;
};

struct SDL_SysWMmsg
{
	union msg_t
	{
		struct win_t
		{
			HWND__* hwnd;
			unsigned int msg;
			unsigned __int64 wParam;
			__int64 lParam;
		};

		SDL_SysWMmsg::msg_t::win_t win;
		int dummy;
	};

	SDL_version version;
	SDL_SYSWM_TYPE subsystem;
	SDL_SysWMmsg::msg_t msg;
};

struct SDL_SysWMEvent
{
	unsigned int type;
	unsigned int timestamp;
	SDL_SysWMmsg* msg;
};

struct SDL_Rect
{
	int x;
	int y;
	int w;
	int h;
};

struct SDL_Surface
{
	unsigned int flags;
	SDL_PixelFormat* format;
	int w;
	int h;
	int pitch;
	void* pixels;
	void* userdata;
	int locked;
	void* lock_data;
	SDL_Rect clip_rect;
	SDL_BlitMap* map;
	int refcount;
};

struct SDL_QuitEvent
{
	unsigned int type;
	unsigned int timestamp;
};

struct SDL_Point
{
	int x;
	int y;
};

struct SDL_Palette
{
	int ncolors;
	SDL_Color* colors;
	unsigned int version;
	int refcount;
};

struct SDL_MultiGestureEvent
{
	unsigned int type;
	unsigned int timestamp;
	__int64 touchId;
	float dTheta;
	float dDist;
	float x;
	float y;
	unsigned __int16 numFingers;
	unsigned __int16 padding;
};

struct SDL_MouseWheelEvent
{
	unsigned int type;
	unsigned int timestamp;
	unsigned int windowID;
	unsigned int which;
	int x;
	int y;
	unsigned int direction;
};

struct SDL_MouseMotionEvent
{
	unsigned int type;
	unsigned int timestamp;
	unsigned int windowID;
	unsigned int which;
	unsigned int state;
	int x;
	int y;
	int xrel;
	int yrel;
};

struct SDL_MouseButtonEvent
{
	unsigned int type;
	unsigned int timestamp;
	unsigned int windowID;
	unsigned int which;
	unsigned __int8 button;
	unsigned __int8 state;
	unsigned __int8 clicks;
	unsigned __int8 padding1;
	int x;
	int y;
};

struct SDL_Keysym
{
	SDL_Scancode scancode;
	SDL_Keycode sym;
	unsigned __int16 mod;
	unsigned int unused;
};

struct SDL_KeyboardEvent
{
	unsigned int type;
	unsigned int timestamp;
	unsigned int windowID;
	unsigned __int8 state;
	unsigned __int8 repeat;
	unsigned __int8 padding2;
	unsigned __int8 padding3;
	SDL_Keysym keysym;
};

struct SDL_JoyHatEvent
{
	unsigned int type;
	unsigned int timestamp;
	int which;
	unsigned __int8 hat;
	unsigned __int8 value;
	unsigned __int8 padding1;
	unsigned __int8 padding2;
};

struct SDL_JoyDeviceEvent
{
	unsigned int type;
	unsigned int timestamp;
	int which;
};

struct SDL_JoyButtonEvent
{
	unsigned int type;
	unsigned int timestamp;
	int which;
	unsigned __int8 button;
	unsigned __int8 state;
	unsigned __int8 padding1;
	unsigned __int8 padding2;
};

struct SDL_JoyBallEvent
{
	unsigned int type;
	unsigned int timestamp;
	int which;
	unsigned __int8 ball;
	unsigned __int8 padding1;
	unsigned __int8 padding2;
	unsigned __int8 padding3;
	__int16 xrel;
	__int16 yrel;
};

struct SDL_JoyAxisEvent
{
	unsigned int type;
	unsigned int timestamp;
	int which;
	unsigned __int8 axis;
	unsigned __int8 padding1;
	unsigned __int8 padding2;
	unsigned __int8 padding3;
	__int16 value;
	unsigned __int16 padding4;
};

struct SDL_DollarGestureEvent
{
	unsigned int type;
	unsigned int timestamp;
	__int64 touchId;
	__int64 gestureId;
	unsigned int numFingers;
	float error;
	float x;
	float y;
};

struct SDL_DisplayMode
{
	unsigned int format;
	int w;
	int h;
	int refresh_rate;
	void* driverdata;
};

struct SDL_ControllerDeviceEvent
{
	unsigned int type;
	unsigned int timestamp;
	int which;
};

struct SDL_ControllerButtonEvent
{
	unsigned int type;
	unsigned int timestamp;
	int which;
	unsigned __int8 button;
	unsigned __int8 state;
	unsigned __int8 padding1;
	unsigned __int8 padding2;
};

struct SDL_ControllerAxisEvent
{
	unsigned int type;
	unsigned int timestamp;
	int which;
	unsigned __int8 axis;
	unsigned __int8 padding1;
	unsigned __int8 padding2;
	unsigned __int8 padding3;
	__int16 value;
	unsigned __int16 padding4;
};

struct SDL_CommonEvent
{
	unsigned int type;
	unsigned int timestamp;
};

struct SDL_BlitInfo
{
	unsigned __int8* src;
	int src_w;
	int src_h;
	int src_pitch;
	int src_skip;
	unsigned __int8* dst;
	int dst_w;
	int dst_h;
	int dst_pitch;
	int dst_skip;
	SDL_PixelFormat* src_fmt;
	SDL_PixelFormat* dst_fmt;
	unsigned __int8* table;
	int flags;
	unsigned int colorkey;
	unsigned __int8 r;
	unsigned __int8 g;
	unsigned __int8 b;
	unsigned __int8 a;
};

struct SDL_BlitMap
{
	SDL_Surface* dst;
	int identity;
	int (__fastcall *blit)(SDL_Surface*, SDL_Rect*, SDL_Surface*, SDL_Rect*);
	void* data;
	SDL_BlitInfo info;
	unsigned int dst_palette_version;
	unsigned int src_palette_version;
};

struct SDL_AudioDeviceEvent
{
	unsigned int type;
	unsigned int timestamp;
	unsigned int which;
	unsigned __int8 iscapture;
	unsigned __int8 padding1;
	unsigned __int8 padding2;
	unsigned __int8 padding3;
};

struct ResFixedHeader_st
{
	unsigned int nFileType;
	unsigned int nFileVersion;
	unsigned int nNumber;
	unsigned int nSize;
	unsigned int nTableOffset;
};

struct MOSAICQUAD
{
	int textureIndex;
	int x;
	int y;
	int w;
	int h;
	int sx;
	int sy;
};

struct MOSAICHEADERV2
{
	unsigned int nFileType;
	unsigned int nFileVersion;
	unsigned int nWidth;
	unsigned int nHeight;
	unsigned int nQuads;
	unsigned int nOffsetToQuads;
};

struct LeaderboardEntry_t
{
	CSteamID m_steamIDUser;
	int m_nGlobalRank;
	int m_nScore;
	int m_cDetails;
	unsigned __int64 m_hUGC;
};

struct DP_Packet
{
	unsigned int flags;
	unsigned __int8* data;
	unsigned __int64 dataLength;
	unsigned __int64 offset;
};

struct DP_Event
{
	DP_EventType type;
	IDPPeer* peer;
	unsigned __int8 channelID;
	unsigned int data;
	DP_Packet* packet;
};

struct CWorldMapHeader
{
	unsigned int m_nMapCount;
	unsigned int m_nMapOffset;
};

struct CWeaponIdentification
{
	unsigned __int16 m_itemType;
	unsigned int m_itemFlags;
	unsigned int m_itemFlagMask;
	unsigned int m_attributes;
};

struct CVidPoly
{
	CVIDPOLY_VERTEX* m_pVertices;
	int m_nVertices;
	_EdgeDescription* m_pET;
	_EdgeDescription* m_pAET;
	void (__fastcall *m_pDrawHLineFunction)(CVidPoly*, void*, int, int, unsigned int, const CRect*, const CPoint*);
};

struct CVariableHash
{
	CVariable* m_hashEntries;
	int m_nTableEntries;
};

struct CVVCHash
{
	CVVCHashEntry* m_hashEntries;
	int m_nTableEntries;
};

struct CVRamPool
{
	int nVTiles;
	st_tiledef* pTileDef;
};

template<class BASE_CLASS, class T>
struct CTypedPtrList : CObject
{
	struct CNode
	{
		CTypedPtrList::CNode* pNext;
		CTypedPtrList::CNode* pPrev;
		T data;
	};

	CTypedPtrList::CNode* m_pNodeHead;
	CTypedPtrList::CNode* m_pNodeTail;
	int m_nCount;
	CTypedPtrList::CNode* m_pNodeFree;
	CPlex* m_pBlocks;
	int m_nBlockSize;

	void RemoveHead()
	{
		((CObList*)this)->RemoveHead();
	}

	void Destruct()
	{
		((CObList*)this)->Destruct();
	}
};

template<class BASE_CLASS, class T>
struct CTypedPtrArray : CObject
{
	T* m_pData;
	int m_nSize;
	int m_nMaxSize;
	int m_nGrowBy;
};

struct CTlkFileOverride
{
	int bLoaded;
	int m_UserAddedCount;
};

struct CTimerWorld
{
	unsigned int m_gameTime;
	unsigned __int8 m_active;
	unsigned __int8 m_nLastPercentage;
};

struct CSpellLevelDecrementing
{
	int m_bImmune;
	int m_nLevels;
};

struct CScriptCache
{
	CAIScript** m_scriptMap;
	int m_nTableEntries;
};

struct CSchoolAndSecondaryDecrementing
{
	unsigned int m_nType;
	int m_nLevels;
};

struct CResTile
{
	CResTileSet* tis;
	int tileIndex;
	CResPVR* pvr;
};

struct CResInfTile : CResTile
{
	int nVRamTile;
	TILE_CODE renderCode;
	CResTile* pDualTileRes;
	VRAM_FLAGS flags;
};

struct CPtrList : CObject
{
	struct CNode
	{
		CPtrList::CNode* pNext;
		CPtrList::CNode* pPrev;
		void* data;
	};

	CPtrList::CNode* m_pNodeHead;
	CPtrList::CNode* m_pNodeTail;
	int m_nCount;
	CPtrList::CNode* m_pNodeFree;
	CPlex* m_pBlocks;
	int m_nBlockSize;

	virtual void CObject_Destructor()
	{
	}
};

struct CMessageHandler
{
	CTypedPtrList<CPtrList,CMessage*> m_messageList;
	unsigned __int8 m_bLastArbitrationLockStatus;
};

struct CAIResponse
{
	__int16 m_weight;
	__int16 m_responseNum;
	__int16 m_responseSetNum;
	__int16 m_scriptNum;
	CTypedPtrList<CPtrList,CAIAction*> m_actionList;
};

struct CAICondition
{
	CTypedPtrList<CPtrList,CAITrigger*> m_triggerList;
};

struct CApplyEffectList : CTypedPtrList<CPtrList,CGameEffect*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CBounceList : CTypedPtrList<CPtrList,CBounceEntry*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CColorEffects : CTypedPtrList<CPtrList,CColorEffect*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CColorRanges : CTypedPtrList<CPtrList,CColorRange*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CContingencyList : CTypedPtrList<CPtrList,CContingency*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CCriticalEntryList : CTypedPtrList<CPtrList,CCriticalEntry*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CGameEffectUsabilityList : CTypedPtrList<CPtrList,CGameEffectUsability*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CImmunitiesAIType : CTypedPtrList<CPtrList,CAIObjectType*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CImmunitiesEffect : CTypedPtrList<CPtrList,CGameEffect*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CImmunitiesItemEquipList : CTypedPtrList<CPtrList,CImmunitiesItemEquip*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CImmunitiesItemTypeEquipList : CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CImmunitiesProjectile : CTypedPtrList<CPtrList,long*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CImmunitiesSchoolAndSecondary : CTypedPtrList<CPtrList,long*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CImmunitiesSchoolAndSecondaryDecrementing : CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CImmunitiesSpellList : CTypedPtrList<CPtrList,CImmunitySpell*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CImmunitiesWeapon : CTypedPtrList<CPtrList,CWeaponIdentification*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CMoveList : CTypedPtrList<CPtrList,CMoveListEntry*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CPersistantEffectList : CTypedPtrList<CPtrList,CPersistantEffect*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CSpawnFile : CTypedPtrList<CPtrList,void*>
{
	CSpawnList* mpExitList;
	CSpawnList* mpEnterList;
	int m_bInSpawn;

	virtual void CObject_Destructor()
	{
	}
};

struct CSequenceSoundList : CTypedPtrList<CPtrList,CSequenceSound*>
{
	__POSITION* m_currentSound;
	int m_soundPlaying;
	int m_channel;

	virtual void CObject_Destructor()
	{
	}
};

struct CSelectiveWeaponTypeList : CTypedPtrList<CPtrList,CSelectiveWeaponType*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CSelectiveBonusList : CTypedPtrList<CPtrList,CSelectiveBonus*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CPtrArray : CObject
{
	void** m_pData;
	int m_nSize;
	int m_nMaxSize;
	int m_nGrowBy;

	virtual void CObject_Destructor()
	{
	}
};

struct CGameAbilityList : CTypedPtrArray<CPtrArray,CAbilityData*>
{
	virtual void CObject_Destructor()
	{
	}
};

struct CSpawnPointArray : CTypedPtrArray<CPtrArray,CSpawnPoint*>
{
	int mDefaultFacing;

	virtual void CObject_Destructor()
	{
	}
};

struct CPersistantEffectListRegenerated : CTypedPtrList<CPtrList,CPersistantEffect*>
{
	unsigned int m_nCounter;

	virtual void CObject_Destructor()
	{
	}
};

struct CPersistantEffect
{
	int m_done;
	int m_deleted;
	__int16 m_numDamage;
	__int16 m_persistantType;
	int m_sourceID;
	__int16 m_period;
	__int16 m_periodCounter;
	int m_counter;

	virtual void CPersistantEffect_Destructor()
	{
	}

	virtual void AIUpdate(CGameSprite* _0, int _1)
	{
	}

	virtual CPersistantEffect* Copy()
	{
		return *(CPersistantEffect**)nullptr;
	}
};

struct CPathSearch
{
	int PATH_SMOOTH;
	CPathNode** m_pListGrid;
	CPathNode** m_pOpenList;
	__int16 m_openListLevel;
	__int16 m_nOpenList;
	int* m_pathBegin;
	__int16 m_nPathNodes;
	__int16 m_pathCurrent;
};

struct CPathNode
{
	CPathNode* m_pathNodePrev;
	int m_gridPosition;
	int m_costStart;
	int m_costTotal;
	unsigned __int8 m_fIsOpen;
};

struct CPARTICLE_POINT
{
	int x;
	int y;
	int z;
};

struct CParticle
{
	__int16 m_nTimeStamp;
	__int16 m_nTailLength;
	__int16 m_nRenderTime;
	unsigned int m_rgbColor;
	unsigned __int16 m_wType;
	int m_nLifeSpan;
	unsigned __int8 m_bTag;
	CPARTICLE_POINT m_pos;
	CPARTICLE_POINT m_vel;
	int m_nGravity;
};

struct CSnowFlake : CParticle
{
	unsigned __int8 m_nDriftWidth;
	unsigned __int8 m_nDriftCounter;
	unsigned __int16 m_nMeltTime;
	int m_nLastDriftVelocity;
};

struct CRainDrop : CParticle
{
};

typedef CObject* (*type_CObList_RemoveHead)(CObList* pThis);
extern type_CObList_RemoveHead p_CObList_RemoveHead;

typedef void (*type_CObList_Destruct)(CObList* pThis);
extern type_CObList_Destruct p_CObList_Destruct;

struct CObList : CObject
{
	struct CNode
	{
		CObList::CNode* pNext;
		CObList::CNode* pPrev;
		CObject* data;
	};

	CObList::CNode* m_pNodeHead;
	CObList::CNode* m_pNodeTail;
	int m_nCount;
	CObList::CNode* m_pNodeFree;
	CPlex* m_pBlocks;
	int m_nBlockSize;

	CObject* RemoveHead()
	{
		return p_CObList_RemoveHead(this);
	}

	void Destruct()
	{
		p_CObList_Destruct(this);
	}

	virtual void CObject_Destructor()
	{
	}
};

struct CObArray : CObject
{
	CObject** m_pData;
	int m_nSize;
	int m_nMaxSize;
	int m_nGrowBy;

	virtual void CObject_Destructor()
	{
	}
};

struct CMusicPosition
{
	int m_nSong;
	int m_nSection;
	int m_nPosition;
};

struct CMessage
{
	int m_targetId;
	int m_sourceId;

	virtual void CMessage_Destructor()
	{
	}

	virtual __int16 GetCommType()
	{
		return *(__int16*)nullptr;
	}

	virtual unsigned __int8 GetMsgType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 GetMsgSubType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void MarshalMessage(unsigned __int8** _0, unsigned int* _1)
	{
	}

	virtual int UnmarshalMessage(unsigned __int8* _0, unsigned int _1)
	{
		return *(int*)nullptr;
	}

	virtual void Run()
	{
	}
};

struct CMachineState
{
	unsigned int m_inputState;
};

template<class TYPE, class ARG_TYPE>
struct CList : CObject
{
	struct CNode
	{
		CList::CNode* pNext;
		CList::CNode* pPrev;
		TYPE data;
	};

	CList::CNode* m_pNodeHead;
	CList::CNode* m_pNodeTail;
	int m_nCount;
	CList::CNode* m_pNodeFree;
	CPlex* m_pBlocks;
	int m_nBlockSize;
};

struct CKeyInfo
{
	unsigned int m_repeatCount;
	int m_keyCode;
	unsigned __int8 m_repeatDelay;
	unsigned __int8 m_repeatRate;
};

struct CImportGame
{
	unsigned __int8 m_bDrizztDead;
	CGameFile* m_pGame;
	unsigned __int8 m_nVersion;
	CTypedPtrArray<CPtrArray,CSavedGamePartyCreature*> m_aPartyCreatures;
	CTypedPtrArray<CPtrArray,CSavedGamePartyCreature*> m_aNonPartyCreatures;
	CTypedPtrArray<CPtrArray,unsigned char*> m_aCreatureData;
	CTypedPtrArray<CPtrArray,unsigned char*> m_aNPCData;
	int m_nGlobalVariables;
	unsigned __int8* m_pGlobalVariables;
	unsigned int m_nPartyGold;
	unsigned int m_nReputation;
};

struct CImmunitiesItemTypeEquip
{
	unsigned int m_type;
	unsigned int m_error;
	CGameEffect* m_pEffect;
};

struct CGameTimer
{
	int m_time;
	unsigned __int8 m_id;
};

struct CGameRemoteObjectListEntry
{
	int remotePlayerID;
	int remoteObjectID;
	int localObjectID;
	CGameRemoteObjectListEntry* pNext;
};

struct CGameRemoteObjectDeletion
{
	int deletedPlayerID;
	int deletedObjectID;
	CGameRemoteObjectDeletion* pNext;
};

struct CGameRemoteObjectControlChange
{
	int oldPlayerID;
	int oldObjectID;
	int newPlayerID;
	int newObjectID;
	CGameRemoteObjectControlChange* pNext;
	unsigned __int8 localControl;
};

struct CGameOptions
{
	unsigned int m_gore;
	unsigned int m_goreOption;
	unsigned int m_scrollSpeed;
	unsigned int m_displayVerbalText;
	unsigned int m_guiFeedBackLevel;
	unsigned int m_locatorFeedBackLevel;
	unsigned int m_soundMusicVolume;
	unsigned int m_soundFXVolume;
	unsigned int m_soundDialogVolume;
	unsigned int m_nVolumeAmbients;
	unsigned int m_soundMovieVolume;
	unsigned int m_soundFootStepsOn;
	unsigned int m_soundVoicesNo;
	unsigned int m_graphicsBrightness;
	unsigned int m_graphicsFontZoom;
	float m_spriteBlurAmount;
	unsigned int m_graphicsTranslucentShadows;
	unsigned int m_graphicsForceMirroringOff;
	unsigned int m_graphicsTranslucentEffects;
	unsigned int m_toolTips;
	unsigned int m_nBoredTime;
	unsigned int m_nCommandSoundsFrequency;
	unsigned int m_nSelectionSoundsFrequency;
	unsigned int m_bAlwaysDither;
	unsigned int m_nKeyBoardScrollAmount;
	unsigned int m_nEffectTextLevel;
	unsigned int m_nTutorialState;
	unsigned int m_nAttackSounds;
	unsigned int m_nAutoPauseState;
	unsigned int m_bAutoPauseCenter;
	int m_nDifficultyMultiplier;
	int m_nMPDifficultyMultiplier;
	int m_bNoExtraDamage;
	int m_bAutoUseMagicAmmo;
	int m_bNoExtraXP;
	unsigned int m_bInfravision;
	unsigned int m_bStupidQuickItemStuff;
	int m_bWeatherEnabled;
	int m_bCheatsEnabled;
	int m_bEnvironmentalAudio;
	int m_bRestHealParty;
	int m_bTerrainHugging;
	int m_bHPOverHead;
	int m_bDebugMode;
	int m_bUIEditMode;
	int m_bCloudSavesEnabled;
	int m_bNeverShowNuisanceSOD;
	int m_nActiveCampaign;
	int m_bDeveloperMode;
	int m_bForceDialogPause;
	int m_bUse3dAnimations;
	int m_bCriticalHitScreenShake;
	int m_bHotkeysOnToolTips;
	int m_bVeryLowPerformance;
	int m_bDisplayExtraCombatInfo;
	unsigned __int16 m_nAreaEffectsDensity;
	int m_bDuplicateFloatingText;
	unsigned __int8 m_nTilesPrecachePercent;
	int m_bColorCircles;
	int m_bClassicCircles;
	int m_nCombatUI;
	int m_bOverConfirmEverything;
	int m_bShowLearnableSpells;
	int m_bShowTriggersOnTab;
	int m_bShowBlackSpace;
	int m_bUseNearestNeighbourScaling;
	int m_showAOE;
	int m_bEquipmentComparison;
	int m_bDisableCastingGlows;
	int m_bLowMemSounds1;
	int m_bLowMemSounds2;
	int m_bDisableVEFVidCells;
	int m_bDisableDisplayText;
	int m_bMidLevelBrighten;
	int m_bHighLevelBrighten;
	unsigned __int16 m_nAreaEffectsRefreshProb;
	int m_bEnhancedPathSearch;
	int m_bPausingMap;
	int m_bExtraFeedback;
	int m_bFilterGames;
	int m_bAllLearnSpellInfo;
	int m_bDisableStaticsDuringCombat;
	int m_bDisableFootstepsDuringCombat;
	int m_bDisablePlacedSoundsDuringCombat;
	int m_nSuperDesperateSpeedAttempt;
	int m_bAutomatedSpeedAdjusting;
	int m_bAutomatedGraphicsTranslucentShadows;
	int m_bAutomatedVeryLowPerformance;
	int m_bAutomatedLowPerformance;
	int m_bAutomatedDisableBrightest;
	int m_bAutomatedLimitTransparency;
	int m_bAutomatedDisableCastingGlows;
	int m_bAutomatedDisableVEFVidCells;
	int m_bAutomatedMidLevelBrighten;
	int m_bAutomatedHighLevelBrighten;
	int m_bAutomatedSoundFootStepsOn;
	int m_bAutomatedAttackSounds;
	int m_bAutomatedUse3dAnimations;
	int m_bAutomatedDisableVVCSounds;
	int m_bAutomatedFasterBlur;
	int m_nCutAutomatedGraphicsTranslucentShadows;
	int m_nCutAutomatedVeryLowPerformance;
	int m_nCutAutomatedLowPerformance;
	int m_nCutAutomatedDisableBrightest;
	int m_nCutAutomatedLimitTransparency;
	int m_nCutAutomatedDisableCastingGlows;
	int m_nCutAutomatedDisableVEFVidCells;
	int m_nCutAutomatedMidLevelBrighten;
	int m_nCutAutomatedHighLevelBrighten;
	int m_nCutAutomatedSoundFootStepsOn;
	int m_nCutAutomatedAttackSounds;
	int m_nCutAutomatedUse3dAnimations;
	int m_nCutAutomatedDisableVVCSounds;
	int m_nCutAutomatedFasterBlur;
	int m_bPCOnlyCombatMode;
	int m_bFullyDisableNonVisibleDuringCombat;
	int m_bDisableVVCSounds;
	int m_bFasterBlur;
	int m_nFatFingerRadius;
	int m_bScaleUI;
	int m_nRenderActionQueue;
	int m_bConfirmDialog;
	int m_bHardwareMouseCursor;
	int m_bShowHealth;
	int m_bMaxHP;
	int m_bStoryMode;
	int m_bNightmareMode;
	int m_bNightmareBonusGold;
	int m_bNightmareBonusXP;
	int m_b3ESneakAttack;
	int m_bClericRangerFix;
	int m_bShowPauseDate;
	int m_bDisableCosmeticAttacks;
	int m_bJournalPopups;
	int m_bRenderTravelRegions;
	int m_bRenderSearchMap;
	int m_bRenderDynamicSearchMap;
	int m_bRenderFrameTimes;
	int m_bZoomLock;
	int m_bDisableMultiplayerBanters;
	int m_bRenderPath;
	int m_bFogEnabled;
	int m_bUseSpriteShader;
	int m_bCharacterHighlightsEnabled;
	int m_bGreyscaleOnPauseEnabled;
	int m_bShortDescription;
	int m_nMaxStringEntries;
	int m_bRenderExploredMap;
	int m_bEnableDirectX;
	int m_bEnableMPChatMenu;
	int m_bExpireTraps;
	int m_bAreaMapZoom;
	int m_nDifficultyLevel;
};

typedef __int8 (__cdecl *type_CGameObjectArray_GetShare)(int index, CGameObject** ptr);
extern type_CGameObjectArray_GetShare p_CGameObjectArray_GetShare;

struct CGameObjectArray
{
	static __int8 GetShare(int index, CGameObject** ptr)
	{
		return p_CGameObjectArray_GetShare(index, ptr);
	}
};

struct CGameJournalEntry
{
	unsigned int m_strText;
	int m_nTime;
	CGameJournalEntryFlag m_Flag;
	unsigned __int16 m_wType;
	unsigned __int8 m_bCharacter;
	unsigned __int8 m_nCharacterHasNotRead;
};

struct CGameJournal
{
	int IWD_TimeCheat;
	CTypedPtrArray<CPtrArray,CTypedPtrList<CPtrList,CGameJournalEntry*>*> m_aChapters;
};

struct CGameEffectList : CTypedPtrList<CPtrList,CGameEffect*>
{
	__POSITION* m_posNext;
	__POSITION* m_posCurrent;
	int m_newEffect;
	int m_retry;

	virtual void CObject_Destructor()
	{
	}
};

struct CGameDialogEntry : CTypedPtrArray<CPtrArray,CGameDialogReply*>
{
	unsigned int m_dialogText;
	CAICondition m_startCondition;
	int m_picked;
	unsigned int m_conditionPriority;
	unsigned int m_dialogIndex;
	unsigned __int8 m_bDisplayButton;

	virtual void CObject_Destructor()
	{
	}
};

struct CGameButtonList : CTypedPtrList<CPtrList,CButtonData*>
{
	int m_nFirstMageSpellIndex;

	virtual void CObject_Destructor()
	{
	}
};

struct CGameAnimation
{
	CGameAnimationType* m_animation;
	unsigned int m_overrides;
	__int16 m_sequenceHighLevel;
	unsigned __int8 m_detectedByInfravision;
	unsigned __int8 m_bloodColor;
	unsigned __int8 m_personalSpace;
};

struct CDeathSound
{
	int m_soundLength;
	int m_characterId;
	__int16 m_soundNum;
	int m_started;
	CAITrigger* m_pTrigger;
};

struct CDWordArray : CObject
{
	unsigned int* m_pData;
	int m_nSize;
	int m_nMaxSize;
	int m_nGrowBy;

	virtual void CObject_Destructor()
	{
	}
};

struct CCreatureFileMemorizedSpellLevel
{
	unsigned __int16 m_spellLevel;
	unsigned __int16 m_baseCount;
	unsigned __int16 m_count;
	unsigned __int16 m_magicType;
	unsigned int m_memorizedStartingSpell;
	unsigned int m_memorizedCount;
};

struct CColorEffect
{
	unsigned __int8 m_effectType;
	unsigned __int8 m_range;
	unsigned int m_tintColor;
	unsigned __int8 m_periodLength;
};

struct CChatBuffer
{
	CTypedPtrList<CPtrList,CString*> m_lLabels;
	CTypedPtrList<CPtrList,CString*> m_lMessages;
	int m_nMessageCount;
	int m_nDisplayCount;
};

struct CCallbackBase
{
	unsigned __int8 m_nCallbackFlags;
	int m_iCallback;

	virtual void Run(void* _0, bool _1, unsigned __int64 _2)
	{
	}

	virtual void Run(void* _0)
	{
	}

	virtual int GetCallbackSizeBytes()
	{
		return *(int*)nullptr;
	}
};

template<class BASE_CLASS, class RESULT_CLASS>
struct CCallResult : CCallbackBase
{
	unsigned __int64 m_hAPICall;
	BASE_CLASS* m_pObj;
	void (__thiscall *m_Func)(BASE_CLASS*, RESULT_CLASS*, bool);
};

struct CBounceEntry
{
	int m_levelDecrement;
	unsigned int m_effectId;
	CProjectile* m_pProjectile;
	int m_decrementOnly;
	unsigned int m_string;
	int m_stringOnly;
	int m_recoverSpellLevels;
};

struct CAIResponseSet
{
	CTypedPtrList<CPtrList,CAIResponse*> m_responseList;
	int m_weightTotal;
};

struct CAIConditionResponse
{
	CAICondition m_condition;
	CAIResponseSet m_responseSet;
};

struct BAMHEADERV2
{
	unsigned int nFileType;
	unsigned int nFileVersion;
	unsigned int nFrames;
	unsigned int nSequences;
	unsigned int nQuads;
	unsigned int nFramesOffset;
	unsigned int nSequencesOffset;
	unsigned int nQuadsOffset;
};

template<class T, int size>
struct Array
{
	struct scoped_ptr
	{
	};

	struct ScopeRecord_t
	{
	};

	T data[size];

	T get(int index)
	{
		if (index < 0 || index >= size)
		{
			return NULL;
		}
		return data[index];
	}

	T* getReference(int index)
	{
		if (index < 0 || index >= size)
		{
			return NULL;
		}
		return &data[index];
	}

	void set(int index, T value)
	{
		if (index < 0 || index >= size)
		{
			return;
		}
		data[index] = value;
	}

	T operator[](int index)
	{
		return data[index];
	}
};

struct WED_LayerHeader_st
{
	unsigned __int16 nTilesAcross;
	unsigned __int16 nTilesDown;
	Array<unsigned __int8,8> rrTileSet;
	unsigned __int16 nNumUniqueTiles;
	unsigned __int16 nLayerFlags;
	unsigned int nOffsetToTileData;
	unsigned int nOffsetToTileList;
};

struct SteamUGCQueryCompleted_t
{
	unsigned __int64 m_handle;
	EResult m_eResult;
	unsigned int m_unNumResultsReturned;
	unsigned int m_unTotalMatchingResults;
	bool m_bCachedData;
	Array<char,256> m_rgchNextCursor;
};

struct SteamUGCDetails_t
{
	unsigned __int64 m_nPublishedFileId;
	EResult m_eResult;
	EWorkshopFileType m_eFileType;
	unsigned int m_nCreatorAppID;
	unsigned int m_nConsumerAppID;
	Array<char,129> m_rgchTitle;
	Array<char,8000> m_rgchDescription;
	unsigned __int64 m_ulSteamIDOwner;
	unsigned int m_rtimeCreated;
	unsigned int m_rtimeUpdated;
	unsigned int m_rtimeAddedToUserList;
	ERemoteStoragePublishedFileVisibility m_eVisibility;
	bool m_bBanned;
	bool m_bAcceptedForUse;
	bool m_bTagsTruncated;
	Array<char,1025> m_rgchTags;
	unsigned __int64 m_hFile;
	unsigned __int64 m_hPreviewFile;
	Array<char,260> m_pchFileName;
	int m_nFileSize;
	int m_nPreviewFileSize;
	Array<char,256> m_rgchURL;
	unsigned int m_unVotesUp;
	unsigned int m_unVotesDown;
	float m_flScore;
	unsigned int m_unNumChildren;
};

struct SteamUGCRequestUGCDetailsResult_t
{
	SteamUGCDetails_t m_details;
	bool m_bCachedData;
};

#pragma pack(push, 1)
struct Spell_Header_st
{
	unsigned int nFileType;
	unsigned int nFileVersion;
	unsigned int genericName;
	unsigned int identifiedName;
	Array<unsigned __int8,8> usedUpItemID;
	unsigned int itemFlags;
	unsigned __int16 itemType;
	unsigned int notUsableBy;
	unsigned __int16 castingAnimationType;
	unsigned __int8 minLevelRequired;
	unsigned __int8 school;
	unsigned __int8 minSTRRequired;
	unsigned __int8 secondaryType;
	unsigned __int8 minSTRBonusRequired;
	unsigned __int8 notUsableBy2a;
	unsigned __int8 minINTRequired;
	unsigned __int8 notUsableBy2b;
	unsigned __int8 minDEXRequired;
	unsigned __int8 notUsableBy2c;
	unsigned __int8 minWISRequired;
	unsigned __int8 notUsableBy2d;
	unsigned __int16 minCONRequired;
	unsigned __int16 minCHRRequired;
	unsigned int spellLevel;
	unsigned __int16 maxStackable;
	Array<unsigned __int8,8> itemIcon;
	unsigned __int16 loreValue;
	Array<unsigned __int8,8> groundIcon;
	unsigned int baseWeight;
	unsigned int genericDescription;
	unsigned int identifiedDescription;
	Array<unsigned __int8,8> descriptionPicture;
	unsigned int attributes;
	unsigned int abilityOffset;
	unsigned __int16 abilityCount;
	unsigned int effectsOffset;
	unsigned __int16 castingStartingEffect;
	unsigned __int16 castingEffectCount;
};
#pragma pack(pop)

struct SDL_TextInputEvent
{
	unsigned int type;
	unsigned int timestamp;
	unsigned int windowID;
	Array<char,32> text;
};

struct SDL_TextEditingEvent
{
	unsigned int type;
	unsigned int timestamp;
	unsigned int windowID;
	Array<char,32> text;
	int start;
	int length;
};

struct SDL_PixelFormat
{
	unsigned int format;
	SDL_Palette* palette;
	unsigned __int8 BitsPerPixel;
	unsigned __int8 BytesPerPixel;
	Array<unsigned __int8,2> padding;
	unsigned int Rmask;
	unsigned int Gmask;
	unsigned int Bmask;
	unsigned int Amask;
	unsigned __int8 Rloss;
	unsigned __int8 Gloss;
	unsigned __int8 Bloss;
	unsigned __int8 Aloss;
	unsigned __int8 Rshift;
	unsigned __int8 Gshift;
	unsigned __int8 Bshift;
	unsigned __int8 Ashift;
	int refcount;
	SDL_PixelFormat* next;
};

struct Item_effect_st
{
	unsigned __int16 effectID;
	unsigned __int8 targetType;
	unsigned __int8 spellLevel;
	int effectAmount;
	unsigned int dwFlags;
	unsigned __int16 durationType;
	unsigned int duration;
	unsigned __int8 probabilityUpper;
	unsigned __int8 probabilityLower;
	Array<unsigned __int8,8> res;
	unsigned int numDice;
	unsigned int diceSize;
	unsigned int savingThrow;
	int saveMod;
	unsigned int special;
};

struct Item_ability_st
{
	unsigned __int16 type;
	unsigned __int8 quickSlotType;
	unsigned __int8 largeDamageDice;
	Array<unsigned __int8,8> quickSlotIcon;
	unsigned __int8 actionType;
	unsigned __int8 actionCount;
	unsigned __int16 range;
	unsigned __int8 launcherType;
	unsigned __int8 largeDamageDiceCount;
	unsigned __int8 speedFactor;
	unsigned __int8 largeDamageDiceBonus;
	__int16 thac0Bonus;
	unsigned __int8 damageDice;
	unsigned __int8 school;
	unsigned __int8 damageDiceCount;
	unsigned __int8 secondaryType;
	__int16 damageDiceBonus;
	unsigned __int16 damageType;
	unsigned __int16 effectCount;
	unsigned __int16 startingEffect;
	unsigned __int16 maxUsageCount;
	unsigned __int16 usageFlags;
	unsigned int abilityFlags;
	unsigned __int16 missileType;
	Array<unsigned __int16,6> attackProbability;
};

struct Item_Header_st
{
	unsigned int nFileType;
	unsigned int nFileVersion;
	unsigned int genericName;
	unsigned int identifiedName;
	Array<unsigned __int8,8> usedUpItemID;
	unsigned int itemFlags;
	unsigned __int16 itemType;
	unsigned int notUsableBy;
	Array<unsigned __int8,2> animationType;
	unsigned __int16 minLevelRequired;
	unsigned __int16 minSTRRequired;
	unsigned __int8 minSTRBonusRequired;
	unsigned __int8 notUsableBy2a;
	unsigned __int8 minINTRequired;
	unsigned __int8 notUsableBy2b;
	unsigned __int8 minDEXRequired;
	unsigned __int8 notUsableBy2c;
	unsigned __int8 minWISRequired;
	unsigned __int8 notUsableBy2d;
	unsigned __int8 minCONRequired;
	unsigned __int8 proficiencyType;
	unsigned __int16 minCHRRequired;
	unsigned int baseValue;
	unsigned __int16 maxStackable;
	Array<unsigned __int8,8> itemIcon;
	unsigned __int16 loreValue;
	Array<unsigned __int8,8> groundIcon;
	unsigned int baseWeight;
	unsigned int genericDescription;
	unsigned int identifiedDescription;
	Array<unsigned __int8,8> descriptionPicture;
	unsigned int attributes;
	unsigned int abilityOffset;
	unsigned __int16 abilityCount;
	unsigned int effectsOffset;
	unsigned __int16 equipedStartingEffect;
	unsigned __int16 equipedEffectCount;
};

struct DP_Player
{
	unsigned int id;
	Array<char,32> name;
	Array<char,32> remoteAddr;
	int sessionId;
	unsigned int flags;
	void* batton;
	IDPPeer* peer;
	bool in_game;
};

struct CWorldMapLinks
{
	unsigned int m_nArea;
	Array<char,32> m_entryPoint;
	unsigned int m_nDistanceScale;
	unsigned int m_dwLinkFlags;
	Array<unsigned __int8,8> m_resRandomEncounterArea0;
	Array<unsigned __int8,8> m_resRandomEncounterArea1;
	Array<unsigned __int8,8> m_resRandomEncounterArea2;
	Array<unsigned __int8,8> m_resRandomEncounterArea3;
	Array<unsigned __int8,8> m_resRandomEncounterArea4;
	unsigned int m_nEncounterProbability;
	Array<unsigned int,32> nUnused;
};

struct CWorldMapData
{
	Array<unsigned __int8,8> m_resMosaic;
	unsigned int m_nWidth;
	unsigned int m_nHeight;
	unsigned int m_nMapID;
	unsigned int m_strTitle;
	unsigned int m_nStartCenteredOnX;
	unsigned int m_nStartCenteredOnY;
	unsigned int m_nAreas;
	unsigned int m_nAreasOffset;
	unsigned int m_nOffsetToLinks;
	unsigned int m_nLinks;
	Array<unsigned __int8,8> m_resAreaIcons;
	unsigned int m_dwFlags;
	Array<unsigned int,31> nUnused;
};

struct CWorldMapArea
{
	Array<unsigned __int8,8> m_resCurrentArea;
	Array<unsigned __int8,8> m_resOriginalArea;
	Array<char,32> m_strName;
	unsigned int m_dwFlags;
	unsigned int m_sequence;
	unsigned int m_mapLocationX;
	unsigned int m_mapLocationY;
	unsigned int m_strLabel;
	unsigned int m_strAreaName;
	Array<unsigned __int8,8> m_resAreaLoadMosaic;
	unsigned int m_nNorthEdgeStartingLink;
	unsigned int m_nNorthEdgeCount;
	unsigned int m_nWestEdgeStartingLink;
	unsigned int m_nWestEdgeCount;
	unsigned int m_nSouthEdgeStartingLink;
	unsigned int m_nSouthEdgeCount;
	unsigned int m_nEastEdgeStartingLink;
	unsigned int m_nEastEdgeCount;
	Array<unsigned int,32> nUnused;
};

struct CVisibilityMap
{
	unsigned __int16* m_pMap;
	int m_nMapSize;
	__int16 m_nWidth;
	__int16 m_nHeight;
	unsigned __int8 m_bOutDoor;
	CSearchBitmap* m_pSearchMap;
	Array<int,15> m_aCharacterIds;
	CVisibilityMapTreeNode** m_pVisMapTrees;
	CVisibilityMapEllipse* m_pVisMapEllipses;
};

struct CVidPalette
{
	unsigned __int64 m_nAUCounter;
	unsigned __int64 m_nAUCounterBase;
	tagRGBQUAD* m_pPalette;
	int m_nEntries;
	unsigned int rgbGlobalTint;
	unsigned __int16 m_nType;
	unsigned __int8 m_bPaletteOwner;
	int m_bSubRangesCalculated;
	Array<unsigned __int8,7> m_rangeColors;
};

struct CVIDIMG_PALETTEAFFECT
{
	unsigned int rgbTintColor;
	unsigned int rgbAddColor;
	unsigned int rgbLightColor;
	Array<unsigned int*,7> pRangeTints;
	Array<unsigned __int8,8> aRangeTintPeriods;
	Array<unsigned int*,7> pRangeAdds;
	Array<unsigned __int8,8> aRangeAddPeriods;
	Array<unsigned int*,7> pRangeLights;
	Array<unsigned __int8,7> aRangeLightPeriods;
	unsigned __int8 suppressTints;
};

struct CVidImage
{
	CVidPalette m_cPalette;
	CVIDIMG_PALETTEAFFECT mPaletteAffects;
};

struct CVidTile : CVidImage
{
	CResTile* pRes;
	unsigned int m_dwFlags;
};

struct CStoreFileSpell
{
	Array<unsigned __int8,8> m_spell;
	unsigned int m_cost;
};

struct CStoreFileItem
{
	Array<unsigned __int8,8> m_itemId;
	unsigned __int16 m_wear;
	Array<unsigned __int16,3> m_usageCount;
	unsigned int m_dynamicFlags;
	unsigned int m_nInStock;
	unsigned int m_nStoreFlags;
};

struct CStoreFileHeader
{
	unsigned int m_nStoreType;
	unsigned int m_strName;
	unsigned int m_nStoreFlags;
	unsigned int m_nBuyMarkUp;
	unsigned int m_nSellMarkDown;
	unsigned int m_nAdditionalMarkDown;
	unsigned __int16 m_nStealDifficulty;
	unsigned __int16 m_nMaxItems;
	Array<unsigned __int8,8> m_script;
	unsigned int m_nbuyTypesOffset;
	unsigned int m_nbuyTypesCount;
	unsigned int m_nInventoryOffset;
	unsigned int m_nInventoryCount;
	unsigned int m_nLore;
	unsigned int m_nIdentifyCost;
	Array<unsigned __int8,8> m_resRumor;
	unsigned int m_drinkOffset;
	unsigned int m_drinkCount;
	Array<unsigned __int8,8> m_resDonation;
	unsigned int m_nInnFlags;
	unsigned int m_nRoomCostPeasant;
	unsigned int m_nRoomCostMerchant;
	unsigned int m_nRoomCostNoble;
	unsigned int m_nRoomCostRoyal;
	unsigned int m_spellOffset;
	unsigned int m_spellCount;
	unsigned int m_rouletMaxBet;
	unsigned int m_crapsMaxBet;
	unsigned int m_wheelMaxBet;
	unsigned int m_rouletWinChance;
	unsigned int m_crapsWinChance;
	unsigned int m_wheelWinChance;
	unsigned int m_rouletWinAmount;
	unsigned int m_crapsWinAmount;
	unsigned int m_wheelWinAmount;
};

struct CStoreFileDrinks
{
	Array<unsigned __int8,8> m_icon;
	unsigned int m_strName;
	unsigned int m_nCost;
	unsigned int m_nRumorChance;
};

struct CSoundMixerImp
{
	ALCcontext_struct* alContext;
	ALCdevice_struct* alDevice;
	Array<float,3> pos;
	int bMixerInitialized;
	int bStreamPlaying;
	int m_bMusicInitialized;
	int bInPositionUpdate;
	int bInSoundUpdate;
	int bInQueueUpdate;
	int bInLoopingUpdate;
	unsigned int m_dwEAXProperties;
	CSoundProperties m_soundProperties;
	int m_nNumSongs;
	int m_nLastSong;
	int m_nCurrentSong;
	int m_nQuietMusicVolume;
	unsigned __int64 m_nActiveArea;
	int m_nDuckingOn;
	CDWordArray m_aMusicSlots;
	Array<unsigned __int8,10001> m_tSqrtTable;
	int nMaxVoices;
	CObList lVoices;
	CObList lWaiting;
	CObList lLooping;
	CObArray aChannels;
	int nMaxChannels;
	int nGlobalVolume;
	int nPanRange;
	int nXCoordinate;
	int nYCoordinate;
	int nZCoordinate;
	CTypedPtrList<CPtrList,CMusicPosition*> m_lMusicPositions;
};

struct CSavedGameStoredLocation
{
	Array<unsigned __int8,8> m_areaName;
	unsigned __int16 m_xPos;
	unsigned __int16 m_yPos;
};

struct CSavedGamePartyCreature
{
	unsigned __int16 m_wFlags;
	unsigned __int16 m_portraitId;
	unsigned int m_creatureOffset;
	unsigned int m_creatureSize;
	Array<unsigned __int8,8> m_creatureResRef;
	unsigned int m_creatureFacing;
	Array<unsigned __int8,8> m_areaName;
	unsigned __int16 m_posX;
	unsigned __int16 m_posY;
	unsigned __int16 m_posViewX;
	unsigned __int16 m_posViewY;
	unsigned __int16 m_nModalState;
	__int16 m_nHappiness;
	Array<int,24> m_nNumberOfTimesInteractedWith;
	Array<__int16,4> m_quickWeaponsItemNum;
	Array<__int16,4> m_quickWeaponsAbilityNum;
	Array<Array<unsigned __int8,8>,3> m_quickSpellsSpellId;
	Array<__int16,3> m_quickItemsItemNum;
	Array<__int16,3> m_quickItemsAbilityNum;
	Array<char,32> m_name;
	unsigned int m_numberTimesTalkedTo;
	unsigned int m_strStrongestKillName;
	unsigned int m_nStrongestKillXPValue;
	unsigned int m_nPreviousTimeWithParty;
	unsigned int m_nJoinPartyTime;
	unsigned __int8 m_bWithParty;
	Array<char,2> m_pad1;
	char m_cFirstResSlot;
	unsigned int m_nChapterKillsXPValue;
	unsigned int m_nChapterKillsNumber;
	unsigned int m_nGameKillsXPValue;
	unsigned int m_nGameKillsNumber;
	Array<Array<unsigned __int8,8>,4> m_lSpellStatsName;
	Array<__int16,4> m_lSpellStatsCount;
	Array<Array<unsigned __int8,8>,4> m_lWeaponStatsName;
	Array<__int16,4> m_lWeaponStatsCount;
	Array<unsigned __int8,8> m_secondarySounds;
};

struct CResRef
{
	Array<unsigned __int8,8> m_resRef;

	void get(lua_State* L)
	{
		char* localCopy = (char*)alloca(sizeof(m_resRef) + 1);
		int i = 0;
		for (; i < sizeof(m_resRef); ++i) {
			char readVal = m_resRef[i];
			if (readVal == '\0') break;
			localCopy[i] = readVal;
		}
		localCopy[i] = '\0';
		p_lua_pushstring(L, localCopy);
	}
};

struct CAbilityId
{
	__int16 m_itemType;
	__int16 m_itemNum;
	__int16 m_abilityNum;
	CResRef m_res;
	unsigned __int8 m_targetType;
	unsigned __int8 m_targetCount;
	unsigned int m_toolTip;
};

struct CButtonData
{
	CResRef m_icon;
	unsigned int m_name;
	CResRef m_launcherIcon;
	unsigned int m_launcherName;
	__int16 m_count;
	CAbilityId m_abilityId;
	unsigned __int8 m_bDisabled;
	unsigned __int8 m_bDisplayCount;
};

struct CCriticalEntry
{
	CResRef m_res;
	int m_hitOrMiss;
	int m_slot;
	int m_attackType;
	int m_itemType;
	int m_bonus;
};

struct CImmunitiesItemEquip
{
	CResRef m_res;
	unsigned int m_error;
	CGameEffect* m_pEffect;
};

struct CImmunitySpell
{
	CResRef m_res;
	unsigned int m_error;
	int m_item;
};

struct CGameStatsRes : CObject
{
	CResRef m_cResRef;
	__int16 m_nTimesUsed;

	virtual void CObject_Destructor()
	{
	}
};

struct Spell_ability_st
{
	unsigned __int16 type;
	unsigned __int16 quickSlotType;
	CResRef quickSlotIcon;
	unsigned __int8 actionType;
	unsigned __int8 actionCount;
	unsigned __int16 range;
	unsigned __int16 minCasterLevel;
	unsigned __int16 speedFactor;
	unsigned __int16 timesPerDay;
	unsigned __int16 damageDice;
	unsigned __int16 damageDiceCount;
	unsigned __int16 damageDiceBonus;
	unsigned __int16 damageType;
	unsigned __int16 effectCount;
	unsigned __int16 startingEffect;
	unsigned __int16 maxUsageCount;
	unsigned __int16 usageFlags;
	unsigned __int16 missileType;
};

struct CWorldMap
{
	CResRef m_cResRef;
	CWorldMapHeader m_cHeader;
	CWorldMapData* m_pData;
	CWorldMapArea** m_ppAreas;
	CWorldMapLinks** m_ppLinks;
};

struct CVVCHashEntry
{
	CResRef m_name;
	unsigned __int16 m_priority;
	unsigned int m_renderType;
	unsigned int m_renderMask;
};

struct CAIScript
{
	CResRef cResRef;
	CTypedPtrList<CPtrList,CAIConditionResponse*> m_caList;
};

struct CTiledObject
{
	int m_nWedIndex;
	CResWED* m_pResWed;
	unsigned __int16 m_wAIState;
	unsigned __int16 m_wRenderState;
	__POSITION* m_posAreaList;
	CResRef m_resId;
};

struct CStore
{
	CResRef m_resRef;
	CStoreFileHeader m_header;
	CTypedPtrList<CPtrList,CStoreFileItem*> m_lInventory;
	unsigned int* m_pBuyTypes;
	unsigned int m_nBuyTypes;
	CStoreFileDrinks* m_pDrinks;
	unsigned int m_nDrinks;
	CStoreFileSpell* m_pSpells;
	unsigned int m_nSpells;
	Array<unsigned __int8,8> m_pVersion;
	int m_bLocalCopy;
};

struct CSequenceSound
{
	CResRef m_sound;
	int m_offset;
};

template<class RES_CLASS, int RES_ID>
struct CResHelper
{
	RES_CLASS* pRes;
	CResRef cResRef;
};

struct CProgressBar
{
	unsigned int m_nSecondsToTimeout;
	int m_nProgressBarCaption;
	int m_nParchmentCaption;
	int m_nActionProgress;
	int m_nActionTarget;
	unsigned __int8 m_bTravelActive;
	unsigned __int8 m_bWaiting;
	int m_nWaitingReason;
	unsigned __int8 m_bDisableMinibars;
	unsigned __int8 m_bTimeoutVisible;
	unsigned __int8 m_bProgressBarActivated;
	Array<unsigned __int8,6> m_bRemoteWaiting;
	Array<int,6> m_nRemoteActionProgress;
	Array<int,6> m_nRemoteActionTarget;
	Array<int,6> m_nRemoteWaitingReason;
};

struct CPlex
{
	CPlex* pNext;
	Array<unsigned int,1> dwReserved;
};

struct CNetworkWindow
{
	unsigned __int8 m_bInitialized;
	unsigned __int8 m_bVSSent;
	unsigned __int8 m_bVSReceived;
	unsigned __int8 m_nPlayerNumber;
	unsigned __int16 m_nAckExpected;
	unsigned __int16 m_nNextFrameToSend;
	unsigned __int16 m_nFrameExpected;
	unsigned __int16 m_nTooFar;
	unsigned __int16 m_nOldestFrame;
	Array<cnetworkwindow_queueentry_st,1> m_pOutgoingBuffers;
	Array<cnetworkwindow_queueentry_st,1> m_pIncomingBuffers;
	CTypedPtrList<CPtrList,cnetworkwindow_queueentry_st*> m_lQueueIncomingMessages;
	CTypedPtrList<CPtrList,cnetworkwindow_queueentry_st*> m_lQueueOutgoingMessages;
	Array<unsigned __int8,1> m_pbTimeOutSet;
	Array<unsigned int,1> m_pnTimeOut;
	Array<unsigned __int8,1> m_pbArrived;
	unsigned __int16 m_nNumBuffered;
	unsigned __int8 m_bNoNak;
	unsigned __int8 padding;
	unsigned int m_nPacketTimeout;
	unsigned int m_nAckTimer;
	unsigned __int8 m_bAckTimerSet;
	unsigned __int8 m_bSomethingHappened;
	unsigned int m_nNextEvent;
	unsigned int m_nPlayerTimeout;
	unsigned int m_nNoMessageTimeout;
};

struct CMachineStates
{
	Array<CMachineState,6> m_machineStates;
};

struct CInfTileSet
{
	Array<CResTileSet*,2> tis;
	CVidTile cVidTile;
	CVRamPool* pVRPool;
	CResInfTile** pResTiles;
	unsigned int nTiles;
	unsigned int nTileSize;
};

struct CImmunitiesSpellLevelDecrementing
{
	Array<CSpellLevelDecrementing,10> m_levels;
};

struct CImmunitiesSpellLevel
{
	Array<int,10> m_levels;
};

struct CGameStatsSprite
{
	unsigned int m_strStrongestKillName;
	unsigned int m_nStrongestKillXPValue;
	unsigned int m_nPreviousTimeWithParty;
	unsigned int m_nJoinPartyTime;
	int m_bWithParty;
	unsigned int m_nChapterKillsXPValue;
	unsigned int m_nChapterKillsNumber;
	unsigned int m_nGameKillsXPValue;
	unsigned int m_nGameKillsNumber;
	Array<CGameStatsRes,4> m_pSpellStats;
	Array<CGameStatsRes,4> m_pWeaponStats;
};

struct CGameSpriteEquipment
{
	Array<CItem*,39> m_items;
	unsigned __int8 m_selectedWeapon;
	unsigned __int16 m_selectedWeaponAbility;
	CItem* m_pTempItem;
	CGameSprite* m_pSprite;
};

struct CGameSaveCharacter
{
	unsigned int m_actionMode;
	Array<CButtonData,4> m_quickWeapons;
	Array<CButtonData,3> m_quickSpells;
	Array<CButtonData,3> m_quickItems;
};

struct CGameSave
{
	unsigned int m_inputMode;
	CResRef m_cResCurrentWorldArea;
	unsigned int m_nCurrentWorldLink;
	unsigned int m_nPartyGold;
	__int16 m_curFormation;
	Array<__int16,5> m_quickFormations;
	Array<CItem*,100> m_groupInventory;
	int m_bArenaMode;
	__int16 m_groupInventoryNumber;
	unsigned int m_mode;
	int m_cutScene;
	int m_nCutSceneStatusOverride;
};

struct CGameRemoteObjectArray
{
	CGameRemoteObjectListEntry** m_pArray;
	__int16 m_nArraySize;
	__int16 m_nControlsChanged;
	CGameRemoteObjectControlChange* m_pControlsChanged;
	CGameRemoteObjectControlChange* m_pControlsChangedTail;
	__int16 m_nDeletions;
	CGameRemoteObjectDeletion* m_pDeletions;
	CGameRemoteObjectDeletion* m_pDeletionsTail;
	__int16 m_nControlsAreaChanged;
	Array<CResRef,6> m_psControlsAreaChangedName;
	Array<unsigned int,6> m_pnControlsAreaChangedPlayerNum;
	Array<__int16,6> m_pnControlsAreaChangedFirstObject;
};

struct CGamePermission
{
	Array<unsigned __int8,8> m_permission;
};

struct CDerivedStatsTemplate
{
	unsigned int m_generalState;
	__int16 m_nMaxHitPoints;
	__int16 m_nArmorClass;
	__int16 m_nACCrushingMod;
	__int16 m_nACMissileMod;
	__int16 m_nACPiercingMod;
	__int16 m_nACSlashingMod;
	__int16 m_nTHAC0;
	__int16 m_nNumberOfAttacks;
	__int16 m_nSaveVSDeath;
	__int16 m_nSaveVSWands;
	__int16 m_nSaveVSPoly;
	__int16 m_nSaveVSBreath;
	__int16 m_nSaveVSSpell;
	__int16 m_nResistFire;
	__int16 m_nResistCold;
	__int16 m_nResistElectricity;
	__int16 m_nResistAcid;
	__int16 m_nResistMagic;
	__int16 m_nResistMagicFire;
	__int16 m_nResistMagicCold;
	__int16 m_nResistSlashing;
	__int16 m_nResistCrushing;
	__int16 m_nResistPiercing;
	__int16 m_nResistMissile;
	__int16 m_nLore;
	__int16 m_nLockPicking;
	__int16 m_nMoveSilently;
	__int16 m_nTraps;
	__int16 m_nPickPocket;
	__int16 m_nFatigue;
	__int16 m_nIntoxication;
	__int16 m_nLuck;
	__int16 m_nTracking;
	unsigned __int16 m_nLevel1;
	unsigned __int16 m_nLevel2;
	unsigned __int16 m_nLevel3;
	__int16 m_nSex;
	__int16 m_nSTR;
	__int16 m_nSTRExtra;
	__int16 m_nINT;
	__int16 m_nWIS;
	__int16 m_nDEX;
	__int16 m_nCON;
	__int16 m_nCHR;
	unsigned int m_nXPValue;
	unsigned int m_nXP;
	unsigned int m_nGold;
	unsigned int m_nMoraleBreak;
	unsigned int m_nMoraleRecoveryTime;
	__int16 m_nReputation;
	__int16 m_nHatedRace;
	int m_nHideInShadows;
	int m_nDetectIllusion;
	int m_nSetTraps;
	__int16 m_nDamageBonus;
	__int16 m_nSpellFailureMage;
	__int16 m_nSpellFailurePriest;
	__int16 m_nSpellDurationModMage;
	__int16 m_nSpellDurationModPriest;
	__int16 m_nTurnUndeadLevel;
	__int16 m_nBackstabDamageMultiplier;
	__int16 m_nLayOnHandsAmount;
	int m_bHeld;
	int m_bPolymorphed;
	int m_bIdentifyMode;
	int m_bEntangle;
	int m_bSanctuary;
	int m_bMinorGlobe;
	int m_bShieldGlobe;
	int m_bGrease;
	int m_bWeb;
	int m_bCasterHold;
	__int16 m_nTranslucent;
	__int16 m_nEncumberance;
	__int16 m_nMissileTHAC0Bonus;
	__int16 m_nMagicDamageResistance;
	__int16 m_nResistPoison;
	__int16 m_nSpellDurationModBard;
	int m_bDoNotJump;
	int m_bAuraCleansing;
	unsigned int m_nCastingType;
	__int16 m_nMentalSpeed;
	__int16 m_nPhysicalSpeed;
	__int16 m_nCastingLevelBonusMage;
	__int16 m_nCastingLevelBonusCleric;
	int m_bSeeInvisible;
	int m_bIgnoreDialogPause;
	int m_nMinHitPoints;
	int m_THAC0BonusRight;
	int m_THAC0BonusLeft;
	int m_DamageBonusRight;
	int m_DamageBonusLeft;
	int m_nStoneSkins;
	int m_nProficiencyBastardSword;
	int m_nProficiencyLongSword;
	int m_nProficiencyShortSword;
	int m_nProficiencyAxe;
	int m_nProficiencyTwoHandedSword;
	int m_nProficiencyKatana;
	int m_nProficiencyScimitarWakisashiNinjaTo;
	int m_nProficiencyDagger;
	int m_nProficiencyWarhammer;
	int m_nProficiencySpear;
	int m_nProficiencyHalberd;
	int m_nProficiencyFlailMorningStar;
	int m_nProficiencyMace;
	int m_nProficiencyQuarterStaff;
	int m_nProficiencyCrossbow;
	int m_nProficiencyLongBow;
	int m_nProficiencyShortBow;
	int m_nProficiencyDart;
	int m_nProficiencySling;
	int m_nProficiencyBlackjack;
	int m_nProficiencyGun;
	int m_nProficiencyMartialArts;
	int m_nProficiency2Handed;
	int m_nProficiencySwordAndShield;
	int m_nProficiencySingleWeapon;
	int m_nProficiency2Weapon;
	int m_nProficiencyClub;
	int m_nExtraProficiency2;
	int m_nExtraProficiency3;
	int m_nExtraProficiency4;
	int m_nExtraProficiency5;
	int m_nExtraProficiency6;
	int m_nExtraProficiency7;
	int m_nExtraProficiency8;
	int m_nExtraProficiency9;
	int m_nExtraProficiency10;
	int m_nExtraProficiency11;
	int m_nExtraProficiency12;
	int m_nExtraProficiency13;
	int m_nExtraProficiency14;
	int m_nExtraProficiency15;
	int m_nExtraProficiency16;
	int m_nExtraProficiency17;
	int m_nExtraProficiency18;
	int m_nExtraProficiency19;
	int m_nExtraProficiency20;
	int m_nPuppetMasterId;
	int m_nPuppetMasterType;
	int m_nPuppetType;
	int m_nPuppetId;
	int m_bCheckForBerserk;
	int m_bBerserkStage1;
	int m_bBerserkStage2;
	int m_nDamageLuck;
	CResRef m_cBardSong;
	CResRef m_cBackStab;
	int m_nVisualRange;
	int m_bExplore;
	int m_bThrullCharm;
	int m_bSummonDisable;
	int m_bSummonDisableAction;
	__int16 m_nHitBonus;
	Array<__int16,11> m_nSpecificDamageBonus;
	Array<__int16,12> m_nSchoolSaveBonus;
	unsigned int m_nKit;
	int m_bForceSurge;
	int m_nSurgeMod;
	int m_bImprovedHaste;
	Array<unsigned int,10> m_nScriptingStates;
	int m_nMeleeTHAC0Bonus;
	int m_nMeleeDamageBonus;
	int m_nMissileDamageBonus;
	int m_bDisableCircle;
	int m_nFistTHAC0Bonus;
	int m_nFistDamageBonus;
	unsigned int m_sClassStringOverrideMixed;
	unsigned int m_sClassStringOverrideLower;
	__int16 m_nClassTypeOverrideMixed;
	__int16 m_nClassTypeOverrideLower;
	int m_bPreventSpellProtectionEffects;
	int m_bImmunityToBackStab;
	int m_nLockPickingMTPBonus;
	int m_nMoveSilentlyMTPBonus;
	int m_nTrapsMTPBonus;
	int m_nPickPocketMTPBonus;
	int m_nHideInShadowsMTPBonus;
	int m_nDetectIllusionMTPBonus;
	int m_nSetTrapsMTPBonus;
	int m_bPreventAISlowDown;
	int m_nExistanceDelayOverride;
	int m_bAnimationOnlyHaste;
	int m_bNoPermanentDeath;
	int m_bImmuneToTurnUndead;
	int m_nChaosShield;
	int m_bNPCBump;
	int m_bUseAnyItem;
	int m_nAssassinate;
	int m_bSexChanged;
	int m_nSpellFailureInnate;
	int m_bImmuneToTracking;
	int m_bDeadMagic;
	int m_bImmuneToTimeStop;
	int m_bImmuneToSequester;
	int m_nStoneSkinsGolem;
	int m_nLevelDrain;
	int m_bDoNotDraw;
	int m_bIgnoreDrainDeath;
};

struct CDerivedStats : CDerivedStatsTemplate
{
	CImmunitiesProjectile m_cImmunitiesProjectile;
	CImmunitiesEffect m_cImmunitiesEffect;
	CImmunitiesAIType m_cImmunitiesAIType;
	CImmunitiesSpellLevel m_cImmunitiesSpellLevel;
	CImmunitiesWeapon m_cImmunitiesWeapon;
	CSelectiveBonusList m_cToHitBonusList;
	CSelectiveBonusList m_cDamageBonusList;
	CImmunitiesItemEquipList m_cImmunitiesItemEquip;
	CImmunitiesItemTypeEquipList m_cImmunitiesItemTypeEquip;
	CImmunitiesProjectile m_cBounceProjectile;
	CImmunitiesEffect m_cBounceEffect;
	CImmunitiesSpellLevel m_cBounceSpellLevel;
	CImmunitiesSpellLevelDecrementing m_cBounceProjectileLevelDec;
	CImmunitiesSpellLevelDecrementing m_cImmunitiesProjectileLevelDec;
	CImmunitiesSchoolAndSecondary m_cImmunitiesSchool;
	CImmunitiesSchoolAndSecondary m_cImmunitiesSecondaryType;
	CImmunitiesSchoolAndSecondary m_cBounceSchool;
	CImmunitiesSchoolAndSecondary m_cBounceSecondaryType;
	CImmunitiesItemEquipList m_cImmunitiesItemUse;
	CImmunitiesItemTypeEquipList m_cImmunitiesItemTypeUse;
	CImmunitiesSpellList m_cImmunitiesSpell;
	CImmunitiesSpellList m_cBounceSpell;
	CImmunitiesSchoolAndSecondaryDecrementing m_cImmunitiesSchoolLevelDec;
	CImmunitiesSchoolAndSecondaryDecrementing m_cImmunitiesSecondaryTypeLevelDec;
	CImmunitiesSchoolAndSecondaryDecrementing m_cBounceSchoolLevelDec;
	CImmunitiesSchoolAndSecondaryDecrementing m_cBounceSecondaryTypeLevelDec;
	CContingencyList m_cContingencyList;
	CPersistantEffectListRegenerated m_cRegeneratedPersistantEffectList;
	CImmunitiesSpellLevelDecrementing m_cSpellTrapLevelDec;
	CContingencyList m_cSequencerList;
	CColorRanges m_appliedColorRanges;
	CColorEffects m_appliedColorEffects;
	Array<CCreatureFileMemorizedSpellLevel,9> m_memorizedSpellsLevelMage;
	Array<CCreatureFileMemorizedSpellLevel,7> m_memorizedSpellsLevelPriest;
	Array<int,16> m_disabledButtons;
	Array<int,3> m_disabledSpellTypes;
	int m_disableSpells;
	CApplyEffectList m_cExtraMeleeEffects;
	CApplyEffectList m_cExtraRangedEffects;
	CSelectiveBonusList m_cProtectionList;
	CSelectiveWeaponTypeList m_cSelectiveWeaponTypeList;
	CCriticalEntryList m_cCriticalEntryList;
	Array<unsigned int,8> m_spellStates;
};

struct CCreatureFileMemorizedSpell
{
	Array<unsigned __int8,8> m_spellId;
	unsigned __int16 m_flags;
	Array<unsigned __int8,2> structureAlignment1;
};

struct CCreatureFileKnownSpell
{
	Array<unsigned __int8,8> m_knownSpellId;
	unsigned __int16 m_spellLevel;
	unsigned __int16 m_magicType;
};

struct CCreatureFileItem
{
	Array<unsigned __int8,8> m_itemId;
	unsigned __int16 m_wear;
	Array<unsigned __int16,3> m_usageCount;
	unsigned int m_dynamicFlags;
};

struct CCreatureFileHeader
{
	unsigned int m_name;
	unsigned int m_apparentName;
	unsigned int m_flags;
	unsigned int m_xpValue;
	unsigned int m_xp;
	unsigned int m_gold;
	unsigned int m_generalState;
	__int16 m_hitPoints;
	unsigned __int16 m_maxHitPointsBase;
	unsigned int m_animationType;
	Array<unsigned __int8,7> m_colors;
	unsigned __int8 m_effectVersion;
	Array<unsigned __int8,8> m_portraitSmall;
	Array<unsigned __int8,8> m_portraitLarge;
	unsigned __int8 m_reputation;
	unsigned __int8 m_hideInShadowsBase;
	__int16 m_armorClass;
	__int16 m_armorClassBase;
	__int16 m_armorClassCrushingAdjustment;
	__int16 m_armorClassMissileAdjustment;
	__int16 m_armorClassPiercingAdjustment;
	__int16 m_armorClassSlashingAdjustment;
	char m_toHitArmorClass0Base;
	unsigned __int8 m_numberOfAttacksBase;
	unsigned __int8 m_saveVSDeathBase;
	unsigned __int8 m_saveVSWandsBase;
	unsigned __int8 m_saveVSPolyBase;
	unsigned __int8 m_saveVSBreathBase;
	unsigned __int8 m_saveVSSpellBase;
	char m_resistFireBase;
	char m_resistColdBase;
	char m_resistElectricityBase;
	char m_resistAcidBase;
	char m_resistMagicBase;
	char m_resistMagicFireBase;
	char m_resistMagicColdBase;
	char m_resistSlashingBase;
	char m_resistCrushingBase;
	char m_resistPiercingBase;
	char m_resistMissileBase;
	unsigned __int8 m_detectIllusionBase;
	unsigned __int8 m_setTrapsBase;
	unsigned __int8 m_loreBase;
	unsigned __int8 m_lockPickingBase;
	unsigned __int8 m_moveSilentlyBase;
	unsigned __int8 m_trapsBase;
	unsigned __int8 m_pickPocketBase;
	unsigned __int8 m_fatigue;
	unsigned __int8 m_intoxication;
	char m_luckBase;
	Array<char,15> m_proficiencies;
	unsigned __int8 m_bNightmare;
	unsigned __int8 m_nTranslucent;
	char m_repChangeKilled;
	char m_repChangeJoined;
	char m_repChangeKicked;
	unsigned __int8 m_undeadLevel;
	unsigned __int8 m_trackingBase;
	Array<char,32> m_trackingTarget;
	Array<unsigned int,100> m_speech;
	unsigned __int8 m_level1;
	unsigned __int8 m_level2;
	unsigned __int8 m_level3;
	unsigned __int8 m_sex;
	unsigned __int8 m_STRBase;
	unsigned __int8 m_STRExtraBase;
	unsigned __int8 m_INTBase;
	unsigned __int8 m_WISBase;
	unsigned __int8 m_DEXBase;
	unsigned __int8 m_CONBase;
	unsigned __int8 m_CHRBase;
	unsigned __int8 m_morale;
	unsigned __int8 m_moraleBreak;
	unsigned __int8 m_hatedRace;
	unsigned __int16 m_moraleRecoveryTime;
	unsigned __int16 m_mageSpecUpperWord;
	unsigned __int16 m_mageSpecialization;
	Array<unsigned __int8,8> m_scriptOverRide;
	Array<unsigned __int8,8> m_scriptClass;
	Array<unsigned __int8,8> m_scriptRace;
	Array<unsigned __int8,8> m_scriptGeneral;
	Array<unsigned __int8,8> m_scriptDefault;
};

struct CAreaVariable
{
	Array<char,32> m_name;
	unsigned __int16 m_type;
	unsigned __int16 m_resRefType;
	unsigned int m_dWValue;
	int m_intValue;
	long double m_floatValue;
	Array<char,32> m_stringValue;
};

struct CVariable : CAreaVariable
{
};

struct CAreaUserNote
{
	unsigned __int16 m_startX;
	unsigned __int16 m_startY;
	unsigned int m_note;
	unsigned int m_dwflags;
	unsigned int m_id;
	Array<unsigned int,9> m_notUsed;
};

struct CAreaSoundsAndMusic
{
	unsigned int m_dayMusic;
	unsigned int m_nightMusic;
	unsigned int m_battleWinningMusic;
	unsigned int m_battleStandOffMusic;
	unsigned int m_battleLosingMusic;
	unsigned int m_alt1Music0;
	unsigned int m_alt1Music1;
	unsigned int m_alt1Music2;
	unsigned int m_alt1Music3;
	unsigned int m_alt1Music4;
	Array<unsigned __int8,8> m_dayAmbient;
	Array<unsigned __int8,8> m_dayAmbientExtended;
	unsigned int m_dayAmbientVolume;
	Array<unsigned __int8,8> m_nightAmbient;
	Array<unsigned __int8,8> m_nightAmbientExtended;
	unsigned int m_nightAmbientVolume;
	Array<unsigned int,16> m_notUsed;
};

struct CAreaFileStaticObject
{
	Array<char,32> m_scriptName;
	unsigned __int16 m_posX;
	unsigned __int16 m_posY;
	unsigned int m_timeOfDayVisible;
	Array<unsigned __int8,8> m_resref;
	unsigned int m_nSequence;
	unsigned int m_dwFlags;
	__int16 m_height;
	unsigned __int16 m_translucency;
	unsigned __int16 m_startFrameRange;
	unsigned __int8 m_probability;
	unsigned __int8 m_period;
	Array<unsigned __int8,8> m_paletteResref;
	unsigned __int16 m_sizeX;
	unsigned __int16 m_sizeY;
};

struct CAreaFileSoundObject
{
	Array<char,32> m_scriptName;
	unsigned __int16 m_posX;
	unsigned __int16 m_posY;
	unsigned __int16 m_range;
	Array<unsigned __int8,2> structureAlignment1;
	unsigned int m_pitchVariance;
	unsigned __int16 m_volumeVariance;
	unsigned __int16 m_volume;
	Array<Array<unsigned __int8,8>,10> m_soundObject;
	unsigned __int16 m_soundObjectNum;
	Array<unsigned __int8,2> structureAlignment2;
	unsigned int m_period;
	unsigned int m_periodVariance;
	unsigned int m_timeOfDayActive;
	unsigned int m_dwFlags;
	Array<unsigned int,16> m_notUsed;
};

struct CAreaFileRestEncounter
{
	Array<char,32> m_scriptName;
	Array<unsigned int,10> m_randomCreatureString;
	Array<Array<unsigned __int8,8>,10> m_randomCreature;
	unsigned __int16 m_randomCreatureNum;
	unsigned __int16 m_difficulty;
	unsigned int m_lifeSpan;
	unsigned __int16 m_huntingRange;
	unsigned __int16 m_followRange;
	unsigned __int16 m_maxTypeNum;
	unsigned __int16 m_activated;
	unsigned __int16 m_probDay;
	unsigned __int16 m_probNight;
	unsigned __int16 m_wFlags;
	Array<unsigned __int8,10> m_weights;
	Array<unsigned int,11> m_notUsed;
};

struct CAreaFileRandomMonsterSpawningPoint
{
	Array<char,32> m_scriptName;
	unsigned __int16 m_posX;
	unsigned __int16 m_posY;
	Array<Array<unsigned __int8,8>,10> m_randomCreature;
	unsigned __int16 m_randomCreatureNum;
	unsigned __int16 m_difficulty;
	unsigned __int16 m_spawningRate;
	unsigned __int16 m_wFlags;
	unsigned int m_lifeSpan;
	unsigned __int16 m_huntingRange;
	unsigned __int16 m_followRange;
	unsigned __int16 m_maxTypeNum;
	unsigned __int16 m_activated;
	unsigned int m_timeOfDayVisible;
	unsigned __int16 m_probDay;
	unsigned __int16 m_probNight;
	unsigned int m_frequency;
	unsigned int m_countdown;
	Array<unsigned __int8,10> m_weights;
	Array<unsigned __int16,19> m_notUsed;
};

struct CAreaFileProjectileObject
{
	Array<unsigned __int8,8> m_resref;
	unsigned int m_effectListOffset;
	unsigned __int16 m_effectListCount;
	unsigned __int16 m_projectileID;
	__int16 m_nDelayCount;
	__int16 m_nRepetitionCount;
	unsigned __int16 m_posX;
	unsigned __int16 m_posY;
	unsigned __int16 m_posZ;
	unsigned __int8 m_targetType;
	char m_portraitNum;
};

struct CAreaFileHeader
{
	Array<unsigned __int8,8> m_areaName;
	unsigned int m_lastSaved;
	unsigned int m_flags;
	Array<unsigned __int8,8> m_areaEdgeNorth;
	unsigned int m_flagsEdgeNorth;
	Array<unsigned __int8,8> m_areaEdgeEast;
	unsigned int m_flagsEdgeEast;
	Array<unsigned __int8,8> m_areaEdgeSouth;
	unsigned int m_flagsEdgeSouth;
	Array<unsigned __int8,8> m_areaEdgeWest;
	unsigned int m_flagsEdgeWest;
	unsigned __int16 m_areaType;
	unsigned __int16 m_rainProbability;
	unsigned __int16 m_snowProbability;
	unsigned __int16 m_fogProbability;
	unsigned __int16 m_lightningProbability;
	unsigned __int8 m_waterAlpha;
	unsigned __int8 m_unused;
};

struct CAreaFileContainer
{
	Array<char,32> m_scriptName;
	unsigned __int16 m_posX;
	unsigned __int16 m_posY;
	unsigned __int16 m_containerType;
	unsigned __int16 m_lockDifficulty;
	unsigned int m_dwFlags;
	unsigned __int16 m_trapDetectionDifficulty;
	unsigned __int16 m_trapRemovalDifficulty;
	unsigned __int16 m_trapActivated;
	unsigned __int16 m_trapDetected;
	unsigned __int16 m_posXTrapOrigin;
	unsigned __int16 m_posYTrapOrigin;
	unsigned __int16 m_boundingRectLeft;
	unsigned __int16 m_boundingRectTop;
	unsigned __int16 m_boundingRectRight;
	unsigned __int16 m_boundingRectBottom;
	unsigned int m_startingItem;
	unsigned int m_itemCount;
	Array<unsigned __int8,8> m_script;
	unsigned int m_pickPointStart;
	unsigned __int16 m_pickPointCount;
	unsigned __int16 m_triggerRange;
	Array<char,32> m_ownedBy;
	Array<unsigned __int8,8> m_keyType;
	unsigned int m_breakDifficulty;
	unsigned int m_strNotPickable;
	Array<unsigned int,14> m_notUsed;
};

struct CAreaFileCharacterEntryPoint
{
	Array<char,32> m_entryName;
	unsigned __int16 m_startX;
	unsigned __int16 m_startY;
	unsigned int m_facing;
	Array<unsigned int,16> m_notUsed;
};

union _9CC80BF4F2F1300360474CD60BF15E00
{
	_6B279AA1C7A281E7C97E085DB9F2DFBB __s0;
	int all;
};

struct _4BC756EB7537E12A00FC57C6BF2CCA8B
{
	_9CC80BF4F2F1300360474CD60BF15E00 selected;
	SDL_Rect mouseOver;
};

struct _9B9540D9920A90D57A3D80DDD1A70514
{
	bool (__fastcall *f)(uiMenu*, const SDL_Rect*, SDL_Event*);
	SDL_Point start;
	uiItem* item;
	uiMenu* m;
	_4BC756EB7537E12A00FC57C6BF2CCA8B editor;
};

struct UnmappedUserType
{
	intptr_t toPointer()
	{
		return (intptr_t)this;
	}
};

struct CAIGroup
{
	__int16 m_groupId;
	int m_groupChanged;
	CTypedPtrList<CPtrList,long> m_memberList;
};

struct mosHeader_st
{
	unsigned int nFileType;
	unsigned int nFileVersion;
	unsigned __int16 nWidth;
	unsigned __int16 nHeight;
	unsigned __int16 nXTiles;
	unsigned __int16 nYTiles;
	unsigned __int16 nTileSize;
	unsigned __int8 nTransparentColor;
	unsigned __int8 nCompressed;
	unsigned int nPaletteOffset;
};

struct sequenceTableEntry_st
{
	__int16 nFrames;
	unsigned __int16 nStartingFrame;
};

struct ConstCharString
{
	const char* data;

	char getChar(int index)
	{
		return data[index];
	}

	void set(const char* toSet)
	{
		size_t len = strlen(toSet);
		char* newStr = (char*)p_malloc(len + 1);
		memcpy((void*)newStr, toSet, len);
		data = newStr;
	}

	void setL(const char* toSet, size_t neededLen)
	{
		size_t cpyLen = strlen(toSet);
		if (cpyLen > neededLen)
			cpyLen = neededLen;
		char* newStr = (char*)p_malloc(neededLen);
		memcpy((void*)newStr, toSet, cpyLen);
		if (cpyLen < neededLen)
			memset((void*)(newStr + cpyLen), 0, neededLen - cpyLen);
		data = newStr;
	}

	void setReference(ConstCharString* other)
	{
		data = other->data;
	}

	void pointTo(intptr_t toSet)
	{
		data = (const char*)toSet;
	}

	const char* get()
	{
		return data;
	}

	void free()
	{
		p_free((void*)data);
	}
};

struct Marker
{
	const char* src;
	int start;
	int count;
	int line;
};

struct ISteamRemoteStorage
{
	virtual bool FileWrite(const char* _0, const void* _1, int _2)
	{
		return *(bool*)nullptr;
	}

	virtual int FileRead(const char* _0, void* _1, int _2)
	{
		return *(int*)nullptr;
	}

	virtual unsigned __int64 FileWriteAsync(const char* _0, const void* _1, unsigned int _2)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 FileReadAsync(const char* _0, unsigned int _1, unsigned int _2)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool FileReadAsyncComplete(unsigned __int64 _0, void* _1, unsigned int _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool FileForget(const char* _0)
	{
		return *(bool*)nullptr;
	}

	virtual bool FileDelete(const char* _0)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 FileShare(const char* _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool SetSyncPlatforms(const char* _0, ERemoteStoragePlatform _1)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 FileWriteStreamOpen(const char* _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool FileWriteStreamWriteChunk(unsigned __int64 _0, const void* _1, int _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool FileWriteStreamClose(unsigned __int64 _0)
	{
		return *(bool*)nullptr;
	}

	virtual bool FileWriteStreamCancel(unsigned __int64 _0)
	{
		return *(bool*)nullptr;
	}

	virtual bool FileExists(const char* _0)
	{
		return *(bool*)nullptr;
	}

	virtual bool FilePersisted(const char* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetFileSize(const char* _0)
	{
		return *(int*)nullptr;
	}

	virtual __int64 GetFileTimestamp(const char* _0)
	{
		return *(__int64*)nullptr;
	}

	virtual ERemoteStoragePlatform GetSyncPlatforms(const char* _0)
	{
		return *(ERemoteStoragePlatform*)nullptr;
	}

	virtual int GetFileCount()
	{
		return *(int*)nullptr;
	}

	virtual const char* GetFileNameAndSize(int _0, int* _1)
	{
		return *(const char**)nullptr;
	}

	virtual bool GetQuota(unsigned __int64* _0, unsigned __int64* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool IsCloudEnabledForAccount()
	{
		return *(bool*)nullptr;
	}

	virtual bool IsCloudEnabledForApp()
	{
		return *(bool*)nullptr;
	}

	virtual void SetCloudEnabledForApp(bool _0)
	{
	}

	virtual unsigned __int64 UGCDownload(unsigned __int64 _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool GetUGCDownloadProgress(unsigned __int64 _0, int* _1, int* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool GetUGCDetails(unsigned __int64 _0, unsigned int* _1, char** _2, int* _3, CSteamID* _4)
	{
		return *(bool*)nullptr;
	}

	virtual int UGCRead(unsigned __int64 _0, void* _1, int _2, unsigned int _3, EUGCReadAction _4)
	{
		return *(int*)nullptr;
	}

	virtual int GetCachedUGCCount()
	{
		return *(int*)nullptr;
	}

	virtual unsigned __int64 GetCachedUGCHandle(int _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 PublishWorkshopFile(const char* _0, const char* _1, unsigned int _2, const char* _3, const char* _4, ERemoteStoragePublishedFileVisibility _5, SteamParamStringArray_t* _6, EWorkshopFileType _7)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 CreatePublishedFileUpdateRequest(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool UpdatePublishedFileFile(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool UpdatePublishedFilePreviewFile(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool UpdatePublishedFileTitle(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool UpdatePublishedFileDescription(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool UpdatePublishedFileVisibility(unsigned __int64 _0, ERemoteStoragePublishedFileVisibility _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool UpdatePublishedFileTags(unsigned __int64 _0, SteamParamStringArray_t* _1)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 CommitPublishedFileUpdate(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 GetPublishedFileDetails(unsigned __int64 _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 DeletePublishedFile(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 EnumerateUserPublishedFiles(unsigned int _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 SubscribePublishedFile(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 EnumerateUserSubscribedFiles(unsigned int _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 UnsubscribePublishedFile(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool UpdatePublishedFileSetChangeDescription(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 GetPublishedItemVoteDetails(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 UpdateUserPublishedItemVote(unsigned __int64 _0, bool _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 GetUserPublishedItemVoteDetails(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 EnumerateUserSharedWorkshopFiles(CSteamID _0, unsigned int _1, SteamParamStringArray_t* _2, SteamParamStringArray_t* _3)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 PublishVideo(EWorkshopVideoProvider _0, const char* _1, const char* _2, const char* _3, unsigned int _4, const char* _5, const char* _6, ERemoteStoragePublishedFileVisibility _7, SteamParamStringArray_t* _8)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 SetUserPublishedFileAction(unsigned __int64 _0, EWorkshopFileAction _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 EnumeratePublishedFilesByUserAction(EWorkshopFileAction _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType _0, unsigned int _1, unsigned int _2, unsigned int _3, SteamParamStringArray_t* _4, SteamParamStringArray_t* _5)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 UGCDownloadToLocation(unsigned __int64 _0, const char* _1, unsigned int _2)
	{
		return *(unsigned __int64*)nullptr;
	}
};

struct IDPProvider
{
	virtual void Connect(int _0, const char* _1)
	{
	}

	virtual bool IsConnected()
	{
		return *(bool*)nullptr;
	}

	virtual void Listen(int _0, const char* _1)
	{
	}

	virtual bool Pump(DP_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void Close()
	{
	}

	virtual void RequestSessionDetails(int _0)
	{
	}

	virtual void AllowJoin(bool _0)
	{
	}

	virtual void SetVersion(const char* _0)
	{
	}

	virtual bool IsBackendConnected()
	{
		return *(bool*)nullptr;
	}

	virtual void IDPProvider_Destructor()
	{
	}
};

struct CharString
{
	char* data;

	char getChar(int index)
	{
		return data[index];
	}

	void setChar(int index, char toSet)
	{
		data[index] = toSet;
	}

	void set(const char* toSet)
	{
		size_t len = strlen(toSet);
		char* newStr = (char*)p_malloc(len + 1);
		memcpy((void*)newStr, toSet, len);
		data = newStr;
	}

	void setL(const char* toSet, size_t neededLen)
	{
		size_t cpyLen = strlen(toSet);
		if (cpyLen > neededLen)
			cpyLen = neededLen;
		char* newStr = (char*)p_malloc(neededLen);
		memcpy((void*)newStr, toSet, cpyLen);
		if (cpyLen < neededLen)
			memset((void*)(newStr + cpyLen), 0, neededLen - cpyLen);
		data = newStr;
	}

	void write(const char* toSet)
	{
		strcpy(data, toSet);
	}

	void writeL(const char* toSet, size_t neededLen)
	{
		size_t cpyLen = strlen(toSet);
		if (cpyLen > neededLen)
			cpyLen = neededLen;
		memcpy((void*)data, toSet, cpyLen);
		if (cpyLen < neededLen)
			memset((void*)(data + cpyLen), 0, neededLen - cpyLen);
	}

	void setReference(CharString* other)
	{
		data = other->data;
	}

	void pointTo(intptr_t toSet)
	{
		data = (char*)toSet;
	}

	char* get()
	{
		return data;
	}

	void free()
	{
		if (data) {
			p_free(data);
		}
	}
};

struct CException : CObject
{
	int m_bAutoDelete;
	int m_bReadyForDelete;

	virtual void CObject_Destructor()
	{
	}

	virtual int GetErrorMessage(char* _0, unsigned int _1, unsigned int* _2)
	{
		return *(int*)nullptr;
	}
};

struct SDL_WindowUserData
{
	char* name;
	void* data;
	SDL_WindowUserData* next;
};

struct SDL_Window
{
	const void* magic;
	unsigned int id;
	char* title;
	SDL_Surface* icon;
	int x;
	int y;
	int w;
	int h;
	int min_w;
	int min_h;
	int max_w;
	int max_h;
	unsigned int flags;
	unsigned int last_fullscreen_flags;
	SDL_Rect windowed;
	SDL_DisplayMode fullscreen_mode;
	float brightness;
	wchar_t* gamma;
	wchar_t* saved_gamma;
	SDL_Surface* surface;
	SDL_bool surface_valid;
	SDL_bool is_hiding;
	SDL_bool is_destroying;
	SDL_WindowShaper* shaper;
	SDL_HitTestResult (__fastcall *hit_test)(SDL_Window*, const SDL_Point*, void*);
	void* hit_test_data;
	SDL_WindowUserData* data;
	void* driverdata;
	SDL_Window* prev;
	SDL_Window* next;
};

struct SDL_DropEvent
{
	unsigned int type;
	unsigned int timestamp;
	char* file;
};

union SDL_Event
{
	SDL_EventType type;
	SDL_CommonEvent common;
	SDL_WindowEvent window;
	SDL_KeyboardEvent key;
	SDL_TextEditingEvent edit;
	SDL_TextInputEvent text;
	SDL_MouseMotionEvent motion;
	SDL_MouseButtonEvent button;
	SDL_MouseWheelEvent wheel;
	SDL_JoyAxisEvent jaxis;
	SDL_JoyBallEvent jball;
	SDL_JoyHatEvent jhat;
	SDL_JoyButtonEvent jbutton;
	SDL_JoyDeviceEvent jdevice;
	SDL_ControllerAxisEvent caxis;
	SDL_ControllerButtonEvent cbutton;
	SDL_ControllerDeviceEvent cdevice;
	SDL_AudioDeviceEvent adevice;
	SDL_QuitEvent quit;
	SDL_UserEvent user;
	SDL_SysWMEvent syswm;
	SDL_TouchFingerEvent tfinger;
	SDL_MultiGestureEvent mgesture;
	SDL_DollarGestureEvent dgesture;
	SDL_DropEvent drop;
	Array<unsigned __int8,56> padding;
};

struct ISteamUserStats
{
	virtual bool RequestCurrentStats()
	{
		return *(bool*)nullptr;
	}

	virtual bool GetStat(const char* _0, float* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool GetStat(const char* _0, int* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetStat(const char* _0, float _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetStat(const char* _0, int _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool UpdateAvgRateStat(const char* _0, float _1, long double _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool GetAchievement(const char* _0, bool* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetAchievement(const char* _0)
	{
		return *(bool*)nullptr;
	}

	virtual bool ClearAchievement(const char* _0)
	{
		return *(bool*)nullptr;
	}

	virtual bool GetAchievementAndUnlockTime(const char* _0, bool* _1, unsigned int* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool StoreStats()
	{
		return *(bool*)nullptr;
	}

	virtual int GetAchievementIcon(const char* _0)
	{
		return *(int*)nullptr;
	}

	virtual const char* GetAchievementDisplayAttribute(const char* _0, const char* _1)
	{
		return *(const char**)nullptr;
	}

	virtual bool IndicateAchievementProgress(const char* _0, unsigned int _1, unsigned int _2)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned int GetNumAchievements()
	{
		return *(unsigned int*)nullptr;
	}

	virtual const char* GetAchievementName(unsigned int _0)
	{
		return *(const char**)nullptr;
	}

	virtual unsigned __int64 RequestUserStats(CSteamID _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool GetUserStat(CSteamID _0, const char* _1, float* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool GetUserStat(CSteamID _0, const char* _1, int* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool GetUserAchievement(CSteamID _0, const char* _1, bool* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool GetUserAchievementAndUnlockTime(CSteamID _0, const char* _1, bool* _2, unsigned int* _3)
	{
		return *(bool*)nullptr;
	}

	virtual bool ResetAllStats(bool _0)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 FindOrCreateLeaderboard(const char* _0, ELeaderboardSortMethod _1, ELeaderboardDisplayType _2)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 FindLeaderboard(const char* _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual const char* GetLeaderboardName(unsigned __int64 _0)
	{
		return *(const char**)nullptr;
	}

	virtual int GetLeaderboardEntryCount(unsigned __int64 _0)
	{
		return *(int*)nullptr;
	}

	virtual ELeaderboardSortMethod GetLeaderboardSortMethod(unsigned __int64 _0)
	{
		return *(ELeaderboardSortMethod*)nullptr;
	}

	virtual ELeaderboardDisplayType GetLeaderboardDisplayType(unsigned __int64 _0)
	{
		return *(ELeaderboardDisplayType*)nullptr;
	}

	virtual unsigned __int64 DownloadLeaderboardEntries(unsigned __int64 _0, ELeaderboardDataRequest _1, int _2, int _3)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 DownloadLeaderboardEntriesForUsers(unsigned __int64 _0, CSteamID* _1, int _2)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool GetDownloadedLeaderboardEntry(unsigned __int64 _0, int _1, LeaderboardEntry_t* _2, int* _3, int _4)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 UploadLeaderboardScore(unsigned __int64 _0, ELeaderboardUploadScoreMethod _1, int _2, const int* _3, int _4)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 AttachLeaderboardUGC(unsigned __int64 _0, unsigned __int64 _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 GetNumberOfCurrentPlayers()
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 RequestGlobalAchievementPercentages()
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual int GetMostAchievedAchievementInfo(char* _0, unsigned int _1, float* _2, bool* _3)
	{
		return *(int*)nullptr;
	}

	virtual int GetNextMostAchievedAchievementInfo(int _0, char* _1, unsigned int _2, float* _3, bool* _4)
	{
		return *(int*)nullptr;
	}

	virtual bool GetAchievementAchievedPercent(const char* _0, float* _1)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 RequestGlobalStats(int _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool GetGlobalStat(const char* _0, long double* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool GetGlobalStat(const char* _0, __int64* _1)
	{
		return *(bool*)nullptr;
	}

	virtual int GetGlobalStatHistory(const char* _0, long double* _1, unsigned int _2)
	{
		return *(int*)nullptr;
	}

	virtual int GetGlobalStatHistory(const char* _0, __int64* _1, unsigned int _2)
	{
		return *(int*)nullptr;
	}

	virtual bool GetAchievementProgressLimits(const char* _0, float* _1, float* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool GetAchievementProgressLimits(const char* _0, int* _1, int* _2)
	{
		return *(bool*)nullptr;
	}
};

struct ISteamUGC
{
	virtual unsigned __int64 CreateQueryUserUGCRequest(unsigned int _0, EUserUGCList _1, EUGCMatchingUGCType _2, EUserUGCListSortOrder _3, unsigned int _4, unsigned int _5, unsigned int _6)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 CreateQueryAllUGCRequest(EUGCQuery _0, EUGCMatchingUGCType _1, unsigned int _2, unsigned int _3, const char* _4)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 CreateQueryAllUGCRequest(EUGCQuery _0, EUGCMatchingUGCType _1, unsigned int _2, unsigned int _3, unsigned int _4)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 CreateQueryUGCDetailsRequest(unsigned __int64* _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 SendQueryUGCRequest(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool GetQueryUGCResult(unsigned __int64 _0, unsigned int _1, SteamUGCDetails_t* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool GetQueryUGCPreviewURL(unsigned __int64 _0, unsigned int _1, char* _2, unsigned int _3)
	{
		return *(bool*)nullptr;
	}

	virtual bool GetQueryUGCMetadata(unsigned __int64 _0, unsigned int _1, char* _2, unsigned int _3)
	{
		return *(bool*)nullptr;
	}

	virtual bool GetQueryUGCChildren(unsigned __int64 _0, unsigned int _1, unsigned __int64* _2, unsigned int _3)
	{
		return *(bool*)nullptr;
	}

	virtual bool GetQueryUGCStatistic(unsigned __int64 _0, unsigned int _1, EItemStatistic _2, unsigned __int64* _3)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned int GetQueryUGCNumAdditionalPreviews(unsigned __int64 _0, unsigned int _1)
	{
		return *(unsigned int*)nullptr;
	}

	virtual bool GetQueryUGCAdditionalPreview(unsigned __int64 _0, unsigned int _1, unsigned int _2, char* _3, unsigned int _4, char* _5, unsigned int _6, EItemPreviewType* _7)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned int GetQueryUGCNumKeyValueTags(unsigned __int64 _0, unsigned int _1)
	{
		return *(unsigned int*)nullptr;
	}

	virtual bool GetQueryUGCKeyValueTag(unsigned __int64 _0, unsigned int _1, const char* _2, char* _3, unsigned int _4)
	{
		return *(bool*)nullptr;
	}

	virtual bool GetQueryUGCKeyValueTag(unsigned __int64 _0, unsigned int _1, unsigned int _2, char* _3, unsigned int _4, char* _5, unsigned int _6)
	{
		return *(bool*)nullptr;
	}

	virtual bool ReleaseQueryUGCRequest(unsigned __int64 _0)
	{
		return *(bool*)nullptr;
	}

	virtual bool AddRequiredTag(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool AddRequiredTagGroup(unsigned __int64 _0, const SteamParamStringArray_t* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool AddExcludedTag(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetReturnOnlyIDs(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetReturnKeyValueTags(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetReturnLongDescription(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetReturnMetadata(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetReturnChildren(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetReturnAdditionalPreviews(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetReturnTotalOnly(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetReturnPlaytimeStats(unsigned __int64 _0, unsigned int _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetLanguage(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetAllowCachedResponse(unsigned __int64 _0, unsigned int _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetCloudFileNameFilter(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetMatchAnyTag(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetSearchText(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetRankedByTrendDays(unsigned __int64 _0, unsigned int _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool AddRequiredKeyValueTag(unsigned __int64 _0, const char* _1, const char* _2)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 RequestUGCDetails(unsigned __int64 _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 CreateItem(unsigned int _0, EWorkshopFileType _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 StartItemUpdate(unsigned int _0, unsigned __int64 _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool SetItemTitle(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetItemDescription(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetItemUpdateLanguage(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetItemMetadata(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetItemVisibility(unsigned __int64 _0, ERemoteStoragePublishedFileVisibility _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetItemTags(unsigned __int64 _0, const SteamParamStringArray_t* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetItemContent(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetItemPreview(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool SetAllowLegacyUpload(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool RemoveAllItemKeyValueTags(unsigned __int64 _0)
	{
		return *(bool*)nullptr;
	}

	virtual bool RemoveItemKeyValueTags(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool AddItemKeyValueTag(unsigned __int64 _0, const char* _1, const char* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool AddItemPreviewFile(unsigned __int64 _0, const char* _1, EItemPreviewType _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool AddItemPreviewVideo(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool UpdateItemPreviewFile(unsigned __int64 _0, unsigned int _1, const char* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool UpdateItemPreviewVideo(unsigned __int64 _0, unsigned int _1, const char* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool RemoveItemPreview(unsigned __int64 _0, unsigned int _1)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 SubmitItemUpdate(unsigned __int64 _0, const char* _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual EItemUpdateStatus GetItemUpdateProgress(unsigned __int64 _0, unsigned __int64* _1, unsigned __int64* _2)
	{
		return *(EItemUpdateStatus*)nullptr;
	}

	virtual unsigned __int64 SetUserItemVote(unsigned __int64 _0, bool _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 GetUserItemVote(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 AddItemToFavorites(unsigned int _0, unsigned __int64 _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 RemoveItemFromFavorites(unsigned int _0, unsigned __int64 _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 SubscribeItem(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 UnsubscribeItem(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned int GetNumSubscribedItems()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetSubscribedItems(unsigned __int64* _0, unsigned int _1)
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetItemState(unsigned __int64 _0)
	{
		return *(unsigned int*)nullptr;
	}

	virtual bool GetItemInstallInfo(unsigned __int64 _0, unsigned __int64* _1, char* _2, unsigned int _3, unsigned int* _4)
	{
		return *(bool*)nullptr;
	}

	virtual bool GetItemDownloadInfo(unsigned __int64 _0, unsigned __int64* _1, unsigned __int64* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool DownloadItem(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool BInitWorkshopForGameServer(unsigned int _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual void SuspendDownloads(bool _0)
	{
	}

	virtual unsigned __int64 StartPlaytimeTracking(unsigned __int64* _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 StopPlaytimeTracking(unsigned __int64* _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 StopPlaytimeTrackingForAllItems()
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 AddDependency(unsigned __int64 _0, unsigned __int64 _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 RemoveDependency(unsigned __int64 _0, unsigned __int64 _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 AddAppDependency(unsigned __int64 _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 RemoveAppDependency(unsigned __int64 _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 GetAppDependencies(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 DeleteItem(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}
};

struct IDPPeer
{
	int m_packetSentCount;
	int m_packetReceivedCount;

	virtual void Send(DP_Packet* _0, int _1)
	{
	}

	virtual DP_Packet* GetFrontPacket()
	{
		return *(DP_Packet**)nullptr;
	}

	virtual int HasData()
	{
		return *(int*)nullptr;
	}

	virtual void Disconnect()
	{
	}

	virtual void GetAddress(char* _0, unsigned __int64 _1)
	{
	}

	virtual void IDPPeer_Destructor()
	{
	}
};

struct CString
{
	char* m_pchData;
};

struct CAIObjectType
{
	CString m_name;
	unsigned __int8 m_EnemyAlly;
	unsigned __int8 m_General;
	unsigned __int8 m_Race;
	unsigned __int8 m_Class;
	int m_Instance;
	Array<unsigned __int8,5> m_SpecialCase;
	unsigned __int8 m_Specifics;
	unsigned __int8 m_Gender;
	unsigned __int8 m_Alignment;
};

struct CAITrigger
{
	__int16 m_triggerID;
	int m_specificID;
	CAIObjectType m_triggerCause;
	int m_flags;
	int m_specific2;
	int m_specific3;
	CString m_string1;
	CString m_string2;
};

struct CSelectiveBonus
{
	CAIObjectType m_type;
	int m_bonus;
};

struct CSelectiveWeaponType
{
	int m_slot;
	CAIObjectType m_type;
	CWeaponIdentification m_weapon;
};

struct CBaldurMessage
{
	unsigned __int8 m_bInOnObjectAdd;
	unsigned __int8 m_bInOnObjectDelete;
	unsigned __int8 m_bInOnRestAnnounce;
	unsigned __int8 m_bInOnJournalAnnounce;
	unsigned __int8 m_bInOnAreaMapNoteAnnounce;
	unsigned __int8 m_bInOnAnnounceBiography;
	unsigned __int8 m_bInHandleBlockingMessages;
	unsigned __int8 m_bPlayerShutdown;
	CChatBuffer m_cChatBuffer;
	unsigned __int8 m_nSignalQueueSize;
	unsigned __int8 m_nSignalQueueStart;
	unsigned __int8 m_nSignalQueueEnd;
	Array<unsigned __int8,24> m_pnSignalFrom;
	Array<unsigned __int8,24> m_pnSignalType;
	Array<unsigned __int8,24> m_pnSignalData;
	unsigned __int8 m_bDeleteAreaPolling;
	CString m_sDeleteAreaString;
	unsigned int m_dwDeleteAreaTimeout;
	Array<unsigned __int8,6> m_pnDeleteAreaVotes;
	Array<int,6> m_pnDeleteAreaVoters;
	unsigned __int8 m_bCloseSessionPolling;
	unsigned int m_dwCloseSessionTimeout;
	Array<unsigned __int8,6> m_pnCloseSessionVotes;
	Array<int,6> m_pnCloseSessionVoters;
	Array<int,6> m_pRemovedPlayerID;
	unsigned __int8 m_bRemovedPlayerID;
	unsigned __int8 m_bDialogRequestPending;
	unsigned __int8 m_bDialogReplyReturned;
	unsigned __int8 m_bDialogReplyValue;
	int m_nDialogReplyUpdates;
	unsigned __int8 m_bLeaveAreaLuaRequestPending;
	unsigned __int8 m_bLeaveAreaLuaReplyReturned;
	unsigned __int8 m_nLeaveAreaLuaReplyValue;
	unsigned __int8 m_bLeaveAreaNameRequestPending;
	unsigned __int8 m_bLeaveAreaNameReplyReturned;
	unsigned __int8 m_nLeaveAreaNameReplyValue;
	unsigned __int8 m_bMultiplayerSynchClientPending;
	unsigned __int8 m_bMultiplayerSynchClientFinished;
	unsigned __int8 m_bMultiplayerSynchServerPending;
	unsigned __int8 m_bMultiplayerSynchServerFinished;
	unsigned __int8 m_nMultiplayerSynchClientLocation;
	unsigned __int8 m_bVersionControlShutdown;
	CString m_sVersionControlShutdownClientString;
	CString m_sVersionControlShutdownServerString;
	unsigned __int8 m_nVersionControlShutdownReason;
	unsigned int m_dwSignalSecondsToTimeout;
	unsigned __int8 m_bMultiplayerSessionShutdown;
	unsigned __int8 m_bInReputationChange;
	unsigned __int8 m_bInMessageSetDrawPoly;
};

struct CSteam
{
	struct SubscribedItems
	{
		Array<unsigned __int64,16> vecPublished;
		int curSubscribed;
		int numSubscribed;
	};

	bool m_isSteamConnected;
	CSteamID m_SteamID;
	CCallResult<CSteam,CreateItemResult_t> m_CreateItemCompleted;
	CCallResult<CSteam,SteamUGCQueryCompleted_t> m_PublishedQueryCompleted;
	CCallResult<CSteam,SubmitItemUpdateResult_t> m_SubmitItemUpdateCompleted;
	int m_RemainingPublished;
	int m_CurPagePublished;
	CString m_PublishingName;
	CString m_PublishingDir;
	int m_CloudState;
	CCallResult<CSteam,SteamUGCRequestUGCDetailsResult_t> m_RequestUGCDetailsCompleted;
	CSteam::SubscribedItems m_Subscribed;
	unsigned __int64 m_nUploadId;
	ISteamRemoteStorage* m_RemoteStorage;
	ISteamUGC* m_UGC;
	ISteamUserStats* m_UserStats;
	void (*logger)(const char*, ...);
};

struct CAIId
{
	int m_id;
	CString m_line;
	CString m_start;
};

struct CAbilityData
{
	CResRef m_icon;
	unsigned int m_name;
	CString m_effect;
	int m_nMinLevel;
	int m_nMaxLevel;
	int m_nNumAllowed;
	CString m_sPrereq;
	CString m_sExcludedBy;
	CString m_sAlignmentRestriction;
};

struct CFileException : CException
{
	int m_cause;
	int m_lOsError;
	CString m_strFileName;

	virtual void CObject_Destructor()
	{
	}

	virtual int GetErrorMessage(char* _0, unsigned int _1, unsigned int* _2)
	{
		return *(int*)nullptr;
	}
};

struct CFeedbackEntry
{
	unsigned __int16 feedBackId;
	int int1;
	int int2;
	int int3;
	unsigned int ref1;
	int int4;
	CString stringIn;
};

struct CFile : CObject
{
	unsigned int m_hFile;
	int m_bCloseOnDelete;
	CString m_strFileName;

	virtual void CObject_Destructor()
	{
	}

	virtual unsigned int GetPosition()
	{
		return *(unsigned int*)nullptr;
	}

	virtual CString* GetFileName()
	{
		return *(CString**)nullptr;
	}

	virtual CString* GetFileTitle()
	{
		return *(CString**)nullptr;
	}

	virtual CString* GetFilePath()
	{
		return *(CString**)nullptr;
	}

	virtual void SetFilePath(const char* _0)
	{
	}

	virtual int Open(const char* _0, unsigned int _1, CFileException* _2)
	{
		return *(int*)nullptr;
	}

	virtual int Seek(int _0, unsigned int _1)
	{
		return *(int*)nullptr;
	}

	virtual void SetLength(unsigned int _0)
	{
	}

	virtual unsigned int GetLength()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int Read(void* _0, unsigned int _1)
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int Write(const void* _0, unsigned int _1)
	{
		return *(unsigned int*)nullptr;
	}

	virtual void Abort()
	{
	}

	virtual void Flush()
	{
	}

	virtual void Close()
	{
	}

	virtual unsigned int GetBufferPtr(unsigned int _0, unsigned int _1, void** _2, void** _3)
	{
		return *(unsigned int*)nullptr;
	}
};

struct CGameDialogReply
{
	unsigned int m_flags;
	unsigned int m_replyText;
	unsigned int m_journalEntry;
	CAICondition m_condition;
	CAIResponse m_response;
	CResRef m_nextDialog;
	unsigned int m_nextEntryIndex;
	__POSITION* m_displayPosition;
	int m_removeIfPicked;
	unsigned __int8 m_displayListId;
	CString m_conditionString;
	int m_needToParseCondition;
	CString m_responseString;
	int m_needToParseResponse;
	int m_bracketedActions;
};

struct CGameDialogSprite
{
	CResRef m_file;
	CTypedPtrArray<CPtrArray,CGameDialogEntry*> m_dialogEntries;
	CTypedPtrArray<CPtrArray,CGameDialogEntry*> m_dialogEntriesOrdered;
	int m_characterIndex;
	int m_talkerIndex;
	unsigned int m_currentEntryIndex;
	int m_waitingForResponse;
	int m_responseMarker;
	unsigned int m_playerColor;
	CString m_playerName;
	int m_dialogFreezeCounter;
	int m_dialogFreezeMultiplayer;
	unsigned int m_dWFlags;
	int m_bPlayedStartSound;
	int m_bItemDialog;
	int m_bSuppressName;
	int m_UpdateTime;
};

struct CMapStringToString : CObject
{
	struct CAssoc
	{
		CMapStringToString::CAssoc* pNext;
		unsigned int nHashValue;
		CString key;
		CString value;
	};

	CMapStringToString::CAssoc** m_pHashTable;
	unsigned int m_nHashTableSize;
	int m_nCount;
	CMapStringToString::CAssoc* m_pFreeList;
	CPlex* m_pBlocks;
	int m_nBlockSize;

	virtual void CObject_Destructor()
	{
	}
};

struct CTlkTable
{
	CMapStringToString m_mapTokens;
	unsigned __int8 m_currentGender;
	CTlkFileOverride m_override;
	Array<CFileView*,2> m_tlkFiles;
	unsigned int* m_engineStrings;
	unsigned int m_nEngineStrings;
	unsigned int m_nEngineStringBase;
};

struct CNetworkConnectionSettings
{
	unsigned int dwFlags;
	unsigned int dwMaxPlayers;
	CString sPlayerName;
};

struct CSpawnList : CTypedPtrList<CPtrList,CSpawn*>
{
	CString mSectionAlias;
	int ReceivedFirstSpawnCall;
	unsigned int LastSpawnTime;
	int CheckSpawnTimes;
	unsigned int SpawnTimeOfDay;
	unsigned int mInterval;
	CSpawnVar* pControlVar;

	virtual void CObject_Destructor()
	{
	}
};

struct CMemINISection : CTypedPtrList<CPtrList,CMemINIValue*>
{
	CString mSectionName;

	virtual void CObject_Destructor()
	{
	}
};

struct CMemINI : CTypedPtrList<CPtrList,void*>
{
	CString mFileName;
	CMemINISection* mpLastSection;

	virtual void CObject_Destructor()
	{
	}
};

struct CSpawnVar
{
	CString mScope;
	CString mLabel;
};

struct CSpawnPointVar : CSpawnVar
{
};

struct CMemINIValue
{
	CString mName;
	CString mValue;

	virtual void CMemINIValue_Destructor()
	{
	}
};

struct CStringList : CObject
{
	struct CNode
	{
		CStringList::CNode* pNext;
		CStringList::CNode* pPrev;
		CString data;
	};

	CStringList::CNode* m_pNodeHead;
	CStringList::CNode* m_pNodeTail;
	int m_nCount;
	CStringList::CNode* m_pNodeFree;
	CPlex* m_pBlocks;
	int m_nBlockSize;

	virtual void CObject_Destructor()
	{
	}
};

struct st_tiledef
{
	int nTile;
	int nUsageCount;
	int texture;
	CInfTileSet* pTileSet;
};

struct DPWrapper
{
	enum class PEER_STATE_t : __int32
	{
		PEER_INITIAL = 0,
		PEER_DISCONNECTED = 1,
		PEER_NEGOTIATING = 2,
		PEER_CONNECTING = 3,
		PEER_CONNECTED = 4,
		PEER_INVALID_PASSWORD = 5,
		PEER_JOIN_ROOM_FULL = 6,
		PEER_JOIN_ERROR = 7,
	};

	std::vector<DP_Player*,std::allocator<DP_Player*>> m_players;
	std::queue<DP_Packet*,std::deque<DP_Packet*,std::allocator<DP_Packet*>>> m_packetQueue;
	int m_currentSessionId;
	IDPProvider* m_provider;
	IDPPeer* m_connection;
	int m_peerState;
	bool m_server;
	int m_ReplyFlags;
	int m_playerCreateID;
	DP_ProviderID m_nProvider;
	int m_nMyID;
	DPWrapper::PEER_STATE_t PEER_STATE;
};

struct CNetwork
{
	_GUID m_nApplicationGuid;
	unsigned __int8 m_bApplicationGuidDefined;
	unsigned __int8 m_bAutoConnectCheck;
	unsigned __int8 m_bServiceProviderEnumerated;
	unsigned __int8 m_bServiceProviderSelected;
	int m_nServiceProvider;
	int m_nTotalServiceProviders;
	Array<CString,4> m_ppszServiceProviderNames;
	Array<DP_ProviderID,4> m_pnServiceProviderIDS;
	unsigned __int8 m_bConnectionInitialized;
	unsigned __int8 m_bSocketConnecting;
	unsigned __int8 m_bSocketConnected;
	CString m_sIPAddress;
	unsigned __int8 padding2;
	void* m_lpDPAddress;
	unsigned int m_dwDPAddressSize;
	CString m_version;
	unsigned __int8 m_bSessionSelected;
	int m_nSession;
	unsigned __int8 m_bSessionNameToMake;
	unsigned __int8 padding3;
	CString m_sSessionNameToMake;
	CString m_sSessionDescriptionToMake;
	unsigned __int8 m_bSessionPasswordEnabled;
	unsigned __int8 padding4;
	CString m_sSessionPassword;
	unsigned __int8 m_bAllowNewConnections;
	unsigned __int8 m_bConnectionEstablished;
	unsigned __int8 m_bIsHost;
	DPWrapper m_directPlay;
	int m_nMaxPlayers;
	unsigned int m_dwSessionFlags;
	unsigned __int8 m_bMaxPlayersDefined;
	unsigned __int8 m_bSessionOptionsDefined;
	CString m_sJoinedGame;
	CString m_sLeftGame;
	CString m_sDroppedGame;
	unsigned __int8 m_bPlayerNameToMake;
	unsigned __int8 m_bPlayerCreated;
	int m_idLocalPlayer;
	CString m_sLocalPlayerName;
	int m_nTotalPlayers;
	Array<CString,6> m_psPlayerName;
	Array<int,6> m_pPlayerID;
	Array<unsigned __int8,6> m_pbPlayerVisible;
	Array<unsigned __int8,6> m_pbPlayerEnumerateFlag;
	int m_nLocalPlayer;
	int m_nHostPlayer;
	CString m_sHostIPAddress;
	int m_bAnnounceNewPlayers;
	Array<CNetworkWindow,6> m_pSlidingWindow;
	CNetworkWindow m_SystemWindow;
	Array<unsigned int,256> m_dwCRC32;
	CNetworkConnectionSettings m_connectionSettings;
	unsigned int m_lastMessageSentTime;
	Array<unsigned int,6> m_lastMessageReceivedTime;
};

struct CSearchRequest
{
	unsigned __int8 m_serviceState;
	unsigned __int8 m_collisionDelay;
	int m_collisionSearch;
	unsigned __int8 m_sourceSide;
	unsigned __int8 m_nPartyIds;
	unsigned __int8 m_nTargetIds;
	unsigned __int8 m_nTargetPoints;
	int m_removeSelf;
	unsigned __int8 m_frontList;
	CSearchBitmap* m_searchBitmap;
	Array<unsigned __int8,16> m_terrainTable;
	int m_pathSmooth;
	int m_exclusiveTargetPoints;
	int m_sourceId;
	tagPOINT m_sourcePt;
	int* m_partyIds;
	int* m_targetIds;
	tagPOINT* m_targetPoints;
	int m_minNodes;
	int m_maxNodes;
	int m_minNodesBack;
	int m_maxNodesBack;
	int m_bBump;
	__int16 m_searchRc;
	__int16 m_nPath;
	int* m_pPath;
};

struct CPoint : tagPOINT
{
};

struct CGameAreaNotes
{
	int m_bInitialized;
	CPoint m_ptCellSize;
	CPoint m_ptButtonSize;
	CTypedPtrList<CPtrList,CAreaUserNote*> m_areaNoteList;
	CAreaUserNote m_cAreaNote;
	int m_bAddingNote;
	unsigned int m_nNoteButtonClicked;
	CResRef m_rArea;
	CString m_szBuffer;
	unsigned __int8 m_bNetworkDelete;
	unsigned __int8 m_nCurrentIcon;
};

struct CGameEffectBase
{
	CResRef m_version;
	unsigned int m_effectId;
	unsigned int m_targetType;
	unsigned int m_spellLevel;
	int m_effectAmount;
	unsigned int m_dWFlags;
	unsigned int m_durationType;
	unsigned int m_duration;
	unsigned __int16 m_probabilityUpper;
	unsigned __int16 m_probabilityLower;
	CResRef m_res;
	unsigned int m_numDice;
	unsigned int m_diceSize;
	unsigned int m_savingThrow;
	int m_saveMod;
	unsigned int m_special;
	unsigned int m_school;
	unsigned int m_JeremyIsAnIdiot;
	unsigned int m_minLevel;
	unsigned int m_maxLevel;
	unsigned int m_flags;
	int m_effectAmount2;
	int m_effectAmount3;
	int m_effectAmount4;
	int m_effectAmount5;
	CResRef m_res2;
	CResRef m_res3;
	CPoint m_source;
	CPoint m_target;
	unsigned int m_sourceType;
	CResRef m_sourceRes;
	unsigned int m_sourceFlags;
	unsigned int m_projectileType;
	int m_slotNum;
	Array<char,32> m_scriptName;
	unsigned int m_casterLevel;
	unsigned int m_firstCall;
	unsigned int m_secondaryType;
	Array<unsigned int,15> m_pad;
};

struct CMultiplayerSettings
{
	Array<CGamePermission,6> m_pcPermissions;
	CGamePermission m_cDefaultPermissions;
	Array<int,6> m_pnPlayerReady;
	Array<int,6> m_pnCharacterControlledByPlayer;
	Array<unsigned __int8,6> m_pbCharacterReady;
	Array<unsigned __int8,6> m_pnCharacterStatus;
	Array<int,6> m_pnLoadGameControlledByPlayer;
	unsigned __int8 m_bRefreshCharacters;
	unsigned __int8 m_nImportingBitField;
	unsigned __int8 m_bRestrictStoreOption;
	unsigned __int8 m_bJoinRequests;
	unsigned __int8 m_bAllowReformParty;
	unsigned __int8 m_bArbitrationLockStatus;
	unsigned __int8 m_bArbitrationLockAllowInput;
	CPoint m_ptAreaStart;
	CString m_sAreaName;
	CString m_sSaveName;
	int m_idHostPermittedDialog;
	int m_nHostPermittedDialogDelay;
	unsigned __int8 m_bHostPermittedDialog;
	unsigned __int8 m_bHostPermittedStore;
	int m_idHostPermittedStore;
	unsigned __int8 m_bFirstConnected;
	CString m_sCampaignType;
};

struct CGameSpriteLastUpdate
{
	int* m_pPath;
	__int16 m_nPath;
	__int16 m_currPath;
	CPoint m_ptDest;
	unsigned __int8 m_nMoveScale;
	__int16 m_nSequence;
	CPoint m_ptPosition;
	__int16 m_nFacing;
	unsigned int m_dwState;
	__int16 m_nHitPoints;
	__int16 m_nMaxHitPoints;
	__int16 m_nArmorClass;
	__int16 m_nACCrushingMod;
	__int16 m_nACMissileMod;
	__int16 m_nACPiercingMod;
	__int16 m_nACSlashingMod;
	__int16 m_nPortraitIcons;
	int* m_pPortraitIcons;
	unsigned __int8 m_nEnemyAlly;
	unsigned __int8 m_nEnemyAllyLive;
	unsigned __int8 m_bMoraleFailure;
	unsigned __int8 m_nGeneral;
	unsigned __int8 m_nGeneralLive;
	CString m_sAreaString;
	unsigned __int8 m_bLevelUp;
	int m_nHPCONBonusTotalOld;
	unsigned __int8 m_bSummonDisable;
	unsigned __int8 m_bDoNotJump;
	unsigned __int8 m_bSanctuary;
	unsigned __int8 m_bDisableCircle;
	unsigned __int8 m_bHeld;
	unsigned __int8 m_bActiveImprisonment;
	Array<unsigned int,8> m_spellState;
	int m_bFullUpdateRequired;
};

struct CAIAction
{
	__int16 m_actionID;
	CAIObjectType m_actorID;
	CAIObjectType m_acteeID;
	CAIObjectType m_acteeID2;
	int m_specificID;
	int m_specificID2;
	int m_specificID3;
	CString m_string1;
	CString m_string2;
	CPoint m_dest;
	unsigned int m_internalFlags;
	CString m_source;
};

struct CAOEEntry
{
	enum class AOEType : __int32
	{
		AOE_CIRCLE = 0,
		AOE_CONE = 1,
		AOE_RECTANGLE = 2,
		AOE_LINE = 3,
	};

	CAOEEntry::AOEType m_type;
	CPoint m_center;
	CPoint m_radius;
	unsigned int m_color;
};

struct CFog
{
	float* densityLast;
	float* densityCurrent;
	float* densityNext;
	int N;
	float dt;
	float diff;
	float visc;
	float force;
	float source;
	int dvel;
	float* u;
	float* v;
	float* u_prev;
	float* v_prev;
	float* dens;
	float* dens_prev;
	bool pointEnabled;
	int pointAmount;
	int pointDuration;
	CPoint pointPos;
	float pointUForce;
	float pointVForce;
	CPoint explosionPos;
	int updateCounter;
	bool fading;
	bool initialized;
	float alpha;
	int contrast;
	unsigned int innerColor;
	unsigned int outerColor;
};

struct CGameAreaClairvoyanceEntry
{
	CPoint m_position;
	int m_id;
	int m_timeKill;
	unsigned __int8* m_pVisibleTerrainTable;
	int m_charId;
	__int16 m_visRange;
	int* m_pVisMapExploredArea;
};

struct CMoveListEntry
{
	int m_nSpiteIndex;
	CResRef m_rAreaRes;
	CPoint m_ptDest;
	CPoint m_ptSource;
	unsigned __int8 m_nFacing;
	int m_nDelay;
};

struct MAP_CHAR_POSITIONS
{
	CPoint ptPos;
	int id;
};

struct CWarp : CObject
{
	CWarp* pLastEngine;
	CObList lTimers;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}
};

struct CBaldurEngine : CWarp
{
	int m_nSelectedCharacter;
	int m_nPickedCharacter;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CDungeonMaster : CBaldurEngine
{
	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CVisibilityMapTreeNode
{
	CPoint m_relativePos;
	unsigned __int16 m_nRange;
	Array<__int16,3> m_aChildren;
	__int16 m_parent;
};

struct CVIDMODE_RETICLE_DESCRIPTION
{
	CPoint ptCenter;
	__int16 xAxis;
	__int16 yAxis;
	__int16 piePiecePtXOffset;
	__int16 piePiecePtYOffset;
	__int16 piePieceXOffset;
	__int16 piePieceYOffset;
	__int16 xGap;
	__int16 yGap;
	__int16 cursor;
};

struct CMarker
{
	unsigned __int8 m_type;
	__int16 m_nReticleCounter;
	unsigned __int8 m_nReticleForceRender;
	unsigned __int8 m_nReticleForceRenderTarget;
	unsigned int m_rgbColor;
	CVIDMODE_RETICLE_DESCRIPTION m_reticleDesc;
	unsigned __int8 m_bTalking;
	unsigned __int8 m_bDoubleSize;
};

struct CSpawnPoint
{
	CPoint mLocation;
	int mFacing;

	virtual void CSpawnPoint_Destructor()
	{
	}
};

struct CSpawn
{
	enum class ePMode : __int32
	{
		POINT_SELECT_RANDOM_SEQUENTIAL = 0,
		POINT_SELECT_SEQUENTIAL = 1,
		POINT_SELECT_INDEXED_SEQUENTIAL = 2,
		POINT_SELECT_EXPLICIT = 3,
	};

	unsigned int Interval;
	CString SectionAlias;
	unsigned int SpawnFlags;
	int DataIsValid;
	CAIObjectType mSearchAI;
	int mSearchQty;
	Array<int,4> mSearchRegion;
	CSpawnVar* mpSearchKeyVar;
	CSpawnVar* mpSearchQtyVar;
	CStringList mCREFiles;
	int mCreateQty;
	CString* mpCreateQtyScope;
	CString* mpCreateQtyLabel;
	CString* mpScriptName;
	unsigned __int8 mEA;
	unsigned __int8 mGeneral;
	unsigned __int8 mRace;
	unsigned __int8 mClass;
	unsigned __int8 mGender;
	unsigned __int8 mSpecifics;
	unsigned __int8 mFaction;
	unsigned __int8 mTeam;
	unsigned __int8 mAlignment;
	CString* mpOverrideScript;
	CString* mpClassScript;
	CString* mpRaceScript;
	CString* mpGeneralScript;
	CString* mpDefaultScript;
	CString* mpAreaScript;
	CString* mpSpecificsScript;
	CStringList mDialogFiles;
	int mDeathGoodModifier;
	int mDeathLawModifier;
	int mDeathLadyModifier;
	int mDeathMurderModifier;
	int Facing;
	CSpawnPointArray mSpawnPointArray;
	CSpawnPoint mSpelectedPoint;
	CSpawn::ePMode mPointSelectMode;
	CString* pPointIndexScope;
	CString* pPointIndexLabel;
	CSpawnPointVar* mpExplicitSpawnPoint;
	CString* pExplicitSpawnFacingScope;
	CString* pExplicitSpawnFacingLabel;
	CSpawnPointVar* mpSpawnPointStorage;
	CString* pSpawnFacingStorageScope;
	CString* pSpawnFacingStorageLabel;
	int mSequentialStartValue;
	unsigned int mTimeOfDay;

	virtual void CSpawn_Destructor()
	{
	}
};

struct CScreenWizSpell : CBaldurEngine
{
	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	int m_nSpellLevel;
	int m_bMultiPlayerViewable;
	int m_nMemorizedSpellIndex;
	unsigned __int8 m_bCtrlKeyDown;
	int m_bMagePage;
	unsigned __int8 m_nContingencyMaxLevel;
	unsigned __int8 m_nContingencyMaxSpells;
	__int16 m_bContingencyRestrictTarget;
	CBaldurEngine* m_pOldEngine;
	CResRef m_refContingencyResRef;
	int m_bControlled;
	int m_bPauseState;
	int m_bContingency;
	CResRef m_resEraseSpell;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenPriestSpell : CBaldurEngine
{
	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	int m_nSpellLevel;
	CResRef m_cResCurrentSpell;
	int m_nErrorState;
	unsigned int m_strErrorText;
	int m_nNumErrorButtons;
	Array<unsigned int,3> m_strErrorButtonText;
	int m_bMultiPlayerViewable;
	int m_nMemorizedSpellIndex;
	unsigned __int8 m_bCtrlKeyDown;
	int m_nEngineState;
	int m_bPriestPage;
	int m_bPauseState;
	int m_bControlled;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenMovies : CBaldurEngine
{
	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	int m_nEngineState;
	CStringList* m_pMovies;
	int m_nMovieIndex;
	CString m_sSelectedMovie;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenConnection : CBaldurEngine
{
	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	int m_bCtrlKeyDown;
	int m_bShiftKeyDown;
	int m_bCapsLockKeyOn;
	int m_nProtocol;
	int m_nSessionIndex;
	_GUID m_guidSession;
	unsigned int m_dwLastSessionRefresh;
	int m_nEnumServiceProvidersCountDown;
	int m_bStartedCountDown;
	unsigned __int8 m_bFirstRender;
	unsigned __int8 m_bEliminateInitialize;
	unsigned __int8 m_bEMSwapped;
	unsigned __int8 m_bEMValue;
	unsigned __int8 m_bEMWaiting;
	unsigned __int8 m_nEMEvent;
	unsigned __int8 m_nEMEventStage;
	int m_nErrorState;
	unsigned int m_strErrorText;
	int m_nNumErrorButtons;
	Array<unsigned int,3> m_strErrorButtonText;
	int m_bAllowInput;
	unsigned __int8 m_bEnumeratingAsynchronous;
	unsigned __int8 m_bJoinWaiting;
	unsigned __int8 m_bJoinComplete;
	unsigned __int8 m_nJoinEvent;
	int m_nJoinErrorCode;
	unsigned __int8 m_bJoinReturnValue;
	int m_nWaitingForProviderNumber;
	int m_nWaitingForProviderCount;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenCharacter : CBaldurEngine
{
	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	CPtrList m_lPopupStack;
	unsigned __int8 m_nDualClass;
	CStringList* m_pScripts;
	int m_nScriptIndex;
	int m_nErrorState;
	int m_nCharacterIndex;
	CStringList* m_pCharacters;
	int m_bMultiPlayerViewable;
	int m_bMultiPlayerModifyable;
	__POSITION* m_nCurrentPortrait;
	CStringList* m_pAppearancePortraits;
	CStringList* m_pPortraits;
	int m_nCustomSoundSetIndex;
	int m_nCustomSoundIndex;
	CResRef m_cResPortraitSmall;
	CResRef m_cResPortraitLarge;
	Array<unsigned __int8,7> m_aColor;
	CString m_sScript;
	Array<int,11> m_bSmartScriptFlags;
	CString m_sNewScript;
	CResRef m_cResPortraitSmallTemp;
	CResRef m_cResPortraitMediumTemp;
	unsigned int m_nSpecialization;
	CStringList* m_pSounds;
	CResRef m_cResSoundSet;
	CCreatureFileHeader* m_pTempBaseStats;
	CDerivedStats* m_pTempDerivedStats;
	CTypedPtrList<CPtrList,CResRef*> m_lstMageSpells;
	int m_bShiftKeyDown;
	int m_bCapsLockKeyOn;
	unsigned __int8 m_bCtrlKeyDown;
	CString m_sExportName;
	int m_bAddInactiveAbilities;
	Array<int,9> m_OldMageSpells;
	Array<int,7> m_OldPriestSpells;
	int m_bPauseState;
	int m_bIsLevelingUp;
	int m_bIsCharGenMenu;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CRect : tagRECT
{
};

struct CGameObject
{
	CGameObjectType m_objectType;
	CPoint m_pos;
	int m_posZ;
	CGameArea* m_pArea;
	__POSITION* m_posVertList;
	unsigned __int8 m_listType;
	CAIObjectType m_typeAI;
	int m_id;
	__int16 m_canBeSeen;
	int m_remotePlayerID;
	int m_remoteObjectID;
	unsigned __int8 m_AISpeed;
	unsigned __int8 m_bLocalControl;
	unsigned __int8 m_AIInhibitor;

	virtual void CGameObject_Destructor()
	{
	}

	virtual unsigned __int8 GetObjectType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void AIUpdate()
	{
	}

	virtual const CAIObjectType* GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void GetNextWaypoint(CPoint* _0)
	{
	}

	virtual __POSITION* GetVertListPos()
	{
		return *(__POSITION**)nullptr;
	}

	virtual unsigned __int8 GetVertListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionButton(const CPoint* _0)
	{
	}

	virtual void OnFormationButton(const CPoint* _0)
	{
	}

	virtual void RemoveFromArea()
	{
	}

	virtual void Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void SetCursor(int _0)
	{
	}

	virtual void SetTarget(CPoint _0, int _1)
	{
	}

	virtual void SetVertListPos(__POSITION* _0)
	{
	}

	virtual int EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}
};

struct CObjectMarker : CGameObject
{
	CList<long,long> m_lstObjectIds;
	bool m_bHealthBarMarker;

	virtual void CGameObject_Destructor()
	{
	}

	virtual unsigned __int8 GetObjectType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void AIUpdate()
	{
	}

	virtual const CAIObjectType* GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void GetNextWaypoint(CPoint* _0)
	{
	}

	virtual __POSITION* GetVertListPos()
	{
		return *(__POSITION**)nullptr;
	}

	virtual unsigned __int8 GetVertListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionButton(const CPoint* _0)
	{
	}

	virtual void OnFormationButton(const CPoint* _0)
	{
	}

	virtual void RemoveFromArea()
	{
	}

	virtual void Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void SetCursor(int _0)
	{
	}

	virtual void SetTarget(CPoint _0, int _1)
	{
	}

	virtual void SetVertListPos(__POSITION* _0)
	{
	}

	virtual int EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}
};

struct CGameSpawning : CGameObject
{
	CAreaFileRandomMonsterSpawningPoint m_spawningObject;
	Array<unsigned __int8,16> m_terrainTable;
	Array<unsigned __int8,16> m_visibleTerrainTable;
	int m_nTrackingCounter;
	unsigned int m_weightSum;

	virtual void CGameObject_Destructor()
	{
	}

	virtual unsigned __int8 GetObjectType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void AIUpdate()
	{
	}

	virtual const CAIObjectType* GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void GetNextWaypoint(CPoint* _0)
	{
	}

	virtual __POSITION* GetVertListPos()
	{
		return *(__POSITION**)nullptr;
	}

	virtual unsigned __int8 GetVertListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionButton(const CPoint* _0)
	{
	}

	virtual void OnFormationButton(const CPoint* _0)
	{
	}

	virtual void RemoveFromArea()
	{
	}

	virtual void Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void SetCursor(int _0)
	{
	}

	virtual void SetTarget(CPoint _0, int _1)
	{
	}

	virtual void SetVertListPos(__POSITION* _0)
	{
	}

	virtual int EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}
};

struct CBlood
{
	CGameArea* m_pArea;
	CTypedPtrList<CPtrList,CParticle*> m_particleList;
	CTypedPtrList<CPtrList,CParticle*> m_lstSplashParticles;
	CPoint m_refPoint;
	CPoint m_pos;
	int m_posZ;
	__int16 m_nTimeStamp;
	Array<unsigned int,3> m_aColors;
	CRect m_rBounding;
	__int16 m_nDirection;
	unsigned __int16 m_particleType;
	unsigned __int16 m_bloodType;
	int m_nCharHeight;
	unsigned __int8 m_bLeavePool;
};

struct CRainStorm
{
	CRainDrop* m_pRainDrops;
	unsigned __int16 m_nCurrentDensity;
	CRect m_rOldWorldViewPort;
	__int16 m_nWindGustCounter;
	int m_nRainDrops;
};

struct CSnowStorm
{
	CSnowFlake* m_pSnowFlakes;
	unsigned __int16 m_nCurrentDensity;
	CRect m_rOldWorldViewPort;
};

struct CSize : tagSIZE
{
};

struct CChitin
{
	int m_mouseLButton;
	int m_mouseRButton;
	int m_bMouseLButtonDown;
	tagPOINT m_mouseLDblClickPoint;
	unsigned int m_mouseLDblClickCount;
	int m_bMouseRButtonDown;
	tagPOINT m_mouseRDblClickPoint;
	unsigned int m_mouseRDblClickCount;
	int m_bMouseMButtonDown;
	tagPOINT m_mouseMDblClickPoint;
	unsigned int m_mouseMDblClickCount;
	unsigned int m_mouseDblClickTime;
	tagSIZE m_mouseDblClickSize;
	int bEngineActive;
	int bServicingEnabled;
	int bMessagesEnabled;
	CObList lEngines;
	unsigned int nIterations;
	CWarp* pStartingEngine;
	unsigned int nTimer;
	unsigned int nTimerRes;
	CString m_sCommandLine;
	CRect m_rClient;
	unsigned __int8 m_bReInitializing;
	unsigned __int8 m_bScreenEdgeScroll;
	unsigned int m_opSystemPlatformId;
	__int16 m_capsLockState;
	CPoint m_ptScreen;
	int m_bStartUpHost;
	int m_bStartUpConnect;
	CString m_sStartUpAddress;
	CString m_sStartUpPort;
	CString m_sStartUpPlayer;
	CString m_sStartUpPassword;
	int m_bStartUpNewGame;
	int m_bStartUpLoadGame;
	CString m_sStartUpSession;
	unsigned __int8 m_bStartUpDirectPlayLobby;
	unsigned __int8 m_bStartUpGameSpyLocation;
	CString m_sStartUpGameSpyLocation;
	unsigned __int8 m_bStartUpThroneOfBhaal;
	CSoundMixer* cSoundMixer;
	int m_nMaxPlayers;
	int m_nCurrentSong;
	_EAXPRESET m_nSoundEnvironment;
	int m_bSoundInitialized;
	unsigned __int8 padding;
	int m_bInMouseWheelQueue;
	CTypedPtrList<CPtrList,long*> m_lstMouseWheel;
	unsigned int m_wheelScrollLines;
	int m_bIsMouseInWindow;
	int m_bFrameOutline;
	int m_bUseMirrorFX;
	unsigned int m_msgAutoPlay;
	void* m_hEvent;
	unsigned __int8 m_bUsePlanescapeSoundReductionCurve;
	unsigned int m_nSoundReductionCurveRadius;
	unsigned int m_nTickCount;
	int m_nAIPerSec;
	int m_nAIElasped;
	unsigned int m_nRenderTickCount;
	int m_nRenderPerSec;
	int m_nRenderElasped;
	int m_nAISleeper;
	int m_bIsTouchUI;
	int m_bUseBGRA;
	int m_bRenderTilesLinear;
	CString m_sFontName;
	int m_nFullFrameTimer;
	int m_nGameTimer;
	int m_nRenderTimer;
	int m_nSearchTimer;
	_iobuf* m_fFrameTimeLog;
	int m_bLogFrames;
	CWarp* pActiveEngine;
	CVideo cVideo;
	CNetwork cNetwork;
	CSteam cSteam;
	unsigned __int8 padding2;
	int bPointerUpdated;
	CPoint cMousePosition;
	int nAUCounter;
	int bInTimer;
	int m_AIStale;
	int m_displayStale;
	int m_bInSyncUpdate;
	unsigned int m_keyRepeatDelay;
	unsigned int m_keyRepeatRate;
	CProgressBar cProgressBar;
	unsigned __int16 m_nAICounter;
	int m_bManualFrameControl;
	int m_displayDebug;
	int m_displaySerialize;
	int m_bExitOnError;
	int m_bEnableCucumber;
	CResRef* pCurRes;
	CString m_sFontNameNormal;
	CString m_sFontNameRealms;
	CString m_sFontNameStoneBig;
	CString m_sFontNameStoneSml;
	CString m_sFontNameToolFont;
	CString m_sFontNameFloatTxt;
	int m_bDisplaySubtitles;
	int m_bReverseMouseWheelZoom;

	virtual void SynchronousUpdate()
	{
	}

	virtual void SetupPanels()
	{
	}

	virtual unsigned int GetIDSInvalidVideoMode()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetIDSOpenGLDll()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetIDSExclusiveMode()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetIDSChoosePixelFormat()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetIDSSetPixelFormat()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetIDSSetGameResolution()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetIDSSetGameBitDepth()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetIDSBadDeskTopBitDepth()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetIDSWindowsFonts()
	{
		return *(unsigned int*)nullptr;
	}

	virtual CRes* AllocResObject(int _0)
	{
		return *(CRes**)nullptr;
	}

	virtual const CString* GetIconRes()
	{
		return *(const CString**)nullptr;
	}

	virtual void GetScreenShotFilePrefix(CString* _0)
	{
	}

	virtual int FontRectOutline()
	{
		return *(int*)nullptr;
	}

	virtual int InitializeServices()
	{
		return *(int*)nullptr;
	}

	virtual void SetProgressBar(unsigned __int8 _0, int _1, int _2, int _3, unsigned __int8 _4, int _5, unsigned __int8 _6, int _7, unsigned __int8 _8, unsigned __int8 _9, unsigned int _10)
	{
	}

	virtual void SetProgressBarActivateEngine(int _0)
	{
	}

	virtual void BroadcastMultiplayerProgressBarInfo()
	{
	}

	virtual void SetCDSwitchStatus(unsigned __int8 _0, unsigned __int8 _1, unsigned __int8 _2, const CString* _3, unsigned __int8 _4, unsigned __int8 _5, unsigned __int8 _6)
	{
	}

	virtual void SetCDSwitchActivateEngine(int _0)
	{
	}

	virtual void OnMultiplayerSessionOpen(CString* _0, CString* _1, CString* _2)
	{
	}

	virtual void OnMultiplayerSessionToClose()
	{
	}

	virtual void OnMultiplayerSessionClose()
	{
	}

	virtual void OnMultiplayerPlayerJoin(int _0, const CString* _1)
	{
	}

	virtual void OnMultiplayerPlayerVisible(int _0)
	{
	}

	virtual void OnMultiplayerPlayerLeave(int _0, const CString* _1)
	{
	}

	virtual int MessageCallback(unsigned __int8* _0, unsigned int _1)
	{
		return *(int*)nullptr;
	}

	virtual unsigned __int8 GetGamespyResponse(unsigned __int8 _0, unsigned __int8** _1, unsigned int* _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AsynchronousUpdate(unsigned int _0, unsigned int _1, unsigned int _2, unsigned int _3, unsigned int _4)
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual void ShutDown(int _0, const char* _1, const char* _2)
	{
	}

	virtual const char* GetKeyFileName()
	{
		return *(const char**)nullptr;
	}

	virtual unsigned __int8 GetNumberSoundChannels()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual int GetMovieVolume()
	{
		return *(int*)nullptr;
	}

	virtual void LoadOptions()
	{
	}

	virtual void PreLoadFonts()
	{
	}

	virtual void SetSoundVolumes()
	{
	}

	virtual unsigned __int16 GetMultiplayerGameSpyPort()
	{
		return *(unsigned __int16*)nullptr;
	}

	virtual unsigned __int16 GetMultiplayerDirectPlayPort()
	{
		return *(unsigned __int16*)nullptr;
	}

	virtual void SetRenderCount(unsigned __int8 _0)
	{
	}

	virtual int ConfirmQuit()
	{
		return *(int*)nullptr;
	}

	virtual void GetGameSpyGameName(CString* _0)
	{
	}

	virtual void GetGameSpyCode(CString* _0)
	{
	}

	virtual void GetPanicCDStrings(CString* _0, CString* _1, CString* _2)
	{
	}

	virtual void OnMixerInitialize()
	{
	}

	virtual int Is3DSound(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetEAXActive()
	{
		return *(int*)nullptr;
	}

	virtual void RedrawScreen()
	{
	}

	virtual unsigned __int8 GetSoundEnvironment(CString _0, unsigned int* _1, float* _2, float* _3, float* _4, float* _5)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CutsceneModeActive()
	{
		return *(unsigned __int8*)nullptr;
	}
};

struct uiColumn
{
	uiVariant* width;
	uiItem* items;
	uiColumn* next;
};

enum class uiItemType : __int32
{
	ITEM_NONE = 0,
	ITEM_TEXT = 1,
	ITEM_BUTTON = 2,
	ITEM_LIST = 3,
	ITEM_EDIT = 4,
	ITEM_MOVIE = 5,
	ITEM_SLIDER = 6,
	ITEM_HANDLE = 7,
	ITEM_DRAGGABLE = 8,
	ITEM_SLOT = 9,
	ITEM_MAP = 10,
	ITEM_TEMPLATE = 11,
};

struct uiItem
{
	struct text_t
	{
		const char* originalText;
		uiVariant* text;
		const char* font;
		int point;
		int useFontZoom;
		uiVariant* color;
		int upper;
		int lower;
		uiVariant* shadow;
		uiVariant* showhighlight;
	};

	struct uiTemplate_t
	{
		uiItem* item;
	};

	struct bam_t
	{
		uiVariant* resref;
		uiVariant* sequence;
		uiVariant* sequenceonce;
		uiVariant* frame;
		uiVariant* greyscale;
		uiVariant* usealpha;
		int scaletoclip;
	};

	struct bmp_t
	{
		int resname;
		uiVariant* resref;
		SDL_Rect area;
	};

	struct list_t
	{
		int table;
		int printrow;
		int rowheight;
		int rowwidth;
		uiVariant* rowbackground;
		int dynamicHeight;
		uiColumn* columns;
		int category;
		int showHighlight;
		int seperator;
		int selected;
		int height;
		uiVariant* color;
		int currentRow;
	};

	struct scrollbar_t
	{
		const char* bam;
		const char* function;
		uiVariant* hide;
		int top;
		int held;
		int dragging;
		int contentHeight;
		int respectConstraints;
		int clunkyScroll;
		int skipReset;
	};

	struct slider_t
	{
		const char* position;
		uiVariant* settings;
		int palette;
		const char* background;
		int right;
	};

	struct edit_t
	{
		const char* var;
		int maxlines;
		int maxchars;
		uiVariant* placeholder;
		int cursor;
		int selectStart;
		int selectEnd;
	};

	struct mosaic_t
	{
		uiVariant* resref;
		int respectClipping;
	};

	struct movie_t
	{
		void* res;
		SDL_Rect subtitle;
		int transparent;
		unsigned int background;
		int loop;
		uiVariant* queuedMovie;
	};

	struct button_t
	{
		uiVariant* portrait;
		uiVariant* paperdoll;
		int encumbrance;
		int colorDisplay;
		int frameTimes;
		const char* toggle;
		const char* on;
		const char* highlightGroup;
		uiVariant* clickable;
		uiVariant* actionBar;
		const char* sound;
	};

	struct map_t
	{
		int type;
	};

	struct progressBar_t
	{
		uiVariant* percent;
		uiVariant* color;
		uiVariant* fullColor;
	};

	struct slot_t
	{
		uiVariant* icon;
		uiVariant* count;
		uiVariant* usages;
		uiVariant* highlight;
		uiVariant* tint;
	};

	struct rectangle_t
	{
		int number;
		uiVariant* opacity;
	};

	struct tooltip_t
	{
		const char* originalText;
		uiVariant* text;
		uiVariant* force;
		int position;
		int forceTop;
	};

	uiItemType type;
	uiMenu* menu;
	const char* name;
	int instanceId;
	const char* templateName;
	Marker areaSrc;
	SDL_Rect area;
	SDL_Rect pad;
	int enabled;
	int ignoreEvents;
	int ha;
	int va;
	uiVariant* alpha;
	uiVariant* fill;
	int useOverlayTint;
	Array<int,3> overlayTint;
	uiItem::text_t text;
	uiItem::uiTemplate_t uiTemplate;
	uiItem::bam_t bam;
	uiItem::bmp_t bmp;
	uiItem::list_t list;
	uiItem::scrollbar_t scrollbar;
	uiItem::slider_t slider;
	uiItem::edit_t edit;
	uiItem::mosaic_t mosaic;
	uiItem::movie_t movie;
	uiItem::button_t button;
	uiItem::map_t map;
	uiItem::progressBar_t progressBar;
	uiItem::slot_t slot;
	uiItem::rectangle_t rectangle;
	int action;
	int actionDbl;
	int actionAlt;
	int actionDrag;
	int actionEnter;
	int actionExit;
	int actionUpdate;
	int actionSimpleDrag;
	int actionSimpleDrop;
	int actionHold;
	int actionScroll;
	int framesHeld;
	uiItem::tooltip_t tooltip;
	uiVariant* glow;
	uiVariant* pulse;
	uiItem* next;
};

struct uiMenu
{
	Marker menuSrc;
	const char* name;
	int panel;
	int state;
	uiItem* items;
	uiVariant* modal;
	uiVariant* opacity;
	uiVariant* greyscale;
	int onOpen;
	int onClose;
	SDL_Point offset;
	int ha;
	int va;
	int width;
	int height;
	int enabled;
	int ignoreEsc;
};

typedef uiMenu* (*type_findMenu)(const char* name, int panel, int state);
extern type_findMenu p_findMenu;

typedef void (*type_saveMenuStack)();
extern type_saveMenuStack p_saveMenuStack;

typedef void (*type_uiLoadMenu)(CResText* menuRes);
extern type_uiLoadMenu p_uiLoadMenu;

typedef void** (*type_bsearch)(void* key, void* base, size_t num, size_t width, void* func);
extern type_bsearch p_bsearch;

typedef void (*type_restoreMenuStack)();
extern type_restoreMenuStack p_restoreMenuStack;

typedef int (*type_CompareCResByTypeThenName)(const CRes* a, const CRes* b);
extern type_CompareCResByTypeThenName p_CompareCResByTypeThenName;

typedef int (*type_SDL_GetKeyFromName)(const char* name);
extern type_SDL_GetKeyFromName p_SDL_GetKeyFromName;

extern int* p_numMenus;
extern Array<uiMenu,256>* p_menus;
extern Array<uiMenu*,256>* p_menuStack;
extern int* p_nextStackMenuIdx;
extern CResText** p_menuSrc;
extern int* p_menuLength;
extern CTypedPtrArray<CPtrArray,CRes*>* p_resources;
extern _9B9540D9920A90D57A3D80DDD1A70514* p_capture;

enum class uiVariantType : __int32
{
	UIVAR_INT = 0,
	UIVAR_FUNCTION = 1,
	UIVAR_STRING = 2,
	UIVAR_FLOAT = 3,
};

struct uiVariant
{
	union value_t
	{
		int intVal;
		const char* strVal;
		float floatVal;
		int luaFunc;
	};

	uiVariantType type;
	uiVariant::value_t value;
};

struct view_t
{
	void* viewOfFile;
	unsigned int viewBase;
	unsigned int viewSize;
	int size;
};

typedef void (*type_CRes_Construct)(CRes* pThis);
extern type_CRes_Construct p_CRes_Construct;

typedef void (*type_CRes_Destruct)(CRes* pThis);
extern type_CRes_Destruct p_CRes_Destruct;

typedef void* (*type_CRes_Demand)(CRes* pThis);
extern type_CRes_Demand p_CRes_Demand;

struct CRes
{
	const char* resref;
	int type;
	view_t view;
	unsigned int nID;
	int zip_id;
	int override_id;
	void* pData;
	unsigned int nSize;
	unsigned int nCount;
	bool bWasMalloced;
	bool bLoaded;

	CRes()
	{
		p_CRes_Construct(this);
	}

	void Destruct()
	{
		p_CRes_Destruct(this);
	}

	void* Demand()
	{
		return p_CRes_Demand(this);
	}

	virtual bool Parse(void* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void Dump()
	{
	}

	virtual CResRef* GetResRef()
	{
		return *(CResRef**)nullptr;
	}
};

struct CResWebm : CRes
{
	void* m_pCodec;
	unsigned int m_nFirstFrameTime;
	unsigned int m_nFrameWaitTime;
	bool m_bComplete;
	bool m_bLooping;
	CRect m_rRender;
	int m_texture;
	bool m_bGreyscale;
	bool m_bTiled;
	int m_nTransparent;
	bool m_bUseTone;
	float m_nDeltaX;
	float m_nDeltaY;
	float m_nOffsetX;
	float m_nOffsetY;

	virtual bool Parse(void* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void Dump()
	{
	}

	virtual CResRef* GetResRef()
	{
		return *(CResRef**)nullptr;
	}
};

struct CResWave : CRes
{
	int m_bCompressed;
	int m_bIsOgg;
	unsigned int m_nWaveNormalSize;
	unsigned int m_nWaveCompressedSize;
	unsigned __int8* m_pWaveData;
	WAV_Header* m_pWaveFormatEx;

	virtual bool Parse(void* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void Dump()
	{
	}

	virtual CResRef* GetResRef()
	{
		return *(CResRef**)nullptr;
	}
};

struct CSoundImp : CObject, CResHelper<CResWave,4>
{
	CSound* m_pParent;
	int m_bPositionedSound;
	int m_dwBufferSize;
	int m_dwFrequency;
	int m_nBufferFormat;
	int m_nRange;
	int m_nRangeVolume;
	int m_nXCoordinate;
	int m_nYCoordinate;
	int m_nZCoordinate;
	int m_nPan;
	int m_nVolume;
	bool m_bSoundInitialized;
	int m_nChannel;
	int m_nPriority;
	int m_nLooping;
	int m_nPitchVariance;
	int m_nVolumeVariance;
	bool m_b3DPositionning;
	unsigned int m_nSource;
	unsigned int m_nBuffer;
	bool m_bFireForget;
	unsigned __int64 m_nArea;
	int m_dwOverrideFlags;
	bool m_bSoundIsntDucked;

	virtual void CObject_Destructor()
	{
	}
};

struct CSound : CObject, CResHelper<CResWave,4>
{
	CSoundImp* pimpl;

	virtual void CObject_Destructor()
	{
	}
};

struct CProjectile : CGameObject
{
	unsigned __int16 m_projectileType;
	unsigned __int8 m_addToListType;
	__int16 m_speed;
	int m_sourceId;
	int m_targetId;
	int m_callBackProjectile;
	CGameEffectList m_effectList;
	__int16 m_nType;
	__int16 m_nFileType;
	CPoint m_posExact;
	CPoint m_posDelta;
	CPoint m_startDelta;
	CPoint m_minRandomSpeed;
	CPoint m_maxRandomSpeed;
	int m_startSpeed;
	CPoint m_posDest;
	Array<unsigned __int8,16> m_terrainTable;
	unsigned __int16 m_decAmmount;
	int m_bSparkleTrail;
	unsigned int m_defaultRenderFlags;
	int m_bIgnoreTarget;
	CSound m_sound;
	CResRef m_fireSoundRef;
	int m_loopFireSound;
	CResRef m_arrivalSoundRef;
	int m_loopArrivalSound;
	unsigned __int8 m_bHasHeight;
	__int16 m_nDeltaZ;
	__int16 m_nDeltaZLast;
	int m_nOrigDistance;
	CPoint m_ptBamSize;
	int m_dwFlags;
	int m_maxBounces;
	CString m_visualEffectRef;
	int m_visualEffect;
	__int16 m_maxDuration;
	__int16 m_lanceWidth;
	unsigned int m_extFlags;
	unsigned int m_strRef;
	unsigned int m_color;
	unsigned __int16 m_colorSpeed;
	unsigned __int16 m_shake;
	unsigned __int16 m_IDSValue1;
	unsigned __int16 m_IDSType1;
	unsigned __int16 m_IDSValue2;
	unsigned __int16 m_IDSType2;
	CResRef m_failureSpell;
	CResRef m_successSpell;
	int m_ignoreDamage;

	virtual void CGameObject_Destructor()
	{
	}

	virtual unsigned __int8 GetObjectType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void AIUpdate()
	{
	}

	virtual const CAIObjectType* GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void GetNextWaypoint(CPoint* _0)
	{
	}

	virtual __POSITION* GetVertListPos()
	{
		return *(__POSITION**)nullptr;
	}

	virtual unsigned __int8 GetVertListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionButton(const CPoint* _0)
	{
	}

	virtual void OnFormationButton(const CPoint* _0)
	{
	}

	virtual void RemoveFromArea()
	{
	}

	virtual void Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void SetCursor(int _0)
	{
	}

	virtual void SetTarget(CPoint _0, int _1)
	{
	}

	virtual void SetVertListPos(__POSITION* _0)
	{
	}

	virtual int EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}

	virtual void Fire(CGameArea* _0, int _1, int _2, CPoint _3, int _4, __int16 _5)
	{
	}

	virtual void OnArrival()
	{
	}

	virtual void RemoveSelf()
	{
	}

	virtual void DeliverEffects()
	{
	}

	virtual void CallBack()
	{
	}

	virtual unsigned int GetDefaultRenderFlags()
	{
		return *(unsigned int*)nullptr;
	}

	virtual void SetDefaultRenderFlags(unsigned int _0)
	{
	}

	virtual int SaveProjectile()
	{
		return *(int*)nullptr;
	}

	virtual void Marshal(SProjectileWrapper* _0)
	{
	}

	virtual CAIObjectType* GetTargetType()
	{
		return *(CAIObjectType**)nullptr;
	}

	virtual void SetTargetType(const CAIObjectType* _0)
	{
	}

	virtual void GetPreview(CGameArea* _0)
	{
	}
};

struct CGameAIBase : CGameObject
{
	CAIObjectType m_lAttacker;
	int m_lAttackStyle;
	CAIObjectType m_lOrderedBy;
	CAIObjectType m_protecting;
	CAIObjectType m_protector;
	CAIObjectType m_lTargeted;
	CAIObjectType m_lHitter;
	CAIObjectType m_lHelp;
	CAIObjectType m_lTrigger;
	CAIObjectType m_lSeen;
	CAIObjectType m_lTalkedTo;
	CAIObjectType m_lHeard;
	CAIObjectType m_lSummonedBy;
	CAIObjectType m_lKilled;
	CAIObjectType m_lEnteredBy;
	CAIObjectType m_lAttackerSent;
	CAIObjectType m_lOrderedBySent;
	CAIObjectType m_protectingSent;
	CAIObjectType m_protectorSent;
	CAIObjectType m_lTargetedSent;
	CAIObjectType m_lHitterSent;
	CAIObjectType m_lHelpSent;
	CAIObjectType m_lTriggerSent;
	CAIObjectType m_lSeenSent;
	CAIObjectType m_lTalkedToSent;
	CAIObjectType m_lHeardSent;
	CAIObjectType m_lSummonedBySent;
	CAIObjectType m_lKilledSent;
	CAIScript* m_overrideScript;
	CAIScript* m_areaScript;
	CAIScript* m_specificsScript;
	CAIScript* m_classScript;
	CAIScript* m_raceScript;
	CAIScript* m_generalScript;
	CAIScript* m_defaultScript;
	CAIScript* m_achievementScript;
	CTypedPtrList<CPtrList,CAIAction*> m_queuedActions;
	CTypedPtrList<CPtrList,CAITrigger*> m_pendingTriggers;
	unsigned int m_PAICallCounter;
	unsigned int m_PAICallCounterNoMod;
	CTypedPtrList<CPtrList,CGameTimer*> m_timers;
	__int16 m_curResponseNum;
	__int16 m_curResponseSetNum;
	__int16 m_curScriptNum;
	int m_interrupt;
	__int16 m_actionCount;
	int m_bJustAttacked;
	CAIAction m_curAction;
	int m_nExpectedProcessPendingTriggersCalls;
	__int16 m_nMissedProcessPendingTriggerCalls;
	__int16 m_nAlertnessPeriod;
	Array<char,32> m_scriptName;
	int m_inCutScene;
	int m_firstCall;
	int m_forceActionPick;
	int m_randValue;
	unsigned __int8 m_reactionRoll;
	__int16 m_nLastActionReturn;
	unsigned __int8 m_nVisualRange;
	unsigned int m_iGameText;
	int m_bInActionExecution;
	int m_bNewTrigger;
	int m_triggerSwitch;
	int m_bNoInterrupt;
	int m_bDisableAI;
	CSound m_forcePauseSound;
	int m_nServerLastObjectSynchDelay;
	CAITrigger triggerOverride;

	virtual void CGameObject_Destructor()
	{
	}

	virtual unsigned __int8 GetObjectType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void AIUpdate()
	{
	}

	virtual const CAIObjectType* GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void GetNextWaypoint(CPoint* _0)
	{
	}

	virtual __POSITION* GetVertListPos()
	{
		return *(__POSITION**)nullptr;
	}

	virtual unsigned __int8 GetVertListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionButton(const CPoint* _0)
	{
	}

	virtual void OnFormationButton(const CPoint* _0)
	{
	}

	virtual void RemoveFromArea()
	{
	}

	virtual void Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void SetCursor(int _0)
	{
	}

	virtual void SetTarget(CPoint _0, int _1)
	{
	}

	virtual void SetVertListPos(__POSITION* _0)
	{
	}

	virtual int EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}

	virtual void ClearActions(int _0)
	{
	}

	virtual void UpdateTarget(CGameObject* _0)
	{
	}

	virtual void AddAction(const CAIAction* _0)
	{
	}

	virtual void AddEffect(CGameEffect* _0, unsigned __int8 _1, int _2, int _3)
	{
	}

	virtual void ClearAI(unsigned __int8 _0)
	{
	}

	virtual void DoAction()
	{
	}

	virtual __int16 ExecuteAction()
	{
		return *(__int16*)nullptr;
	}

	virtual void InsertAction(const CAIAction* _0)
	{
	}

	virtual void ProcessAI()
	{
	}

	virtual void SetCurrAction(const CAIAction* _0)
	{
	}

	virtual void SetScript(__int16 _0, CAIScript* _1)
	{
	}

	virtual __int16 GetVisualRange()
	{
		return *(__int16*)nullptr;
	}

	virtual __int16 GetAttackRange()
	{
		return *(__int16*)nullptr;
	}

	virtual const unsigned __int8* GetVisibleTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual const unsigned __int8* GetTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual int QuickDecode(CAITrigger* _0, CGameSprite** _1)
	{
		return *(int*)nullptr;
	}

	virtual __int16 GetHelpRange()
	{
		return *(__int16*)nullptr;
	}

	virtual void ApplyTriggers()
	{
	}

	virtual void AutoPause(unsigned int _0)
	{
	}

	virtual int GetCanSeeInvisible()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionRemoval(CAIAction* _0)
	{
	}

	virtual CRect* GetBounding()
	{
		return *(CRect**)nullptr;
	}
};

struct CGameAIArea : CGameAIBase
{
	virtual void CGameObject_Destructor()
	{
	}

	virtual unsigned __int8 GetObjectType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void AIUpdate()
	{
	}

	virtual const CAIObjectType* GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void GetNextWaypoint(CPoint* _0)
	{
	}

	virtual __POSITION* GetVertListPos()
	{
		return *(__POSITION**)nullptr;
	}

	virtual unsigned __int8 GetVertListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionButton(const CPoint* _0)
	{
	}

	virtual void OnFormationButton(const CPoint* _0)
	{
	}

	virtual void RemoveFromArea()
	{
	}

	virtual void Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void SetCursor(int _0)
	{
	}

	virtual void SetTarget(CPoint _0, int _1)
	{
	}

	virtual void SetVertListPos(__POSITION* _0)
	{
	}

	virtual int EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}

	virtual void ClearActions(int _0)
	{
	}

	virtual void UpdateTarget(CGameObject* _0)
	{
	}

	virtual void AddAction(const CAIAction* _0)
	{
	}

	virtual void AddEffect(CGameEffect* _0, unsigned __int8 _1, int _2, int _3)
	{
	}

	virtual void ClearAI(unsigned __int8 _0)
	{
	}

	virtual void DoAction()
	{
	}

	virtual __int16 ExecuteAction()
	{
		return *(__int16*)nullptr;
	}

	virtual void InsertAction(const CAIAction* _0)
	{
	}

	virtual void ProcessAI()
	{
	}

	virtual void SetCurrAction(const CAIAction* _0)
	{
	}

	virtual void SetScript(__int16 _0, CAIScript* _1)
	{
	}

	virtual __int16 GetVisualRange()
	{
		return *(__int16*)nullptr;
	}

	virtual __int16 GetAttackRange()
	{
		return *(__int16*)nullptr;
	}

	virtual const unsigned __int8* GetVisibleTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual const unsigned __int8* GetTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual int QuickDecode(CAITrigger* _0, CGameSprite** _1)
	{
		return *(int*)nullptr;
	}

	virtual __int16 GetHelpRange()
	{
		return *(__int16*)nullptr;
	}

	virtual void ApplyTriggers()
	{
	}

	virtual void AutoPause(unsigned int _0)
	{
	}

	virtual int GetCanSeeInvisible()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionRemoval(CAIAction* _0)
	{
	}

	virtual CRect* GetBounding()
	{
		return *(CRect**)nullptr;
	}
};

struct CGameAIGame : CGameAIBase
{
	virtual void CGameObject_Destructor()
	{
	}

	virtual unsigned __int8 GetObjectType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void AIUpdate()
	{
	}

	virtual const CAIObjectType* GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void GetNextWaypoint(CPoint* _0)
	{
	}

	virtual __POSITION* GetVertListPos()
	{
		return *(__POSITION**)nullptr;
	}

	virtual unsigned __int8 GetVertListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionButton(const CPoint* _0)
	{
	}

	virtual void OnFormationButton(const CPoint* _0)
	{
	}

	virtual void RemoveFromArea()
	{
	}

	virtual void Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void SetCursor(int _0)
	{
	}

	virtual void SetTarget(CPoint _0, int _1)
	{
	}

	virtual void SetVertListPos(__POSITION* _0)
	{
	}

	virtual int EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}

	virtual void ClearActions(int _0)
	{
	}

	virtual void UpdateTarget(CGameObject* _0)
	{
	}

	virtual void AddAction(const CAIAction* _0)
	{
	}

	virtual void AddEffect(CGameEffect* _0, unsigned __int8 _1, int _2, int _3)
	{
	}

	virtual void ClearAI(unsigned __int8 _0)
	{
	}

	virtual void DoAction()
	{
	}

	virtual __int16 ExecuteAction()
	{
		return *(__int16*)nullptr;
	}

	virtual void InsertAction(const CAIAction* _0)
	{
	}

	virtual void ProcessAI()
	{
	}

	virtual void SetCurrAction(const CAIAction* _0)
	{
	}

	virtual void SetScript(__int16 _0, CAIScript* _1)
	{
	}

	virtual __int16 GetVisualRange()
	{
		return *(__int16*)nullptr;
	}

	virtual __int16 GetAttackRange()
	{
		return *(__int16*)nullptr;
	}

	virtual const unsigned __int8* GetVisibleTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual const unsigned __int8* GetTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual int QuickDecode(CAITrigger* _0, CGameSprite** _1)
	{
		return *(int*)nullptr;
	}

	virtual __int16 GetHelpRange()
	{
		return *(__int16*)nullptr;
	}

	virtual void ApplyTriggers()
	{
	}

	virtual void AutoPause(unsigned int _0)
	{
	}

	virtual int GetCanSeeInvisible()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionRemoval(CAIAction* _0)
	{
	}

	virtual CRect* GetBounding()
	{
		return *(CRect**)nullptr;
	}
};

struct CGameDoor : CGameAIBase
{
	CResRef m_resID;
	CRect m_rOpenBounding;
	CRect m_rClosedBounding;
	unsigned int m_cursorType;
	unsigned int m_dwFlags;
	CPoint* m_pOpenPolygon;
	unsigned __int16 m_nOpenPolygon;
	CPoint* m_pClosedPolygon;
	unsigned __int16 m_nClosedPolygon;
	CPoint* m_pOpenSearch;
	unsigned __int16 m_nOpenSearch;
	CPoint* m_pClosedSearch;
	unsigned __int16 m_nClosedSearch;
	CPoint m_ptDest1;
	CPoint m_ptDest2;
	Array<unsigned __int8,8> m_scriptRes;
	CTiledObject m_tiledObject;
	Array<char,32> m_scriptName;
	Array<char,32> m_triggerName;
	__int16 m_hitPoints;
	__int16 m_armourClass;
	CResRef m_openSound;
	CResRef m_closeSound;
	unsigned __int16 m_trapDetectionDifficulty;
	unsigned __int16 m_trapDisarmingDifficulty;
	unsigned __int16 m_trapActivated;
	unsigned __int16 m_trapDetected;
	unsigned __int16 m_posXTrapOrigin;
	unsigned __int16 m_posYTrapOrigin;
	CResRef m_keyType;
	unsigned int m_detectionDifficulty;
	unsigned int m_lockDifficulty;
	__int16 m_drawPoly;
	CPoint m_ptOpenDest;
	CPoint m_ptClosedDest;
	CSound m_sndDoor;
	unsigned int m_strNotPickable;
	int m_usedDelay;
	unsigned __int8 m_probabilityRoll;

	virtual void CGameObject_Destructor()
	{
	}

	virtual unsigned __int8 GetObjectType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void AIUpdate()
	{
	}

	virtual const CAIObjectType* GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void GetNextWaypoint(CPoint* _0)
	{
	}

	virtual __POSITION* GetVertListPos()
	{
		return *(__POSITION**)nullptr;
	}

	virtual unsigned __int8 GetVertListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionButton(const CPoint* _0)
	{
	}

	virtual void OnFormationButton(const CPoint* _0)
	{
	}

	virtual void RemoveFromArea()
	{
	}

	virtual void Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void SetCursor(int _0)
	{
	}

	virtual void SetTarget(CPoint _0, int _1)
	{
	}

	virtual void SetVertListPos(__POSITION* _0)
	{
	}

	virtual int EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}

	virtual void ClearActions(int _0)
	{
	}

	virtual void UpdateTarget(CGameObject* _0)
	{
	}

	virtual void AddAction(const CAIAction* _0)
	{
	}

	virtual void AddEffect(CGameEffect* _0, unsigned __int8 _1, int _2, int _3)
	{
	}

	virtual void ClearAI(unsigned __int8 _0)
	{
	}

	virtual void DoAction()
	{
	}

	virtual __int16 ExecuteAction()
	{
		return *(__int16*)nullptr;
	}

	virtual void InsertAction(const CAIAction* _0)
	{
	}

	virtual void ProcessAI()
	{
	}

	virtual void SetCurrAction(const CAIAction* _0)
	{
	}

	virtual void SetScript(__int16 _0, CAIScript* _1)
	{
	}

	virtual __int16 GetVisualRange()
	{
		return *(__int16*)nullptr;
	}

	virtual __int16 GetAttackRange()
	{
		return *(__int16*)nullptr;
	}

	virtual const unsigned __int8* GetVisibleTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual const unsigned __int8* GetTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual int QuickDecode(CAITrigger* _0, CGameSprite** _1)
	{
		return *(int*)nullptr;
	}

	virtual __int16 GetHelpRange()
	{
		return *(__int16*)nullptr;
	}

	virtual void ApplyTriggers()
	{
	}

	virtual void AutoPause(unsigned int _0)
	{
	}

	virtual int GetCanSeeInvisible()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionRemoval(CAIAction* _0)
	{
	}

	virtual CRect* GetBounding()
	{
		return *(CRect**)nullptr;
	}
};

struct CGameTiledObject : CGameAIBase
{
	CResRef m_resID;
	unsigned int m_dwFlags;
	CPoint* m_pPrimarySearch;
	unsigned __int16 m_nPrimarySearch;
	CPoint* m_pSecondarySearch;
	unsigned __int16 m_nSecondarySearch;
	CTiledObject m_tiledObject;
	Array<char,32> m_scriptName;

	virtual void CGameObject_Destructor()
	{
	}

	virtual unsigned __int8 GetObjectType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void AIUpdate()
	{
	}

	virtual const CAIObjectType* GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void GetNextWaypoint(CPoint* _0)
	{
	}

	virtual __POSITION* GetVertListPos()
	{
		return *(__POSITION**)nullptr;
	}

	virtual unsigned __int8 GetVertListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionButton(const CPoint* _0)
	{
	}

	virtual void OnFormationButton(const CPoint* _0)
	{
	}

	virtual void RemoveFromArea()
	{
	}

	virtual void Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void SetCursor(int _0)
	{
	}

	virtual void SetTarget(CPoint _0, int _1)
	{
	}

	virtual void SetVertListPos(__POSITION* _0)
	{
	}

	virtual int EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}

	virtual void ClearActions(int _0)
	{
	}

	virtual void UpdateTarget(CGameObject* _0)
	{
	}

	virtual void AddAction(const CAIAction* _0)
	{
	}

	virtual void AddEffect(CGameEffect* _0, unsigned __int8 _1, int _2, int _3)
	{
	}

	virtual void ClearAI(unsigned __int8 _0)
	{
	}

	virtual void DoAction()
	{
	}

	virtual __int16 ExecuteAction()
	{
		return *(__int16*)nullptr;
	}

	virtual void InsertAction(const CAIAction* _0)
	{
	}

	virtual void ProcessAI()
	{
	}

	virtual void SetCurrAction(const CAIAction* _0)
	{
	}

	virtual void SetScript(__int16 _0, CAIScript* _1)
	{
	}

	virtual __int16 GetVisualRange()
	{
		return *(__int16*)nullptr;
	}

	virtual __int16 GetAttackRange()
	{
		return *(__int16*)nullptr;
	}

	virtual const unsigned __int8* GetVisibleTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual const unsigned __int8* GetTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual int QuickDecode(CAITrigger* _0, CGameSprite** _1)
	{
		return *(int*)nullptr;
	}

	virtual __int16 GetHelpRange()
	{
		return *(__int16*)nullptr;
	}

	virtual void ApplyTriggers()
	{
	}

	virtual void AutoPause(unsigned int _0)
	{
	}

	virtual int GetCanSeeInvisible()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionRemoval(CAIAction* _0)
	{
	}

	virtual CRect* GetBounding()
	{
		return *(CRect**)nullptr;
	}
};

struct CGameTrigger : CGameAIBase
{
	unsigned __int16 m_triggerType;
	CRect m_rBounding;
	unsigned int m_cursorType;
	Array<unsigned __int8,8> m_newArea;
	Array<char,32> m_newEntryPoint;
	unsigned int m_dwFlags;
	unsigned int m_description;
	CPoint* m_pPolygon;
	unsigned __int16 m_nPolygon;
	unsigned __int16 m_boundingRange;
	Array<unsigned __int8,8> m_scriptRes;
	Array<char,32> m_scriptName;
	unsigned __int16 m_trapDetectionDifficulty;
	unsigned __int16 m_trapDisarmingDifficulty;
	unsigned __int16 m_trapActivated;
	unsigned __int16 m_trapDetected;
	CPoint m_posTrapOrigin;
	CResRef m_keyType;
	__int16 m_drawPoly;
	unsigned int m_iGameText;
	CPoint m_ptWalkTo;

	virtual void CGameObject_Destructor()
	{
	}

	virtual unsigned __int8 GetObjectType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void AIUpdate()
	{
	}

	virtual const CAIObjectType* GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void GetNextWaypoint(CPoint* _0)
	{
	}

	virtual __POSITION* GetVertListPos()
	{
		return *(__POSITION**)nullptr;
	}

	virtual unsigned __int8 GetVertListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionButton(const CPoint* _0)
	{
	}

	virtual void OnFormationButton(const CPoint* _0)
	{
	}

	virtual void RemoveFromArea()
	{
	}

	virtual void Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void SetCursor(int _0)
	{
	}

	virtual void SetTarget(CPoint _0, int _1)
	{
	}

	virtual void SetVertListPos(__POSITION* _0)
	{
	}

	virtual int EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}

	virtual void ClearActions(int _0)
	{
	}

	virtual void UpdateTarget(CGameObject* _0)
	{
	}

	virtual void AddAction(const CAIAction* _0)
	{
	}

	virtual void AddEffect(CGameEffect* _0, unsigned __int8 _1, int _2, int _3)
	{
	}

	virtual void ClearAI(unsigned __int8 _0)
	{
	}

	virtual void DoAction()
	{
	}

	virtual __int16 ExecuteAction()
	{
		return *(__int16*)nullptr;
	}

	virtual void InsertAction(const CAIAction* _0)
	{
	}

	virtual void ProcessAI()
	{
	}

	virtual void SetCurrAction(const CAIAction* _0)
	{
	}

	virtual void SetScript(__int16 _0, CAIScript* _1)
	{
	}

	virtual __int16 GetVisualRange()
	{
		return *(__int16*)nullptr;
	}

	virtual __int16 GetAttackRange()
	{
		return *(__int16*)nullptr;
	}

	virtual const unsigned __int8* GetVisibleTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual const unsigned __int8* GetTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual int QuickDecode(CAITrigger* _0, CGameSprite** _1)
	{
		return *(int*)nullptr;
	}

	virtual __int16 GetHelpRange()
	{
		return *(__int16*)nullptr;
	}

	virtual void ApplyTriggers()
	{
	}

	virtual void AutoPause(unsigned int _0)
	{
	}

	virtual int GetCanSeeInvisible()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionRemoval(CAIAction* _0)
	{
	}

	virtual CRect* GetBounding()
	{
		return *(CRect**)nullptr;
	}

	virtual int IsOverActivate(const CPoint* _0)
	{
		return *(int*)nullptr;
	}
};

struct CGameSound : CGameObject
{
	CAreaFileSoundObject m_soundObject;
	CSound m_looping;
	int m_bLoopPlaying;
	int m_period;
	int m_periodCount;
	unsigned __int8 m_currentSound;
	unsigned int m_timeOfDayActive;

	virtual void CGameObject_Destructor()
	{
	}

	virtual unsigned __int8 GetObjectType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void AIUpdate()
	{
	}

	virtual const CAIObjectType* GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void GetNextWaypoint(CPoint* _0)
	{
	}

	virtual __POSITION* GetVertListPos()
	{
		return *(__POSITION**)nullptr;
	}

	virtual unsigned __int8 GetVertListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionButton(const CPoint* _0)
	{
	}

	virtual void OnFormationButton(const CPoint* _0)
	{
	}

	virtual void RemoveFromArea()
	{
	}

	virtual void Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void SetCursor(int _0)
	{
	}

	virtual void SetTarget(CPoint _0, int _1)
	{
	}

	virtual void SetVertListPos(__POSITION* _0)
	{
	}

	virtual int EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}
};

struct CGameTemporal : CGameObject
{
	Array<unsigned __int8,16> m_visibleTerrainTable;
	CGameAnimation m_animation;
	int m_animationRunning;
	CPoint m_posExact;
	CPoint m_posDelta;
	__int16 m_duration;
	unsigned __int8 m_durationFade;
	unsigned __int8 m_collision;
	CSound m_sound;
	int m_bPermanent;
	int m_bAllowSave;
	unsigned __int16 m_projectileType;

	virtual void CGameObject_Destructor()
	{
	}

	virtual unsigned __int8 GetObjectType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void AIUpdate()
	{
	}

	virtual const CAIObjectType* GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void GetNextWaypoint(CPoint* _0)
	{
	}

	virtual __POSITION* GetVertListPos()
	{
		return *(__POSITION**)nullptr;
	}

	virtual unsigned __int8 GetVertListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionButton(const CPoint* _0)
	{
	}

	virtual void OnFormationButton(const CPoint* _0)
	{
	}

	virtual void RemoveFromArea()
	{
	}

	virtual void Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void SetCursor(int _0)
	{
	}

	virtual void SetTarget(CPoint _0, int _1)
	{
	}

	virtual void SetVertListPos(__POSITION* _0)
	{
	}

	virtual int EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}
};

struct CGameEffect : CGameEffectBase
{
	int m_sourceId;
	int m_done;
	int m_forceRepass;
	unsigned int m_durationTemp;
	int m_compareIdOnly;
	int m_compareIdAndFlagsOnly;
	int m_compareIdAndEffectAmountOnly;
	int m_compareIdAndResrefOnly;
	CSound m_sound;
	int m_sourceTarget;

	virtual void CGameEffect_Destructor()
	{
	}

	virtual CGameEffect* Copy()
	{
		return *(CGameEffect**)nullptr;
	}

	virtual int ApplyEffect(CGameSprite* _0)
	{
		return *(int*)nullptr;
	}

	virtual int ResolveEffect(CGameSprite* _0)
	{
		return *(int*)nullptr;
	}

	virtual void OnAdd(CGameSprite* _0)
	{
	}

	virtual void OnAddSpecific(CGameSprite* _0)
	{
	}

	virtual void OnLoad(CGameSprite* _0)
	{
	}

	virtual int CheckSave(CGameSprite* _0, unsigned __int8* _1, unsigned __int8* _2, unsigned __int8* _3, unsigned __int8* _4, unsigned __int8* _5, unsigned __int8* _6)
	{
		return *(int*)nullptr;
	}

	virtual int UsesDice()
	{
		return *(int*)nullptr;
	}

	virtual void DisplayString(CGameSprite* _0)
	{
	}

	virtual void OnRemove(CGameSprite* _0)
	{
	}
};

struct CContingency
{
	CAITrigger m_cTrigger;
	CResRef m_cSpellRes;
	CResRef m_cSpellRes2;
	CResRef m_cSpellRes3;
	CAIObjectType m_cTarget;
	unsigned int m_dwFlags;
	CGameEffect m_parentEffect;
	unsigned int m_dwTarget;
	unsigned int m_dwCondition;
	unsigned int m_nLastCheck;
};

struct CGameEffectUsability : CGameEffect
{
	virtual void CGameEffect_Destructor()
	{
	}

	virtual CGameEffect* Copy()
	{
		return *(CGameEffect**)nullptr;
	}

	virtual int ApplyEffect(CGameSprite* _0)
	{
		return *(int*)nullptr;
	}

	virtual int ResolveEffect(CGameSprite* _0)
	{
		return *(int*)nullptr;
	}

	virtual void OnAdd(CGameSprite* _0)
	{
	}

	virtual void OnAddSpecific(CGameSprite* _0)
	{
	}

	virtual void OnLoad(CGameSprite* _0)
	{
	}

	virtual int CheckSave(CGameSprite* _0, unsigned __int8* _1, unsigned __int8* _2, unsigned __int8* _3, unsigned __int8* _4, unsigned __int8* _5, unsigned __int8* _6)
	{
		return *(int*)nullptr;
	}

	virtual int UsesDice()
	{
		return *(int*)nullptr;
	}

	virtual void DisplayString(CGameSprite* _0)
	{
	}

	virtual void OnRemove(CGameSprite* _0)
	{
	}
};

struct STR_RES
{
	CString szText;
	CSound cSound;
};

struct CWeather
{
	unsigned __int8 m_bOverCast;
	unsigned __int16 m_nLightningFreq;
	unsigned __int16 m_nCurrentWeather;
	unsigned __int16 m_nWeatherLevel;
	unsigned int m_nWeatherEndTime;
	unsigned int m_nWeatherStageEndTime;
	unsigned int m_nWeatherDuration;
	unsigned int m_nLastTimeChecked;
	unsigned __int16 m_nWindLevel;
	unsigned int m_rgbCurrentOverCastColor;
	unsigned int m_nDurationCounter;
	CSnowStorm m_snowStorm;
	CRainStorm m_rainStorm;
	CFog m_fog;
	CSound m_sndRain;
	CSound m_sndWind;
	unsigned __int8 m_bWindOn;
	unsigned __int8 m_bUpgrading;
	unsigned int m_nNextTimeToStartChecking;
	unsigned int m_nWindVolumeLevel;
	unsigned int m_nRainVolumeLevel;
	unsigned __int8 m_bReInitialize;
};

struct CResWED : CRes
{
	WED_WedHeader_st* pWEDHeader;
	WED_LayerHeader_st* pLayers;
	WED_PolyHeader_st* pPolyHeader;
	WED_ScreenSectionList* pScreenSectionList;
	WED_PolyList_st* pPolyList;
	WED_PolyPoint_st* pPolyPoints;

	virtual bool Parse(void* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void Dump()
	{
	}

	virtual CResRef* GetResRef()
	{
		return *(CResRef**)nullptr;
	}
};

struct CResTileSet : CRes
{
	ResFixedHeader_st* h;

	virtual bool Parse(void* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void Dump()
	{
	}

	virtual CResRef* GetResRef()
	{
		return *(CResRef**)nullptr;
	}
};

struct CResText : CRes
{
	CString m_string;

	virtual bool Parse(void* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void Dump()
	{
	}

	virtual CResRef* GetResRef()
	{
		return *(CResRef**)nullptr;
	}
};

struct CAIIdList : CResHelper<CResText,1008>
{
	CString m_fileName;
	CTypedPtrList<CPtrList,CAIId*> m_idList;
	int m_faster;
	CAIId** m_pIdArray;
	int m_nArray;

	virtual void CAIIdList_Destructor()
	{
	}
};

struct CAIScriptFile
{
	__int16 m_parseMode;
	int m_lineNumber;
	CAIScript* m_curScript;
	CAIResponseSet* m_curResponseSet;
	CAICondition* m_curCondition;
	CAIResponse* m_curResponse;
	CString m_errors;
	CFile m_file;
	CString source;
	CString m_decompiledText;
	CAIIdList m_actions;
	CAIIdList m_triggers;
	CAIIdList m_objects;
};

struct C2DArray : CResHelper<CResText,1012>
{
	CString* m_pNamesX;
	CString* m_pNamesY;
	CString* m_pArray;
	CString m_default;
	__int16 m_nSizeX;
	__int16 m_nSizeY;
};

struct CRuleTables
{
	C2DArray m_tReactionModCharisma;
	C2DArray m_tReactionModReputation;
	C2DArray m_tReputationMod;
	CAIIdList m_lNoDecodeList;
	C2DArray m_tProficiencySlots;
	C2DArray m_tProficiencySlotsMax;
	C2DArray m_tSkillPointsRace;
	C2DArray m_tSkillPointsDex;
	C2DArray m_tSkillPointsBard;
	C2DArray m_tSkillPointsRanger;
	C2DArray m_tSkillPointsShaman;
	C2DArray m_tAbilityRaceReq;
	C2DArray m_tAbilityRaceAdj;
	C2DArray m_tAbilityClassReq;
	C2DArray m_tAbilityClassMod;
	C2DArray m_tAbilityDualClassSrcReq;
	C2DArray m_tAbilityDualClassDstReq;
	C2DArray m_tSavingThrowPriest;
	C2DArray m_tSavingThrowWarrior;
	C2DArray m_tSavingThrowWizard;
	C2DArray m_tSavingThrowRogue;
	C2DArray m_tSavingThrowDwarfHalfling;
	C2DArray m_tSavingThrowGnome;
	C2DArray m_tSavingThrowMonk;
	C2DArray m_tClassHitPointsTables;
	C2DArray m_tHitPointsCONBonus;
	C2DArray m_tStartingGold;
	C2DArray m_tTHAC0;
	C2DArray m_tMaxSpellsPriest;
	C2DArray m_tMaxSpellsPriestPaladin;
	C2DArray m_tMaxSpellsPriestRanger;
	C2DArray m_tMaxSpellsMage;
	C2DArray m_tMaxSpellsMageBard;
	C2DArray m_tMaxSpellsMageSorcerer;
	C2DArray m_tMaxSpellsMageDragonDisciple;
	C2DArray m_tMaxSpellsShaman;
	C2DArray m_tMaxSpellsPriestWISBonus;
	C2DArray m_tMaxSpellsPriestDruid;
	C2DArray m_tKnownSpellsSorcerer;
	C2DArray m_tKnownSpellsShaman;
	C2DArray m_tBackstabMultiplier;
	C2DArray m_tSneakAttack;
	C2DArray m_tCripplingStrike;
	C2DArray m_tExperienceLevels;
	C2DArray m_tLayOnHandsAmount;
	CAIIdList m_lInstantActions;
	CAIIdList m_lAllowWhileSleepingActions;
	C2DArray m_tMonsterSummon1;
	C2DArray m_tMonsterSummon2;
	C2DArray m_tMonsterSummon3;
	C2DArray m_tAnimalSummon1;
	C2DArray m_tAnimalSummon2;
	C2DArray m_tStrengthMod;
	C2DArray m_tStrengthModExtra;
	C2DArray m_tIntoxicationMod;
	C2DArray m_tFatigueMod;
	C2DArray m_tEffectText;
	C2DArray m_tPlayerInteraction;
	C2DArray m_tNumSpells;
	C2DArray m_tToolTips;
	C2DArray m_tStartArea;
	C2DArray m_tStartPos;
	C2DArray m_tSparkleColors;
	C2DArray m_tMonths;
	C2DArray m_tYears;
	C2DArray m_tDexterityMod;
	C2DArray m_tPostDialog;
	C2DArray m_tCharacterSounds;
	C2DArray m_tRandomEquipment;
	C2DArray m_tRandomTreasure;
	C2DArray m_tRandomTreasureIWD;
	C2DArray m_tRandomMagic;
	C2DArray m_tRandomScroll;
	C2DArray m_tRandomWeapon;
	C2DArray m_tInteractionDialog;
	C2DArray m_tIntelligenceMod;
	C2DArray m_tDonateRumor;
	C2DArray m_tAreaLinkageCaching;
	C2DArray m_tAreaLinkageCachingSingle;
	C2DArray m_tCacheValidation;
	C2DArray m_tScriptDescription;
	C2DArray m_tCharacterStateDescription;
	C2DArray m_tMasterArea;
	C2DArray m_tMovieDescription;
	C2DArray m_tSpellDescription;
	C2DArray m_tBountyChance;
	C2DArray m_tNPCLevel;
	C2DArray m_tNPCLevel25;
	C2DArray m_tDeathSounds;
	C2DArray m_tAlignment;
	C2DArray m_tReputationStoreMod;
	C2DArray m_tReputationStart;
	C2DArray m_tXPCap;
	C2DArray m_tWeaponSpecialization;
	C2DArray m_tWeaponAttacks;
	C2DArray m_tLore;
	C2DArray m_tLoreBonus;
	C2DArray m_tCharismaStoreMod;
	C2DArray m_tRaiseDeadCost;
	C2DArray m_tHappiness;
	C2DArray m_tReputationDescription;
	C2DArray m_tPortraitReplacement;
	C2DArray m_tIntoxication;
	C2DArray m_tCustomSound;
	C2DArray m_tExclusiveItems;
	CAIIdList m_lChaseActions;
	CAIIdList m_lVEFProjectile;
	CAIIdList m_lProjectile;
	C2DArray m_tContingencyConditions;
	C2DArray m_tContingencyTargets;
	C2DArray m_tAbilitiesStart;
	C2DArray m_tWeaponProficiencies;
	C2DArray m_tClassAbilitiesFighterTrue;
	C2DArray m_tClassAbilitiesFighterBerserker;
	C2DArray m_tClassAbilitiesFighterWizardslayer;
	C2DArray m_tClassAbilitiesFighterKensai;
	C2DArray m_tClassAbilitiesPaladinTrue;
	C2DArray m_tClassAbilitiesPaladinCavalier;
	C2DArray m_tClassAbilitiesPaladinInquisitor;
	C2DArray m_tClassAbilitiesPaladinUndeadhunter;
	C2DArray m_tClassAbilitiesPaladinFallen;
	C2DArray m_tClassAbilitiesRangerTrue;
	C2DArray m_tClassAbilitiesRangerFeralan;
	C2DArray m_tClassAbilitiesRangerStalker;
	C2DArray m_tClassAbilitiesRangerBeastmaster;
	C2DArray m_tClassAbilitiesRangerFallen;
	C2DArray m_tClassAbilitiesThiefTrue;
	C2DArray m_tClassAbilitiesThiefAssassin;
	C2DArray m_tClassAbilitiesThiefBountyhunter;
	C2DArray m_tClassAbilitiesThiefSwashbuckler;
	C2DArray m_tClassAbilitiesBardTrue;
	C2DArray m_tClassAbilitiesBardBlade;
	C2DArray m_tClassAbilitiesBardJester;
	C2DArray m_tClassAbilitiesBardSkald;
	C2DArray m_tClassAbilitiesDruidTrue;
	C2DArray m_tClassAbilitiesShamanTrue;
	C2DArray m_tClassAbilitiesDruidTotemicdruid;
	C2DArray m_tClassAbilitiesDruidShapeshifter;
	C2DArray m_tClassAbilitiesDruidBeastfriend;
	C2DArray m_tClassAbilitiesClericTrue;
	C2DArray m_tClassAbilitiesClericTalos;
	C2DArray m_tClassAbilitiesClericHelm;
	C2DArray m_tClassAbilitiesClericLathander;
	C2DArray m_tClassAbilitiesMageTrue;
	C2DArray m_tClassAbilitiesMageAbjurer;
	C2DArray m_tClassAbilitiesMageNecromancer;
	C2DArray m_tClassAbilitiesMageTransmuter;
	C2DArray m_tClassAbilitiesMageDiviner;
	C2DArray m_tClassAbilitiesMageConjurer;
	C2DArray m_tClassAbilitiesMageInvoker;
	C2DArray m_tClassAbilitiesMageIllusionist;
	C2DArray m_tClassAbilitiesMageEnchanter;
	C2DArray m_tClassAbilitiesMonkTrue;
	C2DArray m_tClassAbilitiesMonkDarkMoon;
	C2DArray m_tClassAbilitiesMonkSunSoul;
	C2DArray m_tClassAbilitiesBarbarianTrue;
	C2DArray m_tSpellAutmaticPicker;
	C2DArray m_tSpellAutmaticPickerShaman;
	C2DArray m_tDualClassAllowed;
	C2DArray m_tRandomColors;
	C2DArray m_tSpawnGroup;
	C2DArray m_tItemUseAnimation;
	C2DArray m_tRangerHatedRace;
	C2DArray m_tXPBonus;
	C2DArray m_tCleanAir;
	C2DArray m_tSplashScreens;
	C2DArray m_tLevelModWildMage;
	C2DArray m_tKitTable;
	C2DArray m_tKitList;
	Array<C2DArray*,256> m_apKitList;
	C2DArray m_tSoundEnvironmentResRef;
	C2DArray m_tSoundEnvironmentEnvirons;
	C2DArray m_tItemDialog;
	C2DArray m_tLoadingHints;
	C2DArray m_tSchoolMessage;
	C2DArray m_tSecTypeMessage;
	C2DArray m_tContingencyExceptions;
	C2DArray m_tClassAbbreviations;
	C2DArray m_tNumLevelUpAbilities;
	C2DArray m_tXPList;
	C2DArray m_tTracking;
	C2DArray m_tMovieSoundOverride;
	C2DArray m_t25StartEquipment;
	C2DArray m_tWish;
	C2DArray m_tEntries;
	C2DArray m_tLoadingHints25;
	C2DArray m_tStartingWeapon;
	C2DArray m_tFamiliars;
	C2DArray m_tThiefSkills;
	C2DArray m_tThiefScaling;
	C2DArray m_tClassTHAC0;
	C2DArray m_tClassInnateSkills;
	C2DArray m_tTBPStartparty;
	C2DArray m_tExtraAnimations;
	C2DArray m_tExtraAnimationSpeeds;
	C2DArray m_tWildMagic;
	C2DArray m_tItemType;
	C2DArray m_tRaceTHAC0Bonus;
	C2DArray m_tClassColours;
	C2DArray m_tRaceColours;
	C2DArray m_tSlotSteal;
	C2DArray m_tNumWeaponSlots;
	C2DArray m_tItemUse;
	C2DArray m_tRaceText;
	C2DArray m_tTokenText;
	C2DArray m_tClassText;
	C2DArray m_tSetSnareLimit;
	C2DArray m_tSummonLimit;
	C2DArray m_tWeaponStyleBonus;
	C2DArray m_tBanterTimings;
	C2DArray m_tClassRaceRestrictions;
	C2DArray m_tMageRaceRestrictions;
	C2DArray m_tClassSpecialBonuses;
	C2DArray m_tMonkFists;
	C2DArray m_tSpellsToHide;
	C2DArray m_tSpellProtections;
	C2DArray m_tSpellAbilities;
	C2DArray m_tSummoningTables;
	C2DArray* m_apSummoningList;
	C2DArray m_tSevenEyes;
	C2DArray m_tItemSpec;
	C2DArray m_tRaceFeatures;
	C2DArray m_tAreaCreatureNodes;
	C2DArray m_tFogAreaSettings;
	C2DArray m_tFogPointSettings;
	C2DArray m_tCampaign;
	C2DArray m_tPartyAI;
	C2DArray m_tContainerIcons;
	C2DArray m_tFallen;
	C2DArray m_tAchievements;
	C2DArray m_tStatValues;
	CAIIdList m_lStats;
	C2DArray m_tSaveName;
	unsigned __int8 m_bPPHostile;
	unsigned __int8 m_bPPReport;
	unsigned __int8 m_bPPBreakInvis;
	int m_nConcentration;
	Array<CResRef,16> m_damageSounds;
	Array<CResRef,16> m_damageEffectAnims;
	Array<CResRef,16> m_damageSplashAnims;
	Array<unsigned int,16> m_damageStrings;
	Array<int,56> m_speechOffsets;
	Array<int,56> m_speechNums;
};

struct CResSpell : CRes
{
	Spell_ability_st* pAbilities;
	Item_effect_st* pEffects;
	Spell_Header_st* pHeader;

	virtual bool Parse(void* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void Dump()
	{
	}

	virtual CResRef* GetResRef()
	{
		return *(CResRef**)nullptr;
	}
};

struct CSpell : CResHelper<CResSpell,1006>
{
};

struct CResPVR : CRes
{
	int texture;
	int format;
	int filtering;
	CSize size;

	virtual bool Parse(void* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void Dump()
	{
	}

	virtual CResRef* GetResRef()
	{
		return *(CResRef**)nullptr;
	}
};

struct CResMosaic : CRes
{
	void* pUncompressedData;
	unsigned int nUncompressedSize;
	int texture;
	MOSAICHEADERV2* pMosaicHeaderV2;
	MOSAICQUAD* quads;
	mosHeader_st* pMosaicHeader;
	tagRGBQUAD* pPalettes;
	unsigned __int8* m_pData;
	unsigned int* pOffsets;

	virtual bool Parse(void* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void Dump()
	{
	}

	virtual CResRef* GetResRef()
	{
		return *(CResRef**)nullptr;
	}
};

struct CVidMosaic : CVidImage, CResHelper<CResMosaic,1004>
{
};

struct CResItem : CRes
{
	Item_ability_st* pAbilities;
	Item_effect_st* pEffects;
	Item_Header_st* pHeader;

	virtual bool Parse(void* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void Dump()
	{
	}

	virtual CResRef* GetResRef()
	{
		return *(CResRef**)nullptr;
	}
};

struct CItem : CResHelper<CResItem,1005>
{
	int m_nAbilities;
	unsigned __int16 m_useCount1;
	unsigned __int16 m_useCount2;
	unsigned __int16 m_useCount3;
	unsigned __int16 m_wear;
	unsigned int m_flags;
	Array<CSound,2> m_useSound;
	__int16 m_numSounds;
	CGameEffectUsabilityList m_Usability;

	virtual void CItem_Destructor()
	{
	}
};

struct CResGame : CRes
{
	virtual bool Parse(void* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void Dump()
	{
	}

	virtual CResRef* GetResRef()
	{
		return *(CResRef**)nullptr;
	}
};

struct CGameFile : CResHelper<CResGame,1013>
{
};

struct CResFont : CRes
{
	void* font;

	virtual bool Parse(void* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void Dump()
	{
	}

	virtual CResRef* GetResRef()
	{
		return *(CResRef**)nullptr;
	}
};

struct CVidFont : CResHelper<CResFont,1034>
{
	CVidCellFont* vidCellFont;
	unsigned int foreground;
	unsigned int tintcolor;
	int pointSize;
	int zoom;
};

struct CScreenMap : CBaldurEngine
{
	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	CPtrList m_lPopupStack;
	__int16 m_nLastPicked;
	int m_nErrorState;
	unsigned int m_strErrorText;
	int m_nNumErrorButtons;
	Array<unsigned int,3> m_strErrorButtonText;
	unsigned __int8 m_bSelectWorldOnUp;
	CVidFont m_preLoadFontRealms;
	CVidFont m_preLoadFontTool;
	CVidFont m_preLoadFontStnSml;
	unsigned int m_noteStrref;
	int m_bShiftKeyDown;
	int m_bCapsLockKeyOn;
	unsigned __int8 m_bCtrlKeyDown;
	int m_nClairvoyanceCaster;
	int m_nClairvoyanceDuration;
	unsigned __int8 m_bClairvoyanceCastInBlack;
	int m_nScrollState;
	unsigned int m_nTimeLButtonHeld;
	CRect m_HoldArea;
	bool m_bDisplayExploredMap;
	CVidMosaic m_vmMap;
	unsigned int m_mapTint;
	CGameArea* m_pArea;
	CRect m_rViewPort;
	Array<MAP_CHAR_POSITIONS,6> m_charPositions;
	unsigned __int16 m_nCharInArea;
	int m_nCharactersChanged;
	unsigned int m_nUserNoteId;
	CRect m_rMap;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenWorld : CBaldurEngine
{
	int m_nStupidMovieWait;
	int m_bProtagonistInStartArea;
	int m_nProtagonistMoveMax;
	int m_bWaitToRender;
	SDL_Event flickEvent;
	int m_bIgnoreDisplayTextTop;
	int nCounter;
	int m_boredCount;
	int m_bored;
	int m_playerShutdown;
	int m_bShiftKeyDown;
	int m_bMenuKeyDown;
	int m_bCtrlKeyDown;
	int m_bCapsLockKeyOn;
	unsigned __int8 m_bPaused;
	unsigned __int8 m_bHardPaused;
	unsigned __int8 m_bHostOnlyPaused;
	unsigned __int8 m_bVisualPaused;
	unsigned __int8 m_bFirstRender;
	int m_bPausedBeforePickParty;
	int m_bCheatKeys;
	int m_bMButtonDown;
	int m_bMButtonDragged;
	int m_bSetStartViewCenter;
	CPoint m_ptStartViewCenter;
	__int16 m_sequence;
	unsigned __int8 m_facing;
	unsigned __int8 m_bloodLevel;
	unsigned __int16 m_castingGlow;
	unsigned __int8 m_hitEffect;
	__int16 m_renderText;
	int m_newText;
	CVidFont m_vidFont;
	CVidFont m_vidFont2;
	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	CGameDialogSprite m_internalLoadedDialog;
	CGameDialogSprite* m_pCurrentDialog;
	CPoint m_dialogStartPos;
	CResRef m_dialogStartArea;
	int m_dialogPausing;
	CRect m_newViewSize;
	int m_bForceViewSize;
	unsigned __int8 m_waitingOnResize;
	unsigned __int8 m_storeText;
	CString m_consoleText;
	int m_nTopContainerRow;
	int m_nTopGroupRow;
	unsigned __int8 m_bForceDitherToggledOn;
	CWeather m_WeatherController;
	int m_scrollLockId;
	__int16 m_nResponseMarker;
	int m_bBlockStepDialog;
	int m_interactionIndex;
	int m_interactionTarget;
	CString m_interactionString;
	int m_interactionCounter;
	int m_interactionForce;
	int m_interactionTime;
	int m_lastInteractionIndex;
	unsigned __int8 m_bSetNightOnActivate;
	unsigned __int8 m_bSetDayOnActivate;
	int m_ambianceForce;
	unsigned int m_deltaTime;
	int m_nChatMessageCount;
	CResRef m_movie;
	unsigned __int8 m_bInControlOfDialog;
	unsigned __int8 m_bInControlOfStore;
	int m_bGameOverPanel;
	CResRef m_movieDelay;
	int m_autoPauseId;
	unsigned int m_autoPauseRef;
	unsigned int m_autoPauseColor;
	unsigned int m_autoPauseName;
	int m_nStoreChatMessageCount;
	int m_nPickPartyRemoveCharacterId;
	Array<int,10> m_aPickPartyCharacter;
	int m_nPickPartyNumCharacters;
	unsigned int m_strErrorText;
	Array<unsigned int,3> m_strErrorButtonText;
	unsigned int m_nDialogPanelOnStartDialog;
	unsigned __int8 m_bDialogPressedAButton;
	unsigned __int8 m_bEndMajorEventListenToJoin;
	unsigned __int8 m_bEndMajorEventPauseStatus;
	unsigned __int8 m_bChapterTransitionPending;
	int m_nChapterTransition;
	Array<unsigned __int8,8> m_szChapterTransitionResRef;
	unsigned __int8 m_bTextScreenTransitionPending;
	Array<unsigned __int8,8> m_szTextScreenTransitionResRef;
	unsigned __int8 m_bMoviePending;
	Array<unsigned __int8,8> m_szMovieResRef;
	unsigned __int8 m_bPendingMapWorld;
	int m_idPendingMapWorldController;
	__int16 m_nPendingMapWorldDirection;
	unsigned __int8 m_bRestPending;
	unsigned __int8 m_bRestRenting;
	unsigned __int8 m_bRestMovie;
	int m_nRestHP;
	int m_nRestGP;
	int m_nBattleCryTimeOut;
	CTypedPtrList<CPtrList,CDeathSound*> m_deathSoundList;
	int m_nPartySizeCheckStartDelay;
	unsigned __int8 m_bPlayEndCredits;
	unsigned __int8 m_bPendingReformParty;
	unsigned __int8 m_bLeaveAreaLuaPanicPending;
	unsigned int m_ulLeaveAreaLuaPanicTimer;
	CPoint m_ptLeaveAreaLuaPanicLocation;
	__int16 m_nLeaveAreaLuaPanicDirection;
	CString m_sLeaveAreaLuaPanicAreaName;
	CString m_sLeaveAreaLuaPanicParchment;
	unsigned int m_dwPausedTickCount;
	unsigned int m_dwLastDialogTickCount;
	int m_lastAmbiance;
	int m_comingOutOfDialog;
	unsigned __int8 m_nAutoHideInterface;
	unsigned __int8 m_nAutoUnhideInterface;
	CRect m_rCurrViewPort;
	int m_bLeftPanel;
	int m_bRightPanel;
	unsigned __int8 m_bCheckRestrict;
	CTypedPtrList<CPtrList,long*> m_otherTalkers;
	int m_nInteractionBlockCnt;
	int m_bInteractionBlock;
	int m_nStateOverride;
	int m_nStateOverrideCnt;
	int m_nBlackOutCountDown;
	int m_nCutSceneDeadZoneCountDown;
	int m_nContainerOutline;
	int m_tutorialWaitTimer;
	int m_bPausedBeforeStore;
	int m_nPauseMessageUpdate;
	unsigned int m_deathStrRef;
	int m_bHighlightEnabled;
	float m_fPanStorage;
	int m_bViewingContainer;
	int m_bInDialog;
	int m_bDead;
	int m_bInCommand;
	int m_bPickingParty;
	int m_bAutoZooming;
	float m_fPreviousZoom;
	float m_fTargetZoom;
	CRect m_rPreviousViewPort;
	CPoint m_ptPreviousView;
	CPoint m_ptTarget;
	int m_nZoomCurStep;
	CRect m_rOriginalViewPort;
	CPoint m_ptOriginalView;
	float m_fOriginalZoom;
	int* m_storedGroup;
	int m_nStoredGroupMembers;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenChapter : CBaldurEngine
{
	Array<CKeyInfo,5> m_pVirtualKeys;
	Array<int,5> m_pVirtualKeysFlags;
	unsigned __int8 m_bCtrlKeyDown;
	int m_nChapter;
	int m_nDream;
	CResRef m_cResText;
	CTypedPtrList<CPtrList,CResRef*> m_bmpList;
	int m_nBmpFlip;
	int m_nCurrBmp;
	int m_nParagraph;
	int m_nLine;
	CSound m_cVoiceSound;
	int m_bStartSound;
	int m_nEngineState;
	CResRef m_cResPower;
	int m_nSongCountDown;
	CVidFont m_preLoadFontRealms;
	int m_bMPRemoveTextScreen;
	int m_nCustomSong;
	int m_waitingForNetwork;
	CWarp* m_destinationEngine;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenCreateChar : CBaldurEngine
{
	C2DArray m_kitList;
	CImportGame m_importGame;
	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	int m_bCtrlKeyDown;
	int m_bShiftKeyDown;
	int m_bCapsLockKeyOn;
	CScreenCreateCharStep m_nFirstStep;
	CScreenCreateCharStep m_nCurrentStep;
	CScreenCreateCharStep m_nNextStep;
	int m_nGameSprite;
	int m_nExtraProficiencySlots;
	int m_nExtraAbilityPoints;
	int m_nExtraSpells;
	int m_nExtraSkillPoints;
	int m_nBasePickPockets;
	int m_nBaseOpenLocks;
	int m_nBaseDetectTraps;
	int m_nBaseMoveSilently;
	int m_nBaseHideInShadows;
	int m_nBaseDetectIllusion;
	int m_nBaseSetTraps;
	unsigned __int8 m_nMinSTR;
	unsigned __int8 m_nMinDEX;
	unsigned __int8 m_nMinCON;
	unsigned __int8 m_nMinINT;
	unsigned __int8 m_nMinWIS;
	unsigned __int8 m_nMinCHR;
	unsigned __int8 m_nMaxSTR;
	unsigned __int8 m_nMaxDEX;
	unsigned __int8 m_nMaxCON;
	unsigned __int8 m_nMaxINT;
	unsigned __int8 m_nMaxWIS;
	unsigned __int8 m_nMaxCHR;
	unsigned __int8 m_nPreviousMin;
	unsigned __int8 m_nPreviousMax;
	int m_nMaxProficiencySlots;
	__POSITION* m_nCurrentPortrait;
	CStringList* m_pAppearancePortraits;
	CPtrList m_lPopupStack;
	int m_nEngineState;
	int m_nCharacterSlot;
	int m_nTopHatedRace;
	unsigned __int8 m_nPickRange;
	unsigned __int8 m_nMemorySTR;
	unsigned __int8 m_nMemorySTRExtra;
	unsigned __int8 m_nMemoryDEX;
	unsigned __int8 m_nMemoryCON;
	unsigned __int8 m_nMemoryINT;
	unsigned __int8 m_nMemoryWIS;
	unsigned __int8 m_nMemoryCHR;
	int m_nMemoryExtra;
	int m_nPortraitSmallIndex;
	int m_nPortraitMediumIndex;
	CStringList* m_pPortraits;
	int m_nCustomSoundSetIndex;
	int m_nCustomSoundIndex;
	int m_nCharacterIndex;
	int m_nPrerollTopIndex;
	CStringList* m_pCharacters;
	int m_bImported;
	CStringList* m_pSounds;
	CVidFont m_preLoadFontRealms;
	CVidFont m_preLoadFontStnSml;
	CVidFont m_preLoadFontTool;
	unsigned __int8 m_nCurrentSpellLevel;
	int m_nExtraMageSpells;
	CCreatureFileHeader* m_pOldBaseStats;
	CDerivedStats* m_pOldDerivedStats;
	int m_nOldConHPBonus;
	unsigned __int8 m_nCurrentSpellLevelChoice;
	unsigned __int8 m_nCurrentSpellLevelChoiceMax;
	unsigned __int16 m_nImportedCharHPs;
	unsigned __int16 m_nImportedCharConBonus;
	unsigned __int8 m_nImportedDualClass;
	unsigned int m_nImportedDualKit;
	int m_nImportedDualReactivated;
	unsigned __int8 m_byImportedCharVersion;
	__int16 m_nSelectedSpecialistSpells;
	__int16 m_nMemorizedSpecialistSpells;
	int m_nTotalKits;
	unsigned __int16 m_nHatedRaces;
	importStateType m_importState;
	unsigned int m_strDefaultHelpString;
	unsigned __int8 m_bUpdatedHelp;
	unsigned int m_strCurrentHelpString;
	int m_bGaveExtraXP;
	int m_nExtraXP;
	CString m_sImportCharName;
	int m_nErrorState;
	unsigned int m_strErrorText;
	int m_nNumErrorButtons;
	Array<unsigned int,3> m_strErrorButtonText;
	Array<int,9> m_OldMageSpells;
	Array<int,7> m_OldPriestSpells;
	CTypedPtrArray<CPtrArray,char> m_aBaseProficiencySlots;
	CCreatureFileHeader* m_pTempBaseStats;
	CDerivedStats* m_pTempDerivedStats;
	Array<int,7> m_storedSkillPoints;
	int m_bAddInactiveAbilities;
	CStringList* m_szCharInfoStorage;
	int m_nSpellcasterLevel;
	int m_nNumLevelUpAbilities;
	unsigned __int8 m_nCurrentAbilityLevelChoice;
	int m_bFinishedAbilitySelection;
	CGameAbilityList* m_lstLevelUpAbilitiesList;
	Array<unsigned __int8,24> m_lstSelectedAbility;
	unsigned __int8 m_nSelectedAbilityInd;
	int m_nDualClass;
	int m_nSpecialization;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenCreateParty : CBaldurEngine
{
	Array<CKeyInfo,5> m_pVirtualKeys;
	int m_bCtrlKeyDown;
	Array<int,5> m_pVirtualKeysFlags;
	int m_nEngineState;
	int m_firstCall;
	CVidFont m_preloadFontStnSml;
	int m_nCharacterSlot;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenDLC : CBaldurEngine
{
	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	int m_bExitProgram;
	CPtrList m_lPopupStack;
	unsigned int m_dwErrorTextId;
	unsigned int m_dwErrorState;
	int m_nNumErrorButtons;
	Array<unsigned int,3> m_strErrorButtonText;
	CTypedPtrList<CPtrList,CGameOptions*> m_lOptionsStack;
	int m_bSpriteMirror;
	unsigned __int8 m_bCtrlKeyDown;
	CVidFont m_preLoadFontRealms;
	CVidFont m_preLoadFontStnSml;
	int m_nNumDLC;
	int m_nCurrentDLC;
	int m_nDlcState;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenInventory : CBaldurEngine
{
	CItem* m_pTempItem;
	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	unsigned __int8 m_bCtrlKeyDown;
	CPoint m_cLastMousePosition;
	int m_nTopGroundItem;
	Array<int,6> m_nGroundPile;
	Array<int,6> m_bGroundPileQueried;
	int m_nErrorState;
	unsigned int m_strErrorText;
	int m_nNumErrorButtons;
	int m_nLastSwapPortrait;
	unsigned int m_dwLastSwapButton;
	int m_bMultiPlayerViewable;
	CResRef m_cCheckLearnSpellRes;
	int m_nCheckLearnSpellCountDown;
	int m_bDroppedItemInHand;
	unsigned __int8 m_bPauseWarningDisplayed;
	CVidFont m_preLoadFontRealms;
	CVidFont m_preLoadFontStnSml;
	CVidFont m_preLoadFontTool;
	unsigned int m_stSpellsDisabled;
	int m_bLearnSpellFailed;
	unsigned int m_strLearnSpellFailedReason;
	int m_bPauseState;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenJournal : CBaldurEngine
{
	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	int m_bShiftKeyDown;
	int m_bCapsLockKeyOn;
	unsigned __int8 m_bCtrlKeyDown;
	CResRef m_oldMosaic;
	CResRef m_oldFont;
	unsigned int m_rgbOldText;
	unsigned int m_rgbOldBackground;
	CVidFont m_preLoadFontRealms;
	CVidFont m_preLoadFontTool;
	int m_bPauseState;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenLoad : CBaldurEngine
{
	Array<CKeyInfo,5> m_pVirtualKeys;
	Array<int,5> m_pVirtualKeysFlags;
	unsigned __int8 m_bCtrlKeyDown;
	int m_nTopGameSlot;
	int m_nNumGameSlots;
	int m_nEngineState;
	CTypedPtrArray<CPtrArray,CSaveGameSlot*> m_aGameSlots;
	int m_nCurrentGameSlot;
	unsigned int m_strErrorText;
	Array<unsigned int,3> m_strErrorButtonText;
	int m_nNumErrorButtons;
	CPtrList m_lPopupStack;
	int m_nMaxSlotNumber;
	CVidFont m_preLoadFontRealms;
	CVidFont m_preLoadFontStnSml;
	int m_bHideSoA;
	int m_bHideToB;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenMultiPlayer : CBaldurEngine
{
	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	int m_bCtrlKeyDown;
	int m_bShiftKeyDown;
	int m_bCapsLockKeyOn;
	CPtrList m_lPopupStack;
	int m_nModifiedCharacterSlot;
	int m_nEngineState;
	int m_nChatMessageCount;
	int m_nPermissionsChatMessageCount;
	int m_nKickPlayerSlot;
	int m_nCharacterSlot;
	unsigned __int8 m_bMultiplayerStartup;
	int m_bLastLockAllowInput;
	CVidFont m_preLoadFontRealms;
	CVidFont m_preLoadFontStnSml;
	CVidFont m_preLoadFontTool;
	unsigned __int8 m_bSentGameDemand;
	Array<CString,6> m_playerNames;
	Array<CString,6> m_characterNames;
	Array<CString,6> m_characterPortrait;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenOptions : CBaldurEngine
{
	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	int m_bExitProgram;
	CPtrList m_lPopupStack;
	unsigned int m_dwErrorTextId;
	unsigned int m_dwErrorState;
	int m_nNumErrorButtons;
	Array<unsigned int,3> m_strErrorButtonText;
	CTypedPtrList<CPtrList,CGameOptions*> m_lOptionsStack;
	int m_bSpriteMirror;
	unsigned __int8 m_bCtrlKeyDown;
	CVidFont m_preLoadFontRealms;
	CVidFont m_preLoadFontStnSml;
	unsigned __int8 m_bFullScreenOptions;
	unsigned __int8 m_bReQuietSound;
	int m_nTopKeymap;
	int m_nSelectedKeymap;
	int m_nNumKeymapEntries;
	int m_nKeymapEditIndex;
	char* m_cKeymapEditSection;
	char* m_cKeymapEditConflictSection;
	char* m_cKeymapEditConflictKey;
	int m_nKeymapEditConflictIndex;
	char m_cKeymapEditConflictValue;
	int m_bPauseState;
	int m_nEngineState;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenSave : CBaldurEngine
{
	int m_bQuitGameSave;
	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	int m_bShiftKeyDown;
	int m_bCapsLockKeyOn;
	int m_nTopGameSlot;
	int m_nNumGameSlots;
	int m_nEngineState;
	CTypedPtrArray<CPtrArray,CSaveGameSlot*> m_aGameSlots;
	CPtrList m_lPopupStack;
	unsigned int m_strErrorText;
	Array<unsigned int,3> m_strErrorButtonText;
	int m_nNumErrorButtons;
	int m_nCurrentGameSlot;
	int m_nMaxSlotNumber;
	unsigned __int8 m_bCtrlKeyDown;
	CVidFont m_preLoadFontRealms;
	CVidFont m_preLoadFontStnSml;
	int m_bPauseState;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenStart : CBaldurEngine
{
	int m_bStartMusic;
	int m_bExitProgram;
	Array<CKeyInfo,5> m_pVirtualKeys;
	int m_bCtrlKeyDown;
	Array<int,5> m_pVirtualKeysFlags;
	unsigned __int8 m_bMovieOn;
	int m_nEngineState;
	int m_firstCall;
	CPtrList m_lPopupStack;
	int m_nErrorState;
	unsigned int m_strErrorText;
	int m_nNumErrorButtons;
	Array<unsigned int,4> m_strErrorButtonText;
	int m_bPlayEndCredits;
	int m_bSplashScreens;
	int m_bNeedCDCheck;
	int m_nCurrentDLC;
	int m_nNumDLC;
	int m_nLastImageUpdate;
	int m_nDlcState;
	CVidFont m_preloadFontStnSml;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CScreenStore : CBaldurEngine
{
	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	unsigned __int8 m_bCtrlKeyDown;
	unsigned __int8 m_bShiftKeyDown;
	int m_bCapsLockKeyOn;
	int m_nTopGroupItem;
	CPtrList m_lGroupItems;
	int m_nTopStoreItem;
	CPtrList m_lStoreItems;
	int m_nTopSpellItem;
	CPtrList m_lSpellItems;
	int m_nTopIdentifyItem;
	CPtrList m_lIdentifyItems;
	int m_nTopDrinkItem;
	CResRef m_cResStore;
	CResRef m_cResBag;
	Array<unsigned int,4> m_adwButtonPanelId;
	CStore* m_pStore;
	CStore* m_pBag;
	int m_nStoreCost;
	int m_nGroupCost;
	unsigned int m_dwSpellCost;
	unsigned int m_dwIdentifyCost;
	unsigned int m_dwRoomType;
	CAIObjectType m_cAIProprietor;
	CAIObjectType m_cAICustomer;
	unsigned int m_dwDonationAmount;
	int m_nDrinkRumorIndex;
	int m_nDonateRumorIndex;
	CPtrList m_lPopupStack;
	CItem* m_pHistoryItem;
	int m_bHistoryUseEnabled;
	CResRef m_cResInfoSpell;
	int m_nChatMessageCount;
	int m_nErrorState;
	unsigned int m_strErrorText;
	int m_nNumErrorButtons;
	Array<unsigned int,3> m_strErrorButtonText;
	unsigned __int8 m_nCharisma;
	CVidFont m_preLoadFontRealms;
	CVidFont m_preLoadFontStnSml;
	CVidFont m_preLoadFontTool;
	unsigned int m_nRequesterAmount;
	int m_nRequesterButtonId;
	int m_bStoreIndex;
	int m_bStoreStarted;
	int m_nBagCount;
	float m_fPanStorage;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CBaldurProjector : CBaldurEngine
{
	CResWebm* m_pMovie;
	int bStretchToScreen;
	CFile* mve_file;
	int m_deactivateEngine;
	Array<CKeyInfo,2> m_pVirtualKeys;
	Array<int,2> m_pVirtualKeysFlags;
	CTypedPtrList<CPtrList,CResRef*> m_movieResRef;
	unsigned __int8 m_bSelectEngine;
	unsigned __int8 m_bFirstRender;
	void* m_pCodec;
	int m_nFirstFrameTime;
	CSound m_cSoundOverride;
	CResRef m_cSubtitles;
	CVidFont m_vidFont;
	int m_bDisplayTOBMovie;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CResCell : CRes
{
	void* pUncompressedData;
	unsigned int nUncompressedSize;
	bamHeader_st* m_pBamHeader;
	BAMHEADERV2* m_pBamHeaderV2;
	MOSAICQUAD* m_pQuads;
	frameTableEntry_st* m_pFrames;
	sequenceTableEntry_st* m_pSequences;
	unsigned __int16* m_pFrameList;
	unsigned __int16 m_nFrameList;
	tagRGBQUAD* m_pPalette;
	int m_bParsing;

	virtual bool Parse(void* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void Dump()
	{
	}

	virtual CResRef* GetResRef()
	{
		return *(CResRef**)nullptr;
	}
};

struct CVidCell : CVidImage, CResHelper<CResCell,1000>
{
	__int16 m_nCurrentFrame;
	unsigned __int16 m_nCurrentSequence;
	int m_nAnimType;
	int m_bPaletteChanged;
	frameTableEntry_st* m_pFrame;
	unsigned __int8 m_bShadowOn;

	virtual int FrameAdvance()
	{
		return *(int*)nullptr;
	}

	virtual int Render(unsigned int* _0, int _1, int _2, int _3, const CRect* _4, unsigned int _5, const CPoint* _6)
	{
		return *(int*)nullptr;
	}

	virtual int Render(int _0, int _1, const CRect* _2, CVidPoly* _3, int _4, unsigned int _5, int _6)
	{
		return *(int*)nullptr;
	}

	virtual void StoreBackground(int _0, int _1, const CRect* _2, CRect* _3, unsigned __int8 _4)
	{
	}

	virtual int GetFrame()
	{
		return *(int*)nullptr;
	}
};

struct CScreenWorldMap : CBaldurEngine
{
	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	unsigned __int8 m_bCtrlKeyDown;
	unsigned __int8 m_bShiftKeyDown;
	int m_bCapsLockKeyOn;
	CPtrList m_lPopupStack;
	CSize m_mapSize;
	int m_nEngineState;
	CPoint m_ptMapView;
	CVidMosaic m_vmMap;
	CVidCell m_vcAreas;
	CVidCell m_vcMarker;
	CVidFont m_vfLabel;
	Array<tagRGBQUAD,256> m_aPalette;
	unsigned int m_wAreaForeground;
	unsigned int m_nHighlightArea;
	unsigned int m_nSelectedArea;
	int m_bSelectedReachable;
	int m_bOverSelectedArea;
	CPoint m_ptMapStartMousePos;
	CPoint m_ptMapStartView;
	int m_bMapDragging;
	CGameArea* m_pCurrentArea;
	int m_nLeaderSprite;
	int m_nLeavingEdge;
	unsigned int m_nCurrentLink;
	CResRef m_cResCurrentArea;
	CUIControlTextDisplay* m_pChatDisplay;
	int m_nChatMessageCount;
	unsigned __int8 m_bInControl;
	unsigned __int8 m_bClickedArea;
	int m_nCurrentSong;
	unsigned int m_nToolTip;
	CVidFont m_preLoadFontRealms;
	CVidFont m_preLoadFontTool;
	unsigned __int8 m_nScrollState;
	CResRef m_rForceRandomEncounter;
	CString m_sForcedEncounterEntry;
	int m_bFontDropShadow;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CGameContainer : CGameAIBase
{
	CRect m_rBounding;
	CPoint* m_pPolygon;
	unsigned __int16 m_nPolygon;
	CTypedPtrList<CPtrList,CItem*> m_lstItems;
	unsigned __int16 m_containerType;
	CPoint m_ptWalkToUse;
	Array<CVidCell,3> m_pileVidCell;
	unsigned __int8 m_nPileVidCell;
	unsigned __int8 m_bDeleteMe;
	Array<unsigned __int8,8> m_scriptRes;
	unsigned __int16 m_lockDifficulty;
	unsigned int m_dwFlags;
	unsigned __int16 m_trapDetectionDifficulty;
	unsigned __int16 m_trapRemovalDifficulty;
	unsigned __int16 m_trapActivated;
	unsigned __int16 m_trapDetected;
	CPoint m_posTrapOrigin;
	unsigned __int16 m_triggerRange;
	Array<char,32> m_ownedBy;
	CResRef m_keyType;
	unsigned int m_breakDifficulty;
	__int16 m_drawPoly;
	unsigned int m_strNotPickable;
	int m_bJustCreated;
	int m_bNeedUpdate;
	unsigned __int8 m_probabilityRoll;

	virtual void CGameObject_Destructor()
	{
	}

	virtual unsigned __int8 GetObjectType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void AIUpdate()
	{
	}

	virtual const CAIObjectType* GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void GetNextWaypoint(CPoint* _0)
	{
	}

	virtual __POSITION* GetVertListPos()
	{
		return *(__POSITION**)nullptr;
	}

	virtual unsigned __int8 GetVertListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionButton(const CPoint* _0)
	{
	}

	virtual void OnFormationButton(const CPoint* _0)
	{
	}

	virtual void RemoveFromArea()
	{
	}

	virtual void Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void SetCursor(int _0)
	{
	}

	virtual void SetTarget(CPoint _0, int _1)
	{
	}

	virtual void SetVertListPos(__POSITION* _0)
	{
	}

	virtual int EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}

	virtual void ClearActions(int _0)
	{
	}

	virtual void UpdateTarget(CGameObject* _0)
	{
	}

	virtual void AddAction(const CAIAction* _0)
	{
	}

	virtual void AddEffect(CGameEffect* _0, unsigned __int8 _1, int _2, int _3)
	{
	}

	virtual void ClearAI(unsigned __int8 _0)
	{
	}

	virtual void DoAction()
	{
	}

	virtual __int16 ExecuteAction()
	{
		return *(__int16*)nullptr;
	}

	virtual void InsertAction(const CAIAction* _0)
	{
	}

	virtual void ProcessAI()
	{
	}

	virtual void SetCurrAction(const CAIAction* _0)
	{
	}

	virtual void SetScript(__int16 _0, CAIScript* _1)
	{
	}

	virtual __int16 GetVisualRange()
	{
		return *(__int16*)nullptr;
	}

	virtual __int16 GetAttackRange()
	{
		return *(__int16*)nullptr;
	}

	virtual const unsigned __int8* GetVisibleTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual const unsigned __int8* GetTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual int QuickDecode(CAITrigger* _0, CGameSprite** _1)
	{
		return *(int*)nullptr;
	}

	virtual __int16 GetHelpRange()
	{
		return *(__int16*)nullptr;
	}

	virtual void ApplyTriggers()
	{
	}

	virtual void AutoPause(unsigned int _0)
	{
	}

	virtual int GetCanSeeInvisible()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionRemoval(CAIAction* _0)
	{
	}

	virtual CRect* GetBounding()
	{
		return *(CRect**)nullptr;
	}

	virtual CPoint* GetPoly()
	{
		return *(CPoint**)nullptr;
	}

	virtual __int16 GetNPoly()
	{
		return *(__int16*)nullptr;
	}
};

struct CCacheStatus
{
	int m_nDrawnBars;
	int m_nScreensDrawn;
	int m_bDemandedResources;
	int m_bTravelScreen;
	int m_nProgressBarCaption;
	int m_nParchmentCaption;
	unsigned int m_dwLastUpdateTickCount;
	int m_nTimeToNewHint;
	int m_nCurrentHint;
	int m_nCurrentHintRef;
	int m_bWaiting;
	CVidFont m_vidFont;
	CVidFont m_initialsFont;
	CVidFont m_parchmentFont;
	CVidMosaic m_titleBar;
	CVidCell m_skullAnimating;
	CVidCell m_progressBar;
	int m_nAnimationFrame;
	int m_nAnimationDirection;
	int m_bActivateEngine;
};

struct CBaldurChitin : CChitin
{
	CInfCursor* m_pObjectCursor;
	CInfGame* m_pObjectGame;
	CDungeonMaster* m_pEngineDM;
	CBaldurProjector* m_pEngineProjector;
	CScreenAI* m_pEngineAI;
	CScreenCharacter* m_pEngineCharacter;
	CScreenCreateChar* m_pEngineCreateChar;
	CScreenCreateParty* m_pEngineCreateParty;
	CScreenInventory* m_pEngineInventory;
	CScreenJournal* m_pEngineJournal;
	CScreenLoad* m_pEngineLoad;
	CScreenMap* m_pEngineMap;
	CScreenOptions* m_pEngineOptions;
	CScreenPriestSpell* m_pEnginePriestSpell;
	CScreenSave* m_pEngineSave;
	CScreenStart* m_pEngineStart;
	CScreenWizSpell* m_pEngineWizSpell;
	CScreenWorld* m_pEngineWorld;
	CScreenStore* m_pEngineStore;
	CScreenMultiPlayer* m_pEngineMultiPlayer;
	CScreenConnection* m_pEngineConnection;
	CScreenWorldMap* m_pEngineWorldMap;
	CScreenChapter* m_pEngineChapter;
	CScreenMovies* m_pEngineMovies;
	CScreenDLC* m_pEngineDLC;
	CTlkTable m_cTlkTable;
	CCacheStatus m_cCachingStatus;
	CScriptCache m_scriptCache;
	CBaldurMessage m_cBaldurMessage;
	CMessageHandler m_cMessageHandler;
	int m_bFontRectOutline;
	unsigned __int8 m_bCDScanDone;
	unsigned __int8 m_bCDFoundDrive;
	CString m_sCDDriveName;
	unsigned __int8 m_bCDMediaInDrive;
	unsigned __int8 m_bCDFoundBaldurCD;
	unsigned __int8 m_bIsAutoStarting;
	int m_bDropPanels;
	int m_bDropCaps;
	int m_bDisableMovies;
	int m_bStartConfig;
	int m_bSuperSpeedAI;
	int m_bFirstRun;
	int m_nInstallType;
	int m_bUseNewGui;
	CVidFont m_preLoadedFont;
	CVidMosaic m_tiledBackground;

	virtual void SynchronousUpdate()
	{
	}

	virtual void SetupPanels()
	{
	}

	virtual unsigned int GetIDSInvalidVideoMode()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetIDSOpenGLDll()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetIDSExclusiveMode()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetIDSChoosePixelFormat()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetIDSSetPixelFormat()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetIDSSetGameResolution()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetIDSSetGameBitDepth()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetIDSBadDeskTopBitDepth()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int GetIDSWindowsFonts()
	{
		return *(unsigned int*)nullptr;
	}

	virtual CRes* AllocResObject(int _0)
	{
		return *(CRes**)nullptr;
	}

	virtual const CString* GetIconRes()
	{
		return *(const CString**)nullptr;
	}

	virtual void GetScreenShotFilePrefix(CString* _0)
	{
	}

	virtual int FontRectOutline()
	{
		return *(int*)nullptr;
	}

	virtual int InitializeServices()
	{
		return *(int*)nullptr;
	}

	virtual void SetProgressBar(unsigned __int8 _0, int _1, int _2, int _3, unsigned __int8 _4, int _5, unsigned __int8 _6, int _7, unsigned __int8 _8, unsigned __int8 _9, unsigned int _10)
	{
	}

	virtual void SetProgressBarActivateEngine(int _0)
	{
	}

	virtual void BroadcastMultiplayerProgressBarInfo()
	{
	}

	virtual void SetCDSwitchStatus(unsigned __int8 _0, unsigned __int8 _1, unsigned __int8 _2, const CString* _3, unsigned __int8 _4, unsigned __int8 _5, unsigned __int8 _6)
	{
	}

	virtual void SetCDSwitchActivateEngine(int _0)
	{
	}

	virtual void OnMultiplayerSessionOpen(CString* _0, CString* _1, CString* _2)
	{
	}

	virtual void OnMultiplayerSessionToClose()
	{
	}

	virtual void OnMultiplayerSessionClose()
	{
	}

	virtual void OnMultiplayerPlayerJoin(int _0, const CString* _1)
	{
	}

	virtual void OnMultiplayerPlayerVisible(int _0)
	{
	}

	virtual void OnMultiplayerPlayerLeave(int _0, const CString* _1)
	{
	}

	virtual int MessageCallback(unsigned __int8* _0, unsigned int _1)
	{
		return *(int*)nullptr;
	}

	virtual unsigned __int8 GetGamespyResponse(unsigned __int8 _0, unsigned __int8** _1, unsigned int* _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AsynchronousUpdate(unsigned int _0, unsigned int _1, unsigned int _2, unsigned int _3, unsigned int _4)
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual void ShutDown(int _0, const char* _1, const char* _2)
	{
	}

	virtual const char* GetKeyFileName()
	{
		return *(const char**)nullptr;
	}

	virtual unsigned __int8 GetNumberSoundChannels()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual int GetMovieVolume()
	{
		return *(int*)nullptr;
	}

	virtual void LoadOptions()
	{
	}

	virtual void PreLoadFonts()
	{
	}

	virtual void SetSoundVolumes()
	{
	}

	virtual unsigned __int16 GetMultiplayerGameSpyPort()
	{
		return *(unsigned __int16*)nullptr;
	}

	virtual unsigned __int16 GetMultiplayerDirectPlayPort()
	{
		return *(unsigned __int16*)nullptr;
	}

	virtual void SetRenderCount(unsigned __int8 _0)
	{
	}

	virtual int ConfirmQuit()
	{
		return *(int*)nullptr;
	}

	virtual void GetGameSpyGameName(CString* _0)
	{
	}

	virtual void GetGameSpyCode(CString* _0)
	{
	}

	virtual void GetPanicCDStrings(CString* _0, CString* _1, CString* _2)
	{
	}

	virtual void OnMixerInitialize()
	{
	}

	virtual int Is3DSound(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetEAXActive()
	{
		return *(int*)nullptr;
	}

	virtual void RedrawScreen()
	{
	}

	virtual unsigned __int8 GetSoundEnvironment(CString _0, unsigned int* _1, float* _2, float* _3, float* _4, float* _5)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CutsceneModeActive()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void ShutDown(int _0, char* _1, const char* _2)
	{
	}

	virtual void UnloadFonts()
	{
	}
};

struct CInfButtonSettings
{
	int m_bEnabled;
	int m_bShowIcon;
	int m_bOverrideRender;
	int m_nButtonFrame;
	int m_nButtonSelectedFrame;
	CVidCell m_vcIcon;
	CVidCell m_vcLauncherIcon;
	int m_bSelectable;
	int m_bSelected;
	int m_bHighlighted;
	int m_itemCount;
	int m_itemCharge;
	int m_bGreyOut;
};

typedef int (*type_CInfButtonArray_SetState)(CInfButtonArray* pThis, int nState);
extern type_CInfButtonArray_SetState p_CInfButtonArray_SetState;

typedef void (*type_CInfButtonArray_SetQuickSlot)(CButtonData* pButtonData, int nButton, int nType);
extern type_CInfButtonArray_SetQuickSlot p_CInfButtonArray_SetQuickSlot;

struct CInfButtonArray
{
	Array<CInfButtonSettings,12> m_buttonArray;
	Array<int,12> m_configIcons;
	Array<int,12> m_buttonTypes;
	int m_buttonToConfigure;
	int m_nState;
	int m_nLastState;
	int m_bWayPointsOn;
	CVidCell m_vcButtons;
	CVidCell m_vcActions;
	int m_quickButtonToConfigure;
	int m_nListStartIndex;
	CButtonType m_nSelectedButton;
	int m_nFirstMageSpellIndex;
	int m_bToggleButtonCleric;

	int SetState(int nState)
	{
		return p_CInfButtonArray_SetState(this, nState);
	}

	static void SetQuickSlot(CButtonData* pButtonData, int nButton, int nType)
	{
		p_CInfButtonArray_SetQuickSlot(pButtonData, nButton, nType);
	}
};

struct CInfToolTip : CVidCell
{
	CString m_sText;
	CRect m_rSource;
	int m_bUseSourceRect;
	CVidFont m_textFont;
	CSound m_openSnd;

	virtual int FrameAdvance()
	{
		return *(int*)nullptr;
	}

	virtual int Render(unsigned int* _0, int _1, int _2, int _3, const CRect* _4, unsigned int _5, const CPoint* _6)
	{
		return *(int*)nullptr;
	}

	virtual int Render(int _0, int _1, const CRect* _2, CVidPoly* _3, int _4, unsigned int _5, int _6)
	{
		return *(int*)nullptr;
	}

	virtual void StoreBackground(int _0, int _1, const CRect* _2, CRect* _3, unsigned __int8 _4)
	{
	}

	virtual int GetFrame()
	{
		return *(int*)nullptr;
	}
};

struct CInfCursor
{
	int bVisible;
	CVidCell vcCursors;
	CVidCell vcArrow;
	CVidCell vcCustom;
	CInfToolTip vcToolTip;
	unsigned int nAnimationCounter;
	int nAnimationSpeed;
	int nCurrentCursor;
	int nDirection;
	int nState;
	unsigned __int8 bAnimatingCustom;
};

struct CPortraitIcon
{
	int icon;
	int frame;
	CVidCell bam;
};

struct CVidCellFont : CVidCell
{
	virtual int FrameAdvance()
	{
		return *(int*)nullptr;
	}

	virtual int Render(unsigned int* _0, int _1, int _2, int _3, const CRect* _4, unsigned int _5, const CPoint* _6)
	{
		return *(int*)nullptr;
	}

	virtual int Render(int _0, int _1, const CRect* _2, CVidPoly* _3, int _4, unsigned int _5, int _6)
	{
		return *(int*)nullptr;
	}

	virtual void StoreBackground(int _0, int _1, const CRect* _2, CRect* _3, unsigned __int8 _4)
	{
	}

	virtual int GetFrame()
	{
		return *(int*)nullptr;
	}
};

struct CResBitmap : CRes
{
	unsigned __int8* m_pDataDecompressed;
	int texture;
	int nColors;
	int nXWords;
	unsigned __int8* m_pData;
	tagBITMAPFILEHEADER* pBitmapFileHeader;
	tagBITMAPINFOHEADER* pBitmapInfoHeader;
	tagRGBQUAD* pColorTable;

	virtual bool Parse(void* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void Dump()
	{
	}

	virtual CResRef* GetResRef()
	{
		return *(CResRef**)nullptr;
	}
};

struct CVidBitmap : CVidImage, CResHelper<CResBitmap,1>
{
	__int16 m_nBitCount;
	CString m_szResFileName;
};

struct CScreenAI : CBaldurEngine
{
	CVidBitmap m_bmpScreen;
	C2DArray m_tSplashScreens;
	__int16 m_nSplashScreen;
	int m_nSplashTimer;
	int m_bInteractiveDemoQuit;
	unsigned __int8 m_nBmpDraw;
	Array<CKeyInfo,5> m_pVirtualKeys;
	Array<int,5> m_pVirtualKeysFlags;
	unsigned __int8 m_bCtrlKeyDown;

	virtual void CObject_Destructor()
	{
	}

	virtual void InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void RequestPause()
	{
	}

	virtual void EngineActivated()
	{
	}

	virtual void EngineDeactivated()
	{
	}

	virtual void EngineDestroyed()
	{
	}

	virtual void EngineInitialized()
	{
	}

	virtual void EngineGameInit()
	{
	}

	virtual void EngineGameUninit()
	{
	}

	virtual void SelectEngine(CWarp* _0)
	{
	}

	virtual bool OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyShift(int _0)
	{
	}

	virtual int GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyMenu(int _0)
	{
	}

	virtual int CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseMove(CPoint _0)
	{
	}

	virtual int CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void OnLButtonDown(CPoint _0)
	{
	}

	virtual void OnLButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void OnMButtonDown(CPoint _0)
	{
	}

	virtual void OnMButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void OnRButtonDown(CPoint _0)
	{
	}

	virtual void OnRButtonUp(CPoint _0)
	{
	}

	virtual int CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void OnKeyDown(int _0)
	{
	}

	virtual void OnKeyUp(int _0)
	{
	}

	virtual void OnTextInput(const char* _0)
	{
	}

	virtual void WindowResized(int _0, int _1)
	{
	}

	virtual void OnLowMemory()
	{
	}

	virtual void EnableEditKeys(__int16 _0)
	{
	}

	virtual void DisableEditKeys()
	{
	}

	virtual void ResetControls()
	{
	}

	virtual void TimerAsynchronousUpdate()
	{
	}

	virtual void TimerSynchronousUpdate()
	{
	}

	virtual void TimerUpdate()
	{
	}

	virtual void RenderUI()
	{
	}

	virtual int GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void SetSelectedCharacter(int _0)
	{
	}

	virtual void SetPickedCharacter(int _0)
	{
	}

	virtual void OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void OnRestButtonClick()
	{
	}

	virtual void UpdateGroundItems()
	{
	}

	virtual void UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void CheckEnableLeftPanel()
	{
	}

	virtual void EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void CancelEngine()
	{
	}

	virtual void UpdateCharacterStatus(int _0)
	{
	}

	virtual void UpdatePartyGoldStatus()
	{
	}

	virtual void GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CInfinity
{
	Array<CInfTileSet*,5> pTileSets;
	CResWED* pResWED;
	CVRamPool* pVRPool;
	CVidMode* pVidMode;
	int bUseDestSrc;
	int bRefreshVRamRect;
	int bInitialized;
	int bWEDDemanded;
	int nOffsetX;
	int nOffsetY;
	int nTilesX;
	int nTilesY;
	int nNewX;
	int nNewY;
	CRect rViewPortNotZoomed;
	CRect rViewPort;
	CRect rVRamRect;
	CRect rRequestRect;
	int nVisibleTilesX;
	int nVisibleTilesY;
	int nAreaX;
	int nAreaY;
	int nCurrentTileX;
	int nCurrentTileY;
	int nCurrentX;
	int nCurrentY;
	int nSub1XOffset;
	int nSub1YOffset;
	int nSub2XOffset;
	int nSub2YOffset;
	int nSub3XOffset;
	int nSub3YOffset;
	int nSub4XOffset;
	int nSub4YOffset;
	CSound sndThunder;
	int nCurrentLightningFrequency;
	int nNextLightningFrequency;
	int nNewLightningFrequency;
	int nCurrentRainLevel;
	int nNextRainLevel;
	int nCurrentSnowLevel;
	int nCurrentWindLevel;
	int nCurrentFogLevel;
	int nNextWindLevel;
	int nCurrentTimeOfDay;
	int nTimeToNextThunder;
	int nThunderLength;
	int bRenderCallLightning;
	int nRenderLightningTimer;
	CPoint cLightningPoint;
	CVidCell m_glowVidCell;
	CTypedPtrList<CPtrList,CAOEEntry*> m_lAOE;
	std::vector<unsigned char*,std::allocator<unsigned char*>> m_RasterizedPolys;
	std::vector<std::vector<WED_PolyPoint_st,std::allocator<WED_PolyPoint_st>>,std::allocator<std::vector<WED_PolyPoint_st,std::allocator<WED_PolyPoint_st>>>> m_DownsampledPolys;
	unsigned __int16 m_areaType;
	unsigned __int8 m_renderDayNightCode;
	unsigned __int8 m_oldRenderDayNightCode;
	unsigned __int8 m_dayLightIntensity;
	unsigned __int8 m_requestDayNightCode;
	unsigned __int8 m_oldRequestDualTileCode;
	unsigned __int8 m_bResizedViewPort;
	unsigned int m_nLastTickCount;
	CPoint m_ptCurrentPosExact;
	__int16 m_autoScrollSpeed;
	CPoint m_ptScrollDest;
	int m_nScrollAttempts;
	int m_nOldScrollState;
	unsigned __int8 m_nScrollDelay;
	unsigned __int8 m_bMovieBroadcast;
	int m_bStartLightning;
	int m_bStopLightning;
	unsigned __int8 m_lightningStrikeProb;
	unsigned int m_rgbRainColor;
	unsigned int m_rgbLightningGlobalLighting;
	unsigned int m_rgbOverCastGlobalLighting;
	unsigned int m_rgbGlobalLighting;
	unsigned int m_rgbTimeOfDayGlobalLighting;
	unsigned int m_rgbTimeOfDayRainColor;
	int m_updateListenPosition;
	CGameArea* m_pArea;
	CVidBitmap m_vbMessageScreen;
	unsigned int m_strrefMessage;
	int m_bScreenShake;
	CPoint m_screenShakeDelta;
	CPoint m_screenShakeDecrease;
	float m_fZoomSaved;
	float m_fZoom;
	float m_fStoredZoom;
	int m_bZoomEnabled;
	int m_bZooming;
};

typedef void (*type_CInfGame_SetState)(CInfGame* pThis, __int16 state, bool allowDead);
extern type_CInfGame_SetState p_CInfGame_SetState;

typedef void (*type_CInfGame_SetIconIndex)(CInfGame* pThis, unsigned __int8 iconIndex);
extern type_CInfGame_SetIconIndex p_CInfGame_SetIconIndex;

struct CInfGame
{
	CRuleTables m_ruleTables;
	CTimerWorld m_worldTime;
	int m_bGameLoaded;
	unsigned __int8 m_bInLoadGame;
	unsigned __int8 m_bInLoadArea;
	unsigned __int8 m_bInIniSpawn;
	unsigned int m_nUniqueAreaID;
	unsigned int m_nAreaFirstObject;
	unsigned __int8 m_bFromNewGame;
	unsigned __int8 m_bInDestroyGame;
	unsigned __int8 m_bAnotherPlayerJoinedGame;
	unsigned __int8 m_bInAreaTransition;
	int m_bStartedDeathSequence;
	CTypedPtrList<CPtrList,long*> m_lstTargetIds;
	CTypedPtrList<CPtrList,CPoint*> m_lstTargetPts;
	__int16 m_nState;
	int m_iconCount;
	unsigned __int8 m_iconIndex;
	CResRef m_iconResRef;
	unsigned __int8 m_tempCursor;
	int m_iContainer;
	int m_iContainerSprite;
	int m_bAllowTargetDead;
	CGamePermission m_singlePlayerPermissions;
	CMultiplayerSettings m_multiPlayerSettings;
	CMachineStates m_machineStates;
	CInfButtonArray m_cButtonArray;
	CVRamPool m_cVRamPool;
	int m_bSaveScreen;
	CString m_sSaveScreenArea;
	CVidBitmap m_rgbMasterBitmap;
	CGameObjectArray m_objectsArray;
	CGameRemoteObjectArray m_remoteObjectsArray;
	unsigned __int8 m_visibleArea;
	unsigned __int8 m_bPlayerScriptStyle;
	Array<CGameArea*,12> m_gameAreas;
	CGameArea* m_pGameAreaMaster;
	Array<int,6> m_characters;
	Array<int,6> m_charactersPortrait;
	__int16 m_nCharacters;
	CTypedPtrList<CPtrList,long*> m_lstGlobalCreatures;
	CTypedPtrArray<CPtrArray,long*> m_characterOverflow;
	__int16 m_nCharacterOverflowCount;
	__int16 m_nReputation;
	CPathSearch* m_pathSearch;
	CPathNode** m_listGrid;
	CPathNode** m_arrayOpenList;
	CAIGroup m_group;
	CTypedPtrList<CPtrList,long*> m_allies;
	CTypedPtrList<CPtrList,long*> m_familiars;
	Array<Array<unsigned __int8,8>,9> m_resrefFamiliarsDefault;
	Array<Array<CTypedPtrList<CPtrList,CResRef*>,9>,9> m_resrefFamiliars;
	int m_bFamiliarBlock;
	unsigned int m_nFamiliarSummoner;
	CString m_sSaveGame;
	int m_bAllowCutSceneBreak;
	CGameSave m_gameSave;
	CGameOptions m_options;
	CGameJournal m_cGameJournal;
	CWorldMap m_cWorldMap;
	Array<int,600> m_pKeymap;
	Array<int,600> m_pKeymapFlags;
	CVariableHash m_variables;
	CVariableHash m_namedCreatures;
	STR_RES m_soundNeedParty;
	STR_RES m_soundAreaTransitionRefused;
	unsigned __int8 m_bForceDither;
	CVidCell m_vcLocator;
	CTypedPtrList<CPtrList,CSearchRequest*> m_searchRequests;
	CTypedPtrList<CPtrList,CSearchRequest*> m_searchRequestsBack;
	int m_searchRequestListEmpty;
	int m_searchShutdown;
	CPtrList m_lDisposableItems;
	__int16 m_currArmor;
	__int16 m_currAnimation;
	CAIIdList SAVE_OBJECT_LIST;
	int m_nProtagonistId;
	unsigned __int8 m_bPartyAI;
	unsigned __int8 m_bShowAreaNotes;
	unsigned __int8 m_nTravelScreenImageToUse;
	CResRef m_resrefTravelScreenImage;
	unsigned int m_dwLastProgressRenderTickCount;
	unsigned int m_dwLastProgressMsgTickCount;
	unsigned int m_nLastSaveTime;
	unsigned int m_gameTime;
	unsigned int m_zoomLevel;
	unsigned int m_zoomEnabled;
	CPoint m_lastClick;
	int m_lastTarget;
	unsigned __int8 m_bTriggerOutline;
	CVidPalette m_entanglePalette;
	CVidPalette m_webHoldPalette;
	int m_nCharacterTerminationSequenceDelay;
	int m_bNoDreamTonight;
	unsigned __int8 m_bContinueHealing;
	CMoveList m_cMoveList;
	CMoveList m_cLimboList;
	CTypedPtrList<CPtrList,SAreaFileWrapper*> m_lTransitionPiles;
	CString m_transitionPilesResref;
	CPoint m_transitionPilesPtDest;
	int m_bMissionPackInfo;
	int m_bMissionPackInfo25;
	int m_bMissionPackInfoTBP;
	int m_nAIIndex;
	int m_nTimeStop;
	int m_nTimeStopCaster;
	int m_nGreyScale;
	int m_nBrownScale;
	CAIScriptFile* m_globalScriptFile;
	Array<CStore*,12> m_aServerStore;
	Array<unsigned __int8,12> m_nServerStoreDemands;
	CString m_appearanceWeapon;
	CString m_appearanceBody;
	CString m_appearanceShield;
	CString m_appearanceHelmet;
	Array<unsigned __int8,7> m_appearanceColorsWeapon;
	Array<unsigned __int8,7> m_appearanceColorsBody;
	Array<unsigned __int8,7> m_appearanceColorsShield;
	Array<unsigned __int8,7> m_appearanceColorsHelmet;
	int m_bOverrideRestEncounter;
	int m_bAddOnActivated;
	int m_bAddInActivated;
	CString m_sCurrentCampaign;
	int m_bCampaignEnabled;
	CTypedPtrList<CPtrList,CSavedGameStoredLocation*> m_storedLocations;
	CTypedPtrList<CPtrList,CSavedGameStoredLocation*> m_storedLocationsPocketPlane;
	CVVCHash m_VVCPriorities;
	int m_nCurrentVVCPriority;

	void SetState(__int16 state, bool allowDead)
	{
		p_CInfGame_SetState(this, state, allowDead);
	}

	void SetIconIndex(unsigned __int8 iconIndex)
	{
		p_CInfGame_SetIconIndex(this, iconIndex);
	}
};

typedef __int32 (*type_CGameSprite_GetKitMask)(CGameSprite* pThis);
extern type_CGameSprite_GetKitMask p_CGameSprite_GetKitMask;

typedef CGameButtonList* (*type_CGameSprite_GetQuickButtons)(CGameSprite* pThis, unsigned __int16 buttonType, unsigned __int8 existanceCheck);
extern type_CGameSprite_GetQuickButtons p_CGameSprite_GetQuickButtons;

typedef void (*type_CGameSprite_ReadySpell)(CGameSprite* pThis, CButtonData* button, bool firstCall);
extern type_CGameSprite_ReadySpell p_CGameSprite_ReadySpell;

typedef void (*type_CGameSprite_ReadyOffInternalList)(CGameSprite* pThis, CButtonData* button, bool firstCall);
extern type_CGameSprite_ReadyOffInternalList p_CGameSprite_ReadyOffInternalList;

typedef CGameButtonList* (*type_CGameSprite_GetInternalButtonList)(CGameSprite* pThis);
extern type_CGameSprite_GetInternalButtonList p_CGameSprite_GetInternalButtonList;

struct CGameSprite : CGameAIBase
{
	struct GroundItem
	{
		int containerID;
		int itemSlot;
		CResRef item;
		CResRef itemIcon;
		unsigned __int16 count;
		unsigned int itemFlags;
	};

	CResRef m_resref;
	unsigned __int16 m_type;
	unsigned int m_expirationTime;
	unsigned __int16 m_huntingRange;
	unsigned __int16 m_followRange;
	CPoint m_posStart;
	unsigned int m_timeOfDayVisible;
	CCreatureFileHeader m_baseStats;
	Array<CTypedPtrList<CPtrList,CCreatureFileKnownSpell*>,7> m_knownSpellsPriest;
	Array<CTypedPtrList<CPtrList,CCreatureFileKnownSpell*>,9> m_knownSpellsMage;
	Array<CTypedPtrList<CPtrList,CCreatureFileKnownSpell*>,1> m_knownSpellsInnate;
	Array<CCreatureFileMemorizedSpellLevel*,7> m_memorizedSpellsLevelPriest;
	Array<CCreatureFileMemorizedSpellLevel*,9> m_memorizedSpellsLevelMage;
	Array<CCreatureFileMemorizedSpellLevel*,1> m_memorizedSpellsLevelInnate;
	Array<CTypedPtrList<CPtrList,CCreatureFileMemorizedSpell*>,7> m_memorizedSpellsPriest;
	Array<CTypedPtrList<CPtrList,CCreatureFileMemorizedSpell*>,9> m_memorizedSpellsMage;
	Array<CTypedPtrList<CPtrList,CCreatureFileMemorizedSpell*>,1> m_memorizedSpellsInnate;
	CGameSpriteEquipment m_equipment;
	unsigned __int8* m_pDialogData;
	unsigned int m_nDialogData;
	CDerivedStats m_derivedStats;
	CDerivedStats m_tempStats;
	CDerivedStats m_bonusStats;
	CGameSaveCharacter m_gameSaveData;
	CString m_sName;
	unsigned __int8 m_lastCharacterCount;
	CGameStatsSprite m_cGameStats;
	CResRef m_currentArea;
	unsigned __int8 m_bGlobal;
	unsigned __int8 m_nModalState;
	Array<CSound,2> m_sndWalk;
	unsigned int m_nSndWalk;
	Array<CSound,2> m_sndArmor;
	unsigned __int8 m_currSndWalk;
	unsigned __int8 m_currSndArmor;
	CSound m_sndReady;
	CSound m_sndDeath;
	CSound m_sndMagic;
	CSound m_sndVoice;
	CSound m_sndSpriteEffect;
	int m_nNumberOfTimesTalkedTo;
	int m_bSeenPartyBefore;
	CResRef m_specificScriptName;
	Array<int,24> m_nNumberOfTimesInteractedWith;
	__int16 m_nHappiness;
	__int16 m_nOldHappiness;
	CAIObjectType m_interactingWith;
	int m_triggerId;
	int m_active;
	int m_activeAI;
	int m_activeImprisonment;
	int m_bSelected;
	int m_bPortraitUpdate;
	unsigned __int8 m_bInfravisionOn;
	Array<unsigned __int8,16> m_terrainTable;
	Array<unsigned __int8,16> m_visibleTerrainTable;
	Array<unsigned __int8,16> m_flightTerrainTable;
	CGameAnimation m_animation;
	unsigned __int16* m_pSpriteEffectArray;
	tagPOINT* m_pSpriteEffectArrayPosition;
	unsigned __int8 m_nTwitches;
	unsigned __int8 m_spriteEffectSequenceNumber;
	unsigned __int8 m_spriteEffectDuration;
	unsigned __int8 m_spriteEffectSequenceLength;
	char m_spriteEffectBaseIntensity;
	unsigned __int8 m_spriteEffectRandomIntensity;
	CVidCell m_spriteEffectVidCell;
	CVidPalette m_spriteEffectPalette;
	unsigned int m_spriteEffectFlags;
	CVidCell m_spriteSplashVidCell;
	CVidPalette m_spriteSplashPalette;
	unsigned int m_spriteSplashFlags;
	CRect m_rSpriteEffectFX;
	CPoint m_ptSpriteEffectReference;
	unsigned __int8 m_effectExtendDirection;
	unsigned __int8 m_bEscapingArea;
	int m_animationRunning;
	int m_posZDelta;
	unsigned __int8 m_doBounce;
	unsigned __int8 m_nMirrorImages;
	unsigned __int8 m_bBlur;
	unsigned __int8 m_bInvisible;
	unsigned __int8 m_bSanctuary;
	CVidCell m_sanctuaryVidCell;
	unsigned __int8 m_bEntangle;
	CVidCell m_entangleVidCell;
	unsigned __int8 m_bMinorGlobe;
	CVidCell m_minorGlobeVidCell;
	unsigned __int8 m_bShieldGlobe;
	CVidCell m_shieldGlobeVidCell;
	unsigned __int8 m_bGreasePool;
	CVidCell m_greasePoolVidCell;
	unsigned __int8 m_bWebHold;
	CVidCell m_webHoldVidCell;
	long double m_fCircleChange;
	long double m_fCurrCircleChange;
	__int16 m_radius;
	char m_circleFacing;
	unsigned __int8 m_bVisibilityUpdated;
	long double m_fDirectionOffset;
	__int16 m_nSequence;
	CPoint m_posExact;
	CPoint m_posDelta;
	CPoint m_posDest;
	CPoint m_posOld;
	CPoint m_posOldWalk;
	CPoint m_posLastVisMapEntry;
	int* m_pVisMapExploredArea;
	__int16 m_skipDeltaDirection;
	__int16 m_deltaDirection;
	__int16 m_nNewDirection;
	__int16 m_nDirection;
	int* m_pPath;
	__int16 m_nPath;
	unsigned __int8 m_bCheckMove;
	CTypedPtrList<CPtrList,long*> m_pPathTemp;
	CTypedPtrList<CPtrList,long*> m_nPathTemp;
	__int16 m_currPath;
	int m_walkBackwards;
	int m_turningAbout;
	unsigned int m_lastRGBColor;
	int m_pathSearchInvalidDest;
	int m_pathCollision;
	CSearchRequest* m_currentSearchRequest;
	__int16 m_nBloodFlashAmount;
	__int16 m_nDamageLocatorTime;
	unsigned int m_nDamageLocatorColor;
	int m_bBloodFlashOn;
	CVidBitmap m_vbPortraitSmall;
	int m_bVisibleMonster;
	int m_bBumpable;
	unsigned __int8 m_bBumped;
	CPoint m_ptBumpedFrom;
	int m_bInClearBumpPath;
	unsigned int m_nBlockedTick;
	int m_followLeader;
	int m_followLeaderAdditive;
	int m_followLeaderNext;
	int m_followStart;
	CTypedPtrList<CPtrList,CBlood*> m_lstBlood;
	__int16 m_castCounter;
	int m_bStartedCasting;
	int m_bInCasting;
	__int16 m_selectedSound;
	__int16 m_moveCount;
	__int16 m_moveToFrontQueue;
	__int16 m_moveToBackQueue;
	int m_moveToBack;
	int m_moveToFront;
	CGameEffectList m_equipedEffectList;
	CGameEffectList m_timedEffectList;
	CPersistantEffectList m_persistantEffects;
	CGameAbilityList m_lstSelectedLevelUpAbilities;
	CPoint m_curDest;
	int m_nGregsRetryCounter;
	int m_bWaitingForAreaLoadInLeaveAreaLUA;
	__int16 m_userCommandPause;
	__int16 m_nCommandPause;
	CPoint m_curPosition;
	int m_tookDamage;
	__POSITION* m_groupPosition;
	int m_groupMove;
	int m_firstDeadAI;
	CProjectile* m_curProjectile;
	CSpell* m_curSpell;
	CItem* m_curItem;
	__int16 m_curItemSlotNum;
	__int16 m_curItemAbilityNum;
	Array<__int16,40> m_weaponProficiencyList;
	Array<unsigned __int8,8> m_generalWeaponList;
	__int16 m_speedFactor;
	__int16 m_lastActionID;
	CAIObjectType m_liveTypeAI;
	CAIObjectType m_startTypeAI;
	int m_endOfDamageSeq;
	__int16 m_playDeadCounter;
	__int16 m_turnToStoneCounter;
	__int16 m_lightningReactCounter;
	__int16 m_sleepCounter;
	__int16 m_runCounter;
	__int16 m_searchPauseCount;
	int m_doneSearch;
	__int16 m_dieCount;
	__int16 m_pauseCount;
	__int16 m_recoilFrame;
	__int16 m_attackFrame;
	int m_noActionCount;
	int m_inFormation;
	int m_newEffect;
	unsigned __int8 m_canDamage;
	int m_leftAttack;
	unsigned __int8 m_halfAttack;
	int m_hasColorEffects;
	int m_hasColorRangeEffects;
	int m_hasAnimationEffects;
	int m_removeFromArea;
	int m_forceAnimationReset;
	CMarker m_marker;
	CMarker m_destMarker;
	int m_targetId;
	CPoint m_targetPoint;
	__int16 m_targetAreaSize;
	unsigned __int8 m_nTempSelectedWeapon;
	unsigned __int8 m_nTempSelectedWeaponAbility;
	CButtonData m_currentUseButton;
	CResRef m_dialog;
	CResRef m_dialogInteraction;
	unsigned __int8 m_sequenceTest;
	STR_RES* m_speech;
	unsigned __int8 m_saveVSDeathRoll;
	unsigned __int8 m_saveVSWandsRoll;
	unsigned __int8 m_saveVSPolyRoll;
	unsigned __int8 m_saveVSBreathRoll;
	unsigned __int8 m_saveVSSpellRoll;
	unsigned __int8 m_magicResistRoll;
	unsigned __int8 m_probabilityRoll;
	unsigned __int8 m_wildMageLevelModRoll;
	unsigned __int8 m_wildMageSurgeRoll;
	__int16 m_wildSurgeLevel;
	__int16 m_nSelectionCountCommon;
	__int16 m_nSelectionCountCommonRareCounter;
	__int16 m_nSelectionCountRare;
	__int16 m_nSelectionCountAction;
	__int16 m_nSelectionCountActionRareCounter;
	int m_lastCheckedHitPoints;
	int m_moraleFailure;
	int m_startedSwing;
	__int16 m_followCount;
	int m_clearAIOnRemoveFromArea;
	int m_dialogWait;
	int m_dialogWaitTarget;
	int m_talkingCounter;
	unsigned __int8 m_talkingRenderCount;
	unsigned __int8 m_inControlLastTime;
	unsigned __int8 m_bSecondPass;
	CTypedPtrList<CPtrList,CPortraitIcon*> m_portraitIcons;
	CVidCell m_portraitIconVidCell;
	int m_firstActionSound;
	int m_lastRested;
	int m_berserkActive;
	__int16 m_attackSoundDeadzone;
	int m_nHPCONBonusTotalOld;
	int m_bHPCONBonusTotalUpdate;
	int m_nLastWeightCheck;
	unsigned int m_modalCounter;
	int m_bHiding;
	unsigned int m_lastRegenerationTime;
	int m_bLevelUp;
	unsigned __int8 m_bAllowDialogInterrupt;
	unsigned __int8 m_bHappinessChanged;
	int m_nUnselectableCounter;
	unsigned int m_nUnselectableType;
	CResRef m_secondarySounds;
	int m_nStealthGreyOut;
	int m_bMentalStateActing;
	Array<int,3> m_nLastLevelUpLevel;
	int m_nLastLevelUpHPRoll;
	int m_bForceVisualEffects;
	__int16 m_currentActionId;
	int m_bPlayedEncumberedStopped;
	int m_bPlayedEncumberedSlowed;
	int m_nPlayedEncumberedStopped;
	int m_nPlayedEncumberedSlowed;
	__int16 m_nPlayedPoisonedDamage;
	__int16 m_nEffectListCalls;
	int m_bAllowEffectListCall;
	unsigned __int8 m_nPreCutSceneMoveScale;
	int m_bUsingCutSceneMovement;
	int m_bDeleteOnRemove;
	CVariableHash* m_pLocalVariables;
	int m_bInUnmarshal;
	CBounceList m_lBounceList;
	int m_nTransitionPointIndex;
	int m_nBounceCounter;
	int m_nMoraleAI;
	int m_nGeneratedVEFIndex;
	int m_nTrackingCounter;
	CGameButtonList* m_interalButtonList;
	CAIScript* m_dreamScript;
	CGameDialogSprite m_cDialog;
	CGameDialogSprite m_cBanter;
	unsigned __int8 m_bForceVisRangeRedraw;
	int m_nLastExpiryCheck;
	int m_nLastContingencyCheck;
	CString m_hitBonusesLeft;
	CString m_hitBonusesRight;
	CString m_damageBonusesLeft;
	CString m_damageBonusesRight;
	__int16 m_effectMovementRate;
	unsigned int m_effectStateFlags;
	Array<CCreatureFileMemorizedSpellLevel,9> m_effectMemorizedSpellsLevelMage;
	Array<CCreatureFileMemorizedSpellLevel,7> m_effectMemorizedSpellsLevelPriest;
	int m_effectStoreInitialized;
	unsigned __int8 m_nLevellingUp;
	int m_bHasDeathSequence;
	CTypedPtrList<CPtrList,long*> m_lstTargetIds;
	CTypedPtrList<CPtrList,CPoint*> m_lstTargetPts;
	int m_bInStoreState;
	int m_bInDialogState;
	int m_nDialogState;
	int m_nWaitingOnDialog;
	bool m_bHighlightPortrait;
	unsigned int m_nHighlightColor;
	int m_bCutSceneOverrideOfState;
	int m_bForceEffectProcessFromTimeStop;
	int m_bCopyForAdd;
	int m_nCopyParent;
	CTypedPtrList<CPtrList,CFeedbackEntry*> m_feedbackQueue;
	int m_bOnSearchMap;
	int m_bRemovedFromMap;
	CGameSpriteLastUpdate m_cLastSpriteUpdate;
	int m_bSendSpriteUpdate;
	int m_nLastDamageTaken;
	int m_nDeadVisualEffectCountDown;
	int m_bForceVisibilityCheck;
	unsigned __int8 m_nVisualRange;
	int m_bPlayAnimationBattleCry;
	int m_bPlayAnimationSelectionSound;
	Array<unsigned __int8,10> m_aLevellupSpellsToPick;
	int m_nCrossAreaChaseCounter;
	int m_bDidAReequipAll;
	int m_bInEquip;
	char m_cFirstResSlot;
	int m_nNumColorRanges;
	int m_nNumColorEffects;
	int m_nNumWeaponImmunities;
	int m_bCheckedIfVisiblePause;
	int m_bCheckedSpecialAbilities;
	int m_bDroppedTempItem;
	int m_nSkippedUpdates;
	int m_bDelayUpdate;
	int m_nHalfSwingCounter;
	bool m_bInCopy;
	CTypedPtrList<CPtrList,CGameSprite::GroundItem*> m_lstVisibleGroundItems;
	int m_nGroundItemPage;
	float m_avgProcessAITime;
	int m_nMaxHitPointsOnceOnlyBonus;
	bool m_bOutline;

	__int32 GetKitMask()
	{
		return p_CGameSprite_GetKitMask(this);
	}

	CGameButtonList* GetQuickButtons(unsigned __int16 buttonType, unsigned __int8 existanceCheck)
	{
		return p_CGameSprite_GetQuickButtons(this, buttonType, existanceCheck);
	}

	void ReadySpell(CButtonData* button, bool firstCall)
	{
		p_CGameSprite_ReadySpell(this, button, firstCall);
	}

	void ReadyOffInternalList(CButtonData* button, bool firstCall)
	{
		p_CGameSprite_ReadyOffInternalList(this, button, firstCall);
	}

	CGameButtonList* GetInternalButtonList()
	{
		return p_CGameSprite_GetInternalButtonList(this);
	}

	virtual void CGameObject_Destructor()
	{
	}

	virtual unsigned __int8 GetObjectType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void AIUpdate()
	{
	}

	virtual const CAIObjectType* GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void GetNextWaypoint(CPoint* _0)
	{
	}

	virtual __POSITION* GetVertListPos()
	{
		return *(__POSITION**)nullptr;
	}

	virtual unsigned __int8 GetVertListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionButton(const CPoint* _0)
	{
	}

	virtual void OnFormationButton(const CPoint* _0)
	{
	}

	virtual void RemoveFromArea()
	{
	}

	virtual void Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void SetCursor(int _0)
	{
	}

	virtual void SetTarget(CPoint _0, int _1)
	{
	}

	virtual void SetVertListPos(__POSITION* _0)
	{
	}

	virtual int EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}

	virtual void ClearActions(int _0)
	{
	}

	virtual void UpdateTarget(CGameObject* _0)
	{
	}

	virtual void AddAction(const CAIAction* _0)
	{
	}

	virtual void AddEffect(CGameEffect* _0, unsigned __int8 _1, int _2, int _3)
	{
	}

	virtual void ClearAI(unsigned __int8 _0)
	{
	}

	virtual void DoAction()
	{
	}

	virtual __int16 ExecuteAction()
	{
		return *(__int16*)nullptr;
	}

	virtual void InsertAction(const CAIAction* _0)
	{
	}

	virtual void ProcessAI()
	{
	}

	virtual void SetCurrAction(const CAIAction* _0)
	{
	}

	virtual void SetScript(__int16 _0, CAIScript* _1)
	{
	}

	virtual __int16 GetVisualRange()
	{
		return *(__int16*)nullptr;
	}

	virtual __int16 GetAttackRange()
	{
		return *(__int16*)nullptr;
	}

	virtual const unsigned __int8* GetVisibleTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual const unsigned __int8* GetTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual int QuickDecode(CAITrigger* _0, CGameSprite** _1)
	{
		return *(int*)nullptr;
	}

	virtual __int16 GetHelpRange()
	{
		return *(__int16*)nullptr;
	}

	virtual void ApplyTriggers()
	{
	}

	virtual void AutoPause(unsigned int _0)
	{
	}

	virtual int GetCanSeeInvisible()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionRemoval(CAIAction* _0)
	{
	}

	virtual CRect* GetBounding()
	{
		return *(CRect**)nullptr;
	}

	virtual void SetTarget(const CPoint* _0, int _1)
	{
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1, int _2)
	{
	}

	virtual void ResetAITypeLive()
	{
	}

	virtual void ResetAIType()
	{
	}

	virtual void ProcessPendingTriggers(int _0)
	{
	}
};

struct CGameStatic : CGameObject
{
	CAreaFileStaticObject m_header;
	CVidCell m_vidCell;
	CResWebm* m_pMovie;
	CResPVR* m_pImage;
	int m_bRender;
	CSize m_size;
	CTypedPtrList<CPtrList,CVidCell*> m_secondaryVidCellList;
	int m_bNewPalette;
	CVidBitmap m_newPalette;

	virtual void CGameObject_Destructor()
	{
	}

	virtual unsigned __int8 GetObjectType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void AIUpdate()
	{
	}

	virtual const CAIObjectType* GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void GetNextWaypoint(CPoint* _0)
	{
	}

	virtual __POSITION* GetVertListPos()
	{
		return *(__POSITION**)nullptr;
	}

	virtual unsigned __int8 GetVertListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionButton(const CPoint* _0)
	{
	}

	virtual void OnFormationButton(const CPoint* _0)
	{
	}

	virtual void RemoveFromArea()
	{
	}

	virtual void Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void SetCursor(int _0)
	{
	}

	virtual void SetTarget(CPoint _0, int _1)
	{
	}

	virtual void SetVertListPos(__POSITION* _0)
	{
	}

	virtual int EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}
};

struct CGameAnimationType
{
	unsigned __int16 m_animationID;
	unsigned __int8 m_moveScale;
	unsigned __int8 m_moveScaleCurrent;
	CRect m_rEllipse;
	int m_nHeightOffset;
	bool m_bUseSpriteShader;
	unsigned __int8 m_colorBlood;
	unsigned __int8 m_colorChunks;
	unsigned int m_nSndFreq;
	const char* m_pSndDeath;
	Array<NECK_POINTS,8> m_neckOffsets;
	Array<CVidBitmap,5> m_combatRounds;
	unsigned __int8 m_personalSpace;
	unsigned __int8 m_walkCount;
	unsigned __int16 m_castFrame;
	unsigned __int8 m_bBrightest;
	unsigned __int8 m_bBrightestDesired;
	unsigned __int8 m_bLightSource;
	CResRef m_soundRef;
	CString m_walkRef;
	Array<CSequenceSoundList,20> m_sequenceRefs;
	int m_bNewPalette;
	CVidBitmap m_newPalette;

	virtual void CGameAnimationType_Destructor()
	{
	}

	virtual void CalculateFxRect(CRect* _0, CPoint* _1, int _2)
	{
	}

	virtual void CalculateGCBoundsRect(CRect* _0, const CPoint* _1, const CPoint* _2, int _3, int _4, int _5)
	{
	}

	virtual void ChangeDirection(__int16 _0)
	{
	}

	virtual void EquipArmor(char _0, unsigned __int8* _1)
	{
	}

	virtual void EquipHelmet(const CString* _0, unsigned __int8* _1)
	{
	}

	virtual void EquipShield(const CString* _0, unsigned __int8* _1)
	{
	}

	virtual void EquipWeapon(const CString* _0, unsigned __int8* _1, unsigned int _2, const unsigned __int16* _3)
	{
	}

	virtual CVidPalette* GetAnimationPalette(unsigned __int8 _0)
	{
		return *(CVidPalette**)nullptr;
	}

	virtual void GetAnimationResRef(CString* _0, unsigned __int8 _1)
	{
	}

	virtual unsigned __int8 CanLieDown()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 DetectedByInfravision()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int16 GetCastFrame()
	{
		return *(unsigned __int16*)nullptr;
	}

	virtual unsigned __int8 GetColorBlood()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 GetColorChunks()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 GetListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 GetMoveScale()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetMoveScale(unsigned __int8 _0)
	{
	}

	virtual void ResetMoveScale()
	{
	}

	virtual unsigned __int8 GetMoveScaleDefault()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual NECK_POINTS GetNeckOffsets(__int16 _0)
	{
		return *(NECK_POINTS*)nullptr;
	}

	virtual const CRect* GetEllipseRect()
	{
		return *(const CRect**)nullptr;
	}

	virtual int GetPathSmooth()
	{
		return *(int*)nullptr;
	}

	virtual unsigned __int8 GetPersonalSpace()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual const char* GetSndArmor(char* _0)
	{
		return *(const char**)nullptr;
	}

	virtual const char* GetSndDeath(char* _0)
	{
		return *(const char**)nullptr;
	}

	virtual const char* GetSndReady(char* _0)
	{
		return *(const char**)nullptr;
	}

	virtual const char* GetSndWalk(char* _0, __int16 _1)
	{
		return *(const char**)nullptr;
	}

	virtual unsigned int GetSndWalkFreq()
	{
		return *(unsigned int*)nullptr;
	}

	virtual int IsFalseColor()
	{
		return *(int*)nullptr;
	}

	virtual int IsInvulnerable()
	{
		return *(int*)nullptr;
	}

	virtual int IsMirroring()
	{
		return *(int*)nullptr;
	}

	virtual int IsBeginningOfSequence()
	{
		return *(int*)nullptr;
	}

	virtual int IsEndOfSequence()
	{
		return *(int*)nullptr;
	}

	virtual int IsEndOfTwitchSequence()
	{
		return *(int*)nullptr;
	}

	virtual void IncrementFrame()
	{
	}

	virtual void DecrementFrame()
	{
	}

	virtual void Render(CInfinity* _0, CVidMode* _1, const CRect* _2, const CPoint* _3, const CPoint* _4, unsigned int _5, unsigned int _6, const CRect* _7, int _8, int _9, int _10, unsigned __int8 _11, CGameSprite* _12)
	{
	}

	virtual void ClearColorEffects(unsigned __int8 _0)
	{
	}

	virtual void ClearColorEffectsAll()
	{
	}

	virtual void SetColorEffect(unsigned __int8 _0, unsigned __int8 _1, unsigned int _2, unsigned __int8 _3)
	{
	}

	virtual void SetColorEffectAll(unsigned __int8 _0, unsigned int _1, unsigned __int8 _2)
	{
	}

	virtual void SetColorRange(unsigned __int8 _0, unsigned __int8 _1)
	{
	}

	virtual void SetColorRangeAll(unsigned __int8 _0)
	{
	}

	virtual __int16 SetSequence(__int16 _0)
	{
		return *(__int16*)nullptr;
	}

	virtual int GetHeightOffset()
	{
		return *(int*)nullptr;
	}

	virtual void CalculateFxRectMax(CRect* _0, CPoint* _1, int _2)
	{
	}

	virtual void CalculateEllipseRect()
	{
	}

	virtual void SetNeckOffsets(__int16 _0, __int16 _1, __int16 _2, __int16 _3, __int16 _4, __int16 _5, __int16 _6, __int16 _7, __int16 _8, __int16 _9, __int16 _10, __int16 _11, __int16 _12, __int16 _13, __int16 _14, __int16 _15)
	{
	}

	virtual unsigned __int8 GetAttackFrameType(unsigned __int8 _0, unsigned __int8 _1, unsigned __int8 _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual int GetAboveGround()
	{
		return *(int*)nullptr;
	}

	virtual __int16 GetAwakePlayInReverse()
	{
		return *(__int16*)nullptr;
	}

	virtual void SetBrightest(unsigned __int8 _0)
	{
	}

	virtual void SetBrightestDesired(unsigned __int8 _0)
	{
	}

	virtual __int16 GetCastHeight()
	{
		return *(__int16*)nullptr;
	}

	virtual void GetCastingOffset(CPoint* _0)
	{
	}

	virtual unsigned __int8 GetCurrentSequenceAndFrame(__int16* _0, __int16* _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 GetCurrentResRef(CString* _0, CString* _1, CString* _2, CString* _3)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void OverrideAnimation(CResRef _0, int _1)
	{
	}

	virtual void Marshal(unsigned __int8** _0, unsigned int* _1)
	{
	}

	virtual bool Unmarshal(CResRef _0)
	{
		return *(bool*)nullptr;
	}
};

struct CGameFireball3d : CGameObject
{
	Array<unsigned __int8,16> m_terrainTable;
	Array<unsigned __int8,16> m_visibleTerrainTable;
	unsigned __int16 m_animationID;
	unsigned __int16 m_animationIDStatic;
	Array<unsigned __int8,7> m_colorRangeValues;
	unsigned __int16 m_ringGranularity;
	CVidCell m_spriteSplashVidCell;
	CVidPalette m_spriteSplashPalette;
	__int16 m_holdDuration;
	int m_radius;
	int m_speed;
	unsigned __int8 m_duration;
	unsigned __int8 m_collision;
	CSize m_ellipseSize;
	unsigned __int8* m_pPlacementGrid;
	CPoint m_nEllipse;
	CRect* m_pEllipse;
	unsigned __int8* m_flagEllipse;
	CSound m_sndExplosion;
	CString m_sSoundTemporal;
	int m_bCenterSoundLooping;
	int m_bSplashGlow;
	int m_bBrightest;
	int m_bRingTemporals;
	int m_bInteriorTemporals;
	int m_bRandomSpeed;
	int m_bPalettedRing;
	int m_bPalettedArea;
	int m_bCone;
	unsigned __int16 m_coneSize;
	CPoint m_posEdge;
	int m_bNewPalette;
	CVidBitmap m_newPalette;
	CResRef m_fireBallArea;
	CResRef m_fireBallRing;
	unsigned __int16 m_projectileType;
	int m_bPermanent;
	int m_bCanSave;

	virtual void CGameObject_Destructor()
	{
	}

	virtual unsigned __int8 GetObjectType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void AIUpdate()
	{
	}

	virtual const CAIObjectType* GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void GetNextWaypoint(CPoint* _0)
	{
	}

	virtual __POSITION* GetVertListPos()
	{
		return *(__POSITION**)nullptr;
	}

	virtual unsigned __int8 GetVertListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void OnActionButton(const CPoint* _0)
	{
	}

	virtual void OnFormationButton(const CPoint* _0)
	{
	}

	virtual void RemoveFromArea()
	{
	}

	virtual void Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void SetCursor(int _0)
	{
	}

	virtual void SetTarget(CPoint _0, int _1)
	{
	}

	virtual void SetVertListPos(__POSITION* _0)
	{
	}

	virtual int EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}
};

struct CSearchBitmap
{
	CVidBitmap m_resSearch;
	unsigned __int8* m_pDynamicCost;
	unsigned __int8* m_snapshotDynamicCost;
	const unsigned __int8* m_snapshotTerrainTable;
	CSize m_GridSquareDimensions;
	CGameArea* m_pArea;
	unsigned __int8 m_sourceSide;
	unsigned __int8 m_snapshotPersonalSpace;
};

struct CGameArea
{
	struct m_cWalkableRenderCache_t
	{
		int nTriCount;
		int nLineCount;
		CPoint* pVertexArray;
		bool bReady;
	};

	struct CacheSearchMap
	{
		struct __l2
		{
			struct _lambda_858d28ddc87715ec3d5e1dd88541236f_
			{
				unsigned __int64* nNextVertex;
				unsigned __int64* nCurVertexCapacity;
				CPoint** pVertexArray;
			};

		};

	};

	CAreaFileHeader m_header;
	int m_bHeaderExtendedNight;
	CAreaSoundsAndMusic m_headerSound;
	CAreaFileRestEncounter m_headerRestEncounter;
	CTypedPtrList<CPtrList,CAreaFileCharacterEntryPoint*> m_entryPoints;
	unsigned __int8 m_id;
	unsigned __int8 m_nCharacters;
	unsigned __int8 m_nInfravision;
	unsigned __int8 m_bAreaLoaded;
	CResRef m_resref;
	CResRef m_restMovieDay;
	CResRef m_restMovieNight;
	unsigned __int8 m_waterAlpha;
	CResWED* m_pResWED;
	CInfGame* m_pGame;
	int m_nScrollState;
	int m_nKeyScrollState;
	int m_bSelectionSquareEnabled;
	int m_bTravelSquare;
	int m_iPickedOnDown;
	int m_iPicked;
	int m_iPickedTarget;
	int m_bPicked;
	int m_nToolTip;
	CPoint m_mousePos;
	CVidBitmap m_bmLum;
	CVidBitmap* m_pbmLumNight;
	CVidBitmap m_bmHeight;
	CObjectMarker* m_pObjectMarker;
	CObjectMarker* m_pObjectMarkerHealthBar;
	unsigned __int8 m_firstRender;
	CRect m_selectSquare;
	__int16 m_rotation;
	CPoint m_moveDest;
	int m_groupMove;
	Array<unsigned __int8,16> m_terrainTable;
	Array<unsigned __int8,16> m_visibleTerrainTable;
	int m_nAIIndex;
	int m_bInPathSearch;
	unsigned int m_nInitialAreaID;
	unsigned int m_nFirstObject;
	unsigned int m_dwLastProgressRenderTickCount;
	unsigned int m_dwLastProgressMsgTickCount;
	unsigned __int8 m_nRandomMonster;
	__int16 m_nVisibleMonster;
	unsigned __int8 m_bRecentlySaved;
	unsigned int m_nSavedTime;
	CGameAreaNotes m_cGameAreaNotes;
	CInfinity m_cInfinity;
	CSearchBitmap m_search;
	CVisibilityMap m_visibility;
	unsigned __int8* m_pDynamicHeight;
	int m_startedMusic;
	unsigned int m_startedMusicCounter;
	CTypedPtrList<CPtrList,long*> m_lVertSort;
	CTypedPtrList<CPtrList,long*> m_lVertSortBack;
	CTypedPtrList<CPtrList,long*> m_lVertSortFlight;
	CTypedPtrList<CPtrList,long*> m_lVertSortUnder;
	CTypedPtrList<CPtrList,long*> m_lVertSortAdd;
	CTypedPtrList<CPtrList,long*> m_lVertSortBackAdd;
	CTypedPtrList<CPtrList,long*> m_lVertSortFlightAdd;
	CTypedPtrList<CPtrList,long*> m_lVertSortUnderAdd;
	CTypedPtrList<CPtrList,__POSITION*> m_lVertSortRemove;
	CTypedPtrList<CPtrList,__POSITION*> m_lVertSortBackRemove;
	CTypedPtrList<CPtrList,__POSITION*> m_lVertSortFlightRemove;
	CTypedPtrList<CPtrList,__POSITION*> m_lVertSortUnderRemove;
	CTypedPtrList<CPtrList,CTiledObject*> m_lTiledObjects;
	CTypedPtrList<CPtrList,long*> m_lGameTextObjects;
	CTypedPtrList<CPtrList,long*> m_lVertSortTransition;
	CPoint m_ptOldViewPos;
	CVariableHash m_variables;
	CVariableHash m_namedCreatures;
	unsigned __int8 m_bPermitNewCharacters;
	__int16 m_nCurrentSong;
	int m_nBattleSongCounter;
	int m_nDamageCounter;
	__int16 m_nScreenFlash;
	__int16 m_nScreenFlashFade;
	unsigned int m_screenFlashRGB;
	CTypedPtrList<CPtrList,CGameAreaClairvoyanceEntry*> m_lClairvoyanceObjects;
	CTypedPtrList<CPtrList,long*> m_lContainersNeedingUpdate;
	int m_bAnySpritesInActions;
	int m_nMPSynchCounter;
	unsigned __int8 m_nMPSignalType;
	unsigned __int8 m_nMPSignalData;
	int m_nMPSignalsToSend;
	int m_nEnemyCountWork;
	int m_nEnemyCountLast;
	int m_nEnemyCount2ndLast;
	int m_nEnemyCountSequestered;
	int m_nTrapCountWork;
	int m_nTrapCountLast;
	int m_nTrapCount2ndLast;
	int m_nUnloadCounter;
	int m_bDisplayingHealth;
	CMemINI INIFile;
	CSpawnFile* mpSpawner;
	int m_nCreatureNodeCount;
	CSize m_lightmapRatio;
	CGameArea::m_cWalkableRenderCache_t m_cWalkableRenderCache;
	CSound m_sndAmbientDay;
	CSound m_sndAmbientNight;
	unsigned __int8 m_sndAmbientVolume;
	unsigned __int16 m_sndAmbientDayVolume;
	unsigned __int16 m_sndAmbientNightVolume;
};

struct CVidMode
{
	int m_nPrintFile;
	int m_nPointerNumber;
	unsigned int m_dwCursorRenderFlags;
	unsigned int m_dwRedMask;
	unsigned int m_dwGreenMask;
	unsigned int m_dwBlueMask;
	unsigned __int8 m_bFadeTo;
	unsigned __int8 m_nFade;
	SDL_Window* m_pWindow;
	void* m_glContext;
	CVidBitmap m_circle;
	int nWidth;
	int nHeight;
	bool bRedrawEntireScreen;
	bool bHardwareMouseCursor;
	CVidCell* pPointerVidCell;
	CVidCell* pTooltipVidCell;
	unsigned __int8 m_bPrintScreen;
	unsigned int nTickCount;
	float m_fInputScale;
	unsigned int rgbGlobalTint;
	unsigned __int8 m_nGammaCorrection;
	unsigned __int8 m_nBrightnessCorrection;
	int m_nScreenScrollY;
	int m_nScreenScrollX;
	int nRShift;
	int nGShift;
	int nBShift;
	tagRGBQUAD rgbTint;
	int bPointerEnabled;
	CRect rPointerStorage;
	CRect m_rLockedRect;
	CVidCell* m_lastCursor;
	int m_lastCursorFrame;
	int m_lastCursorSequence;
	int m_lastCursorNumber;
	unsigned int m_lastCursorFlags;
	unsigned int m_lastCursorResId;
	SDL_Cursor* m_hwCursor;
	SDL_Surface* m_hwCursorSurface;
	int nVRamSurfaces;
	CVidBitmap m_rgbMasterBitmap;
};

struct CSaveGameSlot
{
	CString m_sFileName;
	CString m_sSlotName;
	CResBitmap m_cResScreenShot;
	CResBitmap m_cBmpResPortrait0;
	CResBitmap m_cBmpResPortrait1;
	CResBitmap m_cBmpResPortrait2;
	CResBitmap m_cBmpResPortrait3;
	CResBitmap m_cBmpResPortrait4;
	CResBitmap m_cBmpResPortrait5;
	CResRef m_cResPortrait;
	CString m_sCharacterName;
	unsigned int m_nTime;
	int m_nChapter;
	CString m_sChapter;
};

struct CFileView
{
	file_t f;
	view_t v;
	int fileSize;
	int filePos;
};

extern std::vector<std::pair<const TCHAR*, void**>> internalPointersMap;
