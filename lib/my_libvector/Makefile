# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 17:24:08 by hoomen            #+#    #+#              #
#    Updated: 2022/11/07 16:32:59 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libvector.a

CC			=	cc

FLAGS		=	-Wall -Wextra -Werror

SRC			=	rotate_vector.c

OBJ			=	${SRC:.c=.o}

HEADER		=	libvector.h

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
