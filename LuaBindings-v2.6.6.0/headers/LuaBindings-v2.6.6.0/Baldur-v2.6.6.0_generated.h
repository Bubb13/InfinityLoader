
#pragma once

#include <queue>
#include <vector>

#include "InfinityLoaderCommon.h"
#include "to_lua_pointers.h"

typedef unsigned short ushort;
typedef unsigned int uint;

template<typename A>
struct W
{

private:

	union {
		A val;
	};

public:

	A* operator->() {
		return &val;
	}

	A& operator*() {
		return val;
	}

	template<typename... Args>
	W(Args&&... args) {
		val.Construct(std::forward<Args>(args)...);
	}

	~W() {
		val.Destruct();
	}
};

struct ALCcontext_struct;
struct ALCdevice_struct;
struct C2DArray;
struct CAIAction;
struct CAICondition;
struct CAIGroup;
struct CAIIdList;
struct CAIObjectType;
struct CAIResponse;
struct CAIScript;
struct CAIScriptFile;
struct CAITrigger;
struct CAbilityData;
struct CAbilityId;
struct CAreaFileCharacterEntryPoint;
struct CAreaFileContainer;
struct CAreaFileProjectileObject;
struct CAreaPoint;
struct CBaldurChitin;
struct CButtonData;
struct CChitin;
struct CContingency;
struct CCreatureFileHeader;
struct CCreatureFileItem;
struct CCriticalEntry;
struct CDerivedStats;
struct CGameAIBase;
struct CGameAnimationType;
struct CGameArea;
struct CGameDialogReply;
struct CGameEffect;
struct CGameEffectUsability;
struct CGameFile;
struct CGameObject;
struct CGameSprite;
struct CImmunitiesAIType;
struct CImmunitiesItemEquip;
struct CImmunitySpell;
struct CInfButtonArray;
struct CInfGame;
struct CInfTileSet;
struct CItem;
struct CMessage;
struct CMessageHandler;
struct CMoveListEntry;
struct CObList;
struct CObjectMarker;
struct CPathNode;
struct CPlex;
struct CPoint;
struct CProjectile;
struct CRes;
struct CResPVR;
struct CResRef;
struct CResTileSet;
struct CSavedGamePartyCreature;
struct CScreenStore;
struct CSearchBitmap;
struct CSelectiveBonus;
struct CSelectiveWeaponType;
struct CSequenceSound;
struct CSound;
struct CSoundMixerImp;
struct CSpawn;
struct CSpell;
struct CString;
struct CUIControlTextDisplay;
struct CVVCHashEntry;
struct CVariable;
struct CVariableHash;
struct CVidCellFont;
struct CVidMode;
struct DP_Player;
struct IDPPeer;
struct IDPProvider;
struct Item_Header_st;
struct Item_ability_st;
struct Item_effect_st;
struct SDL_BlitMap;
union SDL_Event;
struct SDL_PixelFormat;
struct SDL_Window;
struct Spell_Header_st;
struct Spell_ability_st;
struct SteamUGCDetails_t;
struct WED_LayerHeader_st;
struct st_tiledef;
struct uiItem;
struct uiMenu;
struct uiVariant;

struct ALCcontext_struct
{
	ALCcontext_struct() = delete;
};

struct ALCdevice_struct
{
	ALCdevice_struct() = delete;
};

struct CUIControlTextDisplay
{
	CUIControlTextDisplay() = delete;
};

struct CVideo
{
	CVidMode* pCurrentMode;

	CVideo() = delete;
};

struct SAreaFileWrapper
{
	CAreaFileContainer* pContainer;
	CCreatureFileItem* pStartingItem;
	CAreaPoint* pPickPointStart;

	SAreaFileWrapper() = delete;
};

struct SDL_Cursor
{
	SDL_Cursor* next;
	void* driverdata;

	SDL_Cursor() = delete;
};

struct SProjectileWrapper
{
	CAreaFileProjectileObject* pProjectileObject;
	unsigned __int8* pEffectList;

	SProjectileWrapper() = delete;
};

struct VoidPointer
{
	void* reference;

	VoidPointer() = delete;
};

struct __POSITION
{
	__POSITION() = delete;
};

struct WED_ScreenSectionList
{
	unsigned __int16 nStartingPoly;
	unsigned __int16 nNumPolys;

	WED_ScreenSectionList() = delete;
};

struct WED_PolyPoint_st
{
	unsigned __int16 x;
	unsigned __int16 y;

	WED_PolyPoint_st() = delete;
};

struct NECK_POINTS
{
	__int16 x;
	__int16 y;

	NECK_POINTS() = delete;
};

struct CVIDPOLY_VERTEX
{
	unsigned __int16 x;
	unsigned __int16 y;

	CVIDPOLY_VERTEX() = delete;
};

struct CAreaPoint
{
	unsigned __int16 m_xPos;
	unsigned __int16 m_yPos;

	CAreaPoint() = delete;
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

enum class EEex_MatchObjectFlags : __int32
{
	IGNORE_LOS = 1,
	MATCH_NON_SPRITES = 2,
	IGNORE_INVISIBLE = 4,
	MATCH_INVISIBLE = 8,
	MATCH_SLEEPING = 16,
	MATCH_DEAD = 32,
	MATCH_BACKLIST = 64,
	PRIORITIZE_BACKLIST = 128,
	MATCH_ONLY_BACKLIST = 256,
	FARTHEST = 512,
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

	CSoundMixer() = delete;
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

	_6B279AA1C7A281E7C97E085DB9F2DFBB() = delete;
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

			SteamIDComponent_t() = delete;
		};

		CSteamID::SteamID_t::SteamIDComponent_t m_comp;
		unsigned __int64 m_unAll64Bits;

		SteamID_t() = delete;
	};

	CSteamID::SteamID_t m_steamid;

	CSteamID() = delete;
};

enum class VertListType : __int8
{
	LIST_FRONT = 0,
	LIST_BACK = 1,
	LIST_FLIGHT = 2,
	LIST_UNDER = 3,
};

struct VRAM_FLAGS
{
	unsigned __int8 bVRamUpdated : 1;

	VRAM_FLAGS() = delete;
};

struct TILE_CODE
{
	unsigned __int8 tileNW;
	unsigned __int8 tileNE;
	unsigned __int8 tileSW;
	unsigned __int8 tileSE;

	TILE_CODE() = delete;
};

struct SDL_version
{
	unsigned __int8 major;
	unsigned __int8 minor;
	unsigned __int8 patch;

	SDL_version() = delete;
};

struct SDL_Color
{
	unsigned __int8 r;
	unsigned __int8 g;
	unsigned __int8 b;
	unsigned __int8 a;

	SDL_Color() = delete;
};

union SDL_WindowShapeParams
{
	unsigned __int8 binarizationCutoff;
	SDL_Color colorKey;

	SDL_WindowShapeParams() = delete;
};

struct SDL_WindowShapeMode
{
	WindowShapeMode mode;
	SDL_WindowShapeParams parameters;

	SDL_WindowShapeMode() = delete;
};

struct CVisibilityMapEllipse
{
	__int16 m_nXExploreRange;
	__int16 m_nYExploreRange;
	unsigned __int8* m_pXEllipsePts;
	unsigned __int8* m_pYEllipsePts;
	unsigned __int8 m_nXPtsSize;
	unsigned __int8 m_nYPtsSize;

	CVisibilityMapEllipse() = delete;
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

	CColorRange() = delete;
};

struct SubmitItemUpdateResult_t
{
	EResult m_eResult;
	bool m_bUserNeedsToAcceptWorkshopLegalAgreement;
	unsigned __int64 m_nPublishedFileId;

	SubmitItemUpdateResult_t() = delete;
};

struct CreateItemResult_t
{
	EResult m_eResult;
	unsigned __int64 m_nPublishedFileId;
	bool m_bUserNeedsToAcceptWorkshopLegalAgreement;

	CreateItemResult_t() = delete;
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

			v2_t() = delete;
		};

		_anonymous_tag_() = delete;
	};

	union _C3D261E28D53B12983426B9B0D118A61
	{
		unsigned int nOffset;
		frameTableEntry_st::_anonymous_tag_::v2_t v2;

		_C3D261E28D53B12983426B9B0D118A61() = delete;
	};

	unsigned __int16 nWidth;
	unsigned __int16 nHeight;
	__int16 nCenterX;
	__int16 nCenterY;
	frameTableEntry_st::_C3D261E28D53B12983426B9B0D118A61 ___u4;

	frameTableEntry_st() = delete;
};

struct file_t
{
	int fd;
	int fm;
	int fs;
	int zo;
	int zs;

	file_t() = delete;
};

struct cnetworkwindow_queueentry_st
{
	int dpIDFrom;
	int dpIDTo;
	unsigned __int8* pInfo;
	unsigned int dwSize;
	unsigned int dwFlags;

	cnetworkwindow_queueentry_st() = delete;
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

	bamHeader_st() = delete;
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

	_EdgeDescription() = delete;
};

struct _EAXPRESET
{
	unsigned int dwEnvironment;
	float fVolume;
	float fDecay;
	float fDamping;

	_EAXPRESET() = delete;
};

struct CSoundProperties
{
	_EAXPRESET m_iEAXpreset;

	CSoundProperties() = delete;
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

	WED_WedHeader_st() = delete;
};

#pragma pack(push, 1)
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

	WED_PolyList_st() = delete;
};
#pragma pack(pop)

struct WED_PolyHeader_st
{
	unsigned int nPolys;
	unsigned int nOffsetToPolyList;
	unsigned int nOffsetToPointList;
	unsigned int nOffsetToScreenSectionList;
	unsigned int nOffsetToScreenPolyList;

	WED_PolyHeader_st() = delete;
};

#pragma pack(push, 1)
struct WAV_Header
{
	unsigned __int16 wFormatTag;
	unsigned __int16 nChannels;
	unsigned int nSamplesPerSec;
	unsigned int nAvgBytesPerSec;
	unsigned __int16 nBlockAlign;
	unsigned __int16 wBitsPerSample;
	unsigned __int16 cbSize;

	WAV_Header() = delete;
};
#pragma pack(pop)

struct SteamParamStringArray_t
{
	const char** m_ppStrings;
	int m_nNumStrings;

	SteamParamStringArray_t() = delete;
};

struct SDL_WindowShaper
{
	SDL_Window* window;
	unsigned int userx;
	unsigned int usery;
	SDL_WindowShapeMode mode;
	SDL_bool hasshape;
	void* driverdata;

	SDL_WindowShaper() = delete;
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

	SDL_WindowEvent() = delete;
};

struct SDL_UserEvent
{
	unsigned int type;
	unsigned int timestamp;
	unsigned int windowID;
	int code;
	void* data1;
	void* data2;

	SDL_UserEvent() = delete;
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

	SDL_TouchFingerEvent() = delete;
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

			win_t() = delete;
		};

		SDL_SysWMmsg::msg_t::win_t win;
		int dummy;

		msg_t() = delete;
	};

	SDL_version version;
	SDL_SYSWM_TYPE subsystem;
	SDL_SysWMmsg::msg_t msg;

	SDL_SysWMmsg() = delete;
};

struct SDL_SysWMEvent
{
	unsigned int type;
	unsigned int timestamp;
	SDL_SysWMmsg* msg;

	SDL_SysWMEvent() = delete;
};

struct SDL_Rect
{
	int x;
	int y;
	int w;
	int h;

	SDL_Rect() = delete;
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

	SDL_Surface() = delete;
};

struct SDL_QuitEvent
{
	unsigned int type;
	unsigned int timestamp;

	SDL_QuitEvent() = delete;
};

struct SDL_Point
{
	int x;
	int y;

	SDL_Point() = delete;
};

struct SDL_Palette
{
	int ncolors;
	SDL_Color* colors;
	unsigned int version;
	int refcount;

	SDL_Palette() = delete;
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

	SDL_MultiGestureEvent() = delete;
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

	SDL_MouseWheelEvent() = delete;
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

	SDL_MouseMotionEvent() = delete;
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

	SDL_MouseButtonEvent() = delete;
};

struct SDL_Keysym
{
	SDL_Scancode scancode;
	SDL_Keycode sym;
	unsigned __int16 mod;
	unsigned int unused;

	SDL_Keysym() = delete;
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

	SDL_KeyboardEvent() = delete;
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

	SDL_JoyHatEvent() = delete;
};

struct SDL_JoyDeviceEvent
{
	unsigned int type;
	unsigned int timestamp;
	int which;

	SDL_JoyDeviceEvent() = delete;
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

	SDL_JoyButtonEvent() = delete;
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

	SDL_JoyBallEvent() = delete;
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

	SDL_JoyAxisEvent() = delete;
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

	SDL_DollarGestureEvent() = delete;
};

struct SDL_DisplayMode
{
	unsigned int format;
	int w;
	int h;
	int refresh_rate;
	void* driverdata;

	SDL_DisplayMode() = delete;
};

struct SDL_ControllerDeviceEvent
{
	unsigned int type;
	unsigned int timestamp;
	int which;

	SDL_ControllerDeviceEvent() = delete;
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

	SDL_ControllerButtonEvent() = delete;
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

	SDL_ControllerAxisEvent() = delete;
};

struct SDL_CommonEvent
{
	unsigned int type;
	unsigned int timestamp;

	SDL_CommonEvent() = delete;
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

	SDL_BlitInfo() = delete;
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

	SDL_BlitMap() = delete;
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

	SDL_AudioDeviceEvent() = delete;
};

struct ResFixedHeader_st
{
	unsigned int nFileType;
	unsigned int nFileVersion;
	unsigned int nNumber;
	unsigned int nSize;
	unsigned int nTableOffset;

	ResFixedHeader_st() = delete;
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

	MOSAICQUAD() = delete;
};

struct MOSAICHEADERV2
{
	unsigned int nFileType;
	unsigned int nFileVersion;
	unsigned int nWidth;
	unsigned int nHeight;
	unsigned int nQuads;
	unsigned int nOffsetToQuads;

	MOSAICHEADERV2() = delete;
};

struct LeaderboardEntry_t
{
	CSteamID m_steamIDUser;
	int m_nGlobalRank;
	int m_nScore;
	int m_cDetails;
	unsigned __int64 m_hUGC;

	LeaderboardEntry_t() = delete;
};

struct DP_Packet
{
	unsigned int flags;
	unsigned __int8* data;
	unsigned __int64 dataLength;
	unsigned __int64 offset;

	DP_Packet() = delete;
};

struct DP_Event
{
	DP_EventType type;
	IDPPeer* peer;
	unsigned __int8 channelID;
	unsigned int data;
	DP_Packet* packet;

	DP_Event() = delete;
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

	DPWrapper() = delete;
};

struct CWorldMapHeader
{
	unsigned int m_nMapCount;
	unsigned int m_nMapOffset;

	CWorldMapHeader() = delete;
};

struct CWeaponIdentification
{
	unsigned __int16 m_itemType;
	unsigned int m_itemFlags;
	unsigned int m_itemFlagMask;
	unsigned int m_attributes;

	CWeaponIdentification() = delete;
};

struct CVariableHash
{
	CVariable* m_hashEntries;
	int m_nTableEntries;

	CVariableHash() = delete;

	typedef CVariable* (__thiscall *type_FindKey)(CVariableHash* pThis, CString* inVarName);
	static type_FindKey p_FindKey;

	typedef int (__thiscall *type_AddKey)(CVariableHash* pThis, CVariable* var);
	static type_AddKey p_AddKey;

	CVariable* FindKey(CString* inVarName)
	{
		return p_FindKey(this, inVarName);
	}

	int AddKey(CVariable* var)
	{
		return p_AddKey(this, var);
	}
};

struct CVVCHash
{
	CVVCHashEntry* m_hashEntries;
	int m_nTableEntries;

	CVVCHash() = delete;
};

struct CVRamPool
{
	int nVTiles;
	st_tiledef* pTileDef;

	CVRamPool() = delete;
};

struct CTlkFileOverride
{
	int bLoaded;
	int m_UserAddedCount;

	CTlkFileOverride() = delete;
};

struct CTimerWorld
{
	unsigned int m_gameTime;
	unsigned __int8 m_active;
	unsigned __int8 m_nLastPercentage;

	CTimerWorld() = delete;
};

struct CSpellLevelDecrementing
{
	int m_bImmune;
	int m_nLevels;

	CSpellLevelDecrementing() = delete;
};

struct CScriptCache
{
	CAIScript** m_scriptMap;
	int m_nTableEntries;

	CScriptCache() = delete;
};

struct CSchoolAndSecondaryDecrementing
{
	unsigned int m_nType;
	int m_nLevels;

	CSchoolAndSecondaryDecrementing() = delete;
};

struct CResTile
{
	CResTileSet* tis;
	int tileIndex;
	CResPVR* pvr;

	CResTile() = delete;
};

struct CResInfTile : CResTile
{
	int nVRamTile;
	TILE_CODE renderCode;
	CResTile* pDualTileRes;
	VRAM_FLAGS flags;

	CResInfTile() = delete;
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

	CPathSearch() = delete;
};

struct CPathNode
{
	CPathNode* m_pathNodePrev;
	int m_gridPosition;
	int m_costStart;
	int m_costTotal;
	unsigned __int8 m_fIsOpen;

	CPathNode() = delete;
};

struct CPARTICLE_POINT
{
	int x;
	int y;
	int z;

	CPARTICLE_POINT() = delete;
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

	CParticle() = delete;
};

struct CSnowFlake : CParticle
{
	unsigned __int8 m_nDriftWidth;
	unsigned __int8 m_nDriftCounter;
	unsigned __int16 m_nMeltTime;
	int m_nLastDriftVelocity;

	CSnowFlake() = delete;
};

struct CRainDrop : CParticle
{
	CRainDrop() = delete;
};

struct CMusicPosition
{
	int m_nSong;
	int m_nSection;
	int m_nPosition;

	CMusicPosition() = delete;
};

struct CMachineState
{
	unsigned int m_inputState;

	CMachineState() = delete;
};

struct CKeyInfo
{
	unsigned int m_repeatCount;
	int m_keyCode;
	unsigned __int8 m_repeatDelay;
	unsigned __int8 m_repeatRate;

	CKeyInfo() = delete;
};

struct CImmunitiesItemTypeEquip
{
	unsigned int m_type;
	unsigned int m_error;
	CGameEffect* m_pEffect;

	CImmunitiesItemTypeEquip() = delete;
};

struct CGameTimer
{
	int m_time;
	unsigned __int8 m_id;

	CGameTimer() = delete;
};

struct CGameRemoteObjectListEntry
{
	int remotePlayerID;
	int remoteObjectID;
	int localObjectID;
	CGameRemoteObjectListEntry* pNext;

	CGameRemoteObjectListEntry() = delete;
};

struct CGameRemoteObjectDeletion
{
	int deletedPlayerID;
	int deletedObjectID;
	CGameRemoteObjectDeletion* pNext;

	CGameRemoteObjectDeletion() = delete;
};

struct CGameRemoteObjectControlChange
{
	int oldPlayerID;
	int oldObjectID;
	int newPlayerID;
	int newObjectID;
	CGameRemoteObjectControlChange* pNext;
	unsigned __int8 localControl;

	CGameRemoteObjectControlChange() = delete;
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

	CGameOptions() = delete;
};

struct CGameObjectArray
{
	CGameObjectArray() = delete;

	typedef byte (__cdecl *type_GetShare)(int index, CGameObject** ptr);
	static type_GetShare p_GetShare;

	static byte GetShare(int index, CGameObject** ptr)
	{
		return p_GetShare(index, ptr);
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

	CGameJournalEntry() = delete;
};

struct CGameAnimation
{
	CGameAnimationType* m_animation;
	unsigned int m_overrides;
	__int16 m_sequenceHighLevel;
	unsigned __int8 m_detectedByInfravision;
	unsigned __int8 m_bloodColor;
	unsigned __int8 m_personalSpace;

	CGameAnimation() = delete;
};

struct CDeathSound
{
	int m_soundLength;
	int m_characterId;
	__int16 m_soundNum;
	int m_started;
	CAITrigger* m_pTrigger;

	CDeathSound() = delete;
};

struct CCreatureFileMemorizedSpellLevel
{
	unsigned __int16 m_spellLevel;
	unsigned __int16 m_baseCount;
	unsigned __int16 m_count;
	unsigned __int16 m_magicType;
	unsigned int m_memorizedStartingSpell;
	unsigned int m_memorizedCount;

	CCreatureFileMemorizedSpellLevel() = delete;
};

struct CColorEffect
{
	unsigned __int8 m_effectType;
	unsigned __int8 m_range;
	unsigned int m_tintColor;
	unsigned __int8 m_periodLength;

	CColorEffect() = delete;
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

	CBounceEntry() = delete;
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

	BAMHEADERV2() = delete;
};

union _9CC80BF4F2F1300360474CD60BF15E00
{
	_6B279AA1C7A281E7C97E085DB9F2DFBB __s0;
	int all;

	_9CC80BF4F2F1300360474CD60BF15E00() = delete;
};

struct _4BC756EB7537E12A00FC57C6BF2CCA8B
{
	_9CC80BF4F2F1300360474CD60BF15E00 selected;
	SDL_Rect mouseOver;

	_4BC756EB7537E12A00FC57C6BF2CCA8B() = delete;
};

struct _9B9540D9920A90D57A3D80DDD1A70514
{
	bool (__fastcall *f)(uiMenu*, const SDL_Rect*, SDL_Event*);
	SDL_Point start;
	uiItem* item;
	uiMenu* m;
	_4BC756EB7537E12A00FC57C6BF2CCA8B editor;

	_9B9540D9920A90D57A3D80DDD1A70514() = delete;
};

struct UnmappedUserType
{
	UnmappedUserType() = delete;

	intptr_t toPointer()
	{
		return (intptr_t)this;
	}
};

namespace EEex
{
	long MatchObject(lua_State* L, CGameObject* pStartObject, const char* matchChunk, int nNearest, int range, EEex_MatchObjectFlags flags);
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

	mosHeader_st() = delete;
};

struct sequenceTableEntry_st
{
	__int16 nFrames;
	unsigned __int16 nStartingFrame;

	sequenceTableEntry_st() = delete;
};

struct st_tiledef
{
	int nTile;
	int nUsageCount;
	int texture;
	CInfTileSet* pTileSet;

	st_tiledef() = delete;
};

struct CRect : tagRECT
{
	CRect() = delete;
};

struct CRainStorm
{
	CRainDrop* m_pRainDrops;
	unsigned __int16 m_nCurrentDensity;
	CRect m_rOldWorldViewPort;
	__int16 m_nWindGustCounter;
	int m_nRainDrops;

	CRainStorm() = delete;
};

struct CSnowStorm
{
	CSnowFlake* m_pSnowFlakes;
	unsigned __int16 m_nCurrentDensity;
	CRect m_rOldWorldViewPort;

	CSnowStorm() = delete;
};

struct CSize : tagSIZE
{
	CSize() = delete;
};

struct uiColumn
{
	uiVariant* width;
	uiItem* items;
	uiColumn* next;

	uiColumn() = delete;
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

enum class uiVariantType : __int32
{
	UIVAR_INT = 0,
	UIVAR_FUNCTION = 1,
	UIVAR_STRING = 2,
	UIVAR_FLOAT = 3,
};

struct view_t
{
	void* viewOfFile;
	unsigned int viewBase;
	unsigned int viewSize;
	int size;

	view_t() = delete;
};

struct CFileView
{
	file_t f;
	view_t v;
	int fileSize;
	int filePos;

	CFileView() = delete;
};

template<class POINTED_TO_TYPE>
struct Pointer
{
	POINTED_TO_TYPE* reference;

	Pointer() = delete;

	POINTED_TO_TYPE getValue()
	{
		return *reference;
	}

	void setValue(POINTED_TO_TYPE val)
	{
		*reference = val;
	}
};

struct ConstCharString
{
	const char* data;

	ConstCharString() = delete;

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

struct uiVariant
{
	union value_t
	{
		int intVal;
		const char* strVal;
		float floatVal;
		int luaFunc;

		value_t() = delete;
	};

	uiVariantType type;
	uiVariant::value_t value;

	uiVariant() = delete;
};

struct Marker
{
	const char* src;
	int start;
	int count;
	int line;

	Marker() = delete;
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

	uiMenu() = delete;
};

struct ISteamRemoteStorage
{
	struct vtbl
	{
		bool (__fastcall *FileWrite)(ISteamRemoteStorage*, const char*, const void*, int);
		int (__fastcall *FileRead)(ISteamRemoteStorage*, const char*, void*, int);
		unsigned __int64 (__fastcall *FileWriteAsync)(ISteamRemoteStorage*, const char*, const void*, unsigned int);
		unsigned __int64 (__fastcall *FileReadAsync)(ISteamRemoteStorage*, const char*, unsigned int, unsigned int);
		bool (__fastcall *FileReadAsyncComplete)(ISteamRemoteStorage*, unsigned __int64, void*, unsigned int);
		bool (__fastcall *FileForget)(ISteamRemoteStorage*, const char*);
		bool (__fastcall *FileDelete)(ISteamRemoteStorage*, const char*);
		unsigned __int64 (__fastcall *FileShare)(ISteamRemoteStorage*, const char*);
		bool (__fastcall *SetSyncPlatforms)(ISteamRemoteStorage*, const char*, ERemoteStoragePlatform);
		unsigned __int64 (__fastcall *FileWriteStreamOpen)(ISteamRemoteStorage*, const char*);
		bool (__fastcall *FileWriteStreamWriteChunk)(ISteamRemoteStorage*, unsigned __int64, const void*, int);
		bool (__fastcall *FileWriteStreamClose)(ISteamRemoteStorage*, unsigned __int64);
		bool (__fastcall *FileWriteStreamCancel)(ISteamRemoteStorage*, unsigned __int64);
		bool (__fastcall *FileExists)(ISteamRemoteStorage*, const char*);
		bool (__fastcall *FilePersisted)(ISteamRemoteStorage*, const char*);
		int (__fastcall *GetFileSize)(ISteamRemoteStorage*, const char*);
		__int64 (__fastcall *GetFileTimestamp)(ISteamRemoteStorage*, const char*);
		ERemoteStoragePlatform (__fastcall *GetSyncPlatforms)(ISteamRemoteStorage*, const char*);
		int (__fastcall *GetFileCount)(ISteamRemoteStorage*);
		const char* (__fastcall *GetFileNameAndSize)(ISteamRemoteStorage*, int, int*);
		bool (__fastcall *GetQuota)(ISteamRemoteStorage*, unsigned __int64*, unsigned __int64*);
		bool (__fastcall *IsCloudEnabledForAccount)(ISteamRemoteStorage*);
		bool (__fastcall *IsCloudEnabledForApp)(ISteamRemoteStorage*);
		void (__fastcall *SetCloudEnabledForApp)(ISteamRemoteStorage*, bool);
		unsigned __int64 (__fastcall *UGCDownload)(ISteamRemoteStorage*, unsigned __int64, unsigned int);
		bool (__fastcall *GetUGCDownloadProgress)(ISteamRemoteStorage*, unsigned __int64, int*, int*);
		bool (__fastcall *GetUGCDetails)(ISteamRemoteStorage*, unsigned __int64, unsigned int*, char**, int*, CSteamID*);
		int (__fastcall *UGCRead)(ISteamRemoteStorage*, unsigned __int64, void*, int, unsigned int, EUGCReadAction);
		int (__fastcall *GetCachedUGCCount)(ISteamRemoteStorage*);
		unsigned __int64 (__fastcall *GetCachedUGCHandle)(ISteamRemoteStorage*, int);
		unsigned __int64 (__fastcall *PublishWorkshopFile)(ISteamRemoteStorage*, const char*, const char*, unsigned int, const char*, const char*, ERemoteStoragePublishedFileVisibility, SteamParamStringArray_t*, EWorkshopFileType);
		unsigned __int64 (__fastcall *CreatePublishedFileUpdateRequest)(ISteamRemoteStorage*, unsigned __int64);
		bool (__fastcall *UpdatePublishedFileFile)(ISteamRemoteStorage*, unsigned __int64, const char*);
		bool (__fastcall *UpdatePublishedFilePreviewFile)(ISteamRemoteStorage*, unsigned __int64, const char*);
		bool (__fastcall *UpdatePublishedFileTitle)(ISteamRemoteStorage*, unsigned __int64, const char*);
		bool (__fastcall *UpdatePublishedFileDescription)(ISteamRemoteStorage*, unsigned __int64, const char*);
		bool (__fastcall *UpdatePublishedFileVisibility)(ISteamRemoteStorage*, unsigned __int64, ERemoteStoragePublishedFileVisibility);
		bool (__fastcall *UpdatePublishedFileTags)(ISteamRemoteStorage*, unsigned __int64, SteamParamStringArray_t*);
		unsigned __int64 (__fastcall *CommitPublishedFileUpdate)(ISteamRemoteStorage*, unsigned __int64);
		unsigned __int64 (__fastcall *GetPublishedFileDetails)(ISteamRemoteStorage*, unsigned __int64, unsigned int);
		unsigned __int64 (__fastcall *DeletePublishedFile)(ISteamRemoteStorage*, unsigned __int64);
		unsigned __int64 (__fastcall *EnumerateUserPublishedFiles)(ISteamRemoteStorage*, unsigned int);
		unsigned __int64 (__fastcall *SubscribePublishedFile)(ISteamRemoteStorage*, unsigned __int64);
		unsigned __int64 (__fastcall *EnumerateUserSubscribedFiles)(ISteamRemoteStorage*, unsigned int);
		unsigned __int64 (__fastcall *UnsubscribePublishedFile)(ISteamRemoteStorage*, unsigned __int64);
		bool (__fastcall *UpdatePublishedFileSetChangeDescription)(ISteamRemoteStorage*, unsigned __int64, const char*);
		unsigned __int64 (__fastcall *GetPublishedItemVoteDetails)(ISteamRemoteStorage*, unsigned __int64);
		unsigned __int64 (__fastcall *UpdateUserPublishedItemVote)(ISteamRemoteStorage*, unsigned __int64, bool);
		unsigned __int64 (__fastcall *GetUserPublishedItemVoteDetails)(ISteamRemoteStorage*, unsigned __int64);
		unsigned __int64 (__fastcall *EnumerateUserSharedWorkshopFiles)(ISteamRemoteStorage*, CSteamID, unsigned int, SteamParamStringArray_t*, SteamParamStringArray_t*);
		unsigned __int64 (__fastcall *PublishVideo)(ISteamRemoteStorage*, EWorkshopVideoProvider, const char*, const char*, const char*, unsigned int, const char*, const char*, ERemoteStoragePublishedFileVisibility, SteamParamStringArray_t*);
		unsigned __int64 (__fastcall *SetUserPublishedFileAction)(ISteamRemoteStorage*, unsigned __int64, EWorkshopFileAction);
		unsigned __int64 (__fastcall *EnumeratePublishedFilesByUserAction)(ISteamRemoteStorage*, EWorkshopFileAction, unsigned int);
		unsigned __int64 (__fastcall *EnumeratePublishedWorkshopFiles)(ISteamRemoteStorage*, EWorkshopEnumerationType, unsigned int, unsigned int, unsigned int, SteamParamStringArray_t*, SteamParamStringArray_t*);
		unsigned __int64 (__fastcall *UGCDownloadToLocation)(ISteamRemoteStorage*, unsigned __int64, const char*, unsigned int);

		vtbl() = delete;
	};

	ISteamRemoteStorage() = delete;

	virtual bool virtual_FileWrite(const char* _0, const void* _1, int _2)
	{
		return *(bool*)nullptr;
	}

	virtual int virtual_FileRead(const char* _0, void* _1, int _2)
	{
		return *(int*)nullptr;
	}

	virtual unsigned __int64 virtual_FileWriteAsync(const char* _0, const void* _1, unsigned int _2)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_FileReadAsync(const char* _0, unsigned int _1, unsigned int _2)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool virtual_FileReadAsyncComplete(unsigned __int64 _0, void* _1, unsigned int _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_FileForget(const char* _0)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_FileDelete(const char* _0)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 virtual_FileShare(const char* _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool virtual_SetSyncPlatforms(const char* _0, ERemoteStoragePlatform _1)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 virtual_FileWriteStreamOpen(const char* _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool virtual_FileWriteStreamWriteChunk(unsigned __int64 _0, const void* _1, int _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_FileWriteStreamClose(unsigned __int64 _0)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_FileWriteStreamCancel(unsigned __int64 _0)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_FileExists(const char* _0)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_FilePersisted(const char* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int virtual_GetFileSize(const char* _0)
	{
		return *(int*)nullptr;
	}

	virtual __int64 virtual_GetFileTimestamp(const char* _0)
	{
		return *(__int64*)nullptr;
	}

	virtual ERemoteStoragePlatform virtual_GetSyncPlatforms(const char* _0)
	{
		return *(ERemoteStoragePlatform*)nullptr;
	}

	virtual int virtual_GetFileCount()
	{
		return *(int*)nullptr;
	}

	virtual const char* virtual_GetFileNameAndSize(int _0, int* _1)
	{
		return *(const char**)nullptr;
	}

	virtual bool virtual_GetQuota(unsigned __int64* _0, unsigned __int64* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_IsCloudEnabledForAccount()
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_IsCloudEnabledForApp()
	{
		return *(bool*)nullptr;
	}

	virtual void virtual_SetCloudEnabledForApp(bool _0)
	{
	}

	virtual unsigned __int64 virtual_UGCDownload(unsigned __int64 _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool virtual_GetUGCDownloadProgress(unsigned __int64 _0, int* _1, int* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_GetUGCDetails(unsigned __int64 _0, unsigned int* _1, char** _2, int* _3, CSteamID* _4)
	{
		return *(bool*)nullptr;
	}

	virtual int virtual_UGCRead(unsigned __int64 _0, void* _1, int _2, unsigned int _3, EUGCReadAction _4)
	{
		return *(int*)nullptr;
	}

	virtual int virtual_GetCachedUGCCount()
	{
		return *(int*)nullptr;
	}

	virtual unsigned __int64 virtual_GetCachedUGCHandle(int _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_PublishWorkshopFile(const char* _0, const char* _1, unsigned int _2, const char* _3, const char* _4, ERemoteStoragePublishedFileVisibility _5, SteamParamStringArray_t* _6, EWorkshopFileType _7)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_CreatePublishedFileUpdateRequest(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool virtual_UpdatePublishedFileFile(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_UpdatePublishedFilePreviewFile(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_UpdatePublishedFileTitle(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_UpdatePublishedFileDescription(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_UpdatePublishedFileVisibility(unsigned __int64 _0, ERemoteStoragePublishedFileVisibility _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_UpdatePublishedFileTags(unsigned __int64 _0, SteamParamStringArray_t* _1)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 virtual_CommitPublishedFileUpdate(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_GetPublishedFileDetails(unsigned __int64 _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_DeletePublishedFile(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_EnumerateUserPublishedFiles(unsigned int _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_SubscribePublishedFile(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_EnumerateUserSubscribedFiles(unsigned int _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_UnsubscribePublishedFile(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool virtual_UpdatePublishedFileSetChangeDescription(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 virtual_GetPublishedItemVoteDetails(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_UpdateUserPublishedItemVote(unsigned __int64 _0, bool _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_GetUserPublishedItemVoteDetails(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_EnumerateUserSharedWorkshopFiles(CSteamID _0, unsigned int _1, SteamParamStringArray_t* _2, SteamParamStringArray_t* _3)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_PublishVideo(EWorkshopVideoProvider _0, const char* _1, const char* _2, const char* _3, unsigned int _4, const char* _5, const char* _6, ERemoteStoragePublishedFileVisibility _7, SteamParamStringArray_t* _8)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_SetUserPublishedFileAction(unsigned __int64 _0, EWorkshopFileAction _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_EnumeratePublishedFilesByUserAction(EWorkshopFileAction _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType _0, unsigned int _1, unsigned int _2, unsigned int _3, SteamParamStringArray_t* _4, SteamParamStringArray_t* _5)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_UGCDownloadToLocation(unsigned __int64 _0, const char* _1, unsigned int _2)
	{
		return *(unsigned __int64*)nullptr;
	}
};

struct IDPProvider
{
	struct vtbl
	{
		void (__fastcall *Connect)(IDPProvider*, int, const char*);
		bool (__fastcall *IsConnected)(IDPProvider*);
		void (__fastcall *Listen)(IDPProvider*, int, const char*);
		bool (__fastcall *Pump)(IDPProvider*, DP_Event*);
		void (__fastcall *Close)(IDPProvider*);
		void (__fastcall *RequestSessionDetails)(IDPProvider*, int);
		void (__fastcall *AllowJoin)(IDPProvider*, bool);
		void (__fastcall *SetVersion)(IDPProvider*, const char*);
		bool (__fastcall *IsBackendConnected)(IDPProvider*);
		void (__fastcall *Destruct)(IDPProvider*);

		vtbl() = delete;
	};

	IDPProvider() = delete;

	virtual void virtual_Connect(int _0, const char* _1)
	{
	}

	virtual bool virtual_IsConnected()
	{
		return *(bool*)nullptr;
	}

	virtual void virtual_Listen(int _0, const char* _1)
	{
	}

	virtual bool virtual_Pump(DP_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void virtual_Close()
	{
	}

	virtual void virtual_RequestSessionDetails(int _0)
	{
	}

	virtual void virtual_AllowJoin(bool _0)
	{
	}

	virtual void virtual_SetVersion(const char* _0)
	{
	}

	virtual bool virtual_IsBackendConnected()
	{
		return *(bool*)nullptr;
	}

	virtual void virtual_Destruct()
	{
	}
};

struct CharString
{
	char* data;

	CharString() = delete;

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

	void getL(lua_State* L, size_t length)
	{
		char* localCopy = (char*)alloca(length + 1);
		int i = 0;
		for (; i < length; ++i) {
			char readVal = data[i];
			if (readVal == '\0')
				break;
			localCopy[i] = readVal;
		}
		localCopy[i] = '\0';
		p_lua_pushstring(L, localCopy);
	}

	void free()
	{
		if (data) {
			p_free(data);
		}
	}
};

struct SDL_WindowUserData
{
	char* name;
	void* data;
	SDL_WindowUserData* next;

	SDL_WindowUserData() = delete;
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

	SDL_Window() = delete;
};

struct SDL_DropEvent
{
	unsigned int type;
	unsigned int timestamp;
	char* file;

	SDL_DropEvent() = delete;
};

struct ISteamUserStats
{
	struct vtbl
	{
		bool (__fastcall *RequestCurrentStats)(ISteamUserStats*);
		bool (__fastcall *GetStat)(ISteamUserStats*, const char*, float*);
		bool (__fastcall *GetStat_2)(ISteamUserStats*, const char*, int*);
		bool (__fastcall *SetStat)(ISteamUserStats*, const char*, float);
		bool (__fastcall *SetStat_2)(ISteamUserStats*, const char*, int);
		bool (__fastcall *UpdateAvgRateStat)(ISteamUserStats*, const char*, float, long double);
		bool (__fastcall *GetAchievement)(ISteamUserStats*, const char*, bool*);
		bool (__fastcall *SetAchievement)(ISteamUserStats*, const char*);
		bool (__fastcall *ClearAchievement)(ISteamUserStats*, const char*);
		bool (__fastcall *GetAchievementAndUnlockTime)(ISteamUserStats*, const char*, bool*, unsigned int*);
		bool (__fastcall *StoreStats)(ISteamUserStats*);
		int (__fastcall *GetAchievementIcon)(ISteamUserStats*, const char*);
		const char* (__fastcall *GetAchievementDisplayAttribute)(ISteamUserStats*, const char*, const char*);
		bool (__fastcall *IndicateAchievementProgress)(ISteamUserStats*, const char*, unsigned int, unsigned int);
		unsigned int (__fastcall *GetNumAchievements)(ISteamUserStats*);
		const char* (__fastcall *GetAchievementName)(ISteamUserStats*, unsigned int);
		unsigned __int64 (__fastcall *RequestUserStats)(ISteamUserStats*, CSteamID);
		bool (__fastcall *GetUserStat)(ISteamUserStats*, CSteamID, const char*, float*);
		bool (__fastcall *GetUserStat_2)(ISteamUserStats*, CSteamID, const char*, int*);
		bool (__fastcall *GetUserAchievement)(ISteamUserStats*, CSteamID, const char*, bool*);
		bool (__fastcall *GetUserAchievementAndUnlockTime)(ISteamUserStats*, CSteamID, const char*, bool*, unsigned int*);
		bool (__fastcall *ResetAllStats)(ISteamUserStats*, bool);
		unsigned __int64 (__fastcall *FindOrCreateLeaderboard)(ISteamUserStats*, const char*, ELeaderboardSortMethod, ELeaderboardDisplayType);
		unsigned __int64 (__fastcall *FindLeaderboard)(ISteamUserStats*, const char*);
		const char* (__fastcall *GetLeaderboardName)(ISteamUserStats*, unsigned __int64);
		int (__fastcall *GetLeaderboardEntryCount)(ISteamUserStats*, unsigned __int64);
		ELeaderboardSortMethod (__fastcall *GetLeaderboardSortMethod)(ISteamUserStats*, unsigned __int64);
		ELeaderboardDisplayType (__fastcall *GetLeaderboardDisplayType)(ISteamUserStats*, unsigned __int64);
		unsigned __int64 (__fastcall *DownloadLeaderboardEntries)(ISteamUserStats*, unsigned __int64, ELeaderboardDataRequest, int, int);
		unsigned __int64 (__fastcall *DownloadLeaderboardEntriesForUsers)(ISteamUserStats*, unsigned __int64, CSteamID*, int);
		bool (__fastcall *GetDownloadedLeaderboardEntry)(ISteamUserStats*, unsigned __int64, int, LeaderboardEntry_t*, int*, int);
		unsigned __int64 (__fastcall *UploadLeaderboardScore)(ISteamUserStats*, unsigned __int64, ELeaderboardUploadScoreMethod, int, const int*, int);
		unsigned __int64 (__fastcall *AttachLeaderboardUGC)(ISteamUserStats*, unsigned __int64, unsigned __int64);
		unsigned __int64 (__fastcall *GetNumberOfCurrentPlayers)(ISteamUserStats*);
		unsigned __int64 (__fastcall *RequestGlobalAchievementPercentages)(ISteamUserStats*);
		int (__fastcall *GetMostAchievedAchievementInfo)(ISteamUserStats*, char*, unsigned int, float*, bool*);
		int (__fastcall *GetNextMostAchievedAchievementInfo)(ISteamUserStats*, int, char*, unsigned int, float*, bool*);
		bool (__fastcall *GetAchievementAchievedPercent)(ISteamUserStats*, const char*, float*);
		unsigned __int64 (__fastcall *RequestGlobalStats)(ISteamUserStats*, int);
		bool (__fastcall *GetGlobalStat)(ISteamUserStats*, const char*, long double*);
		bool (__fastcall *GetGlobalStat_2)(ISteamUserStats*, const char*, __int64*);
		int (__fastcall *GetGlobalStatHistory)(ISteamUserStats*, const char*, long double*, unsigned int);
		int (__fastcall *GetGlobalStatHistory_2)(ISteamUserStats*, const char*, __int64*, unsigned int);
		bool (__fastcall *GetAchievementProgressLimits)(ISteamUserStats*, const char*, float*, float*);
		bool (__fastcall *GetAchievementProgressLimits_2)(ISteamUserStats*, const char*, int*, int*);

		vtbl() = delete;
	};

	ISteamUserStats() = delete;

	virtual bool virtual_RequestCurrentStats()
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_GetStat(const char* _0, float* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_GetStat_2(const char* _0, int* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetStat(const char* _0, float _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetStat_2(const char* _0, int _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_UpdateAvgRateStat(const char* _0, float _1, long double _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_GetAchievement(const char* _0, bool* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetAchievement(const char* _0)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_ClearAchievement(const char* _0)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_GetAchievementAndUnlockTime(const char* _0, bool* _1, unsigned int* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_StoreStats()
	{
		return *(bool*)nullptr;
	}

	virtual int virtual_GetAchievementIcon(const char* _0)
	{
		return *(int*)nullptr;
	}

	virtual const char* virtual_GetAchievementDisplayAttribute(const char* _0, const char* _1)
	{
		return *(const char**)nullptr;
	}

	virtual bool virtual_IndicateAchievementProgress(const char* _0, unsigned int _1, unsigned int _2)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned int virtual_GetNumAchievements()
	{
		return *(unsigned int*)nullptr;
	}

	virtual const char* virtual_GetAchievementName(unsigned int _0)
	{
		return *(const char**)nullptr;
	}

	virtual unsigned __int64 virtual_RequestUserStats(CSteamID _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool virtual_GetUserStat(CSteamID _0, const char* _1, float* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_GetUserStat_2(CSteamID _0, const char* _1, int* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_GetUserAchievement(CSteamID _0, const char* _1, bool* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_GetUserAchievementAndUnlockTime(CSteamID _0, const char* _1, bool* _2, unsigned int* _3)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_ResetAllStats(bool _0)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 virtual_FindOrCreateLeaderboard(const char* _0, ELeaderboardSortMethod _1, ELeaderboardDisplayType _2)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_FindLeaderboard(const char* _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual const char* virtual_GetLeaderboardName(unsigned __int64 _0)
	{
		return *(const char**)nullptr;
	}

	virtual int virtual_GetLeaderboardEntryCount(unsigned __int64 _0)
	{
		return *(int*)nullptr;
	}

	virtual ELeaderboardSortMethod virtual_GetLeaderboardSortMethod(unsigned __int64 _0)
	{
		return *(ELeaderboardSortMethod*)nullptr;
	}

	virtual ELeaderboardDisplayType virtual_GetLeaderboardDisplayType(unsigned __int64 _0)
	{
		return *(ELeaderboardDisplayType*)nullptr;
	}

	virtual unsigned __int64 virtual_DownloadLeaderboardEntries(unsigned __int64 _0, ELeaderboardDataRequest _1, int _2, int _3)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_DownloadLeaderboardEntriesForUsers(unsigned __int64 _0, CSteamID* _1, int _2)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool virtual_GetDownloadedLeaderboardEntry(unsigned __int64 _0, int _1, LeaderboardEntry_t* _2, int* _3, int _4)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 virtual_UploadLeaderboardScore(unsigned __int64 _0, ELeaderboardUploadScoreMethod _1, int _2, const int* _3, int _4)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_AttachLeaderboardUGC(unsigned __int64 _0, unsigned __int64 _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_GetNumberOfCurrentPlayers()
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_RequestGlobalAchievementPercentages()
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual int virtual_GetMostAchievedAchievementInfo(char* _0, unsigned int _1, float* _2, bool* _3)
	{
		return *(int*)nullptr;
	}

	virtual int virtual_GetNextMostAchievedAchievementInfo(int _0, char* _1, unsigned int _2, float* _3, bool* _4)
	{
		return *(int*)nullptr;
	}

	virtual bool virtual_GetAchievementAchievedPercent(const char* _0, float* _1)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 virtual_RequestGlobalStats(int _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool virtual_GetGlobalStat(const char* _0, long double* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_GetGlobalStat_2(const char* _0, __int64* _1)
	{
		return *(bool*)nullptr;
	}

	virtual int virtual_GetGlobalStatHistory(const char* _0, long double* _1, unsigned int _2)
	{
		return *(int*)nullptr;
	}

	virtual int virtual_GetGlobalStatHistory_2(const char* _0, __int64* _1, unsigned int _2)
	{
		return *(int*)nullptr;
	}

	virtual bool virtual_GetAchievementProgressLimits(const char* _0, float* _1, float* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_GetAchievementProgressLimits_2(const char* _0, int* _1, int* _2)
	{
		return *(bool*)nullptr;
	}
};

struct ISteamUGC
{
	struct vtbl
	{
		unsigned __int64 (__fastcall *CreateQueryUserUGCRequest)(ISteamUGC*, unsigned int, EUserUGCList, EUGCMatchingUGCType, EUserUGCListSortOrder, unsigned int, unsigned int, unsigned int);
		unsigned __int64 (__fastcall *CreateQueryAllUGCRequest)(ISteamUGC*, EUGCQuery, EUGCMatchingUGCType, unsigned int, unsigned int, const char*);
		unsigned __int64 (__fastcall *CreateQueryAllUGCRequest_2)(ISteamUGC*, EUGCQuery, EUGCMatchingUGCType, unsigned int, unsigned int, unsigned int);
		unsigned __int64 (__fastcall *CreateQueryUGCDetailsRequest)(ISteamUGC*, unsigned __int64*, unsigned int);
		unsigned __int64 (__fastcall *SendQueryUGCRequest)(ISteamUGC*, unsigned __int64);
		bool (__fastcall *GetQueryUGCResult)(ISteamUGC*, unsigned __int64, unsigned int, SteamUGCDetails_t*);
		bool (__fastcall *GetQueryUGCPreviewURL)(ISteamUGC*, unsigned __int64, unsigned int, char*, unsigned int);
		bool (__fastcall *GetQueryUGCMetadata)(ISteamUGC*, unsigned __int64, unsigned int, char*, unsigned int);
		bool (__fastcall *GetQueryUGCChildren)(ISteamUGC*, unsigned __int64, unsigned int, unsigned __int64*, unsigned int);
		bool (__fastcall *GetQueryUGCStatistic)(ISteamUGC*, unsigned __int64, unsigned int, EItemStatistic, unsigned __int64*);
		unsigned int (__fastcall *GetQueryUGCNumAdditionalPreviews)(ISteamUGC*, unsigned __int64, unsigned int);
		bool (__fastcall *GetQueryUGCAdditionalPreview)(ISteamUGC*, unsigned __int64, unsigned int, unsigned int, char*, unsigned int, char*, unsigned int, EItemPreviewType*);
		unsigned int (__fastcall *GetQueryUGCNumKeyValueTags)(ISteamUGC*, unsigned __int64, unsigned int);
		bool (__fastcall *GetQueryUGCKeyValueTag)(ISteamUGC*, unsigned __int64, unsigned int, const char*, char*, unsigned int);
		bool (__fastcall *GetQueryUGCKeyValueTag_2)(ISteamUGC*, unsigned __int64, unsigned int, unsigned int, char*, unsigned int, char*, unsigned int);
		bool (__fastcall *ReleaseQueryUGCRequest)(ISteamUGC*, unsigned __int64);
		bool (__fastcall *AddRequiredTag)(ISteamUGC*, unsigned __int64, const char*);
		bool (__fastcall *AddRequiredTagGroup)(ISteamUGC*, unsigned __int64, const SteamParamStringArray_t*);
		bool (__fastcall *AddExcludedTag)(ISteamUGC*, unsigned __int64, const char*);
		bool (__fastcall *SetReturnOnlyIDs)(ISteamUGC*, unsigned __int64, bool);
		bool (__fastcall *SetReturnKeyValueTags)(ISteamUGC*, unsigned __int64, bool);
		bool (__fastcall *SetReturnLongDescription)(ISteamUGC*, unsigned __int64, bool);
		bool (__fastcall *SetReturnMetadata)(ISteamUGC*, unsigned __int64, bool);
		bool (__fastcall *SetReturnChildren)(ISteamUGC*, unsigned __int64, bool);
		bool (__fastcall *SetReturnAdditionalPreviews)(ISteamUGC*, unsigned __int64, bool);
		bool (__fastcall *SetReturnTotalOnly)(ISteamUGC*, unsigned __int64, bool);
		bool (__fastcall *SetReturnPlaytimeStats)(ISteamUGC*, unsigned __int64, unsigned int);
		bool (__fastcall *SetLanguage)(ISteamUGC*, unsigned __int64, const char*);
		bool (__fastcall *SetAllowCachedResponse)(ISteamUGC*, unsigned __int64, unsigned int);
		bool (__fastcall *SetCloudFileNameFilter)(ISteamUGC*, unsigned __int64, const char*);
		bool (__fastcall *SetMatchAnyTag)(ISteamUGC*, unsigned __int64, bool);
		bool (__fastcall *SetSearchText)(ISteamUGC*, unsigned __int64, const char*);
		bool (__fastcall *SetRankedByTrendDays)(ISteamUGC*, unsigned __int64, unsigned int);
		bool (__fastcall *AddRequiredKeyValueTag)(ISteamUGC*, unsigned __int64, const char*, const char*);
		unsigned __int64 (__fastcall *RequestUGCDetails)(ISteamUGC*, unsigned __int64, unsigned int);
		unsigned __int64 (__fastcall *CreateItem)(ISteamUGC*, unsigned int, EWorkshopFileType);
		unsigned __int64 (__fastcall *StartItemUpdate)(ISteamUGC*, unsigned int, unsigned __int64);
		bool (__fastcall *SetItemTitle)(ISteamUGC*, unsigned __int64, const char*);
		bool (__fastcall *SetItemDescription)(ISteamUGC*, unsigned __int64, const char*);
		bool (__fastcall *SetItemUpdateLanguage)(ISteamUGC*, unsigned __int64, const char*);
		bool (__fastcall *SetItemMetadata)(ISteamUGC*, unsigned __int64, const char*);
		bool (__fastcall *SetItemVisibility)(ISteamUGC*, unsigned __int64, ERemoteStoragePublishedFileVisibility);
		bool (__fastcall *SetItemTags)(ISteamUGC*, unsigned __int64, const SteamParamStringArray_t*);
		bool (__fastcall *SetItemContent)(ISteamUGC*, unsigned __int64, const char*);
		bool (__fastcall *SetItemPreview)(ISteamUGC*, unsigned __int64, const char*);
		bool (__fastcall *SetAllowLegacyUpload)(ISteamUGC*, unsigned __int64, bool);
		bool (__fastcall *RemoveAllItemKeyValueTags)(ISteamUGC*, unsigned __int64);
		bool (__fastcall *RemoveItemKeyValueTags)(ISteamUGC*, unsigned __int64, const char*);
		bool (__fastcall *AddItemKeyValueTag)(ISteamUGC*, unsigned __int64, const char*, const char*);
		bool (__fastcall *AddItemPreviewFile)(ISteamUGC*, unsigned __int64, const char*, EItemPreviewType);
		bool (__fastcall *AddItemPreviewVideo)(ISteamUGC*, unsigned __int64, const char*);
		bool (__fastcall *UpdateItemPreviewFile)(ISteamUGC*, unsigned __int64, unsigned int, const char*);
		bool (__fastcall *UpdateItemPreviewVideo)(ISteamUGC*, unsigned __int64, unsigned int, const char*);
		bool (__fastcall *RemoveItemPreview)(ISteamUGC*, unsigned __int64, unsigned int);
		unsigned __int64 (__fastcall *SubmitItemUpdate)(ISteamUGC*, unsigned __int64, const char*);
		EItemUpdateStatus (__fastcall *GetItemUpdateProgress)(ISteamUGC*, unsigned __int64, unsigned __int64*, unsigned __int64*);
		unsigned __int64 (__fastcall *SetUserItemVote)(ISteamUGC*, unsigned __int64, bool);
		unsigned __int64 (__fastcall *GetUserItemVote)(ISteamUGC*, unsigned __int64);
		unsigned __int64 (__fastcall *AddItemToFavorites)(ISteamUGC*, unsigned int, unsigned __int64);
		unsigned __int64 (__fastcall *RemoveItemFromFavorites)(ISteamUGC*, unsigned int, unsigned __int64);
		unsigned __int64 (__fastcall *SubscribeItem)(ISteamUGC*, unsigned __int64);
		unsigned __int64 (__fastcall *UnsubscribeItem)(ISteamUGC*, unsigned __int64);
		unsigned int (__fastcall *GetNumSubscribedItems)(ISteamUGC*);
		unsigned int (__fastcall *GetSubscribedItems)(ISteamUGC*, unsigned __int64*, unsigned int);
		unsigned int (__fastcall *GetItemState)(ISteamUGC*, unsigned __int64);
		bool (__fastcall *GetItemInstallInfo)(ISteamUGC*, unsigned __int64, unsigned __int64*, char*, unsigned int, unsigned int*);
		bool (__fastcall *GetItemDownloadInfo)(ISteamUGC*, unsigned __int64, unsigned __int64*, unsigned __int64*);
		bool (__fastcall *DownloadItem)(ISteamUGC*, unsigned __int64, bool);
		bool (__fastcall *BInitWorkshopForGameServer)(ISteamUGC*, unsigned int, const char*);
		void (__fastcall *SuspendDownloads)(ISteamUGC*, bool);
		unsigned __int64 (__fastcall *StartPlaytimeTracking)(ISteamUGC*, unsigned __int64*, unsigned int);
		unsigned __int64 (__fastcall *StopPlaytimeTracking)(ISteamUGC*, unsigned __int64*, unsigned int);
		unsigned __int64 (__fastcall *StopPlaytimeTrackingForAllItems)(ISteamUGC*);
		unsigned __int64 (__fastcall *AddDependency)(ISteamUGC*, unsigned __int64, unsigned __int64);
		unsigned __int64 (__fastcall *RemoveDependency)(ISteamUGC*, unsigned __int64, unsigned __int64);
		unsigned __int64 (__fastcall *AddAppDependency)(ISteamUGC*, unsigned __int64, unsigned int);
		unsigned __int64 (__fastcall *RemoveAppDependency)(ISteamUGC*, unsigned __int64, unsigned int);
		unsigned __int64 (__fastcall *GetAppDependencies)(ISteamUGC*, unsigned __int64);
		unsigned __int64 (__fastcall *DeleteItem)(ISteamUGC*, unsigned __int64);

		vtbl() = delete;
	};

	ISteamUGC() = delete;

	virtual unsigned __int64 virtual_CreateQueryUserUGCRequest(unsigned int _0, EUserUGCList _1, EUGCMatchingUGCType _2, EUserUGCListSortOrder _3, unsigned int _4, unsigned int _5, unsigned int _6)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_CreateQueryAllUGCRequest(EUGCQuery _0, EUGCMatchingUGCType _1, unsigned int _2, unsigned int _3, const char* _4)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_CreateQueryAllUGCRequest_2(EUGCQuery _0, EUGCMatchingUGCType _1, unsigned int _2, unsigned int _3, unsigned int _4)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_CreateQueryUGCDetailsRequest(unsigned __int64* _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_SendQueryUGCRequest(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool virtual_GetQueryUGCResult(unsigned __int64 _0, unsigned int _1, SteamUGCDetails_t* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_GetQueryUGCPreviewURL(unsigned __int64 _0, unsigned int _1, char* _2, unsigned int _3)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_GetQueryUGCMetadata(unsigned __int64 _0, unsigned int _1, char* _2, unsigned int _3)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_GetQueryUGCChildren(unsigned __int64 _0, unsigned int _1, unsigned __int64* _2, unsigned int _3)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_GetQueryUGCStatistic(unsigned __int64 _0, unsigned int _1, EItemStatistic _2, unsigned __int64* _3)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned int virtual_GetQueryUGCNumAdditionalPreviews(unsigned __int64 _0, unsigned int _1)
	{
		return *(unsigned int*)nullptr;
	}

	virtual bool virtual_GetQueryUGCAdditionalPreview(unsigned __int64 _0, unsigned int _1, unsigned int _2, char* _3, unsigned int _4, char* _5, unsigned int _6, EItemPreviewType* _7)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned int virtual_GetQueryUGCNumKeyValueTags(unsigned __int64 _0, unsigned int _1)
	{
		return *(unsigned int*)nullptr;
	}

	virtual bool virtual_GetQueryUGCKeyValueTag(unsigned __int64 _0, unsigned int _1, const char* _2, char* _3, unsigned int _4)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_GetQueryUGCKeyValueTag_2(unsigned __int64 _0, unsigned int _1, unsigned int _2, char* _3, unsigned int _4, char* _5, unsigned int _6)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_ReleaseQueryUGCRequest(unsigned __int64 _0)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_AddRequiredTag(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_AddRequiredTagGroup(unsigned __int64 _0, const SteamParamStringArray_t* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_AddExcludedTag(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetReturnOnlyIDs(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetReturnKeyValueTags(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetReturnLongDescription(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetReturnMetadata(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetReturnChildren(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetReturnAdditionalPreviews(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetReturnTotalOnly(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetReturnPlaytimeStats(unsigned __int64 _0, unsigned int _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetLanguage(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetAllowCachedResponse(unsigned __int64 _0, unsigned int _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetCloudFileNameFilter(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetMatchAnyTag(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetSearchText(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetRankedByTrendDays(unsigned __int64 _0, unsigned int _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_AddRequiredKeyValueTag(unsigned __int64 _0, const char* _1, const char* _2)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 virtual_RequestUGCDetails(unsigned __int64 _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_CreateItem(unsigned int _0, EWorkshopFileType _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_StartItemUpdate(unsigned int _0, unsigned __int64 _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual bool virtual_SetItemTitle(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetItemDescription(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetItemUpdateLanguage(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetItemMetadata(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetItemVisibility(unsigned __int64 _0, ERemoteStoragePublishedFileVisibility _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetItemTags(unsigned __int64 _0, const SteamParamStringArray_t* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetItemContent(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetItemPreview(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_SetAllowLegacyUpload(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_RemoveAllItemKeyValueTags(unsigned __int64 _0)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_RemoveItemKeyValueTags(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_AddItemKeyValueTag(unsigned __int64 _0, const char* _1, const char* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_AddItemPreviewFile(unsigned __int64 _0, const char* _1, EItemPreviewType _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_AddItemPreviewVideo(unsigned __int64 _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_UpdateItemPreviewFile(unsigned __int64 _0, unsigned int _1, const char* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_UpdateItemPreviewVideo(unsigned __int64 _0, unsigned int _1, const char* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_RemoveItemPreview(unsigned __int64 _0, unsigned int _1)
	{
		return *(bool*)nullptr;
	}

	virtual unsigned __int64 virtual_SubmitItemUpdate(unsigned __int64 _0, const char* _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual EItemUpdateStatus virtual_GetItemUpdateProgress(unsigned __int64 _0, unsigned __int64* _1, unsigned __int64* _2)
	{
		return *(EItemUpdateStatus*)nullptr;
	}

	virtual unsigned __int64 virtual_SetUserItemVote(unsigned __int64 _0, bool _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_GetUserItemVote(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_AddItemToFavorites(unsigned int _0, unsigned __int64 _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_RemoveItemFromFavorites(unsigned int _0, unsigned __int64 _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_SubscribeItem(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_UnsubscribeItem(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned int virtual_GetNumSubscribedItems()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int virtual_GetSubscribedItems(unsigned __int64* _0, unsigned int _1)
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int virtual_GetItemState(unsigned __int64 _0)
	{
		return *(unsigned int*)nullptr;
	}

	virtual bool virtual_GetItemInstallInfo(unsigned __int64 _0, unsigned __int64* _1, char* _2, unsigned int _3, unsigned int* _4)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_GetItemDownloadInfo(unsigned __int64 _0, unsigned __int64* _1, unsigned __int64* _2)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_DownloadItem(unsigned __int64 _0, bool _1)
	{
		return *(bool*)nullptr;
	}

	virtual bool virtual_BInitWorkshopForGameServer(unsigned int _0, const char* _1)
	{
		return *(bool*)nullptr;
	}

	virtual void virtual_SuspendDownloads(bool _0)
	{
	}

	virtual unsigned __int64 virtual_StartPlaytimeTracking(unsigned __int64* _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_StopPlaytimeTracking(unsigned __int64* _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_StopPlaytimeTrackingForAllItems()
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_AddDependency(unsigned __int64 _0, unsigned __int64 _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_RemoveDependency(unsigned __int64 _0, unsigned __int64 _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_AddAppDependency(unsigned __int64 _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_RemoveAppDependency(unsigned __int64 _0, unsigned int _1)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_GetAppDependencies(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}

	virtual unsigned __int64 virtual_DeleteItem(unsigned __int64 _0)
	{
		return *(unsigned __int64*)nullptr;
	}
};

struct IDPPeer
{
	struct vtbl
	{
		void (__fastcall *Send)(IDPPeer*, DP_Packet*, int);
		DP_Packet* (__fastcall *GetFrontPacket)(IDPPeer*);
		int (__fastcall *HasData)(IDPPeer*);
		void (__fastcall *Disconnect)(IDPPeer*);
		void (__fastcall *GetAddress)(IDPPeer*, char*, unsigned __int64);
		void (__fastcall *Destruct)(IDPPeer*);

		vtbl() = delete;
	};

	int m_packetSentCount;
	int m_packetReceivedCount;

	IDPPeer() = delete;

	virtual void virtual_Send(DP_Packet* _0, int _1)
	{
	}

	virtual DP_Packet* virtual_GetFrontPacket()
	{
		return *(DP_Packet**)nullptr;
	}

	virtual int virtual_HasData()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_Disconnect()
	{
	}

	virtual void virtual_GetAddress(char* _0, unsigned __int64 _1)
	{
	}

	virtual void virtual_Destruct()
	{
	}
};

struct CVidPoly
{
	CVIDPOLY_VERTEX* m_pVertices;
	int m_nVertices;
	_EdgeDescription* m_pET;
	_EdgeDescription* m_pAET;
	void (__fastcall *m_pDrawHLineFunction)(CVidPoly*, void*, int, int, unsigned int, const CRect*, const CPoint*);

	CVidPoly() = delete;
};

struct CString
{
	char* m_pchData;

	CString() = delete;

	typedef void (__thiscall *type_ConstructFromChars)(CString* pThis, const char* lpsz);
	static type_ConstructFromChars p_ConstructFromChars;

	typedef void (__thiscall *type_Destruct)(CString* pThis);
	static type_Destruct p_Destruct;

	void Construct(const char* lpsz)
	{
		p_ConstructFromChars(this, lpsz);
	}

	void Destruct()
	{
		p_Destruct(this);
	}
};

struct CAIId
{
	int m_id;
	CString m_line;
	CString m_start;

	CAIId() = delete;
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

	CFeedbackEntry() = delete;
};

struct CNetworkConnectionSettings
{
	unsigned int dwFlags;
	unsigned int dwMaxPlayers;
	CString sPlayerName;

	CNetworkConnectionSettings() = delete;
};

struct CSpawnVar
{
	CString mScope;
	CString mLabel;

	CSpawnVar() = delete;
};

struct CSpawnPointVar : CSpawnVar
{
	CSpawnPointVar() = delete;
};

struct CRes
{
	struct vtbl
	{
		bool (__fastcall *Parse)(CRes*, void*);
		void (__fastcall *Dump)(CRes*);
		CResRef* (__fastcall *GetResRef)(CRes*, CResRef*);

		vtbl() = delete;
	};

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

	CRes() = delete;

	typedef void (__thiscall *type_Construct)(CRes* pThis);
	static type_Construct p_Construct;

	typedef void (__thiscall *type_Destruct)(CRes* pThis);
	static type_Destruct p_Destruct;

	typedef void* (__thiscall *type_Demand)(CRes* pThis);
	static type_Demand p_Demand;

	void Construct()
	{
		p_Construct(this);
	}

	void Destruct()
	{
		p_Destruct(this);
	}

	void* Demand()
	{
		return p_Demand(this);
	}

	virtual bool virtual_Parse(void* _0)
	{
		return *(bool*)nullptr;
	}

	virtual void virtual_Dump()
	{
	}

	virtual CResRef* virtual_GetResRef()
	{
		return *(CResRef**)nullptr;
	}
};

struct CResWebm : CRes
{
	struct vtbl : CRes::vtbl
	{
		vtbl() = delete;
	};

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

	CResWebm() = delete;
};

struct CResWave : CRes
{
	struct vtbl : CRes::vtbl
	{
		vtbl() = delete;
	};

	int m_bCompressed;
	int m_bIsOgg;
	unsigned int m_nWaveNormalSize;
	unsigned int m_nWaveCompressedSize;
	unsigned __int8* m_pWaveData;
	WAV_Header* m_pWaveFormatEx;

	CResWave() = delete;
};

struct CResWED : CRes
{
	struct vtbl : CRes::vtbl
	{
		vtbl() = delete;
	};

	WED_WedHeader_st* pWEDHeader;
	WED_LayerHeader_st* pLayers;
	WED_PolyHeader_st* pPolyHeader;
	WED_ScreenSectionList* pScreenSectionList;
	WED_PolyList_st* pPolyList;
	WED_PolyPoint_st* pPolyPoints;

	CResWED() = delete;
};

struct CResTileSet : CRes
{
	struct vtbl : CRes::vtbl
	{
		vtbl() = delete;
	};

	ResFixedHeader_st* h;

	CResTileSet() = delete;
};

struct CResText : CRes
{
	struct vtbl : CRes::vtbl
	{
		vtbl() = delete;
	};

	CString m_string;

	CResText() = delete;
};

struct CResSpell : CRes
{
	struct vtbl : CRes::vtbl
	{
		vtbl() = delete;
	};

	Spell_ability_st* pAbilities;
	Item_effect_st* pEffects;
	Spell_Header_st* pHeader;

	CResSpell() = delete;
};

struct CResPVR : CRes
{
	struct vtbl : CRes::vtbl
	{
		vtbl() = delete;
	};

	int texture;
	int format;
	int filtering;
	CSize size;

	CResPVR() = delete;
};

struct CResMosaic : CRes
{
	struct vtbl : CRes::vtbl
	{
		vtbl() = delete;
	};

	void* pUncompressedData;
	unsigned int nUncompressedSize;
	int texture;
	MOSAICHEADERV2* pMosaicHeaderV2;
	MOSAICQUAD* quads;
	mosHeader_st* pMosaicHeader;
	tagRGBQUAD* pPalettes;
	unsigned __int8* m_pData;
	unsigned int* pOffsets;

	CResMosaic() = delete;
};

struct CResItem : CRes
{
	struct vtbl : CRes::vtbl
	{
		vtbl() = delete;
	};

	Item_ability_st* pAbilities;
	Item_effect_st* pEffects;
	Item_Header_st* pHeader;

	CResItem() = delete;
};

struct CResGame : CRes
{
	struct vtbl : CRes::vtbl
	{
		vtbl() = delete;
	};

	CResGame() = delete;
};

struct CResFont : CRes
{
	struct vtbl : CRes::vtbl
	{
		vtbl() = delete;
	};

	void* font;

	CResFont() = delete;
};

struct CResCell : CRes
{
	struct vtbl : CRes::vtbl
	{
		vtbl() = delete;
	};

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

	CResCell() = delete;
};

struct CResBitmap : CRes
{
	struct vtbl : CRes::vtbl
	{
		vtbl() = delete;
	};

	unsigned __int8* m_pDataDecompressed;
	int texture;
	int nColors;
	int nXWords;
	unsigned __int8* m_pData;
	tagBITMAPFILEHEADER* pBitmapFileHeader;
	tagBITMAPINFOHEADER* pBitmapInfoHeader;
	tagRGBQUAD* pColorTable;

	CResBitmap() = delete;
};

struct CPoint
{
	int x;
	int y;

	CPoint()
	{
		this->x = 0;
		this->y = 0;
	}

	CPoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	CPoint(CPoint* point)
	{
		this->x = point->x;
		this->y = point->y;
	}
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

	CAOEEntry() = delete;
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

	CFog() = delete;
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

	CGameAreaClairvoyanceEntry() = delete;
};

struct MAP_CHAR_POSITIONS
{
	CPoint ptPos;
	int id;

	MAP_CHAR_POSITIONS() = delete;
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

	CVIDMODE_RETICLE_DESCRIPTION() = delete;
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

	CMarker() = delete;
};

struct CSpawnPoint
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CSpawnPoint*);

		vtbl() = delete;
	};

	CPoint mLocation;
	int mFacing;

	CSpawnPoint() = delete;

	virtual void virtual_Destruct()
	{
	}
};

struct CPersistantEffect
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CPersistantEffect*);
		void (__fastcall *AIUpdate)(CPersistantEffect*, CGameSprite*, int);
		CPersistantEffect* (__fastcall *Copy)(CPersistantEffect*);

		vtbl() = delete;
	};

	int m_done;
	int m_deleted;
	__int16 m_numDamage;
	__int16 m_persistantType;
	int m_sourceID;
	__int16 m_period;
	__int16 m_periodCounter;
	int m_counter;

	CPersistantEffect() = delete;

	virtual void virtual_Destruct()
	{
	}

	virtual void virtual_AIUpdate(CGameSprite* _0, int _1)
	{
	}

	virtual CPersistantEffect* virtual_Copy()
	{
		return *(CPersistantEffect**)nullptr;
	}
};

struct CObject
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CObject() = delete;

	virtual void virtual_Destruct()
	{
	}
};

template<class TYPE, class ARG_TYPE>
struct CArray : CObject
{
	TYPE* m_pData;
	int m_nSize;
	int m_nMaxSize;
	int m_nGrowBy;

	CArray() = delete;
};

struct CDWordArray : CObject
{
	struct vtbl : CObject::vtbl
	{
		vtbl() = delete;
	};

	unsigned int* m_pData;
	int m_nSize;
	int m_nMaxSize;
	int m_nGrowBy;

	CDWordArray() = delete;
};

struct CException : CObject
{
	struct vtbl : CObject::vtbl
	{
		int (__fastcall *GetErrorMessage)(CException*, char*, unsigned int, unsigned int*);

		vtbl() = delete;
	};

	int m_bAutoDelete;
	int m_bReadyForDelete;

	CException() = delete;

	virtual int virtual_GetErrorMessage(char* _0, unsigned int _1, unsigned int* _2)
	{
		return *(int*)nullptr;
	}
};

struct CFileException : CException
{
	struct vtbl : CException::vtbl
	{
		vtbl() = delete;
	};

	int m_cause;
	int m_lOsError;
	CString m_strFileName;

	CFileException() = delete;
};

template<class TYPE, class ARG_TYPE>
struct CList : CObject
{
	struct CNode
	{
		CList::CNode* pNext;
		CList::CNode* pPrev;
		TYPE data;

		CNode() = delete;
	};

	CList::CNode* m_pNodeHead;
	CList::CNode* m_pNodeTail;
	int m_nCount;
	CList::CNode* m_pNodeFree;
	CPlex* m_pBlocks;
	int m_nBlockSize;

	CList() = delete;
};

struct CMapStringToString : CObject
{
	struct CAssoc
	{
		CMapStringToString::CAssoc* pNext;
		unsigned int nHashValue;
		CString key;
		CString value;

		CAssoc() = delete;
	};

	struct vtbl : CObject::vtbl
	{
		vtbl() = delete;
	};

	CMapStringToString::CAssoc** m_pHashTable;
	unsigned int m_nHashTableSize;
	int m_nCount;
	CMapStringToString::CAssoc* m_pFreeList;
	CPlex* m_pBlocks;
	int m_nBlockSize;

	CMapStringToString() = delete;
};

struct CObArray : CObject
{
	struct vtbl : CObject::vtbl
	{
		vtbl() = delete;
	};

	CObject** m_pData;
	int m_nSize;
	int m_nMaxSize;
	int m_nGrowBy;

	CObArray() = delete;
};

template<class BASE_CLASS, class T>
struct CTypedPtrList : CObject
{
	struct CNode
	{
		CTypedPtrList::CNode* pNext;
		CTypedPtrList::CNode* pPrev;
		T data;

		CNode() = delete;
	};

	CTypedPtrList::CNode* m_pNodeHead;
	CTypedPtrList::CNode* m_pNodeTail;
	int m_nCount;
	CTypedPtrList::CNode* m_pNodeFree;
	CPlex* m_pBlocks;
	int m_nBlockSize;

	CTypedPtrList() = delete;

	void Construct(int size)
	{
		((CObList*)this)->Construct(size);
	}

	CTypedPtrList::CNode* AddTail(T newElement)
	{
		return (CTypedPtrList::CNode*)((CObList*)this)->AddTail((void*)newElement);
	}

	T RemoveHead()
	{
		return (T)((CObList*)this)->RemoveHead();
	}

	void RemoveAt(__POSITION* position)
	{
		((CObList*)this)->RemoveAt(position);
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

	CTypedPtrArray() = delete;
};

struct CStringList : CObject
{
	struct CNode
	{
		CStringList::CNode* pNext;
		CStringList::CNode* pPrev;
		CString data;

		CNode() = delete;
	};

	struct vtbl : CObject::vtbl
	{
		vtbl() = delete;
	};

	CStringList::CNode* m_pNodeHead;
	CStringList::CNode* m_pNodeTail;
	int m_nCount;
	CStringList::CNode* m_pNodeFree;
	CPlex* m_pBlocks;
	int m_nBlockSize;

	CStringList() = delete;
};

struct CPtrList : CObject
{
	struct CNode
	{
		CPtrList::CNode* pNext;
		CPtrList::CNode* pPrev;
		void* data;

		CNode() = delete;
	};

	struct vtbl : CObject::vtbl
	{
		vtbl() = delete;
	};

	CPtrList::CNode* m_pNodeHead;
	CPtrList::CNode* m_pNodeTail;
	int m_nCount;
	CPtrList::CNode* m_pNodeFree;
	CPlex* m_pBlocks;
	int m_nBlockSize;

	CPtrList() = delete;
};

struct CPersistantEffectList : CTypedPtrList<CPtrList,CPersistantEffect*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CPersistantEffectList() = delete;
};

struct CPersistantEffectListRegenerated : CTypedPtrList<CPtrList,CPersistantEffect*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	unsigned int m_nCounter;

	CPersistantEffectListRegenerated() = delete;
};

struct CMessageHandler
{
	CTypedPtrList<CPtrList,CMessage*> m_messageList;
	unsigned __int8 m_bLastArbitrationLockStatus;

	CMessageHandler() = delete;

	typedef short (__thiscall *type_AddMessage)(CMessageHandler* pThis, CMessage* message, int bForcePassThrough);
	static type_AddMessage p_AddMessage;

	short AddMessage(CMessage* message, int bForcePassThrough)
	{
		return p_AddMessage(this, message, bForcePassThrough);
	}
};

struct CAICondition
{
	CTypedPtrList<CPtrList,CAITrigger*> m_triggerList;

	CAICondition() = delete;

	typedef int (__thiscall *type_Hold)(CAICondition* pThis, CTypedPtrList<CPtrList,CAITrigger*>* triggerList, CGameAIBase* caller);
	static type_Hold p_Hold;

	int Hold(CTypedPtrList<CPtrList,CAITrigger*>* triggerList, CGameAIBase* caller)
	{
		return p_Hold(this, triggerList, caller);
	}
};

struct CAIResponseSet
{
	CTypedPtrList<CPtrList,CAIResponse*> m_responseList;
	int m_weightTotal;

	CAIResponseSet() = delete;
};

struct CAIConditionResponse
{
	CAICondition m_condition;
	CAIResponseSet m_responseSet;

	CAIConditionResponse() = delete;
};

struct CChatBuffer
{
	CTypedPtrList<CPtrList,CString*> m_lLabels;
	CTypedPtrList<CPtrList,CString*> m_lMessages;
	int m_nMessageCount;
	int m_nDisplayCount;

	CChatBuffer() = delete;
};

struct CAIResponse
{
	__int16 m_weight;
	__int16 m_responseNum;
	__int16 m_responseSetNum;
	__int16 m_scriptNum;
	CTypedPtrList<CPtrList,CAIAction*> m_actionList;

	CAIResponse() = delete;
};

struct CSpawnList : CTypedPtrList<CPtrList,CSpawn*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CString mSectionAlias;
	int ReceivedFirstSpawnCall;
	unsigned int LastSpawnTime;
	int CheckSpawnTimes;
	unsigned int SpawnTimeOfDay;
	unsigned int mInterval;
	CSpawnVar* pControlVar;

	CSpawnList() = delete;
};

struct CSpawnFile : CTypedPtrList<CPtrList,void*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CSpawnList* mpExitList;
	CSpawnList* mpEnterList;
	int m_bInSpawn;

	CSpawnFile() = delete;
};

struct CSequenceSoundList : CTypedPtrList<CPtrList,CSequenceSound*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	__POSITION* m_currentSound;
	int m_soundPlaying;
	int m_channel;

	CSequenceSoundList() = delete;
};

struct CSelectiveWeaponTypeList : CTypedPtrList<CPtrList,CSelectiveWeaponType*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CSelectiveWeaponTypeList() = delete;
};

struct CSelectiveBonusList : CTypedPtrList<CPtrList,CSelectiveBonus*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CSelectiveBonusList() = delete;
};

struct CPtrArray : CObject
{
	struct vtbl : CObject::vtbl
	{
		vtbl() = delete;
	};

	void** m_pData;
	int m_nSize;
	int m_nMaxSize;
	int m_nGrowBy;

	CPtrArray() = delete;
};

struct CGameJournal
{
	int IWD_TimeCheat;
	CTypedPtrArray<CPtrArray,CTypedPtrList<CPtrList,CGameJournalEntry*>*> m_aChapters;

	CGameJournal() = delete;
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

	CImportGame() = delete;
};

struct CSpawnPointArray : CTypedPtrArray<CPtrArray,CSpawnPoint*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	int mDefaultFacing;

	CSpawnPointArray() = delete;
};

struct CObList : CObject
{
	struct CNode
	{
		CObList::CNode* pNext;
		CObList::CNode* pPrev;
		CObject* data;

		CNode() = delete;
	};

	struct vtbl : CObject::vtbl
	{
		vtbl() = delete;
	};

	CObList::CNode* m_pNodeHead;
	CObList::CNode* m_pNodeTail;
	int m_nCount;
	CObList::CNode* m_pNodeFree;
	CPlex* m_pBlocks;
	int m_nBlockSize;

	CObList() = delete;

	typedef void (__thiscall *type_Construct)(CObList* pThis, int size);
	static type_Construct p_Construct;

	typedef CObject* (__thiscall *type_RemoveHead)(CObList* pThis);
	static type_RemoveHead p_RemoveHead;

	typedef void (__thiscall *type_RemoveAt)(CObList* pThis, __POSITION* position);
	static type_RemoveAt p_RemoveAt;

	typedef void (__thiscall *type_Destruct)(CObList* pThis);
	static type_Destruct p_Destruct;

	typedef __POSITION* (__thiscall *type_AddTail)(CObList* pThis, void* newElement);
	static type_AddTail p_AddTail;

	void Construct(int size)
	{
		p_Construct(this, size);
	}

	CObject* RemoveHead()
	{
		return p_RemoveHead(this);
	}

	void RemoveAt(__POSITION* position)
	{
		p_RemoveAt(this, position);
	}

	void Destruct()
	{
		p_Destruct(this);
	}

	__POSITION* AddTail(void* newElement)
	{
		return p_AddTail(this, newElement);
	}
};

struct CWarp : CObject
{
	struct vtbl : CObject::vtbl
	{
		void (__fastcall *InvalidateCursorRect)(CWarp*, const CRect*);
		void (__fastcall *NormalizePanelRect)(CWarp*, unsigned int, CRect*);
		void (__fastcall *RequestPause)(CWarp*);
		void (__fastcall *EngineActivated)(CWarp*);
		void (__fastcall *EngineDeactivated)(CWarp*);
		void (__fastcall *EngineDestroyed)(CWarp*);
		void (__fastcall *EngineInitialized)(CWarp*);
		void (__fastcall *EngineGameInit)(CWarp*);
		void (__fastcall *EngineGameUninit)(CWarp*);
		void (__fastcall *SelectEngine)(CWarp*, CWarp*);
		bool (__fastcall *OnEvent)(CWarp*, SDL_Event*);
		int (__fastcall *GetEngineState)(CWarp*);
		int (__fastcall *CheckSystemKeyCtrl)(CWarp*);
		void (__fastcall *SetSystemKeyCtrl)(CWarp*, unsigned __int8);
		int (__fastcall *GetCtrlKey)(CWarp*);
		int (__fastcall *CheckSystemKeyShift)(CWarp*);
		void (__fastcall *SetSystemKeyShift)(CWarp*, int);
		int (__fastcall *GetShiftKey)(CWarp*);
		int (__fastcall *CheckSystemKeyMenu)(CWarp*);
		void (__fastcall *SetSystemKeyMenu)(CWarp*, int);
		int (__fastcall *CheckSystemKeyCapsLock)(CWarp*);
		void (__fastcall *SetSystemKeyCapsLock)(CWarp*, int);
		int (__fastcall *GetCapsLockKey)(CWarp*);
		int (__fastcall *GetMenuKey)(CWarp*);
		int (__fastcall *CheckMouseMove)(CWarp*);
		void (__fastcall *OnMouseMove)(CWarp*, CPoint);
		int (__fastcall *CheckMouseLButton)(CWarp*);
		void (__fastcall *OnLButtonDblClk)(CWarp*, CPoint);
		void (__fastcall *OnLButtonDown)(CWarp*, CPoint);
		void (__fastcall *OnLButtonUp)(CWarp*, CPoint);
		int (__fastcall *CheckMouseMButton)(CWarp*);
		void (__fastcall *OnMButtonDblClk)(CWarp*, CPoint);
		void (__fastcall *OnMButtonDown)(CWarp*, CPoint);
		void (__fastcall *OnMButtonUp)(CWarp*, CPoint);
		int (__fastcall *CheckMouseRButton)(CWarp*);
		void (__fastcall *OnRButtonDblClk)(CWarp*, CPoint);
		void (__fastcall *OnRButtonDown)(CWarp*, CPoint);
		void (__fastcall *OnRButtonUp)(CWarp*, CPoint);
		int (__fastcall *CheckMouseWheel)(CWarp*);
		void (__fastcall *OnMouseWheel)(CWarp*, int, int, unsigned int, unsigned __int16);
		__int16 (__fastcall *GetNumVirtualKeys)(CWarp*);
		CKeyInfo* (__fastcall *GetVirtualKeys)(CWarp*);
		int* (__fastcall *GetVirtualKeysFlags)(CWarp*);
		void (__fastcall *OnKeyDown)(CWarp*, int);
		void (__fastcall *OnKeyUp)(CWarp*, int);
		void (__fastcall *OnTextInput)(CWarp*, const char*);
		void (__fastcall *WindowResized)(CWarp*, int, int);
		void (__fastcall *OnLowMemory)(CWarp*);
		void (__fastcall *EnableEditKeys)(CWarp*, __int16);
		void (__fastcall *DisableEditKeys)(CWarp*);
		void (__fastcall *ResetControls)(CWarp*);
		void (__fastcall *TimerAsynchronousUpdate)(CWarp*);
		void (__fastcall *TimerSynchronousUpdate)(CWarp*);
		void (__fastcall *TimerUpdate)(CWarp*);
		void (__fastcall *RenderUI)(CWarp*);

		vtbl() = delete;
	};

	CWarp* pLastEngine;
	CObList lTimers;

	CWarp() = delete;

	virtual void virtual_InvalidateCursorRect(const CRect* _0)
	{
	}

	virtual void virtual_NormalizePanelRect(unsigned int _0, CRect* _1)
	{
	}

	virtual void virtual_RequestPause()
	{
	}

	virtual void virtual_EngineActivated()
	{
	}

	virtual void virtual_EngineDeactivated()
	{
	}

	virtual void virtual_EngineDestroyed()
	{
	}

	virtual void virtual_EngineInitialized()
	{
	}

	virtual void virtual_EngineGameInit()
	{
	}

	virtual void virtual_EngineGameUninit()
	{
	}

	virtual void virtual_SelectEngine(CWarp* _0)
	{
	}

	virtual bool virtual_OnEvent(SDL_Event* _0)
	{
		return *(bool*)nullptr;
	}

	virtual int virtual_GetEngineState()
	{
		return *(int*)nullptr;
	}

	virtual int virtual_CheckSystemKeyCtrl()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_SetSystemKeyCtrl(unsigned __int8 _0)
	{
	}

	virtual int virtual_GetCtrlKey()
	{
		return *(int*)nullptr;
	}

	virtual int virtual_CheckSystemKeyShift()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_SetSystemKeyShift(int _0)
	{
	}

	virtual int virtual_GetShiftKey()
	{
		return *(int*)nullptr;
	}

	virtual int virtual_CheckSystemKeyMenu()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_SetSystemKeyMenu(int _0)
	{
	}

	virtual int virtual_CheckSystemKeyCapsLock()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_SetSystemKeyCapsLock(int _0)
	{
	}

	virtual int virtual_GetCapsLockKey()
	{
		return *(int*)nullptr;
	}

	virtual int virtual_GetMenuKey()
	{
		return *(int*)nullptr;
	}

	virtual int virtual_CheckMouseMove()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_OnMouseMove(CPoint _0)
	{
	}

	virtual int virtual_CheckMouseLButton()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_OnLButtonDblClk(CPoint _0)
	{
	}

	virtual void virtual_OnLButtonDown(CPoint _0)
	{
	}

	virtual void virtual_OnLButtonUp(CPoint _0)
	{
	}

	virtual int virtual_CheckMouseMButton()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_OnMButtonDblClk(CPoint _0)
	{
	}

	virtual void virtual_OnMButtonDown(CPoint _0)
	{
	}

	virtual void virtual_OnMButtonUp(CPoint _0)
	{
	}

	virtual int virtual_CheckMouseRButton()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_OnRButtonDblClk(CPoint _0)
	{
	}

	virtual void virtual_OnRButtonDown(CPoint _0)
	{
	}

	virtual void virtual_OnRButtonUp(CPoint _0)
	{
	}

	virtual int virtual_CheckMouseWheel()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_OnMouseWheel(int _0, int _1, unsigned int _2, unsigned __int16 _3)
	{
	}

	virtual __int16 virtual_GetNumVirtualKeys()
	{
		return *(__int16*)nullptr;
	}

	virtual CKeyInfo* virtual_GetVirtualKeys()
	{
		return *(CKeyInfo**)nullptr;
	}

	virtual int* virtual_GetVirtualKeysFlags()
	{
		return *(int**)nullptr;
	}

	virtual void virtual_OnKeyDown(int _0)
	{
	}

	virtual void virtual_OnKeyUp(int _0)
	{
	}

	virtual void virtual_OnTextInput(const char* _0)
	{
	}

	virtual void virtual_WindowResized(int _0, int _1)
	{
	}

	virtual void virtual_OnLowMemory()
	{
	}

	virtual void virtual_EnableEditKeys(__int16 _0)
	{
	}

	virtual void virtual_DisableEditKeys()
	{
	}

	virtual void virtual_ResetControls()
	{
	}

	virtual void virtual_TimerAsynchronousUpdate()
	{
	}

	virtual void virtual_TimerSynchronousUpdate()
	{
	}

	virtual void virtual_TimerUpdate()
	{
	}

	virtual void virtual_RenderUI()
	{
	}
};

struct CMoveList : CTypedPtrList<CPtrList,CMoveListEntry*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CMoveList() = delete;
};

struct CMessage
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CMessage*);
		__int16 (__fastcall *GetCommType)(CMessage*);
		unsigned __int8 (__fastcall *GetMsgType)(CMessage*);
		unsigned __int8 (__fastcall *GetMsgSubType)(CMessage*);
		void (__fastcall *MarshalMessage)(CMessage*, unsigned __int8**, unsigned int*);
		int (__fastcall *UnmarshalMessage)(CMessage*, unsigned __int8*, unsigned int);
		void (__fastcall *Run)(CMessage*);

		vtbl() = delete;
	};

	int m_targetId;
	int m_sourceId;

	CMessage() = delete;

	virtual void virtual_Destruct()
	{
	}

	virtual __int16 virtual_GetCommType()
	{
		return *(__int16*)nullptr;
	}

	virtual unsigned __int8 virtual_GetMsgType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 virtual_GetMsgSubType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void virtual_MarshalMessage(unsigned __int8** _0, unsigned int* _1)
	{
	}

	virtual int virtual_UnmarshalMessage(unsigned __int8* _0, unsigned int _1)
	{
		return *(int*)nullptr;
	}

	virtual void virtual_Run()
	{
	}
};

struct CMessageSetDirection : CMessage
{
	struct vtbl : CMessage::vtbl
	{
		vtbl() = delete;
	};

	static void* VFTable;
	CPoint m_face;

	CMessageSetDirection() = delete;

	void Construct(CPoint face, int caller, int target)
	{
		*reinterpret_cast<void**>(this) = VFTable;
		m_sourceId = caller;
		m_targetId = target;
		m_face = face;
	}
};

struct CMemINIValue
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CMemINIValue*);

		vtbl() = delete;
	};

	CString mName;
	CString mValue;

	CMemINIValue() = delete;

	virtual void virtual_Destruct()
	{
	}
};

struct CMemINISection : CTypedPtrList<CPtrList,CMemINIValue*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CString mSectionName;

	CMemINISection() = delete;
};

struct CMemINI : CTypedPtrList<CPtrList,void*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CString mFileName;
	CMemINISection* mpLastSection;

	CMemINI() = delete;
};

struct CImmunitiesWeapon : CTypedPtrList<CPtrList,CWeaponIdentification*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CImmunitiesWeapon() = delete;
};

struct CImmunitiesSpellList : CTypedPtrList<CPtrList,CImmunitySpell*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CImmunitiesSpellList() = delete;
};

struct CImmunitiesSchoolAndSecondaryDecrementing : CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CImmunitiesSchoolAndSecondaryDecrementing() = delete;
};

struct CImmunitiesSchoolAndSecondary : CTypedPtrList<CPtrList,long*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CImmunitiesSchoolAndSecondary() = delete;
};

struct CImmunitiesProjectile : CTypedPtrList<CPtrList,long*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CImmunitiesProjectile() = delete;
};

struct CImmunitiesItemTypeEquipList : CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CImmunitiesItemTypeEquipList() = delete;
};

struct CImmunitiesItemEquipList : CTypedPtrList<CPtrList,CImmunitiesItemEquip*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CImmunitiesItemEquipList() = delete;
};

struct CImmunitiesEffect : CTypedPtrList<CPtrList,CGameEffect*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CImmunitiesEffect() = delete;
};

struct CImmunitiesAIType : CTypedPtrList<CPtrList,CAIObjectType*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CImmunitiesAIType() = delete;

	typedef int (__thiscall *type_OnList)(CImmunitiesAIType* pThis, const CAIObjectType* type);
	static type_OnList p_OnList;

	int OnList(const CAIObjectType* type)
	{
		return p_OnList(this, type);
	}
};

struct CGameEffectUsabilityList : CTypedPtrList<CPtrList,CGameEffectUsability*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CGameEffectUsabilityList() = delete;
};

struct CGameEffectList : CTypedPtrList<CPtrList,CGameEffect*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	__POSITION* m_posNext;
	__POSITION* m_posCurrent;
	int m_newEffect;
	int m_retry;

	CGameEffectList() = delete;
};

struct CGameDialogEntry : CTypedPtrArray<CPtrArray,CGameDialogReply*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	unsigned int m_dialogText;
	CAICondition m_startCondition;
	int m_picked;
	unsigned int m_conditionPriority;
	unsigned int m_dialogIndex;
	unsigned __int8 m_bDisplayButton;

	CGameDialogEntry() = delete;
};

struct CGameButtonList : CTypedPtrList<CPtrList,CButtonData*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	int m_nFirstMageSpellIndex;

	CGameButtonList() = delete;
};

struct CGameAbilityList : CTypedPtrArray<CPtrArray,CAbilityData*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CGameAbilityList() = delete;
};

struct CFile : CObject
{
	struct vtbl : CObject::vtbl
	{
		unsigned int (__fastcall *GetPosition)(CFile*);
		CString* (__fastcall *GetFileName)(CFile*, CString*);
		CString* (__fastcall *GetFileTitle)(CFile*, CString*);
		CString* (__fastcall *GetFilePath)(CFile*, CString*);
		void (__fastcall *SetFilePath)(CFile*, const char*);
		int (__fastcall *Open)(CFile*, const char*, unsigned int, CFileException*);
		int (__fastcall *Seek)(CFile*, int, unsigned int);
		void (__fastcall *SetLength)(CFile*, unsigned int);
		unsigned int (__fastcall *GetLength)(CFile*);
		unsigned int (__fastcall *Read)(CFile*, void*, unsigned int);
		unsigned int (__fastcall *Write)(CFile*, const void*, unsigned int);
		void (__fastcall *Abort)(CFile*);
		void (__fastcall *Flush)(CFile*);
		void (__fastcall *Close)(CFile*);
		unsigned int (__fastcall *GetBufferPtr)(CFile*, unsigned int, unsigned int, void**, void**);

		vtbl() = delete;
	};

	unsigned int m_hFile;
	int m_bCloseOnDelete;
	CString m_strFileName;

	CFile() = delete;

	virtual unsigned int virtual_GetPosition()
	{
		return *(unsigned int*)nullptr;
	}

	virtual CString* virtual_GetFileName()
	{
		return *(CString**)nullptr;
	}

	virtual CString* virtual_GetFileTitle()
	{
		return *(CString**)nullptr;
	}

	virtual CString* virtual_GetFilePath()
	{
		return *(CString**)nullptr;
	}

	virtual void virtual_SetFilePath(const char* _0)
	{
	}

	virtual int virtual_Open(const char* _0, unsigned int _1, CFileException* _2)
	{
		return *(int*)nullptr;
	}

	virtual int virtual_Seek(int _0, unsigned int _1)
	{
		return *(int*)nullptr;
	}

	virtual void virtual_SetLength(unsigned int _0)
	{
	}

	virtual unsigned int virtual_GetLength()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int virtual_Read(void* _0, unsigned int _1)
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int virtual_Write(const void* _0, unsigned int _1)
	{
		return *(unsigned int*)nullptr;
	}

	virtual void virtual_Abort()
	{
	}

	virtual void virtual_Flush()
	{
	}

	virtual void virtual_Close()
	{
	}

	virtual unsigned int virtual_GetBufferPtr(unsigned int _0, unsigned int _1, void** _2, void** _3)
	{
		return *(unsigned int*)nullptr;
	}
};

struct CCriticalEntryList : CTypedPtrList<CPtrList,CCriticalEntry*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CCriticalEntryList() = delete;
};

struct CContingencyList : CTypedPtrList<CPtrList,CContingency*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CContingencyList() = delete;
};

struct CColorRanges : CTypedPtrList<CPtrList,CColorRange*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CColorRanges() = delete;
};

struct CColorEffects : CTypedPtrList<CPtrList,CColorEffect*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CColorEffects() = delete;
};

struct CCallbackBase
{
	struct vtbl
	{
		void (__fastcall *Run)(CCallbackBase*, void*, bool, unsigned __int64);
		void (__fastcall *Run_2)(CCallbackBase*, void*);
		int (__fastcall *GetCallbackSizeBytes)(CCallbackBase*);

		vtbl() = delete;
	};

	unsigned __int8 m_nCallbackFlags;
	int m_iCallback;

	CCallbackBase() = delete;

	virtual void virtual_Run(void* _0, bool _1, unsigned __int64 _2)
	{
	}

	virtual void virtual_Run_2(void* _0)
	{
	}

	virtual int virtual_GetCallbackSizeBytes()
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

	CCallResult() = delete;
};

struct CBounceList : CTypedPtrList<CPtrList,CBounceEntry*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CBounceList() = delete;
};

struct CBaldurEngine : CWarp
{
	struct vtbl : CWarp::vtbl
	{
		int (__fastcall *GetSelectedCharacter)(CBaldurEngine*, int);
		int (__fastcall *GetPickedCharacter)(CBaldurEngine*);
		void (__fastcall *SetSelectedCharacter)(CBaldurEngine*, int);
		void (__fastcall *SetPickedCharacter)(CBaldurEngine*, int);
		void (__fastcall *OnPortraitLClick)(CBaldurEngine*, unsigned int);
		void (__fastcall *OnPortraitLDblClick)(CBaldurEngine*, unsigned int);
		void (__fastcall *UpdateContainerStatus)(CBaldurEngine*, int, __int16);
		void (__fastcall *UpdatePersonalItemStatus)(CBaldurEngine*, int);
		void (__fastcall *OnRestButtonClick)(CBaldurEngine*);
		void (__fastcall *UpdateGroundItems)(CBaldurEngine*);
		void (__fastcall *UpdateCursorShape)(CBaldurEngine*, unsigned __int8);
		void (__fastcall *CheckEnablePortraits)(CBaldurEngine*, unsigned int);
		void (__fastcall *CheckEnableLeftPanel)(CBaldurEngine*);
		void (__fastcall *EnablePortrait)(CBaldurEngine*, unsigned int, unsigned int, int);
		void (__fastcall *CancelEngine)(CBaldurEngine*);
		void (__fastcall *UpdateCharacterStatus)(CBaldurEngine*, int);
		void (__fastcall *UpdatePartyGoldStatus)(CBaldurEngine*);
		void (__fastcall *GetChatEditBoxStatus)(CBaldurEngine*, CString*, int*);
		void (__fastcall *SetChatEditBoxStatus)(CBaldurEngine*, const CString*, int);
		int (__fastcall *StopMusic)(CBaldurEngine*);

		vtbl() = delete;
	};

	int m_nSelectedCharacter;
	int m_nPickedCharacter;

	CBaldurEngine() = delete;

	virtual int virtual_GetSelectedCharacter(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int virtual_GetPickedCharacter()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_SetSelectedCharacter(int _0)
	{
	}

	virtual void virtual_SetPickedCharacter(int _0)
	{
	}

	virtual void virtual_OnPortraitLClick(unsigned int _0)
	{
	}

	virtual void virtual_OnPortraitLDblClick(unsigned int _0)
	{
	}

	virtual void virtual_UpdateContainerStatus(int _0, __int16 _1)
	{
	}

	virtual void virtual_UpdatePersonalItemStatus(int _0)
	{
	}

	virtual void virtual_OnRestButtonClick()
	{
	}

	virtual void virtual_UpdateGroundItems()
	{
	}

	virtual void virtual_UpdateCursorShape(unsigned __int8 _0)
	{
	}

	virtual void virtual_CheckEnablePortraits(unsigned int _0)
	{
	}

	virtual void virtual_CheckEnableLeftPanel()
	{
	}

	virtual void virtual_EnablePortrait(unsigned int _0, unsigned int _1, int _2)
	{
	}

	virtual void virtual_CancelEngine()
	{
	}

	virtual void virtual_UpdateCharacterStatus(int _0)
	{
	}

	virtual void virtual_UpdatePartyGoldStatus()
	{
	}

	virtual void virtual_GetChatEditBoxStatus(CString* _0, int* _1)
	{
	}

	virtual void virtual_SetChatEditBoxStatus(const CString* _0, int _1)
	{
	}

	virtual int virtual_StopMusic()
	{
		return *(int*)nullptr;
	}
};

struct CDungeonMaster : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

	CDungeonMaster() = delete;
};

struct CApplyEffectList : CTypedPtrList<CPtrList,CGameEffect*>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CApplyEffectList() = delete;
};

struct CAIGroup
{
	__int16 m_groupId;
	int m_groupChanged;
	CTypedPtrList<CPtrList,long> m_memberList;

	CAIGroup() = delete;

	typedef void (__thiscall *type_FollowLeader)(CAIGroup* pThis, CPoint target, int additive);
	static type_FollowLeader p_FollowLeader;

	typedef void (__thiscall *type_RemoveFromSearch)(CAIGroup* pThis, CSearchBitmap* search);
	static type_RemoveFromSearch p_RemoveFromSearch;

	typedef void (__thiscall *type_AddToSearch)(CAIGroup* pThis, CSearchBitmap* search);
	static type_AddToSearch p_AddToSearch;

	typedef short* (__thiscall *type_GetFacings)(CAIGroup* pThis, short formationType, short direction);
	static type_GetFacings p_GetFacings;

	typedef CPoint* (__thiscall *type_GetOffsets)(CAIGroup* pThis, short formationType, short direction, byte bFullParty);
	static type_GetOffsets p_GetOffsets;

	void Override_GroupSetTarget(CPoint target, int additive, ushort formationType, CPoint cursor);

	void FollowLeader(CPoint target, int additive)
	{
		p_FollowLeader(this, target, additive);
	}

	void RemoveFromSearch(CSearchBitmap* search)
	{
		p_RemoveFromSearch(this, search);
	}

	void AddToSearch(CSearchBitmap* search)
	{
		p_AddToSearch(this, search);
	}

	short* GetFacings(short formationType, short direction)
	{
		return p_GetFacings(this, formationType, direction);
	}

	CPoint* GetOffsets(short formationType, short direction, byte bFullParty)
	{
		return p_GetOffsets(this, formationType, direction, bFullParty);
	}
};

template<class T>
struct ArrayPointer
{
	T* data;

	ArrayPointer() = delete;

	T get(int index)
	{
		return data[index];
	}

	T* getReference(int index)
	{
		return &data[index];
	}

	void set(int index, T value)
	{
		data[index] = value;
	}

	T& operator[](int index)
	{
		return data[index];
	}
};

template<class T, int size>
struct Array
{
	T data[size];

	Array() = delete;

	T get(int index)
	{
		if (index < 0 || index >= size)
		{
			return (T)NULL;
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

	T& operator[](int index)
	{
		return data[index];
	}
};

struct uiItem
{
	struct bam_t
	{
		uiVariant* resref;
		uiVariant* sequence;
		uiVariant* sequenceonce;
		uiVariant* frame;
		uiVariant* greyscale;
		uiVariant* usealpha;
		int scaletoclip;

		bam_t() = delete;
	};

	struct bmp_t
	{
		int resname;
		uiVariant* resref;
		SDL_Rect area;

		bmp_t() = delete;
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

		button_t() = delete;
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

		edit_t() = delete;
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

		list_t() = delete;
	};

	struct map_t
	{
		int type;

		map_t() = delete;
	};

	struct mosaic_t
	{
		uiVariant* resref;
		int respectClipping;

		mosaic_t() = delete;
	};

	struct movie_t
	{
		void* res;
		SDL_Rect subtitle;
		int transparent;
		unsigned int background;
		int loop;
		uiVariant* queuedMovie;

		movie_t() = delete;
	};

	struct progressBar_t
	{
		uiVariant* percent;
		uiVariant* color;
		uiVariant* fullColor;

		progressBar_t() = delete;
	};

	struct rectangle_t
	{
		int number;
		uiVariant* opacity;

		rectangle_t() = delete;
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

		scrollbar_t() = delete;
	};

	struct slider_t
	{
		const char* position;
		uiVariant* settings;
		int palette;
		const char* background;
		int right;

		slider_t() = delete;
	};

	struct slot_t
	{
		uiVariant* icon;
		uiVariant* count;
		uiVariant* usages;
		uiVariant* highlight;
		uiVariant* tint;

		slot_t() = delete;
	};

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

		text_t() = delete;
	};

	struct tooltip_t
	{
		const char* originalText;
		uiVariant* text;
		uiVariant* force;
		int position;
		int forceTop;

		tooltip_t() = delete;
	};

	struct uiTemplate_t
	{
		uiItem* item;

		uiTemplate_t() = delete;
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

	uiItem() = delete;
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

	WED_LayerHeader_st() = delete;
};

struct SteamUGCQueryCompleted_t
{
	unsigned __int64 m_handle;
	EResult m_eResult;
	unsigned int m_unNumResultsReturned;
	unsigned int m_unTotalMatchingResults;
	bool m_bCachedData;
	Array<char,256> m_rgchNextCursor;

	SteamUGCQueryCompleted_t() = delete;
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

	SteamUGCDetails_t() = delete;
};

struct SteamUGCRequestUGCDetailsResult_t
{
	SteamUGCDetails_t m_details;
	bool m_bCachedData;

	SteamUGCRequestUGCDetailsResult_t() = delete;
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

	Spell_Header_st() = delete;
};
#pragma pack(pop)

struct SDL_TextInputEvent
{
	unsigned int type;
	unsigned int timestamp;
	unsigned int windowID;
	Array<char,32> text;

	SDL_TextInputEvent() = delete;
};

struct SDL_TextEditingEvent
{
	unsigned int type;
	unsigned int timestamp;
	unsigned int windowID;
	Array<char,32> text;
	int start;
	int length;

	SDL_TextEditingEvent() = delete;
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

	SDL_PixelFormat() = delete;
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

	SDL_Event() = delete;
};

template<int length>
struct LCharString
{
	Array<char,length> data;

	LCharString() = delete;

	char getChar(int index)
	{
		if (index < 0 || index >= length)
		{
			return NULL;
		}
		return data[index];
	}

	void setChar(int index, char toSet)
	{
		if (index < 0 || index >= length)
		{
			return;
		}
		data[index] = toSet;
	}

	void set(const char* toSet)
	{
		size_t cpyLen = strlen(toSet);
		if (cpyLen > length)
			cpyLen = length;
		memcpy((void*)&data, toSet, cpyLen);
		if (cpyLen < length)
			memset((void*)&data[cpyLen], 0, length - cpyLen);
	}

	void get(lua_State* L)
	{
		char* localCopy = (char*)alloca(length + 1);
		int i = 0;
		for (; i < length; ++i) {
			char readVal = data[i];
			if (readVal == '\0')
				break;
			localCopy[i] = readVal;
		}
		localCopy[i] = '\0';
		p_lua_pushstring(L, localCopy);
	}
};

#pragma pack(push, 1)
struct CAreaVariable
{
	LCharString<32> m_name;
	unsigned __int16 m_type;
	unsigned __int16 m_resRefType;
	unsigned int m_dWValue;
	int m_intValue;
	long double m_floatValue;
	LCharString<32> m_stringValue;

	CAreaVariable() = delete;
};
#pragma pack(pop)

struct CVariable : CAreaVariable
{
	CVariable() = delete;

	typedef void (__thiscall *type_Construct)(CVariable* pThis);
	static type_Construct p_Construct;

	void Construct()
	{
		p_Construct(this);
	}
};

#pragma pack(push, 1)
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

	Item_ability_st() = delete;
};
#pragma pack(pop)

#pragma pack(push, 1)
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

	Item_Header_st() = delete;
};
#pragma pack(pop)

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

typedef int (*type_rand)();
extern type_rand p_rand;

extern int* p_numMenus;
extern Array<uiMenu,256>* p_menus;
extern Array<uiMenu*,256>* p_menuStack;
extern int* p_nextStackMenuIdx;
extern CResText** p_menuSrc;
extern int* p_menuLength;
extern CTypedPtrArray<CPtrArray,CRes*>* p_resources;
extern _9B9540D9920A90D57A3D80DDD1A70514* p_capture;
extern CBaldurChitin** p_g_pBaldurChitin;
extern lua_State** p_g_lua;
extern char** p_afxPchNil;

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

	DP_Player() = delete;
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

	CWorldMapLinks() = delete;
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

	CWorldMapData() = delete;
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

	CWorldMapArea() = delete;
};

struct CVisibilityMapTreeNode
{
	CPoint m_relativePos;
	unsigned __int16 m_nRange;
	Array<__int16,3> m_aChildren;
	__int16 m_parent;

	CVisibilityMapTreeNode() = delete;
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

	CVisibilityMap() = delete;
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

	CVidPalette() = delete;
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

	CVIDIMG_PALETTEAFFECT() = delete;
};

struct CVidImage
{
	CVidPalette m_cPalette;
	CVIDIMG_PALETTEAFFECT mPaletteAffects;

	CVidImage() = delete;
};

struct CVidTile : CVidImage
{
	CResTile* pRes;
	unsigned int m_dwFlags;

	CVidTile() = delete;
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

	CTlkTable() = delete;
};

struct CStoreFileSpell
{
	Array<unsigned __int8,8> m_spell;
	unsigned int m_cost;

	CStoreFileSpell() = delete;
};

struct CStoreFileItem
{
	Array<unsigned __int8,8> m_itemId;
	unsigned __int16 m_wear;
	Array<unsigned __int16,3> m_usageCount;
	unsigned int m_dynamicFlags;
	unsigned int m_nInStock;
	unsigned int m_nStoreFlags;

	CStoreFileItem() = delete;
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

	CStoreFileHeader() = delete;
};

struct CStoreFileDrinks
{
	Array<unsigned __int8,8> m_icon;
	unsigned int m_strName;
	unsigned int m_nCost;
	unsigned int m_nRumorChance;

	CStoreFileDrinks() = delete;
};

struct CSteam
{
	struct SubscribedItems
	{
		Array<unsigned __int64,16> vecPublished;
		int curSubscribed;
		int numSubscribed;

		SubscribedItems() = delete;
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

	CSteam() = delete;
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

	CSoundMixerImp() = delete;
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

	CSearchRequest() = delete;
};

struct CScreenMovies : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

	Array<CKeyInfo,98> m_pVirtualKeys;
	Array<int,98> m_pVirtualKeysFlags;
	int m_nEngineState;
	CStringList* m_pMovies;
	int m_nMovieIndex;
	CString m_sSelectedMovie;

	CScreenMovies() = delete;
};

struct CScreenConnection : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CScreenConnection() = delete;
};

struct CSavedGameStoredLocation
{
	Array<unsigned __int8,8> m_areaName;
	unsigned __int16 m_xPos;
	unsigned __int16 m_yPos;

	CSavedGameStoredLocation() = delete;
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

	CSavedGamePartyCreature() = delete;
};

struct CResRef
{
	Array<unsigned __int8,8> m_resRef;

	CResRef() = delete;

	void get(lua_State* L)
	{
		char* localCopy = (char*)alloca(sizeof(m_resRef) + 1);
		int i = 0;
		for (; i < sizeof(m_resRef); ++i) {
			char readVal = m_resRef[i];
			if (readVal == '\0')
				break;
			localCopy[i] = readVal;
		}
		localCopy[i] = '\0';
		p_lua_pushstring(L, localCopy);
	}

	void set(const char* newVal)
	{
		int i = 0;
		for (; i < sizeof(m_resRef); ++i) {
			char readVal = newVal[i];
			if (readVal >= 97 && readVal <= 122) {
				readVal -= 32;
			}
			m_resRef[i] = readVal;
			if (readVal == '\0')
				break;
		}
		for (; i < sizeof(m_resRef); ++i) {
			m_resRef[i] = '\0';
		}
	}

	void copy(CResRef* newVal)
	{
		*reinterpret_cast<__int64*>(&m_resRef) = *reinterpret_cast<__int64*>(newVal);
	}
};

struct CAIScript
{
	CResRef cResRef;
	CTypedPtrList<CPtrList,CAIConditionResponse*> m_caList;

	CAIScript() = delete;

	typedef void (__thiscall *type_Construct1)(CAIScript* pThis, CResRef cNewResRef, int playerscript);
	static type_Construct1 p_Construct1;

	void Construct(CResRef cNewResRef, int playerscript)
	{
		p_Construct1(this, cNewResRef, playerscript);
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

	CAbilityId() = delete;

	typedef void (__thiscall *type_Construct)(CAbilityId* pThis);
	static type_Construct p_Construct;

	void Construct()
	{
		p_Construct(this);
	}
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

	CButtonData() = delete;
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

	CGameDialogReply() = delete;
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

	CAbilityData() = delete;
};

struct CCriticalEntry
{
	CResRef m_res;
	int m_hitOrMiss;
	int m_slot;
	int m_attackType;
	int m_itemType;
	int m_bonus;

	CCriticalEntry() = delete;
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

	CGameDialogSprite() = delete;
};

struct CImmunitiesItemEquip
{
	CResRef m_res;
	unsigned int m_error;
	CGameEffect* m_pEffect;

	CImmunitiesItemEquip() = delete;
};

struct CImmunitySpell
{
	CResRef m_res;
	unsigned int m_error;
	int m_item;

	CImmunitySpell() = delete;
};

struct CMoveListEntry
{
	int m_nSpiteIndex;
	CResRef m_rAreaRes;
	CPoint m_ptDest;
	CPoint m_ptSource;
	unsigned __int8 m_nFacing;
	int m_nDelay;

	CMoveListEntry() = delete;
};

struct CGameStatsRes : CObject
{
	struct vtbl : CObject::vtbl
	{
		vtbl() = delete;
	};

	CResRef m_cResRef;
	__int16 m_nTimesUsed;

	CGameStatsRes() = delete;
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

	Spell_ability_st() = delete;
};

#pragma pack(push, 1)
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
	CResRef res;
	unsigned int numDice;
	unsigned int diceSize;
	unsigned int savingThrow;
	int saveMod;
	unsigned int special;

	Item_effect_st() = delete;
};
#pragma pack(pop)

struct CWorldMap
{
	CResRef m_cResRef;
	CWorldMapHeader m_cHeader;
	CWorldMapData* m_pData;
	CWorldMapArea** m_ppAreas;
	CWorldMapLinks** m_ppLinks;

	CWorldMap() = delete;
};

struct CVVCHashEntry
{
	CResRef m_name;
	unsigned __int16 m_priority;
	unsigned int m_renderType;
	unsigned int m_renderMask;

	CVVCHashEntry() = delete;
};

struct CTiledObject
{
	int m_nWedIndex;
	CResWED* m_pResWed;
	unsigned __int16 m_wAIState;
	unsigned __int16 m_wRenderState;
	__POSITION* m_posAreaList;
	CResRef m_resId;

	CTiledObject() = delete;
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

	CStore() = delete;
};

struct CSequenceSound
{
	CResRef m_sound;
	int m_offset;

	CSequenceSound() = delete;
};

struct CScreenWizSpell : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CScreenWizSpell() = delete;
};

struct CScreenPriestSpell : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CScreenPriestSpell() = delete;
};

struct CScreenCharacter : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CScreenCharacter() = delete;
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

	CSaveGameSlot() = delete;
};

template<class RES_CLASS, int RES_ID>
struct CResHelper
{
	RES_CLASS* pRes;
	CResRef cResRef;

	CResHelper() = delete;
};

struct C2DArray : CResHelper<CResText,1012>
{
	ArrayPointer<CString> m_pNamesX;
	ArrayPointer<CString> m_pNamesY;
	ArrayPointer<CString> m_pArray;
	CString m_default;
	__int16 m_nSizeX;
	__int16 m_nSizeY;

	C2DArray() = delete;

	typedef void (__thiscall *type_Construct)(C2DArray* pThis);
	static type_Construct p_Construct;

	typedef void (__thiscall *type_Load)(C2DArray* pThis, const CResRef* res);
	static type_Load p_Load;

	typedef const CString* (__thiscall *type_GetAtLabels)(C2DArray* pThis, const CString* nX, const CString* nY);
	static type_GetAtLabels p_GetAtLabels;

	typedef void (__thiscall *type_Destruct)(C2DArray* pThis);
	static type_Destruct p_Destruct;

	void Construct()
	{
		p_Construct(this);
	}

	void Load(const CResRef* res)
	{
		p_Load(this, res);
	}

	const CString* GetAtLabels(const CString* nX, const CString* nY)
	{
		return p_GetAtLabels(this, nX, nY);
	}

	void Destruct()
	{
		p_Destruct(this);
	}
};

struct CAIIdList : CResHelper<CResText,1008>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CAIIdList*);

		vtbl() = delete;
	};

	CString m_fileName;
	CTypedPtrList<CPtrList,CAIId*> m_idList;
	int m_faster;
	ArrayPointer<CAIId*> m_pIdArray;
	int m_nArray;

	CAIIdList() = delete;

	typedef void (__thiscall *type_Construct1)(CAIIdList* pThis);
	static type_Construct1 p_Construct1;

	typedef void (__thiscall *type_Destruct)(CAIIdList* pThis);
	static type_Destruct p_Destruct;

	typedef void (__thiscall *type_LoadList2)(CAIIdList* pThis, CResRef id, int faster);
	static type_LoadList2 p_LoadList2;

	typedef CAIId* (__thiscall *type_Find1)(CAIIdList* pThis, int id);
	static type_Find1 p_Find1;

	void Construct1()
	{
		p_Construct1(this);
	}

	void Destruct()
	{
		p_Destruct(this);
	}

	void LoadList2(CResRef id, int faster)
	{
		p_LoadList2(this, id, faster);
	}

	CAIId* Find1(int id)
	{
		return p_Find1(this, id);
	}

	virtual void virtual_Destruct()
	{
	}
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

	CRuleTables() = delete;
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

	CAIScriptFile() = delete;

	typedef void (__thiscall *type_Construct)(CAIScriptFile* pThis);
	static type_Construct p_Construct;

	typedef void (__thiscall *type_Destruct)(CAIScriptFile* pThis);
	static type_Destruct p_Destruct;

	typedef void (__thiscall *type_ParseConditionalString)(CAIScriptFile* pThis, CString* data);
	static type_ParseConditionalString p_ParseConditionalString;

	typedef CAIObjectType* (__thiscall *type_ParseObjectType)(CAIScriptFile* pThis, CAIObjectType* result, CString* input);
	static type_ParseObjectType p_ParseObjectType;

	typedef void (__thiscall *type_ParseResponseString)(CAIScriptFile* pThis, CString* data);
	static type_ParseResponseString p_ParseResponseString;

	void Construct()
	{
		p_Construct(this);
	}

	void Destruct()
	{
		p_Destruct(this);
	}

	void ParseConditionalString(CString* data)
	{
		p_ParseConditionalString(this, data);
	}

	CAIObjectType* ParseObjectType(CAIObjectType* result, CString* input)
	{
		return p_ParseObjectType(this, result, input);
	}

	void ParseResponseString(CString* data)
	{
		p_ParseResponseString(this, data);
	}
};

struct CGameFile : CResHelper<CResGame,1013>
{
	CGameFile() = delete;
};

struct CVidMosaic : CVidImage, CResHelper<CResMosaic,1004>
{
	CVidMosaic() = delete;
};

struct CVidFont : CResHelper<CResFont,1034>
{
	CVidCellFont* vidCellFont;
	unsigned int foreground;
	unsigned int tintcolor;
	int pointSize;
	int zoom;

	CVidFont() = delete;
};

struct CScreenInventory : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CScreenInventory() = delete;
};

struct CScreenJournal : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CScreenJournal() = delete;
};

struct CScreenCreateChar : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CScreenCreateChar() = delete;
};

struct CScreenCreateParty : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

	Array<CKeyInfo,5> m_pVirtualKeys;
	int m_bCtrlKeyDown;
	Array<int,5> m_pVirtualKeysFlags;
	int m_nEngineState;
	int m_firstCall;
	CVidFont m_preloadFontStnSml;
	int m_nCharacterSlot;

	CScreenCreateParty() = delete;
};

struct CScreenDLC : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CScreenDLC() = delete;
};

struct CScreenLoad : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CScreenLoad() = delete;
};

struct CScreenMap : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CScreenMap() = delete;
};

struct CScreenMultiPlayer : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CScreenMultiPlayer() = delete;
};

struct CScreenOptions : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CScreenOptions() = delete;
};

struct CScreenSave : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CScreenSave() = delete;
};

struct CScreenStart : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CScreenStart() = delete;
};

struct CVidCell : CVidImage, CResHelper<CResCell,1000>
{
	struct vtbl
	{
		int (__fastcall *FrameAdvance)(CVidCell*);
		int (__fastcall *Render)(CVidCell*, unsigned int*, int, int, int, const CRect*, unsigned int, const CPoint*);
		int (__fastcall *Render_2)(CVidCell*, int, int, const CRect*, CVidPoly*, int, unsigned int, int);
		void (__fastcall *StoreBackground)(CVidCell*, int, int, const CRect*, CRect*, unsigned __int8);
		int (__fastcall *GetFrame)(CVidCell*);

		vtbl() = delete;
	};

	__int16 m_nCurrentFrame;
	unsigned __int16 m_nCurrentSequence;
	int m_nAnimType;
	int m_bPaletteChanged;
	frameTableEntry_st* m_pFrame;
	unsigned __int8 m_bShadowOn;

	CVidCell() = delete;

	virtual int virtual_FrameAdvance()
	{
		return *(int*)nullptr;
	}

	virtual int virtual_Render(unsigned int* _0, int _1, int _2, int _3, const CRect* _4, unsigned int _5, const CPoint* _6)
	{
		return *(int*)nullptr;
	}

	virtual int virtual_Render_2(int _0, int _1, const CRect* _2, CVidPoly* _3, int _4, unsigned int _5, int _6)
	{
		return *(int*)nullptr;
	}

	virtual void virtual_StoreBackground(int _0, int _1, const CRect* _2, CRect* _3, unsigned __int8 _4)
	{
	}

	virtual int virtual_GetFrame()
	{
		return *(int*)nullptr;
	}
};

struct CScreenWorldMap : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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
	CList<unsigned long,unsigned long*>* m_pPath;
	int m_nLeavingEdge;
	unsigned int m_nCurrentLink;
	CResRef m_cResCurrentArea;
	CArray<CRect,CRect*> m_aAreaRect;
	CArray<CRect,CRect*> m_aAreaMarker;
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

	CScreenWorldMap() = delete;
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

	CCacheStatus() = delete;
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

	CInfButtonSettings() = delete;
};

struct CPortraitIcon
{
	int icon;
	int frame;
	CVidCell bam;

	CPortraitIcon() = delete;
};

struct CVidCellFont : CVidCell
{
	struct vtbl : CVidCell::vtbl
	{
		vtbl() = delete;
	};

	CVidCellFont() = delete;
};

struct CVidBitmap : CVidImage, CResHelper<CResBitmap,1>
{
	__int16 m_nBitCount;
	CString m_szResFileName;

	CVidBitmap() = delete;
};

struct CScreenAI : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

	CVidBitmap m_bmpScreen;
	C2DArray m_tSplashScreens;
	__int16 m_nSplashScreen;
	int m_nSplashTimer;
	int m_bInteractiveDemoQuit;
	unsigned __int8 m_nBmpDraw;
	Array<CKeyInfo,5> m_pVirtualKeys;
	Array<int,5> m_pVirtualKeysFlags;
	unsigned __int8 m_bCtrlKeyDown;

	CScreenAI() = delete;
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

	CSearchBitmap() = delete;

	typedef byte (__thiscall *type_GetCost)(CSearchBitmap* pThis, CPoint* point, byte* terrainTable, byte snapshotPersonalSpace, ushort* nTableIndex, int bCheckBump);
	static type_GetCost p_GetCost;

	byte GetCost(CPoint* point, byte* terrainTable, byte snapshotPersonalSpace, ushort* nTableIndex, int bCheckBump)
	{
		return p_GetCost(this, point, terrainTable, snapshotPersonalSpace, nTableIndex, bCheckBump);
	}
};

struct CVidMode
{
	static ushort* p_SCREENWIDTH;
	static ushort* p_SCREENHEIGHT;
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

	CVidMode() = delete;
};

struct CSpell : CResHelper<CResSpell,1006>
{
	CSpell() = delete;

	typedef void (__thiscall *type_Construct)(CSpell* pThis, CResRef res);
	static type_Construct p_Construct;

	void Construct(CResRef res)
	{
		p_Construct(this, res);
	}
};

struct CSoundImp : CObject, CResHelper<CResWave,4>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

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

	CSoundImp() = delete;
};

struct CSound : CObject, CResHelper<CResWave,4>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CObject*);

		vtbl() = delete;
	};

	CSoundImp* pimpl;

	CSound() = delete;
};

struct CScreenChapter : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

	Array<CKeyInfo,5> m_pVirtualKeys;
	Array<int,5> m_pVirtualKeysFlags;
	unsigned __int8 m_bCtrlKeyDown;
	int m_nChapter;
	int m_nDream;
	CResRef m_cResText;
	CList<unsigned long,unsigned long*>* m_pTextList;
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

	CScreenChapter() = delete;
};

struct CInfToolTip : CVidCell
{
	struct vtbl : CVidCell::vtbl
	{
		vtbl() = delete;
	};

	CString m_sText;
	CRect m_rSource;
	int m_bUseSourceRect;
	CVidFont m_textFont;
	CSound m_openSnd;

	CInfToolTip() = delete;
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

	CInfCursor() = delete;
};

struct STR_RES
{
	CString szText;
	CSound cSound;

	STR_RES() = delete;
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

	CWeather() = delete;
};

struct CScreenWorld : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CScreenWorld() = delete;
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

	CProgressBar() = delete;
};

struct CPlex
{
	CPlex* pNext;
	Array<unsigned int,1> dwReserved;

	CPlex() = delete;
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

	CNetworkWindow() = delete;
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

	CNetwork() = delete;
};

struct CChitin
{
	struct vtbl
	{
		void (__fastcall *SynchronousUpdate)(CChitin*);
		void (__fastcall *SetupPanels)(CChitin*);
		unsigned int (__fastcall *GetIDSInvalidVideoMode)(CChitin*);
		unsigned int (__fastcall *GetIDSOpenGLDll)(CChitin*);
		unsigned int (__fastcall *GetIDSExclusiveMode)(CChitin*);
		unsigned int (__fastcall *GetIDSChoosePixelFormat)(CChitin*);
		unsigned int (__fastcall *GetIDSSetPixelFormat)(CChitin*);
		unsigned int (__fastcall *GetIDSSetGameResolution)(CChitin*);
		unsigned int (__fastcall *GetIDSSetGameBitDepth)(CChitin*);
		unsigned int (__fastcall *GetIDSBadDeskTopBitDepth)(CChitin*);
		unsigned int (__fastcall *GetIDSWindowsFonts)(CChitin*);
		CRes* (__fastcall *AllocResObject)(CChitin*, int);
		const CString* (__fastcall *GetIconRes)(CChitin*);
		void (__fastcall *GetScreenShotFilePrefix)(CChitin*, CString*);
		int (__fastcall *FontRectOutline)(CChitin*);
		int (__fastcall *InitializeServices)(CChitin*);
		void (__fastcall *SetProgressBar)(CChitin*, unsigned __int8, int, int, int, unsigned __int8, int, unsigned __int8, int, unsigned __int8, unsigned __int8, unsigned int);
		void (__fastcall *SetProgressBarActivateEngine)(CChitin*, int);
		void (__fastcall *BroadcastMultiplayerProgressBarInfo)(CChitin*);
		void (__fastcall *SetCDSwitchStatus)(CChitin*, unsigned __int8, unsigned __int8, unsigned __int8, const CString*, unsigned __int8, unsigned __int8, unsigned __int8);
		void (__fastcall *SetCDSwitchActivateEngine)(CChitin*, int);
		void (__fastcall *OnMultiplayerSessionOpen)(CChitin*, CString*, CString*, CString*);
		void (__fastcall *OnMultiplayerSessionToClose)(CChitin*);
		void (__fastcall *OnMultiplayerSessionClose)(CChitin*);
		void (__fastcall *OnMultiplayerPlayerJoin)(CChitin*, int, const CString*);
		void (__fastcall *OnMultiplayerPlayerVisible)(CChitin*, int);
		void (__fastcall *OnMultiplayerPlayerLeave)(CChitin*, int, const CString*);
		int (__fastcall *MessageCallback)(CChitin*, unsigned __int8*, unsigned int);
		unsigned __int8 (__fastcall *GetGamespyResponse)(CChitin*, unsigned __int8, unsigned __int8**, unsigned int*);
		void (__fastcall *AsynchronousUpdate)(CChitin*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
		void (__fastcall *SelectEngine)(CChitin*, CWarp*);
		void (__fastcall *ShutDown)(CChitin*, int, const char*, const char*);
		const char* (__fastcall *GetKeyFileName)(CChitin*);
		unsigned __int8 (__fastcall *GetNumberSoundChannels)(CChitin*);
		int (__fastcall *GetMovieVolume)(CChitin*);
		void (__fastcall *LoadOptions)(CChitin*);
		void (__fastcall *PreLoadFonts)(CChitin*);
		void (__fastcall *SetSoundVolumes)(CChitin*);
		unsigned __int16 (__fastcall *GetMultiplayerGameSpyPort)(CChitin*);
		unsigned __int16 (__fastcall *GetMultiplayerDirectPlayPort)(CChitin*);
		void (__fastcall *SetRenderCount)(CChitin*, unsigned __int8);
		int (__fastcall *ConfirmQuit)(CChitin*);
		void (__fastcall *GetGameSpyGameName)(CChitin*, CString*);
		void (__fastcall *GetGameSpyCode)(CChitin*, CString*);
		void (__fastcall *GetPanicCDStrings)(CChitin*, CString*, CString*, CString*);
		void (__fastcall *OnMixerInitialize)(CChitin*);
		int (__fastcall *Is3DSound)(CChitin*, int);
		int (__fastcall *GetEAXActive)(CChitin*);
		void (__fastcall *RedrawScreen)(CChitin*);
		unsigned __int8 (__fastcall *GetSoundEnvironment)(CChitin*, CString, unsigned int*, float*, float*, float*, float*);
		unsigned __int8 (__fastcall *CutsceneModeActive)(CChitin*);

		vtbl() = delete;
	};

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

	CChitin() = delete;

	typedef void (__thiscall *type_OnResizeWindow)(CChitin* pThis, int w, int h);
	static type_OnResizeWindow p_OnResizeWindow;

	void OnResizeWindow(int w, int h)
	{
		p_OnResizeWindow(this, w, h);
	}

	virtual void virtual_SynchronousUpdate()
	{
	}

	virtual void virtual_SetupPanels()
	{
	}

	virtual unsigned int virtual_GetIDSInvalidVideoMode()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int virtual_GetIDSOpenGLDll()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int virtual_GetIDSExclusiveMode()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int virtual_GetIDSChoosePixelFormat()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int virtual_GetIDSSetPixelFormat()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int virtual_GetIDSSetGameResolution()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int virtual_GetIDSSetGameBitDepth()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int virtual_GetIDSBadDeskTopBitDepth()
	{
		return *(unsigned int*)nullptr;
	}

	virtual unsigned int virtual_GetIDSWindowsFonts()
	{
		return *(unsigned int*)nullptr;
	}

	virtual CRes* virtual_AllocResObject(int _0)
	{
		return *(CRes**)nullptr;
	}

	virtual const CString* virtual_GetIconRes()
	{
		return *(const CString**)nullptr;
	}

	virtual void virtual_GetScreenShotFilePrefix(CString* _0)
	{
	}

	virtual int virtual_FontRectOutline()
	{
		return *(int*)nullptr;
	}

	virtual int virtual_InitializeServices()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_SetProgressBar(unsigned __int8 _0, int _1, int _2, int _3, unsigned __int8 _4, int _5, unsigned __int8 _6, int _7, unsigned __int8 _8, unsigned __int8 _9, unsigned int _10)
	{
	}

	virtual void virtual_SetProgressBarActivateEngine(int _0)
	{
	}

	virtual void virtual_BroadcastMultiplayerProgressBarInfo()
	{
	}

	virtual void virtual_SetCDSwitchStatus(unsigned __int8 _0, unsigned __int8 _1, unsigned __int8 _2, const CString* _3, unsigned __int8 _4, unsigned __int8 _5, unsigned __int8 _6)
	{
	}

	virtual void virtual_SetCDSwitchActivateEngine(int _0)
	{
	}

	virtual void virtual_OnMultiplayerSessionOpen(CString* _0, CString* _1, CString* _2)
	{
	}

	virtual void virtual_OnMultiplayerSessionToClose()
	{
	}

	virtual void virtual_OnMultiplayerSessionClose()
	{
	}

	virtual void virtual_OnMultiplayerPlayerJoin(int _0, const CString* _1)
	{
	}

	virtual void virtual_OnMultiplayerPlayerVisible(int _0)
	{
	}

	virtual void virtual_OnMultiplayerPlayerLeave(int _0, const CString* _1)
	{
	}

	virtual int virtual_MessageCallback(unsigned __int8* _0, unsigned int _1)
	{
		return *(int*)nullptr;
	}

	virtual unsigned __int8 virtual_GetGamespyResponse(unsigned __int8 _0, unsigned __int8** _1, unsigned int* _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void virtual_AsynchronousUpdate(unsigned int _0, unsigned int _1, unsigned int _2, unsigned int _3, unsigned int _4)
	{
	}

	virtual void virtual_SelectEngine(CWarp* _0)
	{
	}

	virtual void virtual_ShutDown(int _0, const char* _1, const char* _2)
	{
	}

	virtual const char* virtual_GetKeyFileName()
	{
		return *(const char**)nullptr;
	}

	virtual unsigned __int8 virtual_GetNumberSoundChannels()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual int virtual_GetMovieVolume()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_LoadOptions()
	{
	}

	virtual void virtual_PreLoadFonts()
	{
	}

	virtual void virtual_SetSoundVolumes()
	{
	}

	virtual unsigned __int16 virtual_GetMultiplayerGameSpyPort()
	{
		return *(unsigned __int16*)nullptr;
	}

	virtual unsigned __int16 virtual_GetMultiplayerDirectPlayPort()
	{
		return *(unsigned __int16*)nullptr;
	}

	virtual void virtual_SetRenderCount(unsigned __int8 _0)
	{
	}

	virtual int virtual_ConfirmQuit()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_GetGameSpyGameName(CString* _0)
	{
	}

	virtual void virtual_GetGameSpyCode(CString* _0)
	{
	}

	virtual void virtual_GetPanicCDStrings(CString* _0, CString* _1, CString* _2)
	{
	}

	virtual void virtual_OnMixerInitialize()
	{
	}

	virtual int virtual_Is3DSound(int _0)
	{
		return *(int*)nullptr;
	}

	virtual int virtual_GetEAXActive()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_RedrawScreen()
	{
	}

	virtual unsigned __int8 virtual_GetSoundEnvironment(CString _0, unsigned int* _1, float* _2, float* _3, float* _4, float* _5)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 virtual_CutsceneModeActive()
	{
		return *(unsigned __int8*)nullptr;
	}
};

struct CMachineStates
{
	Array<CMachineState,6> m_machineStates;

	CMachineStates() = delete;
};

struct CItem : CResHelper<CResItem,1005>
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CItem*);

		vtbl() = delete;
	};

	int m_nAbilities;
	unsigned __int16 m_useCount1;
	unsigned __int16 m_useCount2;
	unsigned __int16 m_useCount3;
	unsigned __int16 m_wear;
	unsigned int m_flags;
	Array<CSound,2> m_useSound;
	__int16 m_numSounds;
	CGameEffectUsabilityList m_Usability;

	CItem() = delete;

	virtual void virtual_Destruct()
	{
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

	CInfinity() = delete;
};

struct CInfTileSet
{
	Array<CResTileSet*,2> tis;
	CVidTile cVidTile;
	CVRamPool* pVRPool;
	CResInfTile** pResTiles;
	unsigned int nTiles;
	unsigned int nTileSize;

	CInfTileSet() = delete;
};

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

	CInfButtonArray() = delete;

	typedef int (__thiscall *type_SetState)(CInfButtonArray* pThis, int nState);
	static type_SetState p_SetState;

	typedef void (*type_SetQuickSlot)(CButtonData* pButtonData, int nButton, int nType);
	static type_SetQuickSlot p_SetQuickSlot;

	int SetState(int nState)
	{
		return p_SetState(this, nState);
	}

	static void SetQuickSlot(CButtonData* pButtonData, int nButton, int nType)
	{
		p_SetQuickSlot(pButtonData, nButton, nType);
	}
};

struct CImmunitiesSpellLevelDecrementing
{
	Array<CSpellLevelDecrementing,10> m_levels;

	CImmunitiesSpellLevelDecrementing() = delete;
};

struct CImmunitiesSpellLevel
{
	Array<int,10> m_levels;

	CImmunitiesSpellLevel() = delete;
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

	CGameStatsSprite() = delete;
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

	CGameSpriteLastUpdate() = delete;
};

struct CGameSpriteEquipment
{
	Array<CItem*,39> m_items;
	unsigned __int8 m_selectedWeapon;
	unsigned __int16 m_selectedWeaponAbility;
	CItem* m_pTempItem;
	CGameSprite* m_pSprite;

	CGameSpriteEquipment() = delete;
};

struct CGameSaveCharacter
{
	unsigned int m_actionMode;
	Array<CButtonData,4> m_quickWeapons;
	Array<CButtonData,3> m_quickSpells;
	Array<CButtonData,3> m_quickItems;

	CGameSaveCharacter() = delete;
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

	CGameSave() = delete;
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

	CGameRemoteObjectArray() = delete;
};

struct CGamePermission
{
	Array<unsigned __int8,8> m_permission;

	CGamePermission() = delete;
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

	CMultiplayerSettings() = delete;
};

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

	CInfGame() = delete;

	typedef void (__thiscall *type_SetState)(CInfGame* pThis, __int16 state, bool allowDead);
	static type_SetState p_SetState;

	typedef void (__thiscall *type_SetIconIndex)(CInfGame* pThis, unsigned __int8 iconIndex);
	static type_SetIconIndex p_SetIconIndex;

	void SetState(__int16 state, bool allowDead)
	{
		p_SetState(this, state, allowDead);
	}

	void SetIconIndex(unsigned __int8 iconIndex)
	{
		p_SetIconIndex(this, iconIndex);
	}
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
	LCharString<32> m_scriptName;
	unsigned int m_casterLevel;
	unsigned int m_firstCall;
	unsigned int m_secondaryType;
	Array<unsigned int,15> m_pad;

	CGameEffectBase() = delete;
};

struct CGameEffect : CGameEffectBase
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CGameEffect*, unsigned int);
		CGameEffect* (__fastcall *Copy)(CGameEffect*);
		int (__fastcall *ApplyEffect)(CGameEffect*, CGameSprite*);
		int (__fastcall *ResolveEffect)(CGameEffect*, CGameSprite*);
		void (__fastcall *OnAdd)(CGameEffect*, CGameSprite*);
		void (__fastcall *OnAddSpecific)(CGameEffect*, CGameSprite*);
		void (__fastcall *OnLoad)(CGameEffect*, CGameSprite*);
		int (__fastcall *CheckSave)(CGameEffect*, CGameSprite*, unsigned __int8*, unsigned __int8*, unsigned __int8*, unsigned __int8*, unsigned __int8*, unsigned __int8*);
		int (__fastcall *UsesDice)(CGameEffect*);
		void (__fastcall *DisplayString)(CGameEffect*, CGameSprite*);
		void (__fastcall *OnRemove)(CGameEffect*, CGameSprite*);

		vtbl() = delete;
	};

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

	CGameEffect() = delete;

	typedef CGameEffect* (*type_DecodeEffect)(Item_effect_st* effect, const CPoint* source, int sourceID, const CPoint* target, int sourceTarget);
	static type_DecodeEffect p_DecodeEffect;

	static CGameEffect* DecodeEffect(Item_effect_st* effect, const CPoint* source, int sourceID, const CPoint* target, int sourceTarget)
	{
		return p_DecodeEffect(effect, source, sourceID, target, sourceTarget);
	}

	virtual void virtual_Destruct(unsigned int _0)
	{
	}

	virtual CGameEffect* virtual_Copy()
	{
		return *(CGameEffect**)nullptr;
	}

	virtual int virtual_ApplyEffect(CGameSprite* _0)
	{
		return *(int*)nullptr;
	}

	virtual int virtual_ResolveEffect(CGameSprite* _0)
	{
		return *(int*)nullptr;
	}

	virtual void virtual_OnAdd(CGameSprite* _0)
	{
	}

	virtual void virtual_OnAddSpecific(CGameSprite* _0)
	{
	}

	virtual void virtual_OnLoad(CGameSprite* _0)
	{
	}

	virtual int virtual_CheckSave(CGameSprite* _0, unsigned __int8* _1, unsigned __int8* _2, unsigned __int8* _3, unsigned __int8* _4, unsigned __int8* _5, unsigned __int8* _6)
	{
		return *(int*)nullptr;
	}

	virtual int virtual_UsesDice()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_DisplayString(CGameSprite* _0)
	{
	}

	virtual void virtual_OnRemove(CGameSprite* _0)
	{
	}
};

struct CGameEffectUsability : CGameEffect
{
	struct vtbl : CGameEffect::vtbl
	{
		vtbl() = delete;
	};

	CGameEffectUsability() = delete;
};

struct CGameAnimationType
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CGameAnimationType*);
		void (__fastcall *CalculateFxRect)(CGameAnimationType*, CRect*, CPoint*, int);
		void (__fastcall *CalculateGCBoundsRect)(CGameAnimationType*, CRect*, const CPoint*, const CPoint*, int, int, int);
		void (__fastcall *ChangeDirection)(CGameAnimationType*, __int16);
		void (__fastcall *EquipArmor)(CGameAnimationType*, char, unsigned __int8*);
		void (__fastcall *EquipHelmet)(CGameAnimationType*, const CString*, unsigned __int8*);
		void (__fastcall *EquipShield)(CGameAnimationType*, const CString*, unsigned __int8*);
		void (__fastcall *EquipWeapon)(CGameAnimationType*, const CString*, unsigned __int8*, unsigned int, const unsigned __int16*);
		CVidPalette* (__fastcall *GetAnimationPalette)(CGameAnimationType*, unsigned __int8);
		void (__fastcall *GetAnimationResRef)(CGameAnimationType*, CString*, unsigned __int8);
		unsigned __int8 (__fastcall *CanLieDown)(CGameAnimationType*);
		unsigned __int8 (__fastcall *DetectedByInfravision)(CGameAnimationType*);
		unsigned __int16 (__fastcall *GetCastFrame)(CGameAnimationType*);
		unsigned __int8 (__fastcall *GetColorBlood)(CGameAnimationType*);
		unsigned __int8 (__fastcall *GetColorChunks)(CGameAnimationType*);
		unsigned __int8 (__fastcall *GetListType)(CGameAnimationType*);
		void (__fastcall *SetListType)(CGameAnimationType*, unsigned __int8);
		unsigned __int8 (__fastcall *GetMoveScale)(CGameAnimationType*);
		void (__fastcall *SetMoveScale)(CGameAnimationType*, unsigned __int8);
		void (__fastcall *ResetMoveScale)(CGameAnimationType*);
		unsigned __int8 (__fastcall *GetMoveScaleDefault)(CGameAnimationType*);
		NECK_POINTS (__fastcall *GetNeckOffsets)(CGameAnimationType*, __int16);
		const CRect* (__fastcall *GetEllipseRect)(CGameAnimationType*);
		int (__fastcall *GetPathSmooth)(CGameAnimationType*);
		unsigned __int8 (__fastcall *GetPersonalSpace)(CGameAnimationType*);
		const char* (__fastcall *GetSndArmor)(CGameAnimationType*, char*);
		const char* (__fastcall *GetSndDeath)(CGameAnimationType*, char*);
		const char* (__fastcall *GetSndReady)(CGameAnimationType*, char*);
		const char* (__fastcall *GetSndWalk)(CGameAnimationType*, char*, __int16);
		unsigned int (__fastcall *GetSndWalkFreq)(CGameAnimationType*);
		int (__fastcall *IsFalseColor)(CGameAnimationType*);
		int (__fastcall *IsInvulnerable)(CGameAnimationType*);
		int (__fastcall *IsMirroring)(CGameAnimationType*);
		int (__fastcall *IsBeginningOfSequence)(CGameAnimationType*);
		int (__fastcall *IsEndOfSequence)(CGameAnimationType*);
		int (__fastcall *IsEndOfTwitchSequence)(CGameAnimationType*);
		void (__fastcall *IncrementFrame)(CGameAnimationType*);
		void (__fastcall *DecrementFrame)(CGameAnimationType*);
		void (__fastcall *Render)(CGameAnimationType*, CInfinity*, CVidMode*, const CRect*, const CPoint*, const CPoint*, unsigned int, unsigned int, const CRect*, int, int, int, unsigned __int8, CGameSprite*);
		void (__fastcall *ClearColorEffects)(CGameAnimationType*, unsigned __int8);
		void (__fastcall *ClearColorEffectsAll)(CGameAnimationType*);
		void (__fastcall *SetColorEffect)(CGameAnimationType*, unsigned __int8, unsigned __int8, unsigned int, unsigned __int8);
		void (__fastcall *SetColorEffectAll)(CGameAnimationType*, unsigned __int8, unsigned int, unsigned __int8);
		void (__fastcall *SetColorRange)(CGameAnimationType*, unsigned __int8, unsigned __int8);
		void (__fastcall *SetColorRangeAll)(CGameAnimationType*, unsigned __int8);
		__int16 (__fastcall *SetSequence)(CGameAnimationType*, __int16);
		int (__fastcall *GetHeightOffset)(CGameAnimationType*);
		void (__fastcall *CalculateFxRectMax)(CGameAnimationType*, CRect*, CPoint*, int);
		void (__fastcall *CalculateEllipseRect)(CGameAnimationType*);
		void (__fastcall *SetNeckOffsets)(CGameAnimationType*, __int16, __int16, __int16, __int16, __int16, __int16, __int16, __int16, __int16, __int16, __int16, __int16, __int16, __int16, __int16, __int16);
		unsigned __int8 (__fastcall *GetAttackFrameType)(CGameAnimationType*, unsigned __int8, unsigned __int8, unsigned __int8);
		int (__fastcall *GetAboveGround)(CGameAnimationType*);
		__int16 (__fastcall *GetAwakePlayInReverse)(CGameAnimationType*);
		void (__fastcall *SetBrightest)(CGameAnimationType*, unsigned __int8);
		void (__fastcall *SetBrightestDesired)(CGameAnimationType*, unsigned __int8);
		__int16 (__fastcall *GetCastHeight)(CGameAnimationType*);
		void (__fastcall *GetCastingOffset)(CGameAnimationType*, CPoint*);
		unsigned __int8 (__fastcall *GetCurrentSequenceAndFrame)(CGameAnimationType*, __int16*, __int16*);
		unsigned __int8 (__fastcall *GetCurrentResRef)(CGameAnimationType*, CString*, CString*, CString*, CString*);
		void (__fastcall *OverrideAnimation)(CGameAnimationType*, CResRef, int);
		void (__fastcall *Marshal)(CGameAnimationType*, unsigned __int8**, unsigned int*);
		bool (__fastcall *Unmarshal)(CGameAnimationType*, CResRef);

		vtbl() = delete;
	};

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

	CGameAnimationType() = delete;

	virtual void virtual_Destruct()
	{
	}

	virtual void virtual_CalculateFxRect(CRect* _0, CPoint* _1, int _2)
	{
	}

	virtual void virtual_CalculateGCBoundsRect(CRect* _0, const CPoint* _1, const CPoint* _2, int _3, int _4, int _5)
	{
	}

	virtual void virtual_ChangeDirection(__int16 _0)
	{
	}

	virtual void virtual_EquipArmor(char _0, unsigned __int8* _1)
	{
	}

	virtual void virtual_EquipHelmet(const CString* _0, unsigned __int8* _1)
	{
	}

	virtual void virtual_EquipShield(const CString* _0, unsigned __int8* _1)
	{
	}

	virtual void virtual_EquipWeapon(const CString* _0, unsigned __int8* _1, unsigned int _2, const unsigned __int16* _3)
	{
	}

	virtual CVidPalette* virtual_GetAnimationPalette(unsigned __int8 _0)
	{
		return *(CVidPalette**)nullptr;
	}

	virtual void virtual_GetAnimationResRef(CString* _0, unsigned __int8 _1)
	{
	}

	virtual unsigned __int8 virtual_CanLieDown()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 virtual_DetectedByInfravision()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int16 virtual_GetCastFrame()
	{
		return *(unsigned __int16*)nullptr;
	}

	virtual unsigned __int8 virtual_GetColorBlood()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 virtual_GetColorChunks()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 virtual_GetListType()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void virtual_SetListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 virtual_GetMoveScale()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void virtual_SetMoveScale(unsigned __int8 _0)
	{
	}

	virtual void virtual_ResetMoveScale()
	{
	}

	virtual unsigned __int8 virtual_GetMoveScaleDefault()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual NECK_POINTS virtual_GetNeckOffsets(__int16 _0)
	{
		return *(NECK_POINTS*)nullptr;
	}

	virtual const CRect* virtual_GetEllipseRect()
	{
		return *(const CRect**)nullptr;
	}

	virtual int virtual_GetPathSmooth()
	{
		return *(int*)nullptr;
	}

	virtual unsigned __int8 virtual_GetPersonalSpace()
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual const char* virtual_GetSndArmor(char* _0)
	{
		return *(const char**)nullptr;
	}

	virtual const char* virtual_GetSndDeath(char* _0)
	{
		return *(const char**)nullptr;
	}

	virtual const char* virtual_GetSndReady(char* _0)
	{
		return *(const char**)nullptr;
	}

	virtual const char* virtual_GetSndWalk(char* _0, __int16 _1)
	{
		return *(const char**)nullptr;
	}

	virtual unsigned int virtual_GetSndWalkFreq()
	{
		return *(unsigned int*)nullptr;
	}

	virtual int virtual_IsFalseColor()
	{
		return *(int*)nullptr;
	}

	virtual int virtual_IsInvulnerable()
	{
		return *(int*)nullptr;
	}

	virtual int virtual_IsMirroring()
	{
		return *(int*)nullptr;
	}

	virtual int virtual_IsBeginningOfSequence()
	{
		return *(int*)nullptr;
	}

	virtual int virtual_IsEndOfSequence()
	{
		return *(int*)nullptr;
	}

	virtual int virtual_IsEndOfTwitchSequence()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_IncrementFrame()
	{
	}

	virtual void virtual_DecrementFrame()
	{
	}

	virtual void virtual_Render(CInfinity* _0, CVidMode* _1, const CRect* _2, const CPoint* _3, const CPoint* _4, unsigned int _5, unsigned int _6, const CRect* _7, int _8, int _9, int _10, unsigned __int8 _11, CGameSprite* _12)
	{
	}

	virtual void virtual_ClearColorEffects(unsigned __int8 _0)
	{
	}

	virtual void virtual_ClearColorEffectsAll()
	{
	}

	virtual void virtual_SetColorEffect(unsigned __int8 _0, unsigned __int8 _1, unsigned int _2, unsigned __int8 _3)
	{
	}

	virtual void virtual_SetColorEffectAll(unsigned __int8 _0, unsigned int _1, unsigned __int8 _2)
	{
	}

	virtual void virtual_SetColorRange(unsigned __int8 _0, unsigned __int8 _1)
	{
	}

	virtual void virtual_SetColorRangeAll(unsigned __int8 _0)
	{
	}

	virtual __int16 virtual_SetSequence(__int16 _0)
	{
		return *(__int16*)nullptr;
	}

	virtual int virtual_GetHeightOffset()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_CalculateFxRectMax(CRect* _0, CPoint* _1, int _2)
	{
	}

	virtual void virtual_CalculateEllipseRect()
	{
	}

	virtual void virtual_SetNeckOffsets(__int16 _0, __int16 _1, __int16 _2, __int16 _3, __int16 _4, __int16 _5, __int16 _6, __int16 _7, __int16 _8, __int16 _9, __int16 _10, __int16 _11, __int16 _12, __int16 _13, __int16 _14, __int16 _15)
	{
	}

	virtual unsigned __int8 virtual_GetAttackFrameType(unsigned __int8 _0, unsigned __int8 _1, unsigned __int8 _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual int virtual_GetAboveGround()
	{
		return *(int*)nullptr;
	}

	virtual __int16 virtual_GetAwakePlayInReverse()
	{
		return *(__int16*)nullptr;
	}

	virtual void virtual_SetBrightest(unsigned __int8 _0)
	{
	}

	virtual void virtual_SetBrightestDesired(unsigned __int8 _0)
	{
	}

	virtual __int16 virtual_GetCastHeight()
	{
		return *(__int16*)nullptr;
	}

	virtual void virtual_GetCastingOffset(CPoint* _0)
	{
	}

	virtual unsigned __int8 virtual_GetCurrentSequenceAndFrame(__int16* _0, __int16* _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 virtual_GetCurrentResRef(CString* _0, CString* _1, CString* _2, CString* _3)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void virtual_OverrideAnimation(CResRef _0, int _1)
	{
	}

	virtual void virtual_Marshal(unsigned __int8** _0, unsigned int* _1)
	{
	}

	virtual bool virtual_Unmarshal(CResRef _0)
	{
		return *(bool*)nullptr;
	}
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

	CDerivedStatsTemplate() = delete;
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

	CDerivedStats() = delete;

	typedef long (__thiscall *type_GetAtOffset)(CDerivedStats* pThis, short offset);
	static type_GetAtOffset p_GetAtOffset;

	typedef int (__thiscall *type_GetSpellState)(CDerivedStats* pThis, uint bit);
	static type_GetSpellState p_GetSpellState;

	long GetAtOffset(short offset)
	{
		return p_GetAtOffset(this, offset);
	}

	int GetSpellState(uint bit)
	{
		return p_GetSpellState(this, bit);
	}
};

struct CCreatureFileMemorizedSpell
{
	Array<unsigned __int8,8> m_spellId;
	unsigned __int16 m_flags;
	Array<unsigned __int8,2> structureAlignment1;

	CCreatureFileMemorizedSpell() = delete;
};

struct CCreatureFileKnownSpell
{
	Array<unsigned __int8,8> m_knownSpellId;
	unsigned __int16 m_spellLevel;
	unsigned __int16 m_magicType;

	CCreatureFileKnownSpell() = delete;
};

struct CCreatureFileItem
{
	Array<unsigned __int8,8> m_itemId;
	unsigned __int16 m_wear;
	Array<unsigned __int16,3> m_usageCount;
	unsigned int m_dynamicFlags;

	CCreatureFileItem() = delete;
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

	CCreatureFileHeader() = delete;
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

	CBlood() = delete;
};

struct CBaldurProjector : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CBaldurProjector() = delete;
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

	CBaldurMessage() = delete;
};

struct CBaldurChitin : CChitin
{
	struct vtbl : CChitin::vtbl
	{
		void (__fastcall *ShutDown_2)(CBaldurChitin*, int, char*, const char*);
		void (__fastcall *UnloadFonts)(CBaldurChitin*);

		vtbl() = delete;
	};

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

	CBaldurChitin() = delete;

	virtual void virtual_ShutDown_2(int _0, char* _1, const char* _2)
	{
	}

	virtual void virtual_UnloadFonts()
	{
	}
};

struct CAreaUserNote
{
	unsigned __int16 m_startX;
	unsigned __int16 m_startY;
	unsigned int m_note;
	unsigned int m_dwflags;
	unsigned int m_id;
	Array<unsigned int,9> m_notUsed;

	CAreaUserNote() = delete;
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

	CGameAreaNotes() = delete;
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

	CAreaSoundsAndMusic() = delete;
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

	CAreaFileStaticObject() = delete;
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

	CAreaFileSoundObject() = delete;
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

	CAreaFileRestEncounter() = delete;
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

	CAreaFileRandomMonsterSpawningPoint() = delete;
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

	CAreaFileProjectileObject() = delete;
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

	CAreaFileHeader() = delete;
};

struct CGameArea
{
	struct m_cWalkableRenderCache_t
	{
		int nTriCount;
		int nLineCount;
		CPoint* pVertexArray;
		bool bReady;

		m_cWalkableRenderCache_t() = delete;
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
	CTypedPtrList<CPtrList,long> m_lVertSort;
	CTypedPtrList<CPtrList,long> m_lVertSortBack;
	CTypedPtrList<CPtrList,long> m_lVertSortFlight;
	CTypedPtrList<CPtrList,long> m_lVertSortUnder;
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

	CGameArea() = delete;

	typedef int (__thiscall *type_GetNearest2)(CGameArea* pThis, CPoint center, const CAIObjectType* type, short range, const byte* terrainTable, int lineOfSight, int seeInvisible, byte nNearest);
	static type_GetNearest2 p_GetNearest2;

	typedef int (__thiscall *type_AdjustTarget)(CGameArea* pThis, CPoint start, CPoint* goal, byte personalSpace, short tolerance);
	static type_AdjustTarget p_AdjustTarget;

	typedef int (__thiscall *type_CheckWalkable)(CGameArea* pThis, CPoint* start, CPoint* goal, byte* terrainTable, byte personalSpace, byte bCheckIfExplored);
	static type_CheckWalkable p_CheckWalkable;

	typedef int (__thiscall *type_CheckLOS)(CGameArea* pThis, const CPoint* start, const CPoint* goal, const byte* terrainTable, byte bCheckIfExplored, short nVisualRange);
	static type_CheckLOS p_CheckLOS;

	typedef void (__thiscall *type_GetAllInRange1)(CGameArea* pThis, const CPoint* center, const CAIObjectType* type, short range, const byte* terrainTable, CTypedPtrList<CPtrList,long>* targets, int lineOfSight, int checkForNonSprites);
	static type_GetAllInRange1 p_GetAllInRange1;

	typedef void (__thiscall *type_GetAllInRange2)(CGameArea* pThis, __POSITION* posVertList, const CPoint* ptStart, const CAIObjectType* type, short range, const byte* terrainTable, CTypedPtrList<CPtrList,long>* targets, int lineOfSight, int checkForNonSprites);
	static type_GetAllInRange2 p_GetAllInRange2;

	int Override_AdjustTarget(CPoint start, CPoint* goal, byte personalSpace, short tolerance);

	int Override_GetNearest(int startObject, const CAIObjectType* type, short range, const byte* terrainTable, int checkLOS, int seeInvisible, int ignoreSleeping, byte nNearest, int ignoreDead);

	int Override_GetNearest2(CPoint center, const CAIObjectType* type, short range, const byte* terrainTable, int lineOfSight, int seeInvisible, byte nNearest);

	int GetNearest2(CPoint center, const CAIObjectType* type, short range, const byte* terrainTable, int lineOfSight, int seeInvisible, byte nNearest)
	{
		return p_GetNearest2(this, center, type, range, terrainTable, lineOfSight, seeInvisible, nNearest);
	}

	int AdjustTarget(CPoint start, CPoint* goal, byte personalSpace, short tolerance)
	{
		return p_AdjustTarget(this, start, goal, personalSpace, tolerance);
	}

	int CheckWalkable(CPoint* start, CPoint* goal, byte* terrainTable, byte personalSpace, byte bCheckIfExplored)
	{
		return p_CheckWalkable(this, start, goal, terrainTable, personalSpace, bCheckIfExplored);
	}

	int CheckLOS(const CPoint* start, const CPoint* goal, const byte* terrainTable, byte bCheckIfExplored, short nVisualRange)
	{
		return p_CheckLOS(this, start, goal, terrainTable, bCheckIfExplored, nVisualRange);
	}

	void GetAllInRange1(const CPoint* center, const CAIObjectType* type, short range, const byte* terrainTable, CTypedPtrList<CPtrList,long>* targets, int lineOfSight, int checkForNonSprites)
	{
		p_GetAllInRange1(this, center, type, range, terrainTable, targets, lineOfSight, checkForNonSprites);
	}

	void GetAllInRange2(__POSITION* posVertList, const CPoint* ptStart, const CAIObjectType* type, short range, const byte* terrainTable, CTypedPtrList<CPtrList,long>* targets, int lineOfSight, int checkForNonSprites)
	{
		p_GetAllInRange2(this, posVertList, ptStart, type, range, terrainTable, targets, lineOfSight, checkForNonSprites);
	}
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

	CAreaFileContainer() = delete;
};

struct CAreaFileCharacterEntryPoint
{
	Array<char,32> m_entryName;
	unsigned __int16 m_startX;
	unsigned __int16 m_startY;
	unsigned int m_facing;
	Array<unsigned int,16> m_notUsed;

	CAreaFileCharacterEntryPoint() = delete;
};

struct CAIObjectType
{
	static CAIObjectType* p_NOONE;
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

	CAIObjectType() = delete;

	typedef void (__thiscall *type_Construct1)(CAIObjectType* pThis, byte EnemyAlly, byte General, byte Race, byte Class, byte Specifics, byte Gender, byte Alignment, int Instance, byte* SpecialCase, CString* name);
	static type_Construct1 p_Construct1;

	typedef void (__thiscall *type_Decode)(CAIObjectType* pThis, CGameAIBase* caller);
	static type_Decode p_Decode;

	typedef CGameObject* (__thiscall *type_GetShare)(CAIObjectType* pThis, CGameAIBase* caller, int checkBackList);
	static type_GetShare p_GetShare;

	typedef byte (__thiscall *type_OfType)(const CAIObjectType* pThis, const CAIObjectType* type, int checkForNonSprites, int noNonSprites, int deathMatchAllowance);
	static type_OfType p_OfType;

	typedef void (__thiscall *type_Set)(CAIObjectType* pThis, const CAIObjectType* that);
	static type_Set p_Set;

	void Construct(byte EnemyAlly, byte General, byte Race, byte Class, byte Specifics, byte Gender, byte Alignment, int Instance, byte* SpecialCase, CString* name)
	{
		p_Construct1(this, EnemyAlly, General, Race, Class, Specifics, Gender, Alignment, Instance, SpecialCase, name);
	}

	void Decode(CGameAIBase* caller)
	{
		p_Decode(this, caller);
	}

	CGameObject* GetShare(CGameAIBase* caller, int checkBackList)
	{
		return p_GetShare(this, caller, checkBackList);
	}

	byte OfType(const CAIObjectType* type, int checkForNonSprites, int noNonSprites, int deathMatchAllowance) const
	{
		return p_OfType(this, type, checkForNonSprites, noNonSprites, deathMatchAllowance);
	}

	void Set(const CAIObjectType* that)
	{
		p_Set(this, that);
	}

	void Construct(const CAIObjectType* toCopy)
	{
		this->m_name.m_pchData = *p_afxPchNil;
		this->Set(toCopy);
	}

	void Destruct()
	{
		this->m_name.Destruct();
	}
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

	CAIAction() = delete;

	typedef void (__thiscall *type_Construct1)(CAIAction* pThis, short actionID, CPoint* dest, int specificID, int sp2);
	static type_Construct1 p_Construct1;

	typedef void (__thiscall *type_ConstructCopy)(CAIAction* pThis, const CAIAction* that);
	static type_ConstructCopy p_ConstructCopy;

	typedef void (__thiscall *type_Destruct)(CAIAction* pThis);
	static type_Destruct p_Destruct;

	typedef CAIAction* (__thiscall *type_operator_equ)(CAIAction* pThis, const CAIAction* y);
	static type_operator_equ p_operator_equ;

	typedef void (__thiscall *type_Decode)(CAIAction* pThis, CGameAIBase* caller);
	static type_Decode p_Decode;

	void Construct(short actionID, CPoint* dest, int specificID, int sp2)
	{
		p_Construct1(this, actionID, dest, specificID, sp2);
	}

	void Construct(const CAIAction* that)
	{
		p_ConstructCopy(this, that);
	}

	void Destruct()
	{
		p_Destruct(this);
	}

	CAIAction* operator_equ(const CAIAction* y)
	{
		return p_operator_equ(this, y);
	}

	void Decode(CGameAIBase* caller)
	{
		p_Decode(this, caller);
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

	struct vtbl
	{
		void (__fastcall *Destruct)(CSpawn*);

		vtbl() = delete;
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

	CSpawn() = delete;

	virtual void virtual_Destruct()
	{
	}
};

struct CSelectiveWeaponType
{
	int m_slot;
	CAIObjectType m_type;
	CWeaponIdentification m_weapon;

	CSelectiveWeaponType() = delete;
};

struct CSelectiveBonus
{
	CAIObjectType m_type;
	int m_bonus;

	CSelectiveBonus() = delete;
};

struct CScreenStore : CBaldurEngine
{
	struct vtbl : CBaldurEngine::vtbl
	{
		vtbl() = delete;
	};

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

	CScreenStore() = delete;
};

struct CGameObject
{
	struct vtbl
	{
		void (__fastcall *Destruct)(CGameObject*);
		CGameObjectType (__fastcall *GetObjectType)(CGameObject*);
		void (__fastcall *AddToArea)(CGameObject*, CGameArea*, const CPoint*, int, unsigned __int8);
		void (__fastcall *AIUpdate)(CGameObject*);
		const CAIObjectType* (__fastcall *GetAIType)(CGameObject*);
		int (__fastcall *GetTargetId)(CGameObject*);
		void (__fastcall *GetNextWaypoint)(CGameObject*, CPoint*);
		CTypedPtrList<CPtrList,long>::CNode* (__fastcall *GetVertListPos)(CGameObject*);
		VertListType (__fastcall *GetVertListType)(CGameObject*);
		void (__fastcall *SetVertListType)(CGameObject*, unsigned __int8);
		unsigned __int8 (__fastcall *CanSaveGame)(CGameObject*, unsigned int*, int, int);
		unsigned __int8 (__fastcall *CompressTime)(CGameObject*, unsigned int);
		void (__fastcall *DebugDump)(CGameObject*, const CString*, unsigned __int8);
		int (__fastcall *IsOver)(CGameObject*, const CPoint*);
		int (__fastcall *DoesIntersect)(CGameObject*, CRect);
		int (__fastcall *OnSearchMap)(CGameObject*);
		void (__fastcall *OnActionButton)(CGameObject*, const CPoint*);
		void (__fastcall *OnFormationButton)(CGameObject*, const CPoint*);
		void (__fastcall *RemoveFromArea)(CGameObject*);
		void (__fastcall *Render)(CGameObject*, CGameArea*, CVidMode*);
		unsigned __int8 (__fastcall *DoAIUpdate)(CGameObject*, unsigned __int8, int);
		void (__fastcall *SetAIType)(CGameObject*, const CAIObjectType*, int);
		void (__fastcall *SetCursor)(CGameObject*, int);
		void (__fastcall *SetTarget)(CGameObject*, CPoint, int);
		void (__fastcall *SetVertListPos)(CGameObject*, __POSITION*);
		int (__fastcall *EvaluateStatusTrigger)(CGameObject*, const CAITrigger*);

		vtbl() = delete;
	};

	static Array<byte,16>* p_DEFAULT_VISIBLE_TERRAIN_TABLE;
	static Array<byte,16>* p_DEFAULT_TERRAIN_TABLE;
	CGameObjectType m_objectType;
	CPoint m_pos;
	int m_posZ;
	CGameArea* m_pArea;
	__POSITION* m_posVertList;
	VertListType m_listType;
	CAIObjectType m_typeAI;
	int m_id;
	__int16 m_canBeSeen;
	int m_remotePlayerID;
	int m_remoteObjectID;
	unsigned __int8 m_AISpeed;
	unsigned __int8 m_bLocalControl;
	unsigned __int8 m_AIInhibitor;

	CGameObject() = delete;

	virtual void virtual_Destruct()
	{
	}

	virtual CGameObjectType virtual_GetObjectType()
	{
		return *(CGameObjectType*)nullptr;
	}

	virtual void virtual_AddToArea(CGameArea* _0, const CPoint* _1, int _2, unsigned __int8 _3)
	{
	}

	virtual void virtual_AIUpdate()
	{
	}

	virtual const CAIObjectType* virtual_GetAIType()
	{
		return *(const CAIObjectType**)nullptr;
	}

	virtual int virtual_GetTargetId()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_GetNextWaypoint(CPoint* _0)
	{
	}

	virtual CTypedPtrList<CPtrList,long>::CNode* virtual_GetVertListPos()
	{
		return *(CTypedPtrList<CPtrList,long>::CNode**)nullptr;
	}

	virtual VertListType virtual_GetVertListType()
	{
		return *(VertListType*)nullptr;
	}

	virtual void virtual_SetVertListType(unsigned __int8 _0)
	{
	}

	virtual unsigned __int8 virtual_CanSaveGame(unsigned int* _0, int _1, int _2)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual unsigned __int8 virtual_CompressTime(unsigned int _0)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void virtual_DebugDump(const CString* _0, unsigned __int8 _1)
	{
	}

	virtual int virtual_IsOver(const CPoint* _0)
	{
		return *(int*)nullptr;
	}

	virtual int virtual_DoesIntersect(CRect _0)
	{
		return *(int*)nullptr;
	}

	virtual int virtual_OnSearchMap()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_OnActionButton(const CPoint* _0)
	{
	}

	virtual void virtual_OnFormationButton(const CPoint* _0)
	{
	}

	virtual void virtual_RemoveFromArea()
	{
	}

	virtual void virtual_Render(CGameArea* _0, CVidMode* _1)
	{
	}

	virtual unsigned __int8 virtual_DoAIUpdate(unsigned __int8 _0, int _1)
	{
		return *(unsigned __int8*)nullptr;
	}

	virtual void virtual_SetAIType(const CAIObjectType* _0, int _1)
	{
	}

	virtual void virtual_SetCursor(int _0)
	{
	}

	virtual void virtual_SetTarget(CPoint _0, int _1)
	{
	}

	virtual void virtual_SetVertListPos(__POSITION* _0)
	{
	}

	virtual int virtual_EvaluateStatusTrigger(const CAITrigger* _0)
	{
		return *(int*)nullptr;
	}
};

struct CGameFireball3d : CGameObject
{
	struct vtbl : CGameObject::vtbl
	{
		vtbl() = delete;
	};

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

	CGameFireball3d() = delete;
};

struct CProjectile : CGameObject
{
	struct vtbl : CGameObject::vtbl
	{
		void (__fastcall *Fire)(CProjectile*, CGameArea*, int, int, CPoint, int, __int16);
		void (__fastcall *OnArrival)(CProjectile*);
		void (__fastcall *RemoveSelf)(CProjectile*);
		void (__fastcall *DeliverEffects)(CProjectile*);
		void (__fastcall *CallBack)(CProjectile*);
		unsigned int (__fastcall *GetDefaultRenderFlags)(CProjectile*);
		void (__fastcall *SetDefaultRenderFlags)(CProjectile*, unsigned int);
		int (__fastcall *SaveProjectile)(CProjectile*);
		void (__fastcall *Marshal)(CProjectile*, SProjectileWrapper*);
		CAIObjectType* (__fastcall *GetTargetType)(CProjectile*, CAIObjectType*);
		void (__fastcall *SetTargetType)(CProjectile*, const CAIObjectType*);
		void (__fastcall *GetPreview)(CProjectile*, CGameArea*);

		vtbl() = delete;
	};

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

	CProjectile() = delete;

	virtual void virtual_Fire(CGameArea* _0, int _1, int _2, CPoint _3, int _4, __int16 _5)
	{
	}

	virtual void virtual_OnArrival()
	{
	}

	virtual void virtual_RemoveSelf()
	{
	}

	virtual void virtual_DeliverEffects()
	{
	}

	virtual void virtual_CallBack()
	{
	}

	virtual unsigned int virtual_GetDefaultRenderFlags()
	{
		return *(unsigned int*)nullptr;
	}

	virtual void virtual_SetDefaultRenderFlags(unsigned int _0)
	{
	}

	virtual int virtual_SaveProjectile()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_Marshal(SProjectileWrapper* _0)
	{
	}

	virtual CAIObjectType* virtual_GetTargetType()
	{
		return *(CAIObjectType**)nullptr;
	}

	virtual void virtual_SetTargetType(const CAIObjectType* _0)
	{
	}

	virtual void virtual_GetPreview(CGameArea* _0)
	{
	}
};

struct CObjectMarker : CGameObject
{
	struct vtbl : CGameObject::vtbl
	{
		vtbl() = delete;
	};

	CList<long,long> m_lstObjectIds;
	bool m_bHealthBarMarker;

	CObjectMarker() = delete;
};

struct CGameTemporal : CGameObject
{
	struct vtbl : CGameObject::vtbl
	{
		vtbl() = delete;
	};

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

	CGameTemporal() = delete;
};

struct CGameStatic : CGameObject
{
	struct vtbl : CGameObject::vtbl
	{
		vtbl() = delete;
	};

	CAreaFileStaticObject m_header;
	CVidCell m_vidCell;
	CResWebm* m_pMovie;
	CResPVR* m_pImage;
	int m_bRender;
	CSize m_size;
	CTypedPtrList<CPtrList,CVidCell*> m_secondaryVidCellList;
	int m_bNewPalette;
	CVidBitmap m_newPalette;

	CGameStatic() = delete;
};

struct CGameSpawning : CGameObject
{
	struct vtbl : CGameObject::vtbl
	{
		vtbl() = delete;
	};

	CAreaFileRandomMonsterSpawningPoint m_spawningObject;
	Array<unsigned __int8,16> m_terrainTable;
	Array<unsigned __int8,16> m_visibleTerrainTable;
	int m_nTrackingCounter;
	unsigned int m_weightSum;

	CGameSpawning() = delete;
};

struct CGameSound : CGameObject
{
	struct vtbl : CGameObject::vtbl
	{
		vtbl() = delete;
	};

	CAreaFileSoundObject m_soundObject;
	CSound m_looping;
	int m_bLoopPlaying;
	int m_period;
	int m_periodCount;
	unsigned __int8 m_currentSound;
	unsigned int m_timeOfDayActive;

	CGameSound() = delete;
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

	CAITrigger() = delete;
};

struct CGameAIBase : CGameObject
{
	struct vtbl : CGameObject::vtbl
	{
		void (__fastcall *ClearActions)(CGameAIBase*, int);
		void (__fastcall *UpdateTarget)(CGameAIBase*, CGameObject*);
		void (__fastcall *AddAction)(CGameAIBase*, const CAIAction*);
		void (__fastcall *AddEffect)(CGameAIBase*, CGameEffect*, unsigned __int8, int, int);
		void (__fastcall *ClearAI)(CGameAIBase*, unsigned __int8);
		void (__fastcall *DoAction)(CGameAIBase*);
		__int16 (__fastcall *ExecuteAction)(CGameAIBase*);
		void (__fastcall *InsertAction)(CGameAIBase*, const CAIAction*);
		void (__fastcall *ProcessAI)(CGameAIBase*);
		void (__fastcall *SetCurrAction)(CGameAIBase*, const CAIAction*);
		void (__fastcall *SetScript)(CGameAIBase*, __int16, CAIScript*);
		__int16 (__fastcall *GetVisualRange)(CGameAIBase*);
		__int16 (__fastcall *GetAttackRange)(CGameAIBase*);
		byte* (__fastcall *GetVisibleTerrainTable)(CGameAIBase*);
		const unsigned __int8* (__fastcall *GetTerrainTable)(CGameAIBase*);
		int (__fastcall *QuickDecode)(CGameAIBase*, CAITrigger*, CGameSprite**);
		__int16 (__fastcall *GetHelpRange)(CGameAIBase*);
		void (__fastcall *ApplyTriggers)(CGameAIBase*);
		void (__fastcall *AutoPause)(CGameAIBase*, unsigned int);
		int (__fastcall *GetCanSeeInvisible)(CGameAIBase*);
		void (__fastcall *OnActionRemoval)(CGameAIBase*, CAIAction*);
		CRect* (__fastcall *GetBounding)(CGameAIBase*, CRect*);

		vtbl() = delete;
	};

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

	CGameAIBase() = delete;

	typedef CGameObject* (__thiscall *type_GetTargetShare)(CGameAIBase* pThis);
	static type_GetTargetShare p_GetTargetShare;

	CGameObject* GetTargetShare()
	{
		return p_GetTargetShare(this);
	}

	virtual void virtual_ClearActions(int _0)
	{
	}

	virtual void virtual_UpdateTarget(CGameObject* _0)
	{
	}

	virtual void virtual_AddAction(const CAIAction* _0)
	{
	}

	virtual void virtual_AddEffect(CGameEffect* _0, unsigned __int8 _1, int _2, int _3)
	{
	}

	virtual void virtual_ClearAI(unsigned __int8 _0)
	{
	}

	virtual void virtual_DoAction()
	{
	}

	virtual __int16 virtual_ExecuteAction()
	{
		return *(__int16*)nullptr;
	}

	virtual void virtual_InsertAction(const CAIAction* _0)
	{
	}

	virtual void virtual_ProcessAI()
	{
	}

	virtual void virtual_SetCurrAction(const CAIAction* _0)
	{
	}

	virtual void virtual_SetScript(__int16 _0, CAIScript* _1)
	{
	}

	virtual __int16 virtual_GetVisualRange()
	{
		return *(__int16*)nullptr;
	}

	virtual __int16 virtual_GetAttackRange()
	{
		return *(__int16*)nullptr;
	}

	virtual byte* virtual_GetVisibleTerrainTable()
	{
		return *(byte**)nullptr;
	}

	virtual const unsigned __int8* virtual_GetTerrainTable()
	{
		return *(const unsigned __int8**)nullptr;
	}

	virtual int virtual_QuickDecode(CAITrigger* _0, CGameSprite** _1)
	{
		return *(int*)nullptr;
	}

	virtual __int16 virtual_GetHelpRange()
	{
		return *(__int16*)nullptr;
	}

	virtual void virtual_ApplyTriggers()
	{
	}

	virtual void virtual_AutoPause(unsigned int _0)
	{
	}

	virtual int virtual_GetCanSeeInvisible()
	{
		return *(int*)nullptr;
	}

	virtual void virtual_OnActionRemoval(CAIAction* _0)
	{
	}

	virtual CRect* virtual_GetBounding()
	{
		return *(CRect**)nullptr;
	}
};

struct CGameTrigger : CGameAIBase
{
	struct vtbl : CGameAIBase::vtbl
	{
		int (__fastcall *IsOverActivate)(CGameTrigger*, const CPoint*);

		vtbl() = delete;
	};

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

	CGameTrigger() = delete;

	virtual int virtual_IsOverActivate(const CPoint* _0)
	{
		return *(int*)nullptr;
	}
};

struct CGameTiledObject : CGameAIBase
{
	struct vtbl : CGameAIBase::vtbl
	{
		vtbl() = delete;
	};

	CResRef m_resID;
	unsigned int m_dwFlags;
	CPoint* m_pPrimarySearch;
	unsigned __int16 m_nPrimarySearch;
	CPoint* m_pSecondarySearch;
	unsigned __int16 m_nSecondarySearch;
	CTiledObject m_tiledObject;
	Array<char,32> m_scriptName;

	CGameTiledObject() = delete;
};

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

		GroundItem() = delete;
	};

	struct vtbl : CGameAIBase::vtbl
	{
		void (__fastcall *SetTarget_2)(CGameSprite*, const CPoint*, int);
		void (__fastcall *SetAIType_2)(CGameSprite*, const CAIObjectType*, int, int);
		void (__fastcall *ResetAITypeLive)(CGameSprite*);
		void (__fastcall *ResetAIType)(CGameSprite*);
		void (__fastcall *ProcessPendingTriggers)(CGameSprite*, int);

		vtbl() = delete;
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

	CGameSprite() = delete;

	typedef short (__thiscall *type_GetCasterLevel)(CGameSprite* pThis, CSpell* pSpell, int includeWildMage);
	static type_GetCasterLevel p_GetCasterLevel;

	typedef void (__thiscall *type_CheckQuickLists)(CGameSprite* pThis, CAbilityId* ab, short changeAmount, int remove, int removeSpellIfZero);
	static type_CheckQuickLists p_CheckQuickLists;

	typedef __int32 (__thiscall *type_GetKitMask)(CGameSprite* pThis);
	static type_GetKitMask p_GetKitMask;

	typedef short (__thiscall *type_GetLauncherSlot)(CGameSprite* pThis, short slotNum, short abilityNum);
	static type_GetLauncherSlot p_GetLauncherSlot;

	typedef CGameButtonList* (__thiscall *type_GetQuickButtons)(CGameSprite* pThis, unsigned __int16 buttonType, unsigned __int8 existanceCheck);
	static type_GetQuickButtons p_GetQuickButtons;

	typedef void (__thiscall *type_ReadySpell)(CGameSprite* pThis, CButtonData* button, bool firstCall);
	static type_ReadySpell p_ReadySpell;

	typedef void (__thiscall *type_ReadyOffInternalList)(CGameSprite* pThis, CButtonData* button, bool firstCall);
	static type_ReadyOffInternalList p_ReadyOffInternalList;

	typedef CGameButtonList* (__thiscall *type_GetInternalButtonList)(CGameSprite* pThis);
	static type_GetInternalButtonList p_GetInternalButtonList;

	typedef CDerivedStats* (__thiscall *type_GetActiveStats)(CGameSprite* pThis);
	static type_GetActiveStats p_GetActiveStats;

	typedef void (__thiscall *type_FeedBack)(CGameSprite* pThis, uint feedBackId, int int1, int int2, int int3, int ref1, int int4, CString* stringIn);
	static type_FeedBack p_FeedBack;

	typedef void (__thiscall *type_PlaySound)(CGameSprite* pThis, byte soundID, int showText, int showCircle, int overrideOption);
	static type_PlaySound p_PlaySound;

	typedef void (__thiscall *type_UpdateTarget)(CGameSprite* pThis, CGameObject* target);
	static type_UpdateTarget p_UpdateTarget;

	short GetCasterLevel(CSpell* pSpell, int includeWildMage)
	{
		return p_GetCasterLevel(this, pSpell, includeWildMage);
	}

	void CheckQuickLists(CAbilityId* ab, short changeAmount, int remove, int removeSpellIfZero)
	{
		p_CheckQuickLists(this, ab, changeAmount, remove, removeSpellIfZero);
	}

	__int32 GetKitMask()
	{
		return p_GetKitMask(this);
	}

	short GetLauncherSlot(short slotNum, short abilityNum)
	{
		return p_GetLauncherSlot(this, slotNum, abilityNum);
	}

	CGameButtonList* GetQuickButtons(unsigned __int16 buttonType, unsigned __int8 existanceCheck)
	{
		return p_GetQuickButtons(this, buttonType, existanceCheck);
	}

	void ReadySpell(CButtonData* button, bool firstCall)
	{
		p_ReadySpell(this, button, firstCall);
	}

	void ReadyOffInternalList(CButtonData* button, bool firstCall)
	{
		p_ReadyOffInternalList(this, button, firstCall);
	}

	CGameButtonList* GetInternalButtonList()
	{
		return p_GetInternalButtonList(this);
	}

	CDerivedStats* GetActiveStats()
	{
		return p_GetActiveStats(this);
	}

	void FeedBack(uint feedBackId, int int1, int int2, int int3, int ref1, int int4, CString* stringIn)
	{
		p_FeedBack(this, feedBackId, int1, int2, int3, ref1, int4, stringIn);
	}

	void PlaySound(byte soundID, int showText, int showCircle, int overrideOption)
	{
		p_PlaySound(this, soundID, showText, showCircle, overrideOption);
	}

	void UpdateTarget(CGameObject* target)
	{
		p_UpdateTarget(this, target);
	}

	virtual void virtual_SetTarget_2(const CPoint* _0, int _1)
	{
	}

	virtual void virtual_SetAIType_2(const CAIObjectType* _0, int _1, int _2)
	{
	}

	virtual void virtual_ResetAITypeLive()
	{
	}

	virtual void virtual_ResetAIType()
	{
	}

	virtual void virtual_ProcessPendingTriggers(int _0)
	{
	}
};

struct CGameDoor : CGameAIBase
{
	struct vtbl : CGameAIBase::vtbl
	{
		vtbl() = delete;
	};

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

	CGameDoor() = delete;
};

struct CGameContainer : CGameAIBase
{
	struct vtbl : CGameAIBase::vtbl
	{
		CPoint* (__fastcall *GetPoly)(CGameContainer*);
		__int16 (__fastcall *GetNPoly)(CGameContainer*);

		vtbl() = delete;
	};

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

	CGameContainer() = delete;

	virtual CPoint* virtual_GetPoly()
	{
		return *(CPoint**)nullptr;
	}

	virtual __int16 virtual_GetNPoly()
	{
		return *(__int16*)nullptr;
	}
};

struct CGameAIGame : CGameAIBase
{
	struct vtbl : CGameAIBase::vtbl
	{
		vtbl() = delete;
	};

	CGameAIGame() = delete;
};

struct CGameAIArea : CGameAIBase
{
	struct vtbl : CGameAIBase::vtbl
	{
		vtbl() = delete;
	};

	CGameAIArea() = delete;
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

	CContingency() = delete;
};


extern std::vector<std::pair<const TCHAR*, void**>> internalPointersMap;
