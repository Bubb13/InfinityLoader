
#pragma once

#define IMPORT __declspec(dllimport)
#define EXTERN_IMPORT extern __declspec(dllimport)
#define EXTERN_C_IMPORT extern "C" __declspec(dllimport)
#define EXPORT __declspec(dllexport)
#define EXTERN_EXPORT extern __declspec(dllexport)
#define EXTERN_C_EXPORT extern "C" __declspec(dllexport)

#ifdef _WIN64
#define EXTERN_C_SYMBOL(sym) #sym
#else
#define EXTERN_C_SYMBOL(sym) "_"#sym
#endif
