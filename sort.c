/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:57:59 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/18 21:45:55 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_min(int *lst, int length)
{
	int	i;
	int	min;

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
		return (min);
	}
	return (-1);
}

int	lst_max(int *lst, int length)
{
	int	i;
	int	max;

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
		return (max);
	}
	return (-1);
}

void	sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a->arr, a->length) == -1)
		return ;
	if (a->length == 2)
		return (lst_case_2(a));
	else if (a->length == 3)
		return (lst_case_3(a));
	else if (a->length == 4 || a->length == 5)
		return (lst_case_4_5(a, b));
	else if (a->length <= 10)
		return (lst_large_case(a, b, 10));
	else if (a->length <= 50)
		return (lst_large_case(a, b, 10));
	else if (a->length <= 100)
		return (lst_large_case(a, b, 100));
	else
		return (lst_large_case(a, b, 100));
}
