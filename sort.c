/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:57:59 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/10 19:06:46 by rmouhcin         ###   ########.fr       */
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
		min = i;
		while (i < length)
		{
			if (lst[i] < lst[min])
				min = i;
			i++;
		}
		return min;
	}
	return -1;
}
int lst_max(int *lst,int length)
{
	int i;
	int max;

	if (length)
	{
		i = 0;
		while (i < length)
		{
			if (lst[i] > lst[max])
				max = i;
			i++;
		}
		return max;
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
	if (lst[i] < lst[i - 1])
		return (++i);
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
	return many;
}

// method 1 nhzomjoj mn fo9 stack a n7tuhum f b w nsortiw fihum 3la 7asab dok 2 li 7tina f b

// ==> method 2 n9smu array 3la joj , w nsortiw manuel 3la 7asab chnu khaso ytsorta b swap only
// nhzu lmin f stack a w f stack b bach nsiviw start index dyalhum w ncheckiw kola mera wach msorti
// ncheckiw ta wach 1 li b9a lina mamsortich ye3ni rah kolchi m9ad

// method 3 nhzo ga3 les elemets dyal a w n7tuhum f b w nhzzo kola mra lwlani b 
// w n7tuh f list khawya a 3la 7asab wach kbira wla sghira

// method 4 kola mera n9leb 3la lmin f stack b w npushih f stack a

// method 5 n handliw kola size bo7do ===>
// length 3 : nhard codiw
// length 4 - 5 : nlo7o f stack b samllets 2 number or 1 w dok 3  nhadliwhum b tari9a lwlaniya
// length > 5 ncatiw kola part w nhandliwhum

void	Sort(int *stack_a,int *stack_b,int *stack_a_len,int *stack_b_len)
{	
	if (is_sorted(stack_a,*stack_a_len) == -1)
		return ;
	if (*stack_a_len == 2)
		return lst_case_2(stack_a,*stack_a_len);
	else if (*stack_a_len == 3)
		return lst_case_3(stack_a,*stack_a_len);
	else if (*stack_a_len == 4 || *stack_a_len == 5)
		return lst_case_4_5(stack_a,stack_b,stack_a_len,stack_b_len);
	// else
	// 	lst_large_case(stack_a,stack_b,stack_a_len,stack_b_len);
}
