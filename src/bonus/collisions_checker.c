/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:39:50 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/31 19:37:47 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static void	set_offset_x_pos(t_data *data)
{
	if (data->minimap->x_offset + MINIMAP_SCOPE > data->tab->max_x)
		data->minimap->x_offset = data->tab->max_x - MINIMAP_SCOPE;
	if (data->minimap->x_offset < 0)
		data->minimap->x_offset = 0;
}

static void	set_offset_y_pos(t_data *data)
{
	if (data->minimap->y_offset + MINIMAP_SCOPE > data->tab->max_y)
		data->minimap->y_offset = data->tab->max_y - MINIMAP_SCOPE;
	if (data->minimap->y_offset < 0)
		data->minimap->y_offset = 0;
}

void	set_offset(t_data *data)
{
	data->minimap->x_offset = (int)data->player->x - MINIMAP_SCOPE / 2;
	data->minimap->y_offset = (int)data->player->y - MINIMAP_SCOPE / 2;
	set_offset_x_pos(data);
	set_offset_y_pos(data);
}

bool	check_collisions(t_data *data, double new_v[2])
{
    if (data->map[(int)new_v[X]][(int)new_v[Y]] == '1')
        return (true);
	return (false);
}