/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:39:33 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/05 15:55:11 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*last_c;

	last_c = 0;
	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			last_c = (char *)s;
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (last_c);
}
