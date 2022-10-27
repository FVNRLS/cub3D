/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:45:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/27 13:26:43 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# define MINIMAP_FACTOR	2.5
# define MINIMAP_SCOPE	11

//MINIMAP
void	init_bonus_objects(t_data *data);
void	update_minimap(t_data *data);
bool	check_wall(t_data *data, int x, int y);

#endif
