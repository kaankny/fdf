/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:42:47 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/10/15 12:20:49 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_number_size(int number)
{
	size_t	len;

	len = 0;
	if (number == 0)
	{
		return (1);
	}
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	num;
	int			i;

	num = n;
	len = ft_number_size(n);
	if (n < 0)
	{
		num *= -1;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	i = len;
	while (--i >= 0)
	{
		str[i] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
