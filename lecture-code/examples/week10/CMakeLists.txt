cmake_minimum_required(VERSION 2.8)
add_library(simpson simpson.cpp)
add_executable(simpsontest main.cpp)
target_link_libraries(simpsontest simpson)
