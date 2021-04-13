/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:09:29 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/13 10:09:40 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static t_status	prepare_backtrack(t_vars *v, unsigned int *rotate_sort_count,
		t_op_type **ops)
{
	int		*a_arr_dup;

	a_arr_dup = int_arrdup(v->a.len, v->a.arr);
	if (a_arr_dup == NULL)
		return (Failure);
	*rotate_sort_count = stack_rotate_sort(&v->a, 'a', &v->b, False);
	int_arrcpy(v->a.arr, v->a.len, a_arr_dup);
	free(a_arr_dup);
	v->ops.arr = malloc(sizeof(t_op_type) * (*rotate_sort_count));
	if (v->ops.arr == NULL)
		return (Failure);
	*ops = malloc(sizeof(t_op_type) * (*rotate_sort_count));
	if (*ops == NULL)
	{
		free(v->ops.arr);
		return (Failure);
	}
	v->ops.len = *rotate_sort_count;
	return (Success);
}

static t_bool	is_op_type_valid(const t_vars *v, t_op_type *ops,
		unsigned int index, t_op_type new)
{
	t_op_type	previous;

	if ((v->a.len == 0 && new == Pb) || (v->b.len == 0 && new == Pa))
		return (False);
	else if (v->a.len < 2 && !(new == Sb || new == Pa || new == Pb
			|| new == Rb || new == RRb))
		return (False);
	else if (v->b.len < 2 && !(new == Sa || new == Pa || new == Pb
			|| new == Ra || new == RRa))
		return (False);
	else if (index == 0)
		return (True);
	previous = ops[index - 1];
	if ((Sa <= previous && previous <= Ss)
		&& (Sa <= previous && previous <= Ss))
		return (False);
	else if ((previous == Pa && new == Pb) || (previous == Pb && new == Pa))
		return (False);
	else if ((previous == Ra && new == Rb) || (previous == Rb && new == Ra)
		|| (previous == RRa && new == RRb)
		|| (previous == RRb && new == RRa) || (previous == Ra && new == RRa)
		|| (previous == Rb && new == RRb) || (previous == Rr && new == RRr))
		return (False);
	return (True);
}

static void		backtrack(t_vars *v, t_op_type *ops, unsigned int index)
{
	t_op_type	i;

	if (index >= v->ops.len - 1)
		return ;
	i = Sa;
	while (i <= RRr)
	{
		if (is_op_type_valid(v, ops, index, i))
		{
			ops[index] = i;
			execute_operation(v, i);
			if (check_stacks(v) == Success)
			{
				v->ops.len = index + 1;
				op_type_arrcpy(v->ops.arr, index + 1, ops);
				undo_operation(v, i);
				return ;
			}
			else
				backtrack(v, ops, index + 1);
			undo_operation(v, i);
		}
		i++;
	}
	return ;
}

unsigned int	perfect_sort(t_vars *v)
{
	unsigned int	rotate_sort_count;
	t_op_type		*ops;

	if (prepare_backtrack(v, &rotate_sort_count, &ops) == Failure)
		return (0);
	backtrack(v, ops, 0);
	free(ops);
	if (v->ops.len < rotate_sort_count)
		put_operations(&v->ops);
	else
		v->ops.len = stack_rotate_sort(&v->a, 'a', &v->b, True);
	free(v->ops.arr);
	return (v->ops.len);
}
