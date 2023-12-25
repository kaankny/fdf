/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:42:47 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/10/25 11:24:51 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(unsigned long int ptr, int i)
{
	int	len;

	len = 0;
	if (i == 1)
	{
		if (ft_putstring("0x") < 0)
			return (-1);
		len += 2;
	}
	if (ptr >= 16)
		len += ft_putpointer(ptr / 16, 0);
	if (ft_putchar("0123456789abcdef"[ptr % 16]) < 0)
		return (-1);
	return (len + 1);
}
