/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:34:26 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/27 16:10:58 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

bool	check_wall(t_data *data, int x, int y)
{

	double	x_scal;
	double	y_scal;
	double 	x_round;
	double 	y_round;

	x_scal = ((double)x * ((double) MINIMAP_SCOPE / (double) data->minimap->width));
	y_scal = ((double)y * ((double) MINIMAP_SCOPE / (double) data->minimap->height));
	x_round = round(x_scal);
	y_round = round(y_scal);
	if ((x_scal - x_round < 0.03 && x_scal - x_round > -0.03))
		return (false);
	if ((y_scal - y_round < 0.03 && y_scal - y_round > -0.03))
		return (false);
	x = data->minimap->x_offset + (int)x_round;
	y = data->minimap->y_offset + (int)y_round;
	if (x < 0 || y < 0 || x >= data->tab->max_x || y >= data->tab->max_y)
		return (false);
	if (data->map[x][y] == '1')
		return (true);
	return (false);
}



