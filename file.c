#include "incl/cub3D.h"
#include <stdio.h>

int	main(void)
{
	double	scalar[2];
	double	pos[2]; // the position of the player
	double	dir[2]; // the direction vector of the player
	double	raydir[2]; // the direction of a ray
	double	plane[2]; // the camera plane
	double	cameraX; // position on the camera screen, so that -1 is the left edge, 0 is where te player is, 1 is the right edge
	double	w; // the width of the screen
	double	x; // the x coordinate on the screen
	int		map[2]; // the current square of the map the ray is in
	double	side[2]; // length of ray from current position to next x or y-side
	double	deltadist[2];  // total length of the ray to go from 1 integer to the next
	double	sidedist[2]; // length of ray to reach next x or y-side (from current position)
	int		step[2]; // should we go up or down (-1 or 1)
	double	perpwalldist; // we need in the end
	int		step;
	int		hit;
	int		side;

	scalar[X] = -1;
	scalar[Y] = 0;
	dir[X] = scalar[X];
	dir[Y] = scalar[Y];
	plane[X] = 0;
	plane[Y] = 0.66;
	// a ray that hits the camera plane at 1/3 of its vector length, has a raydir[X] of dir + plane[X] !!
		// add also their y coordinates, since adding two vectors is adding their y- and x-coordinates
	// if the player rotates, the camera rotates as well. Rotate both with the rotate_vector function.

	x = 0;
	while (x < w)
	{
		cameraX = 2 * x / w - 1;

		raydir[X] = dir[X] + plane[X] * cameraX;  // direction of the ray
		raydir[Y] = dir[Y] + plane[Y] * cameraX;

		map[X] = (int)pos[X]; // current square the ray is in
		map[Y] = (int)pos[Y];

		deltadist[X] = ft_abs_dbl(1 / raydir[X]);  // TODO: make an exeption when raydir is 0
		deltadist[Y] = ft_abs_dbl(1 / raydir[Y]);

		
		x++;
	}
	
}
