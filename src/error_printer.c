/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:28:35 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/25 12:43:15 by rmazurit         ###   ########.fr       */
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
	else if (error == INVALID_MAP)
		printf("Error\nInvalid map configuration on line: %s\n", s);
	else if (error == NO_PLAYER)
		printf("Error\nMissing input: no player specified\n");
	else if (error == NO_TEXTURE)
		printf("Error\nMissing input: no %s texture specified\n", s);
	else if (error == NO_COLOR)
		printf("Error\nMissing input: no %s color specified\n", s);
	else if (error == NO_MAP)
		printf("Error\nMissing input: no map\n");
}

int 	print_int_error(int error, char *s)
{
	print_error(error, s);
	return (EXIT_FAILURE);
}

int print_line_error(t_data *data, int y_pos)
{
	char	*line;

	data->parse_error = true;
	line = ft_itoa(data->conf->line_num + y_pos);
	if (!line)
		print_error(MALLOC_ERROR, NULL);
	else
		print_error(INVALID_MAP, line);
	free(line);
	return (EXIT_FAILURE);
}

void	*print_null_error(int error, char *s)
{
	print_error(error, NULL);
	return (NULL);
}

//TODO: del before submission
void	print_map(t_data *data)
{
	int x;
	int	y;

	printf("\n");
	y = 0;
	while (y < data->tab->max_y)
	{
		x = 0;
		while (x < data->tab->max_x)
		{
			printf("%c", data->map[x][y]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}
