cmake_minimum_required(VERSION 3.24)
project(AP3_C C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(AP3_C
        TD1/main.c
        TD1/main.h TD2/main2.h TD2/main2.c TD3/main3.c TD4/main4.h TD4/main4.c TD5/main5.h TD5/main5.c DS/mainDS.c DS/mainDS.h TD6/Livres.c TD6/Livres.h TD6/Emprunts.c TD6/Emprunts.h TD7/td7.c TD7/td7.h)
