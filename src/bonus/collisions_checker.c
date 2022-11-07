/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:17:52 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/07 16:21:38 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_collisions(t_data	*data, double new_v[2])
{
	int	old_xmap;
	int	old_ymap;

	old_xmap = data->player->x;
	old_ymap = data->player->y;
	if (data->map[(int)new_v[X]][(int)new_v[Y]] == '1')
		return (true);
	if (data->map[(int)new_v[X]][old_ymap] == '1'
		&& data->map[old_xmap][(int)new_v[Y]] == '1')
		return (true);
	return (false);
}
