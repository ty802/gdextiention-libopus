#pragma once
#include <stdint.h>
#if !defined(GDE_EXPORT)
#if defined(_WIN32)
#define GDE_EXPORT __declspec(dllexport)
#elif defined(__GNUC__)
#define GDE_EXPORT __attribute__((visibility("default")))
#else
#define GDE_EXPORT
#endif
#endif
#if false
#ifdef BUILD_32
#define STRING_NAME_SIZE 4
#else
#define STRING_NAME_SIZE 8
#endif

// Types.

typedef struct
{
    uint8_t data[STRING_NAME_SIZE];
} StringName;
#endif
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202000L
#define A_Unused [[maybe_unused]]
#elif defined(__GNUC__)
#define A_Unused __attribute__((unused))
#else
#define A_Unused
#endif

