# Programming Techniques for Scientific Simulations, HS 2013
# Exercise 5.1

cmake_minimum_required(VERSION 2.8)

add_library(integrate simpson.cpp)
add_executable(simpson main.cpp)
target_link_libraries(simpson integrate)

install(TARGETS simpson integrate
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
