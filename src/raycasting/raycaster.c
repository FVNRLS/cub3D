/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:45:54 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/03 17:55:33 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

double	raycaster_loop(t_data *data)
{
	bool	hit;
	t_ray	ray;
	double	delta[2];

	hit = false;
	ray.ray_pos[X] = data->player->x;
	ray.ray_pos[Y] = data->player->y;
	printf("ray_pos[X] = %lf, ray_pos[Y] = %lf\n", ray.ray_pos[X], ray.ray_pos[Y]);
	while (hit == false)
	{
		delta[X] = get_delta(data->player->x_scalar, ray.ray_pos[X]);
		delta[Y] = get_delta(data->player->y_scalar, ray.ray_pos[Y]);
		if (delta[X] < delta[Y])
		{
			move_delta(data, &ray, delta[X]);
			hit = check_hit_vertical(data, &ray);
		}
		else
		{
			move_delta(data, &ray, delta[Y]);
			hit = check_hit_horizontal(data, &ray);
		}
		printf("wall is hit at: x = %lf, y = %lf\n", ray.ray_pos[X], ray.ray_pos[Y]);
	}
	//printf("wall is hit at: x = %lf, y = %lf\n", ray.ray_pos[X], ray.ray_pos[Y]);
	return (0);
	// return the distance from the player's eye to the first collision
	// return (ray.ray_pos[X] / data->player->x_scal);

	// yDist = ray->ray_pos[Y] - data->player->y;
	// xDist = ray->ray_pos[X] - data->player->x;
	// Euclidian = yDist / data->player->y_scal;
}
