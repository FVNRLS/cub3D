/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:26:19 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/01 14:24:36 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

void	draw_player(t_data *data, double step)
{
	double	cam[2];
	int		pos[2];
	double	r;
	double	x_sqr;
	double	y_sqr;

	r = (double) data->minimap->size / 80;
	cam[X] = (data->player->x - data->minimap->x_offset) * step;
	cam[Y] = (data->player->y - data->minimap->y_offset) * step;
	pos[Y] = (int)(cam[Y] - r);
	while (pos[Y] < (cam[Y] + r))
	{
		pos[X] = (int)(cam[X] - r);
		while (pos[X] < (cam[X] + r))
		{
			x_sqr = (pos[X] - cam[X]) * (pos[X] - cam[X]);
			y_sqr = (pos[Y] - cam[Y]) * (pos[Y] - cam[Y]);
			if (x_sqr + y_sqr < (r * r))
				mlx_put_pixel(data->img, pos[X], (pos[Y]), GREEN);
			pos[X]++;
		}
		pos[Y]++;
	}
}