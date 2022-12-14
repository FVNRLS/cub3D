/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:37:56 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/07 15:52:27 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

/* Copies map objects from the buffer to the created rectangular map template */
static void	fill_map_with_objects(t_data *data)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < data->tab->max_y)
	{
		x = 0;
		while (data->tab->buf[i] != NEWLINE && data->tab->buf[i] != '\0')
		{
			if (x < data->tab->max_x && data->tab->buf[i] != SPACE)
				data->map[x][y] = data->tab->buf[i];
			i++;
			x++;
		}
		i++;
		y++;
	}
}

/*
 * Malloc map table and fills all slots with 0
 * */
static int	create_rectangular_map_template(t_data *data)
{
	int	x;
	int	y;

	data->tab->map = malloc(sizeof(char *) * (data->tab->max_x + 1));
	if (!data->tab->map)
		return (print_int_error(MALLOC_ERROR, NULL));
	x = 0;
	while (x < data->tab->max_x)
	{
		data->tab->map[x] = malloc(sizeof(char *) * (data->tab->max_y + 1));
		if (!data->tab->map[x])
			return (print_int_error(MALLOC_ERROR, NULL));
		y = 0;
		while (y < data->tab->max_y)
		{
			data->tab->map[x][y] = VOID;
			y++;
		}
		data->tab->map[x][y] = '\0';
		x++;
	}
	data->tab->map[x] = NULL;
	return (EXIT_SUCCESS);
}

/*
 * Calculates needed size to malloc for the rectangular 2D array.
 * Newline doesn't belong to the tab items, so the max. is = max-counter - 1
 * */
static void	calculate_map_size(t_data *data)
{
	int		i;
	int		cnt;
	char	*buf;

	buf = data->tab->buf;
	i = 0;
	cnt = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == NEWLINE || buf[i] == '\0')
		{
			if (cnt > data->tab->max_x)
				data->tab->max_x = cnt - 1;
			data->tab->max_y++;
			if (data->tab->max_y == INT_MAX)
				return ;
			cnt = 0;
		}
		i++;
		cnt++;
	}
}

/* Reads the total map from fd to a buffer with GNL function */
static int	read_map(t_data *data)
{
	int	line;

	line = 1;
	data->tab->buf = ft_strdup(data->conf->line);
	if (!data->tab->buf)
		return (print_int_error(MALLOC_ERROR, NULL));
	free(data->conf->line);
	data->conf->line = NULL;
	while (true)
	{
		data->conf->line = get_next_line(data->conf->fd);
		if (!data->conf->line)
			break ;
		if (data->conf->line[0] == NEWLINE)
			return (print_line_error(data, line));
		data->tab->buf = ft_strjoin(data->tab->buf, data->conf->line);
		if (!data->tab->buf)
			return (print_int_error(MALLOC_ERROR, NULL));
		free(data->conf->line);
		data->conf->line = NULL;
		line++;
	}
	return (EXIT_SUCCESS);
}

/*
 * Creates 2D array (map) with map objects inside.
 * Empty spaces are filled with VOID elements.
 * */
int	create_map(t_data *data)
{
	int	ret;

	ret = read_map(data);
	if (ret == EXIT_SUCCESS)
	{
		calculate_map_size(data);
		if (data->tab->max_y == INT_MAX)
		{
			printf("Error: Mapsize too big\n");
			return (EXIT_FAILURE);
		}
		ret = create_rectangular_map_template(data);
		if (ret == EXIT_SUCCESS)
		{
			data->map = data->tab->map;
			fill_map_with_objects(data);
		}
	}
	return (ret);
}
