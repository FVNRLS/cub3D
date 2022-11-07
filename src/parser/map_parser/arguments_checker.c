/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:37:50 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/25 13:51:02 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

static bool	map_parsed(t_data *data)
{
	if (data->map == NULL)
	{
		print_error(NO_MAP, NULL);
		return (false);
	}
	if (data->player->dir == VOID)
	{
		print_error(NO_PLAYER, NULL);
		return (false);
	}
	return (true);
}

static bool	colors_parsed(t_data *data)
{
	if (data->color->ceil == -1)
	{
		print_error(NO_COLOR, "ceiling");
		return (false);
	}
	if (data->color->floor == -1)
	{
		print_error(NO_COLOR, "floor");
		return (false);
	}
	return (true);
}

static bool	textures_parsed(t_data *data)
{
	if (!data->texture->north)
	{
		print_error(NO_TEXTURE, "north");
		return (false);
	}
	if (!data->texture->south)
	{
		print_error(NO_TEXTURE, "south");
		return (false);
	}
	if (!data->texture->east)
	{
		print_error(NO_TEXTURE, "east");
		return (false);
	}
	if (!data->texture->west)
	{
		print_error(NO_TEXTURE, "west");
		return (false);
	}
	return (true);
}

/*
 * performs final checks on the parsed arguments. If any argument is at its
 * init value, returns false, which causes parse error and terminates the
 * program*/
bool	check_args(t_data *data)
{
	if (textures_parsed(data) && colors_parsed(data) && map_parsed(data))
		return (false);
	else
		return (true);
}
