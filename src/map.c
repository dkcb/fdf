/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 19:00:06 by dkocob        #+#    #+#                 */
/*   Updated: 2021/11/27 17:53:22 by dkocob        ########   odam.nl         */
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

int	map_read()
{
		// current = (t_line *)malloc(sizeof(struct s_node * dc(line, '\0')));
	return (0);
}

int	get_arg_stack(t_data *d, char **line)
{
	t_line	*new;

	new = malloc(sizeof(t_line) * 1);
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
	
		d->map.size_y = i;
		d->map.size_x = 10;
	}
		printf("sizeY:%d\n", d->map.size_y);
		printf("sizeX:%d\n", d->map.size_x);
	d->map.current = d->map.lhead;
	while (i > -1)
	{
		// printf("Sline:%s\n", d->map.current->line);
		d->map.current = d->map.current->next;
		i--;
	}
	return (1);
}
