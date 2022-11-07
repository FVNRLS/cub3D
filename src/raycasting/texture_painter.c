/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_painter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:53:37 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/07 14:50:00 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	calc_for_high_wall(double wallheight, double img_height, \
double texture_height, double y)
{
	double	part_of_wall_outside_img;
	double	part_of_wall_inside_img;
	double	pixel_offset_y;
	int		texture_pixels_inside_img;
	int		y_coord;

	part_of_wall_outside_img = (wallheight - img_height) / wallheight;
	part_of_wall_inside_img = 1.0 - part_of_wall_outside_img;
	texture_pixels_inside_img = part_of_wall_inside_img * texture_height;
	pixel_offset_y = (part_of_wall_outside_img / 2.0) * texture_height;
	y_coord = (int)round(pixel_offset_y + (y / img_height) * \
	texture_pixels_inside_img);
	return (y_coord);
}

static int	calc_for_normal_wall(t_data *data, t_render *rend, int y)
{
	int		y_coord;
	double	y_proportion;
	double	y_position_on_wall;

	y_position_on_wall = (double)(y - rend->wallstart);
	y_proportion = y_position_on_wall / ((double)rend->wallheight);
	y_coord = y_proportion * (data->texture->current->height);
	return (y_coord);
}

static int	lookup_color(mlx_texture_t *texture, int x_coord, int y_coord)
{
	int	r;
	int	g;
	int	b;
	int	t;
	int	byte;

	byte = (y_coord * texture->width * 4) + (x_coord * 4);
	r = texture->pixels[byte];
	g = texture->pixels[byte + 1];
	b = texture->pixels[byte + 2];
	t = texture->pixels[byte + 3];
	return (r << 24 | g << 16 | b << 8 | t);
}

int	get_texture_color(t_data *data, t_render *rend, int y)
{
	int	color;
	int	x_texture;
	int	y_texture;

	x_texture = (int)round(data->texture->text_xcoord * \
	(data->texture->current->width - 1));
	if ((uint32_t)rend->wallheight > data->img->height)
		y_texture = calc_for_high_wall((double)rend->wallheight, \
		(double)data->img->height, \
		(double)data->texture->current->height, (double)y);
	else
	y_texture = calc_for_normal_wall(data, rend, y);
	color = lookup_color(data->texture->current, x_texture, y_texture);
	return (color);
}
