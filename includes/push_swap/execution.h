/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 06:39:49 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/11 11:20:07 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdlib.h>
# include <limits.h>

# include "vars.h"
# include "shared_execution.h"
# include "shared_dput.h"

int				*int_arrdup(unsigned int len, const int *arr);
int				*int_arrcpy(int *dest, unsigned int len, const int *src);
t_op_type		*op_type_arrcpy(t_op_type *dest, unsigned int len,
					const t_op_type *src);
unsigned int	rotate_sort(t_vars *v, t_bool should_put);
unsigned int	merge_sort(t_vars *v, t_bool should_put);
unsigned int	perfect_sort(t_vars *v);

unsigned int	sort_stacks(t_vars *v);

#endif
