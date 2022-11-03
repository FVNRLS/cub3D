/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:30:49 by rmazurit          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/02 19:51:25 by hoomen           ###   ########.fr       */
=======
/*   Updated: 2022/11/03 10:52:56 by rmazurit         ###   ########.fr       */
>>>>>>> 38223a195207b3123184be0af43ee986b9edcdf4
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdlib.h>
# include "struct.h"

int		ft_strlen(const char *s);
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
