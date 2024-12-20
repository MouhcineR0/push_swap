/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:08:42 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/20 10:50:33 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2024
# endif

typedef struct t_stack
{
	int	*arr;
	int	length;
}	t_stack;

typedef struct t_ls
{
	int	*ls;
	int	*prev;
}	t_ls;

void	sa(t_stack *a, int print);
void	sb(t_stack *b, int print);
void	ss(t_stack *a, t_stack *b, int print);
void	pa(t_stack *a, t_stack *b, int print); // push in stack a
void	pb(t_stack *a, t_stack *b, int print); // push in stack b
void	ra(t_stack *a, int print);
void	rb(t_stack *b, int print);
void	rr(t_stack *a, t_stack *b, int print);
void	rra(t_stack *a, int print);
void	rrb(t_stack *b, int print);
void	rrr(t_stack *a, t_stack *b, int print);
int		is_sorted(int *arr, int arr_len);
void	sort(t_stack *a, t_stack *b);
int		lst_min(int *lst, int length);
void	lst_case_2(t_stack *stack);
void	lst_case_3(t_stack *stack);
void	lst_case_4_5(t_stack *a, t_stack *b);
void	lst_case_5(t_stack *a, t_stack *b);
void	lst_large_case(t_stack *a, t_stack *b, int shank_length);
int		lst_max(int *lst, int length);
int		*longest_sub(int *arr, int n, int *result_size);
int		shank_element(t_stack *shank, t_stack *a, int shank_length);
void	shank_move(t_stack *a, t_stack *b, int *tmp);
void	low_cost_move(t_stack *a, t_stack *b);
int		get_cost_index(t_stack *stack, int nb);
void	push_a(t_stack *a, t_stack *b, int index);
int		where_to_place(t_stack *stack, int nb);
int		verify_args(char **a, int length);
int		raise_error(void);
int		fill(char **a, t_stack *stack_a, int length);
int		is_duplicated(t_stack stack);
void	free_str(char **str);
int		free_arr(int *arr1, int *arr2);
char	*get_next_line(int fd);

#endif