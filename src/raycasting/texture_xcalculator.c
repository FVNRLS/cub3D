/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_xcalculator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:31:59 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/07 16:21:38 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static double	calc_xcoord_east(t_ray *ray, t_data *data)
{
	double	dist_y;
	double	coord_y;
	double	x_coord_text;
	double	raylen;

	raylen = ray->sidedist[X] - ray->deltadist[X];
	dist_y = raylen * ray->raydir[Y];
	coord_y = data->player->y + dist_y;
	x_coord_text = coord_y - floor(coord_y);
	return (x_coord_text);
}

static double	calc_xcoord_west(t_ray *ray, t_data *data)
{
	double	dist_y;
	double	coord_y;
	double	x_coord_text;
	double	raylen;

	raylen = ray->sidedist[X] - ray->deltadist[X];
	dist_y = raylen * ray->raydir[Y];
	coord_y = data->player->y + dist_y;
	x_coord_text = ceil(coord_y) - coord_y;
	return (x_coord_text);
}

static double	calc_xcoord_north(t_ray *ray, t_data *data)
{
	double	dist_x;
	double	coord_x;
	double	x_coord_text;
	double	raylen;

	raylen = ray->sidedist[Y] - ray->deltadist[Y];
	dist_x = raylen * ray->raydir[X];
	coord_x = data->player->x + dist_x;
	x_coord_text = coord_x - floor(coord_x);
	return (x_coord_text);
}

static double	calc_xcoord_south(t_ray *ray, t_data *data)
{
	double	dist_x;
	double	coord_x;
	double	x_coord_text;
	double	raylen;

	raylen = ray->sidedist[Y] - ray->deltadist[Y];
	dist_x = raylen * ray->raydir[X];
	coord_x = data->player->x + dist_x;
	x_coord_text = ceil(coord_x) - coord_x;
	return (x_coord_text);
}

void	get_x_coord_texture(t_ray *ray, t_data *data)
{
	if (ray->side == 0 && ray->step[X] == 1)
		data->texture->text_xcoord = calc_xcoord_east(ray, data);
	else if (ray->side == 0)
		data->texture->text_xcoord = calc_xcoord_west(ray, data);
	else if (ray->side == 1 && ray->step[Y] == -1)
		data->texture->text_xcoord = calc_xcoord_north(ray, data);
	else
		data->texture->text_xcoord = calc_xcoord_south(ray, data);
}
