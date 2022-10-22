/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:32:47 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/22 13:38:05 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static void init_flags(t_data *data)
{
	data->parse_error = false;
	data->map_parsed = false;
}

static void init_data_containers(t_data *data)
{

}

static void init_map(t_data *data)
{
	data->tab = malloc(sizeof(t_tab));
	if (!data->tab)
	{
		print_int_error(MALLOC_ERROR, NULL);
		ft_free_all_and_exit(data);
	}
	data->map = NULL;
	data->tab->buf = NULL;
	data->tab->map = NULL;
	data->tab->max_x = 0;
	data->tab->max_y = 1;
}

void	init_environment(t_data *data)
{
	init_flags(data);
	init_data_containers(data);
	init_map_objects(data);
	init_map(data);
}