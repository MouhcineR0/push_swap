/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:08:42 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/18 11:51:07 by rmouhcin         ###   ########.fr       */
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

// typedef struct t_shank {
// 	int *arr;
// 	int start;
// 	int end;
// 	int length; // length of shrunk
// } t_shank ;

void	sa(t_stack *a, int print);
void	sb(t_stack *b, int print);
void	ss(t_stack *a,t_stack *b);
void	pa(t_stack *a,t_stack *b); // push in stack a
void	pb(t_stack *a,t_stack *b); // push in stack b
void	ra(t_stack *a, int print);
void	rb(t_stack *b, int print);
void	rr(t_stack *a,t_stack *b);
void	rra(t_stack *a, int print);
void	rrb(t_stack *b, int print);
void	rrr(t_stack *a,t_stack *b);
int		is_sorted(int *arr ,int arr_len);
void	Sort(t_stack *a,t_stack *b);
int 	lst_min(int *lst,int length);
void	lst_case_2(t_stack *stack);
void	lst_case_3(t_stack *stack);
void	lst_case_4_5(t_stack *a,t_stack *b);
void	lst_case_5(t_stack *a,t_stack *b);
void	lst_large_case(t_stack *a,t_stack *b, int shank_length);
int lst_max(int *lst,int length);
int *longest_increasing_subsequence(int *arr, int n, int *result_size);
int	shank_element(t_stack *shank,t_stack *a,int shank_length);
void shank_move(t_stack *a,t_stack *b,int *tmp);
void low_cost_move(t_stack *a,t_stack *b);
int get_cost_index(t_stack *stack, int nb);
void push_a(t_stack *a,t_stack *b,int index);
int	where_to_place(t_stack *stack,int nb);
int	verify_args(char **a, int length);
int	raise_error(void);
int	fill(char **a, t_stack *stack_a, int length);
int	is_duplicated(t_stack stack);






#endif