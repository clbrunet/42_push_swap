/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 07:33:46 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/13 07:38:54 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	execute_operations(t_vars *v)
{
	unsigned int	i;

	i = 0;
	while (i < v->ops.len)
	{
		execute_operation(v, v->ops.arr[i]);
		i++;
	}
}
