cmake_minimum_required(VERSION 2.8)
FOREACH(S tester intrinsic)
  add_executable(${S} ${S}.cpp)
ENDFOREACH(S)

