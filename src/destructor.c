/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:46:56 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/25 15:34:57 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

static void	free_map_objects(t_data *data)
{
	free(data->conf);
	free(data->conf->specs);

	free(data->conf->items);

	free(data->texture->north);
	free(data->texture->south);
	free(data->texture->east);
	free(data->texture->west);
	free(data->texture);

	free(data->color);

	free(data->tab->buf);
	ft_free_split(data->tab->map);
	free(data->tab);
	free(data->player);
}

static void free_mlx_objects(t_data *data)
{
	mlx_destroy_image(data->gui->mlx, data->gui->img);
	mlx_clear_window(data->gui->mlx, data->gui->win);
	free(data->gui->mlx);
	free(data->gui);
}

void	free_all_resources(t_data *data)
{
	free_map_objects(data);
	if (data->gui != NULL)
		free_mlx_objects(data);
	close(data->conf->fd);
}