/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:24:23 by clbrunet          #+#    #+#             */
/*   Updated: 2021/04/13 10:08:59 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char		*join_read_input(char *input, const char buf[5])
{
	char	*joint;
	size_t	len;

	len = 0;
	len += ft_strlen(input);
	len += ft_strlen(buf);
	joint = malloc(sizeof(char) * (len + 1));
	if (joint == NULL)
	{
		free(input);
		return (NULL);
	}
	*joint = '\0';
	ft_strcat(joint, input);
	free(input);
	ft_strcat(joint, buf);
	return (joint);
}

static t_status	read_input(char **input)
{
	ssize_t	bytes_read;
	char	buf[5];

	*input = malloc(sizeof(char));
	if (*input == NULL)
		return (Failure);
	**input = '\0';
	bytes_read = read(0, buf, 4);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		*input = join_read_input(*input, buf);
		if (*input == NULL)
			return (Failure);
		bytes_read = read(0, buf, 4);
	}
	if (bytes_read == -1)
		return (Failure);
	return (Success);
}

static int		get_line_count(const char *input)
{
	int			line_count;

	line_count = 0;
	while (*input)
	{
		line_count++;
		while (*input && *input != '\n')
			input++;
		if (*input)
			input++;
	}
	return (line_count);
}

t_status		parse_input(t_vars *v)
{
	char	*input;

	if (read_input(&input) == Failure)
		return (Failure);
	v->ops.len = get_line_count(input);
	v->ops.arr = malloc(sizeof(t_op_type) * (v->ops.len));
	if (v->ops.arr == NULL)
		return (Failure);
	if (set_operations(input, v->ops.arr) == Failure)
	{
		free(input);
		free(v->ops.arr);
		dputs(2, "Error\n");
		return (Failure);
	}
	free(input);
	return (Success);
}
