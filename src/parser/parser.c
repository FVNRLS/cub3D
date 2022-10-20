/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:50:41 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/19 16:33:14 by rmazurit         ###   ########.fr       */
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

static int check_first_token(t_data *data)
{
	return ()
}

static void	parse_line(t_data *data)
{
	char	*first;
	int 	item;

	data->conf->tokens = ft_split(data->line, SPACE[0]);
	if (!data->tokens)
		print_int_error(MALLOC_ERROR, NULL);
	first = data->tokens[0];

	if (ft_strcmp(first, "\n") == 0)
		return ;
	else if (ft_strcmp(first, "0") == 0 || (ft_strcmp(first, "1") == 0))
		parse_map(data);
	else
	{
		if (ft_strcmp(first, "C") == 0)
			parse_ceiling();
		else if (ft_strcmp(first, "F") == 0)
			parse_floor();
		else
			parse_textures(data);
	}
}

void	parse_input(t_data *data)
{
	bool	ext_valid;

	ext_valid = check_extension(data->conf);
	if (ext_valid == false)
		return(print_error(INVALID_EXTENSION, NULL));
	data->fd = open(data->conf, O_RDONLY, RIGHTS);
	if (data->fd < 0)
		return (print_error(OPEN_ERROR, NULL));
	while (true)
	{
		data->line = get_next_line(data->fd);
		if (!data->line || data->parse_error == true)
			break ;
		parse_line(data);
		free(data->line);
		data->line = NULL;
	}
	close(data->fd);

	printf("%s\n", data->texture->north);
	printf("%s\n", data->texture->south);
	printf("%s\n", data->texture->east);
	printf("%s\n", data->texture->west);
}


