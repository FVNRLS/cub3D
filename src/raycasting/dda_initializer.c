/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:30:42 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/07 15:33:02 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	get_raydir(t_ray *ray, t_data *data, double camera_x)
{
		ray->raydir[X] = data->player->x_scalar + \
		data->player->camplane[X] * camera_x;
		ray->raydir[Y] = data->player->y_scalar + \
		data->player->camplane[Y] * camera_x;
}

static void	get_mapcoords(t_ray *ray, t_data *data)
{
	ray->map[X] = (int)data->player->x;
	ray->map[Y] = (int)data->player->y;
}

static void	get_deltas(t_ray *ray)
{
	if (ray->raydir[X] == 0)
		ray->deltadist[X] = DBL_MAX;
	else
		ray->deltadist[X] = ft_abs_dbl(1 / ray->raydir[X]);
	if (ray->raydir[Y] == 0)
		ray->deltadist[Y] = DBL_MAX;
	else
		ray->deltadist[Y] = ft_abs_dbl(1 / ray->raydir[Y]);
}

static void	go_to_first_gridline(t_data *data, t_ray *ray)
{
	if (ray->raydir[X] < 0)
	{
		ray->step[X] = -1;
		ray->sidedist[X] = (data->player->x - ray->map[X]) \
		* ray->deltadist[X];
	}
	else
	{
		ray->step[X] = 1;
		ray->sidedist[X] = (ray->map[X] + 1 - data->player->x) \
		* ray->deltadist[X];
	}
	if (ray->raydir[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->sidedist[Y] = (data->player->y - ray->map[Y]) \
		* ray->deltadist[Y];
	}
	else
	{
		ray->step[Y] = 1;
		ray->sidedist[Y] = (ray->map[Y] + 1 - data->player->y) \
		* ray->deltadist[Y];
	}
}

void	init_dda(t_data *data, t_ray *ray, double camera_x)
{
	get_raydir(ray, data, camera_x);
	get_mapcoords(ray, data);
	get_deltas(ray);
	go_to_first_gridline(data, ray);
}
