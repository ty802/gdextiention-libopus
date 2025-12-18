#include "defs.h"
#include "godot.h"
#include "api.h"
#include "opus.h"
#include "godot/core/extension/gdextension_interface.h"
#include "opus_defines.h"
#include "opus_types.h"
#include "structsize.h"
#include "Opus.h"
#include <sys/types.h>
const GDExtensionInstanceBindingCallbacks opus_encoder_callbacks = {
        .create_callback = NULL,
        .free_callback = NULL,
        .reference_callback = NULL
};
GDStringName opus_encoder_classname(){
        GDStringName name;
        api.new_stringname(&name,"opus_encoder",1);
        return name;
}
void opus_encoder_class_bind_methods() {}
void opus_encoder_constructor(opus_encoder* self){
        int error;
        self->encoder = opus_encoder_create(48000, 2, OPUS_APPLICATION_VOIP, &error);
}
GDExtensionObjectPtr opus_encoder_class_create_instance(A_Unused void *p_class_userdata,A_Unused GDExtensionBool p_notify_postinitialize) {

        GDExtensionObjectPtr obj;
        GDStringName basename;
        api.new_stringname(&basename,"Object",1);
        obj = api.new(&basename);
        destructors.string_name_destructor(&basename);
        opus_encoder* self = (opus_encoder*)api.malloc(sizeof(opus_encoder));
        self->encoder = NULL;
        self->object = obj;
        GDStringName encodername = opus_encoder_classname();
        api.object_set_instance(obj,&encodername,self);
        api.object_set_instance_binding(obj,class_library,self,&opus_encoder_callbacks);
        opus_encoder_constructor(self);
        return obj;
}
void opus_encoder_class_free_instance(A_Unused void *p_class_userdata,
                              GDExtensionClassInstancePtr p_instance) {
        if(p_instance == NULL)return;
        opus_encoder* typed = (opus_encoder*)p_instance;
        if(typed->encoder != NULL){
                opus_encoder_destroy(typed->encoder);
        }
}

