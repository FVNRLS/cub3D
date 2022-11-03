/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_catcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:06:45 by rmazurit          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/28 13:40:59 by hoomen           ###   ########.fr       */
=======
/*   Updated: 2022/11/03 10:52:56 by rmazurit         ###   ########.fr       */
>>>>>>> 38223a195207b3123184be0af43ee986b9edcdf4
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
