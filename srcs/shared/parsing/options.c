/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:25:12 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/09 14:25:52 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_parsing.h"

static void	option_error(char option)
{
	dputs(2, RED "checker: unknown option: '" BOLD);
	dputc(2, option);
	dputs(2, RESET RED "'\n" RESET);
	exit(EXIT_FAILURE);
}

const char *const	*parse_options(const char *const *args, t_vars *v)
{
	const char	*options;

	v->options.verbose = False;
	v->options.color = False;
	while (*args && **args == '-' && !ft_isdigit(*(*args + 1)))
	{
		options = *args + 1;
		while (*options)
		{
			if (*options == 'v')
				v->options.verbose = True;
			else if (*options == 'c')
				v->options.color = True;
			else
				option_error(*options);
			options++;
		}
		args++;
	}
	return (args);
}
