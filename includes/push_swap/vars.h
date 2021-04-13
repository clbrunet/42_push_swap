/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 06:34:26 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/12 19:13:09 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# include "shared_vars.h"

typedef enum e_extremity_type
{
	Lowest,
	Second_lowest,
	Greatest
}	t_extremity_type;

typedef struct s_extremity_data
{
	t_extremity_type	type;
	t_bool				should_reverse;
	unsigned int		rotate_nb;
}	t_extremity_data;

typedef struct s_stack_indexes
{
	unsigned int	lowest;
	unsigned int	second_lowest;
	unsigned int	greatest;
}	t_stack_indexes;
typedef struct s_stack_rotate_sort_vars
{
	t_stack				*dst;
	char				dst_name;
	t_stack				*buf;
	char				buf_name;
	t_bool				should_put;
	unsigned int		count;
	t_stack_indexes		indexes;
	t_extremity_data	closest_data;
	t_bool				is_swap_needed;
	unsigned int		buf_rotate_nb;
}	t_stack_rotate_sort_vars;

#endif
