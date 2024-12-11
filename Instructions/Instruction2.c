/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:50:22 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/11 14:18:03 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *a)
{
	int	i;
	int	tmp;

	i = 0;
	if (a->length > 1)
	{
		tmp = a->arr[0];
		while (i + 1 < a->length)
		{
			a->arr[i] = a->arr[i + 1];
			i++;
		}
		a->arr[i] = tmp;
	}
}
void	rb(t_stack *b)
{
	int	i;
	int	tmp;

	if (b->length > 1)
	{
		i = 0;
		tmp = b->arr[0];
		while (i + 1 < b->length)
		{
			b->arr[i] = b->arr[i + 1];
			i++;
		}
		b->arr[i] = tmp;
	}
}

// rr : ra and rb at the same time.
void	rr(t_stack *a,t_stack *b)
{
	ra(a),rb(b);
}

void rra(t_stack *a)
{
	int	tmp;
	int	i;
	int length;

	length = a->length;
	if (length > 1)
	{
		i = 1;
		tmp = a->arr[(length)-- - 1];
		while (length)
		{
			a->arr[length] = a->arr[length - 1];
			i++;
			(length)--;
		}
		a->arr[0] = tmp;
	}
}
void rrb(t_stack *b)
{
	int	tmp;
	int	i;
	int length;

	length = b->length;
	if (length > 1)
	{
		i = 1;
		tmp = b->arr[length-- - 1];
		while (length)
		{
			b->arr[length] = b->arr[length - 1];
			i++;
			length--;
		}
		b->arr[0] = tmp;
	}
}