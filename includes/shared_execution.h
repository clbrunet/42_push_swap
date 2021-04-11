/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_execution.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:34:28 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/11 07:27:36 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_EXECUTION_H
# define SHARED_EXECUTION_H

# include "shared_vars.h"
# include "shared_dput.h"

void		swap(t_stack *stack);
void		swap_both(t_vars *v);
void		push(t_stack *dest, t_stack *src);
void		rotate(t_stack *stack);
void		rotate_both(t_vars *v);
void		reverse_rotate(t_stack *stack);
void		reverse_rotate_both(t_vars *v);

void		print_state(const t_vars *v);
void		put_operation(t_op_type type);
void		put_operations(t_operations *ops);
void		undo_operation(t_vars *v, t_op_type type);
void		execute_operation(t_vars *v, t_op_type type);
t_status	check_stacks(const t_vars *v);

#endif
