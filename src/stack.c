/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/05 17:10:10 by dkocob        #+#    #+#                 */
/*   Updated: 2021/11/27 15:48:53 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


// static int	get_index(struct s_d *d, int num)
// {
// 	int	i;

// 	i = 0;
// 	while (i < d->argc - 1)
// 	{
// 		if (d->sintlist[i] == num)
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// int	unsorted_int(struct s_d *d, int i)
// {
// 	int	*intlist;
// 	int	*sintlist;

// 	intlist = malloc(sizeof(int) * d->argc);
// 	sintlist = malloc(sizeof(int) * d->argc);
// 	if (!sintlist || !intlist)
// 		return (-1);
// 	while (i < d->argc - 1)
// 	{
// 		if (val(d->a[i + 1]) > 2147483647 || val(d->a[i + 1]) < -2147483648)
// 			return (-1);
// 		intlist[i] = (int)val(d->a[i + 1]);
// 		sintlist[i] = intlist[i];
// 		i++;
// 	}
// 	d->intlist = intlist;
// 	d->sintlist = sintlist;
// 	return (0);
// }

// int	sorted_int(struct s_d *d, int i, int tmp)
// {
// 	while (i < d->argc - 1)
// 	{
// 		d->sintlist[i] = d->intlist[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (i < d->argc - 1)
// 	{
// 		if ((d->sintlist[i] > d->sintlist[i + 1]) && i < d->argc - 2)
// 		{
// 			tmp = d->sintlist[i];
// 			d->sintlist[i] = d->sintlist[i + 1];
// 			d->sintlist[i + 1] = tmp;
// 			i = -1;
// 		}
// 		i++;
// 	}
// 	i = 1;
// 	while (i < d->argc)
// 	{
// 		if (d->sintlist[i] == d->sintlist[i - 1])
// 			return (-1);
// 		i++;
// 	}
// 	return (0);
// }

// int	get_arg_stack(struct s_d *d)
// {
// 	int				i;
// 	struct s_node	*previous;
// 	struct s_node	*current;
// 	struct s_node	*next;

// 	i = 0;
// 	current = (struct s_node *)malloc(sizeof(struct s_node));
// 	while (i < d->argc - 1)
// 	{
// 		next = (struct s_node *)malloc(sizeof(struct s_node));
// 		current->nx = next;
// 		current->pr = previous;
// 		current->data = d->intlist[i];
// 		current->i = get_index(d, current->data);
// 		previous = current;
// 		if (i == 0)
// 			d->ha = current;
// 		current = next;
// 		i++;
// 	}
// 	free (current);
// 	d->hb = NULL;
// 	previous->nx = d->ha;
// 	d->ha->pr = previous;
// 	return (i);
// }
