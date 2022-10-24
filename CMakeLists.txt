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
        src/parser/floor_ceiling_parser.c
        src/parser/map_parser/map_parser.c
        src/parser/color_extracter.c
        src/parser/map_parser/map_creator.c
        src/parser/map_parser/map_borders_checker.c
        src/parser/map_parser/map_void_checker.c

        #ERRORS
        src/error_printer.c

        #TOOLS
        src/tools/ft_strlen.c
        src/tools/ft_strncmp.c
        src/tools/ft_split.c
        src/tools/ft_strdup.c
        src/tools/ft_rgb_atoi.c
        src/tools/ft_isdigit.c
        src/tools/ft_strcmp.c
        src/tools/ft_splitlen.c
        src/tools/ft_free_split.c
        src/tools/ft_free_all_and_exit.c
        src/tools/ft_strtrim.c
        src/tools/ft_strjoin.c
        src/tools/ft_itoa.c
        )

# STATIC LIBRARIES
ADD_LIBRARY(get_next_line STATIC IMPORTED)
SET_TARGET_PROPERTIES(get_next_line PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/get_next_line/get_next_line.a)
TARGET_LINK_LIBRARIES(cub3D get_next_line)

ADD_LIBRARY(libmlx STATIC IMPORTED)
SET_TARGET_PROPERTIES(libmlx PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/minilibx/libmlx.a)
TARGET_LINK_LIBRARIES(cub3D libmlx)
