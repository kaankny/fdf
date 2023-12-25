/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:16:57 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/12/17 14:19:58 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

static int	interpolate_color(int start_color, int end_color, float t)
{
	int	result;

	result = (int)(start_color + t * (end_color - start_color));
	return (result);
}

int	get_pixel_color(int sc, int ec, int tp, int cp)
{
	float	t;
	int		result;

	t = (float)cp / (float)tp;
	result = \
		((int)interpolate_color((sc >> 16) & 0xFF, (ec >> 16) & 0xFF, t) << 16)
		| ((int)interpolate_color((sc >> 8) & 0xFF, (ec >> 8) & 0xFF, t) << 8)
		| (int)interpolate_color(sc & 0xFF, ec & 0xFF, t);
	return (result);
}
