/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:27:22 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/01 22:15:27 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

double	dist_next_line_x(t_data *data)
{
	double	dist;

	if (data->player->angle == 0 || data->player->angle == M_PI)
		dist = DBL_MAX;
	else if (data->player->angle < M_PI)
		dist = ceil(data->player->x) - data->player->x;
	else
		dist = data->player->x - floor(data->player->x);
	return (dist);
}

double	dist_next_line_y(t_data *data)
{
	double	dist;

	if (data->player->angle == 1.5 * M_PI || data->player->angle == 0.5 * M_PI)
		dist = DBL_MAX;
	else if (data->player->angle > (1.5 * M_PI) || data->player->angle < (0.5 * M_PI))
		dist = data->player->y - floor(data->player->y);
	else
		dist = ceil(data->player->y) - data->player->y;
	return (dist);
}

int		next_line_x(t_data *data)
{
	double	next_line;

	if (data->player->angle < M_PI)
		next_line = ceil(data->player->x);
	else
		next_line = floor(data->player->x);
	return ((int)next_line);
}

int		next_line_y(t_data *data)
{
	double	next_line;

	if (data->player->angle > (1.5 * M_PI) || data->player->angle < (0.5 * M_PI))
		next_line = floor(data->player->y);
	else
		next_line = ceil(data->player->y);
	return ((int)next_line);
}

double	delta_x(t_data *data)
{
	double	delta;
	if (data->player->x_scalar == 0)
		return (DBL_MAX);
	delta = dist_next_line_x(data) / data->player->x_scalar;
	if (delta < 0)
		delta *= -1;
	return (delta);
}

double	delta_y(t_data *data)
{
	double	delta;
	if (data->player->y_scalar == 0)
		return (DBL_MAX);
	delta = dist_next_line_y(data) / data->player->y_scalar;
	if (delta < 0)
		delta *= -1;
	return (delta);
}

void	raycaster(t_data *data)
{
	double	dist[2];
	double	delta[2];
	int		next[2];
	double	hit_next_x[2];
	double	hit_next_y[2];
	bool	wall[2];

	next[X] = next_line_x(data);
	next[Y] = next_line_y(data);
	dist[X] = dist_next_line_x(data);
	dist[Y] = dist_next_line_y(data);
	delta[X] = delta_x(data);
	delta[Y] = delta_y(data);
	hit_next_x[X] = data->player->x + (delta[X] * data->player->x_scalar);
	hit_next_x[Y] = data->player->y - (delta[X] * data->player->y_scalar);
	printf("player is at x = %lf\n", data->player->x);
	printf("players step on vertical axis = %lf\n", data->player->x_scalar);
	printf("next vertical grid line is: %i\n", next[X]);
	printf("distance to next vertical grid line along cameraline: %lf\n", delta[X]);
	printf("next vertical grid line is hit at: (%lf, %lf)\n", hit_next_x[X], hit_next_x[Y]);
	hit_next_y[Y] = data->player->y - (delta[Y] * data->player->y_scalar);
	hit_next_y[X] = data->player->x + (delta[Y] * data->player->x_scalar);
	printf("player is at y = %lf\n", data->player->y);
	printf("players step on horizontal axis = %lf\n");
	printf("next horizontal grind line is: %i\n", next[Y]);
	printf("distance to next horizontal grid line along cameraline: %lf\n", delta[Y]);
	printf("next horizontal grid line is hit at: (%lf, %lf)\n", hit_next_y[X], hit_next_y[Y]);
	//todo: 
	//check_if_wall_x(data, hit_next_x);
	//check_if_wall_y(data, hit_next_y);
}