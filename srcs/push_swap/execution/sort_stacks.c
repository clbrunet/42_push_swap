/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 06:38:41 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/17 06:40:38 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

unsigned int	sort_stacks(t_vars *v)
{
	unsigned int	count;

	if (check_stacks(v) == Success)
		return (0);
	else if (v->a.len <= 6)
		count = perfect_sort(v);
	else if (v->a.len <= 57)
		count = stack_rotate_sort(&v->a, 'a', &v->b, True);
	else if (v->a.len < 270)
		count = one_split_sort(v, True);
	else
		count = two_split_sort(v, True);
	return (count);
}
