#include "../structsize.h"
#include "defs.h"
#include "interanltypes.h"
#include <cstddef>
#include <cstring>
#include <stddef.h>
HEADER_SUPRESS
#include "godot_cpp/godot.hpp"
#include <godot_cpp/templates/vector.hpp>
#include "godot_cpp/variant/vector2.hpp"
#include <godot_cpp/core/error_macros.hpp>
DIAG_pop
#include "c.hpp"
using namespace godot;
extern "C" {
void throw_str(char* error){
        CRASH_NOW_MSG(error);
}
size_t vec_sizeof_Vector2() { return sizeof(Vector<Vec2>); }

size_t vec_sizeof_byte() { return sizeof(Vector<char>); }

void vec_construct_Vector2(void *buffer) { new (buffer) Vector<Vec2>(); }

void vec_construct_byte(void *buffer) { new (buffer) Vector<char>(); }

GDPackedByteArray vec_construct_byte_from_data(const char *data,
                                               size_t length) {
  GDPackedByteArray res;
  Vector<char> *vec = new (&res) Vector<char>();
  vec->resize(length);
  memcpy(vec->ptrw(), data, length);
  return res;
}
GDPackedVector2Array vec_construct_byte_from_vector2(const Vector2 *data,
                                               size_t length) {
  GDPackedVector2Array res;
  Vector<Vector2> *vec = new (&res) Vector<Vector2>();
  vec->resize(length);
  memcpy(vec->ptrw(), data, length);
  return res;
}
const Vec2 *vec_data_Vector2(void *vec) {
  return static_cast<Vector<Vec2> *>(vec)->ptr();
}

size_t vec_len_Vector2(void *vec) {
  return static_cast<Vector<Vec2> *>(vec)->size();
}

const char *vec_data_byte(void *vec) {
  return static_cast<Vector<char> *>(vec)->ptr();
}

size_t vec_len_byte(void *vec) {
  return static_cast<Vector<char> *>(vec)->size();
}

void vec_push_Vector2(void *vec, Vec2 value) {
  static_cast<Vector<Vec2> *>(vec)->push_back(value);
}
void init(ModuleInitializationLevel lvl){
        GdOpus_initialize(NULL,(GDExtensionInitializationLevel)lvl);
}
void dinit(ModuleInitializationLevel lvl){
        if(lvl == ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_CORE){
                GdOpus_deinitialize(NULL,(GDExtensionInitializationLevel)lvl);
        }
}
GDExtensionBool GDE_EXPORT cpp_init(GDExtensionInterfaceGetProcAddress p_get_proc_address,
          GDExtensionClassLibraryPtr p_library,
          GDExtensionInitialization *r_initialization) {
    godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
    load_api(p_get_proc_address);
    class_library = p_library;
    init_obj.register_initializer(&init);
    init_obj.register_terminator(&dinit);
    init_obj.set_minimum_library_initialization_level(godot::MODULE_INITIALIZATION_LEVEL_CORE);
    init_obj.init();
    return true;
}
}
