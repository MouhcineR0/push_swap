/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:51:20 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/12 09:06:45 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rrr : rra and rrb at the same time.
void	rrr(t_stack *a,t_stack *b)
{
	rra(a,0),rrb(b,0);
	ft_printf("rrr\n");
}
