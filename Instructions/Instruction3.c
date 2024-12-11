/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:51:20 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/11 09:57:03 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rrr : rra and rrb at the same time.
void	rrr(int *stack_a, int *stack_b, int *stack_a_len, int *stack_b_len)
{
	rra(stack_a,*stack_a_len),rrb(stack_b,*stack_b_len);
}
