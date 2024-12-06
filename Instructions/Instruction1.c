/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:24:15 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/06 22:39:43 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(int	*stack_a,int length)
{
	int	tmp;
	
	if (length >= 2)
	{
		tmp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = tmp;
		ft_printf("sa\n");
	}
}
void	sb(int	*stack_b,int length)
{
	int	tmp;
	
	if (length >= 2)
	{
		tmp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = tmp;
		ft_printf("sb\n");
	}
}
void	ss(int *stack_a, int *stack_b , int length)
{
	sa(stack_a,length),sb(stack_b,length);
}
void	pa(int *stack_a, int *stack_b, int length)
{
	
}