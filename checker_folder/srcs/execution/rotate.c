/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 08:45:28 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/08 09:06:17 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->len < 2)
		return ;
	i = stack->len - 1;
	tmp = stack->arr[i];
	while (i)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = tmp;
}

void	rotate_both(t_vars *v)
{
	rotate(&v->a);
	rotate(&v->b);
}
