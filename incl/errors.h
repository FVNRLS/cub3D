/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:30:38 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/07 15:07:58 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define MALLOC_ERROR		1
# define ARG_ERROR			2
# define INVALID_EXTENSION	3
# define OPEN_ERROR			4
# define INVALID_TOKEN		5
# define TEXTURE_ERROR		6
# define COLOR_ERROR		7
# define INVALID_MAP		8
# define NO_TEXTURE			9
# define NO_COLOR			10
# define NO_PLAYER			11
# define NO_MAP				12

void	print_error(int error, char *s);
int		print_int_error(int error, char *s);
void	*print_null_error(int error, char *s);
int		print_line_error(t_data *data, int y_pos);
void	parse_error(t_data *data, int error, char *message);

#endif
