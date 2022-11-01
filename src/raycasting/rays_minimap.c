/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:36:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/01 20:12:36 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/cub3D.h"

static void	angle_to_scalars(t_data *data)
{
	data->player->x_scalar = sin(data->player->angle);
	data->player->y_scalar = cos(data->player->angle);
}

static int	cast_ray_world_to_map(double offset, double ray, double step)
{
	double	ray_on_screen;

	ray_on_screen = (ray - offset) * step;
	return ((int)round(ray_on_screen));
}

static void	cast_ray(t_data *data, double step)
{
	double	cam[2];
	double	factor;
	double	ray[2];
	int		pixel[2];

	cam[X] = data->player->x;
	cam[Y] = data->player->y;
	factor = 0.01;
	while (1)
	{
		ray[X] = cam[X] + (data->player->x_scalar * factor);
		ray[Y] = cam[Y] - (data->player->y_scalar * factor);
		if (data->map[(int)ray[X]][(int)ray[Y]] == '1')
			break ;
		pixel[X] = cast_ray_world_to_map(data->minimap->x_offset, ray[X], step);
		pixel[Y] = cast_ray_world_to_map(data->minimap->y_offset, ray[Y], step);
		if (pixel[X] >= data->minimap->size || pixel[Y] >= data->minimap->size
			|| pixel[X] < 1 || pixel[Y] < 1)
			break ;
		mlx_put_pixel(data->minimap->img, pixel[X], pixel[Y], RED);
		factor += 0.01;
	}
}

void	cast_rays(t_data *data, double step)
{
	// double	player_angle;
	// double	step_angle;

	// player_angle = data->player->angle;

	// step_angle = (0.4 * M_PI) / 10;
	// data->player->angle -= 0.2 * M_PI;
	// while (data->player->angle <= player_angle + 0.2 * M_PI)
	// {
	// 	angle_to_scalars(data);
	// 	cast_ray(data, step);
	// 	data->player->angle += step_angle;
	// }
	// data->player->angle = player_angle;
	// angle_to_scalars(data);
	cast_ray(data, step);
}
