/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:07:54 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/19 12:47:29 by rmazurit         ###   ########.fr       */
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

typedef struct s_data
{
	char		*conf;
	int 		fd;
	bool		parse_error;
	t_map		*map;
	t_texture	*texture;
}		t_data;

#endif
