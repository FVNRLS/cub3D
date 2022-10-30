# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 14:20:18 by hoomen            #+#    #+#              #
#    Updated: 2022/10/30 18:01:58 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D
VPATH	=	src\
			src/bonus src/bonus/minimap\
			src/hooks_and_events src/initializer src/parser\
			src/tools src/parser/map_parser\
			src/initializer\
			src
CC		=	cc -g
CFLAGS	=	#-Werror -Wextra -Wall

SRC		=	bonus_initializer.c collisions_checker.c\
			minimap.c wall_drawer.c\
			hooks_catcher.c key_hooks.c mouse_hooks.c movement_hooks.c\
			rotation_hooks.c\
			initializer.c map_objects.c mlx_initializer.c\
			arguments_checker.c map_borders_checker.c map_creator.c map_parser.c\
			map_player_parser.c map_void_checker.c\
			color_extracter.c floor_ceiling_parser.c parser.c textures_parser.c\
			ft_degree_to_radian.c ft_free_all_and_exit.c ft_free_split.c\
			ft_isdigit.c ft_itoa.c ft_rgb_atoi.c ft_split.c ft_splitlen.c\
			ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c\
			ft_strtrim.c\
			destructor.c error_printer.c main.c

MLX_LIB =	libmlx42.a
F_MLX =		lib/minilibx
MLX_FLAGS =	-lglfw -Llib -lMLX42 -framework Cocoa -framework OpenGL -framework IOKit
GNL_FLAGS =	-Llib -lgnl

GNL_LIB	=	libgnl.a
F_GNL	=	lib/get_next_line

OBJ = $(SRC:.c=.o) $(F_LIBFT_PLUS:.c=.o)

all: $(NAME)

%.o: %.c lib
	$(CC) -c $(CFLAGS) $< -o $@ 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(GNL_FLAGS) -o $(NAME)

lib: $(MLX_LIB) $(GNL_LIB)

$(MLX_LIB):
	$(MAKE) all -C $(F_MLX)
	mv $(F_MLX)/$(MLX_LIB) ./lib

$(GNL_LIB):
	$(MAKE) all -C $(F_GNL)
	mv $(F_GNL)/$(GNL_LIB) ./lib

clean:
	rm -f *.o

fclean:
	$(MAKE) clean -C $(F_MLX)
	rm -f lib/* 

.PHONY: all re clean fclean lib
