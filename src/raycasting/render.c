#include "cub3D.h"

static void	drawverline(t_data *data, t_render *rend, int x)
{
	int	y;
	int	h;

	y = -1;
	h = data->img->height;
	while (++y < rend->wallstart)
		mlx_put_pixel(data->img, x, y, data->color->ceil);
	while (++y < rend->wallend)
		mlx_put_pixel(data->img, x, y, get_texture_color(data, rend, y));
	while (++y < h)
		mlx_put_pixel(data->img, x, y, data->color->floor);
}

static void	get_render_info(t_render *rend, t_ray *ray, t_data *data)
{
	if (ray->side == 0)
		rend->perpwalldist = ray->sidedist[X] - ray->deltadist[X];
	else
		rend->perpwalldist = ray->sidedist[Y] - ray->deltadist[Y];
	rend->wallheight = (data->img->height / rend->perpwalldist);
	rend->wallstart = (-1 * rend->wallheight) / 2 + data->img->height / 2;
	if (rend->wallstart < 0)
		rend->wallstart = 0;
	rend->wallend = rend->wallheight / 2 + data->img->height / 2;
	if (rend->wallend >= data->img->height)
		rend->wallend = data->img->height - 1;
}

static void	get_textures(t_ray *ray, t_data *data)
{
	if (ray->side == 0 && ray->raydir[X] < 0)
		data->texture->current = data->texture->t_west;
	else if (ray->side == 0 && ray->raydir[X] >= 0)
		data->texture->current = data->texture->t_east;
	else if (ray->side == 1 && ray->raydir[Y] < 0)
		data->texture->current = data->texture->t_north;
	else // we hit south
		data->texture->current = data->texture->t_south;
}

static void	calc_wall_dist(t_ray *ray, t_data *data, double camera_x)
{
	bool	hit;

	hit = false;
	while (hit == false)
	{
		if (ray->sidedist[X] < ray->sidedist[Y])
		{
			ray->sidedist[X] += ray->deltadist[X];
			ray->map[X] += ray->step[X];
			ray->side = 0;
		}
		else
		{
			ray->sidedist[Y] += ray->deltadist[Y];
			ray->map[Y] += ray->step[Y];
			ray->side = 1;
		}
		if (data->map[ray->map[X]][ray->map[Y]] == '1')
			hit = true;
	}
	get_x_coord_texture(ray, data);
}

void	render(t_data *data)
{
	t_ray		ray;
	t_render	rend;
	double		camera_x;
	double		x;

	mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	x = 0;
	while (x < data->img->width)
	{
		camera_x = 2 * x / data->img->width - 1;
		init_dda(data, &ray, camera_x);
		calc_wall_dist(&ray, data, camera_x);
		get_render_info(&rend, &ray, data);
		get_textures(&ray, data);
		drawverline(data, &rend, x);
		x++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
