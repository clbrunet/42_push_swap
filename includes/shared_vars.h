/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_vars.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 06:20:17 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/13 10:08:18 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_VARS_H
# define SHARED_VARS_H

typedef enum	e_status
{
	Success = 0,
	Failure
}				t_status;

typedef enum	e_bool
{
	True = 1,
	False = 0
}				t_bool;

typedef struct	s_stack
{
	unsigned int	len;
	int				*arr;
}				t_stack;

typedef enum	e_op_type
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
}				t_op_type;

typedef struct	s_operations
{
	unsigned int	len;
	t_op_type		*arr;
}				t_operations;

typedef struct	s_vars
{
	t_stack			a;
	t_stack			b;
	t_operations	ops;
}				t_vars;

#endif
