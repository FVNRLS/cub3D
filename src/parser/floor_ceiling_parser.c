/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:49:12 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/07 17:51:31 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

/* extracts ceil RGB colors from the .cub fd. and converts them into HEX value*/
void	parse_ceiling(t_data *data)
{
	if (data->color->ceil != -1)
	{
		data->parse_error = true;
		return (print_error(COLOR_ERROR, "ceiling"));
	}
	data->color->ceil = get_color(data);
}

/* extracts floor RGB colors from the .cub fd. and converts them to HEX value */
void	parse_floor(t_data *data)
{
	if (data->color->floor != -1)
	{
		data->parse_error = true;
		return (print_error(COLOR_ERROR, "floor"));
	}
	data->color->floor = get_color(data);
}
