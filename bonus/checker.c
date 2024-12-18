/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:17:21 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/18 11:51:31 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextline/get_next_line.h"
#include "../push_swap.h"
#include "libc.h"


int push_swap(t_stack *a,t_stack *b)
{
	char *buffer;
	while ((buffer = get_next_line(0)))
	{
		printf("%s",buffer);		
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	// verify the arg first
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
		if (!push_swap(&a,&b))
			ft_putstr_fd("KO",1);
		else
			ft_putstr_fd("OK",1);
		free(a.arr);
		free(b.arr);
	}
	else
		return (raise_error());
	return (0);



	// char *buffer;
	// while ((buffer = get_next_line(0)))
	// {
	// 	printf("%s",buffer);		
	// }
	return 0;
}
