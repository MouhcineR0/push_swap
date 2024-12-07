/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:08:42 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/07 13:05:08 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "printf/ft_printf.h"
#include "libft/libft.h"

void	sa(int	*stack_a,int length);
void	sb(int	*stack_b,int length);
void	ss(int *stack_a, int *stack_b , int stack_a_len, int stack_b_len);
void	pa(int *stack_a, int *stack_b, int *stack_a_len, int *stack_b_len);
void	pb(int *stack_a, int *stack_b, int *stack_a_len, int *stack_b_len);

#endif