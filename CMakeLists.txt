cmake_minimum_required(VERSION 3.23)
project(boats C)

set(CMAKE_C_STANDARD 17)

set(CMAKE_C_FLAGS "-lm -std=c17 -Wall -Wconversion -Wextra -Wsign-conversion -Wpedantic")

add_executable(boats main.c bateau_affichage.c port.c taxe.c statistique.c)
