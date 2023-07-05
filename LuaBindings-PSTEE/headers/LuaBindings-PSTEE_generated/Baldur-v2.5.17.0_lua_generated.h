
#pragma once

union Closure;
union GCObject;
struct LocVar;
struct Node;
struct Proto;
union TString;
struct UpVal;
struct lua_State;
struct lua_TValue;

struct _0F841590A95885B59AFC1DD491AEF5B1
{
	lua_TValue* base;
	const unsigned int* savedpc;
};

struct _2E6324AB507C8ECCB4D4155EA554B7C5
{
	UpVal* prev;
	UpVal* next;
};


struct Upvaldesc
{
	TString* name;
	char instack;
	char idx;
};

struct LClosure
{
	GCObject* next;
	char tt;
	char marked;
	char nupvalues;
	GCObject* gclist;
	Proto* p;
	UpVal* upvals[1];
};

struct GCheader
{
	GCObject* next;
	char tt;
	char marked;
};

union Value
{
	GCObject* gc;
	void* p;
	int b;
	int (__cdecl *f)(lua_State*);
};

struct Table
{
	GCObject* next;
	char tt;
	char marked;
	char flags;
	char lsizenode;
	int sizearray;
	lua_TValue* array;
	Node* node;
	Node* lastfree;
	Table* metatable;
	GCObject* gclist;
};

struct Proto
{
	GCObject* next;
	char tt;
	char marked;
	lua_TValue* k;
	unsigned int* code;
	Proto** p;
	int* lineinfo;
	LocVar* locvars;
	Upvaldesc* upvalues;
	Closure* cache;
	TString* source;
	int sizeupvalues;
	int sizek;
	int sizecode;
	int sizelineinfo;
	int sizep;
	int sizelocvars;
	int linedefined;
	int lastlinedefined;
	GCObject* gclist;
	char numparams;
	char is_vararg;
	char maxstacksize;
};

struct Mbuffer
{
	char* buffer;
	unsigned int n;
	unsigned int buffsize;
};

struct LocVar
{
	TString* varname;
	int startpc;
	int endpc;
};

union L_Umaxalign
{
	long double u;
	void* s;
	int l;
};

struct _87CF6D6E8EE0ECAF3C457EB8DAFDA081
{
	GCObject* next;
	char tt;
	char marked;
	Table* metatable;
	Table* env;
	unsigned int len;
};

union Udata
{
	L_Umaxalign dummy;
	_87CF6D6E8EE0ECAF3C457EB8DAFDA081 uv;
};

struct _83225D3B935359A92257E1D58FB5D33E
{
	int ctx;
	int (__cdecl *k)(lua_State*);
	int old_errfunc;
	char old_allowhook;
	char status;
};

union _F19E5F4B8243304B2A9C12D28838366E
{
	_0F841590A95885B59AFC1DD491AEF5B1 l;
	_83225D3B935359A92257E1D58FB5D33E c;
};

struct CallInfo
{
	lua_TValue* func;
	lua_TValue* top;
	CallInfo* previous;
	CallInfo* next;
	__int16 nresults;
	char callstatus;
	int extra;
	_F19E5F4B8243304B2A9C12D28838366E u;
};

struct _2FD4FBC65D0C512FC47E6C723A86F8DA
{
	GCObject* next;
	char tt;
	char marked;
	char extra;
	unsigned int hash;
	unsigned int len;
};

union TString
{
	L_Umaxalign dummy;
	_2FD4FBC65D0C512FC47E6C723A86F8DA tsv;
};

struct _214230D657A5CF53A733675F9E20072B
{
	Value v__;
	int tt__;
};

union _CB571E694056FA675660E83E845BA3E5
{
	_214230D657A5CF53A733675F9E20072B i;
	long double d__;
};

struct _E5A33DB2916B5DB2588AEA3BDEEB641C
{
	_CB571E694056FA675660E83E845BA3E5 u;
	Node* next;
};

struct lua_Debug
{
	int event;
	const char* name;
	const char* namewhat;
	const char* what;
	const char* source;
	int currentline;
	int linedefined;
	int lastlinedefined;
	char nups;
	char nparams;
	char isvararg;
	char istailcall;
	char short_src[60];
	CallInfo* i_ci;
};

struct lua_TValue
{
	_CB571E694056FA675660E83E845BA3E5 u;
};

union TKey
{
	_E5A33DB2916B5DB2588AEA3BDEEB641C nk;
	lua_TValue tvk;
};

struct Node
{
	lua_TValue i_val;
	TKey i_key;
};

struct CClosure
{
	GCObject* next;
	char tt;
	char marked;
	char nupvalues;
	GCObject* gclist;
	int (__cdecl *f)(lua_State*);
	lua_TValue upvalue[1];
};

union Closure
{
	CClosure c;
	LClosure l;
};

union _CD82AF980D583A2B5CA351BFEED8487A
{
	lua_TValue value;
	_2E6324AB507C8ECCB4D4155EA554B7C5 l;
};

struct UpVal
{
	GCObject* next;
	char tt;
	char marked;
	lua_TValue* v;
	_CD82AF980D583A2B5CA351BFEED8487A u;
};

struct lua_longjmp
{
	lua_longjmp* previous;
	int b[16];
	volatile int status;
};

struct stringtable
{
	GCObject** hash;
	unsigned int nuse;
	int size;
};

struct global_State
{
	void* (__cdecl *frealloc)(void*, void*, unsigned int, unsigned int);
	void* ud;
	unsigned int totalbytes;
	int GCdebt;
	unsigned int GCmemtrav;
	unsigned int GCestimate;
	stringtable strt;
	lua_TValue l_registry;
	unsigned int seed;
	char currentwhite;
	char gcstate;
	char gckind;
	char gcrunning;
	int sweepstrgc;
	GCObject* allgc;
	GCObject* finobj;
	GCObject** sweepgc;
	GCObject** sweepfin;
	GCObject* gray;
	GCObject* grayagain;
	GCObject* weak;
	GCObject* ephemeron;
	GCObject* allweak;
	GCObject* tobefnz;
	UpVal uvhead;
	Mbuffer buff;
	int gcpause;
	int gcmajorinc;
	int gcstepmul;
	int (__cdecl *panic)(lua_State*);
	lua_State* mainthread;
	const long double* version;
	TString* memerrmsg;
	TString* tmname[17];
	Table* mt[9];
};

struct lua_State
{
	GCObject* next;
	char tt;
	char marked;
	char status;
	lua_TValue* top;
	global_State* l_G;
	CallInfo* ci;
	const unsigned int* oldpc;
	lua_TValue* stack_last;
	lua_TValue* stack;
	int stacksize;
	unsigned __int16 nny;
	unsigned __int16 nCcalls;
	char hookmask;
	char allowhook;
	int basehookcount;
	int hookcount;
	void (__cdecl *hook)(lua_State*, lua_Debug*);
	GCObject* openupval;
	GCObject* gclist;
	lua_longjmp* errorJmp;
	int errfunc;
	CallInfo base_ci;
};

union GCObject
{
	GCheader gch;
	TString ts;
	Udata u;
	Closure cl;
	Table h;
	Proto p;
	UpVal uv;
	lua_State th;
};

