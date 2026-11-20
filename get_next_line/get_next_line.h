/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:39:37 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/20 17:07:35 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "unistd.h"
# include "stdlib.h"

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_crline(char *src, size_t len);
void	ft_updtbuffer(char *src, size_t start, size_t end);
char	*ft_verify_line(char *line, char *buffer, size_t *bytes_read, int fd);
void	ft_setzero(char *buffer, size_t start, size_t end);

#endif