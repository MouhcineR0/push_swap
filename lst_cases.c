/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:56:18 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/18 21:39:00 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_case_2(t_stack *stack)
{
	if (stack->arr[0] > stack->arr[1])
		sa(stack, 1);
}

void	lst_case_3(t_stack *stack)
{
	if (stack->arr[0] > stack->arr[1] && stack->arr[1] > stack->arr[2])
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (stack->arr[0] < stack->arr[1] && stack->arr[1] > stack->arr[2]
		&& stack->arr[0] > stack->arr[2])
		rra(stack, 1);
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] < stack->arr[2]
		&& stack->arr[0] > stack->arr[2])
	{
		rra(stack, 1);
		rra(stack, 1);
	}
	else if (stack->arr[0] < stack->arr[1] && stack->arr[1] > stack->arr[2]
		&& stack->arr[0] < stack->arr[2])
	{
		rra(stack, 1);
		sa(stack, 1);
	}
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] < stack->arr[2]
		&& stack->arr[0] < stack->arr[2])
		sa(stack, 1);
}

void	lst_case_4_5(t_stack *a, t_stack *b)
{
	int	min_index;

	if (a->length == 3)
		lst_case_3(a);
	else if (a->length == 2)
		lst_case_2(a);
	else if (a->length == 4)
	{
		min_index = lst_min(a->arr, a->length) + 1;
		if (min_index > a->length / 2)
		{
			while (min_index != a->length + 1 && min_index++)
				rra(a, 1);
		}
		else if (min_index <= a->length / 2)
		{
			while (--min_index)
				ra(a, 1);
		}
		pb(a, b, 1);
		lst_case_3(a);
		pa(a, b, 1);
	}
	else
		lst_case_5(a, b);
}

void	lst_case_5(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = lst_min(a->arr, a->length) + 1;
	if (min_index > a->length / 2)
	{
		while (min_index != a->length + 1 && min_index++)
			rra(a, 1);
	}
	else if (min_index <= a->length / 2)
	{
		while (--min_index)
			ra(a, 1);
	}
	pb(a, b, 1);
	lst_case_4_5(a, b);
	pa(a, b, 1);
}

void	lst_large_case(t_stack *a, t_stack *b, int shank_length)
{
	t_stack	sorted_arr;
	int		tmp;
	int		k;

	tmp = -1;
	sorted_arr.arr = (int *) malloc(a->length * sizeof(int));
	lst_cpy(a->arr, sorted_arr.arr, a->length);
	sorted_arr.length = a->length;
	lst_sort(sorted_arr.arr, sorted_arr.length);
	while (a->length >= shank_length)
	{
		tmp = shank_element(&sorted_arr, a, shank_length);
		if (tmp != -1)
			shank_move(a, b, &tmp);
		else
		{
			k = shank_length;
			while (k--)
				rb(&sorted_arr, 0);
			sorted_arr.length -= shank_length;
		}
	}
	low_cost_move(a, b);
}
