/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:40:14 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/21 16:51:33 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map
{
	char	**map;
}		t_map;

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
	bool	map_parsed;
}		t_conf;


typedef struct s_data
{

	bool		parse_error;
	t_conf		*conf;
	t_texture	*texture;
	t_color		*color;
	t_map		*map;
}		t_data;

#endif
