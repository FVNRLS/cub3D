/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:09:01 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/20 12:22:18 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static int parse_north(t_data *data)
{
	if (data->texture->north != NULL)
		return (print_int_error(TEXTURE_ERROR, NORTH));
	data->texture->north = ft_strdup(data->conf->tokens[1]);
	if (!data->texture->north)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int parse_south(t_data *data)
{
	if (data->texture->south != NULL)
		return (print_int_error(TEXTURE_ERROR, SOUTH));
	data->texture->south = ft_strdup(data->conf->tokens[1]);
	if (!data->texture->south)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int parse_east(t_data *data)
{
	if (data->texture->east != NULL)
		return (print_int_error(TEXTURE_ERROR, EAST));
	data->texture->east = ft_strdup(data->conf->tokens[1]);
	if (!data->texture->east)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int parse_west(t_data *data)
{
	if (data->texture->west != NULL)
		return (print_int_error(TEXTURE_ERROR, WEST));
	data->texture->west = ft_strdup(data->conf->tokens[1]);
	if (!data->texture->west)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	parse_textures(t_data *data, int token)
{
	int	ret;

	if (ft_splitlen(data->conf->tokens) != 2)
		ret = (print_int_error(INVALID_TOKEN, NULL));
	else
	{
		ret = 0;
		if (token == T_NORTH)
			ret = parse_north(data);
		else if (token == T_SOUTH)
			ret = parse_south(data);
		else if (token == T_EAST)
			ret = parse_east(data);
		else if (token == T_WEST)
			ret = parse_west(data);
	}
	if (ret == EXIT_FAILURE)
		data->parse_error = true;
}
