cmake_minimum_required(VERSION 3.8)
project(agenda)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES src/main.c src/date.c headers/date.h src/horaire.c headers/horaire.h src/rdv.c headers/rdv.h headers/lib/colors.h)
add_executable(agenda ${SOURCE_FILES} src/main.c)