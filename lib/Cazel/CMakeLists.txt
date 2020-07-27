cmake_minimum_required(VERSION 3.13)
project(Cazel C)

set(CMAKE_C_STANDARD 11)

add_library(Cazel
        src/common.h

        src/utilities.c
        src/utilities.h

        src/rendering/shapes.c
        src/rendering/shapes.h
        src/rendering/drawable_buffer.c
        src/rendering/drawable_buffer.h
        src/rendering/shader.h
        src/rendering/shader.c
        src/rendering/renderer.h
        src/rendering/renderer.c

        src/cazel/application.c
        src/cazel/application.h

        src/cazel.h
        src/cazel/entrypoint.h
        src/cazel/core.h

        src/cazel/window.h
        src/cazel/platform/windows_window.c
        src/cazel/platform/windows_window.h
        src/cazel/window.c)

add_subdirectory (lib/glfw)
add_subdirectory (lib/glad)
add_subdirectory (lib/cglm/)

target_link_libraries (Cazel LINK_PUBLIC glfw)
target_link_libraries (Cazel LINK_PUBLIC glad)
target_link_libraries (Cazel LINK_PUBLIC cglm)
