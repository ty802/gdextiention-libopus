#include "defs.h"
#define STATIC_API_
struct Destructors destructors;
struct Constructors constructors;
struct API api;
#include "init.h"
#include "godot.h"
#include "api.h"
#include "Opus.h"
#include "structsize.h"
void GdOpus_initialize(A_Unused void *p_userdata,
                       GDExtensionInitializationLevel p_level) {
  if (p_level != GDEXTENSION_INITIALIZATION_SCENE) {
    return;
  }
  GDStringName Parentname;
  constructors.string_name_from_utf8_and_Len(&Parentname,"Object",6);
  GDExtensionClassCreationInfo5 opsu_encoder = {
      .is_exposed = 1,
      .create_instance_func = opus_encoder_class_create_instance,
      .free_instance_func = opus_encoder_class_free_instance
  };
  GDStringName name = opus_encoder_classname();
  api.classdb_register_extension_class(&class_library,&name,&Parentname,&opsu_encoder);
}
void GdOpus_deinitialize(A_Unused void *p_userdata,
                         A_Unused GDExtensionInitializationLevel p_level) {
}

GDExtensionBool GDE_EXPORT
opus_godot_init(GDExtensionInterfaceGetProcAddress p_get_proc_address,
                GDExtensionClassLibraryPtr p_library,
                GDExtensionInitialization *r_initialization) {
  r_initialization->initialize = GdOpus_initialize;
  r_initialization->deinitialize = GdOpus_deinitialize;
  r_initialization->userdata = NULL;
  r_initialization->minimum_initialization_level =
      GDEXTENSION_INITIALIZATION_CORE;
  class_library = p_library;
  load_api(p_get_proc_address);
  return 1;
}
