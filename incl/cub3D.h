/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:32:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/20 12:12:54 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# include "struct.h"
# include "errors.h"
# include "tools.h"
# include "../lib/get_next_line/get_next_line.h"

# define RIGHTS		0644
# define NUM_ITEMS	7

# define NEWLINE	"\n"
# define NORTH		"NO"
# define SOUTH		"SO"
# define EAST		"EA"
# define WEST		"WE"
# define CEILING	"C"
# define FLOOR		"F"

# define SPACE		' '
# define ZERO		'0'
# define ONE		'1'
# define PLAYER_N	'N'
# define PLAYER_S	'S'
# define PLAYER_E	'E'
# define PLAYER_W	'W'

# define T_INVALID	(-1)
# define T_NEWLINE	0
# define T_NORTH	1
# define T_SOUTH	2
# define T_EAST		3
# define T_WEST		4
# define T_CEILING	5
# define T_FLOOR	6
# define T_MAP		7
# define T_SPACE	8

//INITIALIZER
void	init_environment(t_data *data);
void	init_map_objects(t_data *data);


//PARSER
void	parse_input(t_data *data);
void	parse_textures(t_data *data, int token);
void	parse_ceiling(t_data *data);
void	parse_floor(t_data *data);
void	parse_map(t_data *data);


//DESTRUCTOR
void	free_all_resources(t_data *data);


#endif
