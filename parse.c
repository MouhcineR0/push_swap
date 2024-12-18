/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:50:37 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/18 20:17:42 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicated(t_stack stack)
{
	int	i;
	int	j;

	i = 0;
	while (i + 1 < stack.length)
	{
		j = i + 1;
		while (j < stack.length)
		{
			if (stack.arr[i] == stack.arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit((int)*str))
			return (0);
		str++;
	}
	return (1);
}

int	fill(char **a, t_stack *stack_a, int length)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	j = 0;
	while (i < length)
	{
		split = ft_split(a[i], ' ');
		if (!split)
			return (0);
		while (*split)
		{
			if (!is_number(*split))
				return (0);
			stack_a->arr[j] = ft_atoi(*split);
			(split)++;
			j++;
		}
		i++;
	}
	return (1);
}

int	verify_args(char **a, int length)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	j = 0;
	while (i < length)
	{
		split = ft_split(a[i], ' ');
		while (*split)
		{
			if (!is_number(*split) || ft_atoi(*split) > 2147483647
				|| ft_atoi(*split) < -2147483648)
				return (0);
			(split)++;
			j++;
		}
		i++;
	}
	return (j);
}

int	raise_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}
