/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:09:03 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/26 10:47:41 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

//META-FUNCTION
void	hooks_catcher_loop(t_data *data);

//KEY HOOKS
void 	check_key_hooks(mlx_key_data_t keydata, void *param);

//MOUSE HOOKS
void 	check_mouse_hooks(void *param);

#endif
