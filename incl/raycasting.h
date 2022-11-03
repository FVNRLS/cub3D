/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:24:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/03 20:02:24 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "struct.h"

# define NOT_HIT	0
# define HIT_N		1
# define HIT_S		2
# define HIT_E		3
# define HIT_W		4
//todo: HIT_C when we hit a corner (both values are round integers)

/* rays_minimap.c */
void	cast_rays(t_data *data, double step);

/* raycaster.c */
double	raycaster_loop(t_data *data, t_render *render);

/* delta_calculator.c */
double	get_delta(double scalar, double ray_pos);
void	move_delta(t_data *data, t_ray *ray, double delta);

/* hit_checkers.c */
int	check_hit_vertical(t_data *data, t_ray *ray);
int	check_hit_horizontal(t_data *data, t_ray *ray);



#endif
