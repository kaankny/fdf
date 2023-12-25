/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:10:56 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/12/20 11:59:51 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>

int	get_height(char	*file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char	*file_name)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	if (!line)
		print_error(
			"[\x1b[35mFDF\x1b[0m] \x1b[31mEmpty File\x1b[0m\n");
	width = ft_count_words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	set_points(t_vector3 *points, int x, int y, char *str)
{
	char	**s;

	points->x = x;
	points->y = y;
	points->z = ft_atoi(str);
	if (ft_check_comma(str))
	{
		s = ft_split(str, ',');
		points->color = ft_atoi_base(s[1], 16);
		free(s[1]);
		free(s[0]);
		free(s);
	}
	else
		points->color = 0xffffff;
}

void	line_init(t_fdf *data, char *line, int y)
{
	static int	k = 0;
	int			i;
	char		**ptr;

	i = 0;
	ptr = ft_split(line, ' ');
	while (ptr[i])
	{
		set_points(&data->points[k], i, y, ptr[i]);
		free(ptr[i]);
		i++;
		k++;
	}
	free(ptr);
}

void	read_file(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		y;

	y = 0;
	data->width = get_width(file_name);
	data->height = get_height(file_name);
	data->points = (t_vector3 *)malloc(sizeof(t_vector3)
			* (data->width * data->height));
	if (!data->points)
		print_error(
			"[\x1b[35mFDF\x1b[0m] \x1b[31mMemmory Alocation Error!\x1b[0m\n");
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	while (line)
	{
		line_init(data, line, y);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
}
