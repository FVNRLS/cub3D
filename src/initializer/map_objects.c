/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:43:21 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/19 12:03:04 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static void	init_textures(t_data *data)
{
	data->texture = malloc(sizeof(t_texture));
	if (!data->texture)
		exit(print_int_error(MALLOC_ERROR, NULL));
	data->texture->north = NULL;
	data->texture->south = NULL;
	data->texture->east = NULL;
	data->texture->west = NULL;
}

void	init_map_objects(t_data *data)
{
	init_textures(data);
}