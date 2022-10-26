/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:30:28 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/26 11:35:53 by rmazurit         ###   ########.fr       */
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
	int 	x;
	int 	y;
	char	dir;
}		t_player;

typedef struct s_data
{
	bool		parse_error;
	bool		map_parsed;
	t_conf		*conf;
	t_texture	*texture;
	t_color		*color;
	t_tab		*tab;
	t_player	*player;
	mlx_t 		*mlx;
	mlx_image_t	*img;
	char		**map;
}		t_data;

#endif
