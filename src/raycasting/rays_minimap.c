/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:36:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/06 15:23:19 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/cub3D.h"

static int	cast_ray_world_to_map(double offset, double ray, double step)
{
	double	ray_on_screen;

	ray_on_screen = (ray - offset) * step;
	return ((int)round(ray_on_screen));
}

void	cast_rays(t_data *data, double step)
{
	double	cam[2];
	double	factor;
	double	ray[2];
	int		pixel[2];

	cam[X] = data->player->x;
	cam[Y] = data->player->y;
	factor = 0.01;
	while (factor < 0.3)
	{
		ray[X] = cam[X] + (data->player->x_scalar * factor);
		ray[Y] = cam[Y] + (data->player->y_scalar * factor);
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
