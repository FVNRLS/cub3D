/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:09:03 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/25 19:53:04 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

//KEYBOARD HOOKS
# define A 			0
# define S 			1
# define D 			2
# define W 			13
# define ESC 		53

//ARROW KEYS HOOKS
# define UP 		126
# define DOWN 		125
# define LEFT 		123
# define RIGHT		124

//HOOKS FUNCTIONS
void	hooks_catcher_loop(t_data *data);
//KEY HOOKS FUNCTIONS
void 	check_key_hooks(mlx_key_data_t keydata, void *data);
int		check_mouse_hooks(t_data *data);
//MOUSE HOOKS FUNCTIONS

#endif
