/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:27:22 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/01 21:14:37 by hoomen           ###   ########.fr       */
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
		delta = DBL_MAX;
	else
		delta = dist_next_line_x(data) / data->player->x_scalar;
	return (delta);
}

double	delta_y(t_data *data)
{
	double	delta;
	if (data->player->y_scalar == 0)
		delta = DBL_MAX;
	else
		delta = dist_next_line_y(data) / data->player->y_scalar;
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
	//printf("check move x check_field[X] = %i\n", check_field[X]);
	if (data->player->y_scalar == 0)
		y_land = data->player->y;
	else
		y_land = data->player->y + data->player->y_scalar * delta;
	printf("y_scalar = %lf\n", data->player->y_scalar);
	printf("check move x, y_land = %lf\n", y_land);
	if (data->player->angle > 1.5 * M_PI || data->player->angle < 0.5 * M_PI)
		check_field[Y] = (int) floor(y_land);
	else
		check_field[Y] = ceil(y_land);
	//printf("check move x check_field[Y] = %i\n", check_field[Y]);
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
	//printf("check move y check_field[Y] = %i\n", check_field[Y]);
	if (data->player->x_scalar == 0)
		x_land = data->player->x;
	else
		x_land = data->player->x + data->player->x_scalar * delta;
	printf("x_scalar = %lf\n", data->player->x_scalar);
	printf("check move y, x_land = %lf\n", x_land);
	if (data->player->angle < M_PI)
		check_field[X] = (int) floor(x_land);
	else
		check_field[X] = (int) floor(x_land) - 1;
	//printf("check move y check_field[X] = %i\n", check_field[X]);
	if (check_field[X] < 0 || check_field[X] >= data->tab->max_x)
		return (false);
	if (data->map[check_field[X]][check_field[Y]] == '1')
		return (true);
	return (false);
}

void	raycaster(t_data *data)
{
	double	dist[2];
	int		next[2];
	double	delta[2];
	bool	wall[2];

	dist[X] = dist_next_line_x(data);
	dist[Y] = dist_next_line_y(data);
	next[X] = next_line_x(data);
	next[Y] = next_line_y(data);
	delta[X] = delta_x(data);
	delta[Y] = delta_y(data);
	//printf("dist[X] = %lf, next[X] = %i, delta[X] = %lf\n", dist[X], next[X], delta[X]);
	//printf("dist[Y] = %lf, next[Y] = %i, delta[Y] = %lf\n", dist[Y], next[Y], delta[Y]);
	//printf("data->player->x + delta[X] * data->player->x_scalar = %lf\n", data->player->x + delta[X] * data->player->x_scalar);
	//printf("data->player->y - delta[X] * data->player->y_scalar = %lf\n", data->player->y - delta[X] * data->player->y_scalar);
	wall[X] = ray_check_wall_x(data, next[X], delta[X]);
	wall[Y] = ray_check_wall_y(data, next[Y], delta[Y]);
	printf("wall[X] = %d, wall[Y] = %d\n", wall[X], wall[Y]);
	
	
	
	
	
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