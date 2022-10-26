/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:03:54 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/26 17:39:09 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static void	move_forward(t_data *data, mlx_key_data_t keycode)
{

}

double	degree_to_radian(double angle)
{
	return (angle * M_PI / 180.0);
}

void	check_move_keys(t_data *data,  mlx_key_data_t keycode)
{
	data->player->x_factor = cos(degree_to_radian(data->player->angle));
	data->player->y_factor = -1 * sin(degree_to_radian(data->player->angle));
//	if (keycode.key == MLX_KEY_ESCAPE && keycode.action == MLX_PRESS)
//		move_forward();
//	else if (keycode == S)
//		move_backwards();
//	else if (keycode == A)
//		move_left();
//	else if (keycode == D)
//		move_right();
}