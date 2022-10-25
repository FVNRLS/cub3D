/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:02:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/25 15:40:45 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static void init_mlx_flags(t_data *data)
{
	data->gui->mlx = NULL;
	data->gui->win = NULL;
	data->gui->img = NULL;
	data->gui->addr = NULL;
}

static void init_gui_environment(t_data *data)
{
	data->gui->mlx = mlx_init();
	if (!data->gui->mlx)
	{
		print_int_error(MALLOC_ERROR, NULL);
		ft_free_all_and_exit(data);
	}
	data->gui->win = mlx_new_window(data->gui->mlx, WINSIZE, WINSIZE, "cub3D");
	if (!data->gui->win)
	{
		print_int_error(MALLOC_ERROR, NULL);
		ft_free_all_and_exit(data);
	}
	data->gui->img = mlx_new_image(data->gui->mlx, WINSIZE, WINSIZE);
	data->gui->addr = mlx_get_data_addr(data->gui->img,
	&data->gui->bits_per_pixel, &data->gui->line_length, &data->gui->endian);
	mlx_put_image_to_window(data->gui->mlx, data->gui->win, data->gui->img, 0, 0);
}

void	init_mlx(t_data *data)
{
	data->gui = malloc(sizeof(t_gui));
	if (!data->gui)
	{
		print_int_error(MALLOC_ERROR, NULL);
		ft_free_all_and_exit(data);
	}
	init_mlx_flags(data);
	init_gui_environment(data);
}