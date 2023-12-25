/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:29:41 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/10/17 11:54:09 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	c_words(char const *s, char c)
{
	int	fl;
	int	i;
	int	w_count;

	i = 0;
	w_count = 0;
	fl = 1;
	while (s[i])
	{
		if (s[i] == c)
			fl = 1;
		else if (fl == 1 && s[i] != c)
		{
			w_count++;
			fl = 0;
		}
		i++;
	}
	return (w_count);
}

static char	**free_all(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_index;

	if (!s)
		return (NULL);
	word_index = 0;
	result = (char **) malloc(sizeof(char *) * (c_words(s, c) + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			result[word_index] = malloc((word_len(s, c) + 1) * sizeof(char));
			if (!result[word_index])
				return (free_all(result));
			ft_strlcpy(result[word_index++], s, word_len(s, c) + 1);
			s += word_len(s, c);
		}
	}
	result[word_index] = NULL;
	return (result);
}
