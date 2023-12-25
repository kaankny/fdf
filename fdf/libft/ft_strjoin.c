/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:23:18 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/10/15 12:30:19 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		mainindex;
	int		index;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	mainindex = 0;
	index = 0;
	while (s1[index] != '\0')
		str[mainindex++] = s1[index++];
	index = 0;
	while (s2[index] != '\0')
		str[mainindex++] = s2[index++];
	str[mainindex] = '\0';
	return (str);
}
