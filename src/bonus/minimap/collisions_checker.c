/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:39:50 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/28 12:34:51 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

static void	set_offset_x_pos(t_data *data)
{
	if (data->minimap->x_offset < 0)
		data->minimap->x_offset = 0;
	else if (data->minimap->x_offset + MINIMAP_SCOPE > data->tab->max_x)
		data->minimap->x_offset = data->tab->max_x - MINIMAP_SCOPE;
}

static void	set_offset_y_pos(t_data *data)
{
	if (data->minimap->y_offset < 0)
		data->minimap->y_offset = 0;
	else if (data->minimap->y_offset + MINIMAP_SCOPE > data->tab->max_y)
		data->minimap->y_offset = data->tab->max_y - MINIMAP_SCOPE;
}

void	set_offset(t_data *data)
{
	data->minimap->x_offset = (int)data->player->x - MINIMAP_SCOPE / 2;
	data->minimap->y_offset = (int)data->player->y - MINIMAP_SCOPE / 2;
	set_offset_x_pos(data);
	set_offset_y_pos(data);
}

bool	check_collisions(t_data *data)
{
	double new_x;
	double new_y;

	new_x = data->player->x + data->player->x_factor;
	new_y = data->player->y + data->player->y_factor;

	if (new_x >= data->tab->max_x - 0.85 || new_y >= data->tab->max_y - 0.85)
		return (true);
	if (new_x <=  0.85 || new_y <=  0.85)
		return (true);
	return (false);
}