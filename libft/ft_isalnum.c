/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabernar <jabernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:10:14 by jabernar          #+#    #+#             */
/*   Updated: 2026/11/04 15:27:56 by jabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int n)
{
	unsigned char	c;

	c = n;
	if (ft_isalpha(n) == 1 || ft_isdigit(n) == 1)
		return (1);
	return (0);
}
