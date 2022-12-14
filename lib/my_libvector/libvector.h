/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:19:41 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/08 11:28:26 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECTOR_H
# define LIBVECTOR_H

# include <math.h>

/* ************************************************************************** */
/* DEFINES                                                                    */
/* ************************************************************************** */

# define X	0
# define Y	1
# define I	0
# define J	1

/* ************************************************************************** */
/* VECTOR ROTATION                                                            */
/* ************************************************************************** */

/* apply a transformation on a 2d vector by rotating it around the origin */
void	rotate_vector(double v[2], double angle);

#endif