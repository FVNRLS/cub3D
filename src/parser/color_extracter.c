/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_extracter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:52:08 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/21 11:46:34 by rmazurit         ###   ########.fr       */
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

void 	reset_rgb_values(t_data *data)
{
	data->color->r = -1;
	data->color->g = -1;
	data->color->b = -1;
}

void	get_rgb_values(t_data *data, char **rgb)
{
	data->color->r = ft_atoi(rgb[0]);
	data->color->g = ft_atoi(rgb[1]);
	data->color->b = ft_atoi(rgb[2]);
}

//TODO: probably worthy to improve with ft_strtrim of every argument..
int	get_color(t_data *data)
{
	int		color;
	char	*color_str;
	char	**rgb;

	color_str = data->conf->tokens[1];
	rgb = ft_split(color_str, ',');
	if (!rgb)
	{
		print_error(MALLOC_ERROR, NULL);
		ft_free_all_and_exit(data);
	}
	if (ft_splitlen(rgb) != 3)
	{
		data->parse_error = true;
		return (print_int_error(INVALID_TOKEN, color_str));
	}
	get_rgb_values(data, rgb);
	color = convert_rgb_to_hex(data->color->r, data->color->g, data->color->b);
	printf("r: %d, g: %d, b: %d\n", data->color->r, data->color->g, data->color->b);
	printf("ceiling hex-color: %X\n", color);
	reset_rgb_values(data);
	ft_free_split(rgb);
	return (color);
}