#include "cub3D.h"
#include <stdio.h>

void	drawverline(t_data *data, int x, int wallstart, int wallend, int color)
{
	int	y;
	int	h;

	y = -1;
	h = data->img->height;
	while (++y < wallstart)
		mlx_put_pixel(data->img, x, y, 255);
	while (++y < wallend)
		mlx_put_pixel(data->img, x, y, color);
	while (++y < h)
		mlx_put_pixel(data->img, x, y, 255);
}

void	cast(t_data *data)
{
	double	pos[2]; // the position of the player
	double	dir[2]; // the direction vector of the player
	double	raydir[2]; // the direction of a ray
	double	plane[2]; // the camera plane
	double	cameraX; // position on the camera screen, so that -1 is the left edge, 0 is where te player is, 1 is the right edge
	double	w; // the width of the screen
	double	h; // the height of the screen
	double	x; // the x coordinate on the screen
	int		map[2]; // the current square of the map the ray is in
	double	deltadist[2];  // total length of the ray to go from 1 integer to the next
	double	sidedist[2]; // length of ray to reach next x or y-side (from current position)
	int		step[2]; // should we go up or down (-1 or 1)
	double	perpwalldist; // we need in the end
	int		hit;
	int		side;
	int		lineheight;
	int		wallstart;
	int		wallend;
	int		color;

	mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->player->x_scalar = data->player->x_scalar;
	dir[Y] = data->player->y_scalar;
	pos[X] = data->player->x;
	pos[Y] = data->player->y;
	plane[X] = data->player->camplane[X];
	plane[Y] = data->player->camplane[Y];
	//plane[X] = 0;
	//plane[Y] = -1;
	//rotate_vector(plane, data->player->angle + (0.5 * M_PI));
	// a ray that hits the camera plane at 1/3 of its vector length, has a raydir[X] of dir + plane[X] !!
		// add also their y coordinates, since adding two vectors is adding their y- and x-coordinates
	// if the player rotates, the camera rotates as well. Rotate both with the rotate_vector function.

	x = 0;
	w = data->img->width;
	h = data->img->height;
	while (x < w)
	{
		cameraX = 2 * x / w - 1;

		raydir[X] = data->player->x_scalar + plane[X] * cameraX;  // direction of the ray
		raydir[Y] = dir[Y] + plane[Y] * cameraX;

		map[X] = (int)pos[X]; // current square the ray is in
		map[Y] = (int)pos[Y];

		if (raydir[X] == 0)
			deltadist[X] = DBL_MAX;
		else
			deltadist[X] = ft_abs_dbl(1 / raydir[X]);  // TODO: make an exeption when raydir is 0
		if (raydir[Y] == 0)
			deltadist[Y] = DBL_MAX;
		else
			deltadist[Y] = ft_abs_dbl(1 / raydir[Y]);

		hit = false;
		if (raydir[X] < 0)
		{
			step[X] = -1;
			sidedist[X] = (pos[X] - map[X]) * deltadist[X];
		}
		else
		{
			step[X] = 1;
			sidedist[X] = (map[X] + 1 - pos[X]) * deltadist[X];
		}
		if (raydir[Y] < 0)
		{
			step[Y] = -1;
			sidedist[Y] = (pos[Y] - map[Y]) * deltadist[Y];
		}
		else
		{
			step[Y] = 1;
			sidedist[Y] = (map[Y] + 1 - pos[Y]) * deltadist[Y];
		}
		while (hit == 0)
		{
			if (sidedist[X] < sidedist[Y])
			{
				sidedist[X] += deltadist[X];
				map[X] += step[X];
				side = 0;
			}
			else
			{
				sidedist[Y] += deltadist[Y];
				map[Y] += step[Y];
				side = 1;
			}
			if (data->map[map[X]][map[Y]] == '1')
				hit = true;
		}
		if (side == 0)
			perpwalldist = sidedist[X] - deltadist[X];
		else
			perpwalldist = sidedist[Y] - deltadist[Y];
		lineheight = (h / perpwalldist);
		wallstart = -lineheight / 2 + h / 2;
		if (wallstart < 0)
			wallstart = 0;
		wallend = lineheight / 2 + h / 2;
		if (wallend >= h)
			wallend = h - 1;
		if (side == 0 && raydir[X] < 0) // we hit west
			color = RED;
		else if (side == 0 && raydir[X] >= 0) // we hit east
			color = NAVY;
		else if (side == 1 && raydir[Y] < 0) // we hit north
			color = SILVER;
		else // we hit south
			color = GREEN;
		drawverline(data, x, wallstart, wallend, color);
		x++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
