/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_split_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:14:35 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/17 06:17:31 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

unsigned int	push_to_b(t_vars *v, t_bool should_put)
{
	unsigned int	count;

	count = v->a.len;
	while (v->a.len)
	{
		push(&v->b, &v->a);
		if (should_put == True)
			dputs(1, "pb\n");
	}
	return (count);
}

unsigned int	push_to_a(t_vars *v, t_bool should_put)
{
	unsigned int	count;

	count = v->b.len;
	while (v->b.len)
	{
		push(&v->a, &v->b);
		if (should_put == True)
			dputs(1, "pa\n");
	}
	return (count);
}

unsigned int	reverse_rotate_push_to_a(t_vars *v, t_bool should_put)
{
	unsigned int	count;

	count = v->b.len;
	while (v->b.len)
	{
		if (v->b.len > 1)
		{
			reverse_rotate(&v->b);
			if (should_put)
				dputs(1, "rrb\n");
			count++;
		}
		push(&v->a, &v->b);
		if (should_put == True)
			dputs(1, "pa\n");
	}
	return (count);
}

unsigned int	reverse_rotate_stack(t_stack *stack, char stack_name,
		t_bool should_put)
{
	unsigned int	count;

	count = 0;
	while (stack->arr[stack->len - 1] > stack->arr[0])
	{
		reverse_rotate(stack);
		if (should_put == True)
		{
			dputs(1, "rr");
			dputc(1, stack_name);
			dputc(1, '\n');
		}
		count++;
	}
	return (count);
}
