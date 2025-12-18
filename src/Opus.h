#include <opus.h>
#include "godot.h"
#include "structsize.h"
typedef struct
{
        OpusEncoder* encoder;
    GDExtensionObjectPtr object; // Stores the underlying Godot object.
} opus_encoder;
void opus_encoder_class_bind_methods();
GDExtensionObjectPtr opus_encoder_class_create_instance(void *p_class_userdata, GDExtensionBool p_notify_postinitialize);
void opus_encoder_class_free_instance(void *p_class_userdata, GDExtensionClassInstancePtr p_instance);
GDStringName opus_encoder_classname();
