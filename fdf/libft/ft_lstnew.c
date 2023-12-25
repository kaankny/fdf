/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:29:54 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/10/16 18:36:00 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*cntn;

	cntn = (t_list *)malloc(sizeof(t_list));
	if (!cntn)
		return (NULL);
	cntn->content = content;
	cntn->next = NULL;
	return (cntn);
}
