/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:41:36 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/11/04 16:45:49 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*nullcase(char const *s1, char const *s2)
{
	if (s1)
		return (ft_strdup((char *)s1));
	else if (s2)
		return (ft_strdup((char *)s2));
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*p;

	if (!s1 || !s2)
		return (nullcase(s1, s2));
	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	p = (char *)malloc(s1_len + s2_len + 1);
	if (!p)
		return (NULL);
	while (i < s1_len + s2_len && *s1)
	{
		p[i] = *(s1++);
		i++;
	}
	while (i < s1_len + s2_len && *s2)
	{
		p[i] = *(s2++);
		i++;
	}
	p[i] = '\0';
	return (p);
}
