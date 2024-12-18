/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:24:15 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/18 15:44:11 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


// https://www.tldraw.com/r/Y9XJlB37C9Znpv8uH_FhE?d=v-2461.7794.7568.10624.page


// sa swap first 2 elements in stack a
// sb swap first 2 elements in stack b
// ss sa + sb
// pa push first elements of stack b and put it in top of stack a
// pb push first elements of stack a and put it in top of stack b
// ra Shift up all elements of stack a by 1 The first element becomes the last one.
// rb  Shift up all elements of stack b by 1 The first element becomes the last one
// rr ra + rb
// rra Shift down all elements of stack a by 1 The last element becomes the first one.
// rrb Shift down all elements of stack b by 1 The last element becomes the first one.
// rrr rra + rrb

void	sa(t_stack *a, int print)
{
	int	tmp;
	
	if (a->length >= 2)
	{
		tmp = a->arr[0];
		a->arr[0] = a->arr[1];
		a->arr[1] = tmp;
		(print) && (ft_printf("sa\n"));
	}
}
void	sb(t_stack *b,int print)
{
	int	tmp;
	
	if (b->length >= 2)
	{
		tmp = b->arr[0];
		b->arr[0] = b->arr[1];
		b->arr[1] = tmp;
		(print) && (ft_printf("sb\n"));
	}
}
void	ss(t_stack *a,t_stack *b, int print)
{
	sa(a,0),sb(b,0);
	(print) && (ft_printf("ss\n"));
}

void	pa(t_stack *a,t_stack *b, int print) // push in stack a
{
	int	i;

	i = 1;
	if (b->length)
	{
		lst_push(a->arr,b->arr[0],a->length);
		while (i < b->length)
		{
			b->arr[i - 1] = b->arr[i];
			i++;
		}
		b->arr[--i] = 0;
		(a->length)++;
		(b->length)--;
		(print) && (ft_printf("pa\n"));
	}
}
void	pb(t_stack *a,t_stack *b, int print) // push in stack b
{
	int	i;

	i = 1;
	if (a->length)
	{
		lst_push(b->arr,a->arr[0],b->length);
		while (i < a->length)
		{
			a->arr[i - 1] = a->arr[i];
			i++;
		}
		a->arr[--i] = 0;
		(b->length)++;
		(a->length)--;
		(print) && (ft_printf("pb\n"));
	}
}
