/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:30:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/25 12:35:16 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static void create_items_container(t_data *data)
{
	data->conf->specs[0] = S_NEWLINE;
	data->conf->specs[1] = NORTH;
	data->conf->specs[2] = SOUTH;
	data->conf->specs[3] = EAST;
	data->conf->specs[4] = WEST;
	data->conf->specs[5] = CEILING;
	data->conf->specs[6] = FLOOR;
	data->conf->specs[NUM_ITEMS] = NULL;
	data->conf->items[0] = VOID;
	data->conf->items[1] = ZERO;
	data->conf->items[2] = ONE;
	data->conf->items[3] = PLAYER_N;
	data->conf->items[4] = PLAYER_S;
	data->conf->items[5] = PLAYER_E;
	data->conf->items[6] = PLAYER_W;
	data->conf->items[7] = '\0';

}

static void init_config_items(t_data *data)
{
	data->conf = malloc(sizeof(t_conf));
	if (!data->conf)
	{
		print_int_error(MALLOC_ERROR, NULL);
		ft_free_all_and_exit(data);
	}
	data->conf->specs = malloc(sizeof(char *) * (NUM_ITEMS + 1));
	if (!data->conf->specs)
	{
		print_int_error(MALLOC_ERROR, NULL);
		ft_free_all_and_exit(data);
	}
	data->conf->items = malloc(sizeof(char) * (NUM_ITEMS + 1));
	if (!data->conf->items)
	{
		print_int_error(MALLOC_ERROR, NULL);
		ft_free_all_and_exit(data);
	}
	data->conf->line = NULL;
	data->conf->tokens = NULL;
	data->conf->fd = -1;
	data->conf->line_num = 1;
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

static void init_ceiling_floor(t_data *data)
{
	data->color = malloc(sizeof(t_color));
	if (!data->color)
	{
		print_error(MALLOC_ERROR, NULL);
		ft_free_all_and_exit(data);
	}
	data->color->ceil = -1;
	data->color->floor = -1;
	data->color->r = -1;
	data->color->g = -1;
	data->color->b = -1;
}

void	init_map_objects(t_data *data)
{
	init_config_items(data);
	init_textures(data);
	init_ceiling_floor(data);
}