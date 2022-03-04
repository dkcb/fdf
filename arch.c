/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arch.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/05 17:10:10 by dkocob        #+#    #+#                 */
/*   Updated: 2022/03/03 16:35:33 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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


// void	setup_controls(struct s_data *d)
// {
// 	mlx_hook(d->win, 2, 0, key_press, &d);
// 	mlx_hook(d->win, 17, 0, close, &d);
// 	mlx_hook(d->win, 4, 0, mouse_press, &d);
// 	mlx_hook(d->win, 5, 0, mouse_release, &d);
// 	mlx_hook(d->win, 6, 0, mouse_move, &d);
// }

// int	set_pixel(struct s_data *d, int x, int y, int c)
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
// 	int	put_line(int sx, int sy, int ex, int ey, int col, struct s_data *d)
// {
// 	int cx = 0;
// 	int cy = 0;

// 	while(ex != sx && ey != sy)
// 	{
// 		put_pixel(cx, cy, d->p.col, d);
// 	}
// 	return (0);
// }

// int	put_line(int sx, int sy, int ex, int ey, int col, struct s_data *d)
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


// int	put_line(int x1, int y1, int x2, int y2, int col, struct s_data *d)
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

// 	void	bresenham_ (int x0, int y0, int x1, int y1, int col, struct s_data *d)
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
// void	bresenham_ (int x0, int y0, int x1, int y1, int col, struct s_data *d)
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

// }int	map_draw_borders(struct s_data *d)
// {	
// 	int	i1 = 0;
// 	int	i2 = 0;
// 	int	unitx = d->img.rx / (d->m.size_x + 20);
// 	int	unity = unitx;
// 	// int	unity = d->img.ry / (d->m.size_y + 4);
// 	int gapx = unitx;
// 	int gapy = unity;
// 	int	isometry = unitx * 2;
// 	// int gapx = unitx * 10;
// 	// int gapy = unity * 3;

// 	// put_line(unitx, unity, d->img.rx - unitx, d->img.ry - unity, 0x00FF0000, d);
// 	// put_line(unitx, unity, d->img.rx - unitx, unity, 0x00FF0000, d);
// 	while (i1 < d->m.size_y)
// 	{
// 		while (i2 < d->m.size_x)
// 		{
// 			// put_line(gapx + unitx * i2, gapy + unity * i1, gapx + unitx * (i2 + 1), gapy + unity * (i1 + 1), 0x00FF0000, d);
// 			put_line((gapx + unitx * i2) + isometry, (gapy + unity * i1) - isometry, (gapx + unitx * (i2 + 1)) + isometry, (gapy + unity * i1) - isometry, 0x00FF0000, d); // X lines
// 			put_line((gapx + unitx * i2) + isometry, (gapy + unity * i1) + isometry, (gapx + unitx * i2) + isometry , (gapy + unity * (i1 + 1)) + isometry, 0x00FF0000, d); // Y lines
// 			i2++;
// 		}
// 		i2 = 0;
// 		i1++;
// 	}
// 	put_line(gapx , gapy + unity * d->m.size_y, gapx + unitx * d->m.size_x, gapy + unity * d->m.size_y, 0x00FF0000, d); // X lines
// 	put_line(gapx + unitx * d->m.size_x, gapy, gapx + unitx * d->m.size_x , gapy + unity * d->m.size_y, 0x00FF0000, d); // Y lines
// 	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
// 	return (0);
// }

// int	map_draw_borders(struct s_data *d)
// {	
// 	int	i1 = 0;
// 	int	i2 = 0;

// 	d->m.unx = d->img.rx / (d->m.size_x + 20);
// 	d->m.uny = d->m.unx;
// 	d->m.gapx =  d->m.unx;
// 	d->m.gapy =  d->m.gapx;
// 	d->m.iso = 2;
// 	d->m.shiftx = 2 * d->m.unx;
// 	d->m.shifty = 1;
// 	while (i1 < d->m.size_y)
// 	{
// 		while (i2 < d->m.size_x * 2)
// 		{
// 			// put_line(d->m.gapx + d->m.unx * i2, d->m.gapy + d->m.uny * i1, d->m.gapx + d->m.unx * (i2 + 1), d->m.gapy + d->m.uny * (i1 + 1), 0x00FF0000, d);
// 			// put_line((d->m.gapx + d->m.unx * i2) + d->m.iso, (d->m.gapy + d->m.uny * i1) - d->m.iso, (d->m.gapx + d->m.unx * (i2 + 1)) + d->m.iso, (d->m.gapy + d->m.uny * i1) - d->m.iso, 0x00FF0000, d); // X lines
// 			// put_line((d->m.gapx + d->m.unx * i2) + d->m.iso, (d->m.gapy + d->m.uny * i1) + d->m.iso, (d->m.gapx + d->m.unx * i2) + d->m.iso , (d->m.gapy + d->m.uny * (i1 + 1)) + d->m.iso, 0x00FF0000, d); // Y lines
// 			// put_line((d->m.gapx + d->m.unx * i2)+ d->m.iso, (d->m.gapy + d->m.uny * i1), (d->m.gapx + d->m.unx * (i2 + 1)) + d->m.iso, (d->m.gapy + d->m.uny * i1), 0x00FF0000, d); // X lines
// 			// put_line(d->m.gapx + d->m.unx * i2 + d->m.shiftx * i1 , (d->m.gapy + d->m.uny * i1) + d->m.iso, (d->m.gapx + d->m.unx * i2) + d->m.iso , (d->m.gapy + d->m.uny * (i1 + 1)) + d->m.iso, 0x00FF0000, d); // Y lines
// 			put_line(d->m.gapx + d->m.unx * i2 + d->m.shiftx * i1 , d->m.gapy + d->m.uny * i1, d->m.gapx + d->m.unx * (i2 + 1) + d->m.shiftx * i1 , (d->m.gapy + d->m.uny * (i1 + 1)), 0x00FF0000, d); // Y2 lines
// 			put_line(d->m.gapx + d->m.unx * i2 + d->m.shiftx * i1 , d->m.gapy + d->m.uny * i1, d->m.gapx + d->m.unx * i2 + d->m.shiftx * i1 + d->m.shiftx * i1 , (d->m.gapy + d->m.uny * (i1 + 1)), 0x035F3000, d); // X2 lines
// 			i2+= 2;
// 		}
// 		i2 = 0;
// 		i1+= 2;
// 	}
// 	return (0);
// }

// int	put_vector(int x1, int y1, double ang, double len, int col, struct s_data *d)
// {
// 	int x2;
// 	int y2;
// 	int dx = abs(x2 - x1);
// 	int dy = abs(y2 - y1);

// 	x2 = x1 + len * cos(ang);
// 	y2 = y1 + len * sin(ang);

// 	while (x1 != x2 || y1 != y2)
// 	{
// 		if (dx >= dy)
// 		put_pixel(x1, y1, col, d);
// 	}
// 	// put_line(x1, y1, x2, y2, col, d);
// 	return (0);
// }

// int	map_draw_borders(struct s_data *d)
// {	
// 	int	i1 = 0;
// 	int	i2 = 0;
// 	int	startx = 0;
// 	int	starty = 0;
// 	int	endx = 0;
// 	int	endy = 0;


// 	d->m.unx = d->img.rx / (d->m.size_x + 20);
// 	d->m.uny = d->m.unx;
// 	d->m.gapx =  d->m.unx;
// 	d->m.gapy =  d->m.gapx;
// 	d->m.iso = 2;
// 	d->m.shiftx = 2 * d->m.unx;
// 	d->m.shifty = 1;
// 	while (i1 < d->m.size_y)
// 	{
// 		while (i2 < d->m.size_x * 1)
// 		{
// 			startx = d->m.gapx + d->m.unx * i2 + d->m.shiftx * i1;
// 			starty = d->m.gapy + d->m.uny * i1;
// 			endx = d->m.gapx + d->m.unx * (i2 + 1) + d->m.shiftx * i1;
// 			endy = (d->m.gapy + d->m.uny * (i1 + 1));

// 			put_line(startx , starty, endx , endy, 0x00FF0000, d); // Y lines
// 			// put_line(d->m.gapx + d->m.unx * i2 + d->m.shiftx * i1 , d->m.gapy + d->m.uny * i1, d->m.gapx + d->m.unx * (i2 + 1) + d->m.shiftx * i1 , (d->m.gapy + d->m.uny * (i1 + 1)), 0x00FF0000, d); // Y2 lines
// 			// put_line(d->m.gapx + d->m.unx * i2 + d->m.shiftx * i1 , d->m.gapy + d->m.uny * i1, d->m.gapx + d->m.unx * i2 + d->m.shiftx * i1 + d->m.shiftx * i1 , (d->m.gapy + d->m.uny * (i1 + 1)), 0x035F3000, d); // X2 lines
// 			i2+= 1;
// 		}
// 		i2 = 0;
// 		i1+= 1;
// 	}
// 	return (0);
// }

// int	put_vector_br(int x1, int y1, double ang, double len, int col, struct s_data *d)
// {
// 	int x2;
// 	int y2;

// 	x2 = x1 + round(len * cos(ang));
// 	y2 = y1 + round(len * sin(ang));
	
// 	put_line(x1, y1, x2, y2, col, d);
// 	return (0);
// }

// int	draw_cube(struct s_data *d)
// {	
// 	struct s_v	v;
	
// 	d->v.col = 0x00FF0000;	
// 	d->v.start.x = 100;
// 	d->v.start.y = 100;
// 	d->v.end.x = 200;
// 	d->v.end.y = 100;
// 	put_vector(&d->v, d);
// 	d->v.start.x = 100;
// 	d->v.start.y = 100;
// 	d->v.end.x = 100;
// 	d->v.end.y = 200;
// 	put_vector(&d->v, d);
// 	d->v.start.x = 100;
// 	d->v.start.y = 200;
// 	d->v.end.x = 200;
// 	d->v.end.y = 200;
// 	put_vector(&d->v, d);
// 	d->v.start.x = 200;
// 	d->v.start.y = 100;
// 	d->v.end.x = 200;
// 	d->v.end.y = 200;
// 	put_vector(&d->v, d);
// 	// put_line(v.start.x, p.y, p.z, p.y2, p.col, d);
// 	return (0);
// }
		// d->v.ang * 0.01745

// int	grid(struct s_data *d)
// {	
// 	struct s_v	v;
// 	int	i = 0;
	
// 	d->v.col = 0x00FF0000;	
// 	d->v.start.x = 400;
// 	d->v.start.y = 400;
// 	d->v.len = 50;
// 	d->v.ang = 30;
// 	put_vector_ang(d);
// 	while (i++ < d->m.size_y)
// 	{
// 		d->v.start.x = d->v.end.x;
// 		d->v.start.y = d->v.end.y;
// 		if (i%2 > 0)
// 			d->v.ang += 299;
// 		else
// 		{
// 			d->v.ang -= 299;
// 		}
		
// 		d->v.col += 500;
// 		put_vector_ang(d);
// 	}
// 	return (0);
// }
// int	put_vector(struct s_v *v, struct s_data *d)
// {
// 	order_int(&v->start.x, &v->start.y, &v->end.x, &v->end.y);
// 	bresenham_(v->start.x, v->start.y, v->end.x, v->end.y, v->col, d);
// 	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
// 	return (0);
// }


// int	draw_cube(struct s_data *d)
// {	
// d->v.end.x = 200;
// d->v.end.y = 100;
// 	put_line(100, 100, 500, 100, 0x00FF0000, d);
// 	put_line(100, 500, 500, 500, 0x00FF0000, d);
// 	put_line(500, 100, 500, 500, 0x00FF0000, d);
// 	put_line(100, 100, 100, 500, 0x00FF0000, d);
// 	put_line(100, 100, 500, 500, 0x00FF0000, d);
// 	put_line(500, 100, 100, 500, 0x00FF0000, d);
// 	put_line(200, 100, 100, 200, 0x00FF0000, d);
// 	put_line(100, 100, 400, 200, 0x00FF0000, d);
	// put_line(v.start.x, p.y, p.z, p.y2, p.col, d);
// 	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
// 	return (0);
// }


// int	map_draw_borders(struct s_data *d)
// {	
// 	int	i1 = 1;
// 	int	i2 = 1;
// 	int	startx = 0;
// 	int	starty = 0;
// 	int	end__x = 0;
// 	int	end__y = 0;


// 	d->m.unx = d->img.rx / (d->m.size_x * 3);
// 	d->m.uny = d->m.unx - 25;
// 	d->m.gapx =  d->m.unx * 15;
// 	d->m.gapy =  d->m.uny * 2;
// 	d->m.shiftx = round(-10);
// 	d->m.shifty = round(1);
// 	startx = d->m.gapx;
// 	starty = d->m.gapy;
// 	end__x = startx + d->m.unx;
// 	end__y = starty;// + d->m.uny;
// 	// put_line(startx , starty, end__x , end__y, 0x035F3000, d);
// 	while (i1 <= d->m.size_y) //Y incr)
// 	{
// 		while (i2 <= d->m.size_x) //X incr
// 		{
// 			startx += d->m.unx;// + d->m.shiftx * i1;
// 			end__x = startx + d->m.unx;
// 			put_line(startx , starty, end__x , end__y, 0x00F50000, d); // X lines
// 			put_line(startx , starty, startx + d->m.shiftx, starty + d->m.uny * d->m.shifty, 0x011F8000, d); // Y lines
// 			i2 += 1; 
// 		}
// 		starty += d->m.uny ;
// 		end__y = starty;
// 		startx = d->m.gapx + d->m.shiftx * i1;
// 		i2 = 1;
// 		i1+= 1;
// 	}
// 	return (0);
// }
// int	put_object(t_data *d)
// {
// 	int i1 = 0;
// 	int i2 = 0;
// 	d->m.un = d->img.rx / (d->m.size_x + 4);
	
// 	// while (i < 10)
// 	// {
// 	// 	put_line()
// 	// 	i++;
// 	// }

	// put_vector_br(d->v.x1, d->v.x1, d->v.ang, d->v.len,  d->v.col, d);
	// while (i1 < d->m.size_y)
	// {
	// 	while (i2 < d->m.size_x)
	// 		{
	// 			put_vector(200, 200, 75, 300, 0x035F3000, d);
	// 			i2++;
	// 		}
	// 		printf("\n");
	// 		i2 = 0;
	// 		i1++;
	// }
// 	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
// 	return (0);
// }


// int	put_vector(struct s_v *v, struct s_data *d)
// {
// 	// struct s_v line;
	
// 	int	x1 = v->start.x;
// 	int	x2 = v->end.x * 1;
// 	int	y1 = 0;
// 	int	y2 = 0;
// 	int	z1 = v->start.y;
// 	int	z2 = v->end.y;

// 	// y1 = x1 + round(len * cos(ang));
// 	// y2 = y1 + round(len * sin(ang));
	
// 	put_line(x1, z1, x2, z2, v->col, d);
// 	// mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
// 	return (0);
// }

// int	grid(struct s_data *d)
// {	
// 	int	i1 = 0;
// 	int	i2 = 0;
// 	int	a = 45;
// 	double c = 0.0174533;
// 	double iso = 1;
	
// 	d->v.orig.x = d->img.rx / 3;
// 	d->v.orig.y = d->img.ry / 3;
// 	d->v.start.x = d->v.orig.x;
// 	d->v.start.y = d->v.orig.y;
// 	d->v.col = 0x00FF0000;	
// 	d->v.len = 20;
// 	while (i1++ < d->m.size_y)
// 	{
// 		while (i2++ < d->m.size_x)
// 		{
// 			v_end_calc(&d->v, a);
// 			put_line(d->v.start.x, d->v.start.y, d->v.end.x, d->v.end.y, d->v.col, d);
// 			v_end_calc(&d->v, a + 90);
// 			put_line(d->v.start.x, d->v.start.y, d->v.end.x, d->v.end.y, d->v.col, d);
// 			v_end_calc(&d->v, a);
// 			d->v.start.x = d->v.end.x + 5;
// 			d->v.start.y = d->v.end.y + 5;
// 		}
// 		d->v.start.x = round(d->v.orig.x - i1 * (d->v.len) * cos((a + 180) * c));
// 		d->v.start.y = round(d->v.orig.y + i1 * (d->v.len) * iso * sin((a + 180) * c));
// 		i2 = 0;
// 	}
// 	return (0);
// }


// int	values(struct s_data *d)
// {
// 	int	**numeric;
// 	int	i1 = 0;
// 	int	i2 = 0;
// 	int	c = 0;

// 	d->m.cur = d->m.lhead;
// 	numeric = malloc(sizeof(int *) * d->m.size_y);
// 	if (!numeric)
// 		return (-1);
// 	while (i1 < d->m.size_y)
// 	{
// 		numeric[i1] = malloc(sizeof(int) * d->m.size_x);
// 		if (!numeric[i1])
// 			return (-1);
// 		while (i2 < d->m.size_x)
// 		{
// 			// printf("%c ", d->m.cur->line[c]);
// 			numeric[i1][i2] = val(&d->m.cur->line[c]);
// 			while (ft_isdigit(d->m.cur->line[c]) || d->m.cur->line[c] == '-')
// 				c++;
// 			while (d->m.cur->line[c] == ' ')
// 				c++;
// 			i2++;
// 		}
// 		// printf("\n");
// 		d->m.cur = d->m.cur->next;
// 		i2 = 0;
// 		c = 0;
// 		i1++;
// 	}
// 	d->m.array = numeric;
// 	return (0);
// }

// int	values(struct s_data *d)
// {
// 	int	**numeric;
// 	int	i1 = 0;
// 	int	i2 = 0;
// 	int	i3 = 0;
// 	int	c = 0;
	
// 	d->m.size_z = 3;
// 	d->m.cur = d->m.lhead;
// 	d->m.l = malloc(sizeof(int**) * d->m.size_x);
// 	while (i1 < d->m.size_x)
// 	{
// 		d->m.l[i1] = malloc(sizeof(int*) * d->m.size_y);
// 		while (i2 < d->m.size_y)
// 		{
// 			while (i3 < d->m.size_z)
// 			{
// 				d->m.l[i3] = malloc(sizeof(int) * d->m.size_z);
// 				// printf("%c ", d->m.cur->line[c]);
// 				d->m.l[i1][i2][i3] = val(&d->m.cur->line[c]);
// 				while (ft_isdigit(d->m.cur->line[c]) || d->m.cur->line[c] == '-')
// 					c++;
// 				while (d->m.cur->line[c] == ' ')
// 					c++;
// 				i3++;
// 			}
// 				i2++;
// 		}
// 		// printf("\n");
// 		d->m.cur = d->m.cur->next;
// 		i2 = 0;
// 		c = 0;
// 		i1++;
// 	}

// 	d->m.array = numeric;
// 	return (0);
// }

// int	grid(struct s_data *d)
// {	
// 	int	i1 = 0;
// 	int	i2 = 0;
// 	int	a = 45;
// 	int fa = -15;
// 	int ha = 15;
// 	double c = 0.0174533;
// 	double iso = 1;
	
// 	d->v.orig.x = d->img.rx / 3;
// 	d->v.orig.y = d->img.ry / 3;
// 	d->v.start.x = d->v.orig.x;
// 	d->v.start.y = d->v.orig.y;
// 	d->v.col = 0x00FF0000;	
// 	d->v.len = 20;
// 	while (i1 < d->m.size_y)
// 	{
// 		while (i2 < d->m.size_x)
// 		{
// 			printf("%d ,", d->m.array[i1][i2]);
// 			v_end_calc(&d->v, a, d->v.len);
// 			put_line(d->v.start.x, d->v.start.y, d->v.end.x, d->v.end.y, d->v.col, d);
// 			v_end_calc(&d->v, a + 90 - fa * 2, d->v.len);
// 			put_line(d->v.start.x, d->v.start.y, d->v.end.x, d->v.end.y, d->v.col, d);
// 			v_end_calc(&d->v, a, d->v.len);
// 			d->v.start.x = d->v.end.x + 10;
// 			d->v.start.y = d->v.end.y + 10;
// 			i2++;
// 		}
// 		fa += 11;
// 		d->v.start.x = round(d->v.orig.x - i1 * d->v.len * cos((a + fa) * c));
// 		d->v.start.y = round(d->v.orig.y + i1 * d->v.len * iso * sin((a + fa) * c));
// 		i2 = 0;
// 		i1++;
// 		printf("\n");
// 	}
// 	return (0);
// }

// int	grid(struct s_data *d)
// {	
// 	int	i1 = 0;
// 	int	i2 = 0;
// 	int	a = 35;
// 	int fa = -15;
// 	int ha = 150;
// 	double iso = 1;
	
// 	d->v.orig.x = d->img.rx / 3;
// 	d->v.orig.y = d->img.ry / 3;
// 	d->v.start.x = d->v.orig.x;
// 	d->v.start.y = d->v.orig.y;
// 	d->v.col = 0x00FF0000;	
// 	d->v.len = 20;
// 	while (i1 < d->m.size_y)
// 	{
// 		while (i2 < d->m.size_x)
// 		{
// 			printf("%d ,", d->m.array[i1][i2]);
// 			v_end_calc(&d->v, a, d->v.len);
// 			// apply_z
// 			put_line(d->v.start.x, d->v.start.y, d->v.end.x, d->v.end.y, d->v.col, d);
// 			v_end_calc(&d->v, a + 90 - fa, d->v.len);
// 			put_line(d->v.start.x, d->v.start.y, d->v.end.x, d->v.end.y, d->v.col, d);
// 			v_end_calc(&d->v, a, d->v.len);
// 			d->v.start.x = d->v.end.x + 10;
// 			d->v.start.y = d->v.end.y + 10;
// 			i2++;
// 		}
// 		fa += 11;
// 		d->v.start.x = round(d->v.orig.x - i1 * d->v.len * cos((a + fa) * CONST));
// 		d->v.start.y = round(d->v.orig.y + i1 * d->v.len * iso * sin((a + fa) * CONST));
// 		i2 = 0;
// 		i1++;
// 		printf("\n");
// 	}
// 	return (0);
// }

// struct s_node	*vlist(struct s_data *d)
// {
// 	struct s_node	*vect;
// 	int	i1 = 0;
// 	int	i2 = 0;
// 	int	i3 = 0;
// 	int	in = 0;
// 	int	c = 0;
// 	// int	size = d->m.size_x * d->m.size_y;
	
// 	vect = malloc(sizeof(vect) * d->m.size_x * d->m.size_y + 1);
// 	if (!vect)
// 		return (NULL);
// 	d->m.cur = d->m.lhead;
// 	while (i1 < d->m.size_x * d->m.size_y)
// 	{
// 		while (i2 < d->m.size_x)
// 		{
// 			vect[i1].x = i1;
// 			vect[i1].y = i3;
// 			vect[i1].z = val(&d->m.cur->line[c]);
// 			while (ft_isdigit(d->m.cur->line[c]) || d->m.cur->line[c] == '-')
// 				c++;
// 			while (d->m.cur->line[c] == ' ')
// 				c++;
// 			i1++;
// 			i2++;
// 		}
// 		d->m.cur = d->m.cur->next;
// 		i3++;
// 		c = 0;
// 		i2 = 0;
// 	}
// 	d->vs = vect;
// 	return (vect);
// }

// int	grid(struct s_data *d)
// {	
// 	int	i1 = 0;
// 	int	i2 = 0;
// 	int	a = 35;
// 	int fa = -15;
// 	int ha = 150;
// 	double iso = 1;
	
// 	d->v.orig.x = d->img.rx / 3;
// 	d->v.orig.y = d->img.ry / 3;
// 	d->v.start.x = d->v.orig.x;
// 	d->v.start.y = d->v.orig.y;
// 	d->v.col = 0x00FF0000;	
// 	d->v.len = 20;
// 	while (i1 < d->m.size_y)
// 	{
// 		while (i2 < d->m.size_x)
// 		{
// 			// printf("%d ,", d->m.array[i1][i2]);
// 			v_end_calc(&d->v, a, d->v.len);
// 			// apply_z
// 			put_line(d->v.start.x, d->v.start.y, d->v.end.x, d->v.end.y, d->v.col, d);
// 			v_end_calc(&d->v, a + 90 - fa, d->v.len);
// 			put_line(d->v.start.x, d->v.start.y, d->v.end.x, d->v.end.y, d->v.col, d);
// 			v_end_calc(&d->v, a, d->v.len);
// 			d->v.start.x = d->v.end.x + 10;
// 			d->v.start.y = d->v.end.y + 10;
// 			i2++;
// 		}
// 		fa += 11;
// 		d->v.start.x = round(d->v.orig.x - i1 * d->v.len * cos((a + fa) * CONST));
// 		d->v.start.y = round(d->v.orig.y + i1 * d->v.len * iso * sin((a + fa) * CONST));
// 		i2 = 0;
// 		i1++;
// 		printf("\n");
// 	}
// 	return (0);
// }

// t_node n[] = {1, 1, 1};
		// float	c = cos(ang * CONST);
		// float	s = sin(ang * CONST);
		// d->vs[i + 1].x = round(d->vs[0].x + len * 1 * cos(ang * CONST));
		// d->vs[i + 1].y = round(d->vs[0].y + len * 1 * sin(ang * CONST));
		// else
		// {
		// 	// if (i == 0 || i % (d->m.size_x) == 1)
		// 	// {
		// 	// 	d->vs[i].x = round(d->vs[i - 1].x + len * 1 * cos(ang * CONST));
		// 	// 	d->vs[i].y = round(d->vs[i - 1].y + len * 1 * sin(ang * CONST));
		// 	// }
		// }
		// i++;
			// printf ("i:%d, (i + 1)/(d->m.size_x):%d \n", i, (i + 1) % (d->m.size_x));
		// d->vs[i + d->m.size_x].y = round(d->vs[i - 1].x + len * 1 * cos((ang + 90) * CONST));
		// d->vs[i + d->m.size_x].y = round(d->vs[i - 1].y + len * 1 * sin((ang + 90) * CONST));
		// printf ("i:%d, (i + 1)/(d->m.size_x):%d \n", i, (i + 1) % (d->m.size_x));
		// d->vs[i].x = round(d->vs[i - 1].x + len * 1 * cos(ang * CONST));
		// d->vs[i].y = round(d->vs[i - 1].y + len * 1 * sin(ang * CONST));


// void v_end_calc(struct s_v *v, int ang, int len)
// {
// 	v->end.x = round(v->start.x + len * cos(ang * CONST));
// 	v->end.y = round(v->start.y + len * sin(ang * CONST));
// }

// // void v_end_calcZX(struct s_v *v, int ang, int len)
// // {
// // 	double CONST = 0.0174533;

// // 	v->end.x = round(v->start.x + len * cos(ang * CONST));
// // 	v->end.y = round(v->start.y + len * sin(ang * CONST));
// // 	v->end.x = round(v->end.x - len * cos(35.264 * CONST));
// // 	v->end.y = round(v->end.y + len * sin(35.264 * CONST));
// // }

// // void v_end_calcZY(struct s_v *v, int ang, int len)
// // {
// // 	double CONST = 0.0174533;

// // 	v->end.x = round(v->start.x + len * cos(ang * CONST));
// // 	v->end.y = round(v->start.y + len * sin(ang * CONST));
// // 	v->end.x = round(v->end.x + len * cos(35.264 * CONST));
// // 	v->end.y = round(v->end.y + len * sin(35.264 * CONST));
// // }

// int	draw_vect_ang(struct s_v v, struct s_data *d)
// {
// 	put_line(v.start.x, v.start.y, v.end.x, v.end.y, v.col, d);
// 	return (0);
// }


// int	draw_quadrat(struct s_v v, struct s_data *d)
// {	
// 	// struct s_v	v;
// 	int	i = 0;
	
// 	// v.ang = 45;
// 	// v.col = 0x00FF0000;	
// 	// v.start.x = 100;
// 	// v.start.y = 10;
// 	// v.len = 50;
// 	// v.ang = 0;
// 	while (i++ < 4)
// 	{
// 		v_end_calc(&v, v.ang, v.len);
// 		draw_vect_ang(v, d);
// 		v.start.x = v.end.x;
// 		v.start.y = v.end.y;
// 		v.ang += 90;
// 		// d->v.col += 27500;
// 	}
// 	return (0);
// }

// int	draw_cube(struct s_cube cube, struct s_data *d)
// {	
// 	struct s_v	v;
// 	int	i = 0;
// 	double iso =  35.264;
// 	iso =  35.264;
	
// 	v.ang = 15;
// 	v.col = 0x00FF0000;	
// 	v.end.x = 100;
// 	v.end.y = 100;
// 	v.len = 50;
// 	while (i++ < 4)
// 	{
// 		v.start.x = v.end.x;
// 		v.start.y = v.end.y;
// 		v.ang += 90;
// 		v_end_calc(&v, v.ang, v.len);
// 		draw_vect_ang(v, d);
// 	}
// 	i = 0;
// 	v.start.x = v.end.x;
// 	v.start.y = v.end.y;
// 	v.end.x = round(v.start.x + v.len/2 * cos(iso * CONST));
// 	v.end.y = round(v.start.y + v.len/2 * sin(iso * CONST));
// 	draw_vect_ang(v, d);

// 	while (i++ < 4)
// 	{
// 		v.start.x = v.end.x;
// 		v.start.y = v.end.y;
// 		v.ang += 90;
// 		v_end_calc(&v, v.ang, v.len);
// 		draw_vect_ang(v, d);
// 	}
// 	return (0);
// }