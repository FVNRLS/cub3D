/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:41:51 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/06 22:19:42 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	check_invalid_void_spaces(t_data *data)
// {
// 	int 	x;
// 	int 	y;
// 	int 	ret;

// 	y = 0;
// 	ret = 0;
// 	while (y < (data->tab->max_y))
// 	{
// 		x = 0;
// 		while (x < data->tab->max_x)
// 		{
// 			if (data->map[x][y] == VOID)
// 				ret = check_item(data, x, y);
// 			if (ret == EXIT_FAILURE)
// 				return ;
// 			x++;
// 		}
// 		y++;
// 	}
// }

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
	print_map(data);
}

void	draw_sprite(t_data *data)
{
	mlx_image_t *spritimg;

	if (data->sprite.detected == false || data->sprite.collected == true)
		return ;
	printf("I will print sprite\n");
	spritimg = mlx_texture_to_image(data->mlx, &data->sprite.tex->texture);
	mlx_image_to_window(data->mlx, spritimg, data->img->width / 2, data->img->height / 2);
}
