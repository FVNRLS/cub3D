/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:57:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/18 11:06:49 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_loop(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->counter++;
	if (data->counter % 1000 == 0)
		render(data);
	if (data->counter == 1000000)
		data->counter = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.counter = 0;
	if (argc != 2)
		return (print_int_error(ARG_ERROR, NULL));
	init_environment(&data);
	data.conf->file = argv[1];
	parse_input(&data);
	if (data.parse_error == true)
		ft_free_all_and_exit(&data);
	init_bonus_objects(&data);
	update_minimap(&data);
	mlx_set_cursor_mode(data.mlx, MLX_MOUSE_HIDDEN);
	mlx_key_hook(data.mlx, &check_key_hooks, (void *)&data);
	mlx_cursor_hook(data.mlx, (void *)&check_cursor, (void *)&data);
	mlx_loop_hook(data.mlx, &render_loop, (void *)&data);
	mlx_loop(data.mlx);
	free_all_resources(&data);
	return (EXIT_SUCCESS);
}
