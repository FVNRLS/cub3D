/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:05:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/03 21:15:25 by hoomen           ###   ########.fr       */
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

void	check_keys_debugging(t_data *data, mlx_key_data_t keycode)
{
	if (keycode.key == MLX_KEY_I && keycode.action == MLX_PRESS)
	{
		printf("player->x = %lf, player->y = %lf\n", data->player->x, data->player->y);
		printf("player->angle = %i\n", (int) round(360 * data->player->angle / (2 * M_PI)));
	}
	if (keycode.key == MLX_KEY_R && keycode.action == MLX_PRESS)
		cast(data);
		// raycaster_loop(data);

}
void 	check_key_hooks(mlx_key_data_t keycode, void *param)
{
	t_data *data;

	data = (t_data*)param;

	check_move_keys(data, keycode);
	check_rotation_keys(data, keycode);
	check_esc_key(data, keycode);
	check_keys_debugging(data, keycode);
}