/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:58:59 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/06 13:25:45 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_case(char c, char **s, int *i)
{
	(*i)++;
	ft_putchar_fd(c, 1);
	(*s)++;
	return (1);
}

int	putstr_case(char *str, char **s, int *i)
{
	ft_putstr_fd(str, 1);
	if (!str)
		*i += 6;
	else
		*i += ft_strlen(str);
	(*s)++;
	return (1);
}

int	putdigit_case(int nb, char **s, int *i)
{
	ft_putnbr_fd_i(nb, 1, i);
	(*s)++;
	return (1);
}

int	putunsigned_case(int nb, char **s, int *i)
{
	ft_putunsigned(nb, 1, i);
	(*s)++;
	return (1);
}

int	putpercent_case(char **str, char **s, int *i)
{
	ft_putchar_fd(**str, 1);
	if (**str)
		(*s)++;
	(*i)++;
	return (1);
}
