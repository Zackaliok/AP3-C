cmake_minimum_required(VERSION 3.24)
project(AP3_C C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(AP3_C
        TD1/main.c
        TD1/main.h TD2/main2.h TD2/main2.c TD3/main3.c TD4/main4.h TD4/main4.c)
