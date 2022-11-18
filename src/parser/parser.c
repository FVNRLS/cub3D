/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:50:41 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/07 16:17:21 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

/* Checks extension of the configuration file .cub */
static bool	check_extension(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	s += len - 4;
	if (ft_strncmp(s, ".cub", 5) == 0)
		return (true);
	return (false);
}

/*
 * Interprets the first token and returns a flag.
 * Based on the flag value it will be decided, which element should be parsed.
 * */
static int	get_first_token(t_data *data, char *first)
{
	int		i;
	char	c;

	i = 0;
	while (data->conf->specs[i] != NULL)
	{
		if (ft_strcmp(first, data->conf->specs[i]) == 0)
			return (i);
		i++;
	}
	c = first[0];
	if (c == T_SPACE || c == ZERO || c == ONE)
		return (T_MAP);
	else
	{
		data->parse_error = true;
		return (T_INVALID);
	}
}

/*
 * Interprets content, returned by GNL in parse_args function.
 * Splits the content into tokens and decides based on the first token, which
 * map element is going to be parsed.
 * Ceiling and floor colors + textures should come before the map elements.
 * After map is parsed, the parsing ends.
 * */
static void	parse_line(t_data *data)
{
	char	*first;
	int		tok;

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

/*
 * CORE PARSING FUNCTION
 * reads .cub file with GNL and interprets its content, until the map is parsed.
 * The map should be always the last element of the configuration file.
 * Depending on the content different map elements are going to be parsed.
 * */
static int	parse_args(t_data *data)
{
	while (data->map_parsed == false)
	{
		data->conf->line = get_next_line(data->conf->fd);
		if (!data->conf->line)
			break ;
		parse_line(data);
		data->conf->line_num++;
		free(data->conf->line);
		data->conf->line = NULL;
		if (data->parse_error == true)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
 * Parses different elements of the game from specified .cub file.
 * Checks file extension, opens the file and reads information from it with help
 * of get_next_line (GNL) function.
 * During reading interprets and defines the elements values.
 * After parsing - checks if all elements were parsed successfully.
 * In case of any error during the different parsing stages
 * the data->parse_error flag is set to true, which causes free of all
 * allocated resources and termination of the program.
 * */
void	parse_input(t_data *data)
{
	bool	ext_valid;
	bool	all_args_parsed;

	ext_valid = check_extension(data->conf->file);
	if (ext_valid == false)
	{
		data->parse_error = true;
		return (print_error(INVALID_EXTENSION, NULL));
	}
	data->conf->fd = open(data->conf->file, O_RDONLY, RIGHTS);
	if (data->conf->fd < 0)
	{
		data->parse_error = true;
		return (print_error(OPEN_ERROR, NULL));
	}
	if (parse_args(data) == EXIT_SUCCESS)
	{
		all_args_parsed = (check_args(data) == false);
		if (all_args_parsed == false)
			data->parse_error = true;
	}
	close(data->conf->fd);
}
