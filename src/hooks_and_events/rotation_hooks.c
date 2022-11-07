/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:25:08 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/07 20:52:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate(t_data *data, int direction)
{
	double	new_angle;
	double	scal[2];
	double	dir[2];
	double	plane[2];
	double	oldscal_x;
	double	oldplane_x;
	double	rot;

	rot = direction * ROTATION_RADIANS;
	oldscal_x = data->player->x_scalar;
	scal[X] = oldscal_x;
	scal[Y] = data->player->y_scalar;
	plane[X] = data->player->camplane[X];
	plane[Y] = data->player->camplane[Y];
	scal[X] = scal[X] * cos(rot) - scal[Y] * sin(rot);
	scal[Y] = oldscal_x * sin(rot) + scal[Y] * cos(rot);
	oldplane_x = plane[X];
	plane[X] = plane[X] * cos(rot) - plane[Y] * sin(rot);
	plane[Y] = oldplane_x * sin(rot) + plane[Y] * cos(rot);
	

	// new_angle = data->player->angle + direction * ROTATION_RADIANS;
	// if (new_angle < 0)
	// 	data->player->angle = 2 * M_PI + new_angle;
	// else if (new_angle >= 2 * M_PI)
	// 	data->player->angle = new_angle - 2 * M_PI;
	// else
	// 	data->player->angle = new_angle;
	// data->player->x_scalar = sin(data->player->angle);
	// data->player->y_scalar = -1 * cos(data->player->angle);
	// data->player->camplane[X] = -1 * FOV * data->player->y_scalar;
	// data->player->camplane[Y] = FOV * data->player->x_scalar;
	render(data);
	update_minimap(data);
}

void	check_rotation_keys(t_data *data, mlx_key_data_t keycode)
{
	if (keycode.key == MLX_KEY_LEFT && (keycode.action == MLX_PRESS
			|| keycode.action == MLX_REPEAT))
		rotate(data, ROTATE_LEFT);
	else if (keycode.key == MLX_KEY_RIGHT && (keycode.action == MLX_PRESS
			|| keycode.action == MLX_REPEAT))
		rotate(data, ROTATE_RIGHT);
}
