/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_painter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:53:37 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/05 20:36:15 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int	main(void)
// {
// 	// Start mlx
// 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
// 	if (!mlx)
//         exit(0);

// 	// Try to load the file
// 	mlx_texture_t* texture = mlx_load_png("./textures/purplestone.png");
// 	if (!texture)
//         exit(0);
	

// //	mlx_image_t *img = mlx_texture_to_image(mlx, texture);
// 	mlx_image_t *img2 = mlx_new_image(mlx, texture->width, texture->height);

	// int	y = 0;
	// int x = 0;
	// int	rgb;
	// int	r;
	// int	g;
	// int	b;
	// int	t;
	// int color;
	// int	offset;
	// int	pixel;
	
	// pixel = 0;
	// while (y < img2->height)
	// {
	// 	x = 0;
	// 	while (x < img2->width)
	// 	{
	// 		r = texture->pixels[pixel];
	// 		g = texture->pixels[pixel + 1];
	// 		b = texture->pixels[pixel + 2];
	// 		t = texture->pixels[pixel + 3];
	// 		color = r << 24 | g << 16 | b << 8 | t;
	// 		mlx_put_pixel(img2, x, y, color);
	// 		x++;
	// 		pixel += 4;
	// 	}
	// 	y++;
	// }
// 	if (mlx_image_to_window(mlx, img2, 0, 0) < 0)
//          exit(0);

// 	mlx_loop(mlx);

// 	// Optional, terminate will clean up any left overs, this is just to demonstrate.
// 	mlx_delete_image(mlx, img2);
// 	mlx_delete_texture(texture);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

static int	calc_for_high_wall(t_data *data, t_render *rend, int y)
{
	// printf("lineheight = %i, imgheight = %i\n");
	return (0);
}

int	get_texture_color(t_data *data, t_render *rend, int y)
{
	int	r;
	int	g;
	int	b;
	int	t;
	int	byte;
	
	int	x_coord;
	int	y_coord;
	double	y_proportion;
	double	y_position_on_wall;

	double	wall_outside;
	double	proportion_outside;
	double	proportion_inside;
	double pixel_offset_y;
	int pixels_inside;


	x_coord = (int)round(data->texture->text_xcoord * (data->texture->current->width - 1));
	// if (rend->lineheight > data->img->height)
		// y_coord = calc_for_high_wall(data, rend, y);
	if (rend->lineheight > data->img->height)
	{
		wall_outside = (double)(rend->lineheight - data->img->height);
		// printf("wall_outside = %lf\n", wall_outside);
		proportion_outside = wall_outside / ((double)rend->lineheight);
		// printf("proportion outside = %lf\n", proportion_outside);
		proportion_inside = 1.0 - proportion_outside;
		// printf("proportion inside = %lf\n", proportion_inside);
		pixels_inside = proportion_inside * (double)data->texture->current->height;


		pixel_offset_y = (proportion_outside / 2.0) * (double)data->texture->current->height;
		// printf("pixel_offset_y = %lf\n")
		y_coord = (int)round(pixel_offset_y + (((double)y / (double)data->img->height) * pixels_inside));
		// printf("x_coord = %i, y_coord = %i\n", x_coord, y_coord);
		// printf("------------------------------------------------\n");
	}
	else
	{
		y_position_on_wall = (double)(y - rend->wallstart);
		y_proportion = y_position_on_wall / ((double)rend->lineheight);
		y_coord = y_proportion * (data->texture->current->height);
	}
	byte = (y_coord * data->texture->current->width * 4) + (x_coord * 4);
	r = data->texture->current->pixels[byte];
	g = data->texture->current->pixels[byte + 1];
	b = data->texture->current->pixels[byte + 2];
	t = data->texture->current->pixels[byte + 3]; 
	//printf("x_coord = %i, y_coord = %i\n", x_coord, y_coord);
	return (r << 24 | g << 16 | b << 8 | t); 
}
