/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 18:56:32 by dkocob        #+#    #+#                 */
/*   Updated: 2021/11/28 22:35:47 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


int	main(int argc, char **argv)
{
	int		fd;
	t_data	d;

	// if (!((fd = open(argv[1], O_RDONLY)) >= 0))
	// if (!((fd = open("./test_maps/20-60.fdf", O_RDONLY)) >= 0))
	// if (!((fd = open("./test_maps/julia.fdf", O_RDONLY)) >= 0))
	// if (!((fd = open("./test_maps/100-6.fdf", O_RDONLY)) >= 0))
	if (!((fd = open("./test_maps/10-2.fdf", O_RDONLY)) >= 0))
		return (-1);
	// map_cnt(x);
	map_init(fd, &d);
	window(&d);

	return (0);
}