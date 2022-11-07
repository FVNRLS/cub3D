/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_borders_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:53:19 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/07 15:40:06 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

static int	check_right_side(t_data *data)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	while (++y < (data->tab->max_y - 2))
	{
		line = ft_itoa(data->conf->line_num + y);
		if (!line)
			return (print_int_error(MALLOC_ERROR, NULL));
		x = data->tab->max_x;
		while (--x >= 0)
		{
			if (data->map[x][y] == ONE)
				break ;
			else if (data->map[x][y] == ZERO)
			{
				print_int_error(INVALID_MAP, line);
				free(line);
				return (EXIT_FAILURE);
			}
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}

static int	check_left_side(t_data *data)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	while (++y < (data->tab->max_y - 2))
	{
		line = ft_itoa(data->conf->line_num + y);
		if (!line)
			return (print_int_error(MALLOC_ERROR, NULL));
		x = -1;
		while (++x < data->tab->max_x)
		{
			if (data->map[x][y] == ONE)
				break ;
			else if (data->map[x][y] == ZERO)
			{
				print_int_error(INVALID_MAP, line);
				free(line);
				return (EXIT_FAILURE);
			}
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}

static int	check_bottom(t_data *data)
{
	int		x;
	char	*line;

	x = data->tab->max_x - 1;
	line = ft_itoa(data->conf->line_num + data->tab->max_y - 1);
	if (!line)
		return (print_int_error(MALLOC_ERROR, NULL));
	while (x >= 0)
	{
		if (data->map[x][data->tab->max_y - 1] == ZERO)
		{
			print_int_error(INVALID_MAP, line);
			free(line);
			return (EXIT_FAILURE);
		}
		x--;
	}
	free(line);
	line = NULL;
	return (EXIT_SUCCESS);
}

static int	check_top(t_data *data)
{
	int		x;
	char	*line;

	x = 0;
	line = ft_itoa(data->conf->line_num);
	if (!line)
		return (print_int_error(MALLOC_ERROR, NULL));
	while (x < data->tab->max_x)
	{
		if (data->map[x][0] == ZERO)
		{
			print_int_error(INVALID_MAP, line);
			free(line);
			return (EXIT_FAILURE);
		}
		x++;
	}
	free(line);
	line = NULL;
	return (EXIT_SUCCESS);
}

void	check_map_borders(t_data *data)
{
	if (check_top(data) == EXIT_FAILURE)
		data->parse_error = true;
	else if (check_bottom(data) == EXIT_FAILURE)
		data->parse_error = true;
	else if (check_left_side(data) == EXIT_FAILURE)
		data->parse_error = true;
	else if (check_right_side(data) == EXIT_FAILURE)
		data->parse_error = true;
}
