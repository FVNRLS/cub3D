/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:39:50 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/27 20:04:04 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

static void	set_player_x_pos(t_data *data, double x_step)
{
	if (data->minimap->x_offset < 0)
	{
		data->minimap->x_player += (data->minimap->x_offset - 1) * x_step;
		data->minimap->x_offset = 0;
	} else if (data->minimap->x_offset + MINIMAP_SCOPE > data->tab->max_x) {
		data->minimap->x_player += x_step * (data->minimap->x_offset +
											 MINIMAP_SCOPE + 1 -
											 data->tab->max_x);
		data->minimap->x_offset = data->tab->max_x - MINIMAP_SCOPE - 1;
	}
}

static void	set_player_y_pos(t_data *data, double y_step)
{
	if (data->minimap->y_offset < 0)
	{
		data->minimap->y_player += (data->minimap->y_offset) * y_step;
		data->minimap->y_offset = 0;
	}
	else if (data->minimap->y_offset + MINIMAP_SCOPE > data->tab->max_y - 1)
	{
		data->minimap->y_player += y_step * (data->minimap->y_offset +
									 MINIMAP_SCOPE + 1 - data->tab->max_y);
		data->minimap->y_offset = data->tab->max_y - MINIMAP_SCOPE - 1;
	}
}

void	set_offset(t_data *data)
{

	double step;

	step = (double)data->minimap->size / MINIMAP_SCOPE;
	data->minimap->x_player = data->minimap->size / 2;
	data->minimap->y_player = data->minimap->size / 2;
	data->minimap->x_offset = (int)data->player->x - MINIMAP_SCOPE / 2;
	data->minimap->y_offset = (int)data->player->y - MINIMAP_SCOPE / 2;
	set_player_x_pos(data, step);
	set_player_y_pos(data, step);
}

bool	check_collisions(t_data *data)
{
	double new_x;
	double new_y;

	new_x = data->player->x + data->player->x_factor;
	new_y = data->player->y + data->player->y_factor;

	if (new_x >= data->tab->max_x - 1.5 || new_y >= data->tab->max_y - 1.5)
		return (true);
	if (new_x <= 0.5 || new_y <= 0.5)
		return (true);
	return (false);
}