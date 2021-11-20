/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstring.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 21:41:13 by dkocob        #+#    #+#                 */
/*   Updated: 2021/10/29 21:33:55 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstring(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] && s[i] != '\0')
		i++;
	write(1, &s[0], i);
	return ;
}
