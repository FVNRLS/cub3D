/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_catcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:06:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/03 13:25:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3D.h"

void	hooks_catcher_loop(void *param)
{
    t_data *data;

    data = (t_data *) param;
    mlx_key_hook(data->mlx, &check_key_hooks, data);
//    bool mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param);

    mlx_mouse_hook(data->mlx, (mlx_mousefunc)&check_mouse_hooks, data);
}
