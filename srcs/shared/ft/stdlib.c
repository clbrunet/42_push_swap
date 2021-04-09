/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:51:26 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/09 06:32:12 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_ft.h"

long int	ft_atol(const char *nptr)
{
	long int	n;
	char		sign;

	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	n = 0;
	while (ft_isdigit(*nptr))
	{
		n = n * 10 + *nptr - '0';
		nptr++;
	}
	return (n * sign);
}
