/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:56:32 by dkocob        #+#    #+#                 */
/*   Updated: 2022/03/15 17:24:46 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init(struct s_data *d)
{
	d->i.i1 = 0;
	d->i.i2 = 0;
	d->i.i3 = 0;
}

int	main(int argc, char **argv)
{
	struct s_data	d;

	d.m.fd = open(argv[1], O_RDONLY);
	if (argc != 2 || d.m.fd < 1 || !argv)
		exit(0);
	map_init(&d);
	d.m.rot = -20;
	d.m.iso = -1;
	d.img.rx = X_REZ;
	d.img.ry = Y_REZ;
	d.m.un = d.img.rx / ((float)(d.m.szx + d.m.szy) *1.3);
	d.m.start.x = d.m.un * (d.m.szx * (float)0.2);
	d.m.start.y = d.m.un * (d.m.szy * (float)1.3);
	window(&d);
	return (0);
}
