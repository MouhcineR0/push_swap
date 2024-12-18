/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:56:18 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/18 15:45:13 by rmouhcin         ###   ########.fr       */
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
		pb(a,b,1);
		lst_case_3(a);
		pa(a,b,1);
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
	pb(a,b,1);
	lst_case_4_5(a,b);
	pa(a,b,1);
}

// int	shank_element(t_stack *shank,t_stack *a,int shank_length)
// {
// 	int left;
// 	int right;
// 	int i;

// 	left = 0;
// 	right = a->length - 1;
// 	while (left <= right)
// 	{
// 		i = 0;
// 		while (i < shank_length) // this should change depend on chank size
// 		{
// 			if (shank->arr[i] == a->arr[left])
// 				return (left);
// 			else if (shank->arr[i] == a->arr[right])
// 				return (right);
// 			i++;
// 		}
// 		left++;
// 		right--;
// 	}
// 	return (-1);
// }

// void push_a(t_stack *a,t_stack *b,int index)
// {
// 	if (index < b->length / 2)
// 	{
// 		while (index > 0 && index--)
// 		{
// 			rb(b,1);
// 		}
// 		pa(a,b);
// 	}
// 	else if (b->length / 2 <= index)
// 	{
// 		while (b->length != index++)
// 		{
// 			rrb(b,1);
// 		}
// 		pa(a,b);
// 	}
// }
// int	where_to_place(t_stack *stack,int nb)
// {
// 	int i;

// 	i = 0;
// 	if (nb < stack->arr[lst_min(stack->arr,stack->length)])
// 		return lst_min(stack->arr,stack->length);
// 	else if (nb > stack->arr[lst_max(stack->arr,stack->length)])
// 		return lst_max(stack->arr,stack->length) + 1;
// 	while (i < stack->length)
// 	{
// 		if (i > 0 && nb < stack->arr[i] && nb > stack->arr[i - 1])
//             return i;
//         i++;
// 	}
// 	return (0); // this case is impossible
// }
// void push_swap(t_stack *a,t_stack *b)
// {
// 	int max_index;
// 	int i = 0;
// 	while (b->length)
// 	{
// 		max_index = lst_max(b->arr,b->length);
// 		if (max_index < b->length / 2)
// 		{
// 			while (max_index--)
// 				rb(b,1);i++;
// 			pa(a,b);i++;
// 		}
// 		else if (b->length / 2 <= max_index)
// 		{
// 			while (b->length != max_index++)
// 				rrb(b,1);i++;
// 			pa(a,b);i++;
// 		}
// 	}
// }
// int get_cost_index(t_stack *stack, int nb)
// {
// 	int i;

// 	i = 0;
// 	if (nb < stack->arr[lst_min(stack->arr,stack->length)])
// 		return lst_min(stack->arr,stack->length);
// 	else if (nb > stack->arr[lst_max(stack->arr,stack->length)])
// 		return lst_max(stack->arr,stack->length);
// 	while (i < stack->length)
// 	{
// 		if (i > 0 && nb < stack->arr[i] && nb > stack->arr[i - 1])
// 		{
// 			if (i > stack->length / 2)
// 				return stack->length - i;
//             return i;
// 		}
//         i++;
// 	}
// 	return (0); // this case is impossible
// }

// int *lst_cost(t_stack *a,t_stack *b)
// {
// 	int i;
// 	int cost;
// 	int *_cost;
	
// 	i = 0;
// 	_cost = (int *) malloc(sizeof(int) * b->length);
// 	cost = 0;

// 	while (i < b->length)
// 	{
// 		cost = get_cost_index(a,b->arr[i]);
// 		if (cost > a->length / 2)
// 			cost = a->length - cost;
// 		if (i <= b->length / 2)
// 			_cost[i] = cost + i;
// 		else if (i > b->length / 2)
// 			_cost[i] = cost + b->length - i;
// 		i++;
// 	}
// 	return (_cost);
// }

// void add_remaining(t_stack *a,t_stack *b)
// {
// 	int min_index;

// 	min_index = lst_min(a->arr,a->length);
// 	if (min_index < a->length / 2)
// 	{
// 		while (min_index--)
// 			ra(a,1);
// 	}
// 	else if (a->length / 2 <= min_index)
// 	{
// 		while (a->length != min_index++)
// 			rra(a,1);
// 	}
// }

// //  should create separate function for while loops
// void cost_move(t_stack *a,t_stack *b,int *min_cost_index,int *place)
// {
// 	if (*place < a->length / 2)
// 	{
// 		while ((*place) > 0 && (*place)--)
// 		{
// 			if (*min_cost_index < b->length / 2 && (*min_cost_index > 0 && (*min_cost_index)--))
// 				rr(a,b);
// 			else
// 				ra(a,1);
// 		}
// 		push_a(a,b,*min_cost_index);
// 	}
// 	else if (a->length / 2 <= *place)
// 	{
// 		while (a->length != (*place)++)
// 		{
// 			if (b->length / 2 <= *min_cost_index && b->length != (*min_cost_index)++)
// 				rrr(a,b);
// 			else
// 				rra(a,1);
// 		}
// 		if (*min_cost_index <= b->length)
// 			push_a(a,b,*min_cost_index);
// 	}
// }

// void low_cost_move(t_stack *a,t_stack *b)
// {
// 	int *_cost;
// 	int min_cost_index;
// 	int place;    // which place should it be (number πsents from stack b) in stack a

// 	// while (a->length > 5)
// 	// 	pb(a,b,1);
// 	// lst_case_5(a,b);
// 	int size;
// 	int *subseq = longest_increasing_subsequence(a->arr,a->length,&size);
// 	int i = 0;
// 	while (a->length != size)
// 	{
// 		if (a->arr[0] == subseq[i])
// 		{
// 			i++;
// 			ra(a,1);
// 		}
// 		else
// 			pb(a,b,1);
// 	}
// 	// return ;
// 	while (b->length)										// EACH ONE SHOULD BE PLACED IN ITS PLACE IN A
// 	{
// 		_cost = lst_cost(a,b);
// 		min_cost_index = lst_min(_cost,b->length);
// 		place = where_to_place(a,b->arr[min_cost_index]);
// 		cost_move(a,b,&min_cost_index,&place); //  this is where it places each in its place above
// 	}
// 	add_remaining(a,b);
// }

// // shanks methods 

// void shank_move(t_stack *a,t_stack *b,int *tmp)
// {
// 	if ((*tmp) < a->length / 2)
// 	{
// 		while ((*tmp)--)
// 			ra(a,1);
// 		pb(a,b,1);
// 	}
// 	else if (a->length / 2 <= (*tmp))
// 	{
// 		while (a->length != (*tmp)++)
// 			rra(a,1);
// 		pb(a,b,1);
// 	}
// 	(*tmp) = -1;
// }
void lst_large_case(t_stack *a,t_stack *b, int shank_length)
{
	t_stack sorted_arr;
	int tmp;
	int k;

	tmp = -1;
	sorted_arr.arr = (int *) malloc(a->length * sizeof(int));
	lst_cpy(a->arr,sorted_arr.arr,a->length);
	sorted_arr.length = a->length;
	lst_sort(sorted_arr.arr,sorted_arr.length);

	while (a->length >= shank_length) // this should change depend on chank size
	{
		tmp = shank_element(&sorted_arr,a,shank_length);
		if (tmp != -1)
			shank_move(a,b,&tmp);
		else
		{
			k = shank_length; // this should change depend on chank size
			while (k--)
				rb(&sorted_arr,0);
			sorted_arr.length -= shank_length; // this should change depend on chank size
		}
	}
	low_cost_move(a,b);
}
