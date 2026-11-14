/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:49:36 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/09 21:48:46 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*st;
	unsigned char		ch;

	st = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*st == ch)
			return ((void *)st);
		st++;
	}
	return (0);
}
