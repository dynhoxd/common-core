/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 19:14:38 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/22 22:29:18 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_line(char **rest, int fd)
{
	char	*linebk;
	char	*line;
	char	*temp;

	linebk = NULL;
	linebk = ft_strchr(rest, '\n');
	if (linebk)
	{
		if (rest[(long)linebk + 1])
		{
			temp = ft_strjoin(temp, &rest[(long)linebk + 1]);
			*rest = temp;
			line = ft_substr(rest, 0, (linebk - rest) + 2);
			return (line);
		}
		else
		{
			line = ft_substr(rest, 0, (linebk - rest) + 1);
			return (line);
		}
		
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			bytes_rd;
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_rd = read(fd, buf, BUFFER_SIZE);
	if (bytes_rd = -1)
		return (NULL);
	rest = ft_strjoin(rest, buf);
	line = check_line(rest, fd);
	return (line);
}
