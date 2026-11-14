/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 19:06:47 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/04 15:35:19 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	c_usgn;
	unsigned char	*ptr;

	c_usgn = c;
	ptr = (unsigned char *)s;
	while (n-- > 0)
		*ptr++ = c_usgn;
	return (s);
}
