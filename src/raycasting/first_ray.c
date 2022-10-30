/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:36:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/10/30 19:44:03 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/cub3D.h"

bool	check_first_ray(t_data *data, int x, int y, double step)
{
	double	adjacent;
	double	opposite;
	double	tan_angle;

	tan_angle = tan(data->player->angle);
	adjacent = ((double)y / step) - (double)data->player->y;
	opposite = ((double)x / step) - (double)data->player->x;
	if (tan_angle * adjacent == opposite)
		return (true);
	return (false);
}
