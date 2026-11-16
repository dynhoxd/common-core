/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:13:02 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/16 21:08:59 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "unistd.h"

int	ft_printf(const char *str, ...);
int	ft_type_call(char ch, va_list args);
int	ft_putchar_ri(char c);
int	ft_putstr_ri(const char *str);
int	ft_putptr(void *p);
int	ft_puthexa(unsigned long n, char base);
int	ft_putnbr_ri(int n);
int	ft_scape_format(char c);

#endif