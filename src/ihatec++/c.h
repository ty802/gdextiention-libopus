extern "C" {
extern GDExtensionClassLibraryPtr class_library;
extern void load_api(GDExtensionInterfaceGetProcAddress p_get_proc_address);
extern void GdOpus_initialize(void *p_userdata,
                       GDExtensionInitializationLevel p_level);
}
