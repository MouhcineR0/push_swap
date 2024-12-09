/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:08:42 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/09 19:58:26 by rmouhcin         ###   ########.fr       */
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
void rrb(int *stack,int length);
int	is_sorted(int *arr ,int arr_len);
void	separate_arr(int *stack_a,int *stack_b,int *stack_a_len,int *stack_b_len);
void	Sort(int *stack_a,int *stack_b,int *stack_a_len,int *stack_b_len);
int lst_min(int *lst,int length);
int many_notsorted_asc(int *arr,int length);
void	lst_case_2(int *stack,int length);


#endif