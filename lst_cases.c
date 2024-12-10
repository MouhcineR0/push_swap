/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:56:18 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/10 15:22:57 by rmouhcin         ###   ########.fr       */
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

void	lst_case_2(int *stack,int length)
{
	if (stack[0] > stack[1])
		sa(stack,length);
}
void	lst_case_3(int *stack,int length)
{
	if (stack[0] > stack[1] && stack[1] > stack[2]) // 3 2 1
		sa(stack,length),rra(stack,length),ft_printf("s");
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] > stack[2]) // 2 3 1
		rra(stack,length),ft_printf("l");
	else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] > stack[2]) // 3 1 2
		rra(stack,length),rra(stack,length),ft_printf("m");
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] < stack[2]) // 1 3 2
		rra(stack,length),sa(stack,length),ft_printf("n");
	else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] < stack[2]) // 2 1 3
		sa(stack,length),ft_printf("r");
}

void	lst_case_4_5(int *stack_a,int *stack_b,int *stack_a_len,int *stack_b_len)
{
	int min_index;

	if (*stack_a_len == 4)
	{
		min_index = lst_min(stack_a,*stack_a_len) + 1;
		if (min_index > *stack_a_len / 2 )
		{
			while (min_index != *stack_a_len + 1 && min_index++)
				rra(stack_a,*stack_a_len);
		}
		else if (min_index <= *stack_a_len / 2 )
		{
			while (--min_index)
				ra(stack_a,*stack_a_len);
		}
		pb(stack_a,stack_b,stack_a_len,stack_b_len);
		lst_case_3(stack_a,*stack_a_len);
		ft_printf("==> ");
	lst_print(stack_a,*stack_a_len);
	lst_print(stack_b,*stack_b_len);
		pa(stack_a,stack_b,stack_a_len,stack_b_len);
	}
	else
		lst_case_5(stack_a,stack_b,stack_a_len,stack_b_len);
}
void	lst_case_5(int *stack_a,int *stack_b,int *stack_a_len,int *stack_b_len)
{
	int min_index;

	min_index = lst_min(stack_a,*stack_a_len) + 1;
	if (min_index > *stack_a_len / 2 )
	{
		while (min_index != *stack_a_len + 1 && min_index++)
			rra(stack_a,*stack_a_len);
	}
	else if (min_index <= *stack_a_len / 2 )
	{
		while (--min_index)
			ra(stack_a,*stack_a_len);
	}
	pb(stack_a,stack_b,stack_a_len,stack_b_len);
	lst_print(stack_a,*stack_a_len);
	lst_case_4_5(stack_a,stack_b,stack_a_len,stack_b_len);
	// ft_printf("==> ");
	// lst_print(stack_a,*stack_a_len);
	// lst_print(stack_b,*stack_b_len);
	pa(stack_a,stack_b,stack_a_len,stack_b_len);
}
