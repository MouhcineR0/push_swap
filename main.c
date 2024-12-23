/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:17:02 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/23 11:16:09 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
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
		if ((!a.arr || !a.arr) && free_arr(a.arr, b.arr))
			return (raise_error());
		if (!fill((char **)argv, &a, argc) && free_arr(a.arr, b.arr))
			return (raise_error());
		if (is_duplicated(a) && free_arr(a.arr, b.arr))
			return (raise_error());
		sort(&a, &b);
		free(a.arr);
		free(b.arr);
	}
	else
		return (raise_error());
	return (0);
}
