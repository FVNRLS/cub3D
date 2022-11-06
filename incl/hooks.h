/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:09:03 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/06 15:56:11 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "../lib/minilibx/include/MLX42/MLX42_Int.h"

# define ROTATION_RADIANS	0.1
# define STEP				0.3
# define MV_FORW			1
# define MV_BACKW			-1
# define ROTATE_RIGHT		1
# define ROTATE_LEFT		-1
# define MV_RIGHT			0
# define MV_LEFT			1

//META-FUNCTION
void	hooks_catcher_loop(t_data *data);

//KEY HOOKS
void	check_key_hooks(mlx_key_data_t keydata, void *param);
void	check_move_keys(t_data *data,  mlx_key_data_t keycode);
void 	check_rotation_keys(t_data *data, mlx_key_data_t keycode);

//MOUSE HOOKS
void	check_cursor(void *param);


//ROTATION
void	rotate(t_data *data, int direction);

#endif
