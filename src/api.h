#pragma once
#include "godot.h"
#include "godot/core/extension/gdextension_interface.h"
extern GDExtensionClassLibraryPtr class_library;

// API methods.

struct Constructors
{
    GDExtensionInterfaceStringNameNewWithUtf8Chars string_name_from_utf8;
    GDExtensionInterfaceStringNameNewWithUtf8CharsAndLen string_name_from_utf8_and_Len;
};

struct Destructors
{
    GDExtensionPtrDestructor string_name_destructor;
    GDExtensionPtrDestructor string_destructor;
};

struct API
{
    GDExtensionInterfaceClassdbRegisterExtensionClass5 classdb_register_extension_class;
    GDExtensionInterfaceClassdbUnregisterExtensionClass classdb_unregister_extension_class;
    GDExtensionInterfaceMemAlloc malloc;
    GDExtensionInterfaceMemFree free;
    GDExtensionInterfaceObjectSetInstance object_set_instance;
    GDExtensionInterfaceObjectSetInstanceBinding object_set_instance_binding;
    GDExtensionInterfaceClassdbConstructObject2 new;
    GDExtensionInterfaceStringNameNewWithLatin1Chars new_stringname;
    GDExtensionInterfaceStringNewWithLatin1Chars new_string;
};
#ifndef STATIC_API_
extern struct Destructors destructors;
extern struct Constructors constructors;
extern struct API api;
#endif // !static
void load_api(GDExtensionInterfaceGetProcAddress p_get_proc_address);
