/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:29:41 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/11/05 12:05:37 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = ft_strlen(s);
	while (i)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i--;
	}
	if (str[0] == (unsigned char)c)
		return ((char *)&str[0]);
	return (NULL);
}
