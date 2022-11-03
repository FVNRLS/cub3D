/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:45:19 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/01 18:02:49 by hoomen           ###   ########.fr       */
=======
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:45:19 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/03 12:00:00 by rmazurit         ###   ########.fr       */
>>>>>>> 38223a195207b3123184be0af43ee986b9edcdf4
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

<<<<<<< HEAD
static bool check_player_pos(t_data *data, int x, int y, double step)
{
	double h;
	double k;
	double r;
	double x_sqr;
	double y_sqr;

	r = (double) data->minimap->size / 80;
	h = (data->player->x - data->minimap->x_offset) * step;
	k = (data->player->y - data->minimap->y_offset) * step;
	x_sqr = (x - h) * (x - h);
	y_sqr = (y - k) * (y - k);
	if (x_sqr + y_sqr <= (r * r))
		return (true);
	return(false);
}

=======
>>>>>>> 38223a195207b3123184be0af43ee986b9edcdf4
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
<<<<<<< HEAD
			if (check_player_pos(data, x, y, step) == true)
				mlx_put_pixel(data->minimap->img, x, y, GREEN);
			else if (check_wall(data, x, y, step) == true)
=======
			if (check_wall(data, x, y, step) == true)
>>>>>>> 38223a195207b3123184be0af43ee986b9edcdf4
				mlx_put_pixel(data->minimap->img,x, y, NAVY);
			else
				mlx_put_pixel(data->minimap->img, x, y, 0xFFFFFF1A);
			x++;
		}
		y++;
	}
<<<<<<< HEAD
	//draw_player(data, step);
=======
	draw_player(data, step);
>>>>>>> 38223a195207b3123184be0af43ee986b9edcdf4
	cast_rays(data, step);
}

void	update_minimap(t_data *data)
{
<<<<<<< HEAD
	mlx_delete_image(data->mlx, data->minimap->img);
=======
	if (data->minimap->img)
		mlx_delete_image(data->mlx, data->minimap->img);
>>>>>>> 38223a195207b3123184be0af43ee986b9edcdf4
	data->minimap->img = mlx_new_image(data->mlx, data->minimap->size,
									   data->minimap->size);
	draw_minimap(data);
	mlx_image_to_window(data->mlx, data->minimap->img, 0, 0);
//	printf("angle: %d,		x_fact: %lf,	y_fact: %lf\n", data->player->angle, data->player->x_factor, data->player->y_factor);
	// printf("x: %lf,	y: %lf\n", data->player->x, data->player->y);

}