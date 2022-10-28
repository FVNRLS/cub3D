/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:45:19 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/28 11:14:29 by rmazurit         ###   ########.fr       */
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

	r = data->minimap->size / 80;
	h = data->minimap->x_player;
	k = data->minimap->y_player;
	x_sqr = (x - h) * (x - h);
	y_sqr = (y - k) * (y - k);
	if (x_sqr + y_sqr <= (r * r))
		return (true);
	return(false);
}

static void	draw_minimap(t_data *data)
{
	int x;
	int y;


	set_offset(data);
	y = 0;
	while (y < data->minimap->size)
	{
		x = 0;
		while (x < data->minimap->size)
		{
			if (check_player_pos(data, x, y) == true)
				mlx_put_pixel(data->minimap->img, x, y, GREEN);
			else if (check_wall(data, x, y) == true)
				mlx_put_pixel(data->minimap->img,x, y, NAVY);
			else
				mlx_put_pixel(data->minimap->img, x, y, 0xFFFFFF1A);
			x++;
		}
		y++;
	}
}

void	update_minimap(t_data *data)
{
	mlx_delete_image(data->mlx, data->minimap->img);
	data->minimap->img = mlx_new_image(data->mlx, data->minimap->size,
									   data->minimap->size);
	draw_minimap(data);
	mlx_image_to_window(data->mlx, data->minimap->img, 0, 0);
//	printf("angle: %d,		x_fact: %lf,	y_fact: %lf\n", data->player->angle, data->player->x_factor, data->player->y_factor);
	printf("x: %lf,	y: %lf\n", data->player->x, data->player->y);

}