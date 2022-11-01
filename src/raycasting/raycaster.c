/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:27:22 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/01 18:54:33 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

double	dist_next_line_x(t_data *data)
{
	double	dist;

	if (data->player->angle < M_PI)
		dist = ceil(data->player->x) - data->player->x;
	else
		dist = data->player->x - floor(data->player->x);
	if (dist < 0)
		dist *= -1;
	return (dist);
}

double	dist_next_line_y(t_data *data)
{
	double	dist;

	if (data->player->angle > (1.5 * M_PI) || data->player->angle < (0.5 * M_PI))
		dist = data->player->y - floor(data->player->y);
	else
		dist = ceil(data->player->y) - data->player->y;
	if (dist < 0)
		dist *= -1;
	return (dist);
}

int		next_line_x(t_data *data)
{
	double	next_line;

	if (data->player->angle < M_PI)
		next_line = ceil(data->player->x);
	else
		next_line = floor(data->player->x);
	if (next_line < 0)
		next_line *= -1;
	return ((int)next_line);
}

int		next_line_y(t_data *data)
{
	double	next_line;

	if (data->player->angle > (1.5 * M_PI) || data->player->angle < (0.5 * M_PI))
		next_line = floor(data->player->y);
	else
		next_line = ceil(data->player->y);
	if (next_line < 0)
		next_line *= -1;
	return ((int)next_line);
}

double	delta_x(t_data *data)
{
	return (dist_next_line_x(data) / data->player->x_scalar);
}

double	delta_y(t_data *data)
{

}

void	raycaster(t_data *data)
{
	double	dist[2];
	int		next[2];
	double	delta[2];

	dist[X] = dist_next_line_x(data);
	dist[Y] = dist_next_line_y(data);
	next[X] = next_line_x(data);
	next[Y] = next_line_y(data);
	printf("dist[X] = %lf, next[X] = %i\n", dist[X], next[X]);
	printf("dist[Y] = %lf, next[Y] = %i\n", dist[Y], next[Y]);
	
	
	
	
	
	// double	pos[2];
	// double	dir[2];
	// double	cam_angle;
	// double	cam_dir[2];
	// int		map_pos[2];
	// double	delta_dist[2];

	// pos[X] = data->player->x;
	// pos[Y] = data->player->y;
	// dir[X] = data->player->x_scalar;
	// dir[Y] = data->player->y_scalar;

	// cam_angle = data->player->angle + (0.5 * M_PI);
	// cam_dir[X] = sin(cam_angle);
	// cam_dir[Y] = cos(cam_angle);

	// map_pos[X] = (int)pos[X];
	// map_pos[Y] = (int)pos[Y];

	// if (dir[X] == 0)
	// 	delta_dist[X] = 0;
	// else
	// 	delta_dist[X] = 1 / dir[X];
	// if (dir[X] < 0)
	// 	dir[X] *= -1;
	// if (dir[Y] == 0)
	// 	delta_dist[Y] = 0;
	// else
	// 	delta_dist[Y] = 1 / dir[Y];
	// if (dir[Y] < -1)
	// 	dir[Y] *= -1;
	
}