/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:19:17 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/12/20 10:34:35 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "../minilibx/mlx.h"
#include <math.h>

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	int	i;

	if (x < WIDTH && y >= 0 && y < HEIGHT && x >= 0)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->line_length);
		fdf->addr[i] = color;
		fdf->addr[++i] = color >> 8;
		fdf->addr[++i] = color >> 16;
	}
}

void	set_p(t_vector3 *start, t_vector3 *end, t_fdf *data)
{
	start->x *= data->zoom;
	start->y *= data->zoom;
	start->z *= data->zoom;
	end->x *= data->zoom;
	end->y *= data->zoom;
	end->z *= data->zoom;
	if (data->is_iso)
	{
		isometric(start, 45);
		isometric(end, 45);
	}
	start->x += data->x_space;
	start->y += data->y_space;
	end->x += data->x_space;
	end->y += data->y_space;
}

int	all_px(t_vector3 start, t_vector3 end)
{
	int	delta_x;
	int	delta_y;

	delta_x = end.x - start.x;
	delta_y = end.y - start.y;
	return ((delta_x * delta_x) + (delta_y * delta_y));
}

void	draw_line(t_vector3 s, t_vector3 e, t_fdf *data)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	set_p(&s, &e, data);
	delta_x = e.x - s.x;
	delta_y = e.y - s.y;
	pixels = sqrt(((e.x - s.x) * (e.x - s.x))
			+ ((e.y - s.y) * (e.y - s.y)));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = s.x;
	pixel_y = s.y;
	while (pixels)
	{
		my_mlx_pixel_put(data, pixel_x, pixel_y, get_pixel_color(s.color,
				e.color, sqrt(((e.x - s.x) * (e.x - s.x)) + ((e.y - s.y)
						* (e.y - s.y))), sqrt(((e.x - s.x) * (e.x - s.x))
					+ ((e.y - s.y) * (e.y - s.y))) - pixels));
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

void	draw(t_fdf *data)
{
	int	i;

	i = 0;
	data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	while (i < data->height * data->width)
	{
		if (data->points[i].x != data->width - 1)
			draw_line(data->points[i], data->points[i + 1], data);
		if (data->points[i].y != data->height - 1)
			draw_line(data->points[i], data->points[i + data->width], data);
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
