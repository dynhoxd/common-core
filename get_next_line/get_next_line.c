/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 19:14:38 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/20 17:08:42 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		bytes_read;
	size_t		i;

	i = 0;
	line = NULL;
	buffer[BUFFER_SIZE] = '\0';
	if (buffer[i])
	{
		bytes_read = ft_strlen(buffer);
		line = ft_verify_line(line, buffer, &bytes_read, fd);
		if (!line)
			return (NULL);
		return (line);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	line = ft_verify_line(line, buffer, &bytes_read, fd);
	if (!line)
		return (NULL);
	return (line);
}
