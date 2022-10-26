/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:09:03 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/26 17:05:10 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "../lib/minilibx/include/MLX42/MLX42_Int.h"

//META-FUNCTION
void	hooks_catcher_loop(t_data *data);

//KEY HOOKS
void	check_key_hooks(mlx_key_data_t keydata, void *param);
void	check_move_keys(t_data *data,  mlx_key_data_t keycode);
void 	check_rotation_keys(t_data *data, mlx_key_data_t keycode);

//MOUSE HOOKS
void	check_mouse_hooks(mlx_mouse_t mouse, void *param);

#endif
