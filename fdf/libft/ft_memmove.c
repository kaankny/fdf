/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:44:35 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/10/18 11:57:01 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (0);
	if (src > dst)
		return (ft_memcpy(dst, src, len));
	while (len--)
		((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	return (dst);
}
