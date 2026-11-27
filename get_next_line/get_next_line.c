/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 19:14:38 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/27 15:54:29 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	new_rest(char **rest)
{
	char	*temp;
	char	*lb;

	if (!*rest)
		return ;
	lb = ft_strchr(*rest, '\n');
	if (!lb || !*(lb + 1))
	{
		free(*rest);
		*rest = NULL;
		return ;
	}
	lb++;
	temp = ft_substr(lb, 0, ft_strlen(lb));
	free(*rest);
	*rest = temp;
}

char	*ft_get_line(char *rest)
{
	char	*lb;
	char	*line;

	if (!rest || !*rest)
		return (NULL);
	lb = ft_strchr(rest, '\n');
	if (lb)
		line = ft_substr(rest, 0, (lb - rest) + 1);
	else
		line = ft_substr(rest, 0, ft_strlen(rest));
	return (line);
}

int	read_and_join(char **rest, int fd)
{
	int		bytes_rd;
	char	*temp;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	bytes_rd = 1;
	while (bytes_rd > 0 && (!(*rest) || !ft_strchr(*rest, '\n')))
	{
		bytes_rd = read(fd, buf, BUFFER_SIZE);
		if (bytes_rd == -1)
			return (free(buf), -1);
		if (bytes_rd > 0)
		{
			buf[bytes_rd] = '\0';
			temp = ft_strjoin(*rest, buf);
			if (!temp)
				return (free(buf), -1);
			free(*rest);
			*rest = temp;
		}
	}
	free(buf);
	return (bytes_rd);
}

char	*get_next_line(int fd)
{
	ssize_t		bytes_rd;
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_rd = read_and_join(&rest, fd);
	if (bytes_rd == -1)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line = ft_get_line(rest);
	if (!line)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	new_rest(&rest);
	return (line);
}
// #include <fcntl.h>
// #include "stdio.h"

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("exemp.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }