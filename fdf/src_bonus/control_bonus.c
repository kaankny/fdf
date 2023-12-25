/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:30:42 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/12/20 10:36:44 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ft_printf/ft_printf.h"

int	ft_check_comma(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (1);
		i++;
	}
	return (0);
}

int	print_error(char *error_msg)
{
	ft_printf(error_msg);
	exit(1);
}

void	control_map(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 0);
	if (fd <= 0)
		print_error("[\x1b[35mFDF\x1b[0m] \x1b[31mWrong File Name!\x1b[0m\n");
	close(fd);
}
