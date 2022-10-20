/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:50:41 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/20 12:24:30 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"


static bool check_extension(char *s)
{
	int len;

	len = ft_strlen(s);
	s += len - 4;
	if (ft_strncmp(s, ".cub", 5) == 0)
		return (true);
	return (false);
}

static int get_first_token(t_data *data, char *first)
{
	int 	i;
	char	c;

	i = 0;
	while (data->conf->specs[i] != NULL)
	{
		if (ft_strcmp(first, data->conf->specs[i]) == 0)
			return (i);
		i++;
	}
	c = first[0];
	if (c == T_SPACE || c == ZERO || c == ONE || c == PLAYER_N || c == PLAYER_S
		|| c == PLAYER_E || c == PLAYER_W)
		return (T_MAP);
	else
	{
		data->parse_error = true;
		return (T_INVALID);
	}
}

static void	parse_line(t_data *data)
{
	char	*first;
	int 	tok;

	data->conf->tokens = ft_split(data->conf->line, SPACE);
	if (!data->conf->tokens)
		print_int_error(MALLOC_ERROR, NULL);
	first = data->conf->tokens[0];
	tok = get_first_token(data, first);

	if (tok == T_INVALID)
		print_error(INVALID_TOKEN, first);
	else if (tok == T_NEWLINE)
	{
		ft_free_split(data->conf->tokens);
		return ;
	}
	else if (tok == T_NORTH || tok == T_SOUTH || tok == T_EAST || tok == T_WEST)
		parse_textures(data, tok);
	else if (tok == T_CEILING)
		parse_ceiling(data);
	else if (tok == T_FLOOR)
		parse_floor(data);
	else if (tok == T_MAP)
		parse_map(data);
	ft_free_split(data->conf->tokens);
}

void	parse_input(t_data *data)
{
	bool	ext_valid;

	ext_valid = check_extension(data->conf->file);
	if (ext_valid == false)
		return(print_error(INVALID_EXTENSION, NULL));
	data->conf->fd = open(data->conf->file, O_RDONLY, RIGHTS);
	if (data->conf->fd < 0)
		return (print_error(OPEN_ERROR, NULL));
	while (true)
	{
		data->conf->line = get_next_line(data->conf->fd);
		if (!data->conf->line)
			break ;
		parse_line(data);
		free(data->conf->line);
		data->conf->line = NULL;
		if (data->parse_error == true)
			break ;
	}
	close(data->conf->fd);

	printf("%s\n", data->texture->north);
	printf("%s\n", data->texture->south);
	printf("%s\n", data->texture->east);
	printf("%s\n", data->texture->west);
}

