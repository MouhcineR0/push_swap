/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_large.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:47:42 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/18 10:01:21 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *lst_cost(t_stack *a,t_stack *b)
{
	int i;
	int cost;
	int *_cost;
	
	i = 0;
	_cost = (int *) malloc(sizeof(int) * b->length);
	cost = 0;

	while (i < b->length)
	{
		cost = get_cost_index(a,b->arr[i]);
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

void add_remaining(t_stack *a,t_stack *b)
{
	int min_index;

	min_index = lst_min(a->arr,a->length);
	if (min_index < a->length / 2)
	{
		while (min_index--)
			ra(a,1);
	}
	else if (a->length / 2 <= min_index)
	{
		while (a->length != min_index++)
			rra(a,1);
	}
}

void cost_move(t_stack *a,t_stack *b,int *min_cost_index,int *place)
{
	if (*place < a->length / 2)
	{
		while ((*place) > 0 && (*place)--)
		{
			if (*min_cost_index < b->length / 2 && (*min_cost_index > 0 && (*min_cost_index)--))
				rr(a,b);
			else
				ra(a,1);
		}
		push_a(a,b,*min_cost_index);
	}
	else if (a->length / 2 <= *place)
	{
		while (a->length != (*place)++)
		{
			if (b->length / 2 <= *min_cost_index && b->length != (*min_cost_index)++)
				rrr(a,b);
			else
				rra(a,1);
		}
		if (*min_cost_index <= b->length)
			push_a(a,b,*min_cost_index);
	}
}

void low_cost_move(t_stack *a,t_stack *b)
{
	int *_cost;
	int min_cost_index;
	int place;    // which place should it be (number πsents from stack b) in stack a

	int size;
	int *subseq = longest_increasing_subsequence(a->arr,a->length,&size);
	int i = 0;
	while (a->length != size)
	{
		if (a->arr[0] == subseq[i])
		{
			i++;
			ra(a,1);
		}
		else
			pb(a,b);
	}
	while (b->length)										// EACH ONE SHOULD BE PLACED IN ITS PLACE IN A
	{
		_cost = lst_cost(a,b);
		min_cost_index = lst_min(_cost,b->length);
		place = where_to_place(a,b->arr[min_cost_index]);
		cost_move(a,b,&min_cost_index,&place); //  this is where it places each in its place above
	}
	add_remaining(a,b);
}

void shank_move(t_stack *a,t_stack *b,int *tmp)
{
	if ((*tmp) < a->length / 2)
	{
		while ((*tmp)--)
			ra(a,1);
		pb(a,b);
	}
	else if (a->length / 2 <= (*tmp))
	{
		while (a->length != (*tmp)++)
			rra(a,1);
		pb(a,b);
	}
	(*tmp) = -1;
}