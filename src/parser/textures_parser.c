/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:09:01 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/19 16:32:02 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

static int	try_extraction(t_data *data, char **tokens)
{
	if (ft_strcmp(tokens[0], "NO") == 0)
	{
		if (data->texture->north != NULL)
			return (print_int_error(TEXTURE_ERROR, "NO"));
		data->texture->north = ft_strdup(tokens[1]);
	}
	else if (ft_strcmp(tokens[0], "SO") == 0)
	{
		if (data->texture->south != NULL)
			return (print_int_error(TEXTURE_ERROR, "SO"));
		data->texture->south = ft_strdup(tokens[1]);
	}
	else if (ft_strcmp(tokens[0], "EA") == 0)
	{
		if (data->texture->east != NULL)
			return (print_int_error(TEXTURE_ERROR, "EA"));
		data->texture->east = ft_strdup(tokens[1]);
	}
	else if (ft_strcmp(tokens[0], "WE") == 0)
	{
		if (data->texture->west != NULL)
			return (print_int_error(TEXTURE_ERROR, "WE"));
		data->texture->west = ft_strdup(tokens[1]);
	}
	return (EXIT_SUCCESS);
}

void	#(t_data *data)
{
	char	**tokens;

	tokens =
	if (!tokens)

	{
		if (try_extraction(data, tokens) == TEXTURE_ERROR)
		{
			ft_free_split(tokens);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
