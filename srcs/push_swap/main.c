/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 06:02:23 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/13 07:55:35 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char *argv[])
{
	t_vars	v;

	if (argc == 1)
		return (0);
	if (parse_args((const char *const *)argv + 1, &v) == Failure)
		return (1);
	else if (v.a.len == 0)
		return (0);
	sort_stacks(&v);
	free(v.b.arr);
	free(v.a.arr);
	return (0);
}
