/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:14:32 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/11/03 19:53:56 by rmouhcin         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int			sign;
	long long	result;
	long long	history;

	result = 0;
	sign = 1;
	history = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = getsign(&str);
	while (ft_isdigit((int)*str))
	{
		result = result * 10 + *str - '0';
		if (history != result / 10 && sign == -1)
			return (0);
		else if (history != result / 10 && sign == 1)
			return (-1);
		str++;
		history = result;
	}
	return (sign * result);
}
