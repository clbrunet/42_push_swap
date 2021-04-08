/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:41:42 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/08 20:55:42 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_PARSING_H
# define SHARED_PARSING_H

# include <stdlib.h>
# include <limits.h>

# include "shared/debug.h"
# include "vars.h"
# include "shared/display.h"
# include "shared/dput.h"
# include "shared/ft.h"

void		option_error(char option);

t_status	parse_args(const char *const *args, t_vars *v);

#endif
