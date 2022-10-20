/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:05:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/19 15:05:39 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static void create_items_container(t_data *data)
{
	int i;

	data->conf->items[0] = ft_strdup(SPACE);
	data->conf->items[1] = ft_strdup(NEWLINE);
	data->conf->items[2] = ft_strdup(CEILING);
	data->conf->items[3] = ft_strdup(FLOOR);
	data->conf->items[4] = ft_strdup(NORTH);
	data->conf->items[5] = ft_strdup(SOUTH);
	data->conf->items[6] = ft_strdup(EAST);
	data->conf->items[7] = ft_strdup(WEST);
	data->conf->items[8] = ft_strdup(ZERO);
	data->conf->items[9] = ft_strdup(ONE);
	data->conf->items[NUM_ITEMS] = NULL;
	i = 0;
	while (i < NUM_ITEMS)
	{
		if (!data->conf->items[i])
		{
			print_int_error(MALLOC_ERROR, NULL);
			ft_free_all_and_exit(data);
		}
		i++;
	}
}

static void init_config_items(t_data *data)
{
	data->conf = malloc(sizeof(t_conf));
	if (!data->conf)
	{
		print_int_error(MALLOC_ERROR, NULL);
		ft_free_all_and_exit(data);
	}
	data->conf->items = malloc(sizeof(char *) * (NUM_ITEMS + 1));
	if (!data->conf->items)
	{
		print_int_error(MALLOC_ERROR, NULL);
		ft_free_all_and_exit(data);
	}
	data->conf->line = NULL;
	data->conf->tokens = NULL;
	data->conf->fd = -1;
	create_items_container(data);


}

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
	init_config_items(data);
}