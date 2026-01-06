#pragma once
#include <gdextension_interface.h>
#include "structsize.h"
#include <opus.h>
typedef struct {
  OpusEncoder *encoder;
  GDExtensionObjectPtr object; 
  int encodersize;
} opus_encoder;
typedef struct {
  OpusDecoder *decoder;
  GDExtensionObjectPtr object; 
  int decodersize;
} opus_decoder;
typedef struct {

} packet;
void opus_encoder_class_bind_methods();
GDExtensionObjectPtr
opus_encoder_class_create_instance(void *p_class_userdata,
                                   GDExtensionBool p_notify_postinitialize);
void opus_encoder_class_free_instance(void *p_class_userdata,
                                      GDExtensionClassInstancePtr p_instance);
GDStringName opus_encoder_classname();
GDPackedByteArray opus_encoder_get_encoded_data(opus_encoder *self,
                                                void *input);

void opus_decoder_class_bind_methods();
GDExtensionObjectPtr
opus_decoder_class_create_instance(void *p_class_userdata,
                                   GDExtensionBool p_notify_postinitialize);
void opus_decoder_class_free_instance(void *p_class_userdata,
                                      GDExtensionClassInstancePtr p_instance);
GDStringName opus_decoder_classname();
GDPackedVector2Array opus_decoder_get_data(opus_decoder *self,
                                                void *input,int expectedlen);
