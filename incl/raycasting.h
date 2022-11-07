/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:24:48 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/07 11:07:51 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "struct.h"

/* rays_minimap.c */
void	cast_rays(t_data *data, double step);

/* render.c */
void	render(t_data *data);

/* dda_initializer.c */
void	init_dda(t_data *data, t_ray *ray, double camera_x);

/* texture_xcalculator.c */
void	get_x_coord_texture(t_ray *ray, t_data *data);

/* texture_painter.c */
int		get_texture_color(t_data *data, t_render *rend, int y);
int		lookup_color(mlx_texture_t *texture, int x_coord, int y_coord);

#endif
