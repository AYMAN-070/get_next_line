/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayman <ayman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:20:52 by ayhammou          #+#    #+#             */
/*   Updated: 2025/11/21 18:40:25 by ayman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*store;
	ssize_t		i;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (gnl_strchr(store, '\n') == NULL)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free (store);
			return (NULL);
		}
		buffer[i] = '\0';
		store = gnl_strjoin(store, buffer);
		if (store == 0 || *store == '\0')
			return (NULL);
	}
	line = gnl_substr(store);
	if (line == NULL)
	{
		free (store);
		return (NULL);
	}
	store = gnl_buffer(store);
	return (line);
}

size_t	alloc(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*gnl_substr(char *buf)
{
	char	*str;
	ssize_t	i;

	i = 0;
	if (buf == 0)
		return (NULL);
	i = alloc(buf);
	str = malloc (sizeof(char) * (i + 2));
	if (str == 0)
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		str[i] = buf[i];
		i--;
	}
	return (str);
}

/* #include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *txt = get_next_line(fd);
	while (txt != NULL)
	{
		printf("%s",txt);
		txt = get_next_line(fd);
	}
} */