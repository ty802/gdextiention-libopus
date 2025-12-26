project('GDOpus', 'c','cpp',
  version: '1.0',
  default_options: [
    'warning_level=2',
    'buildtype=debug',
    'optimization=0',
  ]
)

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
    'b_lto=true'
  ])
libopus_dep = libopus_proj.get_variable('opus_dep')
gdcpp_proj = subproject('godotcpp', default_options: ['b_lto=true'])
gdcpp_dep = gdcpp_proj.get_variable('godotcpp_dep')
gdopus_lib = shared_library('GDOpus',
  sources : ['src/api.c','src/ihatec++/v.cpp','src/init.c','src/Opus.c','src/cpp/audio_stream_raw_opus.cpp'],
  dependencies: [libopus_dep,gdcpp_dep],
  include_directories: include_directories('src'),
  c_args: ['-O0', '-g','-Wunused-parameter','-fvisibility=hidden','-fvisibility-inlines-hidden','-ffunction-sections'],
  link_args: ['-Wl,--exclude-libs,ALL','-Wl,--gc-sections']
)

