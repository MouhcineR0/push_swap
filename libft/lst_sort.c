/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:07:05 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/18 21:14:53 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_sort(int *lst, int length)
{
	int	sorted;
	int	i;
	int	tmp;

	sorted = 0;
	while (!sorted)
	{
		i = 0;
		sorted = 1;
		while (i + 1 < length)
		{
			if (lst[i] >= lst[i + 1])
			{
				tmp = lst[i];
				lst[i] = lst[i + 1];
				lst[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
}
