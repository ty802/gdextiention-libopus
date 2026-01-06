project('GDOpus', 'c','cpp',
  version: '1.0',
  default_options: [
    'warning_level=2',
    'buildtype=debug',
    'optimization=0',
  ]
)

add_project_arguments('-std=c11', language: 'c')
add_project_arguments('-std=c++17', language: 'cpp')
# Set compiler based on platform
cc = meson.get_compiler('c')
if host_machine.system() == 'darwin' or host_machine.system() == 'linux'
  if cc.get_id() != 'clang'
    warning('Preferred compiler is clang on macOS/Linux')
  endif
endif

# Collect all C source files from src directory
libopus_proj = subproject('libopus', default_options: [
    'default_library=static',  
  ])
link_args = []
comp_args = []
if host_machine.system() == 'darwin'  # macOS
  link_args += ['-Wl,-dead_strip']
  comp_args += ['-fvisibility=hidden','-fvisibility-inlines-hidden','-ffunction-sections']
elif host_machine.system() == 'linux'
  link_args += ['-Wl,--exclude-libs,ALL', '-Wl,--gc-sections']
  comp_args += ['-fvisibility=hidden','-fvisibility-inlines-hidden','-ffunction-sections']
elif host_machine.system() == 'windows'
  # Windows-specific flags if needed
  link_args += []
endif
libopus_dep = libopus_proj.get_variable('opus_dep')
gdcpp_proj = subproject('godotcpp')
gdcpp_dep = gdcpp_proj.get_variable('godotcpp_dep')
gdopus_lib = shared_library('GDOpus',
  sources : ['src/api.c','src/ihatec++/v.cpp','src/init.c','src/Opus.c','src/cpp/audio_stream_raw_opus.cpp','src/NativeAction.c'],
  dependencies: [libopus_dep,gdcpp_dep],
  include_directories: include_directories('src'),
  c_args: ['-g'] + comp_args,
  cpp_args: ['-g'] + comp_args,
  link_args: link_args
)

