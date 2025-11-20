/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:20:52 by ayhammou          #+#    #+#             */
/*   Updated: 2025/11/20 17:03:10 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*store;
	ssize_t		i;
	char		buffer[BUFFER_SIZE + 1];
	char	*line;
	
	i = 1;
	store = NULL;
	line = get_next_line(fd);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (gnl_strchr(store, '\n') == NULL && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free (store);
			store = NULL;
			return NULL;
		}
		buffer[i] = '\0';
		store = gnl_strjoin(store, buffer);
		if (store == 0 || *store == '\0')
			return (NULL);
	}
	line = gnl_substr(store);
	if (line == 0)
	{
		free (store);
		store == NULL;
		return (NULL);
	}
	store = gnl_buffer(store);
	return (line);
}
