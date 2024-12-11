/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:56:18 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/11 14:04:02 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sa swap first 2 elements in stack a
// sb swap first 2 elements in stack b
// ss sa + sb
// pa push first elements of stack bi and put it in top of stack a
// pb push first elements of stack a and put it in top of stack b
// ra Shift up all elements of stack a by 1 The first element becomes the last one.
// rb  Shift up all elements of stack b by 1 The first element becomes the last one
// rr ra + rb
// rra Shift down all elements of stack a by 1 The last element becomes the first one.
// rrb Shift down all elements of stack b by 1 The last element becomes the first one.
// rrr rra + rrb

#include "push_swap.h"

void	lst_case_2(t_stack *stack)
{
	if (stack->arr[0] > stack->arr[1])
		sa(stack),ft_printf("sa");
}
void	lst_case_3(t_stack *stack)
{
	if (stack->arr[0] > stack->arr[1] && stack->arr[1] > stack->arr[2]) // 3 2 1
		sa(stack),rra(stack);
	else if (stack->arr[0] < stack->arr[1] && stack->arr[1] > stack->arr[2] && stack->arr[0] > stack->arr[2]) // 2 3 1
		rra(stack);
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] < stack->arr[2] && stack->arr[0] > stack->arr[2]) // 3 1 2
		rra(stack),rra(stack);
	else if (stack->arr[0] < stack->arr[1] && stack->arr[1] > stack->arr[2] && stack->arr[0] < stack->arr[2]) // 1 3 2
		rra(stack),sa(stack);
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] < stack->arr[2] && stack->arr[0] < stack->arr[2]) // 2 1 3
		sa(stack);
}

void	lst_case_4_5(t_stack *a,t_stack *b)
{
	int min_index;

	if (a->length == 4)
	{
		min_index = lst_min(a->arr,a->length) + 1;
		if (min_index > a->length / 2 )
		{
			while (min_index != a->length + 1 && min_index++)
				rra(a);
		}
		else if (min_index <= a->length / 2 )
		{
			while (--min_index)
				ra(a);
		}
		pb(a,b);
		// lst_print(a->arr,a->length);
		lst_case_3(a);
		pa(a,b);
	}
	else
		lst_case_5(a,b);
}
void	lst_case_5(t_stack *a,t_stack *b)
{
	int min_index;

	min_index = lst_min(a->arr,a->length) + 1;
	if (min_index > a->length / 2 )
	{
		while (min_index != a->length + 1 && min_index++)
			rra(a);
	}
	else if (min_index <= a->length / 2 )
	{
		while (--min_index)
			ra(a);
	}
	pb(a,b);
	lst_case_4_5(a,b);
	pa(a,b);
}
// devide by shunks method
void lst_large_case(t_stack *a,t_stack *b)
{
	t_stack sorted_lst;

	sorted_lst.arr = (int *)malloc(a->length * sizeof(int));
	lst_cpy(a->arr,sorted_lst.arr,a->length),lst_sort(sorted_lst.arr,a->length);
	t_shunk shunk;
	while (a->length)
	{
		if (a->length >= 3)
		{
			shunk.elem1 = sorted_lst.arr[0];
			shunk.elem2 = sorted_lst.arr[1];
			shunk.elem3 = sorted_lst.arr[2];
			// find_push(stack_a,stack_a_len,)
			// func that finds this shunks elements and adding it to stack b
		}
		else if (a->length == 2)
		{
			shunk.elem1 = sorted_lst.arr[0];
			shunk.elem2 = sorted_lst.arr[1];
			shunk.elem3 = 0;
			// func that finds this shunks elements and adding it to stack b
		}
		else if (a->length == 1)
		{
			pb(a,b);
			return ; // it will break anyway
		}
	}
}