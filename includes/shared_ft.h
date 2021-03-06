/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_ft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:57:22 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/13 10:13:02 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_FT_H
# define SHARED_FT_H

# include <string.h>

int			ft_isdigit(int c);
int			ft_isspace(int c);

size_t		ft_strlen(const char *s);
char		*ft_strcat(char *dest, const char *src);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
