/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:52:34 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/07 14:37:24 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"
#include "parsing.h"

int	main(int argc, char *argv[])
{
	t_vars	v;

	(void)argc;
	parse_args((const char *const *)argv + 1, &v);

	return (0);
}
