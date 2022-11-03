/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:24:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/02 17:39:31 by hoomen           ###   ########.fr       */
=======
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:24:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/03 12:11:35 by rmazurit         ###   ########.fr       */
>>>>>>> 38223a195207b3123184be0af43ee986b9edcdf4
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "struct.h"

/* rays_minimap.c */
void	cast_rays(t_data *data, double step);

/* raycaster.c */
double	raycaster_loop(t_data *data);

<<<<<<< HEAD
=======
/* delta_calculator.c */
double	get_delta(double scalar, double ray_pos);
void	move_delta(t_data *data, t_ray *ray, double delta);

/* hit_checkers.c */
bool	check_hit_vertical(t_data *data, t_ray *ray);
bool	check_hit_horizontal(t_data *data, t_ray *ray);



>>>>>>> 38223a195207b3123184be0af43ee986b9edcdf4
#endif
