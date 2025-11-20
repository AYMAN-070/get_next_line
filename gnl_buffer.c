/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:06:56 by ayhammou          #+#    #+#             */
/*   Updated: 2025/11/20 14:32:21 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_buffer(char *buf)
{
	size_t	i;
	char	*str;
	size_t	buflen;
	size_t	alloc;

	i = 0;
	buflen = gnl_strlen(buf);
	while (buf[i] != '\n')
		i++;
	if (buflen <= i + 1)
		return (NULL);
	alloc = buflen - (i + 1);
	str = malloc(sizeof(char) * alloc  + 1);
	while (buflen > i + 1)
	{
		str[alloc - 1] = buf[buflen];
		buflen--;
		alloc--;
	}
	free(buf);
	return (str);
}
