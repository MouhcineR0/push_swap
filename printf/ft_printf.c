/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 02:08:00 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/11/13 11:43:07 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isprintf_case(const char **str, va_list *arguments, int *i)
{
	if (**str == 'c')
		return (putchar_case(va_arg(*arguments, int), (char **)str, i));
	else if (**str == 's')
		return (putstr_case(va_arg(*arguments, char *), (char **)str, i));
	else if (**str == 'd' || **str == 'i')
		return (putdigit_case(va_arg(*arguments, int), (char **)str, i));
	else if (**str == 'u')
		return (putunsigned_case(va_arg(*arguments, int), (char **)str, i));
	else if (**str == 'x')
		return (convert_base(va_arg(*arguments, unsigned long),
				(char **)str, "0123456789abcdef", i));
	else if (**str == 'X')
		return (convert_base(va_arg(*arguments, unsigned long),
				(char **)str, "0123456789ABCDEF", i));
	else if (**str == 'p')
		return (convert_base_pointer(va_arg(*arguments, unsigned long),
				(char **)str, "0123456789abcdef", i));
	else
		return (putpercent_case((char **)str, (char **)str, i));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	int		i;

	i = 0;
	va_start(arguments, str);
	while (*str)
	{
		if (*str == '%' && str++ && isprintf_case(&str, &arguments, &i))
			continue ;
		else if (*str)
		{
			ft_putchar_fd(*str, 1);
			str++;
			i++;
		}
	}
	va_end(arguments);
	return (i);
}
