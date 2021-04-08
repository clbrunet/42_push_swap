/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:23:24 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/08 11:20:01 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# include <string.h>

typedef enum e_status
{
	Success = 0,
	Failure
}	t_status;

typedef enum e_op_type
{
	Sa,
	Sb,
	Ss,
	Pa,
	Pb,
	Ra,
	Rb,
	Rr,
	RRa,
	RRb,
	RRr
}	t_op_type;

typedef enum e_bool
{
	True = 1,
	False = 0
}	t_bool;

typedef struct s_options
{
	t_bool	verbose;
	t_bool	color;
}	t_options;

typedef struct s_stack
{
	unsigned int	len;
	int				*arr;
}	t_stack;

typedef struct s_operations
{
	unsigned int	len;
	t_op_type		*arr;
}	t_operations;

typedef struct s_vars
{
	t_stack			a;
	t_stack			b;
	t_operations	ops;
	t_options		options;
}	t_vars;

#endif
