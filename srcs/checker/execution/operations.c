/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:33:46 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/10 10:28:09 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	print_operation(t_op_type type)
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
