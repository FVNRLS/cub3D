/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:24:42 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/01 14:27:12 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static void	init_minimap(t_data *data)
{
	data->minimap = NULL;
	data->minimap = malloc(sizeof(t_minimap));
	if (!data->minimap)
	{
		print_int_error(MALLOC_ERROR, NULL);
		ft_free_all_and_exit(data);
	}
	data->minimap->size = WIDTH / MINIMAP_FACTOR;
	data->minimap->img = NULL;
}

void	init_bonus_objects(t_data *data)
{
	init_minimap(data);
	update_minimap(data);
}
