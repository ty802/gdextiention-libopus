#pragma once
#include "structsize.h"
#include <gdextension_interface.h>
extern GDExtensionClassLibraryPtr class_library;
typedef void (*GDCassDBBindEnum)(const GDStringName *p_class,
                                 const GDStringName *p_enumname,
                                 const GDStringName *p_enumvaluename,
                                 int64_t value, GDExtensionBool p_isBitfield);

struct Constructors {
  GDExtensionInterfaceStringNameNewWithUtf8Chars string_name_from_utf8;
  GDExtensionInterfaceStringNameNewWithUtf8CharsAndLen
      string_name_from_utf8_and_Len;
  GDExtensionInterfaceStringNameNewWithLatin1Chars new_stringname;
  GDExtensionInterfaceStringNewWithLatin1Chars new_string;
  GDExtensionTypeFromVariantConstructorFunc
      packed_vector2_array_from_variant_constructor;
  GDExtensionVariantFromTypeConstructorFunc
      variant_from_packed_vector2_array_constructor;
  GDExtensionVariantFromTypeConstructorFunc
      variant_from_packed_byte_array_constructor;
  GDExtensionTypeFromVariantConstructorFunc
      packed_byte_array_from_variant_constructor;
  GDExtensionVariantFromTypeConstructorFunc box_object;
  GDExtensionTypeFromVariantConstructorFunc unbox_object;
  GDExtensionVariantFromTypeConstructorFunc box_bool;
  GDExtensionVariantFromTypeConstructorFunc box_int;
};

struct Destructors {
  GDExtensionPtrDestructor string_name_destructor;
  GDExtensionPtrDestructor string_destructor;
};

struct API {
  GDExtensionInterfaceClassdbRegisterExtensionClass5
      classdb_register_extension_class;
  GDExtensionInterfaceClassdbUnregisterExtensionClass
      classdb_unregister_extension_class;
  GDExtensionInterfaceMemAlloc malloc;
  GDExtensionInterfaceMemFree free;
  GDExtensionInterfaceObjectSetInstance object_set_instance;
  GDExtensionInterfaceObjectSetInstanceBinding object_set_instance_binding;
  GDExtensionInterfaceClassdbConstructObject2 new;
  GDExtensionInterfaceClassdbRegisterExtensionClassIntegerConstant bind_enum;
  GDExtensionInterfaceGetVariantFromTypeConstructor
      get_variant_from_type_constructor;
  GDExtensionInterfaceGetVariantToTypeConstructor
      get_variant_to_type_constructor;
  GDExtensionInterfaceVariantGetType variant_get_type;
  GDExtensionInterfaceClassdbRegisterExtensionClassMethod
      classdb_register_extension_class_method;
  GDStringName *nameofobject;
};

GDExtensionPropertyInfo make_property(GDExtensionVariantType type,
                                      const char *name);

GDExtensionPropertyInfo make_property_full(GDExtensionVariantType type,
                                           const char *name, uint32_t hint,
                                           const char *hint_string,
                                           const char *class_name,
                                           uint32_t usage_flags);
enum PropertyHint {
  PROPERTY_HINT_NONE = 0,
};

enum PropertyUsageFlags {
  PROPERTY_USAGE_NONE = 0,
  PROPERTY_USAGE_STORAGE = 2,
  PROPERTY_USAGE_EDITOR = 4,
  PROPERTY_USAGE_DEFAULT = PROPERTY_USAGE_STORAGE | PROPERTY_USAGE_EDITOR,
};
void destruct_property(GDExtensionPropertyInfo *info);
extern struct Destructors destructors;
extern struct Constructors constructors;
extern struct API api;
void load_api(GDExtensionInterfaceGetProcAddress p_get_proc_address);
void bind_method_with_return(
    void *founction, GDExtensionStringNamePtr classname, const char *methodname,
    int argcount, const char **arg_names, GDExtensionVariantType *arg_types,
    GDExtensionVariantType returntype, void *call, void *ptr_call);
void call_1_PackedVector2Array_arg_ret_PackedByteArray(
    void *method_userdata, GDExtensionClassInstancePtr p_instance,
    const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count,
    GDExtensionVariantPtr r_return, GDExtensionCallError *p_error);
void call_1_PackedByteArray_arg_ret_PackedVector2Array(
    void *method_userdata, GDExtensionClassInstancePtr p_instance,
    const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count,
    GDExtensionVariantPtr r_return, GDExtensionCallError *p_error);
void call_0_ret_Object(void *method_userdata,
                       GDExtensionClassInstancePtr p_instance,
                       const GDExtensionConstVariantPtr *p_args,
                       GDExtensionInt p_argument_count,
                       GDExtensionVariantPtr r_return,
                       GDExtensionCallError *p_error);
void call_0_ret_bool(void *method_userdata,
                     GDExtensionClassInstancePtr p_instance,
                     const GDExtensionConstVariantPtr *p_args,
                     GDExtensionInt p_argument_count,
                     GDExtensionVariantPtr r_return,
                     GDExtensionCallError *p_error);
void call_0_ret_int(void *method_userdata,
                    GDExtensionClassInstancePtr p_instance,
                    const GDExtensionConstVariantPtr *p_args,
                    GDExtensionInt p_argument_count,
                    GDExtensionVariantPtr r_return,
                    GDExtensionCallError *p_error);
GDExtensionClassCreationInfo5 class_create_info(void);
extern const GDExtensionInstanceBindingCallbacks instance_null_callbacks;
