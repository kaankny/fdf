/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:39:13 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/12/20 11:51:03 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <stdlib.h>
#include "../ft_printf/ft_printf.h"
#include "../minilibx/mlx.h"

int	close_program(t_fdf *data)
{
	ft_printf("[\x1b[35mFDF\x1b[0m] \x1b[33mExiting program\x1b[0m.. BYE!\n");
	if (data->img)
		mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->points);
	exit(0);
}

int	key_hook(int keycode, t_fdf *data)
{
	if (keycode == 27)
		data->zoom++;
	else if (keycode == 24 && data->zoom > 1)
		data->zoom--;
	else if (keycode == 123)
		data->x_space -= 10;
	else if (keycode == 124)
		data->x_space += 10;
	else if (keycode == 126)
		data->y_space -= 10;
	else if (keycode == 125)
		data->y_space += 10;
	else if (keycode == 34)
		data->is_iso = 1;
	else if (keycode == 35)
		data->is_iso = 0;
	else if (keycode == 53)
		close_program(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img);
	draw(data);
	draw_menu(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	data;

	if (ac == 2)
	{
		control_map(av[1]);
		data.is_iso = 1;
		data.mlx_ptr = mlx_init();
		data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "fdf");
		ft_printf("[\x1b[35mFDF\x1b[0m] \x1b[33mReading file\x1b[0m..\n");
		read_file(av[1], &data);
		ft_printf("[\x1b[35mFDF\x1b[0m] \x1b[32mRead completed\x1b[0m!\n");
		data.zoom = HEIGHT / data.height / 2;
		data.x_space = WIDTH / 2 - data.height / 2 * data.zoom;
		data.y_space = HEIGHT / 2 - data.height / 2 * data.zoom;
		ft_printf("[\x1b[35mFDF\x1b[0m] \x1b[32mDrawing\x1b[0m..\n");
		draw(&data);
		draw_menu(&data);
		mlx_key_hook(data.win_ptr, key_hook, &data);
		mlx_hook(data.win_ptr, 17, 0, close_program, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		print_error("Incorrect Argument Number!");
	return (0);
}
