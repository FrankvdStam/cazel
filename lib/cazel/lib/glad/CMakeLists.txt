cmake_minimum_required(VERSION 3.13)
project(glad C)

include_directories(include)

add_library(glad src/glad.c)

set(CMAKE_C_STANDARD 11)