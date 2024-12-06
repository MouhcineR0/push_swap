/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 03:03:46 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/11/04 20:34:08 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char c)
{
	int	len;
	int	found;

	found = 1;
	len = 0;
	while (*str)
	{
		if (*str != c && found)
		{
			len++;
			found = 0;
		}
		if (*str == c && !found)
			found = 1;
		str++;
	}
	return (len);
}

static void	free_location(char **p, int index)
{
	while (index >= 0)
	{
		free(p[index]);
		p[index] = NULL;
		index--;
	}
	free(p);
	p = NULL;
}

static int	allocate(char **p, char *tmp, int index, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tmp[j] != c && tmp[j])
		j++;
	p[index] = (char *)malloc(sizeof(char) * (j + 1));
	if (!p[index])
	{
		free_location(p, index);
		return (0);
	}
	while (*tmp != c && *tmp)
	{
		p[index][i] = *tmp;
		tmp++;
		i++;
	}
	p[index][i] = '\0';
	return (1);
}

static char	**fill(char **p, char *str, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	while (*str)
	{
		tmp = NULL;
		while (*str == c && *str)
			str++;
		if (*str && !allocate(p, str, i, c))
			return (NULL);
		while (*str != c && *str)
			str++;
		i++;
	}
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	int		len;

	if (!s)
		return (NULL);
	len = count_words((char *)s, c);
	list = (char **) malloc(sizeof(char *) * (len + 1));
	if (!list)
		return (NULL);
	list[len] = NULL;
	return (fill(list, (char *)s, c));
}
