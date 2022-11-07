/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:41:27 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/07 16:57:52 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

static void	init_camera_plane(t_data *data)
{
	data->player->camplane[X] = 0.5 * data->player->x_scalar;
	data->player->camplane[Y] = 0.5 * data->player->y_scalar;
	rotate_vector(data->player->camplane, 0.5 * M_PI);
}

/*
 * sets the player angle (converted from degrees to radians)
 * depending on the player orientation (N,W,E,S)
 * initializes the starting camera plane depending on the players orientation
 * */
static void	set_player_angle(t_data *data)
{
	if (data->player->dir == PLAYER_N)
		data->player->angle = 0;
	else if (data->player->dir == PLAYER_E)
		data->player->angle = 0.5 * M_PI;
	else if (data->player->dir == PLAYER_S)
		data->player->angle = M_PI;
	else if (data->player->dir == PLAYER_W)
		data->player->angle = 1.5 * M_PI;
	data->player->x_scalar = sin(data->player->angle);
	data->player->y_scalar = -1 * cos(data->player->angle);
	init_camera_plane(data);
}

/*
 * saves the player position as x and y coordinates, replaces the found element
 * with '0' and sets the starting player angle
 * */
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

/* checks if the map element belongs to valid identifiers (items) */
static int	check_item_validity(t_data *data, char item, int y_pos)
{
	int	i;

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

/*
 * Checks if the player on the parsed has a valid position and isn't defined
 * multiple times.
 * If there are no errors - saves the player position as x and y coordinates and
 * replaces the player element on map with '0'
 * */
void	parse_player(t_data *data)
{
	char	item;
	int		x;
	int		y;

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
