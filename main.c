/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:17:02 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/19 14:17:16 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lsts(int **a, int **b)
{
	free(*a);
	free(*b);
}

void ff()
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	atexit(ff);
	t_stack	a;
	t_stack	b;

	b.length = 0;
	if (argc == 1)
		return (0);
	a.length = verify_args((char **)argv, argc);
	if (a.length)
	{
		a.arr = (int *)malloc(sizeof(int) * a.length);
		b.arr = (int *)malloc(sizeof(int) * a.length);
		if (!a.arr || !a.arr)
			return (raise_error());
		if (!fill((char **)argv, &a, argc))
			return (raise_error());
		if (is_duplicated(a))
			return (raise_error());
		sort(&a, &b);
		// free_lsts(&(a.arr),&(b.arr));
		free(a.arr);
		free(b.arr);
	}
	else
		return (raise_error());
	return (0);
}
