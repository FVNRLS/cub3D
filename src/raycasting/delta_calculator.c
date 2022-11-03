/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:06:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/03 12:11:34 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static double	get_next_gridline(double scalar, double ray_pos)
{
	if (scalar == 0)
		return ((double)INT_MAX);
	if (ray_pos == floor(ray_pos))
	{
		if (scalar < 0)
			return ((int)floor(ray_pos) - 1);
		return ((int)floor(ray_pos) + 1);
	}
	if (scalar < 0)
		return ((int)floor(ray_pos));
	return ((int)ceil(ray_pos));
}

static double	dist_to_next_gridline(double ray_pos, double next_gridline)
{
	double	dist;

	dist = ray_pos - next_gridline;
	if (dist < 0)
		return (dist * -1);
	return (dist);
}

double	get_delta(double scalar, double ray_pos)
{
	double	next_gridline;
	double	dist_straight;

	if (scalar == 0)
		return (DBL_MAX);
	next_gridline = get_next_gridline(scalar, ray_pos);
	dist_straight = dist_to_next_gridline(ray_pos, next_gridline);
	return (ft_abs_dbl(dist_straight / scalar));
}

void	move_delta(t_data *data, t_ray *ray, double delta)
{
	ray->ray_pos[X] = ray->ray_pos[X] + delta * data->player->x_scalar;
	ray->ray_pos[Y] = ray->ray_pos[Y] + delta * data->player->y_scalar;
}
