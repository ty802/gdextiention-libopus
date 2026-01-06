#include "opus_classes.h"
#include "api.h"
#include "defs.h"
#include "ihatec++/v.h"
#include "structsize.h"
#include <stdio.h>
#include <opus.h>
#include <stddef.h>
const GDExtensionInstanceBindingCallbacks opus_encoder_callbacks = {
    .create_callback = NULL, .free_callback = NULL, .reference_callback = NULL};
GDStringName opus_encoder_classname() {
  GDStringName name;
  constructors.new_stringname(&name, "opus_encoder", 1);
  return name;
}
void opus_encoder_class_bind_methods() {}
void opus_encoder_constructor(opus_encoder *self) {
  self->encodersize = opus_encoder_get_size(2);
  self->encoder = api.malloc(self->encodersize);
  opus_encoder_init(self->encoder, 48000, 2, OPUS_APPLICATION_VOIP);
  opus_encoder_ctl(self->encoder, OPUS_SET_BITRATE(64000));
}
GDExtensionObjectPtr opus_encoder_class_create_instance(
    A_Unused void *p_class_userdata,
    A_Unused GDExtensionBool p_notify_postinitialize) {

  GDExtensionObjectPtr obj;
  obj = api.new(api.nameofobject);
  opus_encoder *self = (opus_encoder *)api.malloc(sizeof(opus_encoder));
  self->encodersize = -1;
  self->encoder = NULL;
  self->object = obj;
  GDStringName encodername = opus_encoder_classname();
  api.object_set_instance(obj, &encodername, self);
  api.object_set_instance_binding(obj, class_library, self,
                                  &opus_encoder_callbacks);
  opus_encoder_constructor(self);
  return obj;
}
void opus_encoder_class_free_instance(A_Unused void *p_class_userdata,
                                      GDExtensionClassInstancePtr p_instance) {
  if (p_instance == NULL)
    return;
  opus_encoder *typed = (opus_encoder *)p_instance;
  if (typed->encodersize > 0) {
    api.free(typed->encoder);
  }
  api.free(typed);
}
GDPackedByteArray opus_encoder_get_encoded_data(opus_encoder *self,
                                                void *input) {
  size_t length = vec_len_Vector2(input);
  GDPackedByteArray res;
  struct Vec2 *data = vec_data_Vector2(input);
  size_t max_result_len = length * sizeof(float) * 2;
  unsigned char *buff = api.malloc(max_result_len);
  opus_int32 resultlen = opus_encode_float(self->encoder, (float *)data, length, buff,
                                    max_result_len);
  res = vec_construct_byte_from_data((char *)buff, resultlen);
  api.free(buff);
  return res;
}
