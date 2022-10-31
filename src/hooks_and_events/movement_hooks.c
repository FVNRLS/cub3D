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

void	move_lateral(t_data *data, int direction)
{
	double	new_v[2];
	double	new_v_world[2];
	double	mv_left[2][2] = {{0, 1}, {-1, 0}};
	double	mv_right[2][2] = {{0, -1}, {1, 0}};

	new_v[X] = STEP * data->player->x_scalar;
	new_v[Y] = STEP * data->player->y_scalar;
	if (direction == MV_RIGHT)
		linear_transformation2d(new_v, mv_right);
	if (direction == MV_LEFT)
		linear_transformation2d(new_v, mv_left);
	new_v_world[X] = data->player->x + new_v[X]; 
	new_v_world[Y] = data->player->y - new_v[Y];
	if (check_collisions(data, new_v_world) == true)
		return ;
	data->player->x = new_v_world[X];
	data->player->y = new_v_world[Y];
	update_minimap(data);
}

void	move(t_data *data, int direction)
{
	double	new_v[2];
	double	new_v_world[2];

	new_v[X] = direction * STEP * data->player->x_scalar;
	new_v[Y] = direction * STEP * data->player->y_scalar;
	new_v_world[X] = data->player->x + new_v[X];
	new_v_world[Y] = data->player->y - new_v[Y];
	if (check_collisions(data, new_v_world) == true)
		return ;
	data->player->x = new_v_world[X];
	data->player->y = new_v_world[Y];
	update_minimap(data);
}

void	check_move_keys(t_data *data, mlx_key_data_t keycode)
{
	if (keycode.key	== MLX_KEY_W &&	(keycode.action	== MLX_PRESS
		|| keycode.action == MLX_REPEAT))
		move(data, MV_FORW);
	else if	(keycode.key ==	MLX_KEY_S && (keycode.action ==	MLX_PRESS
		|| keycode.action == MLX_REPEAT))
		move(data, MV_BACKW);
	else if	(keycode.key ==	MLX_KEY_A && (keycode.action ==	MLX_PRESS
		|| keycode.action == MLX_REPEAT))
		move_lateral(data, MV_LEFT);
	else if	(keycode.key ==	MLX_KEY_D && (keycode.action ==	MLX_PRESS
		|| keycode.action == MLX_REPEAT))
		move_lateral(data, MV_RIGHT);
}
