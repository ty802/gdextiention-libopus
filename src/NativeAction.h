#pragma once
#include "gdextension_interface.h"
#include "structsize.h"
struct NativeAction {
        GDExtensionObjectPtr base;
        GDExtensionBool is_ok;
        union{
                GDExtensionVariantPtr result;
                uint8_t error;
        };
};
void register_native_action_class(void);
