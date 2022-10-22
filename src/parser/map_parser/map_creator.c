/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:37:56 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/22 16:21:34 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

static void fill_map_with_objects(t_data *data)
{
	int 	x;
	int 	y;
	int 	i;

	y = 0;
	i = 0;
	while (y < data->tab->max_y)
	{
		x = 0;
		while (data->tab->buf[i] != NEWLINE && data->tab->buf[i] != '\0')
		{
			if (data->tab->buf[i] != SPACE)
				data->map[x][y] = data->tab->buf[i];
			i++;
			x++;
		}
		i++;
		y++;
	}
}

/*
 * Malloc map table and fill all slots with 0
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
			data->tab->map[x][y] = FILLER;
			y++;
		}
		data->tab->map[x][y] = '\0';
		x++;
	}
	data->tab->map[x] = NULL;
	return (EXIT_SUCCESS);
}

/*
 * Needed size to malloc for the rectangular 2D array.
 * Newline doesn't belong to the tab items, so the max. is = max-counter - 1
 * */
static void	calculate_map_size(t_data *data)
{
	int 	i;
	int 	cnt;
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
			cnt = 0;
		}
		i++;
		cnt++;
	}
}

static int	read_map(t_data *data)
{
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
		data->tab->buf = ft_strjoin(data->tab->buf, data->conf->line);
		if (!data->tab->buf)
			return (print_int_error(MALLOC_ERROR, NULL));
		free(data->conf->line);
		data->conf->line = NULL;
	}
	return (EXIT_SUCCESS);
}

int	create_map(t_data *data)
{
	int ret;

	ret = read_map(data);
	if (ret == EXIT_SUCCESS)
	{
		calculate_map_size(data);
		ret = create_rectangular_map_template(data);
		if (ret == EXIT_SUCCESS)
		{
			data->map = data->tab->map;
			fill_map_with_objects(data);
		}
	}
	return (ret);
}

