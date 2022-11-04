/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:49:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/04 17:27:17 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static void	rotate(t_data *data, int direction)
{
	double	new_angle;

	new_angle = data->player->angle + direction * ROTATION_RADIANS;
	if (new_angle < 0)
		data->player->angle = 2 * M_PI + new_angle;
	else if (new_angle >= 2 * M_PI)
		data->player->angle = new_angle - 2 * M_PI;
	else
		data->player->angle = new_angle;
	data->player->x_scalar = sin(data->player->angle);
	data->player->y_scalar = -1 * cos(data->player->angle);
	data->player->camplane[X] = data->player->x_scalar;
	data->player->camplane[Y] = data->player->y_scalar;
	rotate_vector(data->player->camplane, 0.5 * M_PI);
	render(data);
	update_minimap(data);
}

void	check_rotation_keys(t_data *data, mlx_key_data_t keycode)
{
	if (keycode.key	== MLX_KEY_LEFT	&& (keycode.action == MLX_PRESS
	||	keycode.action == MLX_REPEAT))
		rotate(data, ROTATE_LEFT);
	else if	(keycode.key ==	MLX_KEY_RIGHT && (keycode.action == MLX_PRESS
		|| keycode.action == MLX_REPEAT))
		rotate(data, ROTATE_RIGHT);
}
 