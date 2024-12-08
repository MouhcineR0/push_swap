/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:57:59 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/08 20:50:36 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	separate_arr(int *stack_a,int *stack_b,int *stack_a_len,int *stack_b_len)
{
	int i;

	i = (*stack_a_len) / 2;
	while (i)
	{
		pb(stack_a,stack_b,stack_a_len,stack_b_len);
		i--;
	}
}

int lst_min(int *lst,int length)
{
	int i;
	int min;

	if (length)
	{
		i = 0;
		min = lst[i];
		while (i < length)
		{
			if (lst[i] < min)
				min = lst[i];
			i++;
		}
		return min;
	}
	return -1;
}

int non_sortedasc_index(int *lst,int length)
{
	int i;
	
	i = 0;
	while (i + 1 < length)
	{
		if (lst[i] > lst[i + 1])
			return i;
		i++;
	}
	return -1;
}
int non_sorteddisc_index(int *lst,int length)
{
	int i;
	
	i = 0;
	while (i + 1 < length)
	{
		if (lst[i] < lst[i + 1])
			return i;
		i++;
	}
	return -1;
}

int many_notsorted_asc(int *arr,int length)
{
	int many;
	int i;

	i = 0;
	many = 0;
	while (i + 1 < length)
	{
		if (arr[i] > arr[i + 1])
			many++;
		i++;
	}
	if (arr[i] > arr[i - 1])
		many++;
	return many;
}

// method 1 nhzomjoj mn fo9 stack a n7tuhum f b w nsortiw fihum 3la 7asab dok 2 li 7tina f b

// ==> method 2 n9smu array 3la joj , w nsortiw manuel 3la 7asab chnu khaso ytsorta b swap only
// nhzu lmin f stack a w f stack b bach nsiviw start index dyalhum w ncheckiw kola mera wach msorti
// ncheckiw ta wach 1 li b9a lina mamsortich ye3ni rah kolchi m9ad
void	Sort(int *stack_a,int *stack_b,int *stack_a_len,int *stack_b_len)
{
	int stack_a_index;
	int stack_b_index;
	if (*stack_a_len > 2)
	{
		if (is_sorted(stack_a,*stack_a_len) == -1)
			return ;
		separate_arr(stack_a,stack_b,stack_a_len,stack_b_len);
		while (1)
		{
			stack_a_index = non_sortedasc_index(stack_a,*stack_a_len) + 1;
			stack_b_index = non_sorteddisc_index(stack_b,*stack_b_len) + 1;
			if (stack_a_index != -1 && many_notsorted_asc(stack_a,*stack_a_len) != 1)
			{
				while (stack_a_index)
				{
					ft_printf("%d",stack_a_index);
					ra(stack_a,*stack_a_len);
					stack_a_index--;
				}
				sa(stack_a,*stack_a_len);
			}
			// break;
			ft_printf("==> ");
			lst_print(stack_a,*stack_a_len);
			if (many_notsorted_asc(stack_a,*stack_a_len) == 1)
				break;
			// else if (stack_a_index != -1)
			// {
				
			// }
			// else
			// break;
		}
	}
}
