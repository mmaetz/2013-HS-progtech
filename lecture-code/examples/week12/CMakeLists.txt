cmake_minimum_required(VERSION 2.8)
FOREACH(S timesimple timesimple2 timelazyflex2 timelazy2 timeet)
  add_executable(${S} ${S}.cpp)
ENDFOREACH(S)

