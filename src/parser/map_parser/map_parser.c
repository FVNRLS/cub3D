/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:52:59 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/22 15:41:32 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/cub3D.h"

void	parse_map(t_data *data)
{
	int ret;

	ret = create_map(data);
	if (ret == EXIT_FAILURE)
	{
		data->parse_error = true;
		return;
	}
	print_map(data);



//	check_map(data);
//	convert_map(); //?
	data->map_parsed = true;
}