/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   graphics.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 17:55:01 by dkocob        #+#    #+#                 */
/*   Updated: 2021/12/16 21:41:28 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_pixel(int x, int y, int col, struct s_data *d)
{
	char	*dst;
	
	if (x >= 0 && x < d->img.rx && y < d->img.ry && y >= 0)
	{
		dst = d->img.addr + (y * d->img.line_length + x * (d->img.bits_per_pixel / 8));
		*(unsigned int*)dst = col;
	}
}

void	bresenham_ (int x1, int y1, int x2, int y2, int col, struct s_data *d)
{
	int dx;
	int dy;
	int	sx;
	int	sy;
	int err;
	int	e2;

	dx =  x2 - x1;
	sx = 1;
	dy = -1 * (y1 - y2);
	sy = -1;
	if (y2 > y1)
	{
		dy = -1 * (y2 - y1);
		sy = 1;
	}
	err = dx + dy;
	while (x1 <= x2)
	{ 
		put_pixel(x1, y1, col, d);
		if (x1 == x2 && y1 == y2) break;
		e2 = 2 * err;
		if (e2 >= dy)
		{ err += dy; x1 += sx; } /* e_xy+e_x > 0 */
		if (e2 <= dx)
		{ err += dx; y1 += sy; } /* e_xy+e_y < 0 */
	}
}


int	put_line(int x1, int y1, int x2, int y2, int col, struct s_data *d)
{
	order_int(&x1, &y1, &x2, &y2);
	bresenham_(x1, y1, x2, y2, col, d);
	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
	return (0);
}

void	map_draw(struct s_data *d)
{
	int	i = 0;
	
	while (i < d->map.size_x * d->map.size_y)
	{
		if (i % (d->map.size_x) != d->map.size_x - 1)
			put_line(d->vs[i].x, d->vs[i].y, d->vs[i + 1].x, d->vs[i + 1].y, 0x00FF0000, d); // x
		if (i > d->map.size_x - 1)
			put_line(d->vs[i].x, d->vs[i].y, d->vs[i - d->map.size_x].x, d->vs[i - d->map.size_x].y, 0x00F08000, d); // y
		i++;
	}
}
