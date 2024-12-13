/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:27:11 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/13 14:59:04 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_cpy(int *original_lst,int *new_lst,int length)
{
	int i;
	i = 0;
	while (i < length)
	{
		new_lst[i] = original_lst[i];
		i++;
	}
}