/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <kkanyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:00:09 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/10/24 17:24:11 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count(long int num)
{
	long int	n;
	int			i;

	i = 0;
	n = num;
	while (n)
	{
		n /= 10;
		i++;
	}
	i += (num == 0 || num < 0);
	return (i);
}

char	*ft_itoa(long int number)
{
	int		len;
	char	*str;

	len = ft_count(number);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	str[len--] = '\0';
	while (number > 9)
	{
		str[len--] = (number % 10) + 48;
		number /= 10;
	}
	str[len] = (number % 10) + 48;
	return (str);
}
