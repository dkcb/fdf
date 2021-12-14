/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.CONST                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 17:54:41 by dkocob        #+#    #+#                 */
/*   Updated: 2021/12/09 18:18:14 by dkocob        ########   odam.nl         */
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

int	closehook(int keycode, struct s_data *d)
{
	(void)d;
	printf("ECKEYCODE:%d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode < 0)
		exit(0);
	return (0);
}

int	mouse_move(int x, int y, struct s_data *d)
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

int	mouse_press(int press, int x, int y, struct s_data *d)
{
	d->m.pr = 1;
	d->m.px = x;
	d->m.py = y;
	// printf("MPress:%d, x:%d, y:%d\n", d->m.pr, d->m.px, d->m.py);
	return (0);
}

int	mouse_release(int press, int x, int y, struct s_data *d)
{
	// printf("MPress:%d, x:%d, y:%d\n", d->m.pr, d->m.px, d->m.py);
	// printf("MRelease:%d, x:%d, y:%d\n", press, x, y);

	if (d->m.pr == 1)
	{
		put_line(d->m.px, d->m.py, x, y, 0x00FF0000, d);
	}
	d->m.pr = 0;
	return (0);
}

int	hooks(struct s_data *d)
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

void v_end_calc(struct s_v *v, int ang, int len)
{
	v->end.x = round(v->start.x + len * cos(ang * CONST));
	v->end.y = round(v->start.y + len * sin(ang * CONST));
}

// void v_end_calcZX(struct s_v *v, int ang, int len)
// {
// 	double CONST = 0.0174533;

// 	v->end.x = round(v->start.x + len * cos(ang * CONST));
// 	v->end.y = round(v->start.y + len * sin(ang * CONST));
// 	v->end.x = round(v->end.x - len * cos(35.264 * CONST));
// 	v->end.y = round(v->end.y + len * sin(35.264 * CONST));
// }

// void v_end_calcZY(struct s_v *v, int ang, int len)
// {
// 	double CONST = 0.0174533;

// 	v->end.x = round(v->start.x + len * cos(ang * CONST));
// 	v->end.y = round(v->start.y + len * sin(ang * CONST));
// 	v->end.x = round(v->end.x + len * cos(35.264 * CONST));
// 	v->end.y = round(v->end.y + len * sin(35.264 * CONST));
// }

int	draw_vect_ang(struct s_v v, struct s_data *d)
{
	put_line(v.start.x, v.start.y, v.end.x, v.end.y, v.col, d);
	return (0);
}


int	draw_quadrat(struct s_v v, struct s_data *d)
{	
	// struct s_v	v;
	int	i = 0;
	
	// v.ang = 45;
	// v.col = 0x00FF0000;	
	// v.start.x = 100;
	// v.start.y = 10;
	// v.len = 50;
	// v.ang = 0;
	while (i++ < 4)
	{
		v_end_calc(&v, v.ang, v.len);
		draw_vect_ang(v, d);
		v.start.x = v.end.x;
		v.start.y = v.end.y;
		v.ang += 90;
		// d->v.col += 27500;
	}
	return (0);
}

int	draw_cube(struct s_cube cube, struct s_data *d)
{	
	struct s_v	v;
	int	i = 0;
	double iso =  35.264;
	iso =  35.264;
	
	v.ang = 175;
	v.col = 0x00FF0000;	
	v.end.x = 100;
	v.end.y = 100;
	v.len = 50;
	// v.ang = 0;
	while (i++ < 4)
	{
		v.start.x = v.end.x;
		v.start.y = v.end.y;
		v.ang += 90;
		v_end_calc(&v, v.ang, v.len);
		draw_vect_ang(v, d);
		// d->v.col += 27500;
	}
	i = 0;
	v.start.x = v.end.x;
	v.start.y = v.end.y;
	v.end.x = round(v.start.x + v.len/2 * cos(iso * CONST));
	v.end.y = round(v.start.y + v.len/2 * sin(iso * CONST));
	draw_vect_ang(v, d);

	while (i++ < 4)
	{
		v.start.x = v.end.x;
		v.start.y = v.end.y;
		v.ang += 90;
		v_end_calc(&v, v.ang, v.len);
		draw_vect_ang(v, d);
		// d->v.col += 27500;
	}
	// v.start.x = v.end.x;
	// v.start.y = v.end.y;
	// v.end.x = round(v.start.x + v.len/2 * cos(iso * CONST));
	// v.end.y = round(v.start.y - v.len/2 * sin(iso * CONST));
	// draw_vect_ang(v, d);
	return (0);
}

void	map_rotate(struct s_data *d)
{
	int	i = 0;
	int	ang = 45;
	int	len = d->map.un;


	d->vs[0].x = d->map.start.x;
	d->vs[0].y = d->map.start.y;
	// d->vs[i + 1].x = round(d->vs[i].x + len * 1 * cos(ang * CONST));
	// d->vs[i + 1].y = round(d->vs[i].y + len * 1 * sin(ang * CONST));
	printf ("y0:%d\n", d->vs[i].y);
	while (i < d->map.size_x * d->map.size_y)
	{
		if (i > 0 && i % (d->map.size_x) == 0)
		{
		// 	printf ("y1:%d\n", d->vs[i].y);
			d->vs[i].x = round(d->vs[i - d->map.size_x].x + len * 1 * cos((ang + 90) * CONST));
			d->vs[i].y = round(d->vs[i - d->map.size_x].y + len * 1 * sin((ang + 90) * CONST));
			printf ("i:%d, (i + 1)/(d->map.size_x):%d m+x:%d\n", i, (i) % (d->map.size_x), i + d->map.size_x);
		// 	// i++;
		}
		// else
		// {
		// 	d->vs[i + 1].x = round(d->vs[i].x + len * 1 * cos(ang * CONST));
		// 	d->vs[i + 1].y = round(d->vs[i].y + len * 1 * sin(ang * CONST));
		// 	printf ("y2:%d\n", d->vs[i].y);
		// }
		
		d->vs[i + 1].x = round(d->vs[i].x + len * 1 * cos(ang * CONST));
		d->vs[i + 1].y = round(d->vs[i].y + len * 1 * sin(ang * CONST));
		// printf ("y3:%d\n", d->vs[i].y);
		i++;
	}
}

void	map_apply_z(struct s_data *d)
{
	int	i = 0;
	float	ang =  35.264;
	int	len = d->map.un;
	ang = 35;

	d->vs[0].x = d->map.start.x;
	d->vs[0].y = d->map.start.y;
	printf ("y0:%d\n", d->vs[i].y);
	while (i < d->map.size_x * d->map.size_y)
	{
		if (i > 0 && i % (d->map.size_x) == 0)
		{
			d->vs[i].x = round(d->vs[i - d->map.size_x].x + len * 3 * cos((ang + d->vs[i].z * 15 + 90) * CONST));
			d->vs[i].y = round(d->vs[i - d->map.size_x].y + len * 1 * sin((ang + d->vs[i].z * 15 + 90) * CONST));
			printf ("i:%d, (i + 1)/(d->map.size_x):%d m+x:%d\n", i, (i) % (d->map.size_x), i + d->map.size_x);
		}
		d->vs[i + 1].x = round(d->vs[i].x + len * 3 * cos((ang + d->vs[i].z * 8) * CONST));
		d->vs[i + 1].y = round(d->vs[i].y + len * 1 * sin((ang + d->vs[i].z * 8) * CONST));
		i++;
	}
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

int	window(struct s_data *d)
{
	struct s_cube c;
	
	d->img.rx = X_REZ;
	d->img.ry = Y_REZ;
	d->p.col = 0x00FF0000;

	d->mlx = mlx_init();
	d->img.img = mlx_new_image(d->mlx, d->img.rx, d->img.ry);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bits_per_pixel, &d->img.line_length, &d->img.endian);
	d->win = mlx_new_window(d->mlx, d->img.rx, d->img.ry, "fdf");
	draw_cube(c, d);
	draw_vector_struct(d);
	map_apply_z(d);
	// map_rotate(d);
	map_draw(d);
	
	hooks(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
	mlx_loop(d->mlx);
	return (0);
}
