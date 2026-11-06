/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 20:25:16 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/06 21:10:39 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*buffer;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buffer = malloc(s1_len + s2_len + 1);
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s1, s1_len + 1);
	ft_strlcat(buffer, s2, s1_len + s2_len + 1);
	return (buffer);
}
