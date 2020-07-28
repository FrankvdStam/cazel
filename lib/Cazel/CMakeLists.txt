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
        src/cazel/nuklear/nuklear_layer.h src/cazel/input.h src/cazel/input.c src/cazel/platform/windows/windows_input.c src/cazel/platform/windows/windows_input.h)

add_subdirectory (lib/glfw)
add_subdirectory (lib/glad)
add_subdirectory (lib/cglm/)

target_link_libraries (Cazel LINK_PUBLIC glfw)
target_link_libraries (Cazel LINK_PUBLIC glad)
target_link_libraries (Cazel LINK_PUBLIC cglm)
