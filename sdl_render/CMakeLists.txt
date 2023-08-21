project(sdl_render)

cmake_minimum_required(VERSION 3.2.1)

find_package(SDL2 REQUIRED)

add_executable(render render.c)

target_include_directories(render PRIVATE ${SDL2_INCLUDE_DIRS})

target_link_libraries(render PRIVATE ${SDL2_LIBRARIES})