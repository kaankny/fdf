/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <kkanyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:14:25 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/10/25 11:07:05 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_type(va_list args, const char type)
{
	if (type == '%')
		return (ft_putchar('%'));
	else if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (type == 's')
		return (ft_putstring(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_putpointer(va_arg(args, unsigned long int), 1));
	else if (type == 'd' || type == 'i')
		return (ft_putnumber(va_arg(args, int)));
	else if (type == 'u')
		return (ft_putunsignedint(va_arg(args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_puthex(va_arg(args, unsigned int), type));
	return (-1);
}

static int	ft_check_str(const char *str, int *mi, va_list args)
{
	int	format;
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			format = ft_type(args, str[i]);
			if (format == -1)
				return (-1);
			*mi += format;
		}
		else
		{
			format = ft_putchar(str[i]);
			if (format == -1)
				return (-1);
			*mi += format;
		}
		i++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	if (ft_check_str(str, &i, args) == -1)
		return (-1);
	va_end(args);
	return (i);
}
