/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 19:00:06 by dkocob        #+#    #+#                 */
/*   Updated: 2021/12/11 20:26:32 by dkocob        ########   odam.nl         */
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

struct s_node	*vlist(struct s_data *d)
{
	int	i1 = 0;
	int	i2 = 0;
	int	i3 = 0;
	int	c = 0;
	
	d->vs = malloc(sizeof(struct s_node) * d->map.size_x * d->map.size_y + 1);
	if (!d->vs)
		return (NULL);
	d->map.current = d->map.lhead;
	while (i1 < d->map.size_x * d->map.size_y)
	{
		while (i2 < d->map.size_x)
		{
			d->vs[i1].x = d->map.un * i2;
			d->vs[i1].y = d->map.un * i3;
			d->vs[i1].z = val(&d->map.current->line[c]);
			while (ft_isdigit(d->map.current->line[c]) || d->map.current->line[c] == '-')
				c++;
			while (d->map.current->line[c] == ' ')
				c++;
			i1++;
			i2++;
		}
		d->map.current = d->map.current->next;
		i3++;
		c = 0;
		i2 = 0;
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
	if (!d->map.lhead)
	{
		d->map.lhead = new;
		d->map.current = new;
		return (1);
	}
	d->map.current->next = new;
	d->map.current = d->map.current->next;
	return (0);
}

void	draw_vector_struct(struct s_data *d)
{
	int i = 0;
	while (i < d->map.size_x * d->map.size_y)
	{
		// printf (" |%d", d->vs[i].x);
		// printf ("|%d|", d->vs[i].y);
		printf ("%d|, ", d->vs[i].z);
		if ((i + 1) % (d->map.size_x) == 0)
			printf("\n");
		i++;
	}
}

int	map_init(int fd, struct s_data *d)
{
	char	*line;
	int		i = 0;
	
	while (get_next_line(fd, &line))
	{
		get_arg_stack(d, &line);
		i++;
	}
	d->map.size_y = i;
	d->map.size_x = c_cnt(d->map.lhead->line, ' ');
	d->map.current = d->map.lhead;
	vlist(d);
	i = 0;
	return (1);
}
