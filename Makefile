# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 14:20:18 by hoomen            #+#    #+#              #
#    Updated: 2022/10/30 19:22:49 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D
VPATH	=	src
CC		=	cc -g
CFLAGS	=	#-Werror -Wextra -Wall
SRC		=	destructor.c error_printer.c main.c

# **************************************************************************** #
# INITIALIZER                                                                  #
# **************************************************************************** #

VPATH	+=	src/initializer
SRC		+=	initializer.c map_objects.c mlx_initializer.c

# **************************************************************************** #
# PARSER                                                                       #
# **************************************************************************** #

VPATH	+=	src/parser src/parser/map_parser
SRC		+=	arguments_checker.c map_borders_checker.c map_creator.c map_parser.c\
			map_player_parser.c map_void_checker.c\
			color_extracter.c floor_ceiling_parser.c parser.c textures_parser.c

# **************************************************************************** #
# HOOKS AND EVENTS                                                             #
# **************************************************************************** #

VPATH	+=	src/hooks_and_events src/initializer src/parser
SRC		+=	hooks_catcher.c key_hooks.c mouse_hooks.c movement_hooks.c\
			rotation_hooks.c

# **************************************************************************** #
# BONUS                                                                        #
# **************************************************************************** #

VPATH	+=	src/bonus src/bonus/minimap
SRC		+=	bonus_initializer.c collisions_checker.c\
			minimap.c wall_drawer.c
			
# **************************************************************************** #
# TOOLS                                                                        #
# **************************************************************************** #

VPATH	+=	src/tools
SRC		+=	ft_degree_to_radian.c ft_free_all_and_exit.c ft_free_split.c\
			ft_isdigit.c ft_itoa.c ft_rgb_atoi.c ft_split.c ft_splitlen.c\
			ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c\
			ft_strtrim.c

# **************************************************************************** #
# LIBRARIES                                                                    #
# **************************************************************************** #

MLX_LIB		=	libmlx42.a
F_MLX		=	lib/minilibx
MLX_FLAGS	=	-lglfw -Llib -lMLX42 -framework Cocoa -framework OpenGL\
				-framework IOKit
GNL_FLAGS	=	-Llib -lgnl
GNL_LIB		=	libgnl.a
F_GNL		=	lib/get_next_line

# **************************************************************************** #
# OBJECT FILES                                                                 #
# **************************************************************************** #

OBJ		=	$(SRC:.c=.o)


# **************************************************************************** #
# RULES                                                                        #
# **************************************************************************** #

all: $(NAME)

%.o: %.c lib | obj
	$(CC) -c $(CFLAGS) $< -o $@

obj:
	mkdir obj

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(GNL_FLAGS) -o $(NAME)
	mv $(OBJ) obj

lib: $(MLX_LIB) $(GNL_LIB)

$(MLX_LIB):
	$(MAKE) all -C $(F_MLX)
	mv $(F_MLX)/$(MLX_LIB) ./lib

$(GNL_LIB):
	$(MAKE) all -C $(F_GNL)
	mv $(F_GNL)/$(GNL_LIB) ./lib

clean:
	rm -drf obj

fclean: clean
	$(MAKE) clean -C $(F_MLX)
	rm -f lib/* 

.PHONY: all re clean fclean lib
