/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:20:52 by ayhammou          #+#    #+#             */
/*   Updated: 2025/11/27 10:32:29 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*manage_store(char *store[], char *buffer, int fd)
{
	ssize_t	i;

	while (gnl_strchr(store[fd], '\n') == NULL)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return (NULL);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free (store[fd]);
			store[fd] = NULL;
			free (buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		if (i == 0)
		{
			free (buffer);
			break ;
		}
		store[fd] = gnl_strjoin(store[fd], buffer);
	}
	return (store[fd]);
}

char	*get_next_line(int fd)
{
	static char	*store[1024];
	char		*buffer;
	char		*line;

	buffer = NULL;
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	store[fd] = manage_store(store, buffer, fd);
	line = gnl_substr(store[fd]);
	if (line == NULL)
	{
		free (store[fd]);
		return (NULL);
	}
	store[fd] = gnl_buffer(store[fd]);
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
	return (i - 1);
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

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/* #include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("test1.txt", O_RDONLY);
	char *txt1 = get_next_line(fd1);
	char *txt2 = get_next_line(fd2);
	while (txt1 != NULL && txt2 != NULL)
	{
		if(txt1 != NULL)
		{
			printf("%s",txt1);
			free (txt1);
			txt1 = get_next_line(fd1);
		}
		if(txt2 != NULL)
		{
			printf("%s",txt2);
			free (txt2);
			txt2 = get_next_line(fd2);
		}
	}
	close(fd1);
	close(fd2);
	return(0);
} */
