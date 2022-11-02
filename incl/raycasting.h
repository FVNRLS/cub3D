/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:24:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/02 17:39:31 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "struct.h"

/* rays_minimap.c */
void	cast_rays(t_data *data, double step);

/* raycaster.c */
double	raycaster_loop(t_data *data);

#endif
