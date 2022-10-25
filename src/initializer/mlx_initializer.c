/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:02:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/25 17:20:35 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static void init_mlx_flags(t_data *data)
{
	data->mlx = NULL;
	data->img = NULL;
}

static void init_mlx_environment(t_data *data)
{
	mlx_t		mlx;
	mlx_image_t	img;

	data->mlx = &mlx;
	data->img = &img;
	mlx_set_setting(MLX_MAXIMIZED, true);
	data->mlx = mlx_init(WINSIZE, WINSIZE, "cub3D", true);
	if (!data->mlx)
	{
		print_int_error(MALLOC_ERROR, NULL);
		ft_free_all_and_exit(data);
	}
	data->img = mlx_new_image(data->mlx, WINSIZE, WINSIZE);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}

void	init_mlx(t_data *data)
{
//	data->mlx = malloc(sizeof(mlx_t));
//	if (!data->mlx)
//	{
//		print_int_error(MALLOC_ERROR, NULL);
//		ft_free_all_and_exit(data);
//	}
//	data->mlx = malloc(sizeof(mlx_image_t));
//	if (!data->img)
//	{
//		print_int_error(MALLOC_ERROR, NULL);
//		ft_free_all_and_exit(data);
//	}
//	init_mlx_flags(data);
	init_mlx_environment(data);
}