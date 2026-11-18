/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:39:12 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/18 19:06:44 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	waste[9999];
	static char	line[10000];
	char		buffer[BUFFER_SIZE + 1];
	size_t		bytes_read;
	size_t		i_b;
	size_t		i_l;
	size_t		i_w;
	size_t		i_w2;

	i_l = 0;
	i_w = 0;
	i_w2 = 0;
	while (i_l < sizeof(line))
		line[i_l++] = '\0';
	i_l = 0;
	while (waste[i_w])
	{
		if (waste[i_w] != '\n')
			line[i_l++] = waste[i_w++];
		else if (waste[i_w] == '\n')
		{
			if (!waste[i_w + 1])
			{
				line[i_l] = '\0';
				return (line); 
			}
			else
			{
				line[i_l] = '\n';
				line[i_l + 1] = '\0';
				while (waste[++i_w])
					waste[i_w2++] = waste[i_w];
				while (i_w2 <= i_w)
					waste[i_w2++] = '\0';
				return (line);
			}
		}
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (i_l && !bytes_read)
		return (line);
	if (!bytes_read)
		return (NULL);
	while (bytes_read)
	{
		i_b = 0;
		i_w = 0;
		while (buffer[i_b])
		{
			if (buffer[i_b] != '\n')
				line[i_l++] = buffer[i_b++];
			else if (buffer[i_b] == '\n')
			{
				if (!buffer[i_b + 1])
				{
					line[i_l] = '\0';
					return (line); 
				}
				else
				{
					line[i_l] = '\n';
					line[++i_l] = '\0';
					while (buffer[++i_b])
					{
						waste[i_w++] = buffer[i_b];
					}
					waste[i_w] = '\0';
					return (line); 
				}
			}
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}

#include "get_next_line.h"
#include <fcntl.h>
#include "stdio.h"

int	main(void)
{
	int	fd = open("exemp.txt", O_RDONLY);
	if (fd == -1)
		return 1;
	char *line;
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	return 0;
}