/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:29:01 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/07 17:34:55 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, (int)s1[start]))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (end > start && ft_strchr(set, (int)s1[end - 1]))
		end--;
	size = (end - start) + 1;
	str = malloc(size);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], size);
	return (str);
}
