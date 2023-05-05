
#pragma once

#include <setjmp.h>
#include "lua/lua.h"

union Closure;
union GCObject;
struct LocVar;
struct Node;
struct Proto;
union TString;
struct UpVal;
struct lua_State;
struct lua_TValue;

struct Mbuffer
{
	char* buffer;
	unsigned __int64 n;
	unsigned __int64 buffsize;
};

struct Upvaldesc
{
	TString* name;
	unsigned __int8 instack;
	unsigned __int8 idx;
};

struct LClosure
{
	GCObject* next;
	unsigned __int8 tt;
	unsigned __int8 marked;
	unsigned __int8 nupvalues;
	GCObject* gclist;
	Proto* p;
	UpVal* upvals[1];
};

struct GCheader
{
	GCObject* next;
	unsigned __int8 tt;
	unsigned __int8 marked;
};

union Value
{
	GCObject* gc;
	void* p;
	int b;
	int (__fastcall *f)(lua_State*);
	long double n;
};

struct Table
{
	GCObject* next;
	unsigned __int8 tt;
	unsigned __int8 marked;
	unsigned __int8 flags;
	unsigned __int8 lsizenode;
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
	unsigned __int8 tt;
	unsigned __int8 marked;
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
	unsigned __int8 numparams;
	unsigned __int8 is_vararg;
	unsigned __int8 maxstacksize;
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

union Udata
{
	struct uv_t
	{
		GCObject* next;
		unsigned __int8 tt;
		unsigned __int8 marked;
		Table* metatable;
		Table* env;
		unsigned __int64 len;
	};

	L_Umaxalign dummy;
	Udata::uv_t uv;
};

union TString
{
	struct tsv_t
	{
		GCObject* next;
		unsigned __int8 tt;
		unsigned __int8 marked;
		unsigned __int8 extra;
		unsigned int hash;
		unsigned __int64 len;
	};

	L_Umaxalign dummy;
	TString::tsv_t tsv;
};

struct CallInfo
{
	union u_t
	{
		struct c_t
		{
			int ctx;
			int (__fastcall *k)(lua_State*);
			__int64 old_errfunc;
			unsigned __int8 old_allowhook;
			unsigned __int8 status;
		};

		struct l_t
		{
			lua_TValue* base;
			const unsigned int* savedpc;
		};

		CallInfo::u_t::l_t l;
		CallInfo::u_t::c_t c;
	};

	lua_TValue* func;
	lua_TValue* top;
	CallInfo* previous;
	CallInfo* next;
	__int16 nresults;
	unsigned __int8 callstatus;
	__int64 extra;
	CallInfo::u_t u;
};

struct lua_TValue
{
	Value value_;
	int tt_;
};

struct UpVal
{
	union u_t
	{
		struct l_t
		{
			UpVal* prev;
			UpVal* next;
		};

		lua_TValue value;
		UpVal::u_t::l_t l;
	};

	GCObject* next;
	unsigned __int8 tt;
	unsigned __int8 marked;
	lua_TValue* v;
	UpVal::u_t u;
};

union TKey
{
	struct nk_t
	{
		Value value_;
		int tt_;
		Node* next;
	};

	TKey::nk_t nk;
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
	unsigned __int8 tt;
	unsigned __int8 marked;
	unsigned __int8 nupvalues;
	GCObject* gclist;
	int (__fastcall *f)(lua_State*);
	lua_TValue upvalue[1];
};

union Closure
{
	CClosure c;
	LClosure l;
};

struct lua_longjmp
{
	lua_longjmp* previous;
	_SETJMP_FLOAT128 b[16];
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
	void* (__fastcall *frealloc)(void*, void*, unsigned __int64, unsigned __int64);
	void* ud;
	unsigned __int64 totalbytes;
	__int64 GCdebt;
	unsigned __int64 GCmemtrav;
	unsigned __int64 GCestimate;
	stringtable strt;
	lua_TValue l_registry;
	unsigned int seed;
	unsigned __int8 currentwhite;
	unsigned __int8 gcstate;
	unsigned __int8 gckind;
	unsigned __int8 gcrunning;
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
	int (__fastcall *panic)(lua_State*);
	lua_State* mainthread;
	const long double* version;
	TString* memerrmsg;
	TString* tmname[17];
	Table* mt[9];
};

struct lua_State
{
	GCObject* next;
	unsigned __int8 tt;
	unsigned __int8 marked;
	unsigned __int8 status;
	lua_TValue* top;
	global_State* l_G;
	CallInfo* ci;
	const unsigned int* oldpc;
	lua_TValue* stack_last;
	lua_TValue* stack;
	int stacksize;
	unsigned __int16 nny;
	unsigned __int16 nCcalls;
	unsigned __int8 hookmask;
	unsigned __int8 allowhook;
	int basehookcount;
	int hookcount;
	void (__fastcall *hook)(lua_State*, lua_Debug*);
	GCObject* openupval;
	GCObject* gclist;
	lua_longjmp* errorJmp;
	__int64 errfunc;
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
