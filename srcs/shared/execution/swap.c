/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:58:48 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/09 09:10:14 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_execution.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->arr[stack->len - 1];
	stack->arr[stack->len - 1] = stack->arr[stack->len - 2];
	stack->arr[stack->len - 2] = tmp;
}

void	swap_both(t_vars *v)
{
	swap(&v->a);
	swap(&v->b);
}
