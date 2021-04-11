/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:52:34 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/10 10:18:37 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	if (check_stacks(&v) == Success)
		dputs(1, "OK\n");
	else
		dputs(1, "KO\n");
	free(v.a.arr);
	return (0);
}
