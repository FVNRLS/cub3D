/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:50:30 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/20 17:19:58 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

static void	free_map_objects(t_data *data)
{
	free(data->conf);
	free(data->conf->specs);

	free(data->texture->north);
	free(data->texture->south);
	free(data->texture->east);
	free(data->texture->west);
	free(data->texture);
}

void	free_all_resources(t_data *data)
{
	free_map_objects(data);
}