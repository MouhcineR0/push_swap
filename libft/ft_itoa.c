/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:56:52 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/11/03 19:54:04 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fillnb(long nb, char *p, size_t index)
{
	p[index--] = '\0';
	if (nb < 0)
	{
		p[0] = '-';
		nb *= -1;
	}
	while (nb)
	{
		p[index] = nb % 10 + '0';
		index--;
		nb /= 10;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	nb;
	long	rlnb;
	char	*p;

	len = 0;
	nb = n;
	rlnb = n;
	if (!nb)
		return (ft_strdup("0"));
	if (nb < 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	return (fillnb(rlnb, p, len));
}
