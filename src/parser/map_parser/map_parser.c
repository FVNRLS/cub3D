/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:52:59 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/07 16:10:24 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

void	parse_map(t_data *data)
{
	if (create_map(data) == EXIT_FAILURE)
		data->parse_error = true;
	if (data->parse_error == false)
	{
		parse_player(data);
		if (data->parse_error == false && data->player->dir == VOID)
		{
			data->parse_error = true;
			return (print_error(NO_PLAYER, NULL));
		}
	}
	if (data->parse_error == false)
		check_map_borders(data);
	if (data->parse_error == false)
		check_invalid_void_spaces(data);
	data->map_parsed = true;
}
