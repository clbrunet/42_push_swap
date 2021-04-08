/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:52:34 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/08 15:57:06 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_bool	is_a_stack_sorted(t_stack *a)
{
	unsigned int	i;

	i = 1;
	while (i < a->len)
	{
		if (a->arr[i - 1] < a->arr[i])
			return (False);
		i++;
	}
	return (True);
}

void	checker(t_vars *v)
{
	if (v->b.len == 0 && is_a_stack_sorted(&v->a) == True)
		dputs(1, "OK\n");
	else
		dputs(1, "KO\n");
}

int	main(int argc, char *argv[])
{
	t_vars	v;

	(void)argc;
	if (parse_args((const char *const *)argv + 1, &v) == Failure)
		return (1);
	else if (v.a.len == 0)
		return (0);
	if (parse_input(&v) == Failure)
	{
		free(v.a.arr);
		free(v.b.arr);
		return (1);
	}
	execute_operations(&v);
	free(v.ops.arr);
	free(v.b.arr);
	checker(&v);
	free(v.a.arr);
	return (0);
}
