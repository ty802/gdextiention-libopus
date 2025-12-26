#include "opus_classes.h"
#include "api.h"
#include "defs.h"
#include "godot.h"
#include "opus_defines.h"
#include "opus_types.h"
#include "structsize.h"
#include <stdio.h>
#include <opus.h>
#include <stddef.h>
const GDExtensionInstanceBindingCallbacks opus_decoder_callbacks = {
    .create_callback = NULL, .free_callback = NULL, .reference_callback = NULL};
GDStringName opus_decoder_classname() {
  GDStringName name;
  constructors.new_stringname(&name, "opus_decoder", 1);
  return name;
}
void opus_decoder_class_bind_methods() {}
void opus_decoder_constructor(opus_decoder *self) {
  self->decodersize = opus_decoder_get_size(2);
  self->decoder = api.malloc(self->decodersize);
  opus_decoder_init(self->decoder, 48000, 2);
}
GDExtensionObjectPtr opus_decoder_class_create_instance(
    A_Unused void *p_class_userdata,
    A_Unused GDExtensionBool p_notify_postinitialize) {

  GDExtensionObjectPtr obj;
  obj = api.new(api.nameofobject);
  opus_decoder *self = (opus_decoder *)api.malloc(sizeof(opus_decoder));
  self->decodersize = -1;
  self->decoder = NULL;
  self->object = obj;
  GDStringName decodername = opus_decoder_classname();
  api.object_set_instance(obj, &decodername, self);
  api.object_set_instance_binding(obj, class_library, self,
                                  &opus_decoder_callbacks);
  opus_decoder_constructor(self);
  return obj;
}
void opus_decoder_class_free_instance(A_Unused void *p_class_userdata,
                                      GDExtensionClassInstancePtr p_instance) {
  if (p_instance == NULL)
    return;
  opus_decoder *typed = (opus_decoder *)p_instance;
  if (typed->decodersize > 0) {
    api.free(typed->decoder);
  }
}
GDPackedByteArray opus_decoder_get_data(opus_decoder *self,
                                                void *input) {
}
