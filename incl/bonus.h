/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:45:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/07 11:55:15 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# define MINIMAP_FACTOR	5
# define MINIMAP_SCOPE	10

//MINIMAP
void	init_bonus_objects(t_data *data);
void	update_minimap(t_data *data);
bool	check_wall(t_data *data, int x, int y, double step);
bool	check_collisions(t_data *data, double new_v[2]);
void	set_offset(t_data *data);
void	draw_player(t_data *data, double step);

//SPRITES
void	init_sprite(t_data *data);
void	draw_sprite(t_data *data);
void	sprite_collision(t_data *data, t_ray *ray, double camera_x);
void	get_x_coord_sprite(t_ray *ray, t_data *data);
int		get_texture_color_sprite(t_data *data, int y);

#endif
