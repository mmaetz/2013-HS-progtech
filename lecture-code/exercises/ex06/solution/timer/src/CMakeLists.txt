cmake_minimum_required(VERSION 2.8)

add_library(timer STATIC timer.cpp)

install(TARGETS timer DESTINATION lib)
install(FILES timer.hpp DESTINATION include)
