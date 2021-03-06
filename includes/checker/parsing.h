/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:41:42 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/09 06:24:10 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "shared_parsing.h"
# include "vars.h"

t_status	set_operations(const char *input, t_op_type *types);
t_status	parse_input(t_vars *v);

#endif
