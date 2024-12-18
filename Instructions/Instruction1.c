/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:24:15 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/18 21:18:32 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	sb(t_stack *b, int print)
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

void	ss(t_stack *a, t_stack *b, int print)
{
	sa(a, 0);
	sb(b, 0);
	(print) && (ft_printf("ss\n"));
}

void	pa(t_stack *a, t_stack *b, int print)
{
	int	i;

	i = 1;
	if (b->length)
	{
		lst_push(a->arr, b->arr[0], a->length);
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

void	pb(t_stack *a, t_stack *b, int print)
{
	int	i;

	i = 1;
	if (a->length)
	{
		lst_push(b->arr, a->arr[0], b->length);
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
