/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_distance_to_char.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 21:41:13 by dkocob        #+#    #+#                 */
/*   Updated: 2022/03/08 19:01:29 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	dc(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}
