/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:32:38 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/19 13:55:51 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

//TODO: cont here!

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
	}
}

static int	extract_texture_path(t_data *data, char *line)
{
	char **tokens;

	tokens = ft_split(line, SPACE);
	if (!tokens)
		return (print_int_error(MALLOC_ERROR, NULL));
	if (ft_splitlen(tokens) != 2)
		return (EXIT_SUCCESS);


	return (EXIT_SUCCESS);
}

void	parse_textures(t_data *data)
{
	char	*line;

	line = NULL;
	while (true)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		if (extract_texture_path(data, line) != EXIT_SUCCESS)
		{
			data->parse_error = true;
			return ;
		}
		free(line);
		line = NULL;
	}
}