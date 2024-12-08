/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:24:15 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/08 11:02:03 by rmouhcin         ###   ########.fr       */
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

void	sa(int	*stack_a,int stack_a_len)
{
	int	tmp;
	
	if (stack_a_len >= 2)
	{
		tmp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = tmp;
		// ft_printf("sa\n");   // write this after calling the functions
	}
}
void	sb(int	*stack_b,int stack_a_len)
{
	int	tmp;
	
	if (stack_a_len >= 2)
	{
		tmp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = tmp;
		// ft_printf("sb\n");
	}
}
void	ss(int *stack_a, int *stack_b , int stack_a_len, int stack_b_len)
{
	sa(stack_a,stack_a_len),sb(stack_b,stack_b_len);
}

void	pa(int *stack_a, int *stack_b, int *stack_a_len, int *stack_b_len) // push in stack a
{
	int	i;

	i = 1;
	if (*stack_b_len)
	{
		lst_push(stack_a,stack_b[0],*stack_a_len);
		while (i < *stack_b_len)
		{
			stack_b[i - 1] = stack_b[i];
			i++;
		}
		stack_b[--i] = 0;
		(*stack_a_len)++;
		(*stack_b_len)--;
	}
	
}
void	pb(int *stack_a, int *stack_b, int *stack_a_len, int *stack_b_len) // push in stack b
{
	int	i;

	i = 1;
	if (*stack_a_len)
	{
		lst_push(stack_b,stack_a[0],*stack_b_len);
		while (i < *stack_a_len)
		{
			stack_a[i - 1] = stack_a[i];
			i++;
		}
		stack_a[--i] = 0;
		(*stack_b_len)++;
		(*stack_a_len)--;
	}
}

//  Shift up all elements of the stack The first element becomes the last one

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

// rrr : rra and rrb at the same time.