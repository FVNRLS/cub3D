/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:36:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/10/31 22:02:48 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/cub3D.h"

bool	check_first_ray(t_data *data, int x, int y, double step)
{
	double	player_on_screen[2];
	double	ray_v[2];
	double	factor[2];
	double	diff[2];

	player_on_screen[X] = (data->player->x - data->minimap->x_offset) * step;
	player_on_screen[Y] = (data->player->y - data->minimap->y_offset) * step;
	ray_v[Y] = (double)y - player_on_screen[Y];
	ray_v[X] = (double)x - player_on_screen[X];
	factor[Y] = -1 * (ray_v[Y] / data->player->y_scalar);
	// factor[X] = -1 * (ray_v[X] / data->player->x_scalar);
	if (factor[Y] < 0)// || factor[X] > 0)
		return (false);
	diff[X] = ray_v[X] - data->player->x_scalar * factor[Y];
	// diff[Y] = ray_v[Y] - data->player->y_scalar * factor[X];
	if (diff[X] < 0.5 && diff[X] > -0.5)
		return (true);
	// if (diff[Y] < 0.3 && diff[Y] > -0.3)
		// return (true);
	return (false);
}
