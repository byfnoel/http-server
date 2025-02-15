project('http-server', 'cpp',
    version : '0.1',
    default_options : ['warning_level=3', 'cpp_std=c++20']

)

# Specify dependencies
dependency('asio', required : true)

# Add your executable and source files
executable('http-server', 'src/main.cpp', dependencies : [dependency('asio')])



#project('http-server', 'cpp', default_options : ['cpp_std=c++20'])

# Specify dependencies
#asio_dep = dependency('asio', required : true, method : 'pkg-config')

# Add your executable and source files
#executable('http-server', 'src/main.cpp', dependencies : [asio_dep])
