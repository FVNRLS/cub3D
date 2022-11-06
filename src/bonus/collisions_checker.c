/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 collisions_checker.c								:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: hoomen	<hoomen@student.42.fr>				+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2022/10/27 16:39:50 by rmazurit		   #+#	  #+#			  */
/*	 Updated: 2022/11/06 13:08:11 by hoomen			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_collisions(t_data	*data, double new_v[2])
{
	int	old_xmap;
	int	old_ymap;

	old_xmap = data->player->x;
	old_ymap = data->player->y;
	if (data->map[(int)new_v[X]][(int)new_v[Y]]	== '1')
		return (true);
	if (data->map[(int)new_v[X]][old_ymap] == '1'
		&& data->map[old_xmap][(int)new_v[Y]] == '1')
		return (true);
	return (false);
}
