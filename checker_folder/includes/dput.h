/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dput.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 08:47:26 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/07 13:48:02 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_C
# define FT_PUT_C

# include <unistd.h>

# include "ft.h"

int	dputc(int fd, int c);
int	dputs(int fd, const char *s);

#endif
