/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_sort_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:01:19 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/12 19:06:26 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	search_indexes_set_second_lowest(t_stack_indexes *indexes,
		int current, int index, int *second_lowest)
{
	*second_lowest = current;
	indexes->second_lowest = index;
}

static void	search_indexes_greatest_test(t_stack_indexes *indexes, int current,
		int index, int *greatest)
{
	if (current >= *greatest)
	{
		*greatest = current;
		indexes->greatest = index;
	}
}

void	search_indexes(t_stack_indexes *indexes, t_stack *dst)
{
	unsigned int	i;
	int				lowest;
	int				second_lowest;
	int				greatest;

	i = 0;
	lowest = INT_MAX;
	indexes->lowest = 0;
	second_lowest = INT_MAX;
	greatest = INT_MIN;
	while (i < dst->len)
	{
		if (dst->arr[i] <= lowest)
		{
			lowest = dst->arr[i];
			indexes->second_lowest = indexes->lowest;
			second_lowest = dst->arr[indexes->second_lowest];
			indexes->lowest = i;
		}
		else if (dst->arr[i] <= second_lowest)
			search_indexes_set_second_lowest(indexes, dst->arr[i], i,
				&second_lowest);
		search_indexes_greatest_test(indexes, dst->arr[i], i, &greatest);
		i++;
	}
}
