/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:22:41 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/04 14:03:15 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_raydir(t_render *rend, t_data *data, int camera_x)
{
		rend->raydir[X] = data->player->x_scalar + data->player->camplane[X] * camera_x;  // direction of the ray
		rend->raydir[Y] = data->player->y_scalar + data->player->camplane[Y] * camera_x;
}

void	get_mapcoords(t_render *rend, t_data *data)
{
		rend->map[X] = (int)data->player->x; // current square the ray is in
		rend->map[Y] = (int)data->player->y;
}

void	get_deltas(t_render *rend)
{
	if (rend->raydir[X] == 0)
		rend->deltadist[X] = DBL_MAX;
	else
		rend->deltadist[X] = ft_abs_dbl(1 / rend->raydir[X]);
	if (rend->raydir[Y] == 0)
		rend->deltadist[Y] = DBL_MAX;
	else
		rend->deltadist[Y] = ft_abs_dbl(1 / rend->raydir[Y]);
}

void	draw_frame(t_data *data)
{
	int			x;
	int			w;
	int			camera_x;
	t_render	rend;
	
	x = 0;
	w = data->img->width;
	while (x < data->img->width)
	{
		camera_x = 2 * x / w - 1;
		get_raydir(&rend, data, camera_x);
		get_mapcoords(&rend, data);
		get_deltas(&rend);
	}
}


void	render(t_data *data)
{
	mlx_delete_image(data->mlx, data->img);
	draw_frame(data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}