// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line_utils.c                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/10/27 11:34:43 by rmouhcin          #+#    #+#             */
// /*   Updated: 2024/12/18 11:52:17 by rmouhcin         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// static char	*nullcase(char const *s1, char const *s2)
// {
// 	if (s1)
// 		return (ft_strdup((char *)s1));
// 	else if (s2)
// 		return (ft_strdup((char *)s2));
// 	else
// 		return (NULL);
// }

// // char	*ft_strjoin(char const *s1, char const *s2)
// // {
// // 	size_t	s1_len;
// // 	size_t	s2_len;
// // 	size_t	i;
// // 	char	*p;

// // 	if (!s1 || !s2)
// // 		return (nullcase(s1, s2));
// // 	i = 0;
// // 	s1_len = ft_strlen(s1);
// // 	s2_len = ft_strlen(s2);
// // 	p = (char *)malloc(s1_len + s2_len + 1);
// // 	if (!p)
// // 		return (NULL);
// // 	while (i < s1_len + s2_len && *s1)
// // 	{
// // 		p[i] = *(s1++);
// // 		i++;
// // 	}
// // 	while (i < s1_len + s2_len && *s2)
// // 	{
// // 		p[i] = *(s2++);
// // 		i++;
// // 	}
// // 	p[i] = '\0';
// // 	return (p);
// // }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*p;
// 	size_t	i;

// 	if (!s)
// 		return (NULL);
// 	if (start > ft_strlen(s) || !*s)
// 		return (ft_strdup(""));
// 	if (len > ft_strlen(s) - start)
// 		len = ft_strlen(s) - start;
// 	p = (char *)malloc(len + 1);
// 	if (!p)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		p[i] = s[start];
// 		start++;
// 		i++;
// 	}
// 	p[i] = '\0';
// 	return (p);
// }

// char	*ft_strdup(char *src)
// {
// 	char	*copy;
// 	size_t	i;

// 	if (!src || !*src)
// 		return (NULL);
// 	copy = (char *) malloc(ft_strlen(src) + 1);
// 	if (!copy)
// 		return (0);
// 	i = 0;
// 	while (src[i])
// 	{
// 		copy[i] = src[i];
// 		i++;
// 	}
// 	copy[i] = '\0';
// 	return (copy);
// }
