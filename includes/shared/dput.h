/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dput.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:16:03 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/08 11:10:31 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DPUT_H
# define DPUT_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# include "ft.h"

int	dputc(int fd, int c);
int	dputs(int fd, const char *s);
int	dputn(int fd, int n);

#endif
