/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:50:37 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/22 22:40:36 by rmouhcin         ###   ########.fr       */
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

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
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
	char	**tmp;

	i = 1;
	j = 0;
	while (i < length)
	{
		(1) && (split = ft_split(a[i], ' '), tmp = split);
		if (!split)
			return (0);
		while (*split)
		{
			if (!is_number(*split))
				return (free_str(tmp), 0);
			stack_a->arr[j] = ft_atoi(*split);
			(split)++;
			j++;
		}
		free_str(tmp);
		i++;
	}
	return (1);
}

int	verify_args(char **a, int length)
{
	int		i;
	int		j;
	char	**split;
	char	**tmp;

	i = 1;
	j = 0;
	while (i < length)
	{
		split = ft_split(a[i], ' ');
		tmp = split;
		while (*split)
		{
			if (!is_number(*split) || ft_atoi(*split) > 2147483647
				|| ft_atoi(*split) < -2147483648)
				return (free_str(tmp), 0);
			j++;
			(split)++;
		}
		free_str(tmp);
		i++;
	}
	return (j);
}
