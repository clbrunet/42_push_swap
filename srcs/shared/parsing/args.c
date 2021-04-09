/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:27:58 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/09 09:12:34 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_parsing.h"

static const char *const	*parse_options(const char *const *args, t_vars *v)
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

static t_status	parse_integer(const char *arg, int *a_arr)
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
	*a_arr = longv;
	return (Success);
}

static t_status	check_duplicates(t_stack *a)
{
	int	*backup;
	int	*iter;
	int	current;

	iter = a->arr;
	while (iter < a->arr + a->len)
	{
		current = *iter;
		backup = ++iter;
		while (iter < a->arr + a->len)
		{
			if (*iter == current)
				return (Failure);
			iter++;
		}
		iter = backup;
	}
	return (Success);
}

static t_status	set_a_arr(const char *const *args, t_stack *a)
{
	int	*a_arr;

	a_arr = a->arr + a->len - 1;
	while (*args)
	{
		if (parse_integer(*args, a_arr) == Failure)
			return (Failure);
		a_arr--;
		args++;
	}
	if (check_duplicates(a) == Failure)
		return (Failure);
	return (Success);
}

t_status	parse_args(const char *const *args, t_vars *v)
{
	args = parse_options(args, v);
	v->a.len = 0;
	while (args[v->a.len])
		v->a.len++;
	if (v->a.len == 0)
		return (Success);
	v->a.arr = malloc(sizeof(int) * (v->a.len));
	if (v->a.arr == NULL)
		return (Failure);
	if (set_a_arr(args, &v->a) == Failure)
	{
		dputs(2, "Error\n");
		free(v->a.arr);
		return (Failure);
	}
	v->b.len = 0;
	v->b.arr = malloc(sizeof(int) * (v->a.len));
	if (v->b.arr == NULL)
	{
		free(v->a.arr);
		return (Failure);
	}
	return (Success);
}
