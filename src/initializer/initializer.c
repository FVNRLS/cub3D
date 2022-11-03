/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:30:02 by rmazurit          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/30 17:39:13 by hoomen           ###   ########.fr       */
=======
/*   Updated: 2022/11/03 10:52:56 by rmazurit         ###   ########.fr       */
>>>>>>> 38223a195207b3123184be0af43ee986b9edcdf4
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static void init_flags(t_data *data)
{
	data->parse_error = false;
	data->map_parsed = false;
}

/*	Init map to contain 2D array and player */
static void init_map(t_data *data)
{
	data->tab = malloc(sizeof(t_tab));
	if (!data->tab)
	{
		print_int_error(MALLOC_ERROR, NULL);
		ft_free_all_and_exit(data);
	}
	data->map = NULL;
	data->tab->buf = NULL;
	data->tab->map = NULL;
	data->tab->max_x = 0;
	data->tab->max_y = 1;

	data->player = malloc(sizeof(t_player));
	if (!data->player)
	{
		print_int_error(MALLOC_ERROR, NULL);
		ft_free_all_and_exit(data);
	}
	data->player->x = -1;
	data->player->y = -1;
	data->player->dir = VOID;
}

void	init_environment(t_data *data)
{
	init_flags(data);
	init_map_objects(data);
	init_map(data);
	init_mlx(data);
}