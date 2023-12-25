/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:41:15 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/12/17 16:30:03 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <math.h>

void	isometric(t_vector3 *dot, double angle)
{
	dot->x = (dot->x - dot->y) * cos(angle);
	dot->y = (dot->x + dot->y) * sin(angle) - dot->z;
}
