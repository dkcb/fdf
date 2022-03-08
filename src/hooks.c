/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 17:54:41 by dkocob        #+#    #+#                 */
/*   Updated: 2022/03/04 16:17:54 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	closehook(int keycode, struct s_data *d)
{
	(void)d;
	if (keycode == 125)
		d->m.zoom -= (float)0.1;
	if (keycode == 126)
		d->m.zoom += (float)0.1;
	if (keycode == 123)
		d->m.rot -= 5;
	if (keycode == 124)
		d->m.rot += 5;
	if (keycode == 78)
		d->m.un *= (float)0.7;
	if (keycode == 69)
		d->m.un *= (float)1.3;
	if (keycode == 53)
		exit(0);
	if (keycode < 0)
		exit(0);
	render(d);
	return (0);
}

int	mouse_move(int x, int y, struct s_data *d)
{
	if (d->c.pr == 1)
	{
		put_pixel(x, y, 0x00FF0000, d);
	}
	return (0);
}

int	mouse_press(int press, int x, int y, struct s_data *d)
{
	d->c.pr = 1;
	d->c.px = x;
	d->c.py = y;
	return (0);
}

int	mouse_release(int press, int x, int y, struct s_data *d)
{
	if (d->c.pr == 1)
	{
		d->m.start.y -= (d->c.py - y);
		d->m.start.x -= (d->c.px - x);
		render(d);
	}
	d->c.pr = 0;
	return (0);
}

int	hooks(struct s_data *d)
{
	mlx_hook(d->win, 2, 1 << 0, closehook, d);
	mlx_hook(d->win, 17, 1 << 0, closehook, d);
	mlx_hook(d->win, 4, 0, mouse_press, d);
	mlx_hook(d->win, 5, 0, mouse_release, d);
	mlx_hook(d->win, 6, 0, mouse_move, d);
	return (0);
}
