/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:13:02 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/14 20:24:26 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "unistd.h"

int	ft_printf(const char *str, ...);
int	ft_putstr_retint(const char *str);
int	ft_putchar_retint(char c);
int	ft_pbase(unsigned long n, char *base);
int	ft_type_calling(char ch, va_list args);

#endif