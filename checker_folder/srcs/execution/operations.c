/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:33:46 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/08 11:55:48 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	print_operation(t_op_type type)
{
	if (type == Sa)
		dputs(1, "Swap a :\n");
	else if (type == Sb)
		dputs(1, "Swap b :\n");
	else if (type == Ss)
		dputs(1, "Swap both :\n");
	else if (type == Pa)
		dputs(1, "Push a :\n");
	else if (type == Pb)
		dputs(1, "Push b :\n");
	else if (type == Ra)
		dputs(1, "Rotate a :\n");
	else if (type == Rb)
		dputs(1, "Rotate b :\n");
	else if (type == Rr)
		dputs(1, "Rotate both :\n");
	else if (type == RRa)
		dputs(1, "Reverse rotate a :\n");
	else if (type == RRb)
		dputs(1, "Reverse rotate b :\n");
	else if (type == RRr)
		dputs(1, "Reverse rotate both :\n");
}

void	print_state(const t_vars *v)
{
	unsigned int	index;

	dputc(1, '\n');
	if (v->a.len > v->b.len)
		index = v->a.len - 1;
	else
		index = v->b.len - 1;
	while ((int)index >= 0)
	{
		if (index < v->a.len)
			printf("%-11d\t", v->a.arr[index]);
		else
			printf("\t\t");
		if (index < v->b.len)
			printf("%d", v->b.arr[index]);
		printf("\n");
		index--;
	}
	dputs(1, "-\t\t-\n");
	dputs(1, "a\t\tb\n");
	dputs(1, "---------------------------\n");
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

void	execute_operations(t_vars *v)
{
	unsigned int	i;

	if (v->options.verbose == True)
	{
		dputs(1, "---------------------------\nBeginning :\n");
		print_state(v);
	}
	i = 0;
	while (i < v->ops.len)
	{
		execute_operation(v, v->ops.arr[i]);
		if (v->options.verbose == True)
		{
			print_operation(v->ops.arr[i]);
			print_state(v);
		}
		i++;
	}
}
