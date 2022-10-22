/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:53:19 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/22 17:51:56 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

static int check_right_side(t_data *data)
{

	return (EXIT_SUCCESS);
}

static int check_left_side(t_data *data)
{

	return (EXIT_SUCCESS);
}

static int check_bottom(t_data *data)
{

	return (EXIT_SUCCESS);
}


static int check_top_and_bottom(t_data *data)
{
	int 	x;
	char	*line;

	x = 0;
	line = ft_itoa(data->conf->line_num);
	if (!line)
		return (print_int_error(MALLOC_ERROR, line));
	while (x < data->tab->max_x)
	{
		if (data->map[x][0] == ZERO)
			return (print_int_error(INVALID_MAP, line));
		x++;
	}
	x = data->tab->max_x - 1;
	line = ft_itoa(data->conf->line_num + data->tab->max_y - 1);
	if (!line)
		return (print_int_error(MALLOC_ERROR, line));
	while (x >= 0)
	{
		if (data->map[x][data->tab->max_y - 1] == ZERO)
			return (print_int_error(INVALID_MAP, line));
		x--;
	}
	return (EXIT_SUCCESS);
}


void	check_map(t_data *data)
{
	if (check_top_and_bottom(data) == EXIT_FAILURE)
		data->parse_error = true;
//	else if (check_left_side(data) == EXIT_FAILURE)
//		data->parse_error = true;
//	else if (check_right_side(data) == EXIT_FAILURE)
//		data->parse_error = true;
}