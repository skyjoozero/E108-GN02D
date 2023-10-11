cmake_minimum_required(VERSION 3.26)
project(E108_GN02D C)

set(CMAKE_C_STANDARD 11)

add_executable(E108_GN02D main.c
        gps.h
        gps.c)
