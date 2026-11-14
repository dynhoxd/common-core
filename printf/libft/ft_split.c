/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:42:12 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/09 17:38:20 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_str(char const *s, char sep)
{
	size_t	i;
	size_t	str;

	i = 0;
	str = 0;
	while (s[i])
	{
		if (s[i] != sep && (i == 0 || s[i - 1] == sep))
			str++;
		i++;
	}
	return (str);
}

static size_t	ft_strclen(char const *s, char end)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != end)
		i++;
	return (i);
}

static void	ft_free_arr(char **arr, size_t n)
{
	while (n > 0)
		free(arr[--n]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (ft_count_str(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			arr[i] = ft_substr(s, 0, ft_strclen(s, c));
			if (!arr[i])
				return (ft_free_arr(arr, i), NULL);
			i++;
			s += ft_strclen(s, c);
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}
