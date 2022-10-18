//
// Created by Roman Mazuritskiy on 10/18/22.
//

/* The strlen() function takes a string as an argument and returns its length.
The returned value is of type size_t (the unsigned integer type).*/

#include "../../incl/cub3D.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}