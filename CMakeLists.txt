cmake_minimum_required(VERSION 3.8)
project(agenda)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c date.c date.h horaire.c horaire.h rdv.c rdv.h)
add_executable(agenda ${SOURCE_FILES} main.c)