/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 movement_hooks.c									:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: hoomen	<hoomen@student.42.fr>				+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2022/10/26 17:03:54 by rmazurit		   #+#	  #+#			  */
/*	 Updated: 2022/10/30 18:24:55 by hoomen			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

void	move_lateral(t_data *data, double angle)
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
	render(data);
	update_minimap(data);
}

void	check_move_keys(t_data *data, mlx_key_data_t keycode)
{
	if (keycode.key	== MLX_KEY_W &&	(keycode.action	== MLX_PRESS
		|| keycode.action == MLX_REPEAT))
		move_lateral(data, 0);
	else if	(keycode.key ==	MLX_KEY_S && (keycode.action ==	MLX_PRESS
		|| keycode.action == MLX_REPEAT))
		move_lateral(data, M_PI);
	else if	(keycode.key ==	MLX_KEY_A && (keycode.action ==	MLX_PRESS
		|| keycode.action == MLX_REPEAT))
		move_lateral(data, 1.5 * M_PI);
	else if	(keycode.key ==	MLX_KEY_D && (keycode.action ==	MLX_PRESS
		|| keycode.action == MLX_REPEAT))
		move_lateral(data, 0.5 * M_PI);
}
