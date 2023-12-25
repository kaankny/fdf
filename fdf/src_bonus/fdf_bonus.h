/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:05:24 by kkanyilm          #+#    #+#             */
/*   Updated: 2023/12/17 17:02:37 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_vector3
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_vector3;

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			is_iso;
	int			x_space;
	int			y_space;
	int			width;
	int			height;
	int			zoom;
	int			color;
	t_vector3	*points;
}				t_fdf;

void	read_file(char *file_name, t_fdf *data);
void	draw_line(t_vector3 start, t_vector3 end, t_fdf *data);
void	draw(t_fdf *data);
int		print_error(char *error_msg);
int		ft_atoi_base(const char *str, int str_base);
void	control_map(char *file_name);
void	isometric(t_vector3 *dot, double angle);
void	draw_menu(t_fdf *data);
int		get_pixel_color(int sc, int ec, int tp, int cp);
int		ft_check_comma(char *str);
int		ft_count_words(char const *s, char c);

#endif