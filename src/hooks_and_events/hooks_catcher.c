/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_catcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:06:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/25 19:56:56 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

void	hooks_catcher_loop(t_data *data)
{
	mlx_key_hook(data->mlx, &check_key_hooks, data);
//	mlx_mouse_hook(data->mlx, check_mouse_hooks, NULL);
}
