/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:41:42 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/08 07:44:52 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <limits.h>

# include "debug.h"
# include "vars.h"
# include "display.h"
# include "dput.h"
# include "ft.h"

void		option_error(char option);

t_status	parse_args(const char *const *args, t_vars *v);
t_status	set_operations(const char *input, t_op_type *types);
t_status	parse_input(t_vars *v);

#endif
