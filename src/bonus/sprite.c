/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:41:51 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/07 12:15:06 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_sprite_position(t_data *data)
{
	int	map_x;
	int	map_y;
	int	i;
	int	j;

	map_x = (int)data->player->x;
	map_y = (int)data->player->y;
	
	i = -1;
	while (i < 2)
	{
		printf("again\n");
		j = -1;
		while (j < 2)
		{
			printf("check map[%i][%i]\n", map_x + j, map_y + i);
			if (data->map[map_x + j][map_y + i] == '0' && !(i == 0 && j == 0))
			{
				printf("found at map[%i][%i]\n", map_x + j, map_y + i);
				data->map[map_x + j][map_y + i] = 'S';
				return ;
			}
			j++;
		}
		printf("here\n");
		i++;
		printf("i = %i\n", i);
	}
}

void	init_sprite(t_data *data)
{
	data->sprite.tex = mlx_load_xpm42("./textures/key.xpm42");
	if (!data->sprite.tex)
	{
		print_error(MALLOC_ERROR, NULL);
		free_all_resources(data);
		exit(EXIT_FAILURE);
	}
	data->sprite.collected = false;
	data->sprite.detected = false;
	set_sprite_position(data);
	// print_map(data);
}

void	sprite_collision(t_data *data, t_ray *ray, double camera_x)
{
	double	perp_dist;
	double	height;
	double	offset;

	if (data->sprite.detected == true)
		return ;
	// printf("sprite detected\n");
	if (ray->side == 0)
		perp_dist = ray->sidedist[X] - ray->deltadist[X];
	else
		perp_dist = ray->sidedist[Y] - ray->deltadist[Y];
	data->sprite.height = (data->img->height / perp_dist);
	data->sprite.start = (-1 * data->sprite.height) / 2 + data->img->height / 2;
	if (data->sprite.start < 0)
		data->sprite.start = 0;
	data->sprite.end = data->sprite.height / 2 + data->img->height / 2;
	if (data->sprite.end >= data->img->height)
		data->sprite.end = data->img->height - 1;
	data->sprite.detected = true;
}
