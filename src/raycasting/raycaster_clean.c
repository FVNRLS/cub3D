/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:27:22 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/01 21:47:33 by hoomen           ###   ########.fr       */
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

bool	ray_check_wall_x(t_data *data, double next_x, double delta)
{
	int		check_field[2];
	double	y_land;

	if (data->player->x_scalar == 0)
		return (false);
	if (data->player->angle < M_PI)
		check_field[X] = next_x;
	else
		check_field[X] = next_x - 1;
	if (data->player->y_scalar == 0)
		y_land = data->player->y;
	else
		y_land = data->player->y + data->player->y_scalar * delta;
	if (data->player->angle > 1.5 * M_PI || data->player->angle < 0.5 * M_PI)
		check_field[Y] = (int) floor(y_land);
	else
		check_field[Y] = ceil(y_land);
	if (check_field[Y] < 0 || check_field[Y] >= data->tab->max_y)
		return (false);
	if (data->map[check_field[X]][check_field[Y]] == '1')
		return (true);
	return (false);
}

bool	ray_check_wall_y(t_data *data, double next_y, double delta)
{
	int		check_field[2];
	double	x_land;

	if (data->player->y_scalar == 0)
		return (false);
	if (data->player->angle > 1.5 * M_PI || data->player->angle < 0.5 * M_PI)
		check_field[Y] = next_y - 1;
	else
		check_field[Y] = next_y;
	if (data->player->x_scalar == 0)
		x_land = data->player->x;
	else
		x_land = data->player->x + data->player->x_scalar * delta;
	if (data->player->angle < M_PI)
		check_field[X] = (int) floor(x_land);
	else
		check_field[X] = (int) floor(x_land) - 1;
	if (check_field[X] < 0 || check_field[X] >= data->tab->max_x)
		return (false);
	if (data->map[check_field[X]][check_field[Y]] == '1')
		return (true);
	return (false);
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
	





//	wall[X] = ray_check_wall_x(data, next[X], delta[X]);
	// wall[Y] = ray_check_wall_y(data, next[Y], delta[Y]);
	// printf("wall[X] = %d, wall[Y] = %d\n", wall[X], wall[Y]);
	
	
	
	
	
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