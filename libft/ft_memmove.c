/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:15:58 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/10/29 15:23:35 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;

	source = (const unsigned char *)src;
	dest = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	if (dest < source)
	{
		while (len--)
			*dest++ = *source++;
	}
	else
	{
		source += len;
		dest += len;
		while (len--)
		{
			*(--dest) = *(--source);
		}
	}
	return (dst);
}
