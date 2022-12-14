/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:30:49 by rmazurit          #+#    #+#             */
/*   Updated: 2022/11/07 14:37:22 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdlib.h>
# include "struct.h"

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
bool	ft_isdigit(int c);
int		ft_rgb_atoi(char *str);
char	*ft_strdup(char *s1);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_splitlen(char **s);
void	ft_free_split(char **split);
void	ft_free_all_and_exit(t_data *data);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char *buf, char *tmp);
char	*ft_itoa(int n);
double	ft_degree_to_radian(double angle);
double	ft_abs_dbl(double value);

#endif
