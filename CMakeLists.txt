cmake_minimum_required(VERSION 3.23)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c)

add_subdirectory(libs)
target_link_libraries(untitled data_structures)
target_link_libraries(untitled algorithms)
