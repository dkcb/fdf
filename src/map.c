/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 19:00:06 by dkocob        #+#    #+#                 */
/*   Updated: 2022/03/03 16:35:33 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t	dc(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

size_t	c_cnt(char *s, char c)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	while (s[i])
	{
		if (s[i] == c)
			i2++;
		i++;
	}
	return (i2);
}

struct s_p	*vlist(struct s_data *d)
{
	int	c;

	c = 0;
	d->i.i1 = 0;
	d->i.i2 = 0;
	d->i.i3 = 0;
	d->vs = malloc(sizeof(struct s_p) * d->m.szx * d->m.szy);
	if (!d->vs)
		return (NULL);
	d->m.cur = d->m.lhead;
	while (d->i.i1 < d->m.szx * d->m.szy)
	{
		while (d->i.i2 < d->m.szx)
		{
			d->vs[d->i.i1].z = val(&d->m.cur->line[c]);
			if (d->vs[d->i.i1].z > d->m.maxz)
				d->m.maxz = d->vs[d->i.i1].z;
			if (d->vs[d->i.i1].z < d->m.minz)
				d->m.minz = d->vs[d->i.i1].z;
			while (ft_isdigit(d->m.cur->line[c]) || d->m.cur->line[c] == '-')
				c++;
			if (d->m.cur->line[c] == ',')
			{
				c += 3;
				d->vs[d->i.i1].col = val16(&d->m.cur->line[c]);
				while (d->m.cur->line[c] != ' ')
				c++;
			}
			while (d->m.cur->line[c] == ' ')
				c++;
			d->i.i1++;
			d->i.i2++;
		}
		d->m.cur = d->m.cur->next;
		d->i.i3++;
		c = 0;
		d->i.i2 = 0;
		d->m.zoom = (float)3 / (abs(d->m.minz) + abs(d->m.maxz) + 0.01);
	}
	return (d->vs);
}

int	get_arg_stack(struct s_data *d, char **line)
{
	struct s_line	*new;

	new = malloc(sizeof(new));
	if (!line || !new || !line[0])
		return (-1);
	new->line = *line;
	if (!d->m.lhead)
	{
		d->m.lhead = new;
		d->m.cur = new;
		return (1);
	}
	d->m.cur->next = new;
	d->m.cur = d->m.cur->next;
	return (0);
}

// void	get_size(struct s_data *d)
// {
// 	int	i;

// 	i = 0;
// 	d->m.minx = 999999;
// 	d->m.miny = 999999;
// 	d->m.maxx = -999999;
// 	d->m.maxy = -999999;
// 	while (i < d->m.szx * d->m.szy)
// 	{
// 		if (d->vs[i].x < d->m.minx)
// 			d->m.minx = d->vs[i].x;
// 		if (d->vs[i].y < d->m.miny)
// 			d->m.miny = d->vs[i].y;
// 		if (d->vs[i].x > d->m.maxx)
// 			d->m.maxx = d->vs[i].x;
// 		if (d->vs[i].y > d->m.maxy)
// 			d->m.maxy = d->vs[i].y;
// 		i++;
// 	}
// }

int	map_init(int fd, struct s_data *d)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		get_arg_stack(d, &line);
		i++;
	}
	d->m.szy = i;
	d->m.szx = c_cnt(d->m.lhead->line, ' ');
	d->m.cur = d->m.lhead;
	vlist(d);
	i = 0;
	return (1);
}
