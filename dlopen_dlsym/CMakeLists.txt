cmake_minimum_required(VERSION 3.2.1)
project(dlopen_dlsym)

#SharedLibrary
add_library(library SHARED library.c)

#MainProg
add_executable(main main.c)
target_link_libraries(main dl)
