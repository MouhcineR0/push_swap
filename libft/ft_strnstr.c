/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:41:56 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/10/28 08:45:38 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[j] && j < len)
	{
		if (needle[0] == haystack[j] && j < len)
		{
			i = 0;
			while (needle[i] == haystack[j + i] && j + i < len && needle[i])
				i++;
			if (!needle[i])
				return ((char *)&haystack[j]);
		}
		j++;
	}
	return (NULL);
}
