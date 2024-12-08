/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:44:45 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/08 19:34:33 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_push(int *arr, int nb,int length)
{
	int	i;

	if (length >= 1)
	{
		i = 0;
		while (length)
		{
			length--;	
			arr[length + 1] = arr[length];
		}
	}
	arr[length] = nb;
}