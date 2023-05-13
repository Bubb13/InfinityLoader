
#pragma once

typedef void (__cdecl* type_free)(void* memblock);
extern type_free p_free;

typedef void* (__cdecl* type_malloc)(size_t size);
extern type_malloc p_malloc;
