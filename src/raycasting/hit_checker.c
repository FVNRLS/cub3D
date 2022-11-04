/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:11:37 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/04 15:52:44 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../incl/cub3D.h"

// int		get_check_field(double ray_pos, double scalar)
// {
// 	if (scalar == 0)
// 		return (INT_MAX);
// 	if (scalar < 0)
// 		return ((int)floor(ray_pos) - 1);
// 	return ((int)ceil(ray_pos));
// }

// bool	check_hit_vertical(t_data *data, t_ray *ray)
// {
// 	int	check_field[2];

// 	if (data->player->x_scalar == 0)
// 		return (false);
// 	check_field[X] = get_check_field(ray->ray_pos[X], data->player->x_scalar);
// 	check_field[Y] = (int)floor(ray->ray_pos[Y]);
// 	if (check_field[Y] < 0)
// 		return (false);
// 	if (check_field[Y] >= data->tab->max_y)
// 		return (false);
// 	if (data->map[check_field[X]][check_field[Y]] == '1')
// 		return (true);
// 	return (false);
// }

// bool	check_hit_horizontal(t_data *data, t_ray *ray)
// {
// 	int	check_field[2];

// 	if (data->player->y_scalar == 0)
// 		return (false);
// 	check_field[Y] = get_check_field(ray->ray_pos[Y], data->player->y_scalar);
// 	check_field[X] = (int)floor(ray->ray_pos[X]);
// 	if (check_field[X] < 0)
// 		return (false);
// 	if (check_field[X] >= data->tab->max_x)
// 		return (false);
// 	if (data->map[check_field[X]][check_field[Y]] == '1')
// 		return (true);
// 	return (false);
// }