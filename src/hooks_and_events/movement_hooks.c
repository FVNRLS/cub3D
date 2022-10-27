/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:03:54 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/27 16:50:47 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static void	move_right(t_data *data)
{
	data->player->x_factor = sin(ft_degree_to_radian(data->player->angle + 90));
	data->player->y_factor = -1 * cos(ft_degree_to_radian(data->player->angle + 90));
	if (check_collisions(data) == true)
		return ;
	data->player->x += data->player->x_factor;
	data->player->y += data->player->y_factor;
	update_minimap(data);
}

static void	move_left(t_data *data)
{
	data->player->x_factor =  sin(ft_degree_to_radian(data->player->angle - 90));
	data->player->y_factor = -1 * cos(ft_degree_to_radian(data->player->angle - 90));
	if (check_collisions(data) == true)
		return ;
	data->player->x += data->player->x_factor;
	data->player->y += data->player->y_factor;
	update_minimap(data);
}

static void	move_backward(t_data *data)
{
	data->player->x_factor = -1 * sin(ft_degree_to_radian(data->player->angle));
	data->player->y_factor = cos(ft_degree_to_radian(data->player->angle));
	if (check_collisions(data) == true)
		return ;
	data->player->x += data->player->x_factor;
	data->player->y += data->player->y_factor;
	update_minimap(data);
}



/*
 * 	+-------------+-------------+-------------+
	|Angle 	  	  | x (cos)		| y (sin)	  |
	+-------------+-------------+-------------+
	| 0 - 90      | +   		| +			  |
	+-------------+-------------+-------------+
	| 90 - 180 	  | +   		| - 		  |
	+-------------+-------------+-------------+
	| 180 - 270   | -  			| -			  |
 	+-------------+-------------+-------------+
	| 270 - 360	  | -   		| + 		  |
	+-------------+-------------+-------------+
 * */
static void	move_forward(t_data *data)
{
	data->player->x_factor = sin(ft_degree_to_radian(data->player->angle));
	data->player->y_factor = -1 * cos(ft_degree_to_radian(data->player->angle));
	if (check_collisions(data) == true)
		return ;
	data->player->x = data->player->x + data->player->x_factor;
	data->player->y = data->player->y + data->player->y_factor;
	update_minimap(data);
}

void	check_move_keys(t_data *data, mlx_key_data_t keycode)
{
	if (keycode.key == MLX_KEY_W && keycode.action == MLX_PRESS)
		move_forward(data);
	else if (keycode.key == MLX_KEY_S && keycode.action == MLX_PRESS)
		move_backward(data);
	else if (keycode.key == MLX_KEY_A && keycode.action == MLX_PRESS)
		move_left(data);
	else if (keycode.key == MLX_KEY_D && keycode.action == MLX_PRESS)
		move_right(data);
}