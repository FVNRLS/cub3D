/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:59:05 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/06 19:47:29 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

void	check_cursor(void *param)
{
	t_data	*data;
	int		y;
	int		x;

	data = (t_data *)param;
	x = data->mouse_x;
	mlx_get_mouse_pos(data->mlx, &data->mouse_x, &y);
	if (data->mouse_x > x)
		rotate(data, ROTATE_RIGHT * 1);
	else if (data->mouse_x < x)
		rotate(data, ROTATE_LEFT * 1);
}
