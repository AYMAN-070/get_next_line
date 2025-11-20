/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:40:48 by ayhammou          #+#    #+#             */
/*   Updated: 2025/11/20 17:29:19 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill(char *join, char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i] = s2[j];
		j++;
		i++;
	}
	join[i] = '\0';
	free (s1);
	return (join);
}

char	*gnl_strjoin(char *s1, const char *s2)
{
	char	*join;
	size_t		len1;
	size_t		len2;


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

#include <stdio.h>

int main(void)
{
	printf("%s", gnl_strjoin("ayman", "hm"));
	return(0);
}