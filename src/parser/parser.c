/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:50:41 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/19 13:49:30 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static bool check_extension(char *s)
{
	int len;

	len = ft_strlen(s);
	s += len - 4;
	if (ft_strncmp(s, ".cub", 5) == 0)
		return (true);
	return (false);
}

void	parse_input(t_data *data)
{
	bool	ext_valid;

	ext_valid = check_extension(data->conf);
	if (ext_valid == false)
		return(print_error(INVALID_EXTENSION, NULL));
	data->fd = open(data->conf, O_RDONLY, RIGHTS);
	if (data->fd < 0)
		return (print_error(OPEN_ERROR, NULL));
	parse_textures(data);
}


