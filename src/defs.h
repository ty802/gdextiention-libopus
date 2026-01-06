#pragma once
#include <stdint.h>
#if !defined(GDE_EXPORT)
#if defined(_WIN32)
#define GDE_EXPORT __declspec(dllexport)
#define HEADER_SUPRESS
#define DIAG_pop
#elif defined(__GNUC__)
#define GDE_EXPORT __attribute__((visibility("default")))
#define HEADER_SUPRESS _Pragma("GCC diagnostic push")\
_Pragma("GCC diagnostic ignored \"-Wunused-parameter\"")\

#define DIAG_pop _Pragma("GCC diagnostic pop")
#elif defined __clang__
#define GDE_EXPORT
#define HEADER_SUPRESS _Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Wunused-parameter\"")\


#define DIAG_pop _Pragma("clang diagnostic pop")
#else
#define GDE_EXPORT
#define HEADER_SUPRESS
#define DIAG_pop
#endif
#endif
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202000L
#define A_Unused [[maybe_unused]]
#elif defined(__GNUC__)
#define A_Unused __attribute__((unused))
#else
#define A_Unused
#endif

