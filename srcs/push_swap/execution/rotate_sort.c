/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 06:07:32 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/11 07:18:10 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	search_smallest(t_stack *a, unsigned int *smallest_index)
{
	unsigned int	i;
	int				smallest;

	i = 0;
	smallest = INT_MAX;
	*smallest_index = 0;
	while (i < a->len)
	{
		if (a->arr[i] < smallest)
		{
			smallest = a->arr[i];
			*smallest_index = i;
		}
		i++;
	}
}

static void	set_rotation_attributes(unsigned int a_len,
		unsigned int smallest_index, unsigned int *i, t_bool *should_reverse)
{
	if (smallest_index > a_len / 2)
	{
		*should_reverse = False;
		*i = a_len - 1 - smallest_index;
	}
	else
	{
		*i = smallest_index + 1;
		*should_reverse = True;
	}
}

static void	go_up_smallest(t_stack *a, unsigned int *count, t_bool should_put)
{
	unsigned int	i;
	unsigned int	smallest_index;
	t_bool			should_reverse;

	search_smallest(a, &smallest_index);
	set_rotation_attributes(a->len, smallest_index, &i, &should_reverse);
	while (i)
	{
		if (should_put == True)
		{
			if (should_reverse == True)
				dputc(1, 'r');
			dputs(1, "ra\n");
		}
		(*count)++;
		if (should_reverse == True)
			reverse_rotate(a);
		else
			rotate(a);
		i--;
	}
}

unsigned int	rotate_sort(t_vars *v, t_bool should_put)
{
	unsigned int	count;

	count = 0;
	while (v->a.len)
	{
		go_up_smallest(&v->a, &count, should_put);
		if (should_put == True)
			dputs(1, "pb\n");
		count++;
		push(&v->b, &v->a);
	}
	while (v->b.len)
	{
		if (should_put == True)
			dputs(1, "pa\n");
		count++;
		push(&v->a, &v->b);
	}
	return (count);
}
