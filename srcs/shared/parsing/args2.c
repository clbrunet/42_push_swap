/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 07:09:41 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/19 07:15:02 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_parsing.h"

long int	get_longv(const char **arg, char sign)
{
	long int	longv;

	longv = 0;
	while (ft_isdigit(**arg))
	{
		longv = longv * 10 + **arg - '0';
		(*arg)++;
	}
	return (longv * sign);
}
