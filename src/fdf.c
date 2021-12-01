/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 17:54:41 by dkocob        #+#    #+#                 */
/*   Updated: 2021/12/01 22:02:56 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_pixel(int x, int y, int col, t_data *d)
{
	char	*dst;
	
	if (x >= 0 && x < d->img.rx && y < d->img.ry && y >= 0)
	{
		dst = d->img.addr + (y * d->img.line_length + x * (d->img.bits_per_pixel / 8));
		*(unsigned int*)dst = col;
	}
}

int	closehook(int keycode, t_data *d)
{
	(void)d;
	printf("ECKEYCODE:%d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode < 0)
		exit(0);
	return (0);
}

int	mouse_move(int x, int y, t_data *d)
{
	// printf("x:%d, y:%d\n", x, y);
	// d->m.dfpx = d->m.px + x;
	// d->m.dfpy = d->m.py + y;
	if (d->m.pr == 1)
	{
		// printf("MPR==1! x:%d, y:%d, mpr:%d\n", x, y, d->m.pr);
		put_pixel(x, y, 0x00FF0000, d);
		mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
	}
	return (0);
}

int	mouse_press(int press, int x, int y, t_data *d)
{
	d->m.pr = 1;
	d->m.px = x;
	d->m.py = y;
	// printf("MPress:%d, x:%d, y:%d\n", d->m.pr, d->m.px, d->m.py);
	return (0);
}

int	mouse_release(int press, int x, int y, t_data *d)
{
	printf("MPress:%d, x:%d, y:%d\n", d->m.pr, d->m.px, d->m.py);
	printf("MRelease:%d, x:%d, y:%d\n", press, x, y);

	if (d->m.pr == 1)
	{
		// printf("MPR==1! x:%d, y:%d, mpr:%d\n", x, y, d->m.pr);
	// 	d->v.x1 = d->m.px;
	// 	d->v.y1 = d->m.py;
	// 	d->v.x2 = x;
	// 	d->v.y2 = y;
	// 	d->v.ang = 33;
	// 	d->v.len = abs(d->m.py - y);
	// 	d->v.col = 0x035F3000;
	// 	put_object(d);
		put_line(d->m.px, d->m.py, x, y, 0x00FF0000, d);


		// draw(d);
	}
	d->m.pr = 0;
	// draw(d);
	return (0);
}

int	hooks(t_data *d)
{

	mlx_hook(d->win, 2, 1<<0, closehook, d); //key press
	mlx_hook(d->win, 17, 1<<0, closehook, d); //close button
	mlx_hook(d->win, 4, 0, mouse_press, d);
	mlx_hook(d->win, 5, 0, mouse_release, d);
	mlx_hook(d->win, 6, 0, mouse_move, d);
	return (0);
}

int	order_int(int *x1, int *y1, int *x2, int *y2)
{
	int	tmp;

	if (*x1 > *x2)
	{
		tmp = *x2;
		*x2 = *x1;
		*x1 = tmp;
		tmp = *y2;
		*y2 = *y1;
		*y1 = tmp;
	}
	return (0);
}

void	bresenham_ (int x1, int y1, int x2, int y2, int col, t_data *d)
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

int	put_line(int x1, int y1, int x2, int y2, int col, t_data *d)
{
	order_int(&x1, &y1, &x2, &y2);
	bresenham_(x1, y1, x2, y2, col, d);
	return (0);
}

int	draw_cube(t_data *d)
{	
	put_line(100, 100, 500, 100, 0x00FF0000, d);
	put_line(100, 500, 500, 500, 0x00FF0000, d);
	put_line(500, 100, 500, 500, 0x00FF0000, d);
	put_line(100, 100, 100, 500, 0x00FF0000, d);
	put_line(100, 100, 500, 500, 0x00FF0000, d);
	put_line(500, 100, 100, 500, 0x00FF0000, d);
	put_line(200, 100, 100, 200, 0x00FF0000, d);
	put_line(100, 100, 400, 200, 0x00FF0000, d);
	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
	return (0);
}


int	put_vector_br(int x1, int y1, double ang, double len, int col, t_data *d)
{
	int x2;
	int y2;

	x2 = x1 + round(len * cos(ang));
	y2 = y1 + round(len * sin(ang));
	
	put_line(x1, y1, x2, y2, col, d);
	return (0);
}

int	put_object(t_data *d)
{
	int i1 = 0;
	int i2 = 0;
	d->map.un = d->img.rx / (d->map.size_x + 4);
	
	// while (i < 10)
	// {
	// 	put_line()
	// 	i++;
	// }

	put_vector_br(d->v.x1, d->v.x1, d->v.ang, d->v.len,  d->v.col, d);
	// while (i1 < d->map.size_y)
	// {
	// 	while (i2 < d->map.size_x)
	// 		{
	// 			put_vector(200, 200, 75, 300, 0x035F3000, d);
	// 			i2++;
	// 		}
	// 		printf("\n");
	// 		i2 = 0;
	// 		i1++;
	// }
	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
	return (0);
}

int	window(t_data *d)
{

	d->img.rx = X_REZ;
	d->img.ry = Y_REZ;
	d->p.col = 0x00FF0000;
	d->p.x = 0;
	d->p.y = 0;
	d->mlx = mlx_init();
	d->img.img = mlx_new_image(d->mlx, d->img.rx, d->img.ry);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bits_per_pixel, &d->img.line_length, &d->img.endian);
	d->win = mlx_new_window(d->mlx, d->img.rx, d->img.ry, "fdf");
	// draw_cube(d);
	hooks(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
	mlx_loop(d->mlx);
	return (0);
}
