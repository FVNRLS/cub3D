/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:32:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/19 12:47:29 by rmazurit         ###   ########.fr       */
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

# define RIGHTS	0644
# define SPACE	' '

//INITIALIZER
void	init_environment(t_data *data);
void	init_map_objects(t_data *data);


//PARSER
void	parse_input(t_data *data);
void	parse_textures(t_data *data);


//DESTRUCTOR
void	free_all_resources(t_data *data);


#endif
