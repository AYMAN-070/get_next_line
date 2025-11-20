/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:28:57 by ayhammou          #+#    #+#             */
/*   Updated: 2025/11/20 17:04:55 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	alloc(char *buf)
{
	size_t i;
	
	i = 0;
	while (buf[i])
	{
		if (buf[i] = '\n')
			return (i);
		i++;
	}
}
char	*gnl_substr(char *buf)
{
	char	*str;
	size_t	slen;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (buf == 0)
		return (NULL);
	slen = gnl_strlen(buf);
	i = alloc(buf);
	str = malloc (sizeof(char) * i + 1);
	str[i] = '\0';
	while (i > 0)
	{ 
		str[i - 1] = buf[i - 1];
	}
	return (str);
}
