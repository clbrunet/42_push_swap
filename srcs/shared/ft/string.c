/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:58:19 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/13 10:12:30 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_ft.h"

size_t	ft_strlen(const char *s)
{
	const char	*iter;

	iter = s;
	while (*iter)
		iter++;
	return (iter - s);
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*iter;

	iter = dest;
	while (*iter)
		iter++;
	while (*src)
	{
		*iter = *src;
		iter++;
		src++;
	}
	*iter = 0;
	return (dest);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*u_s1;
	const unsigned char	*u_s2;

	if (!n)
		return (0);
	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	while (*u_s1 && *u_s1 == *u_s2 && --n)
	{
		u_s1++;
		u_s2++;
	}
	return ((int)(*u_s1 - *u_s2));
}
