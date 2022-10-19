cmake_minimum_required(VERSION 3.23)
project(cub3D C)

set(CMAKE_C_STANDARD 99)

add_executable(cub3D src/main.c

        #HEADERS
        incl/cub3D.h
        incl/struct.h
        incl/errors.h
        incl/tools.h

        #INITIALIZER AND DESTRUCTOR
        src/initializer/initializer.c
        src/initializer/map_objects.c
        src/destructor.c

        #PARSER
        src/parser/parser.c
        src/parser/textures_parser.c
        src/parser/colors_parser.c
        src/parser/map_parser.c

        #ERRORS
        src/error_printer.c

        #TOOLS
        src/tools/ft_strlen.c
        src/tools/ft_strncmp.c
        src/tools/ft_split.c
        src/tools/ft_strdup.c src/tools/ft_atoi.c src/tools/ft_isdigit.c src/tools/ft_strcmp.c src/tools/ft_splitlen.c)

ADD_LIBRARY(get_next_line STATIC IMPORTED)
SET_TARGET_PROPERTIES(get_next_line PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/get_next_line/get_next_line.a)
TARGET_LINK_LIBRARIES(cub3D get_next_line)
