/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:32:47 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/19 12:33:32 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static void init_flags(t_data *data)
{
	data->parse_error = false;
}


void	init_environment(t_data *data)
{
	init_flags(data);
	init_map_objects(data);
}