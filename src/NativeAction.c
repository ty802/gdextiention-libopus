#include "NativeAction.h"
#include "api.h"
#include "defs.h"
#include "gdextension_interface.h"
#include "structsize.h"
#include <stdio.h>
GDStringName this_class_name() {
  GDStringName name;
  constructors.new_stringname(&name, "native_action", 0);
  return name;
}
GDExtensionObjectPtr
allocate_remote(A_Unused void *p_class_userdata,
                A_Unused GDExtensionBool p_notify_postinitialize) {
  GDExtensionObjectPtr obj = api.new(api.nameofobject);
  struct NativeAction *ac = api.malloc(sizeof(struct NativeAction));
  ac->base = obj;
  GDStringName name = this_class_name();
  api.object_set_instance(obj, &name, ac);
  api.object_set_instance_binding(obj, class_library, ac, &instance_null_callbacks);
  destructors.string_name_destructor(&name);
  return obj;
}

void free_remote(A_Unused void *p_class_userdata,
                 GDExtensionClassInstancePtr p_instance) {
  api.free((struct NativeAction *)p_instance);
}

GDExtensionBool is_ok(const GDExtensionClassInstancePtr this) {
  const struct NativeAction *typed = (const struct NativeAction *)this;
  return typed->is_ok;
}
int error(const GDExtensionClassInstancePtr this) {

  const struct NativeAction *typed = (const struct NativeAction *)this;
  return typed->error;
}
GDExtensionObjectPtr result(const GDExtensionClassInstancePtr this) {

  const struct NativeAction *typed = (const struct NativeAction *)this;
  return typed->result;
}

void register_native_action_class(void) {
  GDExtensionClassCreationInfo5 info = class_create_info();
  info.is_exposed = 1;
  info.create_instance_func = &allocate_remote;
  info.free_instance_func = &free_remote;
  GDStringName name = this_class_name();
  api.classdb_register_extension_class(class_library, &name, api.nameofobject,
                                       &info);
  bind_method_with_return(&is_ok, &name, "is_ok", 0, NULL, NULL,
                          GDEXTENSION_VARIANT_TYPE_BOOL, &call_0_ret_bool,
                          NULL);
  bind_method_with_return(&error, &name, "error", 0, NULL, NULL,
                          GDEXTENSION_VARIANT_TYPE_INT, &call_0_ret_int, NULL);
  bind_method_with_return(&result, &name, "result", 0, NULL, NULL,
                          GDEXTENSION_VARIANT_TYPE_OBJECT, &call_0_ret_Object,
                          NULL);
  destructors.string_name_destructor(&name);
}
