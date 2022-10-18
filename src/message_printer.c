//
// Created by Roman Mazuritskiy on 10/18/22.
//

#include "../incl/cub3D.h"

void	print_error(int	error)
{
	if (error == ARG_ERROR)
		printf("Error\nInvalid arguments\n");
	else if (error == INVALID_EXTENSION)
		printf("Error\nFile extension invalid\n");
	else if (error == OPEN_ERROR)
		printf("Error\nUnable to open file\n");
}

int 	print_int_error(int error)
{
	print_error(error);
	return (EXIT_FAILURE);
}

void	*print_null_error(int error)
{
	print_error(error);
	return (NULL);
}