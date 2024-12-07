/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:44:45 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/07 13:21:24 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_push(int *arr, int nb,int length)
{
	int	i;

	if (length)
	{
		i = 0;
		while (length--)
			arr[length + 1] = arr[length];
	}
	arr[length] = nb;
	// ft_printf("[%d]",arr[length]);
	// lst_print(arr,3);
}