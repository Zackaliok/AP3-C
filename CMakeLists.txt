cmake_minimum_required(VERSION 3.24)
project(AP3_C C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(AP3_C TD9/td9.c TD9/td9.h)
