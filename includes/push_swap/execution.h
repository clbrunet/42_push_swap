/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 06:39:49 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/16 21:15:56 by clbrunet         ###   ########.fr       */
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
void			search_indexes(t_stack_indexes *indexes, t_stack *dst);
void			set_closest_data(t_extremity_data *closest_data,
					unsigned int dst_len, t_stack_indexes *indexes,
					t_bool is_swap_needed);
void			set_closest_should_reverse(t_extremity_data *closest_data,
					unsigned int dst_len, t_stack_indexes *indexes);
void			go_up_closest(t_stack *dst, char dst_name,
					t_extremity_data *closest_data, t_bool should_put);
void			push_to_dst(t_stack *dst, char dst_name, t_stack *buf,
					t_bool should_put);
unsigned int	stack_rotate_sort(t_stack *dst, char dst_name,
					t_stack *buf, t_bool should_put);

unsigned int	one_split_sort(t_vars *v, t_bool should_put);

unsigned int	push_to_b(t_vars *v, t_bool should_put);
unsigned int	push_to_a(t_vars *v, t_bool should_put);
unsigned int	reverse_rotate_push_to_a(t_vars *v, t_bool should_put);
unsigned int	reverse_rotate_stack(t_stack *stack, char stack_name,
					t_bool should_put);
unsigned int	two_split_sort(t_vars *v, t_bool should_put);

unsigned int	perfect_sort(t_vars *v);

unsigned int	sort_stacks(t_vars *v);

#endif
