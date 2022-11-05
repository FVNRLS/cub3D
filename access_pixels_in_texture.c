
#include "incl/cub3D.h"

int	main(void)
{
	// Start mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
        exit(0);

	// Try to load the file
	mlx_texture_t* texture = mlx_load_png("./textures/purplestone.png");
	if (!texture)
        exit(0);
	

//	mlx_image_t *img = mlx_texture_to_image(mlx, texture);
	mlx_image_t *img2 = mlx_new_image(mlx, texture->width, texture->height);

	int	y = 0;
	int x = 0;
	int	rgb;
	int	r;
	int	g;
	int	b;
	int	t;
	int color;
	int	offset;
	int	pixel;
	
	pixel = 0;
	while (y < img2->height)
	{
		x = 0;
		while (x < img2->width)
		{
			r = texture->pixels[pixel];
			g = texture->pixels[pixel + 1];
			b = texture->pixels[pixel + 2];
			t = texture->pixels[pixel + 3];
			color = r << 24 | g << 16 | b << 8 | t;
			mlx_put_pixel(img2, x, y, color);
			x++;
			pixel += 4;
		}
		y++;
	}
	if (mlx_image_to_window(mlx, img2, 0, 0) < 0)
         exit(0);

	mlx_loop(mlx);

	// Optional, terminate will clean up any left overs, this is just to demonstrate.
	mlx_delete_image(mlx, img2);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}