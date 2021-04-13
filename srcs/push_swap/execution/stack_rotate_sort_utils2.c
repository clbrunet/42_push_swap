/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_sort_utils2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:03:12 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/12 19:04:06 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static unsigned int	get_min(unsigned int n1, unsigned int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

void	set_closest_data(t_extremity_data *closest_data,
		unsigned int dst_len, t_stack_indexes *indexes, t_bool is_swap_needed)
{
	unsigned int	lowest_len;
	unsigned int	second_lowest_len;
	unsigned int	greatest_len;

	lowest_len = get_min(indexes->lowest + 1, dst_len - 1 - indexes->lowest);
	second_lowest_len = get_min(indexes->second_lowest + 1,
			dst_len - 1 - indexes->second_lowest) + 1;
	greatest_len = get_min(indexes->greatest + 1,
			dst_len - 1 - indexes->greatest) + 2;
	if (is_swap_needed == False && second_lowest_len < greatest_len
		&& second_lowest_len < lowest_len)
	{
		closest_data->type = Second_lowest;
		closest_data->rotate_nb = second_lowest_len - 1;
	}
	else if (lowest_len < greatest_len)
	{
		closest_data->type = Lowest;
		closest_data->rotate_nb = lowest_len;
	}
	else
	{
		closest_data->type = Greatest;
		closest_data->rotate_nb = greatest_len - 2;
	}
}

void	set_closest_should_reverse(t_extremity_data *closest_data,
		unsigned int dst_len, t_stack_indexes *indexes)
{
	if ((closest_data->type == Lowest
			&& indexes->lowest + 1 < dst_len - 1 - indexes->lowest)
		|| (closest_data->type == Greatest
			&& indexes->greatest + 1 < dst_len - 1 - indexes->greatest)
		|| (closest_data->type == Second_lowest
			&& indexes->second_lowest + 1
			< dst_len - 1 - indexes->second_lowest))
	{
		closest_data->should_reverse = True;
	}
	else
		closest_data->should_reverse = False;
}

void	go_up_closest(t_stack *dst, char dst_name,
		t_extremity_data *closest_data, t_bool should_put)
{
	while (closest_data->rotate_nb)
	{
		if (closest_data->should_reverse == True)
		{
			reverse_rotate(dst);
			if (should_put == True)
				dputc(1, 'r');
		}
		else
			rotate(dst);
		if (should_put == True)
		{
			dputc(1, 'r');
			dputc(1, dst_name);
			dputc(1, '\n');
		}
		closest_data->rotate_nb--;
	}
}

void	push_to_dst(t_stack *dst, char dst_name, t_stack *buf,
		t_bool should_put)
{
	while (buf->len)
	{
		if (should_put == True)
		{
			dputc(1, 'p');
			dputc(1, dst_name);
			dputc(1, '\n');
		}
		push(dst, buf);
	}
}
