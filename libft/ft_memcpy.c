/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:15:56 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/10/30 12:52:51 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dsst;

	if (!src && !dst)
		return (NULL);
	dsst = (unsigned char *)dst;
	while (n--)
	{
		*(unsigned char *)dsst = *(unsigned char *)src;
		dsst++;
		src++;
	}
	return (dst);
}
