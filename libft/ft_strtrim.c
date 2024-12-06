/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:59:41 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/11/05 11:22:00 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find(const char *s, int c)
{
	char	*str;
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(s);
	str = (char *)s;
	i = 0;
	while (i < str_len && str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

static char	*handlenull(char const *s1)
{
	if (!s1)
		return (NULL);
	return ((char *)s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;
	int		j;
	int		fill;

	if (!set || !s1)
		return (handlenull(s1));
	i = 0;
	j = (int)ft_strlen(s1) - 1;
	fill = 0;
	while (find(set, s1[i]))
		i++;
	while (find(set, s1[j]) && j > i)
		j--;
	p = (char *)malloc(j - i + 2);
	if (!p)
		return (NULL);
	while (i <= j)
	{
		p[fill] = s1[i];
		fill++;
		i++;
	}
	p[fill] = '\0';
	return (p);
}
