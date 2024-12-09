/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:56:18 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/09 22:10:24 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include "push_swap.h"

void	lst_case_2(int *stack,int length)
{
	if (stack[0] > stack[1])
		sa(stack,length);
}
void	lst_case_3(int *stack,int length)
{
	if (stack[0] > stack[1] && stack[1] > stack[2]) // 3 2 1
		sa(stack,length),rra(stack,length);
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] > stack[2]) // 2 3 1
		// handle each case 
	else if (stack[0] > stack[1] && stack[1] < stack[2]) // 3 1 2
		sa(stack,length);
	else if (stack[0] < stack[1] && stack[1] > stack[2]) // 1 3 2
		sa(stack,length);
	else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] < stack[2]) // 2 1 3
		sa(stack,length);
}

void	lst_case_4_5(int *stack_a,int *stack_b,int *stack_a_len,int *stack_b_len)
{
	
}