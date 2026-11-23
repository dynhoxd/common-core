/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 19:14:38 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/23 22:50:08 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_rest(char **rest)
{
	char	*bl;
	char	*temp;
	
	if (!rest)
		return (NULL);
	bl = ft_strchr(rest, '\n');
	if (bl && bl + 1)
	{
		temp = ft_substr(*rest, bl + 1, ft_strlen(bl) + 1);
		free(*rest);
		*rest = temp;
	}
	else
		free(*rest);
		*rest = NULL;
	return (*rest);
}

char *get_line(char *rest, char **line)
{
	char	*bl;
	
	if (!rest)
		return (NULL);
	bl = ft_strchr(rest, '\n');
	if (bl)
		*line = ft_substr(rest, 0, (bl - rest) + 1);
	else
		*line = ft_substr(rest, 0, ft_strlen(rest) + 1);
	return (*line);
}

void	read_and_join(char **rest, int fd, char *buf, int bytes_rd)
{
	while (bytes_rd > 0 && (!(*rest) || !ft_strchr(*rest, '\n')))
	{
		bytes_rd = read(fd, buf, BUFFER_SIZE);
		if (bytes_rd == -1)
			return ;
		if (bytes_rd > 0)
		{
			buf[BUFFER_SIZE] = '\0';
			*rest = ft_strjoin(*rest, buf);
		}
	}
	return ;
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			bytes_rd;
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_rd = 1;
	read_and_join(&rest, fd, buf, bytes_rd);
	line = get_line(rest, &line);
	rest = new_rest(&rest);
	if ()
	return (line);
}
