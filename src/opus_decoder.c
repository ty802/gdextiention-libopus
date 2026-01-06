#include "opus_classes.h"
#include "api.h"
#include "defs.h"
#include "structsize.h"
#include <stdio.h>
#include <opus.h>
#include <stddef.h>
#include "ihatec++/v.h"
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
GDPackedVector2Array opus_decoder_get_data(opus_decoder *self,
                                                void *input,int expectedlen) {
        size_t len = vec_len_byte(input);
        const char* data = vec_data_byte(input);
        void* resdata = api.malloc(expectedlen * sizeof(float) * 2);
        // yes this is shit and i deserve the warning for it
        // but also the godot docs are shit and i have no idea how do fix this
        int err = opus_decode_float(self->decoder,(unsigned char*)data,len,resdata,expectedlen,1);
        GDPackedVector2Array result = vec_construct_byte_from_vector2(resdata, expectedlen);
        api.free(resdata);
        return result;
}
