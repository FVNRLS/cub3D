/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:05:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/26 18:14:48 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

/*
	Compare the input keycode with keys (I, C, K, H)
 	If there is a match:
 	Print the appropriate information to the stdout.
*/
void	check_esc_key(t_data *data, mlx_key_data_t keycode)
{
	if (keycode.key == MLX_KEY_ESCAPE && keycode.action == MLX_PRESS)
	{
		free_all_resources(data);
		exit(EXIT_SUCCESS);
	}
}

void 	check_key_hooks(mlx_key_data_t keycode, void *param)
{
	t_data *data;

	data = (t_data*)param;

	check_move_keys(data, keycode);
	check_rotation_keys(data, keycode);
	check_esc_key(data, keycode);
}