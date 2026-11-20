/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:39:24 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/20 17:16:44 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	counter;

	counter = 0;
	while (*s++)
		counter++;
	return (counter);
}

char	*ft_crline(char *src, size_t size)
{
	char	*line;
	size_t	i;

	line = malloc(size);
	if (!line)
		return (NULL);
	i = 0;
	while (i < size - 2)
	{
		line[i] = src[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

void	ft_setzero(char *buffer, size_t start, size_t end)
{
	while (start < end)
		buffer[start++] = '\0';
}

void	ft_updtbuffer(char *buffer, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start + i < end)
	{
		buffer[i] = buffer[start + i];
		i++;
	}
	ft_setzero(buffer, i, end);
}

char	*ft_verify_line(char *line, char *buffer, size_t *bytes_read, int fd)
{
	size_t		counter;
	size_t		i;

	i = 0;
	counter = 0;
	while (i < bytes_read)
	{
		if (buffer[i] && buffer[i] != '\n')
			counter++;
		else if (buffer[i] && buffer[i] == '\n')
		{
			line = ft_crline(buffer, counter + 2);
			if (!line)
				return (NULL);
			if (buffer[++i])
				ft_updtbuffer(buffer, i, bytes_read);
			else
				ft_setzero(buffer, 0, bytes_read);
			return (line);
		}
		i++;
		if (!(i < bytes_read))
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (!bytes_read)
			{
				line = ft_crline(buffer, counter + 2);
				return (line);
			}
			else
			{
				i = 0;
				line = ft_crline(buffer, counter);
			}
		}
	}
	buffer[i] = '\0';
	return (line);
}
