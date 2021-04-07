/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:27:58 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/07 13:50:21 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static const char *const	*parse_options(const char *const *args, t_vars *v)
{
	const char	*options;

	v->options.verbose = False;
	v->options.color = False;
	while (*args && **args == '-')
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

static t_status	parse_integer(const char *arg, int *a_stack)
{
	long int	longv;
	char		sign;

	if (*arg == '-')
	{
		sign = -1;
		arg++;
	}
	else
	{
		sign = 1;
		if (*arg == '+')
			arg++;
	}
	longv = 0;
	while (ft_isdigit(*arg))
	{
		longv = longv * 10 + *arg - '0';
		arg++;
	}
	longv *= sign;
	if (*arg || longv < INT_MIN || INT_MAX < longv)
		return (Failure);
	*a_stack = longv;
	return (Success);
}

static void	parse_a_stack(const char *const *args, t_vars *v)
{
	const char *const	*backup;
	int					*iter;

	backup = args;
	while (*args)
		args++;
	v->a.len = args - backup;
	v->a.stack = malloc(sizeof(int) * (v->a.len));
	if (v->a.stack == NULL)
		exit(EXIT_FAILURE);
	args = backup;
	iter = v->a.stack;
	while (*args)
	{
		if (parse_integer(*args, iter) == Failure)
			a_stack_error(v->a.stack);
		iter++;
		args++;
	}
}

void	parse_args(const char *const *args, t_vars *v)
{
	args = parse_options(args, v);
	if (*args == NULL)
		exit(EXIT_SUCCESS);
	parse_a_stack(args, v);
}
