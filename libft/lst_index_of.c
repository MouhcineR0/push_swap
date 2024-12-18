/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_index_of.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:01:21 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/18 21:14:12 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lst_index_of(int *lst, int length, int nb)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (lst[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}
