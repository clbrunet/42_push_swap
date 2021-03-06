/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 08:26:13 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/09 09:11:01 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_execution.h"

void	push(t_stack *dest, t_stack *src)
{
	if (src->len < 1)
		return ;
	src->len--;
	dest->arr[dest->len] = src->arr[src->len];
	dest->len++;
}
