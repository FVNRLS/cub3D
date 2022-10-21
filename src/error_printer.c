/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:35:20 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/21 16:55:49 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

void	print_error(int	error, char *s)
{
	if (error == MALLOC_ERROR)
		printf("Error\nMemory allocation failed\n");
	else if (error == ARG_ERROR)
		printf("Error\nInvalid arguments\n");
	else if (error == INVALID_EXTENSION)
		printf("Error\nFile extension invalid\n");
	else if (error == OPEN_ERROR)
		printf("Error\nUnable to open file\n");
	else if (error == INVALID_TOKEN)
		printf("Error\nInvalid characters found: %s\n", s);
	else if (error == TEXTURE_ERROR)
		printf("Error\nMultiple definition of texture: %s\n", s);
	else if (error == COLOR_ERROR)
		printf("Error\nMultiple definition of color: %s\n", s);
}

int 	print_int_error(int error, char *s)
{
	print_error(error, s);
	return (EXIT_FAILURE);
}

void	*print_null_error(int error, char *s)
{
	print_error(error, NULL);
	return (NULL);
}