/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:52:07 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/07 14:29:53 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static int	parse_north(t_data *data)
{
	if (data->texture->north != NULL)
		return (print_int_error(TEXTURE_ERROR, NORTH));
	data->texture->north = ft_strdup(data->conf->tokens[1]);
	data->texture->north[ft_strlen(data->texture->north) - 1] = '\0';
	if (!data->texture->north)
		return (EXIT_FAILURE);
	data->texture->t_north = mlx_load_png(data->texture->north);
	if (data->texture->t_north == (void *)false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	parse_south(t_data *data)
{
	if (data->texture->south != NULL)
		return (print_int_error(TEXTURE_ERROR, SOUTH));
	data->texture->south = ft_strdup(data->conf->tokens[1]);
	data->texture->south[ft_strlen(data->texture->south) - 1] = '\0';
	if (!data->texture->south)
		return (EXIT_FAILURE);
	data->texture->t_south = mlx_load_png(data->texture->south);
	if (data->texture->t_south == (void *)false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	parse_east(t_data *data)
{
	if (data->texture->east != NULL)
		return (print_int_error(TEXTURE_ERROR, EAST));
	data->texture->east = ft_strdup(data->conf->tokens[1]);
	data->texture->east[ft_strlen(data->texture->east) - 1] = '\0';
	if (!data->texture->east)
		return (EXIT_FAILURE);
	data->texture->t_east = mlx_load_png(data->texture->east);
	if (data->texture->t_east == (void *)false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	parse_west(t_data *data)
{
	if (data->texture->west != NULL)
		return (print_int_error(TEXTURE_ERROR, WEST));
	data->texture->west = ft_strdup(data->conf->tokens[1]);
	data->texture->west[ft_strlen(data->texture->west) - 1] = '\0';
	if (!data->texture->west)
		return (EXIT_FAILURE);
	data->texture->t_west = mlx_load_png(data->texture->west);
	if (data->texture->t_west == (void *)false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
 * Saves textures images to be able to access them during the rendering process.
 * The images are stored with help of mlx_load_png function and stored in
 * 'mlx_texture' data-type.
 * There are 4 different textures images: north, south, east, west.
 * */
void	parse_textures(t_data *data, int token)
{
	int	ret;

	if (ft_splitlen(data->conf->tokens) != 2)
		ret = (print_int_error(INVALID_TOKEN, data->conf->line));
	else if (ft_strcmp(data->conf->tokens[1], "\n") == 0)
		ret = (print_int_error(INVALID_TOKEN, data->conf->line));
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
