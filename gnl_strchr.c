/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhammou <ayhammou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:32:10 by ayhammou          #+#    #+#             */
/*   Updated: 2025/11/20 15:04:12 by ayhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;
	char	car;

	car = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return((char *) &s[i]);
		i++;
	}
	return (NULL);
}
