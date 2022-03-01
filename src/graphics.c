/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   graphics.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 17:55:01 by dkocob        #+#    #+#                 */
/*   Updated: 2022/03/01 17:36:48 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	img_clear(unsigned int col, struct s_data *d)
{
	int	i1 = -1;
	int	i2 = -1;

	while(i1++ <= d->img.ry)
	{
		while (i2++ <= d->img.rx)
			put_pixel(i2, i1, col, d);
		i2 = -1;
	}
	
}

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
		if (x1 == x2 && y1 == y2)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x1 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}



int	center(struct s_data *d)
{
	get_size(d);
	while (d->map.start.x > (d->img.rx - (d->map.maxx - d->map.minx)) / 4)
		d->map.start.x--;
	while (d->map.start.x < (d->img.rx - (d->map.maxx - d->map.minx)) / 4)
		d->map.start.x++;
	// while (d->img.rx - (d->map.maxx - d->map.minx) != d->img.rx / 2)
	// {
	// 	if (d->img.rx - (d->map.maxx - d->map.minx))
	// 	d->map.start.x--;
	// while (d->img.rx - (d->map.maxx - d->map.minx) >= d->img.rx / 2)
	// 	d->map.start.x++;
	// }
	// float size = get_size(d);

	// while (d->map.size_x * d->map.un != d->img.rx)
	
	// || d->map.size_y * d->map.un < d->img.ry)
	return (0);
}

void	adjust_scale(struct s_data *d)
{
	// while (d->map.)
	// while (d->map.size_x * d->map.un < d->img.rx || d->map.size_y * d->map.un < d->img.ry)
}

int	put_line(int x1, int y1, int x2, int y2, int col, struct s_data *d)
{
	order_int(&x1, &y1, &x2, &y2);
	bresenham_(x1, y1, x2, y2, col, d);
	return (0);
}

void	map_draw(struct s_data *d)
{
	int	i = 0;
	
	img_clear(0x00000000, d);
	while (i < d->map.size_x * d->map.size_y)
	{
		if (i % (d->map.size_x) != d->map.size_x - 1)
			put_line(d->vs[i].x, d->vs[i].y, d->vs[i + 1].x, d->vs[i + 1].y, 0x00FF0000, d); // x
		if (i > d->map.size_x - 1)
			put_line(d->vs[i].x, d->vs[i].y, d->vs[i - d->map.size_x].x, d->vs[i - d->map.size_x].y, 0x00F08000, d); // y
		i++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
}

void	render(struct s_data *d)
{
	map_rotate(d);
	map_apply_z(d);
	map_draw(d);
}