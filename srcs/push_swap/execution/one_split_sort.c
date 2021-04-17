/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_split_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 07:47:43 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/17 06:21:41 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static unsigned int	rotate_stack(t_vars *v, t_bool should_put)
{
	unsigned int	count;

	count = 0;
	while (v->a.arr[v->a.len - 1] > v->a.arr[0])
	{
		rotate(&v->a);
		if (should_put == True)
			dputs(1, "ra\n");
		count++;
	}
	return (count);
}

static unsigned int	merge_stacks(t_vars *v, t_bool should_put)
{
	unsigned int	count;

	count = 0;
	while (v->b.len)
	{
		if (v->b.arr[v->b.len - 1] < v->a.arr[v->a.len - 1]
			|| (v->a.arr[v->a.len - 1] < v->a.arr[0]
				&& v->b.arr[v->b.len - 1] > v->a.arr[0]))
		{
			push(&v->a, &v->b);
			if (should_put == True)
				dputs(1, "pa\n");
		}
		else
		{
			rotate(&v->a);
			if (should_put == True)
				dputs(1, "ra\n");
		}
		count++;
	}
	return (count);
}

unsigned int		one_split_sort(t_vars *v, t_bool should_put)
{
	unsigned int	count;
	unsigned int	len_backup;

	count = 0;
	len_backup = v->a.len;
	v->a.len /= 2;
	v->a.arr += len_backup - v->a.len;
	count += push_to_b(v, should_put);
	count += stack_rotate_sort(&v->b, 'b', &v->a, should_put);
	v->a.len = len_backup - v->b.len;
	v->a.arr -= v->a.len;
	v->b.arr += v->b.len;
	len_backup = v->b.len;
	v->b.len = 0;
	count += stack_rotate_sort(&v->a, 'a', &v->b, should_put);
	v->b.len = len_backup;
	v->b.arr -= len_backup;
	count += merge_stacks(v, should_put);
	count += rotate_stack(v, should_put);
	return (count);
}
