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

int	order_int(int *x1, int *y1, int *x2, int *y2)
{
	int	tmp;

	if (*x1 > *x2)
	{
		tmp = *x2;
		*x2 = *x1;
		*x1 = tmp;
		tmp = *y2;
		*y2 = *y1;
		*y1 = tmp;
	}
	return (0);
}

void	map_rotate(struct s_data *d)
{
	int	i = 0;
	int	ang = d->map.rot;
	int	len = d->map.un;

	d->vs[0].x = d->map.start.x;
	d->vs[0].y = d->map.start.y;
	while (i < d->map.size_x * d->map.size_y)
	{
		if (i > 0 && i % (d->map.size_x) == 0)
		{
			d->vs[i].x = round(d->vs[i - d->map.size_x].x + len * 1 * cos((ang + 90) * CONST));
			d->vs[i].y = round(d->vs[i - d->map.size_x].y + len * d->map.iso * sin((ang + 90) * CONST));
		}
		d->vs[i + 1].x = round(d->vs[i].x + len * 1 * cos(ang * CONST));
		d->vs[i + 1].y = round(d->vs[i].y + len * 1 * sin(ang * CONST));
		i++;
	}
}

void	map_apply_z(struct s_data *d)
{
	int	i = 0;
	float	ang =  35.264;
	int	len = d->map.un;
	// ang = 135;
	ang = d->map.rot - 90;

	while (i < d->map.size_x * d->map.size_y)
	{
		d->vs[i].x = round(d->vs[i].x + len * d->vs[i].z * d->map.zoom * cos(ang * CONST));
		d->vs[i].y = round(d->vs[i].y + len * d->vs[i].z  * d->map.zoom * sin(ang * CONST));
		i++;
	}
}