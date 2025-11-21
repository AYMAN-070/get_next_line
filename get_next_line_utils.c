/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayman <ayman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:06:56 by ayhammou          #+#    #+#             */
/*   Updated: 2025/11/21 19:17:50 by ayman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_buffer(char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	buflen;
	size_t	alloc;

	i = 0;
	j = 0;
	buflen = gnl_strlen(buf);
	while (buf[i] != '\n')
		i++;
	if (buflen == i + 1)
		return (NULL);
	alloc = buflen - (i + 1);
	str = malloc(sizeof(char) * alloc + 1);
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

static char	*fill(char *join, char *s1, const char *s2)
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
	}
	while (s2[j])
	{
		join[i] = s2[j];
		j++;
		i++;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}

char	*gnl_strjoin(char *s1, const char *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;

	len1 = gnl_strlen((const char *)s1);
	len2 = gnl_strlen(s2);
	join = malloc(sizeof(char) * (len1 + len2 + 1));
	if (join == 0)
	{
		free (s1);
		return (NULL);
	}
	return (fill(join, s1, s2));
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