/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:00:25 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/18 11:53:23 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libc.h>

int	in_list(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*getoneline(char **filecontent)
{
	int		cutindex;
	char	*freepointer;
	char	*tmp;

	cutindex = in_list(*filecontent, '\n');
	if (cutindex == -1)
	{
		freepointer = ft_strdup(*filecontent);
		if (*filecontent)
			free(*filecontent);
		*filecontent = NULL;
		return (freepointer);
	}
	tmp = ft_substr(*filecontent, 0, cutindex + 1);
	freepointer = *filecontent;
	*filecontent = ft_substr(*filecontent, cutindex + 1,
			ft_strlen(*filecontent));
	if (freepointer)
		free(freepointer);
	return (tmp);
}

int	readfile(char **filecontent, ssize_t *byteread, int fd)
{
	char	*buffer;
	char	*freepointer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	*byteread = read(fd, buffer, BUFFER_SIZE);
	while (*byteread > 0)
	{
		buffer[*byteread] = '\0';
		freepointer = *filecontent;
		*filecontent = ft_strjoin(*filecontent, buffer);
		if (freepointer)
			free(freepointer);
		if ((in_list(*filecontent, '\n') != -1 || !*byteread))
			break ;
		*byteread = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (*byteread < 0)
	{
		free(*filecontent);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*filecontent;
	ssize_t			byteread;

	byteread = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	if (!readfile(&filecontent, &byteread, fd))
		return (NULL);
	return (getoneline(&filecontent));
}
