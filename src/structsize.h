#pragma once
#include <stdint.h>
#ifdef BUILD_32
#if USE_DOUBLE_PRECISION
#include "structsize/llouble_32"
#else
#include "structsize/float_32"
#endif
#else
#if USE_DOUBLE_PRECISION
#include "structsize/double_64"
#else
#include "structsize/float_64"
#endif
#endif // BUILD_32
