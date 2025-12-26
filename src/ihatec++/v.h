#pragma once
#include "gdextension_interface.h"
#include "godot.h"
#include "interanltypes.h"
#include "structsize.h"
#include <stddef.h>
size_t vec_sizeof_Vector2();
size_t vec_sizeof_byte();

void vec_construct_Vector2(void *buffer);
void vec_construct_byte(void *buffer);
GDPackedByteArray vec_construct_byte_from_data(const char *data, size_t length);
void vec_destruct_Vector2(void *buffer);

void vec_destruct_byte(void *buffer);

struct Vec2 *vec_data_Vector2(void *vec);

size_t vec_len_Vector2(void *vec);

void vec_push_Vector2(void *vec, struct Vec2 value);
GDExtensionBool cpp_init(GDExtensionInterfaceGetProcAddress p_get_proc_address,
                         GDExtensionClassLibraryPtr p_library,
                         GDExtensionInitialization *r_initialization);
const char *vec_data_byte(void *vec);
size_t vec_len_byte(void *vec);
