cmake_minimum_required(VERSION 2.8)

include_directories(${CMAKE_INSTALL_PREFIX}/include)
link_directories(${CMAKE_INSTALL_PREFIX}/lib)

add_executable(benchmark main.cpp)
target_link_libraries(benchmark random timer)

install(TARGETS benchmark DESTINATION bin)
