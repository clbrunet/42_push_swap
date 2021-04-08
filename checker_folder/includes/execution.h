/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:34:28 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/08 09:17:35 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "vars.h"
# include "dput.h"

void	swap(t_stack *stack);
void	swap_both(t_vars *v);
void	push(t_stack *dest, t_stack *src);
void	rotate(t_stack *stack);
void	rotate_both(t_vars *v);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_both(t_vars *v);

void	execute_operations(t_vars *v);

#endif
