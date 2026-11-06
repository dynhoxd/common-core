/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:36:24 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/06 19:44:56 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		number;
	char	sign;

	number = 0;
	sign = '+';
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (nptr[1] < '0' || nptr[1] > '9')
			return (0);
		sign = *nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
		number = (number * 10) + (*nptr++ - '0');
	if (sign == '-')
		return (-number);
	return (number);
}
