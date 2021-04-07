/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dput.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:47:08 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/07 09:01:52 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dput.h"

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
