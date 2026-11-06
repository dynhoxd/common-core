/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:38:41 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/05 17:31:33 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	j = 0;
	while (big[j] && len > j)
	{
		i = 0;
		while (big[j + i] == little[i] && (j + i) < len)
		{
			if (!little[i + 1])
				return ((char *)&big[j]);
			i++;
		}
		j++;
	}
	return (0);
}
