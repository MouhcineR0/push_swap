/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:32:22 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/06 13:25:33 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int n, int fd, int *i)
{
	(*i)++;
	if (fd < 0)
		return ;
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	if (n >= 10)
	{
		ft_putnbr_fd_i(n / 10, fd, i);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}
