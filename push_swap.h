/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:08:42 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/07 16:56:03 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "printf/ft_printf.h"
#include "libft/libft.h"
#include <fcntl.h>

void	sa(int	*stack_a,int length);
void	sb(int	*stack_b,int length);
void	ss(int *stack_a, int *stack_b , int stack_a_len, int stack_b_len);
void	pa(int *stack_a, int *stack_b, int *stack_a_len, int *stack_b_len);
void	pb(int *stack_a, int *stack_b, int *stack_a_len, int *stack_b_len);
void	ra(int *stack,int length);
void	rra(int *stack,int length);

#endif