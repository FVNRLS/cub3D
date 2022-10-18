cmake_minimum_required(VERSION 3.23)
project(cub3D C)

set(CMAKE_C_STANDARD 99)

add_executable(cub3D src/main.c

        incl/cub3D.h
        incl/struct.h

        src/parser/textures_parser.c
        src/parser/colors_parser.c

        src/parser/map_parser.c src/parser/parser.c src/message_printer.c incl/errors.h)
