#include "execution.h"

static void	stack_rotate_sort_vars_hydration(char dst_name,
		t_stack *buf, t_bool should_put, t_stack_rotate_sort_vars *v)
{
	v->dst_name = dst_name;
	v->buf = buf;
	if (dst_name == 'a')
		v->buf_name = 'b';
	else
		v->buf_name = 'a';
	v->should_put = should_put;
	v->count = v->dst->len * 2;
	v->is_swap_needed = False;
	v->buf_rotate_nb = 0;
}

static void	adapt_buf_push(t_stack_rotate_sort_vars *v)
{
	if (v->closest_data.type == Lowest && v->is_swap_needed == True)
	{
		if (v->should_put == True)
		{
			dputc(1, 's');
			dputc(1, v->buf_name);
			dputc(1, '\n');
		}
		swap(v->buf);
		v->count++;
		v->is_swap_needed = False;
	}
	else if (v->closest_data.type == Second_lowest)
		v->is_swap_needed = True;
	else if (v->closest_data.type == Greatest)
	{
		if (v->should_put == True)
		{
			dputc(1, 'r');
			dputc(1, v->buf_name);
			dputc(1, '\n');
		}
		rotate(v->buf);
		v->buf_rotate_nb++;
	}
}

static void	rotate_buf(t_stack_rotate_sort_vars *v)
{
	v->count += v->buf_rotate_nb * 2;
	while (v->buf_rotate_nb)
	{
		if (v->should_put == True)
		{
			dputs(1, "rr");
			dputc(1, v->buf_name);
			dputc(1, '\n');
		}
		reverse_rotate(v->buf);
		v->buf_rotate_nb--;
	}
}

unsigned int	stack_rotate_sort(t_stack *dst, char dst_name,
		t_stack *buf, t_bool should_put)
{
	t_stack_rotate_sort_vars	v;

	v.dst = dst;
	stack_rotate_sort_vars_hydration(dst_name, buf, should_put, &v);
	while (dst->len)
	{
		search_indexes(&v.indexes, dst);
		set_closest_data(&v.closest_data, dst->len, &v.indexes,
			v.is_swap_needed);
		set_closest_should_reverse(&v.closest_data, dst->len, &v.indexes);
		v.count += v.closest_data.rotate_nb;
		go_up_closest(dst, dst_name, &v.closest_data, should_put);
		if (should_put == True)
		{
			dputc(1, 'p');
			dputc(1, v.buf_name);
			dputc(1, '\n');
		}
		push(buf, dst);
		adapt_buf_push(&v);
	}
	rotate_buf(&v);
	push_to_dst(dst, dst_name, buf, should_put);
	return (v.count);
}
