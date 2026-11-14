/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:11:02 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/14 20:25:58 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdarg.h"
#include "unistd.h"
// #include "ft_printf.h"

int	ft_pbase(unsigned long n, char *base)
{
	int		count;
	size_t	base_len;
	
	base_len = ft_strlen(base);
	if (n > base_len)
		count = ft_pbase(n / base_len, base);
	return (count += write (1, &base[n], 1));
}

int	ft_putchar_retint(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr_retint(const char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_type_calling(char ch, va_list args)
{
	char 	*dc;
	char	*hxl;
	char	*hxu;
	
	dc = "0123456789";
	hxl = "0123456789abcdef";
	hxu = "0123456789ABCDEF";
	if (ch == 'c')
		return (ft_putchar_retint(va_arg(args, char)));
	else if (ch == 's')
		return (ft_putstr_retint(va_arg(args, char *)));
	else if (ch == 'p')
		return (ft_putstr_retint("0x") + ft_pbase(va_arg(args, void *), hxl));
	else if (ch == 'd')
		return (ft_pbase(va_arg(args, int), dc));
	else if (ch == 'i')
		return (ft_pbase(va_arg(args, int), dc));
	else if (ch == 'u')
		return (ft_pbase(va_arg(args, unsigned int), dc));
	else if (ch == 'x')
		return (ft_pbase(va_arg(args, long), hxl));
	else if (ch == 'X')
		return (ft_pbase(va_arg(args, long), hxu));
	else if(ch == '%')
		return (ft_putchar_retint('%'));
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		count;
	
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str++ == '%')
		{
			count += ft_type_calling(*str, args);
			str++;
		}
		else
			count += ft_putchar_retint(*str++);
	}
	return (count);
}
