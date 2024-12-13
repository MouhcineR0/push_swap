/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:56:18 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/13 20:36:15 by rmouhcin         ###   ########.fr       */
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

	if (a->length == 3)
		lst_case_3(a);
	else if (a->length == 2)
		lst_case_2(a);
	else if (a->length == 4)
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
	while (sum >= 5)
		sum -= 5;
	// while (b->length)
	// {
	// 	// if (b->length >= 5 && (!sum || sum == -1) && (sum = -1))
	// 	// {
			
	// 	// }
	// 	else if (b->length >= 3 && (sum == 3 || sum == -1) && (sum = -1))
	// 	{
	// 		if (b->arr[0] > b->arr[1] && b->arr[1] > b->arr[2]) // 3 2 1
	// 			pa(a,b),pa(a,b),pa(a,b);
	// 		else if (b->arr[0] < b->arr[1] && b->arr[1] > b->arr[2] && b->arr[0] > b->arr[2]) // 2 3 1
	// 			rb(b,1),pa(a,b),rrb(b,1),pa(a,b),pa(a,b);
	// 		else if (b->arr[0] > b->arr[1] && b->arr[1] < b->arr[2] && b->arr[0] > b->arr[2]) // 3 1 2
	// 			pa(a,b),rb(b,1),pa(a,b),rrb(b,1),pa(a,b);
	// 		else if (b->arr[0] < b->arr[1] && b->arr[1] > b->arr[2] && b->arr[0] < b->arr[2]) // 1 3 2
	// 			rb(b,1),pa(a,b),pa(a,b),rrb(b,1),pa(a,b);
	// 		else if (b->arr[0] > b->arr[1] && b->arr[1] < b->arr[2] && b->arr[0] < b->arr[2]) // 2 1 3
	// 			rb(b,1),rb(b,1),pa(a,b),rrb(b,1),rrb(b,1),pa(a,b),pa(a,b);
	// 		else
	// 			rb(b,1),rb(b,1),pa(a,b),rrb(b,1),pa(a,b),rrb(b,1),pa(a,b);
	// 	}
	// 	else if (sum == 2 && (sum = -1))
	// 	{
	// 		if (b->arr[0] > b->arr[1])
	// 			pa(a,b),pa(a,b);
	// 		else
	// 			rb(b,1),pa(a,b),rrb(b,1),pa(a,b);
	// 	}
	// 	else if (sum == 1 && (sum = -1))
	// 		pa(a,b);
	// }
	while (b->length)
	{
		int index_max;
		int return_rotate;

		index_max = lst_max(b->arr,b->length);
		// ft_printf("((%d))",index_max);
		return_rotate = index_max;
		while (index_max--)
			rb(b,1);
		pa(a,b);
		while (return_rotate--)
			rrb(b,1);
	}
}
// i will do chunks method with 10 elements
// search for elements of the first shank lte7t w lfog w nchuf l9riba w nrotati 3la wdha w npushiha
// wla ndir be3da ghir chanks b 5 elements w nchuf wach 9lal les instructions

int	shank_element(t_stack *shank,t_stack *a)
{
	int left;
	int right;
	int i;

	left = 0;
	right = a->length - 1;
	// lst_print(shank->arr,shank->length);
	// lst_print(a->arr,a->length);
	while (left <= right)
	{
		i = 0;
		while (i < 5) // this should change depend on chank size
		{
			if (shank->arr[i] == a->arr[left])
			{
				// ft_printf("[[[%d %d]]] -> ",left,a->arr[left]);
				// ft_printf("[[[%d %d]]]",i,shank->arr[i]);
				return (left);
			}
			else if (shank->arr[i] == a->arr[right])
			{
				// ft_printf("[[[%d %d]]] -> ",left,a->arr[left]);
				// ft_printf("[[[%d %d]]]",i,shank->arr[i]);
				return (right);
			}
			i++;
		}
		left++;
		right--;
	}
	return (-1);
}
// nbdaw n9su 5 b 5 ila b9at lina chi 7aja 9el mn 5 npushiwha kamla
void lst_large_case(t_stack *a,t_stack *b)
{
	t_stack sorted_arr;
	int tmp;

	tmp = -1;
	sorted_arr.arr = (int *) malloc(a->length * sizeof(int));
	lst_cpy(a->arr,sorted_arr.arr,a->length);
	sorted_arr.length = a->length;
	lst_sort(sorted_arr.arr,sorted_arr.length);
	while (a->length >= 5) // this should change depend on chank size
	{
		tmp = shank_element(&sorted_arr,a);
		if (tmp != -1)
		{
			if (tmp < a->length / 2)
			{
				while (tmp--)
					ra(a,1);
				pb(a,b);
			}
			if (a->length / 2 <= tmp)
			{
				while (a->length != tmp++)
					rra(a,1);
				pb(a,b);
			}
			tmp = -1;
		}
		else
		{
			int k = 5; // this should change depend on chank size
			while (k--)
				rb(&sorted_arr,0);
			sorted_arr.length -= 5; // this should change depend on chank size
		}
		// lst_print(b->arr,b->length);
		// ft_printf("\n");
	}
	if (a->length)
		lst_case_4_5(a,b);
	while (a->length)
		pb(a,b);
}