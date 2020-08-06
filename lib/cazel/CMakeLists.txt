cmake_minimum_required(VERSION 3.13)
project(cazel C)

set(CMAKE_C_STANDARD 11)

add_compile_definitions(CAZEL_DEBUG)
if (WIN32)
    add_compile_definitions(CAZEL_WINDOWS)
endif (WIN32)

if(LINUX)
    add_compile_definitions(CAZEL_LINUX)
endif (LINUX)

add_library(cazel

        src/cazel.h

        src/cazel/main.c
        src/cazel/core.h
        src/cazel/application.c
        src/cazel/application.h

        src/cazel/window.h
        src/cazel/window.c
        src/cazel/platform/glfw/glfw_window.c
        src/cazel/platform/glfw/glfw_window.h

        src/cazel/input.h
        src/cazel/input.c
        src/cazel/platform/glfw/glfw_input.c
        src/cazel/platform/glfw/glfw_input.h

        src/cazel/context.c
        src/cazel/context.h
        src/cazel/platform/opengl/opengl_context.c
        src/cazel/platform/opengl/opengl_context.h


        src/cazel/events/event.c
        src/cazel/events/event.h

        src/cazel/layers/layer.c
        src/cazel/layers/layer.h

        src/cazel/nuklear/nuklear_layer.c
        src/cazel/nuklear/nuklear_layer.h

        src/cazel/renderer/buffers/buffers.c
        src/cazel/renderer/buffers/buffers.h
        src/cazel/renderer/renderer.c src/cazel/renderer/renderer.h src/cazel/renderer/orthographic_camera.c src/cazel/renderer/orthographic_camera.h)

target_compile_options(cazel PUBLIC

        -pedantic-errors
        -ansi
        -pedantic
        -Wall
        -Wextra
        -pedantic
        -Werror
        -Wno-sign-compare
        -Wno-unused-parameter
        -Wno-unused-but-set-variable
        -fno-common
        )


add_subdirectory (lib/glfw)
add_subdirectory (lib/glad)
add_subdirectory (lib/cglm/)
add_subdirectory (lib/flecs/)

target_link_libraries (cazel LINK_PUBLIC glfw)
target_link_libraries (cazel LINK_PUBLIC glad)
target_link_libraries (cazel LINK_PUBLIC cglm)
target_link_libraries (cazel LINK_PUBLIC flecs)
