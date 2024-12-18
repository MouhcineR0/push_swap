/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:57:59 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/18 10:02:13 by rmouhcin         ###   ########.fr       */
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
		max = 0;
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

void	Sort(t_stack *a,t_stack *b)
{
	if (is_sorted(a->arr,a->length) == -1)
		return ;
	if (a->length == 2)
		return lst_case_2(a);
	else if (a->length == 3)
		return lst_case_3(a);
	else if (a->length == 4 || a->length == 5)
		return lst_case_4_5(a,b);
	else if (a->length <= 10)
		lst_large_case(a,b,10);
	else if (a->length <= 50)
		lst_large_case(a,b,10); // 10 best case
	else if (a->length <= 100)
		lst_large_case(a,b,100);// 100 best case  // 50 9aset 700    Arguments: -3393 -1149 -633 6823 -3455 -4714 5017 -9709 -7046 408 6016 1097 6994 -13 -9509 5280 -9603 38 -6901 -9954 -5211 -3646 3445 6468 2287 6316 4788 -46 2274 7693 4230 8286 7835 1870 2173 -5047 -8705 3053 -7879 155 -7589 -9891 -7604 7521 -8313 6155 -4750 9739 3273 8276 5561 5802 7106 4179 -112 3239 -9065 -2052 2848 8271 -9342 -2810 6942 8181 7167 -4552 -2698 -818 -8130 -6531 5797 5987 -2497 6791 3019 2323 9005 -2840 6062 -1338 -45 6227 -7541 7203 -6751 7514 -7490 -9373 2158 -5985 5304 -7213 3140 -9405 5487 -1758 19 -7995 2944 -9156
	else
		lst_large_case(a,b,100); // 100 best case
}
