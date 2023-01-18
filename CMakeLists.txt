cmake_minimum_required(VERSION 3.24)
project(AP3_C C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(AP3_C
        TD1/main.c
        TD1/main.h)
