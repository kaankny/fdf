/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:42:43 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/10/24 16:48:51 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstring(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (ft_putstring("(null)"));
	while (str[len])
	{
		if (ft_putchar(str[len]) < 0)
			return (-1);
		len++;
	}
	return (len);
}
