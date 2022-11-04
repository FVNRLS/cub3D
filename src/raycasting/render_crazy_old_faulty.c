/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:22:41 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/04 17:10:35 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_raydir(t_ray *ray, t_data *data, double camera_x)
{
		ray->raydir[X] = data->player->x_scalar + data->player->camplane[X] * camera_x;  // direction of the ray
		ray->raydir[Y] = data->player->y_scalar + data->player->camplane[Y] * camera_x;
}

void	get_mapcoords(t_ray *ray, t_data *data)
{
		ray->map[X] = (int)data->player->x; // current square the ray is in
		ray->map[Y] = (int)data->player->y;
}

void	get_deltas(t_ray *ray)
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

void	go_to_first_gridline(t_data *data, t_ray *ray)
{
	if (ray->raydir[X] < 0)
	{
		ray->step[X] = -1;
		ray->sidedist[X] = (data->player->x - ray->map[X]) * ray->deltadist[X];
	}
	else
	{
		ray->step[X] = 1;
		ray->sidedist[X] = (ray->map[X] + 1 - data->player->x) * ray->deltadist[X];
	}
	if (ray->raydir[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->sidedist[Y] = (data->player->y - ray->map[Y]) * ray->deltadist[Y];
	}
	else
	{
		ray->step[Y] = 1;
		ray->sidedist[Y] = (ray->map[Y] + 1 - data->player->y) * ray->deltadist[Y];
	}
}

void	calc_wall_dist(t_ray *ray, t_data *data, double camera_x)
{
	bool	hit;

	get_raydir(ray, data, camera_x);
	get_mapcoords(ray, data);
	get_deltas(ray);
	go_to_first_gridline(data, ray);
	hit = false;
	while (hit == false)
	{
		if (ray->sidedist[X] < ray->sidedist[Y])
		{
			ray->sidedist[X] += ray->deltadist[X];
			ray->map[X] += ray->step[X];
			ray->side = 0;
		}
		else
		{
			ray->sidedist[Y] += ray->deltadist[Y];
			ray->map[Y] += ray->step[Y];
			ray->side = 1;
		}
		if (data->map[ray->map[X]][ray->map[Y]] == '1')
			hit = true;
	}
}

void	get_textures(t_render *rend, t_ray *ray, t_data *data)
{
	if (ray->side == 0 && ray->raydir[X] < 0) // we hit west
		rend->wall_texture = RED;
	else if (ray->side == 0 && ray->raydir[X] >= 0) // we hit east
		rend->wall_texture = NAVY;
	else if (ray->side == 1 && ray->raydir[Y] < 0) // we hit north
		rend->wall_texture = SILVER;
	else // we hit south
		rend->wall_texture = GREEN;
}

void	get_render_info(t_render *rend, t_ray *ray, t_data *data)
{
	if (ray->side == 0)
		rend->perpwalldist = ray->sidedist[X] - ray->deltadist[X];
	else
		rend->perpwalldist = ray->sidedist[Y] - ray->deltadist[Y];
	rend->lineheight = (data->img->height / rend->perpwalldist);
	rend->wallstart = (-1 * rend->lineheight) / 2 + data->img->height / 2;
	if (rend->wallstart < 0)
		rend->wallstart = 0;
	rend->wallend = rend->lineheight / 2 + data->img->height / 2;
	if (rend->wallend >= data->img->height)
		rend->wallend = data->img->height - 1;
	get_textures(rend, ray, data);
}

void	drawverline(t_data *data, t_render *rend, int x)
{
	int	y;
	int	h;

	y = -1;
	h = data->img->height;
	while (++y < rend->wallstart)
		mlx_put_pixel(data->img, x, y, 255);
	while (++y < rend->wallend)
		mlx_put_pixel(data->img, x, y, rend->wall_texture);
	while (++y < h)
		mlx_put_pixel(data->img, x, y, 255);
}

void	draw_frame(t_data *data)
{
	int			x;
	double		camera_x;
	t_ray		ray;
	t_render	rend;
	
	x = 0;
	while (x < data->img->width)
	{
		camera_x = 2 * x / data->img->width - 1;
		calc_wall_dist(&ray, data, camera_x);
		get_render_info(&rend, &ray, data);
		drawverline(data, &rend, x);
		x++;
	}
}

void	render(t_data *data)
{
	mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->img->width, data->img->height);
	draw_frame(data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
