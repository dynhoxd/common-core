/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:25:43 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/17 16:10:11 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_ri(const char *str)
{
	int	count;
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = 0;
	i = 0;
	while (str[i])
		count += write(1, &str[i++], 1);
	return (count);
}

int	ft_puthexa(unsigned long n, char base)
{
	char	*base_hxl;
	char	*base_hxu;
	int		count;

	base_hxl = "0123456789abcdef";
	base_hxu = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count = ft_puthexa(n / 16, base);
	if (base == 'l')
	{
		n %= 16;
		count += write (1, &base_hxl[n], 1);
	}
	else
	{
		n %= 16;
		count += write (1, &base_hxu[n], 1);
	}
	return (count);
}

int	ft_putptr(void *p)
{
	unsigned long	n;
	int				count;

	if (!p)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	n = (unsigned long)p;
	count = write (1, "0x", 2);
	count += ft_puthexa(n, 'l');
	return (count);
}

int	ft_putnbr_signed(int n)
{
	long	nb;
	char	c;
	int		count;

	nb = n;
	count = 0;
	if (n < 0)
	{
		count = write (1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		count += ft_putnbr_signed(nb / 10);
	c = (nb % 10) + '0';
	count += write (1, &c, 1);
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n > 9)
		count += ft_putnbr_unsigned(n / 10);
	c = (n % 10) + '0';
	count += write (1, &c, 1);
	return (count);
}
