/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:05:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/06 19:50:58 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_esc_key(t_data *data, mlx_key_data_t keycode)
{
	if (keycode.key == MLX_KEY_ESCAPE && keycode.action == MLX_PRESS)
	{
		free_all_resources(data);
		exit(EXIT_SUCCESS);
	}
}

static void	check_mouse_keys(t_data *data, mlx_key_data_t keycode)
{
	if (keycode.key == MLX_KEY_H && keycode.action == MLX_PRESS)
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	else if (keycode.key == MLX_KEY_M && keycode.action == MLX_PRESS)
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_NORMAL);
}

void 	check_key_hooks(mlx_key_data_t keycode, void *param)
{
	t_data *data;

	data = (t_data*)param;
	check_move_keys(data, keycode);
	check_rotation_keys(data, keycode);
	check_mouse_keys(data, keycode);
	check_esc_key(data, keycode);
}
