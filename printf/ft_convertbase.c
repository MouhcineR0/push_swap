/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:10:14 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/06 13:53:36 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbase(unsigned long nb, char *format, int base_len, int *i)
{
	if (nb > 0)
	{
		(*i)++;
		ft_putbase(nb / base_len, format, base_len, i);
		ft_putchar_fd(format[nb % base_len], 1);
	}
}

int	convert_base(unsigned int nb, char **str, char *format, int *i)
{
	int	base_len;

	(*str)++;
	if (!nb)
	{
		ft_putstr_fd("0", 1);
		(*i)++;
		return (1);
	}
	if (!*format || !format)
		return (0);
	base_len = ft_strlen(format);
	ft_putbase(nb, format, base_len, i);
	return (1);
}

int	convert_base_pointer(unsigned long p, char **str, char *format, int *i)
{
	int	base_len;

	(*str)++;
	if (!*format || !format)
		return (0);
	if (!p)
	{
		*i += 3;
		ft_putstr_fd("0x0", 1);
		return (1);
	}
	base_len = ft_strlen(format);
	ft_putstr_fd("0x", 1);	
	*i += 2;
	ft_putbase(p, format, base_len, i);
	return (1);
}
