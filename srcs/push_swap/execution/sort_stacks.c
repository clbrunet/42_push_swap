/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 06:38:41 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/09 09:18:54 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	search_smallest(t_stack *a, int *smallest, unsigned int *smallest_index)
{
	unsigned int	i;

	i = 0;
	*smallest = INT_MAX;
	*smallest_index = 0;
	while (i < a->len)
	{
		if (a->arr[i] < *smallest)
		{
			*smallest = a->arr[i];
			*smallest_index = i;
		}
		i++;
	}
}

static void	go_up_smallest(t_stack *a)
{
	unsigned int	i;
	unsigned int	smallest_index;
	int				smallest;

	search_smallest(a, &smallest, &smallest_index);
	if (smallest_index > a->len / 2)
	{
		i = a->len - 1 - smallest_index;
		while (i)
		{
			dputs(1, "ra\n");
			rotate(a);
			i--;
		}
	}
	else
	{
		i = smallest_index + 1;
		while (i)
		{
			dputs(1, "rra\n");
			reverse_rotate(a);
			i--;
		}
	}
}

static void	rotate_sort(t_vars *v)
{
	while (v->a.len)
	{
		go_up_smallest(&v->a);
		dputs(1, "pb\n");
		push(&v->b, &v->a);
	}
	while (v->b.len)
	{
		dputs(1, "pa\n");
		push(&v->a, &v->b);
	}
}

void	sort_stacks(t_vars *v)
{
	rotate_sort(v);
}
