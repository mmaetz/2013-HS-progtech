cmake_minimum_required(VERSION 2.8)

add_executable(assert assert.cpp)
add_executable(square1 main.cpp square.cpp)

add_library(square square.cpp)

add_executable(square2 main.cpp)

target_link_libraries(square2 square)