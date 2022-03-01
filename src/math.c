/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 17:54:41 by dkocob        #+#    #+#                 */
/*   Updated: 2022/03/01 18:07:56 by dkocob        ########   odam.nl         */
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
	int	i;

	i = 0;
	d->vs[0].x = d->m.start.x;
	d->vs[0].y = d->m.start.y;
	while (i < d->m.szx * d->m.szy)
	{
		if (i > 0 && i % d->m.szx == 0)
		{
			d->vs[i].x = round(d->vs[i - d->m.szx].x + d->m.un
					* cos((d->m.rot) * R));
			d->vs[i].y = round(d->vs[i - d->m.szx].y + d->m.un
					* d->m.iso * sin((d->m.rot) * R));
		}
		d->vs[i + 1].x = round(d->vs[i].x + d->m.un * cos(d->m.rot * R));
		d->vs[i + 1].y = round(d->vs[i].y + d->m.un * sin(d->m.rot * R));
		i++;
	}
}

void	map_apply_z(struct s_data *d)
{
	int	i;
	int	ang;

	i = 0;
	ang = d->m.rot - 90;
	while (i < d->m.szx * d->m.szy)
	{
		d->vs[i].x = round(d->vs[i].x + d->m.un * d->vs[i].z
				* d->m.zoom * cos(ang * R));
		d->vs[i].y = round(d->vs[i].y + d->m.un * d->vs[i].z
				* d->m.zoom * sin(ang * R));
		i++;
	}
}
