/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 17:54:41 by dkocob        #+#    #+#                 */
/*   Updated: 2021/11/23 18:55:30 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_pixel(t_data *d)
{
	char	*dst;

	if (d->p.x <= d->img.rx && d->p.y <= d->img.ry)
	{
		dst = d->img.addr + (d->p.y * d->img.line_length + d->p.x * (d->img.bits_per_pixel / 8));
		*(unsigned int*)dst = d->p.col;
	}
}

int	set_pixel(t_data *d, int x, int y, int c)
{
	d->p.x = x;
	d->p.y = y;
	d->p.col = c;
	return (0);
}

// void	setup_controls(t_vars *vars)
// {
// 	mlx_hook(vars->win, 2, 0, key_press, &vars);
// 	mlx_hook(vars->win, 17, 0, close, &vars);
// 	mlx_hook(vars->win, 4, 0, mouse_press, &vars);
// 	mlx_hook(vars->win, 5, 0, mouse_release, &vars);
// 	mlx_hook(vars->win, 6, 0, mouse_move, &vars);
// }



int	close(int keycode, t_vars *vars)
{
	printf("ECKEYCODE:%d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode < 0)
		exit(0);
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	printf("x:%d, y:%d\n", x, y);
	// if (keycode < 0)
	// 	exit(0);
	return (0);
}

// int	set_data_mrelease(int press, int x, int y, t_vars *vars)
// {
// 	// vars->mreleased = 1;
// 	printf("Mreleased\n");
// 	return (0);
// }

int	mouse_press(int press, int x, int y, t_vars *vars)
{
	// vars->mrl = 0;
	vars->m.pr = 1;
	vars->m.px = x;
	vars->m.py = y;
	printf("MPress:%d, x:%d, y:%d\n", press, x, y);
	// while (vars->mreleased != 1)
	// {
	// 	// mlx_loop(vars->mlx);
	// }
	// mlx_hook(vars->win, 5, 0, set_data_mrelease , vars);
	// if (keycode < 0)
	// 	exit(0);
	return (0);
}

int	mouse_release(int press, int x, int y, t_vars *vars)
{
	printf("MRelease:%d, x:%d, y:%d\n", press, x, y);
	// vars->mrl = 1;
	vars->m.pr = 0;

	// if (keycode < 0)
	// 	exit(0);
	return (0);
}

int	hooks(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1<<0, close, &vars); //key press
	mlx_hook(vars->win, 17, 1<<0, close, &vars); //close button
	mlx_hook(vars->win, 4, 0, mouse_press, &vars);
	mlx_hook(vars->win, 5, 0, mouse_release, &vars);
	mlx_hook(vars->win, 6, 0, mouse_move, &vars);
	return (0);
}

int	math(t_data *d, char *shape, int scale)
{
	// d->px = 0;
	d->p.y = (d->p.x * d->p.x) / scale;
	return (0);
}

int	draw_shape(t_data *d, char *shape, int scale)
{
	while (d->p.x++ < 1900)
	{
		math(d, "p", 10000);
		set_pixel(d, d->p.x, d->p.y, d->p.col);
		put_pixel(d);
	}
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img.img, 0, 0);
	return (0);
}

int	window(void)
{
		// t_data.vars	d.vars;
	t_data	d;
	// t_img	img;
	int		x = 0;
	int		y = 0;

	d.p.col = 0x00FF0000;
	d.img.rx = 1920;
	d.img.ry = 1080;
	d.p.x = 0;
	d.p.y = 0;
	d.vars.mlx = mlx_init();
	d.img.img = mlx_new_image(d.vars.mlx, d.img.rx, d.img.ry);
	d.img.addr = mlx_get_data_addr(d.img.img, &d.img.bits_per_pixel, &d.img.line_length, &d.img.endian);
	d.vars.win = mlx_new_window(d.vars.mlx, d.img.rx, d.img.ry, "fdf");
	// while (1)
	// {
	// 	if (d.px <= d.rx && d.py <= d.ry)
	// }
	// my_mlx_pixel_put(&img, d.px, d.py, d.color);

	draw_shape(&d, "p", 100);
	hooks(&d.vars);
	mlx_loop(d.vars.mlx);
	return (0);
}
