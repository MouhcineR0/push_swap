/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:17:02 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/06 22:42:15 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isNumber(char *str)
{
	while (*str)
	{
		if (!ft_isdigit((int)*str))
			return (0);
		str++;
	}
	return (1);
}

int *fill(char **a,int *stack_a,int length) // fill in the stack a
{
	int	i;
	int	j;
	char **split;
 
	i = 1;
	j = 0;
	while (i < length)
	{
		split = ft_split(a[i],' ');
		while (*split)
		{
			if (!isNumber(*split))
				return (0);
			stack_a[j] = ft_atoi(*split);
			(split)++;
			j++;
		}
		i++;
	}
	return (stack_a);
}

int verify_args(char **a, int length) // verifying and calculates the length of stack a
{
	int	i;
	int	j;
	char **split;
 
	i = 1;
	j = 0;
	while (i < length)
	{
		split = ft_split(a[i],' ');
		while (*split)
		{
			if (!isNumber(*split))
				return (0);
			(split)++;
			j++;
		}
		i++;
	}
	return (j);
}

int RaiseError()
{
	ft_putstr_fd("Error\n",2);
	return 0;
}

int main(int argc, char const *argv[])
{
	int *stack_a;
	int *stack_b;
	int	stack_a_len;
	int	stack_b_len;

	if (argc == 1)
		return (0);
	stack_a_len = verify_args((char **)argv,argc);
	if (stack_a_len)
	{
		stack_a = (int *)malloc(sizeof(int) * stack_a_len);
		stack_b = (int *)malloc(sizeof(int) * stack_a_len);
		if (!stack_a || !stack_b)
			return RaiseError();
		// Sort(fill((char **)argv,stack_a,argc),stack_b,stack_a_len);
		fill((char **)argv,stack_a,argc);
		sa(stack_a,stack_a_len);
		printarray(stack_a,stack_a_len);
		free(stack_a);
	}
	else
		return RaiseError();
	return 0;
}
