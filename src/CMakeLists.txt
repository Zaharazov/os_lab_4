cmake_minimum_required(VERSION 3.10)
project(Dynamic_Libraries)

set(CMAKE_CXX_STANDARD 17)

add_library(impl1 SHARED impl1.cpp)
add_library(impl2 SHARED impl2.cpp)

add_executable(comp compile.cpp)
target_link_libraries(comp impl1)

add_executable(run runtime.cpp)
