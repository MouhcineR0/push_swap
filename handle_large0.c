/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_large0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:57:10 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/18 20:12:41 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shank_element(t_stack *shank, t_stack *a, int shank_length)
{
	int	left;
	int	right;
	int	i;

	left = 0;
	right = a->length - 1;
	while (left <= right)
	{
		i = 0;
		while (i < shank_length)
		{
			if (shank->arr[i] == a->arr[left])
				return (left);
			else if (shank->arr[i] == a->arr[right])
				return (right);
			i++;
		}
		left++;
		right--;
	}
	return (-1);
}

void	push_a(t_stack *a, t_stack *b, int index)
{
	if (index < b->length / 2)
	{
		while (index > 0 && index--)
			rb(b, 1);
		pa(a, b, 1);
	}
	else if (b->length / 2 <= index)
	{
		while (b->length != index++)
			rrb(b, 1);
		pa(a, b, 1);
	}
}

int	where_to_place(t_stack *stack, int nb)
{
	int	i;

	i = 0;
	if (nb < stack->arr[lst_min(stack->arr, stack->length)])
		return (lst_min(stack->arr, stack->length));
	else if (nb > stack->arr[lst_max(stack->arr, stack->length)])
		return (lst_max(stack->arr, stack->length) + 1);
	while (i < stack->length)
	{
		if (i > 0 && nb < stack->arr[i] && nb > stack->arr[i - 1])
			return (i);
		i++;
	}
	return (0);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	max_index;
	int	i;

	i = 0;
	while (b->length)
	{
		max_index = lst_max(b->arr, b->length);
		if (max_index < b->length / 2)
		{
			while (max_index--)
				rb(b, 1);
			pa(a, b, 1);
		}
		else if (b->length / 2 <= max_index)
		{
			while (b->length != max_index++)
				rrb(b, 1);
			pa(a, b, 1);
		}
	}
}

int	get_cost_index(t_stack *stack, int nb)
{
	int	i;

	i = 0;
	if (nb < stack->arr[lst_min(stack->arr, stack->length)])
		return (lst_min(stack->arr, stack->length));
	else if (nb > stack->arr[lst_max(stack->arr, stack->length)])
		return (lst_max(stack->arr, stack->length));
	while (i < stack->length)
	{
		if (i > 0 && nb < stack->arr[i] && nb > stack->arr[i - 1])
		{
			if (i > stack->length / 2)
				return (stack->length - i);
			return (i);
		}
		i++;
	}
	return (0);
}
