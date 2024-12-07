/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:24:15 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/07 13:26:30 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(int	*stack_a,int stack_a_len)
{
	int	tmp;
	
	if (stack_a_len >= 2)
	{
		tmp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = tmp;
		ft_printf("sa\n");
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
		ft_printf("sb\n");
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
		stack_b[i] = 0;
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
		lst_print(stack_b,3); // empty stack b list
		stack_a[i] = 0;
	(*stack_b_len)++;
	(*stack_a_len)--;
	}
	
}