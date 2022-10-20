/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:49:12 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/20 18:52:06 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"


void	parse_ceiling(t_data *data)
{
	if (ft_splitlen(data->conf->tokens) != 2)
		return (print_error(INVALID_TOKEN, NULL));
	else
	{
		if (data->color->ceil != -1)
		{
			data->parse_error = true;
			return (print_error(TEXTURE_ERROR, WEST));
		}
		data->color->ceil = get_color(data);
		if (data->parse_error == true)
			return ;
	}
}

void	parse_floor(t_data *data)
{

}