/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:20:28 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/07 16:21:38 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	move(t_data *data, double angle)
{
	double	new_v[2];
	double	new_v_world[2];

	new_v[X] = STEP * data->player->x_scalar;
	new_v[Y] = STEP * data->player->y_scalar;
	rotate_vector(new_v, angle);
	new_v_world[X] = data->player->x + new_v[X];
	new_v_world[Y] = data->player->y + new_v[Y];
	if (check_collisions(data, new_v_world) == true)
		return ;
	data->player->x = new_v_world[X];
	data->player->y = new_v_world[Y];
}

void	check_move_keys(t_data *data, mlx_key_data_t keycode)
{
	if (keycode.key == MLX_KEY_W && (keycode.action == MLX_PRESS
			|| keycode.action == MLX_REPEAT))
		move(data, 0);
	else if (keycode.key == MLX_KEY_S
		&& (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT))
		move(data, M_PI);
	else if (keycode.key == MLX_KEY_A && (keycode.action == MLX_PRESS
			|| keycode.action == MLX_REPEAT))
		move(data, 1.5 * M_PI);
	else if (keycode.key == MLX_KEY_D && (keycode.action == MLX_PRESS
			|| keycode.action == MLX_REPEAT))
		move(data, 0.5 * M_PI);
}
