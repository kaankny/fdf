/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:51:00 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/10/14 15:57:45 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s1);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	if (!str)
		return (0);
	while (i < j)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
