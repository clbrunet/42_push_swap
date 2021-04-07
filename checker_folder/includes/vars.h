/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:23:24 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/07 12:13:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# include <string.h>

typedef enum e_status
{
	Success,
	Failure
}	t_status;

typedef enum e_bool
{
	True,
	False
}	t_bool;

typedef struct s_options
{
	t_bool	verbose;
	t_bool	color;
}	t_options;

typedef struct s_stack
{
	int		*stack;
	size_t	len;
}	t_stack;

typedef struct s_vars
{
	t_stack		a;
	t_stack		b;
	t_options	options;
}	t_vars;

#endif
