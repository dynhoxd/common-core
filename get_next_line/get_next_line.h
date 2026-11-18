/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:39:37 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/18 19:33:43 by jabernar         ###   ########.fr       */
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
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif