/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:27:58 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/19 06:57:52 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_parsing.h"

static unsigned int	get_stack_len(const char *const *args)
{
	unsigned int	count;
	const char		*arg;

	count = 0;
	while (*args)
	{
		arg = *args;
		while (ft_isspace(*arg))
			arg++;
		if (*arg == '-' || *arg == '+')
			arg++;
		while (ft_isdigit(*arg))
		{
			while (ft_isdigit(*arg))
				arg++;
			count++;
			while (ft_isspace(*arg))
				arg++;
			if (*arg == '-' || *arg == '+')
				arg++;
		}
		args++;
	}
	return (count);
}

static t_status		parse_integer(const char **arg, int *a_arr)
{
	long int	longv;
	char		sign;

	sign = 1;
	if (**arg == '-')
	{
		sign = -1;
		(*arg)++;
	}
	else if (**arg == '+')
		(*arg)++;
	longv = 0;
	while (ft_isdigit(**arg))
	{
		longv = longv * 10 + **arg - '0';
		(*arg)++;
	}
	while (ft_isspace(**arg))
		(*arg)++;
	longv *= sign;
	if ((**arg && !ft_isdigit(**arg) && **arg != '-' && **arg != '+')
		|| longv < INT_MIN || INT_MAX < longv)
		return (Failure);
	*a_arr = longv;
	return (Success);
}

static t_status		check_duplicates(t_stack *a)
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

static t_status		set_a_arr(const char *const *args, t_stack *a)
{
	int			*a_arr;
	const char	*arg;

	a_arr = a->arr + a->len - 1;
	while (*args)
	{
		arg = *args;
		while (ft_isspace(*arg))
			arg++;
		if (!*arg)
			return (Failure);
		while (*arg == '-' || *arg == '+' || ft_isdigit(*arg))
		{
			if (parse_integer(&arg, a_arr) == Failure)
				return (Failure);
			a_arr--;
		}
		if (*arg)
			return (Failure);
		args++;
	}
	if (check_duplicates(a) == Failure)
		return (Failure);
	return (Success);
}

t_status			parse_args(const char *const *args, t_vars *v)
{
	v->a.len = get_stack_len(args);
	if (v->a.len == 0)
	{
		dputs(2, "Error\n");
		return (Failure);
	}
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
