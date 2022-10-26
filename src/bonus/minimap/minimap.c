/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:45:19 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/26 16:50:40 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

static bool check_player_pos(t_data *data, int x, int y)
{
	int h;
	int k;
	int r;
	int x_sqr;
	int y_sqr;


	r = data->minimap->width / 80;

	h = data->minimap->width / 2;
	k = data->minimap->height / 2;

	x_sqr = (x - h) * (x - h);
	y_sqr = (y - k) * (y - k);
	if (x_sqr + y_sqr <= (r * r))
		return (true);
	return(false);
}

static void	draw_minimap_background(t_data *data)
{
	int x;
	int y;




	y = 0;
	while (y < data->minimap->height)
	{
		x = 0;
		while (x < data->minimap->width)
		{
			if (check_player_pos(data, x, y) == true)
				mlx_put_pixel(data->minimap->img, x, y, 0x00FF00FF);
			else
				mlx_put_pixel(data->minimap->img, x, y, 0xFFFFFF1A);
			x++;
		}
		y++;
	}
}

void	update_minimap(t_data *data)
{
	draw_minimap_background(data);
	mlx_image_to_window(data->mlx, data->minimap->img, 0, 0);
}