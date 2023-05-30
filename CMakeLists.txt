cmake_minimum_required(VERSION 3.23)
project(boats C)

set(CMAKE_C_STANDARD 17)

set(CMAKE_C_FLAGS "-lm -Wall -Wextra -Wconversion -Wsign-conversion -Wpedantic -Wformat")

add_executable(boats main.c bateau_affichage.c bateau.c port.c taxe.c statistique.c)
