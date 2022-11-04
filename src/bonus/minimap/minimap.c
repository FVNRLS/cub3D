/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:45:19 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/04 18:38:25 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

static void	draw_minimap(t_data *data)
{
	int 	x;
	int 	y;
	double 	step;

	step = (double)data->minimap->size / MINIMAP_SCOPE;
	set_offset(data);
	y = 0;
	while (y < data->minimap->size)
	{
		x = 0;
		while (x < data->minimap->size)
		{
			if (check_wall(data, x, y, step) == true)
				mlx_put_pixel(data->minimap->img,x, y, NAVY);
			else
				mlx_put_pixel(data->minimap->img, x, y, 0xFFFFFF1A);
			x++;
		}
		y++;
	}
	draw_player(data, step);
	cast_rays(data, step);
}

void	update_minimap(t_data *data)
{
	if (data->minimap->img)
		mlx_delete_image(data->mlx, data->minimap->img);
	data->minimap->img = mlx_new_image(data->mlx, data->minimap->size,
									   data->minimap->size);
	draw_minimap(data);
	mlx_image_to_window(data->mlx, data->minimap->img, 0, 0);
}