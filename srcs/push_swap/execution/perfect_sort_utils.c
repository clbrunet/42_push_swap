/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_sort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 07:20:09 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/13 10:10:02 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int			*int_arrdup(unsigned int len, const int *arr)
{
	int	*dup;
	int	*iter;

	dup = malloc(sizeof(int) * (len));
	if (dup == NULL)
		return (NULL);
	iter = dup;
	while (len)
	{
		*iter = *arr;
		iter++;
		arr++;
		len--;
	}
	return (dup);
}

int			*int_arrcpy(int *dest, unsigned int len, const int *src)
{
	int	*iter;

	iter = dest;
	while (len)
	{
		*iter = *src;
		iter++;
		src++;
		len--;
	}
	return (dest);
}

t_op_type	*op_type_arrcpy(t_op_type *dest, unsigned int len,
		const t_op_type *src)
{
	t_op_type	*iter;

	iter = dest;
	while (len)
	{
		*iter = *src;
		iter++;
		src++;
		len--;
	}
	return (dest);
}
