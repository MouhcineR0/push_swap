/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:47:29 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/06 13:26:24 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int		putchar_case(char c, char **s, int *i);
int		putstr_case(char *str, char **s, int *i);
int		putdigit_case(int nb, char **s, int *i);
int		putunsigned_case(int nb, char **s, int *i);
int		putpercent_case(char **str, char **s, int *i);
void	ft_putunsigned(unsigned int n, int fd, int *i);
int		convert_base(unsigned int nb, char **str,
			char *format, int *i);
int		convert_base_pointer(unsigned long p,
			char **str, char *format, int *i);
int		ft_printf(const char *str, ...);
void	ft_putnbr_fd_i(int n, int fd, int *i);

#endif