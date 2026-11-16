/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:11:02 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/16 21:47:16 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_ri(char c)
{
	return (write (1, &c, 1));
}

int	ft_type_call(char ch, va_list args)
{
	if (ch == 'c')
		return (ft_putchar_ri(va_arg(args, int)));
	else if (ch == 's')
		return (ft_putstr_ri(va_arg(args, char *)));
	else if (ch == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (ch == 'd' || ch == 'i')
		return (ft_putnbr_ri(va_arg(args, int)));
	else if (ch == 'u')
		return (ft_putnbr_ri((int)va_arg(args, unsigned int)));
	else if (ch == 'x')
		return (ft_puthexa((unsigned long)va_arg(args, unsigned int), 'l'));
	else if (ch == 'X')
		return (ft_puthexa((unsigned long)va_arg(args, unsigned int), 'u'));
	else if (ch == '%')
		return (ft_putchar_ri('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	if (!str)
		return (-1);
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			count += ft_type_call(*str, args);
		}
		else
			count += ft_putchar_ri(*str);
		str++;
	}
	va_end(args);
	return (count);
}

// #include "stdio.h"
// int	main(void)
// {
// 	int		n = 1;
// 	int		n2 = 1000;
// 	char	ch = 'R';
// 	char	*st1 = "Hello World!";
// 	char	*st2 = "";
// 	void	*ptr = NULL;

// 	ft_printf("\n%d\n", n);
// 	printf("%d\a\n\n", n);

// 	ft_printf("%i\n", n2);
// 	printf("%i\n\n", n2);

// 	ft_printf("%u\n", n);
// 	printf("%u\n\n", n);

// 	ft_printf("%c\n", ch);
// 	printf("%c\n\n", ch);

// 	ft_printf("%s\n", st1);
// 	printf("%s\n\n", st1);

// 	ft_printf("%s\n", st2);
// 	printf("%s\n\n", st2);

// 	ft_printf("%x\n", n2);
// 	printf("%x\n\n", n2);

// 	ft_printf("%X\n", n2);
// 	printf("%X\n\n", n2);

// 	ft_printf("%p \n", &n);
// 	printf("%p \n\n", &n);

// 	ft_printf("%p \n", ptr);
// 	printf("%p \n", ptr);
// }