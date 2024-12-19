/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_large.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:47:42 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/19 18:19:30 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*lst_cost(t_stack *a, t_stack *b)
{
	int	i;
	int	cost;
	int	*_cost;

	i = 0;
	cost = 0;
	_cost = (int *) malloc(sizeof(int) * b->length);
	while (i < b->length)
	{
		cost = get_cost_index(a, b->arr[i]);
		if (cost > a->length / 2)
			cost = a->length - cost;
		if (i <= b->length / 2)
			_cost[i] = cost + i;
		else if (i > b->length / 2)
			_cost[i] = cost + b->length - i;
		i++;
	}
	return (_cost);
}

void	add_remaining(t_stack *a)
{
	int	min_index;

	min_index = lst_min(a->arr, a->length);
	if (min_index < a->length / 2)
	{
		while (min_index--)
			ra(a, 1);
	}
	else if (a->length / 2 <= min_index)
	{
		while (a->length != min_index++)
			rra(a, 1);
	}
}

void	cost_move(t_stack *a, t_stack *b, int *min_cost_index, int *place)
{
	if (*place < a->length / 2)
	{
		while ((*place) > 0 && (*place)--)
		{
			if (*min_cost_index < b->length / 2
				&& (*min_cost_index > 0 && (*min_cost_index)--))
				rr(a, b, 1);
			else
				ra(a, 1);
		}
		push_a(a, b, *min_cost_index);
	}
	else if (a->length / 2 <= *place)
	{
		while (a->length != (*place)++)
		{
			if (b->length / 2 <= *min_cost_index
				&& b->length != (*min_cost_index)++)
				rrr(a, b, 1);
			else
				rra(a, 1);
		}
		if (*min_cost_index <= b->length)
			push_a(a, b, *min_cost_index);
	}
}

void	low_cost_move(t_stack *a, t_stack *b)
{
	int	*_cost;
	int	min_cost;
	int	i;
	int	size;
	int	*subseq;

	(1) && (subseq = longest_sub(a->arr, a->length, &size), i = 0);
	while (a->length != size)
	{
		if (i < size && a->arr[0] == subseq[i])
		{
			ra(a, 1);
			i++;
		}
		else
			pb(a, b, 1);
	}
	while (b->length)
	{
		(1) && (_cost = lst_cost(a, b), min_cost = lst_min(_cost, b->length));
		i = where_to_place(a, b->arr[min_cost]);
		cost_move(a, b, &min_cost, &i);
		free(_cost);
	}
	return (free(subseq), add_remaining(a));
}

void	shank_move(t_stack *a, t_stack *b, int *tmp)
{
	if ((*tmp) < a->length / 2)
	{
		while ((*tmp)--)
			ra(a, 1);
		pb(a, b, 1);
	}
	else if (a->length / 2 <= (*tmp))
	{
		while (a->length != (*tmp)++)
			rra(a, 1);
		pb(a, b, 1);
	}
	(*tmp) = -1;
}
