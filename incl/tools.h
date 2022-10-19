/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:08:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/10/19 13:08:31 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdlib.h>

int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
bool	ft_isdigit(int c);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *s1);
int		ft_strcmp(char *s1, char *s2);
int		ft_splitlen(char **s);



#endif
