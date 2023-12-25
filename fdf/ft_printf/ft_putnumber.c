/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:52:21 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/10/24 17:07:09 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_putnumber(long int nbr)
{
	char	*str;
	int		rtn;

	str = ft_itoa(nbr);
	if (!str)
		return (-1);
	rtn = ft_putstring(str);
	free(str);
	return (rtn);
}
