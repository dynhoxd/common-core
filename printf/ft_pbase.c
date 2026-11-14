/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pbase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 19:30:44 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/14 19:37:31 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pbase(unsigned long n, char *base)
{
	int		count;
	size_t	base_len;
	
	base_len = ft_strlen(base);
	if (n > base_len)
		count = ft_pbase(n / base_len, base);
	return (count += write (1, &base[n], 1));
}
