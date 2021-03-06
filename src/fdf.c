/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 17:54:41 by dkocob        #+#    #+#                 */
/*   Updated: 2022/03/15 14:40:30 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	render(struct s_data *d)
{
	map_rotate(d);
	map_apply_z(d);
	map_draw(0, d);
	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
}

int	window(struct s_data *d)
{
	d->mlx = mlx_init();
	d->img.img = mlx_new_image(d->mlx, d->img.rx, d->img.ry);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bits_per_pixel,
			&d->img.line_length, &d->img.endian);
	d->win = mlx_new_window(d->mlx, d->img.rx, d->img.ry, "fdf");
	render(d);
	hooks(d);
	mlx_loop(d->mlx);
	return (0);
}
