/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:02:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/03 13:25:22 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

void	init_mlx(t_data *data)
{
	mlx_t		mlx;
	mlx_image_t	img;

	data->mlx = &mlx;
	data->img = &img;
	mlx_set_setting(MLX_MAXIMIZED, true);
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!data->mlx)
	{
		print_int_error(MALLOC_ERROR, NULL);
		ft_free_all_and_exit(data);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
