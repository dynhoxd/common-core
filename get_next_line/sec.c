/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 19:14:38 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/18 19:35:00 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		bytes_read;
	size_t		counter;
	size_t		i;

	i = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (buffer[i])
	{
		if (buffer[i] != '\n')
			counter++;
		else
			line = ft_substr(buffer, 0, bytes_read + 2);
		i++;
	}
}
