/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isSorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:02:07 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/08 12:13:20 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *arr ,int arr_len) // returns the index where not sorted , if sorted -1 returned
{
	int i;

	i = 0;
	while (i + 1 < arr_len)
	{
		if (arr[i] > arr[i + 1])
			return (i);
		i++;
	}
	return (-1);
}
