/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:09:03 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/18 11:16:34 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "../lib/minilibx/include/MLX42/MLX42_Int.h"

# define ROTATION_RADIANS	0.1
# define STEP				0.15
# define ROTATE_RIGHT		1
# define ROTATE_LEFT		(-1)

//KEY HOOKS
void	check_key_hooks(mlx_key_data_t keydata, void *param);
void	check_move_keys(t_data *data, mlx_key_data_t keycode);
void	check_rotation_keys(t_data *data, mlx_key_data_t keycode);

//MOUSE HOOKS
void	*check_cursor(void *param);

//ROTATION
void	rotate(t_data *data, int direction);

#endif
