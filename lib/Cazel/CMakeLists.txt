cmake_minimum_required(VERSION 3.13)
project(Cazel C)

set(CMAKE_C_STANDARD 11)
add_compile_definitions(WINDOWS)

add_library(Cazel

        src/cazel.h

        src/cazel/main.c
        src/cazel/core.h
        src/cazel/application.c
        src/cazel/application.h
        src/cazel/window.h
        src/cazel/window.c

        src/cazel/platform/windows/windows_window.c
        src/cazel/platform/windows/windows_window.h

        src/cazel/events/event.c
        src/cazel/events/event.h

        src/cazel/layers/layer.c
        src/cazel/layers/layer.h

        src/cazel/nuklear/nuklear_layer.c
        src/cazel/nuklear/nuklear_layer.h src/cazel/input.h src/cazel/input.c src/cazel/platform/windows/windows_input.c src/cazel/platform/windows/windows_input.h src/cazel/renderer/buffers/buffers.c src/cazel/renderer/buffers/buffers.h src/cazel/platform/opengl/opengl_context.c src/cazel/platform/opengl/opengl_context.h src/cazel/context.c src/cazel/context.h)

target_compile_options(Cazel PRIVATE -Wall -Wextra -pedantic -Werror -Wno-sign-compare -Wno-unused-parameter -Wno-unused-but-set-variable)


add_subdirectory (lib/glfw)
add_subdirectory (lib/glad)
add_subdirectory (lib/cglm/)

target_link_libraries (Cazel LINK_PUBLIC glfw)
target_link_libraries (Cazel LINK_PUBLIC glad)
target_link_libraries (Cazel LINK_PUBLIC cglm)
