/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_void_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:34:41 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/06 21:41:09 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_bottom_row(t_data *data, int x, int y)
{
	char	item;
	int 	i_row;

	i_row = (y + 1);
	if (i_row < data->tab->max_y)
	{
		if ((x - 1) >= 0)
		{
			item = data->map[x - 1][i_row];
			if (item == ZERO)
				return (EXIT_FAILURE);
		}
		item = data->map[x][i_row];
		if (item == ZERO)
			return (EXIT_FAILURE);
		if ((x + 1) < data->tab->max_x)
		{
			item = data->map[x + 1][i_row];
			if (item == ZERO)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int	check_middle_row(t_data *data, int x, int y)
{
	char	item;
	int 	i_col;

	i_col = (x - 1);
	if (i_col >= 0)
	{
		item = data->map[i_col][y];
		if (item == ZERO)
			return (EXIT_FAILURE);
	}
	i_col = (x + 1);
	if (i_col < data->tab->max_x)
	{
		item = data->map[i_col][y];
		if (item == ZERO)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_top_row(t_data *data, int x, int y)
{
	char	item;
	int 	i_row;

	i_row = (y - 1);
	if (i_row >= 0)
	{
		if ((x - 1) >= 0)
		{
			item = data->map[x - 1][i_row];
			if (item == ZERO)
				return (EXIT_FAILURE);
		}
		item = data->map[x][i_row];
		if (item == ZERO)
			return (EXIT_FAILURE);
		if ((x + 1) < data->tab->max_x)
		{
			item = data->map[x + 1][i_row];
			if (item == ZERO)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int	check_item(t_data *data, int x, int y)
{
	int 	error_line;

	if (check_top_row(data, x, y) == EXIT_FAILURE)
	{
		error_line = (y - 1);
		return (print_line_error(data, error_line));
	}
	else
	{
		if (check_middle_row(data, x, y) == EXIT_FAILURE)
			return (print_line_error(data, y));
		else
		{
			if (check_bottom_row(data, x, y) == EXIT_FAILURE)
			{
				error_line = (y + 1);
				return (print_line_error(data, error_line));
			}
		}
	}
	return (EXIT_SUCCESS);
}

/*
 	Checking 360 degree around for every void space on the map.
	Void spaces should be surrounded by 1's or other void spaces.
 	If 0 is encountered -> invalid map!
 	To avoid checking out of range elements on map borders (invalid index)
 	a pre-check is applied before each check:

	--> x value_to_check should be >= x_min (0) and < x_max
 	--> y value_to_check should be >= y_min (0) and < y_max - 1

	+-------------+-------------+-------------+
	| (x-1):(y-1) | (x):(y-1)   | (x+1):(y-1) |
	+-------------+-------------+-------------+
	| (x-1):(y)   | void coord. | (x+1):(y)   |
	+-------------+-------------+-------------+
	| (x-1):(y+1) | (x):(y+1)   | (x+1):(y+1) |
	+-------------+-------------+-------------+
*/
void	check_invalid_void_spaces(t_data *data)
{
	int 	x;
	int 	y;
	int 	ret;

	y = 0;
	ret = 0;
	while (y < (data->tab->max_y))
	{
		x = 0;
		while (x < data->tab->max_x)
		{
			if (data->map[x][y] == VOID)
				ret = check_item(data, x, y);
			if (ret == EXIT_FAILURE)
				return ;
			x++;
		}
		y++;
	}
}