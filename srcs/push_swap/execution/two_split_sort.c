/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_split_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 07:47:43 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/17 06:13:40 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void			merge_stacks_action(t_vars *v, t_bool should_put,
		unsigned int *push_count)
{
	if (v->a.arr[v->a.len - 1] > v->b.arr[0]
			|| (v->b.arr[v->b.len - 1] < v->b.arr[0]
				&& v->a.arr[v->a.len - 1] < v->b.arr[v->b.len - 1]))
	{
		push(&v->b, &v->a);
		if (should_put == True)
			dputs(1, "pb\n");
		(*push_count)++;
	}
	else
	{
		reverse_rotate(&v->b);
		if (should_put == True)
			dputs(1, "rrb\n");
	}
}

static unsigned int	merge_stacks(t_vars *v, t_bool should_put)
{
	unsigned int	count;
	unsigned int	push_count;
	unsigned int	len_4;

	len_4 = (v->a.len + v->b.len) / 4;
	count = 0;
	push_count = 0;
	while (v->a.len)
	{
		merge_stacks_action(v, should_put, &push_count);
		if (push_count == len_4)
		{
			push_count = 0;
			count += reverse_rotate_stack(&v->b, 'b', should_put);
		}
		count++;
	}
	return (count);
}

static unsigned int	n_reverse_rotate(t_stack *stack, char stack_name,
		int n, t_bool should_put)
{
	int	i;

	i = 0;
	while (i < n)
	{
		reverse_rotate(stack);
		if (should_put == True)
		{
			dputs(1, "rr");
			dputc(1, stack_name);
			dputc(1, '\n');
		}
		i++;
	}
	return (n);
}

static unsigned int	last_stack_rotate_sort(t_vars *v, t_bool should_put,
		unsigned int len_backup)
{
	unsigned int	count;

	count = 0;
	count += n_reverse_rotate(&v->a, 'a', v->a.len % 4, should_put);
	v->a.len = v->a.len / 4 + v->a.len % 4;
	v->a.arr += len_backup - v->a.len;
	count += push_to_b(v, should_put);
	count += stack_rotate_sort(&v->b, 'b', &v->a, should_put);
	v->a.arr -= len_backup - v->b.len;
	v->a.len = len_backup - v->b.len;
	return (count);
}

unsigned int		two_split_sort(t_vars *v, t_bool should_put)
{
	unsigned int	count;
	unsigned int	len_backup;
	unsigned int	i;

	count = 0;
	len_backup = v->a.len;
	i = 0;
	while (i < 3)
	{
		v->a.len /= 4;
		v->a.arr += len_backup - v->a.len;
		count += push_to_b(v, should_put);
		count += stack_rotate_sort(&v->b, 'b', &v->a, should_put);
		count += push_to_a(v, should_put);
		v->a.arr -= len_backup - v->a.len;
		v->a.len = len_backup;
		count += n_reverse_rotate(&v->a, 'a', v->a.len / 4, should_put);
		i++;
	}
	count += last_stack_rotate_sort(v, should_put, len_backup);
	count += merge_stacks(v, should_put);
	count += reverse_rotate_push_to_a(v, should_put);
	return (count);
}
