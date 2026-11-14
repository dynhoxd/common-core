/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_calling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:01:31 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/14 20:14:24 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
