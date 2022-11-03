/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:30:28 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/03 15:39:24 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../lib/minilibx/include/MLX42/MLX42.h"

typedef struct s_tab
{
	char	*buf;
	char	**map;
	int		max_x;
	int		max_y;

}		t_tab;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}		t_texture;

typedef struct s_color
{
	int		ceil;
	int		floor;
	int 	r;
	int 	g;
	int 	b;
}		t_color;


typedef struct s_conf
{
	int		fd;
	char	*file;
	char	*line;
	char	**tokens;
	char	**specs;
	char 	*items;
	int 	line_num;
}		t_conf;

typedef struct	s_player
{
	double 	x;
	double 	y;
	double	x_scalar;
	double	y_scalar;
	char	dir;
	double	angle;
}		t_player;

typedef	struct s_minimap
{
	mlx_image_t	*img;
	int 		size;
	int 		x_offset;
	int 		y_offset;
	int 		x_player;
	int 		y_player;
}		t_minimap;

// typedef struct s_rays
// {
// 	int			next_gridline[2];
// 	double		delta[2];
// 	double		hit_next_vertical_gridline[2];
// 	double		hit_next_horizontal_gridline[2];
// 	double		ray_pos[2];
// }				t_rays;

typedef struct s_ray
{
	double	ray_pos[2];
	double	ray_scal[2];
	// int		next_gridline[2];//
	// double	dist_to_next_gridline[2];//
	// double	delta[2];//
	// double	hit_next_gridline[2];//
}			t_ray;

typedef struct s_data
{
	bool		parse_error;
	bool		map_parsed;
	t_conf		*conf;
	t_texture	*texture;
	t_color		*color;
	t_tab		*tab;
	t_player	*player;
	// t_rays		*rays;
	mlx_t 		*mlx;
	mlx_image_t	*img;
	t_minimap	*minimap;
	char		**map;
}		t_data;

#endif
