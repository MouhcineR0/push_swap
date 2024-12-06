/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:33:07 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/06 13:28:59 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_i(int n, int fd, int *i)
{
	(*i)++;
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		*i += 10;
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
		(*i)++;
	}
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
