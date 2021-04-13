/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 11:24:15 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/13 07:39:46 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_execution.h"

void	undo_operation(t_vars *v, t_op_type type)
{
	if (type == Sa)
		swap(&v->a);
	else if (type == Sb)
		swap(&v->b);
	else if (type == Ss)
		swap_both(v);
	else if (type == Pa)
		push(&v->b, &v->a);
	else if (type == Pb)
		push(&v->a, &v->b);
	else if (type == Ra)
		reverse_rotate(&v->a);
	else if (type == Rb)
		reverse_rotate(&v->b);
	else if (type == Rr)
		reverse_rotate_both(v);
	else if (type == RRa)
		rotate(&v->a);
	else if (type == RRb)
		rotate(&v->b);
	else if (type == RRr)
		rotate_both(v);
}

void	execute_operation(t_vars *v, t_op_type type)
{
	if (type == Sa)
		swap(&v->a);
	else if (type == Sb)
		swap(&v->b);
	else if (type == Ss)
		swap_both(v);
	else if (type == Pa)
		push(&v->a, &v->b);
	else if (type == Pb)
		push(&v->b, &v->a);
	else if (type == Ra)
		rotate(&v->a);
	else if (type == Rb)
		rotate(&v->b);
	else if (type == Rr)
		rotate_both(v);
	else if (type == RRa)
		reverse_rotate(&v->a);
	else if (type == RRb)
		reverse_rotate(&v->b);
	else if (type == RRr)
		reverse_rotate_both(v);
}

void	put_operation(t_op_type type)
{
	if (type == Sa)
		dputs(1, "sa\n");
	else if (type == Sb)
		dputs(1, "sb\n");
	else if (type == Ss)
		dputs(1, "ss\n");
	else if (type == Pa)
		dputs(1, "pa\n");
	else if (type == Pb)
		dputs(1, "pb\n");
	else if (type == Ra)
		dputs(1, "ra\n");
	else if (type == Rb)
		dputs(1, "rb\n");
	else if (type == Rr)
		dputs(1, "rr\n");
	else if (type == RRa)
		dputs(1, "rra\n");
	else if (type == RRb)
		dputs(1, "rrb\n");
	else if (type == RRr)
		dputs(1, "rrr\n");
}

void	put_operations(t_operations *ops)
{
	t_op_type	*iter;

	iter = ops->arr;
	while (ops->len)
	{
		put_operation(*iter);
		iter++;
		ops->len--;
	}
}
