/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:34:26 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/28 13:06:45 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

bool	check_wall(t_data *data, int x, int y, double step)
{

//	double	x_scal;
//	double	y_scal;
//	double 	x_round;
//	double 	y_round;

//	x_scal = ((double)x * ((double) MINIMAP_SCOPE / (double) data->minimap->size));
//	y_scal = ((double)y * ((double) MINIMAP_SCOPE / (double) data->minimap->size));
//	x_round = round(x_scal);
//	y_round = round(y_scal);
//	if ((x_scal - x_round < 0.03 && x_scal - x_round > -0.03))
//		return (false);
//	if ((y_scal - y_round < 0.03 && y_scal - y_round > -0.03))
//		return (false);
//	x = data->minimap->x_offset + (int)x_round;
//	y = data->minimap->y_offset + (int)y_round;
	double     x_on_map;
	double     y_on_map;

	x_on_map = data->minimap->x_offset + (((double) x) / step);
	y_on_map = data->minimap->y_offset + (((double) y) / step);
//	printf("x_on_map = %d\n", x_on_map);
//	printf("y_on_map = %d\n", y_on_map);
//	printf("object at data->map[%d][%d] = %c\n", x_on_map, y_on_map, data->map[x_on_map][y_on_map]);

//	if (x < 0 || y < 0 || x >= data->tab->max_x || y >= data->tab->max_y)
//		return (false);
//	if (data->map[x][y] == '1')
//		return (true);
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



