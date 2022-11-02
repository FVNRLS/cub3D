/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:45:54 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/02 16:04:45 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

double	next_gridline(double scalar, double ray_pos)
{
	if (scalar == 0)
		return ((double)INT_MAX);
	if (scalar < 0)
		return ((int)floor(ray_pos));
	return ((int)ceil(ray_pos));
}

double	dist_to_next_gridline(double ray_pos, double next_gridline)
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
	next_gridline = next_gridline(scalar, ray_pos);
	dist_straight = dist_to_next_gridline(ray_pos, next_gridline);
	return (dist_straight / scalar);
}

void	move_delta(t_data *data, t_ray *ray, double delta)
{
	ray->ray_pos[X] = ray->ray_pos[X] + delta * data->player->x_scalar;
	ray->ray_pos[Y] = ray->ray_pos[Y] + delta * data->player->y_scalar;
}

int		get_check_field(double ray_pos, double scalar)
{
	if (scalar == 0)
		return (INT_MAX);
	if (scalar < 0)
		return ((int)floor(ray_pos) - 1);
	return ((int)ceil(ray_pos));
}

bool	check_hit(t_data *data, t_ray *ray)
{
	int	check_field[2];

	check_field[X] = get_check_field(ray->ray_pos[X], data->player->x_scalar);
	check_field[Y] = get_check_field(ray->ray_pos[Y], data->player->y_scalar);
	if (check_field[X] < 0 || check_field[Y] < 0)
		return (false);
	if (check_field[X] >= data->tab->max_x || check_field[Y] >= data->tab->max_y)
		return (false);
	if (data->map[[check_field[X]]][check_fieldd[Y]] == '1')
		return (true);
	return (false);
}

void	raycaster_loop(t_data *data)
{
	bool	hit;
	t_ray	ray;
	double	delta[2];

	hit = false;
	ray.ray_pos[X] = data->player->x;
	ray.ray_pos[Y] = data->player->y;
	while (!hit)
	{
		delta[X] = get_delta(data->player->x_scalar, ray.ray_pos[X]);
		delta[Y] = get_delta(data->player->y_scalar, ray.ray_pos[Y]);
		if (delta[X] < delta[Y])
			move_delta_x(data, &ray, delta[X]);
		else
			move_delta_y(data, &ray, delta[Y]);
		hit = check_hit(data, &ray);
	}
}
