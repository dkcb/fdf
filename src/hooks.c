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

int	closehook(int keycode, struct s_data *d)
{
	(void)d;
	printf("ECKEYCODE:%d\n", keycode);
	if (keycode == 125)
		d->map.zoom -= (float)0.2;
	if (keycode == 126)
		d->map.zoom += (float)0.2;
	if (keycode == 123)
		d->map.rot -= 5;
	if (keycode == 124)
		d->map.rot += 5;
	if (keycode == 78)
		d->map.un *= 0.7;
	if (keycode == 69)
		d->map.un *= 1.3;
	if (keycode == 53)
		exit(0);
	if (keycode < 0)
		exit(0);
	render(d);
	printf("iso:%f, rot:%d, ", d->map.iso, d->map.rot );
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
		// mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
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
		// put_line(d->m.px, d->m.py, x, y, 0x00FF0000, d);
		d->map.start.y -= (d->m.py - y);
		d->map.start.x -= (d->m.px - x);
		// d->map.iso += (d->m.py - y) / 100;
		// d->map.rot += (d->m.px - x) / 10;
	render(d);
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
