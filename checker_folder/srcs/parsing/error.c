/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:40:37 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/07 14:27:50 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	option_error(char option)
{
	dputs(2, RED "checker: unknown option: '" BOLD);
	dputc(2, option);
	dputs(2, RESET RED "'\n" RESET);
	exit(EXIT_FAILURE);
}

void	a_stack_error(void *a_stack)
{
	dputs(2, "Error\n");
	free(a_stack);
	exit(EXIT_FAILURE);
}

