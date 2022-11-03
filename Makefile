# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 13:28:05 by hoomen            #+#    #+#              #
#    Updated: 2022/11/03 21:34:48 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# **************************************************************************** #
# EXECUTABLE                                                                   #
# **************************************************************************** #

NAME	=	cub3D

# **************************************************************************** #
# PATH                                                                         #
# **************************************************************************** #

space :=
space +=
VPATH := $(subst $(space),:,$(shell find src -type d))

# **************************************************************************** #
# COMPILER                                                                     #
# **************************************************************************** #

CC		=	cc -g
CFLAGS	=	#-Werror -Wextra -Wall

# **************************************************************************** #
# SOURCE FILES                                                                 #
# **************************************************************************** #

SRC		=	destructor.c error_printer.c main.c

# **************************************************************************** #
# INITIALIZER                                                                  #
# **************************************************************************** #

SRC		+=	initializer.c map_objects.c mlx_initializer.c

# **************************************************************************** #
# PARSER                                                                       #
# **************************************************************************** #

SRC		+=	arguments_checker.c map_borders_checker.c map_creator.c map_parser.c\
			map_player_parser.c map_void_checker.c\
			color_extracter.c floor_ceiling_parser.c parser.c textures_parser.c

# **************************************************************************** #
# HOOKS AND EVENTS                                                             #
# **************************************************************************** #

SRC		+=	hooks_catcher.c key_hooks.c mouse_hooks.c movement_hooks.c\
			rotation_hooks.c

# **************************************************************************** #
# RAYCASTING                                                                   #
# **************************************************************************** #

SRC		+=	raycaster.c delta_calculator.c rays_minimap.c\
			hit_checker.c file2.c

# **************************************************************************** #
# BONUS                                                                        #
# **************************************************************************** #

SRC		+=	bonus_initializer.c collisions_checker.c\
			minimap.c wall_drawer.c draw_player.c

# **************************************************************************** #
# TOOLS                                                                        #
# **************************************************************************** #

SRC		+=	ft_degree_to_radian.c ft_free_all_and_exit.c ft_free_split.c\
			ft_isdigit.c ft_itoa.c ft_rgb_atoi.c ft_split.c ft_splitlen.c\
			ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c\
			ft_strtrim.c ft_abs_dbl.c

# **************************************************************************** #
# LIBRARIES                                                                    #
# **************************************************************************** #

VPATH		+=	lib

# minilibX #
MLX_LIB		=	libmlx42.a
F_MLX		=	lib/minilibx
MLX_FLAGS	=	-lglfw -Llib -lMLX42 -framework Cocoa -framework OpenGL\
				-framework IOKit
# get_next_line #
GNL_FLAGS	=	-Llib -lgnl
GNL_LIB		=	libgnl.a
F_GNL		=	lib/get_next_line

# my_vectorlib #
VEC_FLAGS	=	-Llib -lvector
VEC_LIB		=	libvector.a
F_VEC		=	lib/my_libvector

# **************************************************************************** #
# OBJECT FILES                                                                 #
# **************************************************************************** #

OBJ		=	$(addprefix obj/,$(SRC:.c=.o))

# **************************************************************************** #
# RULES                                                                        #
# **************************************************************************** #

all: $(NAME)

obj/%.o: %.c | lib obj
	$(CC) -c $(CFLAGS) $< -o $@

obj:
	mkdir obj

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(GNL_FLAGS) $(VEC_FLAGS) -o $(NAME)

lib: $(MLX_LIB) $(GNL_LIB) $(VEC_LIB)

$(MLX_LIB):
	$(MAKE) all -C $(F_MLX)
	$(MAKE) clean -C $(F_MLX)
	mv $(F_MLX)/$(MLX_LIB) ./lib

$(GNL_LIB):
	$(MAKE) all -C $(F_GNL)
	$(MAKE) clean -C $(F_GNL)
	mv $(F_GNL)/$(GNL_LIB) ./lib

$(VEC_LIB):
	$(MAKE) all -C $(F_VEC)
	$(MAKE) clean -C $(F_VEC)
	mv $(F_VEC)/$(VEC_LIB) ./lib

clean:
	rm -drf obj

fclean: clean
	rm -f $(NAME)

.PHONY: all re clean fclean lib
