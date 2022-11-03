/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_dbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:48:26 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/02 19:50:15 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD
/* return the absolute value of a double */
double	ft_abs_dbl(double value)
{
	double	abs;

	if (abs < 0)
		return (abs * -1);
	return (abs);
}
=======
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
>>>>>>> 38223a195207b3123184be0af43ee986b9edcdf4
