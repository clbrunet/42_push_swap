/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:40:37 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/08 18:56:21 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared/shared_parsing.h"

void	option_error(char option)
{
	dputs(2, RED "checker: unknown option: '" BOLD);
	dputc(2, option);
	dputs(2, RESET RED "'\n" RESET);
	exit(EXIT_FAILURE);
}
