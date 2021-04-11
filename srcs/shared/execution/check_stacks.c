/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:15:32 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/10 10:21:29 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_execution.h"

static t_bool	is_a_stack_sorted(const t_stack *a)
{
	unsigned int	i;

	i = 1;
	while (i < a->len)
	{
		if (a->arr[i - 1] < a->arr[i])
			return (False);
		i++;
	}
	return (True);
}

t_status	check_stacks(const t_vars *v)
{
	if (v->b.len == 0 && is_a_stack_sorted(&v->a) == True)
		return (Success);
	return (Failure);
}
