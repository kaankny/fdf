/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:40:02 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/12/17 16:30:05 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "../minilibx/mlx.h"

void	draw_menu(t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 10, 0xFFFFFF,
		"<KKANYILM>");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 50, 0xFFFFFF,
		"Zoom: */-");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 70, 0xFFFFFF,
		"Move: Arrorws");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 90, 0xFFFFFF,
		"ISO: I Key");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 110, 0xFFFFFF,
		"Parallel: P key");
}
