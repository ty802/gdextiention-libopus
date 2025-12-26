#include "opus_classes.h"
#include "api.h"
#include "defs.h"
#include "gdextension_interface.h"
#include "godot.h"
#include "ihatec++/v.h"
#include "structsize.h"
#include <sys/types.h>
struct Destructors destructors;
struct Constructors constructors;
struct API api;
static GDExtensionInitialization cppinit;
void init_encoder() {
  GDStringName name = opus_encoder_classname();
  GDExtensionClassCreationInfo5 opus_encoder = {
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
      .create_instance_func = opus_encoder_class_create_instance,
      .free_instance_func = opus_encoder_class_free_instance,
      .unreference_func = NULL,
      .recreate_instance_func = NULL,
      .get_virtual_func = NULL,
      .get_virtual_call_data_func = NULL,
      .call_virtual_with_data_func = NULL,
  };

  api.classdb_register_extension_class(class_library, &name, api.nameofobject,
                                       &opus_encoder);
  {
    const char *names[] = {"8000", "12000", "16000", "24000", "48000"};
    const int nums[] = {8000, 12000, 16000, 24000, 48000};
    GDStringName enumbasename;
    constructors.new_stringname(&enumbasename, "OPUS_ENCODER_SAMPLE_RATE", 0);
    for (uint i = 0; i < 5; i++) {
      GDStringName valuename;
      constructors.new_stringname(&valuename, names[i], 0);
      api.bind_enum(class_library, &name, &enumbasename, &valuename, nums[i],
                    0);
      destructors.string_name_destructor(&valuename);
    }
    destructors.string_name_destructor(&enumbasename);
  }

  {
    const char *names[] = {"Data"};
    const int types[] = {
        GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY,
    };
    bind_method_with_return(&opus_encoder_get_encoded_data, &name, "encode", 1,
                            names, (GDExtensionVariantType *)types,
                            GDEXTENSION_VARIANT_TYPE_PACKED_BYTE_ARRAY,
                            &call_1_PackedVector2Array_arg_ret_PackedByteArray,
                            NULL);
  }

}
void init_decoder(){
  GDStringName name = opus_decoder_classname();
  GDExtensionClassCreationInfo5 opsu_decoder = {
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
      .create_instance_func = opus_decoder_class_create_instance,
      .free_instance_func = opus_decoder_class_free_instance,
      .unreference_func = NULL,
      .recreate_instance_func = NULL,
      .get_virtual_func = NULL,
      .get_virtual_call_data_func = NULL,
      .call_virtual_with_data_func = NULL,
  };
  api.classdb_register_extension_class(class_library,&name,api.nameofobject,&opsu_decoder);
  {
    const char *names[] = {"Data"};
    const int types[] = {
        GDEXTENSION_VARIANT_TYPE_PACKED_BYTE_ARRAY,
    };
    bind_method_with_return(&opus_encoder_get_encoded_data, &name, "decode", 1,
                            names, (GDExtensionVariantType *)types,
                            GDEXTENSION_VARIANT_TYPE_PACKED_VECTOR2_ARRAY,
                            &call_1_PackedByteArray_arg_ret_PackedVector2Array,
                            NULL);
  }       
}
void GdOpus_initialize(A_Unused void *p_userdata,
                       GDExtensionInitializationLevel p_level) {
  if (p_level != GDEXTENSION_INITIALIZATION_SCENE) {
    return;
  }
  init_encoder();
  init_decoder();
}
void GdOpus_deinitialize(A_Unused void *p_userdata,
                         A_Unused GDExtensionInitializationLevel p_level) {
        destructors.string_name_destructor(api.nameofobject);
}

