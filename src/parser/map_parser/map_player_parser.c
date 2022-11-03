/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:41:27 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/03 13:46:40 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

static void	init_scalars(t_data *data, double angle)
{
	data->player->x_scalar = sin(angle);
	data->player->y_scalar = -1 * cos(angle);
}

static void set_player_angle(t_data *data)
{
	double	init_angle;

	if (data->player->dir == PLAYER_N)
		init_angle = 0;
	else if (data->player->dir == PLAYER_E)
		init_angle = 0.5 * M_PI;
	else if (data->player->dir == PLAYER_S)
		init_angle = M_PI;
	else if (data->player->dir == PLAYER_W)
		init_angle = 1.5 * M_PI;
	data->player->angle = init_angle;
	init_scalars(data, init_angle);
}

static int	config_player(t_data *data, int x, int y)
{

	if ((data->player->dir != VOID) || (x == 0 || y == 0))
	{
		data->parse_error = true;
		return (print_line_error(data, y));
	}
	data->player->x = x;
	data->player->y = y;
	data->player->dir = data->map[x][y];
	data->map[x][y] = ZERO;
	set_player_angle(data);
	return (EXIT_SUCCESS);
}

static int	check_item_validity(t_data *data, char item, int y_pos)
{
	int i;

	i = 0;
	while (i < NUM_ITEMS)
	{
		if (data->conf->items[i] == item)
			return (EXIT_SUCCESS);
		i++;
	}
	data->parse_error = true;
	return (print_line_error(data, (y_pos)));
}

void	parse_player(t_data *data)
{
	char	item;
	int 	x;
	int 	y;

	y = 0;
	while (y < data->tab->max_y)
	{
		x = 0;
		while (x < data->tab->max_x)
		{
			item = data->map[x][y];
			if (check_item_validity(data, item, y) == EXIT_FAILURE)
				return ;
			if (item == 'N' || item == 'S' || item == 'E' || item == 'W')
				if (config_player(data, x, y) == EXIT_FAILURE)
					return ;
			x++;
		}
		y++;
	}
}
