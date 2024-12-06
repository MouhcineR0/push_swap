/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printarray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:32:14 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/06 19:47:06 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printarray(int *arr,int len)
{
	int	i;

	i = 0;
	ft_printf("[");
	while (i < len)
	{
		ft_printf(" %d ",arr[i]);
		if (i + 1 != len)
			ft_printf(",");
		i++;
	}
	ft_printf("]");
}