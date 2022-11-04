/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:24:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/04 17:33:20 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "struct.h"

/* rays_minimap.c */
void	cast_rays(t_data *data, double step);

/* raycaster.c */
double	raycaster_loop(t_data *data);

/* delta_calculator.c */
double	get_delta(double scalar, double ray_pos);
void	move_delta(t_data *data, t_ray *ray, double delta);

/* hit_checkers.c */
bool	check_hit_vertical(t_data *data, t_ray *ray);
bool	check_hit_horizontal(t_data *data, t_ray *ray);

/* render.c */
void	render(t_data *data);
void	init_dda(t_data *data, t_ray *ray, double camera_x);

#endif
