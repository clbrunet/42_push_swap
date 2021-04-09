/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:08:46 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/09 09:10:33 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_execution.h"

void	reverse_rotate(t_stack *stack)
{
	int				tmp;
	unsigned int	i;

	if (stack->len < 2)
		return ;
	tmp = stack->arr[0];
	i = 0;
	while (i < stack->len - 1)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[i] = tmp;
}

void	reverse_rotate_both(t_vars *v)
{
	reverse_rotate(&v->a);
	reverse_rotate(&v->b);
}
