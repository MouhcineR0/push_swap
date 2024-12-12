/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:56:18 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/12 09:08:34 by rmouhcin         ###   ########.fr       */
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
		sa(stack,1);
}
void	lst_case_3(t_stack *stack)
{
	if (stack->arr[0] > stack->arr[1] && stack->arr[1] > stack->arr[2]) // 3 2 1
		sa(stack,1),rra(stack,1);
	else if (stack->arr[0] < stack->arr[1] && stack->arr[1] > stack->arr[2] && stack->arr[0] > stack->arr[2]) // 2 3 1
		rra(stack,1);
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] < stack->arr[2] && stack->arr[0] > stack->arr[2]) // 3 1 2
		rra(stack,1),rra(stack,1);
	else if (stack->arr[0] < stack->arr[1] && stack->arr[1] > stack->arr[2] && stack->arr[0] < stack->arr[2]) // 1 3 2
		rra(stack,1),sa(stack,1);
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] < stack->arr[2] && stack->arr[0] < stack->arr[2]) // 2 1 3
		sa(stack,1);
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
				rra(a,1);
		}
		else if (min_index <= a->length / 2 )
		{
			while (--min_index)
				ra(a,1);
		}
		pb(a,b);
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
			rra(a,1);
	}
	else if (min_index <= a->length / 2 )
	{
		while (--min_index)
			ra(a,1);
	}
	pb(a,b);
	lst_case_4_5(a,b);
	pa(a,b);
}
// hadi khatta2
void	sort_shunk(t_stack *a,t_stack *b)
{
	int sum;

	sum = b->length;
	while (sum >= 3)
		sum -= 3;
	while (b->length)
	{
		if (b->length >= 3 && (!sum || sum == -1) && (sum = -1))
		{
			if (b->arr[0] > b->arr[1] && b->arr[1] > b->arr[2]) // 3 2 1
				pa(a,b),pa(a,b),pa(a,b);
			else if (b->arr[0] < b->arr[1] && b->arr[1] > b->arr[2] && b->arr[0] > b->arr[2]) // 2 3 1
				rb(b,1),pa(a,b),rrb(b,1),pa(a,b),pa(a,b);
			else if (b->arr[0] > b->arr[1] && b->arr[1] < b->arr[2] && b->arr[0] > b->arr[2]) // 3 1 2
				pa(a,b),rb(b,1),pa(a,b),rrb(b,1),pa(a,b);
			else if (b->arr[0] < b->arr[1] && b->arr[1] > b->arr[2] && b->arr[0] < b->arr[2]) // 1 3 2
				rb(b,1),pa(a,b),pa(a,b),rrb(b,1),pa(a,b);
			else if (b->arr[0] > b->arr[1] && b->arr[1] < b->arr[2] && b->arr[0] < b->arr[2]) // 2 1 3
				rb(b,1),rb(b,1),pa(a,b),rrb(b,1),rrb(b,1),pa(a,b),pa(a,b);
			else
				rb(b,1),rb(b,1),pa(a,b),rrb(b,1),pa(a,b),rrb(b,1),pa(a,b);
		}
		else if (sum == 2 && (sum = -1))
		{
			if (b->arr[0] > b->arr[1])
				pa(a,b),pa(a,b);
			else
				rb(b,1),pa(a,b),rrb(b,1),pa(a,b);
		}
		else if (sum == 1 && (sum = -1))
			pa(a,b);
	}
}

// find 3 min numbers and push them
void	find_push(t_stack *a,t_stack *b,t_shunk *shunk)
{
	int i;

	i = 0;
	while (i < a->length)
	{
		if ((a->arr[i] == shunk->elem1 && shunk->length >= 1) || (a->arr[i] == shunk->elem2 && shunk->length >= 2) 
		|| (a->arr[i] == shunk->elem3 && shunk->length >= 3))
		{
			if (i < a->length / 2)
			{
				while (i--)
					ra(a,1);
				i = -1;
			}
			else if (i >= a->length / 2)
			{
				while (a->length != i++)
					rra(a,1);
				i = -1;
			}
			pb(a,b);
		}
		i++;
	}
}

// devide by shunks method
void lst_large_case(t_stack *a,t_stack *b)
{
	t_stack sorted_lst;

	sorted_lst.arr = (int *)malloc(a->length * sizeof(int));
	if (!sorted_lst.arr)
		return ;
	sorted_lst.length = a->length;
	lst_cpy(a->arr,sorted_lst.arr,a->length);
	lst_sort(sorted_lst.arr,a->length);
	// lst_print(sorted_lst.arr,sorted_lst.length);
	t_shunk shunk;

	while (a->length)
	{
		if (a->length >= 3)
		{
			shunk.elem1 = sorted_lst.arr[0];
			shunk.elem2 = sorted_lst.arr[1];
			shunk.elem3 = sorted_lst.arr[2];
			shunk.length = 3;
			find_push(a,b,&shunk);
			ra(&sorted_lst,1);
			ra(&sorted_lst,1);
			ra(&sorted_lst,1);
			sorted_lst.length -= 3;
		}
		if (a->length == 2)
		{
			shunk.elem1 = sorted_lst.arr[0];
			shunk.elem2 = sorted_lst.arr[1];
			shunk.length = 2;
			shunk.elem3 = 0;
			find_push(a,b,&shunk);
			ra(&sorted_lst,1);
			ra(&sorted_lst,1);
			sorted_lst.length -= 2;
		}
		if (a->length == 1)
		{
			pb(a,b);
			sort_shunk(a,b);
			return ;
		}
	}
	sort_shunk(a,b);
}
