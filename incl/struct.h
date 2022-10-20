/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:07:54 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/20 10:14:52 by rmazurit         ###   ########.fr       */
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

typedef struct s_conf
{
	int 		fd;
	char		*file;
	char		*line;
	char		**tokens;
	char		**specs;
}		t_conf;


typedef struct s_data
{

	bool		parse_error;
	t_conf		*conf;
	t_map		*map;
	t_texture	*texture;
}		t_data;

#endif
