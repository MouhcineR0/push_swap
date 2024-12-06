/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:16:00 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/11/04 20:36:22 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptrr;

	ptrr = (unsigned char *) b;
	while (len--)
	{
		*ptrr = (unsigned char) c;
		ptrr++;
	}
	return (b);
}
