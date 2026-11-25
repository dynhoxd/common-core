/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 19:33:33 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/25 20:05:20 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	new_rest(char **rest)
{
	char	*temp;
	char	*lb;

	if (!*rest)
		return ;
	lb = ft_strchr(*rest, '\n');
	if (!lb)
	{
		free(*rest);
		*rest = NULL;
		return ;
	}
	lb++;
	if (*lb)
	{
		temp = ft_substr(lb, 0, ft_strlen(lb));
		free(*rest);
		*rest = temp;
	}
	else
	{
		free(*rest);
		*rest = NULL;
	}
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
	static char	*rest[MAX_FD];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_rd = read_and_join(&rest[fd], fd);
	if (bytes_rd == -1)
	{
		free(rest[fd]);
		rest[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(rest[fd]);
	if (!line || !(*line))
	{
		free(line);
		free(rest[fd]);
		line = NULL;
		rest[fd] = NULL;
		return (NULL);
	}
	new_rest(&rest[fd]);
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