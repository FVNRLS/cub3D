/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:05:25 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/21 16:55:49 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define	MALLOC_ERROR		1
# define	ARG_ERROR			2
# define	INVALID_EXTENSION	3
# define	OPEN_ERROR			4
# define 	INVALID_TOKEN		5
# define	TEXTURE_ERROR		6
# define	COLOR_ERROR			7


void	print_error(int	error, char *s);
int 	print_int_error(int error, char *s);
void	*print_null_error(int error, char *s);

#endif
