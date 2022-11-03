/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:45:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/03 13:46:40 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# define MINIMAP_FACTOR	2.5
# define MINIMAP_SCOPE	10

//MINIMAP
void	init_bonus_objects(t_data *data);
void	update_minimap(t_data *data);
bool	check_wall(t_data *data, int x, int y, double step);
bool	check_collisions(t_data *data, double new_v[2]);
void	set_offset(t_data *data);
void	draw_player(t_data *data, double step);

#endif
