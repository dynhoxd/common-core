/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:39:24 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/23 22:12:37 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	counter;

	if(!s)
		return (0);
	counter = 0;
	while (*s++)
		counter++;
	return (counter);
}

char	*ft_strchr(char *s, int c)
{
	char	ch;

	ch = (char)c;
	if(!s)
		return (NULL);
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}
char	*ft_strjoin(char **s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*str;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)*s2);
	str = malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (free(*s1), str);
}
char	*ft_substr(char **s, unsigned int start,
size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (start < len)
		sub[i++] == (*s)[start++];
	sub[i] = '\0';
	return (sub);
}
