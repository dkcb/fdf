/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 19:00:06 by dkocob        #+#    #+#                 */
/*   Updated: 2022/03/15 17:29:07 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	assign_map_values(struct s_data *d)
{
	d->vs[d->i.i1].z = val(&d->m.cur->line[d->i.c]);
	if (d->vs[d->i.i1].z > d->m.maxz)
		d->m.maxz = d->vs[d->i.i1].z;
	if (d->vs[d->i.i1].z < d->m.minz)
		d->m.minz = d->vs[d->i.i1].z;
	while (ft_isdigit(d->m.cur->line[d->i.c]) || d->m.cur->line[d->i.c] == '-')
		d->i.c++;
	if (d->m.cur->line[d->i.c] == ',')
	{
		d->i.c += 3;
		d->vs[d->i.i1].col = val16(&d->m.cur->line[d->i.c]);
		while (d->m.cur->line[d->i.c] != ' ')
		d->i.c++;
	}
	while (d->m.cur->line[d->i.c] == ' ')
		d->i.c++;
	d->i.i1++;
	d->i.i2++;
}

struct s_p	*vlist(struct s_data *d)
{
	d->vs = malloc(sizeof(struct s_p) * (d->m.szx * d->m.szy + 1));
	if (!d->vs)
		exit (0);
	d->m.cur = d->m.lhead;
	while (d->i.i1 < d->m.szx * d->m.szy)
	{
		while (d->i.i2 < d->m.szx)
			assign_map_values(d);
		d->m.cur = d->m.cur->next;
		d->i.i3++;
		d->i.c = 0;
		d->i.i2 = 0;
		d->m.zoom = (float)3 / (abs(d->m.minz) + abs(d->m.maxz) + 0.01);
	}
	return (d->vs);
}

void	get_arg_stack(struct s_data *d)
{
	struct s_line	*new;
	struct s_line	*cur;
	char			*line;
	int				i;

	i = 0;
	cur = malloc(sizeof(struct s_line));
	if (!cur || d->m.fd < 1)
		exit (0);
	while (get_next_line(d->m.fd, &line))
	{
		cur->line = line;
		if (i == 0)
			d->m.lhead = cur;
		new = malloc(sizeof(struct s_line));
		if (!new || d->m.fd < 1)
			exit (0);
		cur->next = new;
		cur = new;
		i++;
	}
	new->next = NULL;
	d->m.szy = i;
}

size_t	c_cnt_fdf(char *s, char c)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i2++;
			while (s[i] == c)
				i++;
		}
		i++;
	}
	return (i2);
}

struct s_p	*map_init(struct s_data *d)
{
	get_arg_stack(d);
	d->m.szx = c_cnt_fdf(d->m.lhead->line, ' ');
	return (vlist(d));
}
