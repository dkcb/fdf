/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 19:08:11 by dkocob        #+#    #+#                 */
/*   Updated: 2021/11/27 19:03:25 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <fcntl.h>
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#define X_REZ 1920
#define Y_REZ 1080

typedef struct	s_node {

}				t_node;

typedef struct	s_line{
	char			*line;
	struct s_line	*next;
}					t_line;

typedef struct	s_map {
	int				size_x;
	int				size_y;
	t_line			*lhead;
	t_line			*current;
}				t_map;

typedef struct	s_img {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				rx;
	int				ry;
}				t_img;

typedef struct	s_p {
	int				x;
	int				y;
	int				col;
}				t_p;

typedef struct	s_obj {
	int				x;
	int				y;
	int				col;
}				t_obj;

typedef struct	s_mouse {
	int				pr;
	int				px;
	int				py;
	int				dfpx;
	int				dfpy;
	int				mrl;
}				t_mouse;

typedef struct	s_data {
	void			*mlx;
	void			*win;
	t_p				p;
	t_img			img;
	t_mouse			m;
	t_map			map;
}				t_data;

// void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int			window(t_data *d);
int			mouse_release(int press, int x, int y, t_data *d);
int			mouse_press(int press, int x, int y, t_data *d);
int			draw(t_data *d);
int			bresenham_RB(int sx, int sy, int ex, int ey, int col, t_data *d);
int			put_line(int sx, int sy, int ex, int ey, int col, t_data *d);
int			order_int(int *x1, int *y1, int *x2, int *y2);
int			get_next_line(int fd, char **line);
int			map_init(int fd, t_data *d);
int			build_frame (t_data *d);





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

	// void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }


// void	setup_controls(t_data *d)
// {
// 	mlx_hook(d->win, 2, 0, key_press, &d);
// 	mlx_hook(d->win, 17, 0, close, &d);
// 	mlx_hook(d->win, 4, 0, mouse_press, &d);
// 	mlx_hook(d->win, 5, 0, mouse_release, &d);
// 	mlx_hook(d->win, 6, 0, mouse_move, &d);
// }

// int	set_pixel(t_data *d, int x, int y, int c)
// {
// 	d->p.x = x;
// 	d->p.y = y;
// 	d->p.col = c;
// 	return (0);
// }
	// int	math(int x)
	// {
	// 	int	y;

	// 	y = x;
	// 	return (y);
	// }
// 	int	put_line(int sx, int sy, int ex, int ey, int col, t_data *d)
// {
// 	int cx = 0;
// 	int cy = 0;

// 	while(ex != sx && ey != sy)
// 	{
// 		put_pixel(cx, cy, d->p.col, d);
// 	}
// 	return (0);
// }

// int	put_line(int sx, int sy, int ex, int ey, int col, t_data *d)
// {
	
// 	int x;
// 	int y;
// 	int dx;
// 	int dy;
// 	int p;

// 	// order_int(&sx, &ex);
// 	// order_int(&sy, &ey);
// 	x = sx;
// 	y = sy;
// 	dx = ex - sx;
// 	dy = ey - sy;
// 	p = 2 * dy - dx;
	
// 	while(dx == 0 && y <= ey)
// 	{
// 		put_pixel(x, y, col, d);
// 		y++;
// 	}
// 	while(dx != 0 && x <= ex)
// 	{
// 		if(p >= 0)
// 		{
// 			put_pixel(x, y, col, d);
// 			y = y + 1;
// 			p = p + 2 * dy - 2 * dx;
// 		}
// 		else
// 		{
// 			put_pixel(x, y, col, d);
// 			p = p + 2 * dy;
// 		}
// 		x++;
// 	}
// 	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
	
// 	// while(ex != sx && ey != sy)
// 	// {
// 	// 	put_pixel(cx, cy, d->p.col, d);
// 	// }
// 	return (0);
// }


// int	put_line(int x1, int y1, int x2, int y2, int col, t_data *d)
// {
	
// 	double x;
// 	double y;
// 	double dx;
// 	double dy;
// 	// int p;
// 	double	slope;

// 	order_int(&x1, &x2);
// 	order_int(&x1, &y2);
// 	x = (double)x1;
// 	y = (double)x1;
// 	dx = x2 - x1;
// 	dy = y2 - x1;
// 	slope = dy / dx;
	
// 	printf("Line x1:%d, x2:%d, y1:%d, y2:%d, dy:%f, dx:%f, slope:%f\n", x, x2, y, y2, dx, dy, slope);
// 	while(dx == 0 && y <= y2)
// 	{
// 		put_pixel(x, y, col, d);
// 		y++;
// 	}
// 	while (slope > 1 && y <= y2)
// 	{
// 		x = y + slope;
// 		put_pixel((int)x, (int)y, col, d);
// 		y++;
// 	}
// 	if (slope < 1 && x <= x2)
// 	{
// 		y = x + slope;
// 		put_pixel((int)x, (int)y, col, d);
// 		x++;
// 	}
// 	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
	
// 	// while(x2 != x1 && y2 != x1)
// 	// {
// 	// 	put_pixel(cx, cy, d->p.col, d);
// 	// }
// 	return (0);
// }

	// int dx;
	// int dy;
	// int err;
	// int	e2;
	// int sx;
	// int sy;

	// dx =  abs (x1 - x0);
	// sx = x0 < x1 ? 1 : -1;
	// // sx = 1;
	// dy = -abs (y1 - y0);
	// sy = y0 < y1 ? 1 : -1; 
	// err = dx + dy;

// 	void	bresenham_ (int x0, int y0, int x1, int y1, int col, t_data *d)
// {
// 	int dx;
// 	int dy;
// 	int err;
// 	int	e2;
// 	int	sx;
// 	int	sy;

// 	// order_int(&x0, &y0, &x1, &y1);
// 	dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
// 	dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
// 	err = dx + dy;
// 	while (x0 <= x1)
// 	{ 
// 		put_pixel(x0, y0, col, d);
// 		if (x0 == x1 && y0 == y1)
// 			break;
// 		e2 = 2 * err;
// 		if (e2 >= dy) 
// 			err += dy; x0 += sx; 
// 		if (e2 <= dx) 
// 		{ 
// 			err += dx; 
// 			y0 += sy; 
// 		}
// 	}
// 	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
// }
// void	bresenham_ (int x0, int y0, int x1, int y1, int col, t_data *d)
// {
// 	int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
// 	int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
// 	int err = dx + dy, e2; /* error value e_xy */

// 	while (x0 <= x1)
// 	{ 
// 		put_pixel(x0, y0, col, d);
// 		if (x0 == x1 && y0 == y1) break;
// 		e2 = 2 * err;
// 		if (e2 >= dy) 
// 		{ err += dy; x0 += sx; } /* e_xy+e_x > 0 */
// 		if (e2 <= dx) 
// 		{ err += dx; y0 += sy; } /* e_xy+e_y < 0 */
// 	}
// 	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);

// }