/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 19:08:11 by dkocob        #+#    #+#                 */
/*   Updated: 2021/11/23 18:51:42 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <fcntl.h>
#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>



typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		rx;
	int		ry;
}				t_img;

typedef struct	s_p {
	int		x;
	int		y;
	int		col;
}				t_p;

typedef struct	s_mouse {
	int		pr;
	int		px;
	int		py;
	int		mrl;
}				t_mouse;

typedef struct	s_vars {
	void	*mlx;
	void	*image;
	void	*win;
	t_mouse	m;
}				t_vars;

typedef struct	s_data {
	t_p		p;
	t_img	img;
	t_vars	vars;
}				t_data;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		key_hook(int keycode, t_vars *vars);
int		close(int keycode, t_vars *vars);
int		window(void);

# endif

// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// while (x++ < 600 && y++)
	// {
	// 	my_mlx_pixel_put(&img, x, x, 0x00FF0000);
	// 	if (x * x < data.ry && y < data.ry)
	// 		my_mlx_pixel_put(&img, x * x, y, 0x00FF0000 + x);
	// 	my_mlx_pixel_put(&img, 1020 - x, data.ry - x, 0x00FF0000);
	// 	my_mlx_pixel_put(&img,  x + x, x, 0x00FF0000 - x);
	// }
	// while (x++ < data.rx)
	// {
	// 	y = (x * x) / 1000;
	// 	if (x < data.rx && y < data.ry)
	// 		my_mlx_pixel_put(&img, 3260 - x, data.ry - y, 0x00FF0000 / x);
	// 	if (x < data.rx && y < data.ry)
	// 		my_mlx_pixel_put(&img, data.rx / 2, y, 0x00FF0331);
	// 	if (x < data.rx && y < data.ry)
	// 		my_mlx_pixel_put(&img, data.rx - x, data.ry - y, 0x00FF0000 / x);
	// }