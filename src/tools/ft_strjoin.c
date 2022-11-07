/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:54:23 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/07 16:21:38 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Allocates memory with malloc() and returns a new string, which is the result
of the concatenation of ’str1’ and ’str2’.
Returns The new string / NULL if the allocation fails.
*/
char	*ft_strjoin(char *buf, char *tmp)
{
	int		i;
	int		j;
	char	*join;

	if (!tmp)
		return (buf);
	join = malloc(sizeof(char) * ((ft_strlen(buf) + ft_strlen(tmp)) + 1));
	if (!join)
		return (NULL);
	i = 0;
	if (buf != NULL)
	{
		while (buf[i] != '\0')
		{
			join[i] = buf[i];
			i++;
		}
		free(buf);
		buf = NULL;
	}
	j = 0;
	while (tmp[j] != '\0')
		join[i++] = tmp[j++];
	join[i] = '\0';
	return (join);
}
