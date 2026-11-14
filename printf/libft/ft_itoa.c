/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:39:15 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/09 19:28:03 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbchrlen(long n)
{
	size_t	size;

	size = 0;
	while (n > 9)
	{
		size++;
		n /= 10;
	}
	return (++size);
}

static void	ft_nbtstr(char *s, size_t n)
{
	if (n > 9)
		ft_nbtstr(s - 1, (n / 10));
	*s = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	size_t	sign;
	size_t	size;

	sign = 0;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		sign = 1;
	}
	size = ft_nbchrlen(nb) + sign;
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	ft_nbtstr(&str[size - 1], nb);
	str[size] = '\0';
	return (str);
}
