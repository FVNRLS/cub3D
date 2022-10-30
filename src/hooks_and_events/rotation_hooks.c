/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:49:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/10/30 19:50:14 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static void	rotate_left(t_data *data)
{
	int	tmp;

	tmp	= data->player->angle -	ROTATION_MOD;
	if (tmp	< 0)
		data->player->angle	= 360 +	tmp;
	else
		data->player->angle	= tmp;
	printf("angle: %i\n", data->player->angle);
}

static void	rotate_right(t_data	*data)
{
	int	tmp;

	tmp	= data->player->angle +	ROTATION_MOD;
	if (tmp	> 359)
		data->player->angle	= tmp -	360;
	else
		data->player->angle	= tmp;
	printf("angle: %i\n", data->player->angle);
}

void	check_rotation_keys(t_data *data, mlx_key_data_t keycode)
{
	if (keycode.key	== MLX_KEY_LEFT	&& (keycode.action == MLX_PRESS
	||	keycode.action == MLX_REPEAT))
		rotate_left(data);
	else if	(keycode.key ==	MLX_KEY_RIGHT && (keycode.action == MLX_PRESS
		|| keycode.action == MLX_REPEAT))
		rotate_right(data);
}
