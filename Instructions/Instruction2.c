/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:50:22 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/11 09:52:37 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(int *stack,int length)
{
	int	i;
	int	tmp;

	i = 0;
	if (length > 1)
	{
		tmp = stack[0];
		while (i + 1 < length)
		{
			stack[i] = stack[i + 1];
			i++;
		}
		stack[i] = tmp;
	}
}
void	rb(int *stack,int length)
{
	int	i;
	int	tmp;

	if (length > 1)
	{
		i = 0;
		tmp = stack[0];
		while (i + 1 < length)
		{
			stack[i] = stack[i + 1];
			i++;
		}
		stack[i] = tmp;
	}
}

// rr : ra and rb at the same time.
void	rr(int *stack_a, int *stack_b, int *stack_a_len, int *stack_b_len)
{
	ra(stack_a,*stack_a_len),rb(stack_b,*stack_b_len);
}

void rra(int *stack,int length)
{
	int	tmp;
	int	i;

	if (length > 1)
	{
		i = 1;
		tmp = stack[length-- - 1];
		while (length)
		{
			stack[length] = stack[length - 1];
			i++;
			length--;
		}
		stack[0] = tmp;
	}
}
void rrb(int *stack,int length)
{
	int	tmp;
	int	i;

	if (length > 1)
	{
		i = 1;
		tmp = stack[length-- - 1];
		while (length)
		{
			stack[length] = stack[length - 1];
			i++;
			length--;
		}
		stack[0] = tmp;
	}
}