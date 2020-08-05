cmake_minimum_required(VERSION 3.13)
project(Sandbox C)

set(CMAKE_C_STANDARD 11)

add_subdirectory (lib/cazel)

add_executable(Sandbox src/main.c)


target_link_libraries (Sandbox LINK_PUBLIC cazel)

#file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

target_compile_options(Sandbox PUBLIC
        -pedantic-errors
        -ansi
        -pedantic
        )