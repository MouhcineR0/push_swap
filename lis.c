/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:55:13 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/18 20:41:20 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*lst_fill(int *arr, int length, int val)
{
	int	i;

	i = 0;
	arr = malloc(length * sizeof(int));
	while (i++ < length)
		arr[i] = val;
	return (arr);
}

void	get_ls(int *arr, t_ls *two_lst, int length)
{
	int	i;
	int	j;

	i = 1;
	while (i++ < length)
	{
		j = 0;
		while (j++ < i)
		{
			if (arr[i] > arr[j] && two_lst->ls[i] < two_lst->ls[j] + 1)
			{
				two_lst->ls[i] = two_lst->ls[j] + 1;
				two_lst->prev[i] = j;
			}
		}
	}
}

void	count_maxlen(t_ls *two_lst, int *max_len, int *end_index, int size)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		if (two_lst->ls[i] > *max_len)
		{
			*max_len = two_lst->ls[i];
			*end_index = i;
		}
	}
}

int	*longest_sub(int *arr, int n, int *result_size)
{
	t_ls		two_lst;
	int			*lis;
	int			max_length;
	int			end_index;
	int			k;

	(1) && (max_length = 0, end_index = 0);
	two_lst.ls = lst_fill(two_lst.ls, n, 1);
	two_lst.prev = lst_fill(two_lst.prev, n, -1);
	get_ls(arr, &two_lst, n);
	count_maxlen(&two_lst, &max_length, &end_index, n);
	lis = malloc(max_length * sizeof(int));
	k = max_length - 1;
	while (end_index != -1)
		(1) && (lis[k--] = arr[end_index], end_index = two_lst.prev[end_index]);
	*result_size = max_length;
	free(two_lst.ls);
	free(two_lst.prev);
	return (lis);
}
