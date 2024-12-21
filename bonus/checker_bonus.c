/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:17:21 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/21 14:13:41 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_instruction(t_stack *a, t_stack *b, char *instraction)
{
	if (!ft_strcmp(instraction, "sa"))
		sa(a, 0);
	else if (!ft_strcmp(instraction, "sb"))
		sb(b, 0);
	else if (!ft_strcmp(instraction, "ss"))
		ss(a, b, 0);
	else if (!ft_strcmp(instraction, "pa"))
		pa(a, b, 0);
	else if (!ft_strcmp(instraction, "pb"))
		pb(a, b, 0);
	else if (!ft_strcmp(instraction, "ra"))
		ra(a, 0);
	else if (!ft_strcmp(instraction, "rb"))
		rb(b, 0);
	else if (!ft_strcmp(instraction, "rr"))
		rr(a, b, 0);
	else if (!ft_strcmp(instraction, "rra"))
		rra(a, 0);
	else if (!ft_strcmp(instraction, "rrb"))
		rrb(b, 0);
	else if (!ft_strcmp(instraction, "rrr"))
		rrr(a, b, 0);
}

int	isvalid_instruction(char *str)
{
	if (ft_strcmp(str, "sa") && ft_strcmp(str, "sb")
		&& ft_strcmp(str, "ss") && ft_strcmp(str, "pa")
		&& ft_strcmp(str, "pb") && ft_strcmp(str, "ra")
		&& ft_strcmp(str, "rb") && ft_strcmp(str, "rr")
		&& ft_strcmp(str, "rra") && ft_strcmp(str, "rrb")
		&& ft_strcmp(str, "rrr"))
		return (0);
	return (1);
}

int	swap_push(t_stack *a, t_stack *b)
{
	char	*buffer;
	char	**instr;

	while (1)
	{
		buffer = get_next_line(0);
		if (!buffer || !*buffer)
		{
			free(buffer);
			return (1);
		}
		instr = ft_split(buffer, '\n');
		free(buffer);
		if (instr && isvalid_instruction(instr[0]))
		{
			do_instruction(a, b, instr[0]);
			free_str(instr);
		}
		else
		{
			free_str(instr);
			return (ft_putstr_fd("Error\n", 2), 0);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	b.length = 0;
	if (argc == 1)
		return (0);
	a.length = verify_args((char **)argv, argc);
	if (!a.length)
		return (raise_error());
	a.arr = (int *)malloc(sizeof(int) * a.length);
	b.arr = (int *)malloc(sizeof(int) * a.length);
	if (!a.arr || !a.arr)
		return (raise_error());
	if ((!fill((char **)argv, &a, argc)
			|| is_duplicated(a)) && free_arr(a.arr, b.arr))
		return (raise_error());
	if (!swap_push(&a, &b) && free_arr(a.arr, b.arr))
		return (raise_error());
	if (is_sorted(a.arr, a.length) == -1 && b.length == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(a.arr);
	free(b.arr);
	return (0);
}
