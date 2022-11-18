/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_dbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:48:26 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/03 13:23:00 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
/* return the absolute value of a double */
double	ft_abs_dbl(double value)
{
	if (value == DBL_MIN)
		return (0);
	if (value < 0)
		return (value * -1);
	return (value);
}
