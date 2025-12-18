project('GDOpus', 'c',
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
sources = run_command('find', 'src', '-name', '*.c', '-type', 'f',
  check: true
).stdout().strip().split('\n')
libopus_proj = subproject('libopus')
libopus_dep = libopus_proj.get_variable('opus_dep')
# Build shared library
gdopus_lib = shared_library('GDOpus',
  sources,
  dependencies: libopus_dep,
  include_directories: include_directories('src','External'),
  c_args: ['-O0', '-g','-Wunused-parameter'],
  install: true,
  install_dir: 'bin'
)
