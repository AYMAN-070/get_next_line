/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:06:56 by ayhammou          #+#    #+#             */
/*   Updated: 2025/11/25 14:13:23 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alloc_newbuffer(size_t i, size_t alloc, char *buf)
{
	size_t	j;
	char	*str;

	str = malloc(sizeof(char) * (alloc + 1));
	if (str == 0)
		return (NULL);
	j = 0;
	while (j < alloc)
	{
		str[j] = buf[i + 1];
		j++;
		i++;
	}
	str[j] = '\0';
	free(buf);
	return (str);
}

char	*gnl_buffer(char *buf)
{
	size_t	i;
	size_t	buflen;
	size_t	alloc;

	i = 0;
	if (buf == 0)
	{
		free(buf);
		return (NULL);
	}
	buflen = gnl_strlen(buf);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buflen == i + 1 || buflen == i)
	{
		free(buf);
		return (NULL);
	}
	alloc = buflen - (i + 1);
	return (alloc_newbuffer(i, alloc, buf));
}

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;
	char	car;

	if (s == 0)
		return (NULL);
	car = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == car)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}

static char	*fill(char *join, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == 0)
		i = 0;
	else
	{
		while (s1[i])
		{
			join[i] = s1[i];
			i++;
		}
		free (s1);
	}
	while (s2[j])
	{
		join[i] = s2[j];
		j++;
		i++;
	}
	join[i] = '\0';
	free(s2);
	return (join);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;

	len1 = gnl_strlen(s1);
	len2 = gnl_strlen(s2);
	join = malloc(sizeof(char) * (len1 + len2 + 1));
	if (join == 0)
	{
		free (s1);
		free (s2);
		return (NULL);
	}
	return (fill(join, s1, s2));
}
