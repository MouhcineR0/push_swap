/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:08:42 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/11 13:47:42 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "printf/ft_printf.h"
#include "libft/libft.h"
#include <fcntl.h>

typedef struct t_stack {
	int *arr;
	int length;
} t_stack ;

typedef struct t_shunk {
	int elem1;
	int elem2;
	int elem3;
	int length; // length of shrunk
	int current_index; // current index of the original list
} t_shunk ;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a,t_stack *b);
void	pa(t_stack *a,t_stack *b); // push in stack a
void	pb(t_stack *a,t_stack *b); // push in stack b
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a,t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a,t_stack *b);
int		is_sorted(int *arr ,int arr_len);
void	Sort(t_stack *a,t_stack *b);
int 	lst_min(int *lst,int length);
int 	many_notsorted_asc(int *arr,int length);
void	lst_case_2(t_stack *stack);
void	lst_case_3(t_stack *stack);
void	lst_case_4_5(t_stack *a,t_stack *b);
void	lst_case_5(t_stack *a,t_stack *b);
void	lst_large_case(t_stack *a,t_stack *b);

#endif