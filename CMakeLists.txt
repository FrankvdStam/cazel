cmake_minimum_required(VERSION 3.13)
project(Sandbox C)

set(CMAKE_C_STANDARD 11)

add_subdirectory (lib/Cazel)

add_executable(Sandbox src/main.c)


target_link_libraries (Sandbox LINK_PUBLIC Cazel)
