/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:57:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/04 19:24:48 by hoomen           ###   ########.fr       */
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

	//atexit(check_leaks);
	if (argc != 2)
		return (print_int_error(ARG_ERROR, NULL));
	init_environment(&data);
	data.conf->file = argv[1];
	parse_input(&data);
	if (data.parse_error == true)
		ft_free_all_and_exit(&data);
	hooks_catcher_loop(&data);
	init_bonus_objects(&data);
	render(&data);
    mlx_loop(data.mlx);
	free_all_resources(&data);
	return (EXIT_SUCCESS);
}
