project('godot-cpp')
python = find_program('python3')
scons = find_program('scons')
scons_build = custom_target('scons-build',
    output: ['lib.a','godot-cpp-generated'],
    command: [python, meson.current_source_dir() / 'findoutput.py' , meson.current_source_dir(), scons, meson.current_build_dir()],
    build_by_default: true
)

# Declare the dependency
godotcpp_dep = declare_dependency(
    link_with: scons_build[0],
    include_directories: include_directories('include','gdextension','gen/include'),
    sources: scons_build[1],
)
