/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:36:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/18 18:57:54 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

int main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (print_int_error(ARG_ERROR));

	parse_input(&data, argv);

	return 0;
}
