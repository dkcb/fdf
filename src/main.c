/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:56:32 by dkocob        #+#    #+#                 */
/*   Updated: 2021/12/17 22:21:00 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	int				fd;
	struct s_data	d;

	// if (!((fd = open(argv[1], O_RDONLY)) >= 0))
	// if (!((fd = open("./test_maps/20-60.fdf", O_RDONLY)) >= 0))
	// if (!((fd = open("./test_maps/julia.fdf", O_RDONLY)) >= 0))
	// if (!((fd = open("./test_maps/pyramide.fdf", O_RDONLY)) >= 0))
	// if (!((fd = open("./test_maps/100-6.fdf", O_RDONLY)) >= 0))
	// if (!((fd = open("./test_maps/10-2.fdf", O_RDONLY)) >= 0))
	// if (!((fd = open("./test_maps/mars.fdf", O_RDONLY)) >= 0))
	if (!((fd = open("test_maps/42.fdf", O_RDONLY)) >= 0))
	// if (!((fd = open("test_maps/t1.fdf", O_RDONLY)) >= 0))
		return (-1);
	map_init(fd, &d);
	d.map.lhead = (void *)0;
	d.map.rot = 15;
	d.map.iso = 0.5;
	d.img.rx = X_REZ;
	d.img.ry = Y_REZ;
	d.map.un = d.img.rx / d.map.size_x;
	d.map.start.x = d.map.un * 3;
	d.map.start.y = d.map.un * 7;
	d.p.col = 0x00FF0000;
	window(&d);
	return (0);
}