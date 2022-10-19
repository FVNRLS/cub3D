/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:35:44 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/19 12:47:29 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3D.h"

void	check_leaks(void)
{
	system("leaks cub3D");
}

int main(int argc, char **argv)
{
	t_data	data;

//	atexit(check_leaks);
	if (argc != 2)
		return (print_int_error(ARG_ERROR, NULL));
	data.conf = argv[1];
	init_environment(&data);
	parse_input(&data);

	free_all_resources(&data);
	return (EXIT_SUCCESS);
}
