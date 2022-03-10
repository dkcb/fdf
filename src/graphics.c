/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   graphics.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/27 17:55:01 by dkocob        #+#    #+#                 */
/*   Updated: 2022/03/10 17:51:34 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	img_clear(unsigned int col, struct s_data *d)
{
	int	i1;
	int	i2;

	i1 = -1;
	i2 = -1;
	while (i1++ <= d->img.ry)
	{
		while (i2++ <= d->img.rx)
			put_pixel(i2, i1, col, d);
		i2 = -1;
	}
}

void	put_pixel(int x, int y, int col, struct s_data *d)
{
	char	*dst;

	if (x >= 0 && x < d->img.rx && y < d->img.ry && y >= 0)
	{
		dst = d->img.addr + (y * d->img.line_length
				+ x * (d->img.bits_per_pixel / 8));
		*(unsigned int *)dst = col;
	}
}

void	bresenham_(struct s_br *br, struct s_ln *ln, struct s_data *d)
{
	if (ln->y2 > ln->y1)
	{
		br->dy = -1 * (ln->y2 - ln->y1);
		br->sy = 1;
	}
	br->err = br->dx + br->dy;
	while (ln->x1 <= ln->x2)
	{
		put_pixel(ln->x1, ln->y1, ln->col, d);
		if (ln->x1 == ln->x2 && ln->y1 == ln->y2)
			break ;
		br->e2 = 2 * br->err;
		if (br->e2 >= br->dy)
		{
			br->err += br->dy;
			ln->x1 += br->sx;
		}
		if (br->e2 <= br->dx)
		{
			br->err += br->dx;
			ln->y1 += br->sy;
		}
	}
}

int	put_line(struct s_ln *ln, struct s_data *d)
{
	struct s_br	br;

	order_int(&ln->x1, &ln->y1, &ln->x2, &ln->y2);
	br.sx = 1;
	br.sy = -1;
	br.dx = ln->x2 - ln->x1;
	br.dy = -1 * (ln->y1 - ln->y2);
	bresenham_(&br, ln, d);
	return (0);
}

void	map_draw(int i, struct s_data *d)
{
	struct s_ln	ln;

	img_clear(0x00000000, d);
	while (i < d->m.szx * d->m.szy)
	{
		if (i % (d->m.szx) != d->m.szx - 1)
		{
			ln.x1 = d->vs[i].x;
			ln.y1 = d->vs[i].y;
			ln.x2 = d->vs[i + 1].x;
			ln.y2 = d->vs[i + 1].y;
			ln.col = 0x00FF0000;
			put_line(&ln, d);
		}
		if (i > d->m.szx - 1)
		{
			ln.x1 = d->vs[i].x;
			ln.y1 = d->vs[i].y;
			ln.x2 = d->vs[i - d->m.szx].x;
			ln.y2 = d->vs[i - d->m.szx].y;
			ln.col = 0x00F08000;
			put_line(&ln, d);
		}
		i++;
	}
}
