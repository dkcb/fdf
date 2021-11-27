/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 17:55:01 by dkocob        #+#    #+#                 */
/*   Updated: 2021/11/27 18:01:19 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	coordinates_prepare(t_data *d)
{
	put_line(100, 100, 500, 100, 0x00FF0000, d);
	return (0);
}

int	coordinates_print(t_data *d)
{

	return (0);
}


int	build_frame (t_data *d)
{
	coordinates_prepare(d);
	coordinates_print(d);
	return (0);
}