/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 07:47:43 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/11 17:16:47 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	search_smallest(t_stack *b, unsigned int *smallest_index)
{
	unsigned int	i;
	int				smallest;

	i = 0;
	smallest = INT_MAX;
	*smallest_index = 0;
	while (i < b->len)
	{
		if (b->arr[i] < smallest)
		{
			smallest = b->arr[i];
			*smallest_index = i;
		}
		i++;
	}
}

static void	set_rotation_attributes(unsigned int b_len,
		unsigned int smallest_index, unsigned int *i, t_bool *should_reverse)
{
	if (smallest_index > b_len / 2)
	{
		*should_reverse = False;
		*i = b_len - 1 - smallest_index;
	}
	else
	{
		*i = smallest_index + 1;
		*should_reverse = True;
	}
}

static void	go_up_smallest(t_stack *b, unsigned int *count, t_bool should_put)
{
	unsigned int	i;
	unsigned int	smallest_index;
	t_bool			should_reverse;

	search_smallest(b, &smallest_index);
	set_rotation_attributes(b->len, smallest_index, &i, &should_reverse);
	while (i)
	{
		if (should_put == True)
		{
			if (should_reverse == True)
				dputc(1, 'r');
			dputs(1, "rb\n");
		}
		(*count)++;
		if (should_reverse == True)
			reverse_rotate(b);
		else
			rotate(b);
		i--;
	}
}

unsigned int	b_rotate_sort(t_vars *v, t_bool should_put)
{
	unsigned int	count;

	count = 0;
	while (v->b.len)
	{
		go_up_smallest(&v->b, &count, should_put);
		if (should_put == True)
			dputs(1, "pa\n");
		count++;
		push(&v->a, &v->b);
	}
	while (v->a.len)
	{
		if (should_put == True)
			dputs(1, "pb\n");
		count++;
		push(&v->b, &v->a);
	}
	return (count);
}

static void	merge_stacks(t_vars *v, t_bool should_put)
{
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
	}
	while (v->a.arr[v->a.len - 1] > v->a.arr[0])
	{
		rotate(&v->a);
		if (should_put == True)
			dputs(1, "ra\n");
	}
}

unsigned int	merge_sort(t_vars *v, t_bool should_put)
{
	unsigned int	len_backup;

	len_backup = v->a.len;
	v->a.len /= 2;
	v->a.arr += len_backup - v->a.len;
	while (v->a.len)
	{
		push(&v->b, &v->a);
		if (should_put == True)
			dputs(1, "pb\n");
	}
	b_rotate_sort(v, True);
	v->a.len = len_backup - v->b.len;
	v->a.arr -= v->a.len;
	v->b.arr += v->b.len;
	len_backup = v->b.len;
	v->b.len = 0;
	rotate_sort(v, True);
	v->b.len = len_backup;
	v->b.arr -= len_backup;
	merge_stacks(v, should_put);
	return (0);
}
