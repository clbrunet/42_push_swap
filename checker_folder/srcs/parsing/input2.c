/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:26:45 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/08 11:58:26 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_status	set_operation(const char *input, t_op_type *type)
{
	if (ft_strncmp(input, "sa\n", 3) == 0)
		*type = Sa;
	else if (ft_strncmp(input, "sb\n", 3) == 0)
		*type = Sb;
	else if (ft_strncmp(input, "ss\n", 3) == 0)
		*type = Ss;
	else if (ft_strncmp(input, "pa\n", 3) == 0)
		*type = Pa;
	else if (ft_strncmp(input, "pb\n", 3) == 0)
		*type = Pb;
	else if (ft_strncmp(input, "ra\n", 3) == 0)
		*type = Ra;
	else if (ft_strncmp(input, "rb\n", 3) == 0)
		*type = Rb;
	else if (ft_strncmp(input, "rr\n", 3) == 0)
		*type = Rr;
	else if (ft_strncmp(input, "rra\n", 4) == 0)
		*type = RRa;
	else if (ft_strncmp(input, "rrb\n", 4) == 0)
		*type = RRb;
	else if (ft_strncmp(input, "rrr\n", 4) == 0)
		*type = RRr;
	else
		return (Failure);
	return (Success);
}

t_status	set_operations(const char *input, t_op_type *types)
{
	while (*input)
	{
		if (set_operation(input, types) == Failure)
			return (Failure);
		input += 2;
		if (*input != '\n')
			input++;
		types++;
		input++;
	}
	return (Success);
}
