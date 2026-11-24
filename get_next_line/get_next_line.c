/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 19:14:38 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/24 20:59:57 by jabernar         ###   ########.fr       */
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

char	*get_line(char *rest)
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

int	read_and_join(char **rest, int fd, char *buf)
{
	int		bytes_rd;
	char	*temp;

	bytes_rd = 1;
	while (bytes_rd > 0 && (!(*rest) || !ft_strchr(*rest, '\n')))
	{
		bytes_rd = read(fd, buf, BUFFER_SIZE);
		if (bytes_rd == -1)
			return (-1);
		if (bytes_rd > 0)
		{
			buf[bytes_rd] = '\0';
			temp = ft_strjoin(*rest, buf);
			free(*rest);
			*rest = temp;
		}
	}
	return (bytes_rd);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		bytes_rd;
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_rd = read_and_join(&rest, fd, buf);
	if (bytes_rd == -1)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line = get_line(rest);
	if (!line || !(*line))
	{
		free(line);
		free(rest);
		line = NULL;
		rest = NULL;
		return (NULL);
	}
	new_rest(&rest);
	return (line);
}
