/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <kkanyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:51:27 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/10/24 17:27:22 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int number, char type)
{
	int	rtn;
	int	tmp;

	rtn = 0;
	if (number >= 16)
	{
		tmp = ft_puthex(number / 16, type);
		if (tmp < 0)
			return (-1);
		rtn += tmp;
	}
	if (type == 'X')
		tmp = ft_putchar("0123456789ABCDEF"[number % 16]);
	if (type == 'x')
		tmp = ft_putchar("0123456789abcdef"[number % 16]);
	if (tmp < 0)
		return (-1);
	return (rtn + 1);
}
