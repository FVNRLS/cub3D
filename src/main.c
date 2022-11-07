/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:57:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/07 15:04:41 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_leaks(void)
{
	system("leaks cub3D");
}

void	render_loop(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	update_minimap(data);
	render(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	atexit(check_leaks);
	if (argc != 2)
		return (print_int_error(ARG_ERROR, NULL));
	init_environment(&data);
	data.conf->file = argv[1];
	parse_input(&data);
	if (data.parse_error == true)
		ft_free_all_and_exit(&data);
	init_bonus_objects(&data);
	mlx_set_cursor_mode(data.mlx, MLX_MOUSE_HIDDEN);
	mlx_key_hook(data.mlx, &check_key_hooks, (void *)&data);
	mlx_cursor_hook(data.mlx, (void *)&check_cursor, (void *)&data);
	mlx_loop_hook(data.mlx, &render_loop, (void *)&data);
	mlx_loop(data.mlx);
	free_all_resources(&data);
	return (EXIT_SUCCESS);
}
