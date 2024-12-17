/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:17:02 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/17 04:21:18 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_duplicated(t_stack stack)
{
	int i;
	int j;

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

int isNumber(char *str)
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

int fill(char **a,t_stack *stack_a,int length) // fill in the stack a
{
	int	i;
	int	j;
	char **split;
 
	i = 1;
	j = 0;
	while (i < length)
	{
		split = ft_split(a[i],' ');
		if (!split)
			return (0);
		while (*split)
		{
			if (!isNumber(*split))
				return (0);
			stack_a->arr[j] = ft_atoi(*split);
			(split)++;
			j++;
		}
		i++;
	}
	return (1);
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
			if (!isNumber(*split) || ft_atoi(*split) > 2147483647 || ft_atoi(*split) < -2147483648)
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
	t_stack a;
	t_stack b;

	b.length = 0;
	if (argc == 1)
		return (0);
	a.length = verify_args((char **)argv,argc);
	if (a.length)
	{
		a.arr = (int *)malloc(sizeof(int) * a.length);
		b.arr = (int *)malloc(sizeof(int) * a.length);
		if (!a.arr || !a.arr)
			return RaiseError();
		if (!fill((char **)argv,&a,argc))
			return (RaiseError());
		if (is_duplicated(a))
			return (RaiseError());
		// lst_print(a.arr,a.length);
		// lst_print(b.arr,b.length);
		Sort(&a,&b);
		// lst_print(a.arr,a.length);
		// lst_print(b.arr,b.length);
		free(a.arr);
		free(b.arr);
	}
	else
		return RaiseError();
	return 0;
}
