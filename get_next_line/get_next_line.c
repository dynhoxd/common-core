/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:39:12 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/17 20:16:28 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer[BUFFER_SIZE];
	size_t	bytes_read;
	
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read)
	{
		
	}
	
}
