/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayman <ayman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:40:48 by ayhammou          #+#    #+#             */
/*   Updated: 2025/11/21 15:32:14 by ayman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

char	*gnl_substr(char *buf);
size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(char *s1, const char *s2);
char	*gnl_strchr(const char *s, int c);
char	*gnl_buffer(char *buf);
char	*get_next_line(int fd);

#endif