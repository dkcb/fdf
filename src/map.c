/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 19:00:06 by dkocob        #+#    #+#                 */
/*   Updated: 2021/11/30 20:32:41 by dkocob        ########   odam.nl         */
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

int	values(t_data *d)
{
	int	**numeric;
	int	i1 = 0;
	int	i2 = 0;
	int	c = 0;

	d->map.current = d->map.lhead;
	numeric = malloc(sizeof(int *) * d->map.size_y);
	while (i1 < d->map.size_y)
	{
		numeric[i1] = malloc(sizeof(int) * d->map.size_x);
		while (i2 < d->map.size_x)
		{
			numeric[i1][i2] = (int)val(&d->map.current->line[c]);
			while (ft_isdigit(d->map.current->line[c]) || d->map.current->line[c] == '-')
				c++;
			while (d->map.current->line[c] == ' ')
				c++;
			i2++;
		}
		d->map.lhead = d->map.current;
		i2 = 0;
		c = 0;
		i1++;
	}
	
	i1 = 0;
	i2 = 0;
	while (i1 < d->map.size_y)
	{
		while (i2 < d->map.size_x)
			{
				printf("%d ", numeric[i1][i2]);
				i2++;
			}
			printf("\n");
			i2 = 0;
			i1++;
	}
	return (0);
}

int	get_arg_stack(t_data *d, char **line)
{
	struct s_line	*new;

	new = malloc(sizeof(struct s_line));
	if (!line[0] || !new)
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

int	map_init(int fd, t_data *d)
{
	int		ret;
	char	*line;
	int		i = 0;
	
	d->map.size_y = 0;
	while (1)
	{
		ret = get_next_line(fd, &line);
		// printf("Fline:%s, ret:%d\n", line, ret);
		// d->map.size_y++;
		get_arg_stack(d, &line);
		// printf("current:%s\n", d->map.current->line);
		if (ret <= 0)
			break ;
		i++;
	
	}
		d->map.size_y = i;
		d->map.size_x = c_cnt(d->map.lhead->line, ' ');
		printf("sizeY:%d\n", d->map.size_y);
		printf("sizeX:%d\n", d->map.size_x);
	d->map.current = d->map.lhead;
	while (i > -1)
	{
		// printf("Sline:%s\n", d->map.current->line);
		d->map.current = d->map.current->next;

		i--;
	}
	values(d);
	return (1);
}
