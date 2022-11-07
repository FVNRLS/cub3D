/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:34:26 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/07 15:16:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

bool	check_wall(t_data *data, int x, int y, double step)
{
	double	x_on_map;
	double	y_on_map;

	x_on_map = data->minimap->x_offset + (((double) x) / step);
	y_on_map = data->minimap->y_offset + (((double) y) / step);
	if ((x_on_map - round(x_on_map) < 0.03 && x_on_map - round(x_on_map) > -0.03))
		return (false);
    if ((y_on_map - round(y_on_map) < 0.03 && y_on_map - round(y_on_map) > -0.03))
		return (false);
	if (x_on_map >= data->tab->max_x)
		return (false);
	if (data->map[(int)x_on_map][(int)y_on_map] == '1')
		return (true);
	return (false);
}
