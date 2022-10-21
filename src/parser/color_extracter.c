/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_extracter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:52:08 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/21 16:37:34 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

/*
	Separate colors and combine them back together with bit shifting method.
	The trgb paramter is always an int, represented as HEX Value.
*/

static int	convert_rgb_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static void	get_rgb_values(t_data *data, char **rgb)
{
	char	*r;
	char 	*g;
	char 	*b;

	r = ft_strtrim(rgb[0], " \n");
	g = ft_strtrim(rgb[1], " \n");
	b = ft_strtrim(rgb[2], " \n");
	data->color->r = ft_rgb_atoi(r);
	data->color->g = ft_rgb_atoi(g);
	data->color->b = ft_rgb_atoi(b);
	free(r);
	free(g);
	free(b);
}

static int	extract_hex_color(t_data *data, char **rgb)
{
	int color;

	get_rgb_values(data, rgb);
	if (data->color->r == -1 || data->color->g == -1 || data->color->b == -1)
		color = -1;
	else
		color = convert_rgb_to_hex(data->color->r, data->color->g,
								   data->color->b);
	data->color->r = -1;
	data->color->g = -1;
	data->color->b = -1;
	return (color);
}

static char	*join_arguments(t_data *data)
{
	int 	i;
	char	*res;
	int 	len;

	res = NULL;
	len = ft_splitlen(data->conf->tokens);
	i = 1;
	if (len == 2)
		res = ft_strdup(data->conf->tokens[1]);
	else
	{
		while (i < len)
		{
			res = ft_strjoin(res, data->conf->tokens[i]);
			if (!res)
				return (print_null_error(MALLOC_ERROR, NULL));
			i++;
		}
	}
	return (res);
}

int	get_color(t_data *data)
{
	int		color;
	char	*color_str;
	char	**rgb;

	color = -1;
	color_str = join_arguments(data);
	rgb = ft_split(color_str, ',');
	if (!color_str || !rgb)
	{
		data->parse_error = true;
		print_error(MALLOC_ERROR, NULL);
	}
	else if (ft_splitlen(rgb) != 3)
	{
		data->parse_error = true;
		print_error(INVALID_TOKEN, color_str);
	}
	else
		color = extract_hex_color(data, rgb);
	if (color == -1)
	{
		data->parse_error = true;
		print_error(INVALID_TOKEN, color_str);
	}
	ft_free_split(rgb);
	printf("rgb:	%s",color_str);
	printf("color:	%X\n",color);
	free(color_str);
	return (color);
}
