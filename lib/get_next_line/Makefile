# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 13:47:53 by rmazurit          #+#    #+#              #
#    Updated: 2022/11/03 15:44:42 by rmazurit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libgnl.a
BONUS_NAME 	= 	libgnl_bonus.a


CC 		= 	cc

FLAGS		= 	-Wall -Wextra -Werror

SRC 		= 	get_next_line.c			\
                   	get_next_line_utils.c		\

BONUS_SRC	=	get_next_line_bonus.c		\
			get_next_line_utils_bonus.c	\

OBJ 		= 	${SRC:.c=.o}

BONUS_OBJ	=	${BONUS_SRC:.c=.o}

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o

all: $(NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(FLAGS) -c $(BONUS_SRC)
	ar rc $(BONUS_NAME) *.o

bonus: $(BONUS_NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
