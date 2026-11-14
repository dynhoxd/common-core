/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:01:19 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/09 21:46:29 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && size - 1)
	{
		dst[i] = src[i];
		size--;
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
