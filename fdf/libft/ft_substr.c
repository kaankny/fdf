/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:47:03 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/10/15 14:17:47 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	index;
	unsigned int	mainindex;

	index = 0;
	mainindex = 0;
	if (start >= ft_strlen(s) || len == 0 || ft_strlen(s) == 0)
		return (ft_strdup(""));
	while (index < len && s[index + start] != '\0')
		index++;
	str = (char *)malloc(sizeof(char) * (index + 1));
	if (!str)
		return (0);
	index = 0;
	while (s[mainindex] != '\0')
	{
		if (mainindex >= start && index < len)
			str[index++] = s[start++];
		mainindex++;
	}
	str[index] = '\0';
	return (str);
}
