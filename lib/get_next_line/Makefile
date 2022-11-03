# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 13:47:53 by rmazurit          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2022/10/30 18:01:14 by hoomen           ###   ########.fr        #
=======
#    Updated: 2022/11/03 10:52:56 by rmazurit         ###   ########.fr        #
>>>>>>> 38223a195207b3123184be0af43ee986b9edcdf4
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
