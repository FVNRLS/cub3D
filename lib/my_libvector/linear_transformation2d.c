/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_transformation2d.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:53:41 by hoomen            #+#    #+#             */
/*   Updated: 2022/10/31 19:42:25 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

// #include <stdio.h>

/* transform a vector v = {x, y} by applying the transformation matrix 
 * t = {{ix, iy}, {jx, jy}}
 */
void	linear_transformation2d(double v[2], double t[2][2])
{
	double	transf_x;
	double	transf_y;

	transf_x = (v[X] * t[I][X]) + (v[Y] * t[J][X]);
	transf_y = (v[X] * t[I][Y]) + (v[Y] * t[J][Y]);

	v[X] = transf_x;
	v[Y] = transf_y;
}

// /* test linear transformation */
// int main(void)
// {
// 	int r_left[2][2];
// 	int v[2];

// 	r_left[I][X] = 0;
// 	r_left[I][Y] = 1;
// 	r_left[J][X] = -1;
// 	r_left[J][Y] = 0;

// 	v[X] = 0;
// 	v[Y] = 1;

// 	linear_transformation2d(v, r_left);
// 	printf("v[X] = %i, v[Y] = %i\n", v[X], v[Y]);
// }

	/* ************************************************************* */
	/*                                                               */
	/*     a = t[I][X]    =    0                                     */
	/*     b = t[J][X]    =   -1                                     */
	/*     c = t[I][Y]    =    1                                     */
	/*     d = t[J][Y]    =    0                                     */
	/*                                                               */
	/*     x = v[X]       =    0                                     */
	/*     y = v[Y]       =    1                                     */
	/*                                                               */
	/*     a * x ==> 0 * 0 = 0                                       */
	/*     b * y ==> -1 * 1 = -1                                     */
	/*     c * x ==> 1 * 0 = 0                                       */
	/*     d * y ==> 0 * 1 = 0                                       */
	/*                                                               */
	/*                                                               */
	/*                                                               */
	/*     transformation principle:                                 */
	/*                                                               */
	/*     {{a, c}, {b, d}} * {x, y} =                               */
	/*                 {(a * x) + (b * y)} + {(c * x) + (d * y)}     */
	/*                                                               */
	/*                                                               */
	/* ************************************************************* */
