/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:55:43 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/19 20:55:49 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	raise_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	free_arr(int *arr1, int *arr2)
{
	free(arr1);
	free(arr2);
	return (1);
}
