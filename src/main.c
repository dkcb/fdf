/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:56:32 by dkocob        #+#    #+#                 */
/*   Updated: 2021/12/16 19:03:20 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	int				fd;
	struct s_data	d;

	// d = malloc(sizeof(struct s_data));
	// if(!d)
	// 	return ((void *)0);

	d.map.lhead = (void *)0;
	d.map.un = 15;
	d.map.rot = 25;
	d.map.iso = 0.8;
	d.map.start.x = 400;
	d.map.start.y = 200;
	d.map.zoom = 0.5;
	// if (!((fd = open(argv[1], O_RDONLY)) >= 0))
	// if (!((fd = open("./test_maps/20-60.fdf", O_RDONLY)) >= 0))
	// if (!((fd = open("./test_maps/julia.fdf", O_RDONLY)) >= 0))
	// if (!((fd = open("./test_maps/100-6.fdf", O_RDONLY)) >= 0))
	// if (!((fd = open("./test_maps/10-2.fdf", O_RDONLY)) >= 0))
	if (!((fd = open("test_maps/42.fdf", O_RDONLY)) >= 0))
		return (-1);
	// map_cnt(x);
	map_init(fd, &d);
	window(&d);

	return (0);
}