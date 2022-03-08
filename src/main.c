/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:56:32 by dkocob        #+#    #+#                 */
/*   Updated: 2022/03/08 19:06:10 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* 	if (!((fd = open(argv[1], O_RDONLY)) >= 0))
	if (!((fd = open("./test_maps/20-60.fdf", O_RDONLY)) >= 0))
	if (!((fd = open("./test_maps/julia.fdf", O_RDONLY)) >= 0))
	if (!((fd = open("./test_maps/pyramide.fdf", O_RDONLY)) >= 0))
	if (!((fd = open("./test_maps/100-6.fdf", O_RDONLY)) >= 0))
	if (!((fd = open("./test_maps/10-2.fdf", O_RDONLY)) >= 0))
	if (!((fd = open("./test_maps/mars.fdf", O_RDONLY)) >= 0))
	if (!((fd = open("test_maps/t1.fdf", O_RDONLY)) >= 0))
	if (!((fd = open("test_maps/plat.fdf", O_RDONLY)) >= 0))
	if (!((fd = open("test_maps/elem-col.fdf", O_RDONLY)) >= 0))
	// if (!((fd = open("./test_maps/mars.fdf", O_RDONLY)) >= 0))
	if (!((fd = open("test_maps/elem-fract.fdf", O_RDONLY)) >= 0)) 
	// fd = open(argv[1], O_RDONLY);
		*/

#include "../includes/fdf.h"

void	init(struct s_data *d)
{
	d->i.i1 = 0;
	d->i.i2 = 0;
	d->i.i3 = 0;
}

int	main(int argc, char **argv)
{
	int				fd;
	struct s_data	d;

	fd = open("test_maps/42.fdf", O_RDONLY);
	if (!fd)
		return (-1);
	map_init(fd, &d);
	d.m.lhead = (void *)0;
	d.m.rot = -20;
	d.m.iso = -1;
	d.img.rx = X_REZ;
	d.img.ry = Y_REZ;
	d.m.un = d.img.rx / ((float)(d.m.szx + d.m.szy) *1.3);
	d.m.start.x = d.m.un * (d.m.szx * (float)0.2);
	d.m.start.y = d.m.un * (d.m.szy * (float)1.3);
	d.p.col = 0x00FF0000;
	window(&d);
	return (0);
}
