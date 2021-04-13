/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:41:42 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/13 07:55:19 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_PARSING_H
# define SHARED_PARSING_H

# include <stdlib.h>
# include <limits.h>

# include "shared_debug.h"
# include "shared_vars.h"
# include "shared_display.h"
# include "shared_dput.h"
# include "shared_ft.h"

t_status	parse_args(const char *const *args, t_vars *v);

#endif
