//
// Created by Roman Mazuritskiy on 10/18/22.
//

#ifndef ERRORS_H
# define ERRORS_H

# define	ARG_ERROR			1
# define	INVALID_EXTENSION	2
# define	OPEN_ERROR			3


void	print_error(int	error);
int 	print_int_error(int error);
void	*print_null_error(int error);

#endif
