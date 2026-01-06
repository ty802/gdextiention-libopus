#include "api.h"
#include "defs.h"
#include "gdextension_interface.h"
#include "structsize.h"
#include <stdlib.h>
GDExtensionClassLibraryPtr class_library = NULL;
const GDExtensionInstanceBindingCallbacks instance_null_callbacks = {
    .create_callback = NULL, .free_callback = NULL, .reference_callback = NULL};

void load_api(GDExtensionInterfaceGetProcAddress p_get_proc_address) {
  // Get helper functions first.
  GDExtensionInterfaceVariantGetPtrDestructor variant_get_ptr_destructor =
      (GDExtensionInterfaceVariantGetPtrDestructor)p_get_proc_address(
          "variant_get_ptr_destructor");

  // API.
  api.classdb_register_extension_class =
      (GDExtensionInterfaceClassdbRegisterExtensionClass5)p_get_proc_address(
          "classdb_register_extension_class5");
  api.classdb_unregister_extension_class =
      (GDExtensionInterfaceClassdbUnregisterExtensionClass)p_get_proc_address(
          "classdb_unregister_extension_class");
  api.free = (GDExtensionInterfaceMemFree)p_get_proc_address("mem_free");
  api.malloc = (GDExtensionInterfaceMemAlloc)p_get_proc_address("mem_alloc");
  api.object_set_instance =
      (GDExtensionInterfaceObjectSetInstance)p_get_proc_address(
          "object_set_instance");
  api.object_set_instance_binding =
      (GDExtensionInterfaceObjectSetInstanceBinding)p_get_proc_address(
          "object_set_instance_binding");
  api.new = (GDExtensionInterfaceClassdbConstructObject2)p_get_proc_address(
      "classdb_construct_object2");
  api.bind_enum =
      (GDExtensionInterfaceClassdbRegisterExtensionClassIntegerConstant)
          p_get_proc_address(
              "classdb_register_extension_class_integer_constant");
  api.get_variant_from_type_constructor =
      (GDExtensionInterfaceGetVariantFromTypeConstructor)p_get_proc_address(
          "get_variant_from_type_constructor");
  api.get_variant_to_type_constructor =
      (GDExtensionInterfaceGetVariantToTypeConstructor)p_get_proc_address(
          "get_variant_to_type_constructor");
  api.variant_get_type = (GDExtensionInterfaceVariantGetType)p_get_proc_address(
      "variant_get_type");
  api.classdb_register_extension_class_method =
      (GDExtensionInterfaceClassdbRegisterExtensionClassMethod)
          p_get_proc_address("classdb_register_extension_class_method");

  // Constructors.
  constructors.string_name_from_utf8 =
      (GDExtensionInterfaceStringNameNewWithUtf8Chars)p_get_proc_address(
          "string_name_new_with_utf8_chars");
  constructors.string_name_from_utf8_and_Len =
      (GDExtensionInterfaceStringNameNewWithUtf8CharsAndLen)p_get_proc_address(
          "string_name_new_with_utf8_chars_and_len");
  constructors.new_stringname =
      (GDExtensionInterfaceStringNameNewWithLatin1Chars)p_get_proc_address(
          "string_name_new_with_latin1_chars");
  constructors.new_string =
      (GDExtensionInterfaceStringNewWithLatin1Chars)p_get_proc_address(
          "string_new_with_latin1_chars");
  constructors.packed_vector2_array_from_variant_constructor =
      api.get_variant_to_type_constructor(
          GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY);
  constructors.variant_from_packed_vector2_array_constructor =
      api.get_variant_from_type_constructor(
          GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY);
  constructors.packed_byte_array_from_variant_constructor =
      api.get_variant_to_type_constructor(
          GDEXTENSION_VARIANT_TYPE_PACKED_BYTE_ARRAY);
  constructors.variant_from_packed_byte_array_constructor =
      api.get_variant_from_type_constructor(
          GDEXTENSION_VARIANT_TYPE_PACKED_BYTE_ARRAY);
  constructors.box_object =
      api.get_variant_from_type_constructor(GDEXTENSION_VARIANT_TYPE_OBJECT);
  constructors.unbox_object =
      api.get_variant_to_type_constructor(GDEXTENSION_VARIANT_TYPE_OBJECT);
  constructors.box_bool =
      api.get_variant_from_type_constructor(GDEXTENSION_VARIANT_TYPE_BOOL);
  constructors.box_int =
      api.get_variant_from_type_constructor(GDEXTENSION_VARIANT_TYPE_INT);
  // Destructors.
  destructors.string_name_destructor =
      variant_get_ptr_destructor(GDEXTENSION_VARIANT_TYPE_STRING_NAME);
  destructors.string_destructor =
      variant_get_ptr_destructor(GDEXTENSION_VARIANT_TYPE_STRING);

  // late api stuff
  api.nameofobject = api.malloc(sizeof(GDStringName));
  constructors.new_stringname(api.nameofobject, "Object", 1);
}

void call_1_PackedVector2Array_arg_ret_PackedByteArray(
    void *method_userdata, GDExtensionClassInstancePtr p_instance,
    const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count,
    GDExtensionVariantPtr r_return, GDExtensionCallError *p_error) {
  if (p_argument_count != 1) {
    if (p_argument_count > 1)
      p_error->error = GDEXTENSION_CALL_ERROR_TOO_MANY_ARGUMENTS;
    else
      p_error->error = GDEXTENSION_CALL_ERROR_TOO_FEW_ARGUMENTS;
    p_error->expected = 1;
    return;
  }
  GDExtensionVariantType type = api.variant_get_type(p_args[0]);
  if (type != GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY) {
    p_error->error = GDEXTENSION_CALL_ERROR_INVALID_ARGUMENT;
    p_error->expected = GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY;
    p_error->argument = 0;
  }
  GDPackedVector2Array arg1;
  constructors.packed_vector2_array_from_variant_constructor(
      &arg1, (GDExtensionVariantPtr)p_args[0]);
  GDPackedByteArray (*function)(void *, void *) = method_userdata;
  GDPackedByteArray res = function(p_instance, &arg1);
  constructors.variant_from_packed_byte_array_constructor(r_return, &res);
  return;
}

void call_1_PackedByteArray_arg_ret_PackedVector2Array(
    void *method_userdata, GDExtensionClassInstancePtr p_instance,
    const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count,
    GDExtensionVariantPtr r_return, GDExtensionCallError *p_error) {
  if (p_argument_count != 1) {
    if (p_argument_count > 1)
      p_error->error = GDEXTENSION_CALL_ERROR_TOO_MANY_ARGUMENTS;
    else
      p_error->error = GDEXTENSION_CALL_ERROR_TOO_FEW_ARGUMENTS;
    p_error->expected = 1;
    return;
  }
  GDExtensionVariantType type = api.variant_get_type(p_args[0]);
  if (type != GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY) {
    p_error->error = GDEXTENSION_CALL_ERROR_INVALID_ARGUMENT;
    p_error->expected = GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY;
    p_error->argument = 0;
  }
  GDPackedByteArray arg1;
  constructors.packed_byte_array_from_variant_constructor(
      &arg1, (GDExtensionVariantPtr)p_args[0]);
  GDPackedVector2Array (*function)(void *, void *) = method_userdata;
  GDPackedVector2Array res = function(p_instance, &arg1);
  constructors.variant_from_packed_vector2_array_constructor(r_return, &res);
  return;
}

void call_static_0_ret_Object(void *method_userdata,
                              A_Unused GDExtensionClassInstancePtr p_instance,
                              A_Unused const GDExtensionConstVariantPtr *p_args,
                              A_Unused GDExtensionInt p_argument_count,
                              GDExtensionVariantPtr r_return,
                              A_Unused GDExtensionCallError *p_error) {
  GDExtensionObjectPtr (*function)(void) = method_userdata;
  GDExtensionObjectPtr ptr = function();
  constructors.box_object(r_return, ptr);
  return;
}

void call_static_1_object_ret_Object(
    void *method_userdata, A_Unused GDExtensionClassInstancePtr p_instance,
    const GDExtensionConstVariantPtr *p_args,
    A_Unused GDExtensionInt p_argument_count, GDExtensionVariantPtr r_return,
    GDExtensionCallError *p_error) {
  GDExtensionVariantType type = api.variant_get_type(p_args[0]);
  if (type != GDEXTENSION_VARIANT_TYPE_OBJECT) {
    p_error->error = GDEXTENSION_CALL_ERROR_INVALID_ARGUMENT;
    p_error->expected = GDEXTENSION_VARIANT_TYPE_OBJECT;
    p_error->argument = 0;
    return;
  }
  GDExtensionObjectPtr obj = NULL;
  constructors.unbox_object(obj, (void *)p_args[0]);
  GDExtensionObjectPtr (*function)(GDExtensionObjectPtr) = method_userdata;
  GDExtensionObjectPtr ptr = function(obj);
  constructors.box_object(r_return, ptr);
  return;
}

void call_0_ret_Object(void *method_userdata,
                              GDExtensionClassInstancePtr p_instance,
                              A_Unused const GDExtensionConstVariantPtr *p_args,
                              A_Unused GDExtensionInt p_argument_count,
                              GDExtensionVariantPtr r_return,
                              A_Unused GDExtensionCallError *p_error) {
  GDExtensionObjectPtr (*function)(const GDExtensionClassInstancePtr) = method_userdata;
  GDExtensionObjectPtr ptr = function(p_instance);
  constructors.box_object(r_return, ptr);
  return;
}

void call_0_ret_bool(void *method_userdata,
                     GDExtensionClassInstancePtr p_instance,
                     A_Unused const GDExtensionConstVariantPtr *p_args,
                     A_Unused GDExtensionInt p_argument_count,
                     GDExtensionVariantPtr r_return,
                     A_Unused GDExtensionCallError *p_error) {
  GDExtensionBool (*function)(const GDExtensionClassInstancePtr) =
      method_userdata;
  GDExtensionBool res = function(p_instance);
  constructors.box_bool(r_return, &res);
  return;
}

void call_0_ret_int(void *method_userdata,
                    GDExtensionClassInstancePtr p_instance,
                    A_Unused const GDExtensionConstVariantPtr *p_args,
                    A_Unused GDExtensionInt p_argument_count,
                    GDExtensionVariantPtr r_return,
                    A_Unused GDExtensionCallError *p_error) {
  int (*function)(const GDExtensionClassInstancePtr) = method_userdata;
  int res = function(p_instance);
  constructors.box_int(r_return, &res);
  return;
}

GDExtensionPropertyInfo make_property(GDExtensionVariantType type,
                                      const char *name) {

  return make_property_full(type, name, PROPERTY_HINT_NONE, "", "",
                            PROPERTY_USAGE_DEFAULT);
}

GDExtensionPropertyInfo make_property_full(GDExtensionVariantType type,
                                           const char *name, uint32_t hint,
                                           const char *hint_string,
                                           const char *class_name,
                                           uint32_t usage_flags) {

  GDStringName *prop_name = api.malloc(sizeof(GDStringName));
  constructors.new_stringname(prop_name, name, 0);
  GDString *prop_hint_string = api.malloc(sizeof(GDString));
  constructors.new_string(prop_hint_string, hint_string);
  GDStringName *prop_class_name = api.malloc(sizeof(GDStringName));
  constructors.new_stringname(prop_class_name, class_name, 0);

  GDExtensionPropertyInfo info = {
      .name = prop_name,
      .type = type,
      .hint = hint,
      .hint_string = prop_hint_string,
      .class_name = prop_class_name,
      .usage = usage_flags,
  };

  return info;
}

void destruct_property(GDExtensionPropertyInfo *info) {
  destructors.string_name_destructor(info->name);
  destructors.string_destructor(info->hint_string);
  destructors.string_name_destructor(info->class_name);
  api.free(info->name);
  api.free(info->hint_string);
  api.free(info->class_name);
}

void bind_method_with_return(void *function, GDExtensionStringNamePtr classname,
                             const char *methodname, int argcount,
                             const char **arg_names,
                             GDExtensionVariantType *arg_types,
                             GDExtensionVariantType returntype, void *call,
                             void *ptr_call) {
  GDExtensionPropertyInfo returninfo = make_property(returntype, "");
  GDExtensionPropertyInfo *args_info =
      api.malloc(argcount * sizeof(GDExtensionPropertyInfo));
  GDExtensionClassMethodArgumentMetadata *metas =
      api.malloc(argcount * sizeof(GDExtensionClassMethodArgumentMetadata));
  for (int i = 0; i < argcount; i++) {
    args_info[i] = make_property(arg_types[i], arg_names[i]);
    metas[i] = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE;
  }
  GDStringName methodname_stringname;
  constructors.new_stringname(&methodname_stringname, methodname, 0);
  GDExtensionClassMethodInfo info = {
      .name = &methodname_stringname,
      .method_userdata = function,
      .call_func = call,
      .ptrcall_func = ptr_call,
      .method_flags = GDEXTENSION_METHOD_FLAGS_DEFAULT,
      .has_return_value = 1,
      .argument_count = argcount,
      .arguments_info = args_info,
      .arguments_metadata = metas,
      .return_value_info = &returninfo,
      .return_value_metadata = GDEXTENSION_METHOD_ARGUMENT_METADATA_NONE,
  };
  api.classdb_register_extension_class_method(class_library, classname, &info);
  for (int i = 0; i < argcount; i++) {
    destruct_property(args_info + (i * sizeof(GDExtensionPropertyInfo)));
    api.free(args_info);
    api.free(metas);
  }
  destructors.string_name_destructor(&methodname_stringname);
  destruct_property(&returninfo);
}

GDExtensionClassCreationInfo5 class_create_info(void) {
  return (GDExtensionClassCreationInfo5){
      .is_virtual = 0,
      .is_abstract = 0,
      .is_exposed = 1,
      .is_runtime = 0,
      .icon_path = NULL,
      .set_func = NULL,
      .get_func = NULL,
      .get_property_list_func = NULL,
      .free_property_list_func = NULL,
      .property_can_revert_func = NULL,
      .property_get_revert_func = NULL,
      .validate_property_func = NULL,
      .notification_func = NULL,
      .to_string_func = NULL,
      .reference_func = NULL,
      .create_instance_func = NULL,
      .free_instance_func = NULL,
      .unreference_func = NULL,
      .recreate_instance_func = NULL,
      .get_virtual_func = NULL,
      .get_virtual_call_data_func = NULL,
      .call_virtual_with_data_func = NULL,
  };
}
