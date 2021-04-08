/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dput.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:47:08 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/08 18:56:03 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared/dput.h"

int	dputc(int fd, int c)
{
	if (write(fd, (unsigned char *)&c, 1) == -1)
		return (EOF);
	return (0);
}

int	dputs(int fd, const char *s)
{
	if (write(fd, s, ft_strlen(s)) == -1)
		return (EOF);
	return (0);
}

int	dputn(int fd, int n)
{
	long int	l;

	l = n;
	if (l < 0)
	{
		if (dputc(fd, '-') == EOF)
			return (EOF);
		l = -l;
	}
	if (l > 9)
		dputn(fd, l / 10);
	if (dputc(fd, l % 10 + '0') == EOF)
		return (EOF);
	return (0);
}
