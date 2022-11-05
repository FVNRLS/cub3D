/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_painter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:53:37 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/05 18:43:57 by hoomen           ###   ########.fr       */
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

	x_coord = (int)round(data->texture->text_xcoord * (data->texture->current->width - 1));
	y_position_on_wall = (double)(y - rend->wallstart);
	y_proportion = y_position_on_wall / ((double)rend->lineheight);
	y_coord = y_proportion * (data->texture->current->height);
	byte = (y_coord * data->texture->current->width * 4) + (x_coord * 4);
	r = data->texture->current->pixels[byte];
	g = data->texture->current->pixels[byte + 1];
	b = data->texture->current->pixels[byte + 2];
	t = data->texture->current->pixels[byte + 3];
	//printf("x_coord = %i, y_coord = %i\n", x_coord, y_coord);
	return (r << 24 | g << 16 | b << 8 | t); 
}
