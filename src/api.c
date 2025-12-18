#include "api.h"
#include "godot.h"
#include "godot/core/extension/gdextension_interface.h"
GDExtensionClassLibraryPtr class_library = NULL;
void load_api(GDExtensionInterfaceGetProcAddress p_get_proc_address)
{
    // Get helper functions first.
    GDExtensionInterfaceVariantGetPtrDestructor variant_get_ptr_destructor = (GDExtensionInterfaceVariantGetPtrDestructor)p_get_proc_address("variant_get_ptr_destructor");

    // API.
    api.classdb_register_extension_class = (GDExtensionInterfaceClassdbRegisterExtensionClass5)p_get_proc_address("classdb_register_extension_class5");
    api.classdb_unregister_extension_class = (GDExtensionInterfaceClassdbUnregisterExtensionClass)p_get_proc_address("classdb_unregister_extension_class");
    api.free = (GDExtensionInterfaceMemFree)p_get_proc_address("mem_free");
    api.malloc = (GDExtensionInterfaceMemAlloc)p_get_proc_address("mem_alloc");
    api.object_set_instance = (GDExtensionInterfaceObjectSetInstance)p_get_proc_address("object_set_instance");
    api.object_set_instance_binding = (GDExtensionInterfaceObjectSetInstanceBinding)p_get_proc_address("object_set_instance_binding");
    api.new = (GDExtensionInterfaceClassdbConstructObject2)p_get_proc_address("classdb_construct_object2");
    api.new_stringname = (GDExtensionInterfaceStringNameNewWithLatin1Chars)p_get_proc_address("string_name_new_with_latin1_chars");
    api.new_string = (GDExtensionInterfaceStringNewWithLatin1Chars)p_get_proc_address("string_new_with_latin1_chars");
    // Constructors.
    constructors.string_name_from_utf8 = (GDExtensionInterfaceStringNameNewWithUtf8Chars)p_get_proc_address("string_name_new_with_utf8_chars");
    constructors.string_name_from_utf8_and_Len = (GDExtensionInterfaceStringNameNewWithUtf8CharsAndLen)p_get_proc_address("string_name_new_with_utf8_chars_and_len");

    // Destructors.
    destructors.string_name_destructor = variant_get_ptr_destructor(GDEXTENSION_VARIANT_TYPE_STRING_NAME);
    destructors.string_name_destructor = variant_get_ptr_destructor(GDEXTENSION_VARIANT_TYPE_STRING);
}
