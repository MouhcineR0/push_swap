/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:14:32 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/22 22:40:53 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getsign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	return (sign);
}

long long	ft_atoi(const char *str)
{
	int			sign;
	long long	result;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = getsign(&str);
	while (ft_isdigit((int)*str))
	{
		result = result * 10 + *str - '0';
		if ((result > INT32_MAX && sign == 1)
			|| (result < INT32_MIN && sign == -1))
			return ((long)INT32_MAX + 1);
		str++;
	}
	return (sign * result);
}
