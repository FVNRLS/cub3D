/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:49:12 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/21 16:56:36 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"


void	parse_ceiling(t_data *data)
{
	if (data->color->ceil != -1)
	{
		data->parse_error = true;
		return (print_error(COLOR_ERROR, "ceiling"));
	}
	data->color->ceil = get_color(data);
}

void	parse_floor(t_data *data)
{
	if (data->color->floor != -1)
	{
		data->parse_error = true;
		return (print_error(COLOR_ERROR, "floor"));
	}
	data->color->floor = get_color(data);
}