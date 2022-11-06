/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 hooks_catcher.c									:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: hoomen	<hoomen@student.42.fr>				+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2022/10/25 16:06:45 by rmazurit		   #+#	  #+#			  */
/*	 Updated: 2022/11/06 15:50:33 by hoomen			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

void	hooks_catcher_loop(t_data *data)
{
    data->mouse_x = data->img->width / 2;
    data->mouse_old_x = data->img->width / 2;
	mlx_key_hook(data->mlx,	&check_key_hooks, (void	*)data);
	mlx_cursor_hook(data->mlx, (mlx_cursorfunc)&check_cursor, (void *)data);
}
