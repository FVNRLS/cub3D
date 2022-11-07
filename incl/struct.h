/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:30:28 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/07 20:34:56 by rmazurit         ###   ########.fr       */
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
}			t_tab;

typedef struct s_texture
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	mlx_texture_t	*t_north;
	mlx_texture_t	*t_south;
	mlx_texture_t	*t_west;
	mlx_texture_t	*t_east;
	double			text_xcoord;
	mlx_texture_t	*current;
}					t_texture;

typedef struct s_color
{
	int		ceil;
	int		floor;
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct s_conf
{
	int		fd;
	char	*file;
	char	*line;
	char	**tokens;
	char	**specs;
	char	*items;
	int		line_num;
}			t_conf;

typedef struct s_player
{
	double	x;
	double	y;
	double	x_scalar;
	double	y_scalar;
	double	camplane[2];
	char	dir;
	double	angle;
}			t_player;

typedef struct s_minimap
{
	mlx_image_t	*img;
	int			size;
	int			x_offset;
	int			y_offset;
}				t_minimap;

typedef struct s_ray
{
	double	raydir[2];
	int		map[2];
	double	deltadist[2];
	double	sidedist[2];
	int		step[2];
	int		side;
}			t_ray;

typedef struct s_render
{
	double			perpwalldist;
	int				wallheight;
	int				wallstart;
	int				wallend;
}					t_render;

typedef struct s_data
{
	bool		parse_error;
	bool		map_parsed;
	int			mouse_x;
	t_conf		*conf;
	t_texture	*texture;
	t_color		*color;
	t_tab		*tab;
	t_player	*player;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_minimap	*minimap;
	int			counter;
	char		**map;
}				t_data;

#endif
